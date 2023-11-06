QT += core gui
QT += sql
QT += charts
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminwindow.cpp \
    aidialog.cpp \
    dialog.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    statistics.cpp \
    userwindow.cpp

HEADERS += \
    adminwindow.h \
    aidialog.h \
    dialog.h \
    login.h \
    mainwindow.h \
    statistics.h \
    userwindow.h

FORMS += \
    adminwindow.ui \
    aidialog.ui \
    dialog.ui \
    login.ui \
    mainwindow.ui \
    statistics.ui \
    userwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    style.qrc

DISTFILES +=

RC_ICONS += hims.ico
TARGET = HIMS

