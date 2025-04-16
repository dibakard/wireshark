/****************************************************************************
** Meta object code from reading C++ file 'extcap_argument.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/extcap_argument.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'extcap_argument.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ExtcapArgument_t {
    const uint offsetsAndSize[14];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ExtcapArgument_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ExtcapArgument_t qt_meta_stringdata_ExtcapArgument = {
    {
QT_MOC_LITERAL(0, 14), // "ExtcapArgument"
QT_MOC_LITERAL(15, 12), // "valueChanged"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 15), // "setDefaultValue"
QT_MOC_LITERAL(45, 13), // "onBoolChanged"
QT_MOC_LITERAL(59, 12), // "onIntChanged"
QT_MOC_LITERAL(72, 15) // "onStringChanged"

    },
    "ExtcapArgument\0valueChanged\0\0"
    "setDefaultValue\0onBoolChanged\0"
    "onIntChanged\0onStringChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExtcapArgument[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   45,    2, 0x0a,    2 /* Public */,
       4,    1,   46,    2, 0x0a,    3 /* Public */,
       5,    1,   49,    2, 0x0a,    5 /* Public */,
       6,    1,   52,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void ExtcapArgument::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExtcapArgument *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged(); break;
        case 1: _t->setDefaultValue(); break;
        case 2: _t->onBoolChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->onIntChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->onStringChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ExtcapArgument::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExtcapArgument::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ExtcapArgument::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ExtcapArgument.offsetsAndSize,
    qt_meta_data_ExtcapArgument,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ExtcapArgument_t
