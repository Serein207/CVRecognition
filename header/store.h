#ifndef STORE_H
#define STORE_H

#include <QStringList>

class Store {
public:
    static Store* getStore() {
        static Store* ptr = nullptr;
        if (!ptr) 
            ptr = new Store();
        return ptr;
    }

    ~Store() { delete Store::getStore(); }

    QStringList m_cvs;
    QStringList m_post;

private:
    Store() = default;
};

#endif // STORE_H
