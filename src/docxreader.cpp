<<<<<<< HEAD
#include "docxreader.h"

QString DOCXReader::readCV(QString filepath)
{
    // 文件打开
    int docomentCount = m_documents->dynamicCall("Count()").toInt();

    //查找是否为历史文件
    bool flag = true;
    QFileInfo fileinfo(filepath);
    for(int i = 1; i <= docomentCount; i++){
        QAxObject* document = m_documents->querySubObject("Item(int)", i);
        if(!fileinfo.fileName().compare(document->property("Name").toString())){
            document->dynamicCall("Activate()");
            flag = false;
            break;
        }
        // 释放资源
        delete document;
    }
    if(flag){
        //打开新文件
        m_documents->dynamicCall("Open(const QString&, bool)", filepath, false);
    }
    QAxObject *m_docx = m_word->querySubObject("ActiveDocument");
    qDebug()<<"Open docx file" << m_docx->dynamicCall("Name").toString() <<"succuss!";

    QAxObject* shapes = m_docx->querySubObject("Shapes");
    QString info;

    // 普通文本读取，debug未进行输出，如有需要可以自行定义QString输出
    QAxObject* content = m_docx->querySubObject("Content");
    info.append(content->dynamicCall("Text()").toString().replace("/", "") + "\n");

    int shapeCount = shapes->dynamicCall("Count()").toInt();
    for (int i = 1; i <= shapeCount; i++) {
        QAxObject* shape = shapes->querySubObject("Item(int)", i);
        QString theType = shape->dynamicCall("Type").toString();

        if(!theType.compare("17")){
            // 文本框：17
            QAxObject* textFrame = shape->querySubObject("TextFrame");
            info.append(readTextFrame(textFrame) + "\n");
        }
        else if(!theType.compare("6")){
            // 合并框：6
            info.append(readCVHelper(shape));
        }
        else if(!theType.compare("1")){
            // 文本框：1
            QAxObject* textFrame = shape->querySubObject("TextFrame");
            info.append(readTextFrame(textFrame) + "\n");
        }
        else{
            //qDebug()<<"The Type:" << theType;
        }
        delete shape;
    }

    m_docx->dynamicCall("Save()");

    delete shapes;
    delete m_docx;

    info.replace("\r\n\r\n", "").replace("\n\n", "\n");
    return info;
}

void DOCXReader::deleteWord()
{
    m_word->dynamicCall("Quit()");
    delete m_documents;
}

QString DOCXReader::readCVHelper(QAxObject * shape)
{
    QString info;
    QAxObject* groupItems = shape->querySubObject("GroupItems");
    int itemCount = groupItems->dynamicCall("Count()").toInt();

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
    QAxObject* textRange = textFrame->querySubObject("TextRange");
    QString text = textRange->property("Text").toString().replace("\u0007", "");

    // 处理文本
    qDebug() << text;

    // 释放资源
    delete textRange;
    delete textFrame;

    return text;
}
=======
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
>>>>>>> ea217bc0a1c8a6c1d85fd5f32722f5d87c9e5a63
