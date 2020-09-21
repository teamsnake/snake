#ifndef FOOD_H
#define FOOD_H
#include<QPainter>
#include<QImage>
class Food
{
public:
    Food(bool isExist);
    void Display(QPainter &painter);
    bool food_isExist;
    int food_x;
    int food_y;
    int food_size;
    int food_index;
    QString food_image;
};

#endif // FOOD_H
