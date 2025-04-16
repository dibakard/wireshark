/****************************************************************************
** Meta object code from reading C++ file 'preferences_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/preferences_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'preferences_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PreferencesDialog_t {
    const uint offsetsAndSize[36];
    char stringdata0[322];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PreferencesDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PreferencesDialog_t qt_meta_stringdata_PreferencesDialog = {
    {
QT_MOC_LITERAL(0, 17), // "PreferencesDialog"
QT_MOC_LITERAL(18, 10), // "selectPane"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 4), // "pane"
QT_MOC_LITERAL(35, 14), // "handleCopyMenu"
QT_MOC_LITERAL(50, 19), // "copyActionTriggered"
QT_MOC_LITERAL(70, 22), // "copyRowActionTriggered"
QT_MOC_LITERAL(93, 36), // "on_advancedSearchLineEdit_tex..."
QT_MOC_LITERAL(130, 9), // "search_re"
QT_MOC_LITERAL(140, 36), // "on_showChangedValuesCheckBox_..."
QT_MOC_LITERAL(177, 7), // "checked"
QT_MOC_LITERAL(185, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(207, 21), // "on_buttonBox_rejected"
QT_MOC_LITERAL(229, 26), // "on_buttonBox_helpRequested"
QT_MOC_LITERAL(256, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(277, 16), // "QAbstractButton*"
QT_MOC_LITERAL(294, 6), // "button"
QT_MOC_LITERAL(301, 20) // "updateSearchLineEdit"

    },
    "PreferencesDialog\0selectPane\0\0pane\0"
    "handleCopyMenu\0copyActionTriggered\0"
    "copyRowActionTriggered\0"
    "on_advancedSearchLineEdit_textEdited\0"
    "search_re\0on_showChangedValuesCheckBox_toggled\0"
    "checked\0on_buttonBox_accepted\0"
    "on_buttonBox_rejected\0on_buttonBox_helpRequested\0"
    "on_buttonBox_clicked\0QAbstractButton*\0"
    "button\0updateSearchLineEdit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PreferencesDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x08,    1 /* Private */,
       4,    1,   83,    2, 0x08,    3 /* Private */,
       5,    0,   86,    2, 0x08,    5 /* Private */,
       6,    0,   87,    2, 0x08,    6 /* Private */,
       7,    1,   88,    2, 0x08,    7 /* Private */,
       9,    1,   91,    2, 0x08,    9 /* Private */,
      11,    0,   94,    2, 0x08,   11 /* Private */,
      12,    0,   95,    2, 0x08,   12 /* Private */,
      13,    0,   96,    2, 0x08,   13 /* Private */,
      14,    1,   97,    2, 0x08,   14 /* Private */,
      17,    0,  100,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,

       0        // eod
};

void PreferencesDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PreferencesDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->selectPane((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->handleCopyMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 2: _t->copyActionTriggered(); break;
        case 3: _t->copyRowActionTriggered(); break;
        case 4: _t->on_advancedSearchLineEdit_textEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->on_showChangedValuesCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->on_buttonBox_accepted(); break;
        case 7: _t->on_buttonBox_rejected(); break;
        case 8: _t->on_buttonBox_helpRequested(); break;
        case 9: _t->on_buttonBox_clicked((*reinterpret_cast< std::add_pointer_t<QAbstractButton*>>(_a[1]))); break;
        case 10: _t->updateSearchLineEdit(); break;
        default: ;
        }
    }
}

const QMetaObject PreferencesDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<GeometryStateDialog::staticMetaObject>(),
    qt_meta_stringdata_PreferencesDialog.offsetsAndSize,
    qt_meta_data_PreferencesDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PreferencesDialog_t
, QtPrivate::TypeAndForceComplete<PreferencesDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractButton *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *PreferencesDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PreferencesDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PreferencesDialog.stringdata0))
        return static_cast<void*>(this);
    return GeometryStateDialog::qt_metacast(_clname);
}

int PreferencesDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeometryStateDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
