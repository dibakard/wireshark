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

void proto_register_m2m(void);
void proto_register_mac_mgmt_msg(void);
void proto_register_mac_mgmt_msg_aas_beam(void);
void proto_register_mac_mgmt_msg_aas_fbck(void);
void proto_register_mac_mgmt_msg_arq_feedback(void);
void proto_register_mac_mgmt_msg_clk_cmp(void);
void proto_register_mac_mgmt_msg_dcd(void);
void proto_register_mac_mgmt_msg_dlmap(void);
void proto_register_mac_mgmt_msg_dreg_cmd(void);
void proto_register_mac_mgmt_msg_dreg_req(void);
void proto_register_mac_mgmt_msg_dsa(void);
void proto_register_mac_mgmt_msg_dsc(void);
void proto_register_mac_mgmt_msg_dsd(void);
void proto_register_mac_mgmt_msg_dsx_rvd(void);
void proto_register_mac_mgmt_msg_fpc(void);
void proto_register_mac_mgmt_msg_pkm(void);
void proto_register_mac_mgmt_msg_pmc_req(void);
void proto_register_mac_mgmt_msg_pmc_rsp(void);
void proto_register_mac_mgmt_msg_prc_lt_ctrl(void);
void proto_register_mac_mgmt_msg_reg_req(void);
void proto_register_mac_mgmt_msg_reg_rsp(void);
void proto_register_mac_mgmt_msg_rep(void);
void proto_register_mac_mgmt_msg_res_cmd(void);
void proto_register_mac_mgmt_msg_rng_req(void);
void proto_register_mac_mgmt_msg_rng_rsp(void);
void proto_register_mac_mgmt_msg_sbc(void);
void proto_register_mac_mgmt_msg_ucd(void);
void proto_register_mac_mgmt_msg_ulmap(void);
void proto_register_wimax(void);
void proto_reg_handoff_m2m(void);
void proto_reg_handoff_mac_mgmt_msg(void);
void proto_reg_handoff_mac_mgmt_msg_aas(void);
void proto_reg_handoff_mac_mgmt_msg_aas_beam(void);
void proto_reg_handoff_mac_mgmt_msg_arq(void);
void proto_reg_handoff_mac_mgmt_msg_clk_cmp(void);
void proto_reg_handoff_mac_mgmt_msg_dcd(void);
void proto_reg_handoff_mac_mgmt_msg_dlmap(void);
void proto_reg_handoff_mac_mgmt_msg_dreg(void);
void proto_reg_handoff_mac_mgmt_msg_dsa(void);
void proto_reg_handoff_mac_mgmt_msg_dsc(void);
void proto_reg_handoff_mac_mgmt_msg_dsd(void);
void proto_reg_handoff_mac_mgmt_msg_dsx_rvd(void);
void proto_reg_handoff_mac_mgmt_msg_fpc(void);
void proto_reg_handoff_mac_mgmt_msg_pkm(void);
void proto_reg_handoff_mac_mgmt_msg_pmc(void);
void proto_reg_handoff_mac_mgmt_msg_prc_lt_ctrl(void);
void proto_reg_handoff_mac_mgmt_msg_reg_req(void);
void proto_reg_handoff_mac_mgmt_msg_reg_rsp(void);
void proto_reg_handoff_mac_mgmt_msg_rep(void);
void proto_reg_handoff_mac_mgmt_msg_res_cmd(void);
void proto_reg_handoff_mac_mgmt_msg_rng_req(void);
void proto_reg_handoff_mac_mgmt_msg_rng_rsp(void);
void proto_reg_handoff_mac_mgmt_msg_sbc(void);
void proto_reg_handoff_mac_mgmt_msg_ucd(void);
void proto_reg_handoff_mac_mgmt_msg_ulmap(void);
void proto_reg_handoff_wimax(void);

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
    static proto_plugin plug_m2m;

    plug_m2m.register_protoinfo = proto_register_m2m;
    plug_m2m.register_handoff = proto_reg_handoff_m2m;
    proto_register_plugin(&plug_m2m);
    static proto_plugin plug_mac_mgmt_msg;

    plug_mac_mgmt_msg.register_protoinfo = proto_register_mac_mgmt_msg;
    plug_mac_mgmt_msg.register_handoff = proto_reg_handoff_mac_mgmt_msg;
    proto_register_plugin(&plug_mac_mgmt_msg);
    static proto_plugin plug_mac_mgmt_msg_aas_beam;

    plug_mac_mgmt_msg_aas_beam.register_protoinfo = proto_register_mac_mgmt_msg_aas_beam;
    plug_mac_mgmt_msg_aas_beam.register_handoff = proto_reg_handoff_mac_mgmt_msg_aas_beam;
    proto_register_plugin(&plug_mac_mgmt_msg_aas_beam);
    static proto_plugin plug_mac_mgmt_msg_aas_fbck;

    plug_mac_mgmt_msg_aas_fbck.register_protoinfo = proto_register_mac_mgmt_msg_aas_fbck;
    plug_mac_mgmt_msg_aas_fbck.register_handoff = NULL;
    proto_register_plugin(&plug_mac_mgmt_msg_aas_fbck);
    static proto_plugin plug_mac_mgmt_msg_arq_feedback;

    plug_mac_mgmt_msg_arq_feedback.register_protoinfo = proto_register_mac_mgmt_msg_arq_feedback;
    plug_mac_mgmt_msg_arq_feedback.register_handoff = NULL;
    proto_register_plugin(&plug_mac_mgmt_msg_arq_feedback);
    static proto_plugin plug_mac_mgmt_msg_clk_cmp;

    plug_mac_mgmt_msg_clk_cmp.register_protoinfo = proto_register_mac_mgmt_msg_clk_cmp;
    plug_mac_mgmt_msg_clk_cmp.register_handoff = proto_reg_handoff_mac_mgmt_msg_clk_cmp;
    proto_register_plugin(&plug_mac_mgmt_msg_clk_cmp);
    static proto_plugin plug_mac_mgmt_msg_dcd;

    plug_mac_mgmt_msg_dcd.register_protoinfo = proto_register_mac_mgmt_msg_dcd;
    plug_mac_mgmt_msg_dcd.register_handoff = proto_reg_handoff_mac_mgmt_msg_dcd;
    proto_register_plugin(&plug_mac_mgmt_msg_dcd);
    static proto_plugin plug_mac_mgmt_msg_dlmap;

    plug_mac_mgmt_msg_dlmap.register_protoinfo = proto_register_mac_mgmt_msg_dlmap;
    plug_mac_mgmt_msg_dlmap.register_handoff = proto_reg_handoff_mac_mgmt_msg_dlmap;
    proto_register_plugin(&plug_mac_mgmt_msg_dlmap);
    static proto_plugin plug_mac_mgmt_msg_dreg_cmd;

    plug_mac_mgmt_msg_dreg_cmd.register_protoinfo = proto_register_mac_mgmt_msg_dreg_cmd;
    plug_mac_mgmt_msg_dreg_cmd.register_handoff = NULL;
    proto_register_plugin(&plug_mac_mgmt_msg_dreg_cmd);
    static proto_plugin plug_mac_mgmt_msg_dreg_req;

    plug_mac_mgmt_msg_dreg_req.register_protoinfo = proto_register_mac_mgmt_msg_dreg_req;
    plug_mac_mgmt_msg_dreg_req.register_handoff = NULL;
    proto_register_plugin(&plug_mac_mgmt_msg_dreg_req);
    static proto_plugin plug_mac_mgmt_msg_dsa;

    plug_mac_mgmt_msg_dsa.register_protoinfo = proto_register_mac_mgmt_msg_dsa;
    plug_mac_mgmt_msg_dsa.register_handoff = proto_reg_handoff_mac_mgmt_msg_dsa;
    proto_register_plugin(&plug_mac_mgmt_msg_dsa);
    static proto_plugin plug_mac_mgmt_msg_dsc;

    plug_mac_mgmt_msg_dsc.register_protoinfo = proto_register_mac_mgmt_msg_dsc;
    plug_mac_mgmt_msg_dsc.register_handoff = proto_reg_handoff_mac_mgmt_msg_dsc;
    proto_register_plugin(&plug_mac_mgmt_msg_dsc);
    static proto_plugin plug_mac_mgmt_msg_dsd;

    plug_mac_mgmt_msg_dsd.register_protoinfo = proto_register_mac_mgmt_msg_dsd;
    plug_mac_mgmt_msg_dsd.register_handoff = proto_reg_handoff_mac_mgmt_msg_dsd;
    proto_register_plugin(&plug_mac_mgmt_msg_dsd);
    static proto_plugin plug_mac_mgmt_msg_dsx_rvd;

    plug_mac_mgmt_msg_dsx_rvd.register_protoinfo = proto_register_mac_mgmt_msg_dsx_rvd;
    plug_mac_mgmt_msg_dsx_rvd.register_handoff = proto_reg_handoff_mac_mgmt_msg_dsx_rvd;
    proto_register_plugin(&plug_mac_mgmt_msg_dsx_rvd);
    static proto_plugin plug_mac_mgmt_msg_fpc;

    plug_mac_mgmt_msg_fpc.register_protoinfo = proto_register_mac_mgmt_msg_fpc;
    plug_mac_mgmt_msg_fpc.register_handoff = proto_reg_handoff_mac_mgmt_msg_fpc;
    proto_register_plugin(&plug_mac_mgmt_msg_fpc);
    static proto_plugin plug_mac_mgmt_msg_pkm;

    plug_mac_mgmt_msg_pkm.register_protoinfo = proto_register_mac_mgmt_msg_pkm;
    plug_mac_mgmt_msg_pkm.register_handoff = proto_reg_handoff_mac_mgmt_msg_pkm;
    proto_register_plugin(&plug_mac_mgmt_msg_pkm);
    static proto_plugin plug_mac_mgmt_msg_pmc_req;

    plug_mac_mgmt_msg_pmc_req.register_protoinfo = proto_register_mac_mgmt_msg_pmc_req;
    plug_mac_mgmt_msg_pmc_req.register_handoff = NULL;
    proto_register_plugin(&plug_mac_mgmt_msg_pmc_req);
    static proto_plugin plug_mac_mgmt_msg_pmc_rsp;

    plug_mac_mgmt_msg_pmc_rsp.register_protoinfo = proto_register_mac_mgmt_msg_pmc_rsp;
    plug_mac_mgmt_msg_pmc_rsp.register_handoff = NULL;
    proto_register_plugin(&plug_mac_mgmt_msg_pmc_rsp);
    static proto_plugin plug_mac_mgmt_msg_prc_lt_ctrl;

    plug_mac_mgmt_msg_prc_lt_ctrl.register_protoinfo = proto_register_mac_mgmt_msg_prc_lt_ctrl;
    plug_mac_mgmt_msg_prc_lt_ctrl.register_handoff = proto_reg_handoff_mac_mgmt_msg_prc_lt_ctrl;
    proto_register_plugin(&plug_mac_mgmt_msg_prc_lt_ctrl);
    static proto_plugin plug_mac_mgmt_msg_reg_req;

    plug_mac_mgmt_msg_reg_req.register_protoinfo = proto_register_mac_mgmt_msg_reg_req;
    plug_mac_mgmt_msg_reg_req.register_handoff = proto_reg_handoff_mac_mgmt_msg_reg_req;
    proto_register_plugin(&plug_mac_mgmt_msg_reg_req);
    static proto_plugin plug_mac_mgmt_msg_reg_rsp;

    plug_mac_mgmt_msg_reg_rsp.register_protoinfo = proto_register_mac_mgmt_msg_reg_rsp;
    plug_mac_mgmt_msg_reg_rsp.register_handoff = proto_reg_handoff_mac_mgmt_msg_reg_rsp;
    proto_register_plugin(&plug_mac_mgmt_msg_reg_rsp);
    static proto_plugin plug_mac_mgmt_msg_rep;

    plug_mac_mgmt_msg_rep.register_protoinfo = proto_register_mac_mgmt_msg_rep;
    plug_mac_mgmt_msg_rep.register_handoff = proto_reg_handoff_mac_mgmt_msg_rep;
    proto_register_plugin(&plug_mac_mgmt_msg_rep);
    static proto_plugin plug_mac_mgmt_msg_res_cmd;

    plug_mac_mgmt_msg_res_cmd.register_protoinfo = proto_register_mac_mgmt_msg_res_cmd;
    plug_mac_mgmt_msg_res_cmd.register_handoff = proto_reg_handoff_mac_mgmt_msg_res_cmd;
    proto_register_plugin(&plug_mac_mgmt_msg_res_cmd);
    static proto_plugin plug_mac_mgmt_msg_rng_req;

    plug_mac_mgmt_msg_rng_req.register_protoinfo = proto_register_mac_mgmt_msg_rng_req;
    plug_mac_mgmt_msg_rng_req.register_handoff = proto_reg_handoff_mac_mgmt_msg_rng_req;
    proto_register_plugin(&plug_mac_mgmt_msg_rng_req);
    static proto_plugin plug_mac_mgmt_msg_rng_rsp;

    plug_mac_mgmt_msg_rng_rsp.register_protoinfo = proto_register_mac_mgmt_msg_rng_rsp;
    plug_mac_mgmt_msg_rng_rsp.register_handoff = proto_reg_handoff_mac_mgmt_msg_rng_rsp;
    proto_register_plugin(&plug_mac_mgmt_msg_rng_rsp);
    static proto_plugin plug_mac_mgmt_msg_sbc;

    plug_mac_mgmt_msg_sbc.register_protoinfo = proto_register_mac_mgmt_msg_sbc;
    plug_mac_mgmt_msg_sbc.register_handoff = proto_reg_handoff_mac_mgmt_msg_sbc;
    proto_register_plugin(&plug_mac_mgmt_msg_sbc);
    static proto_plugin plug_mac_mgmt_msg_ucd;

    plug_mac_mgmt_msg_ucd.register_protoinfo = proto_register_mac_mgmt_msg_ucd;
    plug_mac_mgmt_msg_ucd.register_handoff = proto_reg_handoff_mac_mgmt_msg_ucd;
    proto_register_plugin(&plug_mac_mgmt_msg_ucd);
    static proto_plugin plug_mac_mgmt_msg_ulmap;

    plug_mac_mgmt_msg_ulmap.register_protoinfo = proto_register_mac_mgmt_msg_ulmap;
    plug_mac_mgmt_msg_ulmap.register_handoff = proto_reg_handoff_mac_mgmt_msg_ulmap;
    proto_register_plugin(&plug_mac_mgmt_msg_ulmap);
    static proto_plugin plug_wimax;

    plug_wimax.register_protoinfo = proto_register_wimax;
    plug_wimax.register_handoff = proto_reg_handoff_wimax;
    proto_register_plugin(&plug_wimax);
}
