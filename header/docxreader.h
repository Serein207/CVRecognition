#ifndef DOCXREADER_H
#define DOCXREADER_H

#include <QtAxContainer/QAxWidget>
#include <QAxObject>
#include <QThread>
#include <QFileInfo>

class DOCXReader
{

public:
    static DOCXReader * getInstance(){
        static DOCXReader instance;
        return &instance;
    }

    QString read(QString);
    // 注意，在程序进程退出时请使用deleteWord进行Word的正常关闭
    void deleteWord() const;

private:
    QAxWidget *m_word;
    QAxObject *m_documents;

    DOCXReader(){
        // 创建Word应用
        m_word = new QAxWidget("Word.Application");
        // 设置不可见
        m_word->setProperty("Visible",false);
        m_documents = m_word->querySubObject("Documents");
    };
    DOCXReader(const DOCXReader&) = delete;
    DOCXReader& operator=(const DOCXReader&) = delete;

    QString readCVHelper(QAxObject*);
    QString readTextFrame(QAxObject*);

};

#endif // DOCXREADER_H
