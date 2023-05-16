#include <string>
#include "nlp.h"
#include "ocr.h"

int main() {
    std::string ak = "7b5055c0ecfc4d19b8def6869898fc8b";
    std::string sk = "33df542ec17d417a80d0a56fdcb1118c";
    cmssai::Ocr client(ak, sk);

    std::map<std::string, std::string> options;
    options.emplace(std::make_pair("pdf_page_index", "0"));
    options.emplace(std::make_pair("enable_pdf_recognize", "true"));
    //options.emplace("item_names", "errorcode|errormsg|session_id|recognize_list");

    std::string result = client.custom_url("R(D:\softbei\pdf\1.pdf)",
        "1", 
        cmssai::null);
    std::cout << result << std::endl;
}