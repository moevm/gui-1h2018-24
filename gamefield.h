#ifndef GAMEFIELD_H
#define GAMEFIELD_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class GameField : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    GameField();
};

#endif // GAMEFIELD_H
