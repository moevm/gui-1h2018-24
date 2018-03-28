#include "brick.h"

Brick::Brick(int x, int y)
{
    image.load("/home/vend/GUI_Projects/PO_GUI/images/brick.png");
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
