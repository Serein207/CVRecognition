#include "matchingrateanalysis.h"

QList<EmltData> MatchingRateAnalysis::wordFrequencyExtract(
    const int nLength, const QStringList& resources) {
    QList<EmltData> temp, res;
    for (const auto& resource : resources) {
        if (checkWord(temp, resource)) {
            tempAddOne(temp, resource);
        } else {
            temp.append(EmltData(resource, 1));
        }
    }
    std::sort(
        temp.begin(), temp.end(),
        [=](const EmltData& a, const EmltData& b) { return a.num > b.num; });
    for (int i = 0; i < nLength; i++) {
        if (i >= temp.length()) {
            res.append(EmltData(QString::number(0), 0));
        } else {
            res.append(temp[i]);
        }
    }
    return res;
}

double MatchingRateAnalysis::rateAnalysis(const QList<EmltData>& cvData,
                                          const QList<EmltData>& postData) {
    double score = 0;
    for (const auto& it : cvData) {
        if (checkWord(postData, it.word)) {
            if (checkWord(postData, it.word)) {
                score++;
                // qDebug() << it.word;
            }
        }
    }
    // qDebug() << score;
    return score;
}

// 输出符合的岗位
/*
 * @param demandList 各个岗位需求
 * @param cvMes 个人简历基本信息
 * @param cvList 个人简介经过分词处理的结果
 */
QString MatchingRateAnalysis::singleCvAnalysis(
    const QMap<QString, QStringList>& demandList, const QVector<QString>& cvMes,
    const QStringList& cvList) {
    QStringList preList;
    // qDebug() << demandList.size();
    for (auto it = demandList.begin(); it != demandList.end(); ++it) {
        QMap<QString, QString> jobInfo =
            JobDemandsAnalysis::jobAnalysis(it.key());
        const int cvEduInt = edu2Enum(cvMes[2]);
        // qDebug() << (edu2Enum(jobInfo["edu"]) <= cvEduInt) <<
        // edu2Enum(jobInfo["edu"]) << cvEduInt;
        if (edu2Enum(jobInfo["edu"]) <= cvEduInt || jobInfo["edu"].isEmpty()) {
            // qDebug() << (jobInfo["time"].toInt() <= cvMes[4].toInt()) <<
            // jobInfo["time"].toInt() << cvMes[4].toInt();
            if (jobInfo["time"].toInt() <= cvMes[4].toInt() ||
                jobInfo["time"].isEmpty()) {
                if (rateAnalysis(wordFrequencyExtract(50, cvList),
                                 wordFrequencyExtract(25, it.value())) > 1) {
                    preList.append(jobInfo["name"]);
                }
            }
        }
    }

    // 结果组合
    QString res = "";
    int i = 0;
    for (const auto& resit : preList) {
        res.append(resit);
        if (i + 1 != preList.length()) {
            res.append(",");
        }
        i++;
    }
    if (res.isEmpty()) res = "unknown";
    return res;
}
