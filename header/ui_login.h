/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *button_showMainWin;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_key;
    QLineEdit *lineEdit_secret;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_login;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(300, 200);
        Login->setMinimumSize(QSize(300, 150));
        Login->setMaximumSize(QSize(300, 200));
        Login->setStyleSheet(QString::fromUtf8("QDialog { \n"
"  background-color: white;\n"
"}"));
        button_showMainWin = new QPushButton(Login);
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
        widget = new QWidget(Login);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 50, 181, 81));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_key = new QLineEdit(widget);
        lineEdit_key->setObjectName("lineEdit_key");

        verticalLayout->addWidget(lineEdit_key);

        lineEdit_secret = new QLineEdit(widget);
        lineEdit_secret->setObjectName("lineEdit_secret");

        verticalLayout->addWidget(lineEdit_secret);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button_login = new QPushButton(widget);
        button_login->setObjectName("button_login");

        horizontalLayout->addWidget(button_login);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        button_showMainWin->setText(QCoreApplication::translate("Login", "< \350\277\224\345\233\236", nullptr));
        lineEdit_key->setPlaceholderText(QCoreApplication::translate("Login", "key", nullptr));
        lineEdit_secret->setPlaceholderText(QCoreApplication::translate("Login", "secret", nullptr));
        button_login->setText(QCoreApplication::translate("Login", "LOGIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
