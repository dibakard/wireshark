/****************************************************************************
** Meta object code from reading C++ file 'resolved_addresses_view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/resolved_addresses_view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resolved_addresses_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ResolvedAddressesView_t {
    const uint offsetsAndSize[20];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ResolvedAddressesView_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ResolvedAddressesView_t qt_meta_stringdata_ResolvedAddressesView = {
    {
QT_MOC_LITERAL(0, 21), // "ResolvedAddressesView"
QT_MOC_LITERAL(22, 6), // "saveAs"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 15), // "clipboardAction"
QT_MOC_LITERAL(46, 12), // "toTextStream"
QT_MOC_LITERAL(59, 12), // "QTextStream&"
QT_MOC_LITERAL(72, 6), // "stream"
QT_MOC_LITERAL(79, 24), // "eResolvedAddressesExport"
QT_MOC_LITERAL(104, 6), // "format"
QT_MOC_LITERAL(111, 8) // "selected"

    },
    "ResolvedAddressesView\0saveAs\0\0"
    "clipboardAction\0toTextStream\0QTextStream&\0"
    "stream\0eResolvedAddressesExport\0format\0"
    "selected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResolvedAddressesView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x0a,    1 /* Public */,
       3,    0,   39,    2, 0x08,    2 /* Private */,
       4,    3,   40,    2, 0x108,    3 /* Private | MethodIsConst  */,
       4,    2,   47,    2, 0x128,    7 /* Private | MethodCloned | MethodIsConst  */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7, QMetaType::Bool,    6,    8,    9,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,

       0        // eod
};

void ResolvedAddressesView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ResolvedAddressesView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->saveAs(); break;
        case 1: _t->clipboardAction(); break;
        case 2: _t->toTextStream((*reinterpret_cast< std::add_pointer_t<QTextStream&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<eResolvedAddressesExport>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 3: _t->toTextStream((*reinterpret_cast< std::add_pointer_t<QTextStream&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<eResolvedAddressesExport>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject ResolvedAddressesView::staticMetaObject = { {
    QMetaObject::SuperData::link<QTableView::staticMetaObject>(),
    qt_meta_stringdata_ResolvedAddressesView.offsetsAndSize,
    qt_meta_data_ResolvedAddressesView,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ResolvedAddressesView_t
, QtPrivate::TypeAndForceComplete<ResolvedAddressesView, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTextStream &, std::false_type>, QtPrivate::TypeAndForceComplete<eResolvedAddressesExport, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTextStream &, std::false_type>, QtPrivate::TypeAndForceComplete<eResolvedAddressesExport, std::false_type>


>,
    nullptr
} };


const QMetaObject *ResolvedAddressesView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResolvedAddressesView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ResolvedAddressesView.stringdata0))
        return static_cast<void*>(this);
    return QTableView::qt_metacast(_clname);
}

int ResolvedAddressesView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableView::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
