/****************************************************************************
** Meta object code from reading C++ file 'export_dissection_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/export_dissection_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'export_dissection_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ExportDissectionDialog_t {
    const uint offsetsAndSize[18];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ExportDissectionDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ExportDissectionDialog_t qt_meta_stringdata_ExportDissectionDialog = {
    {
QT_MOC_LITERAL(0, 22), // "ExportDissectionDialog"
QT_MOC_LITERAL(23, 4), // "show"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 14), // "dialogAccepted"
QT_MOC_LITERAL(44, 8), // "selected"
QT_MOC_LITERAL(53, 17), // "exportTypeChanged"
QT_MOC_LITERAL(71, 11), // "name_filter"
QT_MOC_LITERAL(83, 13), // "checkValidity"
QT_MOC_LITERAL(97, 26) // "on_buttonBox_helpRequested"

    },
    "ExportDissectionDialog\0show\0\0"
    "dialogAccepted\0selected\0exportTypeChanged\0"
    "name_filter\0checkValidity\0"
    "on_buttonBox_helpRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExportDissectionDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x0a,    1 /* Public */,
       3,    1,   45,    2, 0x08,    2 /* Private */,
       5,    1,   48,    2, 0x08,    4 /* Private */,
       7,    0,   51,    2, 0x08,    6 /* Private */,
       8,    0,   52,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ExportDissectionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExportDissectionDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->show(); break;
        case 1: _t->dialogAccepted((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 2: _t->exportTypeChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->checkValidity(); break;
        case 4: _t->on_buttonBox_helpRequested(); break;
        default: ;
        }
    }
}

const QMetaObject ExportDissectionDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<WiresharkFileDialog::staticMetaObject>(),
    qt_meta_stringdata_ExportDissectionDialog.offsetsAndSize,
    qt_meta_data_ExportDissectionDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ExportDissectionDialog_t
, QtPrivate::TypeAndForceComplete<ExportDissectionDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ExportDissectionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExportDissectionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExportDissectionDialog.stringdata0))
        return static_cast<void*>(this);
    return WiresharkFileDialog::qt_metacast(_clname);
}

int ExportDissectionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WiresharkFileDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
