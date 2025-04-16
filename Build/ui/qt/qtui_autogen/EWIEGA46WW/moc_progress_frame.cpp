/****************************************************************************
** Meta object code from reading C++ file 'progress_frame.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/progress_frame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'progress_frame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProgressFrame_t {
    const uint offsetsAndSize[42];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ProgressFrame_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ProgressFrame_t qt_meta_stringdata_ProgressFrame = {
    {
QT_MOC_LITERAL(0, 13), // "ProgressFrame"
QT_MOC_LITERAL(14, 13), // "showRequested"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 7), // "animate"
QT_MOC_LITERAL(37, 17), // "terminate_is_stop"
QT_MOC_LITERAL(55, 5), // "bool*"
QT_MOC_LITERAL(61, 9), // "stop_flag"
QT_MOC_LITERAL(71, 12), // "valueChanged"
QT_MOC_LITERAL(84, 5), // "value"
QT_MOC_LITERAL(90, 19), // "maximumValueChanged"
QT_MOC_LITERAL(110, 9), // "setHidden"
QT_MOC_LITERAL(120, 11), // "stopLoading"
QT_MOC_LITERAL(132, 12), // "showProgress"
QT_MOC_LITERAL(145, 8), // "progdlg*"
QT_MOC_LITERAL(154, 5), // "title"
QT_MOC_LITERAL(160, 8), // "showBusy"
QT_MOC_LITERAL(169, 8), // "setValue"
QT_MOC_LITERAL(178, 4), // "hide"
QT_MOC_LITERAL(183, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(205, 4), // "show"
QT_MOC_LITERAL(210, 15) // "setMaximumValue"

    },
    "ProgressFrame\0showRequested\0\0animate\0"
    "terminate_is_stop\0bool*\0stop_flag\0"
    "valueChanged\0value\0maximumValueChanged\0"
    "setHidden\0stopLoading\0showProgress\0"
    "progdlg*\0title\0showBusy\0setValue\0hide\0"
    "on_stopButton_clicked\0show\0setMaximumValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProgressFrame[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   92,    2, 0x06,    1 /* Public */,
       7,    1,   99,    2, 0x06,    5 /* Public */,
       9,    1,  102,    2, 0x06,    7 /* Public */,
      10,    0,  105,    2, 0x06,    9 /* Public */,
      11,    0,  106,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    5,  107,    2, 0x0a,   11 /* Public */,
      12,    4,  118,    2, 0x2a,   17 /* Public | MethodCloned */,
      15,    3,  127,    2, 0x0a,   22 /* Public */,
      16,    1,  134,    2, 0x0a,   26 /* Public */,
      17,    0,  137,    2, 0x0a,   28 /* Public */,
      18,    0,  138,    2, 0x08,   29 /* Private */,
      19,    3,  139,    2, 0x08,   30 /* Private */,
      20,    1,  146,    2, 0x08,   34 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, 0x80000000 | 5,    3,    4,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    0x80000000 | 13, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, 0x80000000 | 5, QMetaType::Int,   14,    3,    4,    6,    8,
    0x80000000 | 13, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, 0x80000000 | 5,   14,    3,    4,    6,
    0x80000000 | 13, QMetaType::Bool, QMetaType::Bool, 0x80000000 | 5,    3,    4,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, 0x80000000 | 5,    3,    4,    6,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void ProgressFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProgressFrame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showRequested((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool*>>(_a[3]))); break;
        case 1: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->maximumValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->setHidden(); break;
        case 4: _t->stopLoading(); break;
        case 5: { progdlg* _r = _t->showProgress((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool*>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])));
            if (_a[0]) *reinterpret_cast< progdlg**>(_a[0]) = std::move(_r); }  break;
        case 6: { progdlg* _r = _t->showProgress((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool*>>(_a[4])));
            if (_a[0]) *reinterpret_cast< progdlg**>(_a[0]) = std::move(_r); }  break;
        case 7: { progdlg* _r = _t->showBusy((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool*>>(_a[3])));
            if (_a[0]) *reinterpret_cast< progdlg**>(_a[0]) = std::move(_r); }  break;
        case 8: _t->setValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->hide(); break;
        case 10: _t->on_stopButton_clicked(); break;
        case 11: _t->show((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool*>>(_a[3]))); break;
        case 12: _t->setMaximumValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProgressFrame::*)(bool , bool , bool * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProgressFrame::showRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProgressFrame::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProgressFrame::valueChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ProgressFrame::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProgressFrame::maximumValueChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ProgressFrame::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProgressFrame::setHidden)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ProgressFrame::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProgressFrame::stopLoading)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject ProgressFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_ProgressFrame.offsetsAndSize,
    qt_meta_data_ProgressFrame,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ProgressFrame_t
, QtPrivate::TypeAndForceComplete<ProgressFrame, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<progdlg *, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<progdlg *, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool *, std::false_type>, QtPrivate::TypeAndForceComplete<progdlg *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *ProgressFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProgressFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProgressFrame.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int ProgressFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ProgressFrame::showRequested(bool _t1, bool _t2, bool * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProgressFrame::valueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ProgressFrame::maximumValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ProgressFrame::setHidden()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ProgressFrame::stopLoading()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
