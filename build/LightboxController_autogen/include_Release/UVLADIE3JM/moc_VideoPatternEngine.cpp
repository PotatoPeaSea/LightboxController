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
    QByteArrayData data[76];
    char stringdata0[1087];
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
QT_MOC_LITERAL(19, 328, 19), // "patternQueueChanged"
QT_MOC_LITERAL(20, 348, 20), // "manualAdvanceChanged"
QT_MOC_LITERAL(21, 369, 24), // "waitingForTriggerChanged"
QT_MOC_LITERAL(22, 394, 24), // "currentQueueIndexChanged"
QT_MOC_LITERAL(23, 419, 20), // "onMediaStatusChanged"
QT_MOC_LITERAL(24, 440, 25), // "QMediaPlayer::MediaStatus"
QT_MOC_LITERAL(25, 466, 6), // "status"
QT_MOC_LITERAL(26, 473, 13), // "onPlayerError"
QT_MOC_LITERAL(27, 487, 19), // "QMediaPlayer::Error"
QT_MOC_LITERAL(28, 507, 5), // "error"
QT_MOC_LITERAL(29, 513, 23), // "onPlayerPositionChanged"
QT_MOC_LITERAL(30, 537, 8), // "position"
QT_MOC_LITERAL(31, 546, 14), // "onPlaybackTick"
QT_MOC_LITERAL(32, 561, 9), // "loadVideo"
QT_MOC_LITERAL(33, 571, 3), // "url"
QT_MOC_LITERAL(34, 575, 14), // "extractPattern"
QT_MOC_LITERAL(35, 590, 16), // "cancelExtraction"
QT_MOC_LITERAL(36, 607, 4), // "play"
QT_MOC_LITERAL(37, 612, 5), // "pause"
QT_MOC_LITERAL(38, 618, 4), // "stop"
QT_MOC_LITERAL(39, 623, 14), // "setTargetBulbs"
QT_MOC_LITERAL(40, 638, 5), // "bulbs"
QT_MOC_LITERAL(41, 644, 16), // "clearTargetBulbs"
QT_MOC_LITERAL(42, 661, 18), // "saveCurrentPattern"
QT_MOC_LITERAL(43, 680, 4), // "name"
QT_MOC_LITERAL(44, 685, 11), // "loadPattern"
QT_MOC_LITERAL(45, 697, 13), // "deletePattern"
QT_MOC_LITERAL(46, 711, 14), // "enqueuePattern"
QT_MOC_LITERAL(47, 726, 15), // "removeFromQueue"
QT_MOC_LITERAL(48, 742, 5), // "index"
QT_MOC_LITERAL(49, 748, 10), // "clearQueue"
QT_MOC_LITERAL(50, 759, 9), // "playQueue"
QT_MOC_LITERAL(51, 769, 11), // "triggerNext"
QT_MOC_LITERAL(52, 781, 13), // "moveQueueItem"
QT_MOC_LITERAL(53, 795, 4), // "from"
QT_MOC_LITERAL(54, 800, 2), // "to"
QT_MOC_LITERAL(55, 803, 6), // "source"
QT_MOC_LITERAL(56, 810, 8), // "fileName"
QT_MOC_LITERAL(57, 819, 11), // "sampleCount"
QT_MOC_LITERAL(58, 831, 7), // "looping"
QT_MOC_LITERAL(59, 839, 10), // "extracting"
QT_MOC_LITERAL(60, 850, 18), // "extractionProgress"
QT_MOC_LITERAL(61, 869, 12), // "patternReady"
QT_MOC_LITERAL(62, 882, 17), // "patternDurationMs"
QT_MOC_LITERAL(63, 900, 17), // "patternFrameCount"
QT_MOC_LITERAL(64, 918, 7), // "playing"
QT_MOC_LITERAL(65, 926, 6), // "paused"
QT_MOC_LITERAL(66, 933, 18), // "playbackPositionMs"
QT_MOC_LITERAL(67, 952, 13), // "playbackSpeed"
QT_MOC_LITERAL(68, 966, 13), // "currentColors"
QT_MOC_LITERAL(69, 980, 15), // "targetBulbCount"
QT_MOC_LITERAL(70, 996, 13), // "statusMessage"
QT_MOC_LITERAL(71, 1010, 13), // "savedPatterns"
QT_MOC_LITERAL(72, 1024, 12), // "patternQueue"
QT_MOC_LITERAL(73, 1037, 13), // "manualAdvance"
QT_MOC_LITERAL(74, 1051, 17), // "waitingForTrigger"
QT_MOC_LITERAL(75, 1069, 17) // "currentQueueIndex"

    },
    "VideoPatternEngine\0sourceChanged\0\0"
    "sampleCountChanged\0extractingChanged\0"
    "extractionProgressChanged\0patternReadyChanged\0"
    "playStateChanged\0loopingChanged\0"
    "playbackPositionChanged\0playbackSpeedChanged\0"
    "currentColorsChanged\0targetBulbsChanged\0"
    "extractionComplete\0frameCount\0"
    "errorOccurred\0message\0statusMessageChanged\0"
    "savedPatternsChanged\0patternQueueChanged\0"
    "manualAdvanceChanged\0waitingForTriggerChanged\0"
    "currentQueueIndexChanged\0onMediaStatusChanged\0"
    "QMediaPlayer::MediaStatus\0status\0"
    "onPlayerError\0QMediaPlayer::Error\0"
    "error\0onPlayerPositionChanged\0position\0"
    "onPlaybackTick\0loadVideo\0url\0"
    "extractPattern\0cancelExtraction\0play\0"
    "pause\0stop\0setTargetBulbs\0bulbs\0"
    "clearTargetBulbs\0saveCurrentPattern\0"
    "name\0loadPattern\0deletePattern\0"
    "enqueuePattern\0removeFromQueue\0index\0"
    "clearQueue\0playQueue\0triggerNext\0"
    "moveQueueItem\0from\0to\0source\0fileName\0"
    "sampleCount\0looping\0extracting\0"
    "extractionProgress\0patternReady\0"
    "patternDurationMs\0patternFrameCount\0"
    "playing\0paused\0playbackPositionMs\0"
    "playbackSpeed\0currentColors\0targetBulbCount\0"
    "statusMessage\0savedPatterns\0patternQueue\0"
    "manualAdvance\0waitingForTrigger\0"
    "currentQueueIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoPatternEngine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
      21,  282, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      19,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  214,    2, 0x06 /* Public */,
       3,    0,  215,    2, 0x06 /* Public */,
       4,    0,  216,    2, 0x06 /* Public */,
       5,    0,  217,    2, 0x06 /* Public */,
       6,    0,  218,    2, 0x06 /* Public */,
       7,    0,  219,    2, 0x06 /* Public */,
       8,    0,  220,    2, 0x06 /* Public */,
       9,    0,  221,    2, 0x06 /* Public */,
      10,    0,  222,    2, 0x06 /* Public */,
      11,    0,  223,    2, 0x06 /* Public */,
      12,    0,  224,    2, 0x06 /* Public */,
      13,    1,  225,    2, 0x06 /* Public */,
      15,    1,  228,    2, 0x06 /* Public */,
      17,    0,  231,    2, 0x06 /* Public */,
      18,    0,  232,    2, 0x06 /* Public */,
      19,    0,  233,    2, 0x06 /* Public */,
      20,    0,  234,    2, 0x06 /* Public */,
      21,    0,  235,    2, 0x06 /* Public */,
      22,    0,  236,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    1,  237,    2, 0x08 /* Private */,
      26,    1,  240,    2, 0x08 /* Private */,
      29,    1,  243,    2, 0x08 /* Private */,
      31,    0,  246,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      32,    1,  247,    2, 0x02 /* Public */,
      34,    0,  250,    2, 0x02 /* Public */,
      35,    0,  251,    2, 0x02 /* Public */,
      36,    0,  252,    2, 0x02 /* Public */,
      37,    0,  253,    2, 0x02 /* Public */,
      38,    0,  254,    2, 0x02 /* Public */,
      39,    1,  255,    2, 0x02 /* Public */,
      41,    0,  258,    2, 0x02 /* Public */,
      42,    1,  259,    2, 0x02 /* Public */,
      44,    1,  262,    2, 0x02 /* Public */,
      45,    1,  265,    2, 0x02 /* Public */,
      46,    1,  268,    2, 0x02 /* Public */,
      47,    1,  271,    2, 0x02 /* Public */,
      49,    0,  274,    2, 0x02 /* Public */,
      50,    0,  275,    2, 0x02 /* Public */,
      51,    0,  276,    2, 0x02 /* Public */,
      52,    2,  277,    2, 0x02 /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, 0x80000000 | 27,   28,
    QMetaType::Void, QMetaType::LongLong,   30,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantList,   40,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void, QMetaType::Int,   48,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   53,   54,

 // properties: name, type, flags
      55, QMetaType::QString, 0x00495001,
      56, QMetaType::QString, 0x00495001,
      57, QMetaType::Int, 0x00495103,
      58, QMetaType::Bool, 0x00495103,
      59, QMetaType::Bool, 0x00495001,
      60, QMetaType::QReal, 0x00495001,
      61, QMetaType::Bool, 0x00495001,
      62, QMetaType::Int, 0x00495001,
      63, QMetaType::Int, 0x00495001,
      64, QMetaType::Bool, 0x00495001,
      65, QMetaType::Bool, 0x00495001,
      66, QMetaType::Int, 0x00495103,
      67, QMetaType::QReal, 0x00495103,
      68, QMetaType::QVariantList, 0x00495001,
      69, QMetaType::Int, 0x00495001,
      70, QMetaType::QString, 0x00495001,
      71, QMetaType::QStringList, 0x00495001,
      72, QMetaType::QStringList, 0x00495001,
      73, QMetaType::Bool, 0x00495103,
      74, QMetaType::Bool, 0x00495001,
      75, QMetaType::Int, 0x00495001,

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
      15,
      16,
      17,
      18,

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
        case 15: _t->patternQueueChanged(); break;
        case 16: _t->manualAdvanceChanged(); break;
        case 17: _t->waitingForTriggerChanged(); break;
        case 18: _t->currentQueueIndexChanged(); break;
        case 19: _t->onMediaStatusChanged((*reinterpret_cast< QMediaPlayer::MediaStatus(*)>(_a[1]))); break;
        case 20: _t->onPlayerError((*reinterpret_cast< QMediaPlayer::Error(*)>(_a[1]))); break;
        case 21: _t->onPlayerPositionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 22: _t->onPlaybackTick(); break;
        case 23: _t->loadVideo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: _t->extractPattern(); break;
        case 25: _t->cancelExtraction(); break;
        case 26: _t->play(); break;
        case 27: _t->pause(); break;
        case 28: _t->stop(); break;
        case 29: _t->setTargetBulbs((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 30: _t->clearTargetBulbs(); break;
        case 31: _t->saveCurrentPattern((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->loadPattern((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 33: _t->deletePattern((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->enqueuePattern((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 35: _t->removeFromQueue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->clearQueue(); break;
        case 37: _t->playQueue(); break;
        case 38: _t->triggerNext(); break;
        case 39: _t->moveQueueItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::MediaStatus >(); break;
            }
            break;
        case 20:
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
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::patternQueueChanged)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::manualAdvanceChanged)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::waitingForTriggerChanged)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (VideoPatternEngine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPatternEngine::currentQueueIndexChanged)) {
                *result = 18;
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
        case 17: *reinterpret_cast< QStringList*>(_v) = _t->patternQueue(); break;
        case 18: *reinterpret_cast< bool*>(_v) = _t->isManualAdvance(); break;
        case 19: *reinterpret_cast< bool*>(_v) = _t->isWaitingForTrigger(); break;
        case 20: *reinterpret_cast< int*>(_v) = _t->currentQueueIndex(); break;
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
        case 18: _t->setManualAdvance(*reinterpret_cast< bool*>(_v)); break;
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
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 21;
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

// SIGNAL 15
void VideoPatternEngine::patternQueueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void VideoPatternEngine::manualAdvanceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void VideoPatternEngine::waitingForTriggerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void VideoPatternEngine::currentQueueIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
