#ifndef MATCHINGRATEANALYSIS_H
#define MATCHINGRATEANALYSIS_H

#include "jobdemandsanalysis.h"

struct EmltData{
    QString word;
    int num;
    EmltData(const QString& w, const int n) {
        word = w;
        num = n;
    }
};


class MatchingRateAnalysis {
    static void tempAddOne(QList<EmltData> resources, const QString& word) {
        for (auto& resource : resources) {
            if(resource.word == word){
                ++resource.num;
                break;
            }
        }
    }
    static bool checkWord(const QList<EmltData>& resource, const QString& word) {
        bool flag = false;
        for (const auto& it : resource) {
            if(it.word == word){
                flag = true;
                break;
            }
        }
        return flag;
    }
    static int edu2Enum(const QString& origin) {
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
    static QList<EmltData> wordFrequencyExtract(const int nLength, const QStringList& resources);

    //词频分析函数
    /*
     *@param cvData 简历词频数据
     *@param postData 岗位需求词频数据
     *@return double 计算分数值
    */
    static double rateAnalysis(const QList<EmltData>& cvData, const QList<EmltData>& postData);

    static QString singleCvAnalysis(const QMap<QString, QStringList>& demandList, const QVector<QString>& cvMes, const QStringList& cvList);
};

#endif // MATCHINGRATEANALYSIS_H
