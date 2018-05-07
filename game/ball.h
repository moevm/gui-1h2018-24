#ifndef BALL_H
#define BALL_H

#include <QImage>
#include <QRect>

class Ball
{
public:
    Ball();

    void resetState();
    void setSpeed(int);
    void autoMove();
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage & getImage();
    void setVisible(bool);

private:
    int xdir;
    int ydir;
    double speed;
    QImage image;
    QRect rect;
    static const int INITIAL_X = 230;
    static const int INITIAL_Y = 355;
};

#endif // BALL_H
