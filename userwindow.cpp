#include "userwindow.h"
#include "ui_userwindow.h"

userwindow::userwindow(QWidget *parent, const QString &loginCount) :
    QMainWindow(parent),
    ui(new Ui::userwindow),
    loginCount(loginCount)
{
    ui->setupUi(this);
    setWindowTitle("医院信息管理系统");

    /* 加载CSS */
    QFile styleFile(":/css/userwindow.css");
    styleFile.open(QFile::ReadOnly);
    QString style = QLatin1String(styleFile.readAll());
    qApp->setStyleSheet(style);

    /* 搜索栏
    QLineEdit *searchLineEdit = new QLineEdit;
    searchLineEdit->setPlaceholderText("搜索...");
    searchLineEdit->setMaximumWidth(200);

    // 搜索按钮
    QPushButton *searchButton = new QPushButton();
    searchButton->setIcon(QIcon(":/icons/images/icons/search.png")); // 设置按钮的图标

    ui->toolBarUser->addWidget(searchLineEdit);
    ui->toolBarUser->addWidget(searchButton);
    */


    // 编号
    QLabel *count_name = new QLabel("用户名", this);
    QLabel *count = new QLabel();

    count_name->setFixedSize(60, 35);
    count_name->setStyleSheet("font-weight: bold; font-size: 14px; color: black; background-color: #FFFFFF; padding: 5px; border-radius: 5px;");
    count->setFixedSize(150, 35);
    count->setStyleSheet("font-weight: bold; font-size: 14px; color: black; background-color: #FFFFFF; padding: 5px; border-radius: 5px;");

    QSpacerItem *spacer = new QSpacerItem(5, 0);
    QSpacerItem *spacer_big = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    // 创建水平布局管理器，用于放置搜索栏、间隙和搜索按钮
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addItem(spacer_big);
    layout->addWidget(count_name);
    layout->addItem(spacer);
    layout->addWidget(count);


    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    ui->toolBarUser->addWidget(widget);

    qDebug() << loginCount;
}

userwindow::~userwindow()
{
    delete ui;
}
