#ifndef GANME_H
#define GANME_H

#include <QMainWindow>
#include<QTimer>
#include<QPaintEvent>
#include<QKeyEvent>
#include"snake.h"
#include"data.h"
#include"map.h"
#include"food.h"
#include"tipsform.h"
#include"helpform.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Ganme;
}
QT_END_NAMESPACE

class Ganme : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ganme(QWidget *parent = nullptr);
    ~Ganme();
protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::Ganme *ui;
    QTimer *paintTimer;
    QVector<Snake*>snake;
    orientation currentToward;
    Map gameMap;
    QPainter *painter;
    Food *food;
    int score;
private:
    void DisPlayScore(QPainter &);
    void CreateSnakeHead();
    void CreateFood();
    void StartGame();
    void BoundaryTest(int s_x,int s_y);
};

#endif // GANME_H
