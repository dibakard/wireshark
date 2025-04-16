/****************************************************************************
** Meta object code from reading C++ file 'tcp_stream_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/tcp_stream_dialog.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcp_stream_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QCPErrorBarsNotSelectable_t {
    const uint offsetsAndSize[2];
    char stringdata0[26];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_QCPErrorBarsNotSelectable_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_QCPErrorBarsNotSelectable_t qt_meta_stringdata_QCPErrorBarsNotSelectable = {
    {
QT_MOC_LITERAL(0, 25) // "QCPErrorBarsNotSelectable"

    },
    "QCPErrorBarsNotSelectable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCPErrorBarsNotSelectable[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void QCPErrorBarsNotSelectable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject QCPErrorBarsNotSelectable::staticMetaObject = { {
    QMetaObject::SuperData::link<QCPErrorBars::staticMetaObject>(),
    qt_meta_stringdata_QCPErrorBarsNotSelectable.offsetsAndSize,
    qt_meta_data_QCPErrorBarsNotSelectable,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_QCPErrorBarsNotSelectable_t
, QtPrivate::TypeAndForceComplete<QCPErrorBarsNotSelectable, std::true_type>



>,
    nullptr
} };


const QMetaObject *QCPErrorBarsNotSelectable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCPErrorBarsNotSelectable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QCPErrorBarsNotSelectable.stringdata0))
        return static_cast<void*>(this);
    return QCPErrorBars::qt_metacast(_clname);
}

int QCPErrorBarsNotSelectable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCPErrorBars::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_TCPStreamDialog_t {
    const uint offsetsAndSize[148];
    char stringdata0[1747];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TCPStreamDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TCPStreamDialog_t qt_meta_stringdata_TCPStreamDialog = {
    {
QT_MOC_LITERAL(0, 15), // "TCPStreamDialog"
QT_MOC_LITERAL(16, 10), // "goToPacket"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 10), // "packet_num"
QT_MOC_LITERAL(39, 11), // "updateGraph"
QT_MOC_LITERAL(51, 15), // "showContextMenu"
QT_MOC_LITERAL(67, 3), // "pos"
QT_MOC_LITERAL(71, 12), // "graphClicked"
QT_MOC_LITERAL(84, 12), // "QMouseEvent*"
QT_MOC_LITERAL(97, 5), // "event"
QT_MOC_LITERAL(103, 11), // "axisClicked"
QT_MOC_LITERAL(115, 8), // "QCPAxis*"
QT_MOC_LITERAL(124, 4), // "axis"
QT_MOC_LITERAL(129, 23), // "QCPAxis::SelectablePart"
QT_MOC_LITERAL(153, 4), // "part"
QT_MOC_LITERAL(158, 10), // "mouseMoved"
QT_MOC_LITERAL(169, 13), // "mouseReleased"
QT_MOC_LITERAL(183, 12), // "captureEvent"
QT_MOC_LITERAL(196, 12), // "CaptureEvent"
QT_MOC_LITERAL(209, 1), // "e"
QT_MOC_LITERAL(211, 15), // "transformYRange"
QT_MOC_LITERAL(227, 8), // "QCPRange"
QT_MOC_LITERAL(236, 8), // "y_range1"
QT_MOC_LITERAL(245, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(267, 40), // "on_graphTypeComboBox_currentI..."
QT_MOC_LITERAL(308, 5), // "index"
QT_MOC_LITERAL(314, 22), // "on_resetButton_clicked"
QT_MOC_LITERAL(337, 35), // "on_streamNumberSpinBox_valueC..."
QT_MOC_LITERAL(373, 10), // "new_stream"
QT_MOC_LITERAL(384, 38), // "on_streamNumberSpinBox_editin..."
QT_MOC_LITERAL(423, 35), // "on_maWindowSizeSpinBox_valueC..."
QT_MOC_LITERAL(459, 11), // "new_ma_size"
QT_MOC_LITERAL(471, 38), // "on_maWindowSizeSpinBox_editin..."
QT_MOC_LITERAL(510, 35), // "on_selectSACKsCheckBox_stateC..."
QT_MOC_LITERAL(546, 5), // "state"
QT_MOC_LITERAL(552, 31), // "on_otherDirectionButton_clicked"
QT_MOC_LITERAL(584, 26), // "on_dragRadioButton_toggled"
QT_MOC_LITERAL(611, 7), // "checked"
QT_MOC_LITERAL(619, 26), // "on_zoomRadioButton_toggled"
QT_MOC_LITERAL(646, 35), // "on_bySeqNumberCheckBox_stateC..."
QT_MOC_LITERAL(682, 45), // "on_samplingMethodComboBox_cur..."
QT_MOC_LITERAL(728, 37), // "on_showSegLengthCheckBox_stat..."
QT_MOC_LITERAL(766, 38), // "on_showThroughputCheckBox_sta..."
QT_MOC_LITERAL(805, 35), // "on_showGoodputCheckBox_stateC..."
QT_MOC_LITERAL(841, 34), // "on_showRcvWinCheckBox_stateCh..."
QT_MOC_LITERAL(876, 36), // "on_showBytesOutCheckBox_state..."
QT_MOC_LITERAL(913, 25), // "on_actionZoomIn_triggered"
QT_MOC_LITERAL(939, 26), // "on_actionZoomInX_triggered"
QT_MOC_LITERAL(966, 26), // "on_actionZoomInY_triggered"
QT_MOC_LITERAL(993, 26), // "on_actionZoomOut_triggered"
QT_MOC_LITERAL(1020, 27), // "on_actionZoomOutX_triggered"
QT_MOC_LITERAL(1048, 27), // "on_actionZoomOutY_triggered"
QT_MOC_LITERAL(1076, 24), // "on_actionReset_triggered"
QT_MOC_LITERAL(1101, 30), // "on_actionMoveRight10_triggered"
QT_MOC_LITERAL(1132, 29), // "on_actionMoveLeft10_triggered"
QT_MOC_LITERAL(1162, 27), // "on_actionMoveUp10_triggered"
QT_MOC_LITERAL(1190, 29), // "on_actionMoveDown10_triggered"
QT_MOC_LITERAL(1220, 29), // "on_actionMoveRight1_triggered"
QT_MOC_LITERAL(1250, 28), // "on_actionMoveLeft1_triggered"
QT_MOC_LITERAL(1279, 26), // "on_actionMoveUp1_triggered"
QT_MOC_LITERAL(1306, 28), // "on_actionMoveDown1_triggered"
QT_MOC_LITERAL(1335, 29), // "on_actionNextStream_triggered"
QT_MOC_LITERAL(1365, 33), // "on_actionPreviousStream_trigg..."
QT_MOC_LITERAL(1399, 34), // "on_actionSwitchDirection_trig..."
QT_MOC_LITERAL(1434, 29), // "on_actionGoToPacket_triggered"
QT_MOC_LITERAL(1464, 27), // "on_actionDragZoom_triggered"
QT_MOC_LITERAL(1492, 40), // "on_actionToggleSequenceNumber..."
QT_MOC_LITERAL(1533, 35), // "on_actionToggleTimeOrigin_tri..."
QT_MOC_LITERAL(1569, 32), // "on_actionRoundTripTime_triggered"
QT_MOC_LITERAL(1602, 29), // "on_actionThroughput_triggered"
QT_MOC_LITERAL(1632, 26), // "on_actionStevens_triggered"
QT_MOC_LITERAL(1659, 27), // "on_actionTcptrace_triggered"
QT_MOC_LITERAL(1687, 32), // "on_actionWindowScaling_triggered"
QT_MOC_LITERAL(1720, 26) // "on_buttonBox_helpRequested"

    },
    "TCPStreamDialog\0goToPacket\0\0packet_num\0"
    "updateGraph\0showContextMenu\0pos\0"
    "graphClicked\0QMouseEvent*\0event\0"
    "axisClicked\0QCPAxis*\0axis\0"
    "QCPAxis::SelectablePart\0part\0mouseMoved\0"
    "mouseReleased\0captureEvent\0CaptureEvent\0"
    "e\0transformYRange\0QCPRange\0y_range1\0"
    "on_buttonBox_accepted\0"
    "on_graphTypeComboBox_currentIndexChanged\0"
    "index\0on_resetButton_clicked\0"
    "on_streamNumberSpinBox_valueChanged\0"
    "new_stream\0on_streamNumberSpinBox_editingFinished\0"
    "on_maWindowSizeSpinBox_valueChanged\0"
    "new_ma_size\0on_maWindowSizeSpinBox_editingFinished\0"
    "on_selectSACKsCheckBox_stateChanged\0"
    "state\0on_otherDirectionButton_clicked\0"
    "on_dragRadioButton_toggled\0checked\0"
    "on_zoomRadioButton_toggled\0"
    "on_bySeqNumberCheckBox_stateChanged\0"
    "on_samplingMethodComboBox_currentIndexChanged\0"
    "on_showSegLengthCheckBox_stateChanged\0"
    "on_showThroughputCheckBox_stateChanged\0"
    "on_showGoodputCheckBox_stateChanged\0"
    "on_showRcvWinCheckBox_stateChanged\0"
    "on_showBytesOutCheckBox_stateChanged\0"
    "on_actionZoomIn_triggered\0"
    "on_actionZoomInX_triggered\0"
    "on_actionZoomInY_triggered\0"
    "on_actionZoomOut_triggered\0"
    "on_actionZoomOutX_triggered\0"
    "on_actionZoomOutY_triggered\0"
    "on_actionReset_triggered\0"
    "on_actionMoveRight10_triggered\0"
    "on_actionMoveLeft10_triggered\0"
    "on_actionMoveUp10_triggered\0"
    "on_actionMoveDown10_triggered\0"
    "on_actionMoveRight1_triggered\0"
    "on_actionMoveLeft1_triggered\0"
    "on_actionMoveUp1_triggered\0"
    "on_actionMoveDown1_triggered\0"
    "on_actionNextStream_triggered\0"
    "on_actionPreviousStream_triggered\0"
    "on_actionSwitchDirection_triggered\0"
    "on_actionGoToPacket_triggered\0"
    "on_actionDragZoom_triggered\0"
    "on_actionToggleSequenceNumbers_triggered\0"
    "on_actionToggleTimeOrigin_triggered\0"
    "on_actionRoundTripTime_triggered\0"
    "on_actionThroughput_triggered\0"
    "on_actionStevens_triggered\0"
    "on_actionTcptrace_triggered\0"
    "on_actionWindowScaling_triggered\0"
    "on_buttonBox_helpRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TCPStreamDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      55,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  344,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,  347,    2, 0x0a,    3 /* Public */,
       5,    1,  348,    2, 0x08,    4 /* Private */,
       7,    1,  351,    2, 0x08,    6 /* Private */,
      10,    3,  354,    2, 0x08,    8 /* Private */,
      15,    1,  361,    2, 0x08,   12 /* Private */,
      16,    1,  364,    2, 0x08,   14 /* Private */,
      17,    1,  367,    2, 0x08,   16 /* Private */,
      20,    1,  370,    2, 0x08,   18 /* Private */,
      23,    0,  373,    2, 0x08,   20 /* Private */,
      24,    1,  374,    2, 0x08,   21 /* Private */,
      26,    0,  377,    2, 0x08,   23 /* Private */,
      27,    1,  378,    2, 0x08,   24 /* Private */,
      29,    0,  381,    2, 0x08,   26 /* Private */,
      30,    1,  382,    2, 0x08,   27 /* Private */,
      32,    0,  385,    2, 0x08,   29 /* Private */,
      33,    1,  386,    2, 0x08,   30 /* Private */,
      35,    0,  389,    2, 0x08,   32 /* Private */,
      36,    1,  390,    2, 0x08,   33 /* Private */,
      38,    1,  393,    2, 0x08,   35 /* Private */,
      39,    1,  396,    2, 0x08,   37 /* Private */,
      40,    1,  399,    2, 0x08,   39 /* Private */,
      41,    1,  402,    2, 0x08,   41 /* Private */,
      42,    1,  405,    2, 0x08,   43 /* Private */,
      43,    1,  408,    2, 0x08,   45 /* Private */,
      44,    1,  411,    2, 0x08,   47 /* Private */,
      45,    1,  414,    2, 0x08,   49 /* Private */,
      46,    0,  417,    2, 0x08,   51 /* Private */,
      47,    0,  418,    2, 0x08,   52 /* Private */,
      48,    0,  419,    2, 0x08,   53 /* Private */,
      49,    0,  420,    2, 0x08,   54 /* Private */,
      50,    0,  421,    2, 0x08,   55 /* Private */,
      51,    0,  422,    2, 0x08,   56 /* Private */,
      52,    0,  423,    2, 0x08,   57 /* Private */,
      53,    0,  424,    2, 0x08,   58 /* Private */,
      54,    0,  425,    2, 0x08,   59 /* Private */,
      55,    0,  426,    2, 0x08,   60 /* Private */,
      56,    0,  427,    2, 0x08,   61 /* Private */,
      57,    0,  428,    2, 0x08,   62 /* Private */,
      58,    0,  429,    2, 0x08,   63 /* Private */,
      59,    0,  430,    2, 0x08,   64 /* Private */,
      60,    0,  431,    2, 0x08,   65 /* Private */,
      61,    0,  432,    2, 0x08,   66 /* Private */,
      62,    0,  433,    2, 0x08,   67 /* Private */,
      63,    0,  434,    2, 0x08,   68 /* Private */,
      64,    0,  435,    2, 0x08,   69 /* Private */,
      65,    0,  436,    2, 0x08,   70 /* Private */,
      66,    0,  437,    2, 0x08,   71 /* Private */,
      67,    0,  438,    2, 0x08,   72 /* Private */,
      68,    0,  439,    2, 0x08,   73 /* Private */,
      69,    0,  440,    2, 0x08,   74 /* Private */,
      70,    0,  441,    2, 0x08,   75 /* Private */,
      71,    0,  442,    2, 0x08,   76 /* Private */,
      72,    0,  443,    2, 0x08,   77 /* Private */,
      73,    0,  444,    2, 0x08,   78 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 13, 0x80000000 | 8,   12,   14,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   31,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   37,
    QMetaType::Void, QMetaType::Bool,   37,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void, QMetaType::Int,   34,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TCPStreamDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TCPStreamDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->goToPacket((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->updateGraph(); break;
        case 2: _t->showContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 3: _t->graphClicked((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 4: _t->axisClicked((*reinterpret_cast< std::add_pointer_t<QCPAxis*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QCPAxis::SelectablePart>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[3]))); break;
        case 5: _t->mouseMoved((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 6: _t->mouseReleased((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 7: _t->captureEvent((*reinterpret_cast< std::add_pointer_t<CaptureEvent>>(_a[1]))); break;
        case 8: _t->transformYRange((*reinterpret_cast< std::add_pointer_t<QCPRange>>(_a[1]))); break;
        case 9: _t->on_buttonBox_accepted(); break;
        case 10: _t->on_graphTypeComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_resetButton_clicked(); break;
        case 12: _t->on_streamNumberSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->on_streamNumberSpinBox_editingFinished(); break;
        case 14: _t->on_maWindowSizeSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 15: _t->on_maWindowSizeSpinBox_editingFinished(); break;
        case 16: _t->on_selectSACKsCheckBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->on_otherDirectionButton_clicked(); break;
        case 18: _t->on_dragRadioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 19: _t->on_zoomRadioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->on_bySeqNumberCheckBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->on_samplingMethodComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->on_showSegLengthCheckBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->on_showThroughputCheckBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->on_showGoodputCheckBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->on_showRcvWinCheckBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->on_showBytesOutCheckBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->on_actionZoomIn_triggered(); break;
        case 28: _t->on_actionZoomInX_triggered(); break;
        case 29: _t->on_actionZoomInY_triggered(); break;
        case 30: _t->on_actionZoomOut_triggered(); break;
        case 31: _t->on_actionZoomOutX_triggered(); break;
        case 32: _t->on_actionZoomOutY_triggered(); break;
        case 33: _t->on_actionReset_triggered(); break;
        case 34: _t->on_actionMoveRight10_triggered(); break;
        case 35: _t->on_actionMoveLeft10_triggered(); break;
        case 36: _t->on_actionMoveUp10_triggered(); break;
        case 37: _t->on_actionMoveDown10_triggered(); break;
        case 38: _t->on_actionMoveRight1_triggered(); break;
        case 39: _t->on_actionMoveLeft1_triggered(); break;
        case 40: _t->on_actionMoveUp1_triggered(); break;
        case 41: _t->on_actionMoveDown1_triggered(); break;
        case 42: _t->on_actionNextStream_triggered(); break;
        case 43: _t->on_actionPreviousStream_triggered(); break;
        case 44: _t->on_actionSwitchDirection_triggered(); break;
        case 45: _t->on_actionGoToPacket_triggered(); break;
        case 46: _t->on_actionDragZoom_triggered(); break;
        case 47: _t->on_actionToggleSequenceNumbers_triggered(); break;
        case 48: _t->on_actionToggleTimeOrigin_triggered(); break;
        case 49: _t->on_actionRoundTripTime_triggered(); break;
        case 50: _t->on_actionThroughput_triggered(); break;
        case 51: _t->on_actionStevens_triggered(); break;
        case 52: _t->on_actionTcptrace_triggered(); break;
        case 53: _t->on_actionWindowScaling_triggered(); break;
        case 54: _t->on_buttonBox_helpRequested(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QCPAxis* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QCPAxis::SelectablePart >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TCPStreamDialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPStreamDialog::goToPacket)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TCPStreamDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<GeometryStateDialog::staticMetaObject>(),
    qt_meta_stringdata_TCPStreamDialog.offsetsAndSize,
    qt_meta_data_TCPStreamDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TCPStreamDialog_t
, QtPrivate::TypeAndForceComplete<TCPStreamDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QCPAxis *, std::false_type>, QtPrivate::TypeAndForceComplete<QCPAxis::SelectablePart, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<CaptureEvent, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QCPRange &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TCPStreamDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCPStreamDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TCPStreamDialog.stringdata0))
        return static_cast<void*>(this);
    return GeometryStateDialog::qt_metacast(_clname);
}

int TCPStreamDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GeometryStateDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
    }
    return _id;
}

// SIGNAL 0
void TCPStreamDialog::goToPacket(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
