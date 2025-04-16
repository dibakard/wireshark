/****************************************************************************
** Meta object code from reading C++ file 'rpc_service_response_time_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/rpc_service_response_time_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rpc_service_response_time_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RpcServiceResponseTimeDialog_t {
    const uint offsetsAndSize[10];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_RpcServiceResponseTimeDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_RpcServiceResponseTimeDialog_t qt_meta_stringdata_RpcServiceResponseTimeDialog = {
    {
QT_MOC_LITERAL(0, 28), // "RpcServiceResponseTimeDialog"
QT_MOC_LITERAL(29, 20), // "dceRpcProgramChanged"
QT_MOC_LITERAL(50, 0), // ""
QT_MOC_LITERAL(51, 12), // "program_name"
QT_MOC_LITERAL(64, 20) // "oncRpcProgramChanged"

    },
    "RpcServiceResponseTimeDialog\0"
    "dceRpcProgramChanged\0\0program_name\0"
    "oncRpcProgramChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RpcServiceResponseTimeDialog[] = {

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
       1,    1,   26,    2, 0x0a,    1 /* Public */,
       4,    1,   29,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void RpcServiceResponseTimeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RpcServiceResponseTimeDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dceRpcProgramChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->oncRpcProgramChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject RpcServiceResponseTimeDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<ServiceResponseTimeDialog::staticMetaObject>(),
    qt_meta_stringdata_RpcServiceResponseTimeDialog.offsetsAndSize,
    qt_meta_data_RpcServiceResponseTimeDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RpcServiceResponseTimeDialog_t
, QtPrivate::TypeAndForceComplete<RpcServiceResponseTimeDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *RpcServiceResponseTimeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RpcServiceResponseTimeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RpcServiceResponseTimeDialog.stringdata0))
        return static_cast<void*>(this);
    return ServiceResponseTimeDialog::qt_metacast(_clname);
}

int RpcServiceResponseTimeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ServiceResponseTimeDialog::qt_metacall(_c, _id, _a);
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
