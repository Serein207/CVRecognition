#include "mainui.h"
#include "ui_mainui.h"

MainUI::MainUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainUI)
{
    cvEntryDialog = new CvEntry(this);
    postEntryDialog = new PostEntry(this);

    ui->setupUi(this);
    this->show();

    connect(cvEntryDialog, &CvEntry::showMainWinSig, this, &MainUI::showMe);
    connect(postEntryDialog, &PostEntry::showMainWinSig, this, &MainUI::showMe);

    connect(ui->button_CvEntry, &QPushButton::clicked, this, &MainUI::showCvEntryDialog);
    connect(ui->button_postEntry, &QPushButton::clicked, this, &MainUI::showPostEntryDialog);
}

MainUI::~MainUI()
{
    delete ui;
}

void MainUI::showMe() {
    this->show();
}

void MainUI::showCvEntryDialog() {
    cvEntryDialog->show();
}

void MainUI::showPostEntryDialog() {
    postEntryDialog->show();
}
