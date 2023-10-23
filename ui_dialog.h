/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton_setPhoto;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_Cancel;
    QFrame *frame;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_name;
    QSpinBox *spinBox_age;
    QLineEdit *lineEdit_id;
    QComboBox *comboBox_gender;
    QLabel *label_name;
    QLabel *label_age;
    QLabel *label_id;
    QLabel *label_gender;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_idNumber;
    QLineEdit *lineEdit_idNumber;
    QLabel *label_address;
    QLineEdit *lineEdit_address;
    QLabel *label_contact;
    QLineEdit *lineEdit_contact;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_deparment;
    QComboBox *comboBox_department;
    QLabel *label_build;
    QComboBox *comboBox_build;
    QLabel *label_room;
    QLineEdit *lineEdit_room;
    QLabel *label_bed;
    QComboBox *comboBox_bed;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QLabel *label_attending;
    QLineEdit *lineEdit_attend;
    QLabel *label_admission;
    QDateEdit *dateEdit_admission;
    QLabel *label_discharge;
    QDateEdit *dateEdit_discharge;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_deparment_2;
    QTextEdit *textEdit_note;
    QLabel *label_photo;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(844, 553);
        pushButton_setPhoto = new QPushButton(Dialog);
        pushButton_setPhoto->setObjectName(QString::fromUtf8("pushButton_setPhoto"));
        pushButton_setPhoto->setGeometry(QRect(10, 10, 80, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/icons/picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_setPhoto->setIcon(icon);
        pushButton_clear = new QPushButton(Dialog);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(110, 10, 90, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_clear->setIcon(icon1);
        pushButton_OK = new QPushButton(Dialog);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(650, 10, 80, 30));
        pushButton_Cancel = new QPushButton(Dialog);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(750, 10, 80, 30));
        frame = new QFrame(Dialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-10, 50, 861, 511));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(210, 10, 301, 181));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_name = new QLineEdit(groupBox);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 1, 3, 1, 3);

        spinBox_age = new QSpinBox(groupBox);
        spinBox_age->setObjectName(QString::fromUtf8("spinBox_age"));

        gridLayout->addWidget(spinBox_age, 2, 2, 1, 1);

        lineEdit_id = new QLineEdit(groupBox);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));

        gridLayout->addWidget(lineEdit_id, 0, 3, 1, 3);

        comboBox_gender = new QComboBox(groupBox);
        comboBox_gender->setObjectName(QString::fromUtf8("comboBox_gender"));

        gridLayout->addWidget(comboBox_gender, 2, 5, 1, 1);

        label_name = new QLabel(groupBox);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        QFont font;
        font.setPointSize(14);
        label_name->setFont(font);

        gridLayout->addWidget(label_name, 1, 0, 1, 1);

        label_age = new QLabel(groupBox);
        label_age->setObjectName(QString::fromUtf8("label_age"));
        label_age->setFont(font);

        gridLayout->addWidget(label_age, 2, 0, 1, 1);

        label_id = new QLabel(groupBox);
        label_id->setObjectName(QString::fromUtf8("label_id"));
        label_id->setFont(font);

        gridLayout->addWidget(label_id, 0, 0, 1, 1);

        label_gender = new QLabel(groupBox);
        label_gender->setObjectName(QString::fromUtf8("label_gender"));
        label_gender->setFont(font);

        gridLayout->addWidget(label_gender, 2, 4, 1, 1);

        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(540, 20, 301, 171));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_idNumber = new QLabel(groupBox_2);
        label_idNumber->setObjectName(QString::fromUtf8("label_idNumber"));
        label_idNumber->setFont(font);

        gridLayout_2->addWidget(label_idNumber, 0, 0, 1, 1);

        lineEdit_idNumber = new QLineEdit(groupBox_2);
        lineEdit_idNumber->setObjectName(QString::fromUtf8("lineEdit_idNumber"));

        gridLayout_2->addWidget(lineEdit_idNumber, 0, 1, 1, 1);

        label_address = new QLabel(groupBox_2);
        label_address->setObjectName(QString::fromUtf8("label_address"));
        label_address->setFont(font);

        gridLayout_2->addWidget(label_address, 1, 0, 1, 1);

        lineEdit_address = new QLineEdit(groupBox_2);
        lineEdit_address->setObjectName(QString::fromUtf8("lineEdit_address"));

        gridLayout_2->addWidget(lineEdit_address, 1, 1, 1, 1);

        label_contact = new QLabel(groupBox_2);
        label_contact->setObjectName(QString::fromUtf8("label_contact"));
        label_contact->setFont(font);

        gridLayout_2->addWidget(label_contact, 2, 0, 1, 1);

        lineEdit_contact = new QLineEdit(groupBox_2);
        lineEdit_contact->setObjectName(QString::fromUtf8("lineEdit_contact"));

        gridLayout_2->addWidget(lineEdit_contact, 2, 1, 1, 1);

        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(40, 200, 201, 291));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_deparment = new QLabel(groupBox_3);
        label_deparment->setObjectName(QString::fromUtf8("label_deparment"));
        label_deparment->setFont(font);

        gridLayout_4->addWidget(label_deparment, 0, 0, 1, 1);

        comboBox_department = new QComboBox(groupBox_3);
        comboBox_department->setObjectName(QString::fromUtf8("comboBox_department"));

        gridLayout_4->addWidget(comboBox_department, 0, 1, 1, 1);

        label_build = new QLabel(groupBox_3);
        label_build->setObjectName(QString::fromUtf8("label_build"));
        label_build->setFont(font);

        gridLayout_4->addWidget(label_build, 1, 0, 1, 1);

        comboBox_build = new QComboBox(groupBox_3);
        comboBox_build->setObjectName(QString::fromUtf8("comboBox_build"));

        gridLayout_4->addWidget(comboBox_build, 1, 1, 1, 1);

        label_room = new QLabel(groupBox_3);
        label_room->setObjectName(QString::fromUtf8("label_room"));
        label_room->setFont(font);

        gridLayout_4->addWidget(label_room, 2, 0, 1, 1);

        lineEdit_room = new QLineEdit(groupBox_3);
        lineEdit_room->setObjectName(QString::fromUtf8("lineEdit_room"));

        gridLayout_4->addWidget(lineEdit_room, 2, 1, 1, 1);

        label_bed = new QLabel(groupBox_3);
        label_bed->setObjectName(QString::fromUtf8("label_bed"));
        label_bed->setFont(font);

        gridLayout_4->addWidget(label_bed, 3, 0, 1, 1);

        comboBox_bed = new QComboBox(groupBox_3);
        comboBox_bed->setObjectName(QString::fromUtf8("comboBox_bed"));

        gridLayout_4->addWidget(comboBox_bed, 3, 1, 1, 1);

        groupBox_4 = new QGroupBox(frame);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(310, 200, 281, 291));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_attending = new QLabel(groupBox_4);
        label_attending->setObjectName(QString::fromUtf8("label_attending"));
        label_attending->setFont(font);

        gridLayout_5->addWidget(label_attending, 0, 0, 1, 1);

        lineEdit_attend = new QLineEdit(groupBox_4);
        lineEdit_attend->setObjectName(QString::fromUtf8("lineEdit_attend"));

        gridLayout_5->addWidget(lineEdit_attend, 0, 1, 1, 1);

        label_admission = new QLabel(groupBox_4);
        label_admission->setObjectName(QString::fromUtf8("label_admission"));
        label_admission->setFont(font);

        gridLayout_5->addWidget(label_admission, 1, 0, 1, 1);

        dateEdit_admission = new QDateEdit(groupBox_4);
        dateEdit_admission->setObjectName(QString::fromUtf8("dateEdit_admission"));

        gridLayout_5->addWidget(dateEdit_admission, 1, 1, 1, 1);

        label_discharge = new QLabel(groupBox_4);
        label_discharge->setObjectName(QString::fromUtf8("label_discharge"));
        label_discharge->setFont(font);

        gridLayout_5->addWidget(label_discharge, 2, 0, 1, 1);

        dateEdit_discharge = new QDateEdit(groupBox_4);
        dateEdit_discharge->setObjectName(QString::fromUtf8("dateEdit_discharge"));

        gridLayout_5->addWidget(dateEdit_discharge, 2, 1, 1, 1);

        groupBox_5 = new QGroupBox(frame);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(630, 200, 181, 291));
        verticalLayout = new QVBoxLayout(groupBox_5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_deparment_2 = new QLabel(groupBox_5);
        label_deparment_2->setObjectName(QString::fromUtf8("label_deparment_2"));
        label_deparment_2->setFont(font);

        verticalLayout->addWidget(label_deparment_2);

        textEdit_note = new QTextEdit(groupBox_5);
        textEdit_note->setObjectName(QString::fromUtf8("textEdit_note"));

        verticalLayout->addWidget(textEdit_note);

        label_photo = new QLabel(frame);
        label_photo->setObjectName(QString::fromUtf8("label_photo"));
        label_photo->setGeometry(QRect(50, 30, 120, 120));

        retranslateUi(Dialog);
        QObject::connect(pushButton_OK, &QPushButton::clicked, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(pushButton_Cancel, &QPushButton::clicked, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton_setPhoto->setText(QCoreApplication::translate("Dialog", "\350\256\276\347\275\256\347\205\247\347\211\207", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("Dialog", "\346\270\205\351\231\244\347\205\247\347\211\207", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("Dialog", "\347\241\256\345\256\232", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("Dialog", "\345\217\226\346\266\210", nullptr));
        groupBox->setTitle(QString());
        label_name->setText(QCoreApplication::translate("Dialog", "\345\247\223\345\220\215", nullptr));
        label_age->setText(QCoreApplication::translate("Dialog", "\345\271\264\351\276\204", nullptr));
        label_id->setText(QCoreApplication::translate("Dialog", "\347\274\226\345\217\267", nullptr));
        label_gender->setText(QCoreApplication::translate("Dialog", "\346\200\247\345\210\253", nullptr));
        groupBox_2->setTitle(QString());
        label_idNumber->setText(QCoreApplication::translate("Dialog", "\350\272\253\344\273\275\350\257\201", nullptr));
        label_address->setText(QCoreApplication::translate("Dialog", "\344\275\217\345\235\200", nullptr));
        label_contact->setText(QCoreApplication::translate("Dialog", "\350\201\224\347\263\273\346\226\271\345\274\217", nullptr));
        groupBox_3->setTitle(QString());
        label_deparment->setText(QCoreApplication::translate("Dialog", "\347\247\221\345\256\244", nullptr));
        label_build->setText(QCoreApplication::translate("Dialog", "\344\275\217\351\231\242\346\245\274", nullptr));
        label_room->setText(QCoreApplication::translate("Dialog", "\347\227\205\346\210\277", nullptr));
        label_bed->setText(QCoreApplication::translate("Dialog", "\345\272\212\345\217\267", nullptr));
        groupBox_4->setTitle(QString());
        label_attending->setText(QCoreApplication::translate("Dialog", "\344\270\273\346\262\273\345\214\273\345\270\210", nullptr));
        label_admission->setText(QCoreApplication::translate("Dialog", "\345\205\245\351\231\242\346\227\266\351\227\264", nullptr));
        label_discharge->setText(QCoreApplication::translate("Dialog", "\345\207\272\351\231\242\346\227\266\351\227\264", nullptr));
        groupBox_5->setTitle(QString());
        label_deparment_2->setText(QCoreApplication::translate("Dialog", "\345\244\207\346\263\250", nullptr));
        label_photo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
