#include "game.h"
#include "ui_game.h"
#include "interface/choosinglevel.h"
#include <iostream>
#include <records/record.h>
#include <interface/recordstable.h>
#include <QTimer>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QRegularExpression>
#include <QPalette>


Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    ui->gameField->setStyleSheet("border: 3px solid black");
    ui->gameField->resize(600,450);
    ui->gameField->setWindowTitle("BreakOut");
    //ui->gameField->setStyleSheet("background-color:black;");
    ui->lives->setPalette(Qt::blue);
    ui->record->setPalette(Qt::blue);
    connect(ui->gameField->getState(), SIGNAL(livesChanged(int)), ui->lives, SLOT(display(int)));
    connect(ui->gameField->getState(), SIGNAL(recordChanged(int)), ui->record, SLOT(display(int)));
}

Game::~Game()
{
    delete ui;
}

void Game::showEvent(QShowEvent *)
{
    ui->gameField->setFocus();
    ui->gameField->startGame();
}

void Game::showFinishDialog()
{
    QInputDialog *dialog = new QInputDialog();
    connect(dialog, SIGNAL(accepted()), this, SLOT(hideGameField()));
    dialog->setStyleSheet("background-color:white;");

    QString name = dialog->getText(this, "Saving record", "Enter your name:");
    QString record = QString::number(ui->gameField->getState()->getRecord());
    bool replaceFlag = false;
    bool hasName = false;

    if (name != ""){
        QStringList strList;
        QFile records(QDir::currentPath() + "/records.txt");
        if(records.open(QIODevice::ReadOnly)) {
            while (!records.atEnd()){
                strList << records.readLine();
                QString last = strList[strList.count() - 1];
                if (last.contains(QRegularExpression("\\b" + name + "\\b\\s\\d\\d?"))){
                    hasName = true;
                    if (last.split(name + " ")[1].toInt() < record.toInt()){
                        strList[strList.count() - 1].replace(QRegularExpression("\\b" + name + "\\b\\s\\d\\d?"),
                                                             name + " " + record);
                        replaceFlag = true;
                    }
                    else {
                        records.close();
                        dialog->accept();
                        return;
                    }
                }
            }
            records.close();
        }
        if (records.open(QIODevice::WriteOnly)) {
            QTextStream stream(&records);
            foreach (QString s, strList) {
                stream << s;
            }
            if (!replaceFlag && !hasName){
                stream << name + " " + record + "\n";
                parentWidget()->findChild<RecordsTable*>("recordsTable")->append(Record(name, record.toInt()));
            }
            records.close();
        }
    }
    if (replaceFlag) parentWidget()->findChild<RecordsTable*>("recordsTable")->reload();
    dialog->accept();
}

void Game::on_newButton_clicked(bool)
{
    if(!ui->gameField->gameOver && !ui->gameField->gameWon){
        ui->gameField->stopGame();
    }
    ui->gameField->startGame();
    ui->gameField->setFocus();
}

void Game::on_exitGameButton_clicked(bool)
{
    if (!ui->gameField->gameOver && !ui->gameField->gameWon){
        ui->gameField->stopGame();
        //ui->gameField->repaint();
    }
    showFinishDialog();

}

void Game::hideGameField()
{
    this->hide();
    parentWidget()->findChild<ChoosingLevel*>("choosingLevel")->show();
}

void Game::lives_display(int lives)
{
    ui->lives->display(lives);
}

void Game::record_display(int record)
{
    ui->record->display(record);
}
