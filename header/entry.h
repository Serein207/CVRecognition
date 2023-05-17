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

class Entry : public QDialog {
    Q_OBJECT

public:
    explicit Entry(QWidget *parent = nullptr);
    virtual ~Entry() = default;

protected:
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);

private:
    void readFile(QString& filename);

signals:
    void showMainWinSig();

public slots:
    void showMainWin();
    void selectFile();
};

#endif // ENTRY_H
