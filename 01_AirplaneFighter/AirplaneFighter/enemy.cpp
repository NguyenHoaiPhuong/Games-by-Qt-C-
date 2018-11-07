#include "enemy.h"
#include "game.h"
#include "player.h"
#include "health.h"

extern Game* game;

Enemy::Enemy(QGraphicsItem *parent)
    : QGraphicsPixmapItem (parent)
{
    setPixmap(QPixmap(":/Images/enemy.png"));
    int x = rand()%(WINDOW_WIDTH - 200);
    setPos(x + 100, 0);

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(ENEMY_MOVE_TIME);
}

void Enemy::move()
{
    if (checkCollidingItems() == true)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }

    if (y() < WINDOW_HEIGHT)
    {
        setPos(x(), y() + ENEMY_MOVE);
    }
    else
    {
        scene()->removeItem(this);
        delete this;

        game->health->decreaseHealth();
        game->health->displayHealth();
        if (game->health->getHealth() <= 0)
            game->gameOver();
    }
}

bool Enemy::checkCollidingItems()
{
    bool bRes = false;
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (auto itr = colliding_items.begin(); itr != colliding_items.end(); itr++)
    {
        if (typeid (*(*itr)) == typeid(Player))
        {
            game->health->decreaseHealth();
            game->health->displayHealth();
            if (game->health->getHealth() <= 0)
                game->gameOver();

            bRes = true;
        }
    }
    return bRes;
}
