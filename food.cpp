#include "food.h"
#include<QDebug>
Food::Food(bool isExist)
{
    this->food_isExist=isExist;
    food_size=20;
}

void Food::Display(QPainter &painter)
{
    //生成Food
    painter.setBrush(Qt::SolidPattern);
    painter.drawPixmap(QRect(this->food_x,this->food_y,this->food_size,this->food_size),QPixmap(this->food_image));
    //qDebug()<<"生成food";
}
