#include "cventry.h"
#include "ui_cventry.h"
#include "store.h"

CvEntry::CvEntry(QWidget *parent) :
    Entry(parent),
    ui(new Ui::CvEntry)
{
    this->setModal(true);
    ui->setupUi(this);
    ui->listWidget->setAcceptDrops(false);
    connect(ui->button_showMainWin, &QPushButton::clicked, this, &CvEntry::showMainWin);
    connect(ui->button_SelectFile, &QPushButton::clicked, this, &CvEntry::selectFile);
    connect(ui->button_input, &QPushButton::clicked, this, &CvEntry::readFile);
}

CvEntry::~CvEntry()
{
    delete ui;
}

void CvEntry::readFile() {
    Store::getStore()->cvs.insert(getContents());
    m_filePaths.clear();
    ui->listWidget->clear();
}

void CvEntry::dropEvent(QDropEvent* event) {
    Entry::dropEvent(event);
    ui->listWidget->clear();
    foreach (const auto& path, m_filePaths) {
        ui->listWidget->addItem(path);
        ui->listWidget->sortItems();
    }
}

void CvEntry::selectFile() {
    Entry::selectFile();
    ui->listWidget->clear();
    foreach(const auto & path, m_filePaths) {
        ui->listWidget->addItem(path);
        ui->listWidget->sortItems();
    }
}
