#include "pdfreader.h"

PDFReader::PDFReader()
{

}

QString PDFReader::readCV(QString filepath)
{
    QPdfDocument *pdfDoc = new QPdfDocument();
    pdfDoc->load(filepath);
    QString info;
    for (int pageIndex = 0; pageIndex < pdfDoc->pageCount(); ++pageIndex) {
        QPdfSelection page = pdfDoc->getAllText(pageIndex);
        QString text = page.text();
        info.append(text + "\n");
        qDebug() << text;
    }
    return info;
}
