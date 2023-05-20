#ifndef STORE_H
#define STORE_H

#include <QMap>
#include <QString>
#include <QFile>
#include <QDir>
#include <QMessageBox>

class Store {
public:
    static Store* getStore() {
        static Store* ptr = nullptr;
        if (!ptr) 
            ptr = new Store();
        return ptr;
    }

    ~Store() { delete Store::getStore(); }
    Store(const Store&) = delete;
    Store& operator=(const Store&) = delete;

    QMap<QString, QString> cvs;
    QMap<QString, QString> post;

    void writeCvFile() {
        writeFile("cv", cvs);
    }
    void writePostFile() {
        writeFile("post", post);
    }
    void readCvFile() {
        readFile("cv", cvs);
    }
    void readPostFile() {
        readFile("post", post);
    }

private:
    Store() = default;

    static void writeFile(const QString& kind, QMap<QString, QString>& map) {
        int count = 1;
        for (auto item = map.constKeyValueBegin();
            item != map.constKeyValueEnd(); ++item) {
            const QString path = QString(".\\data\\%1\\%2.txt").arg(kind).arg(count++);
            QFile file(path);
            if(!file.open(QFile::ReadWrite | QFile::Text)) {
                QMessageBox msg;
                msg.setWindowFlag(Qt::CustomizeWindowHint);
                msg.setWindowTitle("错误！");
                msg.setText("文件打开失败");
                msg.exec();
                break;
            }

            file.write(item->first.toUtf8());
            QString enter = "\n";
            file.write(enter.toUtf8());
            file.write(item->second.toUtf8());
            file.close();
        }
    }

    static void readFile(const QString& kind, QMap<QString, QString>& map) {
        map.clear();
        const auto dir = new QDir(QString(".\\data\\%1").arg(kind));
        QStringList filters;
        filters << "*.txt";
        const auto files = new QList<QFileInfo>(dir->entryInfoList(filters));
        for (int i = 0; i < files->count(); ++i) {
            auto fileName = files->at(i).fileName();
            QFile file(QString("%1\\%2").arg(dir->path()).arg(fileName));
            if(!file.open(QFile::ReadOnly | QFile::Text)) {
                QMessageBox msg;
                msg.setWindowFlag(Qt::CustomizeWindowHint);
                msg.setWindowTitle("错误！");
                msg.setText("文件打开失败");
                msg.exec();
                break;
            }

            QTextStream in(&file);
            QString filePath = in.readLine().toUtf8();
            QString content = in.readAll().toUtf8();
            
            map.insert(filePath, content);
            file.close();
        }

        delete dir;
        delete files;
    }
};

#endif // STORE_H