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
    info.append(content->dynamicCall("Text()").toString()
        .replace("/", "") + "\n")
        .replace("\r\r", "")
        .replace("\f", "")
        .replace("\u0007", "")
        .replace("\u0001\u0015", "")
        .replace("\u000E", "")
        .replace("\u000B", "\n")
        .replace("\u0001", "")
        .replace("\u0002", "");

    int shapeCount = shapes->dynamicCall("Count()").toInt();
    for (int i = 1; i <= shapeCount; i++) {
        QAxObject* shape = shapes->querySubObject("Item(int)", i);
        QString theType = shape->dynamicCall("Type").toString();

        if(!theType.compare("17")){
            // 文本框：17
            try {
                QAxObject* textFrame = shape->querySubObject("TextFrame");
                connect(textFrame, &QAxObject::exception, this, &DOCXReader::handleException);
                QString temp = readTextFrame(textFrame);
                if(!(!temp.compare("\r")||!temp.compare("")||!temp.compare(" ")||!temp.compare("\n")||!temp.compare("\f")||!temp.compare("\u0007"))){
                    info.append(temp + "\n");
                }
            } catch (...) {
            }
        }
        else if(!theType.compare("6")){
            // 合并框：6
            info.append(readCVHelper(shape));
        }
        else if(!theType.compare("1")){
            // 文本框：1
            connect(shape, &QAxObject::exception, this, &DOCXReader::handleException);
            try {
                QAxObject* textFrame = shape->querySubObject("TextFrame");
                connect(textFrame, &QAxObject::exception, this, &DOCXReader::handleException);
                QString temp = readTextFrame(textFrame);
                if(!(!temp.compare("\r")||!temp.compare("")||!temp.compare(" ")||!temp.compare("\n")||!temp.compare("\f")||!temp.compare("\u0007"))){
                    info.append(temp + "\n");
                }
            } catch (...) {
            }
        }
        else{
            //qDebug()<<"The Type:" << theType;
        }
        delete shape;
    }

    m_docx->dynamicCall("Save()");

    delete shapes;
    delete m_docx;
    //qDebug()<<"Read docx file" << m_docx->dynamicCall("Name").toString() <<"finished!";

    return info.replace("\r\n\r\n", "").replace("\n\n", "\n");
}

void DOCXReader::deleteWord()
{
    m_word->dynamicCall("Quit()");
    delete m_documents;
}

void DOCXReader::handleException(int Code, QString Source, QString Description, QString Help)
{
    //qDebug()<<"None Text";
    throw "None Text";
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
            // 文本框：17
            try {
                QAxObject* textFrame = item->querySubObject("TextFrame");
                connect(textFrame, &QAxObject::exception, this, &DOCXReader::handleException);
                QString temp = readTextFrame(textFrame);
                if(!(!temp.compare("\r")||!temp.compare("")||!temp.compare(" ")||!temp.compare("\n")||!temp.compare("\f")||!temp.compare("\u0007"))){
                    info.append(temp + "\n");
                }
            } catch (...) {
            }
        }
        else if(!itemType.compare("6")){
            info.append(readCVHelper(item));
        }
        else if(!itemType.compare("1")){
            // 文本框：1
            try {
                QAxObject* textFrame = item->querySubObject("TextFrame");
                connect(textFrame, &QAxObject::exception, this, &DOCXReader::handleException);
                QString temp = readTextFrame(textFrame);
                if(!(!temp.compare("\r")||!temp.compare("")||!temp.compare(" ")||!temp.compare("\n")||!temp.compare("\f")||!temp.compare("\u0007"))){
                    info.append(temp + "\n");
                }
            } catch (...) {
            }
        }
        else{
            //qDebug()<<"The Type:" << itemType;
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
    QString text = textRange->property("Text").toString();

    //qDebug() << text;

    // 释放资源
    delete textRange;
    delete textFrame;

    return text.replace("\f", "")
        .replace("\u0007", "")
        .replace("\u0001\u0015", "")
        .replace("\u000E", "")
        .replace("\u000B", "\n")
        .replace("\u0001", "")
        .replace("\u0002", "");
}
