#include "record.h"

QString Record::getName() const
{
    return name;
}

void Record::setName(const QString &value)
{
    name = value;
}

int Record::getValue() const
{
    return value;
}

void Record::setValue(int value)
{
    value = value;
}

bool Record::operator <(const Record& other)
{
    return this->value >     other.value;
}

Record::Record(QString name, int value)
    :name(name), value(value)
{
}
