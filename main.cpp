#include "interface/mainwindow.h"
#include <QApplication>
#include "game/gamefield.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
