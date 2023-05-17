#ifndef CVENTRY_H
#define CVENTRY_H

#include "entry.h"

namespace Ui {
class CvEntry;
}

class CvEntry : public Entry
{
    Q_OBJECT

public:
    explicit CvEntry(QWidget *parent = nullptr);
    ~CvEntry();

private:
    Ui::CvEntry *ui;
};

#endif // CVENTRY_H
