/****************************************************************************
** Meta object code from reading C++ file 'io_graph_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/io_graph_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'io_graph_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IOGraph_t {
    const uint offsetsAndSize[24];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_IOGraph_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_IOGraph_t qt_meta_stringdata_IOGraph = {
    {
QT_MOC_LITERAL(0, 7), // "IOGraph"
QT_MOC_LITERAL(8, 13), // "requestReplot"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 13), // "requestRecalc"
QT_MOC_LITERAL(37, 12), // "requestRetap"
QT_MOC_LITERAL(50, 15), // "recalcGraphData"
QT_MOC_LITERAL(66, 13), // "capture_file*"
QT_MOC_LITERAL(80, 8), // "cap_file"
QT_MOC_LITERAL(89, 12), // "captureEvent"
QT_MOC_LITERAL(102, 12), // "CaptureEvent"
QT_MOC_LITERAL(115, 1), // "e"
QT_MOC_LITERAL(117, 20) // "reloadValueUnitField"

    },
    "IOGraph\0requestReplot\0\0requestRecalc\0"
    "requestRetap\0recalcGraphData\0capture_file*\0"
    "cap_file\0captureEvent\0CaptureEvent\0e\0"
    "reloadValueUnitField"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IOGraph[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,
       4,    0,   52,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   53,    2, 0x0a,    4 /* Public */,
       8,    1,   56,    2, 0x0a,    6 /* Public */,
      11,    0,   59,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void IOGraph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IOGraph *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->requestReplot(); break;
        case 1: _t->requestRecalc(); break;
        case 2: _t->requestRetap(); break;
        case 3: _t->recalcGraphData((*reinterpret_cast< std::add_pointer_t<capture_file*>>(_a[1]))); break;
        case 4: _t->captureEvent((*reinterpret_cast< std::add_pointer_t<CaptureEvent>>(_a[1]))); break;
        case 5: _t->reloadValueUnitField(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IOGraph::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IOGraph::requestReplot)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (IOGraph::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IOGraph::requestRecalc)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (IOGraph::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IOGraph::requestRetap)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject IOGraph::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_IOGraph.offsetsAndSize,
    qt_meta_data_IOGraph,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_IOGraph_t
