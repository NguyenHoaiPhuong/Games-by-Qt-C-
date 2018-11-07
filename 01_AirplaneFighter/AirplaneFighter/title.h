#ifndef TITLE_H
#define TITLE_H

#include <QGraphicsTextItem>
#include <QFont>

class Title : public QGraphicsTextItem
{
public:
    Title(QGraphicsItem *parent = nullptr);

    void setText(const QString& text);
};

#endif // TITLE_H
