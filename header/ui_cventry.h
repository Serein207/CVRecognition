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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CvEntry
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_SelectFile;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *button_input;

    void setupUi(QDialog *CvEntry)
    {
        if (CvEntry->objectName().isEmpty())
            CvEntry->setObjectName("CvEntry");
        CvEntry->resize(539, 369);
        CvEntry->setStyleSheet(QString::fromUtf8("QDialog {\n"
" backgoung-color: rgb(255, 255, 254);\n"
"}"));
        layoutWidget = new QWidget(CvEntry);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 30, 481, 311));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft JhengHei UI Light")});
        font.setPointSize(14);
        label->setFont(font);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei UI Light")});
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button_SelectFile = new QPushButton(layoutWidget);
        button_SelectFile->setObjectName("button_SelectFile");
        button_SelectFile->setFont(font1);

        horizontalLayout->addWidget(button_SelectFile);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        button_SelectFile_2 = new QPushButton(layoutWidget);
        button_SelectFile_2->setObjectName("button_SelectFile_2");
        button_SelectFile_2->setFont(font1);

        horizontalLayout_2->addWidget(button_SelectFile_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CvEntry);

        QMetaObject::connectSlotsByName(CvEntry);
    } // setupUi

    void retranslateUi(QDialog *CvEntry)
    {
        CvEntry->setWindowTitle(QCoreApplication::translate("CvEntry", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CvEntry", "\347\256\200\345\216\206\345\275\225\345\205\245", nullptr));
        label_2->setText(QCoreApplication::translate("CvEntry", "\346\224\257\346\214\201\346\226\207\346\234\254\343\200\201PDF\343\200\201DOCX\343\200\201\345\233\276\347\211\207\357\274\210JPEG/PNG\357\274\211\345\275\225\345\205\245", nullptr));
        button_SelectFile->setText(QCoreApplication::translate("CvEntry", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        button_SelectFile_2->setText(QCoreApplication::translate("CvEntry", "\345\274\200\345\247\213\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CvEntry: public Ui_CvEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CVENTRY_H
