#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, const QString &loginCount)
    : QMainWindow(parent),
     ui(new Ui::MainWindow),
    loginCount(loginCount)
{
    ui->setupUi(this);
    setWindowTitle("住院病人信息管理");

    /* CSS */
    QFile styleFile(":/css/mainwindow.css");
    styleFile.open(QFile::ReadOnly);
    QString style = QLatin1String(styleFile.readAll());
    qApp->setStyleSheet(style);

    /* 搜索 */
    searchLineEdit = new QLineEdit;
    searchLineEdit->setPlaceholderText("搜索...");
    searchLineEdit->setMaximumWidth(200);

    searchButton = new QPushButton();
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

    ui->toolBar->addWidget(widget);

   // connect(searchButton, &QPushButton::clicked, this, &adminWindow::searchButtonClicked);

  /* 底部状态栏 */
    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
    //statusBar->setFixedSize(200, 30);
    recordCountLabel = new QLabel("记录数: 0", this);
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

    // 数据库连接与映射
    openTable();
    selectData();
    showRecordCount();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openTable()
{
    /* 1.数据库处理 */
    DB = QSqlDatabase::addDatabase("QMYSQL", "manage");
    DB.setHostName("localhost"); // MySQL服务器主机名
    DB.setDatabaseName("ims"); // 数据库名称
    DB.setUserName("root"); // MySQL用户名
    DB.setPassword("root"); // MySQL密码
    if (DB.open()) {
        // 数据库连接成功
        qDebug() << "DB_patients connect";
    } else {
        // 数据库连接失败，处理错误
        qDebug() << "Database connection error: " << DB.lastError().text();
    }


}

void MainWindow::selectData()
{
    qryModel= new QSqlQueryModel(this);
    selModel= new QItemSelectionModel(qryModel,this);
    ui->tableView->setModel(qryModel);
    ui->tableView->setSelectionModel(selModel);
    qryModel->setQuery("SELECT id, name, gender, idNumber, address FROM personinfo");
    if (qryModel->lastError().isValid())
    {
        QMessageBox::information(this, "错误", "数据表查询错误,错误信息\n" + qryModel->lastError().text());
        return;
    }


    // 标题样式
    QHeaderView* header = ui->tableView->horizontalHeader();
    header->setStyleSheet("QHeaderView::section { background-color: #3498db; color: white; border: 1px solid #2980b9; }");
    QFont font("Arial", 12, QFont::Bold);
    header->setFont(font);
    header->setDefaultAlignment(Qt::AlignCenter);


    // 选择模式
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);	//项选择
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);	//单项选择
    ui->tableView->setAlternatingRowColors(true);	//交错行底色
    // 调整列宽
    int idColumnIndex = qryModel->record().indexOf("id");
    if (idColumnIndex != -1) {
        ui->tableView->horizontalHeader()->resizeSection(idColumnIndex, 150);
    }
    int nameColumnIndex = qryModel->record().indexOf("name");
    if (nameColumnIndex != -1) {
        ui->tableView->horizontalHeader()->resizeSection(nameColumnIndex, 200);
    }
    int genderColumnIndex = qryModel->record().indexOf("gender");
    if (genderColumnIndex != -1) {
        ui->tableView->horizontalHeader()->resizeSection(genderColumnIndex, 100);
    }
    int idNumberColumnIndex = qryModel->record().indexOf("idNumber");
    if (idNumberColumnIndex != -1) {
        ui->tableView->horizontalHeader()->resizeSection(idNumberColumnIndex, 300);
    }
    int addressColumnIndex = qryModel->record().indexOf("address");
    if (addressColumnIndex != -1) {
        ui->tableView->horizontalHeader()->resizeSection(addressColumnIndex, 500);
    }

    QSqlRecord rec= qryModel->record(); //获取空记录，用于获取字段序号
    qryModel->setHeaderData(rec.indexOf("id"), Qt::Horizontal, "编号");
    qryModel->setHeaderData(rec.indexOf("name"), Qt::Horizontal, "姓名");
    qryModel->setHeaderData(rec.indexOf("gender"), Qt::Horizontal, "性别");
    qryModel->setHeaderData(rec.indexOf("idNumber"), Qt::Horizontal, "身份证号");
    qryModel->setHeaderData(rec.indexOf("address"), Qt::Horizontal, "地址");

    ui->actAdd->setEnabled(true);
    ui->actDelete->setEnabled(true);
    ui->actModify->setEnabled(true);
    ui->actPwd->setEnabled(true);
    ui->actRevert->setEnabled(false);
    ui->actSave->setEnabled(false);
}


