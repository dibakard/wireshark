/****************************************************************************
** Meta object code from reading C++ file 'capture_file.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/capture_file.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'capture_file.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CaptureFile_t {
    const uint offsetsAndSize[18];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CaptureFile_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CaptureFile_t qt_meta_stringdata_CaptureFile = {
    {
QT_MOC_LITERAL(0, 11), // "CaptureFile"
QT_MOC_LITERAL(12, 12), // "captureEvent"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 12), // "CaptureEvent"
QT_MOC_LITERAL(39, 12), // "retapPackets"
QT_MOC_LITERAL(52, 19), // "delayedRetapPackets"
QT_MOC_LITERAL(72, 11), // "stopLoading"
QT_MOC_LITERAL(84, 18), // "setCaptureStopFlag"
QT_MOC_LITERAL(103, 9) // "stop_flag"

    },
    "CaptureFile\0captureEvent\0\0CaptureEvent\0"
    "retapPackets\0delayedRetapPackets\0"
    "stopLoading\0setCaptureStopFlag\0stop_flag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CaptureFile[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   53,    2, 0x0a,    3 /* Public */,
       5,    0,   54,    2, 0x0a,    4 /* Public */,
       6,    0,   55,    2, 0x0a,    5 /* Public */,
       7,    1,   56,    2, 0x0a,    6 /* Public */,
       7,    0,   59,    2, 0x2a,    8 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,

       0        // eod
};

void CaptureFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CaptureFile *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->captureEvent((*reinterpret_cast< std::add_pointer_t<CaptureEvent>>(_a[1]))); break;
        case 1: _t->retapPackets(); break;
        case 2: _t->delayedRetapPackets(); break;
        case 3: _t->stopLoading(); break;
        case 4: _t->setCaptureStopFlag((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->setCaptureStopFlag(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CaptureFile::*)(CaptureEvent );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureFile::captureEvent)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CaptureFile::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CaptureFile.offsetsAndSize,
    qt_meta_data_CaptureFile,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CaptureFile_t
, QtPrivate::TypeAndForceComplete<CaptureFile, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<CaptureEvent, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CaptureFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CaptureFile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CaptureFile.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CaptureFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CaptureFile::captureEvent(CaptureEvent _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
