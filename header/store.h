#ifndef STORE_H
#define STORE_H

#include <QDir>

class Store {
public:
    static std::shared_ptr<Store> getStore();
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
    static void deleteStore(const QString& filePath, QMap<QString, QString>& map);

private:
    Store() = default;

    static void writeStore(const QString& kind, const QMap<QString, QString>& map);
    static void readStore(const QString& kind, QMap<QString, QString>& map);

    static QString simplifiedStr(const QString& source);
};

#endif // STORE_H
