#include "userwindow.h"
#include "ui_userwindow.h"

/**************************************************************

Title：userwindow.c
Function: 病人信息界面，可进行信息以及密码修改
Change_Time: 2023/10/31

**************************************************************/


userwindow::userwindow(QWidget *parent, const QString &loginCount) :
    QMainWindow(parent),
    ui(new Ui::userwindow),
    loginCount(loginCount)
{
    ui->setupUi(this);
    setWindowTitle("个人信息");

    this->setWindowIcon(QIcon(":/icons/images/icons/user.ico"));
    Init();
    openTable();
}

userwindow::~userwindow()
{
    delete ui;
}


/* 数据库 */
void userwindow::openTable()
{
    DB = QSqlDatabase::addDatabase("QMYSQL", "user");
    DB.setHostName("121.37.155.243");
    DB.setDatabaseName("hims");
    DB.setUserName("hims");
    DB.setPassword("hims2002");
    if (DB.open()) {
        //qDebug() << "DB_patients connect";
    } else {
        //qDebug() << "Database connection error: " << DB.lastError().text();
    }

    // 界面信息获取
    QSqlQuery query(DB);
    query.prepare("SELECT personinfo.*, patientinfo.* "
                  "FROM personinfo "
                  "INNER JOIN patientinfo ON personinfo.id = patientinfo.id "
                  "WHERE personinfo.id = :ID");
    query.bindValue(":ID", loginCount);
    query.exec();
    query.first();

    if (!query.isValid()) { //无有效记录
        qDebug() << "查询失败";
        return;
    }

    QSqlRecord curRec = query.record();
    setUpdateRecord(curRec);

}


/* 初始化 */
void userwindow::Init()
{
    // CSS
    QFile styleFile(":/css/userwindow.css");
    styleFile.open(QFile::ReadOnly);
    QString style = QLatin1String(styleFile.readAll());
    qApp->setStyleSheet(style);


    // 性别
    ui->comboBox_sex->addItem("男");
    ui->comboBox_sex->addItem("女");
    // 楼号
    ui->comboBox_build->addItem("1");
    ui->comboBox_build->addItem("2");
    ui->comboBox_build->addItem("3");
    ui->comboBox_build->addItem("4");
    // 床号
    ui->comboBox_bed->addItem("1");
    ui->comboBox_bed->addItem("2");
    ui->comboBox_bed->addItem("3");
    // 科室
    QStringList items;
    items << "呼吸内科" << "消化内科" << "泌尿内科" << "心内科" << "血液科" << "内分泌科"
    << "神经内科" << "小儿科" << "感染科" << "普外科" << "骨科" << "神经外科"
    << "肝胆外科" << "泌尿外科" << "烧伤科" << "妇科" << "产科" << "血透室" << "重症监护室";
    items.sort();
    ui->comboBox_department->addItems(items);

    ui->actSave->setEnabled(false);
    ui->label_photo->setEnabled(true);
    ui->groupBox->setEnabled(false);

    ui->groupBox->setEnabled(false);
    ui->groupBox_2->setEnabled(false);
    ui->groupBox_3->setEnabled(false);
    ui->groupBox_4->setEnabled(false);
    ui->groupBox_5->setEnabled(false);
}


/* 信息框修改权限 */
void userwindow::setFlag(bool flag)
{
    ui->groupBox_3->setEnabled(flag);
    ui->groupBox_4->setEnabled(flag);
}


/* 清除图像 */
void userwindow::on_actClear_triggered()
{
    ui->actModify->setEnabled(true);
    ui->actSave->setEnabled(true);
    ui->label_photo->clear();
    m_record.setNull("photo");
}


/* 修改图像 */
void userwindow::on_actPhoto_triggered()
{
    ui->actModify->setEnabled(true);
    ui->actSave->setEnabled(true);
    QString aFile= QFileDialog::getOpenFileName(this,"选择图片文件","", "照片(*.jpg)");
    if (aFile.isEmpty())
        return;
    QByteArray data;
    QFile* file= new QFile(aFile);
    file->open(QIODevice::ReadOnly);
    data = file->readAll();
    file->close();
    delete file;
    m_record.setValue("photo",data);
    QPixmap pic;
    pic.loadFromData(data);
    ui->label_photo->setPixmap(pic.scaledToWidth(ui->label_photo->size().width()));
}


/* 保存 */
void userwindow::on_actSave_triggered()
{
    setFlag(false);
    ui->actModify->setEnabled(true);
    ui->actSave->setEnabled(false);
    QSqlRecord recData = getRecordData();
    QSqlQuery query(DB);
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
        query.bindValue(":ID", loginCount);

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
        query.bindValue(":ID", loginCount);

         if (!query.exec()) {
            QMessageBox::critical(this, "错误", "patientinfo 表记录更新错误\n" + query.lastError().text());
            return;
        }
}


