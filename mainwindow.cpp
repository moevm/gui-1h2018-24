#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->choosingLevel->setVisible(false);
    ui->recordsTable->setVisible(false);
    ui->gameView->setVisible(false);
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
    ui->mainMenu->setVisible(false);
    ui->choosingLevel->setVisible(true);
}

void MainWindow::on_recordsTable_clicked(bool)
{
    ui->mainMenu->setVisible(false);
    ui->recordsTable->setVisible(true);
}

void MainWindow::on_level1Button_clicked(bool)
{
    ui->choosingLevel->setVisible(false);
    ui->gameView->setVisible(true);
}

void MainWindow::on_level2Button_clicked(bool)
{
    ui->choosingLevel->setVisible(false);
    ui->gameView->setVisible(true);
}

void MainWindow::on_exitChoosingLevelButton_clicked(bool)
{
    ui->choosingLevel->setVisible(false);
    ui->mainMenu->setVisible(true);
}

void MainWindow::on_newButton_clicked(bool)
{

}

void MainWindow::on_exitGameButton_clicked(bool)
{
    ui->gameView->setVisible(false);
    ui->choosingLevel->setVisible(true);
}

void MainWindow::on_exitRecordsTableButton_clicked(bool)
{
    ui->recordsTable->setVisible(false);
    ui->mainMenu->setVisible(true);
}
