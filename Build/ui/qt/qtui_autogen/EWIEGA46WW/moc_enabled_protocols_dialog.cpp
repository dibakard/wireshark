/****************************************************************************
** Meta object code from reading C++ file 'enabled_protocols_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/enabled_protocols_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enabled_protocols_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EnabledProtocolsDialog_t {
    const uint offsetsAndSize[22];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_EnabledProtocolsDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_EnabledProtocolsDialog_t qt_meta_stringdata_EnabledProtocolsDialog = {
    {
QT_MOC_LITERAL(0, 22), // "EnabledProtocolsDialog"
QT_MOC_LITERAL(23, 25), // "on_invert_button__clicked"
QT_MOC_LITERAL(49, 0), // ""
QT_MOC_LITERAL(50, 29), // "on_enable_all_button__clicked"
QT_MOC_LITERAL(80, 30), // "on_disable_all_button__clicked"
QT_MOC_LITERAL(111, 32), // "on_search_line_edit__textChanged"
QT_MOC_LITERAL(144, 36), // "on_cmbSearchType_currentIndex..."
QT_MOC_LITERAL(181, 38), // "on_cmbProtocolType_currentInd..."
QT_MOC_LITERAL(220, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(242, 26), // "on_buttonBox_helpRequested"
QT_MOC_LITERAL(269, 8) // "fillTree"

    },
    "EnabledProtocolsDialog\0on_invert_button__clicked\0"
    "\0on_enable_all_button__clicked\0"
    "on_disable_all_button__clicked\0"
    "on_search_line_edit__textChanged\0"
    "on_cmbSearchType_currentIndexChanged\0"
    "on_cmbProtocolType_currentIndexChanged\0"
    "on_buttonBox_accepted\0on_buttonBox_helpRequested\0"
    "fillTree"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EnabledProtocolsDialog[] = {

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
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    1,   71,    2, 0x08,    4 /* Private */,
       6,    1,   74,    2, 0x08,    6 /* Private */,
       7,    1,   77,    2, 0x08,    8 /* Private */,
       8,    0,   80,    2, 0x08,   10 /* Private */,
       9,    0,   81,    2, 0x08,   11 /* Private */,
      10,    0,   82,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EnabledProtocolsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EnabledProtocolsDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_invert_button__clicked(); break;
        case 1: _t->on_enable_all_button__clicked(); break;
        case 2: _t->on_disable_all_button__clicked(); break;
        case 3: _t->on_search_line_edit__textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->on_cmbSearchType_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_cmbProtocolType_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_buttonBox_accepted(); break;
        case 7: _t->on_buttonBox_helpRequested(); break;
        case 8: _t->fillTree(); break;
        default: ;
        }
    }
}

const QMetaObject EnabledProtocolsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<GeometryStateDialog::staticMetaObject>(),
    qt_meta_stringdata_EnabledProtocolsDialog.offsetsAndSize,
    qt_meta_data_EnabledProtocolsDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_EnabledProtocolsDialog_t
, QtPrivate::TypeAndForceComplete<EnabledProtocolsDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *EnabledProtocolsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EnabledProtocolsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EnabledProtocolsDialog.stringdata0))
        return static_cast<void*>(this);
    return GeometryStateDialog::qt_metacast(_clname);
}

int EnabledProtocolsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeometryStateDialog::qt_metacall(_c, _id, _a);
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
