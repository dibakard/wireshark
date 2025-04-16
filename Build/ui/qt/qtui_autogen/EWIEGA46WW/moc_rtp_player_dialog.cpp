/****************************************************************************
** Meta object code from reading C++ file 'rtp_player_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/rtp_player_dialog.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rtp_player_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RtpBaseDialog_t {
    const uint offsetsAndSize[10];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_RtpBaseDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_RtpBaseDialog_t qt_meta_stringdata_RtpBaseDialog = {
    {
QT_MOC_LITERAL(0, 13), // "RtpBaseDialog"
QT_MOC_LITERAL(14, 18), // "rtpAnalysisReplace"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 14), // "rtpAnalysisAdd"
QT_MOC_LITERAL(49, 17) // "rtpAnalysisRemove"

    },
    "RtpBaseDialog\0rtpAnalysisReplace\0\0"
    "rtpAnalysisAdd\0rtpAnalysisRemove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RtpBaseDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x0a,    1 /* Public */,
       3,    0,   33,    2, 0x0a,    2 /* Public */,
       4,    0,   34,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RtpBaseDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RtpBaseDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->rtpAnalysisReplace(); break;
        case 1: _t->rtpAnalysisAdd(); break;
        case 2: _t->rtpAnalysisRemove(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject RtpBaseDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<WiresharkDialog::staticMetaObject>(),
    qt_meta_stringdata_RtpBaseDialog.offsetsAndSize,
    qt_meta_data_RtpBaseDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RtpBaseDialog_t
, QtPrivate::TypeAndForceComplete<RtpBaseDialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *RtpBaseDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RtpBaseDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RtpBaseDialog.stringdata0))
        return static_cast<void*>(this);
    return WiresharkDialog::qt_metacast(_clname);
}

int RtpBaseDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WiresharkDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_RtpPlayerDialog_t {
    const uint offsetsAndSize[208];
    char stringdata0[2227];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_RtpPlayerDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_RtpPlayerDialog_t qt_meta_stringdata_RtpPlayerDialog = {
    {
QT_MOC_LITERAL(0, 15), // "RtpPlayerDialog"
QT_MOC_LITERAL(16, 13), // "packetsMarked"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 12), // "updateFilter"
QT_MOC_LITERAL(44, 6), // "filter"
QT_MOC_LITERAL(51, 5), // "force"
QT_MOC_LITERAL(57, 10), // "goToPacket"
QT_MOC_LITERAL(68, 10), // "packet_num"
QT_MOC_LITERAL(79, 34), // "rtpAnalysisDialogReplaceRtpSt..."
QT_MOC_LITERAL(114, 22), // "QList<rtpstream_id_t*>"
QT_MOC_LITERAL(137, 12), // "stream_infos"
QT_MOC_LITERAL(150, 30), // "rtpAnalysisDialogAddRtpStreams"
QT_MOC_LITERAL(181, 33), // "rtpAnalysisDialogRemoveRtpStr..."
QT_MOC_LITERAL(215, 18), // "rtpAnalysisReplace"
QT_MOC_LITERAL(234, 14), // "rtpAnalysisAdd"
QT_MOC_LITERAL(249, 17), // "rtpAnalysisRemove"
QT_MOC_LITERAL(267, 12), // "retapPackets"
QT_MOC_LITERAL(280, 12), // "captureEvent"
QT_MOC_LITERAL(293, 12), // "CaptureEvent"
QT_MOC_LITERAL(306, 1), // "e"
QT_MOC_LITERAL(308, 13), // "rescanPackets"
QT_MOC_LITERAL(322, 12), // "rescale_axes"
QT_MOC_LITERAL(335, 10), // "createPlot"
QT_MOC_LITERAL(346, 13), // "updateWidgets"
QT_MOC_LITERAL(360, 11), // "itemEntered"
QT_MOC_LITERAL(372, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(389, 4), // "item"
QT_MOC_LITERAL(394, 6), // "column"
QT_MOC_LITERAL(401, 13), // "mouseMovePlot"
QT_MOC_LITERAL(415, 12), // "QMouseEvent*"
QT_MOC_LITERAL(428, 5), // "event"
QT_MOC_LITERAL(434, 15), // "mouseMoveUpdate"
QT_MOC_LITERAL(450, 20), // "showGraphContextMenu"
QT_MOC_LITERAL(471, 3), // "pos"
QT_MOC_LITERAL(475, 12), // "graphClicked"
QT_MOC_LITERAL(488, 18), // "graphDoubleClicked"
QT_MOC_LITERAL(507, 11), // "plotClicked"
QT_MOC_LITERAL(519, 21), // "QCPAbstractPlottable*"
QT_MOC_LITERAL(541, 9), // "plottable"
QT_MOC_LITERAL(551, 9), // "dataIndex"
QT_MOC_LITERAL(561, 15), // "updateHintLabel"
QT_MOC_LITERAL(577, 10), // "resetXAxis"
QT_MOC_LITERAL(588, 12), // "updateGraphs"
QT_MOC_LITERAL(601, 12), // "playFinished"
QT_MOC_LITERAL(614, 15), // "RtpAudioStream*"
QT_MOC_LITERAL(630, 6), // "stream"
QT_MOC_LITERAL(637, 13), // "QAudio::Error"
QT_MOC_LITERAL(651, 5), // "error"
QT_MOC_LITERAL(657, 15), // "setPlayPosition"
QT_MOC_LITERAL(673, 4), // "secs"
QT_MOC_LITERAL(678, 16), // "setPlaybackError"
QT_MOC_LITERAL(695, 14), // "playback_error"
QT_MOC_LITERAL(710, 24), // "changeAudioRoutingOnItem"
QT_MOC_LITERAL(735, 2), // "ti"
QT_MOC_LITERAL(738, 12), // "AudioRouting"
QT_MOC_LITERAL(751, 17), // "new_audio_routing"
QT_MOC_LITERAL(769, 18), // "changeAudioRouting"
QT_MOC_LITERAL(788, 23), // "invertAudioMutingOnItem"
QT_MOC_LITERAL(812, 21), // "on_playButton_clicked"
QT_MOC_LITERAL(834, 22), // "on_pauseButton_clicked"
QT_MOC_LITERAL(857, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(879, 24), // "on_actionReset_triggered"
QT_MOC_LITERAL(904, 25), // "on_actionZoomIn_triggered"
QT_MOC_LITERAL(930, 26), // "on_actionZoomOut_triggered"
QT_MOC_LITERAL(957, 29), // "on_actionMoveLeft10_triggered"
QT_MOC_LITERAL(987, 30), // "on_actionMoveRight10_triggered"
QT_MOC_LITERAL(1018, 28), // "on_actionMoveLeft1_triggered"
QT_MOC_LITERAL(1047, 29), // "on_actionMoveRight1_triggered"
QT_MOC_LITERAL(1077, 29), // "on_actionGoToPacket_triggered"
QT_MOC_LITERAL(1107, 38), // "on_actionGoToSetupPacketPlot_..."
QT_MOC_LITERAL(1146, 38), // "on_actionGoToSetupPacketTree_..."
QT_MOC_LITERAL(1185, 31), // "on_actionRemoveStream_triggered"
QT_MOC_LITERAL(1217, 32), // "on_actionAudioRoutingP_triggered"
QT_MOC_LITERAL(1250, 32), // "on_actionAudioRoutingL_triggered"
QT_MOC_LITERAL(1283, 33), // "on_actionAudioRoutingLR_trigg..."
QT_MOC_LITERAL(1317, 32), // "on_actionAudioRoutingR_triggered"
QT_MOC_LITERAL(1350, 35), // "on_actionAudioRoutingMute_tri..."
QT_MOC_LITERAL(1386, 37), // "on_actionAudioRoutingUnmute_t..."
QT_MOC_LITERAL(1424, 41), // "on_actionAudioRoutingMuteInve..."
QT_MOC_LITERAL(1466, 40), // "on_streamTreeWidget_itemSelec..."
QT_MOC_LITERAL(1507, 37), // "on_streamTreeWidget_itemDoubl..."
QT_MOC_LITERAL(1545, 42), // "on_outputDeviceComboBox_curre..."
QT_MOC_LITERAL(1588, 37), // "on_outputAudioRate_currentTex..."
QT_MOC_LITERAL(1626, 29), // "on_jitterSpinBox_valueChanged"
QT_MOC_LITERAL(1656, 37), // "on_timingComboBox_currentInde..."
QT_MOC_LITERAL(1694, 22), // "on_todCheckBox_toggled"
QT_MOC_LITERAL(1717, 7), // "checked"
QT_MOC_LITERAL(1725, 26), // "on_buttonBox_helpRequested"
QT_MOC_LITERAL(1752, 28), // "on_actionSelectAll_triggered"
QT_MOC_LITERAL(1781, 31), // "on_actionSelectInvert_triggered"
QT_MOC_LITERAL(1813, 29), // "on_actionSelectNone_triggered"
QT_MOC_LITERAL(1843, 12), // "outputNotify"
QT_MOC_LITERAL(1856, 23), // "on_actionPlay_triggered"
QT_MOC_LITERAL(1880, 23), // "on_actionStop_triggered"
QT_MOC_LITERAL(1904, 38), // "on_actionSaveAudioFromCursor_..."
QT_MOC_LITERAL(1943, 38), // "on_actionSaveAudioSyncStream_..."
QT_MOC_LITERAL(1982, 36), // "on_actionSaveAudioSyncFile_tr..."
QT_MOC_LITERAL(2019, 30), // "on_actionSavePayload_triggered"
QT_MOC_LITERAL(2050, 34), // "on_actionSelectInaudible_trig..."
QT_MOC_LITERAL(2085, 36), // "on_actionDeselectInaudible_tr..."
QT_MOC_LITERAL(2122, 32), // "on_actionPrepareFilter_triggered"
QT_MOC_LITERAL(2155, 30), // "on_actionReadCapture_triggered"
QT_MOC_LITERAL(2186, 16), // "sinkStateChanged"
QT_MOC_LITERAL(2203, 23) // "currentOutputDeviceName"

    },
    "RtpPlayerDialog\0packetsMarked\0\0"
    "updateFilter\0filter\0force\0goToPacket\0"
    "packet_num\0rtpAnalysisDialogReplaceRtpStreams\0"
    "QList<rtpstream_id_t*>\0stream_infos\0"
    "rtpAnalysisDialogAddRtpStreams\0"
    "rtpAnalysisDialogRemoveRtpStreams\0"
    "rtpAnalysisReplace\0rtpAnalysisAdd\0"
    "rtpAnalysisRemove\0retapPackets\0"
    "captureEvent\0CaptureEvent\0e\0rescanPackets\0"
    "rescale_axes\0createPlot\0updateWidgets\0"
    "itemEntered\0QTreeWidgetItem*\0item\0"
    "column\0mouseMovePlot\0QMouseEvent*\0"
    "event\0mouseMoveUpdate\0showGraphContextMenu\0"
    "pos\0graphClicked\0graphDoubleClicked\0"
    "plotClicked\0QCPAbstractPlottable*\0"
    "plottable\0dataIndex\0updateHintLabel\0"
    "resetXAxis\0updateGraphs\0playFinished\0"
    "RtpAudioStream*\0stream\0QAudio::Error\0"
    "error\0setPlayPosition\0secs\0setPlaybackError\0"
    "playback_error\0changeAudioRoutingOnItem\0"
    "ti\0AudioRouting\0new_audio_routing\0"
    "changeAudioRouting\0invertAudioMutingOnItem\0"
    "on_playButton_clicked\0on_pauseButton_clicked\0"
    "on_stopButton_clicked\0on_actionReset_triggered\0"
    "on_actionZoomIn_triggered\0"
    "on_actionZoomOut_triggered\0"
    "on_actionMoveLeft10_triggered\0"
    "on_actionMoveRight10_triggered\0"
    "on_actionMoveLeft1_triggered\0"
    "on_actionMoveRight1_triggered\0"
    "on_actionGoToPacket_triggered\0"
    "on_actionGoToSetupPacketPlot_triggered\0"
    "on_actionGoToSetupPacketTree_triggered\0"
    "on_actionRemoveStream_triggered\0"
    "on_actionAudioRoutingP_triggered\0"
    "on_actionAudioRoutingL_triggered\0"
    "on_actionAudioRoutingLR_triggered\0"
    "on_actionAudioRoutingR_triggered\0"
    "on_actionAudioRoutingMute_triggered\0"
    "on_actionAudioRoutingUnmute_triggered\0"
    "on_actionAudioRoutingMuteInvert_triggered\0"
    "on_streamTreeWidget_itemSelectionChanged\0"
    "on_streamTreeWidget_itemDoubleClicked\0"
    "on_outputDeviceComboBox_currentTextChanged\0"
    "on_outputAudioRate_currentTextChanged\0"
    "on_jitterSpinBox_valueChanged\0"
    "on_timingComboBox_currentIndexChanged\0"
    "on_todCheckBox_toggled\0checked\0"
    "on_buttonBox_helpRequested\0"
    "on_actionSelectAll_triggered\0"
    "on_actionSelectInvert_triggered\0"
    "on_actionSelectNone_triggered\0"
    "outputNotify\0on_actionPlay_triggered\0"
    "on_actionStop_triggered\0"
    "on_actionSaveAudioFromCursor_triggered\0"
    "on_actionSaveAudioSyncStream_triggered\0"
    "on_actionSaveAudioSyncFile_triggered\0"
    "on_actionSavePayload_triggered\0"
    "on_actionSelectInaudible_triggered\0"
    "on_actionDeselectInaudible_triggered\0"
    "on_actionPrepareFilter_triggered\0"
    "on_actionReadCapture_triggered\0"
    "sinkStateChanged\0currentOutputDeviceName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RtpPlayerDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      77,   14, // methods
       1,  621, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  476,    2, 0x06,    2 /* Public */,
       3,    2,  477,    2, 0x06,    3 /* Public */,
       3,    1,  482,    2, 0x26,    6 /* Public | MethodCloned */,
       6,    1,  485,    2, 0x06,    8 /* Public */,
       8,    1,  488,    2, 0x06,   10 /* Public */,
      11,    1,  491,    2, 0x06,   12 /* Public */,
      12,    1,  494,    2, 0x06,   14 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    0,  497,    2, 0x0a,   16 /* Public */,
      14,    0,  498,    2, 0x0a,   17 /* Public */,
      15,    0,  499,    2, 0x0a,   18 /* Public */,
      16,    0,  500,    2, 0x08,   19 /* Private */,
      17,    1,  501,    2, 0x08,   20 /* Private */,
      20,    1,  504,    2, 0x08,   22 /* Private */,
      20,    0,  507,    2, 0x28,   24 /* Private | MethodCloned */,
      22,    1,  508,    2, 0x08,   25 /* Private */,
      22,    0,  511,    2, 0x28,   27 /* Private | MethodCloned */,
      23,    0,  512,    2, 0x08,   28 /* Private */,
      24,    2,  513,    2, 0x08,   29 /* Private */,
      28,    1,  518,    2, 0x08,   32 /* Private */,
      31,    0,  521,    2, 0x08,   34 /* Private */,
      32,    1,  522,    2, 0x08,   35 /* Private */,
      34,    1,  525,    2, 0x08,   37 /* Private */,
      35,    1,  528,    2, 0x08,   39 /* Private */,
      36,    3,  531,    2, 0x08,   41 /* Private */,
      40,    0,  538,    2, 0x08,   45 /* Private */,
      41,    0,  539,    2, 0x08,   46 /* Private */,
      42,    0,  540,    2, 0x08,   47 /* Private */,
      43,    2,  541,    2, 0x08,   48 /* Private */,
      48,    1,  546,    2, 0x08,   51 /* Private */,
      50,    1,  549,    2, 0x08,   53 /* Private */,
      52,    2,  552,    2, 0x08,   55 /* Private */,
      56,    1,  557,    2, 0x08,   58 /* Private */,
      57,    1,  560,    2, 0x08,   60 /* Private */,
      58,    0,  563,    2, 0x08,   62 /* Private */,
      59,    0,  564,    2, 0x08,   63 /* Private */,
      60,    0,  565,    2, 0x08,   64 /* Private */,
      61,    0,  566,    2, 0x08,   65 /* Private */,
      62,    0,  567,    2, 0x08,   66 /* Private */,
      63,    0,  568,    2, 0x08,   67 /* Private */,
      64,    0,  569,    2, 0x08,   68 /* Private */,
      65,    0,  570,    2, 0x08,   69 /* Private */,
      66,    0,  571,    2, 0x08,   70 /* Private */,
      67,    0,  572,    2, 0x08,   71 /* Private */,
      68,    0,  573,    2, 0x08,   72 /* Private */,
      69,    0,  574,    2, 0x08,   73 /* Private */,
      70,    0,  575,    2, 0x08,   74 /* Private */,
      71,    0,  576,    2, 0x08,   75 /* Private */,
      72,    0,  577,    2, 0x08,   76 /* Private */,
      73,    0,  578,    2, 0x08,   77 /* Private */,
      74,    0,  579,    2, 0x08,   78 /* Private */,
      75,    0,  580,    2, 0x08,   79 /* Private */,
      76,    0,  581,    2, 0x08,   80 /* Private */,
      77,    0,  582,    2, 0x08,   81 /* Private */,
      78,    0,  583,    2, 0x08,   82 /* Private */,
      79,    0,  584,    2, 0x08,   83 /* Private */,
      80,    2,  585,    2, 0x08,   84 /* Private */,
      81,    1,  590,    2, 0x08,   87 /* Private */,
      82,    1,  593,    2, 0x08,   89 /* Private */,
      83,    1,  596,    2, 0x08,   91 /* Private */,
      84,    1,  599,    2, 0x08,   93 /* Private */,
      85,    1,  602,    2, 0x08,   95 /* Private */,
      87,    0,  605,    2, 0x08,   97 /* Private */,
      88,    0,  606,    2, 0x08,   98 /* Private */,
      89,    0,  607,    2, 0x08,   99 /* Private */,
      90,    0,  608,    2, 0x08,  100 /* Private */,
      91,    0,  609,    2, 0x08,  101 /* Private */,
      92,    0,  610,    2, 0x08,  102 /* Private */,
      93,    0,  611,    2, 0x08,  103 /* Private */,
      94,    0,  612,    2, 0x08,  104 /* Private */,
      95,    0,  613,    2, 0x08,  105 /* Private */,
      96,    0,  614,    2, 0x08,  106 /* Private */,
      97,    0,  615,    2, 0x08,  107 /* Private */,
      98,    0,  616,    2, 0x08,  108 /* Private */,
      99,    0,  617,    2, 0x08,  109 /* Private */,
     100,    0,  618,    2, 0x08,  110 /* Private */,
     101,    0,  619,    2, 0x08,  111 /* Private */,
     102,    0,  620,    2, 0x08,  112 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    4,    5,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25, QMetaType::Int,   26,   27,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   33,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, 0x80000000 | 37, QMetaType::Int, 0x80000000 | 29,   38,   39,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 44, 0x80000000 | 46,   45,   47,
    QMetaType::Void, QMetaType::Double,   49,
    QMetaType::Void, QMetaType::QString,   51,
    QMetaType::Void, 0x80000000 | 25, 0x80000000 | 54,   53,   55,
    QMetaType::Void, 0x80000000 | 54,   55,
    QMetaType::Void, 0x80000000 | 25,   53,
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
    QMetaType::Void, 0x80000000 | 25, QMetaType::Int,   26,   27,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,   86,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
     103, QMetaType::QString, 0x00015001, uint(-1), 0,

       0        // eod
};

void RtpPlayerDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RtpPlayerDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->packetsMarked(); break;
        case 1: _t->updateFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 2: _t->updateFilter((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->goToPacket((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->rtpAnalysisDialogReplaceRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 5: _t->rtpAnalysisDialogAddRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 6: _t->rtpAnalysisDialogRemoveRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 7: _t->rtpAnalysisReplace(); break;
        case 8: _t->rtpAnalysisAdd(); break;
        case 9: _t->rtpAnalysisRemove(); break;
        case 10: _t->retapPackets(); break;
        case 11: _t->captureEvent((*reinterpret_cast< std::add_pointer_t<CaptureEvent>>(_a[1]))); break;
        case 12: _t->rescanPackets((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->rescanPackets(); break;
        case 14: _t->createPlot((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->createPlot(); break;
        case 16: _t->updateWidgets(); break;
        case 17: _t->itemEntered((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 18: _t->mouseMovePlot((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 19: _t->mouseMoveUpdate(); break;
        case 20: _t->showGraphContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 21: _t->graphClicked((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 22: _t->graphDoubleClicked((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 23: _t->plotClicked((*reinterpret_cast< std::add_pointer_t<QCPAbstractPlottable*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[3]))); break;
        case 24: _t->updateHintLabel(); break;
        case 25: _t->resetXAxis(); break;
        case 26: _t->updateGraphs(); break;
        case 27: _t->playFinished((*reinterpret_cast< std::add_pointer_t<RtpAudioStream*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAudio::Error>>(_a[2]))); break;
        case 28: _t->setPlayPosition((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 29: _t->setPlaybackError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 30: _t->changeAudioRoutingOnItem((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<AudioRouting>>(_a[2]))); break;
        case 31: _t->changeAudioRouting((*reinterpret_cast< std::add_pointer_t<AudioRouting>>(_a[1]))); break;
        case 32: _t->invertAudioMutingOnItem((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1]))); break;
        case 33: _t->on_playButton_clicked(); break;
        case 34: _t->on_pauseButton_clicked(); break;
        case 35: _t->on_stopButton_clicked(); break;
        case 36: _t->on_actionReset_triggered(); break;
        case 37: _t->on_actionZoomIn_triggered(); break;
        case 38: _t->on_actionZoomOut_triggered(); break;
        case 39: _t->on_actionMoveLeft10_triggered(); break;
        case 40: _t->on_actionMoveRight10_triggered(); break;
        case 41: _t->on_actionMoveLeft1_triggered(); break;
        case 42: _t->on_actionMoveRight1_triggered(); break;
        case 43: _t->on_actionGoToPacket_triggered(); break;
        case 44: _t->on_actionGoToSetupPacketPlot_triggered(); break;
        case 45: _t->on_actionGoToSetupPacketTree_triggered(); break;
        case 46: _t->on_actionRemoveStream_triggered(); break;
        case 47: _t->on_actionAudioRoutingP_triggered(); break;
        case 48: _t->on_actionAudioRoutingL_triggered(); break;
        case 49: _t->on_actionAudioRoutingLR_triggered(); break;
        case 50: _t->on_actionAudioRoutingR_triggered(); break;
        case 51: _t->on_actionAudioRoutingMute_triggered(); break;
        case 52: _t->on_actionAudioRoutingUnmute_triggered(); break;
        case 53: _t->on_actionAudioRoutingMuteInvert_triggered(); break;
        case 54: _t->on_streamTreeWidget_itemSelectionChanged(); break;
        case 55: _t->on_streamTreeWidget_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 56: _t->on_outputDeviceComboBox_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 57: _t->on_outputAudioRate_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 58: _t->on_jitterSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 59: _t->on_timingComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 60: _t->on_todCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 61: _t->on_buttonBox_helpRequested(); break;
        case 62: _t->on_actionSelectAll_triggered(); break;
        case 63: _t->on_actionSelectInvert_triggered(); break;
        case 64: _t->on_actionSelectNone_triggered(); break;
        case 65: _t->outputNotify(); break;
        case 66: _t->on_actionPlay_triggered(); break;
        case 67: _t->on_actionStop_triggered(); break;
        case 68: _t->on_actionSaveAudioFromCursor_triggered(); break;
        case 69: _t->on_actionSaveAudioSyncStream_triggered(); break;
        case 70: _t->on_actionSaveAudioSyncFile_triggered(); break;
        case 71: _t->on_actionSavePayload_triggered(); break;
        case 72: _t->on_actionSelectInaudible_triggered(); break;
        case 73: _t->on_actionDeselectInaudible_triggered(); break;
        case 74: _t->on_actionPrepareFilter_triggered(); break;
        case 75: _t->on_actionReadCapture_triggered(); break;
        case 76: _t->sinkStateChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QCPAbstractPlottable* >(); break;
            }
            break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< RtpAudioStream* >(); break;
            }
            break;
        case 30:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< AudioRouting >(); break;
            }
            break;
        case 31:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< AudioRouting >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RtpPlayerDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpPlayerDialog::packetsMarked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RtpPlayerDialog::*)(QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpPlayerDialog::updateFilter)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RtpPlayerDialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpPlayerDialog::goToPacket)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (RtpPlayerDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpPlayerDialog::rtpAnalysisDialogReplaceRtpStreams)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (RtpPlayerDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpPlayerDialog::rtpAnalysisDialogAddRtpStreams)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (RtpPlayerDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RtpPlayerDialog::rtpAnalysisDialogRemoveRtpStreams)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<RtpPlayerDialog *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->currentOutputDeviceName(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject RtpPlayerDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<RtpBaseDialog::staticMetaObject>(),
    qt_meta_stringdata_RtpPlayerDialog.offsetsAndSize,
    qt_meta_data_RtpPlayerDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RtpPlayerDialog_t
, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<RtpPlayerDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<CaptureEvent, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QCPAbstractPlottable *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<RtpAudioStream *, std::false_type>, QtPrivate::TypeAndForceComplete<QAudio::Error, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<AudioRouting, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<AudioRouting, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *RtpPlayerDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RtpPlayerDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RtpPlayerDialog.stringdata0))
        return static_cast<void*>(this);
    return RtpBaseDialog::qt_metacast(_clname);
}

int RtpPlayerDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RtpBaseDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 77)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 77;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 77)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 77;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void RtpPlayerDialog::packetsMarked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RtpPlayerDialog::updateFilter(QString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 3
void RtpPlayerDialog::goToPacket(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RtpPlayerDialog::rtpAnalysisDialogReplaceRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RtpPlayerDialog::rtpAnalysisDialogAddRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void RtpPlayerDialog::rtpAnalysisDialogRemoveRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
