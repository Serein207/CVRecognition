#include "matchingrateanalysis.h"

QList<emltdata> MatchingRateAnalysis::wordFrequencyExtract(int nlenth, QStringList resource) {
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

double MatchingRateAnalysis::rateAnalysis(QList<emltdata> CvData, QList<emltdata> jobDemandData) {
    double socre = 0;
    for(auto it : CvData){
        if(checkword(jobDemandData, it.word)){
            socre++;
            qDebug()<<it.word;
        }
    }
    qDebug()<<socre;
    return socre;
}