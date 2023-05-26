#include "pdfreader.h"
#include "picreader.h"

QString PDFReader::read(const QString& filepath)
{
    const auto pdfDoc = new QPdfDocument();
    pdfDoc->load(filepath);
    QString info;
    for (int pageIndex = 0; pageIndex < pdfDoc->pageCount(); ++pageIndex) {
        QPdfSelection page = pdfDoc->getAllText(pageIndex);
        QString text = page.text();
        if(!text.isEmpty())
            info.append(text + "\n");
        // qDebug() << text;
    }
    delete pdfDoc;
    if(info.isEmpty())
        return PicReader::read(filepath);
    else
        return info;
}
