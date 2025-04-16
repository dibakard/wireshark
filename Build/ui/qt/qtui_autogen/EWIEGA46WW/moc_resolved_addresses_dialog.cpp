/****************************************************************************
** Meta object code from reading C++ file 'resolved_addresses_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/resolved_addresses_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resolved_addresses_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ResolvedAddressesDialog_t {
    const uint offsetsAndSize[26];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ResolvedAddressesDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ResolvedAddressesDialog_t qt_meta_stringdata_ResolvedAddressesDialog = {
    {
QT_MOC_LITERAL(0, 23), // "ResolvedAddressesDialog"
QT_MOC_LITERAL(24, 34), // "on_cmbDataType_currentIndexCh..."
QT_MOC_LITERAL(59, 0), // ""
QT_MOC_LITERAL(60, 5), // "index"
QT_MOC_LITERAL(66, 30), // "on_txtSearchFilter_textChanged"
QT_MOC_LITERAL(97, 4), // "text"
QT_MOC_LITERAL(102, 40), // "on_cmbPortFilterType_currentI..."
QT_MOC_LITERAL(143, 28), // "on_txtPortFilter_textChanged"
QT_MOC_LITERAL(172, 11), // "changeEvent"
QT_MOC_LITERAL(184, 7), // "QEvent*"
QT_MOC_LITERAL(192, 5), // "event"
QT_MOC_LITERAL(198, 10), // "tabChanged"
QT_MOC_LITERAL(209, 6) // "saveAs"

    },
    "ResolvedAddressesDialog\0"
    "on_cmbDataType_currentIndexChanged\0\0"
    "index\0on_txtSearchFilter_textChanged\0"
    "text\0on_cmbPortFilterType_currentIndexChanged\0"
    "on_txtPortFilter_textChanged\0changeEvent\0"
    "QEvent*\0event\0tabChanged\0saveAs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResolvedAddressesDialog[] = {

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
       1,    1,   56,    2, 0x09,    1 /* Protected */,
       4,    1,   59,    2, 0x09,    3 /* Protected */,
       6,    1,   62,    2, 0x09,    5 /* Protected */,
       7,    1,   65,    2, 0x09,    7 /* Protected */,
       8,    1,   68,    2, 0x09,    9 /* Protected */,
      11,    1,   71,    2, 0x08,   11 /* Private */,
      12,    0,   74,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void ResolvedAddressesDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ResolvedAddressesDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_cmbDataType_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_txtSearchFilter_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->on_cmbPortFilterType_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_txtPortFilter_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->changeEvent((*reinterpret_cast< std::add_pointer_t<QEvent*>>(_a[1]))); break;
        case 5: _t->tabChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->saveAs(); break;
        default: ;
        }
    }
}

const QMetaObject ResolvedAddressesDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<GeometryStateDialog::staticMetaObject>(),
    qt_meta_stringdata_ResolvedAddressesDialog.offsetsAndSize,
    qt_meta_data_ResolvedAddressesDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ResolvedAddressesDialog_t
, QtPrivate::TypeAndForceComplete<ResolvedAddressesDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ResolvedAddressesDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResolvedAddressesDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ResolvedAddressesDialog.stringdata0))
        return static_cast<void*>(this);
    return GeometryStateDialog::qt_metacast(_clname);
}

int ResolvedAddressesDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
