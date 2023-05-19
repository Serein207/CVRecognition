#ifndef ENTRY_H
#define ENTRY_H

#include <QDialog>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QList>
#include <QUrl>
#include <QString>
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>
#include <QSet>
#include <QProgressDialog>
#include <QCoreApplication>

class Entry : public QDialog {
    Q_OBJECT

public:
    explicit Entry(QWidget *parent = nullptr);
    virtual ~Entry() = default;

protected:
    void dragEnterEvent(QDragEnterEvent* event) override;
    virtual void dropEvent(QDropEvent* event) override;
    QMap<QString, QString> getContents();

    QSet<QString> m_filePaths;

private:
    void handleFilePaths(const QStringList& paths);

    template <typename... Args>
    static bool isContained(const QString& filename, const Args&... formats);

signals:
    void showMainWinSig();

public slots:
    void showMainWin();
    virtual void selectFile();
};

#endif // ENTRY_H
