/********************************************************************************
** Form generated from reading UI file 'allanalyse.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLANALYSE_H
#define UI_ALLANALYSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
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
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *button_analyse;

    void setupUi(QDialog *AllAnalyse)
    {
        if (AllAnalyse->objectName().isEmpty())
            AllAnalyse->setObjectName("AllAnalyse");
        AllAnalyse->resize(583, 513);
        AllAnalyse->setStyleSheet(QString::fromUtf8("QDialog {\n"
"  background-color: rgb(255, 255, 255);\n"
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
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei UI Light")});
        font1.setPointSize(16);
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        button_analyse = new QPushButton(layoutWidget);
        button_analyse->setObjectName("button_analyse");
        button_analyse->setFont(font);

        horizontalLayout_2->addWidget(button_analyse);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AllAnalyse);

        QMetaObject::connectSlotsByName(AllAnalyse);
    } // setupUi

    void retranslateUi(QDialog *AllAnalyse)
    {
        AllAnalyse->setWindowTitle(QCoreApplication::translate("AllAnalyse", "Dialog", nullptr));
        button_showMainWin->setText(QCoreApplication::translate("AllAnalyse", "< \350\277\224\345\233\236", nullptr));
        label_2->setText(QCoreApplication::translate("AllAnalyse", "\345\205\250\351\203\250\345\210\206\346\236\220", nullptr));
        button_analyse->setText(QCoreApplication::translate("AllAnalyse", "\345\274\200\345\247\213\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AllAnalyse: public Ui_AllAnalyse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLANALYSE_H
