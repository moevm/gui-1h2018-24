#ifndef GAME_H
#define GAME_H

#include <QWidget>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

//    void keyPressEvent(QKeyEvent *);
//    void keyReleaseEvent(QKeyEvent *);
    void showEvent(QShowEvent *);
    void showFinishDialog();

private:
    Ui::Game *ui;

private slots:
    void on_newButton_clicked(bool);
    void on_exitGameButton_clicked(bool);
    void hideGameField();
    void lives_display(int);
    void record_display(int);
};

#endif // GAME_H
