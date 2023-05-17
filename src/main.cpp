#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include "test.h"
#include "mainui.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    new MainUI;
    return a.exec();
}
