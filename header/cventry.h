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

protected:
    void dropEvent(QDropEvent* event) override;

private:
    Ui::CvEntry *ui;

public slots:
    virtual void readFile();
    void selectFile() override;
};

#endif // CVENTRY_H
