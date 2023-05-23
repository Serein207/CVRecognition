#ifndef PARSERINFO_H
#define PARSERINFO_H

#include <QImage>

namespace parser {
    using bean_type = QMultiMap<QString, QString>;
    QString parserName(const QString& content);
    bean_type parserSegmentation(const QString& content);
    QString parserImage(const QImage& image, const std::string& suffix);
}

#endif
