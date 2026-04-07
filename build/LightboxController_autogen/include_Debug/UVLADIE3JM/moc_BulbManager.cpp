/****************************************************************************
** Meta object code from reading C++ file 'BulbManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/BulbManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BulbManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BulbManager_t {
    QByteArrayData data[52];
    char stringdata0[575];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BulbManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BulbManager_t qt_meta_stringdata_BulbManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "BulbManager"
QT_MOC_LITERAL(1, 12, 12), // "countChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "scanningChanged"
QT_MOC_LITERAL(4, 42, 19), // "selectedBulbChanged"
QT_MOC_LITERAL(5, 62, 22), // "discoveredCountChanged"
QT_MOC_LITERAL(6, 85, 14), // "bulbDiscovered"
QT_MOC_LITERAL(7, 100, 2), // "ip"
QT_MOC_LITERAL(8, 103, 3), // "mac"
QT_MOC_LITERAL(9, 107, 5), // "model"
QT_MOC_LITERAL(10, 113, 12), // "scanFinished"
QT_MOC_LITERAL(11, 126, 11), // "configError"
QT_MOC_LITERAL(12, 138, 7), // "message"
QT_MOC_LITERAL(13, 146, 11), // "onBulbFound"
QT_MOC_LITERAL(14, 158, 14), // "DiscoveredBulb"
QT_MOC_LITERAL(15, 173, 4), // "bulb"
QT_MOC_LITERAL(16, 178, 14), // "onScanFinished"
QT_MOC_LITERAL(17, 193, 17), // "onBulbDataChanged"
QT_MOC_LITERAL(18, 211, 8), // "discover"
QT_MOC_LITERAL(19, 220, 8), // "stopScan"
QT_MOC_LITERAL(20, 229, 7), // "addBulb"
QT_MOC_LITERAL(21, 237, 13), // "addBulbManual"
QT_MOC_LITERAL(22, 251, 10), // "removeBulb"
QT_MOC_LITERAL(23, 262, 5), // "index"
QT_MOC_LITERAL(24, 268, 6), // "bulbAt"
QT_MOC_LITERAL(25, 275, 5), // "Bulb*"
QT_MOC_LITERAL(26, 281, 10), // "selectBulb"
QT_MOC_LITERAL(27, 292, 19), // "toggleBulbSelection"
QT_MOC_LITERAL(28, 312, 15), // "handleBulbClick"
QT_MOC_LITERAL(29, 328, 11), // "deselectAll"
QT_MOC_LITERAL(30, 340, 10), // "connectAll"
QT_MOC_LITERAL(31, 351, 13), // "disconnectAll"
QT_MOC_LITERAL(32, 365, 16), // "setSelectedColor"
QT_MOC_LITERAL(33, 382, 1), // "r"
QT_MOC_LITERAL(34, 384, 1), // "g"
QT_MOC_LITERAL(35, 386, 1), // "b"
QT_MOC_LITERAL(36, 388, 16), // "setSelectedWhite"
QT_MOC_LITERAL(37, 405, 4), // "warm"
QT_MOC_LITERAL(38, 410, 4), // "cool"
QT_MOC_LITERAL(39, 415, 16), // "setSelectedPower"
QT_MOC_LITERAL(40, 432, 2), // "on"
QT_MOC_LITERAL(41, 435, 12), // "allBulbsList"
QT_MOC_LITERAL(42, 448, 17), // "selectedBulbsList"
QT_MOC_LITERAL(43, 466, 10), // "saveConfig"
QT_MOC_LITERAL(44, 477, 10), // "loadConfig"
QT_MOC_LITERAL(45, 488, 12), // "discoveredIp"
QT_MOC_LITERAL(46, 501, 13), // "discoveredMac"
QT_MOC_LITERAL(47, 515, 15), // "discoveredModel"
QT_MOC_LITERAL(48, 531, 5), // "count"
QT_MOC_LITERAL(49, 537, 8), // "scanning"
QT_MOC_LITERAL(50, 546, 12), // "selectedBulb"
QT_MOC_LITERAL(51, 559, 15) // "discoveredCount"

    },
    "BulbManager\0countChanged\0\0scanningChanged\0"
    "selectedBulbChanged\0discoveredCountChanged\0"
    "bulbDiscovered\0ip\0mac\0model\0scanFinished\0"
    "configError\0message\0onBulbFound\0"
    "DiscoveredBulb\0bulb\0onScanFinished\0"
    "onBulbDataChanged\0discover\0stopScan\0"
    "addBulb\0addBulbManual\0removeBulb\0index\0"
    "bulbAt\0Bulb*\0selectBulb\0toggleBulbSelection\0"
    "handleBulbClick\0deselectAll\0connectAll\0"
    "disconnectAll\0setSelectedColor\0r\0g\0b\0"
    "setSelectedWhite\0warm\0cool\0setSelectedPower\0"
    "on\0allBulbsList\0selectedBulbsList\0"
    "saveConfig\0loadConfig\0discoveredIp\0"
    "discoveredMac\0discoveredModel\0count\0"
    "scanning\0selectedBulb\0discoveredCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BulbManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       4,  252, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  174,    2, 0x06 /* Public */,
       3,    0,  175,    2, 0x06 /* Public */,
       4,    0,  176,    2, 0x06 /* Public */,
       5,    0,  177,    2, 0x06 /* Public */,
       6,    3,  178,    2, 0x06 /* Public */,
      10,    0,  185,    2, 0x06 /* Public */,
      11,    1,  186,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  189,    2, 0x08 /* Private */,
      16,    0,  192,    2, 0x08 /* Private */,
      17,    0,  193,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      18,    0,  194,    2, 0x02 /* Public */,
      19,    0,  195,    2, 0x02 /* Public */,
      20,    3,  196,    2, 0x02 /* Public */,
      21,    1,  203,    2, 0x02 /* Public */,
      22,    1,  206,    2, 0x02 /* Public */,
      24,    1,  209,    2, 0x02 /* Public */,
      26,    1,  212,    2, 0x02 /* Public */,
      27,    1,  215,    2, 0x02 /* Public */,
      28,    1,  218,    2, 0x02 /* Public */,
      29,    0,  221,    2, 0x02 /* Public */,
      30,    0,  222,    2, 0x02 /* Public */,
      31,    0,  223,    2, 0x02 /* Public */,
      32,    3,  224,    2, 0x02 /* Public */,
      36,    2,  231,    2, 0x02 /* Public */,
      39,    1,  236,    2, 0x02 /* Public */,
      41,    0,  239,    2, 0x02 /* Public */,
      42,    0,  240,    2, 0x02 /* Public */,
      43,    0,  241,    2, 0x02 /* Public */,
      44,    0,  242,    2, 0x02 /* Public */,
      45,    1,  243,    2, 0x02 /* Public */,
      46,    1,  246,    2, 0x02 /* Public */,
      47,    1,  249,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,    9,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,   23,
    0x80000000 | 25, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   33,   34,   35,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   37,   38,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::QVariantList,
    QMetaType::QVariantList,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::Int,   23,
    QMetaType::QString, QMetaType::Int,   23,
    QMetaType::QString, QMetaType::Int,   23,

 // properties: name, type, flags
      48, QMetaType::Int, 0x00495001,
      49, QMetaType::Bool, 0x00495001,
      50, 0x80000000 | 25, 0x00495009,
      51, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void BulbManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BulbManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->countChanged(); break;
        case 1: _t->scanningChanged(); break;
        case 2: _t->selectedBulbChanged(); break;
        case 3: _t->discoveredCountChanged(); break;
        case 4: _t->bulbDiscovered((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 5: _t->scanFinished(); break;
        case 6: _t->configError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->onBulbFound((*reinterpret_cast< const DiscoveredBulb(*)>(_a[1]))); break;
        case 8: _t->onScanFinished(); break;
        case 9: _t->onBulbDataChanged(); break;
        case 10: _t->discover(); break;
        case 11: _t->stopScan(); break;
        case 12: _t->addBulb((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 13: _t->addBulbManual((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->removeBulb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: { Bulb* _r = _t->bulbAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Bulb**>(_a[0]) = std::move(_r); }  break;
        case 16: _t->selectBulb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->toggleBulbSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->handleBulbClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->deselectAll(); break;
        case 20: _t->connectAll(); break;
        case 21: _t->disconnectAll(); break;
        case 22: _t->setSelectedColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 23: _t->setSelectedWhite((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 24: _t->setSelectedPower((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: { QVariantList _r = _t->allBulbsList();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 26: { QVariantList _r = _t->selectedBulbsList();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->saveConfig(); break;
        case 28: _t->loadConfig(); break;
        case 29: { QString _r = _t->discoveredIp((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 30: { QString _r = _t->discoveredMac((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 31: { QString _r = _t->discoveredModel((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BulbManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BulbManager::countChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BulbManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BulbManager::scanningChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BulbManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BulbManager::selectedBulbChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BulbManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BulbManager::discoveredCountChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (BulbManager::*)(const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BulbManager::bulbDiscovered)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (BulbManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BulbManager::scanFinished)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (BulbManager::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BulbManager::configError)) {
                *result = 6;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Bulb* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<BulbManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->count(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isScanning(); break;
        case 2: *reinterpret_cast< Bulb**>(_v) = _t->selectedBulb(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->discoveredCount(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject BulbManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_BulbManager.data,
    qt_meta_data_BulbManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BulbManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BulbManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BulbManager.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int BulbManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 32;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BulbManager::countChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BulbManager::scanningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BulbManager::selectedBulbChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BulbManager::discoveredCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void BulbManager::bulbDiscovered(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void BulbManager::scanFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void BulbManager::configError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
