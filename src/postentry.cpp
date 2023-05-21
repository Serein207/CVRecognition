#include "postentry.h"
#include "ui_postentry.h"
#include "store.h"

PostEntry::PostEntry(QWidget *parent) :
    Entry(parent),
    ui(new Ui::PostEntry)
{
    this->setModal(true);
    ui->setupUi(this);
    ui->listWidget->setAcceptDrops(false);
    connect(ui->button_showMainWin, &QPushButton::clicked, this, &PostEntry::showMainWin);
    connect(ui->button_SelectFile, &QPushButton::clicked, this, &PostEntry::selectFile);
    connect(ui->button_input, &QPushButton::clicked, this, &PostEntry::readFile);
}

PostEntry::~PostEntry() {
    delete ui;
}

void PostEntry::readFile() {
    Store::getStore()->post.insert(getContents());
    Store::getStore()->writePostStore();
    m_filePaths.clear();
    ui->listWidget->clear();
}

void PostEntry::dropEvent(QDropEvent* event) {
    Entry::dropEvent(event);
    foreach (const auto& path, m_filePaths) {
        ui->listWidget->addItem(path);
        ui->listWidget->sortItems();
    }
}

void PostEntry::selectFile() {
    Entry::selectFile();
    ui->listWidget->clear();
    foreach(const auto & path, m_filePaths) {
        ui->listWidget->addItem(path);
        ui->listWidget->sortItems();
    }
}
