#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    setWindowTitle("帮助文档");
}

Help::~Help()
{
    delete ui;
}

void Help::closeEvent(QCloseEvent *event)
{
    emit quit();
    event->accept();
}
