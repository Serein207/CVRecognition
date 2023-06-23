#include <QtWidgets/QApplication>

#include "mainui.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    new MainUI;
    return a.exec();
}
