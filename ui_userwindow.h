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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userwindow
{
public:
    QAction *actClear;
    QAction *actPhoto;
    QAction *actModify;
    QAction *actSave;
    QAction *actPwd;
    QWidget *centralwidget;
    QLabel *label_photo;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QLabel *label_idNumber;
    QLineEdit *lineEdit_idNumber;
    QLabel *label_address;
    QLabel *label_contact;
    QLineEdit *lineEdit_contact;
    QLineEdit *lineEdit_address;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *label_name;
    QLabel *label_id;
    QLabel *label_age;
    QLabel *label_sex;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox_sex;
    QSpinBox *spinBox_age;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_4;
    QLabel *label_attending;
    QLineEdit *lineEdit_attending;
    QLabel *label_inpatients;
    QDateEdit *dateEdit_inpatients;
    QLabel *label_discharge;
    QDateEdit *dateEdit_discharge;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_department;
    QComboBox *comboBox_department;
    QLabel *label_build;
    QComboBox *comboBox_build;
    QLabel *label_room;
    QLineEdit *lineEdit_room;
    QLabel *label_bed;
    QComboBox *comboBox_bed;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_note;
    QTextEdit *textEdit_note;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBarUser;

    void setupUi(QMainWindow *userwindow)
    {
        if (userwindow->objectName().isEmpty())
            userwindow->setObjectName(QString::fromUtf8("userwindow"));
        userwindow->setEnabled(true);
        userwindow->resize(800, 550);
        userwindow->setMinimumSize(QSize(800, 520));
        userwindow->setMaximumSize(QSize(800, 550));
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
        actPwd = new QAction(userwindow);
        actPwd->setObjectName(QString::fromUtf8("actPwd"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/images/icons/passwd.png"), QSize(), QIcon::Normal, QIcon::Off);
        actPwd->setIcon(icon4);
        centralwidget = new QWidget(userwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_photo = new QLabel(centralwidget);
        label_photo->setObjectName(QString::fromUtf8("label_photo"));
        label_photo->setGeometry(QRect(20, 50, 120, 120));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(480, 10, 301, 221));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_idNumber = new QLabel(groupBox_4);
        label_idNumber->setObjectName(QString::fromUtf8("label_idNumber"));
        QFont font;
        font.setPointSize(14);
        label_idNumber->setFont(font);

        gridLayout_3->addWidget(label_idNumber, 0, 0, 1, 1);

        lineEdit_idNumber = new QLineEdit(groupBox_4);
        lineEdit_idNumber->setObjectName(QString::fromUtf8("lineEdit_idNumber"));

        gridLayout_3->addWidget(lineEdit_idNumber, 0, 2, 1, 1);

        label_address = new QLabel(groupBox_4);
        label_address->setObjectName(QString::fromUtf8("label_address"));
        label_address->setFont(font);

        gridLayout_3->addWidget(label_address, 1, 0, 1, 1);

        label_contact = new QLabel(groupBox_4);
        label_contact->setObjectName(QString::fromUtf8("label_contact"));
        label_contact->setFont(font);

        gridLayout_3->addWidget(label_contact, 2, 0, 1, 2);

        lineEdit_contact = new QLineEdit(groupBox_4);
        lineEdit_contact->setObjectName(QString::fromUtf8("lineEdit_contact"));

        gridLayout_3->addWidget(lineEdit_contact, 2, 2, 1, 1);

        lineEdit_address = new QLineEdit(groupBox_4);
        lineEdit_address->setObjectName(QString::fromUtf8("lineEdit_address"));

        gridLayout_3->addWidget(lineEdit_address, 1, 2, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(170, 10, 291, 221));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_name = new QLabel(groupBox_3);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setFont(font);

        gridLayout_2->addWidget(label_name, 1, 0, 1, 1);

        label_id = new QLabel(groupBox_3);
        label_id->setObjectName(QString::fromUtf8("label_id"));
        label_id->setFont(font);

        gridLayout_2->addWidget(label_id, 0, 0, 1, 1);

        label_age = new QLabel(groupBox_3);
        label_age->setObjectName(QString::fromUtf8("label_age"));
        label_age->setFont(font);

        gridLayout_2->addWidget(label_age, 2, 0, 1, 1);

        label_sex = new QLabel(groupBox_3);
        label_sex->setObjectName(QString::fromUtf8("label_sex"));
        label_sex->setFont(font);

        gridLayout_2->addWidget(label_sex, 2, 2, 1, 1);

        lineEdit_id = new QLineEdit(groupBox_3);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));

        gridLayout_2->addWidget(lineEdit_id, 0, 2, 1, 2);

        lineEdit_name = new QLineEdit(groupBox_3);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        gridLayout_2->addWidget(lineEdit_name, 1, 2, 1, 2);

        comboBox_sex = new QComboBox(groupBox_3);
        comboBox_sex->setObjectName(QString::fromUtf8("comboBox_sex"));
        comboBox_sex->setEnabled(true);

        gridLayout_2->addWidget(comboBox_sex, 2, 3, 1, 1);

        spinBox_age = new QSpinBox(groupBox_3);
        spinBox_age->setObjectName(QString::fromUtf8("spinBox_age"));
        spinBox_age->setMaximum(120);

        gridLayout_2->addWidget(spinBox_age, 2, 1, 1, 1);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(240, 260, 301, 201));
        gridLayout_4 = new QGridLayout(groupBox_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_attending = new QLabel(groupBox_5);
        label_attending->setObjectName(QString::fromUtf8("label_attending"));
        label_attending->setFont(font);

        gridLayout_4->addWidget(label_attending, 0, 0, 1, 1);

        lineEdit_attending = new QLineEdit(groupBox_5);
        lineEdit_attending->setObjectName(QString::fromUtf8("lineEdit_attending"));

        gridLayout_4->addWidget(lineEdit_attending, 0, 1, 1, 1);

        label_inpatients = new QLabel(groupBox_5);
        label_inpatients->setObjectName(QString::fromUtf8("label_inpatients"));
        QFont font1;
        font1.setPointSize(15);
        label_inpatients->setFont(font1);

        gridLayout_4->addWidget(label_inpatients, 1, 0, 1, 1);

        dateEdit_inpatients = new QDateEdit(groupBox_5);
        dateEdit_inpatients->setObjectName(QString::fromUtf8("dateEdit_inpatients"));

        gridLayout_4->addWidget(dateEdit_inpatients, 1, 1, 1, 1);

        label_discharge = new QLabel(groupBox_5);
        label_discharge->setObjectName(QString::fromUtf8("label_discharge"));
        label_discharge->setFont(font1);

        gridLayout_4->addWidget(label_discharge, 2, 0, 1, 1);

        dateEdit_discharge = new QDateEdit(groupBox_5);
        dateEdit_discharge->setObjectName(QString::fromUtf8("dateEdit_discharge"));

        gridLayout_4->addWidget(dateEdit_discharge, 2, 1, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 260, 211, 201));
        groupBox->setMaximumSize(QSize(350, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_department = new QLabel(groupBox);
        label_department->setObjectName(QString::fromUtf8("label_department"));
        label_department->setFont(font);

        gridLayout->addWidget(label_department, 0, 0, 1, 1);

        comboBox_department = new QComboBox(groupBox);
        comboBox_department->setObjectName(QString::fromUtf8("comboBox_department"));
        comboBox_department->setEnabled(true);

        gridLayout->addWidget(comboBox_department, 0, 1, 1, 1);

        label_build = new QLabel(groupBox);
        label_build->setObjectName(QString::fromUtf8("label_build"));
        label_build->setFont(font);

        gridLayout->addWidget(label_build, 1, 0, 1, 1);

        comboBox_build = new QComboBox(groupBox);
        comboBox_build->setObjectName(QString::fromUtf8("comboBox_build"));
        comboBox_build->setEnabled(true);

        gridLayout->addWidget(comboBox_build, 1, 1, 1, 1);

        label_room = new QLabel(groupBox);
        label_room->setObjectName(QString::fromUtf8("label_room"));
        label_room->setFont(font1);

        gridLayout->addWidget(label_room, 2, 0, 1, 1);

        lineEdit_room = new QLineEdit(groupBox);
        lineEdit_room->setObjectName(QString::fromUtf8("lineEdit_room"));

        gridLayout->addWidget(lineEdit_room, 2, 1, 1, 1);

        label_bed = new QLabel(groupBox);
        label_bed->setObjectName(QString::fromUtf8("label_bed"));
        label_bed->setFont(font1);

        gridLayout->addWidget(label_bed, 3, 0, 1, 1);

        comboBox_bed = new QComboBox(groupBox);
        comboBox_bed->setObjectName(QString::fromUtf8("comboBox_bed"));
        comboBox_bed->setEnabled(true);

        gridLayout->addWidget(comboBox_bed, 3, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(560, 260, 221, 201));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_note = new QLabel(groupBox_2);
        label_note->setObjectName(QString::fromUtf8("label_note"));
        label_note->setFont(font);

        verticalLayout->addWidget(label_note);

        textEdit_note = new QTextEdit(groupBox_2);
        textEdit_note->setObjectName(QString::fromUtf8("textEdit_note"));

        verticalLayout->addWidget(textEdit_note);

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
        toolBarUser->addSeparator();
        toolBarUser->addAction(actPwd);

        retranslateUi(userwindow);

        QMetaObject::connectSlotsByName(userwindow);
    } // setupUi

    void retranslateUi(QMainWindow *userwindow)
    {
        userwindow->setWindowTitle(QCoreApplication::translate("userwindow", "MainWindow", nullptr));
        actClear->setText(QCoreApplication::translate("userwindow", "\346\270\205\351\231\244\347\205\247\347\211\207", nullptr));
#if QT_CONFIG(tooltip)
        actClear->setToolTip(QCoreApplication::translate("userwindow", "\346\270\205\351\231\244\347\205\247\347\211\207", nullptr));
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
        actPwd->setText(QCoreApplication::translate("userwindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
#if QT_CONFIG(tooltip)
        actPwd->setToolTip(QCoreApplication::translate("userwindow", "\344\277\256\346\224\271", nullptr));
#endif // QT_CONFIG(tooltip)
        label_photo->setText(QString());
        groupBox_4->setTitle(QString());
        label_idNumber->setText(QCoreApplication::translate("userwindow", "\350\272\253\344\273\275\350\257\201", nullptr));
        label_address->setText(QCoreApplication::translate("userwindow", "\344\275\217\345\235\200", nullptr));
        label_contact->setText(QCoreApplication::translate("userwindow", "\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        groupBox_3->setTitle(QString());
        label_name->setText(QCoreApplication::translate("userwindow", "\345\247\223\345\220\215", nullptr));
        label_id->setText(QCoreApplication::translate("userwindow", "\347\274\226\345\217\267", nullptr));
        label_age->setText(QCoreApplication::translate("userwindow", "\345\271\264\351\276\204", nullptr));
        label_sex->setText(QCoreApplication::translate("userwindow", "\346\200\247\345\210\253", nullptr));
        groupBox_5->setTitle(QString());
        label_attending->setText(QCoreApplication::translate("userwindow", "\344\270\273\346\262\273\345\214\273\345\270\210", nullptr));
        label_inpatients->setText(QCoreApplication::translate("userwindow", "\345\205\245\351\231\242\346\227\266\351\227\264", nullptr));
        label_discharge->setText(QCoreApplication::translate("userwindow", "\345\207\272\351\231\242\346\227\266\351\227\264", nullptr));
        groupBox->setTitle(QString());
        label_department->setText(QCoreApplication::translate("userwindow", "\347\247\221\345\256\244", nullptr));
        label_build->setText(QCoreApplication::translate("userwindow", "\344\275\217\351\231\242\346\245\274", nullptr));
        label_room->setText(QCoreApplication::translate("userwindow", "\347\227\205\346\210\277", nullptr));
        label_bed->setText(QCoreApplication::translate("userwindow", "\347\227\205\345\272\212", nullptr));
        groupBox_2->setTitle(QString());
        label_note->setText(QCoreApplication::translate("userwindow", "\345\244\207\346\263\250", nullptr));
        toolBarUser->setWindowTitle(QCoreApplication::translate("userwindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userwindow: public Ui_userwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
