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
    QStringList paths;
    for (const auto& url : urlList) {
        const QString filename = url.toLocalFile();
        if (filename.isEmpty()) {
            QMessageBox msg;
            msg.setWindowTitle("错误！");
            msg.setWindowFlag(Qt::CustomizeWindowHint);
            msg.setText("无效的文件路径！");
            msg.exec();
            return;
        }
        paths.append(filename);
    }

    handleFilePaths(paths);
}

QMap<QString, QString> Entry::getContents() {
    if (m_filePaths.isEmpty()) {
        QMessageBox msg(this);
        msg.setWindowFlag(Qt::CustomizeWindowHint);
        msg.setWindowTitle(tr("错误！"));
        msg.setText(tr("文件列表为空！"));
        msg.exec();
        return QMap<QString, QString>{};
    }

    QMap<QString, QString> contents;
    const auto progressDialog = 
        new QProgressDialog(tr("正在读取"), tr("取消"), 0, m_filePaths.size(), this, Qt::CustomizeWindowHint);
    progressDialog->setWindowModality(Qt::ApplicationModal);
    progressDialog->setWindowTitle(tr("文件读取中"));
    progressDialog->show();

    int count = 1;
    foreach (const auto& filename, m_filePaths) {
        QCoreApplication::processEvents();
        if (progressDialog->wasCanceled()) {
            contents.clear();
            progressDialog->close();
            break;
        }
        if (filename.contains(".txt")) {
            contents.insert(filename, TxtReader::read(filename));
        }
        else if (filename.contains(".docx")) {
            contents.insert(filename, DOCXReader::getInstance()->read(filename));
        }
        else if (filename.contains(".pdf")) {
            contents.insert(filename, PDFReader::read(filename));
        }
        else if (filename.contains("jpg") ||
                 filename.contains("png")) {
            // TODO
            // contents.insert(filename, PicReader::read(filename));
        }
        progressDialog->setValue(count++);
    }
    return contents;
}

void Entry::selectFile()  {
    const QString userName = QDir::home().dirName();
    const QString defaultPath = QString("C:/Users/%1/Documents").arg(userName);
    const QStringList paths = QFileDialog::getOpenFileNames(this, "打开",
                       defaultPath, "*.txt;*.png;*.jpg;*.pdf;*.docx");

    if (paths.isEmpty()) return;

    handleFilePaths(paths);
}

void Entry::handleFilePaths(const QStringList& paths) {
    for (const auto& filename: paths) {
        if (isContained(filename, tr(".txt"), tr(".docx"), tr(".pdf"), tr(".jpg"), tr(".png"))) {
            m_filePaths.insert(filename);
        }
        else {
            QMessageBox msg(this);
            msg.setWindowTitle("错误！");
            msg.setWindowFlag(Qt::CustomizeWindowHint);
            QString errorMsg = QString("不支持此格式的文件\n出错文件：%1").arg(filename);
            msg.setText(errorMsg);
            msg.exec();
        }
    }
}

template <typename... Args>
bool Entry::isContained(const QString& filename, const Args&... formats) {
    return (filename.contains(formats) || ...);
}
