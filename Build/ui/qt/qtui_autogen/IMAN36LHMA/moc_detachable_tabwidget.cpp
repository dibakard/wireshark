/****************************************************************************
** Meta object code from reading C++ file 'detachable_tabwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/detachable_tabwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'detachable_tabwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DetachableTabWidget_t {
    const uint offsetsAndSize[24];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DetachableTabWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DetachableTabWidget_t qt_meta_stringdata_DetachableTabWidget = {
    {
QT_MOC_LITERAL(0, 19), // "DetachableTabWidget"
QT_MOC_LITERAL(20, 7), // "moveTab"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 4), // "from"
QT_MOC_LITERAL(34, 2), // "to"
QT_MOC_LITERAL(37, 9), // "detachTab"
QT_MOC_LITERAL(47, 6), // "tabIdx"
QT_MOC_LITERAL(54, 3), // "pos"
QT_MOC_LITERAL(58, 9), // "attachTab"
QT_MOC_LITERAL(68, 8), // "QWidget*"
QT_MOC_LITERAL(77, 7), // "content"
QT_MOC_LITERAL(85, 4) // "name"

    },
    "DetachableTabWidget\0moveTab\0\0from\0to\0"
    "detachTab\0tabIdx\0pos\0attachTab\0QWidget*\0"
    "content\0name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DetachableTabWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   32,    2, 0x09,    1 /* Protected */,
       5,    2,   37,    2, 0x09,    4 /* Protected */,
       8,    2,   42,    2, 0x09,    7 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QPoint,    6,    7,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString,   10,   11,

       0        // eod
};

void DetachableTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DetachableTabWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->moveTab((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->detachTab((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[2]))); break;
        case 2: _t->attachTab((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject DetachableTabWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QTabWidget::staticMetaObject>(),
    qt_meta_stringdata_DetachableTabWidget.offsetsAndSize,
    qt_meta_data_DetachableTabWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DetachableTabWidget_t
, QtPrivate::TypeAndForceComplete<DetachableTabWidget, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *DetachableTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DetachableTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DetachableTabWidget.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int DetachableTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_ToolDialog_t {
    const uint offsetsAndSize[12];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ToolDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ToolDialog_t qt_meta_stringdata_ToolDialog = {
    {
QT_MOC_LITERAL(0, 10), // "ToolDialog"
QT_MOC_LITERAL(11, 13), // "onCloseSignal"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 8), // "QWidget*"
QT_MOC_LITERAL(35, 13), // "contentWidget"
QT_MOC_LITERAL(49, 4) // "name"

    },
    "ToolDialog\0onCloseSignal\0\0QWidget*\0"
    "contentWidget\0name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToolDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,

       0        // eod
};

void ToolDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ToolDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onCloseSignal((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ToolDialog::*)(QWidget * , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ToolDialog::onCloseSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ToolDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ToolDialog.offsetsAndSize,
    qt_meta_data_ToolDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ToolDialog_t
, QtPrivate::TypeAndForceComplete<ToolDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>



>,
    nullptr
} };


const QMetaObject *ToolDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToolDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ToolDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ToolDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ToolDialog::onCloseSignal(QWidget * _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_DragDropTabBar_t {
    const uint offsetsAndSize[16];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DragDropTabBar_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DragDropTabBar_t qt_meta_stringdata_DragDropTabBar = {
    {
QT_MOC_LITERAL(0, 14), // "DragDropTabBar"
QT_MOC_LITERAL(15, 11), // "onDetachTab"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 6), // "tabIdx"
QT_MOC_LITERAL(35, 3), // "pos"
QT_MOC_LITERAL(39, 9), // "onMoveTab"
QT_MOC_LITERAL(49, 6), // "oldIdx"
QT_MOC_LITERAL(56, 6) // "newIdx"

    },
    "DragDropTabBar\0onDetachTab\0\0tabIdx\0"
    "pos\0onMoveTab\0oldIdx\0newIdx"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DragDropTabBar[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,
       5,    2,   31,    2, 0x06,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPoint,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,

       0        // eod
};

void DragDropTabBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DragDropTabBar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onDetachTab((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[2]))); break;
        case 1: _t->onMoveTab((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DragDropTabBar::*)(int , QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DragDropTabBar::onDetachTab)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DragDropTabBar::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DragDropTabBar::onMoveTab)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject DragDropTabBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QTabBar::staticMetaObject>(),
    qt_meta_stringdata_DragDropTabBar.offsetsAndSize,
    qt_meta_data_DragDropTabBar,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DragDropTabBar_t
, QtPrivate::TypeAndForceComplete<DragDropTabBar, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>



>,
    nullptr
} };


const QMetaObject *DragDropTabBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DragDropTabBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DragDropTabBar.stringdata0))
        return static_cast<void*>(this);
    return QTabBar::qt_metacast(_clname);
}

int DragDropTabBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DragDropTabBar::onDetachTab(int _t1, QPoint _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DragDropTabBar::onMoveTab(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
