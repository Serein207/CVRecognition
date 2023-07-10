#include "matchingrateanalysis.h"

// 输出符合的岗位
/*
 * @param demandList 岗位信息原始文本
 * @param cvMes 个人简历基本信息
 * @param cvText 个人简介原始文本
 */
QString MatchingRateAnalysis::singleCvAnalysis(const QVector<QString>& demandList, const QVector<QString>& cvMes, const QString cvText) {
    QStringList preList;
    QVector<QString> keywordRequirementsVector = keywordmatch::curriculumVitaesMatching(demandList, cvText);
    // qDebug() << demandList.size();
    for (const auto &it : demandList) {
        QMap<QString, QString> jobInfo =
            JobDemandsAnalysis::jobAnalysis(it);
        const int cvEduInt = edu2Enum(cvMes[2]);
        // qDebug() << (edu2Enum(jobInfo["edu"]) <= cvEduInt) <<
        // edu2Enum(jobInfo["edu"]) << cvEduInt;
        if (edu2Enum(jobInfo["edu"]) <= cvEduInt || jobInfo["edu"].isEmpty()) {
            // qDebug() << (jobInfo["time"].toInt() <= cvMes[4].toInt()) <<
            // jobInfo["time"].toInt() << cvMes[4].toInt();
            if (jobInfo["time"].toInt() <= cvMes[4].toInt() ||
                jobInfo["time"].isEmpty()) {
                if(keywordRequirementsVector.contains(jobInfo["name"]))
                    preList.append(jobInfo["name"]);
            }
        }
    }

    // 结果组合
    QString res = "";
    int i = 0;
    for (const auto& resit : preList) {
        res.append(resit);
        if (i + 1 != preList.length()) {
            res.append("、");
        }
        i++;
    }
    return res;
}
