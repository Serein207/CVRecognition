#include "matchingrateanalysis.h"

QList<emltdata> MatchingRateAnalysis::wordFrequencyExtract(int nlenth, QStringList resource){
    QList<emltdata> temp, res;
    for(QList<QString>::iterator it = resource.begin(); it != resource.end(); it++){
        if(checkword(temp, *it)){
            tempaddone(temp, *it);
        }
        else {
            temp.append(emltdata(*it, 1));
        }
    }
    std::sort(temp.begin(), temp.end(), [=](const emltdata &a, const emltdata &b){return a.num > b.num;});
    for(int i = 0; i < nlenth; i++){
        res.append(temp[i]);
    }
    return res;
}

double MatchingRateAnalysis::rateAnalysis(QList<emltdata> CVdata, QList<emltdata> jobdemanddata){
    double socre = 0;
    for(const auto &it : CVdata){
        if(checkword(jobdemanddata, it.word)){
            socre++;
            qDebug()<<it.word;
        }
    }
    qDebug()<<socre;
    return socre;
}

//输出符合的岗位
/*
* @param demandList 各个岗位需求
* @param Cvmes 个人简历基本信息
* @param CvList 个人简介经过分词处理的结果
*/
QString MatchingRateAnalysis::singleCvAnalysis(QMap<QString, QList<QString>> demandList, const QVector<QString> Cvmes, QList<QString> CvList){
    QList<QString> prelist;
    QMap<QString, QList<QString>>::iterator it = demandList.begin();
    for(;it != demandList.end(); it++){
        QMap<QString, QString> jobinfo = JobDemandsAnalysis::JobAnalysis(it.key());
        int Cveduint = edu2enum(Cvmes[2]);
        if(edu2enum(jobinfo["edu"]) <= Cveduint || jobinfo["edu"].isEmpty()){
            if(jobinfo["time"] <= Cvmes[4] || jobinfo["time"].isEmpty()){
                if(rateAnalysis(wordFrequencyExtract(50, CvList), wordFrequencyExtract(25, it.value())) > 10){
                    prelist.append(jobinfo["name"]);
                }
            }
        }
    }

    //结果组合
    QString res = "";
    int i = 0;
    for(const auto &resit : prelist){
        res.append(resit);
        if(i+1 != prelist.length()){
            res.append(",");
        }
        i++;
    }

    return res;
}
