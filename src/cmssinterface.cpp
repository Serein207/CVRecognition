#include "cmssinterface.h"
#include "ocr.h"
#include "nlp.h"
#include <map>
#include <utility>
#include <QVector>

QString CmssInterface::getGenericResultJson(const std::string& imageBase64StdStr) {
    std::map<std::string, std::string> options;
    cmssai::Ocr ocrClient(Ak,Sk);
    options.emplace(std::make_pair("image", imageBase64StdStr));
    return QString::fromStdString(ocrClient.generic_url("MeaningLessNull",options));
}

QString CmssInterface::getEntityJson(const QString& content) {
    cmssai::Nlp client(Ak, Sk);
    std::vector<cmssai::Item> entityParams;

    QString contentRemoveSpace = content;
    contentRemoveSpace.replace(" ", "");
    static int count = 1;
    cmssai::Item entityItem;
    entityItem.setTextId(std::to_string(count++));
    entityItem.setText(contentRemoveSpace.toUtf8().toStdString());
    entityParams.push_back(entityItem);
    return QString::fromStdString(client.entity(entityParams));
}

QString CmssInterface::getSegmentationJson(const QString& content) {
    cmssai::Nlp client(Ak, Sk);
    std::vector<cmssai::Item> entityParams;

    QString contentRemoveSpace = content;
    contentRemoveSpace.replace(" ", "");
    static int count = 1;
    cmssai::Item entityItem;
    entityItem.setTextId(std::to_string(count++));
    entityItem.setText(contentRemoveSpace.toUtf8().toStdString());
    entityParams.push_back(entityItem);
    return QString::fromStdString(client.segmentation(entityParams));
}

QString CmssInterface::getKeywordsJson(const QVector<QString>& contentVec) {
    cmssai::Nlp client(Ak, Sk);
    std::vector<cmssai::Item> entityParams;
    for(int i = 0;i < contentVec.size(); i++){
        cmssai::Item entityItem;
        entityItem.setTextId(std::to_string(i));
        entityItem.setText(contentVec[i].toStdString());
        entityParams.push_back(entityItem);
    }
    return QString::fromStdString(client.keywords(entityParams));
}
