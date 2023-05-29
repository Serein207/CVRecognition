#ifndef JOBDEMANDSANALYSIS_H
#define JOBDEMANDSANALYSIS_H

#include <map>
#include <QString>
#include <regex>
#include <QStringList>


#include "QRegularExpression"

class JobDemandsAnalysis{
    inline static QString repnamepattern = R"((?:\d+)、(.+)(岗位职责))";
    inline static QString edupattern = R"((中专|大专|本科|硕士|研究生|博士|专科|高中))";
    inline static QString jobexppattern = R"((\.|、|，|,)([^(\.|、|，|,)]*)(年).*(经验|阅历))";

    inline const static QMap<QString, int> common_used_numerals_tmp = {
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
        if (common_used_numerals_tmp.find(key) != common_used_numerals_tmp.end()) {
            return QString::number(common_used_numerals_tmp[key]);
        }
        int lastInt = 0;
        if (key[0] == u'十') {
            lastInt += (10 + common_used_numerals_tmp[key[1]]);
            return QString("%1").arg(lastInt);
        }
        lastInt += 10 * common_used_numerals_tmp[key[0]];
        if(key.size() == 2) {
            return QString("%1").arg(lastInt);
        }
        lastInt += common_used_numerals_tmp[key[2]];
        return QString("%1").arg(lastInt);
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
