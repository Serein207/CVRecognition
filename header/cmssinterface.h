#ifndef CMSSINTERFACE_H
#define CMSSINTERFACE_H

#include <QString>
#include <string>

class CmssInterface {
public:
    //只根据图片返回识别后的json，如果json全空，说明网络错误，但不会抛出异常
    //json里也会包含api的错误信息用于后续处理
    static QString getGenericResultJson(const std::string& imageBase64StdStr);

    //实体识别返回的json content字符数量不要超过400
    static QString getEntityJson(const QString& content);

    //智能分词返回的json content字符数量不要超过400
    static QString getSegmentationJson(const QString& content);

    //关键词提取返回的json content字符数量不要超过400
    static QString getKeywordsJson(const QVector<QString>& contentVec);
    CmssInterface(const CmssInterface&) = delete;
    CmssInterface& operator=(const CmssInterface&) = delete;

    inline static std::string Ak = "";
    inline static std::string Sk = "";

private:
    CmssInterface() = default;
};

#endif // CMSSINTERFACE_H
