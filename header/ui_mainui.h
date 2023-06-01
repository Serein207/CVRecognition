/********************************************************************************
** Form generated from reading UI file 'mainui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINUI_H
#define UI_MAINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainUI
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_infoEntry;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_CvEntry;
    QPushButton *button_postEntry;
    QLabel *label_CvAnalyse;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_allAnalyse;
    QPushButton *button_singleAnalyse;
    QPushButton *button_fileManage;
    QPushButton *button_idManage;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainUI)
    {
        if (MainUI->objectName().isEmpty())
            MainUI->setObjectName("MainUI");
        MainUI->resize(600, 400);
        MainUI->setMinimumSize(QSize(600, 400));
        MainUI->setMaximumSize(QSize(600, 400));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei UI Light")});
        MainUI->setFont(font);
        MainUI->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"  border-radius: 5px;\n"
"  background: rgb(255, 255, 254);\n"
"}"));
        centralwidget = new QWidget(MainUI);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(".QPushButton {\n"
"  border-radius: 15px;\n"
"  border: none;\n"
"  color: rgb(252, 252, 252);\n"
"  background-color: rgb(16, 171, 255);\n"
"  text-align: center;\n"
"}\n"
"\n"
".QPushButton:hover {\n"
"  background-color: rgb(7, 156, 255);\n"
"}\n"
""));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 10, 511, 331));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_infoEntry = new QLabel(layoutWidget);
        label_infoEntry->setObjectName("label_infoEntry");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei UI Light")});
        font1.setPointSize(14);
        label_infoEntry->setFont(font1);
        label_infoEntry->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(label_infoEntry);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName("horizontalLayout");
        button_CvEntry = new QPushButton(layoutWidget);
        button_CvEntry->setObjectName("button_CvEntry");
        button_CvEntry->setMinimumSize(QSize(180, 80));
        button_CvEntry->setMaximumSize(QSize(180, 80));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft JhengHei UI Light")});
        font2.setPointSize(18);
        button_CvEntry->setFont(font2);
        button_CvEntry->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(button_CvEntry);

        button_postEntry = new QPushButton(layoutWidget);
        button_postEntry->setObjectName("button_postEntry");
        button_postEntry->setMinimumSize(QSize(180, 80));
        button_postEntry->setMaximumSize(QSize(180, 80));
        button_postEntry->setFont(font2);
        button_postEntry->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(button_postEntry);


        verticalLayout->addLayout(horizontalLayout);

        label_CvAnalyse = new QLabel(layoutWidget);
        label_CvAnalyse->setObjectName("label_CvAnalyse");
        label_CvAnalyse->setFont(font1);

        verticalLayout->addWidget(label_CvAnalyse);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        button_allAnalyse = new QPushButton(layoutWidget);
        button_allAnalyse->setObjectName("button_allAnalyse");
        button_allAnalyse->setMinimumSize(QSize(180, 80));
        button_allAnalyse->setMaximumSize(QSize(180, 80));
        button_allAnalyse->setFont(font2);
        button_allAnalyse->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(button_allAnalyse);

        button_singleAnalyse = new QPushButton(layoutWidget);
        button_singleAnalyse->setObjectName("button_singleAnalyse");
        button_singleAnalyse->setMinimumSize(QSize(180, 80));
        button_singleAnalyse->setMaximumSize(QSize(180, 80));
        button_singleAnalyse->setFont(font2);
        button_singleAnalyse->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(button_singleAnalyse);


        verticalLayout->addLayout(horizontalLayout_2);

        button_fileManage = new QPushButton(centralwidget);
        button_fileManage->setObjectName("button_fileManage");
        button_fileManage->setGeometry(QRect(390, 10, 91, 31));
        button_idManage = new QPushButton(centralwidget);
        button_idManage->setObjectName("button_idManage");
        button_idManage->setGeometry(QRect(490, 10, 91, 31));
        MainUI->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainUI);
        statusBar->setObjectName("statusBar");
        MainUI->setStatusBar(statusBar);

        retranslateUi(MainUI);

        QMetaObject::connectSlotsByName(MainUI);
    } // setupUi

    void retranslateUi(QMainWindow *MainUI)
    {
        MainUI->setWindowTitle(QCoreApplication::translate("MainUI", "\346\231\272\350\203\275\347\256\200\345\216\206\350\257\206\345\210\253", nullptr));
        label_infoEntry->setText(QCoreApplication::translate("MainUI", "\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
        button_CvEntry->setText(QCoreApplication::translate("MainUI", "\347\256\200\345\216\206\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
        button_postEntry->setText(QCoreApplication::translate("MainUI", "\345\262\227\344\275\215\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
        label_CvAnalyse->setText(QCoreApplication::translate("MainUI", "<html><head/><body><p>\347\256\200\345\216\206\345\210\206\346\236\220</p></body></html>", nullptr));
        button_allAnalyse->setText(QCoreApplication::translate("MainUI", "\345\205\250\351\203\250\345\210\206\346\236\220", nullptr));
        button_singleAnalyse->setText(QCoreApplication::translate("MainUI", "\345\215\225\347\213\254\345\210\206\346\236\220", nullptr));
        button_fileManage->setText(QCoreApplication::translate("MainUI", "\346\226\207\344\273\266\347\256\241\347\220\206", nullptr));
        button_idManage->setText(QCoreApplication::translate("MainUI", "\350\264\246\345\217\267\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainUI: public Ui_MainUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
