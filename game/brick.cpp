#include "brick.h"

Brick::Brick(int x, int y, int color)
{
    switch (color) {
    case 0:
        image.load(":/images/brick_red.png");
        break;
    case 1:
        image.load(":/images/brick_yellow.png");
        break;
    case 2:
        image.load(":/images/brick_green.png");
        break;
    case 3:
        image.load(":/images/brick_blue.png");
        break;
    case 4:
        image.load(":/images/brick_violet.png");
        break;
    default:
        break;
    }
    destroyed = false;
    rect = image.rect();
    rect.translate(x, y);
}

bool Brick::isDestroyed()
{
    return destroyed;
}

void Brick::setDestroyed(bool destr)
{
    destroyed = destr;
}

QRect Brick::getRect()
{
    return rect;
}

void Brick::setRect(QRect rct)
{
    rect = rct;
}

QImage &Brick::getImage()
{
    return image;
}
