#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>

namespace Ui {
class userwindow;
}

class userwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit userwindow(QWidget *parent = nullptr);
    ~userwindow();

private:
    Ui::userwindow *ui;
};

#endif // USERWINDOW_H
