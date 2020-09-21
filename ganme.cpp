#include "ganme.h"
#include "ui_ganme.h"
#include<QDebug>
#include<QPainter>
#include<QTime>
Ganme::Ganme(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ganme)
{
    ui->setupUi(this);
    score=0;
    SnakeNode=1;
    SnakeSpeed=SNAKE_WIDTH;
    food=nullptr;
    CreateSnakeHead();
    paintTimer=new QTimer;
    paintTimer->setInterval(300);
    StartGame();
}

Ganme::~Ganme()
{
    delete ui;
}

void Ganme::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
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
}

void Ganme::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_D)
    {
        if(currentToward!=Sleft)
        currentToward=orientation::Sright;
    }
    else if(event->key()==Qt::Key_A)
    {
        if(currentToward!=Sright)
        currentToward=orientation::Sleft;
    }
    else if(event->key()==Qt::Key_W)
    {
        if(currentToward!=Sdown)
        currentToward=orientation::Sup;
    }
    else if(event->key()==Qt::Key_S)
    {
        if(currentToward!=Sup)
        currentToward=orientation::Sdown;
    }
    else if(event->key()==Qt::Key_Escape)
    {
        paintTimer->stop();
    }
    else if(event->key()==Qt::Key_Enter)
    {
        paintTimer->start();
    }
}

void Ganme::DisPlayScore(QPainter &painter)
{
    painter.setPen(QPen(Qt::white,10,Qt::SolidLine));
    painter.drawText(GAME_WIDTH-150,60,QString("score:%1").arg(score));
}

void Ganme::CreateSnakeHead()
{
        Snake *s=new Snake(QColor(255,255,255));
        snake.push_back(s);
        snake.at(0)->setPosition(SNAKE_INIT_X,SNAKE_INIT_Y);
}

void Ganme::CreateFood()
{
    food=new Food(true);
    food->food_image=FoodPicture;
    qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
    food->food_index=rand()%4+1;
    food->food_image=food->food_image.arg(food->food_index);
    qDebug() << food->food_image;
    food->food_x=rand()%((GAME_WIDTH-WALL_WIDTH)-WALL_WIDTH)+WALL_WIDTH;
    food->food_y=rand()%((GAME_HEIGHT-WALL_WIDTH)-WALL_WIDTH)+WALL_WIDTH;


}

void Ganme::StartGame()
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

void Ganme::BoundaryTest(int s_x, int s_y)
{
    setWindowTitle(QString("BT贪吃蛇\t\t当前坐标:x:%1 y:%2\t").arg(s_x).arg(s_y));
    //撞自己 die
    int flag=0;
    for(int i=1;i<snake.length();i++){
        if(snake[i]->m_x==s_x&&snake[i]->m_y==s_y) flag=1;
    }
    if(s_x>GAME_WIDTH-WALL_WIDTH || s_x<WALL_WIDTH-snake[0]->m_x || s_y>GAME_HEIGHT-WALL_WIDTH || s_y<WALL_WIDTH-snake[0]->m_y||flag==1)
    {
        paintTimer->stop();
        TipsForm *tips=new TipsForm;
        tips->getStore(score);
        tips->show();

        connect(tips,&TipsForm::restart,[=](){
            score=0;
            SnakeNode=3;
            SnakeSpeed=SNAKE_WIDTH;
            for(int i=snake.length()-1;i>0;i--)
            {
                snake.pop_back();
            }
            snake.at(0)->setPosition(SNAKE_INIT_X,SNAKE_INIT_Y);
            food=nullptr;
            currentToward=Sright;
            paintTimer->start();
        });
        connect(tips,&TipsForm::quit,[=](){
            this->close();
        });
    }
    if(food!=nullptr)
    {
        if(abs(s_x-food->food_x)<(SNAKE_WIDTH)&&abs(s_y-food->food_y)<(SNAKE_HEIGHT))
        {
            food->food_isExist=false;
            score+=food->food_index;
            Snake *s=new Snake(QColor(255,255,255));
            snake.push_back(s);
            snake.last()->setPosition(snake.at(snake.length()-2)->m_x,snake.at(snake.length()-2)->m_y);
        }
    }
}
