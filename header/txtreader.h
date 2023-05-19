#ifndef TXTREADER_H
#define TXTREADER_H

#include <QString>
#include <QFile>
#include <QDebug>
#include <QMessageBox>

class TxtReader
{
public:
    static QString read(const QString& filename);
private:
    TxtReader() = default;
};

#endif // TXTREADER_H
