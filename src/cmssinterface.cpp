#include "cmssinterface.h"
#include "ocr.h"
#include "nlp.h"

std::shared_ptr<CmssInterface> CmssInterface::getCmssInterface() {
    static std::shared_ptr<CmssInterface> ptr = nullptr;
    if (ptr==nullptr){
        ptr = std::shared_ptr<CmssInterface>(new CmssInterface());
    }
    return ptr;
}

QString CmssInterface::getGenericResultJson(std::string imageBase64StdStr){
    std::map<std::string, std::string> options;
    cmssai::Ocr ocrClient(m_ocrAk,m_ocrSk);
    options.emplace(std::make_pair("image", imageBase64StdStr));
    return QString::fromStdString(ocrClient.generic_url("MeaningLessNull",options));
}
