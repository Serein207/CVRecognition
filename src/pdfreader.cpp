#include "pdfreader.h"

void PDFReader::read(const QString& filepath)
{
    const auto pdfDoc = new QPdfDocument();
    pdfDoc->load(filepath);
    QString info;
    for (int pageIndex = 0; pageIndex < pdfDoc->pageCount(); ++pageIndex) {
        QPdfSelection page = pdfDoc->getAllText(pageIndex);
        QString text = page.text();
        info.append(text + "\n");
        qDebug() << text;
    }
    delete pdfDoc;

    qDebug() << info;
    // TODO: info接入资源管理
}
