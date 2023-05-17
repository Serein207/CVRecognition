#ifndef TXTREADER_H
#define TXTREADER_H

#include <QString>
#include <QFile>
#include <QDebug>
#include <QMessageBox>

class TxtReader
{
public:
    static void read(QString filename);
private:
    TxtReader() = default;
};

#endif // TXTREADER_H
