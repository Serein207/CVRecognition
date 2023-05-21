/********************************************************************************
** Form generated from reading UI file 'postentry.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSTENTRY_H
#define UI_POSTENTRY_H

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

class Ui_PostEntry
{
public:
    QPushButton *button_showMainWin;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_SelectFile;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *button_input;

    void setupUi(QDialog *PostEntry)
    {
        if (PostEntry->objectName().isEmpty())
            PostEntry->setObjectName("PostEntry");
        PostEntry->resize(550, 400);
        PostEntry->setMinimumSize(QSize(550, 400));
        PostEntry->setMaximumSize(QSize(550, 400));
        PostEntry->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"}\n"
""));
        button_showMainWin = new QPushButton(PostEntry);
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
        layoutWidget = new QWidget(PostEntry);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(31, 51, 471, 313));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei UI Light")});
        font1.setPointSize(16);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        horizontalLayout->addWidget(label_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button_SelectFile = new QPushButton(layoutWidget);
        button_SelectFile->setObjectName("button_SelectFile");
        button_SelectFile->setFont(font);

        horizontalLayout->addWidget(button_SelectFile);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        button_input = new QPushButton(layoutWidget);
        button_input->setObjectName("button_input");
        button_input->setFont(font);

        horizontalLayout_2->addWidget(button_input);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(PostEntry);

        QMetaObject::connectSlotsByName(PostEntry);
    } // setupUi

    void retranslateUi(QDialog *PostEntry)
    {
        PostEntry->setWindowTitle(QCoreApplication::translate("PostEntry", "\345\262\227\344\275\215\345\275\225\345\205\245", nullptr));
        button_showMainWin->setText(QCoreApplication::translate("PostEntry", "< \350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("PostEntry", "\345\262\227\344\275\215\345\275\225\345\205\245", nullptr));
        label_4->setText(QCoreApplication::translate("PostEntry", "\346\224\257\346\214\201\346\226\207\346\234\254\343\200\201PDF\343\200\201DOCX\343\200\201\345\233\276\347\211\207\357\274\210JPEG/PNG\357\274\211\345\275\225\345\205\245", nullptr));
        label_5->setText(QCoreApplication::translate("PostEntry", "\346\213\226\346\213\275\346\226\207\344\273\266\345\210\260\344\270\213\346\226\271\346\210\226\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        button_SelectFile->setText(QCoreApplication::translate("PostEntry", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        button_input->setText(QCoreApplication::translate("PostEntry", "\345\275\225\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PostEntry: public Ui_PostEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTENTRY_H
