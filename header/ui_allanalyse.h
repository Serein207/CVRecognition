/********************************************************************************
** Form generated from reading UI file 'allanalyse.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLANALYSE_H
#define UI_ALLANALYSE_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AllAnalyse
{
public:
    QPushButton *button_showMainWin;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_1;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *button_analyse;
    QWidget *widget;
    QGridLayout *gridLayout;
    QChartView *eduChartView;
    QChartView *workChartView;
    QChartView *ageChartView;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLineEdit *lineEdit_sum;
    QLabel *label_3;
    QLineEdit *lineEdit_ok;
    QLabel *fileInfo;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_openFile;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *AllAnalyse)
    {
        if (AllAnalyse->objectName().isEmpty())
            AllAnalyse->setObjectName("AllAnalyse");
        AllAnalyse->setWindowModality(Qt::WindowModal);
        AllAnalyse->resize(900, 750);
        AllAnalyse->setMinimumSize(QSize(900, 750));
        AllAnalyse->setMaximumSize(QSize(900, 750));
        AllAnalyse->setStyleSheet(QString::fromUtf8("QDialog {\n"
"  background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLineEdit {\n"
" border: none;\n"
"}"));
        button_showMainWin = new QPushButton(AllAnalyse);
        button_showMainWin->setObjectName("button_showMainWin");
        button_showMainWin->setGeometry(QRect(10, 10, 61, 24));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft JhengHei UI Light")});
        button_showMainWin->setFont(font);
        button_showMainWin->setCursor(QCursor(Qt::PointingHandCursor));
        button_showMainWin->setStyleSheet(QString::fromUtf8("* {\n"
"  border-radius: 15px;\n"
"  border: none;\n"
"  background-color: rgb(255, 255, 255);\n"
"  text-align: left;\n"
"}"));
        layoutWidget = new QWidget(AllAnalyse);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(22, 42, 130, 61));
        verticalLayout_1 = new QVBoxLayout(layoutWidget);
        verticalLayout_1->setObjectName("verticalLayout_1");
        verticalLayout_1->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei UI Light")});
        font1.setPointSize(16);
        label_2->setFont(font1);

        verticalLayout_1->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        button_analyse = new QPushButton(layoutWidget);
        button_analyse->setObjectName("button_analyse");
        button_analyse->setFont(font);

        horizontalLayout_2->addWidget(button_analyse);


        verticalLayout_1->addLayout(horizontalLayout_2);

        widget = new QWidget(AllAnalyse);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(41, 121, 801, 581));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        eduChartView = new QChartView(widget);
        eduChartView->setObjectName("eduChartView");

        gridLayout->addWidget(eduChartView, 0, 0, 1, 1);

        workChartView = new QChartView(widget);
        workChartView->setObjectName("workChartView");

        gridLayout->addWidget(workChartView, 0, 1, 1, 1);

        ageChartView = new QChartView(widget);
        ageChartView->setObjectName("ageChartView");

        gridLayout->addWidget(ageChartView, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(label);

        lineEdit_sum = new QLineEdit(widget);
        lineEdit_sum->setObjectName("lineEdit_sum");
        lineEdit_sum->setMinimumSize(QSize(0, 60));
        lineEdit_sum->setMaximumSize(QSize(300, 60));
        QFont font3;
        font3.setPointSize(28);
        font3.setBold(true);
        lineEdit_sum->setFont(font3);
        lineEdit_sum->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_sum);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(label_3);

        lineEdit_ok = new QLineEdit(widget);
        lineEdit_ok->setObjectName("lineEdit_ok");
        lineEdit_ok->setMinimumSize(QSize(0, 60));
        lineEdit_ok->setMaximumSize(QSize(300, 60));
        lineEdit_ok->setFont(font3);
        lineEdit_ok->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_ok);

        fileInfo = new QLabel(widget);
        fileInfo->setObjectName("fileInfo");
        QFont font4;
        font4.setPointSize(11);
        fileInfo->setFont(font4);

        verticalLayout->addWidget(fileInfo);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        button_openFile = new QPushButton(widget);
        button_openFile->setObjectName("button_openFile");

        horizontalLayout->addWidget(button_openFile);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_3, 1, 1, 1, 1);


        retranslateUi(AllAnalyse);

        QMetaObject::connectSlotsByName(AllAnalyse);
    } // setupUi

    void retranslateUi(QDialog *AllAnalyse)
    {
        AllAnalyse->setWindowTitle(QCoreApplication::translate("AllAnalyse", "Dialog", nullptr));
        button_showMainWin->setText(QCoreApplication::translate("AllAnalyse", "< \350\277\224\345\233\236", nullptr));
        label_2->setText(QCoreApplication::translate("AllAnalyse", "\345\205\250\351\203\250\345\210\206\346\236\220", nullptr));
        button_analyse->setText(QCoreApplication::translate("AllAnalyse", "\345\274\200\345\247\213\345\210\206\346\236\220", nullptr));
        label->setText(QCoreApplication::translate("AllAnalyse", "\345\210\206\346\236\220\347\256\200\345\216\206\346\200\273\346\225\260", nullptr));
        label_3->setText(QCoreApplication::translate("AllAnalyse", "\345\210\206\351\205\215\345\262\227\344\275\215\346\210\220\345\212\237\346\225\260", nullptr));
        fileInfo->setText(QCoreApplication::translate("AllAnalyse", "\345\205\250\351\203\250\346\225\260\346\215\256\345\267\262\344\277\235\345\255\230\345\210\260excel\346\226\207\344\273\266\357\274\214\350\267\257\345\276\204\344\270\272", nullptr));
        button_openFile->setText(QCoreApplication::translate("AllAnalyse", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AllAnalyse: public Ui_AllAnalyse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLANALYSE_H
