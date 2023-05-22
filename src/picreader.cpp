#include <QAxWidget>
#include <QBuffer>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QPdfDocument>
#include <QMessageBox>

#include "picreader.h"
#include "cmssinterface.h"

QString PicReader::read(const QString& filename)
{
    QString info;
    std::string suffix;
    QString filePathDelSuffix = filename;
    if(filename.contains(".png")){
        filePathDelSuffix.remove(".png");
        suffix = "png";
    }
    else if (filename.contains(".jpg")){
        filePathDelSuffix.remove(".jpg");
        suffix = "jpg";
    }

    QImage image;
    if(filename.contains(".pdf")){
        suffix = "png";//这里用png就好了
        QPdfDocument pdfdoc;
        pdfdoc.load(filename);
        if(!pdfdoc.pageCount()){
            QMessageBox msg;
            msg.setWindowTitle("错误！");
            msg.setWindowFlag(Qt::Drawer);
            msg.setText("文件打开失败！");
            msg.exec();
            return QString{};
        }
        for(int i = 0;i < pdfdoc.pageCount() ;i++){
            image = pdfdoc.render(i,pdfdoc.pagePointSize(i).toSize());
            QString singleImageInfo = getImageInfo(image,suffix);
            if(singleImageInfo.isEmpty())return QString{};
            info += singleImageInfo;
        }
    }else{
        if(!image.load(filename)){
            QMessageBox msg;
            msg.setWindowTitle("错误！");
            msg.setWindowFlag(Qt::Drawer);
            msg.setText("文件打开失败！");
            msg.exec();
            return QString{};
        }
        return getImageInfo(image,suffix);
    }
    return info;
}

QString PicReader::getImageInfo(QImage image,std::string suffix){
    QString output;
    QByteArray ba;
    QBuffer buf(&ba);
    image.save(&buf, suffix.c_str());
    std::string imageBase64Str = ba.toBase64().toStdString();
    buf.close();
    QString result = CmssInterface::getCmssInterface()->getGenericResultJson(imageBase64Str);
    //qDebug()<<result;
    QJsonDocument imageJson = QJsonDocument::fromJson(result.toUtf8());
    if(imageJson["state"]!=QJsonValue("OK")){
        QMessageBox msg;
        msg.setWindowTitle("错误！");
        msg.setWindowFlag(Qt::Drawer);
        msg.setText("网络连接失败");
        msg.exec();
        return QString{};
    }
    QJsonValue wordArrayValue = imageJson["body"]["content"]["prism_wordsInfo"];
    if (wordArrayValue.type() == QJsonValue::Array) {
        QJsonArray wordSearchArray = wordArrayValue.toArray();
        for (int i = 0; i < wordSearchArray.count(); i++) {
            output += wordSearchArray.at(i)["word"].toString();
            if(i)
                output+="\n";
        }
    }
    return output;
};
