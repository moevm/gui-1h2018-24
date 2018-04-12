#include "interface/mainwindow.h"
#include <QApplication>
#include "game/gamefield.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    GameField field;
//    field.resize(300, 400);
//    field.show();

    return a.exec();
}
