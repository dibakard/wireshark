/****************************************************************************
** Meta object code from reading C++ file 'traffic_tree.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/traffic_tree.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'traffic_tree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MenuEditAction_t {
    const uint offsetsAndSize[6];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MenuEditAction_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MenuEditAction_t qt_meta_stringdata_MenuEditAction = {
    {
QT_MOC_LITERAL(0, 14), // "MenuEditAction"
QT_MOC_LITERAL(15, 12), // "triggerEntry"
QT_MOC_LITERAL(28, 0) // ""

    },
    "MenuEditAction\0triggerEntry\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuEditAction[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void MenuEditAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MenuEditAction *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->triggerEntry(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject MenuEditAction::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidgetAction::staticMetaObject>(),
    qt_meta_stringdata_MenuEditAction.offsetsAndSize,
    qt_meta_data_MenuEditAction,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MenuEditAction_t
, QtPrivate::TypeAndForceComplete<MenuEditAction, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MenuEditAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuEditAction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MenuEditAction.stringdata0))
        return static_cast<void*>(this);
    return QWidgetAction::qt_metacast(_clname);
}

int MenuEditAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidgetAction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_TrafficTreeHeaderView_t {
    const uint offsetsAndSize[32];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TrafficTreeHeaderView_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TrafficTreeHeaderView_t qt_meta_stringdata_TrafficTreeHeaderView = {
    {
QT_MOC_LITERAL(0, 21), // "TrafficTreeHeaderView"
QT_MOC_LITERAL(22, 18), // "columnsHaveChanged"
QT_MOC_LITERAL(41, 0), // ""
QT_MOC_LITERAL(42, 10), // "QList<int>"
QT_MOC_LITERAL(53, 7), // "visible"
QT_MOC_LITERAL(61, 14), // "filterOnColumn"
QT_MOC_LITERAL(76, 6), // "column"
QT_MOC_LITERAL(83, 8), // "filterOn"
QT_MOC_LITERAL(92, 10), // "filterText"
QT_MOC_LITERAL(103, 17), // "headerContextMenu"
QT_MOC_LITERAL(121, 3), // "pos"
QT_MOC_LITERAL(125, 15), // "columnTriggered"
QT_MOC_LITERAL(141, 7), // "checked"
QT_MOC_LITERAL(149, 19), // "menuActionTriggered"
QT_MOC_LITERAL(169, 8), // "QAction*"
QT_MOC_LITERAL(178, 12) // "filterColumn"

    },
    "TrafficTreeHeaderView\0columnsHaveChanged\0"
    "\0QList<int>\0visible\0filterOnColumn\0"
    "column\0filterOn\0filterText\0headerContextMenu\0"
    "pos\0columnTriggered\0checked\0"
    "menuActionTriggered\0QAction*\0filterColumn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrafficTreeHeaderView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       5,    3,   65,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   72,    2, 0x08,    7 /* Private */,
      11,    1,   75,    2, 0x08,    9 /* Private */,
      11,    0,   78,    2, 0x28,   11 /* Private | MethodCloned */,
      13,    1,   79,    2, 0x08,   12 /* Private */,
      15,    1,   82,    2, 0x08,   14 /* Private */,
      15,    0,   85,    2, 0x28,   16 /* Private | MethodCloned */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    6,    7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,

       0        // eod
};

