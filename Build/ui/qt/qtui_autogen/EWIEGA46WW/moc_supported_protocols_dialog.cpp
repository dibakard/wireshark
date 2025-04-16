/****************************************************************************
** Meta object code from reading C++ file 'supported_protocols_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/supported_protocols_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'supported_protocols_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SupportedProtocolsDialog_t {
    const uint offsetsAndSize[12];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SupportedProtocolsDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SupportedProtocolsDialog_t qt_meta_stringdata_SupportedProtocolsDialog = {
    {
QT_MOC_LITERAL(0, 24), // "SupportedProtocolsDialog"
QT_MOC_LITERAL(25, 8), // "fillTree"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 20), // "updateSearchLineEdit"
QT_MOC_LITERAL(56, 29), // "on_searchLineEdit_textChanged"
QT_MOC_LITERAL(86, 9) // "search_re"

    },
    "SupportedProtocolsDialog\0fillTree\0\0"
    "updateSearchLineEdit\0on_searchLineEdit_textChanged\0"
    "search_re"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SupportedProtocolsDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    1 /* Private */,
       3,    0,   33,    2, 0x08,    2 /* Private */,
       4,    1,   34,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void SupportedProtocolsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SupportedProtocolsDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->fillTree(); break;
        case 1: _t->updateSearchLineEdit(); break;
        case 2: _t->on_searchLineEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SupportedProtocolsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<GeometryStateDialog::staticMetaObject>(),
    qt_meta_stringdata_SupportedProtocolsDialog.offsetsAndSize,
    qt_meta_data_SupportedProtocolsDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SupportedProtocolsDialog_t
, QtPrivate::TypeAndForceComplete<SupportedProtocolsDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *SupportedProtocolsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SupportedProtocolsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SupportedProtocolsDialog.stringdata0))
        return static_cast<void*>(this);
    return GeometryStateDialog::qt_metacast(_clname);
}

int SupportedProtocolsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeometryStateDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
