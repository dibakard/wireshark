/****************************************************************************
** Meta object code from reading C++ file 'capture_options_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/capture_options_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'capture_options_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InterfaceTreeDelegate_t {
    const uint offsetsAndSize[18];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_InterfaceTreeDelegate_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_InterfaceTreeDelegate_t qt_meta_stringdata_InterfaceTreeDelegate = {
    {
QT_MOC_LITERAL(0, 21), // "InterfaceTreeDelegate"
QT_MOC_LITERAL(22, 13), // "filterChanged"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 6), // "filter"
QT_MOC_LITERAL(44, 15), // "linkTypeChanged"
QT_MOC_LITERAL(60, 18), // "selected_link_type"
QT_MOC_LITERAL(79, 21), // "snapshotLengthChanged"
QT_MOC_LITERAL(101, 5), // "value"
QT_MOC_LITERAL(107, 17) // "bufferSizeChanged"

    },
    "InterfaceTreeDelegate\0filterChanged\0"
    "\0filter\0linkTypeChanged\0selected_link_type\0"
    "snapshotLengthChanged\0value\0"
    "bufferSizeChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InterfaceTreeDelegate[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   41,    2, 0x08,    3 /* Private */,
       6,    1,   44,    2, 0x08,    5 /* Private */,
       8,    1,   47,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void InterfaceTreeDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InterfaceTreeDelegate *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->filterChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->linkTypeChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->snapshotLengthChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->bufferSizeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InterfaceTreeDelegate::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InterfaceTreeDelegate::filterChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject InterfaceTreeDelegate::staticMetaObject = { {
    QMetaObject::SuperData::link<QStyledItemDelegate::staticMetaObject>(),
    qt_meta_stringdata_InterfaceTreeDelegate.offsetsAndSize,
    qt_meta_data_InterfaceTreeDelegate,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_InterfaceTreeDelegate_t
, QtPrivate::TypeAndForceComplete<InterfaceTreeDelegate, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *InterfaceTreeDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InterfaceTreeDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InterfaceTreeDelegate.stringdata0))
        return static_cast<void*>(this);
    return QStyledItemDelegate::qt_metacast(_clname);
}

int InterfaceTreeDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void InterfaceTreeDelegate::filterChanged(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CaptureOptionsDialog_t {
    const uint offsetsAndSize[106];
    char stringdata0[993];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CaptureOptionsDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CaptureOptionsDialog_t qt_meta_stringdata_CaptureOptionsDialog = {
    {
QT_MOC_LITERAL(0, 20), // "CaptureOptionsDialog"
QT_MOC_LITERAL(21, 12), // "startCapture"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 11), // "stopCapture"
QT_MOC_LITERAL(47, 21), // "setSelectedInterfaces"
QT_MOC_LITERAL(69, 14), // "setFilterValid"
QT_MOC_LITERAL(84, 5), // "valid"
QT_MOC_LITERAL(90, 14), // "capture_filter"
QT_MOC_LITERAL(105, 17), // "interfacesChanged"
QT_MOC_LITERAL(123, 10), // "ifsChanged"
QT_MOC_LITERAL(134, 20), // "interfaceListChanged"
QT_MOC_LITERAL(155, 23), // "captureFilterTextEdited"
QT_MOC_LITERAL(179, 4), // "text"
QT_MOC_LITERAL(184, 17), // "showExtcapOptions"
QT_MOC_LITERAL(202, 8), // "QString&"
QT_MOC_LITERAL(211, 11), // "device_name"
QT_MOC_LITERAL(223, 19), // "startCaptureOnClose"
QT_MOC_LITERAL(243, 17), // "interfaceSelected"
QT_MOC_LITERAL(261, 34), // "on_capturePromModeCheckBox_to..."
QT_MOC_LITERAL(296, 7), // "checked"
QT_MOC_LITERAL(304, 37), // "on_captureMonitorModeCheckBox..."
QT_MOC_LITERAL(342, 28), // "on_gbStopCaptureAuto_toggled"
QT_MOC_LITERAL(371, 28), // "on_cbUpdatePacketsRT_toggled"
QT_MOC_LITERAL(400, 23), // "on_cbAutoScroll_toggled"
QT_MOC_LITERAL(424, 24), // "on_gbNewFileAuto_toggled"
QT_MOC_LITERAL(449, 29), // "on_cbExtraCaptureInfo_toggled"
QT_MOC_LITERAL(479, 32), // "on_cbResolveMacAddresses_toggled"
QT_MOC_LITERAL(512, 21), // "on_compileBPF_clicked"
QT_MOC_LITERAL(534, 23), // "on_manageButton_clicked"
QT_MOC_LITERAL(558, 32), // "on_cbResolveNetworkNames_toggled"
QT_MOC_LITERAL(591, 34), // "on_cbResolveTransportNames_to..."
QT_MOC_LITERAL(626, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(648, 21), // "on_buttonBox_rejected"
QT_MOC_LITERAL(670, 26), // "on_buttonBox_helpRequested"
QT_MOC_LITERAL(697, 12), // "filterEdited"
QT_MOC_LITERAL(710, 13), // "updateWidgets"
QT_MOC_LITERAL(724, 16), // "updateStatistics"
QT_MOC_LITERAL(741, 20), // "refreshInterfaceList"
QT_MOC_LITERAL(762, 21), // "updateLocalInterfaces"
QT_MOC_LITERAL(784, 19), // "browseButtonClicked"
QT_MOC_LITERAL(804, 20), // "interfaceItemChanged"
QT_MOC_LITERAL(825, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(842, 4), // "item"
QT_MOC_LITERAL(847, 6), // "column"
QT_MOC_LITERAL(854, 11), // "itemClicked"
QT_MOC_LITERAL(866, 17), // "itemDoubleClicked"
QT_MOC_LITERAL(884, 11), // "changeEvent"
QT_MOC_LITERAL(896, 7), // "QEvent*"
QT_MOC_LITERAL(904, 5), // "event"
QT_MOC_LITERAL(910, 26), // "tempDirBrowseButtonClicked"
QT_MOC_LITERAL(937, 22), // "MBComboBoxIndexChanged"
QT_MOC_LITERAL(960, 5), // "index"
QT_MOC_LITERAL(966, 26) // "stopMBComboBoxIndexChanged"

    },
    "CaptureOptionsDialog\0startCapture\0\0"
    "stopCapture\0setSelectedInterfaces\0"
    "setFilterValid\0valid\0capture_filter\0"
    "interfacesChanged\0ifsChanged\0"
    "interfaceListChanged\0captureFilterTextEdited\0"
    "text\0showExtcapOptions\0QString&\0"
    "device_name\0startCaptureOnClose\0"
    "interfaceSelected\0on_capturePromModeCheckBox_toggled\0"
    "checked\0on_captureMonitorModeCheckBox_toggled\0"
    "on_gbStopCaptureAuto_toggled\0"
    "on_cbUpdatePacketsRT_toggled\0"
    "on_cbAutoScroll_toggled\0"
    "on_gbNewFileAuto_toggled\0"
    "on_cbExtraCaptureInfo_toggled\0"
    "on_cbResolveMacAddresses_toggled\0"
    "on_compileBPF_clicked\0on_manageButton_clicked\0"
    "on_cbResolveNetworkNames_toggled\0"
    "on_cbResolveTransportNames_toggled\0"
    "on_buttonBox_accepted\0on_buttonBox_rejected\0"
    "on_buttonBox_helpRequested\0filterEdited\0"
    "updateWidgets\0updateStatistics\0"
    "refreshInterfaceList\0updateLocalInterfaces\0"
    "browseButtonClicked\0interfaceItemChanged\0"
    "QTreeWidgetItem*\0item\0column\0itemClicked\0"
    "itemDoubleClicked\0changeEvent\0QEvent*\0"
    "event\0tempDirBrowseButtonClicked\0"
    "MBComboBoxIndexChanged\0index\0"
    "stopMBComboBoxIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CaptureOptionsDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      38,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  242,    2, 0x06,    1 /* Public */,
       3,    0,  243,    2, 0x06,    2 /* Public */,
       4,    0,  244,    2, 0x06,    3 /* Public */,
       5,    2,  245,    2, 0x06,    4 /* Public */,
       8,    0,  250,    2, 0x06,    7 /* Public */,
       9,    0,  251,    2, 0x06,    8 /* Public */,
      10,    0,  252,    2, 0x06,    9 /* Public */,
      11,    1,  253,    2, 0x06,   10 /* Public */,
      13,    2,  256,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      17,    0,  261,    2, 0x0a,   15 /* Public */,
      18,    1,  262,    2, 0x08,   16 /* Private */,
      20,    1,  265,    2, 0x08,   18 /* Private */,
      21,    1,  268,    2, 0x08,   20 /* Private */,
      22,    1,  271,    2, 0x08,   22 /* Private */,
      23,    1,  274,    2, 0x08,   24 /* Private */,
      24,    1,  277,    2, 0x08,   26 /* Private */,
      25,    1,  280,    2, 0x08,   28 /* Private */,
      26,    1,  283,    2, 0x08,   30 /* Private */,
      27,    0,  286,    2, 0x08,   32 /* Private */,
      28,    0,  287,    2, 0x08,   33 /* Private */,
      29,    1,  288,    2, 0x08,   34 /* Private */,
      30,    1,  291,    2, 0x08,   36 /* Private */,
      31,    0,  294,    2, 0x08,   38 /* Private */,
      32,    0,  295,    2, 0x08,   39 /* Private */,
      33,    0,  296,    2, 0x08,   40 /* Private */,
      34,    0,  297,    2, 0x08,   41 /* Private */,
      35,    0,  298,    2, 0x08,   42 /* Private */,
      36,    0,  299,    2, 0x08,   43 /* Private */,
      37,    0,  300,    2, 0x08,   44 /* Private */,
      38,    0,  301,    2, 0x08,   45 /* Private */,
      39,    0,  302,    2, 0x08,   46 /* Private */,
      40,    2,  303,    2, 0x08,   47 /* Private */,
      44,    2,  308,    2, 0x08,   50 /* Private */,
      45,    2,  313,    2, 0x08,   53 /* Private */,
      46,    1,  318,    2, 0x08,   56 /* Private */,
      49,    0,  321,    2, 0x08,   58 /* Private */,
      50,    1,  322,    2, 0x08,   59 /* Private */,
      52,    1,  325,    2, 0x08,   61 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Bool,   15,   16,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 41, QMetaType::Int,   42,   43,
    QMetaType::Void, 0x80000000 | 41, QMetaType::Int,   42,   43,
    QMetaType::Void, 0x80000000 | 41, QMetaType::Int,   42,   43,
    QMetaType::Void, 0x80000000 | 47,   48,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   51,
    QMetaType::Void, QMetaType::Int,   51,

       0        // eod
};

void CaptureOptionsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CaptureOptionsDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->startCapture(); break;
        case 1: _t->stopCapture(); break;
        case 2: _t->setSelectedInterfaces(); break;
        case 3: _t->setFilterValid((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->interfacesChanged(); break;
        case 5: _t->ifsChanged(); break;
        case 6: _t->interfaceListChanged(); break;
        case 7: _t->captureFilterTextEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->showExtcapOptions((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 9: _t->interfaceSelected(); break;
        case 10: _t->on_capturePromModeCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->on_captureMonitorModeCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->on_gbStopCaptureAuto_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->on_cbUpdatePacketsRT_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->on_cbAutoScroll_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->on_gbNewFileAuto_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 16: _t->on_cbExtraCaptureInfo_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->on_cbResolveMacAddresses_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->on_compileBPF_clicked(); break;
        case 19: _t->on_manageButton_clicked(); break;
        case 20: _t->on_cbResolveNetworkNames_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 21: _t->on_cbResolveTransportNames_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 22: _t->on_buttonBox_accepted(); break;
        case 23: _t->on_buttonBox_rejected(); break;
        case 24: _t->on_buttonBox_helpRequested(); break;
        case 25: _t->filterEdited(); break;
        case 26: _t->updateWidgets(); break;
        case 27: _t->updateStatistics(); break;
        case 28: _t->refreshInterfaceList(); break;
        case 29: _t->updateLocalInterfaces(); break;
        case 30: _t->browseButtonClicked(); break;
        case 31: _t->interfaceItemChanged((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 32: _t->itemClicked((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 33: _t->itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 34: _t->changeEvent((*reinterpret_cast< std::add_pointer_t<QEvent*>>(_a[1]))); break;
        case 35: _t->tempDirBrowseButtonClicked(); break;
        case 36: _t->MBComboBoxIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 37: _t->stopMBComboBoxIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CaptureOptionsDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureOptionsDialog::startCapture)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CaptureOptionsDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureOptionsDialog::stopCapture)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CaptureOptionsDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureOptionsDialog::setSelectedInterfaces)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CaptureOptionsDialog::*)(bool , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureOptionsDialog::setFilterValid)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CaptureOptionsDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureOptionsDialog::interfacesChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CaptureOptionsDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureOptionsDialog::ifsChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CaptureOptionsDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureOptionsDialog::interfaceListChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CaptureOptionsDialog::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureOptionsDialog::captureFilterTextEdited)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (CaptureOptionsDialog::*)(QString & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureOptionsDialog::showExtcapOptions)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject CaptureOptionsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<GeometryStateDialog::staticMetaObject>(),
    qt_meta_stringdata_CaptureOptionsDialog.offsetsAndSize,
    qt_meta_data_CaptureOptionsDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CaptureOptionsDialog_t
, QtPrivate::TypeAndForceComplete<CaptureOptionsDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *CaptureOptionsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CaptureOptionsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CaptureOptionsDialog.stringdata0))
        return static_cast<void*>(this);
    return GeometryStateDialog::qt_metacast(_clname);
}

int CaptureOptionsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeometryStateDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 38)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 38;
    }
    return _id;
}

// SIGNAL 0
void CaptureOptionsDialog::startCapture()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CaptureOptionsDialog::stopCapture()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CaptureOptionsDialog::setSelectedInterfaces()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CaptureOptionsDialog::setFilterValid(bool _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CaptureOptionsDialog::interfacesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CaptureOptionsDialog::ifsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void CaptureOptionsDialog::interfaceListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void CaptureOptionsDialog::captureFilterTextEdited(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CaptureOptionsDialog::showExtcapOptions(QString & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
