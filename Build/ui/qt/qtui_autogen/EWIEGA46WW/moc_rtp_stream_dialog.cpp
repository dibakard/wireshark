/****************************************************************************
** Meta object code from reading C++ file 'rtp_stream_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/rtp_stream_dialog.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rtp_stream_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RtpStreamDialog_t {
    const uint offsetsAndSize[92];
    char stringdata0[1007];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_RtpStreamDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_RtpStreamDialog_t qt_meta_stringdata_RtpStreamDialog = {
    {
QT_MOC_LITERAL(0, 15), // "RtpStreamDialog"
QT_MOC_LITERAL(16, 13), // "packetsMarked"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 12), // "updateFilter"
QT_MOC_LITERAL(44, 6), // "filter"
QT_MOC_LITERAL(51, 5), // "force"
QT_MOC_LITERAL(57, 10), // "goToPacket"
QT_MOC_LITERAL(68, 10), // "packet_num"
QT_MOC_LITERAL(79, 32), // "rtpPlayerDialogReplaceRtpStreams"
QT_MOC_LITERAL(112, 22), // "QList<rtpstream_id_t*>"
QT_MOC_LITERAL(135, 10), // "stream_ids"
QT_MOC_LITERAL(146, 28), // "rtpPlayerDialogAddRtpStreams"
QT_MOC_LITERAL(175, 31), // "rtpPlayerDialogRemoveRtpStreams"
QT_MOC_LITERAL(207, 34), // "rtpAnalysisDialogReplaceRtpSt..."
QT_MOC_LITERAL(242, 12), // "stream_infos"
QT_MOC_LITERAL(255, 30), // "rtpAnalysisDialogAddRtpStreams"
QT_MOC_LITERAL(286, 33), // "rtpAnalysisDialogRemoveRtpStr..."
QT_MOC_LITERAL(320, 16), // "rtpPlayerReplace"
QT_MOC_LITERAL(337, 12), // "rtpPlayerAdd"
QT_MOC_LITERAL(350, 15), // "rtpPlayerRemove"
QT_MOC_LITERAL(366, 18), // "rtpAnalysisReplace"
QT_MOC_LITERAL(385, 14), // "rtpAnalysisAdd"
QT_MOC_LITERAL(400, 17), // "rtpAnalysisRemove"
QT_MOC_LITERAL(418, 14), // "showStreamMenu"
QT_MOC_LITERAL(433, 3), // "pos"
QT_MOC_LITERAL(437, 28), // "on_actionCopyAsCsv_triggered"
QT_MOC_LITERAL(466, 29), // "on_actionCopyAsYaml_triggered"
QT_MOC_LITERAL(496, 36), // "on_actionFindReverseNormal_tr..."
QT_MOC_LITERAL(533, 34), // "on_actionFindReversePair_trig..."
QT_MOC_LITERAL(568, 36), // "on_actionFindReverseSingle_tr..."
QT_MOC_LITERAL(605, 28), // "on_actionGoToSetup_triggered"
QT_MOC_LITERAL(634, 30), // "on_actionMarkPackets_triggered"
QT_MOC_LITERAL(665, 32), // "on_actionPrepareFilter_triggered"
QT_MOC_LITERAL(698, 40), // "on_streamTreeWidget_itemSelec..."
QT_MOC_LITERAL(739, 26), // "on_buttonBox_helpRequested"
QT_MOC_LITERAL(766, 34), // "on_actionExportAsRtpDump_trig..."
QT_MOC_LITERAL(801, 12), // "captureEvent"
QT_MOC_LITERAL(814, 12), // "CaptureEvent"
QT_MOC_LITERAL(827, 1), // "e"
QT_MOC_LITERAL(829, 28), // "displayFilterCheckBoxToggled"
QT_MOC_LITERAL(858, 7), // "checked"
QT_MOC_LITERAL(866, 22), // "on_todCheckBox_toggled"
QT_MOC_LITERAL(889, 28), // "on_actionSelectAll_triggered"
QT_MOC_LITERAL(918, 31), // "on_actionSelectInvert_triggered"
QT_MOC_LITERAL(950, 29), // "on_actionSelectNone_triggered"
QT_MOC_LITERAL(980, 26) // "on_actionAnalyze_triggered"

    },
    "RtpStreamDialog\0packetsMarked\0\0"
    "updateFilter\0filter\0force\0goToPacket\0"
    "packet_num\0rtpPlayerDialogReplaceRtpStreams\0"
    "QList<rtpstream_id_t*>\0stream_ids\0"
    "rtpPlayerDialogAddRtpStreams\0"
    "rtpPlayerDialogRemoveRtpStreams\0"
    "rtpAnalysisDialogReplaceRtpStreams\0"
    "stream_infos\0rtpAnalysisDialogAddRtpStreams\0"
    "rtpAnalysisDialogRemoveRtpStreams\0"
    "rtpPlayerReplace\0rtpPlayerAdd\0"
    "rtpPlayerRemove\0rtpAnalysisReplace\0"
    "rtpAnalysisAdd\0rtpAnalysisRemove\0"
    "showStreamMenu\0pos\0on_actionCopyAsCsv_triggered\0"
    "on_actionCopyAsYaml_triggered\0"
    "on_actionFindReverseNormal_triggered\0"
    "on_actionFindReversePair_triggered\0"
    "on_actionFindReverseSingle_triggered\0"
    "on_actionGoToSetup_triggered\0"
    "on_actionMarkPackets_triggered\0"
    "on_actionPrepareFilter_triggered\0"
    "on_streamTreeWidget_itemSelectionChanged\0"
    "on_buttonBox_helpRequested\0"
    "on_actionExportAsRtpDump_triggered\0"
    "captureEvent\0CaptureEvent\0e\0"
    "displayFilterCheckBoxToggled\0checked\0"
    "on_todCheckBox_toggled\0"
    "on_actionSelectAll_triggered\0"
    "on_actionSelectInvert_triggered\0"
    "on_actionSelectNone_triggered\0"
    "on_actionAnalyze_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RtpStreamDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  224,    2, 0x06,    1 /* Public */,
       3,    2,  225,    2, 0x06,    2 /* Public */,
       3,    1,  230,    2, 0x26,    5 /* Public | MethodCloned */,
       6,    1,  233,    2, 0x06,    7 /* Public */,
       8,    1,  236,    2, 0x06,    9 /* Public */,
      11,    1,  239,    2, 0x06,   11 /* Public */,
      12,    1,  242,    2, 0x06,   13 /* Public */,
      13,    1,  245,    2, 0x06,   15 /* Public */,
      15,    1,  248,    2, 0x06,   17 /* Public */,
      16,    1,  251,    2, 0x06,   19 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      17,    0,  254,    2, 0x0a,   21 /* Public */,
      18,    0,  255,    2, 0x0a,   22 /* Public */,
      19,    0,  256,    2, 0x0a,   23 /* Public */,
      20,    0,  257,    2, 0x0a,   24 /* Public */,
      21,    0,  258,    2, 0x0a,   25 /* Public */,
      22,    0,  259,    2, 0x0a,   26 /* Public */,
      23,    1,  260,    2, 0x08,   27 /* Private */,
      25,    0,  263,    2, 0x08,   29 /* Private */,
      26,    0,  264,    2, 0x08,   30 /* Private */,
      27,    0,  265,    2, 0x08,   31 /* Private */,
      28,    0,  266,    2, 0x08,   32 /* Private */,
      29,    0,  267,    2, 0x08,   33 /* Private */,
      30,    0,  268,    2, 0x08,   34 /* Private */,
      31,    0,  269,    2, 0x08,   35 /* Private */,
      32,    0,  270,    2, 0x08,   36 /* Private */,
      33,    0,  271,    2, 0x08,   37 /* Private */,
      34,    0,  272,    2, 0x08,   38 /* Private */,
      35,    0,  273,    2, 0x08,   39 /* Private */,
      36,    1,  274,    2, 0x08,   40 /* Private */,
      39,    1,  277,    2, 0x08,   42 /* Private */,
      41,    1,  280,    2, 0x08,   44 /* Private */,
      42,    0,  283,    2, 0x08,   46 /* Private */,
      43,    0,  284,    2, 0x08,   47 /* Private */,
      44,    0,  285,    2, 0x08,   48 /* Private */,
      45,    0,  286,    2, 0x08,   49 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    4,    5,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   14,
    QMetaType::Void, 0x80000000 | 9,   14,
    QMetaType::Void, 0x80000000 | 9,   14,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   24,
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
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 37,   38,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RtpStreamDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RtpStreamDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->packetsMarked(); break;
        case 1: _t->updateFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 2: _t->updateFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->goToPacket((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->rtpPlayerDialogReplaceRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 5: _t->rtpPlayerDialogAddRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 6: _t->rtpPlayerDialogRemoveRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 7: _t->rtpAnalysisDialogReplaceRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 8: _t->rtpAnalysisDialogAddRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 9: _t->rtpAnalysisDialogRemoveRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 10: _t->rtpPlayerReplace(); break;
        case 11: _t->rtpPlayerAdd(); break;
        case 12: _t->rtpPlayerRemove(); break;
        case 13: _t->rtpAnalysisReplace(); break;
        case 14: _t->rtpAnalysisAdd(); break;
        case 15: _t->rtpAnalysisRemove(); break;
        case 16: _t->showStreamMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 17: _t->on_actionCopyAsCsv_triggered(); break;
        case 18: _t->on_actionCopyAsYaml_triggered(); break;
        case 19: _t->on_actionFindReverseNormal_triggered(); break;
        case 20: _t->on_actionFindReversePair_triggered(); break;
        case 21: _t->on_actionFindReverseSingle_triggered(); break;
        case 22: _t->on_actionGoToSetup_triggered(); break;
        case 23: _t->on_actionMarkPackets_triggered(); break;
        case 24: _t->on_actionPrepareFilter_triggered(); break;
        case 25: _t->on_streamTreeWidget_itemSelectionChanged(); break;
        case 26: _t->on_buttonBox_helpRequested(); break;
        case 27: _t->on_actionExportAsRtpDump_triggered(); break;
        case 28: _t->captureEvent((*reinterpret_cast< std::add_pointer_t<CaptureEvent>>(_a[1]))); break;
        case 29: _t->displayFilterCheckBoxToggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 30: _t->on_todCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 31: _t->on_actionSelectAll_triggered(); break;
        case 32: _t->on_actionSelectInvert_triggered(); break;
        case 33: _t->on_actionSelectNone_triggered(); break;
        case 34: _t->on_actionAnalyze_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RtpStreamDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpStreamDialog::packetsMarked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RtpStreamDialog::*)(QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpStreamDialog::updateFilter)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RtpStreamDialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpStreamDialog::goToPacket)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (RtpStreamDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpStreamDialog::rtpPlayerDialogReplaceRtpStreams)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (RtpStreamDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpStreamDialog::rtpPlayerDialogAddRtpStreams)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (RtpStreamDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpStreamDialog::rtpPlayerDialogRemoveRtpStreams)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (RtpStreamDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpStreamDialog::rtpAnalysisDialogReplaceRtpStreams)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (RtpStreamDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpStreamDialog::rtpAnalysisDialogAddRtpStreams)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (RtpStreamDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpStreamDialog::rtpAnalysisDialogRemoveRtpStreams)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject RtpStreamDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<RtpBaseDialog::staticMetaObject>(),
    qt_meta_stringdata_RtpStreamDialog.offsetsAndSize,
    qt_meta_data_RtpStreamDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RtpStreamDialog_t
, QtPrivate::TypeAndForceComplete<RtpStreamDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<CaptureEvent, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *RtpStreamDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RtpStreamDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RtpStreamDialog.stringdata0))
        return static_cast<void*>(this);
    return RtpBaseDialog::qt_metacast(_clname);
}

int RtpStreamDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RtpBaseDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void RtpStreamDialog::packetsMarked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RtpStreamDialog::updateFilter(QString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 3
void RtpStreamDialog::goToPacket(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RtpStreamDialog::rtpPlayerDialogReplaceRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RtpStreamDialog::rtpPlayerDialogAddRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void RtpStreamDialog::rtpPlayerDialogRemoveRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void RtpStreamDialog::rtpAnalysisDialogReplaceRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void RtpStreamDialog::rtpAnalysisDialogAddRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void RtpStreamDialog::rtpAnalysisDialogRemoveRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
