#include "statistics.h"
#include "ui_statistics.h"

Statistics::Statistics(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Statistics)
{
    ui->setupUi(this);
    setWindowTitle("住院人数统计图");
    openDB();
    Init();
}

Statistics::~Statistics()
{
    delete ui;
}

void Statistics::openDB()
{
    DB = QSqlDatabase::addDatabase("QMYSQL", "statistics");
    DB.setHostName("localhost"); // MySQL服务器主机名s
    DB.setDatabaseName("ims"); // 数据库名称
    DB.setUserName("ims"); // MySQL用户名
    DB.setPassword("ims"); // MySQL密码
    if (DB.open()) {
       // qDebug() << "statistics connect";
    } else {
       // qDebug() << "Database connection error: " << DB.lastError().text();
    }
}

void Statistics::Init()
{
    //饼状图
    pie_series = new QPieSeries(this);
    pie_series->setHoleSize(0.1);
    connect(pie_series, SIGNAL(clicked(QPieSlice*)), this, SLOT(onPieSeriesClicked(QPieSlice*)));

    //定义各扇形切片的颜色
    static const QStringList list_pie_color = {
        "#F5A9A9","#FE642E","#F8E6E0","#F4FA58","#B18904","#BEF781",
        "#3ADF00", "#58FAAC", "#00FFFF", "#0489B1", "#0431B4",
        "#9F81F7", "#5F04B4", "#FA58F4", "#8A084B", "#D8D8D8", "#F7819F", "#DF01D7", "#F6CEE3"
    };

    // 总人数
    int sum;

    QSqlQuery query(DB);
    if (query.exec("SELECT COUNT(*) AS totalUsers FROM patientinfo;")) {
        if (query.next()) {
            sum = query.value("totalUsers").toInt();
        }
    } else {
        qDebug() << "获取病人数量失败";
    }

    if (query.exec("SELECT department, COUNT(*) AS totalPatientCount "
                   "FROM patientinfo "
                   "GROUP BY department")) {
        int colorIndex = 0;
        while (query.next()) {
            QString department = query.value("department").toString();
            int totalPatientCount = query.value("totalPatientCount").toInt();

            //扇形
            QPieSlice* pie_slice = new QPieSlice(this);

            QFont labelFont;
            labelFont.setPointSize(10);
            labelFont.setBold(true);
            pie_slice->setLabelFont(labelFont);

            pie_slice->setLabelVisible(true);
            pie_slice->setValue(totalPatientCount);
            pie_slice->setLabel(QString("%1: %2 (%3%)").arg(department,
                                QString::number(totalPatientCount),
                                QString::number(totalPatientCount*100.0/sum, 'f', 2)));
            pie_slice->setColor(list_pie_color[colorIndex]);
            pie_slice->setLabelColor(list_pie_color[colorIndex]);
            pie_slice->setBorderColor(list_pie_color[colorIndex]);
            //pie_slice->setLabelPosition(QPieSlice::LabelInsideHorizontal);

            pie_series->append(pie_slice);
            colorIndex++;
            if (colorIndex == 19)
                colorIndex = 0;
        }

        //图表视图
        QChart* chart = new QChart;
        chart->setTitle("住院科室人数统计饼图");

        //设置主题
        chart->setTheme(QChart::ChartThemeDark);

        //标题字体
        QFont font = qApp->font();
        font.setBold(true);
        font.setPointSize(16);
        chart->setTitleFont(font);

        //加入饼图
        chart->addSeries(pie_series);
        //chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setAnimationOptions(QChart::SeriesAnimations);

        //图例
        chart->legend()->setAlignment(Qt::AlignBottom);
        chart->legend()->setBackgroundVisible(false);

        //加入绘画视图
        QChartView* chartView = new QChartView(this);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setChart(chart);

        //加入布局
        QLayout *existingLayout = ui->centralwidget->layout();
        if (existingLayout) {
            delete existingLayout;
        }

        QVBoxLayout* layout = new QVBoxLayout;
        layout->setContentsMargins(0, 0, 0, 0);
        layout->addWidget(chartView);
        ui->centralwidget->setLayout(layout);
    }
}

void Statistics::onPieSeriesClicked(QPieSlice* slice)
{
    slice->setExploded(!slice->isExploded());
}

// 重写
void Statistics::closeEvent(QCloseEvent *event)
{
    emit closed();

    QMainWindow::closeEvent(event);
}
