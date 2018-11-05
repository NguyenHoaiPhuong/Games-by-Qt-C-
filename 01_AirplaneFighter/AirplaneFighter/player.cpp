#include "player.h"

Player::Player(QGraphicsItem* parent)
    : QGraphicsPixmapItem (parent)
{
    QPixmap pm;
    pm.load(":/Images/player.png");
    //pm.fill(Qt::transparent);
    setPixmap(pm);
    QRectF rect = this->boundingRect();
    setPos((WINDOW_WIDTH - rect.width())*0.5, WINDOW_HEIGHT - rect.height());
}

void Player::keyPressEvent(QKeyEvent *event)
{
    QRectF rect = this->boundingRect();
    if (event->key() == Qt::Key_Left)
    {
        if (x() > 0)
        {
            setPos(x() - PLAYER_MOVE, y());
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (x() < WINDOW_WIDTH - rect.width())
        {
            setPos(x() + PLAYER_MOVE, y());
        }
    }
    else if (event->key() == Qt::Key_Up)
    {
        if (y() > 0)
        {
            setPos(x(), y() - PLAYER_MOVE);
        }
    }
    else if (event->key() == Qt::Key_Down)
    {
        if (y() < WINDOW_HEIGHT - rect.height())
        {
            setPos(x(), y() + PLAYER_MOVE);
        }
    }
    else if (event->key() == Qt::Key_A)
    {
        PinkBullet* pinkbullet = new PinkBullet();
        pinkbullet->setPos(x() + rect.width() * 0.16, y());
        scene()->addItem(pinkbullet);
    }
    else if (event->key() == Qt::Key_D)
    {
        BlueBullet* bluebullet = new BlueBullet();
        bluebullet->setPos(x() + rect.width() * 0.75, y());
        scene()->addItem(bluebullet);
    }
}
