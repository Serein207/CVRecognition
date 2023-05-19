#include "txtreader.h"

void TxtReader::read(QString filename)
{
    QFile file(std::move(filename));
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox msg;
        msg.setWindowTitle("错误！");
        msg.setWindowFlag(Qt::CustomizeWindowHint);
        msg.setText("文件打开失败！");
        msg.exec();
        return;
    }

    QTextStream in(&file);
    const QString info = in.readAll();

    qDebug() << info;
    // TODO: info 接入资源管理
}
