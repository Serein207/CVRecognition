#ifndef MATCHINGRATEANALYSIS_H
#define MATCHINGRATEANALYSIS_H

#include "jobdemandsanalysis.h"

struct emltdata{
    QString word;
    int num;
    emltdata(QString w, int n) {
        word = w;
        num = n;
    }
};


class MatchingRateAnalysis
{
    static void tempaddone(QList<emltdata> resource, QString word){
        for(int i = 0; i < resource.length(); i++){
            if(resource.at(i).word == word){
                resource[i].num += 1;
                break;
            }
        }
    }
    static bool checkword(QList<emltdata> resource, QString word){
        bool flag = false;
        for(const auto &it : resource){
            if(it.word == word){
                flag = true;
                break;
            }
        }
        return flag;
    }
    static int edu2enum(QString origin){
        if(origin == "高中"){
            return 0;
        }
        if(origin == "中专"){
            return 1;
        }
        if(origin == "大专"){
            return 2;
        }
        if(origin == "本科"){
            return 3;
        }
        if(origin == "硕士"){
            return 4;
        }
        if(origin == "博士"){
            return 5;
        }
        return -1;
    }

public:
    static QList<emltdata> wordFrequencyExtract(int nlenth, QStringList resource);

    //词频分析函数
    /*
     *@param CVdata 简历词频数据
     *@param jobdemanddata 岗位需求词频数据
     *@return double 计算分数值
    */
    //计分函数，如需修改分数评判标准，请更改此处
    /*
     * emltdata 结构体（word 字符数据，num 统计数）
     */
    static double rateAnalysis(QList<emltdata> CVdata, QList<emltdata> jobdemanddata);

    static QString singleCvAnalysis(QMap<QString, QList<QString>> demandList, const QVector<QString> Cvmes, QList<QString> CvList);
};

#endif // MATCHINGRATEANALYSIS_H
