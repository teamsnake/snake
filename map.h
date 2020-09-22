#ifndef MAP_H
#define MAP_H

#include <QObject>
#include<QPainter>
#include"data.h"

class Map
{
public:
    Map();
    void Display(QPainter &painter,int wid,int hei);
signals:

public slots:
};

#endif // MAP_H
