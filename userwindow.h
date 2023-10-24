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
#include <QMessageBox>

namespace Ui {
class userwindow;
}

class userwindow : public QMainWindow
{
    Q_OBJECT
private:
    QSqlRecord m_record;
    QSqlDatabase DB;
    QSqlQueryModel *qryModel;
    void openTable();   // 连接
    void Init();


public:
    explicit userwindow(QWidget *parent = nullptr, const QString &loginCount = nullptr);
    ~userwindow();
    void setUpdateRecord(QSqlRecord &recData);
    QSqlRecord getRecordData();
    void setFlag(bool flag);

private slots:
    void on_actClear_triggered();

    void on_actPhoto_triggered();

    void on_actSave_triggered();

    void on_actModify_triggered();

    void on_actPwd_triggered();

private:
    Ui::userwindow *ui;
    QString loginCount;

};

#endif // USERWINDOW_H
