#ifndef CHOOSINGLEVEL_H
#define CHOOSINGLEVEL_H

#include <QWidget>

namespace Ui {
class ChoosingLevel;
}

class ChoosingLevel : public QWidget
{
    Q_OBJECT

public:
    explicit ChoosingLevel(QWidget *parent = 0);
    ~ChoosingLevel();
private:
    Ui::ChoosingLevel *ui;
};

#endif // CHOOSINGLEVEL_H
