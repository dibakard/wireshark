/****************************************************************************
** Meta object code from reading C++ file 'wireless_frame.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/wireless_frame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wireless_frame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WirelessFrame_t {
    const uint offsetsAndSize[32];
    char stringdata0[292];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_WirelessFrame_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_WirelessFrame_t qt_meta_stringdata_WirelessFrame = {
    {
QT_MOC_LITERAL(0, 13), // "WirelessFrame"
QT_MOC_LITERAL(14, 23), // "showWirelessPreferences"
QT_MOC_LITERAL(38, 0), // ""
QT_MOC_LITERAL(39, 16), // "wlan_module_name"
QT_MOC_LITERAL(56, 20), // "handleInterfaceEvent"
QT_MOC_LITERAL(77, 11), // "const char*"
QT_MOC_LITERAL(89, 6), // "ifname"
QT_MOC_LITERAL(96, 5), // "added"
QT_MOC_LITERAL(102, 2), // "up"
QT_MOC_LITERAL(105, 13), // "updateWidgets"
QT_MOC_LITERAL(119, 27), // "on_helperToolButton_clicked"
QT_MOC_LITERAL(147, 26), // "on_prefsToolButton_clicked"
QT_MOC_LITERAL(174, 30), // "on_interfaceComboBox_activated"
QT_MOC_LITERAL(205, 28), // "on_channelComboBox_activated"
QT_MOC_LITERAL(234, 32), // "on_channelTypeComboBox_activated"
QT_MOC_LITERAL(267, 24) // "on_fcsComboBox_activated"

    },
    "WirelessFrame\0showWirelessPreferences\0"
    "\0wlan_module_name\0handleInterfaceEvent\0"
    "const char*\0ifname\0added\0up\0updateWidgets\0"
    "on_helperToolButton_clicked\0"
    "on_prefsToolButton_clicked\0"
    "on_interfaceComboBox_activated\0"
    "on_channelComboBox_activated\0"
    "on_channelTypeComboBox_activated\0"
    "on_fcsComboBox_activated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WirelessFrame[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    3,   71,    2, 0x0a,    3 /* Public */,
       9,    0,   78,    2, 0x08,    7 /* Private */,
      10,    0,   79,    2, 0x08,    8 /* Private */,
      11,    0,   80,    2, 0x08,    9 /* Private */,
      12,    1,   81,    2, 0x08,   10 /* Private */,
      13,    1,   84,    2, 0x08,   12 /* Private */,
      14,    1,   87,    2, 0x08,   14 /* Private */,
      15,    1,   90,    2, 0x08,   16 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int, QMetaType::Int,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void WirelessFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WirelessFrame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showWirelessPreferences((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->handleInterfaceEvent((*reinterpret_cast< std::add_pointer_t<const char*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 2: _t->updateWidgets(); break;
        case 3: _t->on_helperToolButton_clicked(); break;
        case 4: _t->on_prefsToolButton_clicked(); break;
        case 5: _t->on_interfaceComboBox_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_channelComboBox_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->on_channelTypeComboBox_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_fcsComboBox_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WirelessFrame::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WirelessFrame::showWirelessPreferences)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject WirelessFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_WirelessFrame.offsetsAndSize,
    qt_meta_data_WirelessFrame,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_WirelessFrame_t
, QtPrivate::TypeAndForceComplete<WirelessFrame, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const char *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *WirelessFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WirelessFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WirelessFrame.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int WirelessFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void WirelessFrame::showWirelessPreferences(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
