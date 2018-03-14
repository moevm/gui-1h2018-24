#include "recordstable.h"
#include "ui_recordstable.h"

RecordsTable::RecordsTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecordsTable)
{
    ui->setupUi(this);
}

RecordsTable::~RecordsTable()
{
    delete ui;
}
