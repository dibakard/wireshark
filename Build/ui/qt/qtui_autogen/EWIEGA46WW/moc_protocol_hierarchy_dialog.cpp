/****************************************************************************
** Meta object code from reading C++ file 'protocol_hierarchy_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/protocol_hierarchy_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'protocol_hierarchy_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProtocolHierarchyDialog_t {
    const uint offsetsAndSize[34];
    char stringdata0[331];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ProtocolHierarchyDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ProtocolHierarchyDialog_t qt_meta_stringdata_ProtocolHierarchyDialog = {
    {
QT_MOC_LITERAL(0, 23), // "ProtocolHierarchyDialog"
QT_MOC_LITERAL(24, 12), // "filterAction"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 6), // "filter"
QT_MOC_LITERAL(45, 20), // "FilterAction::Action"
QT_MOC_LITERAL(66, 6), // "action"
QT_MOC_LITERAL(73, 24), // "FilterAction::ActionType"
QT_MOC_LITERAL(98, 4), // "type"
QT_MOC_LITERAL(103, 17), // "showProtoHierMenu"
QT_MOC_LITERAL(121, 3), // "pos"
QT_MOC_LITERAL(125, 21), // "filterActionTriggered"
QT_MOC_LITERAL(147, 28), // "on_actionCopyAsCsv_triggered"
QT_MOC_LITERAL(176, 29), // "on_actionCopyAsYaml_triggered"
QT_MOC_LITERAL(206, 32), // "on_actionCopyProtoList_triggered"
QT_MOC_LITERAL(239, 32), // "on_actionDisableProtos_triggered"
QT_MOC_LITERAL(272, 31), // "on_actionRevertProtos_triggered"
QT_MOC_LITERAL(304, 26) // "on_buttonBox_helpRequested"

    },
    "ProtocolHierarchyDialog\0filterAction\0"
    "\0filter\0FilterAction::Action\0action\0"
    "FilterAction::ActionType\0type\0"
    "showProtoHierMenu\0pos\0filterActionTriggered\0"
    "on_actionCopyAsCsv_triggered\0"
    "on_actionCopyAsYaml_triggered\0"
    "on_actionCopyProtoList_triggered\0"
    "on_actionDisableProtos_triggered\0"
    "on_actionRevertProtos_triggered\0"
    "on_buttonBox_helpRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProtocolHierarchyDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   75,    2, 0x08,    5 /* Private */,
      10,    0,   78,    2, 0x08,    7 /* Private */,
      11,    0,   79,    2, 0x08,    8 /* Private */,
      12,    0,   80,    2, 0x08,    9 /* Private */,
      13,    0,   81,    2, 0x08,   10 /* Private */,
      14,    0,   82,    2, 0x08,   11 /* Private */,
      15,    0,   83,    2, 0x08,   12 /* Private */,
      16,    0,   84,    2, 0x08,   13 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 6,    3,    5,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ProtocolHierarchyDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProtocolHierarchyDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->filterAction((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<FilterAction::Action>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<FilterAction::ActionType>>(_a[3]))); break;
        case 1: _t->showProtoHierMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 2: _t->filterActionTriggered(); break;
        case 3: _t->on_actionCopyAsCsv_triggered(); break;
        case 4: _t->on_actionCopyAsYaml_triggered(); break;
        case 5: _t->on_actionCopyProtoList_triggered(); break;
        case 6: _t->on_actionDisableProtos_triggered(); break;
        case 7: _t->on_actionRevertProtos_triggered(); break;
        case 8: _t->on_buttonBox_helpRequested(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProtocolHierarchyDialog::*)(QString , FilterAction::Action , FilterAction::ActionType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolHierarchyDialog::filterAction)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ProtocolHierarchyDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<WiresharkDialog::staticMetaObject>(),
    qt_meta_stringdata_ProtocolHierarchyDialog.offsetsAndSize,
    qt_meta_data_ProtocolHierarchyDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ProtocolHierarchyDialog_t
, QtPrivate::TypeAndForceComplete<ProtocolHierarchyDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::Action, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::ActionType, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ProtocolHierarchyDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProtocolHierarchyDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProtocolHierarchyDialog.stringdata0))
        return static_cast<void*>(this);
    return WiresharkDialog::qt_metacast(_clname);
}

int ProtocolHierarchyDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ProtocolHierarchyDialog::filterAction(QString _t1, FilterAction::Action _t2, FilterAction::ActionType _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
