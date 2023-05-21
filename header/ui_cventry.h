/********************************************************************************
** Form generated from reading UI file 'cventry.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CVENTRY_H
#define UI_CVENTRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CvEntry
{
public:
    QPushButton *button_showMainWin;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_SelectFile;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *button_input;

    void setupUi(QDialog *CvEntry)
    {
        if (CvEntry->objectName().isEmpty())
            CvEntry->setObjectName("CvEntry");
        CvEntry->resize(550, 400);
        CvEntry->setMinimumSize(QSize(550, 400));
        CvEntry->setMaximumSize(QSize(550, 400));
        CvEntry->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"}\n"
""));
        button_showMainWin = new QPushButton(CvEntry);
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
        widget = new QWidget(CvEntry);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(31, 51, 471, 313));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei UI Light")});
        font1.setPointSize(16);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button_SelectFile = new QPushButton(widget);
        button_SelectFile->setObjectName("button_SelectFile");
        button_SelectFile->setFont(font);

        horizontalLayout->addWidget(button_SelectFile);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(widget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        button_input = new QPushButton(widget);
        button_input->setObjectName("button_input");
        button_input->setFont(font);

        horizontalLayout_2->addWidget(button_input);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CvEntry);

        QMetaObject::connectSlotsByName(CvEntry);
    } // setupUi

    void retranslateUi(QDialog *CvEntry)
    {
        CvEntry->setWindowTitle(QCoreApplication::translate("CvEntry", "\347\256\200\345\216\206\345\275\225\345\205\245", nullptr));
        button_showMainWin->setText(QCoreApplication::translate("CvEntry", "< \350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("CvEntry", "\347\256\200\345\216\206\345\275\225\345\205\245", nullptr));
        label_2->setText(QCoreApplication::translate("CvEntry", "\346\224\257\346\214\201\346\226\207\346\234\254\343\200\201PDF\343\200\201DOCX\343\200\201\345\233\276\347\211\207\357\274\210JPEG/PNG\357\274\211\345\275\225\345\205\245", nullptr));
        label_3->setText(QCoreApplication::translate("CvEntry", "\346\213\226\346\213\275\346\226\207\344\273\266\345\210\260\344\270\213\346\226\271\346\210\226\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        button_SelectFile->setText(QCoreApplication::translate("CvEntry", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        button_input->setText(QCoreApplication::translate("CvEntry", "\345\275\225\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CvEntry: public Ui_CvEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CVENTRY_H
