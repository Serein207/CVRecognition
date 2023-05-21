#ifndef STORE_H
#define STORE_H

#include <QMap>
#include <QString>
#include <QFile>
#include <QDir>
#include <QMessageBox>

class Store {
public:
    static Store* getStore();

    ~Store() { delete Store::getStore(); }
    Store(const Store&) = delete;
    Store& operator=(const Store&) = delete;

    QMap<QString, QString> cvs;
    QMap<QString, QString> post;

    void writeCvStore() const {
        writeStore("cv", cvs);
    }
    void writePostStore() const {
        writeStore("post", post);
    }
    void readCvStore() {
        readStore("cv", cvs);
    }
    void readPostStore() {
        readStore("post", post);
    }


private:
    Store() = default;

    static void writeStore(const QString& kind, const QMap<QString, QString>& map);
    static void readStore(const QString& kind, QMap<QString, QString>& map);
    static void deleteStore(const QString kind, QMap<QString, QString>& map);
};

#endif // STORE_H