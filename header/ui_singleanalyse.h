/********************************************************************************
** Form generated from reading UI file 'singleanalyse.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLEANALYSE_H
#define UI_SINGLEANALYSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SingleAnalyse
{
public:
    QPushButton *button_showMainWin;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_1;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *button_analyse;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *name;
    QLabel *label_3;
    QLineEdit *age;
    QLabel *label_4;
    QLineEdit *education;
    QLabel *label_5;
    QLineEdit *college;
    QLabel *label_6;
    QLineEdit *work;
    QLabel *label_7;
    QLineEdit *recommend;

    void setupUi(QDialog *SingleAnalyse)
    {
        if (SingleAnalyse->objectName().isEmpty())
            SingleAnalyse->setObjectName("SingleAnalyse");
        SingleAnalyse->resize(577, 454);
        SingleAnalyse->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: hide;\n"
"}\n"
"\n"
"QDialog {\n"
"  background-color: rgb(255, 255, 255);\n"
"}"));
        button_showMainWin = new QPushButton(SingleAnalyse);
        button_showMainWin->setObjectName("button_showMainWin");
        button_showMainWin->setGeometry(QRect(10, 0, 61, 24));
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
        layoutWidget = new QWidget(SingleAnalyse);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 30, 531, 412));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei UI Light")});
        font1.setPointSize(16);
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_1 = new QLabel(layoutWidget);
        label_1->setObjectName("label_1");
        label_1->setFont(font);

        horizontalLayout->addWidget(label_1);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        button_analyse = new QPushButton(layoutWidget);
        button_analyse->setObjectName("button_analyse");
        button_analyse->setFont(font);

        horizontalLayout_2->addWidget(button_analyse);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft JhengHei UI Light")});
        font2.setPointSize(14);
        label->setFont(font2);

        verticalLayout_2->addWidget(label);

        name = new QLineEdit(layoutWidget);
        name->setObjectName("name");
        QFont font3;
        font3.setPointSize(18);
        font3.setBold(false);
        name->setFont(font3);

        verticalLayout_2->addWidget(name);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);

        verticalLayout_2->addWidget(label_3);

        age = new QLineEdit(layoutWidget);
        age->setObjectName("age");
        age->setFont(font3);

        verticalLayout_2->addWidget(age);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);

        verticalLayout_2->addWidget(label_4);

        education = new QLineEdit(layoutWidget);
        education->setObjectName("education");
        education->setFont(font3);

        verticalLayout_2->addWidget(education);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);

        verticalLayout_2->addWidget(label_5);

        college = new QLineEdit(layoutWidget);
        college->setObjectName("college");
        college->setFont(font3);

        verticalLayout_2->addWidget(college);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");
        label_6->setFont(font2);

        verticalLayout_2->addWidget(label_6);

        work = new QLineEdit(layoutWidget);
        work->setObjectName("work");
        work->setFont(font3);

        verticalLayout_2->addWidget(work);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");
        label_7->setFont(font2);

        verticalLayout_2->addWidget(label_7);

        recommend = new QLineEdit(layoutWidget);
        recommend->setObjectName("recommend");
        recommend->setFont(font3);

        verticalLayout_2->addWidget(recommend);


        horizontalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(SingleAnalyse);

        QMetaObject::connectSlotsByName(SingleAnalyse);
    } // setupUi

    void retranslateUi(QDialog *SingleAnalyse)
    {
        SingleAnalyse->setWindowTitle(QCoreApplication::translate("SingleAnalyse", "Dialog", nullptr));
        button_showMainWin->setText(QCoreApplication::translate("SingleAnalyse", "< \350\277\224\345\233\236", nullptr));
        label_2->setText(QCoreApplication::translate("SingleAnalyse", "\345\215\225\347\213\254\345\210\206\346\236\220", nullptr));
        label_1->setText(QCoreApplication::translate("SingleAnalyse", "\351\200\211\346\213\251\345\267\262\345\275\225\345\205\245\347\232\204\347\256\200\345\216\206", nullptr));
        button_analyse->setText(QCoreApplication::translate("SingleAnalyse", "\345\210\206\346\236\220", nullptr));
        label->setText(QCoreApplication::translate("SingleAnalyse", "\345\247\223\345\220\215", nullptr));
        name->setText(QString());
        label_3->setText(QCoreApplication::translate("SingleAnalyse", "\345\271\264\351\276\204", nullptr));
        age->setText(QString());
        label_4->setText(QCoreApplication::translate("SingleAnalyse", "\346\234\200\351\253\230\345\255\246\345\216\206", nullptr));
        education->setText(QString());
        label_5->setText(QCoreApplication::translate("SingleAnalyse", "\346\257\225\344\270\232\351\231\242\346\240\241", nullptr));
        college->setText(QString());
        label_6->setText(QCoreApplication::translate("SingleAnalyse", "\345\267\245\344\275\234\345\271\264\351\231\220", nullptr));
        work->setText(QString());
        label_7->setText(QCoreApplication::translate("SingleAnalyse", "\346\216\250\350\215\220\345\262\227\344\275\215", nullptr));
        recommend->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SingleAnalyse: public Ui_SingleAnalyse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLEANALYSE_H
