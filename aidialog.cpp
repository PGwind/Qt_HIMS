#include "aidialog.h"
#include "ui_aidialog.h"

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

    connectionThread->quit();
    connectionThread->wait();
}


// 界面初始化
void AiDialog::Init()
{
    // 对话框
    setFixedSize(310, 440);
    ui->textEdit->setStyleSheet("background-color: lightblue;");
    //ui->textEdit->setStyleSheet("QTextEdit { background-image: url(:/backgroud/images/backgroud/chatbg.png); }");
    ui->textEdit->setReadOnly(true);
    QFont font = ui->textEdit->font();
    font.setBold(true);
    //font.setPointSize(14);
    ui->textEdit->setFont(font);

    // 发送消息框
    ui->lineEdit->setPlaceholderText("请输入消息");
    ui->lineEdit->setStyleSheet("QTextEdit { background-color: lightgray; border: 2px solid gray; }");


    // 按钮
    QIcon icon1(":/icons/images/icons/dialog.ico");
    this->setWindowIcon(icon1);

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

    connect(socket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

    connect(connectionThread, SIGNAL(finished()), connectionThread, SLOT(deleteLater()));

    connectionThread->start();

    connectToServer();

    connect(ui->btnSend, SIGNAL(clicked()), this, SLOT(sendToServer()));
}

// 连接服务器
void AiDialog::connectToServer()
{
    socket->connectToHost("47.236.109.14", 1024);   // 服务器信息
}


// 发送消息
void AiDialog::sendToServer()
{
    QString message = ui->lineEdit->text();
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(message.toUtf8());
        socket->waitForBytesWritten(1000);  // 阻塞

        ui->textEdit->append("<b>Question:</b> " + message);
        ui->btnSend->setEnabled(false);
        ui->lineEdit->clear();

    } else {
        qDebug() << "连接失败， 重新连接";
        connectToServer();
    }
}

//槽函数
void AiDialog::onConnected()
{
    qDebug() << "Connected to server";
}

void AiDialog::onReadyRead()
{
    QString response = QString(socket->readAll());
    QString coloredResponse = "<span style='color: blue;'><i>Answer:</i> " + response + "</span><br><br>";
    ui->textEdit->append(coloredResponse);

    ui->btnSend->setEnabled(true);
}
