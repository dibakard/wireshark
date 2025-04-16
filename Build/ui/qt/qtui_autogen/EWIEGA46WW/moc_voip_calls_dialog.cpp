/****************************************************************************
** Meta object code from reading C++ file 'voip_calls_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/voip_calls_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'voip_calls_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VoipCallsDialog_t {
    const uint offsetsAndSize[92];
    char stringdata0[787];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_VoipCallsDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_VoipCallsDialog_t qt_meta_stringdata_VoipCallsDialog = {
    {
QT_MOC_LITERAL(0, 15), // "VoipCallsDialog"
QT_MOC_LITERAL(16, 12), // "updateFilter"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 6), // "filter"
QT_MOC_LITERAL(37, 5), // "force"
QT_MOC_LITERAL(43, 18), // "captureFileChanged"
QT_MOC_LITERAL(62, 13), // "capture_file*"
QT_MOC_LITERAL(76, 2), // "cf"
QT_MOC_LITERAL(79, 10), // "goToPacket"
QT_MOC_LITERAL(90, 10), // "packet_num"
QT_MOC_LITERAL(101, 32), // "rtpPlayerDialogReplaceRtpStreams"
QT_MOC_LITERAL(134, 22), // "QList<rtpstream_id_t*>"
QT_MOC_LITERAL(157, 10), // "stream_ids"
QT_MOC_LITERAL(168, 28), // "rtpPlayerDialogAddRtpStreams"
QT_MOC_LITERAL(197, 31), // "rtpPlayerDialogRemoveRtpStreams"
QT_MOC_LITERAL(229, 32), // "rtpStreamsDialogSelectRtpStreams"
QT_MOC_LITERAL(262, 34), // "rtpStreamsDialogDeselectRtpSt..."
QT_MOC_LITERAL(297, 16), // "rtpPlayerReplace"
QT_MOC_LITERAL(314, 12), // "rtpPlayerAdd"
QT_MOC_LITERAL(327, 15), // "rtpPlayerRemove"
QT_MOC_LITERAL(343, 11), // "changeEvent"
QT_MOC_LITERAL(355, 7), // "QEvent*"
QT_MOC_LITERAL(363, 5), // "event"
QT_MOC_LITERAL(369, 9), // "selectAll"
QT_MOC_LITERAL(379, 10), // "selectNone"
QT_MOC_LITERAL(390, 9), // "copyAsCSV"
QT_MOC_LITERAL(400, 10), // "copyAsYAML"
QT_MOC_LITERAL(411, 15), // "switchTimeOfDay"
QT_MOC_LITERAL(427, 25), // "on_callTreeView_activated"
QT_MOC_LITERAL(453, 11), // "QModelIndex"
QT_MOC_LITERAL(465, 5), // "index"
QT_MOC_LITERAL(471, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(492, 16), // "QAbstractButton*"
QT_MOC_LITERAL(509, 6), // "button"
QT_MOC_LITERAL(516, 26), // "on_buttonBox_helpRequested"
QT_MOC_LITERAL(543, 13), // "updateWidgets"
QT_MOC_LITERAL(557, 12), // "captureEvent"
QT_MOC_LITERAL(570, 12), // "CaptureEvent"
QT_MOC_LITERAL(583, 1), // "e"
QT_MOC_LITERAL(585, 28), // "displayFilterCheckBoxToggled"
QT_MOC_LITERAL(614, 7), // "checked"
QT_MOC_LITERAL(622, 28), // "on_actionSelectAll_triggered"
QT_MOC_LITERAL(651, 31), // "on_actionSelectInvert_triggered"
QT_MOC_LITERAL(683, 29), // "on_actionSelectNone_triggered"
QT_MOC_LITERAL(713, 35), // "on_actionSelectRtpStreams_tri..."
QT_MOC_LITERAL(749, 37) // "on_actionDeselectRtpStreams_t..."

    },
    "VoipCallsDialog\0updateFilter\0\0filter\0"
    "force\0captureFileChanged\0capture_file*\0"
    "cf\0goToPacket\0packet_num\0"
    "rtpPlayerDialogReplaceRtpStreams\0"
    "QList<rtpstream_id_t*>\0stream_ids\0"
    "rtpPlayerDialogAddRtpStreams\0"
    "rtpPlayerDialogRemoveRtpStreams\0"
    "rtpStreamsDialogSelectRtpStreams\0"
    "rtpStreamsDialogDeselectRtpStreams\0"
    "rtpPlayerReplace\0rtpPlayerAdd\0"
    "rtpPlayerRemove\0changeEvent\0QEvent*\0"
    "event\0selectAll\0selectNone\0copyAsCSV\0"
    "copyAsYAML\0switchTimeOfDay\0"
    "on_callTreeView_activated\0QModelIndex\0"
    "index\0on_buttonBox_clicked\0QAbstractButton*\0"
    "button\0on_buttonBox_helpRequested\0"
    "updateWidgets\0captureEvent\0CaptureEvent\0"
    "e\0displayFilterCheckBoxToggled\0checked\0"
    "on_actionSelectAll_triggered\0"
    "on_actionSelectInvert_triggered\0"
    "on_actionSelectNone_triggered\0"
    "on_actionSelectRtpStreams_triggered\0"
    "on_actionDeselectRtpStreams_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VoipCallsDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  188,    2, 0x06,    1 /* Public */,
       1,    1,  193,    2, 0x26,    4 /* Public | MethodCloned */,
       5,    1,  196,    2, 0x06,    6 /* Public */,
       8,    1,  199,    2, 0x06,    8 /* Public */,
      10,    1,  202,    2, 0x06,   10 /* Public */,
      13,    1,  205,    2, 0x06,   12 /* Public */,
      14,    1,  208,    2, 0x06,   14 /* Public */,
      15,    1,  211,    2, 0x06,   16 /* Public */,
      16,    1,  214,    2, 0x06,   18 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      17,    0,  217,    2, 0x0a,   20 /* Public */,
      18,    0,  218,    2, 0x0a,   21 /* Public */,
      19,    0,  219,    2, 0x0a,   22 /* Public */,
      20,    1,  220,    2, 0x09,   23 /* Protected */,
      23,    0,  223,    2, 0x08,   25 /* Private */,
      24,    0,  224,    2, 0x08,   26 /* Private */,
      25,    0,  225,    2, 0x08,   27 /* Private */,
      26,    0,  226,    2, 0x08,   28 /* Private */,
      27,    0,  227,    2, 0x08,   29 /* Private */,
      28,    1,  228,    2, 0x08,   30 /* Private */,
      31,    1,  231,    2, 0x08,   32 /* Private */,
      34,    0,  234,    2, 0x08,   34 /* Private */,
      35,    0,  235,    2, 0x08,   35 /* Private */,
      36,    1,  236,    2, 0x08,   36 /* Private */,
      39,    1,  239,    2, 0x08,   38 /* Private */,
      41,    0,  242,    2, 0x08,   40 /* Private */,
      42,    0,  243,    2, 0x08,   41 /* Private */,
      43,    0,  244,    2, 0x08,   42 /* Private */,
      44,    0,  245,    2, 0x08,   43 /* Private */,
      45,    0,  246,    2, 0x08,   44 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 37,   38,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VoipCallsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VoipCallsDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 1: _t->updateFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->captureFileChanged((*reinterpret_cast< std::add_pointer_t<capture_file*>>(_a[1]))); break;
        case 3: _t->goToPacket((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->rtpPlayerDialogReplaceRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 5: _t->rtpPlayerDialogAddRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 6: _t->rtpPlayerDialogRemoveRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 7: _t->rtpStreamsDialogSelectRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 8: _t->rtpStreamsDialogDeselectRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 9: _t->rtpPlayerReplace(); break;
        case 10: _t->rtpPlayerAdd(); break;
        case 11: _t->rtpPlayerRemove(); break;
        case 12: _t->changeEvent((*reinterpret_cast< std::add_pointer_t<QEvent*>>(_a[1]))); break;
        case 13: _t->selectAll(); break;
        case 14: _t->selectNone(); break;
        case 15: _t->copyAsCSV(); break;
        case 16: _t->copyAsYAML(); break;
        case 17: _t->switchTimeOfDay(); break;
        case 18: _t->on_callTreeView_activated((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 19: _t->on_buttonBox_clicked((*reinterpret_cast< std::add_pointer_t<QAbstractButton*>>(_a[1]))); break;
        case 20: _t->on_buttonBox_helpRequested(); break;
        case 21: _t->updateWidgets(); break;
        case 22: _t->captureEvent((*reinterpret_cast< std::add_pointer_t<CaptureEvent>>(_a[1]))); break;
        case 23: _t->displayFilterCheckBoxToggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 24: _t->on_actionSelectAll_triggered(); break;
        case 25: _t->on_actionSelectInvert_triggered(); break;
        case 26: _t->on_actionSelectNone_triggered(); break;
        case 27: _t->on_actionSelectRtpStreams_triggered(); break;
        case 28: _t->on_actionDeselectRtpStreams_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VoipCallsDialog::*)(QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoipCallsDialog::updateFilter)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VoipCallsDialog::*)(capture_file * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoipCallsDialog::captureFileChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VoipCallsDialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoipCallsDialog::goToPacket)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (VoipCallsDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoipCallsDialog::rtpPlayerDialogReplaceRtpStreams)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (VoipCallsDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoipCallsDialog::rtpPlayerDialogAddRtpStreams)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (VoipCallsDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoipCallsDialog::rtpPlayerDialogRemoveRtpStreams)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (VoipCallsDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoipCallsDialog::rtpStreamsDialogSelectRtpStreams)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (VoipCallsDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VoipCallsDialog::rtpStreamsDialogDeselectRtpStreams)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject VoipCallsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<WiresharkDialog::staticMetaObject>(),
    qt_meta_stringdata_VoipCallsDialog.offsetsAndSize,
    qt_meta_data_VoipCallsDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_VoipCallsDialog_t
, QtPrivate::TypeAndForceComplete<VoipCallsDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_file *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractButton *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<CaptureEvent, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *VoipCallsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VoipCallsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VoipCallsDialog.stringdata0))
        return static_cast<void*>(this);
    return WiresharkDialog::qt_metacast(_clname);
}

int VoipCallsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WiresharkDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void VoipCallsDialog::updateFilter(QString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void VoipCallsDialog::captureFileChanged(capture_file * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VoipCallsDialog::goToPacket(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void VoipCallsDialog::rtpPlayerDialogReplaceRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void VoipCallsDialog::rtpPlayerDialogAddRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void VoipCallsDialog::rtpPlayerDialogRemoveRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void VoipCallsDialog::rtpStreamsDialogSelectRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void VoipCallsDialog::rtpStreamsDialogDeselectRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
