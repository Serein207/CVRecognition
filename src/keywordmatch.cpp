#include "keywordmatch.h"

QString keywordmatch::jobNameMatching(QString requireStr)
{
    const QString repnamepattern = R"((?:\d+)、(.+)(岗位职责))";
    QRegularExpressionMatch matchres = QRegularExpression(repnamepattern).match(requireStr);
    if(matchres.hasMatch()){
        //qDebug()<<matchres.captured(1);
        return matchres.captured(1);
    }
    return "";
}

QVector<QString> keywordmatch::requirementsExtract(QString reqfile)
{
    reqfile.replace(" ", "").replace("\n", "").replace("\r", "");
    QVector<QString> ans;
    static const QRegularExpression edupattern(R"((中专|大专|本科|硕士|研究生|博士))");
    static const QRegularExpression position_statement_reg(R"(岗位职责[:：]?)");
    static const QRegularExpression job_requirements_reg(R"((任职要求|职位要求)[:：]?)");
    static const QRegularExpression serial_number_reg(R"(\d[.、])");
    QRegularExpressionMatch match;

    QString resu = reqfile.section(position_statement_reg, 1, 1);
    QString position_statement_str = resu.section(job_requirements_reg, 0, 0);
    QString job_requirements_str = resu.section(job_requirements_reg, 1, 1);
    QVector<QString> arr1 = position_statement_str.split(serial_number_reg);
    QVector<QString> arr2 = job_requirements_str.split(serial_number_reg);
    if(arr1.contains("")) arr1.removeOne("");
    if(arr2.contains("")) arr2.removeOne("");
    for(const auto &i : arr2){
        match = edupattern.match(i);
        if(match.hasMatch()){
            arr2.removeOne(i);
            break;
        }
    }
    for(const auto &i : arr2){
        if(i.contains("年")){
            arr2.removeOne(i);
            break;
        }
    }

    for(const auto &i : arr1) ans.push_back(i);
    for(const auto &i : arr2) ans.push_back(i);
    // qDebug()<<ans;

    return ans;
}

double keywordmatch::onesentencejobrez(QJsonArray singleSentenceArr, QJsonArray curriculumVitaesArr){
    double scoreSum = 0;
    int sucNum = 0;
    int parenNum = parenjug(singleSentenceArr.count());
    for(const QJsonValueRef &a : curriculumVitaesArr){
        for(int i = 0; i < parenNum; i++){
            if(a.toObject().value("name").toString().compare(singleSentenceArr.at(i).toObject().value("name").toString()) == 0){
                // qDebug() << singleSentenceArr.at(i).toObject().value("name").toString();
                scoreSum += singleSentenceArr.at(i).toObject().value("weight").toDouble() * a.toObject().value("weight").toDouble();
                sucNum++;
            }
        }
    }
    double lastScore = scoreSum / (double)(sucNum + 1);
    qDebug() << "Last score: " << lastScore;
    if(lastScore < 0.00000001){
        return 0.0;
    }
    return lastScore;
}

double keywordmatch::requirementWordMatching(QString reqFile, QJsonArray curriculumVitaesArr)
{
    //qDebug()<<reqFile;
    int matchingNum = 0;
    QVector<QString> requirementsList = requirementsExtract(reqFile);
    QString repJsonList = CmssInterface::getKeywordsJson(requirementsList).replace("\n", "").replace(" ", "");
    //qDebug()<<repJsonList;
    QJsonDocument document = QJsonDocument::fromJson(QString::fromLocal8Bit(repJsonList.toLocal8Bit()).toUtf8());
    if(document.isNull()){
        qDebug()<<"需求文件json解析失败!";
        qDebug()<<repJsonList;
        return 0;
    }
    QJsonObject requirementJsonObject = document.object();
    QJsonArray requirementJsonArray = requirementJsonObject.value("body").toObject().value("items").toArray();
    //qDebug()<<requirementJsonArray;
    for(const auto &requirementSingleSentence : requirementJsonArray){
        // qDebug()<<onesentencejobrez(requirementSingleSentence.toObject().value("keywords").toArray(), curriculumVitaesArr) << "matchingNum: "<<matchingNum;
        if(onesentencejobrez(requirementSingleSentence.toObject().value("keywords").toArray(), curriculumVitaesArr)){
            matchingNum++;
        }
    }
    // qDebug()<<"requirementJsonArray: "<<requirementJsonArray.count() << "   matchingNum: " << matchingNum;
    double matchingScore = (double)matchingNum / (double)requirementJsonArray.count();
    qDebug() << "Matching score: " << matchingScore << "\n";
    return matchingScore;
}

QVector<QString> keywordmatch::curriculumVitaesMatching(QVector<QString> reqStrArray, QString curriculumVitaesStr)
{
    QVector<QString> curriculumVitaes_temp;
    QVector<QString> matchingJobNameVector;
    curriculumVitaesStr.replace(" ", "");
    curriculumVitaes_temp.push_back(curriculumVitaesStr);
    QJsonDocument document = QJsonDocument::fromJson(QString::fromLocal8Bit(CmssInterface::getKeywordsJson(curriculumVitaes_temp).replace("\n", "").replace(" ", "").toLocal8Bit()).toUtf8());
    if(document.isNull()){
        qDebug()<<"简历文件json解析错误!";
    }
    QJsonArray curriculumVitaesKeywordJsonArray = document.object().value("body").toObject().value("items").toArray().at(0).toObject().value("keywords").toArray();

    for(auto &a : reqStrArray){
        qDebug()<<jobNameMatching(a);
        if(requirementWordMatching(a, curriculumVitaesKeywordJsonArray) > 0.5 && jobNameMatching(a).compare("") != 0){
            matchingJobNameVector.push_back(jobNameMatching(a));
        }
    }

    return matchingJobNameVector;
}
