#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>
#include <configuration.h>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent = nullptr);

    int getScore();
    void increaseScore();
    void displayScore();
private:
    int score;
};

#endif // SCORE_H
