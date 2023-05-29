#pragma once
#ifndef EXCLREADER_H
#define EXCLREADER_H

#include <QtAxContainer/QAxWidget>
#include <QAxObject>
#include <QThread>
#include <QFileInfo>
#include <QObject>

class ExclReader : public QObject
{
    Q_OBJECT
public:
    static ExclReader* getInstance() {
        static ExclReader instance;
        return &instance;
    }

    QString read(const QString& filepath);
    // ע�⣬�ڳ�������˳�ʱ��ʹ��deleteWord����Word�������ر�
    void deleteExcl() const;
    ~ExclReader() { deleteWord(); }

    ExclReader(const ExclReader&) = delete;
    ExclReader& operator=(const ExclReader&) = delete;

private slots:
    void handleException(int, QString, QString, QString);

private:
    QAxWidget* m_word;
    QAxObject* m_documents;

    DOCXReader() {
        // ����WordӦ��
        m_word = new QAxWidget("Excl.Application");
        // ���ò��ɼ�
        m_word->setProperty("Visible", false);
        m_documents = m_word->querySubObject("Documents");
        connect(m_documents, &QAxObject::exception, this, &DOCXReader::handleException);
    }

    QString readCvHelper(QAxObject*);
    QString readTextFrame(QAxObject*);

};

#endif // DOCXREADER_H
