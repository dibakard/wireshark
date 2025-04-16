/****************************************************************************
** Meta object code from reading C++ file 'rtp_audio_stream.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/rtp_audio_stream.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rtp_audio_stream.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RtpAudioStream_t {
    const uint offsetsAndSize[30];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_RtpAudioStream_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_RtpAudioStream_t qt_meta_stringdata_RtpAudioStream = {
    {
QT_MOC_LITERAL(0, 14), // "RtpAudioStream"
QT_MOC_LITERAL(15, 13), // "processedSecs"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 4), // "secs"
QT_MOC_LITERAL(35, 13), // "playbackError"
QT_MOC_LITERAL(49, 9), // "error_msg"
QT_MOC_LITERAL(59, 15), // "finishedPlaying"
QT_MOC_LITERAL(75, 15), // "RtpAudioStream*"
QT_MOC_LITERAL(91, 6), // "stream"
QT_MOC_LITERAL(98, 13), // "QAudio::Error"
QT_MOC_LITERAL(112, 5), // "error"
QT_MOC_LITERAL(118, 18), // "outputStateChanged"
QT_MOC_LITERAL(137, 13), // "QAudio::State"
QT_MOC_LITERAL(151, 9), // "new_state"
QT_MOC_LITERAL(161, 17) // "delayedStopStream"

    },
    "RtpAudioStream\0processedSecs\0\0secs\0"
    "playbackError\0error_msg\0finishedPlaying\0"
    "RtpAudioStream*\0stream\0QAudio::Error\0"
    "error\0outputStateChanged\0QAudio::State\0"
    "new_state\0delayedStopStream"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RtpAudioStream[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,
       4,    1,   47,    2, 0x06,    3 /* Public */,
       6,    2,   50,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    1,   55,    2, 0x08,    8 /* Private */,
      14,    0,   58,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 9,    8,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

       0        // eod
};

void RtpAudioStream::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RtpAudioStream *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->processedSecs((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 1: _t->playbackError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->finishedPlaying((*reinterpret_cast< std::add_pointer_t<RtpAudioStream*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAudio::Error>>(_a[2]))); break;
        case 3: _t->outputStateChanged((*reinterpret_cast< std::add_pointer_t<QAudio::State>>(_a[1]))); break;
        case 4: _t->delayedStopStream(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< RtpAudioStream* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RtpAudioStream::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpAudioStream::processedSecs)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RtpAudioStream::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpAudioStream::playbackError)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RtpAudioStream::*)(RtpAudioStream * , QAudio::Error );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpAudioStream::finishedPlaying)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject RtpAudioStream::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_RtpAudioStream.offsetsAndSize,
    qt_meta_data_RtpAudioStream,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RtpAudioStream_t
, QtPrivate::TypeAndForceComplete<RtpAudioStream, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<RtpAudioStream *, std::false_type>, QtPrivate::TypeAndForceComplete<QAudio::Error, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAudio::State, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *RtpAudioStream::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RtpAudioStream::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RtpAudioStream.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RtpAudioStream::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void RtpAudioStream::processedSecs(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RtpAudioStream::playbackError(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RtpAudioStream::finishedPlaying(RtpAudioStream * _t1, QAudio::Error _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
