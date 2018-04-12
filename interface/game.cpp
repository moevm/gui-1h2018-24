#include "game.h"
#include "ui_game.h"
#include "interface/choosinglevel.h"
#include <iostream>
#include <QTimer>

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    ui->gameField->setStyleSheet("border: 3px solid black");
    ui->gameField->resize(600,450);
    ui->gameField->setWindowTitle("BreakOut");
    ui->lives->setPalette(Qt::blue);
    ui->record->setPalette(Qt::blue);
    connect(ui->gameField->getState(), SIGNAL(livesChanged(int)), ui->lives, SLOT(display(int)));
    connect(ui->gameField->getState(), SIGNAL(recordChanged(int)), ui->record, SLOT(display(int)));
}

Game::~Game()
{
    delete ui;
}

void Game::showEvent(QShowEvent *)
{
    ui->gameField->setFocus();
    ui->gameField->startGame();
}

void Game::on_newButton_clicked(bool)
{
    if(!ui->gameField->gameOver && !ui->gameField->gameWon){
        ui->gameField->stopGame();
    }
    ui->gameField->startGame();
    ui->gameField->setFocus();
}

void Game::on_exitGameButton_clicked(bool)
{
    if (ui->gameField->gameOver || ui->gameField->gameWon){
        this->hide();
        parentWidget()->findChild<ChoosingLevel*>("choosingLevel")->show();
    }
    else {
        ui->gameField->stopGame();
        ui->gameField->repaint();
        QTimer* temp = new QTimer();
        connect(temp, SIGNAL(timeout()), this, SLOT(hideGameField()));
        temp->start(2000);
    }
}

void Game::hideGameField()
{
    this->hide();
    parentWidget()->findChild<ChoosingLevel*>("choosingLevel")->show();
    delete sender();
}

void Game::lives_display(int lives)
{
    ui->lives->display(lives);
}

void Game::record_display(int record)
{
    ui->record->display(record);
}
