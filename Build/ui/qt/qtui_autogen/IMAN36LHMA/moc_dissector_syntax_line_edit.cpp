/****************************************************************************
** Meta object code from reading C++ file 'dissector_syntax_line_edit.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/dissector_syntax_line_edit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dissector_syntax_line_edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DissectorSyntaxLineEdit_t {
    const uint offsetsAndSize[14];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DissectorSyntaxLineEdit_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DissectorSyntaxLineEdit_t qt_meta_stringdata_DissectorSyntaxLineEdit = {
    {
QT_MOC_LITERAL(0, 23), // "DissectorSyntaxLineEdit"
QT_MOC_LITERAL(24, 18), // "checkDissectorName"
QT_MOC_LITERAL(43, 0), // ""
QT_MOC_LITERAL(44, 9), // "dissector"
QT_MOC_LITERAL(54, 11), // "changeEvent"
QT_MOC_LITERAL(66, 7), // "QEvent*"
QT_MOC_LITERAL(74, 5) // "event"

    },
    "DissectorSyntaxLineEdit\0checkDissectorName\0"
    "\0dissector\0changeEvent\0QEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DissectorSyntaxLineEdit[] = {

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
       4,    1,   29,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void DissectorSyntaxLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DissectorSyntaxLineEdit *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->checkDissectorName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->changeEvent((*reinterpret_cast< std::add_pointer_t<QEvent*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DissectorSyntaxLineEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<SyntaxLineEdit::staticMetaObject>(),
    qt_meta_stringdata_DissectorSyntaxLineEdit.offsetsAndSize,
    qt_meta_data_DissectorSyntaxLineEdit,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DissectorSyntaxLineEdit_t
, QtPrivate::TypeAndForceComplete<DissectorSyntaxLineEdit, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QEvent *, std::false_type>


>,
    nullptr
} };


const QMetaObject *DissectorSyntaxLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DissectorSyntaxLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DissectorSyntaxLineEdit.stringdata0))
        return static_cast<void*>(this);
    return SyntaxLineEdit::qt_metacast(_clname);
}

int DissectorSyntaxLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SyntaxLineEdit::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
