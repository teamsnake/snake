#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#define GAME_WIDTH 600
#define GAME_HEIGHT 600
#define SNAKE_WIDTH 20
#define SNAKE_HEIGHT 20
#define SNAKE_INIT_X 40
#define SNAKE_INIT_Y 40
#define WALL_WIDTH 20
#define FoodPicture ":/dot.png"
#define FruitPicture ":/fruit%1.png"

#include <QMainWindow>
#include<QTimer>
#include<QPaintEvent>
#include<QKeyEvent>

#include"snake.h"
#include"map.h"
#include"food.h"
#include"fruit.h"
#include"help.h"
#include"final.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    static int SnakeNode;
    static int SnakeSpeed;
    QTimer *paintTimer;
    QVector<Snake*>snake;
    orientation currentToward;
    Map gameMap;
    QPainter *painter;
    Food *food;
    Fruit *fruit;
    int score;

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

    void DisPlayScore(QPainter &);
    void CreateSnakeHead();
    void CreateFood();
    void CreateFruit();
    void StartGame();
    void BoundaryTest(int s_x,int s_y);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

};

#endif // MAINWINDOW_H
