#ifndef MAINUI_H
#define MAINUI_H

#include <QMainWindow>
#include "cventry.h"
#include "postentry.h"
#include "singleanalyse.h"
#include "allanalyse.h"
#include "filemanage.h"
#include "login.h"

namespace Ui {
class MainUI;
}

class MainUI : public QMainWindow {
    Q_OBJECT

public:
    MainUI(QWidget *parent = nullptr);
    ~MainUI();

private:
    Ui::MainUI *ui;
    CvEntry* cvEntryDialog;
    PostEntry* postEntryDialog;
    SingleAnalyse* singleAnalyseDialog;
    AllAnalyse* allAnalyseDialog;
    FileManage* fileManageDialog;
    Login* loginDialog;

public slots:
    void showMe();
    void showCvEntryDialog();
    void showPostEntryDialog();
    void showSingleAnalyseDialog();
    void showAllAnalyseDialog();
    void showFileManageDialog();
    void showLoginDialog();
};

#endif // MAINUI_H
