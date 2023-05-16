#include "test.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    test();
    auto dialog = new QDialog();
    dialog->show();
    delete dialog;
    return a.exec();
}