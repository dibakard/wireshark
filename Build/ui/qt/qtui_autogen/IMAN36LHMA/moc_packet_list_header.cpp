/****************************************************************************
** Meta object code from reading C++ file 'packet_list_header.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/packet_list_header.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'packet_list_header.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PacketListHeader_t {
    const uint offsetsAndSize[40];
    char stringdata0[262];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PacketListHeader_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PacketListHeader_t qt_meta_stringdata_PacketListHeader = {
    {
QT_MOC_LITERAL(0, 16), // "PacketListHeader"
QT_MOC_LITERAL(17, 16), // "resetColumnWidth"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 3), // "col"
QT_MOC_LITERAL(39, 13), // "updatePackets"
QT_MOC_LITERAL(53, 6), // "redraw"
QT_MOC_LITERAL(60, 21), // "showColumnPreferences"
QT_MOC_LITERAL(82, 9), // "pane_name"
QT_MOC_LITERAL(92, 10), // "editColumn"
QT_MOC_LITERAL(103, 6), // "column"
QT_MOC_LITERAL(110, 14), // "columnsChanged"
QT_MOC_LITERAL(125, 25), // "columnVisibilityTriggered"
QT_MOC_LITERAL(151, 12), // "setAlignment"
QT_MOC_LITERAL(164, 8), // "QAction*"
QT_MOC_LITERAL(173, 16), // "setDisplayFormat"
QT_MOC_LITERAL(190, 15), // "showColumnPrefs"
QT_MOC_LITERAL(206, 12), // "doEditColumn"
QT_MOC_LITERAL(219, 15), // "resizeToContent"
QT_MOC_LITERAL(235, 12), // "removeColumn"
QT_MOC_LITERAL(248, 13) // "resizeToWidth"

    },
    "PacketListHeader\0resetColumnWidth\0\0"
    "col\0updatePackets\0redraw\0showColumnPreferences\0"
    "pane_name\0editColumn\0column\0columnsChanged\0"
    "columnVisibilityTriggered\0setAlignment\0"
    "QAction*\0setDisplayFormat\0showColumnPrefs\0"
    "doEditColumn\0resizeToContent\0removeColumn\0"
    "resizeToWidth"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PacketListHeader[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x06,    1 /* Public */,
       4,    1,   95,    2, 0x06,    3 /* Public */,
       6,    1,   98,    2, 0x06,    5 /* Public */,
       8,    1,  101,    2, 0x06,    7 /* Public */,
      10,    0,  104,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,  105,    2, 0x09,   10 /* Protected */,
      12,    1,  106,    2, 0x09,   11 /* Protected */,
      14,    1,  109,    2, 0x09,   13 /* Protected */,
      15,    0,  112,    2, 0x09,   15 /* Protected */,
      16,    0,  113,    2, 0x09,   16 /* Protected */,
      17,    0,  114,    2, 0x09,   17 /* Protected */,
      18,    0,  115,    2, 0x09,   18 /* Protected */,
      19,    0,  116,    2, 0x09,   19 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PacketListHeader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PacketListHeader *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resetColumnWidth((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->updatePackets((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->showColumnPreferences((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->editColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->columnsChanged(); break;
        case 5: _t->columnVisibilityTriggered(); break;
        case 6: _t->setAlignment((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 7: _t->setDisplayFormat((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 8: _t->showColumnPrefs(); break;
        case 9: _t->doEditColumn(); break;
        case 10: _t->resizeToContent(); break;
        case 11: _t->removeColumn(); break;
        case 12: _t->resizeToWidth(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PacketListHeader::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketListHeader::resetColumnWidth)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PacketListHeader::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketListHeader::updatePackets)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PacketListHeader::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketListHeader::showColumnPreferences)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PacketListHeader::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketListHeader::editColumn)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PacketListHeader::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketListHeader::columnsChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject PacketListHeader::staticMetaObject = { {
    QMetaObject::SuperData::link<QHeaderView::staticMetaObject>(),
    qt_meta_stringdata_PacketListHeader.offsetsAndSize,
    qt_meta_data_PacketListHeader,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PacketListHeader_t
, QtPrivate::TypeAndForceComplete<PacketListHeader, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAction *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAction *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *PacketListHeader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PacketListHeader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PacketListHeader.stringdata0))
        return static_cast<void*>(this);
    return QHeaderView::qt_metacast(_clname);
}

int PacketListHeader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QHeaderView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void PacketListHeader::resetColumnWidth(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PacketListHeader::updatePackets(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PacketListHeader::showColumnPreferences(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PacketListHeader::editColumn(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PacketListHeader::columnsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
