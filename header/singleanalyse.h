#ifndef SINGLEANALYSE_H
#define SINGLEANALYSE_H

#include <QDialog>

namespace Ui {
class SingleAnalyse;
}

class SingleAnalyse : public QDialog
{
    Q_OBJECT

public:
    explicit SingleAnalyse(QWidget *parent = nullptr);
    ~SingleAnalyse();

private:
    Ui::SingleAnalyse *ui;
};

#endif // SINGLEANALYSE_H
