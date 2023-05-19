#ifndef PDFREADER_H
#define PDFREADER_H

#include <QPdfDocument>
#include <QFile>

class PDFReader
{
public:
    PDFReader();
    QString readCV(QString);
};

#endif // PDFREADER_H
