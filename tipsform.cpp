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
}

TipsForm::~TipsForm()
{
    delete ui;
}
void TipsForm::getStore(int score)
{

    ui->label->setText(QString::number(score,10));
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
