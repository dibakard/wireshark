/****************************************************************************
** Meta object code from reading C++ file 'endpoint_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/endpoint_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'endpoint_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EndpointDialog_t {
    const uint offsetsAndSize[18];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_EndpointDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_EndpointDialog_t qt_meta_stringdata_EndpointDialog = {
    {
QT_MOC_LITERAL(0, 14), // "EndpointDialog"
QT_MOC_LITERAL(15, 7), // "openMap"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 7), // "saveMap"
QT_MOC_LITERAL(32, 10), // "tabChanged"
QT_MOC_LITERAL(43, 3), // "idx"
QT_MOC_LITERAL(47, 26), // "on_buttonBox_helpRequested"
QT_MOC_LITERAL(74, 18), // "aggregationToggled"
QT_MOC_LITERAL(93, 7) // "checked"

    },
    "EndpointDialog\0openMap\0\0saveMap\0"
    "tabChanged\0idx\0on_buttonBox_helpRequested\0"
    "aggregationToggled\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EndpointDialog[] = {

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
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    1,   46,    2, 0x08,    3 /* Private */,
       6,    0,   49,    2, 0x08,    5 /* Private */,
       7,    1,   50,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,

       0        // eod
};

void EndpointDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EndpointDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openMap(); break;
        case 1: _t->saveMap(); break;
        case 2: _t->tabChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_buttonBox_helpRequested(); break;
        case 4: _t->aggregationToggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject EndpointDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<TrafficTableDialog::staticMetaObject>(),
    qt_meta_stringdata_EndpointDialog.offsetsAndSize,
    qt_meta_data_EndpointDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_EndpointDialog_t
, QtPrivate::TypeAndForceComplete<EndpointDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *EndpointDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EndpointDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EndpointDialog.stringdata0))
        return static_cast<void*>(this);
    return TrafficTableDialog::qt_metacast(_clname);
}

int EndpointDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TrafficTableDialog::qt_metacall(_c, _id, _a);
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
