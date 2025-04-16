/****************************************************************************
** Meta object code from reading C++ file 'syntax_line_edit.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/syntax_line_edit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'syntax_line_edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SyntaxLineEdit_t {
    const uint offsetsAndSize[44];
    char stringdata0[245];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SyntaxLineEdit_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SyntaxLineEdit_t qt_meta_stringdata_SyntaxLineEdit = {
    {
QT_MOC_LITERAL(0, 14), // "SyntaxLineEdit"
QT_MOC_LITERAL(15, 13), // "setStyleSheet"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 11), // "style_sheet"
QT_MOC_LITERAL(42, 12), // "insertFilter"
QT_MOC_LITERAL(55, 6), // "filter"
QT_MOC_LITERAL(62, 18), // "checkDisplayFilter"
QT_MOC_LITERAL(81, 14), // "checkFieldName"
QT_MOC_LITERAL(96, 5), // "field"
QT_MOC_LITERAL(102, 17), // "checkCustomColumn"
QT_MOC_LITERAL(120, 6), // "fields"
QT_MOC_LITERAL(127, 12), // "checkInteger"
QT_MOC_LITERAL(140, 6), // "number"
QT_MOC_LITERAL(147, 21), // "insertFieldCompletion"
QT_MOC_LITERAL(169, 15), // "completion_text"
QT_MOC_LITERAL(185, 11), // "syntaxState"
QT_MOC_LITERAL(197, 11), // "SyntaxState"
QT_MOC_LITERAL(209, 5), // "Empty"
QT_MOC_LITERAL(215, 4), // "Busy"
QT_MOC_LITERAL(220, 7), // "Invalid"
QT_MOC_LITERAL(228, 10), // "Deprecated"
QT_MOC_LITERAL(239, 5) // "Valid"

    },
    "SyntaxLineEdit\0setStyleSheet\0\0style_sheet\0"
    "insertFilter\0filter\0checkDisplayFilter\0"
    "checkFieldName\0field\0checkCustomColumn\0"
    "fields\0checkInteger\0number\0"
    "insertFieldCompletion\0completion_text\0"
    "syntaxState\0SyntaxState\0Empty\0Busy\0"
    "Invalid\0Deprecated\0Valid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SyntaxLineEdit[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       1,   77, // properties
       1,   82, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x0a,    2 /* Public */,
       4,    1,   59,    2, 0x0a,    4 /* Public */,
       6,    1,   62,    2, 0x0a,    6 /* Public */,
       7,    1,   65,    2, 0x0a,    8 /* Public */,
       9,    1,   68,    2, 0x0a,   10 /* Public */,
      11,    1,   71,    2, 0x0a,   12 /* Public */,
      13,    1,   74,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Bool, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,

 // properties: name, type, flags
      15, 0x80000000 | 16, 0x00015009, uint(-1), 0,

 // enums: name, alias, flags, count, data
      16,   16, 0x0,    5,   87,

 // enum data: key, value
      17, uint(SyntaxLineEdit::Empty),
      18, uint(SyntaxLineEdit::Busy),
      19, uint(SyntaxLineEdit::Invalid),
      20, uint(SyntaxLineEdit::Deprecated),
      21, uint(SyntaxLineEdit::Valid),

       0        // eod
};

void SyntaxLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SyntaxLineEdit *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setStyleSheet((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->insertFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: { bool _r = _t->checkDisplayFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->checkFieldName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->checkCustomColumn((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->checkInteger((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->insertFieldCompletion((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SyntaxLineEdit *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< SyntaxState*>(_v) = _t->syntaxState(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject SyntaxLineEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QLineEdit::staticMetaObject>(),
    qt_meta_stringdata_SyntaxLineEdit.offsetsAndSize,
    qt_meta_data_SyntaxLineEdit,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SyntaxLineEdit_t
, QtPrivate::TypeAndForceComplete<SyntaxState, std::true_type>, QtPrivate::TypeAndForceComplete<SyntaxLineEdit, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *SyntaxLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SyntaxLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SyntaxLineEdit.stringdata0))
        return static_cast<void*>(this);
    return QLineEdit::qt_metacast(_clname);
}

int SyntaxLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
