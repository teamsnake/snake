#include "helpform.h"
#include "ui_helpform.h"

HelpForm::HelpForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelpForm)
{
    ui->setupUi(this);
    setWindowTitle("帮助文档");
}

HelpForm::~HelpForm()
{
    delete ui;
}
