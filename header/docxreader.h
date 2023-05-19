#ifndef DOCXREADER_H
#define DOCXREADER_H

#include <QtAxContainer/QAxWidget>
#include <QAxObject>

class DOCXReader
{

public:
    static DOCXReader * getInstance(){
        static DOCXReader instance;
        return &instance;
    }

    QString readCV(QString);
    //注意，在程序进程退出时请使用deleteWord进行Word的正常关闭
    void deleteWord();
private:
    QAxWidget *m_word;
    QAxObject *m_document;

    DOCXReader(){
        //创建Word应用
        m_word = new QAxWidget("Word.Application");
        //设置不可见
        m_word->setProperty("Visible",false);
        m_document = m_word->querySubObject("Documents");
    };
    DOCXReader(const DOCXReader&) = delete;
    DOCXReader& operator=(const DOCXReader&) = delete;

    QString readCVHelper(QAxObject*);
    QString readTextFrame(QAxObject*);
};

#endif // DOCXREADER_H
