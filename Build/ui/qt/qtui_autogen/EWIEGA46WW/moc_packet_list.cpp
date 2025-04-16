/****************************************************************************
** Meta object code from reading C++ file 'packet_list.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/packet_list.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'packet_list.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PacketList_t {
    const uint offsetsAndSize[162];
    char stringdata0[1107];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PacketList_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PacketList_t qt_meta_stringdata_PacketList = {
    {
QT_MOC_LITERAL(0, 10), // "PacketList"
QT_MOC_LITERAL(11, 23), // "packetDissectionChanged"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 21), // "showColumnPreferences"
QT_MOC_LITERAL(58, 9), // "pane_name"
QT_MOC_LITERAL(68, 10), // "editColumn"
QT_MOC_LITERAL(79, 6), // "column"
QT_MOC_LITERAL(86, 18), // "packetListScrolled"
QT_MOC_LITERAL(105, 6), // "at_end"
QT_MOC_LITERAL(112, 23), // "showProtocolPreferences"
QT_MOC_LITERAL(136, 11), // "module_name"
QT_MOC_LITERAL(148, 22), // "editProtocolPreference"
QT_MOC_LITERAL(171, 7), // "pref_t*"
QT_MOC_LITERAL(179, 4), // "pref"
QT_MOC_LITERAL(184, 9), // "module_t*"
QT_MOC_LITERAL(194, 6), // "module"
QT_MOC_LITERAL(201, 14), // "framesSelected"
QT_MOC_LITERAL(216, 10), // "QList<int>"
QT_MOC_LITERAL(227, 13), // "fieldSelected"
QT_MOC_LITERAL(241, 17), // "FieldInformation*"
QT_MOC_LITERAL(259, 12), // "rowsInserted"
QT_MOC_LITERAL(272, 11), // "QModelIndex"
QT_MOC_LITERAL(284, 6), // "parent"
QT_MOC_LITERAL(291, 5), // "start"
QT_MOC_LITERAL(297, 3), // "end"
QT_MOC_LITERAL(301, 7), // "drawRow"
QT_MOC_LITERAL(309, 9), // "QPainter*"
QT_MOC_LITERAL(319, 7), // "painter"
QT_MOC_LITERAL(327, 20), // "QStyleOptionViewItem"
QT_MOC_LITERAL(348, 6), // "option"
QT_MOC_LITERAL(355, 5), // "index"
QT_MOC_LITERAL(361, 14), // "setCaptureFile"
QT_MOC_LITERAL(376, 13), // "capture_file*"
QT_MOC_LITERAL(390, 2), // "cf"
QT_MOC_LITERAL(393, 16), // "setMonospaceFont"
QT_MOC_LITERAL(410, 9), // "mono_font"
QT_MOC_LITERAL(420, 14), // "setRegularFont"
QT_MOC_LITERAL(435, 12), // "regular_font"
QT_MOC_LITERAL(448, 12), // "goNextPacket"
QT_MOC_LITERAL(461, 16), // "goPreviousPacket"
QT_MOC_LITERAL(478, 13), // "goFirstPacket"
QT_MOC_LITERAL(492, 12), // "goLastPacket"
QT_MOC_LITERAL(505, 10), // "goToPacket"
QT_MOC_LITERAL(516, 6), // "packet"
QT_MOC_LITERAL(523, 5), // "hf_id"
QT_MOC_LITERAL(529, 19), // "goNextHistoryPacket"
QT_MOC_LITERAL(549, 23), // "goPreviousHistoryPacket"
QT_MOC_LITERAL(573, 9), // "markFrame"
QT_MOC_LITERAL(583, 22), // "markAllDisplayedFrames"
QT_MOC_LITERAL(606, 3), // "set"
QT_MOC_LITERAL(610, 11), // "ignoreFrame"
QT_MOC_LITERAL(622, 24), // "ignoreAllDisplayedFrames"
QT_MOC_LITERAL(647, 16), // "setTimeReference"
QT_MOC_LITERAL(664, 22), // "unsetAllTimeReferences"
QT_MOC_LITERAL(687, 14), // "applyTimeShift"
QT_MOC_LITERAL(702, 14), // "recolorPackets"
QT_MOC_LITERAL(717, 20), // "redrawVisiblePackets"
QT_MOC_LITERAL(738, 37), // "redrawVisiblePacketsDontSelec..."
QT_MOC_LITERAL(776, 13), // "colorsChanged"
QT_MOC_LITERAL(790, 14), // "columnsChanged"
QT_MOC_LITERAL(805, 13), // "fieldsChanged"
QT_MOC_LITERAL(819, 18), // "preferencesChanged"
QT_MOC_LITERAL(838, 16), // "freezePacketList"
QT_MOC_LITERAL(855, 16), // "changing_profile"
QT_MOC_LITERAL(872, 25), // "columnVisibilityTriggered"
QT_MOC_LITERAL(898, 14), // "sectionResized"
QT_MOC_LITERAL(913, 3), // "col"
QT_MOC_LITERAL(917, 9), // "new_width"
QT_MOC_LITERAL(927, 12), // "sectionMoved"
QT_MOC_LITERAL(940, 11), // "copySummary"
QT_MOC_LITERAL(952, 25), // "vScrollBarActionTriggered"
QT_MOC_LITERAL(978, 14), // "drawFarOverlay"
QT_MOC_LITERAL(993, 15), // "drawNearOverlay"
QT_MOC_LITERAL(1009, 13), // "updatePackets"
QT_MOC_LITERAL(1023, 6), // "redraw"
QT_MOC_LITERAL(1030, 17), // "ctxDecodeAsDialog"
QT_MOC_LITERAL(1048, 15), // "SummaryCopyType"
QT_MOC_LITERAL(1064, 10), // "CopyAsText"
QT_MOC_LITERAL(1075, 9), // "CopyAsCSV"
QT_MOC_LITERAL(1085, 10), // "CopyAsYAML"
QT_MOC_LITERAL(1096, 10) // "CopyAsHTML"

    },
    "PacketList\0packetDissectionChanged\0\0"
    "showColumnPreferences\0pane_name\0"
    "editColumn\0column\0packetListScrolled\0"
    "at_end\0showProtocolPreferences\0"
    "module_name\0editProtocolPreference\0"
    "pref_t*\0pref\0module_t*\0module\0"
    "framesSelected\0QList<int>\0fieldSelected\0"
    "FieldInformation*\0rowsInserted\0"
    "QModelIndex\0parent\0start\0end\0drawRow\0"
    "QPainter*\0painter\0QStyleOptionViewItem\0"
    "option\0index\0setCaptureFile\0capture_file*\0"
    "cf\0setMonospaceFont\0mono_font\0"
    "setRegularFont\0regular_font\0goNextPacket\0"
    "goPreviousPacket\0goFirstPacket\0"
    "goLastPacket\0goToPacket\0packet\0hf_id\0"
    "goNextHistoryPacket\0goPreviousHistoryPacket\0"
    "markFrame\0markAllDisplayedFrames\0set\0"
    "ignoreFrame\0ignoreAllDisplayedFrames\0"
    "setTimeReference\0unsetAllTimeReferences\0"
    "applyTimeShift\0recolorPackets\0"
    "redrawVisiblePackets\0"
    "redrawVisiblePacketsDontSelectCurrent\0"
    "colorsChanged\0columnsChanged\0fieldsChanged\0"
    "preferencesChanged\0freezePacketList\0"
    "changing_profile\0columnVisibilityTriggered\0"
    "sectionResized\0col\0new_width\0sectionMoved\0"
    "copySummary\0vScrollBarActionTriggered\0"
    "drawFarOverlay\0drawNearOverlay\0"
    "updatePackets\0redraw\0ctxDecodeAsDialog\0"
    "SummaryCopyType\0CopyAsText\0CopyAsCSV\0"
    "CopyAsYAML\0CopyAsHTML"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PacketList[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      45,   14, // methods
       0,    0, // properties
       1,  393, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  284,    2, 0x06,    1 /* Public */,
       3,    1,  285,    2, 0x06,    2 /* Public */,
       5,    1,  288,    2, 0x06,    4 /* Public */,
       7,    1,  291,    2, 0x06,    6 /* Public */,
       9,    1,  294,    2, 0x06,    8 /* Public */,
      11,    2,  297,    2, 0x06,   10 /* Public */,
      16,    1,  302,    2, 0x06,   13 /* Public */,
      18,    1,  305,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      20,    3,  308,    2, 0x09,   17 /* Protected */,
      25,    3,  315,    2, 0x109,   21 /* Protected | MethodIsConst  */,
      31,    1,  322,    2, 0x0a,   25 /* Public */,
      34,    1,  325,    2, 0x0a,   27 /* Public */,
      36,    1,  328,    2, 0x0a,   29 /* Public */,
      38,    0,  331,    2, 0x0a,   31 /* Public */,
      39,    0,  332,    2, 0x0a,   32 /* Public */,
      40,    0,  333,    2, 0x0a,   33 /* Public */,
      41,    0,  334,    2, 0x0a,   34 /* Public */,
      42,    2,  335,    2, 0x0a,   35 /* Public */,
      42,    1,  340,    2, 0x2a,   38 /* Public | MethodCloned */,
      45,    0,  343,    2, 0x0a,   40 /* Public */,
      46,    0,  344,    2, 0x0a,   41 /* Public */,
      47,    0,  345,    2, 0x0a,   42 /* Public */,
      48,    1,  346,    2, 0x0a,   43 /* Public */,
      50,    0,  349,    2, 0x0a,   45 /* Public */,
      51,    1,  350,    2, 0x0a,   46 /* Public */,
      52,    0,  353,    2, 0x0a,   48 /* Public */,
      53,    0,  354,    2, 0x0a,   49 /* Public */,
      54,    0,  355,    2, 0x0a,   50 /* Public */,
      55,    0,  356,    2, 0x0a,   51 /* Public */,
      56,    0,  357,    2, 0x0a,   52 /* Public */,
      57,    0,  358,    2, 0x0a,   53 /* Public */,
      58,    0,  359,    2, 0x0a,   54 /* Public */,
      59,    0,  360,    2, 0x0a,   55 /* Public */,
      60,    1,  361,    2, 0x0a,   56 /* Public */,
      61,    0,  364,    2, 0x0a,   58 /* Public */,
      62,    1,  365,    2, 0x0a,   59 /* Public */,
      64,    0,  368,    2, 0x08,   61 /* Private */,
      65,    3,  369,    2, 0x08,   62 /* Private */,
      68,    3,  376,    2, 0x08,   66 /* Private */,
      69,    0,  383,    2, 0x08,   70 /* Private */,
      70,    1,  384,    2, 0x08,   71 /* Private */,
      71,    0,  387,    2, 0x08,   73 /* Private */,
      72,    0,  388,    2, 0x08,   74 /* Private */,
      73,    1,  389,    2, 0x08,   75 /* Private */,
      75,    0,  392,    2, 0x08,   77 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14,   13,   15,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 19,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 21, QMetaType::Int, QMetaType::Int,   22,   23,   24,
    QMetaType::Void, 0x80000000 | 26, 0x80000000 | 28, 0x80000000 | 21,   27,   29,   30,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, QMetaType::QFont,   35,
    QMetaType::Void, QMetaType::QFont,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   43,   44,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   49,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   49,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   63,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   66,    2,   67,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   74,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
      76,   76, 0x0,    4,  398,

 // enum data: key, value
      77, uint(PacketList::CopyAsText),
      78, uint(PacketList::CopyAsCSV),
      79, uint(PacketList::CopyAsYAML),
      80, uint(PacketList::CopyAsHTML),

       0        // eod
};

