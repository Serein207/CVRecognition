#ifndef PARSERINFO_H
#define PARSERINFO_H

#include <QImage>

namespace parser {
    using bean_type = QMultiHash<QString, QString>;
    QString parserName(const QString& content);
    bean_type parserSegmentation(const QString& content);
    QString parserImage(const QImage& image, const std::string& suffix);
    QString parserYears(const QString& content);
    QString parserAge(const QString& content);
    QString parserEducation(const QString& content);
    QString parserCollege(const QString& content);
}

#endif
