#ifndef STATE_H
#define STATE_H
#include <QObject>


class State : public QObject
{
    Q_OBJECT

    int lives;
    int record;
public:
    State();
    void resetState();
    int getLives() const;
    void setLives(int value);
    int getRecord() const;
    void setRecord(int value);
    void decrementLives();
    void incrementRecord();
signals:
    void livesChanged(int lives);
    void recordChanged(int record);
};

#endif // STATE_H
