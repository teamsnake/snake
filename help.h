#ifndef HELP_H
#define HELP_H

#include <QWidget>
#include<QCloseEvent>
namespace Ui {
class Help;
}

class Help : public QWidget
{
    Q_OBJECT

public:
    explicit Help(QWidget *parent = nullptr);
    ~Help();
    void closeEvent(QCloseEvent *event);
private:
    Ui::Help *ui;
signals:
    void quit();
};

#endif // HELP_H
