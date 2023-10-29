#ifndef STATISTICS_H
#define STATISTICS_H

#include <QMainWindow>
#include <QtCharts>
#include <QtSql>

namespace Ui {
class Statistics;
}

class Statistics : public QMainWindow
{
    Q_OBJECT
private:
    QSqlDatabase DB;
    QPieSeries *pie_series;

    void openDB();
    void Init();

public:
    explicit Statistics(QWidget *parent = nullptr);
    ~Statistics();

    void closeEvent(QCloseEvent *event) override;

signals:
    void closed();

private slots:
    void onPieSeriesClicked(QPieSlice*);

private:
    Ui::Statistics *ui;
};

#endif // STATISTICS_H
