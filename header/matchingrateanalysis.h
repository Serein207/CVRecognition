#ifndef MATCHINGRATEANALYSIS_H
#define MATCHINGRATEANALYSIS_H

#include <QDebug>

struct emltdata {
    QString word;
    int num;
    emltdata(QString w, int n) {
        word = w;
        num = n;
    }
};

class MatchingRateAnalysis {
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
        for(auto it : resource){
            if(it.word == word){
                flag = true;
                break;
            }
        }
        return flag;
    }

public:
    //词频统计函数
    /*
     *@param nlenth 前n个高词频词语数量
     *@param resource 原始词库
    */
    static QList<emltdata> wordFrequencyExtract(int nlenth, QStringList resource);

    //词频分析函数
    /*
     *@param CvData 简历词频数据
     *@param jobDemandData 岗位需求词频数据
     *@return double 计算分数值
    */
    //计分函数，如需修改分数评判标准，请更改此处
    /*
     * emltdata 结构体（word 字符数据，num 统计数）
     */
    static double rateAnalysis(QList<emltdata> CvData, QList<emltdata> jobDemandData);
};

#endif // MATCHINGRATEANALYSIS_H
