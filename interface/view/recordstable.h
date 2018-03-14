#ifndef RECORDSTABLE_H
#define RECORDSTABLE_H

#include <QWidget>

namespace Ui {
class RecordsTable;
}

class RecordsTable : public QWidget
{
    Q_OBJECT

public:
    explicit RecordsTable(QWidget *parent = 0);
    ~RecordsTable();

private:
    Ui::RecordsTable *ui;
};

#endif // RECORDSTABLE_H
