#ifndef RECORDSTABLE_H
#define RECORDSTABLE_H

#include <QWidget>
#include <records/record.h>
#include<QtSql/QSqlTableModel>

namespace Ui {
class RecordsTable;
}

class RecordsTable : public QWidget
{
    Q_OBJECT

    std::vector<Record> listOfRecords;
public:
    explicit RecordsTable(QWidget *parent = 0);
    void append(Record record);
    void reload();
    ~RecordsTable();

private:
    Ui::RecordsTable *ui;
};

#endif // RECORDSTABLE_H
