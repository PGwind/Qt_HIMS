/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminWindow
{
public:
    QAction *actAdd;
    QAction *actModify;
    QAction *actDelete;
    QAction *actSave;
    QAction *actRevert;
    QAction *actPwd;
    QWidget *centralwidget;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *adminWindow)
    {
        if (adminWindow->objectName().isEmpty())
            adminWindow->setObjectName(QString::fromUtf8("adminWindow"));
        adminWindow->resize(861, 534);
        actAdd = new QAction(adminWindow);
        actAdd->setObjectName(QString::fromUtf8("actAdd"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/icons/addUser.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAdd->setIcon(icon);
        actModify = new QAction(adminWindow);
        actModify->setObjectName(QString::fromUtf8("actModify"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images/icons/modify.png"), QSize(), QIcon::Normal, QIcon::Off);
        actModify->setIcon(icon1);
        actDelete = new QAction(adminWindow);
        actDelete->setObjectName(QString::fromUtf8("actDelete"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/images/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actDelete->setIcon(icon2);
        actSave = new QAction(adminWindow);
        actSave->setObjectName(QString::fromUtf8("actSave"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/images/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actSave->setIcon(icon3);
        actRevert = new QAction(adminWindow);
        actRevert->setObjectName(QString::fromUtf8("actRevert"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/images/icons/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actRevert->setIcon(icon4);
        actPwd = new QAction(adminWindow);
        actPwd->setObjectName(QString::fromUtf8("actPwd"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/images/icons/passwd.png"), QSize(), QIcon::Normal, QIcon::Off);
        actPwd->setIcon(icon5);
        centralwidget = new QWidget(adminWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 861, 431));
        adminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(adminWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 861, 21));
        adminWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(adminWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        adminWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(adminWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        adminWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actAdd);
        toolBar->addAction(actModify);
        toolBar->addAction(actDelete);
        toolBar->addAction(actRevert);
        toolBar->addAction(actSave);
        toolBar->addSeparator();
        toolBar->addAction(actPwd);

        retranslateUi(adminWindow);

        QMetaObject::connectSlotsByName(adminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *adminWindow)
    {
        adminWindow->setWindowTitle(QCoreApplication::translate("adminWindow", "MainWindow", nullptr));
        actAdd->setText(QCoreApplication::translate("adminWindow", "\346\267\273\345\212\240\347\224\250\346\210\267", nullptr));
#if QT_CONFIG(tooltip)
        actAdd->setToolTip(QCoreApplication::translate("adminWindow", "\346\267\273\345\212\240", nullptr));
#endif // QT_CONFIG(tooltip)
        actModify->setText(QCoreApplication::translate("adminWindow", "\344\277\256\346\224\271\347\224\250\346\210\267", nullptr));
#if QT_CONFIG(tooltip)
        actModify->setToolTip(QCoreApplication::translate("adminWindow", "\344\277\256\346\224\271", nullptr));
#endif // QT_CONFIG(tooltip)
        actDelete->setText(QCoreApplication::translate("adminWindow", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
#if QT_CONFIG(tooltip)
        actDelete->setToolTip(QCoreApplication::translate("adminWindow", "\345\210\240\351\231\244", nullptr));
#endif // QT_CONFIG(tooltip)
        actSave->setText(QCoreApplication::translate("adminWindow", "\344\277\235\345\255\230\344\277\256\346\224\271", nullptr));
#if QT_CONFIG(tooltip)
        actSave->setToolTip(QCoreApplication::translate("adminWindow", "\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
        actRevert->setText(QCoreApplication::translate("adminWindow", "\346\222\244\345\233\236\344\277\256\346\224\271", nullptr));
#if QT_CONFIG(tooltip)
        actRevert->setToolTip(QCoreApplication::translate("adminWindow", "\346\222\244\345\233\236", nullptr));
#endif // QT_CONFIG(tooltip)
        actPwd->setText(QCoreApplication::translate("adminWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
#if QT_CONFIG(tooltip)
        actPwd->setToolTip(QCoreApplication::translate("adminWindow", "\344\277\256\346\224\271", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBar->setWindowTitle(QCoreApplication::translate("adminWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminWindow: public Ui_adminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
