#include "singleanalyse.h"
#include "ui_singleanalyse.h"
#include "store.h"
#include "cmssinterface.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>

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

    qDebug() << path;
    qDebug() << content;

    // TODO: 分析简历并在文本框内显示内容
    for (int i = 0; i < content.length(); i += 399) {
        QJsonDocument entityJson = QJsonDocument::fromJson(
            CmssInterface::getCmssInterface()->
                getEntityJson(content.mid(i, 399)).toUtf8()
        );
        if (entityJson["state"] != QJsonValue("OK")) {
            QMessageBox msg;
            msg.setWindowTitle("错误！");
            msg.setWindowFlag(Qt::Drawer);
            msg.setText("网络连接失败");
            msg.exec();
            return;
        }

        QJsonValue itemsValue = entityJson["body"]["items"];
        if (itemsValue.type() == QJsonValue::Array) {
            QJsonArray itemsArray = itemsValue.toArray();
            for (int j = 0; j < itemsArray.count(); ++j) {
                QJsonArray nerTokens = itemsArray.at(j)["nerTokens"].toArray();
                for (int k = 0; k < nerTokens.count(); ++k) {
                    if (nerTokens.at(k)["type"].toString().contains("PER")) {
                        const QString name = nerTokens.at(j)["word"].toString();
                        qDebug() << name;
                        ui->name->setText(name);
                        return;
                    }
                }
            }
        }
    }
    ui->name->setText("unknown");
}
