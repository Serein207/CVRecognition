#include "cmssinterface.h"
#include "ocr.h"
#include "nlp.h"
#include <map>
#include <utility>

std::shared_ptr<CmssInterface> CmssInterface::getCmssInterface() {
    static std::shared_ptr<CmssInterface> ptr = nullptr;
    if (ptr==nullptr){
        ptr = std::shared_ptr<CmssInterface>(new CmssInterface());
    }
    return ptr;
}

QString CmssInterface::getGenericResultJson(const std::string& imageBase64StdStr) const {
    std::map<std::string, std::string> options;
    cmssai::Ocr ocrClient(m_ocrAk,m_ocrSk);
    options.emplace(std::make_pair("image", imageBase64StdStr));
    return QString::fromStdString(ocrClient.generic_url("MeaningLessNull",options));
}

QString CmssInterface::getEntityJson(const QString& content) const {
    cmssai::Nlp client(m_ocrAk, m_ocrSk);
    std::vector<cmssai::Item> entityParams;

    static int count = 1;
    cmssai::Item entityItem;
    entityItem.setTextId(std::to_string(count++));
    entityItem.setText(content.simplified().toUtf8().toStdString());
    entityParams.push_back(entityItem);
    std::string entityResult = client.entity(entityParams);
    std::cout << entityResult << std::endl;
        
    return QString::fromStdString(client.entity(entityParams));
}