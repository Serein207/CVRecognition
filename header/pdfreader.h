#ifndef PDFREADER_H
#define PDFREADER_H

#include <QPdfDocument>
#include <QFile>

class PDFReader
{
public:
    static void read(const QString& filepath);
private:
    PDFReader() = default;
};

#endif // PDFREADER_H
