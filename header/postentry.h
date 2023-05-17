#ifndef POSTENTRY_H
#define POSTENTRY_H

#include "entry.h"

namespace Ui {
class PostEntry;
}

class PostEntry : public Entry
{
    Q_OBJECT

public:
    explicit PostEntry(QWidget *parent = nullptr);
    ~PostEntry();

private:
    Ui::PostEntry *ui;
};

#endif // POSTENTRY_H
