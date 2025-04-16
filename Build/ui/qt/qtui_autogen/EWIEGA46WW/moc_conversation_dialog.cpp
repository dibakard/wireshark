/****************************************************************************
** Meta object code from reading C++ file 'conversation_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/conversation_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'conversation_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConversationDialog_t {
    const uint offsetsAndSize[38];
    char stringdata0[234];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ConversationDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ConversationDialog_t qt_meta_stringdata_ConversationDialog = {
    {
QT_MOC_LITERAL(0, 18), // "ConversationDialog"
QT_MOC_LITERAL(19, 22), // "openFollowStreamDialog"
QT_MOC_LITERAL(42, 0), // ""
QT_MOC_LITERAL(43, 8), // "proto_id"
QT_MOC_LITERAL(52, 10), // "stream_num"
QT_MOC_LITERAL(63, 14), // "sub_stream_num"
QT_MOC_LITERAL(78, 11), // "openIOGraph"
QT_MOC_LITERAL(90, 8), // "filtered"
QT_MOC_LITERAL(99, 11), // "QList<uint>"
QT_MOC_LITERAL(111, 8), // "conv_ids"
QT_MOC_LITERAL(120, 8), // "conv_agg"
QT_MOC_LITERAL(129, 12), // "followStream"
QT_MOC_LITERAL(142, 8), // "graphTcp"
QT_MOC_LITERAL(151, 11), // "showGraphIO"
QT_MOC_LITERAL(163, 26), // "on_buttonBox_helpRequested"
QT_MOC_LITERAL(190, 20), // "displayFilterSuccess"
QT_MOC_LITERAL(211, 7), // "success"
QT_MOC_LITERAL(219, 10), // "tabChanged"
QT_MOC_LITERAL(230, 3) // "idx"

    },
    "ConversationDialog\0openFollowStreamDialog\0"
    "\0proto_id\0stream_num\0sub_stream_num\0"
    "openIOGraph\0filtered\0QList<uint>\0"
    "conv_ids\0conv_agg\0followStream\0graphTcp\0"
    "showGraphIO\0on_buttonBox_helpRequested\0"
    "displayFilterSuccess\0success\0tabChanged\0"
    "idx"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConversationDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   62,    2, 0x06,    1 /* Public */,
       6,    3,   69,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,   76,    2, 0x08,    9 /* Private */,
      12,    0,   77,    2, 0x08,   10 /* Private */,
      13,    0,   78,    2, 0x08,   11 /* Private */,
      14,    0,   79,    2, 0x08,   12 /* Private */,
      15,    1,   80,    2, 0x08,   13 /* Private */,
      17,    1,   83,    2, 0x08,   15 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::UInt, QMetaType::UInt,    3,    4,    5,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 8, QMetaType::QVariantList,    7,    9,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void ConversationDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConversationDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openFollowStreamDialog((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[3]))); break;
        case 1: _t->openIOGraph((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<uint>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<QVariant>>>(_a[3]))); break;
        case 2: _t->followStream(); break;
        case 3: _t->graphTcp(); break;
        case 4: _t->showGraphIO(); break;
        case 5: _t->on_buttonBox_helpRequested(); break;
        case 6: _t->displayFilterSuccess((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->tabChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<uint> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConversationDialog::*)(int , unsigned  , unsigned  );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConversationDialog::openFollowStreamDialog)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ConversationDialog::*)(bool , QVector<uint> , QVector<QVariant> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConversationDialog::openIOGraph)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ConversationDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<TrafficTableDialog::staticMetaObject>(),
    qt_meta_stringdata_ConversationDialog.offsetsAndSize,
    qt_meta_data_ConversationDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ConversationDialog_t
, QtPrivate::TypeAndForceComplete<ConversationDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<unsigned , std::false_type>, QtPrivate::TypeAndForceComplete<unsigned , std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<uint>, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<QVariant>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *ConversationDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConversationDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConversationDialog.stringdata0))
        return static_cast<void*>(this);
    return TrafficTableDialog::qt_metacast(_clname);
}

int ConversationDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TrafficTableDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ConversationDialog::openFollowStreamDialog(int _t1, unsigned  _t2, unsigned  _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ConversationDialog::openIOGraph(bool _t1, QVector<uint> _t2, QVector<QVariant> _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
