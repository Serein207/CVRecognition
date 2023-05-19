#include "cventry.h"
#include "ui_cventry.h"
#include "store.h"

CvEntry::CvEntry(QWidget *parent) :
    Entry(parent),
    ui(new Ui::CvEntry)
{
    this->setModal(true);
    ui->setupUi(this);
    ui->textEdit->setAcceptDrops(false);
    connect(ui->button_showMainWin, &QPushButton::clicked, this, &CvEntry::showMainWin);
    connect(ui->button_SelectFile, &QPushButton::clicked, this, &CvEntry::selectFile);
    connect(ui->button_input, &QPushButton::clicked, this, &CvEntry::readFile);
}

CvEntry::~CvEntry()
{
    delete ui;
}

void CvEntry::readFile() {
    Store::getStore()->m_cvs += getContents();
    m_filePaths.clear();
    ui->textEdit->clear();
}

void CvEntry::dropEvent(QDropEvent* event) {
    __super::dropEvent(event);
    ui->textEdit->clear();
    for (const auto& path : m_filePaths) {
        ui->textEdit->append(path);
    }
}
