/****************************************************************************
** Meta object code from reading C++ file 'splash_overlay.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/splash_overlay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'splash_overlay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SplashOverlay_t {
    const uint offsetsAndSize[14];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SplashOverlay_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SplashOverlay_t qt_meta_stringdata_SplashOverlay = {
    {
QT_MOC_LITERAL(0, 13), // "SplashOverlay"
QT_MOC_LITERAL(14, 12), // "splashUpdate"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 17), // "register_action_e"
QT_MOC_LITERAL(46, 6), // "action"
QT_MOC_LITERAL(53, 11), // "const char*"
QT_MOC_LITERAL(65, 7) // "message"

    },
    "SplashOverlay\0splashUpdate\0\0"
    "register_action_e\0action\0const char*\0"
    "message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SplashOverlay[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

       0        // eod
};

void SplashOverlay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SplashOverlay *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->splashUpdate((*reinterpret_cast< std::add_pointer_t<register_action_e>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<const char*>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject SplashOverlay::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_SplashOverlay.offsetsAndSize,
    qt_meta_data_SplashOverlay,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SplashOverlay_t
, QtPrivate::TypeAndForceComplete<SplashOverlay, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<register_action_e, std::false_type>, QtPrivate::TypeAndForceComplete<const char *, std::false_type>


>,
    nullptr
} };


const QMetaObject *SplashOverlay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SplashOverlay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SplashOverlay.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SplashOverlay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
