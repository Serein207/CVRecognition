#ifndef MAINUI_H
#define MAINUI_H

#include <QMainWindow>
#include "cventry.h"
#include "postentry.h"

namespace Ui {
class MainUI;
}

class MainUI : public QMainWindow
{
    Q_OBJECT

public:
    MainUI(QWidget *parent = nullptr);
    ~MainUI();

private:
    Ui::MainUI *ui;
    CvEntry* cvEntryDialog;
    PostEntry* postEntryDialog;

public slots:
    void showMe();
    void showCvEntryDialog();
    void showPostEntryDialog();
};

#endif // MAINUI_H
