#include "allanalyse.h"
#include "ui_allanalyse.h"

AllAnalyse::AllAnalyse(QWidget *parent) :
    QDialog(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::AllAnalyse)
{
    ui->setupUi(this);
    this->setModal(true);
    this->setWindowTitle(tr("全部分析"));
    connect(ui->button_showMainWin, &QPushButton::clicked, this, &AllAnalyse::showMainWin);
}

AllAnalyse::~AllAnalyse()
{
    delete ui;
}

void AllAnalyse::showMainWin() {
    emit showMainWinSig();
    this->close();
}
