/****************************************************************************
** Meta object code from reading C++ file 'adminwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../adminwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_adminWindow_t {
    const uint offsetsAndSize[34];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_adminWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_adminWindow_t qt_meta_stringdata_adminWindow = {
    {
QT_MOC_LITERAL(0, 11), // "adminWindow"
QT_MOC_LITERAL(12, 19), // "searchButtonClicked"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 17), // "do_currentChanged"
QT_MOC_LITERAL(51, 11), // "QModelIndex"
QT_MOC_LITERAL(63, 7), // "current"
QT_MOC_LITERAL(71, 8), // "previous"
QT_MOC_LITERAL(80, 20), // "do_currentRowChanged"
QT_MOC_LITERAL(101, 19), // "on_actAdd_triggered"
QT_MOC_LITERAL(121, 20), // "on_actSave_triggered"
QT_MOC_LITERAL(142, 22), // "on_actDelete_triggered"
QT_MOC_LITERAL(165, 22), // "on_actRevert_triggered"
QT_MOC_LITERAL(188, 20), // "on_tableView_pressed"
QT_MOC_LITERAL(209, 5), // "index"
QT_MOC_LITERAL(215, 22), // "on_actModify_triggered"
QT_MOC_LITERAL(238, 19), // "on_actPwd_triggered"
QT_MOC_LITERAL(258, 26) // "on_tableView_doubleClicked"

    },
    "adminWindow\0searchButtonClicked\0\0"
    "do_currentChanged\0QModelIndex\0current\0"
    "previous\0do_currentRowChanged\0"
    "on_actAdd_triggered\0on_actSave_triggered\0"
    "on_actDelete_triggered\0on_actRevert_triggered\0"
    "on_tableView_pressed\0index\0"
    "on_actModify_triggered\0on_actPwd_triggered\0"
    "on_tableView_doubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_adminWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    2,   81,    2, 0x08,    2 /* Private */,
       7,    2,   86,    2, 0x08,    5 /* Private */,
       8,    0,   91,    2, 0x08,    8 /* Private */,
       9,    0,   92,    2, 0x08,    9 /* Private */,
      10,    0,   93,    2, 0x08,   10 /* Private */,
      11,    0,   94,    2, 0x08,   11 /* Private */,
      12,    1,   95,    2, 0x08,   12 /* Private */,
      14,    0,   98,    2, 0x08,   14 /* Private */,
      15,    0,   99,    2, 0x08,   15 /* Private */,
      16,    1,  100,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,   13,

       0        // eod
};

void adminWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<adminWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->searchButtonClicked(); break;
        case 1: _t->do_currentChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        case 2: _t->do_currentRowChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        case 3: _t->on_actAdd_triggered(); break;
        case 4: _t->on_actSave_triggered(); break;
        case 5: _t->on_actDelete_triggered(); break;
        case 6: _t->on_actRevert_triggered(); break;
        case 7: _t->on_tableView_pressed((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 8: _t->on_actModify_triggered(); break;
        case 9: _t->on_actPwd_triggered(); break;
        case 10: _t->on_tableView_doubleClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject adminWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_adminWindow.offsetsAndSize,
    qt_meta_data_adminWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_adminWindow_t
, QtPrivate::TypeAndForceComplete<adminWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>


>,
    nullptr
} };


const QMetaObject *adminWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *adminWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_adminWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int adminWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
