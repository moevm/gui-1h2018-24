#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD
    ui->choosingLevel->setVisible(false);
    ui->recordsTable->setVisible(false);
=======
>>>>>>> bfe41cb9ccdfbe3f5c8bb996b90f3d480253f172
}

MainWindow::~MainWindow()
{
    delete ui;
}
