/****************************************************************************
** Meta object code from reading C++ file 'compiled_filter_output.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/compiled_filter_output.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'compiled_filter_output.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CompiledFilterOutput_t {
    const uint offsetsAndSize[14];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CompiledFilterOutput_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CompiledFilterOutput_t qt_meta_stringdata_CompiledFilterOutput = {
    {
QT_MOC_LITERAL(0, 20), // "CompiledFilterOutput"
QT_MOC_LITERAL(21, 35), // "on_interfaceList_currentItemC..."
QT_MOC_LITERAL(57, 0), // ""
QT_MOC_LITERAL(58, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(75, 7), // "current"
QT_MOC_LITERAL(83, 8), // "previous"
QT_MOC_LITERAL(92, 14) // "copyFilterText"

    },
    "CompiledFilterOutput\0"
    "on_interfaceList_currentItemChanged\0"
    "\0QListWidgetItem*\0current\0previous\0"
    "copyFilterText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CompiledFilterOutput[] = {

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
       1,    2,   26,    2, 0x08,    1 /* Private */,
       6,    0,   31,    2, 0x08,    4 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void,

       0        // eod
};

void CompiledFilterOutput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CompiledFilterOutput *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_interfaceList_currentItemChanged((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[2]))); break;
        case 1: _t->copyFilterText(); break;
        default: ;
        }
    }
}

const QMetaObject CompiledFilterOutput::staticMetaObject = { {
    QMetaObject::SuperData::link<GeometryStateDialog::staticMetaObject>(),
    qt_meta_stringdata_CompiledFilterOutput.offsetsAndSize,
    qt_meta_data_CompiledFilterOutput,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CompiledFilterOutput_t
, QtPrivate::TypeAndForceComplete<CompiledFilterOutput, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CompiledFilterOutput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CompiledFilterOutput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CompiledFilterOutput.stringdata0))
        return static_cast<void*>(this);
    return GeometryStateDialog::qt_metacast(_clname);
}

int CompiledFilterOutput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeometryStateDialog::qt_metacall(_c, _id, _a);
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
