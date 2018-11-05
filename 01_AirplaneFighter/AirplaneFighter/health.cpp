#include "health.h"

Health::Health()
{
    health = 3;

    setFont(QFont("Arial", 20));
    setDefaultTextColor(Qt::blue);
}

int Health::getHealth()
{
    return health;
}

void Health::decreaseHealth()
{
    health --;
}

void Health::displayHealth()
{
    setPlainText("Health:\t" + QString::number(health));
}
