/****************************************************************************
** Meta object code from reading C++ file 'packet_diagram.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/packet_diagram.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'packet_diagram.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PacketDiagram_t {
    const uint offsetsAndSize[32];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PacketDiagram_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PacketDiagram_t qt_meta_stringdata_PacketDiagram = {
    {
QT_MOC_LITERAL(0, 13), // "PacketDiagram"
QT_MOC_LITERAL(14, 13), // "fieldSelected"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 17), // "FieldInformation*"
QT_MOC_LITERAL(47, 14), // "setCaptureFile"
QT_MOC_LITERAL(62, 13), // "capture_file*"
QT_MOC_LITERAL(76, 2), // "cf"
QT_MOC_LITERAL(79, 7), // "setFont"
QT_MOC_LITERAL(87, 4), // "font"
QT_MOC_LITERAL(92, 20), // "selectedFieldChanged"
QT_MOC_LITERAL(113, 5), // "finfo"
QT_MOC_LITERAL(119, 20), // "selectedFrameChanged"
QT_MOC_LITERAL(140, 10), // "QList<int>"
QT_MOC_LITERAL(151, 6), // "frames"
QT_MOC_LITERAL(158, 19), // "connectToMainWindow"
QT_MOC_LITERAL(178, 21) // "sceneSelectionChanged"

    },
    "PacketDiagram\0fieldSelected\0\0"
    "FieldInformation*\0setCaptureFile\0"
    "capture_file*\0cf\0setFont\0font\0"
    "selectedFieldChanged\0finfo\0"
    "selectedFrameChanged\0QList<int>\0frames\0"
    "connectToMainWindow\0sceneSelectionChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PacketDiagram[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   59,    2, 0x0a,    3 /* Public */,
       7,    1,   62,    2, 0x0a,    5 /* Public */,
       9,    1,   65,    2, 0x0a,    7 /* Public */,
      11,    1,   68,    2, 0x0a,    9 /* Public */,
      14,    0,   71,    2, 0x08,   11 /* Private */,
      15,    0,   72,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QFont,    8,
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PacketDiagram::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PacketDiagram *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->fieldSelected((*reinterpret_cast< std::add_pointer_t<FieldInformation*>>(_a[1]))); break;
        case 1: _t->setCaptureFile((*reinterpret_cast< std::add_pointer_t<capture_file*>>(_a[1]))); break;
        case 2: _t->setFont((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        case 3: _t->selectedFieldChanged((*reinterpret_cast< std::add_pointer_t<FieldInformation*>>(_a[1]))); break;
        case 4: _t->selectedFrameChanged((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 5: _t->connectToMainWindow(); break;
        case 6: _t->sceneSelectionChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FieldInformation* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FieldInformation* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PacketDiagram::*)(FieldInformation * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketDiagram::fieldSelected)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PacketDiagram::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_PacketDiagram.offsetsAndSize,
    qt_meta_data_PacketDiagram,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PacketDiagram_t
, QtPrivate::TypeAndForceComplete<PacketDiagram, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<FieldInformation *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_file *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QFont &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<FieldInformation *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *PacketDiagram::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PacketDiagram::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PacketDiagram.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int PacketDiagram::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void PacketDiagram::fieldSelected(FieldInformation * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
