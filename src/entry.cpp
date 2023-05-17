#include "entry.h"
#include "txtreader.h"

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
    QString filename = urlList[0].toLocalFile();

    if (filename.isEmpty()) {
        QMessageBox msg;
        msg.setWindowTitle("错误！");
        msg.setWindowFlag(Qt::CustomizeWindowHint);
        msg.setText("无效的文件路径！");
        msg.exec();
        return;
    }

    readFile(filename);
}

void Entry::readFile(QString& filename) {
    if (filename.contains(".txt")) {
        TxtReader::read(filename);
    } else if (filename.contains(".docx")) {
        // TODO
    } else if (filename.contains(".pdf")) {
        // TODO
    } else if (filename.contains("jpg") ||
               filename.contains("png")) {
        //TODO
    } else {
        QMessageBox msg(this);
        msg.setWindowTitle("错误！");
        msg.setWindowFlag(Qt::CustomizeWindowHint);
        msg.setText("不支持此格式的文件！");
        msg.exec();
    }
}

void Entry::selectFile()  {
    QDir dir;
    QString userName = dir.home().dirName();
    QString defaultPath = QString("C:/Users/%1/Documents").arg(userName);
    QString path = QFileDialog::getOpenFileName(this, "打开",
                       defaultPath, "*.txt;*.png;*.jpg;*.pdf;*.docx");
    readFile(path);
}
