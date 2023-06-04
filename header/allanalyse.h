#ifndef ALLANALYSE_H
#define ALLANALYSE_H

#include <QDialog>
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
    QString filename;

    void createPieCharts(const QVector<QString>& contents);
    void createAgeBarChars(const QVector<QString>& contents);
    void createWorkYearsBarChars(const QVector<QString>& contents);
    QVector<QVector<QString>> generatedData();

signals:
    void showMainWinSig();

public slots:
    void showMainWin();
    void anlalyseSlot();
    void loadFiles() const;
    void openFile();

private:
    void writeDataToPieChart(QPieSeries* pieSeries, const QString& label, const double& size, const int index);
    QString getColor(int index) const;
    QMap<QString, int> handleData(const QVector<QString>& contents);
    void getExcel(const QVector<QVector<QString>>& contents);
    void setLineEdit(const QVector<QVector<QString>>& contents);
};

#endif // ALLANALYSE_H
