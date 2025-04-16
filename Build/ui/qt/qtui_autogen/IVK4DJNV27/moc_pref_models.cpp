/****************************************************************************
** Meta object code from reading C++ file 'pref_models.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/models/pref_models.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pref_models.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PrefsModel_t {
    const uint offsetsAndSize[2];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PrefsModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PrefsModel_t qt_meta_stringdata_PrefsModel = {
    {
QT_MOC_LITERAL(0, 10) // "PrefsModel"

    },
    "PrefsModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrefsModel[] = {

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

void PrefsModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject PrefsModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractItemModel::staticMetaObject>(),
    qt_meta_stringdata_PrefsModel.offsetsAndSize,
    qt_meta_data_PrefsModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PrefsModel_t
, QtPrivate::TypeAndForceComplete<PrefsModel, std::true_type>



>,
    nullptr
} };


const QMetaObject *PrefsModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrefsModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PrefsModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int PrefsModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_AdvancedPrefsModel_t {
    const uint offsetsAndSize[2];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AdvancedPrefsModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AdvancedPrefsModel_t qt_meta_stringdata_AdvancedPrefsModel = {
    {
QT_MOC_LITERAL(0, 18) // "AdvancedPrefsModel"

    },
    "AdvancedPrefsModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdvancedPrefsModel[] = {

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

void AdvancedPrefsModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject AdvancedPrefsModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSortFilterProxyModel::staticMetaObject>(),
    qt_meta_stringdata_AdvancedPrefsModel.offsetsAndSize,
    qt_meta_data_AdvancedPrefsModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AdvancedPrefsModel_t
, QtPrivate::TypeAndForceComplete<AdvancedPrefsModel, std::true_type>



>,
    nullptr
} };


const QMetaObject *AdvancedPrefsModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdvancedPrefsModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdvancedPrefsModel.stringdata0))
        return static_cast<void*>(this);
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int AdvancedPrefsModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
