#include "adminwindow.h"
#include "ui_adminwindow.h"

adminWindow::adminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminWindow)
{
    ui->setupUi(this);
    setWindowTitle("高级账户管理");

    /* CSS */
    QFile styleFile(":/css/adminwindow.css");
    styleFile.open(QFile::ReadOnly);
    QString style = QLatin1String(styleFile.readAll());
    qApp->setStyleSheet(style);

    /* 搜索 */
    QLineEdit *searchLineEdit = new QLineEdit;
    searchLineEdit->setPlaceholderText("搜索...");
    searchLineEdit->setMaximumWidth(200);

    QPushButton *searchButton = new QPushButton();
    searchButton->setIcon(QIcon(":/icons/images/icons/search.png")); // 设置按钮的图标

    searchLineEdit->setMinimumSize(100, 30);
    searchLineEdit->setMaximumSize(200, 30);
    searchButton->setFixedSize(40, 30);

    QSpacerItem *spacer = new QSpacerItem(5, 0);
    QSpacerItem *spacer_big = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addItem(spacer_big);
    layout->addWidget(searchLineEdit);
    layout->addItem(spacer);
    layout->addWidget(searchButton);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

//    QPushButton *test = new QPushButton();
//    ui->toolBar->addWidget(test);

    ui->toolBar->addWidget(widget);

    /* 底部状态栏 */
    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
    //statusBar->setFixedSize(200, 30);
    QLabel *recordCountLabel = new QLabel("记录数: 0", this);
    statusBar->addWidget(recordCountLabel);
    recordCountLabel->setStyleSheet("QLabel { background-color: #3498db;"
                                    " color: white; border: 1px solid #2980b9; "
                                    "border-radius: 5px; padding: 2px; font-weight: bold; font-size: 16px;}");

    /* tableView 大小伸展*/
    QVBoxLayout *table_layout = new QVBoxLayout;
    table_layout->addWidget(ui->tableView);
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(table_layout);
    setCentralWidget(centralWidget);
    ui->tableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);



}

adminWindow::~adminWindow()
{
    delete ui;
}
