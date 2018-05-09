#include "recordstable.h"
#include "ui_recordstable.h"
#include <QFile>
#include <QTextStream>
#include <QDir>

RecordsTable::RecordsTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecordsTable)
{
    ui->setupUi(this);
    reload();
}

void RecordsTable::append(Record record)
{
    listOfRecords.push_back(record);
    std::sort(listOfRecords.begin(), listOfRecords.end());
    ui->table->clear();
    ui->table->setRowCount(0);
    //ui->table->horizontalHeaderItem(0)->setText(QString("Name"));
    //ui->table->horizontalHeaderItem(1)->setText(QString("Record"));

    for (auto i = 0; i < listOfRecords.size(); ++i){
        ui->table->insertRow(i);
        ui->table->setItem(i, 0, new QTableWidgetItem(listOfRecords[i].getName()));
        ui->table->setItem(i, 1, new QTableWidgetItem(QString::number(listOfRecords[i].getValue())));
    }
}

void RecordsTable::reload()
{
    ui->table->clear();
    ui->table->setRowCount( 0);
    //ui->table->horizontalHeaderItem(0)->setText(QString("Name"));
    //ui->table->horizontalHeaderItem(1)->setText(QString("Record"));
    this->listOfRecords.clear();

    QFile records(QDir::currentPath() + "/records.txt");
    if(records.open(QIODevice::ReadOnly)) {
        while (!records.atEnd()) {
            QString line = records.readLine();
            this->listOfRecords.push_back(Record(line.split(" ")[0], line.split(" ")[1].toInt()));
        }
        records.close();
    }
    std::sort(listOfRecords.begin(), listOfRecords.end());

    ui->table->setColumnCount(2);
    ui->table->setShowGrid(true);
    ui->table->setHorizontalHeaderLabels(QStringList() << "Name" << "Record");

    for (auto i = 0; i < listOfRecords.size(); ++i){
        ui->table->insertRow(i);
        ui->table->setItem(i, 0, new QTableWidgetItem(listOfRecords[i].getName()));
        ui->table->setItem(i, 1, new QTableWidgetItem(QString::number(listOfRecords[i].getValue())));
    }
}

RecordsTable::~RecordsTable()
{
    delete ui;
}
