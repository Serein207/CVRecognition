#include "singleanalyse.h"
#include "ui_singleanalyse.h"

SingleAnalyse::SingleAnalyse(QWidget *parent) :
    QDialog(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::SingleAnalyse)
{
    ui->setupUi(this);
    this->setModal(true);
    this->setWindowTitle(tr("单独分析"));
    connect(ui->button_showMainWin, &QPushButton::clicked, this, &SingleAnalyse::showMainWin);
}

SingleAnalyse::~SingleAnalyse()
{
    delete ui;
}

void SingleAnalyse::showMainWin() {
    emit showMainWinSig();
    this->close();
}
