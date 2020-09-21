#ifndef SNAKE_H
#define SNAKE_H
#include"mainwindow.h"
#include<QObject>
#include<QRect>
#include<QColor>
#include<QPainter>
#include<QDebug>

enum orientation{Sright,Sleft,Sup,Sdown};
class Snake:public QObject
{
    Q_OBJECT

public:
    Snake(QColor color)
    {
        this->m_color=color;
    }
    int m_x;
    int m_y;
    QColor m_color;
    void setPosition(int x,int y);
    void Display(QPainter &painter);
    Snake& operator=(Snake& s)
    {
        this->m_x=s.m_x;
        this->m_y=s.m_y;
        return *this;
    }
};
#endif // SNAKE_H
