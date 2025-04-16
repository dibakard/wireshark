/****************************************************************************
** Meta object code from reading C++ file 'manuf_table_model.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/models/manuf_table_model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manuf_table_model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManufTableModel_t {
    const uint offsetsAndSize[2];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ManufTableModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ManufTableModel_t qt_meta_stringdata_ManufTableModel = {
    {
QT_MOC_LITERAL(0, 15) // "ManufTableModel"

    },
    "ManufTableModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManufTableModel[] = {

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

void ManufTableModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject ManufTableModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_ManufTableModel.offsetsAndSize,
    qt_meta_data_ManufTableModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ManufTableModel_t
, QtPrivate::TypeAndForceComplete<ManufTableModel, std::true_type>



>,
    nullptr
} };


const QMetaObject *ManufTableModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManufTableModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManufTableModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int ManufTableModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ManufSortFilterProxyModel_t {
    const uint offsetsAndSize[20];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ManufSortFilterProxyModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ManufSortFilterProxyModel_t qt_meta_stringdata_ManufSortFilterProxyModel = {
    {
QT_MOC_LITERAL(0, 25), // "ManufSortFilterProxyModel"
QT_MOC_LITERAL(26, 16), // "setFilterAddress"
QT_MOC_LITERAL(43, 0), // ""
QT_MOC_LITERAL(44, 13), // "setFilterName"
QT_MOC_LITERAL(58, 19), // "QRegularExpression&"
QT_MOC_LITERAL(78, 11), // "clearFilter"
QT_MOC_LITERAL(90, 20), // "ManufProxyFilterType"
QT_MOC_LITERAL(111, 11), // "FilterEmpty"
QT_MOC_LITERAL(123, 15), // "FilterByAddress"
QT_MOC_LITERAL(139, 12) // "FilterByName"

    },
    "ManufSortFilterProxyModel\0setFilterAddress\0"
    "\0setFilterName\0QRegularExpression&\0"
    "clearFilter\0ManufProxyFilterType\0"
    "FilterEmpty\0FilterByAddress\0FilterByName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManufSortFilterProxyModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       1,   39, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x0a,    1 /* Public */,
       3,    1,   35,    2, 0x0a,    3 /* Public */,
       5,    0,   38,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
       6,    6, 0x0,    3,   44,

 // enum data: key, value
       7, uint(ManufSortFilterProxyModel::FilterEmpty),
       8, uint(ManufSortFilterProxyModel::FilterByAddress),
       9, uint(ManufSortFilterProxyModel::FilterByName),

       0        // eod
};

void ManufSortFilterProxyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ManufSortFilterProxyModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setFilterAddress((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 1: _t->setFilterName((*reinterpret_cast< std::add_pointer_t<QRegularExpression&>>(_a[1]))); break;
        case 2: _t->clearFilter(); break;
        default: ;
        }
    }
}

const QMetaObject ManufSortFilterProxyModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSortFilterProxyModel::staticMetaObject>(),
    qt_meta_stringdata_ManufSortFilterProxyModel.offsetsAndSize,
    qt_meta_data_ManufSortFilterProxyModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ManufSortFilterProxyModel_t
, QtPrivate::TypeAndForceComplete<ManufSortFilterProxyModel, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QRegularExpression &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ManufSortFilterProxyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManufSortFilterProxyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManufSortFilterProxyModel.stringdata0))
        return static_cast<void*>(this);
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int ManufSortFilterProxyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
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
