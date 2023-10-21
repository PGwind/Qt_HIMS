#include "adminwindow.h"
#include "ui_adminwindow.h"

adminWindow::adminWindow(QWidget *parent, const QString &loginCount) :
    QMainWindow(parent),
    ui(new Ui::adminWindow),
    loginCount(loginCount)
{
//    if (loginCount == "admin")  // 超级用户
//        power = true;
//    if (power)
//        qDebug() << "超级用户";
//    else
//        qDebug() << "非超级用户";

    ui->setupUi(this);
    setWindowTitle("高级用户信息管理");

    isEditingEnabled = false;

    /* CSS */
    QFile styleFile(":/css/adminwindow.css");
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

    connect(searchButton, &QPushButton::clicked, this, &adminWindow::searchButtonClicked);


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


}

adminWindow::~adminWindow()
{
    delete ui;
}

void adminWindow::openTable()
{
    /* 1.数据库处理 */
    DB = QSqlDatabase::addDatabase("QMYSQL", "admin");
    DB.setHostName("localhost"); // MySQL服务器主机名
    DB.setDatabaseName("ims"); // 数据库名称
    DB.setUserName("root"); // MySQL用户名
    DB.setPassword("root"); // MySQL密码
    if (DB.open()) {
        // 数据库连接成功
        //qDebug() << "admin connect";
    } else {
        // 数据库连接失败，处理错误
        qDebug() << "Database connection error: " << DB.lastError().text();
    }

    model = new QSqlTableModel(nullptr, DB);
    model->setTable("admin"); // 设置表名
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if (!power)
        model->setFilter("count != 'admin'");   // 过滤
    model->select(); // 从数据库加载数据
    if (!(model->select()))	//查询数据失败
    {
        QMessageBox::critical(this, "错误信息",
                              "打开数据表错误,错误信息:\n"+ model->lastError().text());
        return;
    }

    showRecordCount();


    /* 2.Model/View结构 */
    ui->tableView->setModel(model);
    // 标题样式
    QHeaderView* header = ui->tableView->horizontalHeader();
    header->setStyleSheet("QHeaderView::section { background-color: #3498db; color: white; border: 1px solid #2980b9; }");
    QFont font("Arial", 12, QFont::Bold);
    header->setFont(font);
    header->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);	//项选择
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);	//单项选择
    ui->tableView->setAlternatingRowColors(true);	//交错行底色
    // 标题大小
    int countColumnIndex = model->fieldIndex("count");
    ui->tableView->horizontalHeader()->resizeSection(countColumnIndex, 200);
    int noteColumnIndex = model->fieldIndex("note");
    ui->tableView->horizontalHeader()->resizeSection(noteColumnIndex, 375);
    int logintimeColumnIndex = model->fieldIndex("logintime");
    ui->tableView->horizontalHeader()->resizeSection(logintimeColumnIndex, 250);
    // 选择需要显示的列
    ui->tableView->setColumnHidden(model->fieldIndex("password"), true);
    ui->tableView->setColumnHidden(model->fieldIndex("salt"), true);
    //ui->tableView->setRowHidden(0, true);
    // 标题名称
    model->setHeaderData(model->fieldIndex("count"), Qt::Horizontal, "Count");
    model->setHeaderData(model->fieldIndex("note"), Qt::Horizontal, "Note");
    model->setHeaderData(model->fieldIndex("logintime"), Qt::Horizontal, "Login Time");

    /* 创建选择模型 */
    selModel=new QItemSelectionModel(model,this);
    connect(selModel,&QItemSelectionModel::currentRowChanged,
            this,&adminWindow::do_currentRowChanged);

    /* 3.按钮设置 */
    ui->actSave->setEnabled(false);
    ui->actModify->setEnabled(true);
    ui->actDelete->setEnabled(false);
    ui->actRevert->setEnabled(false);



}

/* 显示记录 */
void adminWindow::showRecordCount()
{
    recordCountLabel->setText(QString("记录条数：%1").arg(model->rowCount()));
}

