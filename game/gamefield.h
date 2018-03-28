#ifndef GAMEFIELD_H
#define GAMEFIELD_H
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include "game/ball.h"
#include "game/brick.h"
#include "game/board.h"

class GameField : public QWidget
{
    friend class Game;
public:
    GameField(QWidget* parent = 0);
    ~GameField();

    void mousePressEvent(QMouseEvent*);
    static int getBottomEdge();

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void drawObjects(QPainter *);
    void finishGame(QPainter *, QString);
    void moveObjects();

    void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();

  private:
    int x;
    int timerId;
    static const int N_OF_BRICKS = 35;
    static const int DELAY = 10;
    static const int BOTTOM_EDGE = 450;
    Ball *ball;
    Board *board;
    Brick *bricks[N_OF_BRICKS];
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
};

#endif // GAMEFIELD_H
