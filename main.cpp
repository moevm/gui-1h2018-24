#include "interface/view/mainwindow.h"
#include <QApplication>
#include "game/view/gamefield.h"

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
