#include "singleanalyse.h"
#include "ui_singleanalyse.h"

SingleAnalyse::SingleAnalyse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingleAnalyse)
{
    ui->setupUi(this);
}

SingleAnalyse::~SingleAnalyse()
{
    delete ui;
}
