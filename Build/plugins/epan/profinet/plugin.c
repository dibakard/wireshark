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

void proto_register_dcom_cba(void);
void proto_register_dcom_cba_acco(void);
void proto_register_pn_dcp(void);
void proto_register_pn_io(void);
void proto_register_pn_mrp(void);
void proto_register_pn_mrrt(void);
void proto_register_pn_ptcp(void);
void proto_register_pn_rt(void);
void proto_reg_handoff_dcom_cba(void);
void proto_reg_handoff_dcom_cba_acco(void);
void proto_reg_handoff_pn_dcp(void);
void proto_reg_handoff_pn_io(void);
void proto_reg_handoff_pn_mrp(void);
void proto_reg_handoff_pn_mrrt(void);
void proto_reg_handoff_pn_ptcp(void);
void proto_reg_handoff_pn_rt(void);

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
    static proto_plugin plug_dcom_cba;

    plug_dcom_cba.register_protoinfo = proto_register_dcom_cba;
    plug_dcom_cba.register_handoff = proto_reg_handoff_dcom_cba;
    proto_register_plugin(&plug_dcom_cba);
    static proto_plugin plug_dcom_cba_acco;

    plug_dcom_cba_acco.register_protoinfo = proto_register_dcom_cba_acco;
    plug_dcom_cba_acco.register_handoff = proto_reg_handoff_dcom_cba_acco;
    proto_register_plugin(&plug_dcom_cba_acco);
    static proto_plugin plug_pn_dcp;

    plug_pn_dcp.register_protoinfo = proto_register_pn_dcp;
    plug_pn_dcp.register_handoff = proto_reg_handoff_pn_dcp;
    proto_register_plugin(&plug_pn_dcp);
    static proto_plugin plug_pn_io;

    plug_pn_io.register_protoinfo = proto_register_pn_io;
    plug_pn_io.register_handoff = proto_reg_handoff_pn_io;
    proto_register_plugin(&plug_pn_io);
    static proto_plugin plug_pn_mrp;

    plug_pn_mrp.register_protoinfo = proto_register_pn_mrp;
    plug_pn_mrp.register_handoff = proto_reg_handoff_pn_mrp;
    proto_register_plugin(&plug_pn_mrp);
    static proto_plugin plug_pn_mrrt;

    plug_pn_mrrt.register_protoinfo = proto_register_pn_mrrt;
    plug_pn_mrrt.register_handoff = proto_reg_handoff_pn_mrrt;
    proto_register_plugin(&plug_pn_mrrt);
    static proto_plugin plug_pn_ptcp;

    plug_pn_ptcp.register_protoinfo = proto_register_pn_ptcp;
    plug_pn_ptcp.register_handoff = proto_reg_handoff_pn_ptcp;
    proto_register_plugin(&plug_pn_ptcp);
    static proto_plugin plug_pn_rt;

    plug_pn_rt.register_protoinfo = proto_register_pn_rt;
    plug_pn_rt.register_handoff = proto_reg_handoff_pn_rt;
    proto_register_plugin(&plug_pn_rt);
}
