/****************************************************************************
** Meta object code from reading C++ file 'capture_comment_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/capture_comment_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'capture_comment_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CaptureCommentDialog_t {
    const uint offsetsAndSize[16];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CaptureCommentDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CaptureCommentDialog_t qt_meta_stringdata_CaptureCommentDialog = {
    {
QT_MOC_LITERAL(0, 20), // "CaptureCommentDialog"
QT_MOC_LITERAL(21, 21), // "captureCommentChanged"
QT_MOC_LITERAL(43, 0), // ""
QT_MOC_LITERAL(44, 10), // "addComment"
QT_MOC_LITERAL(55, 13), // "updateWidgets"
QT_MOC_LITERAL(69, 26), // "on_buttonBox_helpRequested"
QT_MOC_LITERAL(96, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(118, 21) // "on_buttonBox_rejected"

    },
    "CaptureCommentDialog\0captureCommentChanged\0"
    "\0addComment\0updateWidgets\0"
    "on_buttonBox_helpRequested\0"
    "on_buttonBox_accepted\0on_buttonBox_rejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CaptureCommentDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CaptureCommentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CaptureCommentDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->captureCommentChanged(); break;
        case 1: _t->addComment(); break;
        case 2: _t->updateWidgets(); break;
        case 3: _t->on_buttonBox_helpRequested(); break;
        case 4: _t->on_buttonBox_accepted(); break;
        case 5: _t->on_buttonBox_rejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CaptureCommentDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureCommentDialog::captureCommentChanged)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject CaptureCommentDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<WiresharkDialog::staticMetaObject>(),
    qt_meta_stringdata_CaptureCommentDialog.offsetsAndSize,
    qt_meta_data_CaptureCommentDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CaptureCommentDialog_t
, QtPrivate::TypeAndForceComplete<CaptureCommentDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CaptureCommentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CaptureCommentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CaptureCommentDialog.stringdata0))
        return static_cast<void*>(this);
    return WiresharkDialog::qt_metacast(_clname);
}

int CaptureCommentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WiresharkDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void CaptureCommentDialog::captureCommentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
