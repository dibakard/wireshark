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

#include "epan/tap.h"

void register_tap_listener_pinfo_stat_tree(void);

WS_DLL_PUBLIC_DEF const char plugin_version[] = PLUGIN_VERSION;
WS_DLL_PUBLIC_DEF const int plugin_want_major = VERSION_MAJOR;
WS_DLL_PUBLIC_DEF const int plugin_want_minor = VERSION_MINOR;

WS_DLL_PUBLIC void plugin_register(void);
WS_DLL_PUBLIC uint32_t plugin_describe(void);

uint32_t plugin_describe(void)
{
    return WS_PLUGIN_DESC_TAP_LISTENER;
}

void plugin_register(void)
{
    static tap_plugin plug_pinfo_stat_tree;

    plug_pinfo_stat_tree.register_tap_listener = register_tap_listener_pinfo_stat_tree;
    tap_register_plugin(&plug_pinfo_stat_tree);
}
