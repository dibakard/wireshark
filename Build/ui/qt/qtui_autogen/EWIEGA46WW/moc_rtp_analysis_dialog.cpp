/****************************************************************************
** Meta object code from reading C++ file 'rtp_analysis_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/rtp_analysis_dialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rtp_analysis_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RtpAnalysisDialog_t {
    const uint offsetsAndSize[70];
    char stringdata0[633];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_RtpAnalysisDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_RtpAnalysisDialog_t qt_meta_stringdata_RtpAnalysisDialog = {
    {
QT_MOC_LITERAL(0, 17), // "RtpAnalysisDialog"
QT_MOC_LITERAL(18, 10), // "goToPacket"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 10), // "packet_num"
QT_MOC_LITERAL(41, 32), // "rtpPlayerDialogReplaceRtpStreams"
QT_MOC_LITERAL(74, 22), // "QList<rtpstream_id_t*>"
QT_MOC_LITERAL(97, 10), // "stream_ids"
QT_MOC_LITERAL(108, 28), // "rtpPlayerDialogAddRtpStreams"
QT_MOC_LITERAL(137, 31), // "rtpPlayerDialogRemoveRtpStreams"
QT_MOC_LITERAL(169, 12), // "updateFilter"
QT_MOC_LITERAL(182, 6), // "filter"
QT_MOC_LITERAL(189, 5), // "force"
QT_MOC_LITERAL(195, 16), // "rtpPlayerReplace"
QT_MOC_LITERAL(212, 12), // "rtpPlayerAdd"
QT_MOC_LITERAL(225, 15), // "rtpPlayerRemove"
QT_MOC_LITERAL(241, 13), // "updateWidgets"
QT_MOC_LITERAL(255, 29), // "on_actionGoToPacket_triggered"
QT_MOC_LITERAL(285, 30), // "on_actionNextProblem_triggered"
QT_MOC_LITERAL(316, 29), // "on_actionSaveOneCsv_triggered"
QT_MOC_LITERAL(346, 29), // "on_actionSaveAllCsv_triggered"
QT_MOC_LITERAL(376, 28), // "on_actionSaveGraph_triggered"
QT_MOC_LITERAL(405, 26), // "on_buttonBox_helpRequested"
QT_MOC_LITERAL(432, 14), // "showStreamMenu"
QT_MOC_LITERAL(447, 3), // "pos"
QT_MOC_LITERAL(451, 13), // "showGraphMenu"
QT_MOC_LITERAL(465, 12), // "graphClicked"
QT_MOC_LITERAL(478, 12), // "QMouseEvent*"
QT_MOC_LITERAL(491, 5), // "event"
QT_MOC_LITERAL(497, 8), // "closeTab"
QT_MOC_LITERAL(506, 5), // "index"
QT_MOC_LITERAL(512, 18), // "rowCheckboxChanged"
QT_MOC_LITERAL(531, 7), // "checked"
QT_MOC_LITERAL(539, 21), // "singleCheckboxChanged"
QT_MOC_LITERAL(561, 35), // "on_actionPrepareFilterOne_tri..."
QT_MOC_LITERAL(597, 35) // "on_actionPrepareFilterAll_tri..."

    },
    "RtpAnalysisDialog\0goToPacket\0\0packet_num\0"
    "rtpPlayerDialogReplaceRtpStreams\0"
    "QList<rtpstream_id_t*>\0stream_ids\0"
    "rtpPlayerDialogAddRtpStreams\0"
    "rtpPlayerDialogRemoveRtpStreams\0"
    "updateFilter\0filter\0force\0rtpPlayerReplace\0"
    "rtpPlayerAdd\0rtpPlayerRemove\0updateWidgets\0"
    "on_actionGoToPacket_triggered\0"
    "on_actionNextProblem_triggered\0"
    "on_actionSaveOneCsv_triggered\0"
    "on_actionSaveAllCsv_triggered\0"
    "on_actionSaveGraph_triggered\0"
    "on_buttonBox_helpRequested\0showStreamMenu\0"
    "pos\0showGraphMenu\0graphClicked\0"
    "QMouseEvent*\0event\0closeTab\0index\0"
    "rowCheckboxChanged\0checked\0"
    "singleCheckboxChanged\0"
    "on_actionPrepareFilterOne_triggered\0"
    "on_actionPrepareFilterAll_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RtpAnalysisDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  158,    2, 0x06,    1 /* Public */,
       4,    1,  161,    2, 0x06,    3 /* Public */,
       7,    1,  164,    2, 0x06,    5 /* Public */,
       8,    1,  167,    2, 0x06,    7 /* Public */,
       9,    2,  170,    2, 0x06,    9 /* Public */,
       9,    1,  175,    2, 0x26,   12 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,  178,    2, 0x0a,   14 /* Public */,
      13,    0,  179,    2, 0x0a,   15 /* Public */,
      14,    0,  180,    2, 0x0a,   16 /* Public */,
      15,    0,  181,    2, 0x09,   17 /* Protected */,
      16,    0,  182,    2, 0x08,   18 /* Private */,
      17,    0,  183,    2, 0x08,   19 /* Private */,
      18,    0,  184,    2, 0x08,   20 /* Private */,
      19,    0,  185,    2, 0x08,   21 /* Private */,
      20,    0,  186,    2, 0x08,   22 /* Private */,
      21,    0,  187,    2, 0x08,   23 /* Private */,
      22,    1,  188,    2, 0x08,   24 /* Private */,
      24,    1,  191,    2, 0x08,   26 /* Private */,
      25,    1,  194,    2, 0x08,   28 /* Private */,
      28,    1,  197,    2, 0x08,   30 /* Private */,
      30,    1,  200,    2, 0x08,   32 /* Private */,
      32,    1,  203,    2, 0x08,   34 /* Private */,
      33,    0,  206,    2, 0x08,   36 /* Private */,
      34,    0,  207,    2, 0x08,   37 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   10,   11,
    QMetaType::Void, QMetaType::QString,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   23,
    QMetaType::Void, QMetaType::QPoint,   23,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RtpAnalysisDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RtpAnalysisDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->goToPacket((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->rtpPlayerDialogReplaceRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 2: _t->rtpPlayerDialogAddRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 3: _t->rtpPlayerDialogRemoveRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 4: _t->updateFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 5: _t->updateFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->rtpPlayerReplace(); break;
        case 7: _t->rtpPlayerAdd(); break;
        case 8: _t->rtpPlayerRemove(); break;
        case 9: _t->updateWidgets(); break;
        case 10: _t->on_actionGoToPacket_triggered(); break;
        case 11: _t->on_actionNextProblem_triggered(); break;
        case 12: _t->on_actionSaveOneCsv_triggered(); break;
        case 13: _t->on_actionSaveAllCsv_triggered(); break;
        case 14: _t->on_actionSaveGraph_triggered(); break;
        case 15: _t->on_buttonBox_helpRequested(); break;
        case 16: _t->showStreamMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 17: _t->showGraphMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 18: _t->graphClicked((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 19: _t->closeTab((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->rowCheckboxChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->singleCheckboxChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->on_actionPrepareFilterOne_triggered(); break;
        case 23: _t->on_actionPrepareFilterAll_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RtpAnalysisDialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpAnalysisDialog::goToPacket)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RtpAnalysisDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpAnalysisDialog::rtpPlayerDialogReplaceRtpStreams)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RtpAnalysisDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpAnalysisDialog::rtpPlayerDialogAddRtpStreams)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (RtpAnalysisDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpAnalysisDialog::rtpPlayerDialogRemoveRtpStreams)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (RtpAnalysisDialog::*)(QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpAnalysisDialog::updateFilter)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject RtpAnalysisDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<WiresharkDialog::staticMetaObject>(),
    qt_meta_stringdata_RtpAnalysisDialog.offsetsAndSize,
    qt_meta_data_RtpAnalysisDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RtpAnalysisDialog_t
, QtPrivate::TypeAndForceComplete<RtpAnalysisDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *RtpAnalysisDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RtpAnalysisDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RtpAnalysisDialog.stringdata0))
        return static_cast<void*>(this);
    return WiresharkDialog::qt_metacast(_clname);
}

int RtpAnalysisDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WiresharkDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void RtpAnalysisDialog::goToPacket(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RtpAnalysisDialog::rtpPlayerDialogReplaceRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RtpAnalysisDialog::rtpPlayerDialogAddRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RtpAnalysisDialog::rtpPlayerDialogRemoveRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RtpAnalysisDialog::updateFilter(QString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
