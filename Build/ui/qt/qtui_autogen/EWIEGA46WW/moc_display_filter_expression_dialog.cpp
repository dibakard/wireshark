/****************************************************************************
** Meta object code from reading C++ file 'display_filter_expression_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/display_filter_expression_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'display_filter_expression_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DisplayFilterExpressionDialog_t {
    const uint offsetsAndSize[30];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DisplayFilterExpressionDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DisplayFilterExpressionDialog_t qt_meta_stringdata_DisplayFilterExpressionDialog = {
    {
QT_MOC_LITERAL(0, 29), // "DisplayFilterExpressionDialog"
QT_MOC_LITERAL(30, 19), // "insertDisplayFilter"
QT_MOC_LITERAL(50, 0), // ""
QT_MOC_LITERAL(51, 6), // "filter"
QT_MOC_LITERAL(58, 11), // "addTreeItem"
QT_MOC_LITERAL(70, 6), // "result"
QT_MOC_LITERAL(77, 8), // "fillTree"
QT_MOC_LITERAL(86, 13), // "updateWidgets"
QT_MOC_LITERAL(100, 39), // "on_fieldTreeWidget_itemSelect..."
QT_MOC_LITERAL(140, 42), // "on_relationListWidget_itemSel..."
QT_MOC_LITERAL(183, 38), // "on_enumListWidget_itemSelecti..."
QT_MOC_LITERAL(222, 29), // "on_searchLineEdit_textChanged"
QT_MOC_LITERAL(252, 9), // "search_re"
QT_MOC_LITERAL(262, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(284, 26) // "on_buttonBox_helpRequested"

    },
    "DisplayFilterExpressionDialog\0"
    "insertDisplayFilter\0\0filter\0addTreeItem\0"
    "result\0fillTree\0updateWidgets\0"
    "on_fieldTreeWidget_itemSelectionChanged\0"
    "on_relationListWidget_itemSelectionChanged\0"
    "on_enumListWidget_itemSelectionChanged\0"
    "on_searchLineEdit_textChanged\0search_re\0"
    "on_buttonBox_accepted\0on_buttonBox_helpRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DisplayFilterExpressionDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   77,    2, 0x08,    3 /* Private */,
       6,    0,   80,    2, 0x08,    5 /* Private */,
       7,    0,   81,    2, 0x08,    6 /* Private */,
       8,    0,   82,    2, 0x08,    7 /* Private */,
       9,    0,   83,    2, 0x08,    8 /* Private */,
      10,    0,   84,    2, 0x08,    9 /* Private */,
      11,    1,   85,    2, 0x08,   10 /* Private */,
      13,    0,   88,    2, 0x08,   12 /* Private */,
      14,    0,   89,    2, 0x08,   13 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DisplayFilterExpressionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DisplayFilterExpressionDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->insertDisplayFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->addTreeItem((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->fillTree(); break;
        case 3: _t->updateWidgets(); break;
        case 4: _t->on_fieldTreeWidget_itemSelectionChanged(); break;
        case 5: _t->on_relationListWidget_itemSelectionChanged(); break;
        case 6: _t->on_enumListWidget_itemSelectionChanged(); break;
        case 7: _t->on_searchLineEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->on_buttonBox_accepted(); break;
        case 9: _t->on_buttonBox_helpRequested(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DisplayFilterExpressionDialog::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DisplayFilterExpressionDialog::insertDisplayFilter)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DisplayFilterExpressionDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<GeometryStateDialog::staticMetaObject>(),
    qt_meta_stringdata_DisplayFilterExpressionDialog.offsetsAndSize,
    qt_meta_data_DisplayFilterExpressionDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DisplayFilterExpressionDialog_t
, QtPrivate::TypeAndForceComplete<DisplayFilterExpressionDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *DisplayFilterExpressionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DisplayFilterExpressionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DisplayFilterExpressionDialog.stringdata0))
        return static_cast<void*>(this);
    return GeometryStateDialog::qt_metacast(_clname);
}

int DisplayFilterExpressionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeometryStateDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void DisplayFilterExpressionDialog::insertDisplayFilter(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
