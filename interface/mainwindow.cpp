#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "game/gamefield.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->choosingLevel->hide();
    ui->recordsTable->hide();
    ui->gameView->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exit_clicked(bool)
{
    exit(0);
}

void MainWindow::on_newGame_clicked(bool)
{
    ui->mainMenu->hide();
    ui->choosingLevel->show();
}

void MainWindow::on_recordsTable_clicked(bool)
{
    ui->mainMenu->hide();
    ui->recordsTable->show();
}

void MainWindow::on_level1Button_clicked(bool)
{
    ui->choosingLevel->hide();
    ui->gameView->findChild<GameField*>("gameField")->setLevel(1);
    ui->gameView->show();
}

void MainWindow::on_level2Button_clicked(bool)
{
    ui->choosingLevel->hide();
    ui->gameView->findChild<GameField*>("gameField")->setLevel(2);
    ui->gameView->show();
}

void MainWindow::on_exitChoosingLevelButton_clicked(bool)
{
    ui->choosingLevel->hide();
    ui->mainMenu->show();
}

void MainWindow::on_exitRecordsTableButton_clicked(bool)
{
    ui->recordsTable->hide();
    ui->mainMenu->show();
}


