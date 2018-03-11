#include "choosinglevel.h"
#include "ui_choosinglevel.h"

ChoosingLevel::ChoosingLevel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChoosingLevel)
{
    ui->setupUi(this);
}

ChoosingLevel::~ChoosingLevel()
{
    delete ui;
}
