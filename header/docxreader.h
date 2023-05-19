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
    DOCXReader(const DOCXReader&) = delete;
    DOCXReader& operator=(const DOCXReader&) = delete;

    QString read(QString);
    ~DOCXReader() { deleteWord(); }

private:
    QAxWidget *m_word;
    QAxObject *m_document;

    DOCXReader(){
        //创建Word应用
        m_word = new QAxWidget("Word.Application");
        //设置不可见
        m_word->setProperty("Visible",false);
        m_document = m_word->querySubObject("Documents");
    }

    void deleteWord() const;

    QString readCVHelper(QAxObject*);
    static QString readTextFrame(QAxObject*);
};

#endif // DOCXREADER_H