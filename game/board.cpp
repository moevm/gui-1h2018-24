#include "board.h"

Board::Board()
{
    dx = 0;
    image.load(":/images/board.png");

    rect = image.rect();
    resetState();
}

void Board::resetState()
{
    rect.moveTo(INITIAL_X, INITIAL_Y);
}

void Board::move()
{
    double x = (rect.x() + rect.width() + dx * 1.5 > RIGHT_EDGE || rect.x() + dx * 1.5 < 0) ?
                rect.x() : rect.x() + dx * 1.5;
    int y = rect.top();

    rect.moveTo(x, y);
}

void Board::setDx(int x)
{
    dx = x;
}

QRect Board::getRect()
{
    return rect;
}

QImage &Board::getImage()
{
    return image;
}


