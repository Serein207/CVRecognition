#ifndef TXTREADER_H
#define TXTREADER_H

#include <QFile>
#include <QMessageBox>
#include <QString>

class TxtReader {
   public:
    static QString read(const QString& filename);

   private:
    TxtReader() = default;
};

#endif  // TXTREADER_H
