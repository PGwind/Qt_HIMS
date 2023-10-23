#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSqlRecord>
#include <QFile>
#include <QFileDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
private:
    QSqlRecord  m_record;

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void    setUpdateRecord(QSqlRecord &recData);   //更新记录
    void    setInsertRecord(QSqlRecord &recData);   //插入记录
    QSqlRecord  getRecordData();     //获取界面输入的数据

private slots:
    void on_pushButton_setPhoto_clicked();

    void on_pushButton_clear_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
