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
    void anlalyseSlot();
    void loadFiles() const;
};

#endif // ALLANALYSE_H
