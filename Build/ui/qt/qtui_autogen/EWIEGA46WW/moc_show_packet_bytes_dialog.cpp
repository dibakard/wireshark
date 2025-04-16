/****************************************************************************
** Meta object code from reading C++ file 'show_packet_bytes_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/show_packet_bytes_dialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'show_packet_bytes_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ShowPacketBytesDialog_t {
    const uint offsetsAndSize[44];
    char stringdata0[310];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ShowPacketBytesDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ShowPacketBytesDialog_t qt_meta_stringdata_ShowPacketBytesDialog = {
    {
QT_MOC_LITERAL(0, 21), // "ShowPacketBytesDialog"
QT_MOC_LITERAL(22, 23), // "on_sbStart_valueChanged"
QT_MOC_LITERAL(46, 0), // ""
QT_MOC_LITERAL(47, 5), // "value"
QT_MOC_LITERAL(53, 21), // "on_sbEnd_valueChanged"
QT_MOC_LITERAL(75, 33), // "on_cbDecodeAs_currentIndexCha..."
QT_MOC_LITERAL(109, 3), // "idx"
QT_MOC_LITERAL(113, 31), // "on_cbShowAs_currentIndexChanged"
QT_MOC_LITERAL(145, 23), // "on_leFind_returnPressed"
QT_MOC_LITERAL(169, 16), // "on_bFind_clicked"
QT_MOC_LITERAL(186, 21), // "on_buttonBox_rejected"
QT_MOC_LITERAL(208, 12), // "showSelected"
QT_MOC_LITERAL(221, 5), // "start"
QT_MOC_LITERAL(227, 3), // "end"
QT_MOC_LITERAL(231, 12), // "useRegexFind"
QT_MOC_LITERAL(244, 9), // "use_regex"
QT_MOC_LITERAL(254, 8), // "findText"
QT_MOC_LITERAL(263, 7), // "go_back"
QT_MOC_LITERAL(271, 10), // "helpButton"
QT_MOC_LITERAL(282, 10), // "printBytes"
QT_MOC_LITERAL(293, 9), // "copyBytes"
QT_MOC_LITERAL(303, 6) // "saveAs"

    },
    "ShowPacketBytesDialog\0on_sbStart_valueChanged\0"
    "\0value\0on_sbEnd_valueChanged\0"
    "on_cbDecodeAs_currentIndexChanged\0idx\0"
    "on_cbShowAs_currentIndexChanged\0"
    "on_leFind_returnPressed\0on_bFind_clicked\0"
    "on_buttonBox_rejected\0showSelected\0"
    "start\0end\0useRegexFind\0use_regex\0"
    "findText\0go_back\0helpButton\0printBytes\0"
    "copyBytes\0saveAs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShowPacketBytesDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x08,    1 /* Private */,
       4,    1,  107,    2, 0x08,    3 /* Private */,
       5,    1,  110,    2, 0x08,    5 /* Private */,
       7,    1,  113,    2, 0x08,    7 /* Private */,
       8,    0,  116,    2, 0x08,    9 /* Private */,
       9,    0,  117,    2, 0x08,   10 /* Private */,
      10,    0,  118,    2, 0x08,   11 /* Private */,
      11,    2,  119,    2, 0x08,   12 /* Private */,
      14,    1,  124,    2, 0x08,   15 /* Private */,
      16,    1,  127,    2, 0x08,   17 /* Private */,
      16,    0,  130,    2, 0x28,   19 /* Private | MethodCloned */,
      18,    0,  131,    2, 0x08,   20 /* Private */,
      19,    0,  132,    2, 0x08,   21 /* Private */,
      20,    0,  133,    2, 0x08,   22 /* Private */,
      21,    0,  134,    2, 0x08,   23 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ShowPacketBytesDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ShowPacketBytesDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_sbStart_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_sbEnd_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_cbDecodeAs_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_cbShowAs_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_leFind_returnPressed(); break;
        case 5: _t->on_bFind_clicked(); break;
        case 6: _t->on_buttonBox_rejected(); break;
        case 7: _t->showSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 8: _t->useRegexFind((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->findText((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->findText(); break;
        case 11: _t->helpButton(); break;
        case 12: _t->printBytes(); break;
        case 13: _t->copyBytes(); break;
        case 14: _t->saveAs(); break;
        default: ;
        }
    }
}

const QMetaObject ShowPacketBytesDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<WiresharkDialog::staticMetaObject>(),
    qt_meta_stringdata_ShowPacketBytesDialog.offsetsAndSize,
    qt_meta_data_ShowPacketBytesDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ShowPacketBytesDialog_t
, QtPrivate::TypeAndForceComplete<ShowPacketBytesDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ShowPacketBytesDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShowPacketBytesDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShowPacketBytesDialog.stringdata0))
        return static_cast<void*>(this);
    return WiresharkDialog::qt_metacast(_clname);
}

int ShowPacketBytesDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WiresharkDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
struct qt_meta_stringdata_ShowPacketBytesTextEdit_t {
    const uint offsetsAndSize[14];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ShowPacketBytesTextEdit_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ShowPacketBytesTextEdit_t qt_meta_stringdata_ShowPacketBytesTextEdit = {
    {
QT_MOC_LITERAL(0, 23), // "ShowPacketBytesTextEdit"
QT_MOC_LITERAL(24, 12), // "showSelected"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 16), // "contextMenuEvent"
QT_MOC_LITERAL(55, 18), // "QContextMenuEvent*"
QT_MOC_LITERAL(74, 5), // "event"
QT_MOC_LITERAL(80, 7) // "showAll"

    },
    "ShowPacketBytesTextEdit\0showSelected\0"
    "\0contextMenuEvent\0QContextMenuEvent*\0"
    "event\0showAll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShowPacketBytesTextEdit[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   43,    2, 0x08,    4 /* Private */,
       1,    0,   46,    2, 0x08,    6 /* Private */,
       6,    0,   47,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ShowPacketBytesTextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ShowPacketBytesTextEdit *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->contextMenuEvent((*reinterpret_cast< std::add_pointer_t<QContextMenuEvent*>>(_a[1]))); break;
        case 2: _t->showSelected(); break;
        case 3: _t->showAll(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ShowPacketBytesTextEdit::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShowPacketBytesTextEdit::showSelected)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ShowPacketBytesTextEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QTextEdit::staticMetaObject>(),
    qt_meta_stringdata_ShowPacketBytesTextEdit.offsetsAndSize,
    qt_meta_data_ShowPacketBytesTextEdit,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ShowPacketBytesTextEdit_t
, QtPrivate::TypeAndForceComplete<ShowPacketBytesTextEdit, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QContextMenuEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ShowPacketBytesTextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShowPacketBytesTextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShowPacketBytesTextEdit.stringdata0))
        return static_cast<void*>(this);
    return QTextEdit::qt_metacast(_clname);
}

int ShowPacketBytesTextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ShowPacketBytesTextEdit::showSelected(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
