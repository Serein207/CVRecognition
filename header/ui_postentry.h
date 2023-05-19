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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PostEntry
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_1;
    QLabel *label_1;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *button_SelectFile_5;
    QTextBrowser *textBrowser_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *button_input;
    QPushButton *button_showMainWin;

    void setupUi(QDialog *PostEntry)
    {
        if (PostEntry->objectName().isEmpty())
            PostEntry->setObjectName("PostEntry");
        PostEntry->resize(550, 400);
        PostEntry->setMinimumSize(QSize(550, 400));
        PostEntry->setMaximumSize(QSize(550, 400));
        layoutWidget = new QWidget(PostEntry);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 50, 481, 311));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft JhengHei UI Light")});
        font.setPointSize(16);
        label_5->setFont(font);

        verticalLayout_3->addWidget(label_5);

        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName("horizontalLayout_1");
        label_1 = new QLabel(layoutWidget);
        label_1->setObjectName("label_1");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei UI Light")});
        label_1->setFont(font1);

        horizontalLayout_1->addWidget(label_1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_1->addItem(horizontalSpacer_5);

        button_SelectFile_5 = new QPushButton(layoutWidget);
        button_SelectFile_5->setObjectName("button_SelectFile_5");
        button_SelectFile_5->setFont(font1);

        horizontalLayout_1->addWidget(button_SelectFile_5);


        verticalLayout_3->addLayout(horizontalLayout_1);

        textBrowser_3 = new QTextBrowser(layoutWidget);
        textBrowser_3->setObjectName("textBrowser_3");

        verticalLayout_3->addWidget(textBrowser_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        button_Entry = new QPushButton(layoutWidget);
        button_Entry->setObjectName("button_Entry");
        button_Entry->setFont(font1);

        horizontalLayout_5->addWidget(button_Entry);


        verticalLayout_3->addLayout(horizontalLayout_5);

        button_showMainWin = new QPushButton(PostEntry);
        button_showMainWin->setObjectName("button_showMainWin");
        button_showMainWin->setGeometry(QRect(10, 10, 61, 24));
        button_showMainWin->setFont(font1);
        button_showMainWin->setCursor(QCursor(Qt::PointingHandCursor));
        button_showMainWin->setStyleSheet(QString::fromUtf8("* {\n"
"  border-radius: 15px;\n"
"  border: none;\n"
"  background-color: rgb(255, 255, 255);\n"
"  text-align: left;\n"
"}"));

        retranslateUi(PostEntry);

        QMetaObject::connectSlotsByName(PostEntry);
    } // setupUi

    void retranslateUi(QDialog *PostEntry)
    {
        PostEntry->setWindowTitle(QCoreApplication::translate("PostEntry", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("PostEntry", "\345\262\227\344\275\215\345\275\225\345\205\245", nullptr));
        label_1->setText(QCoreApplication::translate("PostEntry", "\346\224\257\346\214\201\346\226\207\346\234\254\343\200\201PDF\343\200\201DOCX\343\200\201\345\233\276\347\211\207\357\274\210JPEG/PNG\357\274\211\345\275\225\345\205\245", nullptr));
        button_SelectFile_5->setText(QCoreApplication::translate("PostEntry", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        button_Entry->setText(QCoreApplication::translate("PostEntry", "\345\275\225\345\205\245", nullptr));
        button_showMainWin->setText(QCoreApplication::translate("PostEntry", "< \350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PostEntry: public Ui_PostEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTENTRY_H
