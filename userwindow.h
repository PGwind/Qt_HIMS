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
#include <QInputDialog>

namespace Ui {
class userwindow;
}

class userwindow : public QMainWindow
{
    Q_OBJECT

private:
    QSqlRecord m_record;
    QSqlDatabase DB;

    void openTable();
    void Init();

    void setUpdateRecord(QSqlRecord &recData);  // 更新信息页
    QSqlRecord getRecordData(); // 读取数据

    void setFlag(bool flag);    // 控件禁用

    QString GenerateRandomSalt(int length); // 哈希盐值salt
    QString hashPassword(const QString &password, const QString &salt); // 哈希加密

public:
    explicit userwindow(QWidget *parent = nullptr, const QString &loginCount = nullptr);
    ~userwindow(); 

private slots:
    void on_actClear_triggered();

    void on_actPhoto_triggered();

    void on_actSave_triggered();

    void on_actModify_triggered();

    void on_actPwd_triggered();

    void onChatButtonClicked();

private:
    Ui::userwindow *ui;
    QString loginCount;

};

#endif // USERWINDOW_H
