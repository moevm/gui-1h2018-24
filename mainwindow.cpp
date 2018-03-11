#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->choosingLevel->setVisible(false);
    ui->recordsTable->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
