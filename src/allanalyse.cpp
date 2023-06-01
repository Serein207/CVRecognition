#include "allanalyse.h"
#include "ui_allanalyse.h"
#include "excelwriter.h"
#include "store.h"
#include "parserInfo.h"
#include <QDir>
#include <QFileDialog>
#include <QProgressDialog>

AllAnalyse::AllAnalyse(QWidget *parent) :
    QDialog(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::AllAnalyse)
{
    ui->setupUi(this);
    this->setModal(true);
    this->setWindowTitle(tr("全部分析"));
    loadFiles();
    connect(ui->button_showMainWin, &QPushButton::clicked, this, &AllAnalyse::showMainWin);
    connect(ui->button_analyse, &QPushButton::clicked, this, &AllAnalyse::anlalyseSlot);
}

AllAnalyse::~AllAnalyse() {
    delete ui;
}

void AllAnalyse::showMainWin() {
    emit showMainWinSig();
    this->close();
}

void AllAnalyse::anlalyseSlot() {
    const QString userName = QDir::home().dirName();
    const QString defaultName = QDate::currentDate().toString("yyyyMMdd") + QTime::currentTime().toString("hhmmss");
    const QString defaultPath = QString("C:/Users/%1/Documents").arg(userName) + "/" + defaultName;
    const QString filename = QFileDialog::getSaveFileName(this, tr("保存到"), defaultPath, "*.xlsx");
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

    const auto progressDialog =
        new QProgressDialog(tr("正在分析"), tr("取消"), 0, Store::getStore()->cvs.size() + 2, this, Qt::CustomizeWindowHint);
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

    ExcelWriter writer(filename, contents);
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