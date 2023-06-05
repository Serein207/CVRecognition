#include "allanalyse.h"
#include "ui_allanalyse.h"
#include "excelwriter.h"
#include "store.h"
#include "parserInfo.h"
#include <QDir>
#include <QFileDialog>
#include <QProgressDialog>
#include <QDesktopServices>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QMessageBox>
#include <QValueAxis>

AllAnalyse::AllAnalyse(QWidget *parent) :
    QDialog(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::AllAnalyse)
{
    ui->setupUi(this);
    this->setModal(true);
    this->setWindowTitle(tr("全部分析"));
    loadFiles();

    ui->fileInfo->hide();
    ui->button_openFile->hide();

    connect(ui->button_showMainWin, &QPushButton::clicked, this, &AllAnalyse::showMainWin);
    connect(ui->button_analyse, &QPushButton::clicked, this, &AllAnalyse::anlalyseSlot);
    connect(ui->button_openFile, &QPushButton::clicked, this, &AllAnalyse::openFile);
}

AllAnalyse::~AllAnalyse() {
    delete ui;
}

void AllAnalyse::showMainWin() {
    emit showMainWinSig();
    this->close();
}

void AllAnalyse::anlalyseSlot() {
    auto contents = generatedData();
    if (contents.isEmpty()) return;

    getExcel(contents);

    QVector<QString> age, edu, workYears;
    for (const auto& content : contents) {
        age.push_back(content[2]);
        edu.push_back(content[3]);
        workYears.push_back(content[5]);
    }

    createPieCharts(edu);
    createAgeBarChars(age);
    createWorkYearsBarChars(workYears);
    setLineEdit(contents);

    ui->fileInfo->setText("全部数据已保存到excel文件：\n" + filename);
    ui->fileInfo->show();
    ui->button_openFile->show();

    QMessageBox msg(this);
    msg.setWindowTitle("成功");
    msg.setWindowFlag(Qt::Drawer);
    msg.setText("完成分析");
    msg.exec();
}

void AllAnalyse::getExcel(const QVector<QVector<QString>>& contents) {
    const QString userName = QDir::home().dirName();
    const QString defaultName = QDate::currentDate().toString("yyyyMMdd") + QTime::currentTime().toString("hhmmss");
    const QString defaultPath = QString("C:/Users/%1/Documents").arg(userName) + "/" + defaultName;

    filename = QFileDialog::getSaveFileName(this, tr("保存到"), defaultPath, "*.xlsx");

    if (filename.isEmpty()) return;
    if (!filename.contains(".xlsx")) {
        QMessageBox msg(this);
        msg.setWindowTitle("错误！");
        msg.setWindowFlag(Qt::Drawer);
        msg.setText("文件名错误！");
        msg.exec();
        return;
    }

    if (Store::getStore()->post.isEmpty()) {
        QMessageBox msg(this);
        msg.setWindowTitle("错误！");
        msg.setWindowFlag(Qt::Drawer);
        msg.setText("未录入岗位需求文件！");
        msg.exec();
        return;
    }

    ExcelWriter writer(filename, contents);
}

void AllAnalyse::loadFiles() const {
    Store::getStore()->readCvStore();
    Store::getStore()->readPostStore();
}

void AllAnalyse::createPieCharts(const QVector<QString>& contents) {
    const auto pieSeries = new QPieSeries(this);
    pieSeries->setHoleSize(0.35);

    const auto data = handleData(contents);
    for (auto it = data.constKeyValueBegin(); it != data.constKeyValueEnd(); ++it) {
        writeDataToPieChart(pieSeries, it->first, it->second, std::distance(data.constKeyValueBegin(), it));
    }

    const auto chart = new QChart;
    chart->setTitle("学历分布");
    chart->setTitleFont(QFont("微软雅黑", 12));
    chart->addSeries(pieSeries);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setVisible(false);
    ui->eduChartView->setRenderHint(QPainter::Antialiasing);
    ui->eduChartView->setRenderHint(QPainter::NonCosmeticBrushPatterns);
    ui->eduChartView->setChart(chart);
}

QString AllAnalyse::getColor(int index) const {
    QString color[] = { "#00CCCC", "#B266FF", "#FFFF99", "#FFCC99", "#99FFCC" };
    index = (index / 5 + index) % 5;
    return color[index];
}

QMap<QString, int> AllAnalyse::handleData(const QVector<QString>& contents) {
    QMap<QString, int> result;
    for (const auto& content : contents) {
        if (content != "unknown")
            result.insert(content, 0);
    }
    for (const auto& content : contents) {
        result[content]++;
    }
    return result;
}

void AllAnalyse::writeDataToPieChart(QPieSeries* pieSeries, const QString& label, const double& size, const int index) {
    const auto pieSlice_running = new QPieSlice(this);
    pieSlice_running->setValue(size);
    pieSlice_running->setLabel(label + " " + QString::number(size));
    pieSlice_running->setLabelVisible();
    pieSlice_running->setLabelFont(QFont("微软雅黑", 8));

    pieSlice_running->setColor(QColor(getColor(index)));
    pieSeries->append(pieSlice_running);
}

