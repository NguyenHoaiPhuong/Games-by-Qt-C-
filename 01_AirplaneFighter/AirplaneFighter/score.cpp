#include "score.h"

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem (parent)
{
    score = 0;

    setFont(QFont("Arial", 20));
    setDefaultTextColor(Qt::blue);
}

int Score::getScore()
{
    return score;
}

void Score::increaseScore()
{
    score ++;
}

void Score::displayScore()
{
    setPlainText("Score:\t\t" + QString::number(score));
}
