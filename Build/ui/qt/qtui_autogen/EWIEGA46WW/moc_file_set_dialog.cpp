/****************************************************************************
** Meta object code from reading C++ file 'file_set_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/file_set_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'file_set_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileSetDialog_t {
    const uint offsetsAndSize[14];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FileSetDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FileSetDialog_t qt_meta_stringdata_FileSetDialog = {
    {
QT_MOC_LITERAL(0, 13), // "FileSetDialog"
QT_MOC_LITERAL(14, 22), // "fileSetOpenCaptureFile"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 16), // "selectionChanged"
QT_MOC_LITERAL(55, 14), // "QItemSelection"
QT_MOC_LITERAL(70, 8), // "selected"
QT_MOC_LITERAL(79, 26) // "on_buttonBox_helpRequested"

    },
    "FileSetDialog\0fileSetOpenCaptureFile\0"
    "\0selectionChanged\0QItemSelection\0"
    "selected\0on_buttonBox_helpRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileSetDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    2,   35,    2, 0x08,    3 /* Private */,
       6,    0,   40,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    2,
    QMetaType::Void,

       0        // eod
};

void FileSetDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileSetDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->fileSetOpenCaptureFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->selectionChanged((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[2]))); break;
        case 2: _t->on_buttonBox_helpRequested(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QItemSelection >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FileSetDialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileSetDialog::fileSetOpenCaptureFile)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject FileSetDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<GeometryStateDialog::staticMetaObject>(),
    qt_meta_stringdata_FileSetDialog.offsetsAndSize,
    qt_meta_data_FileSetDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FileSetDialog_t
, QtPrivate::TypeAndForceComplete<FileSetDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>, QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FileSetDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileSetDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileSetDialog.stringdata0))
        return static_cast<void*>(this);
    return GeometryStateDialog::qt_metacast(_clname);
}

int FileSetDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeometryStateDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void FileSetDialog::fileSetOpenCaptureFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
