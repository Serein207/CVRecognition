#include "filemanage.h"
#include "ui_filemanage.h"

FileManage::FileManage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileManage)
{
    ui->setupUi(this);
    connect(ui->button_showMainWin, &QPushButton::clicked, this, &FileManage::showMainWin);
}

FileManage::~FileManage() {
    delete ui;
}

void FileManage::showMainWin() {
    emit showMainWinSig();
    this->close();
}
