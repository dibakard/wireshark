/****************************************************************************
** Meta object code from reading C++ file 'main_status_bar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/main_status_bar.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_status_bar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainStatusBar_t {
    const uint offsetsAndSize[60];
    char stringdata0[441];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainStatusBar_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainStatusBar_t qt_meta_stringdata_MainStatusBar = {
    {
QT_MOC_LITERAL(0, 13), // "MainStatusBar"
QT_MOC_LITERAL(14, 14), // "showExpertInfo"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 18), // "editCaptureComment"
QT_MOC_LITERAL(49, 11), // "stopLoading"
QT_MOC_LITERAL(61, 14), // "setCaptureFile"
QT_MOC_LITERAL(76, 13), // "capture_file*"
QT_MOC_LITERAL(90, 2), // "cf"
QT_MOC_LITERAL(93, 20), // "selectedFieldChanged"
QT_MOC_LITERAL(114, 17), // "FieldInformation*"
QT_MOC_LITERAL(132, 23), // "highlightedFieldChanged"
QT_MOC_LITERAL(156, 20), // "selectedFrameChanged"
QT_MOC_LITERAL(177, 10), // "QList<int>"
QT_MOC_LITERAL(188, 23), // "updateCaptureStatistics"
QT_MOC_LITERAL(212, 16), // "capture_session*"
QT_MOC_LITERAL(229, 11), // "cap_session"
QT_MOC_LITERAL(241, 28), // "updateCaptureFixedStatistics"
QT_MOC_LITERAL(270, 19), // "captureEventHandler"
QT_MOC_LITERAL(290, 12), // "CaptureEvent"
QT_MOC_LITERAL(303, 2), // "ev"
QT_MOC_LITERAL(306, 14), // "appInitialized"
QT_MOC_LITERAL(321, 16), // "toggleBackground"
QT_MOC_LITERAL(338, 7), // "enabled"
QT_MOC_LITERAL(346, 14), // "setProfileName"
QT_MOC_LITERAL(361, 15), // "switchToProfile"
QT_MOC_LITERAL(377, 13), // "manageProfile"
QT_MOC_LITERAL(391, 15), // "showProfileMenu"
QT_MOC_LITERAL(407, 10), // "global_pos"
QT_MOC_LITERAL(418, 15), // "Qt::MouseButton"
QT_MOC_LITERAL(434, 6) // "button"

    },
    "MainStatusBar\0showExpertInfo\0\0"
    "editCaptureComment\0stopLoading\0"
    "setCaptureFile\0capture_file*\0cf\0"
    "selectedFieldChanged\0FieldInformation*\0"
    "highlightedFieldChanged\0selectedFrameChanged\0"
    "QList<int>\0updateCaptureStatistics\0"
    "capture_session*\0cap_session\0"
    "updateCaptureFixedStatistics\0"
    "captureEventHandler\0CaptureEvent\0ev\0"
    "appInitialized\0toggleBackground\0enabled\0"
    "setProfileName\0switchToProfile\0"
    "manageProfile\0showProfileMenu\0global_pos\0"
    "Qt::MouseButton\0button"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainStatusBar[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x06,    1 /* Public */,
       3,    0,  111,    2, 0x06,    2 /* Public */,
       4,    0,  112,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,  113,    2, 0x0a,    4 /* Public */,
       8,    1,  116,    2, 0x0a,    6 /* Public */,
      10,    1,  119,    2, 0x0a,    8 /* Public */,
      11,    1,  122,    2, 0x0a,   10 /* Public */,
      13,    1,  125,    2, 0x0a,   12 /* Public */,
      16,    1,  128,    2, 0x0a,   14 /* Public */,
      17,    1,  131,    2, 0x0a,   16 /* Public */,
      20,    0,  134,    2, 0x08,   18 /* Private */,
      21,    1,  135,    2, 0x08,   19 /* Private */,
      23,    0,  138,    2, 0x08,   21 /* Private */,
      24,    0,  139,    2, 0x08,   22 /* Private */,
      25,    0,  140,    2, 0x08,   23 /* Private */,
      26,    2,  141,    2, 0x08,   24 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, 0x80000000 | 28,   27,   29,

       0        // eod
};

void MainStatusBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainStatusBar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showExpertInfo(); break;
        case 1: _t->editCaptureComment(); break;
        case 2: _t->stopLoading(); break;
        case 3: _t->setCaptureFile((*reinterpret_cast< std::add_pointer_t<capture_file*>>(_a[1]))); break;
        case 4: _t->selectedFieldChanged((*reinterpret_cast< std::add_pointer_t<FieldInformation*>>(_a[1]))); break;
        case 5: _t->highlightedFieldChanged((*reinterpret_cast< std::add_pointer_t<FieldInformation*>>(_a[1]))); break;
        case 6: _t->selectedFrameChanged((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 7: _t->updateCaptureStatistics((*reinterpret_cast< std::add_pointer_t<capture_session*>>(_a[1]))); break;
        case 8: _t->updateCaptureFixedStatistics((*reinterpret_cast< std::add_pointer_t<capture_session*>>(_a[1]))); break;
        case 9: _t->captureEventHandler((*reinterpret_cast< std::add_pointer_t<CaptureEvent>>(_a[1]))); break;
        case 10: _t->appInitialized(); break;
        case 11: _t->toggleBackground((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->setProfileName(); break;
        case 13: _t->switchToProfile(); break;
        case 14: _t->manageProfile(); break;
        case 15: _t->showProfileMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FieldInformation* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FieldInformation* >(); break;
            }
            break;
        case 6:
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
            using _t = void (MainStatusBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainStatusBar::showExpertInfo)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainStatusBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainStatusBar::editCaptureComment)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainStatusBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainStatusBar::stopLoading)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MainStatusBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QStatusBar::staticMetaObject>(),
    qt_meta_stringdata_MainStatusBar.offsetsAndSize,
    qt_meta_data_MainStatusBar,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainStatusBar_t
, QtPrivate::TypeAndForceComplete<MainStatusBar, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_file *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<FieldInformation *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<FieldInformation *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_session *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_session *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<CaptureEvent, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<Qt::MouseButton, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainStatusBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainStatusBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainStatusBar.stringdata0))
        return static_cast<void*>(this);
    return QStatusBar::qt_metacast(_clname);
}

int MainStatusBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStatusBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainStatusBar::showExpertInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainStatusBar::editCaptureComment()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainStatusBar::stopLoading()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
