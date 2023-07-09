#include "cmssinterface.h"
#include "parserInfo.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QMessageBox>
#include <QBuffer>
#include <QRegularExpression>

#include "matchingrateanalysis.h"
#include "store.h"

QString parser::parserName(const QString& content) {
    for (int i = 0; i < content.length(); i += 400) {
        QJsonDocument entityJson = QJsonDocument::fromJson(
            CmssInterface::getEntityJson(content.mid(i, 400)).toUtf8()
        );
        if (entityJson["state"] != QJsonValue("OK")) {
            return "NetworkErr";
        }

        QJsonValue itemsValue = entityJson["body"]["items"];
        QJsonArray itemsArray = itemsValue.toArray();
        for (int j = 0; j < itemsArray.count(); ++j) {
            QJsonArray nerTokens = itemsArray.at(j)["nerTokens"].toArray();
            for (int k = 0; k < nerTokens.count(); ++k) {
                if (nerTokens.at(k)["type"].toString().contains("PER")) {
                    return nerTokens.at(k)["word"].toString();
                }
            }
        }
    }
    return "unknown";
}

QString parser::parserImage(const QImage& image, const std::string& suffix) {
    QString output;
    QByteArray ba;
    QBuffer buf(&ba);
    image.save(&buf, suffix.c_str());
    std::string imageBase64Str = ba.toBase64().toStdString();
    buf.close();
    QString result = CmssInterface::getGenericResultJson(imageBase64Str);
    //qDebug()<<result;
    QJsonDocument imageJson = QJsonDocument::fromJson(result.toUtf8());
    if (imageJson["state"] != QJsonValue("OK")) {
        QMessageBox msg;
        msg.setWindowTitle("错误");
        msg.setWindowFlag(Qt::Drawer);
        msg.setText("连接超时或未连接");
        msg.exec();
        return {};
    }
    QJsonValue wordArrayValue = imageJson["body"]["content"]["prism_wordsInfo"];
    if (wordArrayValue.type() == QJsonValue::Array) {
        QJsonArray wordSearchArray = wordArrayValue.toArray();
        for (int i = 0; i < wordSearchArray.count(); i++) {
            output += wordSearchArray.at(i)["word"].toString();
            if (i)
                output += "\n";
        }
    }
    return output;
}

parser::bean_type parser::parserSegmentation(const QString& content) {
    bean_type result;
    for (int i = 0; i < content.length(); i += 400) {
        QJsonDocument segmentationJson = QJsonDocument::fromJson(
            CmssInterface::getSegmentationJson(content.mid(i, 400)).toUtf8()
        );
        if (segmentationJson["state"] != QJsonValue("OK")) {
            return {};
        }

        QJsonArray items = segmentationJson["body"]["items"].toArray();
        for (int j = 0; j < items.count(); ++j) {
            QJsonArray beanArray = items.at(j)["bean"].toArray();
            for (int k = 0; k < beanArray.count(); ++k) {
                const QString nature = beanArray.at(k)["nature"].toString();
                if (nature == "w" || nature == "p" || nature == "uj" ||
                    nature == "q" || nature == "ul" || nature == "m" ||
                    nature == "r" || nature == "c") continue;
                if (beanArray.at(k)["word"].toString().length() >= 2)
                    result.emplace_back(
                        beanArray.at(k)["word"].toString()
                    );
                //qDebug() << beanArray.at(k);
            }
        }
    }
    return result;
}

QString handleDate(const QString& date) {
    QString result = date;
    result.replace("年", ".")
        .replace("/", ".")
        .replace("、", ".");
    if (result.length() == 6)
        result.insert(5, "0");
    if (result.length() == 4)
        result += ".01";
    return result;
}

