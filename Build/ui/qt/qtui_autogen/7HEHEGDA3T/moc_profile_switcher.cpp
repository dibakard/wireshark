/****************************************************************************
** Meta object code from reading C++ file 'profile_switcher.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/utils/profile_switcher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profile_switcher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProfileSwitcher_t {
    const uint offsetsAndSize[26];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ProfileSwitcher_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ProfileSwitcher_t qt_meta_stringdata_ProfileSwitcher = {
    {
QT_MOC_LITERAL(0, 15), // "ProfileSwitcher"
QT_MOC_LITERAL(16, 19), // "captureEventHandler"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 12), // "CaptureEvent"
QT_MOC_LITERAL(50, 2), // "ev"
QT_MOC_LITERAL(53, 11), // "checkPacket"
QT_MOC_LITERAL(65, 13), // "capture_file*"
QT_MOC_LITERAL(79, 8), // "cap_file"
QT_MOC_LITERAL(88, 11), // "frame_data*"
QT_MOC_LITERAL(100, 5), // "fdata"
QT_MOC_LITERAL(106, 9), // "qsizetype"
QT_MOC_LITERAL(116, 3), // "row"
QT_MOC_LITERAL(120, 16) // "disableSwitching"

    },
    "ProfileSwitcher\0captureEventHandler\0"
    "\0CaptureEvent\0ev\0checkPacket\0capture_file*\0"
    "cap_file\0frame_data*\0fdata\0qsizetype\0"
    "row\0disableSwitching"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProfileSwitcher[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x0a,    1 /* Public */,
       5,    3,   35,    2, 0x0a,    3 /* Public */,
      12,    0,   42,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 10,    7,    9,   11,
    QMetaType::Void,

       0        // eod
};

void ProfileSwitcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProfileSwitcher *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->captureEventHandler((*reinterpret_cast< std::add_pointer_t<CaptureEvent>>(_a[1]))); break;
        case 1: _t->checkPacket((*reinterpret_cast< std::add_pointer_t<capture_file*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<frame_data*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qsizetype>>(_a[3]))); break;
        case 2: _t->disableSwitching(); break;
        default: ;
        }
    }
}

const QMetaObject ProfileSwitcher::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ProfileSwitcher.offsetsAndSize,
    qt_meta_data_ProfileSwitcher,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ProfileSwitcher_t
, QtPrivate::TypeAndForceComplete<ProfileSwitcher, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<CaptureEvent, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_file *, std::false_type>, QtPrivate::TypeAndForceComplete<frame_data *, std::false_type>, QtPrivate::TypeAndForceComplete<qsizetype, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ProfileSwitcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProfileSwitcher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProfileSwitcher.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ProfileSwitcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
