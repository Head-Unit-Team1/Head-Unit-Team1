/****************************************************************************
** Meta object code from reading C++ file 'lrsign.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "lrsign.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lrsign.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LRSign_t {
    QByteArrayData data[9];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LRSign_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LRSign_t qt_meta_stringdata_LRSign = {
    {
QT_MOC_LITERAL(0, 0, 6), // "LRSign"
QT_MOC_LITERAL(1, 7, 21), // "directionValueChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18), // "broadcastDirection"
QT_MOC_LITERAL(4, 49, 7), // "int32_t"
QT_MOC_LITERAL(5, 57, 9), // "signValue"
QT_MOC_LITERAL(6, 67, 16), // "sendLrsignRandom"
QT_MOC_LITERAL(7, 84, 16), // "changedDirection"
QT_MOC_LITERAL(8, 101, 14) // "directionValue"

    },
    "LRSign\0directionValueChanged\0\0"
    "broadcastDirection\0int32_t\0signValue\0"
    "sendLrsignRandom\0changedDirection\0"
    "directionValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LRSign[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   36, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    1,   33,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 4,    7,

 // properties: name, type, flags
       8, 0x80000000 | 4, 0x00495009,

 // properties: notify_signal_id
       0,

       0        // eod
};

void LRSign::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LRSign *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->directionValueChanged(); break;
        case 1: _t->broadcastDirection((*reinterpret_cast< int32_t(*)>(_a[1]))); break;
        case 2: _t->sendLrsignRandom((*reinterpret_cast< int32_t(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LRSign::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LRSign::directionValueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LRSign::*)(int32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LRSign::broadcastDirection)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<LRSign *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int32_t*>(_v) = _t->directionValue(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject LRSign::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_LRSign.data,
    qt_meta_data_LRSign,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LRSign::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LRSign::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LRSign.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LRSign::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void LRSign::directionValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LRSign::broadcastDirection(int32_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
