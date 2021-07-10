/****************************************************************************
** Meta object code from reading C++ file 'MeshApp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../MeshApp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MeshApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MeshApp_t {
    QByteArrayData data[14];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeshApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeshApp_t qt_meta_stringdata_MeshApp = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MeshApp"
QT_MOC_LITERAL(1, 8, 25), // "_calculateProgressBar_set"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "value"
QT_MOC_LITERAL(4, 41, 15), // "_TimerLabel_set"
QT_MOC_LITERAL(5, 57, 6), // "Timer*"
QT_MOC_LITERAL(6, 64, 5), // "timer"
QT_MOC_LITERAL(7, 70, 9), // "_Iter_set"
QT_MOC_LITERAL(8, 80, 4), // "iter"
QT_MOC_LITERAL(9, 85, 8), // "_Rms_set"
QT_MOC_LITERAL(10, 94, 3), // "rms"
QT_MOC_LITERAL(11, 98, 26), // "on_calculateButton_clicked"
QT_MOC_LITERAL(12, 125, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(13, 149, 26) // "on_actionSave_as_triggered"

    },
    "MeshApp\0_calculateProgressBar_set\0\0"
    "value\0_TimerLabel_set\0Timer*\0timer\0"
    "_Iter_set\0iter\0_Rms_set\0rms\0"
    "on_calculateButton_clicked\0"
    "on_actionOpen_triggered\0"
    "on_actionSave_as_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeshApp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    1,   52,    2, 0x0a /* Public */,
       7,    1,   55,    2, 0x0a /* Public */,
       9,    1,   58,    2, 0x0a /* Public */,
      11,    0,   61,    2, 0x08 /* Private */,
      12,    0,   62,    2, 0x08 /* Private */,
      13,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MeshApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MeshApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->_calculateProgressBar_set((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->_TimerLabel_set((*reinterpret_cast< Timer*(*)>(_a[1]))); break;
        case 2: _t->_Iter_set((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->_Rms_set((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_calculateButton_clicked(); break;
        case 5: _t->on_actionOpen_triggered(); break;
        case 6: _t->on_actionSave_as_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MeshApp::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MeshApp.data,
    qt_meta_data_MeshApp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MeshApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeshApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MeshApp.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MeshApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
