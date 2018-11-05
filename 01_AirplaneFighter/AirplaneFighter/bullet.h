#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include "configuration.h"

class PinkBullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PinkBullet(QGraphicsItem* parent = 0);

public slots:
    void move();

private:
    bool checkCollidingObjects();
};

class BlueBullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    BlueBullet(QGraphicsItem* parent = 0);

public slots:
    void move();

private:
    bool checkCollidingObjects();
};

#endif // BULLET_H
