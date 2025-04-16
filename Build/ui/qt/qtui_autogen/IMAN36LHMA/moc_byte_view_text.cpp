/****************************************************************************
** Meta object code from reading C++ file 'byte_view_text.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/byte_view_text.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'byte_view_text.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ByteViewText_t {
    const uint offsetsAndSize[46];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ByteViewText_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ByteViewText_t qt_meta_stringdata_ByteViewText = {
    {
QT_MOC_LITERAL(0, 12), // "ByteViewText"
QT_MOC_LITERAL(13, 11), // "byteHovered"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 3), // "pos"
QT_MOC_LITERAL(30, 12), // "byteSelected"
QT_MOC_LITERAL(43, 23), // "byteViewSettingsChanged"
QT_MOC_LITERAL(67, 16), // "setMonospaceFont"
QT_MOC_LITERAL(84, 9), // "mono_font"
QT_MOC_LITERAL(94, 22), // "updateByteViewSettings"
QT_MOC_LITERAL(117, 10), // "detachData"
QT_MOC_LITERAL(128, 12), // "markProtocol"
QT_MOC_LITERAL(141, 5), // "start"
QT_MOC_LITERAL(147, 6), // "length"
QT_MOC_LITERAL(154, 9), // "markField"
QT_MOC_LITERAL(164, 9), // "scroll_to"
QT_MOC_LITERAL(174, 12), // "markAppendix"
QT_MOC_LITERAL(187, 11), // "unmarkField"
QT_MOC_LITERAL(199, 9), // "copyBytes"
QT_MOC_LITERAL(209, 19), // "setHexDisplayFormat"
QT_MOC_LITERAL(229, 8), // "QAction*"
QT_MOC_LITERAL(238, 6), // "action"
QT_MOC_LITERAL(245, 20), // "setCharacterEncoding"
QT_MOC_LITERAL(266, 18) // "toggleHoverAllowed"

    },
    "ByteViewText\0byteHovered\0\0pos\0"
    "byteSelected\0byteViewSettingsChanged\0"
    "setMonospaceFont\0mono_font\0"
    "updateByteViewSettings\0detachData\0"
    "markProtocol\0start\0length\0markField\0"
    "scroll_to\0markAppendix\0unmarkField\0"
    "copyBytes\0setHexDisplayFormat\0QAction*\0"
    "action\0setCharacterEncoding\0"
    "toggleHoverAllowed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ByteViewText[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x06,    1 /* Public */,
       4,    1,  107,    2, 0x06,    3 /* Public */,
       5,    0,  110,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,  111,    2, 0x0a,    6 /* Public */,
       8,    0,  114,    2, 0x0a,    8 /* Public */,
       9,    0,  115,    2, 0x0a,    9 /* Public */,
      10,    2,  116,    2, 0x0a,   10 /* Public */,
      13,    3,  121,    2, 0x0a,   13 /* Public */,
      13,    2,  128,    2, 0x2a,   17 /* Public | MethodCloned */,
      15,    2,  133,    2, 0x0a,   20 /* Public */,
      16,    0,  138,    2, 0x0a,   23 /* Public */,
      17,    1,  139,    2, 0x08,   24 /* Private */,
      18,    1,  142,    2, 0x08,   26 /* Private */,
      21,    1,  145,    2, 0x08,   28 /* Private */,
      22,    1,  148,    2, 0x08,   30 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QFont,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   11,   12,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void ByteViewText::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ByteViewText *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->byteHovered((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->byteSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->byteViewSettingsChanged(); break;
        case 3: _t->setMonospaceFont((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        case 4: _t->updateByteViewSettings(); break;
        case 5: _t->detachData(); break;
        case 6: _t->markProtocol((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 7: _t->markField((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 8: _t->markField((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 9: _t->markAppendix((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 10: _t->unmarkField(); break;
        case 11: _t->copyBytes((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->setHexDisplayFormat((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 13: _t->setCharacterEncoding((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 14: _t->toggleHoverAllowed((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        case 13:
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
            using _t = void (ByteViewText::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ByteViewText::byteHovered)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ByteViewText::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ByteViewText::byteSelected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ByteViewText::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ByteViewText::byteViewSettingsChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ByteViewText::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractScrollArea::staticMetaObject>(),
    qt_meta_stringdata_ByteViewText.offsetsAndSize,
    qt_meta_data_ByteViewText,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ByteViewText_t
, QtPrivate::TypeAndForceComplete<ByteViewText, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QFont &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAction *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAction *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *ByteViewText::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ByteViewText::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ByteViewText.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "IDataPrintable"))
        return static_cast< IDataPrintable*>(this);
    if (!strcmp(_clname, "org.wireshark.Qt.UI.IDataPrintable"))
        return static_cast< IDataPrintable*>(this);
    return QAbstractScrollArea::qt_metacast(_clname);
}

int ByteViewText::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ByteViewText::byteHovered(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ByteViewText::byteSelected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ByteViewText::byteViewSettingsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
