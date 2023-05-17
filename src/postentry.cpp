#include "postentry.h"
#include "ui_postentry.h"

PostEntry::PostEntry(QWidget *parent) :
    Entry(parent),
    ui(new Ui::PostEntry)
{
    this->setModal(true);
    ui->setupUi(this);
    ui->textEdit->setAcceptDrops(false);
    connect(ui->button_showMainWin, &QPushButton::clicked, this, &PostEntry::showMainWin);
    connect(ui->button_SelectFile, &QPushButton::clicked, this, &PostEntry::selectFile);
}

PostEntry::~PostEntry()
{
    delete ui;
}
