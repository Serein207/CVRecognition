#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
    class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login* ui;
    void writeFile();

signals:
    void showMainWinSig();

public slots:
    void showMainWin();
    void loadFile();
    void login();
};

#endif
