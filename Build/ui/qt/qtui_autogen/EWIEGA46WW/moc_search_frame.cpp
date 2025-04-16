/****************************************************************************
** Meta object code from reading C++ file 'search_frame.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/search_frame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'search_frame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SearchFrame_t {
    const uint offsetsAndSize[38];
    char stringdata0[370];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SearchFrame_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SearchFrame_t qt_meta_stringdata_SearchFrame = {
    {
QT_MOC_LITERAL(0, 11), // "SearchFrame"
QT_MOC_LITERAL(12, 14), // "setCaptureFile"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 13), // "capture_file*"
QT_MOC_LITERAL(42, 2), // "cf"
QT_MOC_LITERAL(45, 19), // "findFrameWithFilter"
QT_MOC_LITERAL(65, 8), // "QString&"
QT_MOC_LITERAL(74, 6), // "filter"
QT_MOC_LITERAL(81, 39), // "on_searchInComboBox_currentIn..."
QT_MOC_LITERAL(121, 3), // "idx"
QT_MOC_LITERAL(125, 43), // "on_charEncodingComboBox_curre..."
QT_MOC_LITERAL(169, 23), // "on_caseCheckBox_toggled"
QT_MOC_LITERAL(193, 7), // "checked"
QT_MOC_LITERAL(201, 41), // "on_searchTypeComboBox_current..."
QT_MOC_LITERAL(243, 29), // "on_searchLineEdit_textChanged"
QT_MOC_LITERAL(273, 22), // "on_dirCheckBox_toggled"
QT_MOC_LITERAL(296, 27), // "on_multipleCheckBox_toggled"
QT_MOC_LITERAL(324, 21), // "on_findButton_clicked"
QT_MOC_LITERAL(346, 23) // "on_cancelButton_clicked"

    },
    "SearchFrame\0setCaptureFile\0\0capture_file*\0"
    "cf\0findFrameWithFilter\0QString&\0filter\0"
    "on_searchInComboBox_currentIndexChanged\0"
    "idx\0on_charEncodingComboBox_currentIndexChanged\0"
    "on_caseCheckBox_toggled\0checked\0"
    "on_searchTypeComboBox_currentIndexChanged\0"
    "on_searchLineEdit_textChanged\0"
    "on_dirCheckBox_toggled\0"
    "on_multipleCheckBox_toggled\0"
    "on_findButton_clicked\0on_cancelButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchFrame[] = {

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
       1,    1,   80,    2, 0x0a,    1 /* Public */,
       5,    1,   83,    2, 0x0a,    3 /* Public */,
       8,    1,   86,    2, 0x08,    5 /* Private */,
      10,    1,   89,    2, 0x08,    7 /* Private */,
      11,    1,   92,    2, 0x08,    9 /* Private */,
      13,    1,   95,    2, 0x08,   11 /* Private */,
      14,    1,   98,    2, 0x08,   13 /* Private */,
      15,    1,  101,    2, 0x08,   15 /* Private */,
      16,    1,  104,    2, 0x08,   17 /* Private */,
      17,    0,  107,    2, 0x08,   19 /* Private */,
      18,    0,  108,    2, 0x08,   20 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SearchFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SearchFrame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setCaptureFile((*reinterpret_cast< std::add_pointer_t<capture_file*>>(_a[1]))); break;
        case 1: _t->findFrameWithFilter((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1]))); break;
        case 2: _t->on_searchInComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_charEncodingComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_caseCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->on_searchTypeComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_searchLineEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->on_dirCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->on_multipleCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->on_findButton_clicked(); break;
        case 10: _t->on_cancelButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject SearchFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<AccordionFrame::staticMetaObject>(),
    qt_meta_stringdata_SearchFrame.offsetsAndSize,
    qt_meta_data_SearchFrame,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SearchFrame_t
, QtPrivate::TypeAndForceComplete<SearchFrame, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_file *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *SearchFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SearchFrame.stringdata0))
        return static_cast<void*>(this);
    return AccordionFrame::qt_metacast(_clname);
}

int SearchFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AccordionFrame::qt_metacall(_c, _id, _a);
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
