#ifndef RECORD_H
#define RECORD_H
#include <QString>

class Record
{
    QString name;
    int value;
public:
    Record(QString name, int value);
    QString getName() const;
    void setName(const QString &value);
    int getValue() const;
    void setValue(int value);
    bool operator <(const Record& other);
};

#endif // RECORD_H
