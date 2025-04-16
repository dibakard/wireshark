/****************************************************************************
** Meta object code from reading C++ file 'astringlist_list_model.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/models/astringlist_list_model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'astringlist_list_model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AStringListListModel_t {
    const uint offsetsAndSize[2];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AStringListListModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AStringListListModel_t qt_meta_stringdata_AStringListListModel = {
    {
QT_MOC_LITERAL(0, 20) // "AStringListListModel"

    },
    "AStringListListModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AStringListListModel[] = {

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

void AStringListListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject AStringListListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_AStringListListModel.offsetsAndSize,
    qt_meta_data_AStringListListModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AStringListListModel_t
, QtPrivate::TypeAndForceComplete<AStringListListModel, std::true_type>



>,
    nullptr
} };


const QMetaObject *AStringListListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AStringListListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AStringListListModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int AStringListListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_AStringListListSortFilterProxyModel_t {
    const uint offsetsAndSize[16];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AStringListListSortFilterProxyModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AStringListListSortFilterProxyModel_t qt_meta_stringdata_AStringListListSortFilterProxyModel = {
    {
QT_MOC_LITERAL(0, 35), // "AStringListListSortFilterProx..."
QT_MOC_LITERAL(36, 9), // "setFilter"
QT_MOC_LITERAL(46, 0), // ""
QT_MOC_LITERAL(47, 25), // "AStringListListFilterType"
QT_MOC_LITERAL(73, 16), // "FilterByContains"
QT_MOC_LITERAL(90, 13), // "FilterByStart"
QT_MOC_LITERAL(104, 18), // "FilterByEquivalent"
QT_MOC_LITERAL(123, 10) // "FilterNone"

    },
    "AStringListListSortFilterProxyModel\0"
    "setFilter\0\0AStringListListFilterType\0"
    "FilterByContains\0FilterByStart\0"
    "FilterByEquivalent\0FilterNone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AStringListListSortFilterProxyModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       1,   23, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x0a,    1 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // enums: name, alias, flags, count, data
       3,    3, 0x0,    4,   28,

 // enum data: key, value
       4, uint(AStringListListSortFilterProxyModel::FilterByContains),
       5, uint(AStringListListSortFilterProxyModel::FilterByStart),
       6, uint(AStringListListSortFilterProxyModel::FilterByEquivalent),
       7, uint(AStringListListSortFilterProxyModel::FilterNone),

       0        // eod
};

void AStringListListSortFilterProxyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AStringListListSortFilterProxyModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AStringListListSortFilterProxyModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSortFilterProxyModel::staticMetaObject>(),
    qt_meta_stringdata_AStringListListSortFilterProxyModel.offsetsAndSize,
    qt_meta_data_AStringListListSortFilterProxyModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AStringListListSortFilterProxyModel_t
, QtPrivate::TypeAndForceComplete<AStringListListSortFilterProxyModel, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *AStringListListSortFilterProxyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AStringListListSortFilterProxyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AStringListListSortFilterProxyModel.stringdata0))
        return static_cast<void*>(this);
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int AStringListListSortFilterProxyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
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
