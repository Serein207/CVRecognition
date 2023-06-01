#include "singleanalyse.h"
#include "ui_singleanalyse.h"
#include "store.h"
#include "parserInfo.h"
#include "matchingrateanalysis.h"

SingleAnalyse::SingleAnalyse(QWidget *parent) :
    QDialog(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::SingleAnalyse)
{
    ui->setupUi(this);
    this->setModal(true);
    this->setWindowTitle(tr("单独分析"));
    connect(ui->button_showMainWin, &QPushButton::clicked, this, &SingleAnalyse::showMainWin);
    connect(ui->button_analyse, &QPushButton::clicked, this, &SingleAnalyse::analyse);
}

SingleAnalyse::~SingleAnalyse() {
    delete ui;
}

void SingleAnalyse::showMainWin() {
    emit showMainWinSig();
    this->close();
}

void SingleAnalyse::loadFiles() const {
    Store::getStore()->readCvStore();
    Store::getStore()->readPostStore();
    ui->listWidget->clear();
    for (auto item = Store::getStore()->cvs.keyBegin();
        item != Store::getStore()->cvs.keyEnd(); ++item) {
        ui->listWidget->addItem(*item);
    }
    ui->listWidget->sortItems();
}

void SingleAnalyse::analyse() {
    if (!ui->listWidget->selectedItems().count()) {
        QMessageBox msg(this);
        msg.setWindowTitle(tr("错误！"));
        msg.setWindowFlag(Qt::Drawer);
        msg.setText(tr("未选择简历！"));
        msg.exec();
        return;
    }
    const auto path = ui->listWidget->currentItem()->text();
    if (path.isEmpty()) {
        QMessageBox msg(this);
        msg.setWindowTitle(tr("错误！"));
        msg.setWindowFlag(Qt::Drawer);
        msg.setText(tr("文件路径为空！"));
        msg.exec();
        return;
    }

    const auto content = Store::getStore()->cvs[path];

    //qDebug() << path;
    //qDebug() << content;
    //feipiao test,下面的这段代码其中有qdebug 输出调试信息
    //parser::parserPost(Store::getStore()->post);

    const auto texts = parser::singleInfo(content);
    ui->name->setText(texts[0]);
    ui->age->setText(texts[1]);
    ui->education->setText(texts[2]);
    ui->college->setText(texts[3]);
    ui->work->setText(texts[4]);
    ui->recommend->setText(texts[5]);
}
