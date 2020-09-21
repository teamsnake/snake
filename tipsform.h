#ifndef TIPSFORM_H
#define TIPSFORM_H

#include <QMainWindow>

namespace Ui {
class TipsForm;
}

class TipsForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit TipsForm(QWidget *parent = 0);
    ~TipsForm();

    void getStore(int score);
private:
    Ui::TipsForm *ui;
signals:
    void restart();
    void quit();
private slots:
    void on_btn_restart_clicked();
    void on_btn_close_clicked();
};

#endif // TIPSFORM_H
