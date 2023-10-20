#include "login.h"
#include "ui_login.h"
#include <QFile>
#include <QDateTime>
#include <QRandomGenerator>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    /* 加载CSS */
    QFile styleFile(":/css/login.css");
    styleFile.open(QFile::ReadOnly);
    QString style = QLatin1String(styleFile.readAll());
    qApp->setStyleSheet(style);

    ui->lineEdit_count->setPlaceholderText("👤 Enter Account");
    ui->lineEdit_passwd->setPlaceholderText("🔒 Enter Password");
    ui->lineEdit_passwd->setEchoMode(QLineEdit::Password);  // 输入时隐藏


    /*连接数据库 */
    DB = QSqlDatabase::addDatabase("QMYSQL");
    DB.setHostName("localhost");
    DB.setDatabaseName("ims");
    DB.setUserName("root");
    DB.setPassword("root");

    // 打开数据库连接
    if (DB.open()) {
        qDebug() << "Connected to the database!";
    } else {
        qDebug() << "Failed to connect to the database: " << DB.lastError().text();
    }

    // 创建数据模型和选择模型
    qryModel = new QSqlQueryModel;
    selModel = new QItemSelectionModel(qryModel);


    // 在qryModel中执行SQL查询并设置选择模型
    qryModel->setQuery("SELECT * FROM your_table_name");
    selModel->setModel(qryModel);
}

login::~login()
{
    delete ui;
}

void login::on_btnMin_clicked()
{
    this->showMinimized();
}


void login::on_btnClose_clicked()
{
    this->close();
}


/* 窗口拖动 */
void login::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragging = true;
        m_dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}

void login::mouseMoveEvent(QMouseEvent *event)
{
    if (m_dragging) {
        move(event->globalPosition().toPoint() - m_dragPosition);
        event->accept();
    }
}


void login::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_dragging = false;
}


/* 哈希盐值salt  */
QString login::GenerateRandomSalt(int length)
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

/* 哈希加密 */
QString login::hashPassword(const QString &password, const QString &salt)
{
    QByteArray saltByteArray = salt.toUtf8();
    QByteArray passwordBytes = password.toUtf8();
    passwordBytes.append(saltByteArray);

    // 使用SHA-256哈希算法对密码和盐值进行哈希
    QByteArray hashedPassword = QCryptographicHash::hash(passwordBytes, QCryptographicHash::Sha256);
    return QString(hashedPassword.toHex());
}

/* 密码合法性检测 */
bool login::isPasswordValid(const QString &password)
{
    QRegularExpression regex("^(?=.*[a-z])(?=.*[A-Z]).{6,}$");
    QRegularExpressionMatch match = regex.match(password);

    return match.hasMatch();
}


/* 注册用户 */
void login::on_btnRegister_clicked()
{
    QString count = ui->lineEdit_count->text();
    QString password = ui->lineEdit_passwd->text();
    QString uid = QUuid::createUuid().toString(); // 生成唯一的UUID

    // 密码复杂性检测
    if (!isPasswordValid(password)) {
        QMessageBox::warning(this, "密码较弱", "密码必须大于6位且包含大小写字母");
        return;
    }

    // 检查用户名是否已存在
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM users WHERE count = :count");
    checkQuery.bindValue(":count", count);

    if (checkQuery.exec() && checkQuery.next()) {
        QMessageBox::warning(this, "用户名已存在", "用户名 " + count + " 已被注册！");
        return;
    }

    // 生成随机盐值
    QString salt = GenerateRandomSalt(16);

    // 哈希密码和盐值
    QString hashedPassword = hashPassword(password, salt);

    // 将用户名、哈希密码和盐值存储在数据库表中
    QSqlQuery query;
    query.prepare("INSERT INTO users (uid, count, password, salt, role) VALUES (:uid, :count, :password, :salt, :role)");
    query.bindValue(":uid", uid);
    query.bindValue(":count", count);
    query.bindValue(":password", hashedPassword);
    query.bindValue(":salt", salt);
    query.bindValue(":role", "user"); // 默认角色为 "user"

    if (query.exec()) {
        QMessageBox::information(this, "注册成功", "用户已成功注册!");
    } else {
        QMessageBox::critical(this, "注册失败", "无法注册用户: " + query.lastError().text());
    }
}


/* 用户登录 */
void login::on_btnLogin_clicked()
{
    QString count = ui->lineEdit_count->text();
    QString password = ui->lineEdit_passwd->text();

    // 查询数据库以获取用户的盐值和哈希密码
    QSqlQuery query;
    query.prepare("SELECT salt, password, role FROM users WHERE count = :count");
    query.bindValue(":count", count);

    if (query.exec()) {
        if (query.next()) {
            QString salt = query.value(0).toString();
            QString storedHashedPassword = query.value(1).toString();
            QString userRole = query.value(2).toString();

            // 重新计算用户输入密码的哈希
            QString hashedPassword = hashPassword(password, salt);


            if (hashedPassword == storedHashedPassword) {
                // 密码正确
                if (userRole == "user") {
                    // 打开用户页面
                    userWindow = new userwindow();
                    userWindow->show();
                   // qDebug() << "User login successful!";
                } else if (userRole == "admin") {
                    // 打开管理员页面
                    adminWindow = new MainWindow();
                    adminWindow->show();
                    //qDebug() << "Admin login successful!";
                } else {
                    // 未知角色
                    QMessageBox::critical(this, "登录失败", "未知角色");
                }
                this->close();

            } else {
                // 密码错误
                QMessageBox::critical(this, "登录失败", "密码错误");
            }
        } else {
            // 用户不存在
            QMessageBox::critical(this, "登录失败", "用户不存在");
        }
    } else {
        // 数据库查询失败
        QMessageBox::critical(this, "登录失败", "数据库查询失败: " + query.lastError().text());
    }
}

/* Enter快捷键登录 */
void login::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        on_btnLogin_clicked();
    }
}




