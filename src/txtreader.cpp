#include "txtreader.h"

QString TxtReader::read(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox msg;
        msg.setWindowTitle("错误！");
        msg.setWindowFlag(Qt::CustomizeWindowHint);
        msg.setText("文件打开失败！");
        msg.exec();
        return QString{};
    }

    QTextStream in(&file);
    return in.readAll();
}
