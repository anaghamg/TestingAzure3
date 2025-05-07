#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMinimumSize(250,250);
    w.setMaximumSize(250,250);
    w.show();

    return a.exec();
}
