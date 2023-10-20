#ifndef LOGIN_H
#define LOGIN_H

#include "mainwindow.h"
#include "userwindow.h"
#include <QWidget>
#include <QMouseEvent>
#include <QtSql>
#include <QDataWidgetMapper>
#include <QMessageBox>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT
private:
    bool m_dragging;
    QPoint m_dragPosition;

    QSqlDatabase  DB;   //数据库
    QSqlQueryModel  *qryModel;  //数据模型
    QItemSelectionModel *selModel;  //选择模型

    QString GenerateRandomSalt(int length); // 哈希盐值salt
    QString hashPassword(const QString &password, const QString &salt); // 哈希加密
    bool isPasswordValid(const QString &password); // 密码安全检测

    userwindow *userWindow;
    MainWindow *adminWindow;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_btnMin_clicked();   // 最小化

    void on_btnClose_clicked(); // 关闭

    void on_btnRegister_clicked();  // 注册

    void on_btnLogin_clicked(); // 登录

private:
    Ui::login *ui;
};

#endif // LOGIN_H
