#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QFont>
#include "configuration.h"

class Button : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Button(const QString& strText, QGraphicsItem* parent = nullptr);

    void setText(const QString& strText);

signals:
    void clicked();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

private:
    QGraphicsTextItem* text;
};

#endif // BUTTON_H
