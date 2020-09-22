#include "map.h"

Map::Map()
{

}
void Map::Display(QPainter &painter,int wid,int hei)
{
    painter.setPen(QPen(Qt::white,WALL_WIDTH,Qt::SolidLine));
    painter.drawLine(0,0,wid,0);
    painter.drawLine(0,hei,wid,hei);
    painter.drawLine(0,0,0,hei);
    painter.drawLine(wid,0,wid,hei);
    painter.setBrush(QBrush(QColor(0,0,0),Qt::SolidPattern));
    //painter.setPen(QPen(Qt::black,WALL_WIDTH,Qt::SolidLine));
    painter.drawRect(0,0,GAME_WIDTH,GAME_HEIGHT);

}
