#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QStatusBar>
#include <QHBoxLayout>
#include <QLabel>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QMouseEvent>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QLabel *recordCountLabel;

    QSqlDatabase DB;
    QSqlQueryModel *qryModel;
    QItemSelectionModel *selModel;

    bool isEditingEnabled; // tableview编辑

    void Init();

    void openTable();   // 连接
    void selectData(); //查询数据
    void showRecordCount(); // 记录数
    void updateRecord(int recNo);

    QString GenerateRandomSalt(int length); // 哈希盐值salt
    QString hashPassword(const QString &password, const QString &salt); // 哈希加密
    bool updatePassword(const QString &logincount, const QString &newPassword); // 密码修改

    void keyPressEvent(QKeyEvent *event) override; // 快捷键搜索

public:
    MainWindow(QWidget *parent = nullptr, const QString &loginCount = nullptr);
    ~MainWindow();

private slots:
    void searchButtonClicked();

    void on_actModify_triggered();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_actAdd_triggered();

    void on_actDelete_triggered();

    void on_actPwd_triggered();

    void on_actSum_triggered();

    void onStatisticsClosed();

    void onChatButtonClicked();


private:
    Ui::MainWindow *ui;
    QString loginCount;
};
#endif // MAINWINDOW_H
