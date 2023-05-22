#include "store.h"

Store* Store::getStore() {
    static Store* ptr = nullptr;
    if (!ptr)
        ptr = new Store();
    return ptr;
}

void Store::writeStore(const QString& kind, const QMap<QString, QString>& map) {
    int count = 1;
    const QDir dataDir(".\\data");
    if (!dataDir.exists()) {
        if (!QDir().mkdir(".\\data")) {
            QMessageBox msg;
            msg.setWindowFlag(Qt::Drawer);
            msg.setWindowTitle("错误！");
            msg.setText("文件夹data创建失败");
            msg.exec();
            return;
        }
    }

    QDir dir(QString(".\\data\\%1").arg(kind));
    if (dir.exists())
        dir.removeRecursively();
    
    if (!QDir().mkdir(QString(".\\data\\%1").arg(kind))) {
        QMessageBox msg;
        msg.setWindowFlag(Qt::Drawer);
        msg.setWindowTitle("错误！");
        msg.setText(QString("文件夹%1创建失败").arg(kind));
        msg.exec();
        return;
    }

    for (auto item = map.constKeyValueBegin();
        item != map.constKeyValueEnd(); ++item) {
        const QString path = QString(".\\data\\%1\\%2.txt").arg(kind).arg(count++);
        QFile file(path);
        if (!file.open(QFile::ReadWrite | QFile::Text)) {
            QMessageBox msg;
            msg.setWindowFlag(Qt::Drawer);
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

void Store::readStore(const QString& kind, QMap<QString, QString>& map) {
    map.clear();
    const QDir dataDir(".\\data");
    if (!dataDir.exists()) {
        if (!QDir().mkdir(".\\data")) {
            QMessageBox msg;
            msg.setWindowFlag(Qt::Drawer);
            msg.setWindowTitle("错误！");
            msg.setText("文件夹data创建失败");
            msg.exec();
            return;
        }
    }
    const QDir dir(QString(".\\data\\%1").arg(kind));
    if (!dir.exists()) {
        if (!QDir().mkdir(QString(".\\data\\%1").arg(kind))) {
            QMessageBox msg;
            msg.setWindowFlag(Qt::Drawer);
            msg.setWindowTitle("错误！");
            msg.setText(QString("文件夹%1创建失败").arg(kind));
            msg.exec();
            return;
        }
    }
    QStringList filters;
    filters << "*.txt";
    const auto files = new QList<QFileInfo>(dir.entryInfoList(filters));
    for (int i = 0; i < files->count(); ++i) {
        auto fileName = files->at(i).fileName();
        QFile file(QString("%1\\%2").arg(dir.path()).arg(fileName));
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox msg;
            msg.setWindowFlag(Qt::Drawer);
            msg.setWindowTitle("错误！");
            msg.setText("文件打开失败");
            msg.exec();
            break;
        }

        QTextStream in(&file);
        QString filePath = in.readLine().toUtf8().trimmed()
            .replace("\r", " ")
            .replace("\n", " ")
            .replace("\t", " ")
            .replace("\f", " ");
        QString content = in.readAll().toUtf8().trimmed()
            .replace("\r", " ")
            .replace("\n", " ")
            .replace("\t", " ")
            .replace("\f", " ");

        map.insert(filePath, content);
        file.close();
    }
    delete files;
}

void Store::deleteStore(const QString& filePath, QMap<QString, QString>& map) {
    if (filePath.isEmpty()) {
        QMessageBox msg;
        msg.setWindowFlag(Qt::Drawer);
        msg.setWindowTitle("错误！");
        msg.setText("文件路径为空！");
        msg.exec();
    }

    const auto item = map.find(filePath);
    if (item == map.end()) {
        QMessageBox msg;
        msg.setWindowFlag(Qt::Drawer);
        msg.setWindowTitle("错误！");
        msg.setText("文件不存在！");
        msg.exec();
    }

    map.erase(item);
    Store::getStore()->writeCvStore();
    Store::getStore()->writePostStore();
}
