#include "ball.h"
#include "constants.h"

Ball::Ball()
{
    image.load(":/images/ball.png");

    rect = image.rect();
    resetState();
}

void Ball::resetState()
{
    rect.moveTo(INITIAL_X, INITIAL_Y);
    xdir = 2 * speed;
    ydir = -2 * speed;
}

void Ball::setSpeed(int level)
{
    switch (level) {
    case 1:
        speed = 1 * level;
        break;
    case 2:
        speed = 0.75 * level;
        break;
    }
}

void Ball::autoMove()
{
    rect.translate(xdir, ydir);

    if (rect.left() <= 0) {
      xdir = 2 * speed;
    }

    if (rect.right() >= RIGHT_EDGE) {
      xdir = -2 * speed;
    }

    if (rect.top() <= 0) {
      ydir = 2 * speed;
    }
}

void Ball::setXDir(int x)
{
    xdir = x * speed;
}

void Ball::setYDir(int y)
{
    ydir = y * speed;
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

void Ball::setVisible(bool flag)
{
    if (flag){
        image.load(":/images/ball.png");
    } else{
        image.load(":/images/ball_hide.png");
    }
}