void AllAnalyse::openFile() {
    if (filename.isEmpty()) {
        QMessageBox msg(this);
        msg.setWindowTitle("错误");
        msg.setWindowFlag(Qt::Drawer);
        msg.setText("不存在此文件");
        msg.exec();
        return;
    }

    QFile file(filename);
    if (!file.exists()) {
        QMessageBox msg(this);
        msg.setWindowTitle("错误");
        msg.setWindowFlag(Qt::Drawer);
        msg.setText("不存在此文件");
        msg.exec();
        return;
    }

    QDesktopServices::openUrl(QUrl::fromLocalFile(filename));
}

void AllAnalyse::setLineEdit(const QVector<QVector<QString>>& contents) {
    ui->lineEdit_sum->setText(QString::number(contents.size()));
    int count = 0;
    for (const auto& content : contents) {
        if (content[6] != "unknown") {
            ++count;
        }
    }
    ui->lineEdit_ok->setText(QString::number(count));
}

QVector<QVector<QString>> AllAnalyse::generatedData() {
    const auto progressDialog =
        new QProgressDialog(tr("简历分析中"), tr("取消"), 0, Store::getStore()->cvs.size(), this, Qt::CustomizeWindowHint);
    progressDialog->setWindowModality(Qt::ApplicationModal);
    progressDialog->show();

    QVector<QVector<QString>> contents;
    int count = 1;

    for (auto it = Store::getStore()->cvs.constKeyValueBegin();
        it != Store::getStore()->cvs.constKeyValueEnd(); ++it) {
        QCoreApplication::processEvents();
        if (progressDialog->wasCanceled()) {
            progressDialog->close();
            return {};
        }

        QVector<QString> singleContent;
        singleContent.push_back(it->first);
        auto singleInfo = parser::singleInfo(it->second);
        if (singleInfo.contains("NetworkErr")) {
            QMessageBox msg;
            msg.setWindowTitle("错误");
            msg.setWindowFlag(Qt::Drawer);
            msg.setText("连接超时或未连接");
            msg.exec();
            progressDialog->close();
            return contents;
        }
        singleContent.append(singleInfo);
        contents.push_back(singleContent);
        progressDialog->setValue(count++);
    }
    return contents;
}

void AllAnalyse::createAgeBarChars(const QVector<QString>& contents) {
    const auto set = new QBarSet("SET", this);

    int group[] = { 0, 0, 0, 0 };

    for (const auto& content : contents) {
        try {
            const int num = content.toInt();
            if (num <= 26) ++group[0];
            else if (num <= 35) ++group[1];
            else if (num <= 45) ++group[2];
            else ++group[3];
        } catch (...) {}
    }

    *set << group[0] << group[1] << group[2] << group[3];
    set->setColor(QColor::fromString(getColor(0)));

    const auto series = new QBarSeries(this);
    series->append(set);

    const QStringList categories = { "18-26", "27-35", "36-45", "46+" };

    const auto chart = new QChart;
    chart->setTitle("年龄分布");
    chart->setTitleFont(QFont("微软雅黑", 12));
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setVisible(false);
    chart->addSeries(series);

    chart->createDefaultAxes();

    const auto axisX = new QBarCategoryAxis(this);
    axisX->append(categories);
    series->attachAxis(axisX);
    chart->setAxisX(axisX, series);

    const int maxNum = *std::max_element(group, group + 4);
    const auto axisY = new QValueAxis(this);
    axisY->setRange(0, maxNum);
    axisY->setTickCount(maxNum % 5 ? maxNum % 5 + 2 : 6);
    axisY->setLabelFormat("%d");
    chart->setAxisY(axisY);

    ui->ageChartView->setChart(chart);
    ui->ageChartView->setRenderHint(QPainter::Antialiasing);
}

void AllAnalyse::createWorkYearsBarChars(const QVector<QString>& contents){
    const auto set = new QBarSet("SET", this);

    int group[] = { 0, 0, 0, 0 };

    for (const auto& content : contents) {
        const int num = content.toInt();
        if (num <= 3) ++group[0];
        else if (num <= 6) ++group[1];
        else if (num <= 10) ++group[2];
        else ++group[3];
    }

    *set << group[0] << group[1] << group[2] << group[3];
    set->setColor(QColor::fromString(getColor(1)));

    // qDebug() << group[0] << group[1] << group[2] << group[3];

    const auto series = new QBarSeries;
    series->append(set);

    QStringList categories;
    categories << "0-3" << "4-6" << "7-10" << "11+";

    const auto chart = new QChart;
    chart->setTitle("工作年限分布");
    chart->setTitleFont(QFont("微软雅黑", 12));
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setVisible(false);
    chart->addSeries(series);

    chart->createDefaultAxes();

    const auto axisX = new QBarCategoryAxis(this);
    axisX->append(categories);
    series->attachAxis(axisX);
    chart->setAxisX(axisX, series);

    const int maxNum = *std::max_element(group, group + 4);
    const auto axisY = new QValueAxis(this);
    axisY->setRange(0, maxNum);
    axisY->setTickCount(maxNum % 5 ? maxNum % 5 + 2 : 6);
    axisY->setLabelFormat("%d");
    chart->setAxisY(axisY);

    ui->workChartView->setChart(chart);
    ui->workChartView->setRenderHint(QPainter::Antialiasing);
}
