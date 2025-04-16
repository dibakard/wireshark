/****************************************************************************
** Meta object code from reading C++ file 'capture_file_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/capture_file_dialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'capture_file_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CaptureFileDialog_t {
    const uint offsetsAndSize[44];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CaptureFileDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CaptureFileDialog_t qt_meta_stringdata_CaptureFileDialog = {
    {
QT_MOC_LITERAL(0, 17), // "CaptureFileDialog"
QT_MOC_LITERAL(18, 6), // "accept"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 4), // "exec"
QT_MOC_LITERAL(31, 4), // "open"
QT_MOC_LITERAL(36, 8), // "QString&"
QT_MOC_LITERAL(45, 9), // "file_name"
QT_MOC_LITERAL(55, 5), // "uint&"
QT_MOC_LITERAL(61, 4), // "type"
QT_MOC_LITERAL(66, 14), // "display_filter"
QT_MOC_LITERAL(81, 6), // "saveAs"
QT_MOC_LITERAL(88, 18), // "check_savability_t"
QT_MOC_LITERAL(107, 21), // "must_support_comments"
QT_MOC_LITERAL(129, 21), // "exportSelectedPackets"
QT_MOC_LITERAL(151, 15), // "packet_range_t*"
QT_MOC_LITERAL(167, 5), // "range"
QT_MOC_LITERAL(173, 8), // "selRange"
QT_MOC_LITERAL(182, 5), // "merge"
QT_MOC_LITERAL(188, 20), // "fixFilenameExtension"
QT_MOC_LITERAL(209, 7), // "preview"
QT_MOC_LITERAL(217, 4), // "path"
QT_MOC_LITERAL(222, 26) // "on_buttonBox_helpRequested"

    },
    "CaptureFileDialog\0accept\0\0exec\0open\0"
    "QString&\0file_name\0uint&\0type\0"
    "display_filter\0saveAs\0check_savability_t\0"
    "must_support_comments\0exportSelectedPackets\0"
    "packet_range_t*\0range\0selRange\0merge\0"
    "fixFilenameExtension\0preview\0path\0"
    "on_buttonBox_helpRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CaptureFileDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x0a,    1 /* Public */,
       3,    0,   75,    2, 0x0a,    2 /* Public */,
       4,    3,   76,    2, 0x0a,    3 /* Public */,
      10,    2,   83,    2, 0x0a,    7 /* Public */,
      13,    3,   88,    2, 0x0a,   10 /* Public */,
      13,    2,   95,    2, 0x2a,   14 /* Public | MethodCloned */,
      17,    2,  100,    2, 0x0a,   17 /* Public */,
      18,    0,  105,    2, 0x08,   20 /* Private */,
      19,    1,  106,    2, 0x08,   21 /* Private */,
      21,    0,  109,    2, 0x08,   23 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Int, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 5,    6,    8,    9,
    0x80000000 | 11, 0x80000000 | 5, QMetaType::Bool,    6,   12,
    0x80000000 | 11, 0x80000000 | 5, 0x80000000 | 14, QMetaType::QString,    6,   15,   16,
    0x80000000 | 11, 0x80000000 | 5, 0x80000000 | 14,    6,   15,
    QMetaType::Int, 0x80000000 | 5, 0x80000000 | 5,    6,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,

       0        // eod
};

void CaptureFileDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CaptureFileDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->accept(); break;
        case 1: { int _r = _t->exec();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->open((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString&>>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { check_savability_t _r = _t->saveAs((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast< check_savability_t*>(_a[0]) = std::move(_r); }  break;
        case 4: { check_savability_t _r = _t->exportSelectedPackets((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<packet_range_t*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< check_savability_t*>(_a[0]) = std::move(_r); }  break;
        case 5: { check_savability_t _r = _t->exportSelectedPackets((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<packet_range_t*>>(_a[2])));
            if (_a[0]) *reinterpret_cast< check_savability_t*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->merge((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString&>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->fixFilenameExtension(); break;
        case 8: _t->preview((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->on_buttonBox_helpRequested(); break;
        default: ;
        }
    }
}

const QMetaObject CaptureFileDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<WiresharkFileDialog::staticMetaObject>(),
    qt_meta_stringdata_CaptureFileDialog.offsetsAndSize,
    qt_meta_data_CaptureFileDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CaptureFileDialog_t
, QtPrivate::TypeAndForceComplete<CaptureFileDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString &, std::false_type>, QtPrivate::TypeAndForceComplete<unsigned int &, std::false_type>, QtPrivate::TypeAndForceComplete<QString &, std::false_type>, QtPrivate::TypeAndForceComplete<check_savability_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<check_savability_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString &, std::false_type>, QtPrivate::TypeAndForceComplete<packet_range_t *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<check_savability_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString &, std::false_type>, QtPrivate::TypeAndForceComplete<packet_range_t *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString &, std::false_type>, QtPrivate::TypeAndForceComplete<QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CaptureFileDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CaptureFileDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CaptureFileDialog.stringdata0))
        return static_cast<void*>(this);
    return WiresharkFileDialog::qt_metacast(_clname);
}

int CaptureFileDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WiresharkFileDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
