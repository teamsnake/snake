#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class myMainWindow;
}

class myMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit myMainWindow(QWidget *parent = 0);
    ~myMainWindow();

private slots:
    void on_btn_help_clicked();

    void on_btn_rank_clicked();

    void on_btn_start_clicked();

private:
    Ui::myMainWindow *ui;
};

#endif // MYMAINWINDOW_H
