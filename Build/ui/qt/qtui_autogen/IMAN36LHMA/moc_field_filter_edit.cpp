/****************************************************************************
** Meta object code from reading C++ file 'field_filter_edit.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/field_filter_edit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'field_filter_edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FieldFilterEdit_t {
    const uint offsetsAndSize[20];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FieldFilterEdit_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FieldFilterEdit_t qt_meta_stringdata_FieldFilterEdit = {
    {
QT_MOC_LITERAL(0, 15), // "FieldFilterEdit"
QT_MOC_LITERAL(16, 22), // "pushFilterSyntaxStatus"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 21), // "popFilterSyntaxStatus"
QT_MOC_LITERAL(62, 23), // "pushFilterSyntaxWarning"
QT_MOC_LITERAL(86, 11), // "checkFilter"
QT_MOC_LITERAL(98, 11), // "filter_text"
QT_MOC_LITERAL(110, 11), // "changeEvent"
QT_MOC_LITERAL(122, 7), // "QEvent*"
QT_MOC_LITERAL(130, 5) // "event"

    },
    "FieldFilterEdit\0pushFilterSyntaxStatus\0"
    "\0popFilterSyntaxStatus\0pushFilterSyntaxWarning\0"
    "checkFilter\0filter_text\0changeEvent\0"
    "QEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FieldFilterEdit[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       3,    0,   53,    2, 0x06,    3 /* Public */,
       4,    1,   54,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   57,    2, 0x0a,    6 /* Public */,
       5,    1,   58,    2, 0x08,    7 /* Private */,
       7,    1,   61,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void FieldFilterEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FieldFilterEdit *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pushFilterSyntaxStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->popFilterSyntaxStatus(); break;
        case 2: _t->pushFilterSyntaxWarning((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: { bool _r = _t->checkFilter();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->checkFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->changeEvent((*reinterpret_cast< std::add_pointer_t<QEvent*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FieldFilterEdit::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldFilterEdit::pushFilterSyntaxStatus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FieldFilterEdit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldFilterEdit::popFilterSyntaxStatus)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FieldFilterEdit::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldFilterEdit::pushFilterSyntaxWarning)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject FieldFilterEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<SyntaxLineEdit::staticMetaObject>(),
    qt_meta_stringdata_FieldFilterEdit.offsetsAndSize,
    qt_meta_data_FieldFilterEdit,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FieldFilterEdit_t
, QtPrivate::TypeAndForceComplete<FieldFilterEdit, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QEvent *, std::false_type>


>,
    nullptr
} };


const QMetaObject *FieldFilterEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FieldFilterEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FieldFilterEdit.stringdata0))
        return static_cast<void*>(this);
    return SyntaxLineEdit::qt_metacast(_clname);
}

int FieldFilterEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SyntaxLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FieldFilterEdit::pushFilterSyntaxStatus(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FieldFilterEdit::popFilterSyntaxStatus()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FieldFilterEdit::pushFilterSyntaxWarning(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
