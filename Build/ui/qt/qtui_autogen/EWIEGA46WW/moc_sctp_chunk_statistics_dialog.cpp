/****************************************************************************
** Meta object code from reading C++ file 'sctp_chunk_statistics_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/sctp_chunk_statistics_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sctp_chunk_statistics_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SCTPChunkStatisticsDialog_t {
    const uint offsetsAndSize[24];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SCTPChunkStatisticsDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SCTPChunkStatisticsDialog_t qt_meta_stringdata_SCTPChunkStatisticsDialog = {
    {
QT_MOC_LITERAL(0, 25), // "SCTPChunkStatisticsDialog"
QT_MOC_LITERAL(26, 14), // "setCaptureFile"
QT_MOC_LITERAL(41, 0), // ""
QT_MOC_LITERAL(42, 13), // "capture_file*"
QT_MOC_LITERAL(56, 2), // "cf"
QT_MOC_LITERAL(59, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(81, 32), // "on_actionHideChunkType_triggered"
QT_MOC_LITERAL(114, 39), // "on_actionChunkTypePreferences..."
QT_MOC_LITERAL(154, 16), // "contextMenuEvent"
QT_MOC_LITERAL(171, 18), // "QContextMenuEvent*"
QT_MOC_LITERAL(190, 5), // "event"
QT_MOC_LITERAL(196, 36) // "on_actionShowAllChunkTypes_tr..."

    },
    "SCTPChunkStatisticsDialog\0setCaptureFile\0"
    "\0capture_file*\0cf\0on_pushButton_clicked\0"
    "on_actionHideChunkType_triggered\0"
    "on_actionChunkTypePreferences_triggered\0"
    "contextMenuEvent\0QContextMenuEvent*\0"
    "event\0on_actionShowAllChunkTypes_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SCTPChunkStatisticsDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x0a,    1 /* Public */,
       5,    0,   53,    2, 0x08,    3 /* Private */,
       6,    0,   54,    2, 0x08,    4 /* Private */,
       7,    0,   55,    2, 0x08,    5 /* Private */,
       8,    1,   56,    2, 0x08,    6 /* Private */,
      11,    0,   59,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void SCTPChunkStatisticsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SCTPChunkStatisticsDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setCaptureFile((*reinterpret_cast< std::add_pointer_t<capture_file*>>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_actionHideChunkType_triggered(); break;
        case 3: _t->on_actionChunkTypePreferences_triggered(); break;
        case 4: _t->contextMenuEvent((*reinterpret_cast< std::add_pointer_t<QContextMenuEvent*>>(_a[1]))); break;
        case 5: _t->on_actionShowAllChunkTypes_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject SCTPChunkStatisticsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_SCTPChunkStatisticsDialog.offsetsAndSize,
    qt_meta_data_SCTPChunkStatisticsDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SCTPChunkStatisticsDialog_t
, QtPrivate::TypeAndForceComplete<SCTPChunkStatisticsDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_file *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QContextMenuEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *SCTPChunkStatisticsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SCTPChunkStatisticsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SCTPChunkStatisticsDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SCTPChunkStatisticsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
