/****************************************************************************
** Meta object code from reading C++ file 'profile_tree_view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/profile_tree_view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profile_tree_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProfileTreeEditDelegate_t {
    const uint offsetsAndSize[2];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ProfileTreeEditDelegate_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ProfileTreeEditDelegate_t qt_meta_stringdata_ProfileTreeEditDelegate = {
    {
QT_MOC_LITERAL(0, 23) // "ProfileTreeEditDelegate"

    },
    "ProfileTreeEditDelegate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProfileTreeEditDelegate[] = {

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

void ProfileTreeEditDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject ProfileTreeEditDelegate::staticMetaObject = { {
    QMetaObject::SuperData::link<QItemDelegate::staticMetaObject>(),
    qt_meta_stringdata_ProfileTreeEditDelegate.offsetsAndSize,
    qt_meta_data_ProfileTreeEditDelegate,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ProfileTreeEditDelegate_t
, QtPrivate::TypeAndForceComplete<ProfileTreeEditDelegate, std::true_type>



>,
    nullptr
} };


const QMetaObject *ProfileTreeEditDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProfileTreeEditDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProfileTreeEditDelegate.stringdata0))
        return static_cast<void*>(this);
    return QItemDelegate::qt_metacast(_clname);
}

int ProfileTreeEditDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QItemDelegate::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ProfileTreeView_t {
    const uint offsetsAndSize[14];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ProfileTreeView_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ProfileTreeView_t qt_meta_stringdata_ProfileTreeView = {
    {
QT_MOC_LITERAL(0, 15), // "ProfileTreeView"
QT_MOC_LITERAL(16, 11), // "itemUpdated"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 16), // "selectionChanged"
QT_MOC_LITERAL(46, 14), // "QItemSelection"
QT_MOC_LITERAL(61, 8), // "selected"
QT_MOC_LITERAL(70, 10) // "deselected"

    },
    "ProfileTreeView\0itemUpdated\0\0"
    "selectionChanged\0QItemSelection\0"
    "selected\0deselected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProfileTreeView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    2,   27,    2, 0x09,    2 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,

       0        // eod
};

void ProfileTreeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProfileTreeView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->itemUpdated(); break;
        case 1: _t->selectionChanged((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QItemSelection >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProfileTreeView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProfileTreeView::itemUpdated)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ProfileTreeView::staticMetaObject = { {
    QMetaObject::SuperData::link<QTreeView::staticMetaObject>(),
    qt_meta_stringdata_ProfileTreeView.offsetsAndSize,
    qt_meta_data_ProfileTreeView,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ProfileTreeView_t
, QtPrivate::TypeAndForceComplete<ProfileTreeView, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>, QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>


>,
    nullptr
} };


const QMetaObject *ProfileTreeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProfileTreeView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProfileTreeView.stringdata0))
        return static_cast<void*>(this);
    return QTreeView::qt_metacast(_clname);
}

int ProfileTreeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ProfileTreeView::itemUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
