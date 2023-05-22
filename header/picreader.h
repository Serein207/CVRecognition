#ifndef PICREADER_H
#define PICREADER_H

#include <QString>
#include <QImage>

class PicReader {
public:
    static QString read(const QString& filename);

private:
    PicReader() = default;

    static QString getImageInfo(const QImage& image, const std::string& suffix);
};

#endif // PICREADER_H
