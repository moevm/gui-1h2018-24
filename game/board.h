#ifndef BOARD_H
#define BOARD_H

#include <QImage>
#include <QRect>
#include "constants.h"

class Board
{
public:
    Board();

    void resetState();
    void move();
    void setDx(int);
    QRect getRect();
    QImage & getImage();

private:
    QImage image;
    QRect rect;
    int dx;
    static const int INITIAL_X = 250;
    static const int INITIAL_Y = 420;
};

#endif // BOARD_H
