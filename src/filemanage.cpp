#include "filemanage.h"
#include "ui_filemanage.h"
#include "store.h"

FileManage::FileManage(QWidget *parent) :
    QDialog(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::FileManage)
{
    ui->setupUi(this);
    this->setModal(true);
    this->setWindowTitle(tr("文件管理"));
    connect(ui->button_showMainWin, &QPushButton::clicked, this, &FileManage::showMainWin);
    connect(ui->button_deleteCv, &QPushButton::clicked, this, &FileManage::deleteCvFile);
    connect(ui->button_deletePost, &QPushButton::clicked, this, &FileManage::deletePostFile);
}

FileManage::~FileManage() {
    delete ui;
}

void FileManage::showMainWin() {
    emit showMainWinSig();
    this->close();
}

void FileManage::deleteFile(const QListWidget* listWidget, QMap<QString, QString>& map) {
    if (!listWidget->selectedItems().count()) {
        QMessageBox msg(this);
        msg.setWindowTitle(tr("错误！"));
        msg.setWindowFlag(Qt::Drawer);
        msg.setText(tr("未选择文件！"));
        msg.exec();
        return;
    }
    const QString filePath = listWidget->currentItem()->text();
    Store::deleteStore(filePath, map);
    loadFiles();

    QMessageBox msg(this);
    msg.setWindowFlag(Qt::Drawer);
    msg.setWindowTitle(tr("删除成功"));
    msg.setText(tr("删除成功！"));
    msg.exec();
}

void FileManage::loadFiles() const {
    Store::getStore()->readCvStore();
    Store::getStore()->readPostStore();
    ui->listWidget_Cvs->clear();
    ui->listWidget_Post->clear();

    for (auto item = Store::getStore()->cvs.keyBegin();
        item != Store::getStore()->cvs.keyEnd(); ++item) {
        ui->listWidget_Cvs->addItem(*item);
    }
    ui->listWidget_Cvs->sortItems();

    for (auto item = Store::getStore()->post.keyBegin();
        item != Store::getStore()->post.keyEnd(); ++item) {
        ui->listWidget_Post->addItem(*item);
    }
    ui->listWidget_Post->sortItems();
}

void FileManage::deleteCvFile() {
    deleteFile(ui->listWidget_Cvs, Store::getStore()->cvs);
}

void FileManage::deletePostFile() {
    deleteFile(ui->listWidget_Post, Store::getStore()->post);
}

