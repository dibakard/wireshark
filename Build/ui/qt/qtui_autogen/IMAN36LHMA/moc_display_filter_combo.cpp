/****************************************************************************
** Meta object code from reading C++ file 'display_filter_combo.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/display_filter_combo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'display_filter_combo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DisplayFilterCombo_t {
    const uint offsetsAndSize[18];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DisplayFilterCombo_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DisplayFilterCombo_t qt_meta_stringdata_DisplayFilterCombo = {
    {
QT_MOC_LITERAL(0, 18), // "DisplayFilterCombo"
QT_MOC_LITERAL(19, 18), // "checkDisplayFilter"
QT_MOC_LITERAL(38, 0), // ""
QT_MOC_LITERAL(39, 18), // "applyDisplayFilter"
QT_MOC_LITERAL(58, 16), // "setDisplayFilter"
QT_MOC_LITERAL(75, 6), // "filter"
QT_MOC_LITERAL(82, 14), // "updateMaxCount"
QT_MOC_LITERAL(97, 13), // "filterApplied"
QT_MOC_LITERAL(111, 5) // "force"

    },
    "DisplayFilterCombo\0checkDisplayFilter\0"
    "\0applyDisplayFilter\0setDisplayFilter\0"
    "filter\0updateMaxCount\0filterApplied\0"
    "force"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DisplayFilterCombo[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x0a,    1 /* Public */,
       3,    0,   45,    2, 0x0a,    2 /* Public */,
       4,    1,   46,    2, 0x0a,    3 /* Public */,
       6,    0,   49,    2, 0x08,    5 /* Private */,
       7,    2,   50,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    5,    8,

       0        // eod
};

void DisplayFilterCombo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DisplayFilterCombo *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->checkDisplayFilter();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->applyDisplayFilter(); break;
        case 2: _t->setDisplayFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->updateMaxCount(); break;
        case 4: _t->filterApplied((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject DisplayFilterCombo::staticMetaObject = { {
    QMetaObject::SuperData::link<QComboBox::staticMetaObject>(),
    qt_meta_stringdata_DisplayFilterCombo.offsetsAndSize,
    qt_meta_data_DisplayFilterCombo,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DisplayFilterCombo_t
, QtPrivate::TypeAndForceComplete<DisplayFilterCombo, std::true_type>
, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *DisplayFilterCombo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DisplayFilterCombo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DisplayFilterCombo.stringdata0))
        return static_cast<void*>(this);
    return QComboBox::qt_metacast(_clname);
}

int DisplayFilterCombo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
