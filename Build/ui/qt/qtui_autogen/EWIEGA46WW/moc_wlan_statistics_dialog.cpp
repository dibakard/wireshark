/****************************************************************************
** Meta object code from reading C++ file 'wlan_statistics_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/wlan_statistics_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wlan_statistics_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WlanStatisticsDialog_t {
    const uint offsetsAndSize[14];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_WlanStatisticsDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_WlanStatisticsDialog_t qt_meta_stringdata_WlanStatisticsDialog = {
    {
QT_MOC_LITERAL(0, 20), // "WlanStatisticsDialog"
QT_MOC_LITERAL(21, 8), // "fillTree"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 19), // "addStationTreeItems"
QT_MOC_LITERAL(51, 18), // "updateHeaderLabels"
QT_MOC_LITERAL(70, 13), // "filterUpdated"
QT_MOC_LITERAL(84, 6) // "filter"

    },
    "WlanStatisticsDialog\0fillTree\0\0"
    "addStationTreeItems\0updateHeaderLabels\0"
    "filterUpdated\0filter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WlanStatisticsDialog[] = {

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
       1,    0,   38,    2, 0x08,    1 /* Private */,
       3,    0,   39,    2, 0x08,    2 /* Private */,
       4,    0,   40,    2, 0x08,    3 /* Private */,
       5,    1,   41,    2, 0x08,    4 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void WlanStatisticsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WlanStatisticsDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->fillTree(); break;
        case 1: _t->addStationTreeItems(); break;
        case 2: _t->updateHeaderLabels(); break;
        case 3: _t->filterUpdated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject WlanStatisticsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<TapParameterDialog::staticMetaObject>(),
    qt_meta_stringdata_WlanStatisticsDialog.offsetsAndSize,
    qt_meta_data_WlanStatisticsDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_WlanStatisticsDialog_t
, QtPrivate::TypeAndForceComplete<WlanStatisticsDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *WlanStatisticsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WlanStatisticsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WlanStatisticsDialog.stringdata0))
        return static_cast<void*>(this);
    return TapParameterDialog::qt_metacast(_clname);
}

int WlanStatisticsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TapParameterDialog::qt_metacall(_c, _id, _a);
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
