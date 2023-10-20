/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QFrame *frame;
    QLineEdit *lineEdit_count;
    QLineEdit *lineEdit_passwd;
    QPushButton *btnRegister;
    QLabel *labelCover;
    QPushButton *btnMin;
    QPushButton *btnClose;
    QPushButton *btnLogin;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(430, 330);
        login->setMinimumSize(QSize(430, 330));
        login->setMaximumSize(QSize(430, 330));
        frame = new QFrame(login);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 430, 330));
        frame->setMinimumSize(QSize(430, 330));
        frame->setMaximumSize(QSize(430, 330));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lineEdit_count = new QLineEdit(frame);
        lineEdit_count->setObjectName(QString::fromUtf8("lineEdit_count"));
        lineEdit_count->setGeometry(QRect(120, 130, 170, 30));
        lineEdit_count->setMinimumSize(QSize(170, 30));
        lineEdit_count->setMaximumSize(QSize(170, 30));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        lineEdit_count->setFont(font);
        lineEdit_passwd = new QLineEdit(frame);
        lineEdit_passwd->setObjectName(QString::fromUtf8("lineEdit_passwd"));
        lineEdit_passwd->setGeometry(QRect(120, 200, 171, 31));
        lineEdit_passwd->setFont(font);
        btnRegister = new QPushButton(frame);
        btnRegister->setObjectName(QString::fromUtf8("btnRegister"));
        btnRegister->setGeometry(QRect(90, 260, 91, 24));
        labelCover = new QLabel(frame);
        labelCover->setObjectName(QString::fromUtf8("labelCover"));
        labelCover->setGeometry(QRect(90, 50, 250, 50));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        labelCover->setFont(font1);
        labelCover->setAlignment(Qt::AlignCenter);
        btnMin = new QPushButton(frame);
        btnMin->setObjectName(QString::fromUtf8("btnMin"));
        btnMin->setGeometry(QRect(370, 0, 30, 30));
        btnClose = new QPushButton(frame);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(400, 0, 30, 30));
        btnLogin = new QPushButton(frame);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(220, 260, 101, 24));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Form", nullptr));
        lineEdit_count->setPlaceholderText(QCoreApplication::translate("login", "Count", nullptr));
        lineEdit_passwd->setPlaceholderText(QCoreApplication::translate("login", "Password", nullptr));
        btnRegister->setText(QCoreApplication::translate("login", "\346\263\250\345\206\214", nullptr));
        labelCover->setText(QCoreApplication::translate("login", "\345\214\273\351\231\242\344\275\217\351\231\242\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        btnMin->setText(QString());
        btnClose->setText(QString());
        btnLogin->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