/* 数据变化 */
void adminWindow::do_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(current);
    Q_UNUSED(previous);
    ui->actSave->setEnabled(model->isDirty());
    ui->actRevert->setEnabled(model->isDirty());
}

/* 行变化 */
void adminWindow::do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);
    ui->actDelete->setEnabled(current.isValid());
    ui->actModify->setEnabled(current.isValid());
    ui->actSave->setEnabled(current.isValid());
}


/* 哈希加密 */
QString adminWindow::GenerateRandomSalt(int length)
{
    const QString characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const int charactersLength = characters.length();
    QString salt;

    for (int i = 0; i < length; ++i) {
        int randomIndex = QRandomGenerator::global()->bounded(charactersLength);
        salt += characters.at(randomIndex);
    }

    return salt;
}

QString adminWindow::hashPassword(const QString &password, const QString &salt)
{
    QByteArray saltByteArray = salt.toUtf8();
    QByteArray passwordBytes = password.toUtf8();
    passwordBytes.append(saltByteArray);

    // 使用SHA-256哈希算法对密码和盐值进行哈希
    QByteArray hashedPassword = QCryptographicHash::hash(passwordBytes, QCryptographicHash::Sha256);
    return QString(hashedPassword.toHex());
}



/***************************************** 菜单栏 ***************************/
/* 添加 */
void adminWindow::on_actAdd_triggered()
{
    // 获取当前系统时间
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString logintimeValue = currentDateTime.toString("yyyy-MM-dd HH:mm:ss");

    // 添加新行
    int row = model->rowCount();
    model->insertRow(row);

    QString countValue = ui->tableView->model()->index(row, model->fieldIndex("count")).data().toString();
    QString noteValue = ui->tableView->model()->index(row, model->fieldIndex("note")).data().toString();
    // 哈希密码和盐值
    QString salt = adminWindow::GenerateRandomSalt(16);
    QString password = "xuyi";
    QString hashedPassword = hashPassword(password, salt);

    QSqlRecord rec = model->record();
    rec.setValue("count", countValue);
    rec.setValue("note", noteValue);
    rec.setValue("logintime", logintimeValue);
    rec.setValue("password", hashedPassword);
    rec.setValue("salt", salt);
    model->setRecord(row, rec);

    selModel->clearSelection();
    QModelIndex curIndex = model->index(model->rowCount()-1,1);     //创建最后一行的ModelIndex
    selModel->setCurrentIndex(curIndex,QItemSelectionModel::Select);

    showRecordCount();

    ui->actSave->setEnabled(false);
    ui->actDelete->setEnabled(false);
    ui->actModify->setEnabled(true);
    ui->actRevert->setEnabled(true);

}

/* 保存 */
void adminWindow::on_actSave_triggered()
{
    int rowCount = model->rowCount();
    QSet<QString> countSet; // 使用集合来存储 "count" 值，以便检查重复
    bool hasDuplicateOrNonAdmin = false;

    for (int row = 0; row < rowCount; row++) {
        QString countValue = model->data(model->index(row, model->fieldIndex("count"))).toString();

        if (countSet.contains(countValue)) {
            hasDuplicateOrNonAdmin = true;
            break;
        }

        countSet.insert(countValue);
    }

    if (hasDuplicateOrNonAdmin) {
        QMessageBox::warning(this, "非法用户名", "用户名已存在或非法.");
    } else {
        bool res = model->submitAll();
        if (!res) {
            QMessageBox::information(this, "保存失败", "保存数据失败:\n" + model->lastError().text());
        } else {
            ui->actSave->setEnabled(false);
            ui->actRevert->setEnabled(false);
        }
    }
    showRecordCount();

    isEditingEnabled = false;
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);

    ui->actModify->setEnabled(true);
    ui->actSave->setEnabled(false);
    ui->actDelete->setEnabled(false);
    ui->actAdd->setEnabled(true);
    ui->actRevert->setEnabled(false);
}


