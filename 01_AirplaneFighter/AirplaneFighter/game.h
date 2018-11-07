#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include "player.h"
#include "enemy.h"
#include "score.h"
#include "health.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = nullptr);

public slots:
    void CreateEnemy();

public:
    QGraphicsScene* scene;
    Score* score;
    Health* health;
    Player* player;
};

#endif // GAME_H