void TrafficTreeHeaderView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrafficTreeHeaderView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->columnsHaveChanged((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 1: _t->filterOnColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 2: _t->headerContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 3: _t->columnTriggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->columnTriggered(); break;
        case 5: _t->menuActionTriggered((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 6: _t->filterColumn((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->filterColumn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TrafficTreeHeaderView::*)(QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrafficTreeHeaderView::columnsHaveChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TrafficTreeHeaderView::*)(int , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrafficTreeHeaderView::filterOnColumn)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject TrafficTreeHeaderView::staticMetaObject = { {
    QMetaObject::SuperData::link<QHeaderView::staticMetaObject>(),
    qt_meta_stringdata_TrafficTreeHeaderView.offsetsAndSize,
    qt_meta_data_TrafficTreeHeaderView,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TrafficTreeHeaderView_t
, QtPrivate::TypeAndForceComplete<TrafficTreeHeaderView, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAction *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TrafficTreeHeaderView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrafficTreeHeaderView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrafficTreeHeaderView.stringdata0))
        return static_cast<void*>(this);
    return QHeaderView::qt_metacast(_clname);
}

int TrafficTreeHeaderView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QHeaderView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TrafficTreeHeaderView::columnsHaveChanged(QList<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TrafficTreeHeaderView::filterOnColumn(int _t1, int _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_TrafficDataFilterProxy_t {
    const uint offsetsAndSize[12];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TrafficDataFilterProxy_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TrafficDataFilterProxy_t qt_meta_stringdata_TrafficDataFilterProxy = {
    {
QT_MOC_LITERAL(0, 22), // "TrafficDataFilterProxy"
QT_MOC_LITERAL(23, 15), // "filterForColumn"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 6), // "column"
QT_MOC_LITERAL(47, 8), // "filterOn"
QT_MOC_LITERAL(56, 10) // "filterText"

    },
    "TrafficDataFilterProxy\0filterForColumn\0"
    "\0column\0filterOn\0filterText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrafficDataFilterProxy[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   20,    2, 0x0a,    1 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    3,    4,    5,

       0        // eod
};

void TrafficDataFilterProxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrafficDataFilterProxy *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->filterForColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject TrafficDataFilterProxy::staticMetaObject = { {
    QMetaObject::SuperData::link<QSortFilterProxyModel::staticMetaObject>(),
    qt_meta_stringdata_TrafficDataFilterProxy.offsetsAndSize,
    qt_meta_data_TrafficDataFilterProxy,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TrafficDataFilterProxy_t
, QtPrivate::TypeAndForceComplete<TrafficDataFilterProxy, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *TrafficDataFilterProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrafficDataFilterProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrafficDataFilterProxy.stringdata0))
        return static_cast<void*>(this);
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int TrafficDataFilterProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_TrafficTree_t {
    const uint offsetsAndSize[56];
    char stringdata0[404];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TrafficTree_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TrafficTree_t qt_meta_stringdata_TrafficTree = {
    {
QT_MOC_LITERAL(0, 11), // "TrafficTree"
QT_MOC_LITERAL(12, 12), // "filterAction"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 6), // "filter"
QT_MOC_LITERAL(33, 20), // "FilterAction::Action"
QT_MOC_LITERAL(54, 6), // "action"
QT_MOC_LITERAL(61, 24), // "FilterAction::ActionType"
QT_MOC_LITERAL(86, 4), // "type"
QT_MOC_LITERAL(91, 18), // "columnsHaveChanged"
QT_MOC_LITERAL(110, 10), // "QList<int>"
QT_MOC_LITERAL(121, 7), // "columns"
QT_MOC_LITERAL(129, 18), // "tapListenerEnabled"
QT_MOC_LITERAL(148, 6), // "enable"
QT_MOC_LITERAL(155, 10), // "disableTap"
QT_MOC_LITERAL(166, 14), // "columnsChanged"
QT_MOC_LITERAL(181, 17), // "customContextMenu"
QT_MOC_LITERAL(199, 3), // "pos"
QT_MOC_LITERAL(203, 15), // "useFilterAction"
QT_MOC_LITERAL(219, 15), // "clipboardAction"
QT_MOC_LITERAL(235, 12), // "resizeAction"
QT_MOC_LITERAL(248, 19), // "toggleSaveRawAction"
QT_MOC_LITERAL(268, 17), // "handleDataChanged"
QT_MOC_LITERAL(286, 11), // "QModelIndex"
QT_MOC_LITERAL(298, 7), // "topLeft"
QT_MOC_LITERAL(306, 11), // "bottomRight"
QT_MOC_LITERAL(318, 19), // "handleLayoutChanged"
QT_MOC_LITERAL(338, 28), // "QList<QPersistentModelIndex>"
QT_MOC_LITERAL(367, 36) // "QAbstractItemModel::LayoutCha..."

    },
    "TrafficTree\0filterAction\0\0filter\0"
    "FilterAction::Action\0action\0"
    "FilterAction::ActionType\0type\0"
    "columnsHaveChanged\0QList<int>\0columns\0"
    "tapListenerEnabled\0enable\0disableTap\0"
    "columnsChanged\0customContextMenu\0pos\0"
    "useFilterAction\0clipboardAction\0"
    "resizeAction\0toggleSaveRawAction\0"
    "handleDataChanged\0QModelIndex\0topLeft\0"
    "bottomRight\0handleLayoutChanged\0"
    "QList<QPersistentModelIndex>\0"
    "QAbstractItemModel::LayoutChangeHint"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrafficTree[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   86,    2, 0x06,    1 /* Public */,
       8,    1,   93,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    1,   96,    2, 0x0a,    7 /* Public */,
      13,    0,   99,    2, 0x0a,    9 /* Public */,
      14,    1,  100,    2, 0x0a,   10 /* Public */,
      15,    1,  103,    2, 0x08,   12 /* Private */,
      17,    0,  106,    2, 0x08,   14 /* Private */,
      18,    0,  107,    2, 0x08,   15 /* Private */,
      19,    0,  108,    2, 0x08,   16 /* Private */,
      20,    0,  109,    2, 0x08,   17 /* Private */,
      21,    3,  110,    2, 0x08,   18 /* Private */,
      25,    2,  117,    2, 0x08,   22 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 6,    3,    5,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QPoint,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 9,   23,   24,    2,
    QMetaType::Void, 0x80000000 | 26, 0x80000000 | 27,    2,    2,

       0        // eod
};

void TrafficTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrafficTree *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->filterAction((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<FilterAction::Action>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<FilterAction::ActionType>>(_a[3]))); break;
        case 1: _t->columnsHaveChanged((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 2: _t->tapListenerEnabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->disableTap(); break;
        case 4: _t->columnsChanged((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 5: _t->customContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 6: _t->useFilterAction(); break;
        case 7: _t->clipboardAction(); break;
        case 8: _t->resizeAction(); break;
        case 9: _t->toggleSaveRawAction(); break;
        case 10: _t->handleDataChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[3]))); break;
        case 11: _t->handleLayoutChanged((*reinterpret_cast< std::add_pointer_t<QList<QPersistentModelIndex>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAbstractItemModel::LayoutChangeHint>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TrafficTree::*)(QString , FilterAction::Action , FilterAction::ActionType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrafficTree::filterAction)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TrafficTree::*)(QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrafficTree::columnsHaveChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject TrafficTree::staticMetaObject = { {
    QMetaObject::SuperData::link<QTreeView::staticMetaObject>(),
    qt_meta_stringdata_TrafficTree.offsetsAndSize,
    qt_meta_data_TrafficTree,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TrafficTree_t
, QtPrivate::TypeAndForceComplete<TrafficTree, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::Action, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::ActionType, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<const QList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QList<QPersistentModelIndex>, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractItemModel::LayoutChangeHint, std::false_type>


>,
    nullptr
} };


const QMetaObject *TrafficTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrafficTree::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrafficTree.stringdata0))
        return static_cast<void*>(this);
    return QTreeView::qt_metacast(_clname);
}

int TrafficTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void TrafficTree::filterAction(QString _t1, FilterAction::Action _t2, FilterAction::ActionType _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TrafficTree::columnsHaveChanged(QList<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
