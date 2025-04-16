/****************************************************************************
** Meta object code from reading C++ file 'glib_mainloop_on_qeventloop.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/glib_mainloop_on_qeventloop.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glib_mainloop_on_qeventloop.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GLibPoller_t {
    const uint offsetsAndSize[6];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GLibPoller_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GLibPoller_t qt_meta_stringdata_GLibPoller = {
    {
QT_MOC_LITERAL(0, 10), // "GLibPoller"
QT_MOC_LITERAL(11, 6), // "polled"
QT_MOC_LITERAL(18, 0) // ""

    },
    "GLibPoller\0polled\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GLibPoller[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void GLibPoller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GLibPoller *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->polled(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GLibPoller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLibPoller::polled)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject GLibPoller::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_GLibPoller.offsetsAndSize,
    qt_meta_data_GLibPoller,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_GLibPoller_t
, QtPrivate::TypeAndForceComplete<GLibPoller, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>



>,
    nullptr
} };


const QMetaObject *GLibPoller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GLibPoller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GLibPoller.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int GLibPoller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void GLibPoller::polled()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_GLibMainloopOnQEventLoop_t {
    const uint offsetsAndSize[6];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GLibMainloopOnQEventLoop_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GLibMainloopOnQEventLoop_t qt_meta_stringdata_GLibMainloopOnQEventLoop = {
    {
QT_MOC_LITERAL(0, 24), // "GLibMainloopOnQEventLoop"
QT_MOC_LITERAL(25, 16), // "checkAndDispatch"
QT_MOC_LITERAL(42, 0) // ""

    },
    "GLibMainloopOnQEventLoop\0checkAndDispatch\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GLibMainloopOnQEventLoop[] = {

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
       1,    0,   20,    2, 0x09,    1 /* Protected */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void GLibMainloopOnQEventLoop::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GLibMainloopOnQEventLoop *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->checkAndDispatch(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject GLibMainloopOnQEventLoop::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_GLibMainloopOnQEventLoop.offsetsAndSize,
    qt_meta_data_GLibMainloopOnQEventLoop,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_GLibMainloopOnQEventLoop_t
, QtPrivate::TypeAndForceComplete<GLibMainloopOnQEventLoop, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *GLibMainloopOnQEventLoop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GLibMainloopOnQEventLoop::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GLibMainloopOnQEventLoop.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GLibMainloopOnQEventLoop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
