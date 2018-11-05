#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QFont>
#include "configuration.h"

class Health : public QGraphicsTextItem
{
public:
    Health();

    int getHealth();
    void decreaseHealth();
    void displayHealth();

private:
    int health;
};

#endif // HEALTH_H
