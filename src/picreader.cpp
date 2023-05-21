#include <QAxWidget>
#include <QBuffer>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>

#include "ocr.h"
#include "picreader.h"

QString PicReader::read(const QString& filename)
{
    //qDebug() << "FEIPIAO TEST";
    std::string ak = "7b5055c0ecfc4d19b8def6869898fc8b";
    std::string sk = "33df542ec17d417a80d0a56fdcb1118c";
    cmssai::Ocr client(ak, sk);
    QString wordResult;
    std::map<std::string, std::string> options;
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
    QImage image(filePathDelSuffix);
    QByteArray ba;
    QBuffer buf(&ba);
    image.save(&buf, suffix.c_str());
    std::string imageBase64Str = ba.toBase64().toStdString();
    buf.close();
    options.emplace(std::make_pair("image", imageBase64Str));
    //options.emplace("item_names", "errorcode|errormsg|session_id|recognize_list");
    QString result = QString::fromStdString(client.generic_url("MeaningLessNull",
        options));
    QJsonDocument imageJson = QJsonDocument::fromJson(result.toUtf8());
    QJsonValue wordArrayValue = imageJson["body"]["content"]["prism_wordsInfo"];
    if (wordArrayValue.type() == QJsonValue::Array) {
        QJsonArray wordSearchArray = wordArrayValue.toArray();
        for (int i = 0; i < wordSearchArray.count(); i++) {
            wordResult += wordSearchArray.at(i)["word"].toString();
        }
    }
    return wordResult;
}
