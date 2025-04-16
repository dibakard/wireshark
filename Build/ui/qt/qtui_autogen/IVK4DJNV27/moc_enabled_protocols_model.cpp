/****************************************************************************
** Meta object code from reading C++ file 'enabled_protocols_model.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/models/enabled_protocols_model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enabled_protocols_model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EnabledProtocolItem_t {
    const uint offsetsAndSize[10];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_EnabledProtocolItem_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_EnabledProtocolItem_t qt_meta_stringdata_EnabledProtocolItem = {
    {
QT_MOC_LITERAL(0, 19), // "EnabledProtocolItem"
QT_MOC_LITERAL(20, 18), // "EnableProtocolType"
QT_MOC_LITERAL(39, 3), // "Any"
QT_MOC_LITERAL(43, 8), // "Standard"
QT_MOC_LITERAL(52, 9) // "Heuristic"

    },
    "EnabledProtocolItem\0EnableProtocolType\0"
    "Any\0Standard\0Heuristic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EnabledProtocolItem[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    3,   19,

 // enum data: key, value
       2, uint(EnabledProtocolItem::Any),
       3, uint(EnabledProtocolItem::Standard),
       4, uint(EnabledProtocolItem::Heuristic),

       0        // eod
};

const QMetaObject EnabledProtocolItem::staticMetaObject = { {
    QtPrivate::MetaObjectForType<ModelHelperTreeItem<EnabledProtocolItem>>::value(),
    qt_meta_stringdata_EnabledProtocolItem.offsetsAndSize,
    qt_meta_data_EnabledProtocolItem,
    nullptr,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_EnabledProtocolItem_t
, QtPrivate::TypeAndForceComplete<EnabledProtocolItem, std::true_type>



>,
    nullptr
} };

struct qt_meta_stringdata_EnabledProtocolsModel_t {
    const uint offsetsAndSize[2];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_EnabledProtocolsModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_EnabledProtocolsModel_t qt_meta_stringdata_EnabledProtocolsModel = {
    {
QT_MOC_LITERAL(0, 21) // "EnabledProtocolsModel"

    },
    "EnabledProtocolsModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EnabledProtocolsModel[] = {

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

void EnabledProtocolsModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject EnabledProtocolsModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractItemModel::staticMetaObject>(),
    qt_meta_stringdata_EnabledProtocolsModel.offsetsAndSize,
    qt_meta_data_EnabledProtocolsModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_EnabledProtocolsModel_t
, QtPrivate::TypeAndForceComplete<EnabledProtocolsModel, std::true_type>



>,
    nullptr
} };


const QMetaObject *EnabledProtocolsModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EnabledProtocolsModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EnabledProtocolsModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int EnabledProtocolsModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_EnabledProtocolsProxyModel_t {
    const uint offsetsAndSize[14];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_EnabledProtocolsProxyModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_EnabledProtocolsProxyModel_t qt_meta_stringdata_EnabledProtocolsProxyModel = {
    {
QT_MOC_LITERAL(0, 26), // "EnabledProtocolsProxyModel"
QT_MOC_LITERAL(27, 10), // "SearchType"
QT_MOC_LITERAL(38, 10), // "EveryWhere"
QT_MOC_LITERAL(49, 12), // "OnlyProtocol"
QT_MOC_LITERAL(62, 15), // "OnlyDescription"
QT_MOC_LITERAL(78, 12), // "EnabledItems"
QT_MOC_LITERAL(91, 13) // "DisabledItems"

    },
    "EnabledProtocolsProxyModel\0SearchType\0"
    "EveryWhere\0OnlyProtocol\0OnlyDescription\0"
    "EnabledItems\0DisabledItems"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EnabledProtocolsProxyModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    5,   19,

 // enum data: key, value
       2, uint(EnabledProtocolsProxyModel::EveryWhere),
       3, uint(EnabledProtocolsProxyModel::OnlyProtocol),
       4, uint(EnabledProtocolsProxyModel::OnlyDescription),
       5, uint(EnabledProtocolsProxyModel::EnabledItems),
       6, uint(EnabledProtocolsProxyModel::DisabledItems),

       0        // eod
};

void EnabledProtocolsProxyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject EnabledProtocolsProxyModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSortFilterProxyModel::staticMetaObject>(),
    qt_meta_stringdata_EnabledProtocolsProxyModel.offsetsAndSize,
    qt_meta_data_EnabledProtocolsProxyModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_EnabledProtocolsProxyModel_t
, QtPrivate::TypeAndForceComplete<EnabledProtocolsProxyModel, std::true_type>



>,
    nullptr
} };


const QMetaObject *EnabledProtocolsProxyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EnabledProtocolsProxyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EnabledProtocolsProxyModel.stringdata0))
        return static_cast<void*>(this);
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int EnabledProtocolsProxyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
