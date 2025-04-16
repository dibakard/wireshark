/****************************************************************************
** Meta object code from reading C++ file 'decode_as_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/decode_as_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'decode_as_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DecodeAsDialog_t {
    const uint offsetsAndSize[32];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DecodeAsDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DecodeAsDialog_t qt_meta_stringdata_DecodeAsDialog = {
    {
QT_MOC_LITERAL(0, 14), // "DecodeAsDialog"
QT_MOC_LITERAL(15, 14), // "modelRowsReset"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 15), // "copyFromProfile"
QT_MOC_LITERAL(47, 8), // "filename"
QT_MOC_LITERAL(56, 38), // "on_decodeAsTreeView_currentIt..."
QT_MOC_LITERAL(95, 11), // "QModelIndex"
QT_MOC_LITERAL(107, 7), // "current"
QT_MOC_LITERAL(115, 8), // "previous"
QT_MOC_LITERAL(124, 24), // "on_newToolButton_clicked"
QT_MOC_LITERAL(149, 27), // "on_deleteToolButton_clicked"
QT_MOC_LITERAL(177, 25), // "on_copyToolButton_clicked"
QT_MOC_LITERAL(203, 26), // "on_clearToolButton_clicked"
QT_MOC_LITERAL(230, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(251, 16), // "QAbstractButton*"
QT_MOC_LITERAL(268, 6) // "button"

    },
    "DecodeAsDialog\0modelRowsReset\0\0"
    "copyFromProfile\0filename\0"
    "on_decodeAsTreeView_currentItemChanged\0"
    "QModelIndex\0current\0previous\0"
    "on_newToolButton_clicked\0"
    "on_deleteToolButton_clicked\0"
    "on_copyToolButton_clicked\0"
    "on_clearToolButton_clicked\0"
    "on_buttonBox_clicked\0QAbstractButton*\0"
    "button"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DecodeAsDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x0a,    1 /* Public */,
       3,    1,   63,    2, 0x08,    2 /* Private */,
       5,    2,   66,    2, 0x08,    4 /* Private */,
       9,    0,   71,    2, 0x08,    7 /* Private */,
      10,    0,   72,    2, 0x08,    8 /* Private */,
      11,    0,   73,    2, 0x08,    9 /* Private */,
      12,    0,   74,    2, 0x08,   10 /* Private */,
      13,    1,   75,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void DecodeAsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DecodeAsDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->modelRowsReset(); break;
        case 1: _t->copyFromProfile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->on_decodeAsTreeView_currentItemChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        case 3: _t->on_newToolButton_clicked(); break;
        case 4: _t->on_deleteToolButton_clicked(); break;
        case 5: _t->on_copyToolButton_clicked(); break;
        case 6: _t->on_clearToolButton_clicked(); break;
        case 7: _t->on_buttonBox_clicked((*reinterpret_cast< std::add_pointer_t<QAbstractButton*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractButton* >(); break;
            }
            break;
        }
    }
}

const QMetaObject DecodeAsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<GeometryStateDialog::staticMetaObject>(),
    qt_meta_stringdata_DecodeAsDialog.offsetsAndSize,
    qt_meta_data_DecodeAsDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DecodeAsDialog_t
, QtPrivate::TypeAndForceComplete<DecodeAsDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractButton *, std::false_type>


>,
    nullptr
} };


const QMetaObject *DecodeAsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DecodeAsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DecodeAsDialog.stringdata0))
        return static_cast<void*>(this);
    return GeometryStateDialog::qt_metacast(_clname);
}

int DecodeAsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeometryStateDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
