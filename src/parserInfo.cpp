#include "cmssinterface.h"
#include "parserInfo.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QMessageBox>
#include <QBuffer>
#include <QRegularExpression>

QString parser::parserName(const QString& content) {
    for (int i = 0; i < content.length(); i += 400) {
        QJsonDocument entityJson = QJsonDocument::fromJson(
            CmssInterface::getEntityJson(content.mid(i, 400)).toUtf8()
        );
        if (entityJson["state"] != QJsonValue("OK")) {
            QMessageBox msg;
            msg.setWindowTitle("错误！");
            msg.setWindowFlag(Qt::Drawer);
            msg.setText("网络连接失败");
            msg.exec();
            return "unknown";
        }

        QJsonValue itemsValue = entityJson["body"]["items"];
        if (itemsValue.type() == QJsonValue::Array) {
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
        msg.setWindowTitle("错误！");
        msg.setWindowFlag(Qt::Drawer);
        msg.setText("网络连接失败");
        msg.exec();
        return QString {};
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
            QMessageBox msg;
            msg.setWindowTitle("错误！");
            msg.setWindowFlag(Qt::Drawer);
            msg.setText("网络连接失败");
            msg.exec();
            return bean_type {};
        }

        QJsonArray items = segmentationJson["body"]["items"].toArray();
        for (int j = 0; j < items.count(); ++j) {
            QJsonArray beanArray = items.at(j)["bean"].toArray();
            for (int k = 0; k < beanArray.count(); ++k) {
                const QString nature = beanArray.at(k)["nature"].toString();
                if (nature == "w" || nature == "p" || nature == "uj" ||
                    nature == "q" || nature == "ul") continue;
                result.insert(
                    nature,
                    beanArray.at(k)["word"].toString()
                );
                // qDebug() << beanArray.at(k)["word"].toString() << " ";
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
    if (result.length() != 7)
        result.insert(5, "0");
    return result;
}

QString parser::parserYears(const QString& content) {
    QString removeSpaceContent = content;
    removeSpaceContent.replace(" ", "");

    const QRegularExpression directRegex(
        R"((\d)(?:年.*?(?!实习)经(验|历)))"
    );
    QRegularExpressionMatchIterator intervalIterator = directRegex.globalMatch(removeSpaceContent);
    int sum = 0;
    while (intervalIterator.hasNext()) {
        QRegularExpressionMatch match = intervalIterator.next();
        //qDebug() << match;
        sum += match.captured(1).toInt();
    }
    if (directRegex.match(removeSpaceContent).hasMatch()) {
        return QString("%1").arg(sum);
    }

    QSet<QPair<QDate, QDate>> intervals;

    QDate startDate {}, endDate {};
    int lastIndex = 0;
    const QRegularExpression regex1(
        R"((\d{4}(?:\.|年|/|、)\d{1,2})(?:-|–)(\d{4}(?:\.|年|/|、)\d{1,2}))"
    );
    const QRegularExpression regexToday1(
        R"((\d{4}(?:\.|年|/|、)\d{1,2})(?:-|–)*至今)"
    );
    QRegularExpressionMatchIterator intervalIterator1 = regex1.globalMatch(removeSpaceContent);
    QRegularExpressionMatchIterator intervalTodayIterator1 = regexToday1.globalMatch(removeSpaceContent);
    
    while (intervalIterator1.hasNext()) {
        QRegularExpressionMatch match = intervalIterator1.next();
        if (content.mid(match.lastCapturedIndex(),
            match.lastCapturedIndex() - lastIndex).contains("实习") &&
            lastIndex != 0) {
            const auto it = intervals.find(qMakePair(startDate, endDate));
            intervals.erase(it);
        }
        startDate = QDate::fromString(handleDate(match.captured(1)),
            "yyyy.MM");
        endDate = QDate::fromString(handleDate(match.captured(2)),
            "yyyy.MM");
        
        intervals.insert(qMakePair(startDate, endDate));
    }

    while (intervalTodayIterator1.hasNext()) {
        QRegularExpressionMatch match = intervalTodayIterator1.next();
        if (content.mid(match.lastCapturedIndex(),
            match.lastCapturedIndex() - lastIndex).contains("实习") &&
            lastIndex != 0) {
            const auto it = intervals.find(qMakePair(startDate, endDate));
            intervals.erase(it);
        }
        startDate = QDate::fromString(handleDate(match.captured(1)),
            "yyyy.MM");
        endDate = QDate::currentDate();
        // qDebug() << startDate << endDate;
        intervals.insert(qMakePair(startDate, endDate));
    }

    lastIndex = 0;
    startDate = {};
    endDate = {};
    const QRegularExpression regex2(
        R"((\d{4})(?:\.|年){0,1}(?:-|–)(\d{4})(?:\.|年){0,1})"
    );
    const QRegularExpression regexToday2(
        R"((\d{4})(?:\.|年|){0,1}(?:-|–)*至今)"
    );
    QRegularExpressionMatchIterator intervalIterator2 = regex2.globalMatch(removeSpaceContent);
    QRegularExpressionMatchIterator intervalTodayIterator2 = regexToday2.globalMatch(removeSpaceContent);

    while (intervalIterator2.hasNext()) {
        QRegularExpressionMatch match = intervalIterator2.next();
        if (content.mid(match.lastCapturedIndex(), 
            match.lastCapturedIndex() - lastIndex).contains("实习") && 
            lastIndex != 0) {
            const auto it = intervals.find(qMakePair(startDate, endDate));
            intervals.erase(it);
        }
        lastIndex = match.lastCapturedIndex();
        startDate = QDate::fromString(match.captured(1),
            "yyyy");
        endDate = QDate::fromString(match.captured(2),
            "yyyy");
        intervals.insert(qMakePair(startDate, endDate));
        // qDebug() << startDate << endDate;
    }

    while (intervalTodayIterator2.hasNext()) {
        QRegularExpressionMatch match = intervalTodayIterator2.next();
        if (content.mid(match.lastCapturedIndex(),
            match.lastCapturedIndex() - lastIndex).contains("实习") &&
            lastIndex != 0) {
            const auto it = intervals.find(qMakePair(startDate, endDate));
            intervals.erase(it);
        }
        startDate = QDate::fromString(handleDate(match.captured(1)),
            "yyyy");
        endDate = QDate::currentDate();
        // qDebug() << startDate << endDate;
        intervals.insert(qMakePair(startDate, endDate));
    }

    long long years = 0;
    foreach(const auto& interval, intervals) {
        const QDate start = interval.first;
        const QDate end = interval.second;
        auto count = start.daysTo(end) / 365ll;
        if (count > 0 && count < 40) 
            years += count;
    }

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
    QStringList educationList = { "博士", "硕士", "本科", "学士", "大专", "专科", "中专", "职业学院", "职业学校" , "职业技术学院", "职业技术学校", "高中"};
    QString highestEducation = "unknown";

    QString removeSpaceContent = content;
    removeSpaceContent.replace(" ", "");
    for (const auto& education : educationList) {
        if (removeSpaceContent.contains(education)) {
            if (education == "职业学院" || education == "职业学校" || education == "大专" || 
                education == "职业技术学校" || education == "职业技术学院") {
                highestEducation = "专科";
            }
            else if (education == "学士") {
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
            QMessageBox msg;
            msg.setWindowTitle("错误！");
            msg.setWindowFlag(Qt::Drawer);
            msg.setText("网络连接失败");
            msg.exec();
            return "unknown";
        }

        QJsonValue itemsValue = entityJson["body"]["items"];
        if (itemsValue.type() == QJsonValue::Array) {
            QJsonArray itemsArray = itemsValue.toArray();
            for (int j = 0; j < itemsArray.count(); ++j) {
                QJsonArray nerTokens = itemsArray.at(j)["nerTokens"].toArray();
                for (int k = 0; k < nerTokens.count(); ++k) {
                    if (nerTokens.at(k)["type"].toString().contains("ORG")) {
                        QString org = nerTokens.at(k)["word"].toString();
                        // qDebug() << org;
                        if (org.contains("大学") || 
                            org.contains("学院") ||
                            org.contains("学校")) {
                            return org;
                        }
                    }
                }
            }
        }
    }
    return "unknown";
}
