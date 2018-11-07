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
#include "title.h"
#include "button.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = nullptr);

public slots:
    void gameStart();
    void createEnemy();

private:
    void initView();
    void initGameScene();
    void initPlayer();
    void initEnemy();
    void initHealth();
    void initScore();
    void initTitle();
    void initButtons();
    void initMusic();

public:
    void gameOver();

public:
    QGraphicsScene* scene;
    Score* score;
    Health* health;
    Player* player;
    Title* title;
    Button* startButton;
    Button* endButton;
    QTimer* enemyCreationTimer;
    QMediaPlayer* music;
};

#endif // GAME_H
