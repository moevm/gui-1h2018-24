#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "choosinglevel.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}
