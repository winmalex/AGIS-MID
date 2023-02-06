/****************************************************************************
** Meta object code from reading C++ file 'my.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../my.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'my.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_my_t {
    QByteArrayData data[10];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_my_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_my_t qt_meta_stringdata_my = {
    {
QT_MOC_LITERAL(0, 0, 2), // "my"
QT_MOC_LITERAL(1, 3, 8), // "toAnswer"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 21), // "MyPackage::DataVector"
QT_MOC_LITERAL(4, 35, 4), // "code"
QT_MOC_LITERAL(5, 40, 9), // "toWarning"
QT_MOC_LITERAL(6, 50, 7), // "message"
QT_MOC_LITERAL(7, 58, 7), // "toError"
QT_MOC_LITERAL(8, 66, 11), // "toConnected"
QT_MOC_LITERAL(9, 78, 14) // "toDisconnected"

    },
    "my\0toAnswer\0\0MyPackage::DataVector\0"
    "code\0toWarning\0message\0toError\0"
    "toConnected\0toDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_my[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       5,    2,   42,    2, 0x0a /* Public */,
       7,    1,   47,    2, 0x0a /* Public */,
       8,    0,   50,    2, 0x0a /* Public */,
       9,    0,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    4,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void my::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<my *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toAnswer((*reinterpret_cast< MyPackage::DataVector(*)>(_a[1]))); break;
        case 1: _t->toWarning((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->toError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->toConnected(); break;
        case 4: _t->toDisconnected(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject my::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_my.data,
    qt_meta_data_my,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *my::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *my::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_my.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int my::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
