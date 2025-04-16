/****************************************************************************
** Meta object code from reading C++ file 'export_object_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/export_object_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'export_object_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ExportObjectDialog_t {
    const uint offsetsAndSize[42];
    char stringdata0[262];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ExportObjectDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ExportObjectDialog_t qt_meta_stringdata_ExportObjectDialog = {
    {
QT_MOC_LITERAL(0, 18), // "ExportObjectDialog"
QT_MOC_LITERAL(19, 4), // "show"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 6), // "accept"
QT_MOC_LITERAL(32, 12), // "captureEvent"
QT_MOC_LITERAL(45, 12), // "CaptureEvent"
QT_MOC_LITERAL(58, 1), // "e"
QT_MOC_LITERAL(60, 26), // "on_buttonBox_helpRequested"
QT_MOC_LITERAL(87, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(108, 16), // "QAbstractButton*"
QT_MOC_LITERAL(125, 6), // "button"
QT_MOC_LITERAL(132, 37), // "on_cmbContentType_currentInde..."
QT_MOC_LITERAL(170, 5), // "index"
QT_MOC_LITERAL(176, 16), // "modelDataChanged"
QT_MOC_LITERAL(193, 11), // "QModelIndex"
QT_MOC_LITERAL(205, 7), // "topLeft"
QT_MOC_LITERAL(213, 4), // "from"
QT_MOC_LITERAL(218, 2), // "to"
QT_MOC_LITERAL(221, 14), // "modelRowsReset"
QT_MOC_LITERAL(236, 17), // "currentHasChanged"
QT_MOC_LITERAL(254, 7) // "current"

    },
    "ExportObjectDialog\0show\0\0accept\0"
    "captureEvent\0CaptureEvent\0e\0"
    "on_buttonBox_helpRequested\0"
    "on_buttonBox_clicked\0QAbstractButton*\0"
    "button\0on_cmbContentType_currentIndexChanged\0"
    "index\0modelDataChanged\0QModelIndex\0"
    "topLeft\0from\0to\0modelRowsReset\0"
    "currentHasChanged\0current"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExportObjectDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x0a,    1 /* Public */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    1,   70,    2, 0x08,    3 /* Private */,
       7,    0,   73,    2, 0x08,    5 /* Private */,
       8,    1,   74,    2, 0x08,    6 /* Private */,
      11,    1,   77,    2, 0x08,    8 /* Private */,
      13,    3,   80,    2, 0x08,   10 /* Private */,
      18,    0,   87,    2, 0x08,   14 /* Private */,
      19,    1,   88,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int, QMetaType::Int,   15,   16,   17,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   20,

       0        // eod
};

void ExportObjectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExportObjectDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->show(); break;
        case 1: _t->accept(); break;
        case 2: _t->captureEvent((*reinterpret_cast< std::add_pointer_t<CaptureEvent>>(_a[1]))); break;
        case 3: _t->on_buttonBox_helpRequested(); break;
        case 4: _t->on_buttonBox_clicked((*reinterpret_cast< std::add_pointer_t<QAbstractButton*>>(_a[1]))); break;
        case 5: _t->on_cmbContentType_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->modelDataChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 7: _t->modelRowsReset(); break;
        case 8: _t->currentHasChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ExportObjectDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<WiresharkDialog::staticMetaObject>(),
    qt_meta_stringdata_ExportObjectDialog.offsetsAndSize,
    qt_meta_data_ExportObjectDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ExportObjectDialog_t
, QtPrivate::TypeAndForceComplete<ExportObjectDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<CaptureEvent, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractButton *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QModelIndex, std::false_type>


>,
    nullptr
} };


const QMetaObject *ExportObjectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExportObjectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExportObjectDialog.stringdata0))
        return static_cast<void*>(this);
    return WiresharkDialog::qt_metacast(_clname);
}

int ExportObjectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WiresharkDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
