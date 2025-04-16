/****************************************************************************
** Meta object code from reading C++ file 'coloring_rules_delegate.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/models/coloring_rules_delegate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coloring_rules_delegate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ColoringRulesDelegate_t {
    const uint offsetsAndSize[18];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ColoringRulesDelegate_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ColoringRulesDelegate_t qt_meta_stringdata_ColoringRulesDelegate = {
    {
QT_MOC_LITERAL(0, 21), // "ColoringRulesDelegate"
QT_MOC_LITERAL(22, 12), // "invalidField"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 11), // "QModelIndex"
QT_MOC_LITERAL(48, 5), // "index"
QT_MOC_LITERAL(54, 10), // "errMessage"
QT_MOC_LITERAL(65, 10), // "validField"
QT_MOC_LITERAL(76, 15), // "ruleNameChanged"
QT_MOC_LITERAL(92, 4) // "name"

    },
    "ColoringRulesDelegate\0invalidField\0\0"
    "QModelIndex\0index\0errMessage\0validField\0"
    "ruleNameChanged\0name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColoringRulesDelegate[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   32,    2, 0x106,    1 /* Public | MethodIsConst  */,
       6,    1,   37,    2, 0x106,    4 /* Public | MethodIsConst  */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,   40,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void ColoringRulesDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ColoringRulesDelegate *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->invalidField((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->validField((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->ruleNameChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ColoringRulesDelegate::*)(const QModelIndex & , const QString & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColoringRulesDelegate::invalidField)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ColoringRulesDelegate::*)(const QModelIndex & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColoringRulesDelegate::validField)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ColoringRulesDelegate::staticMetaObject = { {
    QMetaObject::SuperData::link<QStyledItemDelegate::staticMetaObject>(),
    qt_meta_stringdata_ColoringRulesDelegate.offsetsAndSize,
    qt_meta_data_ColoringRulesDelegate,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ColoringRulesDelegate_t
, QtPrivate::TypeAndForceComplete<ColoringRulesDelegate, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *ColoringRulesDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColoringRulesDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ColoringRulesDelegate.stringdata0))
        return static_cast<void*>(this);
    return QStyledItemDelegate::qt_metacast(_clname);
}

int ColoringRulesDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ColoringRulesDelegate::invalidField(const QModelIndex & _t1, const QString & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(const_cast< ColoringRulesDelegate *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ColoringRulesDelegate::validField(const QModelIndex & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< ColoringRulesDelegate *>(this), &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