long long parserWorkYearsHelper(const QString& content, const QRegularExpression& regex) {
    QSet<QPair<QDate, QDate>> intervals;

    QDate startDate {}, endDate {};
    int lastIndex = 0;
    QRegularExpressionMatchIterator intervalIterator = regex.globalMatch(content);

    while (intervalIterator.hasNext()) {
        QRegularExpressionMatch match = intervalIterator.next();
        // qDebug() << match;
        if (content.mid(match.lastCapturedIndex(),
            match.lastCapturedIndex() - lastIndex).contains("实习") &&
            lastIndex != 0) {
            const auto it = intervals.find(qMakePair(startDate, endDate));
            intervals.erase(it);
        }
        startDate = QDate::fromString(handleDate(match.captured(1)),
            "yyyy.MM");
        if (match.captured(2) == "至今") {
            endDate = endDate = QDate::currentDate();
        } else {
            endDate = QDate::fromString(handleDate(match.captured(2)),
                "yyyy.MM");
        }
        intervals.insert(qMakePair(startDate, endDate));
        // qDebug() << startDate << endDate;
        lastIndex = match.lastCapturedIndex();
    }

    long long years = 0;
    foreach(const auto & interval, intervals) {
        const QDate start = interval.first;
        const QDate end = interval.second;
        const auto count = start.daysTo(end) / 365ll;
        if (count > 0 && count < 40)
            years += count;
    }

    return years;
}

QString parser::parserWorkYears(const QString& content) {
    QString removeSpaceContent = content;
    removeSpaceContent.replace(" ", "");

    const QRegularExpression directRegex(
        R"([^\d](\d){1,2}(?:年.*?(?!实习)经(验|历)))"
    );
    QRegularExpressionMatchIterator intervalIterator = directRegex.globalMatch(removeSpaceContent);
    int sum = 0;
    while (intervalIterator.hasNext()) {
        QRegularExpressionMatch match = intervalIterator.next();
        // qDebug() << match;
        sum += match.captured(1).toInt();
    }
    if (directRegex.match(removeSpaceContent).hasMatch()) {
        return QString("%1").arg(sum);
    }

    const auto years =
        parserWorkYearsHelper(removeSpaceContent,
            QRegularExpression(R"((\d{4}(?:.|年|/|、)\d{1,2})(?:-|–|－|一|—|到|至)(\d{4}(?:.|年|/|、)\d{1,2}))"))
        +
        parserWorkYearsHelper(removeSpaceContent,
            QRegularExpression(R"((\d{4}(?:.|年|/|、)\d{1,2})(?:-|–|－|一|—|到|至)?(至今))"))
        +
        parserWorkYearsHelper(removeSpaceContent,
            QRegularExpression(R"((\d{4})(?:.|年)?(?:-|–|－|一|—|到|至)(\d{4})(?:.|年)?)"))
        +
        parserWorkYearsHelper(removeSpaceContent,
            QRegularExpression(R"((\d{4})(?:.|年)?(?:-|–|－|一|—|到|至)?(至今))"));

    return QString("%1").arg(years);
}

QString parser::parserAge(const QString& content) {
    const QRegularExpression directRegExp(R"((\d+)\s*(岁|周岁))");
    QString removeSpaceContent = content;
    removeSpaceContent.replace(" ", "");
    QRegularExpressionMatchIterator directAge = directRegExp.globalMatch(removeSpaceContent);
    while (directAge.hasNext()) {
        const QRegularExpressionMatch match = directAge.next();
        return match.captured(1);
    }

    const QRegularExpression indirectRegExp(R"(\d{4}(?:\.|年|/|、))");
    QRegularExpressionMatchIterator indirectAge = indirectRegExp.globalMatch(removeSpaceContent);
    int minValue = QDateTime::currentDateTime().date().year() + 1;
    while (indirectAge.hasNext()) {
        QRegularExpressionMatch match = indirectAge.next();
        // qDebug() << match;
        const int value = match.captured(0).removeLast().toInt();
        if (value < 1950) continue;
        if (value < minValue) {
            minValue = value;
        }
    }

    const int age = QDateTime::currentDateTime().date().year() - minValue;
    if (age > 18) 
        return QString("%1").arg(age);

    const QRegularExpression invalidRegExp(R"([1-5][8-9]|[2-5][0-9]|[6][0-5])");
    QRegularExpressionMatch match = invalidRegExp.match(content);
    if (match.hasMatch()) 
        return match.captured(0);

    return "unknown";
}

