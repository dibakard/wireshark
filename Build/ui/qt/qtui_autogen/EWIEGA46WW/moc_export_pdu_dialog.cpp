/****************************************************************************
** Meta object code from reading C++ file 'export_pdu_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/export_pdu_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'export_pdu_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ExportPDUDialog_t {
    const uint offsetsAndSize[8];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ExportPDUDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ExportPDUDialog_t qt_meta_stringdata_ExportPDUDialog = {
    {
QT_MOC_LITERAL(0, 15), // "ExportPDUDialog"
QT_MOC_LITERAL(16, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(38, 0), // ""
QT_MOC_LITERAL(39, 26) // "on_buttonBox_helpRequested"

    },
    "ExportPDUDialog\0on_buttonBox_accepted\0"
    "\0on_buttonBox_helpRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExportPDUDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x08,    1 /* Private */,
       3,    0,   27,    2, 0x08,    2 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ExportPDUDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExportPDUDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_buttonBox_accepted(); break;
        case 1: _t->on_buttonBox_helpRequested(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject ExportPDUDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ExportPDUDialog.offsetsAndSize,
    qt_meta_data_ExportPDUDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ExportPDUDialog_t
, QtPrivate::TypeAndForceComplete<ExportPDUDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ExportPDUDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExportPDUDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExportPDUDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ExportPDUDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
