#include <QtGui/QApplication>
#include "mainwindow.h"
#include "parser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(argv[1]);
    w.show();

    return a.exec();
}
