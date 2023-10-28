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
#include <QtSql>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QInputDialog>
#include <QMouseEvent>

namespace Ui {
class adminWindow;
}

class adminWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    bool isEditingEnabled;
    QLabel *recordCountLabel;

    QSqlDatabase DB;
    QSqlTableModel *model;
    QItemSelectionModel *selModel;

    void Init();

    void openTable();   // 连接

    void showRecordCount(); // 记录数

    QString GenerateRandomSalt(int length); // 哈希盐值salt

    QString hashPassword(const QString &password, const QString &salt); // 哈希加密

    bool updatePassword(const QString &logincount, const QString &newPassword); // 密码修改

    void keyPressEvent(QKeyEvent *event) override; // 快捷键搜索

public:
    explicit adminWindow(QWidget *parent = nullptr, const QString &loginCount = nullptr);
    ~adminWindow();

private slots:
    void searchButtonClicked(); // 搜索

    void do_currentChanged(const QModelIndex &current, const QModelIndex &previous);    // 当前项

    void do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous); // 行处理

    void on_actAdd_triggered(); // 增加

    void on_actSave_triggered();   // 保存

    void on_actDelete_triggered();  // 删除

    void on_actRevert_triggered();  // 撤销

    void on_tableView_pressed(const QModelIndex &index);

    void on_actModify_triggered();  // 修改

    void on_actPwd_triggered(); // 密码

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::adminWindow *ui;
    QString loginCount;
    bool power = false; // 最高级用户
};

#endif // ADMINWINDOW_H
