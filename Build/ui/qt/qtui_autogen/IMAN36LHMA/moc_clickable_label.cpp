/****************************************************************************
** Meta object code from reading C++ file 'clickable_label.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/clickable_label.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clickable_label.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClickableLabel_t {
    const uint offsetsAndSize[14];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ClickableLabel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ClickableLabel_t qt_meta_stringdata_ClickableLabel = {
    {
QT_MOC_LITERAL(0, 14), // "ClickableLabel"
QT_MOC_LITERAL(15, 7), // "clicked"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 9), // "clickedAt"
QT_MOC_LITERAL(34, 10), // "global_pos"
QT_MOC_LITERAL(45, 15), // "Qt::MouseButton"
QT_MOC_LITERAL(61, 6) // "button"

    },
    "ClickableLabel\0clicked\0\0clickedAt\0"
    "global_pos\0Qt::MouseButton\0button"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClickableLabel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    1 /* Public */,
       3,    2,   27,    2, 0x06,    2 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, 0x80000000 | 5,    4,    6,

       0        // eod
};

void ClickableLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClickableLabel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clicked(); break;
        case 1: _t->clickedAt((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClickableLabel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClickableLabel::clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClickableLabel::*)(const QPoint & , Qt::MouseButton );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClickableLabel::clickedAt)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ClickableLabel::staticMetaObject = { {
    QMetaObject::SuperData::link<QLabel::staticMetaObject>(),
    qt_meta_stringdata_ClickableLabel.offsetsAndSize,
    qt_meta_data_ClickableLabel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ClickableLabel_t
, QtPrivate::TypeAndForceComplete<ClickableLabel, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<Qt::MouseButton, std::false_type>



>,
    nullptr
} };


const QMetaObject *ClickableLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClickableLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClickableLabel.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int ClickableLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ClickableLabel::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ClickableLabel::clickedAt(const QPoint & _t1, Qt::MouseButton _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
