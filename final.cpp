#include "final.h"
#include "ui_final.h"

final::final(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::final)
{
    ui->setupUi(this);
}

final::~final()
{
    delete ui;
}

void final::getStore(int score)
{
    if(score<50)
    ui->label->setText(QString("总分:%1 再接再厉！").arg(score));
    else if(score>=50&&score<100)
    ui->label->setText(QString("总分:%1 你很棒！").arg(score));
}

void final::on_pushButton_clicked()
{
    emit restart();
    this->close();
}

void final::on_pushButton_2_clicked()
{
    emit quit();
    this->close();
}
