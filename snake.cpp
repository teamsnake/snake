#include "snake.h"
void Snake::setPosition(int x, int y)
{
    this->m_x=x;
    this->m_y=y;
}
void Snake::Display(QPainter &painter)
{
    painter.setBrush(QBrush(this->m_color,Qt::SolidPattern));
    painter.setPen(Qt::SolidLine);
    painter.drawRect(this->m_x,this->m_y,SNAKE_WIDTH,SNAKE_HEIGHT);

}
