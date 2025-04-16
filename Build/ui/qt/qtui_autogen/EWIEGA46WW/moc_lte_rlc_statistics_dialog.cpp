/****************************************************************************
** Meta object code from reading C++ file 'lte_rlc_statistics_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/lte_rlc_statistics_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lte_rlc_statistics_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LteRlcStatisticsDialog_t {
    const uint offsetsAndSize[40];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_LteRlcStatisticsDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_LteRlcStatisticsDialog_t qt_meta_stringdata_LteRlcStatisticsDialog = {
    {
QT_MOC_LITERAL(0, 22), // "LteRlcStatisticsDialog"
QT_MOC_LITERAL(23, 14), // "launchRLCGraph"
QT_MOC_LITERAL(38, 0), // ""
QT_MOC_LITERAL(39, 12), // "channelKnown"
QT_MOC_LITERAL(52, 7), // "uint8_t"
QT_MOC_LITERAL(60, 7), // "version"
QT_MOC_LITERAL(68, 8), // "uint16_t"
QT_MOC_LITERAL(77, 4), // "ueid"
QT_MOC_LITERAL(82, 7), // "rlcMode"
QT_MOC_LITERAL(90, 11), // "channelType"
QT_MOC_LITERAL(102, 9), // "channelId"
QT_MOC_LITERAL(112, 9), // "direction"
QT_MOC_LITERAL(122, 8), // "fillTree"
QT_MOC_LITERAL(131, 26), // "updateItemSelectionChanged"
QT_MOC_LITERAL(158, 34), // "useRLCFramesFromMacCheckBoxTo..."
QT_MOC_LITERAL(193, 5), // "state"
QT_MOC_LITERAL(199, 26), // "launchULGraphButtonClicked"
QT_MOC_LITERAL(226, 26), // "launchDLGraphButtonClicked"
QT_MOC_LITERAL(253, 13), // "filterUpdated"
QT_MOC_LITERAL(267, 6) // "filter"

    },
    "LteRlcStatisticsDialog\0launchRLCGraph\0"
    "\0channelKnown\0uint8_t\0version\0uint16_t\0"
    "ueid\0rlcMode\0channelType\0channelId\0"
    "direction\0fillTree\0updateItemSelectionChanged\0"
    "useRLCFramesFromMacCheckBoxToggled\0"
    "state\0launchULGraphButtonClicked\0"
    "launchDLGraphButtonClicked\0filterUpdated\0"
    "filter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LteRlcStatisticsDialog[] = {

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
       1,    7,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,   71,    2, 0x08,    9 /* Private */,
      13,    0,   72,    2, 0x08,   10 /* Private */,
      14,    1,   73,    2, 0x08,   11 /* Private */,
      16,    0,   76,    2, 0x08,   13 /* Private */,
      17,    0,   77,    2, 0x08,   14 /* Private */,
      18,    1,   78,    2, 0x08,   15 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 4,    3,    5,    7,    8,    9,   10,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,

       0        // eod
};

void LteRlcStatisticsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LteRlcStatisticsDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->launchRLCGraph((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[7]))); break;
        case 1: _t->fillTree(); break;
        case 2: _t->updateItemSelectionChanged(); break;
        case 3: _t->useRLCFramesFromMacCheckBoxToggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->launchULGraphButtonClicked(); break;
        case 5: _t->launchDLGraphButtonClicked(); break;
        case 6: _t->filterUpdated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LteRlcStatisticsDialog::*)(bool , uint8_t , uint16_t , uint8_t , uint16_t , uint16_t , uint8_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LteRlcStatisticsDialog::launchRLCGraph)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject LteRlcStatisticsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<TapParameterDialog::staticMetaObject>(),
    qt_meta_stringdata_LteRlcStatisticsDialog.offsetsAndSize,
    qt_meta_data_LteRlcStatisticsDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_LteRlcStatisticsDialog_t
, QtPrivate::TypeAndForceComplete<LteRlcStatisticsDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *LteRlcStatisticsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LteRlcStatisticsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LteRlcStatisticsDialog.stringdata0))
        return static_cast<void*>(this);
    return TapParameterDialog::qt_metacast(_clname);
}

int LteRlcStatisticsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TapParameterDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void LteRlcStatisticsDialog::launchRLCGraph(bool _t1, uint8_t _t2, uint16_t _t3, uint8_t _t4, uint16_t _t5, uint16_t _t6, uint8_t _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
