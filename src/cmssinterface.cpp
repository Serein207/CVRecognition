#include "cmssinterface.h"
#include "ocr.h"
#include "nlp.h"
#include <map>
#include <utility>

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

QString CmssInterface::getSegmentationJson(const QString& content) {
    cmssai::Nlp client(Ak, Sk);
    std::vector<cmssai::Item> entityParams;

    static int count = 1;
    cmssai::Item entityItem;
    entityItem.setTextId(std::to_string(count++));
    entityItem.setText(content.simplified().toUtf8().toStdString());
    entityParams.push_back(entityItem);
    return QString::fromStdString(client.segmentation(entityParams));
}
