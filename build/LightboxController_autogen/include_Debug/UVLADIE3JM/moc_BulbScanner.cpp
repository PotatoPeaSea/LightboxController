/****************************************************************************
** Meta object code from reading C++ file 'BulbScanner.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/BulbScanner.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BulbScanner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BulbScanner_t {
    QByteArrayData data[14];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BulbScanner_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BulbScanner_t qt_meta_stringdata_BulbScanner = {
    {
QT_MOC_LITERAL(0, 0, 11), // "BulbScanner"
QT_MOC_LITERAL(1, 12, 9), // "bulbFound"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "DiscoveredBulb"
QT_MOC_LITERAL(4, 38, 4), // "bulb"
QT_MOC_LITERAL(5, 43, 12), // "scanFinished"
QT_MOC_LITERAL(6, 56, 9), // "scanError"
QT_MOC_LITERAL(7, 66, 7), // "message"
QT_MOC_LITERAL(8, 74, 11), // "onReadyRead"
QT_MOC_LITERAL(9, 86, 15), // "onBroadcastTick"
QT_MOC_LITERAL(10, 102, 13), // "onScanTimeout"
QT_MOC_LITERAL(11, 116, 9), // "startScan"
QT_MOC_LITERAL(12, 126, 8), // "stopScan"
QT_MOC_LITERAL(13, 135, 10) // "isScanning"

    },
    "BulbScanner\0bulbFound\0\0DiscoveredBulb\0"
    "bulb\0scanFinished\0scanError\0message\0"
    "onReadyRead\0onBroadcastTick\0onScanTimeout\0"
    "startScan\0stopScan\0isScanning"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BulbScanner[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      11,    0,   69,    2, 0x02 /* Public */,
      12,    0,   70,    2, 0x02 /* Public */,
      13,    0,   71,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void BulbScanner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BulbScanner *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bulbFound((*reinterpret_cast< const DiscoveredBulb(*)>(_a[1]))); break;
        case 1: _t->scanFinished(); break;
        case 2: _t->scanError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onReadyRead(); break;
        case 4: _t->onBroadcastTick(); break;
        case 5: _t->onScanTimeout(); break;
        case 6: _t->startScan(); break;
        case 7: _t->stopScan(); break;
        case 8: { bool _r = _t->isScanning();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BulbScanner::*)(const DiscoveredBulb & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BulbScanner::bulbFound)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BulbScanner::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BulbScanner::scanFinished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BulbScanner::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BulbScanner::scanError)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BulbScanner::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_BulbScanner.data,
    qt_meta_data_BulbScanner,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BulbScanner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BulbScanner::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BulbScanner.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BulbScanner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void BulbScanner::bulbFound(const DiscoveredBulb & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BulbScanner::scanFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BulbScanner::scanError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
