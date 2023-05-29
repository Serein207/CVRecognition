#ifndef JOBDEMANDSANALYSIS_H
#define JOBDEMANDSANALYSIS_H

#include <map>
#include <QString>
#include <regex>
#include <QStringList>


#include "QRegularExpression"

class JobDemandsAnalysis{
    inline static QString repnamepattern = R"((\d+)(、|.)(.*))";
    inline static QString edupattern = R"((中专|大专|本科|硕士|研究生|博士|专科|高中))";
    inline static QString jobexppattern = R"((\.|、|，|,)([^(\.|、|，|,)]*)(年).*(经验|阅历))";

    inline const static std::map<QString, int> common_used_numerals_tmp = {
        {"零", 0},
         {"一", 1},
          {"二", 2},
           {"两", 2},
            {"三", 3},
             {"四", 4},
              {"五", 5},
               {"六", 6},
                {"七", 7},
                 {"八", 8},
                  {"九", 9},
                   {"十", 10}
                   };

    static QString chineseTurn2Int(QString key){
        if(std::regex_match(key.toStdString(), std::regex(R"(^\d*$)"))){
            return key;
        }
        else{
            int tempint = 1;
            int lastint = 0;
            if(common_used_numerals_tmp.find(key) != common_used_numerals_tmp.end()){
                return QString::number(common_used_numerals_tmp.find(key)->second);
            }
            else{
                QStringList list = key.split("十");
                if(list[0] != ""){
                    tempint = common_used_numerals_tmp.find(list[0])->second;
                }
                if(list[1] != ""){
                    lastint = common_used_numerals_tmp.find(list[1])->second;
                }
                return QString::number(10 * tempint + lastint);
            }
        }
    }

public:
    //岗位需求解析函数，如果该岗位不存在某个参数，则为空 ""
    /*
    *{
    *   "name": "" //岗位名
    *   "edu": ""  //岗位需求学历
    *   "time": "" //需要的专业实践经验时间
    *}
    */
    static QMap<QString, QString> JobAnalysis(QString word);
};

#endif // JOBDEMANDSANALYSIS_H
