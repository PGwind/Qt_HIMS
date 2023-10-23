#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

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

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_setPhoto_clicked()
{
    QString aFile=QFileDialog::getOpenFileName(this,"选择图片文件","", "照片(*.jpg)");
    if (aFile.isEmpty())
        return;

    QByteArray data;
    QFile* file=new QFile(aFile);
    file->open(QIODevice::ReadOnly);
    data = file->readAll();
    file->close();

    QPixmap pic;
    pic.loadFromData(data);
    m_record.setValue("photo",data); //图片保存到Photo字段

//    QPixmap pic;
//    pic.loadFromData(data);
    ui->label_photo->setPixmap(pic.scaledToWidth(ui->label_photo->size().width()));
}


void Dialog::on_pushButton_clear_clicked()
{
    ui->label_photo->clear();
    m_record.setNull("photo"); //Photo 字段清空
}

void Dialog::setUpdateRecord(QSqlRecord &recData)   //更新记录
{
    m_record= recData;
    ui->lineEdit_id->setEnabled(false);
    setWindowTitle("更新记录");

    ui->lineEdit_id->setText(recData.value("id").toString());
    ui->lineEdit_name->setText(recData.value("name").toString());
    ui->spinBox_age->setValue(recData.value("age").toInt());
    ui->comboBox_gender->setEditText(recData.value("gender").toString());
    ui->lineEdit_idNumber->setText(recData.value("idNumber").toString());
    ui->lineEdit_address->setText(recData.value("address").toString());

    QVariant va= recData.value("photo");
    if (!va.isValid()) //Photo 字段内容为空
        ui->label_photo->clear();
    else
    {
        QByteArray data= va.toByteArray();
        QPixmap pic;
        //        pic.loadFromData(data);
        //        ui->label_photo->setPixmap(pic.scaledToWidth(ui->label_photo->size().width()));
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
    m_record.setValue("idNumber", ui->lineEdit_name->text());
    m_record.setValue("address", ui->lineEdit_name->text());

    return m_record;
}