, QtPrivate::TypeAndForceComplete<IOGraph, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_file *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<CaptureEvent, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *IOGraph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IOGraph::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IOGraph.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IOGraph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void IOGraph::requestReplot()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void IOGraph::requestRecalc()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void IOGraph::requestRetap()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_IOGraphDialog_t {
    const uint offsetsAndSize[192];
    char stringdata0[1745];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_IOGraphDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_IOGraphDialog_t qt_meta_stringdata_IOGraphDialog = {
    {
QT_MOC_LITERAL(0, 13), // "IOGraphDialog"
QT_MOC_LITERAL(14, 10), // "goToPacket"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 10), // "packet_num"
QT_MOC_LITERAL(37, 15), // "recalcGraphData"
QT_MOC_LITERAL(53, 13), // "capture_file*"
QT_MOC_LITERAL(67, 8), // "cap_file"
QT_MOC_LITERAL(76, 15), // "intervalChanged"
QT_MOC_LITERAL(92, 8), // "interval"
QT_MOC_LITERAL(101, 21), // "reloadValueUnitFields"
QT_MOC_LITERAL(123, 14), // "scheduleReplot"
QT_MOC_LITERAL(138, 3), // "now"
QT_MOC_LITERAL(142, 14), // "scheduleRecalc"
QT_MOC_LITERAL(157, 13), // "scheduleRetap"
QT_MOC_LITERAL(171, 12), // "reloadFields"
QT_MOC_LITERAL(184, 16), // "modelDataChanged"
QT_MOC_LITERAL(201, 11), // "QModelIndex"
QT_MOC_LITERAL(213, 7), // "topLeft"
QT_MOC_LITERAL(221, 11), // "bottomRight"
QT_MOC_LITERAL(233, 10), // "QList<int>"
QT_MOC_LITERAL(244, 5), // "roles"
QT_MOC_LITERAL(250, 14), // "modelRowsReset"
QT_MOC_LITERAL(265, 17), // "modelRowsInserted"
QT_MOC_LITERAL(283, 6), // "parent"
QT_MOC_LITERAL(290, 5), // "first"
QT_MOC_LITERAL(296, 4), // "last"
QT_MOC_LITERAL(301, 16), // "modelRowsRemoved"
QT_MOC_LITERAL(318, 14), // "modelRowsMoved"
QT_MOC_LITERAL(333, 12), // "sourceParent"
QT_MOC_LITERAL(346, 11), // "sourceStart"
QT_MOC_LITERAL(358, 9), // "sourceEnd"
QT_MOC_LITERAL(368, 17), // "destinationParent"
QT_MOC_LITERAL(386, 14), // "destinationRow"
QT_MOC_LITERAL(401, 12), // "applyChanges"
QT_MOC_LITERAL(414, 15), // "copyFromProfile"
QT_MOC_LITERAL(430, 8), // "filename"
QT_MOC_LITERAL(439, 13), // "updateWidgets"
QT_MOC_LITERAL(453, 15), // "showContextMenu"
QT_MOC_LITERAL(469, 3), // "pos"
QT_MOC_LITERAL(473, 12), // "graphClicked"
QT_MOC_LITERAL(486, 12), // "QMouseEvent*"
QT_MOC_LITERAL(499, 5), // "event"
QT_MOC_LITERAL(505, 10), // "mouseMoved"
QT_MOC_LITERAL(516, 13), // "mouseReleased"
QT_MOC_LITERAL(530, 20), // "selectedFrameChanged"
QT_MOC_LITERAL(551, 6), // "frames"
QT_MOC_LITERAL(558, 10), // "moveLegend"
QT_MOC_LITERAL(569, 9), // "resetAxes"
QT_MOC_LITERAL(579, 16), // "updateStatistics"
QT_MOC_LITERAL(596, 16), // "copyAsCsvClicked"
QT_MOC_LITERAL(613, 24), // "graphUatSelectionChanged"
QT_MOC_LITERAL(638, 14), // "QItemSelection"
QT_MOC_LITERAL(653, 8), // "selected"
QT_MOC_LITERAL(662, 10), // "deselected"
QT_MOC_LITERAL(673, 39), // "on_intervalComboBox_currentIn..."
QT_MOC_LITERAL(713, 5), // "index"
QT_MOC_LITERAL(719, 30), // "on_graphUat_currentItemChanged"
QT_MOC_LITERAL(750, 7), // "current"
QT_MOC_LITERAL(758, 8), // "previous"
QT_MOC_LITERAL(767, 34), // "on_automaticUpdateCheckBox_to..."
QT_MOC_LITERAL(802, 7), // "checked"
QT_MOC_LITERAL(810, 24), // "on_newToolButton_clicked"
QT_MOC_LITERAL(835, 27), // "on_deleteToolButton_clicked"
QT_MOC_LITERAL(863, 25), // "on_copyToolButton_clicked"
QT_MOC_LITERAL(889, 26), // "on_clearToolButton_clicked"
QT_MOC_LITERAL(916, 32), // "on_moveUpwardsToolButton_clicked"
QT_MOC_LITERAL(949, 34), // "on_moveDownwardsToolButton_cl..."
QT_MOC_LITERAL(984, 26), // "on_dragRadioButton_toggled"
QT_MOC_LITERAL(1011, 26), // "on_zoomRadioButton_toggled"
QT_MOC_LITERAL(1038, 24), // "on_actionReset_triggered"
QT_MOC_LITERAL(1063, 25), // "on_actionZoomIn_triggered"
QT_MOC_LITERAL(1089, 26), // "on_actionZoomInX_triggered"
QT_MOC_LITERAL(1116, 26), // "on_actionZoomInY_triggered"
QT_MOC_LITERAL(1143, 26), // "on_actionZoomOut_triggered"
QT_MOC_LITERAL(1170, 27), // "on_actionZoomOutX_triggered"
QT_MOC_LITERAL(1198, 27), // "on_actionZoomOutY_triggered"
QT_MOC_LITERAL(1226, 27), // "on_actionMoveUp10_triggered"
QT_MOC_LITERAL(1254, 29), // "on_actionMoveLeft10_triggered"
QT_MOC_LITERAL(1284, 30), // "on_actionMoveRight10_triggered"
QT_MOC_LITERAL(1315, 29), // "on_actionMoveDown10_triggered"
QT_MOC_LITERAL(1345, 26), // "on_actionMoveUp1_triggered"
QT_MOC_LITERAL(1372, 28), // "on_actionMoveLeft1_triggered"
QT_MOC_LITERAL(1401, 29), // "on_actionMoveRight1_triggered"
QT_MOC_LITERAL(1431, 28), // "on_actionMoveDown1_triggered"
QT_MOC_LITERAL(1460, 29), // "on_actionGoToPacket_triggered"
QT_MOC_LITERAL(1490, 27), // "on_actionDragZoom_triggered"
QT_MOC_LITERAL(1518, 35), // "on_actionToggleTimeOrigin_tri..."
QT_MOC_LITERAL(1554, 29), // "on_actionCrosshairs_triggered"
QT_MOC_LITERAL(1584, 26), // "on_buttonBox_helpRequested"
QT_MOC_LITERAL(1611, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(1633, 16), // "buttonBoxClicked"
QT_MOC_LITERAL(1650, 16), // "QAbstractButton*"
QT_MOC_LITERAL(1667, 6), // "button"
QT_MOC_LITERAL(1674, 21), // "actionLegendTriggered"
QT_MOC_LITERAL(1696, 24), // "actionTimeOfDayTriggered"
QT_MOC_LITERAL(1721, 23) // "actionLogScaleTriggered"

    },
    "IOGraphDialog\0goToPacket\0\0packet_num\0"
    "recalcGraphData\0capture_file*\0cap_file\0"
    "intervalChanged\0interval\0reloadValueUnitFields\0"
    "scheduleReplot\0now\0scheduleRecalc\0"
    "scheduleRetap\0reloadFields\0modelDataChanged\0"
    "QModelIndex\0topLeft\0bottomRight\0"
    "QList<int>\0roles\0modelRowsReset\0"
    "modelRowsInserted\0parent\0first\0last\0"
    "modelRowsRemoved\0modelRowsMoved\0"
    "sourceParent\0sourceStart\0sourceEnd\0"
    "destinationParent\0destinationRow\0"
    "applyChanges\0copyFromProfile\0filename\0"
    "updateWidgets\0showContextMenu\0pos\0"
    "graphClicked\0QMouseEvent*\0event\0"
    "mouseMoved\0mouseReleased\0selectedFrameChanged\0"
    "frames\0moveLegend\0resetAxes\0"
    "updateStatistics\0copyAsCsvClicked\0"
    "graphUatSelectionChanged\0QItemSelection\0"
    "selected\0deselected\0"
    "on_intervalComboBox_currentIndexChanged\0"
    "index\0on_graphUat_currentItemChanged\0"
    "current\0previous\0on_automaticUpdateCheckBox_toggled\0"
    "checked\0on_newToolButton_clicked\0"
    "on_deleteToolButton_clicked\0"
    "on_copyToolButton_clicked\0"
    "on_clearToolButton_clicked\0"
    "on_moveUpwardsToolButton_clicked\0"
    "on_moveDownwardsToolButton_clicked\0"
    "on_dragRadioButton_toggled\0"
    "on_zoomRadioButton_toggled\0"
    "on_actionReset_triggered\0"
    "on_actionZoomIn_triggered\0"
    "on_actionZoomInX_triggered\0"
    "on_actionZoomInY_triggered\0"
    "on_actionZoomOut_triggered\0"
    "on_actionZoomOutX_triggered\0"
    "on_actionZoomOutY_triggered\0"
    "on_actionMoveUp10_triggered\0"
    "on_actionMoveLeft10_triggered\0"
    "on_actionMoveRight10_triggered\0"
    "on_actionMoveDown10_triggered\0"
    "on_actionMoveUp1_triggered\0"
    "on_actionMoveLeft1_triggered\0"
    "on_actionMoveRight1_triggered\0"
    "on_actionMoveDown1_triggered\0"
    "on_actionGoToPacket_triggered\0"
    "on_actionDragZoom_triggered\0"
    "on_actionToggleTimeOrigin_triggered\0"
    "on_actionCrosshairs_triggered\0"
    "on_buttonBox_helpRequested\0"
    "on_buttonBox_accepted\0buttonBoxClicked\0"
    "QAbstractButton*\0button\0actionLegendTriggered\0"
    "actionTimeOfDayTriggered\0"
    "actionLogScaleTriggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IOGraphDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      65,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  404,    2, 0x06,    1 /* Public */,
       4,    1,  407,    2, 0x06,    3 /* Public */,
       7,    1,  410,    2, 0x06,    5 /* Public */,
       9,    0,  413,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    1,  414,    2, 0x0a,    8 /* Public */,
      10,    0,  417,    2, 0x2a,   10 /* Public | MethodCloned */,
      12,    1,  418,    2, 0x0a,   11 /* Public */,
      12,    0,  421,    2, 0x2a,   13 /* Public | MethodCloned */,
      13,    1,  422,    2, 0x0a,   14 /* Public */,
      13,    0,  425,    2, 0x2a,   16 /* Public | MethodCloned */,
      14,    0,  426,    2, 0x0a,   17 /* Public */,
      15,    3,  427,    2, 0x09,   18 /* Protected */,
      21,    0,  434,    2, 0x09,   22 /* Protected */,
      22,    3,  435,    2, 0x09,   23 /* Protected */,
      26,    3,  442,    2, 0x09,   27 /* Protected */,
      27,    5,  449,    2, 0x09,   31 /* Protected */,
      33,    0,  460,    2, 0x08,   37 /* Private */,
      34,    1,  461,    2, 0x08,   38 /* Private */,
      36,    0,  464,    2, 0x08,   40 /* Private */,
      37,    1,  465,    2, 0x08,   41 /* Private */,
      39,    1,  468,    2, 0x08,   43 /* Private */,
      42,    1,  471,    2, 0x08,   45 /* Private */,
      43,    1,  474,    2, 0x08,   47 /* Private */,
      44,    1,  477,    2, 0x08,   49 /* Private */,
      46,    0,  480,    2, 0x08,   51 /* Private */,
      47,    0,  481,    2, 0x08,   52 /* Private */,
      48,    0,  482,    2, 0x08,   53 /* Private */,
      49,    0,  483,    2, 0x08,   54 /* Private */,
      50,    2,  484,    2, 0x08,   55 /* Private */,
      54,    1,  489,    2, 0x08,   58 /* Private */,
      56,    2,  492,    2, 0x08,   60 /* Private */,
      59,    1,  497,    2, 0x08,   63 /* Private */,
      61,    0,  500,    2, 0x08,   65 /* Private */,
      62,    0,  501,    2, 0x08,   66 /* Private */,
      63,    0,  502,    2, 0x08,   67 /* Private */,
      64,    0,  503,    2, 0x08,   68 /* Private */,
      65,    0,  504,    2, 0x08,   69 /* Private */,
      66,    0,  505,    2, 0x08,   70 /* Private */,
      67,    1,  506,    2, 0x08,   71 /* Private */,
      68,    1,  509,    2, 0x08,   73 /* Private */,
      69,    0,  512,    2, 0x08,   75 /* Private */,
      70,    0,  513,    2, 0x08,   76 /* Private */,
      71,    0,  514,    2, 0x08,   77 /* Private */,
      72,    0,  515,    2, 0x08,   78 /* Private */,
      73,    0,  516,    2, 0x08,   79 /* Private */,
      74,    0,  517,    2, 0x08,   80 /* Private */,
      75,    0,  518,    2, 0x08,   81 /* Private */,
      76,    0,  519,    2, 0x08,   82 /* Private */,
      77,    0,  520,    2, 0x08,   83 /* Private */,
      78,    0,  521,    2, 0x08,   84 /* Private */,
      79,    0,  522,    2, 0x08,   85 /* Private */,
      80,    0,  523,    2, 0x08,   86 /* Private */,
      81,    0,  524,    2, 0x08,   87 /* Private */,
      82,    0,  525,    2, 0x08,   88 /* Private */,
      83,    0,  526,    2, 0x08,   89 /* Private */,
      84,    0,  527,    2, 0x08,   90 /* Private */,
      85,    0,  528,    2, 0x08,   91 /* Private */,
      86,    0,  529,    2, 0x08,   92 /* Private */,
      87,    0,  530,    2, 0x08,   93 /* Private */,
      88,    0,  531,    2, 0x08,   94 /* Private */,
      89,    0,  532,    2, 0x08,   95 /* Private */,
      90,    1,  533,    2, 0x08,   96 /* Private */,
      93,    1,  536,    2, 0x08,   98 /* Private */,
      94,    1,  539,    2, 0x08,  100 /* Private */,
      95,    1,  542,    2, 0x08,  102 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 16, 0x80000000 | 19,   17,   18,   20,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16, QMetaType::Int, QMetaType::Int,   23,   24,   25,
    QMetaType::Void, 0x80000000 | 16, QMetaType::Int, QMetaType::Int,   23,   24,   25,
    QMetaType::Void, 0x80000000 | 16, QMetaType::Int, QMetaType::Int, 0x80000000 | 16, QMetaType::Int,   28,   29,   30,   31,   32,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   35,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   38,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, 0x80000000 | 19,   45,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 51, 0x80000000 | 51,   52,   53,
    QMetaType::Void, QMetaType::Int,   55,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 16,   57,   58,
    QMetaType::Void, QMetaType::Bool,   60,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   60,
    QMetaType::Void, QMetaType::Bool,   60,
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
    QMetaType::Void, 0x80000000 | 91,   92,
    QMetaType::Void, QMetaType::Bool,   60,
    QMetaType::Void, QMetaType::Bool,   60,
    QMetaType::Void, QMetaType::Bool,   60,

       0        // eod
};

void IOGraphDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IOGraphDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->goToPacket((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->recalcGraphData((*reinterpret_cast< std::add_pointer_t<capture_file*>>(_a[1]))); break;
        case 2: _t->intervalChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->reloadValueUnitFields(); break;
        case 4: _t->scheduleReplot((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->scheduleReplot(); break;
        case 6: _t->scheduleRecalc((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->scheduleRecalc(); break;
        case 8: _t->scheduleRetap((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->scheduleRetap(); break;
        case 10: _t->reloadFields(); break;
        case 11: _t->modelDataChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[3]))); break;
        case 12: _t->modelRowsReset(); break;
        case 13: _t->modelRowsInserted((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 14: _t->modelRowsRemoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 15: _t->modelRowsMoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 16: _t->applyChanges(); break;
        case 17: _t->copyFromProfile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->updateWidgets(); break;
        case 19: _t->showContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 20: _t->graphClicked((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 21: _t->mouseMoved((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 22: _t->mouseReleased((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 23: _t->selectedFrameChanged((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 24: _t->moveLegend(); break;
        case 25: _t->resetAxes(); break;
        case 26: _t->updateStatistics(); break;
        case 27: _t->copyAsCsvClicked(); break;
        case 28: _t->graphUatSelectionChanged((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[2]))); break;
        case 29: _t->on_intervalComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->on_graphUat_currentItemChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        case 31: _t->on_automaticUpdateCheckBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 32: _t->on_newToolButton_clicked(); break;
        case 33: _t->on_deleteToolButton_clicked(); break;
        case 34: _t->on_copyToolButton_clicked(); break;
        case 35: _t->on_clearToolButton_clicked(); break;
        case 36: _t->on_moveUpwardsToolButton_clicked(); break;
        case 37: _t->on_moveDownwardsToolButton_clicked(); break;
        case 38: _t->on_dragRadioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 39: _t->on_zoomRadioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 40: _t->on_actionReset_triggered(); break;
        case 41: _t->on_actionZoomIn_triggered(); break;
        case 42: _t->on_actionZoomInX_triggered(); break;
        case 43: _t->on_actionZoomInY_triggered(); break;
        case 44: _t->on_actionZoomOut_triggered(); break;
        case 45: _t->on_actionZoomOutX_triggered(); break;
        case 46: _t->on_actionZoomOutY_triggered(); break;
        case 47: _t->on_actionMoveUp10_triggered(); break;
        case 48: _t->on_actionMoveLeft10_triggered(); break;
        case 49: _t->on_actionMoveRight10_triggered(); break;
        case 50: _t->on_actionMoveDown10_triggered(); break;
        case 51: _t->on_actionMoveUp1_triggered(); break;
        case 52: _t->on_actionMoveLeft1_triggered(); break;
        case 53: _t->on_actionMoveRight1_triggered(); break;
        case 54: _t->on_actionMoveDown1_triggered(); break;
        case 55: _t->on_actionGoToPacket_triggered(); break;
        case 56: _t->on_actionDragZoom_triggered(); break;
        case 57: _t->on_actionToggleTimeOrigin_triggered(); break;
        case 58: _t->on_actionCrosshairs_triggered(); break;
        case 59: _t->on_buttonBox_helpRequested(); break;
        case 60: _t->on_buttonBox_accepted(); break;
        case 61: _t->buttonBoxClicked((*reinterpret_cast< std::add_pointer_t<QAbstractButton*>>(_a[1]))); break;
        case 62: _t->actionLegendTriggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 63: _t->actionTimeOfDayTriggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 64: _t->actionLogScaleTriggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 28:
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
            using _t = void (IOGraphDialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IOGraphDialog::goToPacket)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (IOGraphDialog::*)(capture_file * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IOGraphDialog::recalcGraphData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (IOGraphDialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IOGraphDialog::intervalChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (IOGraphDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IOGraphDialog::reloadValueUnitFields)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject IOGraphDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<WiresharkDialog::staticMetaObject>(),
    qt_meta_stringdata_IOGraphDialog.offsetsAndSize,
    qt_meta_data_IOGraphDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_IOGraphDialog_t
, QtPrivate::TypeAndForceComplete<IOGraphDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_file *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<const QVector<int> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>, QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractButton *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *IOGraphDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IOGraphDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IOGraphDialog.stringdata0))
        return static_cast<void*>(this);
    return WiresharkDialog::qt_metacast(_clname);
}

int IOGraphDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WiresharkDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 65)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 65;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 65)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 65;
    }
    return _id;
}

// SIGNAL 0
void IOGraphDialog::goToPacket(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IOGraphDialog::recalcGraphData(capture_file * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void IOGraphDialog::intervalChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IOGraphDialog::reloadValueUnitFields()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
