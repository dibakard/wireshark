/****************************************************************************
** Meta object code from reading C++ file 'profile_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/profile_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profile_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProfileDialog_t {
    const uint offsetsAndSize[42];
    char stringdata0[327];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ProfileDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ProfileDialog_t qt_meta_stringdata_ProfileDialog = {
    {
QT_MOC_LITERAL(0, 13), // "ProfileDialog"
QT_MOC_LITERAL(14, 18), // "currentItemChanged"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 11), // "QModelIndex"
QT_MOC_LITERAL(46, 1), // "c"
QT_MOC_LITERAL(48, 1), // "p"
QT_MOC_LITERAL(50, 14), // "exportProfiles"
QT_MOC_LITERAL(65, 25), // "exportAllPersonalProfiles"
QT_MOC_LITERAL(91, 13), // "importFromZip"
QT_MOC_LITERAL(105, 19), // "importFromDirectory"
QT_MOC_LITERAL(125, 20), // "newToolButtonClicked"
QT_MOC_LITERAL(146, 23), // "deleteToolButtonClicked"
QT_MOC_LITERAL(170, 21), // "copyToolButtonClicked"
QT_MOC_LITERAL(192, 17), // "buttonBoxAccepted"
QT_MOC_LITERAL(210, 17), // "buttonBoxRejected"
QT_MOC_LITERAL(228, 22), // "buttonBoxHelpRequested"
QT_MOC_LITERAL(251, 11), // "dataChanged"
QT_MOC_LITERAL(263, 13), // "filterChanged"
QT_MOC_LITERAL(277, 16), // "selectionChanged"
QT_MOC_LITERAL(294, 16), // "selectedProfiles"
QT_MOC_LITERAL(311, 15) // "QModelIndexList"

    },
    "ProfileDialog\0currentItemChanged\0\0"
    "QModelIndex\0c\0p\0exportProfiles\0"
    "exportAllPersonalProfiles\0importFromZip\0"
    "importFromDirectory\0newToolButtonClicked\0"
    "deleteToolButtonClicked\0copyToolButtonClicked\0"
    "buttonBoxAccepted\0buttonBoxRejected\0"
    "buttonBoxHelpRequested\0dataChanged\0"
    "filterChanged\0selectionChanged\0"
    "selectedProfiles\0QModelIndexList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProfileDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  116,    2, 0x08,    1 /* Private */,
       1,    1,  121,    2, 0x28,    4 /* Private | MethodCloned */,
       1,    0,  124,    2, 0x28,    6 /* Private | MethodCloned */,
       6,    1,  125,    2, 0x08,    7 /* Private */,
       6,    0,  128,    2, 0x28,    9 /* Private | MethodCloned */,
       8,    0,  129,    2, 0x08,   10 /* Private */,
       9,    0,  130,    2, 0x08,   11 /* Private */,
      10,    0,  131,    2, 0x08,   12 /* Private */,
      11,    0,  132,    2, 0x08,   13 /* Private */,
      12,    0,  133,    2, 0x08,   14 /* Private */,
      13,    0,  134,    2, 0x08,   15 /* Private */,
      14,    0,  135,    2, 0x08,   16 /* Private */,
      15,    0,  136,    2, 0x08,   17 /* Private */,
      16,    1,  137,    2, 0x08,   18 /* Private */,
      17,    1,  140,    2, 0x08,   20 /* Private */,
      18,    0,  143,    2, 0x08,   22 /* Private */,
      19,    0,  144,    2, 0x08,   23 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    0x80000000 | 20,

       0        // eod
};

void ProfileDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProfileDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->currentItemChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        case 1: _t->currentItemChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->currentItemChanged(); break;
        case 3: _t->exportProfiles((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->exportProfiles(); break;
        case 5: _t->importFromZip(); break;
        case 6: _t->importFromDirectory(); break;
        case 7: _t->newToolButtonClicked(); break;
        case 8: _t->deleteToolButtonClicked(); break;
        case 9: _t->copyToolButtonClicked(); break;
        case 10: _t->buttonBoxAccepted(); break;
        case 11: _t->buttonBoxRejected(); break;
        case 12: _t->buttonBoxHelpRequested(); break;
        case 13: _t->dataChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 14: _t->filterChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->selectionChanged(); break;
        case 16: { QModelIndexList _r = _t->selectedProfiles();
            if (_a[0]) *reinterpret_cast< QModelIndexList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject ProfileDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<GeometryStateDialog::staticMetaObject>(),
    qt_meta_stringdata_ProfileDialog.offsetsAndSize,
    qt_meta_data_ProfileDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ProfileDialog_t
, QtPrivate::TypeAndForceComplete<ProfileDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QModelIndexList, std::false_type>


>,
    nullptr
} };


const QMetaObject *ProfileDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProfileDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProfileDialog.stringdata0))
        return static_cast<void*>(this);
    return GeometryStateDialog::qt_metacast(_clname);
}

int ProfileDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeometryStateDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
