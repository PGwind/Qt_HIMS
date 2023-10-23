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
}

userwindow::~userwindow()
{
    delete ui;
}

void userwindow::updateRecord(QSqlRecord &recData)
{
    m_record= recData;
    ui->lineEdit_id->setEnabled(false);
    setWindowTitle("更新记录");

    ui->lineEdit_id->setText(recData.value("id").toString());
    ui->lineEdit_name->setText(recData.value("name").toString());
    ui->spinBox_age->setValue(recData.value("age").toInt());
    ui->comboBox_sex->setEditText(recData.value("gender").toString());
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

void userwindow::addRecord(QSqlRecord &recData)
{
    m_record = recData;
    ui->lineEdit_id->setEnabled(false);
    setWindowTitle("插入新记录");
    ui->lineEdit_id->setText(recData.value("id").toString());

}

QSqlRecord userwindow::getRecordData()
{
    m_record.setValue("id", ui->lineEdit_id->text().toInt());
    m_record.setValue("name", ui->lineEdit_name->text());
    m_record.setValue("age", ui->spinBox_age->value());
    m_record.setValue("gender", ui->comboBox_sex->currentText());
    m_record.setValue("idNumber", ui->lineEdit_name->text());
    m_record.setValue("address", ui->lineEdit_name->text());

    return m_record;
}

void userwindow::on_actClear_triggered()
{
    ui->label_photo->clear();
    m_record.setNull("photo");
}


void userwindow::on_actPhoto_triggered()
{
    QString aFile= QFileDialog::getOpenFileName(this,"选择图片文件","", "照片(*.jpg)");
    if (aFile.isEmpty())
        return;
    QByteArray data;
    QFile* file= new QFile(aFile);
    file->open(QIODevice::ReadOnly);
    data = file->readAll();
    file->close();
    delete file;
    m_record.setValue("photo",data); //图片保存到 Photo 字段中
    QPixmap pic;
    pic.loadFromData(data);
    ui->label_photo->setPixmap(pic.scaledToWidth(ui->label_photo->size().width()));
}


void userwindow::on_actSave_triggered()
{
    isSave = true;
}


void userwindow::on_actCancel_triggered()
{
    this->close();
}





