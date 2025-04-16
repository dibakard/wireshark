/****************************************************************************
** Meta object code from reading C++ file 'wireshark_main_window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../ui/qt/wireshark_main_window.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wireshark_main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WiresharkMainWindow_t {
    const uint offsetsAndSize[506];
    char stringdata0[4738];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_WiresharkMainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_WiresharkMainWindow_t qt_meta_stringdata_WiresharkMainWindow = {
    {
QT_MOC_LITERAL(0, 19), // "WiresharkMainWindow"
QT_MOC_LITERAL(20, 23), // "setDissectedCaptureFile"
QT_MOC_LITERAL(44, 0), // ""
QT_MOC_LITERAL(45, 13), // "capture_file*"
QT_MOC_LITERAL(59, 2), // "cf"
QT_MOC_LITERAL(62, 18), // "closePacketDialogs"
QT_MOC_LITERAL(81, 12), // "reloadFields"
QT_MOC_LITERAL(94, 17), // "packetInfoChanged"
QT_MOC_LITERAL(112, 13), // "_packet_info*"
QT_MOC_LITERAL(126, 5), // "pinfo"
QT_MOC_LITERAL(132, 18), // "fieldFilterChanged"
QT_MOC_LITERAL(151, 12), // "field_filter"
QT_MOC_LITERAL(164, 15), // "selectRtpStream"
QT_MOC_LITERAL(180, 15), // "rtpstream_id_t*"
QT_MOC_LITERAL(196, 2), // "id"
QT_MOC_LITERAL(199, 17), // "deselectRtpStream"
QT_MOC_LITERAL(217, 17), // "showExtcapOptions"
QT_MOC_LITERAL(235, 8), // "QString&"
QT_MOC_LITERAL(244, 11), // "device_name"
QT_MOC_LITERAL(256, 19), // "startCaptureOnClose"
QT_MOC_LITERAL(276, 15), // "openCaptureFile"
QT_MOC_LITERAL(292, 7), // "cf_path"
QT_MOC_LITERAL(300, 14), // "display_filter"
QT_MOC_LITERAL(315, 4), // "type"
QT_MOC_LITERAL(320, 11), // "is_tempfile"
QT_MOC_LITERAL(332, 13), // "filterPackets"
QT_MOC_LITERAL(346, 10), // "new_filter"
QT_MOC_LITERAL(357, 5), // "force"
QT_MOC_LITERAL(363, 14), // "layoutToolbars"
QT_MOC_LITERAL(378, 23), // "updatePreferenceActions"
QT_MOC_LITERAL(402, 19), // "updateRecentActions"
QT_MOC_LITERAL(422, 25), // "setTitlebarForCaptureFile"
QT_MOC_LITERAL(448, 24), // "showCaptureOptionsDialog"
QT_MOC_LITERAL(473, 22), // "captureCapturePrepared"
QT_MOC_LITERAL(496, 16), // "capture_session*"
QT_MOC_LITERAL(513, 27), // "captureCaptureUpdateStarted"
QT_MOC_LITERAL(541, 28), // "captureCaptureUpdateFinished"
QT_MOC_LITERAL(570, 27), // "captureCaptureFixedFinished"
QT_MOC_LITERAL(598, 11), // "cap_session"
QT_MOC_LITERAL(610, 20), // "captureCaptureFailed"
QT_MOC_LITERAL(631, 17), // "captureFileOpened"
QT_MOC_LITERAL(649, 23), // "captureFileReadFinished"
QT_MOC_LITERAL(673, 18), // "captureFileClosing"
QT_MOC_LITERAL(692, 17), // "captureFileClosed"
QT_MOC_LITERAL(710, 14), // "launchRLCGraph"
QT_MOC_LITERAL(725, 12), // "channelKnown"
QT_MOC_LITERAL(738, 7), // "uint8_t"
QT_MOC_LITERAL(746, 3), // "RAT"
QT_MOC_LITERAL(750, 8), // "uint16_t"
QT_MOC_LITERAL(759, 4), // "ueid"
QT_MOC_LITERAL(764, 7), // "rlcMode"
QT_MOC_LITERAL(772, 11), // "channelType"
QT_MOC_LITERAL(784, 9), // "channelId"
QT_MOC_LITERAL(794, 9), // "direction"
QT_MOC_LITERAL(804, 32), // "rtpPlayerDialogReplaceRtpStreams"
QT_MOC_LITERAL(837, 22), // "QList<rtpstream_id_t*>"
QT_MOC_LITERAL(860, 10), // "stream_ids"
QT_MOC_LITERAL(871, 28), // "rtpPlayerDialogAddRtpStreams"
QT_MOC_LITERAL(900, 31), // "rtpPlayerDialogRemoveRtpStreams"
QT_MOC_LITERAL(932, 34), // "rtpAnalysisDialogReplaceRtpSt..."
QT_MOC_LITERAL(967, 30), // "rtpAnalysisDialogAddRtpStreams"
QT_MOC_LITERAL(998, 33), // "rtpAnalysisDialogRemoveRtpStr..."
QT_MOC_LITERAL(1032, 32), // "rtpStreamsDialogSelectRtpStreams"
QT_MOC_LITERAL(1065, 34), // "rtpStreamsDialogDeselectRtpSt..."
QT_MOC_LITERAL(1100, 19), // "captureEventHandler"
QT_MOC_LITERAL(1120, 12), // "CaptureEvent"
QT_MOC_LITERAL(1133, 2), // "ev"
QT_MOC_LITERAL(1136, 20), // "initViewColorizeMenu"
QT_MOC_LITERAL(1157, 21), // "initConversationMenus"
QT_MOC_LITERAL(1179, 24), // "addExportObjectsMenuItem"
QT_MOC_LITERAL(1204, 11), // "const void*"
QT_MOC_LITERAL(1216, 3), // "key"
QT_MOC_LITERAL(1220, 5), // "value"
QT_MOC_LITERAL(1226, 8), // "userdata"
QT_MOC_LITERAL(1235, 22), // "initExportObjectsMenus"
QT_MOC_LITERAL(1258, 23), // "addFollowStreamMenuItem"
QT_MOC_LITERAL(1282, 21), // "initFollowStreamMenus"
QT_MOC_LITERAL(1304, 12), // "startCapture"
QT_MOC_LITERAL(1317, 25), // "pushLiveCaptureInProgress"
QT_MOC_LITERAL(1343, 24), // "popLiveCaptureInProgress"
QT_MOC_LITERAL(1368, 11), // "stopCapture"
QT_MOC_LITERAL(1380, 18), // "loadWindowGeometry"
QT_MOC_LITERAL(1399, 18), // "saveWindowGeometry"
QT_MOC_LITERAL(1418, 16), // "mainStackChanged"
QT_MOC_LITERAL(1435, 20), // "updateRecentCaptures"
QT_MOC_LITERAL(1456, 21), // "recentActionTriggered"
QT_MOC_LITERAL(1478, 16), // "addPacketComment"
QT_MOC_LITERAL(1495, 17), // "editPacketComment"
QT_MOC_LITERAL(1513, 19), // "deletePacketComment"
QT_MOC_LITERAL(1533, 25), // "deleteCommentsFromPackets"
QT_MOC_LITERAL(1559, 17), // "commentToMenuText"
QT_MOC_LITERAL(1577, 4), // "text"
QT_MOC_LITERAL(1582, 7), // "max_len"
QT_MOC_LITERAL(1590, 19), // "setEditCommentsMenu"
QT_MOC_LITERAL(1610, 25), // "setMenusForSelectedPacket"
QT_MOC_LITERAL(1636, 26), // "setMenusForSelectedTreeRow"
QT_MOC_LITERAL(1663, 17), // "FieldInformation*"
QT_MOC_LITERAL(1681, 2), // "fi"
QT_MOC_LITERAL(1684, 25), // "interfaceSelectionChanged"
QT_MOC_LITERAL(1710, 26), // "captureFilterSyntaxChanged"
QT_MOC_LITERAL(1737, 5), // "valid"
QT_MOC_LITERAL(1743, 16), // "redissectPackets"
QT_MOC_LITERAL(1760, 18), // "checkDisplayFilter"
QT_MOC_LITERAL(1779, 13), // "fieldsChanged"
QT_MOC_LITERAL(1793, 16), // "reloadLuaPlugins"
QT_MOC_LITERAL(1810, 18), // "showAccordionFrame"
QT_MOC_LITERAL(1829, 15), // "AccordionFrame*"
QT_MOC_LITERAL(1845, 10), // "show_frame"
QT_MOC_LITERAL(1856, 6), // "toggle"
QT_MOC_LITERAL(1863, 16), // "showColumnEditor"
QT_MOC_LITERAL(1880, 6), // "column"
QT_MOC_LITERAL(1887, 20), // "showPreferenceEditor"
QT_MOC_LITERAL(1908, 21), // "addStatsPluginsToMenu"
QT_MOC_LITERAL(1930, 15), // "addDynamicMenus"
QT_MOC_LITERAL(1946, 18), // "reloadDynamicMenus"
QT_MOC_LITERAL(1965, 21), // "addPluginIFStructures"
QT_MOC_LITERAL(1987, 13), // "searchSubMenu"
QT_MOC_LITERAL(2001, 6), // "QMenu*"
QT_MOC_LITERAL(2008, 10), // "objectName"
QT_MOC_LITERAL(2019, 23), // "activatePluginIFToolbar"
QT_MOC_LITERAL(2043, 21), // "startInterfaceCapture"
QT_MOC_LITERAL(2065, 14), // "capture_filter"
QT_MOC_LITERAL(2080, 29), // "applyGlobalCommandLineOptions"
QT_MOC_LITERAL(2110, 18), // "setFeaturesEnabled"
QT_MOC_LITERAL(2129, 7), // "enabled"
QT_MOC_LITERAL(2137, 45), // "on_actionNewDisplayFilterExpr..."
QT_MOC_LITERAL(2183, 16), // "onFilterSelected"
QT_MOC_LITERAL(2200, 19), // "onFilterPreferences"
QT_MOC_LITERAL(2220, 12), // "onFilterEdit"
QT_MOC_LITERAL(2233, 8), // "uatIndex"
QT_MOC_LITERAL(2242, 18), // "queuedFilterAction"
QT_MOC_LITERAL(2261, 6), // "filter"
QT_MOC_LITERAL(2268, 20), // "FilterAction::Action"
QT_MOC_LITERAL(2289, 6), // "action"
QT_MOC_LITERAL(2296, 24), // "FilterAction::ActionType"
QT_MOC_LITERAL(2321, 21), // "openStatCommandDialog"
QT_MOC_LITERAL(2343, 9), // "menu_path"
QT_MOC_LITERAL(2353, 11), // "const char*"
QT_MOC_LITERAL(2365, 3), // "arg"
QT_MOC_LITERAL(2369, 22), // "openTapParameterDialog"
QT_MOC_LITERAL(2392, 7), // "cfg_str"
QT_MOC_LITERAL(2400, 22), // "connectFileMenuActions"
QT_MOC_LITERAL(2423, 17), // "exportPacketBytes"
QT_MOC_LITERAL(2441, 9), // "exportPDU"
QT_MOC_LITERAL(2451, 18), // "stripPacketHeaders"
QT_MOC_LITERAL(2470, 20), // "exportTLSSessionKeys"
QT_MOC_LITERAL(2491, 9), // "printFile"
QT_MOC_LITERAL(2501, 22), // "connectEditMenuActions"
QT_MOC_LITERAL(2524, 17), // "copySelectedItems"
QT_MOC_LITERAL(2542, 33), // "WiresharkMainWindow::CopySele..."
QT_MOC_LITERAL(2576, 14), // "selection_type"
QT_MOC_LITERAL(2591, 10), // "findPacket"
QT_MOC_LITERAL(2602, 13), // "editTimeShift"
QT_MOC_LITERAL(2616, 25), // "editConfigurationProfiles"
QT_MOC_LITERAL(2642, 21), // "editTimeShiftFinished"
QT_MOC_LITERAL(2664, 24), // "addPacketCommentFinished"
QT_MOC_LITERAL(2689, 20), // "PacketCommentDialog*"
QT_MOC_LITERAL(2710, 9), // "pc_dialog"
QT_MOC_LITERAL(2720, 6), // "result"
QT_MOC_LITERAL(2727, 25), // "editPacketCommentFinished"
QT_MOC_LITERAL(2753, 8), // "nComment"
QT_MOC_LITERAL(2762, 23), // "deleteAllPacketComments"
QT_MOC_LITERAL(2786, 31), // "deleteAllPacketCommentsFinished"
QT_MOC_LITERAL(2818, 13), // "injectSecrets"
QT_MOC_LITERAL(2832, 17), // "discardAllSecrets"
QT_MOC_LITERAL(2850, 25), // "discardAllSecretsFinished"
QT_MOC_LITERAL(2876, 21), // "showPreferencesDialog"
QT_MOC_LITERAL(2898, 11), // "module_name"
QT_MOC_LITERAL(2910, 22), // "connectViewMenuActions"
QT_MOC_LITERAL(2933, 19), // "showHideMainWidgets"
QT_MOC_LITERAL(2953, 8), // "QAction*"
QT_MOC_LITERAL(2962, 18), // "setTimestampFormat"
QT_MOC_LITERAL(2981, 21), // "setTimestampPrecision"
QT_MOC_LITERAL(3003, 40), // "setTimeDisplaySecondsWithHour..."
QT_MOC_LITERAL(3044, 7), // "checked"
QT_MOC_LITERAL(3052, 16), // "editResolvedName"
QT_MOC_LITERAL(3069, 17), // "setNameResolution"
QT_MOC_LITERAL(3087, 8), // "zoomText"
QT_MOC_LITERAL(3096, 23), // "showColoringRulesDialog"
QT_MOC_LITERAL(3120, 20), // "colorizeConversation"
QT_MOC_LITERAL(3141, 11), // "create_rule"
QT_MOC_LITERAL(3153, 23), // "colorizeActionTriggered"
QT_MOC_LITERAL(3177, 16), // "openPacketDialog"
QT_MOC_LITERAL(3194, 14), // "from_reference"
QT_MOC_LITERAL(3209, 34), // "reloadCaptureFileAsFormatOrCa..."
QT_MOC_LITERAL(3244, 17), // "reloadCaptureFile"
QT_MOC_LITERAL(3262, 20), // "connectGoMenuActions"
QT_MOC_LITERAL(3283, 16), // "setPreviousFocus"
QT_MOC_LITERAL(3300, 18), // "resetPreviousFocus"
QT_MOC_LITERAL(3319, 25), // "connectCaptureMenuActions"
QT_MOC_LITERAL(3345, 21), // "startCaptureTriggered"
QT_MOC_LITERAL(3367, 25), // "connectAnalyzeMenuActions"
QT_MOC_LITERAL(3393, 16), // "matchFieldFilter"
QT_MOC_LITERAL(3410, 11), // "filter_type"
QT_MOC_LITERAL(3422, 18), // "applyFieldAsColumn"
QT_MOC_LITERAL(3441, 21), // "filterMenuAboutToShow"
QT_MOC_LITERAL(3463, 23), // "applyConversationFilter"
QT_MOC_LITERAL(3487, 17), // "applyExportObject"
QT_MOC_LITERAL(3505, 22), // "openFollowStreamDialog"
QT_MOC_LITERAL(3528, 8), // "proto_id"
QT_MOC_LITERAL(3537, 10), // "stream_num"
QT_MOC_LITERAL(3548, 14), // "sub_stream_num"
QT_MOC_LITERAL(3563, 16), // "use_stream_index"
QT_MOC_LITERAL(3580, 11), // "openIOGraph"
QT_MOC_LITERAL(3592, 8), // "filtered"
QT_MOC_LITERAL(3601, 11), // "QList<uint>"
QT_MOC_LITERAL(3613, 8), // "conv_ids"
QT_MOC_LITERAL(3622, 8), // "conv_agg"
QT_MOC_LITERAL(3631, 21), // "statCommandExpertInfo"
QT_MOC_LITERAL(3653, 22), // "connectHelpMenuActions"
QT_MOC_LITERAL(3676, 17), // "goToCancelClicked"
QT_MOC_LITERAL(3694, 13), // "goToGoClicked"
QT_MOC_LITERAL(3708, 25), // "goToLineEditReturnPressed"
QT_MOC_LITERAL(3734, 28), // "connectStatisticsMenuActions"
QT_MOC_LITERAL(3763, 27), // "showResolvedAddressesDialog"
QT_MOC_LITERAL(3791, 23), // "showConversationsDialog"
QT_MOC_LITERAL(3815, 19), // "showEndpointsDialog"
QT_MOC_LITERAL(3835, 19), // "openTcpStreamDialog"
QT_MOC_LITERAL(3855, 10), // "graph_type"
QT_MOC_LITERAL(3866, 23), // "openSCTPAllAssocsDialog"
QT_MOC_LITERAL(3890, 42), // "on_actionSCTPShowAllAssociati..."
QT_MOC_LITERAL(3933, 45), // "on_actionSCTPAnalyseThisAssoc..."
QT_MOC_LITERAL(3979, 44), // "on_actionSCTPFilterThisAssoci..."
QT_MOC_LITERAL(4024, 30), // "statCommandMulticastStatistics"
QT_MOC_LITERAL(4055, 25), // "statCommandWlanStatistics"
QT_MOC_LITERAL(4081, 24), // "openStatisticsTreeDialog"
QT_MOC_LITERAL(4106, 4), // "abbr"
QT_MOC_LITERAL(4111, 18), // "statCommandIOGraph"
QT_MOC_LITERAL(4130, 17), // "showIOGraphDialog"
QT_MOC_LITERAL(4148, 20), // "io_graph_item_unit_t"
QT_MOC_LITERAL(4169, 11), // "value_units"
QT_MOC_LITERAL(4181, 27), // "connectTelephonyMenuActions"
QT_MOC_LITERAL(4209, 29), // "openTelephonyRtpStreamsDialog"
QT_MOC_LITERAL(4239, 16), // "RtpStreamDialog*"
QT_MOC_LITERAL(4256, 28), // "openTelephonyRtpPlayerDialog"
QT_MOC_LITERAL(4285, 16), // "RtpPlayerDialog*"
QT_MOC_LITERAL(4302, 30), // "openTelephonyRtpAnalysisDialog"
QT_MOC_LITERAL(4333, 18), // "RtpAnalysisDialog*"
QT_MOC_LITERAL(4352, 27), // "statCommandLteMacStatistics"
QT_MOC_LITERAL(4380, 27), // "statCommandLteRlcStatistics"
QT_MOC_LITERAL(4408, 27), // "openRtpStreamAnalysisDialog"
QT_MOC_LITERAL(4436, 19), // "openRtpPlayerDialog"
QT_MOC_LITERAL(4456, 26), // "connectWirelessMenuActions"
QT_MOC_LITERAL(4483, 23), // "connectToolsMenuActions"
QT_MOC_LITERAL(4507, 25), // "externalMenuItemTriggered"
QT_MOC_LITERAL(4533, 42), // "on_actionContextWikiProtocolP..."
QT_MOC_LITERAL(4576, 46), // "on_actionContextFilterFieldRe..."
QT_MOC_LITERAL(4623, 23), // "extcap_options_finished"
QT_MOC_LITERAL(4647, 23), // "showExtcapOptionsDialog"
QT_MOC_LITERAL(4671, 14), // "findRtpStreams"
QT_MOC_LITERAL(4686, 23), // "QList<rtpstream_id_t*>*"
QT_MOC_LITERAL(4710, 7), // "reverse"
QT_MOC_LITERAL(4718, 19) // "openTLSKeylogDialog"

    },
    "WiresharkMainWindow\0setDissectedCaptureFile\0"
    "\0capture_file*\0cf\0closePacketDialogs\0"
    "reloadFields\0packetInfoChanged\0"
    "_packet_info*\0pinfo\0fieldFilterChanged\0"
    "field_filter\0selectRtpStream\0"
    "rtpstream_id_t*\0id\0deselectRtpStream\0"
    "showExtcapOptions\0QString&\0device_name\0"
    "startCaptureOnClose\0openCaptureFile\0"
    "cf_path\0display_filter\0type\0is_tempfile\0"
    "filterPackets\0new_filter\0force\0"
    "layoutToolbars\0updatePreferenceActions\0"
    "updateRecentActions\0setTitlebarForCaptureFile\0"
    "showCaptureOptionsDialog\0"
    "captureCapturePrepared\0capture_session*\0"
    "captureCaptureUpdateStarted\0"
    "captureCaptureUpdateFinished\0"
    "captureCaptureFixedFinished\0cap_session\0"
    "captureCaptureFailed\0captureFileOpened\0"
    "captureFileReadFinished\0captureFileClosing\0"
    "captureFileClosed\0launchRLCGraph\0"
    "channelKnown\0uint8_t\0RAT\0uint16_t\0"
    "ueid\0rlcMode\0channelType\0channelId\0"
    "direction\0rtpPlayerDialogReplaceRtpStreams\0"
    "QList<rtpstream_id_t*>\0stream_ids\0"
    "rtpPlayerDialogAddRtpStreams\0"
    "rtpPlayerDialogRemoveRtpStreams\0"
    "rtpAnalysisDialogReplaceRtpStreams\0"
    "rtpAnalysisDialogAddRtpStreams\0"
    "rtpAnalysisDialogRemoveRtpStreams\0"
    "rtpStreamsDialogSelectRtpStreams\0"
    "rtpStreamsDialogDeselectRtpStreams\0"
    "captureEventHandler\0CaptureEvent\0ev\0"
    "initViewColorizeMenu\0initConversationMenus\0"
    "addExportObjectsMenuItem\0const void*\0"
    "key\0value\0userdata\0initExportObjectsMenus\0"
    "addFollowStreamMenuItem\0initFollowStreamMenus\0"
    "startCapture\0pushLiveCaptureInProgress\0"
    "popLiveCaptureInProgress\0stopCapture\0"
    "loadWindowGeometry\0saveWindowGeometry\0"
    "mainStackChanged\0updateRecentCaptures\0"
    "recentActionTriggered\0addPacketComment\0"
    "editPacketComment\0deletePacketComment\0"
    "deleteCommentsFromPackets\0commentToMenuText\0"
    "text\0max_len\0setEditCommentsMenu\0"
    "setMenusForSelectedPacket\0"
    "setMenusForSelectedTreeRow\0FieldInformation*\0"
    "fi\0interfaceSelectionChanged\0"
    "captureFilterSyntaxChanged\0valid\0"
    "redissectPackets\0checkDisplayFilter\0"
    "fieldsChanged\0reloadLuaPlugins\0"
    "showAccordionFrame\0AccordionFrame*\0"
    "show_frame\0toggle\0showColumnEditor\0"
    "column\0showPreferenceEditor\0"
    "addStatsPluginsToMenu\0addDynamicMenus\0"
    "reloadDynamicMenus\0addPluginIFStructures\0"
    "searchSubMenu\0QMenu*\0objectName\0"
    "activatePluginIFToolbar\0startInterfaceCapture\0"
    "capture_filter\0applyGlobalCommandLineOptions\0"
    "setFeaturesEnabled\0enabled\0"
    "on_actionNewDisplayFilterExpression_triggered\0"
    "onFilterSelected\0onFilterPreferences\0"
    "onFilterEdit\0uatIndex\0queuedFilterAction\0"
    "filter\0FilterAction::Action\0action\0"
    "FilterAction::ActionType\0openStatCommandDialog\0"
    "menu_path\0const char*\0arg\0"
    "openTapParameterDialog\0cfg_str\0"
    "connectFileMenuActions\0exportPacketBytes\0"
    "exportPDU\0stripPacketHeaders\0"
    "exportTLSSessionKeys\0printFile\0"
    "connectEditMenuActions\0copySelectedItems\0"
    "WiresharkMainWindow::CopySelected\0"
    "selection_type\0findPacket\0editTimeShift\0"
    "editConfigurationProfiles\0"
    "editTimeShiftFinished\0addPacketCommentFinished\0"
    "PacketCommentDialog*\0pc_dialog\0result\0"
    "editPacketCommentFinished\0nComment\0"
    "deleteAllPacketComments\0"
    "deleteAllPacketCommentsFinished\0"
    "injectSecrets\0discardAllSecrets\0"
    "discardAllSecretsFinished\0"
    "showPreferencesDialog\0module_name\0"
    "connectViewMenuActions\0showHideMainWidgets\0"
    "QAction*\0setTimestampFormat\0"
    "setTimestampPrecision\0"
    "setTimeDisplaySecondsWithHoursAndMinutes\0"
    "checked\0editResolvedName\0setNameResolution\0"
    "zoomText\0showColoringRulesDialog\0"
    "colorizeConversation\0create_rule\0"
    "colorizeActionTriggered\0openPacketDialog\0"
    "from_reference\0reloadCaptureFileAsFormatOrCapture\0"
    "reloadCaptureFile\0connectGoMenuActions\0"
    "setPreviousFocus\0resetPreviousFocus\0"
    "connectCaptureMenuActions\0"
    "startCaptureTriggered\0connectAnalyzeMenuActions\0"
    "matchFieldFilter\0filter_type\0"
    "applyFieldAsColumn\0filterMenuAboutToShow\0"
    "applyConversationFilter\0applyExportObject\0"
    "openFollowStreamDialog\0proto_id\0"
    "stream_num\0sub_stream_num\0use_stream_index\0"
    "openIOGraph\0filtered\0QList<uint>\0"
    "conv_ids\0conv_agg\0statCommandExpertInfo\0"
    "connectHelpMenuActions\0goToCancelClicked\0"
    "goToGoClicked\0goToLineEditReturnPressed\0"
    "connectStatisticsMenuActions\0"
    "showResolvedAddressesDialog\0"
    "showConversationsDialog\0showEndpointsDialog\0"
    "openTcpStreamDialog\0graph_type\0"
    "openSCTPAllAssocsDialog\0"
    "on_actionSCTPShowAllAssociations_triggered\0"
    "on_actionSCTPAnalyseThisAssociation_triggered\0"
    "on_actionSCTPFilterThisAssociation_triggered\0"
    "statCommandMulticastStatistics\0"
    "statCommandWlanStatistics\0"
    "openStatisticsTreeDialog\0abbr\0"
    "statCommandIOGraph\0showIOGraphDialog\0"
    "io_graph_item_unit_t\0value_units\0"
    "connectTelephonyMenuActions\0"
    "openTelephonyRtpStreamsDialog\0"
    "RtpStreamDialog*\0openTelephonyRtpPlayerDialog\0"
    "RtpPlayerDialog*\0openTelephonyRtpAnalysisDialog\0"
    "RtpAnalysisDialog*\0statCommandLteMacStatistics\0"
    "statCommandLteRlcStatistics\0"
    "openRtpStreamAnalysisDialog\0"
    "openRtpPlayerDialog\0connectWirelessMenuActions\0"
    "connectToolsMenuActions\0"
    "externalMenuItemTriggered\0"
    "on_actionContextWikiProtocolPage_triggered\0"
    "on_actionContextFilterFieldReference_triggered\0"
    "extcap_options_finished\0showExtcapOptionsDialog\0"
    "findRtpStreams\0QList<rtpstream_id_t*>*\0"
    "reverse\0openTLSKeylogDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WiresharkMainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
     181,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1, 1100,    2, 0x06,    1 /* Public */,
       5,    0, 1103,    2, 0x06,    3 /* Public */,
       6,    0, 1104,    2, 0x06,    4 /* Public */,
       7,    1, 1105,    2, 0x06,    5 /* Public */,
      10,    1, 1108,    2, 0x06,    7 /* Public */,
      12,    1, 1111,    2, 0x06,    9 /* Public */,
      15,    1, 1114,    2, 0x06,   11 /* Public */,
      16,    2, 1117,    2, 0x06,   13 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      20,    4, 1122,    2, 0x0a,   16 /* Public */,
      20,    3, 1131,    2, 0x2a,   21 /* Public | MethodCloned */,
      20,    2, 1138,    2, 0x0a,   25 /* Public */,
      20,    1, 1143,    2, 0x2a,   28 /* Public | MethodCloned */,
      20,    0, 1146,    2, 0x2a,   30 /* Public | MethodCloned */,
      25,    2, 1147,    2, 0x0a,   31 /* Public */,
      25,    1, 1152,    2, 0x2a,   34 /* Public | MethodCloned */,
      25,    0, 1155,    2, 0x2a,   36 /* Public | MethodCloned */,
      28,    0, 1156,    2, 0x0a,   37 /* Public */,
      29,    0, 1157,    2, 0x0a,   38 /* Public */,
      30,    0, 1158,    2, 0x0a,   39 /* Public */,
      31,    0, 1159,    2, 0x0a,   40 /* Public */,
      32,    0, 1160,    2, 0x0a,   41 /* Public */,
      33,    1, 1161,    2, 0x0a,   42 /* Public */,
      35,    1, 1164,    2, 0x0a,   44 /* Public */,
      36,    1, 1167,    2, 0x0a,   46 /* Public */,
      37,    1, 1170,    2, 0x0a,   48 /* Public */,
      39,    1, 1173,    2, 0x0a,   50 /* Public */,
      40,    0, 1176,    2, 0x0a,   52 /* Public */,
      41,    0, 1177,    2, 0x0a,   53 /* Public */,
      42,    0, 1178,    2, 0x0a,   54 /* Public */,
      43,    0, 1179,    2, 0x0a,   55 /* Public */,
      44,    7, 1180,    2, 0x0a,   56 /* Public */,
      54,    1, 1195,    2, 0x0a,   64 /* Public */,
      57,    1, 1198,    2, 0x0a,   66 /* Public */,
      58,    1, 1201,    2, 0x0a,   68 /* Public */,
      59,    1, 1204,    2, 0x0a,   70 /* Public */,
      60,    1, 1207,    2, 0x0a,   72 /* Public */,
      61,    1, 1210,    2, 0x0a,   74 /* Public */,
      62,    1, 1213,    2, 0x0a,   76 /* Public */,
      63,    1, 1216,    2, 0x0a,   78 /* Public */,
      64,    1, 1219,    2, 0x08,   80 /* Private */,
      67,    0, 1222,    2, 0x08,   82 /* Private */,
      68,    0, 1223,    2, 0x08,   83 /* Private */,
      69,    3, 1224,    2, 0x08,   84 /* Private */,
      74,    0, 1231,    2, 0x08,   88 /* Private */,
      75,    3, 1232,    2, 0x08,   89 /* Private */,
      76,    0, 1239,    2, 0x08,   93 /* Private */,
      77,    1, 1240,    2, 0x08,   94 /* Private */,
      77,    0, 1243,    2, 0x08,   96 /* Private */,
      78,    0, 1244,    2, 0x08,   97 /* Private */,
      79,    0, 1245,    2, 0x08,   98 /* Private */,
      80,    0, 1246,    2, 0x08,   99 /* Private */,
      81,    0, 1247,    2, 0x08,  100 /* Private */,
      82,    0, 1248,    2, 0x08,  101 /* Private */,
      83,    1, 1249,    2, 0x08,  102 /* Private */,
      84,    0, 1252,    2, 0x08,  104 /* Private */,
      85,    0, 1253,    2, 0x08,  105 /* Private */,
      86,    0, 1254,    2, 0x08,  106 /* Private */,
      87,    0, 1255,    2, 0x08,  107 /* Private */,
      88,    0, 1256,    2, 0x08,  108 /* Private */,
      89,    0, 1257,    2, 0x08,  109 /* Private */,
      90,    2, 1258,    2, 0x08,  110 /* Private */,
      90,    1, 1263,    2, 0x28,  113 /* Private | MethodCloned */,
      93,    0, 1266,    2, 0x08,  115 /* Private */,
      94,    0, 1267,    2, 0x08,  116 /* Private */,
      95,    1, 1268,    2, 0x08,  117 /* Private */,
      95,    0, 1271,    2, 0x28,  119 /* Private | MethodCloned */,
      98,    0, 1272,    2, 0x08,  120 /* Private */,
      99,    1, 1273,    2, 0x08,  121 /* Private */,
     101,    0, 1276,    2, 0x08,  123 /* Private */,
     102,    0, 1277,    2, 0x08,  124 /* Private */,
     103,    0, 1278,    2, 0x08,  125 /* Private */,
     104,    0, 1279,    2, 0x08,  126 /* Private */,
     105,    2, 1280,    2, 0x08,  127 /* Private */,
     105,    1, 1285,    2, 0x28,  130 /* Private | MethodCloned */,
     109,    1, 1288,    2, 0x08,  132 /* Private */,
     111,    0, 1291,    2, 0x08,  134 /* Private */,
     112,    0, 1292,    2, 0x08,  135 /* Private */,
     113,    0, 1293,    2, 0x08,  136 /* Private */,
     114,    0, 1294,    2, 0x08,  137 /* Private */,
     115,    0, 1295,    2, 0x08,  138 /* Private */,
     116,    1, 1296,    2, 0x08,  139 /* Private */,
     119,    1, 1299,    2, 0x08,  141 /* Private */,
     120,    2, 1302,    2, 0x08,  143 /* Private */,
     122,    0, 1307,    2, 0x08,  146 /* Private */,
     123,    1, 1308,    2, 0x08,  147 /* Private */,
     123,    0, 1311,    2, 0x28,  149 /* Private | MethodCloned */,
     125,    0, 1312,    2, 0x08,  150 /* Private */,
     126,    2, 1313,    2, 0x08,  151 /* Private */,
     127,    0, 1318,    2, 0x08,  154 /* Private */,
     128,    1, 1319,    2, 0x08,  155 /* Private */,
     130,    3, 1322,    2, 0x08,  157 /* Private */,
     135,    3, 1329,    2, 0x08,  161 /* Private */,
     139,    3, 1336,    2, 0x08,  165 /* Private */,
     139,    0, 1343,    2, 0x08,  169 /* Private */,
     141,    0, 1344,    2, 0x08,  170 /* Private */,
     142,    0, 1345,    2, 0x08,  171 /* Private */,
     143,    0, 1346,    2, 0x08,  172 /* Private */,
     144,    0, 1347,    2, 0x08,  173 /* Private */,
     145,    0, 1348,    2, 0x08,  174 /* Private */,
     146,    0, 1349,    2, 0x08,  175 /* Private */,
     147,    0, 1350,    2, 0x08,  176 /* Private */,
     148,    1, 1351,    2, 0x08,  177 /* Private */,
     151,    0, 1354,    2, 0x08,  179 /* Private */,
     152,    0, 1355,    2, 0x08,  180 /* Private */,
     153,    0, 1356,    2, 0x08,  181 /* Private */,
     154,    1, 1357,    2, 0x08,  182 /* Private */,
     155,    2, 1360,    2, 0x08,  184 /* Private */,
     159,    3, 1365,    2, 0x08,  187 /* Private */,
     161,    0, 1372,    2, 0x08,  191 /* Private */,
     162,    1, 1373,    2, 0x08,  192 /* Private */,
     163,    0, 1376,    2, 0x08,  194 /* Private */,
     164,    0, 1377,    2, 0x08,  195 /* Private */,
     165,    1, 1378,    2, 0x08,  196 /* Private */,
     166,    1, 1381,    2, 0x08,  198 /* Private */,
     168,    0, 1384,    2, 0x08,  200 /* Private */,
     169,    1, 1385,    2, 0x08,  201 /* Private */,
     171,    1, 1388,    2, 0x08,  203 /* Private */,
     172,    1, 1391,    2, 0x08,  205 /* Private */,
     173,    1, 1394,    2, 0x08,  207 /* Private */,
     175,    0, 1397,    2, 0x08,  209 /* Private */,
     176,    0, 1398,    2, 0x08,  210 /* Private */,
     177,    0, 1399,    2, 0x08,  211 /* Private */,
     178,    0, 1400,    2, 0x08,  212 /* Private */,
     179,    1, 1401,    2, 0x08,  213 /* Private */,
     179,    0, 1404,    2, 0x28,  215 /* Private | MethodCloned */,
     181,    0, 1405,    2, 0x08,  216 /* Private */,
     182,    1, 1406,    2, 0x08,  217 /* Private */,
     182,    0, 1409,    2, 0x28,  219 /* Private | MethodCloned */,
     184,    0, 1410,    2, 0x08,  220 /* Private */,
     185,    0, 1411,    2, 0x08,  221 /* Private */,
     186,    0, 1412,    2, 0x08,  222 /* Private */,
     187,    0, 1413,    2, 0x08,  223 /* Private */,
     188,    0, 1414,    2, 0x08,  224 /* Private */,
     189,    0, 1415,    2, 0x08,  225 /* Private */,
     190,    0, 1416,    2, 0x08,  226 /* Private */,
     191,    0, 1417,    2, 0x08,  227 /* Private */,
     192,    2, 1418,    2, 0x08,  228 /* Private */,
     194,    0, 1423,    2, 0x08,  231 /* Private */,
     195,    0, 1424,    2, 0x08,  232 /* Private */,
     196,    0, 1425,    2, 0x08,  233 /* Private */,
     197,    0, 1426,    2, 0x08,  234 /* Private */,
     198,    4, 1427,    2, 0x08,  235 /* Private */,
     198,    3, 1436,    2, 0x28,  240 /* Private | MethodCloned */,
     198,    1, 1443,    2, 0x08,  244 /* Private */,
     203,    3, 1446,    2, 0x08,  246 /* Private */,
     208,    2, 1453,    2, 0x08,  250 /* Private */,
     209,    0, 1458,    2, 0x08,  253 /* Private */,
     210,    0, 1459,    2, 0x08,  254 /* Private */,
     211,    0, 1460,    2, 0x08,  255 /* Private */,
     212,    0, 1461,    2, 0x08,  256 /* Private */,
     213,    0, 1462,    2, 0x08,  257 /* Private */,
     214,    0, 1463,    2, 0x08,  258 /* Private */,
     215,    0, 1464,    2, 0x08,  259 /* Private */,
     216,    0, 1465,    2, 0x08,  260 /* Private */,
     217,    1, 1466,    2, 0x08,  261 /* Private */,
     219,    0, 1469,    2, 0x08,  263 /* Private */,
     220,    0, 1470,    2, 0x08,  264 /* Private */,
     221,    0, 1471,    2, 0x08,  265 /* Private */,
     222,    0, 1472,    2, 0x08,  266 /* Private */,
     223,    2, 1473,    2, 0x08,  267 /* Private */,
     224,    2, 1478,    2, 0x08,  270 /* Private */,
     225,    1, 1483,    2, 0x08,  273 /* Private */,
     227,    2, 1486,    2, 0x08,  275 /* Private */,
     228,    2, 1491,    2, 0x08,  278 /* Private */,
     231,    0, 1496,    2, 0x08,  281 /* Private */,
     232,    0, 1497,    2, 0x08,  282 /* Private */,
     234,    0, 1498,    2, 0x08,  283 /* Private */,
     236,    0, 1499,    2, 0x08,  284 /* Private */,
     238,    2, 1500,    2, 0x08,  285 /* Private */,
     239,    2, 1505,    2, 0x08,  288 /* Private */,
     240,    0, 1510,    2, 0x08,  291 /* Private */,
     241,    0, 1511,    2, 0x08,  292 /* Private */,
     242,    0, 1512,    2, 0x08,  293 /* Private */,
     243,    0, 1513,    2, 0x08,  294 /* Private */,
     244,    0, 1514,    2, 0x08,  295 /* Private */,
     245,    0, 1515,    2, 0x08,  296 /* Private */,
     246,    0, 1516,    2, 0x08,  297 /* Private */,
     247,    1, 1517,    2, 0x08,  298 /* Private */,
     248,    2, 1520,    2, 0x08,  300 /* Private */,
     249,    2, 1525,    2, 0x08,  303 /* Private */,
     252,    0, 1530,    2, 0x08,  306 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QByteArray,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 17, QMetaType::Bool,   18,   19,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::UInt, QMetaType::Bool,   21,   22,   23,   24,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::UInt,   21,   22,   23,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   21,   22,
    QMetaType::Bool, QMetaType::QString,   21,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   26,   27,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 34,    2,
    QMetaType::Void, 0x80000000 | 34,    2,
    QMetaType::Void, 0x80000000 | 34,    2,
    QMetaType::Void, 0x80000000 | 34,   38,
    QMetaType::Void, 0x80000000 | 34,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 46, 0x80000000 | 48, 0x80000000 | 46, 0x80000000 | 48, 0x80000000 | 48, 0x80000000 | 46,   45,   47,   49,   50,   51,   52,   53,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, 0x80000000 | 65,   66,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 70, QMetaType::VoidStar, QMetaType::VoidStar,   71,   72,   73,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 70, QMetaType::VoidStar, QMetaType::VoidStar,   71,   72,   73,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString, QMetaType::Int,   91,   92,
    QMetaType::QString, QMetaType::QString,   91,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 96,   97,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  100,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 106, QMetaType::Bool,  107,  108,
    QMetaType::Void, 0x80000000 | 106,  107,
    QMetaType::Void, QMetaType::Int,  110,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 117, QMetaType::QString,  118,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,  100,  121,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  124,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  129,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 132, 0x80000000 | 134,  131,  133,   23,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 137, QMetaType::VoidStar,  136,  138,   73,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::VoidStar,  140,  138,   73,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 149,  150,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 156, QMetaType::Int,  157,  158,
    QMetaType::Void, 0x80000000 | 156, QMetaType::Int, QMetaType::UInt,  157,  158,  160,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  158,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  158,
    QMetaType::Void, QMetaType::QString,  167,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 170,  133,
    QMetaType::Void, 0x80000000 | 170,  133,
    QMetaType::Void, 0x80000000 | 170,  133,
    QMetaType::Void, QMetaType::Bool,  174,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  180,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  183,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 132, 0x80000000 | 134,  133,  193,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::UInt, QMetaType::UInt, QMetaType::Bool,  199,  200,  201,  202,
    QMetaType::Void, QMetaType::Int, QMetaType::UInt, QMetaType::UInt,  199,  200,  201,
    QMetaType::Void, QMetaType::Int,  199,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 205, QMetaType::QVariantList,  204,  206,  207,
    QMetaType::Void, 0x80000000 | 137, QMetaType::VoidStar,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  218,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 137, QMetaType::VoidStar,  138,    2,
    QMetaType::Void, 0x80000000 | 137, QMetaType::VoidStar,  138,    2,
    QMetaType::Void, 0x80000000 | 137,  226,
    QMetaType::Void, 0x80000000 | 137, QMetaType::VoidStar,    2,    2,
    QMetaType::Void, 0x80000000 | 229, QMetaType::QString,  230,    2,
    QMetaType::Void,
    0x80000000 | 233,
    0x80000000 | 235,
    0x80000000 | 237,
    QMetaType::Void, 0x80000000 | 137, QMetaType::VoidStar,  138,    2,
    QMetaType::Void, 0x80000000 | 137, QMetaType::VoidStar,  138,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  158,
    QMetaType::Void, 0x80000000 | 17, QMetaType::Bool,   18,   19,
    QMetaType::QString, 0x80000000 | 250, QMetaType::Bool,   56,  251,
    QMetaType::Void,

       0        // eod
};

void WiresharkMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WiresharkMainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setDissectedCaptureFile((*reinterpret_cast< std::add_pointer_t<capture_file*>>(_a[1]))); break;
        case 1: _t->closePacketDialogs(); break;
        case 2: _t->reloadFields(); break;
        case 3: _t->packetInfoChanged((*reinterpret_cast< std::add_pointer_t<_packet_info*>>(_a[1]))); break;
        case 4: _t->fieldFilterChanged((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 5: _t->selectRtpStream((*reinterpret_cast< std::add_pointer_t<rtpstream_id_t*>>(_a[1]))); break;
        case 6: _t->deselectRtpStream((*reinterpret_cast< std::add_pointer_t<rtpstream_id_t*>>(_a[1]))); break;
        case 7: _t->showExtcapOptions((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 8: { bool _r = _t->openCaptureFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->openCaptureFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->openCaptureFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->openCaptureFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->openCaptureFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->filterPackets((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 14: _t->filterPackets((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->filterPackets(); break;
        case 16: _t->layoutToolbars(); break;
        case 17: _t->updatePreferenceActions(); break;
        case 18: _t->updateRecentActions(); break;
        case 19: _t->setTitlebarForCaptureFile(); break;
        case 20: _t->showCaptureOptionsDialog(); break;
        case 21: _t->captureCapturePrepared((*reinterpret_cast< std::add_pointer_t<capture_session*>>(_a[1]))); break;
        case 22: _t->captureCaptureUpdateStarted((*reinterpret_cast< std::add_pointer_t<capture_session*>>(_a[1]))); break;
        case 23: _t->captureCaptureUpdateFinished((*reinterpret_cast< std::add_pointer_t<capture_session*>>(_a[1]))); break;
        case 24: _t->captureCaptureFixedFinished((*reinterpret_cast< std::add_pointer_t<capture_session*>>(_a[1]))); break;
        case 25: _t->captureCaptureFailed((*reinterpret_cast< std::add_pointer_t<capture_session*>>(_a[1]))); break;
        case 26: _t->captureFileOpened(); break;
        case 27: _t->captureFileReadFinished(); break;
        case 28: _t->captureFileClosing(); break;
        case 29: _t->captureFileClosed(); break;
        case 30: _t->launchRLCGraph((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<uint16_t>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[7]))); break;
        case 31: _t->rtpPlayerDialogReplaceRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 32: _t->rtpPlayerDialogAddRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 33: _t->rtpPlayerDialogRemoveRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 34: _t->rtpAnalysisDialogReplaceRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 35: _t->rtpAnalysisDialogAddRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 36: _t->rtpAnalysisDialogRemoveRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 37: _t->rtpStreamsDialogSelectRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 38: _t->rtpStreamsDialogDeselectRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>>>(_a[1]))); break;
        case 39: _t->captureEventHandler((*reinterpret_cast< std::add_pointer_t<CaptureEvent>>(_a[1]))); break;
        case 40: _t->initViewColorizeMenu(); break;
        case 41: _t->initConversationMenus(); break;
        case 42: { bool _r = _t->addExportObjectsMenuItem((*reinterpret_cast< std::add_pointer_t<const void*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 43: _t->initExportObjectsMenus(); break;
        case 44: { bool _r = _t->addFollowStreamMenuItem((*reinterpret_cast< std::add_pointer_t<const void*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 45: _t->initFollowStreamMenus(); break;
        case 46: _t->startCapture((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 47: _t->startCapture(); break;
        case 48: _t->pushLiveCaptureInProgress(); break;
        case 49: _t->popLiveCaptureInProgress(); break;
        case 50: _t->stopCapture(); break;
        case 51: _t->loadWindowGeometry(); break;
        case 52: _t->saveWindowGeometry(); break;
        case 53: _t->mainStackChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 54: _t->updateRecentCaptures(); break;
        case 55: _t->recentActionTriggered(); break;
        case 56: _t->addPacketComment(); break;
        case 57: _t->editPacketComment(); break;
        case 58: _t->deletePacketComment(); break;
        case 59: _t->deleteCommentsFromPackets(); break;
        case 60: { QString _r = _t->commentToMenuText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 61: { QString _r = _t->commentToMenuText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 62: _t->setEditCommentsMenu(); break;
        case 63: _t->setMenusForSelectedPacket(); break;
        case 64: _t->setMenusForSelectedTreeRow((*reinterpret_cast< std::add_pointer_t<FieldInformation*>>(_a[1]))); break;
        case 65: _t->setMenusForSelectedTreeRow(); break;
        case 66: _t->interfaceSelectionChanged(); break;
        case 67: _t->captureFilterSyntaxChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 68: _t->redissectPackets(); break;
        case 69: _t->checkDisplayFilter(); break;
        case 70: _t->fieldsChanged(); break;
        case 71: _t->reloadLuaPlugins(); break;
        case 72: _t->showAccordionFrame((*reinterpret_cast< std::add_pointer_t<AccordionFrame*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 73: _t->showAccordionFrame((*reinterpret_cast< std::add_pointer_t<AccordionFrame*>>(_a[1]))); break;
        case 74: _t->showColumnEditor((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 75: _t->showPreferenceEditor(); break;
        case 76: _t->addStatsPluginsToMenu(); break;
        case 77: _t->addDynamicMenus(); break;
        case 78: _t->reloadDynamicMenus(); break;
        case 79: _t->addPluginIFStructures(); break;
        case 80: { QMenu* _r = _t->searchSubMenu((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QMenu**>(_a[0]) = std::move(_r); }  break;
        case 81: _t->activatePluginIFToolbar((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 82: _t->startInterfaceCapture((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 83: _t->applyGlobalCommandLineOptions(); break;
        case 84: _t->setFeaturesEnabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 85: _t->setFeaturesEnabled(); break;
        case 86: _t->on_actionNewDisplayFilterExpression_triggered(); break;
        case 87: _t->onFilterSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 88: _t->onFilterPreferences(); break;
        case 89: _t->onFilterEdit((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 90: _t->queuedFilterAction((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<FilterAction::Action>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<FilterAction::ActionType>>(_a[3]))); break;
        case 91: _t->openStatCommandDialog((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<const char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[3]))); break;
        case 92: _t->openTapParameterDialog((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[3]))); break;
        case 93: _t->openTapParameterDialog(); break;
        case 94: _t->connectFileMenuActions(); break;
        case 95: _t->exportPacketBytes(); break;
        case 96: _t->exportPDU(); break;
        case 97: _t->stripPacketHeaders(); break;
        case 98: _t->exportTLSSessionKeys(); break;
        case 99: _t->printFile(); break;
        case 100: _t->connectEditMenuActions(); break;
        case 101: _t->copySelectedItems((*reinterpret_cast< std::add_pointer_t<WiresharkMainWindow::CopySelected>>(_a[1]))); break;
        case 102: _t->findPacket(); break;
        case 103: _t->editTimeShift(); break;
        case 104: _t->editConfigurationProfiles(); break;
        case 105: _t->editTimeShiftFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 106: _t->addPacketCommentFinished((*reinterpret_cast< std::add_pointer_t<PacketCommentDialog*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 107: _t->editPacketCommentFinished((*reinterpret_cast< std::add_pointer_t<PacketCommentDialog*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[3]))); break;
        case 108: _t->deleteAllPacketComments(); break;
        case 109: _t->deleteAllPacketCommentsFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 110: _t->injectSecrets(); break;
        case 111: _t->discardAllSecrets(); break;
        case 112: _t->discardAllSecretsFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 113: _t->showPreferencesDialog((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 114: _t->connectViewMenuActions(); break;
        case 115: _t->showHideMainWidgets((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 116: _t->setTimestampFormat((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 117: _t->setTimestampPrecision((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 118: _t->setTimeDisplaySecondsWithHoursAndMinutes((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 119: _t->editResolvedName(); break;
        case 120: _t->setNameResolution(); break;
        case 121: _t->zoomText(); break;
        case 122: _t->showColoringRulesDialog(); break;
        case 123: _t->colorizeConversation((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 124: _t->colorizeConversation(); break;
        case 125: _t->colorizeActionTriggered(); break;
        case 126: _t->openPacketDialog((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 127: _t->openPacketDialog(); break;
        case 128: _t->reloadCaptureFileAsFormatOrCapture(); break;
        case 129: _t->reloadCaptureFile(); break;
        case 130: _t->connectGoMenuActions(); break;
        case 131: _t->setPreviousFocus(); break;
        case 132: _t->resetPreviousFocus(); break;
        case 133: _t->connectCaptureMenuActions(); break;
        case 134: _t->startCaptureTriggered(); break;
        case 135: _t->connectAnalyzeMenuActions(); break;
        case 136: _t->matchFieldFilter((*reinterpret_cast< std::add_pointer_t<FilterAction::Action>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<FilterAction::ActionType>>(_a[2]))); break;
        case 137: _t->applyFieldAsColumn(); break;
        case 138: _t->filterMenuAboutToShow(); break;
        case 139: _t->applyConversationFilter(); break;
        case 140: _t->applyExportObject(); break;
        case 141: _t->openFollowStreamDialog((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 142: _t->openFollowStreamDialog((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[3]))); break;
        case 143: _t->openFollowStreamDialog((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 144: _t->openIOGraph((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<uint>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<QVariant>>>(_a[3]))); break;
        case 145: _t->statCommandExpertInfo((*reinterpret_cast< std::add_pointer_t<const char*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[2]))); break;
        case 146: _t->connectHelpMenuActions(); break;
        case 147: _t->goToCancelClicked(); break;
        case 148: _t->goToGoClicked(); break;
        case 149: _t->goToLineEditReturnPressed(); break;
        case 150: _t->connectStatisticsMenuActions(); break;
        case 151: _t->showResolvedAddressesDialog(); break;
        case 152: _t->showConversationsDialog(); break;
        case 153: _t->showEndpointsDialog(); break;
        case 154: _t->openTcpStreamDialog((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 155: _t->openSCTPAllAssocsDialog(); break;
        case 156: _t->on_actionSCTPShowAllAssociations_triggered(); break;
        case 157: _t->on_actionSCTPAnalyseThisAssociation_triggered(); break;
        case 158: _t->on_actionSCTPFilterThisAssociation_triggered(); break;
        case 159: _t->statCommandMulticastStatistics((*reinterpret_cast< std::add_pointer_t<const char*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[2]))); break;
        case 160: _t->statCommandWlanStatistics((*reinterpret_cast< std::add_pointer_t<const char*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[2]))); break;
        case 161: _t->openStatisticsTreeDialog((*reinterpret_cast< std::add_pointer_t<const char*>>(_a[1]))); break;
        case 162: _t->statCommandIOGraph((*reinterpret_cast< std::add_pointer_t<const char*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[2]))); break;
        case 163: _t->showIOGraphDialog((*reinterpret_cast< std::add_pointer_t<io_graph_item_unit_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 164: _t->connectTelephonyMenuActions(); break;
        case 165: { RtpStreamDialog* _r = _t->openTelephonyRtpStreamsDialog();
            if (_a[0]) *reinterpret_cast< RtpStreamDialog**>(_a[0]) = std::move(_r); }  break;
        case 166: { RtpPlayerDialog* _r = _t->openTelephonyRtpPlayerDialog();
            if (_a[0]) *reinterpret_cast< RtpPlayerDialog**>(_a[0]) = std::move(_r); }  break;
        case 167: { RtpAnalysisDialog* _r = _t->openTelephonyRtpAnalysisDialog();
            if (_a[0]) *reinterpret_cast< RtpAnalysisDialog**>(_a[0]) = std::move(_r); }  break;
        case 168: _t->statCommandLteMacStatistics((*reinterpret_cast< std::add_pointer_t<const char*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[2]))); break;
        case 169: _t->statCommandLteRlcStatistics((*reinterpret_cast< std::add_pointer_t<const char*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[2]))); break;
        case 170: _t->openRtpStreamAnalysisDialog(); break;
        case 171: _t->openRtpPlayerDialog(); break;
        case 172: _t->connectWirelessMenuActions(); break;
        case 173: _t->connectToolsMenuActions(); break;
        case 174: _t->externalMenuItemTriggered(); break;
        case 175: _t->on_actionContextWikiProtocolPage_triggered(); break;
        case 176: _t->on_actionContextFilterFieldReference_triggered(); break;
        case 177: _t->extcap_options_finished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 178: _t->showExtcapOptionsDialog((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 179: { QString _r = _t->findRtpStreams((*reinterpret_cast< std::add_pointer_t<QList<rtpstream_id_t*>*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 180: _t->openTLSKeylogDialog(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 64:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FieldInformation* >(); break;
            }
            break;
        case 115:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        case 116:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        case 117:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        case 144:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<uint> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WiresharkMainWindow::*)(capture_file * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiresharkMainWindow::setDissectedCaptureFile)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WiresharkMainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiresharkMainWindow::closePacketDialogs)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WiresharkMainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiresharkMainWindow::reloadFields)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WiresharkMainWindow::*)(_packet_info * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiresharkMainWindow::packetInfoChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WiresharkMainWindow::*)(const QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiresharkMainWindow::fieldFilterChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (WiresharkMainWindow::*)(rtpstream_id_t * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiresharkMainWindow::selectRtpStream)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (WiresharkMainWindow::*)(rtpstream_id_t * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiresharkMainWindow::deselectRtpStream)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (WiresharkMainWindow::*)(QString & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiresharkMainWindow::showExtcapOptions)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject WiresharkMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<MainWindow::staticMetaObject>(),
    qt_meta_stringdata_WiresharkMainWindow.offsetsAndSize,
    qt_meta_data_WiresharkMainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_WiresharkMainWindow_t
, QtPrivate::TypeAndForceComplete<WiresharkMainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_file *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<_packet_info *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<rtpstream_id_t *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<rtpstream_id_t *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_session *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_session *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_session *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_session *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<capture_session *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint16_t, std::false_type>, QtPrivate::TypeAndForceComplete<uint8_t, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<CaptureEvent, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const void *, std::false_type>, QtPrivate::TypeAndForceComplete<void *, std::false_type>, QtPrivate::TypeAndForceComplete<void *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const void *, std::false_type>, QtPrivate::TypeAndForceComplete<void *, std::false_type>, QtPrivate::TypeAndForceComplete<void *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<FieldInformation *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<AccordionFrame *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<AccordionFrame *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMenu *, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::Action, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::ActionType, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const char *, std::false_type>, QtPrivate::TypeAndForceComplete<void *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>, QtPrivate::TypeAndForceComplete<void *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<WiresharkMainWindow::CopySelected, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<PacketCommentDialog *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<PacketCommentDialog *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<unsigned , std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAction *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAction *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAction *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::Action, std::false_type>, QtPrivate::TypeAndForceComplete<FilterAction::ActionType, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<unsigned , std::false_type>, QtPrivate::TypeAndForceComplete<unsigned , std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<unsigned , std::false_type>, QtPrivate::TypeAndForceComplete<unsigned , std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<uint>, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<QVariant>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const char *, std::false_type>, QtPrivate::TypeAndForceComplete<void *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const char *, std::false_type>, QtPrivate::TypeAndForceComplete<void *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const char *, std::false_type>, QtPrivate::TypeAndForceComplete<void *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const char *, std::false_type>, QtPrivate::TypeAndForceComplete<void *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<io_graph_item_unit_t, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<RtpStreamDialog *, std::false_type>, QtPrivate::TypeAndForceComplete<RtpPlayerDialog *, std::false_type>, QtPrivate::TypeAndForceComplete<RtpAnalysisDialog *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const char *, std::false_type>, QtPrivate::TypeAndForceComplete<void *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const char *, std::false_type>, QtPrivate::TypeAndForceComplete<void *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<rtpstream_id_t*> *, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *WiresharkMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WiresharkMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WiresharkMainWindow.stringdata0))
        return static_cast<void*>(this);
    return MainWindow::qt_metacast(_clname);
}

int WiresharkMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 181)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 181;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 181)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 181;
    }
    return _id;
}

// SIGNAL 0
void WiresharkMainWindow::setDissectedCaptureFile(capture_file * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WiresharkMainWindow::closePacketDialogs()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WiresharkMainWindow::reloadFields()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void WiresharkMainWindow::packetInfoChanged(_packet_info * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WiresharkMainWindow::fieldFilterChanged(const QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void WiresharkMainWindow::selectRtpStream(rtpstream_id_t * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void WiresharkMainWindow::deselectRtpStream(rtpstream_id_t * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void WiresharkMainWindow::showExtcapOptions(QString & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
