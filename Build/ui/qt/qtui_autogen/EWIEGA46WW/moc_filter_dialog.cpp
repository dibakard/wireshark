/****************************************************************************
** Meta object code from reading C++ file 'filter_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/filter_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filter_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilterDialog_t {
    const uint offsetsAndSize[24];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FilterDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FilterDialog_t qt_meta_stringdata_FilterDialog = {
    {
QT_MOC_LITERAL(0, 12), // "FilterDialog"
QT_MOC_LITERAL(13, 13), // "updateWidgets"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 16), // "selectionChanged"
QT_MOC_LITERAL(45, 14), // "QItemSelection"
QT_MOC_LITERAL(60, 8), // "selected"
QT_MOC_LITERAL(69, 10), // "deselected"
QT_MOC_LITERAL(80, 24), // "on_newToolButton_clicked"
QT_MOC_LITERAL(105, 27), // "on_deleteToolButton_clicked"
QT_MOC_LITERAL(133, 25), // "on_copyToolButton_clicked"
QT_MOC_LITERAL(159, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(181, 26) // "on_buttonBox_helpRequested"

    },
    "FilterDialog\0updateWidgets\0\0"
    "selectionChanged\0QItemSelection\0"
    "selected\0deselected\0on_newToolButton_clicked\0"
    "on_deleteToolButton_clicked\0"
    "on_copyToolButton_clicked\0"
    "on_buttonBox_accepted\0on_buttonBox_helpRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    2,   57,    2, 0x08,    2 /* Private */,
       7,    0,   62,    2, 0x08,    5 /* Private */,
       8,    0,   63,    2, 0x08,    6 /* Private */,
       9,    0,   64,    2, 0x08,    7 /* Private */,
      10,    0,   65,    2, 0x08,    8 /* Private */,
      11,    0,   66,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FilterDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FilterDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateWidgets(); break;
        case 1: _t->selectionChanged((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[2]))); break;
        case 2: _t->on_newToolButton_clicked(); break;
        case 3: _t->on_deleteToolButton_clicked(); break;
        case 4: _t->on_copyToolButton_clicked(); break;
        case 5: _t->on_buttonBox_accepted(); break;
        case 6: _t->on_buttonBox_helpRequested(); break;
        default: ;
        }
    }
}

const QMetaObject FilterDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<GeometryStateDialog::staticMetaObject>(),
    qt_meta_stringdata_FilterDialog.offsetsAndSize,
    qt_meta_data_FilterDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FilterDialog_t
, QtPrivate::TypeAndForceComplete<FilterDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>, QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FilterDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterDialog.stringdata0))
        return static_cast<void*>(this);
    return GeometryStateDialog::qt_metacast(_clname);
}

int FilterDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeometryStateDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
struct qt_meta_stringdata_FilterTreeDelegate_t {
    const uint offsetsAndSize[2];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FilterTreeDelegate_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FilterTreeDelegate_t qt_meta_stringdata_FilterTreeDelegate = {
    {
QT_MOC_LITERAL(0, 18) // "FilterTreeDelegate"

    },
    "FilterTreeDelegate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterTreeDelegate[] = {

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

void FilterTreeDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject FilterTreeDelegate::staticMetaObject = { {
    QMetaObject::SuperData::link<QStyledItemDelegate::staticMetaObject>(),
    qt_meta_stringdata_FilterTreeDelegate.offsetsAndSize,
    qt_meta_data_FilterTreeDelegate,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FilterTreeDelegate_t
, QtPrivate::TypeAndForceComplete<FilterTreeDelegate, std::true_type>



>,
    nullptr
} };


const QMetaObject *FilterTreeDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterTreeDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterTreeDelegate.stringdata0))
        return static_cast<void*>(this);
    return QStyledItemDelegate::qt_metacast(_clname);
}

int FilterTreeDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
