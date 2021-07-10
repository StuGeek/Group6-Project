/****************************************************************************
** Meta object code from reading C++ file 'data.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../data.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'data.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mesh_t {
    QByteArrayData data[1];
    char stringdata0[5];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mesh_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mesh_t qt_meta_stringdata_Mesh = {
    {
QT_MOC_LITERAL(0, 0, 4) // "Mesh"

    },
    "Mesh"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mesh[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Mesh::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Mesh::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Mesh.data,
    qt_meta_data_Mesh,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mesh::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mesh::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mesh.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Mesh::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_FlowField_t {
    QByteArrayData data[10];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FlowField_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FlowField_t qt_meta_stringdata_FlowField = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FlowField"
QT_MOC_LITERAL(1, 10, 23), // "__CalculateProgress_set"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "__TimerLabel_set"
QT_MOC_LITERAL(4, 52, 6), // "Timer*"
QT_MOC_LITERAL(5, 59, 5), // "timer"
QT_MOC_LITERAL(6, 65, 10), // "__iter_set"
QT_MOC_LITERAL(7, 76, 5), // "_iter"
QT_MOC_LITERAL(8, 82, 9), // "__rms_set"
QT_MOC_LITERAL(9, 92, 4) // "_rms"

    },
    "FlowField\0__CalculateProgress_set\0\0"
    "__TimerLabel_set\0Timer*\0timer\0__iter_set\0"
    "_iter\0__rms_set\0_rms"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FlowField[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,
       8,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void FlowField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FlowField *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->__CalculateProgress_set((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->__TimerLabel_set((*reinterpret_cast< Timer*(*)>(_a[1]))); break;
        case 2: _t->__iter_set((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->__rms_set((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FlowField::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FlowField::__CalculateProgress_set)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FlowField::*)(Timer * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FlowField::__TimerLabel_set)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FlowField::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FlowField::__iter_set)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FlowField::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FlowField::__rms_set)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FlowField::staticMetaObject = { {
    &Mesh::staticMetaObject,
    qt_meta_stringdata_FlowField.data,
    qt_meta_data_FlowField,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FlowField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FlowField::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FlowField.stringdata0))
        return static_cast<void*>(this);
    return Mesh::qt_metacast(_clname);
}

int FlowField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Mesh::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void FlowField::__CalculateProgress_set(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FlowField::__TimerLabel_set(Timer * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FlowField::__iter_set(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FlowField::__rms_set(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
