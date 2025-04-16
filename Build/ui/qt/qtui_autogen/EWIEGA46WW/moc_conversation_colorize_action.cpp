/****************************************************************************
** Meta object code from reading C++ file 'conversation_colorize_action.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/conversation_colorize_action.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'conversation_colorize_action.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConversationAction_t {
    const uint offsetsAndSize[14];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ConversationAction_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ConversationAction_t qt_meta_stringdata_ConversationAction = {
    {
QT_MOC_LITERAL(0, 18), // "ConversationAction"
QT_MOC_LITERAL(19, 13), // "setPacketInfo"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 13), // "_packet_info*"
QT_MOC_LITERAL(48, 5), // "pinfo"
QT_MOC_LITERAL(54, 14), // "setFieldFilter"
QT_MOC_LITERAL(69, 12) // "field_filter"

    },
    "ConversationAction\0setPacketInfo\0\0"
    "_packet_info*\0pinfo\0setFieldFilter\0"
    "field_filter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConversationAction[] = {

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
       5,    1,   29,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QByteArray,    6,

       0        // eod
};

void ConversationAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConversationAction *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setPacketInfo((*reinterpret_cast< std::add_pointer_t<_packet_info*>>(_a[1]))); break;
        case 1: _t->setFieldFilter((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ConversationAction::staticMetaObject = { {
    QMetaObject::SuperData::link<QAction::staticMetaObject>(),
    qt_meta_stringdata_ConversationAction.offsetsAndSize,
    qt_meta_data_ConversationAction,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ConversationAction_t
, QtPrivate::TypeAndForceComplete<ConversationAction, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<_packet_info *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray, std::false_type>


>,
    nullptr
} };


const QMetaObject *ConversationAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConversationAction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConversationAction.stringdata0))
        return static_cast<void*>(this);
    return QAction::qt_metacast(_clname);
}

int ConversationAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAction::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_ColorizeAction_t {
    const uint offsetsAndSize[8];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ColorizeAction_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ColorizeAction_t qt_meta_stringdata_ColorizeAction = {
    {
QT_MOC_LITERAL(0, 14), // "ColorizeAction"
QT_MOC_LITERAL(15, 14), // "setFieldFilter"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 12) // "field_filter"

    },
    "ColorizeAction\0setFieldFilter\0\0"
    "field_filter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColorizeAction[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x0a,    1 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

       0        // eod
};

void ColorizeAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ColorizeAction *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setFieldFilter((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ColorizeAction::staticMetaObject = { {
    QMetaObject::SuperData::link<QAction::staticMetaObject>(),
    qt_meta_stringdata_ColorizeAction.offsetsAndSize,
    qt_meta_data_ColorizeAction,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ColorizeAction_t
, QtPrivate::TypeAndForceComplete<ColorizeAction, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray, std::false_type>


>,
    nullptr
} };


const QMetaObject *ColorizeAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorizeAction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ColorizeAction.stringdata0))
        return static_cast<void*>(this);
    return QAction::qt_metacast(_clname);
}

int ColorizeAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
