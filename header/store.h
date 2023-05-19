#ifndef STORE_H
#define STORE_H

#include <QMap>
#include <QString>

class Store {
public:
    static Store* getStore() {
        static Store* ptr = nullptr;
        if (!ptr) 
            ptr = new Store();
        return ptr;
    }

    ~Store() { delete Store::getStore(); }

    QMap<QString, QString> cvs;
    QMap<QString, QString> post;

private:
    Store() = default;
};

#endif // STORE_H
