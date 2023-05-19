#ifndef MAINUI_H
#define MAINUI_H

#include <QMainWindow>
#include "cventry.h"
#include "postentry.h"
#include "singleanalyse.h"
#include "allanalyse.h"

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
    SingleAnalyse* singleAnalyseDialog;
    AllAnalyse* allAnalyseDialog;

public slots:
    void showMe();
    void showCvEntryDialog();
    void showPostEntryDialog();
    void showSingleAnalyseDialog();
    void showAllAnalyseDialog();
};

#endif // MAINUI_H
