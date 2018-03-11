#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_exit_clicked(bool);
    void on_newGame_clicked(bool);
    void on_recordsTable_clicked(bool);
    void on_level1Button_clicked(bool);
    void on_level2Button_clicked(bool);
    void on_exitChoosingLevelButton_clicked(bool);
    void on_newButton_clicked(bool);
    void on_exitGameButton_clicked(bool);
    void on_exitRecordsTableButton_clicked(bool);



};

#endif // MAINWINDOW_H
