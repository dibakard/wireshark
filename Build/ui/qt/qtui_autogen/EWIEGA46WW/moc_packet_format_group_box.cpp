/****************************************************************************
** Meta object code from reading C++ file 'packet_format_group_box.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/packet_format_group_box.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'packet_format_group_box.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PacketFormatGroupBox_t {
    const uint offsetsAndSize[6];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PacketFormatGroupBox_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PacketFormatGroupBox_t qt_meta_stringdata_PacketFormatGroupBox = {
    {
QT_MOC_LITERAL(0, 20), // "PacketFormatGroupBox"
QT_MOC_LITERAL(21, 13), // "formatChanged"
QT_MOC_LITERAL(35, 0) // ""

    },
    "PacketFormatGroupBox\0formatChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PacketFormatGroupBox[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void PacketFormatGroupBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PacketFormatGroupBox *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->formatChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PacketFormatGroupBox::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketFormatGroupBox::formatChanged)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject PacketFormatGroupBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QGroupBox::staticMetaObject>(),
    qt_meta_stringdata_PacketFormatGroupBox.offsetsAndSize,
    qt_meta_data_PacketFormatGroupBox,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PacketFormatGroupBox_t
, QtPrivate::TypeAndForceComplete<PacketFormatGroupBox, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>



>,
    nullptr
} };


const QMetaObject *PacketFormatGroupBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PacketFormatGroupBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PacketFormatGroupBox.stringdata0))
        return static_cast<void*>(this);
    return QGroupBox::qt_metacast(_clname);
}

int PacketFormatGroupBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void PacketFormatGroupBox::formatChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_PacketFormatBlankGroupBox_t {
    const uint offsetsAndSize[2];
    char stringdata0[26];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PacketFormatBlankGroupBox_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PacketFormatBlankGroupBox_t qt_meta_stringdata_PacketFormatBlankGroupBox = {
    {
QT_MOC_LITERAL(0, 25) // "PacketFormatBlankGroupBox"

    },
    "PacketFormatBlankGroupBox"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PacketFormatBlankGroupBox[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void PacketFormatBlankGroupBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject PacketFormatBlankGroupBox::staticMetaObject = { {
    QMetaObject::SuperData::link<PacketFormatGroupBox::staticMetaObject>(),
    qt_meta_stringdata_PacketFormatBlankGroupBox.offsetsAndSize,
    qt_meta_data_PacketFormatBlankGroupBox,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PacketFormatBlankGroupBox_t
, QtPrivate::TypeAndForceComplete<PacketFormatBlankGroupBox, std::true_type>



>,
    nullptr
} };


const QMetaObject *PacketFormatBlankGroupBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PacketFormatBlankGroupBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PacketFormatBlankGroupBox.stringdata0))
        return static_cast<void*>(this);
    return PacketFormatGroupBox::qt_metacast(_clname);
}

int PacketFormatBlankGroupBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PacketFormatGroupBox::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_PacketFormatTextGroupBox_t {
    const uint offsetsAndSize[24];
    char stringdata0[309];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PacketFormatTextGroupBox_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PacketFormatTextGroupBox_t qt_meta_stringdata_PacketFormatTextGroupBox = {
    {
QT_MOC_LITERAL(0, 24), // "PacketFormatTextGroupBox"
QT_MOC_LITERAL(25, 26), // "on_summaryCheckBox_toggled"
QT_MOC_LITERAL(52, 0), // ""
QT_MOC_LITERAL(53, 7), // "checked"
QT_MOC_LITERAL(61, 26), // "on_detailsCheckBox_toggled"
QT_MOC_LITERAL(88, 24), // "on_bytesCheckBox_toggled"
QT_MOC_LITERAL(113, 40), // "on_includeColumnHeadingsCheck..."
QT_MOC_LITERAL(154, 29), // "on_allCollapsedButton_toggled"
QT_MOC_LITERAL(184, 28), // "on_asDisplayedButton_toggled"
QT_MOC_LITERAL(213, 28), // "on_allExpandedButton_toggled"
QT_MOC_LITERAL(242, 37), // "on_includeDataSourcesCheckBox..."
QT_MOC_LITERAL(280, 28) // "on_timestampCheckBox_toggled"

    },
    "PacketFormatTextGroupBox\0"
    "on_summaryCheckBox_toggled\0\0checked\0"
    "on_detailsCheckBox_toggled\0"
    "on_bytesCheckBox_toggled\0"
    "on_includeColumnHeadingsCheckBox_toggled\0"
    "on_allCollapsedButton_toggled\0"
    "on_asDisplayedButton_toggled\0"
    "on_allExpandedButton_toggled\0"
    "on_includeDataSourcesCheckBox_toggled\0"
    "on_timestampCheckBox_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PacketFormatTextGroupBox[] = {

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
       1,    1,   68,    2, 0x08,    1 /* Private */,
       4,    1,   71,    2, 0x08,    3 /* Private */,
       5,    1,   74,    2, 0x08,    5 /* Private */,
       6,    1,   77,    2, 0x08,    7 /* Private */,
       7,    1,   80,    2, 0x08,    9 /* Private */,
       8,    1,   83,    2, 0x08,   11 /* Private */,
       9,    1,   86,    2, 0x08,   13 /* Private */,
      10,    1,   89,    2, 0x08,   15 /* Private */,
      11,    1,   92,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void PacketFormatTextGroupBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PacketFormatTextGroupBox *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_summaryCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->on_detailsCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->on_bytesCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->on_includeColumnHeadingsCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->on_allCollapsedButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->on_asDisplayedButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->on_allExpandedButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->on_includeDataSourcesCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->on_timestampCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject PacketFormatTextGroupBox::staticMetaObject = { {
    QMetaObject::SuperData::link<PacketFormatGroupBox::staticMetaObject>(),
    qt_meta_stringdata_PacketFormatTextGroupBox.offsetsAndSize,
    qt_meta_data_PacketFormatTextGroupBox,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PacketFormatTextGroupBox_t
, QtPrivate::TypeAndForceComplete<PacketFormatTextGroupBox, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *PacketFormatTextGroupBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PacketFormatTextGroupBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PacketFormatTextGroupBox.stringdata0))
        return static_cast<void*>(this);
    return PacketFormatGroupBox::qt_metacast(_clname);
}

int PacketFormatTextGroupBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PacketFormatGroupBox::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_PacketFormatJSONGroupBox_t {
    const uint offsetsAndSize[2];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PacketFormatJSONGroupBox_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PacketFormatJSONGroupBox_t qt_meta_stringdata_PacketFormatJSONGroupBox = {
    {
QT_MOC_LITERAL(0, 24) // "PacketFormatJSONGroupBox"

    },
    "PacketFormatJSONGroupBox"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PacketFormatJSONGroupBox[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void PacketFormatJSONGroupBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject PacketFormatJSONGroupBox::staticMetaObject = { {
    QMetaObject::SuperData::link<PacketFormatGroupBox::staticMetaObject>(),
    qt_meta_stringdata_PacketFormatJSONGroupBox.offsetsAndSize,
    qt_meta_data_PacketFormatJSONGroupBox,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PacketFormatJSONGroupBox_t
, QtPrivate::TypeAndForceComplete<PacketFormatJSONGroupBox, std::true_type>



>,
    nullptr
} };


const QMetaObject *PacketFormatJSONGroupBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PacketFormatJSONGroupBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PacketFormatJSONGroupBox.stringdata0))
        return static_cast<void*>(this);
    return PacketFormatGroupBox::qt_metacast(_clname);
}

int PacketFormatJSONGroupBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PacketFormatGroupBox::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
