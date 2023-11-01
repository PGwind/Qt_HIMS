#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSqlRecord>
#include <QFile>
#include <QFileDialog>
#include <QtSql>
#include <QInputDialog>
#include <QRandomGenerator>
#include <QMessageBox>

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

    void Init();

    void setUpdateRecord(QSqlRecord &recData);   //更新记
    void setInsertRecord(QSqlRecord &recData);   //插入记录

    QSqlRecord  getRecordData();     //获取界面输入的数据

    QString GenerateRandomSalt(int length); // 哈希盐值salt
    QString hashPassword(const QString &password, const QString &salt); // 哈希加密

private slots:
    void on_pushButton_setPhoto_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_lock_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
