#include "docxreader.h"

void DOCXReader::read(QString filepath)
{
    QAxObject *docx = m_document->querySubObject("Open(const QString&, bool)", filepath, true);
    qDebug()<<"open docx succuss!";

    QAxObject* shapes = docx->querySubObject("Shapes");
    QString info;

    QAxObject* content = docx->querySubObject("Content");
    info.append(content->dynamicCall("Text()").toString().replace("\n", "").replace("/", "") + "\n");

    const int shapeCount = shapes->dynamicCall("Count()").toInt();
    for (int i = 1; i <= shapeCount; i++) {
        QAxObject* shape = shapes->querySubObject("Item(int)", i);

        QString theType = shape->dynamicCall("Type").toString();
 //       qDebug()<<theType;
        if(!theType.compare("17")){
            QAxObject* textFrame = shape->querySubObject("TextFrame");
            info.append(readTextFrame(textFrame) + "\n");
        }
        else if(!theType.compare("6")){
            //info = shape->generateDocumentation();
            info.append(readCVHelper(shape));
        }
        delete shape;
    }

    docx->dynamicCall("Save()");
    docx->dynamicCall("Close()");

    delete shapes;
    delete docx;

    qDebug() << info;
    // TODO: info 接入资源管理
}

void DOCXReader::deleteWord() const
{
    m_word->dynamicCall("Quit()");

    delete m_document;
    delete m_word;
}

QString DOCXReader::readCVHelper(QAxObject * shape)
{
    QString info;
    QAxObject* groupItems = shape->querySubObject("GroupItems");
    const int itemCount = groupItems->dynamicCall("Count()").toInt();

    for (int i = 1; i <= itemCount; i++) {
        QAxObject* item = groupItems->querySubObject("Item(int)", i);
        QString itemType = item->dynamicCall("Type()").toString();

        if (!itemType.compare("17")) {
            // 这是一个文本框对象
            QAxObject* textFrame = item->querySubObject("TextFrame");
            info.append(readTextFrame(textFrame) + "\n");
        }
        if(!itemType.compare("6")){
            info.append(readCVHelper(item));
        }

        // 释放资源
        delete item;
    }

    // 释放资源
    delete groupItems;
    return info;
}

QString DOCXReader::readTextFrame(QAxObject * textFrame)
{
    const QAxObject* textRange = textFrame->querySubObject("TextRange");
    QString text = textRange->property("Text").toString().replace("\u0007", "");

    // 处理文本
    qDebug() << text;

    // 释放资源
    delete textRange;
    delete textFrame;

    return text;
}
