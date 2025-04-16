/****************************************************************************
** Meta object code from reading C++ file 'firewall_rules_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/firewall_rules_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'firewall_rules_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FirewallRulesDialog_t {
    const uint offsetsAndSize[20];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FirewallRulesDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FirewallRulesDialog_t qt_meta_stringdata_FirewallRulesDialog = {
    {
QT_MOC_LITERAL(0, 19), // "FirewallRulesDialog"
QT_MOC_LITERAL(20, 38), // "on_productComboBox_currentInd..."
QT_MOC_LITERAL(59, 0), // ""
QT_MOC_LITERAL(60, 7), // "new_idx"
QT_MOC_LITERAL(68, 26), // "on_inboundCheckBox_toggled"
QT_MOC_LITERAL(95, 23), // "on_denyCheckBox_toggled"
QT_MOC_LITERAL(119, 26), // "on_buttonBox_helpRequested"
QT_MOC_LITERAL(146, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(167, 16), // "QAbstractButton*"
QT_MOC_LITERAL(184, 6) // "button"

    },
    "FirewallRulesDialog\0"
    "on_productComboBox_currentIndexChanged\0"
    "\0new_idx\0on_inboundCheckBox_toggled\0"
    "on_denyCheckBox_toggled\0"
    "on_buttonBox_helpRequested\0"
    "on_buttonBox_clicked\0QAbstractButton*\0"
    "button"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FirewallRulesDialog[] = {

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
       1,    1,   44,    2, 0x08,    1 /* Private */,
       4,    1,   47,    2, 0x08,    3 /* Private */,
       5,    1,   50,    2, 0x08,    5 /* Private */,
       6,    0,   53,    2, 0x08,    7 /* Private */,
       7,    1,   54,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void FirewallRulesDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FirewallRulesDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_productComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_inboundCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->on_denyCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->on_buttonBox_helpRequested(); break;
        case 4: _t->on_buttonBox_clicked((*reinterpret_cast< std::add_pointer_t<QAbstractButton*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject FirewallRulesDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<WiresharkDialog::staticMetaObject>(),
    qt_meta_stringdata_FirewallRulesDialog.offsetsAndSize,
    qt_meta_data_FirewallRulesDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FirewallRulesDialog_t
, QtPrivate::TypeAndForceComplete<FirewallRulesDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractButton *, std::false_type>


>,
    nullptr
} };


const QMetaObject *FirewallRulesDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FirewallRulesDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FirewallRulesDialog.stringdata0))
        return static_cast<void*>(this);
    return WiresharkDialog::qt_metacast(_clname);
}

int FirewallRulesDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WiresharkDialog::qt_metacall(_c, _id, _a);
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
