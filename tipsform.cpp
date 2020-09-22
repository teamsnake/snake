#include "tipsform.h"
#include "ui_tipsform.h"
#include "data.h"
#include <QIcon>

TipsForm::TipsForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TipsForm)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(APP_ICON));
    setWindowTitle("得分面板");
    ui->label_3->hide();
    ui->label_4->hide();
}

TipsForm::~TipsForm()
{
    delete ui;
}
void TipsForm::getStore(int score)
{
    ui->label_2->setText(QString::number(score,10));
    if(score<100)
        ui->label_3->show();
    if(score>=100)
        ui->label_4->show();
}
void TipsForm::on_btn_restart_clicked()
{
    emit restart();
    this->close();
}

void TipsForm::on_btn_close_clicked()
{
    emit quit();
    this->close();
}
