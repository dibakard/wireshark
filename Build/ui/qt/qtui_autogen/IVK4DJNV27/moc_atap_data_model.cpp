/****************************************************************************
** Meta object code from reading C++ file 'atap_data_model.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/models/atap_data_model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'atap_data_model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ATapDataModel_t {
    const uint offsetsAndSize[8];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ATapDataModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ATapDataModel_t qt_meta_stringdata_ATapDataModel = {
    {
QT_MOC_LITERAL(0, 13), // "ATapDataModel"
QT_MOC_LITERAL(14, 18), // "tapListenerChanged"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 6) // "enable"

    },
    "ATapDataModel\0tapListenerChanged\0\0"
    "enable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ATapDataModel[] = {

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
       1,    1,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void ATapDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ATapDataModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->tapListenerChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ATapDataModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ATapDataModel::tapListenerChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ATapDataModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_ATapDataModel.offsetsAndSize,
    qt_meta_data_ATapDataModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ATapDataModel_t
, QtPrivate::TypeAndForceComplete<ATapDataModel, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>



>,
    nullptr
} };


const QMetaObject *ATapDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ATapDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ATapDataModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int ATapDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
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
void ATapDataModel::tapListenerChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_EndpointDataModel_t {
    const uint offsetsAndSize[2];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_EndpointDataModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_EndpointDataModel_t qt_meta_stringdata_EndpointDataModel = {
    {
QT_MOC_LITERAL(0, 17) // "EndpointDataModel"

    },
    "EndpointDataModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EndpointDataModel[] = {

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

void EndpointDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject EndpointDataModel::staticMetaObject = { {
    QMetaObject::SuperData::link<ATapDataModel::staticMetaObject>(),
    qt_meta_stringdata_EndpointDataModel.offsetsAndSize,
    qt_meta_data_EndpointDataModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_EndpointDataModel_t
, QtPrivate::TypeAndForceComplete<EndpointDataModel, std::true_type>



>,
    nullptr
} };


const QMetaObject *EndpointDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EndpointDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EndpointDataModel.stringdata0))
        return static_cast<void*>(this);
    return ATapDataModel::qt_metacast(_clname);
}

int EndpointDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ATapDataModel::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ConversationDataModel_t {
    const uint offsetsAndSize[2];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ConversationDataModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ConversationDataModel_t qt_meta_stringdata_ConversationDataModel = {
    {
QT_MOC_LITERAL(0, 21) // "ConversationDataModel"

    },
    "ConversationDataModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConversationDataModel[] = {

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

void ConversationDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject ConversationDataModel::staticMetaObject = { {
    QMetaObject::SuperData::link<ATapDataModel::staticMetaObject>(),
    qt_meta_stringdata_ConversationDataModel.offsetsAndSize,
    qt_meta_data_ConversationDataModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ConversationDataModel_t
, QtPrivate::TypeAndForceComplete<ConversationDataModel, std::true_type>



>,
    nullptr
} };


const QMetaObject *ConversationDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConversationDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConversationDataModel.stringdata0))
        return static_cast<void*>(this);
    return ATapDataModel::qt_metacast(_clname);
}

int ConversationDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ATapDataModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
