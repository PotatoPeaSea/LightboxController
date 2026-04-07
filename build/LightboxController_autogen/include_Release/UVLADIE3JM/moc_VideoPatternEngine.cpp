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
    QByteArrayData data[59];
    char stringdata0[841];
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
QT_MOC_LITERAL(10, 173, 20), // "playbackSpeedChanged"
QT_MOC_LITERAL(11, 194, 20), // "currentColorsChanged"
QT_MOC_LITERAL(12, 215, 18), // "targetBulbsChanged"
QT_MOC_LITERAL(13, 234, 18), // "extractionComplete"
QT_MOC_LITERAL(14, 253, 10), // "frameCount"
QT_MOC_LITERAL(15, 264, 13), // "errorOccurred"
QT_MOC_LITERAL(16, 278, 7), // "message"
QT_MOC_LITERAL(17, 286, 20), // "statusMessageChanged"
QT_MOC_LITERAL(18, 307, 20), // "savedPatternsChanged"
QT_MOC_LITERAL(19, 328, 20), // "onMediaStatusChanged"
QT_MOC_LITERAL(20, 349, 25), // "QMediaPlayer::MediaStatus"
QT_MOC_LITERAL(21, 375, 6), // "status"
QT_MOC_LITERAL(22, 382, 13), // "onPlayerError"
QT_MOC_LITERAL(23, 396, 19), // "QMediaPlayer::Error"
QT_MOC_LITERAL(24, 416, 5), // "error"
QT_MOC_LITERAL(25, 422, 23), // "onPlayerPositionChanged"
QT_MOC_LITERAL(26, 446, 8), // "position"
QT_MOC_LITERAL(27, 455, 14), // "onPlaybackTick"
QT_MOC_LITERAL(28, 470, 9), // "loadVideo"
QT_MOC_LITERAL(29, 480, 3), // "url"
QT_MOC_LITERAL(30, 484, 14), // "extractPattern"
QT_MOC_LITERAL(31, 499, 16), // "cancelExtraction"
QT_MOC_LITERAL(32, 516, 4), // "play"
QT_MOC_LITERAL(33, 521, 5), // "pause"
QT_MOC_LITERAL(34, 527, 4), // "stop"
QT_MOC_LITERAL(35, 532, 14), // "setTargetBulbs"
QT_MOC_LITERAL(36, 547, 5), // "bulbs"
QT_MOC_LITERAL(37, 553, 16), // "clearTargetBulbs"
QT_MOC_LITERAL(38, 570, 18), // "saveCurrentPattern"
QT_MOC_LITERAL(39, 589, 4), // "name"
QT_MOC_LITERAL(40, 594, 11), // "loadPattern"
QT_MOC_LITERAL(41, 606, 13), // "deletePattern"
QT_MOC_LITERAL(42, 620, 6), // "source"
QT_MOC_LITERAL(43, 627, 8), // "fileName"
QT_MOC_LITERAL(44, 636, 11), // "sampleCount"
QT_MOC_LITERAL(45, 648, 7), // "looping"
QT_MOC_LITERAL(46, 656, 10), // "extracting"
QT_MOC_LITERAL(47, 667, 18), // "extractionProgress"
QT_MOC_LITERAL(48, 686, 12), // "patternReady"
QT_MOC_LITERAL(49, 699, 17), // "patternDurationMs"
QT_MOC_LITERAL(50, 717, 17), // "patternFrameCount"
QT_MOC_LITERAL(51, 735, 7), // "playing"
QT_MOC_LITERAL(52, 743, 6), // "paused"
QT_MOC_LITERAL(53, 750, 18), // "playbackPositionMs"
QT_MOC_LITERAL(54, 769, 13), // "playbackSpeed"
QT_MOC_LITERAL(55, 783, 13), // "currentColors"
QT_MOC_LITERAL(56, 797, 15), // "targetBulbCount"
QT_MOC_LITERAL(57, 813, 13), // "statusMessage"
QT_MOC_LITERAL(58, 827, 13) // "savedPatterns"

    },
    "VideoPatternEngine\0sourceChanged\0\0"
    "sampleCountChanged\0extractingChanged\0"
    "extractionProgressChanged\0patternReadyChanged\0"
    "playStateChanged\0loopingChanged\0"
    "playbackPositionChanged\0playbackSpeedChanged\0"
    "currentColorsChanged\0targetBulbsChanged\0"
    "extractionComplete\0frameCount\0"
    "errorOccurred\0message\0statusMessageChanged\0"
    "savedPatternsChanged\0onMediaStatusChanged\0"
    "QMediaPlayer::MediaStatus\0status\0"
    "onPlayerError\0QMediaPlayer::Error\0"
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
    "playbackSpeed\0currentColors\0targetBulbCount\0"
    "statusMessage\0savedPatterns"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoPatternEngine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
      17,  214, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  164,    2, 0x06 /* Public */,
       3,    0,  165,    2, 0x06 /* Public */,
       4,    0,  166,    2, 0x06 /* Public */,
       5,    0,  167,    2, 0x06 /* Public */,
       6,    0,  168,    2, 0x06 /* Public */,
       7,    0,  169,    2, 0x06 /* Public */,
       8,    0,  170,    2, 0x06 /* Public */,
       9,    0,  171,    2, 0x06 /* Public */,
      10,    0,  172,    2, 0x06 /* Public */,
      11,    0,  173,    2, 0x06 /* Public */,
      12,    0,  174,    2, 0x06 /* Public */,
      13,    1,  175,    2, 0x06 /* Public */,
      15,    1,  178,    2, 0x06 /* Public */,
      17,    0,  181,    2, 0x06 /* Public */,
      18,    0,  182,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    1,  183,    2, 0x08 /* Private */,
      22,    1,  186,    2, 0x08 /* Private */,
      25,    1,  189,    2, 0x08 /* Private */,
      27,    0,  192,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      28,    1,  193,    2, 0x02 /* Public */,
      30,    0,  196,    2, 0x02 /* Public */,
      31,    0,  197,    2, 0x02 /* Public */,
      32,    0,  198,    2, 0x02 /* Public */,
      33,    0,  199,    2, 0x02 /* Public */,
      34,    0,  200,    2, 0x02 /* Public */,
      35,    1,  201,    2, 0x02 /* Public */,
      37,    0,  204,    2, 0x02 /* Public */,
      38,    1,  205,    2, 0x02 /* Public */,
      40,    1,  208,    2, 0x02 /* Public */,
      41,    1,  211,    2, 0x02 /* Public */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, QMetaType::LongLong,   26,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantList,   36,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::Void, QMetaType::QString,   39,

 // properties: name, type, flags
      42, QMetaType::QString, 0x00495001,
      43, QMetaType::QString, 0x00495001,
      44, QMetaType::Int, 0x00495103,
      45, QMetaType::Bool, 0x00495103,
      46, QMetaType::Bool, 0x00495001,
      47, QMetaType::QReal, 0x00495001,
      48, QMetaType::Bool, 0x00495001,
      49, QMetaType::Int, 0x00495001,
      50, QMetaType::Int, 0x00495001,
      51, QMetaType::Bool, 0x00495001,
      52, QMetaType::Bool, 0x00495001,
      53, QMetaType::Int, 0x00495103,
      54, QMetaType::QReal, 0x00495103,
      55, QMetaType::QVariantList, 0x00495001,
      56, QMetaType::Int, 0x00495001,
      57, QMetaType::QString, 0x00495001,
      58, QMetaType::QStringList, 0x00495001,

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
      10,
      13,
      14,

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
        case 8: _t->playbackSpeedChanged(); break;
        case 9: _t->currentColorsChanged(); break;
        case 10: _t->targetBulbsChanged(); break;
        case 11: _t->extractionComplete((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->errorOccurred((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->statusMessageChanged(); break;
        case 14: _t->savedPatternsChanged(); break;
        case 15: _t->onMediaStatusChanged((*reinterpret_cast< QMediaPlayer::MediaStatus(*)>(_a[1]))); break;
        case 16: _t->onPlayerError((*reinterpret_cast< QMediaPlayer::Error(*)>(_a[1]))); break;
        case 17: _t->onPlayerPositionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 18: _t->onPlaybackTick(); break;
        case 19: _t->loadVideo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->extractPattern(); break;
        case 21: _t->cancelExtraction(); break;
        case 22: _t->play(); break;
        case 23: _t->pause(); break;
        case 24: _t->stop(); break;
        case 25: _t->setTargetBulbs((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 26: _t->clearTargetBulbs(); break;
        case 27: _t->saveCurrentPattern((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 28: _t->loadPattern((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 29: _t->deletePattern((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::MediaStatus >(); break;
            }
            break;
        case 16:
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::playbackSpeedChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::currentColorsChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::targetBulbsChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::extractionComplete)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::errorOccurred)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::statusMessageChanged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::savedPatternsChanged)) {
                *result = 14;
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
        case 12: *reinterpret_cast< qreal*>(_v) = _t->playbackSpeed(); break;
        case 13: *reinterpret_cast< QVariantList*>(_v) = _t->currentColors(); break;
        case 14: *reinterpret_cast< int*>(_v) = _t->targetBulbCount(); break;
        case 15: *reinterpret_cast< QString*>(_v) = _t->statusMessage(); break;
        case 16: *reinterpret_cast< QStringList*>(_v) = _t->savedPatterns(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<VideoPatternEngine *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setSampleCount(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setLooping(*reinterpret_cast< bool*>(_v)); break;
        case 11: _t->setPlaybackPositionMs(*reinterpret_cast< int*>(_v)); break;
        case 12: _t->setPlaybackSpeed(*reinterpret_cast< qreal*>(_v)); break;
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
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 17;
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
void VideoPatternEngine::playbackSpeedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void VideoPatternEngine::currentColorsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void VideoPatternEngine::targetBulbsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void VideoPatternEngine::extractionComplete(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void VideoPatternEngine::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void VideoPatternEngine::statusMessageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void VideoPatternEngine::savedPatternsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
