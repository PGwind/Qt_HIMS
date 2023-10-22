/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actAdd;
    QAction *actModify;
    QAction *actDelete;
    QAction *actRevert;
    QAction *actSave;
    QAction *actPwd;
    QWidget *centralwidget;
    QTableView *tableView;
    QMenuBar *menubar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actAdd = new QAction(MainWindow);
        actAdd->setObjectName(QString::fromUtf8("actAdd"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/icons/addUser.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAdd->setIcon(icon);
        actModify = new QAction(MainWindow);
        actModify->setObjectName(QString::fromUtf8("actModify"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images/icons/modify.png"), QSize(), QIcon::Normal, QIcon::Off);
        actModify->setIcon(icon1);
        actDelete = new QAction(MainWindow);
        actDelete->setObjectName(QString::fromUtf8("actDelete"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/images/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actDelete->setIcon(icon2);
        actRevert = new QAction(MainWindow);
        actRevert->setObjectName(QString::fromUtf8("actRevert"));
        actSave = new QAction(MainWindow);
        actSave->setObjectName(QString::fromUtf8("actSave"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/images/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actSave->setIcon(icon3);
        actPwd = new QAction(MainWindow);
        actPwd->setObjectName(QString::fromUtf8("actPwd"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/images/icons/passwd.png"), QSize(), QIcon::Normal, QIcon::Off);
        actPwd->setIcon(icon4);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 801, 491));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actAdd);
        toolBar->addAction(actModify);
        toolBar->addAction(actDelete);
        toolBar->addSeparator();
        toolBar->addAction(actPwd);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actAdd->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\224\250\346\210\267", nullptr));
#if QT_CONFIG(tooltip)
        actAdd->setToolTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\224\250\346\210\267", nullptr));
#endif // QT_CONFIG(tooltip)
        actModify->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
#if QT_CONFIG(tooltip)
        actModify->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
#endif // QT_CONFIG(tooltip)
        actDelete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
#if QT_CONFIG(tooltip)
        actDelete->setToolTip(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
#endif // QT_CONFIG(tooltip)
        actRevert->setText(QCoreApplication::translate("MainWindow", "\346\222\244\345\233\236\344\277\256\346\224\271", nullptr));
#if QT_CONFIG(tooltip)
        actRevert->setToolTip(QCoreApplication::translate("MainWindow", "\346\222\244\345\233\236\344\277\256\346\224\271", nullptr));
#endif // QT_CONFIG(tooltip)
        actSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\344\277\256\346\224\271", nullptr));
#if QT_CONFIG(tooltip)
        actSave->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\344\277\256\346\224\271", nullptr));
#endif // QT_CONFIG(tooltip)
        actPwd->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
#if QT_CONFIG(tooltip)
        actPwd->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
