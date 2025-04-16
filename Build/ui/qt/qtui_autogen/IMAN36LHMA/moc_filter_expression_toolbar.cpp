/****************************************************************************
** Meta object code from reading C++ file 'filter_expression_toolbar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/filter_expression_toolbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filter_expression_toolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilterExpressionToolBar_t {
    const uint offsetsAndSize[46];
    char stringdata0[291];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FilterExpressionToolBar_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FilterExpressionToolBar_t qt_meta_stringdata_FilterExpressionToolBar = {
    {
QT_MOC_LITERAL(0, 23), // "FilterExpressionToolBar"
QT_MOC_LITERAL(24, 14), // "filterSelected"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 17), // "filterPreferences"
QT_MOC_LITERAL(58, 10), // "filterEdit"
QT_MOC_LITERAL(69, 8), // "uatIndex"
QT_MOC_LITERAL(78, 24), // "filterExpressionsChanged"
QT_MOC_LITERAL(103, 19), // "onCustomMenuHandler"
QT_MOC_LITERAL(123, 3), // "pos"
QT_MOC_LITERAL(127, 13), // "onActionMoved"
QT_MOC_LITERAL(141, 8), // "QAction*"
QT_MOC_LITERAL(150, 6), // "action"
QT_MOC_LITERAL(157, 6), // "oldPos"
QT_MOC_LITERAL(164, 6), // "newPos"
QT_MOC_LITERAL(171, 15), // "onFilterDropped"
QT_MOC_LITERAL(187, 11), // "description"
QT_MOC_LITERAL(199, 6), // "filter"
QT_MOC_LITERAL(206, 12), // "removeFilter"
QT_MOC_LITERAL(219, 13), // "disableFilter"
QT_MOC_LITERAL(233, 10), // "editFilter"
QT_MOC_LITERAL(244, 13), // "filterClicked"
QT_MOC_LITERAL(258, 22), // "toolBarShowPreferences"
QT_MOC_LITERAL(281, 9) // "closeMenu"

    },
    "FilterExpressionToolBar\0filterSelected\0"
    "\0filterPreferences\0filterEdit\0uatIndex\0"
    "filterExpressionsChanged\0onCustomMenuHandler\0"
    "pos\0onActionMoved\0QAction*\0action\0"
    "oldPos\0newPos\0onFilterDropped\0description\0"
    "filter\0removeFilter\0disableFilter\0"
    "editFilter\0filterClicked\0"
    "toolBarShowPreferences\0closeMenu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterExpressionToolBar[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   92,    2, 0x06,    1 /* Public */,
       3,    0,   97,    2, 0x06,    4 /* Public */,
       4,    1,   98,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,  101,    2, 0x0a,    7 /* Public */,
       7,    1,  102,    2, 0x09,    8 /* Protected */,
       9,    3,  105,    2, 0x09,   10 /* Protected */,
      14,    2,  112,    2, 0x09,   14 /* Protected */,
      17,    0,  117,    2, 0x08,   17 /* Private */,
      18,    0,  118,    2, 0x08,   18 /* Private */,
      19,    0,  119,    2, 0x08,   19 /* Private */,
      20,    0,  120,    2, 0x08,   20 /* Private */,
      21,    0,  121,    2, 0x08,   21 /* Private */,
      22,    1,  122,    2, 0x08,   22 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    8,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int, QMetaType::Int,   11,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    2,

       0        // eod
};

void FilterExpressionToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FilterExpressionToolBar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->filterSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 1: _t->filterPreferences(); break;
        case 2: _t->filterEdit((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->filterExpressionsChanged(); break;
        case 4: _t->onCustomMenuHandler((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 5: _t->onActionMoved((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 6: _t->onFilterDropped((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 7: _t->removeFilter(); break;
        case 8: _t->disableFilter(); break;
        case 9: _t->editFilter(); break;
        case 10: _t->filterClicked(); break;
        case 11: _t->toolBarShowPreferences(); break;
        case 12: _t->closeMenu((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        case 12:
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
            using _t = void (FilterExpressionToolBar::*)(QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterExpressionToolBar::filterSelected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FilterExpressionToolBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterExpressionToolBar::filterPreferences)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FilterExpressionToolBar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterExpressionToolBar::filterEdit)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject FilterExpressionToolBar::staticMetaObject = { {
    QMetaObject::SuperData::link<DragDropToolBar::staticMetaObject>(),
    qt_meta_stringdata_FilterExpressionToolBar.offsetsAndSize,
    qt_meta_data_FilterExpressionToolBar,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FilterExpressionToolBar_t
, QtPrivate::TypeAndForceComplete<FilterExpressionToolBar, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAction *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAction *, std::false_type>


>,
    nullptr
} };


const QMetaObject *FilterExpressionToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterExpressionToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterExpressionToolBar.stringdata0))
        return static_cast<void*>(this);
    return DragDropToolBar::qt_metacast(_clname);
}

int FilterExpressionToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DragDropToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void FilterExpressionToolBar::filterSelected(QString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FilterExpressionToolBar::filterPreferences()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FilterExpressionToolBar::filterEdit(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
