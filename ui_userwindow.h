/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userwindow
{
public:
    QAction *actClear;
    QAction *actPhoto;
    QAction *actModify;
    QAction *actSave;
    QAction *actCancel;
    QWidget *centralwidget;
    QLabel *label_photo;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_3;
    QLabel *label_id;
    QLineEdit *lineEdit_2;
    QLabel *label_name;
    QLabel *label_age;
    QLabel *label_sex;
    QLineEdit *lineEdit_3;
    QSpinBox *spinBox;
    QComboBox *comboBox_5;
    QGroupBox *groupBox_4;
    QLabel *label_attending;
    QLabel *label_department;
    QLineEdit *lineEdit_attending;
    QComboBox *comboBox_department;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QComboBox *comboBox_build;
    QLabel *label_build;
    QLabel *label_room;
    QLabel *label_bed;
    QComboBox *comboBox_bed;
    QLineEdit *lineEdit_room;
    QGroupBox *groupBox_2;
    QLabel *label_inpatients;
    QLabel *label_discharge;
    QLabel *label_note;
    QDateEdit *dateEdit_inpatients;
    QDateEdit *dateEdit_discharge;
    QTextEdit *textEdit_note;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBarUser;

    void setupUi(QMainWindow *userwindow)
    {
        if (userwindow->objectName().isEmpty())
            userwindow->setObjectName(QString::fromUtf8("userwindow"));
        userwindow->resize(800, 600);
        userwindow->setMinimumSize(QSize(800, 600));
        userwindow->setMaximumSize(QSize(800, 600));
        actClear = new QAction(userwindow);
        actClear->setObjectName(QString::fromUtf8("actClear"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/icons/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actClear->setIcon(icon);
        actPhoto = new QAction(userwindow);
        actPhoto->setObjectName(QString::fromUtf8("actPhoto"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images/icons/picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        actPhoto->setIcon(icon1);
        actModify = new QAction(userwindow);
        actModify->setObjectName(QString::fromUtf8("actModify"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/images/icons/modify.png"), QSize(), QIcon::Normal, QIcon::Off);
        actModify->setIcon(icon2);
        actSave = new QAction(userwindow);
        actSave->setObjectName(QString::fromUtf8("actSave"));
        actSave->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/images/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actSave->setIcon(icon3);
        actCancel = new QAction(userwindow);
        actCancel->setObjectName(QString::fromUtf8("actCancel"));
        actCancel->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/images/icons/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actCancel->setIcon(icon4);
        centralwidget = new QWidget(userwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_photo = new QLabel(centralwidget);
        label_photo->setObjectName(QString::fromUtf8("label_photo"));
        label_photo->setGeometry(QRect(20, 40, 181, 181));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(220, 30, 561, 191));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        label_id = new QLabel(groupBox_3);
        label_id->setObjectName(QString::fromUtf8("label_id"));
        label_id->setGeometry(QRect(20, 30, 50, 30));
        QFont font;
        font.setPointSize(14);
        label_id->setFont(font);
        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 30, 171, 31));
        label_name = new QLabel(groupBox_3);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(20, 70, 50, 30));
        label_name->setFont(font);
        label_age = new QLabel(groupBox_3);
        label_age->setObjectName(QString::fromUtf8("label_age"));
        label_age->setGeometry(QRect(20, 120, 50, 30));
        label_age->setFont(font);
        label_sex = new QLabel(groupBox_3);
        label_sex->setObjectName(QString::fromUtf8("label_sex"));
        label_sex->setGeometry(QRect(163, 120, 51, 31));
        label_sex->setFont(font);
        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(100, 70, 171, 31));
        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(80, 120, 61, 31));
        comboBox_5 = new QComboBox(groupBox_3);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(220, 120, 51, 31));

        horizontalLayout_2->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        label_attending = new QLabel(groupBox_4);
        label_attending->setObjectName(QString::fromUtf8("label_attending"));
        label_attending->setGeometry(QRect(10, 40, 90, 30));
        label_attending->setFont(font);
        label_department = new QLabel(groupBox_4);
        label_department->setObjectName(QString::fromUtf8("label_department"));
        label_department->setGeometry(QRect(10, 110, 90, 30));
        label_department->setFont(font);
        lineEdit_attending = new QLineEdit(groupBox_4);
        lineEdit_attending->setObjectName(QString::fromUtf8("lineEdit_attending"));
        lineEdit_attending->setGeometry(QRect(110, 40, 161, 31));
        comboBox_department = new QComboBox(groupBox_4);
        comboBox_department->setObjectName(QString::fromUtf8("comboBox_department"));
        comboBox_department->setGeometry(QRect(110, 110, 161, 31));

        horizontalLayout_2->addWidget(groupBox_4);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(9, 255, 781, 241));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(350, 16777215));
        comboBox_build = new QComboBox(groupBox);
        comboBox_build->setObjectName(QString::fromUtf8("comboBox_build"));
        comboBox_build->setGeometry(QRect(130, 40, 171, 31));
        label_build = new QLabel(groupBox);
        label_build->setObjectName(QString::fromUtf8("label_build"));
        label_build->setGeometry(QRect(40, 30, 70, 40));
        label_build->setFont(font);
        label_room = new QLabel(groupBox);
        label_room->setObjectName(QString::fromUtf8("label_room"));
        label_room->setGeometry(QRect(40, 100, 70, 40));
        QFont font1;
        font1.setPointSize(15);
        label_room->setFont(font1);
        label_bed = new QLabel(groupBox);
        label_bed->setObjectName(QString::fromUtf8("label_bed"));
        label_bed->setGeometry(QRect(40, 170, 71, 31));
        label_bed->setFont(font1);
        comboBox_bed = new QComboBox(groupBox);
        comboBox_bed->setObjectName(QString::fromUtf8("comboBox_bed"));
        comboBox_bed->setGeometry(QRect(130, 170, 171, 31));
        lineEdit_room = new QLineEdit(groupBox);
        lineEdit_room->setObjectName(QString::fromUtf8("lineEdit_room"));
        lineEdit_room->setGeometry(QRect(130, 110, 171, 31));

        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        label_inpatients = new QLabel(groupBox_2);
        label_inpatients->setObjectName(QString::fromUtf8("label_inpatients"));
        label_inpatients->setGeometry(QRect(30, 40, 90, 30));
        label_inpatients->setFont(font1);
        label_discharge = new QLabel(groupBox_2);
        label_discharge->setObjectName(QString::fromUtf8("label_discharge"));
        label_discharge->setGeometry(QRect(30, 80, 90, 30));
        label_discharge->setFont(font1);
        label_note = new QLabel(groupBox_2);
        label_note->setObjectName(QString::fromUtf8("label_note"));
        label_note->setGeometry(QRect(30, 150, 51, 41));
        label_note->setFont(font);
        dateEdit_inpatients = new QDateEdit(groupBox_2);
        dateEdit_inpatients->setObjectName(QString::fromUtf8("dateEdit_inpatients"));
        dateEdit_inpatients->setGeometry(QRect(160, 30, 161, 31));
        dateEdit_discharge = new QDateEdit(groupBox_2);
        dateEdit_discharge->setObjectName(QString::fromUtf8("dateEdit_discharge"));
        dateEdit_discharge->setGeometry(QRect(160, 80, 161, 31));
        textEdit_note = new QTextEdit(groupBox_2);
        textEdit_note->setObjectName(QString::fromUtf8("textEdit_note"));
        textEdit_note->setGeometry(QRect(100, 129, 311, 81));

        horizontalLayout->addWidget(groupBox_2);

        userwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(userwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        userwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(userwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        userwindow->setStatusBar(statusbar);
        toolBarUser = new QToolBar(userwindow);
        toolBarUser->setObjectName(QString::fromUtf8("toolBarUser"));
        toolBarUser->setEnabled(true);
        toolBarUser->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        userwindow->addToolBar(Qt::TopToolBarArea, toolBarUser);

        toolBarUser->addAction(actClear);
        toolBarUser->addAction(actPhoto);
        toolBarUser->addSeparator();
        toolBarUser->addAction(actModify);
        toolBarUser->addAction(actSave);
        toolBarUser->addAction(actCancel);
        toolBarUser->addSeparator();

        retranslateUi(userwindow);

        QMetaObject::connectSlotsByName(userwindow);
    } // setupUi

    void retranslateUi(QMainWindow *userwindow)
    {
        userwindow->setWindowTitle(QCoreApplication::translate("userwindow", "MainWindow", nullptr));
        actClear->setText(QCoreApplication::translate("userwindow", "\346\270\205\351\231\244\345\244\264\345\203\217", nullptr));
#if QT_CONFIG(tooltip)
        actClear->setToolTip(QCoreApplication::translate("userwindow", "\346\270\205\351\231\244\345\244\264\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actPhoto->setText(QCoreApplication::translate("userwindow", "\350\256\276\347\275\256\347\205\247\347\211\207", nullptr));
#if QT_CONFIG(tooltip)
        actPhoto->setToolTip(QCoreApplication::translate("userwindow", "\350\256\276\347\275\256\347\205\247\347\211\207", nullptr));
#endif // QT_CONFIG(tooltip)
        actModify->setText(QCoreApplication::translate("userwindow", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
#if QT_CONFIG(tooltip)
        actModify->setToolTip(QCoreApplication::translate("userwindow", "\344\277\256\346\224\271", nullptr));
#endif // QT_CONFIG(tooltip)
        actSave->setText(QCoreApplication::translate("userwindow", "\344\277\235\345\255\230\344\277\256\346\224\271", nullptr));
#if QT_CONFIG(tooltip)
        actSave->setToolTip(QCoreApplication::translate("userwindow", "\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
        actCancel->setText(QCoreApplication::translate("userwindow", "\345\217\226\346\266\210\344\277\256\346\224\271", nullptr));
#if QT_CONFIG(tooltip)
        actCancel->setToolTip(QCoreApplication::translate("userwindow", "\345\217\226\346\266\210\344\277\256\346\224\271", nullptr));
#endif // QT_CONFIG(tooltip)
        label_photo->setText(QCoreApplication::translate("userwindow", "TextLabel", nullptr));
        groupBox_3->setTitle(QString());
        label_id->setText(QCoreApplication::translate("userwindow", "\347\274\226\345\217\267", nullptr));
        label_name->setText(QCoreApplication::translate("userwindow", "\345\247\223\345\220\215", nullptr));
        label_age->setText(QCoreApplication::translate("userwindow", "\345\271\264\351\276\204", nullptr));
        label_sex->setText(QCoreApplication::translate("userwindow", "\346\200\247\345\210\253", nullptr));
        groupBox_4->setTitle(QString());
        label_attending->setText(QCoreApplication::translate("userwindow", "\344\270\273\346\262\273\345\214\273\345\270\210", nullptr));
        label_department->setText(QCoreApplication::translate("userwindow", "\347\247\221\345\256\244", nullptr));
        groupBox->setTitle(QString());
        label_build->setText(QCoreApplication::translate("userwindow", "\344\275\217\351\231\242\346\245\274", nullptr));
        label_room->setText(QCoreApplication::translate("userwindow", "\347\227\205\346\210\277", nullptr));
        label_bed->setText(QCoreApplication::translate("userwindow", "\347\227\205\345\272\212", nullptr));
        groupBox_2->setTitle(QString());
        label_inpatients->setText(QCoreApplication::translate("userwindow", "\345\205\245\351\231\242\346\227\266\351\227\264", nullptr));
        label_discharge->setText(QCoreApplication::translate("userwindow", "\345\207\272\351\231\242\346\227\266\351\227\264", nullptr));
        label_note->setText(QCoreApplication::translate("userwindow", "\345\244\207\346\263\250", nullptr));
        toolBarUser->setWindowTitle(QCoreApplication::translate("userwindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userwindow: public Ui_userwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
