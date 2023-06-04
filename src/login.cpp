#include "login.h"
#include <QMessageBox>
#include <QDir>
#include "cmssinterface.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QDialog(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    loadFile();
    connect(ui->button_login, &QPushButton::clicked, this, &Login::login);
    connect(ui->button_showMainWin, &QPushButton::clicked, this, &Login::showMainWin);
}

Login::~Login() {
    delete ui;
}

void Login::showMainWin() {
    emit showMainWinSig();
    this->close();
}

void Login::login() {
    if (ui->lineEdit_key->text().isEmpty() || ui->lineEdit_secret->text().isEmpty()) {
        QMessageBox msg(this);
        msg.setWindowTitle("错误！");
        msg.setWindowFlag(Qt::Drawer);
        msg.setText("输入框为空！");
        msg.exec();
        return;
    }
    writeFile();
}

void Login::writeFile() {
    const QDir dataDir(".\\data");
    if (!dataDir.exists()) {
        if (!QDir().mkdir(".\\data")) {
            QMessageBox msg;
            msg.setWindowFlag(Qt::Drawer);
            msg.setWindowTitle("错误！");
            msg.setText("文件夹data创建失败");
            msg.exec();
            return;
        }
    }

    QDir dir(QString(".\\data\\id"));

    if (!dir.exists()) {
        if (!QDir().mkdir(QString(".\\data\\id"))) {
            QMessageBox msg;
            msg.setWindowFlag(Qt::Drawer);
            msg.setWindowTitle("错误！");
            msg.setText(QString("文件夹id创建失败"));
            msg.exec();
            return;
        }
    }

    QFile file(".\\data\\id\\id.txt");
    if (!file.open(QFile::ReadWrite | QFile::Text)) {
        QMessageBox msg;
        msg.setWindowFlag(Qt::Drawer);
        msg.setWindowTitle("错误！");
        msg.setText("文件打开失败");
        msg.exec();
        return;
    }

    QString ak = ui->lineEdit_key->text();
    QString sk = ui->lineEdit_secret->text();
    file.write(ak.toUtf8());
    file.write(",");
    file.write(sk.toUtf8());
    CmssInterface::Ak = ak.toStdString();
    CmssInterface::Sk = sk.toStdString();

    file.close();
}

void Login::loadFile() {
    const QDir dataDir(".\\data");
    if (!dataDir.exists()) {
        if (!QDir().mkdir(".\\data")) {
            QMessageBox msg;
            msg.setWindowFlag(Qt::Drawer);
            msg.setWindowTitle("错误！");
            msg.setText("文件夹data创建失败");
            msg.exec();
            return;
        }
    }

    QDir dir(QString(".\\data\\id"));

    if (!dir.exists()) {
        if (!QDir().mkdir(QString(".\\data\\id"))) {
            QMessageBox msg;
            msg.setWindowFlag(Qt::Drawer);
            msg.setWindowTitle("错误！");
            msg.setText(QString("文件夹id创建失败"));
            msg.exec();
            return;
        }
    }

    QFile file(".\\data\\id\\id.txt");
    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox msg;
        msg.setWindowFlag(Qt::Drawer);
        msg.setWindowTitle("错误！");
        msg.setText("文件打开失败");
        msg.exec();
        return;
    }
    
    // file.write(CmssInterface::Ak.c_str());
    // file.write(",");
    // file.write(CmssInterface::Sk.c_str());

    QTextStream in(&file);

    QStringList split = in.readLine().split(",");

    //qDebug() << split;

    if (split.size() != 2) return;

    ui->lineEdit_key->setText(split[0]);
    ui->lineEdit_secret->setText(split[1]);
    CmssInterface::Ak = split[0].toStdString();
    CmssInterface::Sk = split[1].toStdString();

    file.close();
}
