#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QFile>
#include <QtSql>
#include <QFileDialog>

namespace Ui {
class userwindow;
}

class userwindow : public QMainWindow
{
    Q_OBJECT
private:
    QSqlRecord m_record;

public:
    bool isSave = false;
    explicit userwindow(QWidget *parent = nullptr, const QString &loginCount = nullptr);
    ~userwindow();
    void updateRecord(QSqlRecord &recData); //更新记录
    void addRecord(QSqlRecord &recData); //插入记录
    QSqlRecord getRecordData(); //获取界面中输入的数据

private slots:
    void on_actClear_triggered();

    void on_actPhoto_triggered();

    void on_actSave_triggered();

    void on_actCancel_triggered();

private:
    Ui::userwindow *ui;
    QString loginCount;

};

#endif // USERWINDOW_H
