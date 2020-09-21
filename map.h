#ifndef MAP_H
#define MAP_H
#include"mainwindow.h"
#include <QObject>
#include<QPainter>
class Map
{
public:
    Map();
    void Display(QPainter &painter,int wid,int hei);
private:

};
#endif // MAP_H
