#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QFile>
#include <QLabel>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QItemSelectionModel>

namespace Ui {
class adminWindow;
}

class adminWindow : public QMainWindow
{
    Q_OBJECT
private:
    QSqlDatabase DB; //数据库连接
    QSqlQueryModel *qryModel; //数据模型
    QItemSelectionModel *selModel; //选择模型
    void selectData(); //查询数据
    void updateRecord(int recNo); //更新一条记录
public:
    explicit adminWindow(QWidget *parent = nullptr);
    ~adminWindow();

private:
    Ui::adminWindow *ui;
};

#endif // ADMINWINDOW_H
