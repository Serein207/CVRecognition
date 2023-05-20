#include <QAxWidget>
#include <QPdfDocument>
#include <QBuffer>

#include "test.h"
#include "ocr.h"

std::string test() {
    std::string ak = "7b5055c0ecfc4d19b8def6869898fc8b";
    std::string sk = "33df542ec17d417a80d0a56fdcb1118c";
    cmssai::Ocr client(ak, sk);


    //std::string idcard_image_url =
    // "https://ai.bdstatic.com/file/D348C98B677149C8B95909CFA204BA1C";
    //QString result = QString::fromStdString(client.idcard_url(idcard_image_url, cmssai::null));
    //std::cout<<idcard_result<<std::endl;
    //qDebug()<<result.toStdString().c_str();

    std::map<std::string, std::string> options;
    QImage image("C:/Users/feipiao/Desktop/1_00");
    QByteArray ba;
    QBuffer buf(&ba);
    image.save(&buf, "png");
    std::string teststr = ba.toBase64().toStdString();
    buf.close();
    options.emplace(std::make_pair("image", teststr));
    //options.emplace("item_names", "errorcode|errormsg|session_id|recognize_list");

    QString result = QString::fromStdString(client.generic_url(" ",
        options));
    qDebug()<<result.toStdString().c_str();
    return result.toStdString();
}
//
