#include "aidialog.h"
#include "ui_aidialog.h"
#include <QMessageBox>
#include <QEvent>

/**************************************************************

Title：aidialog.cpp
Function: AI咨询界面，连接科大讯飞星火大模型V3.0
Change_Time: 2023/11/7

**************************************************************/


AiDialog::AiDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AiDialog)
{
    ui->setupUi(this);

    Init();

    InitThread();
}

AiDialog::~AiDialog()
{
    delete ui;

    // 关闭 socket 连接
    socket->disconnectFromHost();
    socket->close();

    //结束线程
    connectionThread->quit();
    connectionThread->wait();

    delete socket;
    delete connectionThread;

    //qDebug() << "AiDialog destructor called";
}


// 界面初始化
void AiDialog::Init()
{
    // 对话框
    setFixedSize(310, 440);
    //ui->textEdit->setStyleSheet("background-color: lightblue;");  // 背景颜色
    //ui->textEdit->setStyleSheet("QTextEdit { background-image: url(:/backgroud/images/backgroud/chatbg.png); }"); // 背景图片
    ui->textEdit->setReadOnly(true);
    QFont font = ui->textEdit->font();
    font.setBold(true);
    //font.setPointSize(14);
    ui->textEdit->setFont(font);

    // 发送消息框
    ui->lineEdit->setPlaceholderText("请输入消息");
    ui->lineEdit->setStyleSheet("QTextEdit { background-color: lightgray; border: 2px solid gray; }");


    // 界面图标
    QIcon icon1(":/icons/images/icons/dialog.ico");
    this->setWindowIcon(icon1);

    // 按钮图标
    QIcon icon2(":/icons/images/icons/send.png");
    ui->btnSend->setIcon(icon2);
    ui->btnSend->setIconSize(QSize(32, 32));
}


// 线程初始化
void AiDialog::InitThread()
{
    connectionThread = new QThread;

    socket = new QTcpSocket();
    socket->moveToThread(connectionThread);

    connectionThread->start();  // 启动

    connectToServer();  // 连接服务器

    connect(socket, SIGNAL(connected()), this, SLOT(onConnected()));    // 检测连接
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));    // 读取socket
    connect(connectionThread, SIGNAL(finished()), connectionThread, SLOT(deleteLater()));   // 删除已结束线程

    connect(ui->btnSend, SIGNAL(clicked()), this, SLOT(sendToServer()));    // 发送socket
}

// 连接服务器
void AiDialog::connectToServer()
{
    QString ipAddress = "47.236.109.14";
    quint64 port = Q_UINT64_C(1024);

    socket->connectToHost(ipAddress, port);  // 服务器信息

    if (!socket->waitForConnected()) {
        // 连接失败，显示消息框
        QMessageBox messageBox;
        messageBox.setWindowTitle("连接失败");
        messageBox.setText("连接失败，重新连接");
        messageBox.setIcon(QMessageBox::Critical);
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.setDefaultButton(QMessageBox::Ok);

        messageBox.exec();
    }
}


// 发送消息
void AiDialog::sendToServer()
{
    QString message = ui->lineEdit->text();
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(message.toUtf8());
        socket->waitForBytesWritten(1000);  // 阻塞

        QString messageWithIcon = "<span style='font-size: 20px; float: right;'>&#x1F64B; </span><span style='color: blue;'>" + message + "</span>";
        ui->textEdit->append(messageWithIcon);


        ui->btnSend->setEnabled(false);
        ui->lineEdit->clear();

    } else {
        //qDebug() << "连接失败， 重新连接";
        QMessageBox messageBox;
        messageBox.setWindowTitle("连接失败");
        messageBox.setText("连接失败，重新连接");
        messageBox.setIcon(QMessageBox::Critical); // 设置图标为错误图标
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.setDefaultButton(QMessageBox::Ok);
        connectToServer();
    }
}

// 连接成功
void AiDialog::onConnected()
{
    //qDebug() << "Connected to server Successfully";
//    QMessageBox msgBox;
//    msgBox.setText("Connected to server Successfully");
//    msgBox.exec();
}

// 发送
void AiDialog::onReadyRead()
{
    QString response = QString(socket->readAll());

    QString coloredResponse = "<span style='font-size: 20px; "
                              "'>&#x1F916; </span><span style='font-size: 12px;'>" + response + "</span><br><br>";


    ui->textEdit->append(coloredResponse);

    ui->btnSend->setEnabled(true);
}
