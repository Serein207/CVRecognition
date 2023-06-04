#ifndef ALLANALYSE_H
#define ALLANALYSE_H

#include <QDialog>
#include <QChartView>
#include <QPieSeries>

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
    QChartView* chartView;
    void createpieSewise(const QVector<QString>& contents);
    void writeDataToPieChart(QPieSeries* my_pieSeries, const QString& label, const double& size, const int index);
    QString getRandomColor(int index);
    QMap<QString, int> handleData(const QVector<QString>& contents);

signals:
    void showMainWinSig();

public slots:
    void showMainWin();
    void anlalyseSlot();
    void loadFiles() const;
};

#endif // ALLANALYSE_H
