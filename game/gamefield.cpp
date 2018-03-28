#include "gamefield.h"
#include <iostream>

GameField::GameField(QWidget* parent)
    :QWidget(parent)
{
    x = 0;
    gameOver = false;
    gameWon = false;
    paused = false;
    gameStarted = false;
    ball = new Ball();
    board = new Board();

    int k = 0;

    for (int i=0; i<5; i++) {
      for (int j=0; j<7; j++) {
        bricks[k] = new Brick(j*72+45, i*24+30);
        k++;
      }
    }
    std::cout<<"I am created"<<std::endl;
}

GameField::~GameField(){
    delete ball;
    delete board;

    for (int i=0; i<N_OF_BRICKS; i++) {
      delete bricks[i];
    }
}

void GameField::mousePressEvent(QMouseEvent *)
{
    this->setFocus();
}

void GameField::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);
    QPainter painter(this);

    if (gameOver) {
        finishGame(&painter, "Game lost");

    }
    else if(gameWon) {
        finishGame(&painter, "Victory");
    }
    else {
        drawObjects(&painter);
    }
}

void GameField::finishGame(QPainter *painter, QString message) {

    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(message);
    painter->setFont(font);
    int h = height();
    int w = width();

    painter->translate(QPoint(w/2, h/2));
    painter->drawText(-textWidth/2, 0, message);
}

void GameField::drawObjects(QPainter *painter) {

    painter->drawImage(ball->getRect(), ball->getImage());
    painter->drawImage(board->getRect(), board->getImage());

    for (int i=0; i<N_OF_BRICKS; i++) {
    if (!bricks[i]->isDestroyed()) {
        painter->drawImage(bricks[i]->getRect(), bricks[i]->getImage());
    }
    }
}

void GameField::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);

    moveObjects();
    checkCollision();
    repaint();
}

void GameField::moveObjects() {

    ball->autoMove();
    board->move();
}

void GameField::keyReleaseEvent(QKeyEvent *e) {

    int dx = 0;

    switch (e->key()) {
        case Qt::Key_A:
            dx = 0;
            board->setDx(dx);
            break;

        case Qt::Key_D:
            dx = 0;
            board->setDx(dx);
            break;
    }
}

void GameField::keyPressEvent(QKeyEvent *e) {

    int dx = 0;
    this->setFocus();

    switch (e->key()) {
    case Qt::Key_A:

        dx = -2;
        board->setDx(dx);

        break;

    case Qt::Key_D:

        dx = 2;
        board->setDx(dx);
        break;

    case Qt::Key_P:

        pauseGame();
        break;

    default:
        QWidget::keyPressEvent(e);
    }
}

void GameField::startGame() {

    if (!gameStarted) {
        ball->resetState();
        board->resetState();

        for (int i=0; i<N_OF_BRICKS; i++) {
          bricks[i]->setDestroyed(false);
        }

        gameOver = false;
        gameWon = false;
        gameStarted = true;
        timerId = startTimer(DELAY);
    }
}

void GameField::pauseGame() {

    if (paused) {
        timerId = startTimer(DELAY);
        paused = false;
    }
    else {
        paused = true;
        killTimer(timerId);
    }
}

void GameField::stopGame() {

    killTimer(timerId);
    gameOver = true;
    gameStarted = false;
}

void GameField::victory() {

    killTimer(timerId);
    gameWon = true;
    gameStarted = false;
}

void GameField::checkCollision() {

    if (ball->getRect().bottom() > BOTTOM_EDGE) {
        stopGame();
    }

    for (int i=0, j=0; i<N_OF_BRICKS; i++) {
            if (bricks[i]->isDestroyed()) {
                j++;
            }

            if (j == N_OF_BRICKS) {
                victory();
            }
        }

        if ((ball->getRect()).intersects(board->getRect())) {

            int boardLPos = board->getRect().left();
            int ballLPos = ball->getRect().left();

            int first = boardLPos + 12;
            int second = boardLPos + 24;
            int third = boardLPos + 48;
            int fourth = boardLPos + 60;
            int fifth = boardLPos + 72;

            if (ballLPos < first) {
                ball->setXDir(-2);
                ball->setYDir(-2);
            }

            if (ballLPos >= first && ballLPos < second) {
                ball->setXDir(-1);
                ball->setYDir(-2);
            }

            if (ballLPos >= second && ballLPos < third) {
                ball->setXDir(0);
                ball->setYDir(-2);
            }
            if (ballLPos >= third && ballLPos < fourth) {
                ball->setXDir(1);
                ball->setYDir(-2);
            }
            if (ballLPos >= fourth && ballLPos < fifth) {
                ball->setXDir(2);
                ball->setYDir(-2);
            }
        }

    for (int i=0; i<N_OF_BRICKS; i++) {

        if ((ball->getRect()).intersects(bricks[i]->getRect())) {
            int ballLeft = ball->getRect().left();
            int ballHeight = ball->getRect().height();
            int ballWidth = ball->getRect().width();
            int ballTop = ball->getRect().top();

            QPoint pointRight(ballLeft + ballWidth + 1, ballTop);
            QPoint pointLeft(ballLeft - 1, ballTop);
            QPoint pointTop(ballLeft, ballTop -1);
            QPoint pointBottom(ballLeft, ballTop + ballHeight + 1);

            if (!bricks[i]->isDestroyed()) {
                if(bricks[i]->getRect().contains(pointRight)) {
                    ball->setXDir(-2);
                }

                else if(bricks[i]->getRect().contains(pointLeft)) {
                    ball->setXDir(2);
                }

                if(bricks[i]->getRect().contains(pointTop)) {
                    ball->setYDir(2);
                }

                else if(bricks[i]->getRect().contains(pointBottom)) {
                    ball->setYDir(-2);
                }

                bricks[i]->setDestroyed(true);
            }
        }
    }
}

int GameField::getBottomEdge()
{
    return BOTTOM_EDGE;
}
