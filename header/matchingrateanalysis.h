#ifndef MATCHINGRATEANALYSIS_H
#define MATCHINGRATEANALYSIS_H

#include "jobdemandsanalysis.h"
#include "keywordmatch.h"

class MatchingRateAnalysis {
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
    static QString singleCvAnalysis(const QVector<QString>& demandList, const QVector<QString>& cvMes, const QString cvText);
};

#endif // MATCHINGRATEANALYSIS_H
