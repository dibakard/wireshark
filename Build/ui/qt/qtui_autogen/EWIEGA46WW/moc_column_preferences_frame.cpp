/****************************************************************************
** Meta object code from reading C++ file 'column_preferences_frame.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/column_preferences_frame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'column_preferences_frame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ColumnPreferencesFrame_t {
    const uint offsetsAndSize[26];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ColumnPreferencesFrame_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ColumnPreferencesFrame_t qt_meta_stringdata_ColumnPreferencesFrame = {
    {
QT_MOC_LITERAL(0, 22), // "ColumnPreferencesFrame"
QT_MOC_LITERAL(23, 16), // "selectionChanged"
QT_MOC_LITERAL(40, 0), // ""
QT_MOC_LITERAL(41, 14), // "QItemSelection"
QT_MOC_LITERAL(56, 8), // "selected"
QT_MOC_LITERAL(65, 10), // "deselected"
QT_MOC_LITERAL(76, 24), // "on_newToolButton_clicked"
QT_MOC_LITERAL(101, 27), // "on_deleteToolButton_clicked"
QT_MOC_LITERAL(129, 36), // "on_chkShowDisplayedOnly_state..."
QT_MOC_LITERAL(166, 44), // "on_columnTreeView_customConte..."
QT_MOC_LITERAL(211, 3), // "pos"
QT_MOC_LITERAL(215, 11), // "resetAction"
QT_MOC_LITERAL(227, 7) // "checked"

    },
    "ColumnPreferencesFrame\0selectionChanged\0"
    "\0QItemSelection\0selected\0deselected\0"
    "on_newToolButton_clicked\0"
    "on_deleteToolButton_clicked\0"
    "on_chkShowDisplayedOnly_stateChanged\0"
    "on_columnTreeView_customContextMenuRequested\0"
    "pos\0resetAction\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColumnPreferencesFrame[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   56,    2, 0x08,    1 /* Private */,
       6,    0,   61,    2, 0x08,    4 /* Private */,
       7,    0,   62,    2, 0x08,    5 /* Private */,
       8,    1,   63,    2, 0x08,    6 /* Private */,
       9,    1,   66,    2, 0x08,    8 /* Private */,
      11,    1,   69,    2, 0x08,   10 /* Private */,
      11,    0,   72,    2, 0x28,   12 /* Private | MethodCloned */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QPoint,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,

       0        // eod
};

void ColumnPreferencesFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ColumnPreferencesFrame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->selectionChanged((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[2]))); break;
        case 1: _t->on_newToolButton_clicked(); break;
        case 2: _t->on_deleteToolButton_clicked(); break;
        case 3: _t->on_chkShowDisplayedOnly_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_columnTreeView_customContextMenuRequested((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 5: _t->resetAction((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->resetAction(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QItemSelection >(); break;
            }
            break;
        }
    }
}

const QMetaObject ColumnPreferencesFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_ColumnPreferencesFrame.offsetsAndSize,
    qt_meta_data_ColumnPreferencesFrame,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ColumnPreferencesFrame_t
, QtPrivate::TypeAndForceComplete<ColumnPreferencesFrame, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>, QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ColumnPreferencesFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColumnPreferencesFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ColumnPreferencesFrame.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int ColumnPreferencesFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
