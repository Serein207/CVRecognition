#include "jobdemandsanalysis.h"

QMap<QString, QString> JobDemandsAnalysis::JobAnalysis(QString word){
    QStringList ls = word.replace(" ", "").split("\n");
    QMap<QString, QString> res{{"name", ""}, {"edu", ""}, {"time", ""}};
    QRegularExpressionMatch matchres;
    for(int i = 0; i < ls.length(); i++){
        if (i == 0){
            matchres = QRegularExpression(repnamepattern).match(ls[i]);
            if(matchres.hasMatch()){
                //qDebug()<<matchres.captured(3);
                res["name"] = matchres.captured(3);
            }
        }

        matchres = QRegularExpression(edupattern).match(ls[i]);
        if(matchres.hasMatch()){
            //qDebug()<<matchres.captured(1);
            QString eduorigin = matchres.captured(1);
            if(eduorigin == "研究生"){
                eduorigin = "硕士";
            }
            if(eduorigin == "大专"){
                eduorigin = "专科";
            }
            res["edu"] = eduorigin;
        }

        matchres = QRegularExpression(jobexppattern).match(ls[i]);
        if(matchres.hasMatch()){
            QString temp = matchres.captured(2);
            if(temp.contains("-")){
                //qDebug()<<chineseTurn2Int(temp.split("-")[0]);
                res["time"] = chineseTurn2Int(temp.split("-")[0]);
            }
            else {
                //qDebug()<<chineseTurn2Int(matchres.captured(2));
                res["time"] = chineseTurn2Int(matchres.captured(2));
            }
        }
    }

    return res;
}
