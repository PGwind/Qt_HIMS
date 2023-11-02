#include "mainwindow.h"
#include "ui_mainwindow.h"

/**************************************************************

Title：mainwindow.c
Function: 信息管理员界面，负责病人信息的增删改查
Time: 2023/10/31

**************************************************************/


MainWindow::MainWindow(QWidget *parent, const QString &loginCount)
    : QMainWindow(parent),
     ui(new Ui::MainWindow),
    loginCount(loginCount)
{
    ui->setupUi(this);
    setWindowTitle("住院病人信息管理");
    this->setWindowIcon(QIcon(":/icons/images/icons/main.ico"));

    Init();
    openTable();
    selectData();

    // 更新登录时间
    QSqlQuery query(DB);
    query.prepare("UPDATE admin SET logintime = :currentDateTime WHERE count = :loginCount");
    query.bindValue(":currentDateTime", QDateTime::currentDateTime());
    query.bindValue(":loginCount", loginCount);

    if (query.exec()) {
        //qDebug() << "logintime updated successfully.";
    } else {
        //qDebug() << "Failed to update logintime:" << query.lastError().text();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


/* 初始化 */
void MainWindow::Init()
{
    // CSS
    QFile styleFile(":/css/mainwindow.css");
    styleFile.open(QFile::ReadOnly);
    QString style = QLatin1String(styleFile.readAll());
    qApp->setStyleSheet(style);

    // 搜索
    searchLineEdit = new QLineEdit;
    searchLineEdit->setPlaceholderText("搜索...");
    searchLineEdit->setMaximumWidth(200);

    searchButton = new QPushButton;
    searchButton->setIcon(QIcon(":/icons/images/icons/search.png"));

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

    connect(searchButton, &QPushButton::clicked, this, &MainWindow::searchButtonClicked);

    // 底部状态栏
    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
    //statusBar->setFixedSize(200, 30);
    recordCountLabel = new QLabel("记录数: 0", this);
    statusBar->addWidget(recordCountLabel);
    recordCountLabel->setStyleSheet("QLabel { background-color: #3498db;"
                                    " color: white; border: 1px solid #2980b9; "
                                    "border-radius: 5px; padding: 2px; font-weight: bold; font-size: 16px;}");

    // tableView 大小伸展
    QVBoxLayout *table_layout = new QVBoxLayout;
    table_layout->addWidget(ui->tableView);
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(table_layout);
    setCentralWidget(centralWidget);
    ui->tableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}


/* 数据库连接 */
void MainWindow::openTable()
{
    // 数据库处理
    DB = QSqlDatabase::addDatabase("QMYSQL");
    DB.setHostName("121.37.155.243");
    DB.setDatabaseName("hims");
    DB.setUserName("hims");
    DB.setPassword("hims2002");
    if (DB.open()) {
        // qDebug() << "ManagePatients connect";
    } else {
        // qDebug() << "Database connection error: " << DB.lastError().text();
    }
}



/* 数据模式选择映射 */
void MainWindow::selectData()
{
    qryModel= new QSqlQueryModel(this);
    selModel= new QItemSelectionModel(qryModel,this);
    ui->tableView->setModel(qryModel);
    ui->tableView->setSelectionModel(selModel);
    qryModel->setQuery("SELECT id, name, gender, idNumber, contact, address FROM personinfo");
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
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setAlternatingRowColors(true);

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

    QSqlRecord rec= qryModel->record();
    qryModel->setHeaderData(rec.indexOf("id"), Qt::Horizontal, "编号");
    qryModel->setHeaderData(rec.indexOf("name"), Qt::Horizontal, "姓名");
    qryModel->setHeaderData(rec.indexOf("gender"), Qt::Horizontal, "性别");
    qryModel->setHeaderData(rec.indexOf("idNumber"), Qt::Horizontal, "身份证号");
    qryModel->setHeaderData(rec.indexOf("contact"), Qt::Horizontal, "联系方式");
    qryModel->setHeaderData(rec.indexOf("address"), Qt::Horizontal, "地址");

    showRecordCount();

    ui->actAdd->setEnabled(true);
    ui->actDelete->setEnabled(true);
    ui->actModify->setEnabled(true);
    ui->actPwd->setEnabled(true);
    ui->actRevert->setEnabled(false);
    ui->actSave->setEnabled(false);
}



/************************************ 按钮 **********************************/
// 修改按钮
void MainWindow::on_actModify_triggered()
{
    int curRecNo= selModel->currentIndex().row();
    updateRecord(curRecNo);
}


// 双击修改
void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    int curRecNo=index.row();
    updateRecord(curRecNo);
}


// 更新记录
void MainWindow::updateRecord(int recNo)
{
    QSqlRecord curRec= qryModel->record(recNo);
    int id = curRec.value("id").toInt();
    QSqlQuery query(DB);
   // query.prepare("SELECT * FROM personinfo WHERE id = :ID");
    query.prepare("SELECT personinfo.*, patientinfo.* "
                  "FROM personinfo "
                  "INNER JOIN patientinfo ON personinfo.id = patientinfo.id "
                  "WHERE personinfo.id = :ID");
    query.bindValue(":ID", id);
    query.exec();
    query.first();

    if (!query.isValid()) { //无有效记录
        qDebug() << "查询失败";
        return;
    }

    curRec = query.record();

    Dialog *dataDialog = new Dialog(this);
    Qt::WindowFlags flags= dataDialog->windowFlags();
    dataDialog->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);
    dataDialog->setUpdateRecord(curRec);

    int ret= dataDialog->exec();
    if (ret == QDialog::Accepted) {
        QSqlRecord recData = dataDialog->getRecordData();

        query.prepare("UPDATE personinfo SET name=:name, age=:age,"
                      " gender=:gender, photo=:photo,"
                      " idNumber=:idNumber, contact=:contact, address=:address"
                      " WHERE id = :ID");

        query.bindValue(":name", recData.value("name"));
        query.bindValue(":age", recData.value("age").toInt());
        query.bindValue(":gender",recData.value("gender"));
        query.bindValue(":photo",recData.value("photo"));
        query.bindValue(":idNumber", recData.value("idNumber"));
        query.bindValue(":contact", recData.value("contact"));
        query.bindValue(":address", recData.value("address"));
        query.bindValue(":ID", id);

        if (!query.exec()) {
            QMessageBox::critical(this, "错误", "personinfo 表记录更新错误\n" + query.lastError().text());
            return;
        }

        // 更新 patientinfo 表
        query.prepare("UPDATE patientinfo SET buildingNumber=:buildingNumber, roomNumber=:roomNumber, "
                      "bedNumber=:bedNumber, department=:department, "
                      "attendingPhysician=:attendingPhysician, admissionDate=:admissionDate, "
                      "dischargeDate=:dischargeDate, notes=:notes "
                      "WHERE id = :ID");
        query.bindValue(":buildingNumber", recData.value("buildingNumber"));
        query.bindValue(":roomNumber", recData.value("roomNumber"));
        query.bindValue(":bedNumber", recData.value("bedNumber"));
        query.bindValue(":department", recData.value("department"));
        query.bindValue(":attendingPhysician", recData.value("attendingPhysician"));
        query.bindValue(":admissionDate", recData.value("admissionDate"));
        query.bindValue(":dischargeDate", recData.value("dischargeDate"));
        query.bindValue(":notes", recData.value("notes"));
        query.bindValue(":ID", id);

         if (!query.exec()) {
            QMessageBox::critical(this, "错误", "patientinfo 表记录更新错误\n" + query.lastError().text());
            return;
        }
        qryModel->setQuery("SELECT id, name, gender, idNumber, contact, address FROM personinfo", DB); //数据模型重新查询数据，更新 tableView 显示内容
        showRecordCount();
    }
    delete dataDialog;
}


