#include "state.h"
State::State()
{
    resetState();
}

void State::resetState()
{
    lives = 2;
    record = 0;
    emit livesChanged(lives);
    emit recordChanged(record);
}

int State::getLives() const
{
    return lives;
}

void State::setLives(int value)
{
    lives = value;
    emit livesChanged(lives);
}

int State::getRecord() const
{
    return record;
}

void State::setRecord(int value)
{
    record = value;
    emit recordChanged(record);
}

void State::decrementLives()
{
    --lives;
    emit livesChanged(lives);
}

void State::incrementRecord()
{
    ++record;
    emit recordChanged(record);
}
