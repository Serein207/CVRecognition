#include "allanalyse.h"
#include "ui_allanalyse.h"
#include "excelwriter.h"
#include "store.h"
#include "parserInfo.h"
#include <QDir>
#include <QFileDialog>
#include <QProgressDialog>
#include <QDesktopServices>

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

void AllAnalyse::anlalyseSlot() {
    const auto progressDialog =
        new QProgressDialog(tr("正在分析"), tr("取消"), 0, Store::getStore()->cvs.size() + 3ll, this, Qt::CustomizeWindowHint);
    progressDialog->setWindowModality(Qt::ApplicationModal);
    progressDialog->setWindowTitle(tr("简历分析中"));
    progressDialog->show();

    QVector<QVector<QString>> contents;
    int count = 1;
    for (auto it = Store::getStore()->cvs.constKeyValueBegin();
        it != Store::getStore()->cvs.constKeyValueEnd(); ++it) {
        QCoreApplication::processEvents();
        if (progressDialog->wasCanceled()) {
            contents.clear();
            progressDialog->close();
            return;
        }
        QVector<QString> singleContent;
        singleContent.push_back(it->first);
        singleContent.append(parser::singleInfo(it->second));
        contents.push_back(singleContent);
        progressDialog->setValue(count++);
    }

    getExcel(contents);
    progressDialog->setValue(count++);

    QVector<QString> edu;
    for(const auto& content : contents)
    {
        edu.push_back(content[3]);
    }
    createpieSewise(edu);
    progressDialog->setValue(count++);

    setLineEdit(contents);

    ui->fileInfo->setText("全部数据已保存到excel文件：\n" + filename);
    ui->fileInfo->show();
    ui->button_openFile->show();

    progressDialog->setValue(progressDialog->maximum());

    QMessageBox msg(this);
    msg.setWindowTitle("成功");
    msg.setWindowFlag(Qt::Drawer);
    msg.setText("完成分析");
    msg.exec();
    
}

void AllAnalyse::loadFiles() const {
    Store::getStore()->readCvStore();
    Store::getStore()->readPostStore();
}

void AllAnalyse::createpieSewise(const QVector<QString>& contents) {
    QPieSeries* pieSeries = new QPieSeries;
    //中间圆与大圆的比例
    pieSeries->setHoleSize(0.35);
    //扇形及数据
    const auto data = handleData(contents);
    for (auto it = data.constKeyValueBegin(); it != data.constKeyValueEnd(); ++it) {
        writeDataToPieChart(pieSeries, it->first, it->second, std::distance(data.constKeyValueBegin(), it));
    }
    // 图表视图
    QChart* chart = new QChart;
    chart->setTitle("学历分布");
    chart->setTitleFont(QFont("微软雅黑", 12));
    chart->addSeries(pieSeries);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setVisible(false);
    ui->eduChartView->setRenderHint(QPainter::Antialiasing);
    ui->eduChartView->setRenderHint(QPainter::NonCosmeticBrushPatterns);
    ui->eduChartView->setChart(chart);
}

QString AllAnalyse::getRandomColor(int index) {
    QString color[] = { "#00CCCC", "#B266FF", "#FFFF99", "#FFCC99", "#99FFCC" };
    index = (index / 5 + index) % 5;
    return color[index];
}

QMap<QString, int> AllAnalyse::handleData(const QVector<QString>& contents) {
    QMap<QString, int> result;
    for (const auto& content : contents) {
        result.insert(content, 0);
    }
    for (const auto& content : contents) {
        result[content]++;
    }
    return result;
}

void AllAnalyse::writeDataToPieChart(QPieSeries* pieSeries, const QString& label, const double& size, const int index) {
    QPieSlice* pieSlice_running = new QPieSlice();
    pieSlice_running->setValue(size);//扇形占整个圆的百分比
    pieSlice_running->setLabel(label + " " + QString::number(size));//标签
    pieSlice_running->setLabelVisible();
    pieSlice_running->setLabelFont(QFont("微软雅黑", 8));

    pieSlice_running->setColor(QColor(getRandomColor(index)));//颜色调用下面的getRandomColor()函数得到每次的都不一样。
    pieSeries->append(pieSlice_running);//将扇形加入到圆上
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
