#include "cventry.h"
#include "ui_cventry.h"


CvEntry::CvEntry(QWidget *parent) :
    Entry(parent),
    ui(new Ui::CvEntry)
{
    this->setModal(true);
    ui->setupUi(this);
    ui->textEdit->setAcceptDrops(false);
    connect(ui->button_showMainWin, &QPushButton::clicked, this, &CvEntry::showMainWin);
    connect(ui->button_SelectFile, &QPushButton::clicked, this, &CvEntry::selectFile);
}

CvEntry::~CvEntry()
{
    delete ui;
}
