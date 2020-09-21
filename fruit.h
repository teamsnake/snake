#ifndef FRUIT_H
#define FRUIT_H
#include<QPainter>
#include<QImage>

class Fruit
{
public:
    Fruit(bool fisExist);
    void Display(QPainter &painter);
    bool fruit_isExist;
    int fruit_x;
    int fruit_y;
    int fruit_size;
    int fruit_index;
    QString fruit_image;
};

#endif // FRUIT_H
