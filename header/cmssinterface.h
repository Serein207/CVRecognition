#ifndef CMSSINTERFACE_H
#define CMSSINTERFACE_H

#include <QString>
#include <string>
#include <memory>
#include <map>
#include <utility>


class CmssInterface
{

public:


    static std::shared_ptr<CmssInterface> getCmssInterface();


    ~CmssInterface() {}

    QString getGenericResultJson(std::string imageBase64StdStr);
    //只根据图片返回识别后的json，如果json全空，说明网络错误，但不会抛出异常
    //json里也会包含api的错误信息用于后续处理
protected:

private:
    CmssInterface(){}
    CmssInterface(const CmssInterface&) = delete;
    CmssInterface& operator=(const CmssInterface&) = delete;

    const std::string m_ocrAk = "7b5055c0ecfc4d19b8def6869898fc8b";
    const std::string m_ocrSk = "33df542ec17d417a80d0a56fdcb1118c";
};

#endif // CMSSINTERFACE_H
