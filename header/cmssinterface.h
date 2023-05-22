#ifndef CMSSINTERFACE_H
#define CMSSINTERFACE_H

#include <QString>
#include <string>
#include <memory>

class CmssInterface {
public:
    static std::shared_ptr<CmssInterface> getCmssInterface();

    ~CmssInterface() = default;

    //只根据图片返回识别后的json，如果json全空，说明网络错误，但不会抛出异常
    //json里也会包含api的错误信息用于后续处理
    QString getGenericResultJson(const std::string& imageBase64StdStr) const;

    //实体识别json content字符数量不要超过399
    QString getEntityJson(const QString& content) const;

    CmssInterface(const CmssInterface&) = delete;
    CmssInterface& operator=(const CmssInterface&) = delete;

private:
    CmssInterface() = default;

    const std::string m_ocrAk = "7b5055c0ecfc4d19b8def6869898fc8b";
    const std::string m_ocrSk = "33df542ec17d417a80d0a56fdcb1118c";
};

#endif // CMSSINTERFACE_H
