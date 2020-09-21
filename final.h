#ifndef FINAL_H
#define FINAL_H

#include <QWidget>

namespace Ui {
class final;
}

class final : public QWidget
{
    Q_OBJECT

public:
    explicit final(QWidget *parent = 0);
    ~final();

    void getStore(int score);

private:
    Ui::final *ui;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
signals:
    void restart();
    void quit();
};

#endif // FINAL_H
