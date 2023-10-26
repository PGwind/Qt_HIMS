#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    Init();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::Init()
{
    /* 加载CSS */
    QFile styleFile(":/css/userwindow.css");
    styleFile.open(QFile::ReadOnly);
    QString style = QLatin1String(styleFile.readAll());
    qApp->setStyleSheet(style);

    ui->frame->setStyleSheet("QFrame { border: 1px solid black; }");


    // 性别
    ui->comboBox_gender->addItem("男");
    ui->comboBox_gender->addItem("女");
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
}

void Dialog::on_pushButton_setPhoto_clicked()
{
    QString aFile=QFileDialog::getOpenFileName(this,"选择图片文件","", "照片(*.jpg)");
    if (aFile.isEmpty())
        return;

    QByteArray data;
    QFile* file = new QFile(aFile);
    file->open(QIODevice::ReadOnly);
    data = file->readAll();
    file->close();
    delete file;

    m_record.setValue("photo",data); //图片保存到Photo字段

    QPixmap pic;
    pic.loadFromData(data);
    ui->label_photo->setPixmap(pic.scaledToWidth(ui->label_photo->size().width()));
}

void Dialog::on_pushButton_clear_clicked()
{
    ui->label_photo->clear();
    m_record.setNull("photo");
}

void Dialog::setUpdateRecord(QSqlRecord &recData)   //更新记录
{
    m_record = recData;
    ui->lineEdit_id->setEnabled(false);
    setWindowTitle("更新记录");

    ui->lineEdit_id->setText(recData.value("id").toString());
    ui->lineEdit_name->setText(recData.value("name").toString());
    ui->spinBox_age->setValue(recData.value("age").toInt());

    ui->comboBox_gender->setCurrentText(recData.value("gender").toString());
    ui->lineEdit_idNumber->setText(recData.value("idNumber").toString());
    ui->lineEdit_contact->setText(recData.value("contact").toString());
    ui->lineEdit_address->setText(recData.value("address").toString());

    ui->comboBox_build->setCurrentText(recData.value("buildingNumber").toString());
    ui->lineEdit_room->setText(recData.value("roomNumber").toString());
    ui->comboBox_bed->setCurrentText(recData.value("bedNumber").toString());
    ui->comboBox_department->setCurrentText(recData.value("department").toString());
    ui->lineEdit_attend->setText(recData.value("attendingPhysician").toString());
    ui->dateEdit_admission->setDate(recData.value("admissionDate").toDate());
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
            // qDebug() << "加载图像失败";
        }
    }
}

void Dialog::setInsertRecord(QSqlRecord &recData)   //插入记录
{
    m_record = recData;
    ui->lineEdit_id->setEnabled(false);
    setWindowTitle("插入新记录");
    ui->lineEdit_id->setText(recData.value("id").toString());
}

QSqlRecord Dialog::getRecordData()     //获取界面输入的数据
{
    m_record.setValue("id", ui->lineEdit_id->text().toInt());
    m_record.setValue("name", ui->lineEdit_name->text());
    m_record.setValue("age", ui->spinBox_age->value());
    m_record.setValue("gender", ui->comboBox_gender->currentText());
    m_record.setValue("idNumber", ui->lineEdit_idNumber->text());
    m_record.setValue("contact", ui->lineEdit_contact->text());
    m_record.setValue("address", ui->lineEdit_address->text());

    m_record.setValue("buildingNumber", ui->comboBox_build->currentText().toInt());
    m_record.setValue("roomNumber", ui->lineEdit_room->text());
    m_record.setValue("bedNumber", ui->comboBox_bed->currentText().toInt());
    m_record.setValue("department", ui->comboBox_department->currentText());
    m_record.setValue("attendingPhysician", ui->lineEdit_attend->text());
    m_record.setValue("admissionDate", ui->dateEdit_admission->date());
    m_record.setValue("dischargeDate", ui->dateEdit_discharge->date());
    m_record.setValue("notes", ui->textEdit_note->toPlainText());

    return m_record;
}

void Dialog::on_pushButton_lock_clicked()
{
    int id = m_record.value("id").toInt();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "change");
    db.setHostName("localhost"); // MySQL服务器主机名
    db.setDatabaseName("ims"); // 数据库名称
    db.setUserName("root"); // MySQL用户名
    db.setPassword("root"); // MySQL密码

    if (db.open()) {
        //qDebug() << "dialog connect";
    } else {
        qDebug() << "Database connection error: " << db.lastError().text();
    }

    QString newPassword = QInputDialog::getText(this, "输入密码", "请输入新密码:", QLineEdit::Password);
    qDebug() << newPassword;
    QString salt = GenerateRandomSalt(16);
    QString hashedPassword = hashPassword(newPassword, salt);
    QSqlQuery query(db);
    query.prepare("UPDATE users SET password=:password, salt=:salt WHERE id=:id");

    // 绑定值
    query.bindValue(":password", hashedPassword);
    query.bindValue(":salt", salt);
    query.bindValue(":id", id);

    // 执行更新
    if (query.exec()) {

    } else {
        // 更新出错，处理错误
        qDebug() << "更新失败: " << query.lastError().text();
    }

}

/* 哈希加密 */
QString Dialog::GenerateRandomSalt(int length)
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

QString Dialog::hashPassword(const QString &password, const QString &salt)
{
    QByteArray saltByteArray = salt.toUtf8();
    QByteArray passwordbytes = password.toUtf8();
    passwordbytes.append(saltByteArray);

    // 使用SHA-256哈希算法对密码和盐值进行哈希
    QByteArray hashedPassword = QCryptographicHash::hash(passwordbytes, QCryptographicHash::Sha256);
    return QString(hashedPassword.toHex());
}
