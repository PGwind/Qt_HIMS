#include "visualization.h"
#include "ui_visualization.h"

/**************************************************************

Title：statistics.c
Function: 信息管理二级界面, 数据可视化显示
Change_Time: 2023/11/4

**************************************************************/


visualization::visualization(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::visualization)
{
    ui->setupUi(this);

    this->showMaximized();

    // 创建一个布局管理器
    QVBoxLayout *layout = new QVBoxLayout;


    //webChannel = new QWebChannel;
    //webChannel->registerObject(QString("webtransport"), this);

    view = new QWebEngineView(this);
    //view->page()->setWebChannel(webChannel);
    QString filePath = qApp->applicationDirPath() + "/resources/index.html";
    view->load(QUrl::fromLocalFile(filePath));
    // 将QWebEngineView添加到布局中
    layout->addWidget(view);

    // 将布局设置为主窗口的中央部分
    centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    openTable();
    //queryBarChartData();
    //queryPieChartData();

    connect(view->page(), SIGNAL(loadFinished(bool)), this, SLOT(slotForBar(bool)));
    connect(view->page(), SIGNAL(loadFinished(bool)), this, SLOT(slotForPie(bool)));
}

visualization::~visualization()
{
    delete ui;
    delete view;
}


/* 数据库连接 */
void visualization::openTable()
{
    // 数据库处理
    DB = QSqlDatabase::addDatabase("QMYSQL", "visualization");
    DB.setHostName("121.37.155.243");
    DB.setDatabaseName("hims");
    DB.setUserName("hims");
    DB.setPassword("hims2002");
    if (DB.open()) {
        qDebug() << "Database connection successful.";
    } else {
        qDebug() << "Database connection error: " << DB.lastError().text();
    }


}


/* 柱状图 */
void visualization::slotForBar(bool ok)
{
    if (ok)
    {
        QSqlQuery query(DB);
        query.prepare("SELECT department, COUNT(*) AS totalPatientCount FROM patientinfo GROUP BY department ORDER BY department;");

        if (query.exec()) {
            // 创建一个 JSON 数组来存储查询结果
            QJsonArray departmentDataArray;

            while (query.next()) {
                QJsonObject departmentData;
                departmentData["department"] = query.value("department").toString();
                departmentData["totalPatientCount"] = query.value("totalPatientCount").toInt();
                departmentDataArray.append(departmentData);
            }

            QJsonObject result;
            result["pieChartData"] = departmentDataArray;
            QString jsonData = QJsonDocument(result).toJson();  // JSON 对象转换为 JSON 字符串

            //qDebug()  << "jsondata\n" << jsonData;

            view->page()->runJavaScript("setBarChartData(" + jsonData + ");");
        } else {
            qDebug() << "SQL query error: " << query.lastError().text();
        }
    }
}


/* 扇形图 */
void visualization::slotForPie(bool ok)
{
    if (ok) {
        QSqlQuery query(DB);
        query.prepare("SELECT department, COUNT(*) AS totalPatientCount FROM patientinfo GROUP BY department ORDER BY department;");

        if (query.exec()) {
            // 创建一个 JSON 数组来存储查询结果
            QJsonArray departmentDataArray;

            while (query.next()) {
                QJsonObject departmentData;
                departmentData["department"] = query.value("department").toString();
                departmentData["totalPatientCount"] = query.value("totalPatientCount").toInt();
                departmentDataArray.append(departmentData);
            }


            QJsonObject result;
            result["pieChartData"] = departmentDataArray;
            QString jsonData = QJsonDocument(result).toJson();  // JSON 对象转换为 JSON 字符串

            //qDebug()  << "jsondata\n" << jsonData;

            view->page()->runJavaScript("setPieChartData(" + jsonData + ");");
        } else {
            qDebug() << "SQL query error: " << query.lastError().text();
        }
    }
}

/* 重写关闭事件 */
void visualization::closeEvent(QCloseEvent *event)
{
    emit closed();

    QMainWindow::closeEvent(event);
}

