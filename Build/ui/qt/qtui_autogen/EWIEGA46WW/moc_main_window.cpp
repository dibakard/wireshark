/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/main_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[72];
    char stringdata0[555];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 14), // "setCaptureFile"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 13), // "capture_file*"
QT_MOC_LITERAL(41, 2), // "cf"
QT_MOC_LITERAL(44, 13), // "captureActive"
QT_MOC_LITERAL(58, 13), // "fieldSelected"
QT_MOC_LITERAL(72, 17), // "FieldInformation*"
QT_MOC_LITERAL(90, 14), // "fieldHighlight"
QT_MOC_LITERAL(105, 14), // "framesSelected"
QT_MOC_LITERAL(120, 10), // "QList<int>"
QT_MOC_LITERAL(131, 12), // "filterAction"
QT_MOC_LITERAL(144, 6), // "filter"
QT_MOC_LITERAL(151, 20), // "FilterAction::Action"
QT_MOC_LITERAL(172, 6), // "action"
QT_MOC_LITERAL(179, 24), // "FilterAction::ActionType"
QT_MOC_LITERAL(204, 4), // "type"
QT_MOC_LITERAL(209, 20), // "displayFilterSuccess"
QT_MOC_LITERAL(230, 7), // "success"
QT_MOC_LITERAL(238, 16), // "setDisplayFilter"
QT_MOC_LITERAL(255, 10), // "filterType"
QT_MOC_LITERAL(266, 13), // "filterPackets"
QT_MOC_LITERAL(280, 21), // "showPreferencesDialog"
QT_MOC_LITERAL(302, 11), // "module_name"
QT_MOC_LITERAL(314, 17), // "showIOGraphDialog"
QT_MOC_LITERAL(332, 20), // "io_graph_item_unit_t"
QT_MOC_LITERAL(353, 11), // "layoutPanes"
QT_MOC_LITERAL(365, 23), // "applyRecentPaneGeometry"
QT_MOC_LITERAL(389, 23), // "updateForUnsavedChanges"
QT_MOC_LITERAL(413, 34), // "addDisplayFilterTranslationAc..."
QT_MOC_LITERAL(448, 6), // "QMenu*"
QT_MOC_LITERAL(455, 9), // "copy_menu"
QT_MOC_LITERAL(465, 37), // "updateDisplayFilterTranslatio..."
QT_MOC_LITERAL(503, 7), // "df_text"
QT_MOC_LITERAL(511, 14), // "updateTitlebar"
QT_MOC_LITERAL(526, 28) // "copyDisplayFilterTranslation"

    },
    "MainWindow\0setCaptureFile\0\0capture_file*\0"
    "cf\0captureActive\0fieldSelected\0"
    "FieldInformation*\0fieldHighlight\0"
    "framesSelected\0QList<int>\0filterAction\0"
    "filter\0FilterAction::Action\0action\0"
    "FilterAction::ActionType\0type\0"
    "displayFilterSuccess\0success\0"
    "setDisplayFilter\0filterType\0filterPackets\0"
    "showPreferencesDialog\0module_name\0"
    "showIOGraphDialog\0io_graph_item_unit_t\0"
    "layoutPanes\0applyRecentPaneGeometry\0"
    "updateForUnsavedChanges\0"
    "addDisplayFilterTranslationActions\0"
    "QMenu*\0copy_menu\0updateDisplayFilterTranslationActions\0"
    "df_text\0updateTitlebar\0"
    "copyDisplayFilterTranslation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  122,    2, 0x06,    1 /* Public */,
       5,    1,  125,    2, 0x06,    3 /* Public */,
       6,    1,  128,    2, 0x06,    5 /* Public */,
       8,    1,  131,    2, 0x06,    7 /* Public */,
       9,    1,  134,    2, 0x06,    9 /* Public */,
      11,    3,  137,    2, 0x06,   11 /* Public */,
      17,    1,  144,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      19,    3,  147,    2, 0x0a,   17 /* Public */,
      21,    2,  154,    2, 0x0a,   21 /* Public */,
      22,    1,  159,    2, 0x0a,   24 /* Public */,
      24,    2,  162,    2, 0x0a,   26 /* Public */,
      26,    0,  167,    2, 0x0a,   29 /* Public */,
      27,    0,  168,    2, 0x0a,   30 /* Public */,
      28,    0,  169,    2, 0x0a,   31 /* Public */,
      29,    1,  170,    2, 0x09,   32 /* Protected */,
      32,    1,  173,    2, 0x09,   34 /* Protected */,
      34,    0,  176,    2, 0x09,   36 /* Protected */,
      35,    0,  177,    2, 0x08,   37 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13, 0x80000000 | 15,   12,   14,   16,
    QMetaType::Void, QMetaType::Bool,   18,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13, 0x80000000 | 15,   12,   14,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, 0x80000000 | 25, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, QMetaType::QString,   33,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setCaptureFile((*reinterpret_cast< std::add_pointer_t<capture_file*>>(_a[1]))); break;
        case 1: _t->captureActive((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->fieldSelected((*reinterpret_cast< std::add_pointer_t<FieldInformation*>>(_a[1]))); break;
        case 3: _t->fieldHighlight((*reinterpret_cast< std::add_pointer_t<FieldInformation*>>(_a[1]))); break;
        case 4: _t->framesSelected((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 5: _t->filterAction((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<FilterAction::Action>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<FilterAction::ActionType>>(_a[3]))); break;
        case 6: _t->displayFilterSuccess((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->setDisplayFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<FilterAction::Action>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<FilterAction::ActionType>>(_a[3]))); break;
        case 8: _t->filterPackets((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 9: _t->showPreferencesDialog((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->showIOGraphDialog((*reinterpret_cast< std::add_pointer_t<io_graph_item_unit_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 11: _t->layoutPanes(); break;
        case 12: _t->applyRecentPaneGeometry(); break;
        case 13: _t->updateForUnsavedChanges(); break;
        case 14: _t->addDisplayFilterTranslationActions((*reinterpret_cast< std::add_pointer_t<QMenu*>>(_a[1]))); break;
        case 15: _t->updateDisplayFilterTranslationActions((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->updateTitlebar(); break;
        case 17: _t->copyDisplayFilterTranslation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FieldInformation* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FieldInformation* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(capture_file * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::setCaptureFile)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::captureActive)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(FieldInformation * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::fieldSelected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(FieldInformation * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::fieldHighlight)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::framesSelected)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , FilterAction::Action , FilterAction::ActionType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::filterAction)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::displayFilterSuccess)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_file *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<FieldInformation *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<FieldInformation *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::Action, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::ActionType, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::Action, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::ActionType, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<io_graph_item_unit_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMenu *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::setCaptureFile(capture_file * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::captureActive(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::fieldSelected(FieldInformation * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::fieldHighlight(FieldInformation * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::framesSelected(QList<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::filterAction(QString _t1, FilterAction::Action _t2, FilterAction::ActionType _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::displayFilterSuccess(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
