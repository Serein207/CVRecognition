#include "jobdemandsanalysis.h"

QMap<QString, QString> JobDemandsAnalysis::jobAnalysis(QString word){
    //qDebug() << word;
    word = word.replace(" ", "");
    QMap<QString, QString> res{{"name", ""}, {"edu", ""}, {"time", ""}};
    QRegularExpressionMatch match = QRegularExpression(repNamePattern).match(word);
    if(match.hasMatch()){
        res["name"] = match.captured(1);
    }

    match = QRegularExpression(eduPattern).match(word);
    if(match.hasMatch()){
        QString eduOrigin = match.captured(1);
        if(eduOrigin == "研究生"){
            eduOrigin = "硕士";
        }
        if(eduOrigin == "大专"){
            eduOrigin = "专科";
        }
        res["edu"] = eduOrigin;
    }

    match = QRegularExpression(jobExpPattern).match(word);
    if(match.hasMatch()){
        QString temp = match.captured(2);
        if(temp.contains("-")){
            res["time"] = chineseTurn2Int(temp.split("-")[0]);
        }
        else {
            res["time"] = chineseTurn2Int(match.captured(2));
        }
    }

    return res;
}