/* 修改 */
void userwindow::on_actModify_triggered()
{
    setFlag(true);
    ui->actSave->setEnabled(true);
    ui->centralwidget->setEnabled(true);
    ui->lineEdit_id->setEnabled(false);
    ui->actModify->setEnabled(false);

}


/* 密码 */
void userwindow::on_actPwd_triggered()
{
    bool ok;
    QString newPassword = QInputDialog::getText(this, "修改密码", "请输入新密码：", QLineEdit::Normal, "请确保密码安全性！！！", &ok);

    if (ok) {
        if (newPassword.isEmpty()) {
            QMessageBox::warning(this, "错误", "密码不能为空，请重新输入。");
        } else {
            QString salt = GenerateRandomSalt(16);
            QString hashedPassword = hashPassword(newPassword, salt);

            QSqlQuery query(DB);
            query.prepare("UPDATE users SET password = :password, salt = :salt WHERE id = :count");
            query.bindValue(":password", hashedPassword);
            query.bindValue(":salt", salt);
            query.bindValue(":count", loginCount);

            if (query.exec()) {
                QMessageBox::information(this, "成功", "密码已更新并保存");
            } else {
                QMessageBox::warning(this, "错误", "密码更新失败");
            }
        }
    }
}



/* 更新记录 */
void userwindow::setUpdateRecord(QSqlRecord &recData)
{
    m_record = recData;
    ui->lineEdit_id->setEnabled(false);

    ui->lineEdit_id->setText(recData.value("id").toString());
    ui->lineEdit_name->setText(recData.value("name").toString());
    ui->spinBox_age->setValue(recData.value("age").toInt());
    ui->comboBox_sex->setCurrentText(recData.value("gender").toString());
    ui->lineEdit_idNumber->setText(recData.value("idNumber").toString());
    ui->lineEdit_contact->setText(recData.value("contact").toString());
    ui->lineEdit_address->setText(recData.value("address").toString());

    ui->comboBox_build->setCurrentText(recData.value("buildingNumber").toString());
    ui->lineEdit_room->setText(recData.value("roomNumber").toString());
    ui->comboBox_bed->setCurrentText(recData.value("bedNumber").toString());
    ui->comboBox_department->setCurrentText(recData.value("department").toString());
    ui->lineEdit_attending->setText(recData.value("attendingPhysician").toString());
    ui->dateEdit_inpatients->setDate(recData.value("admissionDate").toDate());
    ui->dateEdit_discharge->setDate(recData.value("dischargeDate").toDate());
    ui->textEdit_note->setText(recData.value("notes").toString());

    QVariant va= recData.value("photo");
    if (!va.isValid()) //Photo 字段内容为空
        ui->label_photo->clear();
    else
    {
        QByteArray data= va.toByteArray();
        QPixmap pic;
        if (pic.loadFromData(data))
        {
            ui->label_photo->setPixmap(pic.scaledToWidth(ui->label_photo->size().width()));
        }
        else
        {
            qDebug() << "加载图像失败";
        }
    }
}


/* 获取界面输入的数据 */
QSqlRecord userwindow::getRecordData()
{
    m_record.setValue("id", ui->lineEdit_id->text().toInt());
    m_record.setValue("name", ui->lineEdit_name->text());
    m_record.setValue("age", ui->spinBox_age->value());
    m_record.setValue("gender", ui->comboBox_sex->currentText());
    m_record.setValue("idNumber", ui->lineEdit_idNumber->text());
    m_record.setValue("contact", ui->lineEdit_contact->text());
    m_record.setValue("address", ui->lineEdit_address->text());

    m_record.setValue("buildingNumber", ui->comboBox_build->currentText().toInt());
    m_record.setValue("roomNumber", ui->lineEdit_room->text());
    m_record.setValue("bedNumber", ui->comboBox_bed->currentText().toInt());
    m_record.setValue("department", ui->comboBox_department->currentText().toInt());
    m_record.setValue("attendingPhysician", ui->lineEdit_attending->text());
    m_record.setValue("admissionDate", ui->dateEdit_inpatients->date());
    m_record.setValue("dischargeDate", ui->dateEdit_discharge->date());
    m_record.setValue("notes", ui->textEdit_note->toPlainText());

    return m_record;
}


/* 哈希加密 */
QString userwindow::GenerateRandomSalt(int length)
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

QString userwindow::hashPassword(const QString &password, const QString &salt)
{
    QByteArray saltByteArray = salt.toUtf8();
    QByteArray passwordbytes = password.toUtf8();
    passwordbytes.append(saltByteArray);

    QByteArray hashedPassword = QCryptographicHash::hash(passwordbytes, QCryptographicHash::Sha256);
    return QString(hashedPassword.toHex());
}
