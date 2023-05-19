#include "entry.h"
#include "txtreader.h"
#include "pdfreader.h"
#include "docxreader.h"

Entry::Entry(QWidget* parent) :
    QDialog(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint)
{
    this->setModal(true);
    this->setAcceptDrops(true);
}

void Entry::showMainWin() {
    emit showMainWinSig();
    this->close();
}

void Entry::dragEnterEvent(QDragEnterEvent* event) {
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    } else {
        event->ignore();
    }
}

void Entry::dropEvent(QDropEvent* event) {
    const QMimeData* mimeData = event->mimeData();

    if (!mimeData->hasUrls()) {
        event->ignore();
        return;
    }

    QList<QUrl> urlList = mimeData->urls();
    const QString filename = urlList[0].toLocalFile();

    if (filename.isEmpty()) {
        QMessageBox msg;
        msg.setWindowTitle("错误！");
        msg.setWindowFlag(Qt::CustomizeWindowHint);
        msg.setText("无效的文件路径！");
        msg.exec();
        return;
    }

    // TODO: 多个（种）文件同时读取，将路径存入QVector<QString>中

    readFile(filename);
    // TODO: 对于简历信息和岗位信息需要重写虚函数，并且在函数开头调用__super::readFile()
}

void Entry::readFile(const QString& filename) {
    if (filename.contains(".txt")) {
        TxtReader::read(filename);
    } else if (filename.contains(".docx")) {
        DOCXReader::getInstance()->read(filename);
    } else if (filename.contains(".pdf")) {
        PDFReader::read(filename);
    } else if (filename.contains("jpg") ||
               filename.contains("png")) {
        // TODO
    } else {
        QMessageBox msg(this);
        msg.setWindowTitle("错误！");
        msg.setWindowFlag(Qt::CustomizeWindowHint);
        msg.setText("不支持此格式的文件！");
        msg.exec();
    }
}

void Entry::selectFile()  {
    const QString userName = QDir::home().dirName();
    const QString defaultPath = QString("C:/Users/%1/Documents").arg(userName);
    const QString path = QFileDialog::getOpenFileName(this, "打开",
                       defaultPath, "*.txt;*.png;*.jpg;*.pdf;*.docx");

    if (path.isEmpty()) return;

    readFile(path);
    // TODO: 对于简历信息和岗位信息需要重写虚函数，并且在函数开头调用__super::readFile()
}
