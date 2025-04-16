/****************************************************************************
** Meta object code from reading C++ file 'capture_filter_edit.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/widgets/capture_filter_edit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'capture_filter_edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CaptureFilterEdit_t {
    const uint offsetsAndSize[40];
    char stringdata0[268];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CaptureFilterEdit_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CaptureFilterEdit_t qt_meta_stringdata_CaptureFilterEdit = {
    {
QT_MOC_LITERAL(0, 17), // "CaptureFilterEdit"
QT_MOC_LITERAL(18, 26), // "captureFilterSyntaxChanged"
QT_MOC_LITERAL(45, 0), // ""
QT_MOC_LITERAL(46, 5), // "valid"
QT_MOC_LITERAL(52, 20), // "captureFilterChanged"
QT_MOC_LITERAL(73, 6), // "filter"
QT_MOC_LITERAL(80, 12), // "startCapture"
QT_MOC_LITERAL(93, 11), // "addBookmark"
QT_MOC_LITERAL(105, 11), // "checkFilter"
QT_MOC_LITERAL(117, 18), // "updateBookmarkMenu"
QT_MOC_LITERAL(136, 10), // "saveFilter"
QT_MOC_LITERAL(147, 12), // "removeFilter"
QT_MOC_LITERAL(160, 11), // "showFilters"
QT_MOC_LITERAL(172, 13), // "prepareFilter"
QT_MOC_LITERAL(186, 18), // "applyCaptureFilter"
QT_MOC_LITERAL(205, 20), // "setFilterSyntaxState"
QT_MOC_LITERAL(226, 5), // "state"
QT_MOC_LITERAL(232, 7), // "err_msg"
QT_MOC_LITERAL(240, 15), // "bookmarkClicked"
QT_MOC_LITERAL(256, 11) // "clearFilter"

    },
    "CaptureFilterEdit\0captureFilterSyntaxChanged\0"
    "\0valid\0captureFilterChanged\0filter\0"
    "startCapture\0addBookmark\0checkFilter\0"
    "updateBookmarkMenu\0saveFilter\0"
    "removeFilter\0showFilters\0prepareFilter\0"
    "applyCaptureFilter\0setFilterSyntaxState\0"
    "state\0err_msg\0bookmarkClicked\0clearFilter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CaptureFilterEdit[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x06,    1 /* Public */,
       4,    1,  107,    2, 0x06,    3 /* Public */,
       6,    0,  110,    2, 0x06,    5 /* Public */,
       7,    1,  111,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,  114,    2, 0x0a,    8 /* Public */,
       9,    0,  115,    2, 0x0a,    9 /* Public */,
      10,    0,  116,    2, 0x0a,   10 /* Public */,
      11,    0,  117,    2, 0x0a,   11 /* Public */,
      12,    0,  118,    2, 0x0a,   12 /* Public */,
      13,    0,  119,    2, 0x0a,   13 /* Public */,
      14,    0,  120,    2, 0x08,   14 /* Private */,
       8,    1,  121,    2, 0x08,   15 /* Private */,
      15,    3,  124,    2, 0x08,   17 /* Private */,
      18,    0,  131,    2, 0x08,   21 /* Private */,
      19,    0,  132,    2, 0x08,   22 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    5,   16,   17,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CaptureFilterEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CaptureFilterEdit *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->captureFilterSyntaxChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->captureFilterChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->startCapture(); break;
        case 3: _t->addBookmark((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->checkFilter(); break;
        case 5: _t->updateBookmarkMenu(); break;
        case 6: _t->saveFilter(); break;
        case 7: _t->removeFilter(); break;
        case 8: _t->showFilters(); break;
        case 9: _t->prepareFilter(); break;
        case 10: _t->applyCaptureFilter(); break;
        case 11: _t->checkFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->setFilterSyntaxState((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 13: _t->bookmarkClicked(); break;
        case 14: _t->clearFilter(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CaptureFilterEdit::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureFilterEdit::captureFilterSyntaxChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CaptureFilterEdit::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureFilterEdit::captureFilterChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CaptureFilterEdit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureFilterEdit::startCapture)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CaptureFilterEdit::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureFilterEdit::addBookmark)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject CaptureFilterEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<SyntaxLineEdit::staticMetaObject>(),
    qt_meta_stringdata_CaptureFilterEdit.offsetsAndSize,
    qt_meta_data_CaptureFilterEdit,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CaptureFilterEdit_t
, QtPrivate::TypeAndForceComplete<CaptureFilterEdit, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CaptureFilterEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CaptureFilterEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CaptureFilterEdit.stringdata0))
        return static_cast<void*>(this);
    return SyntaxLineEdit::qt_metacast(_clname);
}

int CaptureFilterEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SyntaxLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void CaptureFilterEdit::captureFilterSyntaxChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CaptureFilterEdit::captureFilterChanged(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CaptureFilterEdit::startCapture()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CaptureFilterEdit::addBookmark(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
