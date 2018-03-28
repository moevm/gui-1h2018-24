#include "game.h"
#include "ui_game.h"
#include "interface/view/choosinglevel.h"

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    ui->gameField->setStyleSheet("border: 3px solid black");
    ui->gameField->resize(600,450);
    ui->gameField->setWindowTitle("BreakOut");
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
    if(!ui->gameField->gameOver && !ui->gameField->gameWon){
        ui->gameField->stopGame();
    }
    this->hide();
    parentWidget()->findChild<ChoosingLevel*>("choosingLevel")->show();
}
