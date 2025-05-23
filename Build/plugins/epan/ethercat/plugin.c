/*
 * Do not modify this file. Changes will be overwritten.
 *
 * Generated automatically from make-plugin-reg.py.
 */

#include "config.h"

#include <gmodule.h>

/* plugins are DLLs on Windows */
#define WS_BUILD_DLL
#include "ws_symbol_export.h"
#include <wsutil/plugins.h>

#include "epan/proto.h"

void proto_register_ams(void);
void proto_register_ecat(void);
void proto_register_ecat_mailbox(void);
void proto_register_esl(void);
void proto_register_ethercat_frame(void);
void proto_register_ioraw(void);
void proto_register_nv(void);
void proto_reg_handoff_ams(void);
void proto_reg_handoff_ecat(void);
void proto_reg_handoff_ecat_mailbox(void);
void proto_reg_handoff_esl(void);
void proto_reg_handoff_ethercat_frame(void);
void proto_reg_handoff_ioraw(void);
void proto_reg_handoff_nv(void);

WS_DLL_PUBLIC_DEF const char plugin_version[] = PLUGIN_VERSION;
WS_DLL_PUBLIC_DEF const int plugin_want_major = VERSION_MAJOR;
WS_DLL_PUBLIC_DEF const int plugin_want_minor = VERSION_MINOR;

WS_DLL_PUBLIC void plugin_register(void);
WS_DLL_PUBLIC uint32_t plugin_describe(void);

uint32_t plugin_describe(void)
{
    return WS_PLUGIN_DESC_DISSECTOR;
}

void plugin_register(void)
{
    static proto_plugin plug_ams;

    plug_ams.register_protoinfo = proto_register_ams;
    plug_ams.register_handoff = proto_reg_handoff_ams;
    proto_register_plugin(&plug_ams);
    static proto_plugin plug_ecat;

    plug_ecat.register_protoinfo = proto_register_ecat;
    plug_ecat.register_handoff = proto_reg_handoff_ecat;
    proto_register_plugin(&plug_ecat);
    static proto_plugin plug_ecat_mailbox;

    plug_ecat_mailbox.register_protoinfo = proto_register_ecat_mailbox;
    plug_ecat_mailbox.register_handoff = proto_reg_handoff_ecat_mailbox;
    proto_register_plugin(&plug_ecat_mailbox);
    static proto_plugin plug_esl;

    plug_esl.register_protoinfo = proto_register_esl;
    plug_esl.register_handoff = proto_reg_handoff_esl;
    proto_register_plugin(&plug_esl);
    static proto_plugin plug_ethercat_frame;

    plug_ethercat_frame.register_protoinfo = proto_register_ethercat_frame;
    plug_ethercat_frame.register_handoff = proto_reg_handoff_ethercat_frame;
    proto_register_plugin(&plug_ethercat_frame);
    static proto_plugin plug_ioraw;

    plug_ioraw.register_protoinfo = proto_register_ioraw;
    plug_ioraw.register_handoff = proto_reg_handoff_ioraw;
    proto_register_plugin(&plug_ioraw);
    static proto_plugin plug_nv;

    plug_nv.register_protoinfo = proto_register_nv;
    plug_nv.register_handoff = proto_reg_handoff_nv;
    proto_register_plugin(&plug_nv);
}
