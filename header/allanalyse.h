#ifndef ALLANALYSE_H
#define ALLANALYSE_H

#include <QDialog>

namespace Ui {
class AllAnalyse;
}

class AllAnalyse : public QDialog
{
    Q_OBJECT

public:
    explicit AllAnalyse(QWidget *parent = nullptr);
    ~AllAnalyse();

private:
    Ui::AllAnalyse *ui;

signals:
    void showMainWinSig();

public slots:
    void showMainWin();
};

#endif // ALLANALYSE_H
