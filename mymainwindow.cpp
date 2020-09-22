#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include "helpform.h"
#include "ui_helpform.h"
#include "ganme.h"
#include "ui_ganme.h"
myMainWindow::myMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myMainWindow)
{
    ui->setupUi(this);
    ui->FTopScore->hide();
}

myMainWindow::~myMainWindow()
{
    delete ui;
}

void myMainWindow::on_btn_help_clicked()
{
    HelpForm *help=new HelpForm;
    help->show();

}

void myMainWindow::on_btn_rank_clicked()
{
    if(ui->FTopScore->isVisible()){
        ui->FTopScore->hide();
    }
    else{
        ui->FTopScore->show();
    }
}

void myMainWindow::on_btn_start_clicked()
{
    Ganme *game=new Ganme;
    game->show();

}