// 添加
void MainWindow::on_actAdd_triggered()
{
    QSqlQuery query(DB);
    query.exec("SELECT personinfo.*, patientinfo.* "
               "FROM personinfo "
               "INNER JOIN patientinfo ON personinfo.id = patientinfo.id "
               "WHERE personinfo.id = -1");

    QSqlRecord curRec = query.record();
    int ID = qryModel->rowCount() + 100000;
    curRec.setValue("id", ID);

    Dialog *dataDialog = new Dialog(this);
    Qt::WindowFlags flags = dataDialog->windowFlags();
    dataDialog->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);
    dataDialog->setInsertRecord(curRec);

    int ret = dataDialog->exec();
    if (ret == QDialog::Accepted) {
        QSqlRecord recData = dataDialog->getRecordData();

        // 插入 personinfo 表记录
        query.prepare("INSERT INTO personinfo (id, name, age, gender, photo, idNumber, contact, address) "
                      "VALUES(:id, :name, :age, :gender, :photo, :idNumber, :contact, :address)");
        query.bindValue(":id", recData.value("id"));
        query.bindValue(":name", recData.value("name"));
        query.bindValue(":age", recData.value("age"));
        query.bindValue(":gender", recData.value("gender"));
        query.bindValue(":photo", recData.value("photo"));
        query.bindValue(":idNumber", recData.value("idNumber"));
        query.bindValue(":contact", recData.value("contact"));
        query.bindValue(":address", recData.value("address"));

        QVariant nameValue = recData.value("name");

        if (!query.exec()) {
            QMessageBox::critical(this, "错误", "personinfo 表记录更新错误\n" + query.lastError().text());
            return;
        }

        query.prepare("UPDATE patientinfo SET buildingNumber=:buildingNumber, roomNumber=:roomNumber, "
                      "bedNumber=:bedNumber, department=:department, "
                      "attendingPhysician=:attendingPhysician, admissionDate=:admissionDate, "
                      "dischargeDate=:dischargeDate, notes=:notes "
                      "WHERE id = :ID");


        query.bindValue(":buildingNumber", recData.value("buildingNumber"));
        query.bindValue(":roomNumber", recData.value("roomNumber"));
        query.bindValue(":bedNumber", recData.value("bedNumber"));
        query.bindValue(":department", recData.value("department"));
        query.bindValue(":attendingPhysician", recData.value("attendingPhysician"));
        query.bindValue(":admissionDate", recData.value("admissionDate"));
        query.bindValue(":dischargeDate", recData.value("dischargeDate"));
        query.bindValue(":notes", recData.value("notes"));
        query.bindValue(":ID", ID);

        if (!query.exec()) {
            QMessageBox::critical(this, "错误", "patientinfo 表记录更新错误\n" + query.lastError().text());
            return;
        }

        qryModel->setQuery("SELECT id, name, gender, idNumber, contact, address FROM personinfo", DB);
        showRecordCount();
    }
    delete dataDialog;
}


