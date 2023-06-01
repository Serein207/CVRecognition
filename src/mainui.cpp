#include "mainui.h"
#include "ui_mainui.h"

MainUI::MainUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainUI)
{
    cvEntryDialog = new CvEntry(this);
    postEntryDialog = new PostEntry(this);
    singleAnalyseDialog = new SingleAnalyse(this);
    allAnalyseDialog = new AllAnalyse(this);
    fileManageDialog = new FileManage(this);
    loginDialog = new Login(this);

    ui->setupUi(this);
    this->show();

    connect(cvEntryDialog, &CvEntry::showMainWinSig, this, &MainUI::showMe);
    connect(postEntryDialog, &PostEntry::showMainWinSig, this, &MainUI::showMe);
    connect(singleAnalyseDialog, &SingleAnalyse::showMainWinSig, this, &MainUI::showMe);
    connect(allAnalyseDialog, &AllAnalyse::showMainWinSig, this, &MainUI::showMe);
    connect(fileManageDialog, &FileManage::showMainWinSig, this, &MainUI::showMe);
    connect(loginDialog, &Login::showMainWinSig, this, &MainUI::showMe);

    connect(ui->button_CvEntry, &QPushButton::clicked, this, &MainUI::showCvEntryDialog);
    connect(ui->button_postEntry, &QPushButton::clicked, this, &MainUI::showPostEntryDialog);
    connect(ui->button_singleAnalyse, &QPushButton::clicked, this, &MainUI::showSingleAnalyseDialog);
    connect(ui->button_allAnalyse, &QPushButton::clicked, this, &MainUI::showAllAnalyseDialog);
    connect(ui->button_fileManage, &QPushButton::clicked, this, &MainUI::showFileManageDialog);
    connect(ui->button_idManage, &QPushButton::clicked, this, &MainUI::showLoginDialog);

    connect(ui->button_singleAnalyse, &QPushButton::clicked, singleAnalyseDialog, &SingleAnalyse::loadFiles);
    connect(ui->button_allAnalyse, &QPushButton::clicked, allAnalyseDialog, &AllAnalyse::loadFiles);
    connect(ui->button_fileManage, &QPushButton::clicked, fileManageDialog, &FileManage::loadFiles);
    connect(ui->button_idManage, &QPushButton::clicked, loginDialog, &Login::loadFile);
}

MainUI::~MainUI() {
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

void MainUI::showSingleAnalyseDialog() {
    singleAnalyseDialog->show();
}

void MainUI::showAllAnalyseDialog() {
    allAnalyseDialog->show();
}

void MainUI::showFileManageDialog() {
    fileManageDialog->clearCheckBoxStatus();
    fileManageDialog->show();
}

void MainUI::showLoginDialog() {
    loginDialog->show();
}
