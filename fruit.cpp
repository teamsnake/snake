#include "fruit.h"

Fruit::Fruit(bool fisExist)
{
    this->fruit_isExist=fisExist;
    fruit_size=20;
}

void Fruit::Display(QPainter &painter)
{
    //生成fruit
    painter.setBrush(Qt::SolidPattern);
    painter.drawPixmap(QRect(this->fruit_x,this->fruit_y,this->fruit_size,this->fruit_size)\
                       ,QPixmap(this->fruit_image));
}

