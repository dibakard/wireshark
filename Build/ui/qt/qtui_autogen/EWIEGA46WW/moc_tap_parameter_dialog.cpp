/****************************************************************************
** Meta object code from reading C++ file 'tap_parameter_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/tap_parameter_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tap_parameter_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TapParameterDialog_t {
    const uint offsetsAndSize[36];
    char stringdata0[325];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TapParameterDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TapParameterDialog_t qt_meta_stringdata_TapParameterDialog = {
    {
QT_MOC_LITERAL(0, 18), // "TapParameterDialog"
QT_MOC_LITERAL(19, 12), // "filterAction"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 6), // "filter"
QT_MOC_LITERAL(40, 20), // "FilterAction::Action"
QT_MOC_LITERAL(61, 6), // "action"
QT_MOC_LITERAL(68, 24), // "FilterAction::ActionType"
QT_MOC_LITERAL(93, 4), // "type"
QT_MOC_LITERAL(98, 12), // "updateFilter"
QT_MOC_LITERAL(111, 21), // "filterActionTriggered"
QT_MOC_LITERAL(133, 26), // "collapseAllActionTriggered"
QT_MOC_LITERAL(160, 24), // "expandAllActionTriggered"
QT_MOC_LITERAL(185, 13), // "updateWidgets"
QT_MOC_LITERAL(199, 8), // "fillTree"
QT_MOC_LITERAL(208, 28), // "on_applyFilterButton_clicked"
QT_MOC_LITERAL(237, 34), // "on_actionCopyToClipboard_trig..."
QT_MOC_LITERAL(272, 25), // "on_actionSaveAs_triggered"
QT_MOC_LITERAL(298, 26) // "on_buttonBox_helpRequested"

    },
    "TapParameterDialog\0filterAction\0\0"
    "filter\0FilterAction::Action\0action\0"
    "FilterAction::ActionType\0type\0"
    "updateFilter\0filterActionTriggered\0"
    "collapseAllActionTriggered\0"
    "expandAllActionTriggered\0updateWidgets\0"
    "fillTree\0on_applyFilterButton_clicked\0"
    "on_actionCopyToClipboard_triggered\0"
    "on_actionSaveAs_triggered\0"
    "on_buttonBox_helpRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TapParameterDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   80,    2, 0x06,    1 /* Public */,
       8,    1,   87,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   90,    2, 0x09,    7 /* Protected */,
      10,    0,   91,    2, 0x09,    8 /* Protected */,
      11,    0,   92,    2, 0x09,    9 /* Protected */,
      12,    0,   93,    2, 0x09,   10 /* Protected */,
      13,    0,   94,    2, 0x08,   11 /* Private */,
      14,    0,   95,    2, 0x08,   12 /* Private */,
      15,    0,   96,    2, 0x08,   13 /* Private */,
      16,    0,   97,    2, 0x08,   14 /* Private */,
      17,    0,   98,    2, 0x08,   15 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 6,    3,    5,    7,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TapParameterDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TapParameterDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->filterAction((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<FilterAction::Action>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<FilterAction::ActionType>>(_a[3]))); break;
        case 1: _t->updateFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->filterActionTriggered(); break;
        case 3: _t->collapseAllActionTriggered(); break;
        case 4: _t->expandAllActionTriggered(); break;
        case 5: _t->updateWidgets(); break;
        case 6: _t->fillTree(); break;
        case 7: _t->on_applyFilterButton_clicked(); break;
        case 8: _t->on_actionCopyToClipboard_triggered(); break;
        case 9: _t->on_actionSaveAs_triggered(); break;
        case 10: _t->on_buttonBox_helpRequested(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TapParameterDialog::*)(QString , FilterAction::Action , FilterAction::ActionType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TapParameterDialog::filterAction)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TapParameterDialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TapParameterDialog::updateFilter)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject TapParameterDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<WiresharkDialog::staticMetaObject>(),
    qt_meta_stringdata_TapParameterDialog.offsetsAndSize,
    qt_meta_data_TapParameterDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TapParameterDialog_t
, QtPrivate::TypeAndForceComplete<TapParameterDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::Action, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::ActionType, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TapParameterDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TapParameterDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TapParameterDialog.stringdata0))
        return static_cast<void*>(this);
    return WiresharkDialog::qt_metacast(_clname);
}

int TapParameterDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WiresharkDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void TapParameterDialog::filterAction(QString _t1, FilterAction::Action _t2, FilterAction::ActionType _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TapParameterDialog::updateFilter(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
