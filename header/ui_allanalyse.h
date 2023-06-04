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
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QChartView *eduChartView;
    QChartView *workChartView;
    QChartView *ageChartView;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_sum;
    QLabel *label_3;
    QLineEdit *lineEdit_ok;
    QSpacerItem *verticalSpacer;
    QLabel *fileInfo;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_openFile;
    QSpacerItem *horizontalSpacer_3;

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

        layoutWidget1 = new QWidget(AllAnalyse);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(40, 120, 801, 601));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        eduChartView = new QChartView(layoutWidget1);
        eduChartView->setObjectName("eduChartView");

        gridLayout->addWidget(eduChartView, 0, 0, 1, 1);

        workChartView = new QChartView(layoutWidget1);
        workChartView->setObjectName("workChartView");

        gridLayout->addWidget(workChartView, 0, 1, 1, 1);

        ageChartView = new QChartView(layoutWidget1);
        ageChartView->setObjectName("ageChartView");

        gridLayout->addWidget(ageChartView, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(label);

        lineEdit_sum = new QLineEdit(layoutWidget1);
        lineEdit_sum->setObjectName("lineEdit_sum");
        lineEdit_sum->setMinimumSize(QSize(0, 50));
        lineEdit_sum->setMaximumSize(QSize(16777215, 50));
        QFont font3;
        font3.setPointSize(14);
        lineEdit_sum->setFont(font3);
        lineEdit_sum->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdit_sum);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(label_3);

        lineEdit_ok = new QLineEdit(layoutWidget1);
        lineEdit_ok->setObjectName("lineEdit_ok");
        lineEdit_ok->setMinimumSize(QSize(0, 50));
        lineEdit_ok->setMaximumSize(QSize(16777215, 50));
        lineEdit_ok->setFont(font3);
        lineEdit_ok->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdit_ok);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        fileInfo = new QLabel(layoutWidget1);
        fileInfo->setObjectName("fileInfo");
        QFont font4;
        font4.setPointSize(11);
        fileInfo->setFont(font4);

        verticalLayout_2->addWidget(fileInfo);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        button_openFile = new QPushButton(layoutWidget1);
        button_openFile->setObjectName("button_openFile");

        horizontalLayout->addWidget(button_openFile);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);


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
