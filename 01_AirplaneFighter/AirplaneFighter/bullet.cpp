#include "bullet.h"
#include "enemy.h"
#include "game.h"

extern Game* game;

/* Pink Bullet */
PinkBullet::PinkBullet(QGraphicsItem* parent)
    : QGraphicsPixmapItem (parent)
{
    setPixmap(QPixmap(":/Images/pinkbullet.png"));
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(BULLET_MOVE_TIME);
}

void PinkBullet::move()
{
    if (checkCollidingObjects() == true)
    {
        game->score->increaseScore();
        game->score->displayScore();

        scene()->removeItem(this);
        delete this;

        return;
    }
    QRectF rect = boundingRect();
    setPos(x(), y() - 10);
    if (y() + rect.height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

bool PinkBullet::checkCollidingObjects()
{
    bool bRes = false;

    QList<QGraphicsItem *> items = collidingItems();
    for (auto itr = items.begin(); itr != items.end(); itr++)
    {
        if (typeid (*(*itr)) == typeid(Enemy))
        {
            scene()->removeItem(*itr);
            Enemy* enemy = static_cast<Enemy*>(*itr);
            delete enemy;
            bRes = true;
        }
    }

    return bRes;
}

/* Blue Bullet */
BlueBullet::BlueBullet(QGraphicsItem* parent)
    : QGraphicsPixmapItem (parent)
{
    setPixmap(QPixmap(":/Images/bluebullet.png"));
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(BULLET_MOVE_TIME);
}

void BlueBullet::move()
{
    if (checkCollidingObjects() == true)
    {
        game->score->increaseScore();
        game->score->displayScore();

        scene()->removeItem(this);
        delete this;

        return;
    }
    QRectF rect = boundingRect();
    setPos(x(), y() - 10);
    if (y() + rect.height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

bool BlueBullet::checkCollidingObjects()
{
    bool bRes = false;

    QList<QGraphicsItem *> items = collidingItems();
    for (auto itr = items.begin(); itr != items.end(); itr++)
    {
        if (typeid (*(*itr)) == typeid(Enemy))
        {
            scene()->removeItem(*itr);
            Enemy* enemy = static_cast<Enemy*>(*itr);
            delete enemy;
            bRes = true;
        }
    }

    return bRes;
}
