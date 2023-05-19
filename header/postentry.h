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

protected:
    void dropEvent(QDropEvent* event) override;

private:
    Ui::PostEntry *ui;

public slots:
    void readFile();
    void selectFile() override;
};

#endif // POSTENTRY_H
