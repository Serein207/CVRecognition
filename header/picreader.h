#ifndef PICREADER_H
#define PICREADER_H

#include <QString>

class PicReader
{
public:
    static QString read(const QString& filename);
private:
    PicReader() = default;
};

#endif // PICREADER_H
