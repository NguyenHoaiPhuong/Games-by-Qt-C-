#include "title.h"

Title::Title(QGraphicsItem *parent) : QGraphicsTextItem (parent)
{
    QFont font;
    font.setPointSize(50);
    font.setFamily("Arial");
    setFont(font);
    setDefaultTextColor(Qt::red);
}

void Title::setText(const QString &text)
{
    setPlainText(text);
}
