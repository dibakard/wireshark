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

void proto_register_ircomm(void);
void proto_register_irda(void);
void proto_register_irsir(void);
void proto_reg_handoff_irda(void);
void proto_reg_handoff_irsir(void);

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
    static proto_plugin plug_ircomm;

    plug_ircomm.register_protoinfo = proto_register_ircomm;
    plug_ircomm.register_handoff = NULL;
    proto_register_plugin(&plug_ircomm);
    static proto_plugin plug_irda;

    plug_irda.register_protoinfo = proto_register_irda;
    plug_irda.register_handoff = proto_reg_handoff_irda;
    proto_register_plugin(&plug_irda);
    static proto_plugin plug_irsir;

    plug_irsir.register_protoinfo = proto_register_irsir;
    plug_irsir.register_handoff = proto_reg_handoff_irsir;
    proto_register_plugin(&plug_irsir);
}
