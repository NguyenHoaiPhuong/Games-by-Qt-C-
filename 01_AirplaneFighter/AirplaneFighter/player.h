#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "configuration.h"
#include "bullet.h"

class Player : public QGraphicsPixmapItem
{
public:
    Player(QGraphicsItem* parent = 0);

    void keyPressEvent(QKeyEvent* event) override;
};

#endif // PLAYER_H
