#ifndef DOCXREADER_H
#define DOCXREADER_H

#include <QtAxContainer/QAxWidget>
#include <QAxObject>
#include <QThread>
#include <QFileInfo>
#include <QObject>

class DOCXReader : public QObject
{
    Q_OBJECT
public:
    static DOCXReader * getInstance(){
        static DOCXReader instance;
        return &instance;
    }

    static QString read(const QString& filepath) const;
    // 注意，在程序进程退出时请使用deleteWord进行Word的正常关闭
    void deleteWord() const;

    DOCXReader(const DOCXReader&) = delete;
    DOCXReader& operator=(const DOCXReader&) = delete;

private slots:
    void handleException(int, QString, QString, QString);

private:
    static QAxWidget *m_word;
    static QAxObject *m_documents;

    DOCXReader(){
        // 创建Word应用
        m_word = new QAxWidget("Word.Application");
        // 设置不可见
        m_word->setProperty("Visible",false);
        m_documents = m_word->querySubObject("Documents");
        connect(m_documents, &QAxObject::exception, this, &DOCXReader::handleException);
    }

    static QString readCvHelper(QAxObject*);
    static QString readTextFrame(QAxObject*);

};

#endif // DOCXREADER_H
