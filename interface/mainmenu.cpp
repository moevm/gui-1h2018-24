#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    ui->logo->setPixmap(QPixmap(":/images/logo.png"));
}

MainMenu::~MainMenu()
{
    delete ui;
}
