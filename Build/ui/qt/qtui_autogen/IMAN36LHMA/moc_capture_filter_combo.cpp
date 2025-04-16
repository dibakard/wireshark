/****************************************************************************
** Meta object code from reading C++ file 'capture_filter_combo.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/capture_filter_combo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'capture_filter_combo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CaptureFilterCombo_t {
    const uint offsetsAndSize[16];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CaptureFilterCombo_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CaptureFilterCombo_t qt_meta_stringdata_CaptureFilterCombo = {
    {
QT_MOC_LITERAL(0, 18), // "CaptureFilterCombo"
QT_MOC_LITERAL(19, 17), // "interfacesChanged"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 26), // "captureFilterSyntaxChanged"
QT_MOC_LITERAL(65, 5), // "valid"
QT_MOC_LITERAL(71, 12), // "startCapture"
QT_MOC_LITERAL(84, 24), // "saveAndRebuildFilterList"
QT_MOC_LITERAL(109, 17) // "rebuildFilterList"

    },
    "CaptureFilterCombo\0interfacesChanged\0"
    "\0captureFilterSyntaxChanged\0valid\0"
    "startCapture\0saveAndRebuildFilterList\0"
    "rebuildFilterList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CaptureFilterCombo[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    1,   45,    2, 0x06,    2 /* Public */,
       5,    0,   48,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   49,    2, 0x08,    5 /* Private */,
       7,    0,   50,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CaptureFilterCombo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CaptureFilterCombo *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->interfacesChanged(); break;
        case 1: _t->captureFilterSyntaxChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->startCapture(); break;
        case 3: _t->saveAndRebuildFilterList(); break;
        case 4: _t->rebuildFilterList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CaptureFilterCombo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureFilterCombo::interfacesChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CaptureFilterCombo::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureFilterCombo::captureFilterSyntaxChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CaptureFilterCombo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureFilterCombo::startCapture)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject CaptureFilterCombo::staticMetaObject = { {
    QMetaObject::SuperData::link<QComboBox::staticMetaObject>(),
    qt_meta_stringdata_CaptureFilterCombo.offsetsAndSize,
    qt_meta_data_CaptureFilterCombo,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CaptureFilterCombo_t
, QtPrivate::TypeAndForceComplete<CaptureFilterCombo, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CaptureFilterCombo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CaptureFilterCombo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CaptureFilterCombo.stringdata0))
        return static_cast<void*>(this);
    return QComboBox::qt_metacast(_clname);
}

int CaptureFilterCombo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CaptureFilterCombo::interfacesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CaptureFilterCombo::captureFilterSyntaxChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CaptureFilterCombo::startCapture()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
