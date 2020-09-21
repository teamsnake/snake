#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QPainter>
#include<QTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    score=0;
    SnakeNode=3;
    SnakeSpeed=SNAKE_WIDTH;
    food=nullptr;
    CreateSnakeHead();
    paintTimer=new QTimer;
    paintTimer->setInterval(300);
    StartGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    //painter.begin(this);
    DisPlayScore(painter);
    gameMap.Display(painter,this->width(),this->height());
    if(food==nullptr)
    {
        CreateFood();
        qDebug()<<"食物坐标:"<<food->food_x<<food->food_y;
        food->Display(painter);
    }
    else {
        if(!food->food_isExist)
        {
            delete food;
            food=nullptr;
        }
        else
        food->Display(painter);
    }
    for(int i=0;i<snake.length();i++)
    {
        snake.at(i)->Display(painter);
    }
    //painter.end();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_D)
    {
        if(currentToward!=orientation::Sright)
            currentToward=orientation::Sright;
    }
    else if(event->key()==Qt::Key_A)
    {
        if(currentToward!=orientation::Sleft)
            currentToward=orientation::Sleft;
    }
    else if(event->key()==Qt::Key_W)
    {
        if(currentToward!=orientation::Sup)
            currentToward=orientation::Sup;
    }
    else if(event->key()==Qt::Key_S)
    {
        if(currentToward!=orientation::Sdown)
            currentToward=orientation::Sdown;
    }
    else if(event->key()==Qt::Key_Escape)
    {
        paintTimer->stop();
    }
    else if(event->key()==Qt::Key_Space)
    {
        paintTimer->start();
    }
}

void MainWindow::DisPlayScore(QPainter &painter)
{
    painter.setPen(QPen(Qt::red,10,Qt::SolidLine));
    painter.drawText(GAME_WIDTH-150,60,QString("score:%1").arg(score));
}

void MainWindow::CreateSnakeHead()
{
    for(int i=0;i<SnakeNode;i++)
    {
        qsrand(QTime(0,0,0).msecsTo(QTime::currentTime())*i);
        int r=rand()%256;
        int g=rand()%256;
        int b=rand()%256;
        Snake *s=new Snake(QColor(r,g,b));
        qDebug()<<s->m_color;
        snake.push_back(s);
        qDebug()<<"节点:"<<i+1;
    }
    for(int i=0;i<snake.length();i++)
    {
        snake.at(i)->setPosition(SNAKE_INIT_X,SNAKE_INIT_Y);
    }
}

void MainWindow::CreateFood()
{
    food=new Food(true);
    food->food_image=FoodPicture;
    qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
    food->food_x=rand()%((GAME_WIDTH-WALL_WIDTH)-WALL_WIDTH)+WALL_WIDTH;
    food->food_y=rand()%((GAME_HEIGHT-WALL_WIDTH)-WALL_WIDTH)+WALL_WIDTH;
}

void MainWindow::CreateFruit()
{
    fruit=new Fruit(true);
    fruit->fruit_image=FruitPicture;
    qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
    fruit->fruit_index=rand()%4+1;
    fruit->fruit_image=fruit->fruit_image.arg(fruit->fruit_index);
    qDebug()<<fruit->fruit_image;
    fruit->fruit_x=rand()%((GAME_WIDTH-WALL_WIDTH)-WALL_WIDTH);
    fruit->fruit_y=rand()%((GAME_HEIGHT-WALL_WIDTH)-WALL_WIDTH);
}

void MainWindow::StartGame()
{
    currentToward=Sright;
    paintTimer->start();
    connect(paintTimer,&QTimer::timeout,[=](){
        switch (currentToward)
        {
            case orientation::Sright:
            {
                for(int i=snake.length()-1;i>0;i--)
                {
                    *snake[i]=*snake[i-1];
                }
                BoundaryTest(snake[0]->m_x+SnakeSpeed,snake[0]->m_y);
                snake[0]->setPosition(snake[0]->m_x+SnakeSpeed,snake[0]->m_y);
                break;
            }
            case orientation::Sleft:
            {
                for(int i=snake.length()-1;i>0;i--)
                {
                    *snake[i]=*snake[i-1];
                }
                BoundaryTest(snake[0]->m_x-SnakeSpeed,snake[0]->m_y);
                snake[0]->setPosition(snake[0]->m_x-SnakeSpeed,snake[0]->m_y);

                break;
            }
            case orientation::Sup:
            {
                for(int i=snake.length()-1;i>0;i--)
                {
                    *snake[i]=*snake[i-1];
                }
                BoundaryTest(snake[0]->m_x,snake[0]->m_y-SnakeSpeed);
                snake[0]->setPosition(snake[0]->m_x,snake[0]->m_y-SnakeSpeed);

                break;
            }
            case orientation::Sdown:
            {
                for(int i=snake.length()-1;i>0;i--)
                {
                    *snake[i]=*snake[i-1];
                }
                BoundaryTest(snake[0]->m_x,snake[0]->m_y+SnakeSpeed);
                snake[0]->setPosition(snake[0]->m_x,snake[0]->m_y+SnakeSpeed);
                break;
            }
        }
        update();
    });
}

void MainWindow::BoundaryTest(int s_x, int s_y)
{
    setWindowTitle(QString("当前坐标:(%1, %2)").arg(s_x).arg(s_y));
    if(s_x>GAME_WIDTH-WALL_WIDTH || s_x<WALL_WIDTH-snake[0]->m_x || s_y>GAME_HEIGHT-WALL_WIDTH || s_y<WALL_WIDTH-snake[0]->m_y)
    {
        paintTimer->stop();
        final *tips=new final;
        tips->getStore(score);
        tips->show();

        connect(tips,&final::restart,[=](){
            score=0;
            SnakeNode=3;
            SnakeSpeed=SNAKE_WIDTH;
            for(int i=snake.length()-1;i>2;i--)
            {
                snake.pop_back();
            }
            for(int i=0;i<snake.length();i++)
            {
                snake.at(i)->setPosition(SNAKE_INIT_X,SNAKE_INIT_Y);
            }
            food=nullptr;
            currentToward=Sright;
            paintTimer->start();
        });
        connect(tips,&final::quit,[=](){
            this->close();
        });
    }
    if(food!=nullptr)
    {
        if(abs(s_x-food->food_x)<(SNAKE_WIDTH)&&abs(s_y-food->food_y)<(SNAKE_HEIGHT))
        {
            food->food_isExist=false;
            score+=food->food_index;
            qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
            int r=rand()%256;
            int g=rand()%256;
            int b=rand()%256;
            Snake *s=new Snake(QColor(r,g,b));
            qDebug()<<s->m_color;
            snake.push_back(s);
            snake.last()->setPosition(snake.at(snake.length()-2)->m_x,snake.at(snake.length()-2)->m_y);
            //SnakeSpeed=SNAKE_WIDTH*((score/10+1)%9);
        }
    }
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{
    paintTimer->stop();
    Help *help=new Help;
    help->show();
    connect(help,&Help::quit,[=](){
        paintTimer->start();
    });
}
