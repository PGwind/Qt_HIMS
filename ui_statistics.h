/********************************************************************************
** Form generated from reading UI file 'statistics.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICS_H
#define UI_STATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Statistics
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *Statistics)
    {
        if (Statistics->objectName().isEmpty())
            Statistics->setObjectName(QString::fromUtf8("Statistics"));
        Statistics->resize(800, 600);
        centralwidget = new QWidget(Statistics);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Statistics->setCentralWidget(centralwidget);

        retranslateUi(Statistics);

        QMetaObject::connectSlotsByName(Statistics);
    } // setupUi

    void retranslateUi(QMainWindow *Statistics)
    {
        Statistics->setWindowTitle(QCoreApplication::translate("Statistics", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Statistics: public Ui_Statistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICS_H
