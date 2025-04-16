/****************************************************************************
** Meta object code from reading C++ file 'sctp_graph_arwnd_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/sctp_graph_arwnd_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sctp_graph_arwnd_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SCTPGraphArwndDialog_t {
    const uint offsetsAndSize[24];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SCTPGraphArwndDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SCTPGraphArwndDialog_t qt_meta_stringdata_SCTPGraphArwndDialog = {
    {
QT_MOC_LITERAL(0, 20), // "SCTPGraphArwndDialog"
QT_MOC_LITERAL(21, 14), // "setCaptureFile"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 13), // "capture_file*"
QT_MOC_LITERAL(51, 2), // "cf"
QT_MOC_LITERAL(54, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(78, 12), // "graphClicked"
QT_MOC_LITERAL(91, 21), // "QCPAbstractPlottable*"
QT_MOC_LITERAL(113, 9), // "plottable"
QT_MOC_LITERAL(123, 12), // "QMouseEvent*"
QT_MOC_LITERAL(136, 5), // "event"
QT_MOC_LITERAL(142, 21) // "on_saveButton_clicked"

    },
    "SCTPGraphArwndDialog\0setCaptureFile\0"
    "\0capture_file*\0cf\0on_pushButton_4_clicked\0"
    "graphClicked\0QCPAbstractPlottable*\0"
    "plottable\0QMouseEvent*\0event\0"
    "on_saveButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SCTPGraphArwndDialog[] = {

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
       1,    1,   38,    2, 0x0a,    1 /* Public */,
       5,    0,   41,    2, 0x08,    3 /* Private */,
       6,    3,   42,    2, 0x08,    4 /* Private */,
      11,    0,   49,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int, 0x80000000 | 9,    8,    2,   10,
    QMetaType::Void,

       0        // eod
};

void SCTPGraphArwndDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SCTPGraphArwndDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setCaptureFile((*reinterpret_cast< std::add_pointer_t<capture_file*>>(_a[1]))); break;
        case 1: _t->on_pushButton_4_clicked(); break;
        case 2: _t->graphClicked((*reinterpret_cast< std::add_pointer_t<QCPAbstractPlottable*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[3]))); break;
        case 3: _t->on_saveButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject SCTPGraphArwndDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_SCTPGraphArwndDialog.offsetsAndSize,
    qt_meta_data_SCTPGraphArwndDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SCTPGraphArwndDialog_t
, QtPrivate::TypeAndForceComplete<SCTPGraphArwndDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_file *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QCPAbstractPlottable *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *SCTPGraphArwndDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SCTPGraphArwndDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SCTPGraphArwndDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SCTPGraphArwndDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