, QtPrivate::TypeAndForceComplete<ExtcapArgument, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *ExtcapArgument::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExtcapArgument::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExtcapArgument.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ExtcapArgument::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ExtcapArgument::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_ExtArgText_t {
    const uint offsetsAndSize[6];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ExtArgText_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ExtArgText_t qt_meta_stringdata_ExtArgText = {
    {
QT_MOC_LITERAL(0, 10), // "ExtArgText"
QT_MOC_LITERAL(11, 15), // "setDefaultValue"
QT_MOC_LITERAL(27, 0) // ""

    },
    "ExtArgText\0setDefaultValue\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExtArgText[] = {

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

void ExtArgText::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExtArgText *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setDefaultValue(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject ExtArgText::staticMetaObject = { {
    QMetaObject::SuperData::link<ExtcapArgument::staticMetaObject>(),
    qt_meta_stringdata_ExtArgText.offsetsAndSize,
    qt_meta_data_ExtArgText,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ExtArgText_t
, QtPrivate::TypeAndForceComplete<ExtArgText, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ExtArgText::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExtArgText::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExtArgText.stringdata0))
        return static_cast<void*>(this);
    return ExtcapArgument::qt_metacast(_clname);
}

int ExtArgText::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ExtcapArgument::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_ExtArgNumber_t {
    const uint offsetsAndSize[2];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ExtArgNumber_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ExtArgNumber_t qt_meta_stringdata_ExtArgNumber = {
    {
QT_MOC_LITERAL(0, 12) // "ExtArgNumber"

    },
    "ExtArgNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExtArgNumber[] = {

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

void ExtArgNumber::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject ExtArgNumber::staticMetaObject = { {
    QMetaObject::SuperData::link<ExtArgText::staticMetaObject>(),
    qt_meta_stringdata_ExtArgNumber.offsetsAndSize,
    qt_meta_data_ExtArgNumber,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ExtArgNumber_t
, QtPrivate::TypeAndForceComplete<ExtArgNumber, std::true_type>



>,
    nullptr
} };


const QMetaObject *ExtArgNumber::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExtArgNumber::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExtArgNumber.stringdata0))
        return static_cast<void*>(this);
    return ExtArgText::qt_metacast(_clname);
}

int ExtArgNumber::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ExtArgText::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ExtArgSelector_t {
    const uint offsetsAndSize[8];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ExtArgSelector_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ExtArgSelector_t qt_meta_stringdata_ExtArgSelector = {
    {
QT_MOC_LITERAL(0, 14), // "ExtArgSelector"
QT_MOC_LITERAL(15, 15), // "setDefaultValue"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 17) // "onReloadTriggered"

    },
    "ExtArgSelector\0setDefaultValue\0\0"
    "onReloadTriggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExtArgSelector[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x0a,    1 /* Public */,
       3,    0,   27,    2, 0x08,    2 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ExtArgSelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExtArgSelector *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setDefaultValue(); break;
        case 1: _t->onReloadTriggered(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject ExtArgSelector::staticMetaObject = { {
    QMetaObject::SuperData::link<ExtcapArgument::staticMetaObject>(),
    qt_meta_stringdata_ExtArgSelector.offsetsAndSize,
    qt_meta_data_ExtArgSelector,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ExtArgSelector_t
, QtPrivate::TypeAndForceComplete<ExtArgSelector, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ExtArgSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExtArgSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExtArgSelector.stringdata0))
        return static_cast<void*>(this);
    return ExtcapArgument::qt_metacast(_clname);
}

int ExtArgSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ExtcapArgument::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_ExtArgEditSelector_t {
    const uint offsetsAndSize[6];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ExtArgEditSelector_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ExtArgEditSelector_t qt_meta_stringdata_ExtArgEditSelector = {
    {
QT_MOC_LITERAL(0, 18), // "ExtArgEditSelector"
QT_MOC_LITERAL(19, 15), // "setDefaultValue"
QT_MOC_LITERAL(35, 0) // ""

    },
    "ExtArgEditSelector\0setDefaultValue\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExtArgEditSelector[] = {

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

void ExtArgEditSelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExtArgEditSelector *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setDefaultValue(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject ExtArgEditSelector::staticMetaObject = { {
    QMetaObject::SuperData::link<ExtArgSelector::staticMetaObject>(),
    qt_meta_stringdata_ExtArgEditSelector.offsetsAndSize,
    qt_meta_data_ExtArgEditSelector,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ExtArgEditSelector_t
, QtPrivate::TypeAndForceComplete<ExtArgEditSelector, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ExtArgEditSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExtArgEditSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExtArgEditSelector.stringdata0))
        return static_cast<void*>(this);
    return ExtArgSelector::qt_metacast(_clname);
}

int ExtArgEditSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ExtArgSelector::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_ExtArgRadio_t {
    const uint offsetsAndSize[6];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ExtArgRadio_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ExtArgRadio_t qt_meta_stringdata_ExtArgRadio = {
    {
QT_MOC_LITERAL(0, 11), // "ExtArgRadio"
QT_MOC_LITERAL(12, 15), // "setDefaultValue"
QT_MOC_LITERAL(28, 0) // ""

    },
    "ExtArgRadio\0setDefaultValue\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExtArgRadio[] = {

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

void ExtArgRadio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExtArgRadio *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setDefaultValue(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject ExtArgRadio::staticMetaObject = { {
    QMetaObject::SuperData::link<ExtcapArgument::staticMetaObject>(),
    qt_meta_stringdata_ExtArgRadio.offsetsAndSize,
    qt_meta_data_ExtArgRadio,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ExtArgRadio_t
, QtPrivate::TypeAndForceComplete<ExtArgRadio, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ExtArgRadio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExtArgRadio::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExtArgRadio.stringdata0))
        return static_cast<void*>(this);
    return ExtcapArgument::qt_metacast(_clname);
}

int ExtArgRadio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ExtcapArgument::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_ExtArgBool_t {
    const uint offsetsAndSize[6];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ExtArgBool_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ExtArgBool_t qt_meta_stringdata_ExtArgBool = {
    {
QT_MOC_LITERAL(0, 10), // "ExtArgBool"
QT_MOC_LITERAL(11, 15), // "setDefaultValue"
QT_MOC_LITERAL(27, 0) // ""

    },
    "ExtArgBool\0setDefaultValue\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExtArgBool[] = {

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

void ExtArgBool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExtArgBool *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setDefaultValue(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject ExtArgBool::staticMetaObject = { {
    QMetaObject::SuperData::link<ExtcapArgument::staticMetaObject>(),
    qt_meta_stringdata_ExtArgBool.offsetsAndSize,
    qt_meta_data_ExtArgBool,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ExtArgBool_t
, QtPrivate::TypeAndForceComplete<ExtArgBool, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ExtArgBool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExtArgBool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExtArgBool.stringdata0))
        return static_cast<void*>(this);
    return ExtcapArgument::qt_metacast(_clname);
}

int ExtArgBool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ExtcapArgument::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_ExtArgTimestamp_t {
    const uint offsetsAndSize[8];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ExtArgTimestamp_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ExtArgTimestamp_t qt_meta_stringdata_ExtArgTimestamp = {
    {
QT_MOC_LITERAL(0, 15), // "ExtArgTimestamp"
QT_MOC_LITERAL(16, 15), // "setDefaultValue"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 17) // "onDateTimeChanged"

    },
    "ExtArgTimestamp\0setDefaultValue\0\0"
    "onDateTimeChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExtArgTimestamp[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x0a,    1 /* Public */,
       3,    1,   27,    2, 0x08,    2 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,    2,

       0        // eod
};

void ExtArgTimestamp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExtArgTimestamp *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setDefaultValue(); break;
        case 1: _t->onDateTimeChanged((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ExtArgTimestamp::staticMetaObject = { {
    QMetaObject::SuperData::link<ExtcapArgument::staticMetaObject>(),
    qt_meta_stringdata_ExtArgTimestamp.offsetsAndSize,
    qt_meta_data_ExtArgTimestamp,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ExtArgTimestamp_t
, QtPrivate::TypeAndForceComplete<ExtArgTimestamp, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDateTime, std::false_type>


>,
    nullptr
} };


const QMetaObject *ExtArgTimestamp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExtArgTimestamp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExtArgTimestamp.stringdata0))
        return static_cast<void*>(this);
    return ExtcapArgument::qt_metacast(_clname);
}

int ExtArgTimestamp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ExtcapArgument::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
