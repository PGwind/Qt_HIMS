#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QFile>

namespace Ui {
class userwindow;
}

class userwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit userwindow(QWidget *parent = nullptr, const QString &loginCount = nullptr);
    ~userwindow();

private:
    Ui::userwindow *ui;
    QString loginCount;

};

#endif // USERWINDOW_H
