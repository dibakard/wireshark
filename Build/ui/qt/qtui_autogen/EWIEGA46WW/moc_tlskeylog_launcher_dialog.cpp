/****************************************************************************
** Meta object code from reading C++ file 'tlskeylog_launcher_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/tlskeylog_launcher_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tlskeylog_launcher_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TLSKeylogDialog_t {
    const uint offsetsAndSize[14];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TLSKeylogDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TLSKeylogDialog_t qt_meta_stringdata_TLSKeylogDialog = {
    {
QT_MOC_LITERAL(0, 15), // "TLSKeylogDialog"
QT_MOC_LITERAL(16, 18), // "on_launchActivated"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 16), // "on_saveActivated"
QT_MOC_LITERAL(53, 17), // "on_resetActivated"
QT_MOC_LITERAL(71, 19), // "on_browseKeylogPath"
QT_MOC_LITERAL(91, 20) // "on_browseProgramPath"

    },
    "TLSKeylogDialog\0on_launchActivated\0\0"
    "on_saveActivated\0on_resetActivated\0"
    "on_browseKeylogPath\0on_browseProgramPath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TLSKeylogDialog[] = {

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
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TLSKeylogDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TLSKeylogDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_launchActivated(); break;
        case 1: _t->on_saveActivated(); break;
        case 2: _t->on_resetActivated(); break;
        case 3: _t->on_browseKeylogPath(); break;
        case 4: _t->on_browseProgramPath(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject TLSKeylogDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_TLSKeylogDialog.offsetsAndSize,
    qt_meta_data_TLSKeylogDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TLSKeylogDialog_t
, QtPrivate::TypeAndForceComplete<TLSKeylogDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TLSKeylogDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TLSKeylogDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TLSKeylogDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TLSKeylogDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
