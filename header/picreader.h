#ifndef PICREADER_H
#define PICREADER_H

#include <QString>
#include <QImage>

class PicReader {
public:
    static QString read(const QString& filename);

private:
    PicReader() = default;
};

namespace BasicInfo {
    void parserName(const QString& content);
    QString getImageInfo(QImage image,std::string suffix);
}

#endif // PICREADER_H