/* 删除 */
void adminWindow::on_actDelete_triggered()
{
    int row = ui->tableView->currentIndex().row();//记录当前选择行
    if(QMessageBox::Yes == QMessageBox::question(this,"警告","确定删除第"+QString::number(row)+"行吗？",QMessageBox::Yes | QMessageBox::No , QMessageBox::Yes))
    {
        if(model->select())//判断是否为空表
            model->removeRow(row);//删除当前行
        model->submitAll();//提交修改的数据
        ui->tableView->setModel(model);//设置模型
        model->select();//显示修改后的数据
    }
}

/* 撤回 */
void adminWindow::on_actRevert_triggered()
{
    model->revertAll(); // 取消修改
    ui->actSave->setEnabled(false);
    ui->actRevert->setEnabled(false);
    showRecordCount();

    // 刷新视图以显示原始信息
    ui->tableView->viewport()->update();

    isEditingEnabled = false;
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);

    ui->actModify->setEnabled(true);
    ui->actAdd->setEnabled(true);
    ui->actDelete->setEnabled(false);
}


/* 修改 */
void adminWindow::on_actModify_triggered()
{
    isEditingEnabled = true;
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);

    ui->actAdd->setEnabled(false);
    ui->actModify->setEnabled(false);
    ui->actSave->setEnabled(true);
    ui->actRevert->setEnabled(true);
    ui->actDelete->setEnabled(true);
}

/* TableView修改属性 */
void adminWindow::on_tableView_pressed(const QModelIndex &index)
{
    Q_UNUSED(index);
    if (!isEditingEnabled) {
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}


/********************************** 修改密码 **********************************/
// 提取对应行count
void adminWindow::on_tableView_doubleClicked(const QModelIndex &index)  // 获取当前行count
{
    int countColumnIndex = model->fieldIndex("count");
    if (countColumnIndex >= 0) {
        QModelIndex countIndex = index.sibling(index.row(), countColumnIndex);
        QString countValue = countIndex.data().toString();
        loginCount = countValue;
    }
}

// 修改密码按钮
void adminWindow::on_actPwd_triggered()
{
    bool ok;
    QString newPassword = QInputDialog::getText(this, "修改密码","请输入 " + loginCount + " 的新密码:", QLineEdit::Normal, "请确保密码安全性！！！", &ok);
    if (ok) {
        if (updatePassword(loginCount, newPassword)) {
            QMessageBox::information(this, "成功", "密码已成功修改");
        } else {
            qDebug() << loginCount;
            QMessageBox::warning(this, "错误", "密码修改失败");
        }
    }
}

// 更新密码
bool adminWindow::updatePassword(const QString &logincount, const QString &newPassword)
{
    int row = -1;

    for (int i = 0; i < model->rowCount(); ++i) {
        QModelIndex index = model->index(i, model->fieldIndex("count"));
        if (model->data(index).toString() == logincount) {
            row = i;
            qDebug() << QString("行数 %1").arg(i);
            break;
        }
    }

    QString salt = adminWindow::GenerateRandomSalt(16);
    QString hashedPassword = hashPassword(newPassword, salt);

    if (row != -1) {
        QModelIndex passwordIndex = model->index(row, model->fieldIndex("password"));
        model->setData(passwordIndex, hashedPassword);

        // 更新 salt
        QModelIndex saltIndex = model->index(row, model->fieldIndex("salt"));
        model->setData(saltIndex, salt);

        if (model->submitAll())
        {
            //qDebug() << "submit success";
            return true;
        } else {
           // qDebug() << "submit error";
            return false;
        }

    } else {
        //qDebug() << "serach error";
        return false;
    }
}

/********************** 搜索 *************************/
void adminWindow::searchButtonClicked()
{
    QString searchText = searchLineEdit->text();

    if (searchText.isEmpty() && power)
    {
        model->setFilter("");
    } else if (searchText.isEmpty() && !power) {
        model->setFilter("count != 'admin'");
    } else if (power) {
        model->setFilter("count LIKE '%" + searchText + "%' ");
    } else {
        model->setFilter("count LIKE '%" + searchText + "%' AND count NOT LIKE 'admin' ");
    }

    model->select();
    ui->tableView->setModel(model);
    showRecordCount();
}


/* Enter快捷键搜索 */
void adminWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        searchButtonClicked();
    }
}
