#include <QAxWidget>
#include <QBuffer>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QPdfDocument>
#include <QMessageBox>

#include "ocr.h"
#include "picreader.h"

QString PicReader::read(const QString& filename)
{
    auto getImageInfo= [](QImage image,std::string suffix)->QString{
        QString output;
        std::string ak = "7b5055c0ecfc4d19b8def6869898fc8b";
        std::string sk = "33df542ec17d417a80d0a56fdcb1118c";
        cmssai::Ocr client(ak, sk);
        QByteArray ba;
        QBuffer buf(&ba);
        image.save(&buf, suffix.c_str());
        std::string imageBase64Str = ba.toBase64().toStdString();
        buf.close();
        std::map<std::string, std::string> options;
        options.emplace(std::make_pair("image", imageBase64Str));
        //options.emplace("item_names", "errorcode|errormsg|session_id|recognize_list");
        QString result = QString::fromStdString(client.generic_url("MeaningLessNull",
            options));
        //qDebug()<<result;
        QJsonDocument imageJson = QJsonDocument::fromJson(result.toUtf8());
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
        for(int i = 0;i <= pdfdoc.pageCount() ;i++){
            image = pdfdoc.render(i,pdfdoc.pagePointSize(i).toSize());
            info += getImageInfo(image,suffix);
        }
    }else{
        if(!image.load(filename)){
            QMessageBox msg;
            msg.setWindowTitle("错误！");
            msg.setWindowFlag(Qt::Drawer);
            msg.setText("文件打开失败！");
            msg.exec();
            return QString{};
        }else{
            return getImageInfo(image,suffix);
        }
    }


    return info;
}
