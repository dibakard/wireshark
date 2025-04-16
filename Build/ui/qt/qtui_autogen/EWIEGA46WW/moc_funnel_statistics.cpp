/****************************************************************************
** Meta object code from reading C++ file 'funnel_statistics.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/funnel_statistics.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'funnel_statistics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FunnelStatistics_t {
    const uint offsetsAndSize[24];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FunnelStatistics_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FunnelStatistics_t qt_meta_stringdata_FunnelStatistics = {
    {
QT_MOC_LITERAL(0, 16), // "FunnelStatistics"
QT_MOC_LITERAL(17, 15), // "openCaptureFile"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 7), // "cf_path"
QT_MOC_LITERAL(42, 6), // "filter"
QT_MOC_LITERAL(49, 16), // "setDisplayFilter"
QT_MOC_LITERAL(66, 20), // "FilterAction::Action"
QT_MOC_LITERAL(87, 6), // "action"
QT_MOC_LITERAL(94, 24), // "FilterAction::ActionType"
QT_MOC_LITERAL(119, 10), // "filterType"
QT_MOC_LITERAL(130, 21), // "funnelActionTriggered"
QT_MOC_LITERAL(152, 24) // "displayFilterTextChanged"

    },
    "FunnelStatistics\0openCaptureFile\0\0"
    "cf_path\0filter\0setDisplayFilter\0"
    "FilterAction::Action\0action\0"
    "FilterAction::ActionType\0filterType\0"
    "funnelActionTriggered\0displayFilterTextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FunnelStatistics[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   38,    2, 0x06,    1 /* Public */,
       5,    3,   43,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,   50,    2, 0x0a,    8 /* Public */,
      11,    1,   51,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6, 0x80000000 | 8,    4,    7,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void FunnelStatistics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FunnelStatistics *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openCaptureFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->setDisplayFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<FilterAction::Action>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<FilterAction::ActionType>>(_a[3]))); break;
        case 2: _t->funnelActionTriggered(); break;
        case 3: _t->displayFilterTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FunnelStatistics::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FunnelStatistics::openCaptureFile)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FunnelStatistics::*)(QString , FilterAction::Action , FilterAction::ActionType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FunnelStatistics::setDisplayFilter)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FunnelStatistics::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FunnelStatistics.offsetsAndSize,
    qt_meta_data_FunnelStatistics,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FunnelStatistics_t
, QtPrivate::TypeAndForceComplete<FunnelStatistics, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::Action, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::ActionType, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *FunnelStatistics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FunnelStatistics::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FunnelStatistics.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FunnelStatistics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void FunnelStatistics::openCaptureFile(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FunnelStatistics::setDisplayFilter(QString _t1, FilterAction::Action _t2, FilterAction::ActionType _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_FunnelAction_t {
    const uint offsetsAndSize[6];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FunnelAction_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FunnelAction_t qt_meta_stringdata_FunnelAction = {
    {
QT_MOC_LITERAL(0, 12), // "FunnelAction"
QT_MOC_LITERAL(13, 21), // "triggerPacketCallback"
QT_MOC_LITERAL(35, 0) // ""

    },
    "FunnelAction\0triggerPacketCallback\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FunnelAction[] = {

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
       1,    0,   20,    2, 0x0a,    1 /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void FunnelAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FunnelAction *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->triggerPacketCallback(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject FunnelAction::staticMetaObject = { {
    QMetaObject::SuperData::link<QAction::staticMetaObject>(),
    qt_meta_stringdata_FunnelAction.offsetsAndSize,
    qt_meta_data_FunnelAction,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FunnelAction_t
, QtPrivate::TypeAndForceComplete<FunnelAction, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FunnelAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FunnelAction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FunnelAction.stringdata0))
        return static_cast<void*>(this);
    return QAction::qt_metacast(_clname);
}

int FunnelAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAction::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_FunnelConsoleAction_t {
    const uint offsetsAndSize[2];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FunnelConsoleAction_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FunnelConsoleAction_t qt_meta_stringdata_FunnelConsoleAction = {
    {
QT_MOC_LITERAL(0, 19) // "FunnelConsoleAction"

    },
    "FunnelConsoleAction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FunnelConsoleAction[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void FunnelConsoleAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject FunnelConsoleAction::staticMetaObject = { {
    QMetaObject::SuperData::link<FunnelAction::staticMetaObject>(),
    qt_meta_stringdata_FunnelConsoleAction.offsetsAndSize,
    qt_meta_data_FunnelConsoleAction,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FunnelConsoleAction_t
, QtPrivate::TypeAndForceComplete<FunnelConsoleAction, std::true_type>



>,
    nullptr
} };


const QMetaObject *FunnelConsoleAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FunnelConsoleAction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FunnelConsoleAction.stringdata0))
        return static_cast<void*>(this);
    return FunnelAction::qt_metacast(_clname);
}

int FunnelConsoleAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = FunnelAction::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
