#ifndef FILEMANAGE_H
#define FILEMANAGE_H

#include <QDialog>

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

signals:
    void showMainWinSig();

public slots:
    void showMainWin();
};

#endif // FILEMANAGE_H
