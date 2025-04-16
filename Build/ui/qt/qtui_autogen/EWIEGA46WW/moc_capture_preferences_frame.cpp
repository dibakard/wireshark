/****************************************************************************
** Meta object code from reading C++ file 'capture_preferences_frame.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/capture_preferences_frame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'capture_preferences_frame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CapturePreferencesFrame_t {
    const uint offsetsAndSize[26];
    char stringdata0[350];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CapturePreferencesFrame_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CapturePreferencesFrame_t qt_meta_stringdata_CapturePreferencesFrame = {
    {
QT_MOC_LITERAL(0, 23), // "CapturePreferencesFrame"
QT_MOC_LITERAL(24, 43), // "on_defaultInterfaceComboBox_e..."
QT_MOC_LITERAL(68, 0), // ""
QT_MOC_LITERAL(69, 9), // "new_iface"
QT_MOC_LITERAL(79, 34), // "on_capturePromModeCheckBox_to..."
QT_MOC_LITERAL(114, 7), // "checked"
QT_MOC_LITERAL(122, 37), // "on_captureMonitorModeCheckBox..."
QT_MOC_LITERAL(160, 32), // "on_capturePcapNgCheckBox_toggled"
QT_MOC_LITERAL(193, 34), // "on_captureRealTimeCheckBox_to..."
QT_MOC_LITERAL(228, 44), // "on_captureUpdateIntervalLineE..."
QT_MOC_LITERAL(273, 7), // "new_str"
QT_MOC_LITERAL(281, 33), // "on_captureNoInterfaceLoad_tog..."
QT_MOC_LITERAL(315, 34) // "on_captureNoExtcapCheckBox_to..."

    },
    "CapturePreferencesFrame\0"
    "on_defaultInterfaceComboBox_editTextChanged\0"
    "\0new_iface\0on_capturePromModeCheckBox_toggled\0"
    "checked\0on_captureMonitorModeCheckBox_toggled\0"
    "on_capturePcapNgCheckBox_toggled\0"
    "on_captureRealTimeCheckBox_toggled\0"
    "on_captureUpdateIntervalLineEdit_textChanged\0"
    "new_str\0on_captureNoInterfaceLoad_toggled\0"
    "on_captureNoExtcapCheckBox_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CapturePreferencesFrame[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x08,    1 /* Private */,
       4,    1,   65,    2, 0x08,    3 /* Private */,
       6,    1,   68,    2, 0x08,    5 /* Private */,
       7,    1,   71,    2, 0x08,    7 /* Private */,
       8,    1,   74,    2, 0x08,    9 /* Private */,
       9,    1,   77,    2, 0x08,   11 /* Private */,
      11,    1,   80,    2, 0x08,   13 /* Private */,
      12,    1,   83,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,

       0        // eod
};

void CapturePreferencesFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CapturePreferencesFrame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_defaultInterfaceComboBox_editTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->on_capturePromModeCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->on_captureMonitorModeCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->on_capturePcapNgCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->on_captureRealTimeCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->on_captureUpdateIntervalLineEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->on_captureNoInterfaceLoad_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->on_captureNoExtcapCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CapturePreferencesFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_CapturePreferencesFrame.offsetsAndSize,
    qt_meta_data_CapturePreferencesFrame,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CapturePreferencesFrame_t
, QtPrivate::TypeAndForceComplete<CapturePreferencesFrame, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *CapturePreferencesFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CapturePreferencesFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CapturePreferencesFrame.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int CapturePreferencesFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