// 删除
void MainWindow::on_actDelete_triggered()
{
    int curRecNo= selModel->currentIndex().row();
    QSqlRecord curRec= qryModel->record(curRecNo);
    if (curRec.isEmpty())
        return;

    int id = curRec.value("id").toInt();
    QSqlQuery query(DB);
    query.prepare("DELETE FROM personinfo WHERE id = :ID");
    query.bindValue(":ID",id);
    if (!query.exec())
        QMessageBox::critical(this, "错误",  "删除记录出现错误\n"+query.lastError().text());
    else {
            // 删除 patientinfo 表中相应记录
            query.prepare("DELETE FROM patientinfo WHERE id = :ID");
            query.bindValue(":ID", id);
        if (!query.exec()) {
            QMessageBox::critical(this, "错误", "删除 patientinfo 表记录出现错误\n" + query.lastError().text());
        } else {
            qryModel->setQuery("SELECT id, name, gender, idNumber, address FROM personinfo", DB);
            showRecordCount();
        }
    }
}


// 信息统计
void MainWindow::on_actSum_triggered()
{
    Statistics *statistic = new Statistics(this);
    connect(statistic, &Statistics::closed, this, &MainWindow::onStatisticsClosed);
    statistic->show();
    ui->actSum->setEnabled(false);
}

void MainWindow::onStatisticsClosed()
{
    ui->actSum->setEnabled(true);
}



/************************ 修改密码  *********************************/
void MainWindow::on_actPwd_triggered()
{
    bool ok = true;;
    QString newPassword = QInputDialog::getText(this, "修改密码","请输入 " + loginCount + " 的新密码:", QLineEdit::Normal, "请确保密码安全性！！！", &ok);
    if (ok) {
        if (newPassword.isEmpty()) {
            QMessageBox::warning(this, "错误", "密码不能为空，请重新输入。");
        } else if (updatePassword(loginCount, newPassword)) {
            QMessageBox::information(this, "成功", "密码已成功修改");
        } else {
            //qDebug() << loginCount;
            QMessageBox::warning(this, "错误", "密码修改失败");
        }
    }
}


// 更新密码
bool MainWindow::updatePassword(const QString &logincount, const QString &newPassword)
{
    QSqlTableModel *model = new QSqlTableModel(nullptr, DB);
    model->setTable("admin");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    int row = -1;

    for (int i = 0; i < model->rowCount(); ++i) {
        QModelIndex index = model->index(i, model->fieldIndex("count"));
        if (model->data(index).toString() == logincount) {
            row = i;
            qDebug() << QString("行数 %1").arg(i);
            break;
        }
    }

    QString salt = GenerateRandomSalt(16);
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
            //qDebug() << "submit error";
            return false;
        }

    } else {
        //qDebug() << "serach error";
        return false;
    }
}


// 哈希加密
QString MainWindow::GenerateRandomSalt(int length)
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

QString MainWindow::hashPassword(const QString &password, const QString &salt)
{
    QByteArray saltByteArray = salt.toUtf8();
    QByteArray passwordBytes = password.toUtf8();
    passwordBytes.append(saltByteArray);

    QByteArray hashedPassword = QCryptographicHash::hash(passwordBytes, QCryptographicHash::Sha256);
    return QString(hashedPassword.toHex());
}



/********************** 搜索 *************************/
void MainWindow::searchButtonClicked()
{
    QString searchTerm = searchLineEdit->text();

    if (searchTerm.isEmpty()) {
        qryModel->setQuery("SELECT id, name, gender, idNumber, contact, address FROM personinfo", DB);
    } else {
        qryModel->setQuery("SELECT id, name, gender, idNumber, contact, address FROM personinfo WHERE "
                        "id LIKE '%" + searchTerm + "%' OR "
                        "name LIKE '%" + searchTerm + "%'", DB);
    }

    if (qryModel->lastError().isValid()) {
        QMessageBox::information(this, "错误", "数据表查询错误, 错误信息\n" + qryModel->lastError().text());
        return;
    }

    ui->tableView->setModel(qryModel);
    showRecordCount();
}

// Enter快捷键搜索
void MainWindow::keyPressEvent(QKeyEvent *event) {
        if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
            searchButtonClicked();
        }
}

/* 显示记录数 */
void MainWindow::showRecordCount()
{
    int recordCount = qryModel->rowCount();
    recordCountLabel->setText(QString("记录条数：%1").arg(recordCount));
}






