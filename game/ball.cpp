#include "ball.h"
#include "constants.h"

Ball::Ball()
{
    xdir = 1;
    ydir = -1;

    image.load("/home/vend/GUI_Projects/PO_GUI/images/ball.png");

    rect = image.rect();
    resetState();
}

void Ball::resetState()
{
    rect.moveTo(INITIAL_X, INITIAL_Y);
    xdir = 2;
    ydir = -2;
}

void Ball::autoMove()
{
    rect.translate(xdir, ydir);

    if (rect.left() <= 0) {
      xdir = 2;
    }

    if (rect.right() >= RIGHT_EDGE) {
      xdir = -2;
    }

    if (rect.top() <= 0) {
      ydir = 2;
    }
}

void Ball::setXDir(int x)
{
    xdir = x;
}

void Ball::setYDir(int y)
{
    ydir = y;
}

int Ball::getXDir()
{
    return xdir;
}

int Ball::getYDir()
{
    return ydir;
}

QRect Ball::getRect()
{
    return rect;
}

QImage &Ball::getImage()
{
    return image;
}
