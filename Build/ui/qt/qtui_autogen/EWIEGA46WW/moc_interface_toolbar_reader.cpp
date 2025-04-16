/****************************************************************************
** Meta object code from reading C++ file 'interface_toolbar_reader.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/interface_toolbar_reader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interface_toolbar_reader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InterfaceToolbarReader_t {
    const uint offsetsAndSize[18];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_InterfaceToolbarReader_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_InterfaceToolbarReader_t qt_meta_stringdata_InterfaceToolbarReader = {
    {
QT_MOC_LITERAL(0, 22), // "InterfaceToolbarReader"
QT_MOC_LITERAL(23, 8), // "received"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 6), // "ifname"
QT_MOC_LITERAL(40, 3), // "num"
QT_MOC_LITERAL(44, 7), // "command"
QT_MOC_LITERAL(52, 7), // "payload"
QT_MOC_LITERAL(60, 8), // "finished"
QT_MOC_LITERAL(69, 4) // "loop"

    },
    "InterfaceToolbarReader\0received\0\0"
    "ifname\0num\0command\0payload\0finished\0"
    "loop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InterfaceToolbarReader[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   32,    2, 0x06,    1 /* Public */,
       7,    0,   41,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   42,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QByteArray,    3,    4,    5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void InterfaceToolbarReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InterfaceToolbarReader *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->received((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[4]))); break;
        case 1: _t->finished(); break;
        case 2: _t->loop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InterfaceToolbarReader::*)(QString , int , int , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InterfaceToolbarReader::received)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (InterfaceToolbarReader::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InterfaceToolbarReader::finished)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject InterfaceToolbarReader::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_InterfaceToolbarReader.offsetsAndSize,
    qt_meta_data_InterfaceToolbarReader,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_InterfaceToolbarReader_t
, QtPrivate::TypeAndForceComplete<InterfaceToolbarReader, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *InterfaceToolbarReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InterfaceToolbarReader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InterfaceToolbarReader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int InterfaceToolbarReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void InterfaceToolbarReader::received(QString _t1, int _t2, int _t3, QByteArray _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InterfaceToolbarReader::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
