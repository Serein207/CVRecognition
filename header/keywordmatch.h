#ifndef KEYWORDMATCH_H
#define KEYWORDMATCH_H

#include <QString>
#include <QVector>
#include <QRegularExpression>
#include <QRegExp>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include "CmssInterface.h"

class keywordmatch
{
public:
    keywordmatch(const keywordmatch&) = delete;
    static int parenjug(int n){
        if(n <= 5){
            return n;
        }
        return n / 4 + 1;
    }
    static QString jobNameMatching(QString requireStr);
    static QVector<QString> requirementsExtract(QString reqfile);
    static double onesentencejobrez(QJsonArray singleSentenceArr, QJsonArray curriculumVitaesArr);
    static double requirementWordMatching(QString reqFile, QJsonArray curriculumVitaesArr);
    static QVector<QString> curriculumVitaesMatching(QVector<QString> reqStrArray, QString curriculumVitaesStr);
};

#endif // KEYWORDMATCH_H