QString parser::parserEducation(const QString& content) {
    QStringList educationList = { "博士", "硕士", "本科", "学士", "大专", "专科", "中专", "职业学院", "职业学校" , "职业技术学院", "职业技术学校", "高中", "大学"};
    QString highestEducation = "高中";

    QString removeSpaceContent = content;
    removeSpaceContent.replace(" ", "");
    for (const auto& education : educationList) {
        if (removeSpaceContent.contains(education)) {
            if (education == "职业学院" || education == "职业学校" || education == "大专" || 
                education == "职业技术学校" || education == "职业技术学院") {
                highestEducation = "专科";
            }
            else if (education == "学士" || education == "大学") {
                highestEducation = "本科";
            }
            else {
                highestEducation = education;
            }
            break;
        }
    }
    return highestEducation;
}

QString parser::parserCollege(const QString& content) {
    for (int i = 0; i < content.length(); i += 400) {
        QJsonDocument entityJson = QJsonDocument::fromJson(
            CmssInterface::getEntityJson(content.mid(i, 400)).toUtf8()
        );

        if (entityJson["state"] != QJsonValue("OK")) {
            return "NetworkErr";
        }

        QJsonValue itemsValue = entityJson["body"]["items"];
        QJsonArray itemsArray = itemsValue.toArray();
        for (int j = 0; j < itemsArray.count(); ++j) {
            QJsonArray nerTokens = itemsArray.at(j)["nerTokens"].toArray();
            for (int k = 0; k < nerTokens.count(); ++k) {
                if (nerTokens.at(k)["type"].toString().contains("ORG")) {
                    QString org = nerTokens.at(k)["word"].toString();
                    if (org.contains("大学") || 
                        org.contains("学院") ||
                        org.contains("学校")) {
                        return org;
                    }
                }
            }
        }
    }
    return "unknown";
}

QVector<QString> parser::parserResult(const QString& content) {
    const QString name = parserName(content);
    if (name == "NetworkErr") return { "NetworkErr" };

    const QString college = parserCollege(content);
    if (college == "NetworkErr") return{ "NetworkErr" };
    return QVector<QString> {
        name,
            parserAge(content),
            parserEducation(content),
        college,
        parserWorkYears(content)
    };
}

QVector<QString> parser::parserPostVec(const QMap<QString,QString>& post){
    QVector<QString> contentVec;
    for(auto it = post.constKeyValueBegin(); it != post.constKeyValueEnd(); ++it){
        QStringList list = it->second.split(QRegularExpression("([0-9]+、)"));
        QStringList handledList;
        for(int i = 1; i < list.size(); i++){
            if(list[i].contains("岗位职责")){
                handledList.push_back(list[i]);
            } else if (!handledList.isEmpty()) {
                handledList[handledList.size()-1] += list[i];
            }
        }
        int count = 1;
        for(const auto& postContent : handledList){
            contentVec.push_back(QString("%1、%2").arg(count++).arg(postContent));
        }
    }
    qDebug()<<contentVec;
    return contentVec;
}

QVector<QString> parser::singleInfo(const QString& content) {
    auto singleInfoVec = parserResult(content);
    if (singleInfoVec.contains("NetworkErr")) return {"NetworkErr"};
    const auto recommend = MatchingRateAnalysis::singleCvAnalysis(
        parserPostVec(Store::getStore()->post),
        singleInfoVec, content
    );
    singleInfoVec.push_back(recommend);
    return singleInfoVec;
}
