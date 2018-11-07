#include "game.h"

Game::Game(QWidget *parent)
    : QGraphicsView (parent)
    , scene(nullptr)
    , player(nullptr)
    , enemyCreationTimer(nullptr)
    , health (nullptr)
    , score (nullptr)
    , title(nullptr)
    , startButton(nullptr)
    , endButton(nullptr)
    , music(nullptr)
{
    // View or window
    initView();

    // Game Scene
    initGameScene();

    // Game Title
    initTitle();

    // Start and End buttons
    initButtons();

    show();
}

void Game::gameStart()
{
    // Score
    initScore();

    // Health
    initHealth();

    // Player Item
    initPlayer();

    // Enemy Items
    initEnemy();

    // Music
    initMusic();

    // Title
    title->setVisible(false);

    // Buttons
    startButton->setVisible(false);
    endButton->setVisible(false);
}

void Game::createEnemy()
{
    Enemy* enemy = new Enemy();
    scene->addItem(enemy);
}

void Game::initView()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);
}

void Game::initGameScene()
{
    scene = new QGraphicsScene();
    QGraphicsPixmapItem* bg = new QGraphicsPixmapItem();
    QPixmap bg_pixmap = QPixmap(":/Images/background.png").scaled(WINDOW_WIDTH,WINDOW_HEIGHT);
    bg->setPixmap(bg_pixmap);
    scene->addItem(bg);
    setScene(scene);
    setSceneRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
}

void Game::initPlayer()
{
    player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
}

void Game::initEnemy()
{
    enemyCreationTimer = new QTimer(this);
    connect(enemyCreationTimer, SIGNAL(timeout()), this, SLOT(createEnemy()));
    enemyCreationTimer->start(ENEMY_CREATE_TIME);
}

void Game::initHealth()
{
    if (!health)
    {
        health = new Health();
        scene->addItem(health);
        health->setPos(HEALTH_POS_X, HEALTH_POS_Y);
    }
    health->setVisible(true);
    health->setHealth(3);
    health->displayHealth();
}

void Game::initScore()
{
    if (!score)
    {
        score = new Score();
        scene->addItem(score);
        score->setPos(SCORE_POS_X, SCORE_POS_Y);
    }
    score->setVisible(true);
    score->setScore(0);
    score->displayScore();
}

void Game::initTitle()
{
    title = new Title();
    title->setText("Aircraft Battle");
    scene->addItem(title);
    title->setPos((width() - title->boundingRect().width()) / 2, (height() - 4 * title->boundingRect().height()) / 2);
}

void Game::initButtons()
{
    startButton = new Button("Start");
    startButton->setPos((WINDOW_WIDTH - BUTTON_WIDTH) / 2, (WINDOW_HEIGHT - 3.5 * BUTTON_HEIGHT) / 2);
    connect(startButton, SIGNAL(clicked()), this, SLOT(gameStart()));

    endButton = new Button("Quit");
    endButton->setPos((WINDOW_WIDTH - BUTTON_WIDTH) / 2, (WINDOW_HEIGHT - BUTTON_HEIGHT) / 2);
    connect(endButton, SIGNAL(clicked()), this, SLOT(close()));

    scene->addItem(startButton);
    scene->addItem(endButton);
}

void Game::initMusic()
{
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/Sounds/HelloVietNam-QuynhAnh.mp3"));
    music->play();
}

void Game::gameOver()
{
    // Player and Enemies
    scene->removeItem(player);
    enemyCreationTimer->stop();

    // Health
    health->setVisible(false);

    // Score
    score->setVisible(false);

    // Title
    title->setVisible(true);
    title->setText("Game Over");
    title->setPos((width() - title->boundingRect().width()) / 2, (height() - 4 * title->boundingRect().height()) / 2);

    // Buttons
    startButton->setVisible(true);
    startButton->setText("Play Again");
    endButton->setVisible(true);

    // Music
    music->stop();
}
