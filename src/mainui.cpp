#include "mainui.h"
#include "ui_mainui.h"
#include "test.h"

MainUI::MainUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainUI)
{
    ui->setupUi(this);
    QString result = test().c_str();
    ui->lineEdit->setText(result);
    this->show();
}

MainUI::~MainUI()
{
    delete ui;
}
