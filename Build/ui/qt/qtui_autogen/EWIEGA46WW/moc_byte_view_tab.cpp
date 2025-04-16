/****************************************************************************
** Meta object code from reading C++ file 'byte_view_tab.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/byte_view_tab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'byte_view_tab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ByteViewTab_t {
    const uint offsetsAndSize[40];
    char stringdata0[316];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ByteViewTab_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ByteViewTab_t qt_meta_stringdata_ByteViewTab = {
    {
QT_MOC_LITERAL(0, 11), // "ByteViewTab"
QT_MOC_LITERAL(12, 13), // "fieldSelected"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 17), // "FieldInformation*"
QT_MOC_LITERAL(45, 14), // "fieldHighlight"
QT_MOC_LITERAL(60, 23), // "byteViewSettingsChanged"
QT_MOC_LITERAL(84, 19), // "byteViewUnmarkField"
QT_MOC_LITERAL(104, 10), // "detachData"
QT_MOC_LITERAL(115, 14), // "setCaptureFile"
QT_MOC_LITERAL(130, 13), // "capture_file*"
QT_MOC_LITERAL(144, 2), // "cf"
QT_MOC_LITERAL(147, 20), // "selectedFrameChanged"
QT_MOC_LITERAL(168, 10), // "QList<int>"
QT_MOC_LITERAL(179, 20), // "selectedFieldChanged"
QT_MOC_LITERAL(200, 23), // "highlightedFieldChanged"
QT_MOC_LITERAL(224, 18), // "captureFileClosing"
QT_MOC_LITERAL(243, 19), // "byteViewTextHovered"
QT_MOC_LITERAL(263, 18), // "byteViewTextMarked"
QT_MOC_LITERAL(282, 19), // "connectToMainWindow"
QT_MOC_LITERAL(302, 13) // "captureActive"

    },
    "ByteViewTab\0fieldSelected\0\0FieldInformation*\0"
    "fieldHighlight\0byteViewSettingsChanged\0"
    "byteViewUnmarkField\0detachData\0"
    "setCaptureFile\0capture_file*\0cf\0"
    "selectedFrameChanged\0QList<int>\0"
    "selectedFieldChanged\0highlightedFieldChanged\0"
    "captureFileClosing\0byteViewTextHovered\0"
    "byteViewTextMarked\0connectToMainWindow\0"
    "captureActive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ByteViewTab[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x06,    1 /* Public */,
       4,    1,  101,    2, 0x06,    3 /* Public */,
       5,    0,  104,    2, 0x06,    5 /* Public */,
       6,    0,  105,    2, 0x06,    6 /* Public */,
       7,    0,  106,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,  107,    2, 0x0a,    8 /* Public */,
      11,    1,  110,    2, 0x0a,   10 /* Public */,
      13,    1,  113,    2, 0x0a,   12 /* Public */,
      14,    1,  116,    2, 0x0a,   14 /* Public */,
      15,    0,  119,    2, 0x0a,   16 /* Public */,
      16,    1,  120,    2, 0x08,   17 /* Private */,
      17,    1,  123,    2, 0x08,   19 /* Private */,
      18,    0,  126,    2, 0x08,   21 /* Private */,
      19,    1,  127,    2, 0x08,   22 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void ByteViewTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ByteViewTab *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->fieldSelected((*reinterpret_cast< std::add_pointer_t<FieldInformation*>>(_a[1]))); break;
        case 1: _t->fieldHighlight((*reinterpret_cast< std::add_pointer_t<FieldInformation*>>(_a[1]))); break;
        case 2: _t->byteViewSettingsChanged(); break;
        case 3: _t->byteViewUnmarkField(); break;
        case 4: _t->detachData(); break;
        case 5: _t->setCaptureFile((*reinterpret_cast< std::add_pointer_t<capture_file*>>(_a[1]))); break;
        case 6: _t->selectedFrameChanged((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 7: _t->selectedFieldChanged((*reinterpret_cast< std::add_pointer_t<FieldInformation*>>(_a[1]))); break;
        case 8: _t->highlightedFieldChanged((*reinterpret_cast< std::add_pointer_t<FieldInformation*>>(_a[1]))); break;
        case 9: _t->captureFileClosing(); break;
        case 10: _t->byteViewTextHovered((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->byteViewTextMarked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->connectToMainWindow(); break;
        case 13: _t->captureActive((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FieldInformation* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FieldInformation* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FieldInformation* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FieldInformation* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ByteViewTab::*)(FieldInformation * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ByteViewTab::fieldSelected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ByteViewTab::*)(FieldInformation * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ByteViewTab::fieldHighlight)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ByteViewTab::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ByteViewTab::byteViewSettingsChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ByteViewTab::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ByteViewTab::byteViewUnmarkField)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ByteViewTab::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ByteViewTab::detachData)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject ByteViewTab::staticMetaObject = { {
    QMetaObject::SuperData::link<QTabWidget::staticMetaObject>(),
    qt_meta_stringdata_ByteViewTab.offsetsAndSize,
    qt_meta_data_ByteViewTab,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ByteViewTab_t
, QtPrivate::TypeAndForceComplete<ByteViewTab, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<FieldInformation *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<FieldInformation *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_file *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<FieldInformation *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<FieldInformation *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *ByteViewTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ByteViewTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ByteViewTab.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int ByteViewTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ByteViewTab::fieldSelected(FieldInformation * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ByteViewTab::fieldHighlight(FieldInformation * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ByteViewTab::byteViewSettingsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ByteViewTab::byteViewUnmarkField()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ByteViewTab::detachData()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
