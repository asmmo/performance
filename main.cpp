#include "mainwindow.h"
#include <SysInfo.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SysInfo::instance();
    MainWindow w;
    w.show();
    return a.exec();
}
