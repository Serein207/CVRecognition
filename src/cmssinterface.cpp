#include "cmssinterface.h"
#include "ocr.h"
#include "nlp.h"
#include <map>
#include <utility>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QMessageBox>

QString CmssInterface::getGenericResultJson(const std::string& imageBase64StdStr) {
    std::map<std::string, std::string> options;
    cmssai::Ocr ocrClient(Ak,Sk);
    options.emplace(std::make_pair("image", imageBase64StdStr));
    return QString::fromStdString(ocrClient.generic_url("MeaningLessNull",options));
}

QString CmssInterface::getEntityJson(const QString& content) {
    cmssai::Nlp client(Ak, Sk);
    std::vector<cmssai::Item> entityParams;

    static int count = 1;
    cmssai::Item entityItem;
    entityItem.setTextId(std::to_string(count++));
    entityItem.setText(content.simplified().toUtf8().toStdString());
    entityParams.push_back(entityItem);
    return QString::fromStdString(client.entity(entityParams));
}

QString CmssInterface::parserName(const QString& content) {
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
