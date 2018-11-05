#ifndef ENEMY_H
#define ENEMY_H

#include <stdlib.h>
#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "configuration.h"

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsItem *parent = nullptr);

public slots:
    void move();

private:
    bool checkCollidingItems();
};

#endif // ENEMY_H
