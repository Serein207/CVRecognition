#include "cmssinterface.h"
#include "parserInfo.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QMessageBox>
#include <QBuffer>

QString parser::parserName(const QString& content) {
    for (int i = 0; i < content.length(); i += 400) {
        QJsonDocument entityJson = QJsonDocument::fromJson(
            CmssInterface::getEntityJson(content.mid(i, 400)).toUtf8()
        );
        if (entityJson["state"] != QJsonValue("OK")) {
            QMessageBox msg;
            msg.setWindowTitle("错误！");
            msg.setWindowFlag(Qt::Drawer);
            msg.setText("网络连接失败");
            msg.exec();
            return "unknown";
        }

        QJsonValue itemsValue = entityJson["body"]["items"];
        if (itemsValue.type() == QJsonValue::Array) {
            QJsonArray itemsArray = itemsValue.toArray();
            for (int j = 0; j < itemsArray.count(); ++j) {
                QJsonArray nerTokens = itemsArray.at(j)["nerTokens"].toArray();
                for (int k = 0; k < nerTokens.count(); ++k) {
                    if (nerTokens.at(k)["type"].toString().contains("PER")) {
                        return nerTokens.at(k)["word"].toString();
                    }
                }
            }
        }
    }
    return "unknown";
}

QString parser::parserImage(const QImage& image, const std::string& suffix) {
    QString output;
    QByteArray ba;
    QBuffer buf(&ba);
    image.save(&buf, suffix.c_str());
    std::string imageBase64Str = ba.toBase64().toStdString();
    buf.close();
    QString result = CmssInterface::getGenericResultJson(imageBase64Str);
    //qDebug()<<result;
    QJsonDocument imageJson = QJsonDocument::fromJson(result.toUtf8());
    if (imageJson["state"] != QJsonValue("OK")) {
        QMessageBox msg;
        msg.setWindowTitle("错误！");
        msg.setWindowFlag(Qt::Drawer);
        msg.setText("网络连接失败");
        msg.exec();
        return QString {};
    }
    QJsonValue wordArrayValue = imageJson["body"]["content"]["prism_wordsInfo"];
    if (wordArrayValue.type() == QJsonValue::Array) {
        QJsonArray wordSearchArray = wordArrayValue.toArray();
        for (int i = 0; i < wordSearchArray.count(); i++) {
            output += wordSearchArray.at(i)["word"].toString();
            if (i)
                output += "\n";
        }
    }
    return output;
}

parser::bean_type parser::parserSegmentation(const QString& content) {
    bean_type result;
    for (int i = 0; i < content.length(); i += 400) {
        QJsonDocument segmentationJson = QJsonDocument::fromJson(
            CmssInterface::getSegmentationJson(content.mid(i, 400)).toUtf8()
        );
        if (segmentationJson["state"] != QJsonValue("OK")) {
            QMessageBox msg;
            msg.setWindowTitle("错误！");
            msg.setWindowFlag(Qt::Drawer);
            msg.setText("网络连接失败");
            msg.exec();
            return bean_type {};
        }

        QJsonArray items = segmentationJson["body"]["items"].toArray();
        for (int j = 0; j < items.count(); ++j) {
            QJsonArray beanArray = items.at(j)["bean"].toArray();
            for (int k = 0; k < beanArray.count(); ++k) {
                result.insert(
                    beanArray.at(k)["nature"].toString(),
                    beanArray.at(k)["word"].toString()
                );
            }
        }
    }
    return result;
}