void PacketList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PacketList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->packetDissectionChanged(); break;
        case 1: _t->showColumnPreferences((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->editColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->packetListScrolled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->showProtocolPreferences((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->editProtocolPreference((*reinterpret_cast< std::add_pointer_t<pref_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<module_t*>>(_a[2]))); break;
        case 6: _t->framesSelected((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 7: _t->fieldSelected((*reinterpret_cast< std::add_pointer_t<FieldInformation*>>(_a[1]))); break;
        case 8: _t->rowsInserted((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 9: _t->drawRow((*reinterpret_cast< std::add_pointer_t<QPainter*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStyleOptionViewItem>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[3]))); break;
        case 10: _t->setCaptureFile((*reinterpret_cast< std::add_pointer_t<capture_file*>>(_a[1]))); break;
        case 11: _t->setMonospaceFont((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        case 12: _t->setRegularFont((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        case 13: _t->goNextPacket(); break;
        case 14: _t->goPreviousPacket(); break;
        case 15: _t->goFirstPacket(); break;
        case 16: _t->goLastPacket(); break;
        case 17: _t->goToPacket((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 18: _t->goToPacket((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->goNextHistoryPacket(); break;
        case 20: _t->goPreviousHistoryPacket(); break;
        case 21: _t->markFrame(); break;
        case 22: _t->markAllDisplayedFrames((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 23: _t->ignoreFrame(); break;
        case 24: _t->ignoreAllDisplayedFrames((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 25: _t->setTimeReference(); break;
        case 26: _t->unsetAllTimeReferences(); break;
        case 27: _t->applyTimeShift(); break;
        case 28: _t->recolorPackets(); break;
        case 29: _t->redrawVisiblePackets(); break;
        case 30: _t->redrawVisiblePacketsDontSelectCurrent(); break;
        case 31: _t->colorsChanged(); break;
        case 32: _t->columnsChanged(); break;
        case 33: _t->fieldsChanged((*reinterpret_cast< std::add_pointer_t<capture_file*>>(_a[1]))); break;
        case 34: _t->preferencesChanged(); break;
        case 35: _t->freezePacketList((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 36: _t->columnVisibilityTriggered(); break;
        case 37: _t->sectionResized((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 38: _t->sectionMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 39: _t->copySummary(); break;
        case 40: _t->vScrollBarActionTriggered((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 41: _t->drawFarOverlay(); break;
        case 42: _t->drawNearOverlay(); break;
        case 43: _t->updatePackets((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 44: _t->ctxDecodeAsDialog(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FieldInformation* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PacketList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketList::packetDissectionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PacketList::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketList::showColumnPreferences)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PacketList::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketList::editColumn)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PacketList::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketList::packetListScrolled)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PacketList::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketList::showProtocolPreferences)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PacketList::*)(pref_t * , module_t * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketList::editProtocolPreference)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PacketList::*)(QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketList::framesSelected)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PacketList::*)(FieldInformation * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketList::fieldSelected)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject PacketList::staticMetaObject = { {
    QMetaObject::SuperData::link<QTreeView::staticMetaObject>(),
    qt_meta_stringdata_PacketList.offsetsAndSize,
    qt_meta_data_PacketList,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PacketList_t
, QtPrivate::TypeAndForceComplete<PacketList, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<pref_t *, std::false_type>, QtPrivate::TypeAndForceComplete<module_t *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<FieldInformation *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPainter *, std::false_type>, QtPrivate::TypeAndForceComplete<const QStyleOptionViewItem &, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_file *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QFont &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QFont &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_file *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *PacketList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PacketList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PacketList.stringdata0))
        return static_cast<void*>(this);
    return QTreeView::qt_metacast(_clname);
}

int PacketList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    }
    return _id;
}

// SIGNAL 0
void PacketList::packetDissectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PacketList::showColumnPreferences(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PacketList::editColumn(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PacketList::packetListScrolled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PacketList::showProtocolPreferences(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PacketList::editProtocolPreference(pref_t * _t1, module_t * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PacketList::framesSelected(QList<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PacketList::fieldSelected(FieldInformation * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
