/****************************************************************************
** Meta object code from reading C++ file 'sequence_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/sequence_dialog.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sequence_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SequenceDialog_t {
    const uint offsetsAndSize[126];
    char stringdata0[1206];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SequenceDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SequenceDialog_t qt_meta_stringdata_SequenceDialog = {
    {
QT_MOC_LITERAL(0, 14), // "SequenceDialog"
QT_MOC_LITERAL(15, 32), // "rtpStreamsDialogSelectRtpStreams"
QT_MOC_LITERAL(48, 0), // ""
QT_MOC_LITERAL(49, 22), // "QList<rtpstream_id_t*>"
QT_MOC_LITERAL(72, 12), // "stream_infos"
QT_MOC_LITERAL(85, 34), // "rtpStreamsDialogDeselectRtpSt..."
QT_MOC_LITERAL(120, 32), // "rtpPlayerDialogReplaceRtpStreams"
QT_MOC_LITERAL(153, 10), // "stream_ids"
QT_MOC_LITERAL(164, 28), // "rtpPlayerDialogAddRtpStreams"
QT_MOC_LITERAL(193, 31), // "rtpPlayerDialogRemoveRtpStreams"
QT_MOC_LITERAL(225, 13), // "updateWidgets"
QT_MOC_LITERAL(239, 17), // "hScrollBarChanged"
QT_MOC_LITERAL(257, 5), // "value"
QT_MOC_LITERAL(263, 17), // "vScrollBarChanged"
QT_MOC_LITERAL(281, 12), // "xAxisChanged"
QT_MOC_LITERAL(294, 8), // "QCPRange"
QT_MOC_LITERAL(303, 5), // "range"
QT_MOC_LITERAL(309, 12), // "yAxisChanged"
QT_MOC_LITERAL(322, 15), // "showContextMenu"
QT_MOC_LITERAL(338, 3), // "pos"
QT_MOC_LITERAL(342, 14), // "diagramClicked"
QT_MOC_LITERAL(357, 12), // "QMouseEvent*"
QT_MOC_LITERAL(370, 5), // "event"
QT_MOC_LITERAL(376, 17), // "axisDoubleClicked"
QT_MOC_LITERAL(394, 8), // "QCPAxis*"
QT_MOC_LITERAL(403, 4), // "axis"
QT_MOC_LITERAL(408, 23), // "QCPAxis::SelectablePart"
QT_MOC_LITERAL(432, 4), // "part"
QT_MOC_LITERAL(437, 13), // "mouseReleased"
QT_MOC_LITERAL(451, 10), // "mouseMoved"
QT_MOC_LITERAL(462, 12), // "mouseWheeled"
QT_MOC_LITERAL(475, 12), // "QWheelEvent*"
QT_MOC_LITERAL(488, 11), // "fillDiagram"
QT_MOC_LITERAL(500, 9), // "resetView"
QT_MOC_LITERAL(510, 13), // "exportDiagram"
QT_MOC_LITERAL(524, 16), // "layoutAxisLabels"
QT_MOC_LITERAL(541, 14), // "addressChanged"
QT_MOC_LITERAL(556, 5), // "index"
QT_MOC_LITERAL(562, 28), // "displayFilterCheckBoxToggled"
QT_MOC_LITERAL(591, 7), // "checked"
QT_MOC_LITERAL(599, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(620, 16), // "QAbstractButton*"
QT_MOC_LITERAL(637, 6), // "button"
QT_MOC_LITERAL(644, 29), // "on_actionGoToPacket_triggered"
QT_MOC_LITERAL(674, 33), // "on_actionGoToNextPacket_trigg..."
QT_MOC_LITERAL(708, 37), // "on_actionGoToPreviousPacket_t..."
QT_MOC_LITERAL(746, 25), // "on_flowComboBox_activated"
QT_MOC_LITERAL(772, 30), // "on_actionMoveRight10_triggered"
QT_MOC_LITERAL(803, 29), // "on_actionMoveLeft10_triggered"
QT_MOC_LITERAL(833, 27), // "on_actionMoveUp10_triggered"
QT_MOC_LITERAL(861, 29), // "on_actionMoveDown10_triggered"
QT_MOC_LITERAL(891, 29), // "on_actionMoveRight1_triggered"
QT_MOC_LITERAL(921, 28), // "on_actionMoveLeft1_triggered"
QT_MOC_LITERAL(950, 26), // "on_actionMoveUp1_triggered"
QT_MOC_LITERAL(977, 28), // "on_actionMoveDown1_triggered"
QT_MOC_LITERAL(1006, 25), // "on_actionZoomIn_triggered"
QT_MOC_LITERAL(1032, 26), // "on_actionZoomOut_triggered"
QT_MOC_LITERAL(1059, 35), // "on_actionSelectRtpStreams_tri..."
QT_MOC_LITERAL(1095, 37), // "on_actionDeselectRtpStreams_t..."
QT_MOC_LITERAL(1133, 26), // "on_buttonBox_helpRequested"
QT_MOC_LITERAL(1160, 16), // "rtpPlayerReplace"
QT_MOC_LITERAL(1177, 12), // "rtpPlayerAdd"
QT_MOC_LITERAL(1190, 15) // "rtpPlayerRemove"

    },
    "SequenceDialog\0rtpStreamsDialogSelectRtpStreams\0"
    "\0QList<rtpstream_id_t*>\0stream_infos\0"
    "rtpStreamsDialogDeselectRtpStreams\0"
    "rtpPlayerDialogReplaceRtpStreams\0"
    "stream_ids\0rtpPlayerDialogAddRtpStreams\0"
    "rtpPlayerDialogRemoveRtpStreams\0"
    "updateWidgets\0hScrollBarChanged\0value\0"
    "vScrollBarChanged\0xAxisChanged\0QCPRange\0"
    "range\0yAxisChanged\0showContextMenu\0"
    "pos\0diagramClicked\0QMouseEvent*\0event\0"
    "axisDoubleClicked\0QCPAxis*\0axis\0"
    "QCPAxis::SelectablePart\0part\0mouseReleased\0"
    "mouseMoved\0mouseWheeled\0QWheelEvent*\0"
    "fillDiagram\0resetView\0exportDiagram\0"
    "layoutAxisLabels\0addressChanged\0index\0"
    "displayFilterCheckBoxToggled\0checked\0"
    "on_buttonBox_clicked\0QAbstractButton*\0"
    "button\0on_actionGoToPacket_triggered\0"
    "on_actionGoToNextPacket_triggered\0"
    "on_actionGoToPreviousPacket_triggered\0"
    "on_flowComboBox_activated\0"
    "on_actionMoveRight10_triggered\0"
    "on_actionMoveLeft10_triggered\0"
    "on_actionMoveUp10_triggered\0"
    "on_actionMoveDown10_triggered\0"
    "on_actionMoveRight1_triggered\0"
    "on_actionMoveLeft1_triggered\0"
    "on_actionMoveUp1_triggered\0"
    "on_actionMoveDown1_triggered\0"
    "on_actionZoomIn_triggered\0"
    "on_actionZoomOut_triggered\0"
    "on_actionSelectRtpStreams_triggered\0"
    "on_actionDeselectRtpStreams_triggered\0"
    "on_buttonBox_helpRequested\0rtpPlayerReplace\0"
    "rtpPlayerAdd\0rtpPlayerRemove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SequenceDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      43,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  272,    2, 0x06,    1 /* Public */,
       5,    1,  275,    2, 0x06,    3 /* Public */,
       6,    1,  278,    2, 0x06,    5 /* Public */,
       8,    1,  281,    2, 0x06,    7 /* Public */,
       9,    1,  284,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,  287,    2, 0x08,   11 /* Private */,
      11,    1,  288,    2, 0x08,   12 /* Private */,
      13,    1,  291,    2, 0x08,   14 /* Private */,
      14,    1,  294,    2, 0x08,   16 /* Private */,
      17,    1,  297,    2, 0x08,   18 /* Private */,
      18,    1,  300,    2, 0x08,   20 /* Private */,
      20,    1,  303,    2, 0x08,   22 /* Private */,
      23,    3,  306,    2, 0x08,   24 /* Private */,
      28,    1,  313,    2, 0x08,   28 /* Private */,
      29,    1,  316,    2, 0x08,   30 /* Private */,
      30,    1,  319,    2, 0x08,   32 /* Private */,
      32,    0,  322,    2, 0x08,   34 /* Private */,
      33,    0,  323,    2, 0x08,   35 /* Private */,
      34,    0,  324,    2, 0x08,   36 /* Private */,
      35,    0,  325,    2, 0x08,   37 /* Private */,
      36,    1,  326,    2, 0x08,   38 /* Private */,
      38,    1,  329,    2, 0x08,   40 /* Private */,
      40,    1,  332,    2, 0x08,   42 /* Private */,
      43,    0,  335,    2, 0x08,   44 /* Private */,
      44,    0,  336,    2, 0x08,   45 /* Private */,
      45,    0,  337,    2, 0x08,   46 /* Private */,
      46,    1,  338,    2, 0x08,   47 /* Private */,
      47,    0,  341,    2, 0x08,   49 /* Private */,
      48,    0,  342,    2, 0x08,   50 /* Private */,
      49,    0,  343,    2, 0x08,   51 /* Private */,
      50,    0,  344,    2, 0x08,   52 /* Private */,
      51,    0,  345,    2, 0x08,   53 /* Private */,
      52,    0,  346,    2, 0x08,   54 /* Private */,
      53,    0,  347,    2, 0x08,   55 /* Private */,
      54,    0,  348,    2, 0x08,   56 /* Private */,
      55,    0,  349,    2, 0x08,   57 /* Private */,
      56,    0,  350,    2, 0x08,   58 /* Private */,
      57,    0,  351,    2, 0x08,   59 /* Private */,
      58,    0,  352,    2, 0x08,   60 /* Private */,
      59,    0,  353,    2, 0x08,   61 /* Private */,
      60,    0,  354,    2, 0x08,   62 /* Private */,
      61,    0,  355,    2, 0x08,   63 /* Private */,
      62,    0,  356,    2, 0x08,   64 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    7,
    QMetaType::Void, 0x80000000 | 3,    7,
    QMetaType::Void, 0x80000000 | 3,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::QPoint,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 24, 0x80000000 | 26, 0x80000000 | 21,   25,   27,   22,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, 0x80000000 | 31,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void, 0x80000000 | 41,   42,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,
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

void SequenceDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SequenceDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->rtpStreamsDialogSelectRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 1: _t->rtpStreamsDialogDeselectRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 2: _t->rtpPlayerDialogReplaceRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 3: _t->rtpPlayerDialogAddRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 4: _t->rtpPlayerDialogRemoveRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 5: _t->updateWidgets(); break;
        case 6: _t->hScrollBarChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->vScrollBarChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->xAxisChanged((*reinterpret_cast< std::add_pointer_t<QCPRange>>(_a[1]))); break;
        case 9: _t->yAxisChanged((*reinterpret_cast< std::add_pointer_t<QCPRange>>(_a[1]))); break;
        case 10: _t->showContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 11: _t->diagramClicked((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 12: _t->axisDoubleClicked((*reinterpret_cast< std::add_pointer_t<QCPAxis*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QCPAxis::SelectablePart>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[3]))); break;
        case 13: _t->mouseReleased((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 14: _t->mouseMoved((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 15: _t->mouseWheeled((*reinterpret_cast< std::add_pointer_t<QWheelEvent*>>(_a[1]))); break;
        case 16: _t->fillDiagram(); break;
        case 17: _t->resetView(); break;
        case 18: _t->exportDiagram(); break;
        case 19: _t->layoutAxisLabels(); break;
        case 20: _t->addressChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->displayFilterCheckBoxToggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 22: _t->on_buttonBox_clicked((*reinterpret_cast< std::add_pointer_t<QAbstractButton*>>(_a[1]))); break;
        case 23: _t->on_actionGoToPacket_triggered(); break;
        case 24: _t->on_actionGoToNextPacket_triggered(); break;
        case 25: _t->on_actionGoToPreviousPacket_triggered(); break;
        case 26: _t->on_flowComboBox_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->on_actionMoveRight10_triggered(); break;
        case 28: _t->on_actionMoveLeft10_triggered(); break;
        case 29: _t->on_actionMoveUp10_triggered(); break;
        case 30: _t->on_actionMoveDown10_triggered(); break;
        case 31: _t->on_actionMoveRight1_triggered(); break;
        case 32: _t->on_actionMoveLeft1_triggered(); break;
        case 33: _t->on_actionMoveUp1_triggered(); break;
        case 34: _t->on_actionMoveDown1_triggered(); break;
        case 35: _t->on_actionZoomIn_triggered(); break;
        case 36: _t->on_actionZoomOut_triggered(); break;
        case 37: _t->on_actionSelectRtpStreams_triggered(); break;
        case 38: _t->on_actionDeselectRtpStreams_triggered(); break;
        case 39: _t->on_buttonBox_helpRequested(); break;
        case 40: _t->rtpPlayerReplace(); break;
        case 41: _t->rtpPlayerAdd(); break;
        case 42: _t->rtpPlayerRemove(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QCPAxis* >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QCPAxis::SelectablePart >(); break;
            }
            break;
        case 22:
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
            using _t = void (SequenceDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SequenceDialog::rtpStreamsDialogSelectRtpStreams)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SequenceDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SequenceDialog::rtpStreamsDialogDeselectRtpStreams)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SequenceDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SequenceDialog::rtpPlayerDialogReplaceRtpStreams)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SequenceDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SequenceDialog::rtpPlayerDialogAddRtpStreams)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SequenceDialog::*)(QVector<rtpstream_id_t*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SequenceDialog::rtpPlayerDialogRemoveRtpStreams)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject SequenceDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<WiresharkDialog::staticMetaObject>(),
    qt_meta_stringdata_SequenceDialog.offsetsAndSize,
    qt_meta_data_SequenceDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SequenceDialog_t
, QtPrivate::TypeAndForceComplete<SequenceDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QCPRange, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QCPRange, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QCPAxis *, std::false_type>, QtPrivate::TypeAndForceComplete<QCPAxis::SelectablePart, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QWheelEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractButton *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *SequenceDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SequenceDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SequenceDialog.stringdata0))
        return static_cast<void*>(this);
    return WiresharkDialog::qt_metacast(_clname);
}

int SequenceDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WiresharkDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
    }
    return _id;
}

// SIGNAL 0
void SequenceDialog::rtpStreamsDialogSelectRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SequenceDialog::rtpStreamsDialogDeselectRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SequenceDialog::rtpPlayerDialogReplaceRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SequenceDialog::rtpPlayerDialogAddRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SequenceDialog::rtpPlayerDialogRemoveRtpStreams(QVector<rtpstream_id_t*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
