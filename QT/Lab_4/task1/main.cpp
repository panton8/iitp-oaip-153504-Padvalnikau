#include "mainwindow.h"
#include <QString>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString
    MainWindow w;
    w.show();
    return a.exec();
}
