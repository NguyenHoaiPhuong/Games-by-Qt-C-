#include "game.h"

Game::Game(QWidget *parent)
    : QGraphicsView (parent)
{
    // View or window
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);

    // Game Scene
    scene = new QGraphicsScene();
    QGraphicsPixmapItem* bg = new QGraphicsPixmapItem();
    QPixmap bg_pixmap = QPixmap(":/Images/background.png").scaled(WINDOW_WIDTH,WINDOW_HEIGHT);
    bg->setPixmap(bg_pixmap);
    scene->addItem(bg);
    setScene(scene);
    setSceneRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);

    // Score
    score = new Score();
    scene->addItem(score);
    score->setPos(SCORE_POS_X, SCORE_POS_Y);
    score->displayScore();

    // Health
    health = new Health();
    scene->addItem(health);
    health->setPos(HEALTH_POS_X, HEALTH_POS_Y);
    health->displayHealth();

    // Player Item
    player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    // Enemy Items
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(CreateEnemy()));
    timer->start(ENEMY_CREATE_TIME);

    // Music
    QMediaPlayer* music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/Sounds/HelloVietNam-QuynhAnh.mp3"));
    music->play();

    show();
}

void Game::CreateEnemy()
{
    Enemy* enemy = new Enemy();
    scene->addItem(enemy);
}
