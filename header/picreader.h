#ifndef PICREADER_H
#define PICREADER_H

#include <QString>

class PicReader {
public:
    static QString read(const QString& filename);
private:
    PicReader() = default;
};

namespace BasicInfo {
    void parserName(const QString& content);
}

#endif // PICREADER_H
