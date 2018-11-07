#include "health.h"

Health::Health()
{
    setFont(QFont("Arial", 20));
    setDefaultTextColor(Qt::blue);
}

int Health::getHealth()
{
    return health;
}

void Health::setHealth(const int &h)
{
    health = h;
}

void Health::decreaseHealth()
{
    health --;
}

void Health::displayHealth()
{
    setPlainText("Health:\t" + QString::number(health));
}
