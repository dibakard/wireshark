/****************************************************************************
** Meta object code from reading C++ file 'uat_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/uat_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uat_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UatDialog_t {
    const uint offsetsAndSize[50];
    char stringdata0[438];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_UatDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_UatDialog_t qt_meta_stringdata_UatDialog = {
    {
QT_MOC_LITERAL(0, 9), // "UatDialog"
QT_MOC_LITERAL(10, 15), // "copyFromProfile"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 8), // "filename"
QT_MOC_LITERAL(36, 16), // "modelDataChanged"
QT_MOC_LITERAL(53, 11), // "QModelIndex"
QT_MOC_LITERAL(65, 7), // "topLeft"
QT_MOC_LITERAL(73, 16), // "modelRowsRemoved"
QT_MOC_LITERAL(90, 14), // "modelRowsReset"
QT_MOC_LITERAL(105, 27), // "uatTreeViewSelectionChanged"
QT_MOC_LITERAL(133, 14), // "QItemSelection"
QT_MOC_LITERAL(148, 8), // "selected"
QT_MOC_LITERAL(157, 10), // "deselected"
QT_MOC_LITERAL(168, 33), // "on_uatTreeView_currentItemCha..."
QT_MOC_LITERAL(202, 7), // "current"
QT_MOC_LITERAL(210, 8), // "previous"
QT_MOC_LITERAL(219, 13), // "acceptChanges"
QT_MOC_LITERAL(233, 13), // "rejectChanges"
QT_MOC_LITERAL(247, 24), // "on_newToolButton_clicked"
QT_MOC_LITERAL(272, 27), // "on_deleteToolButton_clicked"
QT_MOC_LITERAL(300, 25), // "on_copyToolButton_clicked"
QT_MOC_LITERAL(326, 27), // "on_moveUpToolButton_clicked"
QT_MOC_LITERAL(354, 29), // "on_moveDownToolButton_clicked"
QT_MOC_LITERAL(384, 26), // "on_clearToolButton_clicked"
QT_MOC_LITERAL(411, 26) // "on_buttonBox_helpRequested"

    },
    "UatDialog\0copyFromProfile\0\0filename\0"
    "modelDataChanged\0QModelIndex\0topLeft\0"
    "modelRowsRemoved\0modelRowsReset\0"
    "uatTreeViewSelectionChanged\0QItemSelection\0"
    "selected\0deselected\0"
    "on_uatTreeView_currentItemChanged\0"
    "current\0previous\0acceptChanges\0"
    "rejectChanges\0on_newToolButton_clicked\0"
    "on_deleteToolButton_clicked\0"
    "on_copyToolButton_clicked\0"
    "on_moveUpToolButton_clicked\0"
    "on_moveDownToolButton_clicked\0"
    "on_clearToolButton_clicked\0"
    "on_buttonBox_helpRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UatDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x08,    1 /* Private */,
       4,    1,  107,    2, 0x08,    3 /* Private */,
       7,    0,  110,    2, 0x08,    5 /* Private */,
       8,    0,  111,    2, 0x08,    6 /* Private */,
       9,    2,  112,    2, 0x08,    7 /* Private */,
      13,    2,  117,    2, 0x08,   10 /* Private */,
      16,    0,  122,    2, 0x08,   13 /* Private */,
      17,    0,  123,    2, 0x08,   14 /* Private */,
      18,    0,  124,    2, 0x08,   15 /* Private */,
      19,    0,  125,    2, 0x08,   16 /* Private */,
      20,    0,  126,    2, 0x08,   17 /* Private */,
      21,    0,  127,    2, 0x08,   18 /* Private */,
      22,    0,  128,    2, 0x08,   19 /* Private */,
      23,    0,  129,    2, 0x08,   20 /* Private */,
      24,    0,  130,    2, 0x08,   21 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 10,   11,   12,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UatDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UatDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->copyFromProfile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->modelDataChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->modelRowsRemoved(); break;
        case 3: _t->modelRowsReset(); break;
        case 4: _t->uatTreeViewSelectionChanged((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[2]))); break;
        case 5: _t->on_uatTreeView_currentItemChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        case 6: _t->acceptChanges(); break;
        case 7: _t->rejectChanges(); break;
        case 8: _t->on_newToolButton_clicked(); break;
        case 9: _t->on_deleteToolButton_clicked(); break;
        case 10: _t->on_copyToolButton_clicked(); break;
        case 11: _t->on_moveUpToolButton_clicked(); break;
        case 12: _t->on_moveDownToolButton_clicked(); break;
        case 13: _t->on_clearToolButton_clicked(); break;
        case 14: _t->on_buttonBox_helpRequested(); break;
        default: ;
        }
    }
}

const QMetaObject UatDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<GeometryStateDialog::staticMetaObject>(),
    qt_meta_stringdata_UatDialog.offsetsAndSize,
    qt_meta_data_UatDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_UatDialog_t
, QtPrivate::TypeAndForceComplete<UatDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>, QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *UatDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UatDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UatDialog.stringdata0))
        return static_cast<void*>(this);
    return GeometryStateDialog::qt_metacast(_clname);
}

int UatDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeometryStateDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
