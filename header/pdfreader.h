#ifndef PDFREADER_H
#define PDFREADER_H

#include <QPdfDocument>
#include <QFile>

class PDFReader
{
public:
    static QString read(const QString& filepath);
private:
    PDFReader() = default;
};

#endif // PDFREADER_H
