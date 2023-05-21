#ifndef FILEMANAGE_H
#define FILEMANAGE_H

#include <QDialog>
#include <QListWidget>

namespace Ui {
class FileManage;
}

class FileManage : public QDialog
{
    Q_OBJECT

public:
    explicit FileManage(QWidget *parent = nullptr);
    ~FileManage();

private:
    Ui::FileManage *ui;

    void deleteFile(const QListWidget* listWidget, QMap<QString, QString>& map);

signals:
    void showMainWinSig();

public slots:
    void showMainWin();
    void deleteCvFile();
    void deletePostFile();
    void loadFiles() const;
};

#endif // FILEMANAGE_H
