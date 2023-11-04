#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QWebEngineSettings>
#include <QWebEngineProfile>
#include <QStackedLayout>
#include <QResizeEvent>
#include <QtSql>


namespace Ui {
class visualization;
}

class visualization : public QMainWindow
{
    Q_OBJECT
private:
    QSqlDatabase DB;
    QWidget *centralWidget;
    QWebEngineView *view;

    void openTable();

public:
    explicit visualization(QWidget *parent = nullptr);
    ~visualization();

    void closeEvent(QCloseEvent *event) override;

signals:
    void closed();

private slots:
    void slotForBar(bool ok);
    void slotForPie(bool ok);


private:
    Ui::visualization *ui;
};

#endif // VISUALIZATION_H
