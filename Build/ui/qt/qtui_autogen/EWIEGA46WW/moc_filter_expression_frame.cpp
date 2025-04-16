/****************************************************************************
** Meta object code from reading C++ file 'filter_expression_frame.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/filter_expression_frame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filter_expression_frame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilterExpressionFrame_t {
    const uint offsetsAndSize[22];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FilterExpressionFrame_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FilterExpressionFrame_t qt_meta_stringdata_FilterExpressionFrame = {
    {
QT_MOC_LITERAL(0, 21), // "FilterExpressionFrame"
QT_MOC_LITERAL(22, 21), // "showPreferencesDialog"
QT_MOC_LITERAL(44, 0), // ""
QT_MOC_LITERAL(45, 9), // "pane_name"
QT_MOC_LITERAL(55, 24), // "filterExpressionsChanged"
QT_MOC_LITERAL(80, 13), // "updateWidgets"
QT_MOC_LITERAL(94, 48), // "on_filterExpressionPreference..."
QT_MOC_LITERAL(143, 28), // "on_labelLineEdit_textChanged"
QT_MOC_LITERAL(172, 36), // "on_displayFilterLineEdit_text..."
QT_MOC_LITERAL(209, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(231, 21) // "on_buttonBox_rejected"

    },
    "FilterExpressionFrame\0showPreferencesDialog\0"
    "\0pane_name\0filterExpressionsChanged\0"
    "updateWidgets\0"
    "on_filterExpressionPreferencesPushButton_clicked\0"
    "on_labelLineEdit_textChanged\0"
    "on_displayFilterLineEdit_textChanged\0"
    "on_buttonBox_accepted\0on_buttonBox_rejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterExpressionFrame[] = {

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
       4,    0,   65,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   66,    2, 0x08,    4 /* Private */,
       6,    0,   67,    2, 0x08,    5 /* Private */,
       7,    1,   68,    2, 0x08,    6 /* Private */,
       8,    1,   71,    2, 0x08,    8 /* Private */,
       9,    0,   74,    2, 0x08,   10 /* Private */,
      10,    0,   75,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FilterExpressionFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FilterExpressionFrame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showPreferencesDialog((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->filterExpressionsChanged(); break;
        case 2: _t->updateWidgets(); break;
        case 3: _t->on_filterExpressionPreferencesPushButton_clicked(); break;
        case 4: _t->on_labelLineEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->on_displayFilterLineEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->on_buttonBox_accepted(); break;
        case 7: _t->on_buttonBox_rejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FilterExpressionFrame::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterExpressionFrame::showPreferencesDialog)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FilterExpressionFrame::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FilterExpressionFrame::filterExpressionsChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FilterExpressionFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<AccordionFrame::staticMetaObject>(),
    qt_meta_stringdata_FilterExpressionFrame.offsetsAndSize,
    qt_meta_data_FilterExpressionFrame,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FilterExpressionFrame_t
, QtPrivate::TypeAndForceComplete<FilterExpressionFrame, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FilterExpressionFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterExpressionFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterExpressionFrame.stringdata0))
        return static_cast<void*>(this);
    return AccordionFrame::qt_metacast(_clname);
}

int FilterExpressionFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AccordionFrame::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void FilterExpressionFrame::showPreferencesDialog(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FilterExpressionFrame::filterExpressionsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