/* 显示记录 */
void MainWindow::showRecordCount()
{
    int recordCount = qryModel->rowCount(); // 使用 qryModel 获取记录数
    recordCountLabel->setText(QString("记录条数：%1").arg(recordCount));
}

// 修改
void MainWindow::on_actModify_triggered()
{
    int curRecNo= selModel->currentIndex().row();
    updateRecord(curRecNo);
}


// 双击
void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    int curRecNo=index.row();
    updateRecord(curRecNo);
}

// 修改调用
void MainWindow::updateRecord(int recNo)
{
    QSqlRecord curRec= qryModel->record(recNo);
    QString id = curRec.value("id").toString();
    QSqlQuery query(DB);
    query.prepare("SELECT * FROM personinfo WHERE id = :ID");
    query.bindValue(":ID",id);
    query.exec();
    query.first();

    if (!query.isValid()) { //无有效记录
        qDebug() << "查询失败";
        return;
    }

    curRec = query.record();
    userwindow *user = new userwindow(this, id);
    //Qt::WindowFlags flags= user->windowFlags();
    //user->setWindowFlags(flags | Qt:: MSWindowsFixedSizeDialogHint);
  //  user->updateRecord(curRec);
    user->show();

    bool ret = user->isSave;
    if (ret) {
        QSqlRecord recData= user->getRecordData(); //获取对话框返回的记录
        query.prepare("UPDATE personinfo SET name=:name, age=:age,"
                      " gender=:gender, photo=:photo,"
                      " idNumber=:idNumber, address=:address");

        query.bindValue(":name", recData.value("Name"));
        query.bindValue("age", recData.value("Gender"));
        query.bindValue(":gender",recData.value("Birthday"));
        query.bindValue(":photo",recData.value("Province"));
        query.bindValue(":idNumber", recData.value("Department"));
        query.bindValue(":address", recData.value("Salary"));
        query.bindValue(":Memo", recData.value("Memo"));
        query.bindValue(":Photo", recData.value("Photo"));

        if (!query.exec())
            QMessageBox::critical(this, "错误", "记录更新错误\n"+query.lastError().text());
        else
            qryModel->query().exec(); //数据模型重新查询数据，更新 tableView 显示内容

         delete user;
    }

}

// 添加
void MainWindow::on_actAdd_triggered()
{
    QSqlQuery query(DB);
    query.exec("SELECT * FROM personinfo WHERE id = -1"); //查不出实际记录，只查询出字段信息
    QSqlRecord curRec= query.record(); //获取当前记录，实际为空记

    userwindow *user = new userwindow(this);
    Qt::WindowFlags flags= user->windowFlags();
    user->setWindowFlags(flags | Qt:: MSWindowsFixedSizeDialogHint);
    user->addRecord(curRec);
    user->show();

    bool ret = user->isSave;
    if (ret) {
        QSqlRecord recData= user->getRecordData(); //获取对话框返回的记录
        query.prepare("INSERT INTO personinfo (name,age,gender,photo,idNumber,"
                      " address) "
                      " VALUES(:name, :age, :gender, :photot, :idNumber,"
                      " :address)");

        query.bindValue(":name", recData.value("name"));
        query.bindValue("age", recData.value("age"));
        query.bindValue(":gender",recData.value("gender"));
        query.bindValue(":photo",recData.value("photo"));
        query.bindValue(":idNumber", recData.value("idNumber"));
        query.bindValue(":address", recData.value("address"));

        if (!query.exec())
            QMessageBox::critical(this, "错误", "记录更新错误\n"+query.lastError().text());
        else
            qryModel->query().exec(); //数据模型重新查询数据，更新 tableView 显示内容
    }
    delete user;
}


void MainWindow::on_actDelete_triggered()
{
    int curRecNo= selModel->currentIndex().row();
    QSqlRecord curRec= qryModel->record(curRecNo); //获取当前记录
    if (curRec.isEmpty()) //当前为空记录
        return;
    int id = curRec.value("id").toInt(); //获取工号
    QSqlQuery query(DB);
    query.prepare("DELETE FROM personinfo WHERE id = :ID");
    query.bindValue(":ID",id);
    if (!query.exec())
        QMessageBox::critical(this, "错误",  "删除记录出现错误\n"+query.lastError().text());
    else
        {
            QString sqlStr= qryModel->query().executedQuery(); // 运行过的 SELECT 语句
            qryModel->setQuery(sqlStr); //重新查询数据
        }
}

