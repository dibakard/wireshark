/****************************************************************************
** Meta object code from reading C++ file 'packet_list_model.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/models/packet_list_model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'packet_list_model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PacketListModel_t {
    const uint offsetsAndSize[42];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PacketListModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PacketListModel_t qt_meta_stringdata_PacketListModel = {
    {
QT_MOC_LITERAL(0, 15), // "PacketListModel"
QT_MOC_LITERAL(16, 14), // "packetAppended"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 13), // "capture_file*"
QT_MOC_LITERAL(46, 8), // "cap_file"
QT_MOC_LITERAL(55, 11), // "frame_data*"
QT_MOC_LITERAL(67, 5), // "fdata"
QT_MOC_LITERAL(73, 9), // "qsizetype"
QT_MOC_LITERAL(83, 3), // "row"
QT_MOC_LITERAL(87, 10), // "goToPacket"
QT_MOC_LITERAL(98, 22), // "bgColorizationProgress"
QT_MOC_LITERAL(121, 5), // "first"
QT_MOC_LITERAL(127, 4), // "last"
QT_MOC_LITERAL(132, 4), // "sort"
QT_MOC_LITERAL(137, 6), // "column"
QT_MOC_LITERAL(144, 13), // "Qt::SortOrder"
QT_MOC_LITERAL(158, 5), // "order"
QT_MOC_LITERAL(164, 11), // "stopSorting"
QT_MOC_LITERAL(176, 16), // "flushVisibleRows"
QT_MOC_LITERAL(193, 11), // "dissectIdle"
QT_MOC_LITERAL(205, 5) // "reset"

    },
    "PacketListModel\0packetAppended\0\0"
    "capture_file*\0cap_file\0frame_data*\0"
    "fdata\0qsizetype\0row\0goToPacket\0"
    "bgColorizationProgress\0first\0last\0"
    "sort\0column\0Qt::SortOrder\0order\0"
    "stopSorting\0flushVisibleRows\0dissectIdle\0"
    "reset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PacketListModel[] = {

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
       9,    1,   75,    2, 0x06,    5 /* Public */,
      10,    2,   78,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    2,   83,    2, 0x0a,   10 /* Public */,
      13,    1,   88,    2, 0x2a,   13 /* Public | MethodCloned */,
      17,    0,   91,    2, 0x0a,   15 /* Public */,
      18,    0,   92,    2, 0x0a,   16 /* Public */,
      19,    1,   93,    2, 0x0a,   17 /* Public */,
      19,    0,   96,    2, 0x2a,   19 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 15,   14,   16,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void,

       0        // eod
};

void PacketListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PacketListModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->packetAppended((*reinterpret_cast< std::add_pointer_t<capture_file*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<frame_data*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qsizetype>>(_a[3]))); break;
        case 1: _t->goToPacket((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->bgColorizationProgress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->sort((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::SortOrder>>(_a[2]))); break;
        case 4: _t->sort((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->stopSorting(); break;
        case 6: _t->flushVisibleRows(); break;
        case 7: _t->dissectIdle((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->dissectIdle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PacketListModel::*)(capture_file * , frame_data * , qsizetype );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketListModel::packetAppended)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PacketListModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketListModel::goToPacket)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PacketListModel::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketListModel::bgColorizationProgress)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject PacketListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractItemModel::staticMetaObject>(),
    qt_meta_stringdata_PacketListModel.offsetsAndSize,
    qt_meta_data_PacketListModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PacketListModel_t
, QtPrivate::TypeAndForceComplete<PacketListModel, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_file *, std::false_type>, QtPrivate::TypeAndForceComplete<frame_data *, std::false_type>, QtPrivate::TypeAndForceComplete<qsizetype, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Qt::SortOrder, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *PacketListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PacketListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PacketListModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int PacketListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
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
void PacketListModel::packetAppended(capture_file * _t1, frame_data * _t2, qsizetype _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PacketListModel::goToPacket(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PacketListModel::bgColorizationProgress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
