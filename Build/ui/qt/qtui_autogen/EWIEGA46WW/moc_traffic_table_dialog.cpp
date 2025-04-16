/****************************************************************************
** Meta object code from reading C++ file 'traffic_table_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/traffic_table_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'traffic_table_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrafficTableDialog_t {
    const uint offsetsAndSize[42];
    char stringdata0[342];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TrafficTableDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TrafficTableDialog_t qt_meta_stringdata_TrafficTableDialog = {
    {
QT_MOC_LITERAL(0, 18), // "TrafficTableDialog"
QT_MOC_LITERAL(19, 12), // "filterAction"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 6), // "filter"
QT_MOC_LITERAL(40, 20), // "FilterAction::Action"
QT_MOC_LITERAL(61, 6), // "action"
QT_MOC_LITERAL(68, 24), // "FilterAction::ActionType"
QT_MOC_LITERAL(93, 4), // "type"
QT_MOC_LITERAL(98, 22), // "openFollowStreamDialog"
QT_MOC_LITERAL(121, 8), // "proto_id"
QT_MOC_LITERAL(130, 18), // "openTcpStreamGraph"
QT_MOC_LITERAL(149, 10), // "graph_type"
QT_MOC_LITERAL(160, 17), // "currentTabChanged"
QT_MOC_LITERAL(178, 33), // "on_nameResolutionCheckBox_tog..."
QT_MOC_LITERAL(212, 7), // "checked"
QT_MOC_LITERAL(220, 28), // "displayFilterCheckBoxToggled"
QT_MOC_LITERAL(249, 37), // "aggregationSummaryOnlyCheckBo..."
QT_MOC_LITERAL(287, 12), // "captureEvent"
QT_MOC_LITERAL(300, 12), // "CaptureEvent"
QT_MOC_LITERAL(313, 1), // "e"
QT_MOC_LITERAL(315, 26) // "on_buttonBox_helpRequested"

    },
    "TrafficTableDialog\0filterAction\0\0"
    "filter\0FilterAction::Action\0action\0"
    "FilterAction::ActionType\0type\0"
    "openFollowStreamDialog\0proto_id\0"
    "openTcpStreamGraph\0graph_type\0"
    "currentTabChanged\0on_nameResolutionCheckBox_toggled\0"
    "checked\0displayFilterCheckBoxToggled\0"
    "aggregationSummaryOnlyCheckBoxToggled\0"
    "captureEvent\0CaptureEvent\0e\0"
    "on_buttonBox_helpRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrafficTableDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   68,    2, 0x06,    1 /* Public */,
       8,    1,   75,    2, 0x06,    5 /* Public */,
      10,    1,   78,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,   81,    2, 0x09,    9 /* Protected */,
      13,    1,   82,    2, 0x08,   10 /* Private */,
      15,    1,   85,    2, 0x08,   12 /* Private */,
      16,    1,   88,    2, 0x08,   14 /* Private */,
      17,    1,   91,    2, 0x08,   16 /* Private */,
      20,    0,   94,    2, 0x08,   18 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 6,    3,    5,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,

       0        // eod
};

void TrafficTableDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrafficTableDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->filterAction((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<FilterAction::Action>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<FilterAction::ActionType>>(_a[3]))); break;
        case 1: _t->openFollowStreamDialog((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->openTcpStreamGraph((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->currentTabChanged(); break;
        case 4: _t->on_nameResolutionCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->displayFilterCheckBoxToggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->aggregationSummaryOnlyCheckBoxToggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->captureEvent((*reinterpret_cast< std::add_pointer_t<CaptureEvent>>(_a[1]))); break;
        case 8: _t->on_buttonBox_helpRequested(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TrafficTableDialog::*)(QString , FilterAction::Action , FilterAction::ActionType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrafficTableDialog::filterAction)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TrafficTableDialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrafficTableDialog::openFollowStreamDialog)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TrafficTableDialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrafficTableDialog::openTcpStreamGraph)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject TrafficTableDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<WiresharkDialog::staticMetaObject>(),
    qt_meta_stringdata_TrafficTableDialog.offsetsAndSize,
    qt_meta_data_TrafficTableDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TrafficTableDialog_t
, QtPrivate::TypeAndForceComplete<TrafficTableDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::Action, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::ActionType, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<CaptureEvent, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TrafficTableDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrafficTableDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrafficTableDialog.stringdata0))
        return static_cast<void*>(this);
    return WiresharkDialog::qt_metacast(_clname);
}

int TrafficTableDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void TrafficTableDialog::filterAction(QString _t1, FilterAction::Action _t2, FilterAction::ActionType _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TrafficTableDialog::openFollowStreamDialog(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TrafficTableDialog::openTcpStreamGraph(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
