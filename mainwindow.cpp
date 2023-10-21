#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, const QString &loginCount)
    : QMainWindow(parent),
     ui(new Ui::MainWindow),
    loginCount(loginCount)
{
    ui->setupUi(this);
    //qDebug() << loginCount;

}

MainWindow::~MainWindow()
{
    delete ui;
}

