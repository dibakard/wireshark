/****************************************************************************
** Meta object code from reading C++ file 'expert_info_view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/expert_info_view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'expert_info_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ExpertInfoTreeView_t {
    const uint offsetsAndSize[18];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ExpertInfoTreeView_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ExpertInfoTreeView_t qt_meta_stringdata_ExpertInfoTreeView = {
    {
QT_MOC_LITERAL(0, 18), // "ExpertInfoTreeView"
QT_MOC_LITERAL(19, 10), // "goToPacket"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 10), // "packet_num"
QT_MOC_LITERAL(42, 5), // "hf_id"
QT_MOC_LITERAL(48, 14), // "currentChanged"
QT_MOC_LITERAL(63, 11), // "QModelIndex"
QT_MOC_LITERAL(75, 7), // "current"
QT_MOC_LITERAL(83, 8) // "previous"

    },
    "ExpertInfoTreeView\0goToPacket\0\0"
    "packet_num\0hf_id\0currentChanged\0"
    "QModelIndex\0current\0previous"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExpertInfoTreeView[] = {

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
       1,    2,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    2,   31,    2, 0x09,    4 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,

       0        // eod
};

void ExpertInfoTreeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExpertInfoTreeView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->goToPacket((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->currentChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ExpertInfoTreeView::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExpertInfoTreeView::goToPacket)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ExpertInfoTreeView::staticMetaObject = { {
    QMetaObject::SuperData::link<QTreeView::staticMetaObject>(),
    qt_meta_stringdata_ExpertInfoTreeView.offsetsAndSize,
    qt_meta_data_ExpertInfoTreeView,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ExpertInfoTreeView_t
, QtPrivate::TypeAndForceComplete<ExpertInfoTreeView, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>


>,
    nullptr
} };


const QMetaObject *ExpertInfoTreeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExpertInfoTreeView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExpertInfoTreeView.stringdata0))
        return static_cast<void*>(this);
    return QTreeView::qt_metacast(_clname);
}

int ExpertInfoTreeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ExpertInfoTreeView::goToPacket(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
