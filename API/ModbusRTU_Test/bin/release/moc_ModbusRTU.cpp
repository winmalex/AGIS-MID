/****************************************************************************
** Meta object code from reading C++ file 'ModbusRTU.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ModbusRTU/Include/ModbusRTU.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModbusRTU.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModbusRTU_t {
    QByteArrayData data[25];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModbusRTU_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModbusRTU_t qt_meta_stringdata_ModbusRTU = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ModbusRTU"
QT_MOC_LITERAL(1, 10, 12), // "signalAnswer"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 21), // "MyPackage::DataVector"
QT_MOC_LITERAL(4, 46, 4), // "code"
QT_MOC_LITERAL(5, 51, 13), // "signalWarning"
QT_MOC_LITERAL(6, 65, 7), // "message"
QT_MOC_LITERAL(7, 73, 11), // "signalError"
QT_MOC_LITERAL(8, 85, 15), // "signalConnected"
QT_MOC_LITERAL(9, 101, 18), // "signalDisconnected"
QT_MOC_LITERAL(10, 120, 9), // "connected"
QT_MOC_LITERAL(11, 130, 4), // "name"
QT_MOC_LITERAL(12, 135, 12), // "disconnected"
QT_MOC_LITERAL(13, 148, 4), // "read"
QT_MOC_LITERAL(14, 153, 3), // "len"
QT_MOC_LITERAL(15, 157, 5), // "print"
QT_MOC_LITERAL(16, 163, 4), // "line"
QT_MOC_LITERAL(17, 168, 5), // "write"
QT_MOC_LITERAL(18, 174, 4), // "data"
QT_MOC_LITERAL(19, 179, 11), // "pushPackage"
QT_MOC_LITERAL(20, 191, 10), // "MyPackage*"
QT_MOC_LITERAL(21, 202, 7), // "package"
QT_MOC_LITERAL(22, 210, 13), // "answerPackage"
QT_MOC_LITERAL(23, 224, 15), // "tickReadPackage"
QT_MOC_LITERAL(24, 240, 16) // "tickWritePackage"

    },
    "ModbusRTU\0signalAnswer\0\0MyPackage::DataVector\0"
    "code\0signalWarning\0message\0signalError\0"
    "signalConnected\0signalDisconnected\0"
    "connected\0name\0disconnected\0read\0len\0"
    "print\0line\0write\0data\0pushPackage\0"
    "MyPackage*\0package\0answerPackage\0"
    "tickReadPackage\0tickWritePackage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModbusRTU[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       5,    2,   92,    2, 0x06 /* Public */,
       7,    1,   97,    2, 0x06 /* Public */,
       8,    0,  100,    2, 0x06 /* Public */,
       9,    0,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  102,    2, 0x0a /* Public */,
      12,    0,  105,    2, 0x0a /* Public */,
      13,    1,  106,    2, 0x0a /* Public */,
      15,    1,  109,    2, 0x0a /* Public */,
      17,    1,  112,    2, 0x0a /* Public */,
      17,    0,  115,    2, 0x2a /* Public | MethodCloned */,
      19,    1,  116,    2, 0x0a /* Public */,
      22,    0,  119,    2, 0x0a /* Public */,
      23,    0,  120,    2, 0x08 /* Private */,
      24,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    4,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,   11,
    QMetaType::Bool,
    QMetaType::QString, QMetaType::Int,   14,
    QMetaType::Bool, QMetaType::QString,   16,
    QMetaType::Bool, QMetaType::QByteArray,   18,
    QMetaType::Bool,
    QMetaType::Bool, 0x80000000 | 20,   21,
    0x80000000 | 20,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ModbusRTU::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModbusRTU *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalAnswer((*reinterpret_cast< MyPackage::DataVector(*)>(_a[1]))); break;
        case 1: _t->signalWarning((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->signalError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->signalConnected(); break;
        case 4: _t->signalDisconnected(); break;
        case 5: { bool _r = _t->connected((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->disconnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->read((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->print((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->write((*reinterpret_cast< QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->write();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->pushPackage((*reinterpret_cast< MyPackage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { MyPackage* _r = _t->answerPackage();
            if (_a[0]) *reinterpret_cast< MyPackage**>(_a[0]) = std::move(_r); }  break;
        case 13: _t->tickReadPackage(); break;
        case 14: _t->tickWritePackage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyPackage* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ModbusRTU::*)(MyPackage::DataVector );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusRTU::signalAnswer)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ModbusRTU::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusRTU::signalWarning)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ModbusRTU::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusRTU::signalError)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ModbusRTU::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusRTU::signalConnected)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ModbusRTU::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusRTU::signalDisconnected)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ModbusRTU::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ModbusRTU.data,
    qt_meta_data_ModbusRTU,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModbusRTU::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModbusRTU::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModbusRTU.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ModbusRTU::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ModbusRTU::signalAnswer(MyPackage::DataVector _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ModbusRTU::signalWarning(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ModbusRTU::signalError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ModbusRTU::signalConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ModbusRTU::signalDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
