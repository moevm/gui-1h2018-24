#include "mainmenu.h"
#include "ui_mainmenu.h"

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

void MainMenu::on_exit_clicked(bool)
{
<<<<<<< HEAD
=======
    //this->parent()->findChild<QWidget*>("MainWindow")->close();
>>>>>>> bfe41cb9ccdfbe3f5c8bb996b90f3d480253f172
    exit(0);
}
