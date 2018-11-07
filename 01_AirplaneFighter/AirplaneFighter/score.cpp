#include "score.h"

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem (parent)
{
    setFont(QFont("Arial", 20));
    setDefaultTextColor(Qt::blue);
}

int Score::getScore()
{
    return score;
}

void Score::setScore(const int &c)
{
    score = c;
}

void Score::increaseScore()
{
    score ++;
}

void Score::displayScore()
{
    setPlainText("Score:\t\t" + QString::number(score));
}
