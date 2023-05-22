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
            QString singleImageInfo = BasicInfo::getImageInfo(image,suffix);
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
        return BasicInfo::getImageInfo(image,suffix);
    }
    return info;
}

QString BasicInfo::getImageInfo(QImage image,std::string suffix){
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


void BasicInfo::parserName(const QString& content) {
    /*
    std::string ak = "7b5055c0ecfc4d19b8def6869898fc8b";
    std::string sk = "33df542ec17d417a80d0a56fdcb1118c";
    cmssai::Nlp client(ak, sk);
    std::vector<cmssai::Item> entityParams;
    for (int i = 0; i < content.length(); i += 399) {
        cmssai::Item entityItem;
        entityItem.setTextId("1");
        entityItem.setTitle("简历");
        entityItem.setContent(content.mid(i, 399).toUtf8().toStdString());
        entityParams.push_back(entityItem);
        entityParams.push_back(entityItem);
        std::string industry_result = client.entity(entityParams);
        std::cout << industry_result << std::endl;
    }
    */
}
