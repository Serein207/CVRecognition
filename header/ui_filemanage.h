/********************************************************************************
** Form generated from reading UI file 'filemanage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEMANAGE_H
#define UI_FILEMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileManage
{
public:
    QPushButton *button_showMainWin;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_Cvs;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *cvAllSelect;
    QPushButton *button_deleteCv;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listWidget_Post;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *postAllSelect;
    QPushButton *button_deletePost;

    void setupUi(QDialog *FileManage)
    {
        if (FileManage->objectName().isEmpty())
            FileManage->setObjectName("FileManage");
        FileManage->resize(582, 433);
        FileManage->setStyleSheet(QString::fromUtf8("QDialog {\n"
"  background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QListWidget {\n"
"	font: 25 9pt \"Microsoft YaHei Light\";\n"
"	border: 15px solid white; /* \350\256\276\347\275\256\350\276\271\346\241\206\347\232\204\345\244\247\345\260\217\357\274\214\346\240\267\345\274\217\357\274\214\351\242\234\350\211\262 */\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    height: 30px;\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"	background-color: transparent;\n"
"	padding: 10px;\n"
"	border-left: 3px solid rgb(130, 130, 130);\n"
"}\n"
"QListWidget::item:selected {\n"
"	background-color: transparent;\n"
"	color: black;\n"
"	padding: 10px;\n"
"	border-left: 3px solid black;\n"
"}\n"
""));
        button_showMainWin = new QPushButton(FileManage);
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
        layoutWidget = new QWidget(FileManage);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(31, 51, 251, 361));
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

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");

        verticalLayout->addLayout(horizontalLayout);

        listWidget_Cvs = new QListWidget(layoutWidget);
        listWidget_Cvs->setObjectName("listWidget_Cvs");

        verticalLayout->addWidget(listWidget_Cvs);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        cvAllSelect = new QCheckBox(layoutWidget);
        cvAllSelect->setObjectName("cvAllSelect");
        cvAllSelect->setFont(font);

        horizontalLayout_2->addWidget(cvAllSelect);

        button_deleteCv = new QPushButton(layoutWidget);
        button_deleteCv->setObjectName("button_deleteCv");
        button_deleteCv->setFont(font);

        horizontalLayout_2->addWidget(button_deleteCv);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget_2 = new QWidget(FileManage);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(300, 50, 251, 361));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");

        verticalLayout_2->addLayout(horizontalLayout_3);

        listWidget_Post = new QListWidget(layoutWidget_2);
        listWidget_Post->setObjectName("listWidget_Post");

        verticalLayout_2->addWidget(listWidget_Post);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        postAllSelect = new QCheckBox(layoutWidget_2);
        postAllSelect->setObjectName("postAllSelect");
        postAllSelect->setFont(font);

        horizontalLayout_4->addWidget(postAllSelect);

        button_deletePost = new QPushButton(layoutWidget_2);
        button_deletePost->setObjectName("button_deletePost");
        button_deletePost->setFont(font);

        horizontalLayout_4->addWidget(button_deletePost);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(FileManage);

        QMetaObject::connectSlotsByName(FileManage);
    } // setupUi

    void retranslateUi(QDialog *FileManage)
    {
        FileManage->setWindowTitle(QCoreApplication::translate("FileManage", "Dialog", nullptr));
        button_showMainWin->setText(QCoreApplication::translate("FileManage", "< \350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("FileManage", "\347\256\200\345\216\206\346\226\207\344\273\266", nullptr));
        label_2->setText(QCoreApplication::translate("FileManage", "\351\200\211\346\213\251\351\234\200\350\246\201\345\210\240\351\231\244\347\232\204\346\226\207\344\273\266", nullptr));
        cvAllSelect->setText(QCoreApplication::translate("FileManage", "\345\205\250\351\200\211", nullptr));
        button_deleteCv->setText(QCoreApplication::translate("FileManage", "\345\210\240\351\231\244", nullptr));
        label_3->setText(QCoreApplication::translate("FileManage", "\345\262\227\344\275\215\351\234\200\346\261\202\346\226\207\344\273\266", nullptr));
        label_4->setText(QCoreApplication::translate("FileManage", "\351\200\211\346\213\251\351\234\200\350\246\201\345\210\240\351\231\244\347\232\204\346\226\207\344\273\266", nullptr));
        postAllSelect->setText(QCoreApplication::translate("FileManage", "\345\205\250\351\200\211", nullptr));
        button_deletePost->setText(QCoreApplication::translate("FileManage", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileManage: public Ui_FileManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGE_H
