/****************************************************************************
** Meta object code from reading C++ file 'VideoPatternEngine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/VideoPatternEngine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VideoPatternEngine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoPatternEngine_t {
    QByteArrayData data[57];
    char stringdata0[806];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoPatternEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoPatternEngine_t qt_meta_stringdata_VideoPatternEngine = {
    {
QT_MOC_LITERAL(0, 0, 18), // "VideoPatternEngine"
QT_MOC_LITERAL(1, 19, 13), // "sourceChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 18), // "sampleCountChanged"
QT_MOC_LITERAL(4, 53, 17), // "extractingChanged"
QT_MOC_LITERAL(5, 71, 25), // "extractionProgressChanged"
QT_MOC_LITERAL(6, 97, 19), // "patternReadyChanged"
QT_MOC_LITERAL(7, 117, 16), // "playStateChanged"
QT_MOC_LITERAL(8, 134, 14), // "loopingChanged"
QT_MOC_LITERAL(9, 149, 23), // "playbackPositionChanged"
QT_MOC_LITERAL(10, 173, 20), // "currentColorsChanged"
QT_MOC_LITERAL(11, 194, 18), // "targetBulbsChanged"
QT_MOC_LITERAL(12, 213, 18), // "extractionComplete"
QT_MOC_LITERAL(13, 232, 10), // "frameCount"
QT_MOC_LITERAL(14, 243, 13), // "errorOccurred"
QT_MOC_LITERAL(15, 257, 7), // "message"
QT_MOC_LITERAL(16, 265, 20), // "statusMessageChanged"
QT_MOC_LITERAL(17, 286, 20), // "savedPatternsChanged"
QT_MOC_LITERAL(18, 307, 20), // "onMediaStatusChanged"
QT_MOC_LITERAL(19, 328, 25), // "QMediaPlayer::MediaStatus"
QT_MOC_LITERAL(20, 354, 6), // "status"
QT_MOC_LITERAL(21, 361, 13), // "onPlayerError"
QT_MOC_LITERAL(22, 375, 19), // "QMediaPlayer::Error"
QT_MOC_LITERAL(23, 395, 5), // "error"
QT_MOC_LITERAL(24, 401, 23), // "onPlayerPositionChanged"
QT_MOC_LITERAL(25, 425, 8), // "position"
QT_MOC_LITERAL(26, 434, 14), // "onPlaybackTick"
QT_MOC_LITERAL(27, 449, 9), // "loadVideo"
QT_MOC_LITERAL(28, 459, 3), // "url"
QT_MOC_LITERAL(29, 463, 14), // "extractPattern"
QT_MOC_LITERAL(30, 478, 16), // "cancelExtraction"
QT_MOC_LITERAL(31, 495, 4), // "play"
QT_MOC_LITERAL(32, 500, 5), // "pause"
QT_MOC_LITERAL(33, 506, 4), // "stop"
QT_MOC_LITERAL(34, 511, 14), // "setTargetBulbs"
QT_MOC_LITERAL(35, 526, 5), // "bulbs"
QT_MOC_LITERAL(36, 532, 16), // "clearTargetBulbs"
QT_MOC_LITERAL(37, 549, 18), // "saveCurrentPattern"
QT_MOC_LITERAL(38, 568, 4), // "name"
QT_MOC_LITERAL(39, 573, 11), // "loadPattern"
QT_MOC_LITERAL(40, 585, 13), // "deletePattern"
QT_MOC_LITERAL(41, 599, 6), // "source"
QT_MOC_LITERAL(42, 606, 8), // "fileName"
QT_MOC_LITERAL(43, 615, 11), // "sampleCount"
QT_MOC_LITERAL(44, 627, 7), // "looping"
QT_MOC_LITERAL(45, 635, 10), // "extracting"
QT_MOC_LITERAL(46, 646, 18), // "extractionProgress"
QT_MOC_LITERAL(47, 665, 12), // "patternReady"
QT_MOC_LITERAL(48, 678, 17), // "patternDurationMs"
QT_MOC_LITERAL(49, 696, 17), // "patternFrameCount"
QT_MOC_LITERAL(50, 714, 7), // "playing"
QT_MOC_LITERAL(51, 722, 6), // "paused"
QT_MOC_LITERAL(52, 729, 18), // "playbackPositionMs"
QT_MOC_LITERAL(53, 748, 13), // "currentColors"
QT_MOC_LITERAL(54, 762, 15), // "targetBulbCount"
QT_MOC_LITERAL(55, 778, 13), // "statusMessage"
QT_MOC_LITERAL(56, 792, 13) // "savedPatterns"

    },
    "VideoPatternEngine\0sourceChanged\0\0"
    "sampleCountChanged\0extractingChanged\0"
    "extractionProgressChanged\0patternReadyChanged\0"
    "playStateChanged\0loopingChanged\0"
    "playbackPositionChanged\0currentColorsChanged\0"
    "targetBulbsChanged\0extractionComplete\0"
    "frameCount\0errorOccurred\0message\0"
    "statusMessageChanged\0savedPatternsChanged\0"
    "onMediaStatusChanged\0QMediaPlayer::MediaStatus\0"
    "status\0onPlayerError\0QMediaPlayer::Error\0"
    "error\0onPlayerPositionChanged\0position\0"
    "onPlaybackTick\0loadVideo\0url\0"
    "extractPattern\0cancelExtraction\0play\0"
    "pause\0stop\0setTargetBulbs\0bulbs\0"
    "clearTargetBulbs\0saveCurrentPattern\0"
    "name\0loadPattern\0deletePattern\0source\0"
    "fileName\0sampleCount\0looping\0extracting\0"
    "extractionProgress\0patternReady\0"
    "patternDurationMs\0patternFrameCount\0"
    "playing\0paused\0playbackPositionMs\0"
    "currentColors\0targetBulbCount\0"
    "statusMessage\0savedPatterns"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoPatternEngine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
      16,  208, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  159,    2, 0x06 /* Public */,
       3,    0,  160,    2, 0x06 /* Public */,
       4,    0,  161,    2, 0x06 /* Public */,
       5,    0,  162,    2, 0x06 /* Public */,
       6,    0,  163,    2, 0x06 /* Public */,
       7,    0,  164,    2, 0x06 /* Public */,
       8,    0,  165,    2, 0x06 /* Public */,
       9,    0,  166,    2, 0x06 /* Public */,
      10,    0,  167,    2, 0x06 /* Public */,
      11,    0,  168,    2, 0x06 /* Public */,
      12,    1,  169,    2, 0x06 /* Public */,
      14,    1,  172,    2, 0x06 /* Public */,
      16,    0,  175,    2, 0x06 /* Public */,
      17,    0,  176,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,  177,    2, 0x08 /* Private */,
      21,    1,  180,    2, 0x08 /* Private */,
      24,    1,  183,    2, 0x08 /* Private */,
      26,    0,  186,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      27,    1,  187,    2, 0x02 /* Public */,
      29,    0,  190,    2, 0x02 /* Public */,
      30,    0,  191,    2, 0x02 /* Public */,
      31,    0,  192,    2, 0x02 /* Public */,
      32,    0,  193,    2, 0x02 /* Public */,
      33,    0,  194,    2, 0x02 /* Public */,
      34,    1,  195,    2, 0x02 /* Public */,
      36,    0,  198,    2, 0x02 /* Public */,
      37,    1,  199,    2, 0x02 /* Public */,
      39,    1,  202,    2, 0x02 /* Public */,
      40,    1,  205,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, QMetaType::LongLong,   25,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantList,   35,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   38,
    QMetaType::Void, QMetaType::QString,   38,
    QMetaType::Void, QMetaType::QString,   38,

 // properties: name, type, flags
      41, QMetaType::QString, 0x00495001,
      42, QMetaType::QString, 0x00495001,
      43, QMetaType::Int, 0x00495103,
      44, QMetaType::Bool, 0x00495103,
      45, QMetaType::Bool, 0x00495001,
      46, QMetaType::QReal, 0x00495001,
      47, QMetaType::Bool, 0x00495001,
      48, QMetaType::Int, 0x00495001,
      49, QMetaType::Int, 0x00495001,
      50, QMetaType::Bool, 0x00495001,
      51, QMetaType::Bool, 0x00495001,
      52, QMetaType::Int, 0x00495001,
      53, QMetaType::QVariantList, 0x00495001,
      54, QMetaType::Int, 0x00495001,
      55, QMetaType::QString, 0x00495001,
      56, QMetaType::QStringList, 0x00495001,

 // properties: notify_signal_id
       0,
       0,
       1,
       6,
       2,
       3,
       4,
       4,
       4,
       5,
       5,
       7,
       8,
       9,
      12,
      13,

       0        // eod
};

void VideoPatternEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoPatternEngine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sourceChanged(); break;
        case 1: _t->sampleCountChanged(); break;
        case 2: _t->extractingChanged(); break;
        case 3: _t->extractionProgressChanged(); break;
        case 4: _t->patternReadyChanged(); break;
        case 5: _t->playStateChanged(); break;
        case 6: _t->loopingChanged(); break;
        case 7: _t->playbackPositionChanged(); break;
        case 8: _t->currentColorsChanged(); break;
        case 9: _t->targetBulbsChanged(); break;
        case 10: _t->extractionComplete((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->errorOccurred((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->statusMessageChanged(); break;
        case 13: _t->savedPatternsChanged(); break;
        case 14: _t->onMediaStatusChanged((*reinterpret_cast< QMediaPlayer::MediaStatus(*)>(_a[1]))); break;
        case 15: _t->onPlayerError((*reinterpret_cast< QMediaPlayer::Error(*)>(_a[1]))); break;
        case 16: _t->onPlayerPositionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 17: _t->onPlaybackTick(); break;
        case 18: _t->loadVideo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->extractPattern(); break;
        case 20: _t->cancelExtraction(); break;
        case 21: _t->play(); break;
        case 22: _t->pause(); break;
        case 23: _t->stop(); break;
        case 24: _t->setTargetBulbs((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 25: _t->clearTargetBulbs(); break;
        case 26: _t->saveCurrentPattern((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 27: _t->loadPattern((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 28: _t->deletePattern((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::MediaStatus >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::Error >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::sourceChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::sampleCountChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::extractingChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::extractionProgressChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::patternReadyChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::playStateChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::loopingChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::playbackPositionChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::currentColorsChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::targetBulbsChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::extractionComplete)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::errorOccurred)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::statusMessageChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::savedPatternsChanged)) {
                *result = 13;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<VideoPatternEngine *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->source(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->fileName(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->sampleCount(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->isLooping(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->isExtracting(); break;
        case 5: *reinterpret_cast< qreal*>(_v) = _t->extractionProgress(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->isPatternReady(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->patternDurationMs(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->patternFrameCount(); break;
        case 9: *reinterpret_cast< bool*>(_v) = _t->isPlaying(); break;
        case 10: *reinterpret_cast< bool*>(_v) = _t->isPaused(); break;
        case 11: *reinterpret_cast< int*>(_v) = _t->playbackPositionMs(); break;
        case 12: *reinterpret_cast< QVariantList*>(_v) = _t->currentColors(); break;
        case 13: *reinterpret_cast< int*>(_v) = _t->targetBulbCount(); break;
        case 14: *reinterpret_cast< QString*>(_v) = _t->statusMessage(); break;
        case 15: *reinterpret_cast< QStringList*>(_v) = _t->savedPatterns(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<VideoPatternEngine *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setSampleCount(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setLooping(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject VideoPatternEngine::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractVideoSurface::staticMetaObject>(),
    qt_meta_stringdata_VideoPatternEngine.data,
    qt_meta_data_VideoPatternEngine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VideoPatternEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoPatternEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoPatternEngine.stringdata0))
        return static_cast<void*>(this);
    return QAbstractVideoSurface::qt_metacast(_clname);
}

int VideoPatternEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractVideoSurface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 16;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void VideoPatternEngine::sourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VideoPatternEngine::sampleCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void VideoPatternEngine::extractingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void VideoPatternEngine::extractionProgressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void VideoPatternEngine::patternReadyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void VideoPatternEngine::playStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void VideoPatternEngine::loopingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void VideoPatternEngine::playbackPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void VideoPatternEngine::currentColorsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void VideoPatternEngine::targetBulbsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void VideoPatternEngine::extractionComplete(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void VideoPatternEngine::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void VideoPatternEngine::statusMessageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void VideoPatternEngine::savedPatternsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
