/****************************************************************************
** Meta object code from reading C++ file 'carInfoController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../carInfoController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'carInfoController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CarInfoController_t {
    QByteArrayData data[14];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CarInfoController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CarInfoController_t qt_meta_stringdata_CarInfoController = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CarInfoController"
QT_MOC_LITERAL(1, 18, 19), // "batteryLevelChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 16), // "modeColorChanged"
QT_MOC_LITERAL(4, 56, 16), // "directionChanged"
QT_MOC_LITERAL(5, 73, 15), // "setBatteryLevel"
QT_MOC_LITERAL(6, 89, 5), // "level"
QT_MOC_LITERAL(7, 95, 12), // "setModeColor"
QT_MOC_LITERAL(8, 108, 5), // "color"
QT_MOC_LITERAL(9, 114, 12), // "setDirection"
QT_MOC_LITERAL(10, 127, 9), // "direction"
QT_MOC_LITERAL(11, 137, 12), // "batteryLevel"
QT_MOC_LITERAL(12, 150, 9), // "modeColor"
QT_MOC_LITERAL(13, 160, 14) // "blinkDirection"

    },
    "CarInfoController\0batteryLevelChanged\0"
    "\0modeColorChanged\0directionChanged\0"
    "setBatteryLevel\0level\0setModeColor\0"
    "color\0setDirection\0direction\0batteryLevel\0"
    "modeColor\0blinkDirection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CarInfoController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       3,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x02 /* Public */,
       7,    1,   50,    2, 0x02 /* Public */,
       9,    1,   53,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,

 // properties: name, type, flags
      11, QMetaType::Int, 0x00495103,
      12, QMetaType::QString, 0x00495103,
      13, QMetaType::QString, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void CarInfoController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CarInfoController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->batteryLevelChanged(); break;
        case 1: _t->modeColorChanged(); break;
        case 2: _t->directionChanged(); break;
        case 3: _t->setBatteryLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setModeColor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setDirection((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CarInfoController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarInfoController::batteryLevelChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CarInfoController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarInfoController::modeColorChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CarInfoController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarInfoController::directionChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CarInfoController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->batteryLevel(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->modeColor(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->blinkDirection(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CarInfoController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBatteryLevel(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setModeColor(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setDirection(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CarInfoController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CarInfoController.data,
    qt_meta_data_CarInfoController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CarInfoController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CarInfoController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CarInfoController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CarInfoController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CarInfoController::batteryLevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CarInfoController::modeColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CarInfoController::directionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
