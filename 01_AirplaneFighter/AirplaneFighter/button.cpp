#include "button.h"

Button::Button(const QString& strText, QGraphicsItem* parent) : QGraphicsRectItem (parent)
{
    QBrush br;
    br.setStyle(Qt::SolidPattern);
    br.setColor(Qt::darkRed);
    setBrush(br);    
    setRect(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);

    text = new QGraphicsTextItem(this);
    setText(strText);

    // Allow responding to hover
    setAcceptHoverEvents(true);
}

void Button::setText(const QString &strText)
{
    QFont font;
    font.setPointSize(20);
    font.setFamily("Arial");
    text->setFont(font);

    text->setPlainText(strText);    
    text->setPos((BUTTON_WIDTH - text->boundingRect().width()) / 2, (BUTTON_HEIGHT - text->boundingRect().height()) / 2);
    text->setDefaultTextColor(Qt::white);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event)
        emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    if (event)
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::red);
        setBrush(brush);
    }
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if (event)
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::darkRed);
        setBrush(brush);
    }
}
