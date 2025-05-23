/* Do not modify this file. Changes will be overwritten.                      */
/* Generated automatically by the ASN.1 to Wireshark dissector compiler       */
/* packet-ansi_map.c                                                          */
/* asn2wrs.py -b -q -L -p ansi_map -c ./ansi_map.cnf -s ./packet-ansi_map-template -D . -O ../.. ansi_map.asn */

/* packet-ansi_map.c
 * Routines for ANSI 41 Mobile Application Part (IS41 MAP) dissection
 * Specications from 3GPP2 (www.3gpp2.org)
 * Based on the dissector by :
 * Michael Lum <mlum [AT] telostech.com>
 * In association with Telos Technology Inc.
 *
 * Copyright 2005 - 2009, Anders Broman <anders.broman@ericsson.com>
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Credit to Tomas Kukosa for developing the asn2wrs compiler.
 *
 * Title                3GPP2                   Other
 *
 *   Cellular Radiotelecommunications Intersystem Operations
 *                      3GPP2 N.S0005-0 v 1.0           ANSI/TIA/EIA-41-D
 *
 *   Network Support for MDN-Based Message Centers
 *                      3GPP2 N.S0024-0 v1.0    IS-841
 *
 *   Enhanced International Calling
 *                      3GPP2 N.S0027           IS-875
 *
 *   ANSI-41-D Miscellaneous Enhancements Revision 0
 *                      3GPP2 N.S0015           PN-3590 (ANSI-41-E)
 *
 *   Authentication Enhancements
 *                      3GPP2 N.S0014-0 v1.0    IS-778
 *
 *   Features In CDMA
 *                      3GPP2 N.S0010-0 v1.0    IS-735
 *
 *   OTASP and OTAPA
 *                      3GPP2 N.S0011-0 v1.0    IS-725-A
 *
 *   Circuit Mode Services
 *                      3GPP2 N.S0008-0 v1.0    IS-737
 *      XXX SecondInterMSCCircuitID not implemented, parameter ID conflicts with ISLP Information!
 *
 *   IMSI
 *                      3GPP2 N.S0009-0 v1.0    IS-751
 *
 *   WIN Phase 1
 *                      3GPP2 N.S0013-0 v1.0    IS-771
 *
 *       DCCH (Clarification of Audit Order with Forced
 *         Re-Registration in pre-TIA/EIA-136-A Implementation
 *                      3GPP2 A.S0017-B                 IS-730
 *
 *   UIM
 *                      3GPP2 N.S0003
 *
 *   WIN Phase 2
 *                      3GPP2 N.S0004-0 v1.0    IS-848
 *
 *   TIA/EIA-41-D Pre-Paid Charging
 *                      3GPP2 N.S0018-0 v1.0    IS-826
 *
 *   User Selective Call Forwarding
 *                      3GPP2 N.S0021-0 v1.0    IS-838
 *
 *
 *   Answer Hold
 *                      3GPP2 N.S0022-0 v1.0    IS-837
 *
 */

#include "config.h"

#include <epan/packet.h>
#include <epan/prefs.h>
#include <epan/expert.h>
#include <epan/tap.h>
#include <epan/stat_tap_ui.h>
#include <epan/asn1.h>
#include <epan/tfs.h>

#include <wsutil/array.h>

#include "packet-ber.h"
#include "packet-ansi_map.h"
#include "packet-ansi_a.h"
#include "packet-gsm_map.h"
#include "packet-tcap.h"
#include "packet-ansi_tcap.h"

#define PNAME  "ANSI Mobile Application Part"
#define PSNAME "ANSI MAP"
#define PFNAME "ansi_map"


void proto_register_ansi_map(void);
void proto_reg_handoff_ansi_map(void);

/* Preference settings */
#define MAX_SSN 254
static range_t *global_ssn_range;
#define ANSI_MAP_TID_ONLY            0
#define ANSI_MAP_TID_AND_SOURCE      1
#define ANSI_MAP_TID_SOURCE_AND_DEST 2
static int ansi_map_response_matching_type = ANSI_MAP_TID_AND_SOURCE;

static dissector_handle_t ansi_map_handle;

/* Initialize the protocol and registered fields */
static int ansi_map_tap;
static int proto_ansi_map;

#if 0
static int hf_ansi_map_op_code_fam;
static int hf_ansi_map_op_code;
#endif

static int hf_ansi_map_reservedBitH;
static int hf_ansi_map_reservedBitHG;
static int hf_ansi_map_reservedBitHGFE;
static int hf_ansi_map_reservedBitFED;
static int hf_ansi_map_reservedBitD;
static int hf_ansi_map_reservedBitED;

static int hf_ansi_map_type_of_digits;
static int hf_ansi_map_na;
static int hf_ansi_map_pi;
static int hf_ansi_map_navail;
static int hf_ansi_map_si;
static int hf_ansi_map_digits_enc;
static int hf_ansi_map_np;
static int hf_ansi_map_nr_digits;
static int hf_ansi_map_bcd_digits;
static int hf_ansi_map_ia5_digits;
static int hf_ansi_map_subaddr_type;
static int hf_ansi_map_subaddr_odd_even;
static int hf_ansi_alertcode_cadence;
static int hf_ansi_alertcode_pitch;
static int hf_ansi_alertcode_alertaction;
static int hf_ansi_map_announcementcode_tone;
static int hf_ansi_map_announcementcode_class;
static int hf_ansi_map_announcementcode_std_ann;
static int hf_ansi_map_announcementcode_cust_ann;
static int hf_ansi_map_authorizationperiod_period;
static int hf_ansi_map_value;
static int hf_ansi_map_msc_type;
static int hf_ansi_map_handoffstate_pi;
static int hf_ansi_map_tgn;
static int hf_ansi_map_tmn;
static int hf_ansi_map_messagewaitingnotificationcount_tom;
static int hf_ansi_map_messagewaitingnotificationcount_no_mw;
static int hf_ansi_map_messagewaitingnotificationtype_mwi;
static int hf_ansi_map_messagewaitingnotificationtype_apt;
static int hf_ansi_map_messagewaitingnotificationtype_pt;

static int hf_ansi_map_trans_cap_prof;
static int hf_ansi_map_trans_cap_busy;
static int hf_ansi_map_trans_cap_ann;
static int hf_ansi_map_trans_cap_rui;
static int hf_ansi_map_trans_cap_spini;
static int hf_ansi_map_trans_cap_uzci;
static int hf_ansi_map_trans_cap_ndss;
static int hf_ansi_map_trans_cap_nami;
static int hf_ansi_trans_cap_multerm;
static int hf_ansi_map_terminationtriggers_busy;
static int hf_ansi_map_terminationtriggers_rf;
static int hf_ansi_map_terminationtriggers_npr;
static int hf_ansi_map_terminationtriggers_na;
static int hf_ansi_map_terminationtriggers_nr;
static int hf_ansi_trans_cap_tl;
static int hf_ansi_map_cdmaserviceoption;
static int hf_ansi_trans_cap_waddr;
static int hf_ansi_map_MarketID;
static int hf_ansi_map_swno;
static int hf_ansi_map_idno;
static int hf_ansi_map_segcount;
static int hf_ansi_map_sms_originationrestrictions_fmc;
static int hf_ansi_map_sms_originationrestrictions_direct;
static int hf_ansi_map_sms_originationrestrictions_default;
static int hf_ansi_map_systemcapabilities_auth;
static int hf_ansi_map_systemcapabilities_se;
static int hf_ansi_map_systemcapabilities_vp;
static int hf_ansi_map_systemcapabilities_cave;
static int hf_ansi_map_systemcapabilities_ssd;
static int hf_ansi_map_systemcapabilities_dp;

static int hf_ansi_map_mslocation_lat;
static int hf_ansi_map_mslocation_long;
static int hf_ansi_map_mslocation_res;
static int hf_ansi_map_nampscallmode_namps;
static int hf_ansi_map_nampscallmode_amps;
static int hf_ansi_map_nampschanneldata_navca;
static int hf_ansi_map_nampschanneldata_CCIndicator;

static int hf_ansi_map_callingfeaturesindicator_cfufa;
static int hf_ansi_map_callingfeaturesindicator_cfbfa;
static int hf_ansi_map_callingfeaturesindicator_cfnafa;
static int hf_ansi_map_callingfeaturesindicator_cwfa;
static int hf_ansi_map_callingfeaturesindicator_3wcfa;
static int hf_ansi_map_callingfeaturesindicator_pcwfa;
static int hf_ansi_map_callingfeaturesindicator_dpfa;
static int hf_ansi_map_callingfeaturesindicator_ahfa;
static int hf_ansi_map_callingfeaturesindicator_uscfvmfa;
static int hf_ansi_map_callingfeaturesindicator_uscfmsfa;
static int hf_ansi_map_callingfeaturesindicator_uscfnrfa;
static int hf_ansi_map_callingfeaturesindicator_cpdsfa;
static int hf_ansi_map_callingfeaturesindicator_ccsfa;
static int hf_ansi_map_callingfeaturesindicator_epefa;
static int hf_ansi_map_callingfeaturesindicator_cdfa;
static int hf_ansi_map_callingfeaturesindicator_vpfa;
static int hf_ansi_map_callingfeaturesindicator_ctfa;
static int hf_ansi_map_callingfeaturesindicator_cnip1fa;
static int hf_ansi_map_callingfeaturesindicator_cnip2fa;
static int hf_ansi_map_callingfeaturesindicator_cnirfa;
static int hf_ansi_map_callingfeaturesindicator_cniroverfa;
static int hf_ansi_map_cdmacallmode_cdma;
static int hf_ansi_map_cdmacallmode_amps;
static int hf_ansi_map_cdmacallmode_namps;
static int hf_ansi_map_cdmacallmode_cls1;
static int hf_ansi_map_cdmacallmode_cls2;
static int hf_ansi_map_cdmacallmode_cls3;
static int hf_ansi_map_cdmacallmode_cls4;
static int hf_ansi_map_cdmacallmode_cls5;
static int hf_ansi_map_cdmacallmode_cls6;
static int hf_ansi_map_cdmacallmode_cls7;
static int hf_ansi_map_cdmacallmode_cls8;
static int hf_ansi_map_cdmacallmode_cls9;
static int hf_ansi_map_cdmacallmode_cls10;
static int hf_ansi_map_cdmachanneldata_Frame_Offset;
static int hf_ansi_map_cdmachanneldata_CDMA_ch_no;
static int hf_ansi_map_cdmachanneldata_band_cls;
static int hf_ansi_map_cdmachanneldata_lc_mask_b6;
static int hf_ansi_map_cdmachanneldata_lc_mask_b5;
static int hf_ansi_map_cdmachanneldata_lc_mask_b4;
static int hf_ansi_map_cdmachanneldata_lc_mask_b3;
static int hf_ansi_map_cdmachanneldata_lc_mask_b2;
static int hf_ansi_map_cdmachanneldata_lc_mask_b1;
static int hf_ansi_map_cdmachanneldata_np_ext;
static int hf_ansi_map_cdmachanneldata_nominal_pwr;
static int hf_ansi_map_cdmachanneldata_nr_preamble;

static int hf_ansi_map_cdmastationclassmark_pc;
static int hf_ansi_map_cdmastationclassmark_dtx;
static int hf_ansi_map_cdmastationclassmark_smi;
static int hf_ansi_map_cdmastationclassmark_dmi;
static int hf_ansi_map_channeldata_vmac;
static int hf_ansi_map_channeldata_dtx;
static int hf_ansi_map_channeldata_scc;
static int hf_ansi_map_channeldata_chno;
static int hf_ansi_map_ConfidentialityModes_vp;
static int hf_ansi_map_controlchanneldata_dcc;
static int hf_ansi_map_controlchanneldata_cmac;
static int hf_ansi_map_controlchanneldata_chno;
static int hf_ansi_map_controlchanneldata_sdcc1;
static int hf_ansi_map_controlchanneldata_sdcc2;
static int hf_ansi_map_ConfidentialityModes_se;
static int hf_ansi_map_deniedauthorizationperiod_period;
static int hf_ansi_map_ConfidentialityModes_dp;

static int hf_ansi_map_originationtriggers_all;
static int hf_ansi_map_originationtriggers_local;
static int hf_ansi_map_originationtriggers_ilata;
static int hf_ansi_map_originationtriggers_olata;
static int hf_ansi_map_originationtriggers_int;
static int hf_ansi_map_originationtriggers_wz;
static int hf_ansi_map_originationtriggers_unrec;
static int hf_ansi_map_originationtriggers_rvtc;
static int hf_ansi_map_originationtriggers_star;
static int hf_ansi_map_originationtriggers_ds;
static int hf_ansi_map_originationtriggers_pound;
static int hf_ansi_map_originationtriggers_dp;
static int hf_ansi_map_originationtriggers_pa;
static int hf_ansi_map_originationtriggers_nodig;
static int hf_ansi_map_originationtriggers_onedig;
static int hf_ansi_map_originationtriggers_twodig;
static int hf_ansi_map_originationtriggers_threedig;
static int hf_ansi_map_originationtriggers_fourdig;
static int hf_ansi_map_originationtriggers_fivedig;
static int hf_ansi_map_originationtriggers_sixdig;
static int hf_ansi_map_originationtriggers_sevendig;
static int hf_ansi_map_originationtriggers_eightdig;
static int hf_ansi_map_originationtriggers_ninedig;
static int hf_ansi_map_originationtriggers_tendig;
static int hf_ansi_map_originationtriggers_elevendig;
static int hf_ansi_map_originationtriggers_twelvedig;
static int hf_ansi_map_originationtriggers_thirteendig;
static int hf_ansi_map_originationtriggers_fourteendig;
static int hf_ansi_map_originationtriggers_fifteendig;
static int hf_ansi_map_triggercapability_init;
static int hf_ansi_map_triggercapability_kdigit;
static int hf_ansi_map_triggercapability_all;
static int hf_ansi_map_triggercapability_rvtc;
static int hf_ansi_map_triggercapability_oaa;
static int hf_ansi_map_triggercapability_oans;
static int hf_ansi_map_triggercapability_odisc;
static int hf_ansi_map_triggercapability_ona;
static int hf_ansi_map_triggercapability_ct;
static int hf_ansi_map_triggercapability_unrec;
static int hf_ansi_map_triggercapability_pa;
static int hf_ansi_map_triggercapability_at;
static int hf_ansi_map_triggercapability_cgraa;
static int hf_ansi_map_triggercapability_it;
static int hf_ansi_map_triggercapability_cdraa;
static int hf_ansi_map_triggercapability_obsy;
static int hf_ansi_map_triggercapability_tra;
static int hf_ansi_map_triggercapability_tbusy;
static int hf_ansi_map_triggercapability_tna;
static int hf_ansi_map_triggercapability_tans;
static int hf_ansi_map_triggercapability_tdisc;
static int hf_ansi_map_winoperationscapability_conn;
static int hf_ansi_map_winoperationscapability_ccdir;
static int hf_ansi_map_winoperationscapability_pos;
static int hf_ansi_map_PACA_Level;
static int hf_ansi_map_pacaindicator_pa;

static int hf_ansi_map_point_code;
static int hf_ansi_map_SSN;
static int hf_ansi_map_win_trigger_list;

static int hf_ansi_map_electronicSerialNumber;    /* ElectronicSerialNumber */
static int hf_ansi_map_msid;                      /* MSID */
static int hf_ansi_map_authenticationAlgorithmVersion;  /* AuthenticationAlgorithmVersion */
static int hf_ansi_map_authenticationResponseReauthentication;  /* AuthenticationResponseReauthentication */
static int hf_ansi_map_authenticationResponseUniqueChallenge;  /* AuthenticationResponseUniqueChallenge */
static int hf_ansi_map_callHistoryCount;          /* CallHistoryCount */
static int hf_ansi_map_cdmaPrivateLongCodeMask;   /* CDMAPrivateLongCodeMask */
static int hf_ansi_map_carrierDigits;             /* CarrierDigits */
static int hf_ansi_map_caveKey;                   /* CaveKey */
static int hf_ansi_map_denyAccess;                /* DenyAccess */
static int hf_ansi_map_destinationDigits;         /* DestinationDigits */
static int hf_ansi_map_locationAreaID;            /* LocationAreaID */
static int hf_ansi_map_randomVariableReauthentication;  /* RandomVariableReauthentication */
static int hf_ansi_map_meid;                      /* MEID */
static int hf_ansi_map_mobileStationMIN;          /* MobileStationMIN */
static int hf_ansi_map_mscid;                     /* MSCID */
static int hf_ansi_map_randomVariableSSD;         /* RandomVariableSSD */
static int hf_ansi_map_randomVariableUniqueChallenge;  /* RandomVariableUniqueChallenge */
static int hf_ansi_map_routingDigits;             /* RoutingDigits */
static int hf_ansi_map_senderIdentificationNumber;  /* SenderIdentificationNumber */
static int hf_ansi_map_sharedSecretData;          /* SharedSecretData */
static int hf_ansi_map_signalingMessageEncryptionKey;  /* SignalingMessageEncryptionKey */
static int hf_ansi_map_ssdnotShared;              /* SSDNotShared */
static int hf_ansi_map_updateCount;               /* UpdateCount */
static int hf_ansi_map_interMSCCircuitID;         /* InterMSCCircuitID */
static int hf_ansi_map_mobileIdentificationNumber;  /* MobileIdentificationNumber */
static int hf_ansi_map_countUpdateReport;         /* CountUpdateReport */
static int hf_ansi_map_uniqueChallengeReport;     /* UniqueChallengeReport */
static int hf_ansi_map_reportType;                /* ReportType */
static int hf_ansi_map_systemAccessType;          /* SystemAccessType */
static int hf_ansi_map_systemCapabilities;        /* SystemCapabilities */
static int hf_ansi_map_callHistoryCountExpected;  /* CallHistoryCountExpected */
static int hf_ansi_map_reportType2;               /* ReportType */
static int hf_ansi_map_terminalType;              /* TerminalType */
static int hf_ansi_map_authenticationData;        /* AuthenticationData */
static int hf_ansi_map_authenticationResponse;    /* AuthenticationResponse */
static int hf_ansi_map_cdmaNetworkIdentification;  /* CDMANetworkIdentification */
static int hf_ansi_map_confidentialityModes;      /* ConfidentialityModes */
static int hf_ansi_map_controlChannelMode;        /* ControlChannelMode */
static int hf_ansi_map_digits;                    /* Digits */
static int hf_ansi_map_pc_ssn;                    /* PC_SSN */
static int hf_ansi_map_randomVariable;            /* RandomVariable */
static int hf_ansi_map_serviceRedirectionCause;   /* ServiceRedirectionCause */
static int hf_ansi_map_suspiciousAccess;          /* SuspiciousAccess */
static int hf_ansi_map_transactionCapability;     /* TransactionCapability */
static int hf_ansi_map_analogRedirectRecord;      /* AnalogRedirectRecord */
static int hf_ansi_map_cdmaRedirectRecord;        /* CDMARedirectRecord */
static int hf_ansi_map_dataKey;                   /* DataKey */
static int hf_ansi_map_roamingIndication;         /* RoamingIndication */
static int hf_ansi_map_serviceRedirectionInfo;    /* ServiceRedirectionInfo */
static int hf_ansi_map_voicePrivacyMask;          /* VoicePrivacyMask */
static int hf_ansi_map_reauthenticationReport;    /* ReauthenticationReport */
static int hf_ansi_map_serviceIndicator;          /* ServiceIndicator */
static int hf_ansi_map_signalingMessageEncryptionReport;  /* SignalingMessageEncryptionReport */
static int hf_ansi_map_ssdUpdateReport;           /* SSDUpdateReport */
static int hf_ansi_map_voicePrivacyReport;        /* VoicePrivacyReport */
static int hf_ansi_map_randomVariableBaseStation;  /* RandomVariableBaseStation */
static int hf_ansi_map_authenticationResponseBaseStation;  /* AuthenticationResponseBaseStation */
static int hf_ansi_map_billingID;                 /* BillingID */
static int hf_ansi_map_channelData;               /* ChannelData */
static int hf_ansi_map_interSwitchCount;          /* InterSwitchCount */
static int hf_ansi_map_servingCellID;             /* ServingCellID */
static int hf_ansi_map_stationClassMark;          /* StationClassMark */
static int hf_ansi_map_targetCellID;              /* TargetCellID */
static int hf_ansi_map_handoffReason;             /* HandoffReason */
static int hf_ansi_map_handoffState;              /* HandoffState */
static int hf_ansi_map_tdmaBurstIndicator;        /* TDMABurstIndicator */
static int hf_ansi_map_tdmaCallMode;              /* TDMACallMode */
static int hf_ansi_map_tdmaChannelData;           /* TDMAChannelData */
static int hf_ansi_map_baseStationManufacturerCode;  /* BaseStationManufacturerCode */
static int hf_ansi_map_alertCode;                 /* AlertCode */
static int hf_ansi_map_cdma2000HandoffInvokeIOSData;  /* CDMA2000HandoffInvokeIOSData */
static int hf_ansi_map_cdmaBandClassList;         /* CDMABandClassList */
static int hf_ansi_map_cdmaCallMode;              /* CDMACallMode */
static int hf_ansi_map_cdmaChannelData;           /* CDMAChannelData */
static int hf_ansi_map_cdmaConnectionReferenceList;  /* CDMAConnectionReferenceList */
static int hf_ansi_map_cdmaMobileProtocolRevision;  /* CDMAMobileProtocolRevision */
static int hf_ansi_map_cdmaMSMeasuredChannelIdentity;  /* CDMAMSMeasuredChannelIdentity */
static int hf_ansi_map_cdmaServiceConfigurationRecord;  /* CDMAServiceConfigurationRecord */
static int hf_ansi_map_cdmaServiceOptionList;     /* CDMAServiceOptionList */
static int hf_ansi_map_cdmaServingOneWayDelay;    /* CDMAServingOneWayDelay */
static int hf_ansi_map_cdmaStationClassMark;      /* CDMAStationClassMark */
static int hf_ansi_map_cdmaStationClassMark2;     /* CDMAStationClassMark2 */
static int hf_ansi_map_cdmaTargetMAHOList;        /* CDMATargetMAHOList */
static int hf_ansi_map_cdmaTargetMeasurementList;  /* CDMATargetMeasurementList */
static int hf_ansi_map_dataPrivacyParameters;     /* DataPrivacyParameters */
static int hf_ansi_map_ilspInformation;           /* ISLPInformation */
static int hf_ansi_map_msLocation;                /* MSLocation */
static int hf_ansi_map_nampsCallMode;             /* NAMPSCallMode */
static int hf_ansi_map_nampsChannelData;          /* NAMPSChannelData */
static int hf_ansi_map_nonPublicData;             /* NonPublicData */
static int hf_ansi_map_pdsnAddress;               /* PDSNAddress */
static int hf_ansi_map_pdsnProtocolType;          /* PDSNProtocolType */
static int hf_ansi_map_qosPriority;               /* QoSPriority */
static int hf_ansi_map_systemOperatorCode;        /* SystemOperatorCode */
static int hf_ansi_map_tdmaBandwidth;             /* TDMABandwidth */
static int hf_ansi_map_tdmaServiceCode;           /* TDMAServiceCode */
static int hf_ansi_map_tdmaTerminalCapability;    /* TDMATerminalCapability */
static int hf_ansi_map_tdmaVoiceCoder;            /* TDMAVoiceCoder */
static int hf_ansi_map_userZoneData;              /* UserZoneData */
static int hf_ansi_map_bsmcstatus;                /* BSMCStatus */
static int hf_ansi_map_cdma2000HandoffResponseIOSData;  /* CDMA2000HandoffResponseIOSData */
static int hf_ansi_map_cdmaCodeChannelList;       /* CDMACodeChannelList */
static int hf_ansi_map_cdmaSearchParameters;      /* CDMASearchParameters */
static int hf_ansi_map_cdmaSearchWindow;          /* CDMASearchWindow */
static int hf_ansi_map_sOCStatus;                 /* SOCStatus */
static int hf_ansi_map_releaseReason;             /* ReleaseReason */
static int hf_ansi_map_acgencountered;            /* ACGEncountered */
static int hf_ansi_map_callingPartyName;          /* CallingPartyName */
static int hf_ansi_map_callingPartyNumberDigits1;  /* CallingPartyNumberDigits1 */
static int hf_ansi_map_callingPartyNumberDigits2;  /* CallingPartyNumberDigits2 */
static int hf_ansi_map_callingPartySubaddress;    /* CallingPartySubaddress */
static int hf_ansi_map_conferenceCallingIndicator;  /* ConferenceCallingIndicator */
static int hf_ansi_map_mobileDirectoryNumber;     /* MobileDirectoryNumber */
static int hf_ansi_map_mSCIdentificationNumber;   /* MSCIdentificationNumber */
static int hf_ansi_map_oneTimeFeatureIndicator;   /* OneTimeFeatureIndicator */
static int hf_ansi_map_systemMyTypeCode;          /* SystemMyTypeCode */
static int hf_ansi_map_featureResult;             /* FeatureResult */
static int hf_ansi_map_accessDeniedReason;        /* AccessDeniedReason */
static int hf_ansi_map_actionCode;                /* ActionCode */
static int hf_ansi_map_announcementList;          /* AnnouncementList */
static int hf_ansi_map_callingPartyNumberString1;  /* CallingPartyNumberString1 */
static int hf_ansi_map_callingPartyNumberString2;  /* CallingPartyNumberString2 */
static int hf_ansi_map_digits_Destination;        /* Digits */
static int hf_ansi_map_displayText;               /* DisplayText */
static int hf_ansi_map_displayText2;              /* DisplayText2 */
static int hf_ansi_map_dmh_AccountCodeDigits;     /* DMH_AccountCodeDigits */
static int hf_ansi_map_dmh_AlternateBillingDigits;  /* DMH_AlternateBillingDigits */
static int hf_ansi_map_dmh_BillingDigits;         /* DMH_BillingDigits */
static int hf_ansi_map_dmh_RedirectionIndicator;  /* DMH_RedirectionIndicator */
static int hf_ansi_map_groupInformation;          /* GroupInformation */
static int hf_ansi_map_noAnswerTime;              /* NoAnswerTime */
static int hf_ansi_map_pACAIndicator;             /* PACAIndicator */
static int hf_ansi_map_pilotNumber;               /* PilotNumber */
static int hf_ansi_map_preferredLanguageIndicator;  /* PreferredLanguageIndicator */
static int hf_ansi_map_redirectingNumberDigits;   /* RedirectingNumberDigits */
static int hf_ansi_map_redirectingNumberString;   /* RedirectingNumberString */
static int hf_ansi_map_redirectingSubaddress;     /* RedirectingSubaddress */
static int hf_ansi_map_resumePIC;                 /* ResumePIC */
static int hf_ansi_map_terminationList;           /* TerminationList */
static int hf_ansi_map_terminationTriggers;       /* TerminationTriggers */
static int hf_ansi_map_triggerAddressList;        /* TriggerAddressList */
static int hf_ansi_map_emergencyServicesRoutingDigits;  /* EmergencyServicesRoutingDigits */
static int hf_ansi_map_targetCellIDList;          /* TargetCellIDList */
static int hf_ansi_map_signalQuality;             /* SignalQuality */
static int hf_ansi_map_targetMeasurementList;     /* TargetMeasurementList */
static int hf_ansi_map_alertResult;               /* AlertResult */
static int hf_ansi_map_messageWaitingNotificationCount;  /* MessageWaitingNotificationCount */
static int hf_ansi_map_messageWaitingNotificationType;  /* MessageWaitingNotificationType */
static int hf_ansi_map_cdmaBandClass;             /* CDMABandClass */
static int hf_ansi_map_cdmaServiceOption;         /* CDMAServiceOption */
static int hf_ansi_map_cdmaSlotCycleIndex;        /* CDMASlotCycleIndex */
static int hf_ansi_map_extendedMSCID;             /* ExtendedMSCID */
static int hf_ansi_map_extendedSystemMyTypeCode;  /* ExtendedSystemMyTypeCode */
static int hf_ansi_map_imsi;                      /* IMSI */
static int hf_ansi_map_legInformation;            /* LegInformation */
static int hf_ansi_map_mSIDUsage;                 /* MSIDUsage */
static int hf_ansi_map_networkTMSI;               /* NetworkTMSI */
static int hf_ansi_map_pageCount;                 /* PageCount */
static int hf_ansi_map_pageIndicator;             /* PageIndicator */
static int hf_ansi_map_pageResponseTime;          /* PageResponseTime */
static int hf_ansi_map_pilotBillingID;            /* PilotBillingID */
static int hf_ansi_map_redirectingPartyName;      /* RedirectingPartyName */
static int hf_ansi_map_tdmaDataFeaturesIndicator;  /* TDMADataFeaturesIndicator */
static int hf_ansi_map_terminationTreatment;      /* TerminationTreatment */
static int hf_ansi_map_conditionallyDeniedReason;  /* ConditionallyDeniedReason */
static int hf_ansi_map_pagingFrameClass;          /* PagingFrameClass */
static int hf_ansi_map_pSID_RSIDList;             /* PSID_RSIDList */
static int hf_ansi_map_randc;                     /* RANDC */
static int hf_ansi_map_tdmaDataMode;              /* TDMADataMode */
static int hf_ansi_map_changeServiceAttributes;   /* ChangeServiceAttributes */
static int hf_ansi_map_edirectingSubaddress;      /* RedirectingSubaddress */
static int hf_ansi_map_setupResult;               /* SetupResult */
static int hf_ansi_map_terminationAccessType;     /* TerminationAccessType */
static int hf_ansi_map_triggerType;               /* TriggerType */
static int hf_ansi_map_winCapability;             /* WINCapability */
static int hf_ansi_map_callingPartyCategory;      /* CallingPartyCategory */
static int hf_ansi_map_controlNetworkID;          /* ControlNetworkID */
static int hf_ansi_map_digits_carrier;            /* Digits */
static int hf_ansi_map_digits_dest;               /* Digits */
static int hf_ansi_map_dmh_ServiceID;             /* DMH_ServiceID */
static int hf_ansi_map_lectronicSerialNumber;     /* ElectronicSerialNumber */
static int hf_ansi_map_deregistrationType;        /* DeregistrationType */
static int hf_ansi_map_servicesResult;            /* ServicesResult */
static int hf_ansi_map_sms_MessageWaitingIndicator;  /* SMS_MessageWaitingIndicator */
static int hf_ansi_map_featureIndicator;          /* FeatureIndicator */
static int hf_ansi_map_authenticationCapability;  /* AuthenticationCapability */
static int hf_ansi_map_callingFeaturesIndicator;  /* CallingFeaturesIndicator */
static int hf_ansi_map_geographicAuthorization;   /* GeographicAuthorization */
static int hf_ansi_map_meidValidated;             /* MEIDValidated */
static int hf_ansi_map_mobilePositionCapability;  /* MobilePositionCapability */
static int hf_ansi_map_originationIndicator;      /* OriginationIndicator */
static int hf_ansi_map_originationTriggers;       /* OriginationTriggers */
static int hf_ansi_map_restrictionDigits;         /* RestrictionDigits */
static int hf_ansi_map_sms_OriginationRestrictions;  /* SMS_OriginationRestrictions */
static int hf_ansi_map_sms_TerminationRestrictions;  /* SMS_TerminationRestrictions */
static int hf_ansi_map_spinipin;                  /* SPINIPIN */
static int hf_ansi_map_spiniTriggers;             /* SPINITriggers */
static int hf_ansi_map_terminationRestrictionCode;  /* TerminationRestrictionCode */
static int hf_ansi_map_userGroup;                 /* UserGroup */
static int hf_ansi_map_lirMode;                   /* LIRMode */
static int hf_ansi_map_cdmaCodeChannel;           /* CDMACodeChannel */
static int hf_ansi_map_cdmaMobileCapabilities;    /* CDMAMobileCapabilities */
static int hf_ansi_map_cdmaServingOneWayDelay2;   /* CDMAServingOneWayDelay2 */
static int hf_ansi_map_cdmaPSMMList;              /* CDMAPSMMList */
static int hf_ansi_map_mpcAddress;                /* MPCAddress */
static int hf_ansi_map_dmh_ChargeInformation;     /* DMH_ChargeInformation */
static int hf_ansi_map_qualificationInformationCode;  /* QualificationInformationCode */
static int hf_ansi_map_authorizationDenied;       /* AuthorizationDenied */
static int hf_ansi_map_authorizationPeriod;       /* AuthorizationPeriod */
static int hf_ansi_map_deniedAuthorizationPeriod;  /* DeniedAuthorizationPeriod */
static int hf_ansi_map_randValidTime;             /* RANDValidTime */
static int hf_ansi_map_redirectionReason;         /* RedirectionReason */
static int hf_ansi_map_cancellationType;          /* CancellationType */
static int hf_ansi_map_controlChannelData;        /* ControlChannelData */
static int hf_ansi_map_receivedSignalQuality;     /* ReceivedSignalQuality */
static int hf_ansi_map_systemAccessData;          /* SystemAccessData */
static int hf_ansi_map_cancellationDenied;        /* CancellationDenied */
static int hf_ansi_map_availabilityType;          /* AvailabilityType */
static int hf_ansi_map_borderCellAccess;          /* BorderCellAccess */
static int hf_ansi_map_msc_Address;               /* MSC_Address */
static int hf_ansi_map_sms_Address;               /* SMS_Address */
static int hf_ansi_map_mpcAddressList;            /* MPCAddressList */
static int hf_ansi_map_digits_Carrier;            /* Digits */
static int hf_ansi_map_digitCollectionControl;    /* DigitCollectionControl */
static int hf_ansi_map_trunkStatus;               /* TrunkStatus */
static int hf_ansi_map_voiceMailboxNumber;        /* VoiceMailboxNumber */
static int hf_ansi_map_voiceMailboxPIN;           /* VoiceMailboxPIN */
static int hf_ansi_map_sms_BearerData;            /* SMS_BearerData */
static int hf_ansi_map_sms_TeleserviceIdentifier;  /* SMS_TeleserviceIdentifier */
static int hf_ansi_map_sms_ChargeIndicator;       /* SMS_ChargeIndicator */
static int hf_ansi_map_sms_DestinationAddress;    /* SMS_DestinationAddress */
static int hf_ansi_map_sms_OriginalDestinationAddress;  /* SMS_OriginalDestinationAddress */
static int hf_ansi_map_sms_OriginalDestinationSubaddress;  /* SMS_OriginalDestinationSubaddress */
static int hf_ansi_map_sms_OriginalOriginatingAddress;  /* SMS_OriginalOriginatingAddress */
static int hf_ansi_map_sms_OriginalOriginatingSubaddress;  /* SMS_OriginalOriginatingSubaddress */
static int hf_ansi_map_sms_OriginatingAddress;    /* SMS_OriginatingAddress */
static int hf_ansi_map_sms_CauseCode;             /* SMS_CauseCode */
static int hf_ansi_map_interMessageTime;          /* InterMessageTime */
static int hf_ansi_map_newlyAssignedIMSI;         /* NewlyAssignedIMSI */
static int hf_ansi_map_newlyAssignedMIN;          /* NewlyAssignedMIN */
static int hf_ansi_map_newMINExtension;           /* NewMINExtension */
static int hf_ansi_map_sms_MessageCount;          /* SMS_MessageCount */
static int hf_ansi_map_sms_NotificationIndicator;  /* SMS_NotificationIndicator */
static int hf_ansi_map_teleservice_Priority;      /* Teleservice_Priority */
static int hf_ansi_map_temporaryReferenceNumber;  /* TemporaryReferenceNumber */
static int hf_ansi_map_mobileStationMSID;         /* MobileStationMSID */
static int hf_ansi_map_sms_TransactionID;         /* SMS_TransactionID */
static int hf_ansi_map_sms_AccessDeniedReason;    /* SMS_AccessDeniedReason */
static int hf_ansi_map_seizureType;               /* SeizureType */
static int hf_ansi_map_requiredParametersMask;    /* RequiredParametersMask */
static int hf_ansi_map_reasonList;                /* ReasonList */
static int hf_ansi_map_networkTMSIExpirationTime;  /* NetworkTMSIExpirationTime */
static int hf_ansi_map_newNetworkTMSI;            /* NewNetworkTMSI */
static int hf_ansi_map_serviceID;                 /* ServiceID */
static int hf_ansi_map_dataAccessElementList;     /* DataAccessElementList */
static int hf_ansi_map_timeDateOffset;            /* TimeDateOffset */
static int hf_ansi_map_timeOfDay;                 /* TimeOfDay */
static int hf_ansi_map_dmd_BillingIndicator;      /* DMH_BillingIndicator */
static int hf_ansi_map_failureType;               /* FailureType */
static int hf_ansi_map_failureCause;              /* FailureCause */
static int hf_ansi_map_outingDigits;              /* RoutingDigits */
static int hf_ansi_map_databaseKey;               /* DatabaseKey */
static int hf_ansi_map_modificationRequestList;   /* ModificationRequestList */
static int hf_ansi_map_modificationResultList;    /* ModificationResultList */
static int hf_ansi_map_serviceDataAccessElementList;  /* ServiceDataAccessElementList */
static int hf_ansi_map_privateSpecializedResource;  /* PrivateSpecializedResource */
static int hf_ansi_map_specializedResource;       /* SpecializedResource */
static int hf_ansi_map_executeScript;             /* ExecuteScript */
static int hf_ansi_map_scriptResult;              /* ScriptResult */
static int hf_ansi_map_tdmaVoiceMode;             /* TDMAVoiceMode */
static int hf_ansi_map_callStatus;                /* CallStatus */
static int hf_ansi_map_releaseCause;              /* ReleaseCause */
static int hf_ansi_map_callRecoveryIDList;        /* CallRecoveryIDList */
static int hf_ansi_map_positionInformationCode;   /* PositionInformationCode */
static int hf_ansi_map_mSStatus;                  /* MSStatus */
static int hf_ansi_map_pSID_RSIDInformation;      /* PSID_RSIDInformation */
static int hf_ansi_map_positionRequestType;       /* PositionRequestType */
static int hf_ansi_map_lcsBillingID;              /* LCSBillingID */
static int hf_ansi_map_lcs_Client_ID;             /* LCS_Client_ID */
static int hf_ansi_map_dtxIndication;             /* DTXIndication */
static int hf_ansi_map_tdma_MAHO_CELLID;          /* TDMA_MAHO_CELLID */
static int hf_ansi_map_tdma_MAHO_CHANNEL;         /* TDMA_MAHO_CHANNEL */
static int hf_ansi_map_tdma_TimeAlignment;        /* TDMA_TimeAlignment */
static int hf_ansi_map_pqos_HorizontalPosition;   /* PQOS_HorizontalPosition */
static int hf_ansi_map_pqos_HorizontalVelocity;   /* PQOS_HorizontalVelocity */
static int hf_ansi_map_pqos_MaximumPositionAge;   /* PQOS_MaximumPositionAge */
static int hf_ansi_map_pqos_PositionPriority;     /* PQOS_PositionPriority */
static int hf_ansi_map_pqos_ResponseTime;         /* PQOS_ResponseTime */
static int hf_ansi_map_pqos_VerticalPosition;     /* PQOS_VerticalPosition */
static int hf_ansi_map_pqos_VerticalVelocity;     /* PQOS_VerticalVelocity */
static int hf_ansi_map_cdmaPSMMCount;             /* CDMAPSMMCount */
static int hf_ansi_map_lirAuthorization;          /* LIRAuthorization */
static int hf_ansi_map_mpcid;                     /* MPCID */
static int hf_ansi_map_tdma_MAHORequest;          /* TDMA_MAHORequest */
static int hf_ansi_map_positionResult;            /* PositionResult */
static int hf_ansi_map_positionInformation;       /* PositionInformation */
static int hf_ansi_map_controlType;               /* ControlType */
static int hf_ansi_map_destinationAddress;        /* DestinationAddress */
static int hf_ansi_map_gapDuration;               /* GapDuration */
static int hf_ansi_map_gapInterval;               /* GapInterval */
static int hf_ansi_map_invokingNEType;            /* InvokingNEType */
static int hf_ansi_map_range;                     /* Range */
static int hf_ansi_map_meidStatus;                /* MEIDStatus */
static int hf_ansi_map_aKeyProtocolVersion;       /* AKeyProtocolVersion */
static int hf_ansi_map_mobileStationPartialKey;   /* MobileStationPartialKey */
static int hf_ansi_map_newlyAssignedMSID;         /* NewlyAssignedMSID */
static int hf_ansi_map_baseStationPartialKey;     /* BaseStationPartialKey */
static int hf_ansi_map_modulusValue;              /* ModulusValue */
static int hf_ansi_map_otasp_ResultCode;          /* OTASP_ResultCode */
static int hf_ansi_map_primitiveValue;            /* PrimitiveValue */
static int hf_ansi_map_record_Type;               /* Record_Type */
static int hf_ansi_map_information_Record;        /* Information_Record */
static int hf_ansi_map_cdma2000MobileSupportedCapabilities;  /* CDMA2000MobileSupportedCapabilities */
static int hf_ansi_map_announcementCode1;         /* AnnouncementCode */
static int hf_ansi_map_announcementCode2;         /* AnnouncementCode */
static int hf_ansi_map_cdmaPilotPN;               /* CDMAPilotPN */
static int hf_ansi_map_cdmaPowerCombinedIndicator;  /* CDMAPowerCombinedIndicator */
static int hf_ansi_map_CDMACodeChannelList_item;  /* CDMACodeChannelInformation */
static int hf_ansi_map_cdmaPilotStrength;         /* CDMAPilotStrength */
static int hf_ansi_map_cdmaTargetOneWayDelay;     /* CDMATargetOneWayDelay */
static int hf_ansi_map_CDMATargetMAHOList_item;   /* CDMATargetMAHOInformation */
static int hf_ansi_map_cdmaSignalQuality;         /* CDMASignalQuality */
static int hf_ansi_map_CDMATargetMeasurementList_item;  /* CDMATargetMeasurementInformation */
static int hf_ansi_map_TargetMeasurementList_item;  /* TargetMeasurementInformation */
static int hf_ansi_map_TerminationList_item;      /* TerminationList_item */
static int hf_ansi_map_intersystemTermination;    /* IntersystemTermination */
static int hf_ansi_map_localTermination;          /* LocalTermination */
static int hf_ansi_map_pstnTermination;           /* PSTNTermination */
static int hf_ansi_map_CDMABandClassList_item;    /* CDMABandClassInformation */
static int hf_ansi_map_CDMAServiceOptionList_item;  /* CDMAServiceOption */
static int hf_ansi_map_pSID_RSIDInformation1;     /* PSID_RSIDInformation */
static int hf_ansi_map_targetCellID1;             /* TargetCellID */
static int hf_ansi_map_cdmaConnectionReference;   /* CDMAConnectionReference */
static int hf_ansi_map_cdmaState;                 /* CDMAState */
static int hf_ansi_map_cdmaServiceOptionConnectionIdentifier;  /* CDMAServiceOptionConnectionIdentifier */
static int hf_ansi_map_CDMAConnectionReferenceList_item;  /* CDMAConnectionReferenceList_item */
static int hf_ansi_map_cdmaConnectionReferenceInformation;  /* CDMAConnectionReferenceInformation */
static int hf_ansi_map_cdmaConnectionReferenceInformation2;  /* CDMAConnectionReferenceInformation */
static int hf_ansi_map_analogRedirectInfo;        /* AnalogRedirectInfo */
static int hf_ansi_map_CDMAChannelNumberList_item;  /* CDMAChannelNumberList_item */
static int hf_ansi_map_cdmaChannelNumber;         /* CDMAChannelNumber */
static int hf_ansi_map_cdmaChannelNumber2;        /* CDMAChannelNumber */
static int hf_ansi_map_cdmaChannelNumberList;     /* CDMAChannelNumberList */
static int hf_ansi_map_dataID;                    /* DataID */
static int hf_ansi_map_change;                    /* Change */
static int hf_ansi_map_dataValue;                 /* DataValue */
static int hf_ansi_map_DataAccessElementList_item;  /* DataAccessElementList_item */
static int hf_ansi_map_dataAccessElement1;        /* DataAccessElement */
static int hf_ansi_map_dataAccessElement2;        /* DataAccessElement */
static int hf_ansi_map_dataResult;                /* DataResult */
static int hf_ansi_map_DataUpdateResultList_item;  /* DataUpdateResult */
static int hf_ansi_map_globalTitle;               /* GlobalTitle */
static int hf_ansi_map_pC_SSN;                    /* PC_SSN */
static int hf_ansi_map_scriptName;                /* ScriptName */
static int hf_ansi_map_scriptArgument;            /* ScriptArgument */
static int hf_ansi_map_allOrNone;                 /* AllOrNone */
static int hf_ansi_map_ModificationRequestList_item;  /* ModificationRequest */
static int hf_ansi_map_serviceDataResultList;     /* ServiceDataResultList */
static int hf_ansi_map_ModificationResultList_item;  /* ModificationResult */
static int hf_ansi_map_ServiceDataAccessElementList_item;  /* ServiceDataAccessElement */
static int hf_ansi_map_dataUpdateResultList;      /* DataUpdateResultList */
static int hf_ansi_map_ServiceDataResultList_item;  /* ServiceDataResult */
static int hf_ansi_map_triggerList;               /* TriggerList */
static int hf_ansi_map_triggerListOpt;            /* TriggerList */
static int hf_ansi_map_wIN_TriggerList;           /* WIN_TriggerList */
static int hf_ansi_map_triggerCapability;         /* TriggerCapability */
static int hf_ansi_map_wINOperationsCapability;   /* WINOperationsCapability */
static int hf_ansi_map_CallRecoveryIDList_item;   /* CallRecoveryID */
static int hf_ansi_map_generalizedTime;           /* GeneralizedTime */
static int hf_ansi_map_geographicPosition;        /* GeographicPosition */
static int hf_ansi_map_positionSource;            /* PositionSource */
static int hf_ansi_map_horizontal_Velocity;       /* Horizontal_Velocity */
static int hf_ansi_map_vertical_Velocity;         /* Vertical_Velocity */
static int hf_ansi_map_sCFOverloadGapInterval;    /* SCFOverloadGapInterval */
static int hf_ansi_map_serviceManagementSystemGapInterval;  /* ServiceManagementSystemGapInterval */
static int hf_ansi_map_CDMAPSMMList_item;         /* CDMAPSMMList_item */
static int hf_ansi_map_cdmaTargetMAHOList2;       /* CDMATargetMAHOList */
static int hf_ansi_map_mpcAddress2;               /* MPCAddress */
static int hf_ansi_map_mobileStationIMSI;         /* MobileStationIMSI */
static int hf_ansi_map_handoffMeasurementRequest;  /* HandoffMeasurementRequest */
static int hf_ansi_map_facilitiesDirective;       /* FacilitiesDirective */
static int hf_ansi_map_handoffBack;               /* HandoffBack */
static int hf_ansi_map_facilitiesRelease;         /* FacilitiesRelease */
static int hf_ansi_map_qualificationRequest;      /* QualificationRequest */
static int hf_ansi_map_qualificationDirective;    /* QualificationDirective */
static int hf_ansi_map_blocking;                  /* Blocking */
static int hf_ansi_map_unblocking;                /* Unblocking */
static int hf_ansi_map_resetCircuit;              /* ResetCircuit */
static int hf_ansi_map_trunkTest;                 /* TrunkTest */
static int hf_ansi_map_trunkTestDisconnect;       /* TrunkTestDisconnect */
static int hf_ansi_map_registrationNotification;  /* RegistrationNotification */
static int hf_ansi_map_registrationCancellation;  /* RegistrationCancellation */
static int hf_ansi_map_locationRequest;           /* LocationRequest */
static int hf_ansi_map_routingRequest;            /* RoutingRequest */
static int hf_ansi_map_featureRequest;            /* FeatureRequest */
static int hf_ansi_map_unreliableRoamerDataDirective;  /* UnreliableRoamerDataDirective */
static int hf_ansi_map_mSInactive;                /* MSInactive */
static int hf_ansi_map_transferToNumberRequest;   /* TransferToNumberRequest */
static int hf_ansi_map_redirectionRequest;        /* RedirectionRequest */
static int hf_ansi_map_handoffToThird;            /* HandoffToThird */
static int hf_ansi_map_flashRequest;              /* FlashRequest */
static int hf_ansi_map_authenticationDirective;   /* AuthenticationDirective */
static int hf_ansi_map_authenticationRequest;     /* AuthenticationRequest */
static int hf_ansi_map_baseStationChallenge;      /* BaseStationChallenge */
static int hf_ansi_map_authenticationFailureReport;  /* AuthenticationFailureReport */
static int hf_ansi_map_countRequest;              /* CountRequest */
static int hf_ansi_map_interSystemPage;           /* InterSystemPage */
static int hf_ansi_map_unsolicitedResponse;       /* UnsolicitedResponse */
static int hf_ansi_map_bulkDeregistration;        /* BulkDeregistration */
static int hf_ansi_map_handoffMeasurementRequest2;  /* HandoffMeasurementRequest2 */
static int hf_ansi_map_facilitiesDirective2;      /* FacilitiesDirective2 */
static int hf_ansi_map_handoffBack2;              /* HandoffBack2 */
static int hf_ansi_map_handoffToThird2;           /* HandoffToThird2 */
static int hf_ansi_map_authenticationDirectiveForward;  /* AuthenticationDirectiveForward */
static int hf_ansi_map_authenticationStatusReport;  /* AuthenticationStatusReport */
static int hf_ansi_map_informationDirective;      /* InformationDirective */
static int hf_ansi_map_informationForward;        /* InformationForward */
static int hf_ansi_map_interSystemAnswer;         /* InterSystemAnswer */
static int hf_ansi_map_interSystemPage2;          /* InterSystemPage2 */
static int hf_ansi_map_interSystemSetup;          /* InterSystemSetup */
static int hf_ansi_map_originationRequest;        /* OriginationRequest */
static int hf_ansi_map_randomVariableRequest;     /* RandomVariableRequest */
static int hf_ansi_map_redirectionDirective;      /* RedirectionDirective */
static int hf_ansi_map_remoteUserInteractionDirective;  /* RemoteUserInteractionDirective */
static int hf_ansi_map_sMSDeliveryBackward;       /* SMSDeliveryBackward */
static int hf_ansi_map_sMSDeliveryForward;        /* SMSDeliveryForward */
static int hf_ansi_map_sMSDeliveryPointToPoint;   /* SMSDeliveryPointToPoint */
static int hf_ansi_map_sMSNotification;           /* SMSNotification */
static int hf_ansi_map_sMSRequest;                /* SMSRequest */
static int hf_ansi_map_oTASPRequest;              /* OTASPRequest */
static int hf_ansi_map_changeFacilities;          /* ChangeFacilities */
static int hf_ansi_map_changeService;             /* ChangeService */
static int hf_ansi_map_parameterRequest;          /* ParameterRequest */
static int hf_ansi_map_tMSIDirective;             /* TMSIDirective */
static int hf_ansi_map_numberPortabilityRequest;  /* NumberPortabilityRequest */
static int hf_ansi_map_serviceRequest;            /* ServiceRequest */
static int hf_ansi_map_analyzedInformation;       /* AnalyzedInformation */
static int hf_ansi_map_connectionFailureReport;   /* ConnectionFailureReport */
static int hf_ansi_map_connectResource;           /* ConnectResource */
static int hf_ansi_map_facilitySelectedAndAvailable;  /* FacilitySelectedAndAvailable */
static int hf_ansi_map_modify;                    /* Modify */
static int hf_ansi_map_search;                    /* Search */
static int hf_ansi_map_seizeResource;             /* SeizeResource */
static int hf_ansi_map_sRFDirective;              /* SRFDirective */
static int hf_ansi_map_tBusy;                     /* TBusy */
static int hf_ansi_map_tNoAnswer;                 /* TNoAnswer */
static int hf_ansi_map_smsDeliveryPointToPointAck;  /* SMSDeliveryPointToPointAck */
static int hf_ansi_map_messageDirective;          /* MessageDirective */
static int hf_ansi_map_bulkDisconnection;         /* BulkDisconnection */
static int hf_ansi_map_callControlDirective;      /* CallControlDirective */
static int hf_ansi_map_oAnswer;                   /* OAnswer */
static int hf_ansi_map_oDisconnect;               /* ODisconnect */
static int hf_ansi_map_callRecoveryReport;        /* CallRecoveryReport */
static int hf_ansi_map_tAnswer;                   /* TAnswer */
static int hf_ansi_map_tDisconnect;               /* TDisconnect */
static int hf_ansi_map_unreliableCallData;        /* UnreliableCallData */
static int hf_ansi_map_oCalledPartyBusy;          /* OCalledPartyBusy */
static int hf_ansi_map_oNoAnswer;                 /* ONoAnswer */
static int hf_ansi_map_positionRequest;           /* PositionRequest */
static int hf_ansi_map_positionRequestForward;    /* PositionRequestForward */
static int hf_ansi_map_callTerminationReport;     /* CallTerminationReport */
static int hf_ansi_map_geoPositionRequest;        /* GeoPositionRequest */
static int hf_ansi_map_interSystemPositionRequest;  /* InterSystemPositionRequest */
static int hf_ansi_map_interSystemPositionRequestForward;  /* InterSystemPositionRequestForward */
static int hf_ansi_map_aCGDirective;              /* ACGDirective */
static int hf_ansi_map_roamerDatabaseVerificationRequest;  /* RoamerDatabaseVerificationRequest */
static int hf_ansi_map_addService;                /* AddService */
static int hf_ansi_map_dropService;               /* DropService */
static int hf_ansi_map_lcsParameterRequest;       /* LCSParameterRequest */
static int hf_ansi_map_checkMEID;                 /* CheckMEID */
static int hf_ansi_map_positionEventNotification;  /* PositionEventNotification */
static int hf_ansi_map_statusRequest;             /* StatusRequest */
static int hf_ansi_map_interSystemSMSDeliveryPointToPoint;  /* InterSystemSMSDeliveryPointToPoint */
static int hf_ansi_map_qualificationRequest2;     /* QualificationRequest2 */
static int hf_ansi_map_handoffMeasurementRequestRes;  /* HandoffMeasurementRequestRes */
static int hf_ansi_map_facilitiesDirectiveRes;    /* FacilitiesDirectiveRes */
static int hf_ansi_map_handoffBackRes;            /* HandoffBackRes */
static int hf_ansi_map_facilitiesReleaseRes;      /* FacilitiesReleaseRes */
static int hf_ansi_map_qualificationDirectiveRes;  /* QualificationDirectiveRes */
static int hf_ansi_map_qualificationRequestRes;   /* QualificationRequestRes */
static int hf_ansi_map_resetCircuitRes;           /* ResetCircuitRes */
static int hf_ansi_map_registrationNotificationRes;  /* RegistrationNotificationRes */
static int hf_ansi_map_registrationCancellationRes;  /* RegistrationCancellationRes */
static int hf_ansi_map_locationRequestRes;        /* LocationRequestRes */
static int hf_ansi_map_routingRequestRes;         /* RoutingRequestRes */
static int hf_ansi_map_featureRequestRes;         /* FeatureRequestRes */
static int hf_ansi_map_transferToNumberRequestRes;  /* TransferToNumberRequestRes */
static int hf_ansi_map_handoffToThirdRes;         /* HandoffToThirdRes */
static int hf_ansi_map_authenticationDirectiveRes;  /* AuthenticationDirectiveRes */
static int hf_ansi_map_authenticationRequestRes;  /* AuthenticationRequestRes */
static int hf_ansi_map_baseStationChallengeRes;   /* BaseStationChallengeRes */
static int hf_ansi_map_authenticationFailureReportRes;  /* AuthenticationFailureReportRes */
static int hf_ansi_map_countRequestRes;           /* CountRequestRes */
static int hf_ansi_map_interSystemPageRes;        /* InterSystemPageRes */
static int hf_ansi_map_unsolicitedResponseRes;    /* UnsolicitedResponseRes */
static int hf_ansi_map_handoffMeasurementRequest2Res;  /* HandoffMeasurementRequest2Res */
static int hf_ansi_map_facilitiesDirective2Res;   /* FacilitiesDirective2Res */
static int hf_ansi_map_handoffBack2Res;           /* HandoffBack2Res */
static int hf_ansi_map_handoffToThird2Res;        /* HandoffToThird2Res */
static int hf_ansi_map_authenticationDirectiveForwardRes;  /* AuthenticationDirectiveForwardRes */
static int hf_ansi_map_authenticationStatusReportRes;  /* AuthenticationStatusReportRes */
static int hf_ansi_map_informationDirectiveRes;   /* InformationDirectiveRes */
static int hf_ansi_map_informationForwardRes;     /* InformationForwardRes */
static int hf_ansi_map_interSystemPage2Res;       /* InterSystemPage2Res */
static int hf_ansi_map_interSystemSetupRes;       /* InterSystemSetupRes */
static int hf_ansi_map_originationRequestRes;     /* OriginationRequestRes */
static int hf_ansi_map_randomVariableRequestRes;  /* RandomVariableRequestRes */
static int hf_ansi_map_remoteUserInteractionDirectiveRes;  /* RemoteUserInteractionDirectiveRes */
static int hf_ansi_map_sMSDeliveryBackwardRes;    /* SMSDeliveryBackwardRes */
static int hf_ansi_map_sMSDeliveryForwardRes;     /* SMSDeliveryForwardRes */
static int hf_ansi_map_sMSDeliveryPointToPointRes;  /* SMSDeliveryPointToPointRes */
static int hf_ansi_map_sMSNotificationRes;        /* SMSNotificationRes */
static int hf_ansi_map_sMSRequestRes;             /* SMSRequestRes */
static int hf_ansi_map_oTASPRequestRes;           /* OTASPRequestRes */
static int hf_ansi_map_changeFacilitiesRes;       /* ChangeFacilitiesRes */
static int hf_ansi_map_changeServiceRes;          /* ChangeServiceRes */
static int hf_ansi_map_parameterRequestRes;       /* ParameterRequestRes */
static int hf_ansi_map_tMSIDirectiveRes;          /* TMSIDirectiveRes */
static int hf_ansi_map_numberPortabilityRequestRes;  /* NumberPortabilityRequestRes */
static int hf_ansi_map_serviceRequestRes;         /* ServiceRequestRes */
static int hf_ansi_map_analyzedInformationRes;    /* AnalyzedInformationRes */
static int hf_ansi_map_facilitySelectedAndAvailableRes;  /* FacilitySelectedAndAvailableRes */
static int hf_ansi_map_modifyRes;                 /* ModifyRes */
static int hf_ansi_map_searchRes;                 /* SearchRes */
static int hf_ansi_map_seizeResourceRes;          /* SeizeResourceRes */
static int hf_ansi_map_sRFDirectiveRes;           /* SRFDirectiveRes */
static int hf_ansi_map_tBusyRes;                  /* TBusyRes */
static int hf_ansi_map_tNoAnswerRes;              /* TNoAnswerRes */
static int hf_ansi_map_callControlDirectiveRes;   /* CallControlDirectiveRes */
static int hf_ansi_map_oDisconnectRes;            /* ODisconnectRes */
static int hf_ansi_map_tDisconnectRes;            /* TDisconnectRes */
static int hf_ansi_map_oCalledPartyBusyRes;       /* OCalledPartyBusyRes */
static int hf_ansi_map_oNoAnswerRes;              /* ONoAnswerRes */
static int hf_ansi_map_positionRequestRes;        /* PositionRequestRes */
static int hf_ansi_map_positionRequestForwardRes;  /* PositionRequestForwardRes */
static int hf_ansi_map_interSystemPositionRequestRes;  /* InterSystemPositionRequestRes */
static int hf_ansi_map_interSystemPositionRequestForwardRes;  /* InterSystemPositionRequestForwardRes */
static int hf_ansi_map_roamerDatabaseVerificationRequestRes;  /* RoamerDatabaseVerificationRequestRes */
static int hf_ansi_map_addServiceRes;             /* AddServiceRes */
static int hf_ansi_map_dropServiceRes;            /* DropServiceRes */
static int hf_ansi_map_interSystemSMSPage;        /* InterSystemSMSPage */
static int hf_ansi_map_lcsParameterRequestRes;    /* LCSParameterRequestRes */
static int hf_ansi_map_checkMEIDRes;              /* CheckMEIDRes */
static int hf_ansi_map_statusRequestRes;          /* StatusRequestRes */
static int hf_ansi_map_interSystemSMSDeliveryPointToPointRes;  /* InterSystemSMSDeliveryPointToPointRes */
static int hf_ansi_map_qualificationRequest2Res;  /* QualificationRequest2Res */

/* Initialize the subtree pointers */
static int ett_ansi_map;
static int ett_mintype;
static int ett_digitstype;
static int ett_billingid;
static int ett_sms_bearer_data;
static int ett_sms_teleserviceIdentifier;
static int ett_extendedmscid;
static int ett_extendedsystemmytypecode;
static int ett_handoffstate;
static int ett_mscid;
static int ett_cdmachanneldata;
static int ett_cdmastationclassmark;
static int ett_channeldata;
static int ett_confidentialitymodes;
static int ett_controlchanneldata;
static int ett_CDMA2000HandoffInvokeIOSData;
static int ett_CDMA2000HandoffResponseIOSData;
static int ett_originationtriggers;
static int ett_pacaindicator;
static int ett_callingpartyname;
static int ett_triggercapability;
static int ett_winoperationscapability;
static int ett_win_trigger_list;
static int ett_controlnetworkid;
static int ett_transactioncapability;
static int ett_cdmaserviceoption;
static int ett_systemcapabilities;
static int ett_sms_originationrestrictions;

static int ett_ansi_map_AuthenticationDirective_U;
static int ett_ansi_map_AuthenticationDirectiveRes_U;
static int ett_ansi_map_AuthenticationDirectiveForward_U;
static int ett_ansi_map_AuthenticationDirectiveForwardRes_U;
static int ett_ansi_map_AuthenticationFailureReport_U;
static int ett_ansi_map_AuthenticationFailureReportRes_U;
static int ett_ansi_map_AuthenticationRequest_U;
static int ett_ansi_map_AuthenticationRequestRes_U;
static int ett_ansi_map_AuthenticationStatusReport_U;
static int ett_ansi_map_AuthenticationStatusReportRes_U;
static int ett_ansi_map_BaseStationChallenge_U;
static int ett_ansi_map_BaseStationChallengeRes_U;
static int ett_ansi_map_Blocking_U;
static int ett_ansi_map_BulkDeregistration_U;
static int ett_ansi_map_CountRequest_U;
static int ett_ansi_map_CountRequestRes_U;
static int ett_ansi_map_FacilitiesDirective_U;
static int ett_ansi_map_FacilitiesDirectiveRes_U;
static int ett_ansi_map_FacilitiesDirective2_U;
static int ett_ansi_map_FacilitiesDirective2Res_U;
static int ett_ansi_map_FacilitiesRelease_U;
static int ett_ansi_map_FacilitiesReleaseRes_U;
static int ett_ansi_map_FeatureRequest_U;
static int ett_ansi_map_FeatureRequestRes_U;
static int ett_ansi_map_FlashRequest_U;
static int ett_ansi_map_HandoffBack_U;
static int ett_ansi_map_HandoffBackRes_U;
static int ett_ansi_map_HandoffBack2_U;
static int ett_ansi_map_HandoffBack2Res_U;
static int ett_ansi_map_HandoffMeasurementRequest_U;
static int ett_ansi_map_HandoffMeasurementRequestRes_U;
static int ett_ansi_map_HandoffMeasurementRequest2_U;
static int ett_ansi_map_HandoffMeasurementRequest2Res_U;
static int ett_ansi_map_HandoffToThird_U;
static int ett_ansi_map_HandoffToThirdRes_U;
static int ett_ansi_map_HandoffToThird2_U;
static int ett_ansi_map_HandoffToThird2Res_U;
static int ett_ansi_map_InformationDirective_U;
static int ett_ansi_map_InformationDirectiveRes_U;
static int ett_ansi_map_InformationForward_U;
static int ett_ansi_map_InformationForwardRes_U;
static int ett_ansi_map_InterSystemAnswer_U;
static int ett_ansi_map_InterSystemPage_U;
static int ett_ansi_map_InterSystemPageRes_U;
static int ett_ansi_map_InterSystemPage2_U;
static int ett_ansi_map_InterSystemPage2Res_U;
static int ett_ansi_map_InterSystemSetup_U;
static int ett_ansi_map_InterSystemSetupRes_U;
static int ett_ansi_map_LocationRequest_U;
static int ett_ansi_map_LocationRequestRes_U;
static int ett_ansi_map_MSInactive_U;
static int ett_ansi_map_OriginationRequest_U;
static int ett_ansi_map_OriginationRequestRes_U;
static int ett_ansi_map_QualificationDirective_U;
static int ett_ansi_map_QualificationDirectiveRes_U;
static int ett_ansi_map_QualificationRequest_U;
static int ett_ansi_map_QualificationRequestRes_U;
static int ett_ansi_map_RandomVariableRequest_U;
static int ett_ansi_map_RandomVariableRequestRes_U;
static int ett_ansi_map_RedirectionDirective_U;
static int ett_ansi_map_RedirectionRequest_U;
static int ett_ansi_map_RegistrationCancellation_U;
static int ett_ansi_map_RegistrationCancellationRes_U;
static int ett_ansi_map_RegistrationNotification_U;
static int ett_ansi_map_RegistrationNotificationRes_U;
static int ett_ansi_map_RemoteUserInteractionDirective_U;
static int ett_ansi_map_RemoteUserInteractionDirectiveRes_U;
static int ett_ansi_map_ResetCircuit_U;
static int ett_ansi_map_ResetCircuitRes_U;
static int ett_ansi_map_RoutingRequest_U;
static int ett_ansi_map_RoutingRequestRes_U;
static int ett_ansi_map_SMSDeliveryBackward_U;
static int ett_ansi_map_SMSDeliveryBackwardRes_U;
static int ett_ansi_map_SMSDeliveryForward_U;
static int ett_ansi_map_SMSDeliveryForwardRes_U;
static int ett_ansi_map_SMSDeliveryPointToPoint_U;
static int ett_ansi_map_SMSDeliveryPointToPointRes_U;
static int ett_ansi_map_SMSDeliveryPointToPointAck_U;
static int ett_ansi_map_SMSNotification_U;
static int ett_ansi_map_SMSNotificationRes_U;
static int ett_ansi_map_SMSRequest_U;
static int ett_ansi_map_SMSRequestRes_U;
static int ett_ansi_map_TransferToNumberRequest_U;
static int ett_ansi_map_TransferToNumberRequestRes_U;
static int ett_ansi_map_TrunkTest_U;
static int ett_ansi_map_TrunkTestDisconnect_U;
static int ett_ansi_map_Unblocking_U;
static int ett_ansi_map_UnreliableRoamerDataDirective_U;
static int ett_ansi_map_UnsolicitedResponse_U;
static int ett_ansi_map_UnsolicitedResponseRes_U;
static int ett_ansi_map_ParameterRequest_U;
static int ett_ansi_map_ParameterRequestRes_U;
static int ett_ansi_map_TMSIDirective_U;
static int ett_ansi_map_TMSIDirectiveRes_U;
static int ett_ansi_map_NumberPortabilityRequest_U;
static int ett_ansi_map_NumberPortabilityRequestRes_U;
static int ett_ansi_map_ServiceRequest_U;
static int ett_ansi_map_ServiceRequestRes_U;
static int ett_ansi_map_AnalyzedInformation_U;
static int ett_ansi_map_AnalyzedInformationRes_U;
static int ett_ansi_map_ConnectionFailureReport_U;
static int ett_ansi_map_ConnectResource_U;
static int ett_ansi_map_FacilitySelectedAndAvailable_U;
static int ett_ansi_map_FacilitySelectedAndAvailableRes_U;
static int ett_ansi_map_Modify_U;
static int ett_ansi_map_ModifyRes_U;
static int ett_ansi_map_Search_U;
static int ett_ansi_map_SearchRes_U;
static int ett_ansi_map_SeizeResource_U;
static int ett_ansi_map_SeizeResourceRes_U;
static int ett_ansi_map_SRFDirective_U;
static int ett_ansi_map_SRFDirectiveRes_U;
static int ett_ansi_map_TBusy_U;
static int ett_ansi_map_TBusyRes_U;
static int ett_ansi_map_TNoAnswer_U;
static int ett_ansi_map_TNoAnswerRes_U;
static int ett_ansi_map_ChangeFacilities_U;
static int ett_ansi_map_ChangeFacilitiesRes_U;
static int ett_ansi_map_ChangeService_U;
static int ett_ansi_map_ChangeServiceRes_U;
static int ett_ansi_map_MessageDirective_U;
static int ett_ansi_map_BulkDisconnection_U;
static int ett_ansi_map_CallControlDirective_U;
static int ett_ansi_map_CallControlDirectiveRes_U;
static int ett_ansi_map_OAnswer_U;
static int ett_ansi_map_ODisconnect_U;
static int ett_ansi_map_ODisconnectRes_U;
static int ett_ansi_map_CallRecoveryReport_U;
static int ett_ansi_map_TAnswer_U;
static int ett_ansi_map_TDisconnect_U;
static int ett_ansi_map_TDisconnectRes_U;
static int ett_ansi_map_UnreliableCallData_U;
static int ett_ansi_map_OCalledPartyBusy_U;
static int ett_ansi_map_OCalledPartyBusyRes_U;
static int ett_ansi_map_ONoAnswer_U;
static int ett_ansi_map_ONoAnswerRes_U;
static int ett_ansi_map_PositionRequest_U;
static int ett_ansi_map_PositionRequestRes_U;
static int ett_ansi_map_PositionRequestForward_U;
static int ett_ansi_map_PositionRequestForwardRes_U;
static int ett_ansi_map_CallTerminationReport_U;
static int ett_ansi_map_GeoPositionRequest_U;
static int ett_ansi_map_InterSystemPositionRequest_U;
static int ett_ansi_map_InterSystemPositionRequestRes_U;
static int ett_ansi_map_InterSystemPositionRequestForward_U;
static int ett_ansi_map_InterSystemPositionRequestForwardRes_U;
static int ett_ansi_map_ACGDirective_U;
static int ett_ansi_map_RoamerDatabaseVerificationRequest_U;
static int ett_ansi_map_RoamerDatabaseVerificationRequestRes_U;
static int ett_ansi_map_LCSParameterRequest_U;
static int ett_ansi_map_LCSParameterRequestRes_U;
static int ett_ansi_map_CheckMEID_U;
static int ett_ansi_map_CheckMEIDRes_U;
static int ett_ansi_map_AddService_U;
static int ett_ansi_map_AddServiceRes_U;
static int ett_ansi_map_DropService_U;
static int ett_ansi_map_DropServiceRes_U;
static int ett_ansi_map_PositionEventNotification_U;
static int ett_ansi_map_OTASPRequest_U;
static int ett_ansi_map_OTASPRequestRes_U;
static int ett_ansi_map_StatusRequest_U;
static int ett_ansi_map_StatusRequestRes_U;
static int ett_ansi_map_InterSystemSMSDeliveryPointToPoint_U;
static int ett_ansi_map_InterSystemSMSDeliveryPointToPointRes_U;
static int ett_ansi_map_InterSystemSMSPage_U;
static int ett_ansi_map_QualificationRequest2_U;
static int ett_ansi_map_QualificationRequest2Res_U;
static int ett_ansi_map_AnnouncementList;
static int ett_ansi_map_CDMACodeChannelInformation;
static int ett_ansi_map_CDMACodeChannelList;
static int ett_ansi_map_CDMATargetMAHOInformation;
static int ett_ansi_map_CDMATargetMAHOList;
static int ett_ansi_map_CDMATargetMeasurementInformation;
static int ett_ansi_map_CDMATargetMeasurementList;
static int ett_ansi_map_IntersystemTermination;
static int ett_ansi_map_LocalTermination;
static int ett_ansi_map_PSTNTermination;
static int ett_ansi_map_TargetMeasurementInformation;
static int ett_ansi_map_TargetMeasurementList;
static int ett_ansi_map_TerminationList;
static int ett_ansi_map_TerminationList_item;
static int ett_ansi_map_CDMABandClassInformation;
static int ett_ansi_map_CDMABandClassList;
static int ett_ansi_map_CDMAServiceOptionList;
static int ett_ansi_map_PSID_RSIDList;
static int ett_ansi_map_TargetCellIDList;
static int ett_ansi_map_CDMAConnectionReferenceInformation;
static int ett_ansi_map_CDMAConnectionReferenceList;
static int ett_ansi_map_CDMAConnectionReferenceList_item;
static int ett_ansi_map_AnalogRedirectRecord;
static int ett_ansi_map_CDMAChannelNumberList;
static int ett_ansi_map_CDMAChannelNumberList_item;
static int ett_ansi_map_CDMARedirectRecord;
static int ett_ansi_map_MSID;
static int ett_ansi_map_DataAccessElement;
static int ett_ansi_map_DataAccessElementList;
static int ett_ansi_map_DataAccessElementList_item;
static int ett_ansi_map_DataUpdateResult;
static int ett_ansi_map_DataUpdateResultList;
static int ett_ansi_map_DestinationAddress;
static int ett_ansi_map_ExecuteScript;
static int ett_ansi_map_ModificationRequest;
static int ett_ansi_map_ModificationRequestList;
static int ett_ansi_map_ModificationResult;
static int ett_ansi_map_ModificationResultList;
static int ett_ansi_map_ServiceDataAccessElement;
static int ett_ansi_map_ServiceDataAccessElementList;
static int ett_ansi_map_ServiceDataResult;
static int ett_ansi_map_ServiceDataResultList;
static int ett_ansi_map_TriggerAddressList;
static int ett_ansi_map_TriggerList;
static int ett_ansi_map_WINCapability;
static int ett_ansi_map_CallRecoveryID;
static int ett_ansi_map_CallRecoveryIDList;
static int ett_ansi_map_PositionInformation;
static int ett_ansi_map_GapInterval;
static int ett_ansi_map_CDMAPSMMList;
static int ett_ansi_map_CDMAPSMMList_item;
static int ett_ansi_map_MPCAddressList;
static int ett_ansi_map_MobileStationMSID;
static int ett_ansi_map_NewlyAssignedMSID;
static int ett_ansi_map_InvokeData;
static int ett_ansi_map_ReturnData;

static expert_field ei_ansi_map_nr_not_used;
static expert_field ei_ansi_map_unknown_invokeData_blob;
static expert_field ei_ansi_map_no_data;

/* Global variables */
static dissector_table_t is637_tele_id_dissector_table; /* IS-637 Teleservice ID */
static dissector_table_t is683_dissector_table; /* IS-683-A (OTA) */
static dissector_table_t is801_dissector_table; /* IS-801 (PLD) */
static packet_info *g_pinfo;
static proto_tree *g_tree;
static tvbuff_t *SMS_BearerData_tvb;
static int32_t   ansi_map_sms_tele_id = -1;
static bool is683_ota;
static bool is801_pld;
static bool ansi_map_is_invoke;
static uint32_t OperationCode;
static uint8_t ServiceIndicator;


struct ansi_map_invokedata_t {
    uint32_t opcode;
    uint8_t ServiceIndicator;
};

static void dissect_ansi_map_win_trigger_list(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_);


/* Transaction table */
static wmem_multimap_t *TransactionId_table;

/* Store Invoke information needed for the corresponding reply */
static void
update_saved_invokedata(packet_info *pinfo, struct ansi_tcap_private_t *p_private_tcap){
    struct ansi_map_invokedata_t *ansi_map_saved_invokedata;
    address* src = &(pinfo->src);
    address* dst = &(pinfo->dst);
    uint8_t *src_str;
    uint8_t *dst_str;
    const char *buf = NULL;

    src_str = address_to_str(pinfo->pool, src);
    dst_str = address_to_str(pinfo->pool, dst);

    /* Data from the TCAP dissector */
    if ((!pinfo->fd->visited)&&(p_private_tcap->TransactionID_str)){
        /* Only do this once XXX I hope it's the right thing to do */
        /* The hash string needs to contain src and dest to distinguish different flows */
        switch(ansi_map_response_matching_type){
            case ANSI_MAP_TID_ONLY:
                buf = wmem_strdup(pinfo->pool, p_private_tcap->TransactionID_str);
                break;
            case ANSI_MAP_TID_AND_SOURCE:
                buf = wmem_strdup_printf(pinfo->pool, "%s%s",p_private_tcap->TransactionID_str,src_str);
                break;
            case ANSI_MAP_TID_SOURCE_AND_DEST:
            default:
                buf = wmem_strdup_printf(pinfo->pool, "%s%s%s",p_private_tcap->TransactionID_str,src_str,dst_str);
                break;
        }

        ansi_map_saved_invokedata = wmem_new(wmem_file_scope(), struct ansi_map_invokedata_t);
        ansi_map_saved_invokedata->opcode = p_private_tcap->d.OperationCode_private;
        ansi_map_saved_invokedata->ServiceIndicator = ServiceIndicator;

        wmem_multimap_insert32(TransactionId_table,
                            wmem_strdup(wmem_file_scope(), buf),
                            pinfo->num,
                            ansi_map_saved_invokedata);

        /*ws_warning("Invoke Hash string %s pkt: %u",buf,pinfo->num);*/
    }
}
/* value strings */
const value_string ansi_map_opr_code_strings[] = {
    {   1, "Handoff Measurement Request" },
    {   2, "Facilities Directive" },
    {   3, "Mobile On Channel" },
    {   4, "Handoff Back" },
    {   5, "Facilities Release" },
    {   6, "Qualification Request" },
    {   7, "Qualification Directive" },
    {   8, "Blocking" },
    {   9, "Unblocking" },
    {  10,  "Reset Circuit" },
    {  11, "Trunk Test" },
    {  12, "Trunk Test Disconnect" },
    {  13, "Registration Notification" },
    {  14, "Registration Cancellation" },
    {  15, "Location Request" },
    {  16, "Routing Request" },
    {  17, "Feature Request" },
    {  18, "Reserved 18 (Service Profile Request, IS-41-C)" },
    {  19, "Reserved 19 (Service Profile Directive, IS-41-C)" },
    {  20, "Unreliable Roamer Data Directive" },
    {  21, "Reserved 21 (Call Data Request, IS-41-C)" },
    {  22, "MS Inactive" },
    {  23, "Transfer To Number Request" },
    {  24, "Redirection Request" },
    {  25, "Handoff To Third" },
    {  26, "Flash Request" },
    {  27, "Authentication Directive" },
    {  28, "Authentication Request" },
    {  29, "Base Station Challenge" },
    {  30, "Authentication Failure Report" },
    {  31, "Count Request" },
    {  32, "Inter System Page" },
    {  33, "Unsolicited Response" },
    {  34, "Bulk Deregistration" },
    {  35, "Handoff Measurement Request 2" },
    {  36, "Facilities Directive 2" },
    {  37, "Handoff Back 2" },
    {  38, "Handoff To Third 2" },
    {  39, "Authentication Directive Forward" },
    {  40, "Authentication Status Report" },
    {  41, "Reserved 41" },
    {  42, "Information Directive" },
    {  43, "Information Forward" },
    {  44, "Inter System Answer" },
    {  45, "Inter System Page 2" },
    {  46, "Inter System Setup" },
    {  47, "Origination Request" },
    {  48, "Random Variable Request" },
    {  49, "Redirection Directive" },
    {  50, "Remote User Interaction Directive" },
    {  51, "SMS Delivery Backward" },
    {  52, "SMS Delivery Forward" },
    {  53, "SMS Delivery Point to Point" },
    {  54, "SMS Notification" },
    {  55, "SMS Request" },
    {  56, "OTASP Request" },
    {  57, "Information Backward" },
    {  58, "Change Facilities" },
    {  59, "Change Service" },
    {  60, "Parameter Request" },
    {  61, "TMSI Directive" },
    {  62, "NumberPortabilityRequest" },
    {  63, "Service Request" },
    {  64, "Analyzed Information Request" },
    {  65, "Connection Failure Report" },
    {  66, "Connect Resource" },
    {  67, "Disconnect Resource" },
    {  68, "Facility Selected and Available" },
    {  69, "Instruction Request" },
    {  70, "Modify" },
    {  71, "Reset Timer" },
    {  72, "Search" },
    {  73, "Seize Resource" },
    {  74, "SRF Directive" },
    {  75, "T Busy" },
    {  76, "T NoAnswer" },
    {  77, "Release" },
    {  78, "SMS Delivery Point to Point Ack" },
    {  79, "Message Directive" },
    {  80, "Bulk Disconnection" },
    {  81, "Call Control Directive" },
    {  82, "O Answer" },
    {  83, "O Disconnect" },
    {  84, "Call Recovery Report" },
    {  85, "T Answer" },
    {  86, "T Disconnect" },
    {  87, "Unreliable Call Data" },
    {  88, "O CalledPartyBusy" },
    {  89, "O NoAnswer" },
    {  90, "Position Request" },
    {  91, "Position Request Forward" },
    {  92, "Call Termination Report" },
    {  93, "Geo Position Directive" },
    {  94, "Geo Position Request" },
    {  95, "Inter System Position Request" },
    {  96, "Inter System Position Request Forward" },
    {  97, "ACG Directive" },
    {  98, "Roamer Database Verification Request" },
    {  99, "Add Service" },
    { 100, "Drop Service" },
    { 101, "InterSystemSMSPage" },
    { 102, "LCSParameterRequest" },
    { 103, "Unknown ANSI-MAP PDU" },
    { 104, "Unknown ANSI-MAP PDU" },
    { 105, "Unknown ANSI-MAP PDU" },
    { 106, "PositionEventNotification" },
    { 107, "Unknown ANSI-MAP PDU" },
    { 108, "Unknown ANSI-MAP PDU" },
    { 109, "Unknown ANSI-MAP PDU" },
    { 110, "Unknown ANSI-MAP PDU" },
    { 111, "InterSystemSMSDelivery-PointToPoint" },
    { 112, "QualificationRequest2" },
    {   0, NULL },
};
static value_string_ext ansi_map_opr_code_strings_ext = VALUE_STRING_EXT_INIT(ansi_map_opr_code_strings);

static int dissect_invokeData(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx);
static int dissect_returnData(proto_tree *tree, tvbuff_t *tvb, int offset,  asn1_ctx_t *actx);
static int dissect_ansi_map_SystemMyTypeCode(bool implicit_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index _U_);

/* Type of Digits (octet 1, bits A-H) */
static const value_string ansi_map_type_of_digits_vals[] = {
    {   0, "Not Used" },
    {   1, "Dialed Number or Called Party Number" },
    {   2, "Calling Party Number" },
    {   3, "Caller Interaction" },
    {   4, "Routing Number" },
    {   5, "Billing Number" },
    {   6, "Destination Number" },
    {   7, "LATA" },
    {   8, "Carrier" },
    {   0, NULL }
};
/* Nature of Number (octet 2, bits A-H )*/
static const true_false_string ansi_map_na_bool_val  = {
    "International",
    "National"
};
static const true_false_string ansi_map_pi_bool_val  = {
    "Presentation Restricted",
    "Presentation Allowed"
};
static const true_false_string ansi_map_navail_bool_val  = {
    "Number is not available",
    "Number is available"
};
#if 0
static const true_false_string ansi_map_si_bool_val  = {
    "User provided, screening passed",
    "User provided, not screened"
};
#endif
static const value_string ansi_map_si_vals[]  = {
    {   0, "User provided, not screened"},
    {   1, "User provided, screening passed"},
    {   2, "User provided, screening failed"},
    {   3, "Network provided"},
    {   0, NULL }
};
/* Encoding (octet 3, bits A-D) */
static const value_string ansi_map_digits_enc_vals[]  = {
    {   0, "Not used"},
    {   1, "BCD"},
    {   2, "IA5"},
    {   3, "Octet string"},
    {   0, NULL }
};
/* Numbering Plan (octet 3, bits E-H) */
static const value_string ansi_map_np_vals[]  = {
    {   0, "Unknown or not applicable"},
    {   1, "ISDN Numbering"},
    {   2, "Telephony Numbering (ITU-T Rec. E.164,E.163)"},
    {   3, "Data Numbering (ITU-T Rec. X.121)"},
    {   4, "Telex Numbering (ITU-T Rec. F.69)"},
    {   5, "Maritime Mobile Numbering"},
    {   6, "Land Mobile Numbering (ITU-T Rec. E.212)"},
    {   7, "Private Numbering Plan"},
    {  13, "SS7 Point Code (PC) and Subsystem Number (SSN)"},
    {  14, "Internet Protocol (IP) Address."},
    {  15, "Reserved for extension"},
    {   0, NULL }
};

static void
dissect_ansi_map_min_type(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
    char *digit_str;
    int   offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_mintype);

    proto_tree_add_item_ret_display_string(subtree, hf_ansi_map_bcd_digits, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_BCD_DIGITS_0_9|ENC_LITTLE_ENDIAN, pinfo->pool, &digit_str);
    proto_item_append_text(actx->created_item, " - %s", digit_str);
}

static void
dissect_ansi_map_digits_type(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    uint8_t octet , octet_len;
    uint8_t b1,b2,b3,b4;
    int    offset = 0;
    char  *digit_str;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_digitstype);

    /* Octet 1 */
    proto_tree_add_item(subtree, hf_ansi_map_type_of_digits, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    /* Octet 2 */
    proto_tree_add_item(subtree, hf_ansi_map_reservedBitHG, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_si, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_reservedBitD, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_navail, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_pi, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_na, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    /* Octet 3 */
    octet = tvb_get_uint8(tvb,offset);
    proto_tree_add_item(subtree, hf_ansi_map_np, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_digits_enc, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    /* Octet 4 - */
    switch(octet>>4){
    case 0:/* Unknown or not applicable */
        switch ((octet&0xf)){
        case 1:
            /* BCD Coding */
            octet_len = tvb_get_uint8(tvb,offset);
            proto_tree_add_item(subtree, hf_ansi_map_nr_digits, tvb, offset, 1, ENC_BIG_ENDIAN);
            if(octet_len == 0)
                return;
            offset++;
            proto_tree_add_item_ret_display_string(subtree, hf_ansi_map_bcd_digits, tvb, offset, -1, ENC_KEYPAD_BC_TBCD|ENC_LITTLE_ENDIAN, pinfo->pool, &digit_str);
            proto_item_append_text(actx->created_item, " - %s", digit_str);
            break;
        case 2:
            {
            const uint8_t* digits;
            /* IA5 Coding */
            octet_len = tvb_get_uint8(tvb,offset);
            proto_tree_add_item(subtree, hf_ansi_map_nr_digits, tvb, offset, 1, ENC_BIG_ENDIAN);
            if(octet_len == 0)
                return;
            offset++;
            proto_tree_add_item_ret_string(subtree, hf_ansi_map_ia5_digits, tvb, offset, tvb_reported_length_remaining(tvb,offset),
                                            ENC_ASCII|ENC_NA, pinfo->pool, &digits);
            proto_item_append_text(actx->created_item, " - %s", digits);
            }
            break;
        case 3:
            /* Octet string */
            break;
        default:
            break;
        }
        break;
    case 1:/* ISDN Numbering (not used in this Standard). */
    case 3:/* Data Numbering (ITU-T Rec. X.121) (not used in this Standard). */
    case 4:/* Telex Numbering (ITU-T Rec. F.69) (not used in this Standard). */
    case 5:/* Maritime Mobile Numbering (not used in this Standard). */
        proto_tree_add_expert(subtree, pinfo, &ei_ansi_map_nr_not_used, tvb, offset, -1);
        break;
    case 2:/* Telephony Numbering (ITU-T Rec. E.164,E.163). */
    case 6:/* Land Mobile Numbering (ITU-T Rec. E.212) */
    case 7:/* Private Numbering Plan */
        octet_len = tvb_get_uint8(tvb,offset);
        proto_tree_add_item(subtree, hf_ansi_map_nr_digits, tvb, offset, 1, ENC_BIG_ENDIAN);
        if(octet_len == 0)
            return;
        offset++;
        switch ((octet&0xf)){
        case 1:
            /* BCD Coding */
            proto_tree_add_item_ret_display_string(subtree, hf_ansi_map_bcd_digits, tvb, offset, -1, ENC_KEYPAD_BC_TBCD|ENC_LITTLE_ENDIAN, pinfo->pool, &digit_str);
            proto_item_append_text(actx->created_item, " - %s", digit_str);
            break;
        case 2:
            {
            const uint8_t* digits;
            /* IA5 Coding */
            proto_tree_add_item_ret_string(subtree, hf_ansi_map_ia5_digits, tvb, offset, tvb_reported_length_remaining(tvb,offset),
                                            ENC_ASCII|ENC_NA, pinfo->pool, &digits);
            proto_item_append_text(actx->created_item, " - %s", digits);
            }
            break;
        case 3:
            /* Octet string */
            break;
        default:
            break;
        }
        break;
    case 13:/* ANSI SS7 Point Code (PC) and Subsystem Number (SSN). */
        switch ((octet&0xf)){
        case 3:
            /* Octet string */
            /* Point Code Member Number octet 2 */
            b1 = tvb_get_uint8(tvb,offset);
            offset++;
            /* Point Code Cluster Number octet 3 */
            b2 = tvb_get_uint8(tvb,offset);
            offset++;
            /* Point Code Network Number octet 4 */
            b3 = tvb_get_uint8(tvb,offset);
            offset++;
            proto_tree_add_bytes_format_value(subtree, hf_ansi_map_point_code, tvb, offset-3, 3, NULL, "%u-%u-%u", b3, b2, b1);
            /* Subsystem Number (SSN) octet 5 */
            b4 = tvb_get_uint8(tvb,offset);
            proto_tree_add_item(subtree, hf_ansi_map_SSN, tvb, offset, 1, ENC_NA);
            proto_item_append_text(actx->created_item, " - Point Code %u-%u-%u  SSN %u", b3, b2, b1, b4);
            break;
        default:
            break;
        }
        break;
    case 14:/* Internet Protocol (IP) Address. */
        break;
    default:
        proto_tree_add_expert(subtree, pinfo, &ei_ansi_map_nr_not_used, tvb, offset, -1);
        break;
    }

}
/* 6.5.3.13. Subaddress */

/* Type of Subaddress (octet 1, bits E-G) */
static const value_string ansi_map_sub_addr_type_vals[]  = {
    {   0, "NSAP (CCITT Rec. X.213 or ISO 8348 AD2)"},
    {   1, "User specified"},
    {   2, "Reserved"},
    {   3, "Reserved"},
    {   4, "Reserved"},
    {   5, "Reserved"},
    {   6, "Reserved"},
    {   7, "Reserved"},
    {   0, NULL }
};

static void
dissect_ansi_map_subaddress(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
    /* Type of Subaddress (octet 1, bits E-G) */
    proto_tree_add_item(subtree, hf_ansi_map_subaddr_type, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Odd/Even Indicator (O/E) (octet 1, bit D) */
    proto_tree_add_item(subtree, hf_ansi_map_subaddr_odd_even, tvb, offset, 1, ENC_BIG_ENDIAN);

}
/*
 * 6.5.2.2 ActionCode
 * Table 114 ActionCode value
 *
 * 6.5.2.2 ActionCode(TIA/EIA-41.5-D, page 5-129) */

static const value_string ansi_map_ActionCode_vals[]  = {
    {   0, "Not used"},
    {   1, "Continue processing"},
    {   2, "Disconnect call"},
    {   3, "Disconnect call leg"},
    {   4, "Conference Calling Drop Last Party"},
    {   5, "Bridge call leg(s) to conference call"},
    {   6, "Drop call leg on busy or routing failure"},
    {   7, "Disconnect all call legs"},
    {   8, "Attach MSC to OTAF"},
    {   9, "Initiate RegistrationNotification"},
    {  10, "Generate Public Encryption values"},
    {  11, "Generate A-key"},
    {  12, "Perform SSD Update procedure"},
    {  13, "Perform Re-authentication procedure"},
    {  14, "Release TRN"},
    {  15, "Commit A-key"},
    {  16, "Release Resources (e.g., A-key, Traffic Channel)"},
    {  17, "Record NEWMSID"},
    {  18, "Allocate Resources (e.g., Multiple message traffic channel delivery)."},
    {  19, "Generate Authentication Signature"},
    {  20, "Release leg and redirect subscriber"},
    {  21, "Do Not Wait For MS User Level Response"},
    {  22, "Prepare for CDMA Handset-Based Position Determination"},
    {  23, "CDMA Handset-Based Position Determination Complete"},
    {   0, NULL }
};
static value_string_ext ansi_map_ActionCode_vals_ext = VALUE_STRING_EXT_INIT(ansi_map_ActionCode_vals);

/* 6.5.2.3 AlertCode */

/* Pitch (octet 1, bits G-H) */
static const value_string ansi_map_AlertCode_Pitch_vals[]  = {
    {   0, "Medium pitch"},
    {   1, "High pitch"},
    {   2, "Low pitch"},
    {   3, "Reserved"},
    {   0, NULL }
};
/* Cadence (octet 1, bits A-F) */
static const value_string ansi_map_AlertCode_Cadence_vals[]  = {
    {   0, "NoTone"},
    {   1, "Long"},
    {   2, "ShortShort"},
    {   3, "ShortShortLong"},
    {   4, "ShortShort2"},
    {   5, "ShortLongShort"},
    {   6, "ShortShortShortShort"},
    {   7, "PBXLong"},
    {   8, "PBXShortShort"},
    {   9, "PBXShortShortLong"},

    {  10, "PBXShortLongShort"},
    {  11, "PBXShortShortShortShort"},
    {  12, "PipPipPipPip"},
    {  13, "Reserved. Treat the same as value 0, NoTone"},
    {  14, "Reserved. Treat the same as value 0, NoTone"},
    {  15, "Reserved. Treat the same as value 0, NoTone"},
    {  16, "Reserved. Treat the same as value 0, NoTone"},
    {  17, "Reserved. Treat the same as value 0, NoTone"},
    {  18, "Reserved. Treat the same as value 0, NoTone"},
    {  19, "Reserved. Treat the same as value 0, NoTone"},
    {   0, NULL }
};

/* Alert Action (octet 2, bits A-C) */
static const value_string ansi_map_AlertCode_Alert_Action_vals[]  = {
    {   0, "Alert without waiting to report"},
    {   1, "Apply a reminder alert once"},
    {   2, "Other values reserved. Treat the same as value 0, Alert without waiting to report"},
    {   3, "Other values reserved. Treat the same as value 0, Alert without waiting to report"},
    {   4, "Other values reserved. Treat the same as value 0, Alert without waiting to report"},
    {   5, "Other values reserved. Treat the same as value 0, Alert without waiting to report"},
    {   6, "Other values reserved. Treat the same as value 0, Alert without waiting to report"},
    {   7, "Other values reserved. Treat the same as value 0, Alert without waiting to report"},
    {   0, NULL }
};
static void
dissect_ansi_map_alertcode(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
    /* Pitch (octet 1, bits G-H) */
    proto_tree_add_item(subtree, hf_ansi_alertcode_pitch, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Cadence (octet 1, bits A-F) */
    proto_tree_add_item(subtree, hf_ansi_alertcode_cadence, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;

    /* Alert Action (octet 2, bits A-C) */
    proto_tree_add_item(subtree, hf_ansi_alertcode_alertaction, tvb, offset, 1, ENC_BIG_ENDIAN);

}
/* 6.5.2.4 AlertResult */
/* Result (octet 1) */
static const value_string ansi_map_AlertResult_result_vals[]  = {
    {   0, "Not specified"},
    {   1, "Success"},
    {   2, "Failure"},
    {   3, "Denied"},
    {   4, "NotAttempted"},
    {   5, "NoPageResponse"},
    {   6, "Busy"},
    {   0, NULL }
};

/* 6.5.2.5 AnnouncementCode Updated from NS0018Re*/
/* Tone (octet 1) */
static const value_string ansi_map_AnnouncementCode_tone_vals[]  = {
    {   0, "DialTone"},
    {   1, "RingBack or AudibleAlerting"},
    {   2, "InterceptTone or MobileReorder"},
    {   3, "CongestionTone or ReorderTone"},
    {   4, "BusyTone"},
    {   5, "ConfirmationTone"},
    {   6, "AnswerTone"},
    {   7, "CallWaitingTone"},
    {   8, "OffHookTone"},
    {  17, "RecallDialTone"},
    {  18, "BargeInTone"},
    {  20, "PPCInsufficientTone"},
    {  21, "PPCWarningTone1"},
    {  22, "PPCWarningTone2"},
    {  23, "PPCWarningTone3"},
    {  24, "PPCDisconnectTone"},
    {  25, "PPCRedirectTone"},
    {  63, "TonesOff"},
    { 192, "PipTone"},
    { 193, "AbbreviatedIntercept"},
    { 194, "AbbreviatedCongestion"},
    { 195, "WarningTone"},
    { 196, "DenialToneBurst"},
    { 197, "DialToneBurst"},
    { 250, "IncomingAdditionalCallTone"},
    { 251, "PriorityAdditionalCallTone"},
    {   0, NULL }
};
/* Class (octet 2, bits A-D) */
static const value_string ansi_map_AnnouncementCode_class_vals[]  = {
    {   0, "Concurrent"},
    {   1, "Sequential"},
    {   0, NULL }
};
/* Standard Announcement (octet 3) Updated with N.S0015 */
static const value_string ansi_map_AnnouncementCode_std_ann_vals[]  = {
    {   0, "None"},
    {   1, "UnauthorizedUser"},
    {   2, "InvalidESN"},
    {   3, "UnauthorizedMobile"},
    {   4, "SuspendedOrigination"},
    {   5, "OriginationDenied"},
    {   6, "ServiceAreaDenial"},
    {  16, "PartialDial"},
    {  17, "Require1Plus"},
    {  18, "Require1PlusNPA"},
    {  19, "Require0Plus"},
    {  20, "Require0PlusNPA"},
    {  21, "Deny1Plus"},
    {  22, "Unsupported10plus"},
    {  23, "Deny10plus"},
    {  24, "Unsupported10XXX"},
    {  25, "Deny10XXX"},
    {  26, "Deny10XXXLocally"},
    {  27, "Require10Plus"},
    {  28, "RequireNPA"},
    {  29, "DenyTollOrigination"},
    {  30, "DenyInternationalOrigination"},
    {  31, "Deny0Minus"},
    {  48, "DenyNumber"},
    {  49, "AlternateOperatorServices"},
    {  64, "No Circuit or AllCircuitsBusy or FacilityProblem"},
    {  65, "Overload"},
    {  66, "InternalOfficeFailure"},
    {  67, "NoWinkReceived"},
    {  68, "InterofficeLinkFailure"},
    {  69, "Vacant"},
    {  70, "InvalidPrefix or InvalidAccessCode"},
    {  71, "OtherDialingIrregularity"},
    {  80, "VacantNumber or DisconnectedNumber"},
    {  81, "DenyTermination"},
    {  82, "SuspendedTermination"},
    {  83, "ChangedNumber"},
    {  84, "InaccessibleSubscriber"},
    {  85, "DenyIncomingTol"},
    {  86, "RoamerAccessScreening"},
    {  87, "RefuseCall"},
    {  88, "RedirectCall"},
    {  89, "NoPageResponse"},
    {  90, "NoAnswer"},
    {  96, "RoamerIntercept"},
    {  97, "GeneralInformation"},
    { 112, "UnrecognizedFeatureCode"},
    { 113, "UnauthorizedFeatureCode"},
    { 114, "RestrictedFeatureCode"},
    { 115, "InvalidModifierDigits"},
    { 116, "SuccessfulFeatureRegistration"},
    { 117, "SuccessfulFeatureDeRegistration"},
    { 118, "SuccessfulFeatureActivation"},
    { 119, "SuccessfulFeatureDeActivation"},
    { 120, "InvalidForwardToNumber"},
    { 121, "CourtesyCallWarning"},
    { 128, "EnterPINSendPrompt"},
    { 129, "EnterPINPrompt"},
    { 130, "ReEnterPINSendPrompt"},
    { 131, "ReEnterPINPrompt"},
    { 132, "EnterOldPINSendPrompt"},
    { 133, "EnterOldPINPrompt"},
    { 134, "EnterNewPINSendPrompt"},
    { 135, "EnterNewPINPrompt"},
    { 136, "ReEnterNewPINSendPrompt"},
    { 137, "ReEnterNewPINPrompt"},
    { 138, "EnterPasswordPrompt"},
    { 139, "EnterDirectoryNumberPrompt"},
    { 140, "ReEnterDirectoryNumberPrompt"},
    { 141, "EnterFeatureCodePrompt"},
    { 142, "EnterEnterCreditCardNumberPrompt"},
    { 143, "EnterDestinationNumberPrompt"},
    { 152, "PPCInsufficientAccountBalance"},
    { 153, "PPCFiveMinuteWarning"},
    { 154, "PPCThreeMinuteWarning"},
    { 155, "PPCTwoMinuteWarning"},
    { 156, "PPCOneMinuteWarning"},
    { 157, "PPCDisconnect"},
    { 158, "PPCRedirect"},
    {   0, NULL }
};



static void
dissect_ansi_map_announcementcode(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_billingid);

    /* Tone (octet 1) */
    proto_tree_add_item(subtree, hf_ansi_map_announcementcode_tone, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    /* Class (octet 2, bits A-D) */
    proto_tree_add_item(subtree, hf_ansi_map_announcementcode_class, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    /* Standard Announcement (octet 3) */
    proto_tree_add_item(subtree, hf_ansi_map_announcementcode_std_ann, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    /* Custom Announcement ( octet 4 )
       e.       The assignment of this octet is left to bilateral agreement. When a Custom
       Announcement is specified it takes precedence over either the Standard
       Announcement or Tone
    */
    proto_tree_add_item(subtree, hf_ansi_map_announcementcode_cust_ann, tvb, offset, 1, ENC_BIG_ENDIAN);

}
/* 6.5.2.8 AuthenticationCapability Updated N.S0003*/
static const value_string ansi_map_AuthenticationCapability_vals[]  = {
    {   0, "Not used"},
    {   1, "No authentication required"},
    {   2, "Authentication required"},
    { 128, "Authentication required and UIM capable."},
    {   0, NULL }
};

/* 6.5.2.14 AuthorizationPeriod*/

/* Period (octet 1) */
static const value_string ansi_map_authorizationperiod_period_vals[]  = {
    {   0, "Not used"},
    {   1, "Per Call"},
    {   2, "Hours"},
    {   3, "Days"},
    {   4, "Weeks"},
    {   5, "Per Agreement"},
    {   6, "Indefinite (i.e., authorized until canceled or deregistered)"},
    {   7, "Number of calls. Re-authorization should be attempted after this number of (rejected) call attempts"},
    {   0, NULL }
};
/* Value (octet 2)
Number of minutes hours, days, weeks, or
number of calls (as per Period). If Period
indicates anything else the Value is set to zero
on sending and ignored on receipt.
*/
static void
dissect_ansi_map_authorizationperiod(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
    proto_tree_add_item(subtree, hf_ansi_map_authorizationperiod_period, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    proto_tree_add_item(subtree, hf_ansi_map_value, tvb, offset, 1, ENC_BIG_ENDIAN);

}
/* 6.5.2.15 AvailabilityType */
static const value_string ansi_map_AvailabilityType_vals[]  = {
    {   0, "Not used"},
    {   1, "Unspecified MS inactivity type"},
    {   0, NULL }
};

/* 6.5.2.16 BillingID */
static void
dissect_ansi_map_billingid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_billingid);

    proto_tree_add_item(subtree, hf_ansi_map_MarketID, tvb, offset, 2, ENC_BIG_ENDIAN);
    offset = offset + 2;
    proto_tree_add_item(subtree, hf_ansi_map_swno, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    /* ID Number */
    proto_tree_add_item(subtree, hf_ansi_map_idno, tvb, offset, 3, ENC_BIG_ENDIAN);
    offset = offset + 3;
    proto_tree_add_item(subtree, hf_ansi_map_segcount, tvb, offset, 1, ENC_BIG_ENDIAN);

}


/* 6.5.2.20 CallingFeaturesIndicator */
static const value_string ansi_map_FeatureActivity_vals[]  = {
    {   0, "Not used"},
    {   1, "Not authorized"},
    {   2, "Authorized but de-activated"},
    {   3, "Authorized and activated"},
    {   0, NULL }
};


static void
dissect_ansi_map_callingfeaturesindicator(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
    int offset = 0;
    int length;

    proto_tree *subtree;

    length = tvb_reported_length_remaining(tvb,offset);

    subtree = proto_item_add_subtree(actx->created_item, ett_mscid);

    /* Call Waiting: FeatureActivity, CW-FA (Octet 1 bits GH )          */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cwfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Call Forwarding No Answer FeatureActivity, CFNA-FA (Octet 1 bits EF )    */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cfnafa, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Call Forwarding Busy FeatureActivity, CFB-FA (Octet 1 bits CD )  */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cfbfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Call Forwarding Unconditional FeatureActivity, CFU-FA (Octet 1 bits AB ) */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cfufa, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    length--;

    /* Call Transfer: FeatureActivity, CT-FA (Octet 2 bits GH )         */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_ctfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Voice Privacy FeatureActivity, VP-FA (Octet 2 bits EF )  */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_vpfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Call Delivery: FeatureActivity (not interpreted on reception by IS-41-C or later)
       CD-FA (Octet 2 bits CD )         */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cdfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Three-Way Calling FeatureActivity, 3WC-FA (Octet 2 bits AB )     */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_3wcfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    length--;


    /* Calling Number Identification Restriction Override FeatureActivity CNIROver-FA (Octet 3 bits GH )        */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cniroverfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Calling Number Identification Restriction: FeatureActivity CNIR-FA (Octet 3 bits EF )    */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cnirfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Calling Number Identification Presentation: FeatureActivity CNIP2-FA (Octet 3 bits CD )  */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cnip2fa, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Calling Number Identification Presentation: FeatureActivity CNIP1-FA (Octet 3 bits AB )  */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cnip1fa, tvb, offset, 1, ENC_BIG_ENDIAN);
    length--;
    if ( length == 0)
        return;
    offset++;

    /* USCF divert to voice mail: FeatureActivity USCFvm-FA (Octet 4 bits GH )  */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_uscfvmfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Answer Hold: FeatureActivity AH-FA (Octet 4 bits EF ) N.S0029-0 v1.0     */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_ahfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Data Privacy Feature Activity DP-FA (Octet 4 bits CD ) N.S0008-0 v 1.0   */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_dpfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Priority Call Waiting FeatureActivity PCW-FA (Octet 4 bits AB )  */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_pcwfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    length--;
    if ( length == 0)
        return;
    offset++;

    /* USCF divert to mobile station provided DN:FeatureActivity.USCFms-FA (Octet 5 bits AB ) */
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_uscfmsfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* USCF divert to network registered DN:FeatureActivity. USCFnr-FA (Octet 5 bits CD )*/
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_uscfnrfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* CDMA-Packet Data Service: FeatureActivity. CPDS-FA (Octet 5 bits EF ) N.S0029-0 v1.0*/
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_cpdsfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* CDMA-Concurrent Service:FeatureActivity. CCS-FA (Octet 5 bits GH ) N.S0029-0 v1.0*/
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_ccsfa, tvb, offset, 1, ENC_BIG_ENDIAN);
    length--;
    if ( length == 0)
        return;
    offset++;

    /* TDMA Enhanced Privacy and Encryption:FeatureActivity.TDMA EPE-FA (Octet 6 bits AB ) N.S0029-0 v1.0*/
    proto_tree_add_item(subtree, hf_ansi_map_callingfeaturesindicator_epefa, tvb, offset, 1, ENC_BIG_ENDIAN);
}


/* 6.5.2.27 CancellationType */
static const value_string ansi_map_CancellationType_vals[]  = {
    {   0, "Not used"},
    {   1, "ServingSystemOption"},
    {   2, "ReportInCall."},
    {   3, "Discontinue"},
    {   0, NULL }
};

/* 6.5.2.29 CDMACallMode Updated with N.S0029-0 v1.0*/
/* Call Mode (octet 1, bit A) */
static const true_false_string ansi_map_CDMACallMode_cdma_bool_val  = {
  "CDMA 800 MHz channel (Band Class 0) acceptable.",
  "CDMA 800 MHz channel (Band Class 0) not acceptable"
};
/* Call Mode (octet 1, bit B) */
static const true_false_string ansi_map_CallMode_amps_bool_val  = {
    "AAMPS 800 MHz channel acceptable",
    "AMPS 800 MHz channel not acceptable"
};
/* Call Mode (octet 1, bit C) */
static const true_false_string ansi_map_CallMode_namps_bool_val  = {
    "NAMPS 800 MHz channel acceptable",
    "NAMPS 800 MHz channel not acceptable"
};
/* Call Mode (octet 1, bit D) */
static const true_false_string ansi_map_CDMACallMode_cls1_bool_val  = {
    "CDMA 1900 MHz channel (Band Class 1) acceptable.",
    "CDMA 1900 MHz channel (Band Class 1) not acceptable"
};
/* Call Mode (octet 1, bit E) */
static const true_false_string ansi_map_CDMACallMode_cls2_bool_val  = {
    "TACS channel (Band Class 2) acceptable",
    "TACS channel (Band Class 2) not acceptable"
};
/* Call Mode (octet 1, bit F) */
static const true_false_string ansi_map_CDMACallMode_cls3_bool_val  = {
    "JTACS channel (Band Class 3) acceptable",
    "JTACS channel (Band Class 3) not acceptable"
};
/* Call Mode (octet 1, bit G) */
static const true_false_string ansi_map_CDMACallMode_cls4_bool_val  = {
    "Korean PCS channel (Band Class 4) acceptable",
    "Korean PCS channel (Band Class 4) not acceptable"
};
/* Call Mode (octet 1, bit H) */
static const true_false_string ansi_map_CDMACallMode_cls5_bool_val  = {
    "450 MHz channel (Band Class 5) acceptable",
    "450 MHz channel (Band Class 5) not acceptable"
};
/* Call Mode (octet 2, bit A) */
static const true_false_string ansi_map_CDMACallMode_cls6_bool_val  = {
    "2 GHz channel (Band Class 6) acceptable.",
    "2 GHz channel (Band Class 6) not acceptable."
};

/* Call Mode (octet 2, bit B) */
static const true_false_string ansi_map_CDMACallMode_cls7_bool_val  = {
    "700 MHz channel (Band Class 7) acceptable",
    "700 MHz channel (Band Class 7) not acceptable"
};

/* Call Mode (octet 2, bit C) */
static const true_false_string ansi_map_CDMACallMode_cls8_bool_val  = {
    "1800 MHz channel (Band Class 8) acceptable",
    "1800 MHz channel (Band Class 8) not acceptable"
};
/* Call Mode (octet 2, bit D) */
static const true_false_string ansi_map_CDMACallMode_cls9_bool_val  = {
    "900 MHz channel (Band Class 9) acceptable",
    "900 MHz channel (Band Class 9) not acceptable"
};
/* Call Mode (octet 2, bit E) */
static const true_false_string ansi_map_CDMACallMode_cls10_bool_val  = {
    "Secondary 800 MHz channel (Band Class 10) acceptable.",
    "Secondary 800 MHz channel (Band Class 10) not acceptable."
};

static void
dissect_ansi_map_cdmacallmode(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
    int offset = 0;
    int length;

    proto_tree *subtree;

    length = tvb_reported_length_remaining(tvb,offset);


    subtree = proto_item_add_subtree(actx->created_item, ett_mscid);
    /* Call Mode (octet 1, bit H) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls5, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Call Mode (octet 1, bit G) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls4, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Call Mode (octet 1, bit F) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls3, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Call Mode (octet 1, bit E) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls2, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Call Mode (octet 1, bit D) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls1, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Call Mode (octet 1, bit C) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_namps, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Call Mode (octet 1, bit B) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_amps, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Call Mode (octet 1, bit A) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cdma, tvb, offset, 1, ENC_BIG_ENDIAN);

    length--;
    if ( length == 0)
        return;
    offset++;

    /* Call Mode (octet 2, bit E) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls10, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Call Mode (octet 2, bit D) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls9, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Call Mode (octet 2, bit C) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls8, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Call Mode (octet 2, bit B) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls7, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Call Mode (octet 2, bit A) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmacallmode_cls6, tvb, offset, 1, ENC_BIG_ENDIAN);

}
/* 6.5.2.30 CDMAChannelData */
/* Updated with N.S0010-0 v 1.0 */

static const value_string ansi_map_cdmachanneldata_band_cls_vals[]  = {
    {   0, "800 MHz Cellular System"},
    {   0, NULL }
};

static void
dissect_ansi_map_cdmachanneldata(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;
    int length;

    proto_tree *subtree;

    length = tvb_reported_length_remaining(tvb,offset);


    subtree = proto_item_add_subtree(actx->created_item, ett_cdmachanneldata);

    proto_tree_add_item(subtree, hf_ansi_map_reservedBitH, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_Frame_Offset, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* CDMA Channel Number */
    proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_CDMA_ch_no, tvb, offset, 2, ENC_BIG_ENDIAN);
    offset = offset + 2;
    length = length -2;
    /* Band Class */
    proto_tree_add_item(subtree, hf_ansi_map_reservedBitH, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_band_cls, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Long Code Mask */
    proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_lc_mask_b6, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_lc_mask_b5, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_lc_mask_b4, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_lc_mask_b3, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_lc_mask_b2, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_lc_mask_b1, tvb, offset, 1, ENC_BIG_ENDIAN);
    length = length - 6;
    if (length == 0)
        return;
    offset++;
    /* NP_EXT */
    proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_np_ext, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Nominal Power */
    proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_nominal_pwr, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Number Preamble */
    proto_tree_add_item(subtree, hf_ansi_map_cdmachanneldata_nr_preamble, tvb, offset, 1, ENC_BIG_ENDIAN);

}
/* 6.5.2.31 CDMACodeChannel */

/* 6.5.2.41 CDMAStationClassMark */
/* Power Class: (PC) (octet 1, bits A and B) */
static const value_string ansi_map_CDMAStationClassMark_pc_vals[]  = {
    {   0, "Class I"},
    {   1, "Class II"},
    {   2, "Class III"},
    {   3, "Reserved"},
    {   0, NULL }
};
/* Analog Transmission: (DTX) (octet 1, bit C) */
static const true_false_string ansi_map_CDMAStationClassMark_dtx_bool_val  = {
    "Discontinuous",
    "Continuous"
};
/* Slotted Mode Indicator: (SMI) (octet 1, bit F) */
static const true_false_string ansi_map_CDMAStationClassMark_smi_bool_val  = {
    "Slotted capable",
    "Slotted incapable"
};
/* Dual-mode Indicator(DMI) (octet 1, bit G) */
static const true_false_string ansi_map_CDMAStationClassMark_dmi_bool_val  = {
    "Dual-mode CDMA",
    "CDMA only"
};


static void
dissect_ansi_map_cdmastationclassmark(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_cdmastationclassmark);

    proto_tree_add_item(subtree, hf_ansi_map_reservedBitH, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Dual-mode Indicator(DMI) (octet 1, bit G) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmastationclassmark_dmi, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Slotted Mode Indicator: (SMI) (octet 1, bit F) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmastationclassmark_smi, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_reservedBitED, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Analog Transmission: (DTX) (octet 1, bit C) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmastationclassmark_dtx, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Power Class: (PC) (octet 1, bits A and B) */
    proto_tree_add_item(subtree, hf_ansi_map_cdmastationclassmark_pc, tvb, offset, 1, ENC_BIG_ENDIAN);
}
/* 6.5.2.47 ChannelData */
/* Discontinuous Transmission Mode (DTX) (octet 1, bits E and D) */
static const value_string ansi_map_ChannelData_dtx_vals[]  = {
    {   0, "DTX disabled"},
    {   1, "Reserved. Treat the same as value 00, DTX disabled."},
    {   2, "DTX-low mode"},
    {   3, "DTX mode active or acceptable"},
    {   0, NULL }
};


static void
dissect_ansi_map_channeldata(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_channeldata);

    /* SAT Color Code (SCC) (octet 1, bits H and G) */
    proto_tree_add_item(subtree, hf_ansi_map_channeldata_scc, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Discontinuous Transmission Mode (DTX) (octet 1, bits E and D) */
    proto_tree_add_item(subtree, hf_ansi_map_channeldata_dtx, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Voice Mobile Attenuation Code (VMAC) (octet 1, bits A - C)*/
    proto_tree_add_item(subtree, hf_ansi_map_channeldata_vmac, tvb, offset, 1, ENC_BIG_ENDIAN);

    offset++;
    /* Channel Number (CHNO) ( octet 2 and 3 ) */
    proto_tree_add_item(subtree, hf_ansi_map_channeldata_chno, tvb, offset, 2, ENC_BIG_ENDIAN);

}

/* 6.5.2.50 ConfidentialityModes */
/* Updated with N.S0008-0 v 1.0*/
/* Voice Privacy (VP) Confidentiality Status (octet 1, bit A) */

static void
dissect_ansi_map_confidentialitymodes(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_confidentialitymodes);

    /* DataPrivacy (DP) Confidentiality Status (octet 1, bit C) */
    proto_tree_add_item(subtree, hf_ansi_map_ConfidentialityModes_dp, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Signaling Message Encryption (SE) Confidentiality Status (octet 1, bit B) */
    proto_tree_add_item(subtree, hf_ansi_map_ConfidentialityModes_se, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Voice Privacy (VP) Confidentiality Status (octet 1, bit A) */
    proto_tree_add_item(subtree, hf_ansi_map_ConfidentialityModes_vp, tvb, offset, 1, ENC_BIG_ENDIAN);

}

/* 6.5.2.51 ControlChannelData */

/* Digital Color Code (DCC) (octet 1, bit H and G) */
/* Control Mobile Attenuation Code (CMAC) (octet 1, bit A - C) */
/* Channel Number (CHNO) ( octet 2 and 3 ) */
/* Supplementary Digital Color Codes (SDCC1 and SDCC2) */
/* SDCC1 ( octet 4, bit D and C )*/
/* SDCC2 ( octet 4, bit A and B )*/

static void
dissect_ansi_map_controlchanneldata(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_controlchanneldata);

    /* Digital Color Code (DCC) (octet 1, bit H and G) */
    proto_tree_add_item(subtree, hf_ansi_map_controlchanneldata_dcc, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_reservedBitFED, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Control Mobile Attenuation Code (CMAC) (octet 1, bit A - C) */
    proto_tree_add_item(subtree, hf_ansi_map_controlchanneldata_cmac, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    /* Channel Number (CHNO) ( octet 2 and 3 ) */
    proto_tree_add_item(subtree, hf_ansi_map_controlchanneldata_chno, tvb, offset, 2, ENC_BIG_ENDIAN);
    /* Supplementary Digital Color Codes (SDCC1 and SDCC2) */
    offset = offset +2;
    /* SDCC1 ( octet 4, bit D and C )*/
    proto_tree_add_item(subtree, hf_ansi_map_controlchanneldata_sdcc1, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_reservedBitHGFE, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* SDCC2 ( octet 4, bit A and B )*/
    proto_tree_add_item(subtree, hf_ansi_map_controlchanneldata_sdcc2, tvb, offset, 1, ENC_BIG_ENDIAN);

}

/* 6.5.2.52 CountUpdateReport */
static const value_string ansi_map_CountUpdateReport_vals[]  = {
    {   0, "Class I"},
    {   1, "Class II"},
    {   2, "Class III"},
    {   3, "Reserved"},
    {   0, NULL }
};

/* 6.5.2.53 DeniedAuthorizationPeriod */
/* Period (octet 1) */
static const value_string ansi_map_deniedauthorizationperiod_period_vals[]  = {
    {   0, "Not used"},
    {   1, "Per Call. Re-authorization should be attempted on the next call attempt"},
    {   2, "Hours"},
    {   3, "Days"},
    {   4, "Weeks"},
    {   5, "Per Agreement"},
    {   6, "Reserved"},
    {   7, "Number of calls. Re-authorization should be attempted after this number of (rejected) call attempts"},
    {   8, "Minutes"},
    {   0, NULL }
};
/* Value (octet 2)
Number of minutes hours, days, weeks, or
number of calls (as per Period). If Period
indicates anything else the Value is set to zero
on sending and ignored on receipt.
*/

static void
dissect_ansi_map_deniedauthorizationperiod(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
    proto_tree_add_item(subtree, hf_ansi_map_deniedauthorizationperiod_period, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    proto_tree_add_item(subtree, hf_ansi_map_value, tvb, offset, 1, ENC_BIG_ENDIAN);

}


/* 6.5.2.57 DigitCollectionControl */
/* TODO Add decoding here */

/* 6.5.2.64 ExtendedMSCID */
static const value_string ansi_map_msc_type_vals[]  = {
    {   0, "Not specified"},
    {   1, "Serving MSC"},
    {   2, "Home MSC"},
    {   3, "Gateway MSC"},
    {   4, "HLR"},
    {   5, "VLR"},
    {   6, "EIR (reserved)"},
    {   7, "AC"},
    {   8, "Border MSC"},
    {   9, "Originating MSC"},
    {   0, NULL }
};

static void
dissect_ansi_map_extendedmscid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_extendedmscid);
    /* Type (octet 1) */
    proto_tree_add_item(subtree, hf_ansi_map_msc_type, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    proto_tree_add_item(subtree, hf_ansi_map_MarketID, tvb, offset, 2, ENC_BIG_ENDIAN);
    offset = offset + 2;
    proto_tree_add_item(subtree, hf_ansi_map_swno, tvb, offset, 1, ENC_BIG_ENDIAN);

}
/* 6.5.2.65 ExtendedSystemMyTypeCode */
static void
dissect_ansi_map_extendedsystemmytypecode(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx){

    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_extendedsystemmytypecode);
    /* Type (octet 1) */
    proto_tree_add_item(subtree, hf_ansi_map_msc_type, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    dissect_ansi_map_SystemMyTypeCode(true, tvb, offset, actx, subtree, hf_ansi_map_systemMyTypeCode);
}


/* 6.5.2.68 GeographicAuthorization */
/* Geographic Authorization (octet 1) */
static const value_string ansi_map_GeographicAuthorization_vals[]  = {
    {   0, "Not used"},
    {   1, "Authorized for all MarketIDs served by the VLR"},
    {   2, "Authorized for this MarketID only"},
    {   3, "Authorized for this MarketID and Switch Number only"},
    {   4, "Authorized for this LocationAreaID within a MarketID only"},
    {   5, "VLR"},
    {   6, "EIR (reserved)"},
    {   7, "AC"},
    {   8, "Border MSC"},
    {   9, "Originating MSC"},
    {   0, NULL }
};

/* 6.5.2.71 HandoffState */
/* Party Involved (PI) (octet 1, bit A) */
static const true_false_string ansi_map_HandoffState_pi_bool_val  = {
    "Terminator is handing off",
    "Originator is handing off"
};
static void
dissect_ansi_map_handoffstate(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_handoffstate);
    /* Party Involved (PI) (octet 1, bit A) */
    proto_tree_add_item(subtree, hf_ansi_map_handoffstate_pi, tvb, offset, 1, ENC_BIG_ENDIAN);
}

/* 6.5.2.72 InterMSCCircuitID */
/* Trunk Member Number (M) Octet2 */
static void
dissect_ansi_map_intermsccircuitid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;

    proto_tree *subtree;
    uint8_t octet, octet2;


    subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
    /* Trunk Group Number (G) Octet 1 */
    octet = tvb_get_uint8(tvb,offset);
    proto_tree_add_item(subtree, hf_ansi_map_tgn, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    /* Trunk Member Number (M) Octet2 */
    octet2 = tvb_get_uint8(tvb,offset);
    proto_tree_add_item(subtree, hf_ansi_map_tmn, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_item_append_text(actx->created_item, " (G %u/M %u)", octet, octet2);
}

/* 6.5.2.78 MessageWaitingNotificationCount */
/* Type of messages (octet 1) */
static const value_string ansi_map_MessageWaitingNotificationCount_type_vals[]  = {
    {   0, "Voice messages"},
    {   1, "Short Message Services (SMS) messages"},
    {   2, "Group 3 (G3) Fax messages"},
    {   0, NULL }
};

static void
dissect_ansi_map_messagewaitingnotificationcount(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
    /* Type of messages (octet 1) */
    proto_tree_add_item(subtree, hf_ansi_map_messagewaitingnotificationcount_tom, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    /* Number of Messages Waiting (octet 2) */
    proto_tree_add_item(subtree, hf_ansi_map_messagewaitingnotificationcount_no_mw, tvb, offset, 1, ENC_BIG_ENDIAN);

}

#if 0
/* 6.5.2.79 MessageWaitingNotificationType */
/* Pip Tone (PT) (octet 1, bit A) */
static const true_false_string ansi_map_MessageWaitingNotificationType_pt_bool_val  = {
    "Pip Tone (PT) notification is required",
    "Pip Tone (PT) notification is not authorized or no notification is required"
};
#endif
#if 0
/* Alert Pip Tone (APT) (octet 1, bit B) */
static const true_false_string ansi_map_MessageWaitingNotificationType_apt_bool_val  = {
    "Alert Pip Tone (APT) notification is required",
    "Alert Pip Tone (APT) notification is not authorized or notification is not required"
};
#endif
/* Message Waiting Indication (MWI) (octet 1, bits C and D) */
static const value_string ansi_map_MessageWaitingNotificationType_mwi_vals[]  = {
    {   0, "No MWI. Message Waiting Indication (MWI) notification is not authorized or notification is not required"},
    {   1, "Reserved"},
    {   2, "MWI On. Message Waiting Indication (MWI) notification is required. Messages waiting"},
    {   3, "MWI Off. Message Waiting Indication (MWI) notification is required. No messages waiting"},
    {   0, NULL }
};

static void
dissect_ansi_map_messagewaitingnotificationtype(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_billingid);

    /* Message Waiting Indication (MWI) (octet 1, bits C and D) */
    proto_tree_add_item(subtree, hf_ansi_map_messagewaitingnotificationtype_mwi, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Alert Pip Tone (APT) (octet 1, bit B) */
    proto_tree_add_item(subtree, hf_ansi_map_messagewaitingnotificationtype_apt, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Pip Tone (PT) (octet 1, bit A) */
    proto_tree_add_item(subtree, hf_ansi_map_messagewaitingnotificationtype_pt, tvb, offset, 1, ENC_BIG_ENDIAN);
}

/* 6.5.2.81 MobileIdentificationNumber */

/* 6.5.2.82 MSCID */

static void
dissect_ansi_map_mscid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_mscid);

    proto_tree_add_item(subtree, hf_ansi_map_MarketID, tvb, offset, 2, ENC_BIG_ENDIAN);
    offset = offset + 2;
    proto_tree_add_item(subtree, hf_ansi_map_swno, tvb, offset, 1, ENC_BIG_ENDIAN);
}


/* 6.5.2.84 MSLocation */
static void
dissect_ansi_map_mslocation(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
    int offset = 0;

    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_mscid);

    /* Latitude in tenths of a second octet 1 - 3 */
    proto_tree_add_item(subtree, hf_ansi_map_mslocation_lat, tvb, offset, 3, ENC_BIG_ENDIAN);
    offset = offset + 3;
    /* Longitude in tenths of a second octet 4 - 6 */
    proto_tree_add_item(subtree, hf_ansi_map_mslocation_long, tvb, offset, 3, ENC_BIG_ENDIAN);
    offset = offset + 3;
    /* Resolution in units of 1 foot octet 7, octet 8 optional */
    proto_tree_add_item(subtree, hf_ansi_map_mslocation_res, tvb, offset, -1, ENC_BIG_ENDIAN);

}
/* 6.5.2.85 NAMPSCallMode */
static void
dissect_ansi_map_nampscallmode(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
    int offset = 0;
    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_mscid);

    /* Call Mode (octet 1, bits A and B) */
    proto_tree_add_item(subtree, hf_ansi_map_nampscallmode_amps, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_nampscallmode_namps, tvb, offset, 1, ENC_BIG_ENDIAN);
}

/* 6.5.2.86 NAMPSChannelData */
/* Narrow Analog Voice Channel Assignment (NAVCA) (octet 1, bits A and B) */
static const value_string ansi_map_NAMPSChannelData_navca_vals[]  = {
    {   0, "Wide. 30 kHz AMPS voice channel"},
    {   1, "Upper. 10 kHz NAMPS voice channel"},
    {   2, "Middle. 10 kHz NAMPS voice channel"},
    {   3, "Lower. 10 kHz NAMPS voice channel"},
    {   0, NULL }
};
/* Color Code Indicator (CCIndicator) (octet 1, bits C, D, and E) */
static const value_string ansi_map_NAMPSChannelData_ccinidicator_vals[]  = {
    {   0, "ChannelData parameter SCC field applies"},
    {   1, "Digital SAT Color Code 1 (ignore SCC field)"},
    {   2, "Digital SAT Color Code 2 (ignore SCC field)"},
    {   3, "Digital SAT Color Code 3 (ignore SCC field)"},
    {   4, "Digital SAT Color Code 4 (ignore SCC field)"},
    {   5, "Digital SAT Color Code 5 (ignore SCC field)"},
    {   6, "Digital SAT Color Code 6 (ignore SCC field)"},
    {   7, "Digital SAT Color Code 7 (ignore SCC field)"},
    {   0, NULL }
};



static void
dissect_ansi_map_nampschanneldata(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
    int offset = 0;
    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_mscid);

    /* Color Code Indicator (CCIndicator) (octet 1, bits C, D, and E) */
    proto_tree_add_item(subtree, hf_ansi_map_nampschanneldata_CCIndicator, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Narrow Analog Voice Channel Assignment (NAVCA) (octet 1, bits A and B) */
    proto_tree_add_item(subtree, hf_ansi_map_nampschanneldata_navca, tvb, offset, 1, ENC_BIG_ENDIAN);

}

#if 0
/* 6.5.2.88 OneTimeFeatureIndicator */
/* updated with N.S0012 */
/* Call Waiting for Future Incoming Call (CWFI) (octet 1, bits A and B) */
/* Call Waiting for Incoming Call (CWIC) (octet 1, bits C and D) */

static const value_string ansi_map_onetimefeatureindicator_cw_vals[]  = {
    {   0, "Ignore"},
    {   1, "No CW"},
    {   2, "Normal CW"},
    {   3, "Priority CW"},
    {   0, NULL }
};
#endif
#if 0
/* MessageWaitingNotification (MWN) (octet 1, bits E and F) */
static const value_string ansi_map_onetimefeatureindicator_mwn_vals[]  = {
    {   0, "Ignore"},
    {   1, "Pip Tone Inactive"},
    {   2, "Pip Tone Active"},
    {   3, "Reserved"},
    {   0, NULL }
};
#endif
#if 0
/* Calling Number Identification Restriction (CNIR) (octet 1, bits G and H)*/
static const value_string ansi_map_onetimefeatureindicator_cnir_vals[]  = {
    {   0, "Ignore"},
    {   1, "CNIR Inactive"},
    {   2, "CNIR Active"},
    {   3, "Reserved"},
    {   0, NULL }
};
#endif

#if 0
/* Priority Access and Channel Assignment (PACA) (octet 2, bits A and B)*/
static const value_string ansi_map_onetimefeatureindicator_paca_vals[]  = {
    {   0, "Ignore"},
    {   1, "PACA Demand Inactive"},
    {   2, "PACA Demand Activated"},
    {   3, "Reserved"},
    {   0, NULL }
};
#endif

#if 0
/* Flash Privileges (Flash) (octet 2, bits C and D) */
static const value_string ansi_map_onetimefeatureindicator_flash_vals[]  = {
    {   0, "Ignore"},
    {   1, "Flash Inactive"},
    {   2, "Flash Active"},
    {   3, "Reserved"},
    {   0, NULL }
};
#endif
#if 0
/* Calling Name Restriction (CNAR) (octet 2, bits E and F) */
static const value_string ansi_map_onetimefeatureindicator_cnar_vals[]  = {
    {   0, "Ignore"},
    {   1, "Presentation Allowed"},
    {   2, "Presentation Restricted."},
    {   3, "Blocking Toggle"},
    {   0, NULL }
};
#endif
static void
dissect_ansi_map_onetimefeatureindicator(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
    /*
    int offset = 0;
    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_mscid);
    */
    /* Calling Number Identification Restriction (CNIR) (octet 1, bits G and H)*/
    /* MessageWaitingNotification (MWN) (octet 1, bits E and F) */
    /* Call Waiting for Incoming Call (CWIC) (octet 1, bits C and D) */
    /* Call Waiting for Future Incoming Call (CWFI) (octet 1, bits A and B) */
    /*offset++;*/
    /* Calling Name Restriction (CNAR) (octet 2, bits E and F) */
    /* Flash Privileges (Flash) (octet 2, bits C and D) */
    /* Priority Access and Channel Assignment (PACA) (octet 2, bits A and B)*/


}

/* 6.5.2.90 OriginationTriggers */
/* All Origination (All) (octet 1, bit A) */
static const true_false_string ansi_map_originationtriggers_all_bool_val  = {
    "Launch an OriginationRequest for any call attempt. This overrides all other values",
    "Trigger is not active"
};

/* Local (octet 1, bit B) */
static const true_false_string ansi_map_originationtriggers_local_bool_val  = {
    "Launch an OriginationRequest for any local call attempt",
    "Trigger is not active"
};

/* Intra-LATA Toll (ILATA) (octet 1, bit C) */
static const true_false_string ansi_map_originationtriggers_ilata_bool_val  = {
    "Launch an OriginationRequest for any intra-LATA call attempt",
    "Trigger is not active"
};
/* Inter-LATA Toll (OLATA) (octet 1, bit D) */
static const true_false_string ansi_map_originationtriggers_olata_bool_val  = {
    "Launch an OriginationRequest for any inter-LATA toll call attempt",
    "Trigger is not active"
};
/* International (Int'l ) (octet 1, bit E) */
static const true_false_string ansi_map_originationtriggers_int_bool_val  = {
    "Launch an OriginationRequest for any international call attempt",
    "Trigger is not active"
};
/* World Zone (WZ) (octet 1, bit F) */
static const true_false_string ansi_map_originationtriggers_wz_bool_val  = {
    "Launch an OriginationRequest for any call attempt outside of the current World Zone (as defined in ITU-T Rec. E.164)",
    "Trigger is not active"
};

/* Unrecognized Number (Unrec) (octet 1, bit G) */
static const true_false_string ansi_map_originationtriggers_unrec_bool_val  = {
    "Launch an OriginationRequest for any call attempt to an unrecognized number",
    "Trigger is not active"
};
/* Revertive Call (RvtC) (octet 1, bit H)*/
static const true_false_string ansi_map_originationtriggers_rvtc_bool_val  = {
    "Launch an OriginationRequest for any Revertive Call attempt",
    "Trigger is not active"
};

/* Star (octet 2, bit A) */
static const true_false_string ansi_map_originationtriggers_star_bool_val  = {
    "Launch an OriginationRequest for any number beginning with a Star '*' digit",
    "Trigger is not active"
};

/* Double Star (DS) (octet 2, bit B) */
static const true_false_string ansi_map_originationtriggers_ds_bool_val  = {
    "Launch an OriginationRequest for any number beginning with two Star '**' digits",
    "Trigger is not active"
};
/* Pound (octet 2, bit C) */
static const true_false_string ansi_map_originationtriggers_pound_bool_val  = {
    "Launch an OriginationRequest for any number beginning with a Pound '#' digit",
    "Trigger is not active"
};
/* Double Pound (DP) (octet 2, bit D) */
static const true_false_string ansi_map_originationtriggers_dp_bool_val  = {
    "Launch an OriginationRequest for any number beginning with two Pound '##' digits",
    "Trigger is not active"
};
/* Prior Agreement (PA) (octet 2, bit E) */
static const true_false_string ansi_map_originationtriggers_pa_bool_val  = {
    "Launch an OriginationRequest for any number matching a criteria of a prior agreement",
    "Trigger is not active"
};

/* No digits (octet 3, bit A) */
static const true_false_string ansi_map_originationtriggers_nodig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with no digits",
    "Trigger is not active"
};

/* 1 digit (octet 3, bit B) */
static const true_false_string ansi_map_originationtriggers_onedig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with 1 digit",
    "Trigger is not active"
};
/* 1 digit (octet 3, bit C) */
static const true_false_string ansi_map_originationtriggers_twodig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with 2 digits",
    "Trigger is not active"
};
/* 1 digit (octet 3, bit D) */
static const true_false_string ansi_map_originationtriggers_threedig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with 3 digits",
    "Trigger is not active"
};
/* 1 digit (octet 3, bit E) */
static const true_false_string ansi_map_originationtriggers_fourdig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with 4 digits",
    "Trigger is not active"
};
/* 1 digit (octet 3, bit F) */
static const true_false_string ansi_map_originationtriggers_fivedig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with 5 digits",
    "Trigger is not active"
};
/* 1 digit (octet 3, bit G) */
static const true_false_string ansi_map_originationtriggers_sixdig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with 6 digits",
    "Trigger is not active"
};
/* 1 digit (octet 3, bit H) */
static const true_false_string ansi_map_originationtriggers_sevendig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with 7 digits",
    "Trigger is not active"
};
/* 1 digit (octet 4, bit A) */
static const true_false_string ansi_map_originationtriggers_eightdig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with 8 digits",
    "Trigger is not active"
};
/* 1 digit (octet 4, bit B) */
static const true_false_string ansi_map_originationtriggers_ninedig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with 9 digits",
    "Trigger is not active"
};
/* 1 digit (octet 4, bit C) */
static const true_false_string ansi_map_originationtriggers_tendig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with 10 digits",
    "Trigger is not active"
};
/* 1 digit (octet 4, bit D) */
static const true_false_string ansi_map_originationtriggers_elevendig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with 11 digits",
    "Trigger is not active"
};
/* 1 digit (octet 4, bit E) */
static const true_false_string ansi_map_originationtriggers_twelvedig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with 12 digits",
    "Trigger is not active"
};
/* 1 digit (octet 4, bit F) */
static const true_false_string ansi_map_originationtriggers_thirteendig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with 13 digits",
    "Trigger is not active"
};
/* 1 digit (octet 4, bit G) */
static const true_false_string ansi_map_originationtriggers_fourteendig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with 14 digits",
    "Trigger is not active"
};
/* 1 digit (octet 4, bit H) */
static const true_false_string ansi_map_originationtriggers_fifteendig_bool_val  = {
    "Launch an OriginationRequest for any call attempt with 15 digits",
    "Trigger is not active"
};

static void
dissect_ansi_map_originationtriggers(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;
    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_originationtriggers);

    /* Revertive Call (RvtC) (octet 1, bit H)*/
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_rvtc, tvb, offset,     1, ENC_BIG_ENDIAN);
    /* Unrecognized Number (Unrec) (octet 1, bit G) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_unrec, tvb, offset,    1, ENC_BIG_ENDIAN);
    /* World Zone (WZ) (octet 1, bit F) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_wz, tvb, offset,       1, ENC_BIG_ENDIAN);
    /* International (Int'l ) (octet 1, bit E) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_int, tvb, offset,      1, ENC_BIG_ENDIAN);
    /* Inter-LATA Toll (OLATA) (octet 1, bit D) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_olata, tvb, offset,    1, ENC_BIG_ENDIAN);
    /* Intra-LATA Toll (ILATA) (octet 1, bit C) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_ilata, tvb, offset,    1, ENC_BIG_ENDIAN);
    /* Local (octet 1, bit B) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_local, tvb, offset,    1, ENC_BIG_ENDIAN);
    /* All Origination (All) (octet 1, bit A) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_all, tvb, offset,      1, ENC_BIG_ENDIAN);
    offset++;

    /*Prior Agreement (PA) (octet 2, bit E) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_pa, tvb, offset,       1, ENC_BIG_ENDIAN);
    /* Double Pound (DP) (octet 2, bit D) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_dp, tvb, offset,       1, ENC_BIG_ENDIAN);
    /* Pound (octet 2, bit C) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_pound, tvb, offset,    1, ENC_BIG_ENDIAN);
    /* Double Star (DS) (octet 2, bit B) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_ds, tvb, offset,       1, ENC_BIG_ENDIAN);
    /* Star (octet 2, bit A) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_star, tvb, offset,     1, ENC_BIG_ENDIAN);
    offset++;

    /* 7 digit (octet 3, bit H) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_sevendig, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* 6 digit (octet 3, bit G) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_sixdig, tvb, offset,   1, ENC_BIG_ENDIAN);
    /* 5 digit (octet 3, bit F) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_fivedig, tvb, offset,  1, ENC_BIG_ENDIAN);
    /* 4 digit (octet 3, bit E) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_fourdig, tvb, offset,  1, ENC_BIG_ENDIAN);
    /* 3 digit (octet 3, bit D) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_threedig, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* 2 digit (octet 3, bit C) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_twodig, tvb, offset,   1, ENC_BIG_ENDIAN);
    /* 1 digit (octet 3, bit B) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_onedig, tvb, offset,   1, ENC_BIG_ENDIAN);
    /* No digits (octet 3, bit A) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_nodig, tvb, offset,    1, ENC_BIG_ENDIAN);
    offset++;

    /* 15 digit (octet 4, bit H) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_fifteendig, tvb, offset,       1, ENC_BIG_ENDIAN);
    /* 14 digit (octet 4, bit G) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_fourteendig, tvb, offset,      1, ENC_BIG_ENDIAN);
    /* 13 digit (octet 4, bit F) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_thirteendig, tvb, offset,      1, ENC_BIG_ENDIAN);
    /* 12 digit (octet 4, bit E) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_twelvedig, tvb, offset,        1, ENC_BIG_ENDIAN);
    /* 11 digit (octet 4, bit D) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_elevendig, tvb, offset,        1, ENC_BIG_ENDIAN);
    /* 10 digit (octet 4, bit C) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_tendig, tvb, offset,   1, ENC_BIG_ENDIAN);
    /* 9 digit (octet 4, bit B) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_ninedig, tvb, offset,  1, ENC_BIG_ENDIAN);
    /* 8 digits (octet 4, bit A) */
    proto_tree_add_item(subtree, hf_ansi_map_originationtriggers_eightdig, tvb, offset, 1, ENC_BIG_ENDIAN);

}

/* 6.5.2.91 PACAIndicator */

/* Permanent Activation (PA) (octet 1, bit A) */
static const true_false_string ansi_map_pacaindicator_pa_bool_val  = {
    "PACA is permanently activated",
    "PACA is not permanently activated"
};

static const value_string ansi_map_PACA_Level_vals[]  = {
    {   0, "Not used"},
    {   1, "Priority Level. 1 This is the highest level"},
    {   2, "Priority Level 2"},
    {   3, "Priority Level 3"},
    {   4, "Priority Level 4"},
    {   5, "Priority Level 5"},
    {   6, "Priority Level 6"},
    {   7, "Priority Level 7"},
    {   8, "Priority Level 8"},
    {   9, "Priority Level 9"},
    {   10, "Priority Level 10"},
    {   11, "Priority Level 11"},
    {   12, "Priority Level 12"},
    {   13, "Priority Level 13"},
    {   14, "Priority Level 14"},
    {   15, "Priority Level 15"},
    {   0, NULL }
};

static void
dissect_ansi_map_pacaindicator(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;
    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_pacaindicator);
    /* PACA Level (octet 1, bits B-E) */
    proto_tree_add_item(subtree, hf_ansi_map_PACA_Level, tvb, offset,   1, ENC_BIG_ENDIAN);
    /* Permanent Activation (PA) (octet 1, bit A) */
    proto_tree_add_item(subtree, hf_ansi_map_pacaindicator_pa, tvb, offset,     1, ENC_BIG_ENDIAN);
}

/* 6.5.2.92 PageIndicator */
static const value_string ansi_map_PageIndicator_vals[]  = {
    {   0, "Not used"},
    {   1, "Page"},
    {   2, "Listen only"},
    {   0, NULL }
};

/* 6.5.2.93 PC_SSN */
static void
dissect_ansi_map_pc_ssn(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;
    proto_tree *subtree;
    uint8_t b1,b2,b3;


    subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
    /* Type (octet 1) */
    proto_tree_add_item(subtree, hf_ansi_map_msc_type, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    /* Point Code Member Number octet 2 */
    b1 = tvb_get_uint8(tvb,offset);
    offset++;
    /* Point Code Cluster Number octet 3 */
    b2 = tvb_get_uint8(tvb,offset);
    offset++;
    /* Point Code Network Number octet 4 */
    b3 = tvb_get_uint8(tvb,offset);
    offset++;
    proto_tree_add_bytes_format_value(subtree, hf_ansi_map_point_code, tvb, offset-3, 3, NULL, "%u-%u-%u", b3, b2, b1);
    proto_tree_add_item(subtree, hf_ansi_map_SSN, tvb, offset, 1, ENC_NA);
}
/* 6.5.2.94 PilotBillingID */
static void
dissect_ansi_map_pilotbillingid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;
    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
    /* First Originating MarketID octet 1 and 2 */
    proto_tree_add_item(subtree, hf_ansi_map_MarketID, tvb, offset, 2, ENC_BIG_ENDIAN);
    offset = offset + 2;
    /* First Originating Switch Number octet 3*/
    proto_tree_add_item(subtree, hf_ansi_map_swno, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
    /* ID Number */
    proto_tree_add_item(subtree, hf_ansi_map_idno, tvb, offset, 3, ENC_BIG_ENDIAN);
    offset = offset + 3;
    proto_tree_add_item(subtree, hf_ansi_map_segcount, tvb, offset, 1, ENC_BIG_ENDIAN);

}
/* 6.5.2.96 PreferredLanguageIndicator */
static const value_string ansi_map_PreferredLanguageIndicator_vals[]  = {
    {   0, "Unspecified"},
    {   1, "English"},
    {   2, "French"},
    {   3, "Spanish"},
    {   4, "German"},
    {   5, "Portuguese"},
    {   0, NULL }
};

/* 6.5.2.106 ReceivedSignalQuality */
/* a. This octet is encoded the same as octet 1 in the SignalQuality parameter (see
   6.5.2.121).
*/
/* 6.5.2.118 SetupResult */
static const value_string ansi_map_SetupResult_vals[]  = {
    {   0, "Not used"},
    {   1, "Unsuccessful"},
    {   2, "Successful"},
    {   0, NULL }
};
/* 6.5.2.121 SignalQuality */
/* TODO */

/*      6.5.2.122 SMS_AccessDeniedReason (TIA/EIA-41.5-D, page 5-256)
        N.S0011-0 v 1.0
*/
static const value_string ansi_map_SMS_AccessDeniedReason_vals[]  = {
    {   0, "Not used"},
    {   1, "Denied"},
    {   2, "Postponed"},
    {   3, "Unavailable"},
    {   4, "Invalid"},
    {   0, NULL }
};


/* 6.5.2.125 SMS_CauseCode (TIA/EIA-41.5-D, page 5-262)
   N.S0011-0 v 1.0
*/
static const value_string ansi_map_SMS_CauseCode_vals[]  = {
    {   0, "Address vacant"},
    {   1, "Address translation failure"},
    {   2, "Network resource shortage"},
    {   3, "Network failure"},
    {   4, "Invalid Teleservice ID"},
    {   5, "Other network problem"},
    {   6, "Unsupported network interface"},
    {   8, "CDMA handset-based position determination failure"},
    {   9, "CDMA handset-based position determination resources released - voice service request"},
    {   10, "CDMA handset-based position determination resources released - voice service request - message acknowledged"},
    {   11, "Reserved"},
    {   12, "Reserved"},
    {   13, "Reserved"},
    {   14, "Emergency Services Call Precedence"},
    {   32, "No page response"},
    {   33, "Destination busy"},
    {   34, "No acknowledgment"},
    {   35, "Destination resource shortage"},
    {   36, "SMS delivery postponed"},
    {   37, "Destination out of service"},
    {   38, "Destination no longer at this address"},
    {   39, "Other terminal problem"},
    {   64, "Radio interface resource shortage"},
    {   65, "Radio interface incompatibility"},
    {   66, "Other radio interface problem"},
    {   67, "Unsupported Base Station Capability"},
    {   96, "Encoding problem"},
    {   97, "Service origination denied"},
    {   98, "Service termination denied"},
    {   99, "Supplementary service not supported"},
    {   100, "Service not supported"},
    {   101, "Reserved"},
    {   102, "Missing expected parameter"},
    {   103, "Missing mandatory parameter"},
    {   104, "Unrecognized parameter value"},
    {   105, "Unexpected parameter value"},
    {   106, "User Data size error"},
    {   107, "Other general problems"},
    {   108, "Session not active"},
    {   109, "Reserved"},
    {   110, "MS Disconnect"},
    {   0, NULL }
};
static value_string_ext ansi_map_SMS_CauseCode_vals_ext = VALUE_STRING_EXT_INIT(ansi_map_SMS_CauseCode_vals);

/* 6.5.2.126 SMS_ChargeIndicator */
/* SMS Charge Indicator (octet 1) */
static const value_string ansi_map_SMS_ChargeIndicator_vals[]  = {
    {   0, "Not used"},
    {   1, "No charge"},
    {   2, "Charge original originator"},
    {   3, "Charge original destination"},
    {   0, NULL }
};
/*      4 through 63 Reserved. Treat the same as value 1, No charge.
        64 through 127 Reserved. Treat the same as value 2, Charge original originator.
        128 through 223 Reserved. Treat the same as value 3, Charge original destination.
        224 through 255 Reserved for TIA/EIA-41 protocol extension. If unknown, treat the same as value 2, Charge
        original originator.
*/

/* 6.5.2.130 SMS_NotificationIndicator N.S0005-0 v 1.0*/
static const value_string ansi_map_SMS_NotificationIndicator_vals[]  = {
    {   0, "Not used"},
    {   1, "Notify when available"},
    {   2, "Do not notify when available"},
    {   0, NULL }
};

/* 6.5.2.136 SMS_OriginationRestrictions */
/* DEFAULT (octet 1, bits A and B) */

static const value_string ansi_map_SMS_OriginationRestrictions_default_vals[]  = {
    {   0, "Block all"},
    {   1, "Reserved"},
    {   2, "Allow specific"},
    {   3, "Allow all"},
    {   0, NULL }
};
/* DIRECT (octet 1, bit C) */
static const true_false_string ansi_map_SMS_OriginationRestrictions_direct_bool_val  = {
    "Allow Direct",
    "Block Direct"
};

/* Force Message Center (FMC) (octet 1, bit D) */
static const true_false_string ansi_map_SMS_OriginationRestrictions_fmc_bool_val  = {
    "Force Indirect",
    "No effect"
};

static void
dissect_ansi_map_sms_originationrestrictions(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;
    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_sms_originationrestrictions);
    proto_tree_add_item(subtree, hf_ansi_map_reservedBitHGFE, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_sms_originationrestrictions_fmc, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_sms_originationrestrictions_direct, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_sms_originationrestrictions_default, tvb, offset, 1, ENC_BIG_ENDIAN);

}

/* 6.5.2.137 SMS_TeleserviceIdentifier */
/* Updated with N.S0011-0 v 1.0 */

#if 0
/* SMS Teleservice Identifier (octets 1 and 2) */
static const value_string ansi_map_SMS_TeleserviceIdentifier_vals[]  = {
    {     0, "Not used"},
    {     1, "Reserved for maintenance"},
    {     2, "SSD Update no response"},
    {     3, "SSD Update successful"},
    {     4, "SSD Update failed"},
    {  4096, "AMPS Extended Protocol Enhanced Services" },
    {  4097, "CDMA Cellular Paging Teleservice" },
    {  4098, "CDMA Cellular Messaging Teleservice" },
    {  4099, "CDMA Voice Mail Notification" },
    { 32513, "TDMA Cellular Messaging Teleservice" },
    { 32520, "TDMA System Assisted Mobile Positioning through Satellite (SAMPS)" },
    { 32584, "TDMA Segmented System Assisted Mobile Positioning Service" },
    {     0, NULL }
};
#endif
/* 6.5.2.140 SPINITriggers */
/* All Origination (All) (octet 1, bit A) */

/* 6.5.2.142 SSDUpdateReport */
static const value_string ansi_map_SSDUpdateReport_vals[]  = {
    {       0, "Not used"},
    {    4096, "AMPS Extended Protocol Enhanced Services"},
    {    4097, "CDMA Cellular Paging Teleservice"},
    {    4098, "CDMA Cellular Messaging Teleservice"},
    {   32513, "TDMA Cellular Messaging Teleservice"},
    {   32514, "TDMA Cellular Paging Teleservice (CPT-136)"},
    {   32515, "TDMA Over-the-Air Activation Teleservice (OATS)"},
    {   32516, "TDMA Over-the-Air Programming Teleservice (OPTS)"},
    {   32517, "TDMA General UDP Transport Service (GUTS)"},
    {   32576, "Reserved"},
    {   32577, "TDMA Segmented Cellular MessagingTeleservice"},
    {   32578, "TDMA Segmented Cellular Paging Teleservice"},
    {   32579, "TDMA Segmented Over-the-Air Activation Teleservice (OATS)"},
    {   32580, "TDMA Segmented Over-the-Air Programming Teleservice (OPTS)."},
    {   32581, "TDMA Segmented General UDP Transport Service (GUTS)"},
    {       0, NULL }
};

/* 6.5.2.143 StationClassMark */

/* 6.5.2.144 SystemAccessData */

/* 6.5.2.146 SystemCapabilities */
/* Updated in N.S0008-0 v 1.0 */
static const true_false_string ansi_map_systemcapabilities_auth_bool_val  = {
    "Authentication parameters were requested on this system access (AUTH=1 in the OMT)",
    "Authentication parameters were not requested on this system access (AUTH=0 in the OMT)."
};

static const true_false_string ansi_map_systemcapabilities_se_bool_val  = {
    "Signaling Message Encryption supported by the system",
    "Signaling Message Encryption not supported by the system"
};

static const true_false_string ansi_map_systemcapabilities_vp_bool_val  = {
    "Voice Privacy supported by the system",
    "Voice Privacy not supported by the system"
};

static const true_false_string ansi_map_systemcapabilities_cave_bool_val  = {
    "System can execute the CAVE algorithm and share SSD for the indicated MS",
    "System cannot execute the CAVE algorithm and cannot share SSD for the indicated MS"
};

static const true_false_string ansi_map_systemcapabilities_ssd_bool_val  = {
    "SSD is shared with the system for the indicated MS",
    "SSD is not shared with the system for the indicated MS"
};

static const true_false_string ansi_map_systemcapabilities_dp_bool_val  = {
    "DP is supported by the system",
    "DP is not supported by the system"
};

static void
dissect_ansi_map_systemcapabilities(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;
    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_systemcapabilities);
    proto_tree_add_item(subtree, hf_ansi_map_reservedBitHG, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_systemcapabilities_dp, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_systemcapabilities_ssd, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_systemcapabilities_cave, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_systemcapabilities_vp, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_systemcapabilities_se, tvb, offset, 1, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_ansi_map_systemcapabilities_auth, tvb, offset, 1, ENC_BIG_ENDIAN);
}

/* 6.5.2.151 TDMABurstIndicator */
/* 6.5.2.152 TDMACallMode */
/* 6.5.2.153 TDMAChannelData Updated in N.S0007-0 v 1.0*/

/* 6.5.2.155 TerminationAccessType */
/* XXX Fix Me, Fill up the values or do special decoding? */
static const value_string ansi_map_TerminationAccessType_vals[]  = {
    {   0, "Not used"},
    {   1, "Reserved for controlling system assignment (may be a trunk group identifier)."},
    /* 1 through  127 */
    { 127, "Reserved for controlling system assignment (may be a trunk group identifier)."},
    { 128, "Reserved for TIA/EIA-41 protocol extension. If unknown, treat the same as value 253, Land-to-Mobile Directory Number access"},
    /* 128 through  160 */
    { 160, "Reserved for TIA/EIA-41 protocol extension. If unknown, treat the same as value 253, Land-to-Mobile Directory Number access"},
    { 161, "Reserved for this Standard"},
    /* 161 through  251 */
    { 151, "Reserved for this Standard"},
    { 252, "Mobile-to-Mobile Directory Number access"},
    { 253, "Land-to-Mobile Directory Number access"},
    { 254, "Remote Feature Control port access"},
    { 255, "Roamer port access"},
    {   0, NULL }
};

/* 6.5.2.158 TerminationTreatment */
static const value_string ansi_map_TerminationTreatment_vals[]  = {
    {   0, "Not used"},
    {   1, "MS Termination"},
    {   2, "Voice Mail Storage"},
    {   3, "Voice Mail Retrieval"},
    {   4, "Dialogue Termination"},
    {   0, NULL }
};

/* 6.5.2.159 TerminationTriggers */
/* Busy (octet 1, bits A and B) */
static const value_string ansi_map_terminationtriggers_busy_vals[]  = {
    {   0, "Busy Call"},
    {   1, "Busy Trigger"},
    {   2, "Busy Leg"},
    {   3, "Reserved. Treat as an unrecognized parameter value"},
    {   0, NULL }
};
/* Routing Failure (RF) (octet 1, bits C and D) */
static const value_string ansi_map_terminationtriggers_rf_vals[]  = {
    {   0, "Failed Call"},
    {   1, "Routing Failure Trigger"},
    {   2, "Failed Leg"},
    {   3, "Reserved. Treat as an unrecognized parameter value"},
    {   0, NULL }
};
/* No Page Response (NPR) (octet 1, bits E and F) */
static const value_string ansi_map_terminationtriggers_npr_vals[]  = {
    {   0, "No Page Response Call"},
    {   1, "No Page Response Trigger"},
    {   2, "No Page Response Leg"},
    {   3, "Reserved. Treat as an unrecognized parameter value"},
    {   0, NULL }
};
/* No Answer (NA) (octet 1, bits G and H) */
static const value_string ansi_map_terminationtriggers_na_vals[]  = {
    {   0, "No Answer Call"},
    {   1, "No Answer Trigger"},
    {   2, "No Answer Leg"},
    {   3, "Reserved"},
    {   0, NULL }
};
/* None Reachable (NR) (octet 2, bit A) */
static const value_string ansi_map_terminationtriggers_nr_vals[]  = {
    {   0, "Member Not Reachable"},
    {   1, "Group Not Reachable"},
    {   0, NULL }
};

/* 6.5.2.159 TerminationTriggers N.S0005-0 v 1.0*/
static void
dissect_ansi_map_terminationtriggers(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;
    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_transactioncapability);

    proto_tree_add_item(subtree, hf_ansi_map_reservedBitH, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* No Page Response (NPR) (octet 1, bits E and F) */
    proto_tree_add_item(subtree, hf_ansi_map_terminationtriggers_npr, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* No Answer (NA) (octet 1, bits G and H) */
    proto_tree_add_item(subtree, hf_ansi_map_terminationtriggers_na, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Routing Failure (RF) (octet 1, bits C and D) */
    proto_tree_add_item(subtree, hf_ansi_map_terminationtriggers_rf, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Busy (octet 1, bits A and B) */
    proto_tree_add_item(subtree, hf_ansi_map_terminationtriggers_busy, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;

    /* None Reachable (NR) (octet 2, bit A) */
    proto_tree_add_item(subtree, hf_ansi_map_terminationtriggers_nr, tvb, offset, 1, ENC_BIG_ENDIAN);
}

/* 6.5.2.160 TransactionCapability (TIA/EIA-41.5-D, page 5-315) */
/* Updated with N.S0010-0 v 1.0, N.S0012-0 v 1.0 N.S0013-0 v 1.0 */
static const true_false_string ansi_map_trans_cap_prof_bool_val  = {
    "The system is capable of supporting the IS-41-C profile parameters",
    "The system is not capable of supporting the IS-41-C profile parameters"
};

static const true_false_string ansi_map_trans_cap_busy_bool_val  = {
    "The system is capable of detecting a busy condition at the current time",
    "The system is not capable of detecting a busy condition at the current time"
};

static const true_false_string ansi_map_trans_cap_ann_bool_val  = {
    "The system is capable of honoring the AnnouncementList parameter at the current time",
    "The system is not capable of honoring the AnnouncementList parameter at the current time"
};

static const true_false_string ansi_map_trans_cap_rui_bool_val  = {
    "The system is capable of interacting with the user",
    "The system is not capable of interacting with the user"
};

static const true_false_string ansi_map_trans_cap_spini_bool_val  = {
    "The system is capable of supporting local SPINI operation",
    "The system is not capable of supporting local SPINI operation at the current time"
};

static const true_false_string ansi_map_trans_cap_uzci_bool_val  = {
    "The system is User Zone capable at the current time",
    "The system is not User Zone capable at the current time"
};
static const true_false_string ansi_map_trans_cap_ndss_bool_val  = {
    "Serving system is NDSS capable",
    "Serving system is not NDSS capable"
};
static const true_false_string ansi_map_trans_cap_nami_bool_val  = {
    "The system is CNAP/CNAR capable",
    "The system is not CNAP/CNAR capable"
};

static const value_string ansi_map_trans_cap_multerm_vals[]  = {
    {   0, "The system cannot accept a termination at this time (i.e., cannot accept routing information)"},
    {   1, "The system supports the number of call legs indicated"},
    {   2, "The system supports the number of call legs indicated"},
    {   3, "The system supports the number of call legs indicated"},
    {   4, "The system supports the number of call legs indicated"},
    {   5, "The system supports the number of call legs indicated"},
    {   6, "The system supports the number of call legs indicated"},
    {   7, "The system supports the number of call legs indicated"},
    {   8, "The system supports the number of call legs indicated"},
    {   9, "The system supports the number of call legs indicated"},
    {   10, "The system supports the number of call legs indicated"},
    {   11, "The system supports the number of call legs indicated"},
    {   12, "The system supports the number of call legs indicated"},
    {   13, "The system supports the number of call legs indicated"},
    {   14, "The system supports the number of call legs indicated"},
    {   15, "The system supports the number of call legs indicated"},
    {   0, NULL }
};

static const true_false_string ansi_map_trans_cap_tl_bool_val  = {
    "The system is capable of supporting the TerminationList parameter at the current time",
    "The system is not capable of supporting the TerminationList parameter at the current time"
};

static const true_false_string ansi_map_trans_cap_waddr_bool_val  = {
    "The system is capable of supporting the TriggerAddressList parameter",
    "The system is not capable of supporting the TriggerAddressList parameter"
};


static void
dissect_ansi_map_transactioncapability(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;
    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_transactioncapability);

    /*NAME Capability Indicator (NAMI) (octet 1, bit H) */
    proto_tree_add_item(subtree, hf_ansi_map_trans_cap_nami, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* NDSS Capability (NDSS) (octet 1, bit G) */
    proto_tree_add_item(subtree, hf_ansi_map_trans_cap_ndss, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* UZ Capability Indicator (UZCI) (octet 1, bit F) */
    proto_tree_add_item(subtree, hf_ansi_map_trans_cap_uzci, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Subscriber PIN Intercept (SPINI) (octet 1, bit E) */
    proto_tree_add_item(subtree, hf_ansi_map_trans_cap_spini, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Remote User Interaction (RUI) (octet 1, bit D) */
    proto_tree_add_item(subtree, hf_ansi_map_trans_cap_rui, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Announcements (ANN) (octet 1, bit C) */
    proto_tree_add_item(subtree, hf_ansi_map_trans_cap_ann, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Busy Detection (BUSY) (octet 1, bit B) */
    proto_tree_add_item(subtree, hf_ansi_map_trans_cap_busy, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Profile (PROF) (octet 1, bit A) */
    proto_tree_add_item(subtree, hf_ansi_map_trans_cap_prof, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;

    /* WIN Addressing (WADDR) (octet 2, bit F) */
    proto_tree_add_item(subtree, hf_ansi_trans_cap_waddr, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* TerminationList (TL) (octet 2, bit E) */
    proto_tree_add_item(subtree, hf_ansi_trans_cap_tl, tvb, offset, 1, ENC_BIG_ENDIAN);
    /* Multiple Terminations (octet 2, bits A-D) */
    proto_tree_add_item(subtree, hf_ansi_trans_cap_multerm, tvb, offset, 1, ENC_BIG_ENDIAN);
}

/* 6.5.2.162 UniqueChallengeReport */
/* Unique Challenge Report (octet 1) */
static const value_string ansi_map_UniqueChallengeReport_vals[]  = {
    {   0, "Not used"},
    {   1, "Unique Challenge not attempted"},
    {   2, "Unique Challenge no response"},
    {   3, "Unique Challenge successful"},
    {   4, "Unique Challenge failed"},
    {   0, NULL }
};

/* 6.5.2.166 VoicePrivacyMask */


/* 6.5.2.e (TSB76) CDMAServiceConfigurationRecord N.S0008-0 v 1.0 */
/* a. This field carries the CDMA Service Configuration Record. The bit-layout is the
   same as that of Service Configuration Record in TSB74, and J-STD-008.
*/

/* 6.5.2.f CDMAServiceOption N.S0010-0 v 1.0 */

/* values copied from old ANSI map dissector */
static const range_string cdmaserviceoption_vals[] = {
    { 1, 1, "Basic Variable Rate Voice Service (8 kbps)" },
    { 2, 2, "Mobile Station Loopback (8 kbps)" },
    { 3, 3, "Enhanced Variable Rate Voice Service (8 kbps)" },
    { 4, 4, "Asynchronous Data Service (9.6 kbps)" },
    { 5, 5, "Group 3 Facsimile (9.6 kbps)" },
    { 6, 6, "Short Message Services (Rate Set 1)" },
    { 7, 7, "Packet Data Service: Internet or ISO Protocol Stack (9.6 kbps)" },
    { 8, 8, "Packet Data Service: CDPD Protocol Stack (9.6 kbps)" },
    { 9, 9, "Mobile Station Loopback (13 kbps)" },
    { 10, 10, "STU-III Transparent Service" },
    { 11, 11, "STU-III Non-Transparent Service" },
    { 12, 12, "Asynchronous Data Service (14.4 or 9.6 kbps)" },
    { 13, 13, "Group 3 Facsimile (14.4 or 9.6 kbps)" },
    { 14, 14, "Short Message Services (Rate Set 2)" },
    { 15, 15, "Packet Data Service: Internet or ISO Protocol Stack (14.4 kbps)" },
    { 16, 16, "Packet Data Service: CDPD Protocol Stack (14.4 kbps)" },
    { 17, 17, "High Rate Voice Service (13 kbps)" },
    { 18, 18, "Over-the-Air Parameter Administration (Rate Set 1)" },
    { 19, 19, "Over-the-Air Parameter Administration (Rate Set 2)" },
    { 20, 20, "Group 3 Analog Facsimile (Rate Set 1)" },
    { 21, 21, "Group 3 Analog Facsimile (Rate Set 2)" },
    { 22, 22, "High Speed Packet Data Service: Internet or ISO Protocol Stack (RS1 forward, RS1 reverse)" },
    { 23, 23, "High Speed Packet Data Service: Internet or ISO Protocol Stack (RS1 forward, RS2 reverse)" },
    { 24, 24, "High Speed Packet Data Service: Internet or ISO Protocol Stack (RS2 forward, RS1 reverse)" },
    { 25, 25, "High Speed Packet Data Service: Internet or ISO Protocol Stack (RS2 forward, RS2 reverse)" },
    { 26, 26, "High Speed Packet Data Service: CDPD Protocol Stack (RS1 forward, RS1 reverse)" },
    { 27, 27, "High Speed Packet Data Service: CDPD Protocol Stack (RS1 forward, RS2 reverse)" },
    { 28, 28, "High Speed Packet Data Service: CDPD Protocol Stack (RS2 forward, RS1 reverse)" },
    { 29, 29, "High Speed Packet Data Service: CDPD Protocol Stack (RS2 forward, RS2 reverse)" },
    { 30, 30, "Supplemental Channel Loopback Test for Rate Set 1" },
    { 31, 31, "Supplemental Channel Loopback Test for Rate Set 2" },
    { 32, 32, "Test Data Service Option (TDSO)" },
    { 33, 33, "cdma2000 High Speed Packet Data Service, Internet or ISO Protocol Stack" },
    { 34, 34, "cdma2000 High Speed Packet Data Service, CDPD Protocol Stack" },
    { 35, 35, "Location Services, Rate Set 1 (9.6 kbps)" },
    { 36, 36, "Location Services, Rate Set 2 (14.4 kbps)" },
    { 37, 37, "ISDN Interworking Service (64 kbps)" },
    { 38, 38, "GSM Voice" },
    { 39, 39, "GSM Circuit Data" },
    { 40, 40, "GSM Packet Data" },
    { 41, 41, "GSM Short Message Service" },
    { 42, 42, "None Reserved for MC-MAP standard service options" },
    { 54, 54, "Markov Service Option (MSO)" },
    { 55, 55, "Loopback Service Option (LSO)" },
    { 56, 56, "Selectable Mode Vocoder" },
    { 57, 57, "32 kbps Circuit Video Conferencing" },
    { 58, 58, "64 kbps Circuit Video Conferencing" },
    { 59, 59, "HRPD Accounting Records Identifier" },
    { 60, 60, "Link Layer Assisted Robust Header Compression (LLA ROHC) - Header Removal" },
    { 61, 61, "Link Layer Assisted Robust Header Compression (LLA ROHC) - Header Compression" },
    { 62, 62, "Source-Controlled Variable-Rate Multimode Wideband Speech Codec (VMR-WB) Rate Set 2" },
    { 63, 63, "Source-Controlled Variable-Rate Multimode Wideband Speech Codec (VMR-WB) Rate Set 1" },
    { 64, 64, "HRPD auxiliary Packet Data Service instance" },
    { 65, 65, "cdma2000/GPRS Inter-working" },
    { 66, 66, "cdma2000 High Speed Packet Data Service, Internet or ISO Protocol Stack" },
    { 67, 67, "HRPD Packet Data IP Service where Higher Layer Protocol is IP or ROHC" },
    { 68, 68, "Enhanced Variable Rate Voice Service (EVRC-B)" },
    { 69, 69, "HRPD Packet Data Service, which when used in paging over the 1x air interface, a page response is required" },
    { 70, 70, "Enhanced Variable Rate Voice Service (EVRC-WB)" },
    { 71, 4099, "None Reserved for standard service options" },
    { 4100, 4100, "Asynchronous Data Service, Revision 1 (9.6 or 14.4 kbps)" },
    { 4101, 4101, "Group 3 Facsimile, Revision 1 (9.6 or 14.4 kbps)" },
    { 4102, 4102, "Reserved for standard service option" },
    { 4103, 4103, "Packet Data Service: Internet or ISO Protocol Stack, Revision 1 (9.6 or 14.4 kbps)" },
    { 4104, 4104, "Packet Data Service: CDPD Protocol Stack, Revision 1 (9.6 or 14.4 kbps)" },
    { 4105, 32767, "Reserved for standard service options" },
    { 32768, 32768, "QCELP (13 kbps)" },
    { 32769, 32771, "Proprietary QUALCOMM Incorporated" },
    { 32772, 32775, "Proprietary OKI Telecom" },
    { 32776, 32779, "Proprietary Lucent Technologies" },
    { 32780, 32783, "Nokia" },
    { 32784, 32787, "NORTEL NETWORKS" },
    { 32788, 32791, "Sony Electronics Inc" },
    { 32792, 32795, "Motorola" },
    { 32796, 32799, "QUALCOMM Incorporated" },
    { 32800, 32803, "QUALCOMM Incorporated" },
    { 32804, 32807, "QUALCOMM Incorporated" },
    { 32808, 32811, "QUALCOMM Incorporated" },
    { 32812, 32815, "Lucent Technologies" },
    { 32816, 32819, "Denso International" },
    { 32820, 32823, "Motorola" },
    { 32824, 32827, "Denso International" },
    { 32828, 32831, "Denso International" },
    { 32832, 32835, "Denso International" },
    { 32836, 32839, "NEC America" },
    { 32840, 32843, "Samsung Electronics" },
    { 32844, 32847, "Texas Instruments Incorporated" },
    { 32848, 32851, "Toshiba Corporation" },
    { 32852, 32855, "LG Electronics Inc." },
    { 32856, 32859, "VIA Telecom Inc." },
    { 0,           0,          NULL                   }
};

static void
dissect_ansi_map_cdmaserviceoption(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){
    int offset = 0;
    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_cdmaserviceoption);

    proto_tree_add_item(subtree, hf_ansi_map_cdmaserviceoption, tvb, offset, 2, ENC_BIG_ENDIAN);


}
/* 6.5.2.f (TSB76) CDMAServiceOption N.S0008-0 v 1.0*/
/* This field carries the CDMA Service Option. The bit-layout is the same as that of
   Service Option in TSB74 and J-STD-008.*/

/* 6.5.2.i (IS-730) TDMAServiceCode N.S0008-0 v 1.0 */
static const value_string ansi_map_TDMAServiceCode_vals[]  = {
    {   0, "Analog Speech Only"},
    {   1, "Digital Speech Only"},
    {   2, "Analog or Digital Speech, Analog Preferred"},
    {   3, "Analog or Digital Speech, Digital Preferred"},
    {   4, "Asynchronous Data"},
    {   5, "G3 Fax"},
    {   6, "Not Used (Service Rejected)"},
    {   7, "STU-III"},
    {   0, NULL }
};
#if 0
/* 6.5.2.j (IS-730) TDMATerminalCapability N.S0008-0 v 1.0 Updated with N.S0015-0 */
/* Supported Frequency Band (octet 1) */
/* Voice Coder (octet 2) */
/* Protocol Version (octet 3) N.S0015-0 */
static const value_string ansi_map_TDMATerminalCapability_prot_ver_vals[]  = {
    {   0, "EIA-553 or IS-54-A"},
    {   1, "TIA/EIA-627.(IS-54-B)"},
    {   2, "IS-136"},
    {   3, "Permanently Reserved (ANSI J-STD-011).Treat the same as value 4, IS-136-A."},
    {   4, "PV 0 as published in TIA/EIA-136-0 and IS-136-A."},
    {   5, "PV 1 as published in TIA/EIA-136-A."},
    {   6, "PV 2 as published in TIA/EIA-136-A."},
    {   7, "PV 3 as published in TIA/EIA-136-A."},
    {   0, NULL }
};
#endif
/* Asynchronous Data (ADS) (octet 4, bit A) N.S0007-0*/
/* Group 3 Fax (G3FAX) (octet 4, bit B) */
/* Secure Telephone Unit III (STU3) (octet 4, bit C) */
/* Analog Voice (AVOX) (octet 4, bit D) */
/* Half Rate (HRATE) (octet 4, bit E) */
/* Full Rate (FRATE) (octet 4, bit F) */
/* Double Rate (2RATE) (octet 4, bit G) */
/* Triple Rate (3RATE) (octet 4, bit H) */


/* 6.5.2.k (IS-730)) TDMAVoiceCoder N.S0008-0 v 1.0, N.S0007-0 */
/* VoiceCoder (octet 1) */

/* 6.5.2.p UserZoneData N.S0015-0 */

/* 6.5.2.aa BaseStationManufacturerCode N.S0007-0 v 1.0 */
/* The BaseStationManufacturerCode (BSMC) parameter specifies the manufacturer of the
   base station that is currently serving the MS (see IS-136 for enumeration of values).*/

/* 6.5.2.ab BSMCStatus */

/* BSMC Status (octet 1) */
static const value_string ansi_map_BSMCStatus_vals[]  = {
    {   0, "Same BSMC Value shall not be supported"},
    {   1, "Same BSMC Value shall be supported"},
    {   0, NULL }
};

/*- 6.5.2.ac ControlChannelMode (N.S0007-0 v 1.0)*/
static const value_string ansi_map_ControlChannelMode_vals[]  = {
    {   0, "Unknown"},
    {   1, "MS is in Analog CC Mode"},
    {   2, "MS is in Digital CC Mode"},
    {   3, "MS is in NAMPS CC Mode"},
    {   0, NULL }
};

/* 6.5.2.ad NonPublicData N.S0007-0 v 1.0*/
/* NP Only Service (NPOS) (octet 1, bits A and B) */
/* Charging Area Tone Service (CATS) (octet 1, bits C - F) */
/* PSID/RSID Download Order (PRDO) (octet 1, bits G and H) */

/* 6.5.2.ae PagingFrameClass N.S0007-0 v 1.0*/
/* Paging Frame Class (octet 1) */

static const value_string ansi_map_PagingFrameClass_vals[]  = {
    {   0, "PagingFrameClass 1 (1.28 seconds)"},
    {   1, "PagingFrameClass 2 (2.56 seconds)"},
    {   2, "PagingFrameClass 3 (3.84 seconds)"},
    {   3, "PagingFrameClass 4 (7.68 seconds)"},
    {   4, "PagingFrameClass 5 (15.36 seconds)"},
    {   5, "PagingFrameClass 6 (30.72 seconds)"},
    {   6, "PagingFrameClass 7 (61.44 seconds)"},
    {   7, "PagingFrameClass 8 (122.88 seconds)"},
    {   8, "Reserved. Treat the same as value 0, PagingFrameClass 1"},
    {   0, NULL }
};

/* 6.5.2.af PSID_RSIDInformation N.S0007-0 v 1.0*/
/* PSID/RSID Indicator (octet 1, bit A) */
/* PSID/RSID Type (octet 1, bits B-D) */

/* 6.5.2.ah ServicesResult N.S0007-0 v 1.0*/
/* PSID/RSID Download Result (PRDR) (octet 1, bits A and B) */
static const value_string ansi_map_ServicesResult_ppr_vals[]  = {
    {   0, "No Indication"},
    {   1, "Unsuccessful PSID/RSID download"},
    {   2, "Successful PSID/RSID download"},
    {   3, "Reserved. Treat the same as value 0, No Indication"},
    {   0, NULL }
};

/* 6.5.2.ai SOCStatus N.S0007-0 v 1.0*/

/* SOC Status (octet 1) */
static const value_string ansi_map_SOCStatus_vals[]  = {
    {   0, "Same SOC Value shall not be supported"},
    {   1, "Same SOC Value shall be supported"},
    {   0, NULL }
};

/* 6.5.2.aj SystemOperatorCode N.S0007-0 v 1.0*/
/* The SystemOperatorCode (SOC) parameter specifies the system operator that is currently
   providing service to a MS (see IS-136 for enumeration of values) */

/* 6.5.2.al UserGroup N.S0007-0 v 1.0*/

/* 6.5.2.am UserZoneData N.S0007-0 v 1.0*/


/*Table 6.5.2.ay TDMABandwidth value N.S0008-0 v 1.0 */
static const value_string ansi_map_TDMABandwidth_vals[]  = {
    {   0, "Half-Rate Digital Traffic Channel Only"},
    {   1, "Full-Rate Digital Traffic Channel Only"},
    {   2, "Half-Rate or Full-rate Digital Traffic Channel - Full-Rate Preferred"},
    {   3, "Half-rate or Full-rate Digital Traffic Channel - Half-rate Preferred"},
    {   4, "Double Full-Rate Digital Traffic Channel Only"},
    {   5, "Triple Full-Rate Digital Traffic Channel Only"},
    {   6, "Reserved. Treat reserved values the same as value 1 - Full-Rate Digital Traffic Channel Only"},
    {   7, "Reserved. Treat reserved values the same as value 1 - Full-Rate Digital Traffic Channel Only"},
    {   8, "Reserved. Treat reserved values the same as value 1 - Full-Rate Digital Traffic Channel Only"},
    {   9, "Reserved. Treat reserved values the same as value 1 - Full-Rate Digital Traffic Channel Only"},
    {   10, "Reserved. Treat reserved values the same as value 1 - Full-Rate Digital Traffic Channel Only"},
    {   11, "Reserved. Treat reserved values the same as value 1 - Full-Rate Digital Traffic Channel Only"},
    {   12, "Reserved. Treat reserved values the same as value 1 - Full-Rate Digital Traffic Channel Only"},
    {   13, "Reserved. Treat reserved values the same as value 1 - Full-Rate Digital Traffic Channel Only"},
    {   14, "Reserved. Treat reserved values the same as value 1 - Full-Rate Digital Traffic Channel Only"},
    {   15, "Reserved. Treat reserved values the same as value 1 - Full-Rate Digital Traffic Channel Only"},
    {   0, NULL }

};

/* 6.5.2.az TDMADataFeaturesIndicator N.S0008-0 v 1.0 */
/* TDMADataFeaturesIndicator
   ansi_map_FeatureActivity_vals

   ADS FeatureActivity ADS-FA ( octet 1 bit A and B )
   G3 Fax FeatureActivity G3FAX-FA ( octet 1 bit C and D )
   STU-III FeatureActivity STUIII-FA ( octet 1 bit E and F )
   Half Rate data FeatureActivity HRATE-FA ( octet 2 bit A and B )
   Full Rate data FeatureActivity FRATE-FA ( octet 2 bit C and D )
   Double Rate data FeatureActivity 2RATE-FA ( octet 2 bit E and F )
   Triple Rate data FeatureActivity 3RATE-FA ( octet g bit G and H )

   Table 6.5.2.azt TDMADataFeaturesIndicator value
   static const value_string ansi_map_TDMADataFeaturesIndicator_vals[]  = {
   {   0, "Not Used"},
   {   1, "Not Authorized"},
   {   2, "Authorized, but de-activated"},
   {   3, "Authorized and activated"},
   {   0, NULL }

   };
*/

/* 6.5.2.ba TDMADataMode N.S0008-0 v 1.0*/

/* 6.5.2.bb TDMAVoiceMode */

/* 6.5.2.bb CDMAConnectionReference N.S0008-0 v 1.0 */
/* Service Option Connection Reference Octet 1 */
/*      a. This field carries the CDMA Service Option Connection Reference. The bitlayout
        is the same as that of Service Option Connection Reference in TSB74 and
        J-STD-008.
*/

/* 6.5.2.ad CDMAState N.S0008-0 v 1.0 */
/* Service Option State Octet 1 */
/* a. This field carries the CDMA Service Option State information. The CDMA
   Service Option State is defined in the current CDMA Service Options standard.
   If CDMA Service Option State is not explicitly defined within a section of the
   relevant CDMA Service Option standard, the CDMA Service Option State shall
   carry the value of the ORD_Q octet of all current Service Option Control Orders
   (see IS-95), or the contents of all current CDMA Service Option Control
   Messages (see TSB74) type specific field for this connection reference. */

/* 6.5.2.aj SecondInterMSCCircuitID */
/* -- XXX Same code as ISLPinformation???
   dissect_ansi_map_secondintermsccircuitid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree){

   int offset = 0;

   proto_tree *subtree;


   subtree = proto_item_add_subtree(actx->created_item, ett_billingid);
   / Trunk Group Number (G) Octet 1 /
   proto_tree_add_item(subtree, hf_ansi_map_tgn, tvb, offset, 1, ENC_BIG_ENDIAN);
   offset++;
   / Trunk Member Number (M) Octet2 /
   proto_tree_add_item(subtree, hf_ansi_map_tmn, tvb, offset, 1, ENC_BIG_ENDIAN);
   }
*/
#if 0
/* 6.5.2.as ChangeServiceAttributes N.S0008-0 v 1.0 */
/* Change Facilities Flag (CHGFAC)(octet 1, bits A - B) */
static const value_string ansi_map_ChangeServiceAttributes_chgfac_vals[]  = {
    {   0, "Change Facilities Operation Requested"},
    {   1, "Change Facilities Operation Not Requested"},
    {   2, "Change Facilities Operation Used"},
    {   3, "Change Facilities Operation Not Used"},
    {   0, NULL }
};
#endif
#if 0
/* Service Negotiate Flag (SRVNEG)(octet 1, bits C - D) */
static const value_string ansi_map_ChangeServiceAttributes_srvneg_vals[]  = {
    {   0, "Service Negotiation Used"},
    {   1, "Service Negotiation Not Used"},
    {   2, "Service Negotiation Required"},
    {   3, "Service Negotiation Not Required"},
    {   0, NULL }
};
#endif
#if 0
/* 6.5.2.au DataPrivacyParameters N.S0008-0 v 1.0*/
/* Privacy Mode (PM) (octet 1, Bits A and B) */
static const value_string ansi_map_DataPrivacyParameters_pm_vals[]  = {
    {   0, "Privacy inactive or not supported"},
    {   1, "Privacy Requested or Acknowledged"},
    {   2, "Reserved. Treat reserved values the same as value 0, Privacy inactive or not supported."},
    {   3, "Reserved. Treat reserved values the same as value 0, Privacy inactive or not supported."},
    {   0, NULL }
};
#endif
#if 0
/* Data Privacy Version (PM) (octet 2) */
static const value_string ansi_map_DataPrivacyParameters_data_priv_ver_vals[]  = {
    {   0, "Not used"},
    {   1, "Data Privacy Version 1"},
    {   0, NULL }
};
#endif

/* 6.5.2.av ISLPInformation N.S0008-0 v 1.0*/
/* ISLP Type (octet 1) */
static const value_string ansi_map_islp_type_vals[]  = {
    {   0, "No ISLP supported"},
    {   1, "ISLP supported"},
    {   0, NULL }
};
/* 6.5.2.bc AnalogRedirectInfo */
/* Sys Ordering (octet 1, bits A-E) */
/* Ignore CDMA (IC) (octet 1, bit F) */

/* 6.5.2.be CDMAChannelNumber N.S0010-0 v 1.0*/

/* 6.5.2.bg CDMAPowerCombinedIndicator N.S0010-0 v 1.0*/

/* 6.5.2.bi CDMASearchParameters N.S0010-0 v 1.0*/

/* 6.5.2.bk CDMANetworkIdentification N.S0010-0 v 1.0*/
/* See CDMA [J-STD-008] for encoding of this field. */

/* 6.5.2.bo RequiredParametersMask N.S0010-0 v 1.0 */

/* 6.5.2.bp ServiceRedirectionCause */
static const value_string ansi_map_ServiceRedirectionCause_type_vals[]  = {
    {   0, "Not used"},
    {   1, "NormalRegistration"},
    {   2, "SystemNotFound."},
    {   3, "ProtocolMismatch."},
    {   4, "RegistrationRejection."},
    {   5, "WrongSID."},
    {   6, "WrongNID.."},
    {   0, NULL }
};

/* 6.5.2.bq ServiceRedirectionInfo  N.S0010-0 v 1.0 */

/* 6.5.2.br RoamingIndication N.S0010-0 v 1.0*/
/* See CDMA [TSB58] for the definition of this field. */

/* 6.5.2.bw CallingPartyName N.S0012-0 v 1.0*/

#if 0
/* Presentation Status (octet 1, bits A and B) */
static const value_string ansi_map_Presentation_Status_vals[]  = {
    {   0, "Presentation allowed"},
    {   1, "Presentation restricted"},
    {   2, "Blocking toggle"},
    {   3, "No indication"},
    {   0, NULL }
};
#endif
#if 0
/* Availability (octet 1, bit E) N.S0012-0 v 1.0*/
static const true_false_string ansi_map_Availability_bool_val  = {
    "Name not available",
    "Name available/unknown"
};
#endif
static void
dissect_ansi_map_callingpartyname(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    /* Availability (octet 1, bit E) N.S0012-0 v 1.0*/

    /* Presentation Status (octet 1, bits A and B) */



}


/* 6.5.2.bx DisplayText N.S0012-0 v 1.0*/
/* a. Refer to ANSI T1.610 for field encoding. */

/* 6.5.2.bz ServiceID
   Service Identifier (octets 1 to n)
   0 Not used.
   1 Calling Name Presentation - No RND.
   2 Calling Name Presentation with RND.
*/

/* 6.5.2.co GlobalTitle N.S0013-0 v 1.0
 * Refer to Section 3 of ANSI T1.112 for the encoding of this field.
 */
/* Address Indicator octet 1 */
/* Global Title Octet 2 - n */


#if 0
/* 6.5.2.dc SpecializedResource N.S0013-0 v 1.0*/
/* Resource Type (octet 1) */
static const value_string ansi_map_resource_type_vals[]  = {
    {   0, "Not used"},
    {   1, "DTMF tone detector"},
    {   2, "Automatic Speech Recognition - Speaker Independent - Digits"},
    {   3, "Automatic Speech Recognition - Speaker Independent - Speech User Interface Version 1"},
    {   0, NULL }
};
#endif
/* 6.5.2.df TriggerCapability */
/* Updated with N.S0004 N.S0013-0 v 1.0*/

static const true_false_string ansi_map_triggercapability_bool_val  = {
    "triggers can be armed by the TriggerAddressList parameter",
    "triggers cannot be armed by the TriggerAddressList parameter"
};

static void
dissect_ansi_map_triggercapability(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;
    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_triggercapability);


    /* O_No_Answer (ONA) (octet 1, bit H)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_ona, tvb, offset,        1, ENC_BIG_ENDIAN);
    /* O_Disconnect (ODISC) (octet 1, bit G)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_odisc, tvb, offset,      1, ENC_BIG_ENDIAN);
    /* O_Answer (OANS) (octet 1, bit F)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_oans, tvb, offset,       1, ENC_BIG_ENDIAN);
    /* Origination_Attempt_Authorized (OAA) (octet 1, bit E)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_oaa, tvb, offset,        1, ENC_BIG_ENDIAN);
    /* Revertive_Call (RvtC) (octet 1, bit D)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_rvtc, tvb, offset,       1, ENC_BIG_ENDIAN);
    /* All_Calls (All) (octet 1, bit C)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_all, tvb, offset,        1, ENC_BIG_ENDIAN);
    /* K-digit (K-digit) (octet 1, bit B)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_kdigit, tvb, offset,     1, ENC_BIG_ENDIAN);
    /* Introducing Star/Pound (INIT) (octet 1, bit A) */
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_init, tvb, offset,       1, ENC_BIG_ENDIAN);
    offset++;


    /* O_Called_Party_Busy (OBSY) (octet 2, bit H)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_obsy, tvb, offset,       1, ENC_BIG_ENDIAN);
    /* Called_Routing_Address_Available (CdRAA) (octet 2, bit G)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_cdraa, tvb, offset,      1, ENC_BIG_ENDIAN);
    /* Initial_Termination (IT) (octet 2, bit F)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_it, tvb, offset,         1, ENC_BIG_ENDIAN);
    /* Calling_Routing_Address_Available (CgRAA)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_cgraa, tvb, offset,      1, ENC_BIG_ENDIAN);
    /* Advanced_Termination (AT) (octet 2, bit D)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_at, tvb, offset,         1, ENC_BIG_ENDIAN);
    /* Prior_Agreement (PA) (octet 2, bit C)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_pa, tvb, offset,         1, ENC_BIG_ENDIAN);
    /* Unrecognized_Number (Unrec) (octet 2, bit B)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_unrec, tvb, offset,      1, ENC_BIG_ENDIAN);
    /* Call Types (CT) (octet 2, bit A)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_ct, tvb, offset,         1, ENC_BIG_ENDIAN);
    offset++;
    /* */
    /* */
    /* */
    /* T_Disconnect (TDISC) (octet 3, bit E)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_tdisc, tvb, offset,      1, ENC_BIG_ENDIAN);
    /* T_Answer (TANS) (octet 3, bit D)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_tans, tvb, offset,       1, ENC_BIG_ENDIAN);
    /* T_No_Answer (TNA) (octet 3, bit C)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_tna, tvb, offset,        1, ENC_BIG_ENDIAN);
    /* T_Busy (TBusy) (octet 3, bit B)*/
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_tbusy, tvb, offset,      1, ENC_BIG_ENDIAN);
    /* Terminating_Resource_Available (TRA) (octet 3, bit A) */
    proto_tree_add_item(subtree, hf_ansi_map_triggercapability_tra, tvb, offset,        1, ENC_BIG_ENDIAN);

}
/* 6.5.2.ei DMH_ServiceID N.S0018 */

/* 6.5.2.dj WINOperationsCapability */
/* Updated with N.S0004 */
/* ConnectResource (CONN) (octet 1, bit A) */
static const true_false_string ansi_map_winoperationscapability_conn_bool_val  = {
    "Sender is capable of supporting the ConnectResource, DisconnectResource, ConnectionFailureReport and ResetTimer (SSFT timer) operations",
    "Sender is not capable of supporting the ConnectResource, DisconnectResource,ConnectionFailureReport and ResetTimer (SSFT timer) operations"
};

/* CallControlDirective (CCDIR) (octet 1, bit B) */
static const true_false_string ansi_map_winoperationscapability_ccdir_bool_val  = {
    "Sender is capable of supporting the CallControlDirective operation",
    "Sender is not capable of supporting the CallControlDirective operation"
};

/* PositionRequest (POS) (octet 1, bit C) */
static const true_false_string ansi_map_winoperationscapability_pos_bool_val  = {
    "Sender is capable of supporting the PositionRequest operation",
    "Sender is not capable of supporting the PositionRequest operation"
};
static void
dissect_ansi_map_winoperationscapability(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;
    proto_tree *subtree;

    subtree = proto_item_add_subtree(actx->created_item, ett_winoperationscapability);

    /* PositionRequest (POS) (octet 1, bit C) */
    proto_tree_add_item(subtree, hf_ansi_map_winoperationscapability_pos, tvb, offset,  1, ENC_BIG_ENDIAN);
    /* CallControlDirective (CCDIR) (octet 1, bit B) */
    proto_tree_add_item(subtree, hf_ansi_map_winoperationscapability_ccdir, tvb, offset,        1, ENC_BIG_ENDIAN);
    /* ConnectResource (CONN) (octet 1, bit A) */
    proto_tree_add_item(subtree, hf_ansi_map_winoperationscapability_conn, tvb, offset, 1, ENC_BIG_ENDIAN);

}
/*
 * 6.5.2.dk N.S0013-0 v 1.0,X.S0004-550-E v1.0 2.301
 * Code to be found after include functions.
 */

/* 6.5.2.ei TIA/EIA-41.5-D Modifications N.S0018Re */
/* Octet 1,2 1st MarketID */
/* Octet 3 1st MarketSegmentID */
/* Octet 4,5 1st DMH_ServiceID value */
/* Second marcet ID etc */
/* 6.5.2.ek ControlNetworkID N.S0018*/
static void
dissect_ansi_map_controlnetworkid(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;
    proto_tree *subtree;


    subtree = proto_item_add_subtree(actx->created_item, ett_controlnetworkid);
    /* MarketID octet 1 and 2 */
    proto_tree_add_item(subtree, hf_ansi_map_MarketID, tvb, offset, 2, ENC_BIG_ENDIAN);
    offset = offset + 2;
    /* Switch Number octet 3*/
    proto_tree_add_item(subtree, hf_ansi_map_swno, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset++;
}


/* 6.5.2.dk WIN_TriggerList N.S0013-0 v 1.0 */

/* 6.5.2.ec DisplayText2 Updated in N.S0015-0*/

/* 6.5.2.eq MSStatus N.S0004 */

/* 6.5.2.er PositionInformationCode N.S0004 */

/* 6.5.2.fd InterMessageTime N.S0015-0*/
/* Timer value (in 10s of seconds) octet 1 */

/* 6.5.2.fe MSIDUsage N.S0015-0 */
/* M and I Report (octet 1, bits A and B) */
static const value_string ansi_MSIDUsage_m_or_i_vals[]  = {
    {   0, "Not used"},
    {   1, "MIN last used"},
    {   2, "IMSI last used"},
    {   3, "Reserved"},
    {   0, NULL }
};

/* 6.5.2.ff NewMINExtension N.S0015-0 */

#if 0
/* 6.5.2.fv ACGEncountered N.S0023-0 v 1.0 */
/* ACG Encountered (octet 1, bits A-F) */
static const value_string ansi_ACGEncountered_vals[]  = {
    {   0, "PC_SSN"},
    {   1, "1-digit control"},
    {   2, "2-digit control"},
    {   3, "3-digit control"},
    {   4, "4-digit control"},
    {   5, "5-digit control"},
    {   6, "6-digit control"},
    {   7, "7-digit control"},
    {   8, "8-digit control"},
    {   9, "9-digit control"},
    {   10, "10-digit control"},
    {   11, "11-digit control"},
    {   12, "12-digit control"},
    {   13, "13-digit control"},
    {   14, "14-digit control"},
    {   15, "15-digit control"},
    {   0, NULL }
};
#endif
#if 0
/* Control Type (octet 1, bits G-H) */
static const value_string ansi_ACGEncountered_cntrl_type_vals[]  = {
    {   0, "Not used."},
    {   1, "Service Management System Initiated control encountered"},
    {   2, "SCF Overload control encountered"},
    {   3, "Reserved. Treat the same as value 0, Not used."},
    {   0, NULL }
};
#endif

/* 6.5.2.fw ControlType N.S0023-0 v 1.0 */



#if 0
/* 6.5.2.ge QoSPriority N.S0029-0 v1.0*/
/* 6.5.2.xx QOSPriority */
/* Non-Assured Priority (octet 1, bits A-D) */
static const value_string ansi_map_Priority_vals[]  = {
    {   0, "Priority Level 0. This is the lowest level"},
    {   1, "Priority Level 1"},
    {   2, "Priority Level 2"},
    {   3, "Priority Level 3"},
    {   4, "Priority Level 4"},
    {   5, "Priority Level 5"},
    {   6, "Priority Level 6"},
    {   7, "Priority Level 7"},
    {   8, "Priority Level 8"},
    {   8, "Priority Level 9"},
    {   10, "Priority Level 10"},
    {   11, "Priority Level 11"},
    {   12, "Priority Level 12"},
    {   13, "Priority Level 13"},
    {   14, "Reserved"},
    {   15, "Reserved"},
    {   0, NULL }
};
#endif
/* Assured Priority (octet 1, bits E-H)*/


/* 6.5.2.gf PDSNAddress N.S0029-0 v1.0*/
/* a. See IOS Handoff Request message for the definition of this field. */

/* 6.5.2.gg PDSNProtocolType N.S0029-0 v1.0*/
/* See IOS Handoff Request message for the definition of this field. */

/* 6.5.2.gh CDMAMSMeasuredChannelIdentity N.S0029-0 v1.0*/

/* 6.5.2.gl CallingPartyCategory N.S0027*/
/* a. Refer to ITU-T Q.763 (Signalling System No. 7  ISDN user part formats and
   codes) for encoding of this parameter.
   b. Refer to national ISDN user part specifications for definitions and encoding of the
   reserved for national use values.
*/
/* 6.5.2.gm CDMA2000HandoffInvokeIOSData N.S0029-0 v1.0*/
/* IOS A1 Element Handoff Invoke Information */


/* 6.5.2.gn CDMA2000HandoffResponseIOSData */
/* IOS A1 Element Handoff Response Information N.S0029-0 v1.0*/

/* 6.5.2.gr CDMAServiceOptionConnectionIdentifier N.S0029-0 v1.0*/

/* 6.5.2.fk GeographicPosition */
/* Calling Geodetic Location (CGL)
 * a. See T1.628 for encoding.
 * b. Ignore extra octets, if received. Send only defined (or significant) octets.
 */
/* 6.5.2.fs PositionRequestType (See J-STD-036, page 8-47) X.S0002-0 v2.0
 */

/* Position Request Type (octet 1, bits A-H) */
/*
  static const value_string ansi_map_Position_Request_Type_vals[]  = {
  {   0, "Not used"},
  {   1, "Initial Position"},
  {   2, "Return the updated position"},
  {   3, "Return the updated or last known position"},
  {   4, "Reserved for LSP interface"},
  {   5, "Initial Position Only"},
  {   6, "Return the last known position"},
  {   7, "Return the updated position based on the serving cell identity"},
*/
/*
  values through 95 Reserved. Treat the same as value 1, Initial position.
  96 through 255 Reserved for TIA/EIA-41 protocol extension. If unknown, treat the
  same as value 1, Initial position.
  *
  {     0, NULL }
  };

*/

/* LCS Client Type (CTYP) (octet 2, bit A) *
   0 Emergency services LCS Client.
   1 Non-emergency services LCS Client.
   Call-Related Indicator (CALL) (octet 2, bit B)
   Decimal Value Meaning
   0 Call-related LCS Client request.
   1 Non call-related LCS Client request.

   Current Serving Cell Information for Coarse Position Determination (CELL) (octet 2, bit C)
   Decimal Value Meaning
   0 No specific request.
   1 Current serving cell information. Current serving cell information for
   Target MS requested. Radio contact with Target MS is required.
*/
/* 6.5.2.ft PositionResult *
   static const value_string ansi_map_PositionResult_vals[]  = {
   {   0, "Not used"},
   {   1, "Initial position returned"},
   {   2, "Updated position returned"},
   {   3, "Last known position returned"},
   {   4, "Requested position is not available"},
   {   5, "Target MS disconnect"},
   {   6, "Target MS has handed-off"},
   {   7, "Identified MS is inactive or has roamed to another system"},
   {   8, "Unresponsive"},
   {   9, "Identified MS is responsive, but refused position request"},
   {   10, "System Failure"},
   {   11, "MSID is not known"},
   {   12, "Callback number is not known"},
   {   13, "Improper request"},
   {   14, "Mobile information returned"},
   {   15, "Signal not detected"},
   {   16, "PDE Timeout"},
   {   17, "Position pending"},
   {   18, "TDMA MAHO Information Returned"},
   {   19, "TDMA MAHO Information is not available"},
   {   20, "Access Denied"},
   {   21, "Requested PQOS not met"},
   {   22, "Resource required for CDMA handset-based position determination is currently unavailable"},
   {   23, "CDMA handset-based position determination failure"},
   {   24, "CDMA handset-based position determination failure detected by the PDE"},
   {   25, "CDMA handset-based position determination incomplete traffic channel requested for voice services"},
   {   26, "Emergency services call notification"},
   {   27, "Emergency services call precedence"},
   {   28, "Request acknowledged"},
   {    0, NULL }
   };
*/
#if 0
/* 6.5.2.bp-1 ServiceRedirectionCause value */
static const value_string ansi_map_ServiceRedirectionCause_vals[]  = {
    {   0, "Not used"},
    {   1, "NormalRegistration"},
    {   2, "SystemNotFound"},
    {   3, "ProtocolMismatch"},
    {   4, "RegistrationRejection"},
    {   5, "WrongSID"},
    {   6, "WrongNID"},
    {   0, NULL }
};
#endif
/* 6.5.2.mT AuthenticationResponseReauthentication N.S0011-0 v 1.0*/

/* 6.5.2.vT ReauthenticationReport N.S0011-0 v 1.0*/
static const value_string ansi_map_ReauthenticationReport_vals[]  = {
    {   0, "Not used"},
    {   1, "Reauthentication not attempted"},
    {   2, "Reauthentication no response"},
    {   3, "Reauthentication successful"},
    {   4, "Reauthentication failed"},
    {   0, NULL }
};



#if 0
/* 6.5.2.lB AKeyProtocolVersion
   N.S0011-0 v 1.0
*/
static const value_string ansi_map_AKeyProtocolVersion_vals[]  = {
    {   0, "Not used"},
    {   1, "A-key Generation not supported"},
    {   2, "Diffie Hellman with 768-bit modulus, 160-bit primitive, and 160-bit exponents"},
    {   3, "Diffie Hellman with 512-bit modulus, 160-bit primitive, and 160-bit exponents"},
    {   4, "Diffie Hellman with 768-bit modulus, 32-bit primitive, and 160-bit exponents"},
    {   0, NULL }
};
#endif
/* 6.5.2.sB OTASP_ResultCode
   N.S0011-0 v 1.0
*/
static const value_string ansi_map_OTASP_ResultCode_vals[]  = {
    {   0, "Accepted - Successful"},
    {   1, "Rejected - Unknown cause."},
    {   2, "Computation Failure - E.g., unable to compute A-key"},
    {   3, "CSC Rejected - CSC challenge failure"},
    {   4, "Unrecognized OTASPCallEntry"},
    {   5, "Unsupported AKeyProtocolVersion(s)"},
    {   6, "Unable to Commit"},
    {   0, NULL }
};

/*6.5.2.wB ServiceIndicator
  N.S0011-0 v 1.0
*/
static const value_string ansi_map_ServiceIndicator_vals[]  = {
    {   0, "Undefined Service"},
    {   1, "CDMA OTASP Service"},
    {   2, "TDMA OTASP Service"},
    {   3, "CDMA OTAPA Service"},
    {   4, "CDMA Position Determination Service (Emergency Services)"},
    {   5, "AMPS Position Determination Service (Emergency Services)"},
    {   6, "CDMA Position Determination Service (Value Added Services)"},
    {   0, NULL }
};

/* 6.5.2.xB SignalingMessageEncryptionReport
   N.S0011-0 v 1.0
*/
static const value_string ansi_map_SMEReport_vals[]  = {
    {   0, "Not used"},
    {   1, "Signaling Message Encryption enabling not attempted"},
    {   2, "Signaling Message Encryption enabling no response"},
    {   3, "Signaling Message Encryption is enabled"},
    {   4, "Signaling Message Encryption enabling failed"},
    {   0, NULL }
};

/* 6.5.2.zB VoicePrivacyReport
   N.S0011-0 v 1.0
*/
static const value_string ansi_map_VoicePrivacyReport_vals[]  = {
    {   0, "Not used"},
    {   1, "Voice Privacy not attempted"},
    {   2, "Voice Privacy no response"},
    {   3, "Voice Privacy is active"},
    {   4, "Voice Privacy failed"},
    {   0, NULL }
};




static int
dissect_ansi_map_ElectronicSerialNumber(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_MINType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_min_type(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_MobileIdentificationNumber(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_MINType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}


static const value_string ansi_map_MSID_vals[] = {
  {   8, "mobileIdentificationNumber" },
  { 242, "imsi" },
  { 0, NULL }
};

static const ber_choice_t MSID_choice[] = {
  {   8, &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { 242, &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { 0, NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_MSID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 MSID_choice, hf_index, ett_ansi_map_MSID,
                                 NULL);

  return offset;
}



static int
dissect_ansi_map_AuthenticationAlgorithmVersion(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_AuthenticationResponseReauthentication(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_AuthenticationResponseUniqueChallenge(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CallHistoryCount(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}



static int
dissect_ansi_map_CDMAPrivateLongCodeMask(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_DigitsType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_digits_type(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_CarrierDigits(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_CaveKey(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string ansi_map_DenyAccess_vals[] = {
  {   0, "not-used" },
  {   1, "unspecified" },
  {   2, "ssd-Update-failure" },
  {   3, "cOUNT-Update-failure" },
  {   4, "unique-Challenge-failure" },
  {   5, "aUTHR-mismatch" },
  {   6, "cOUNT-mismatch" },
  {   7, "process-collision" },
  {   8, "missing-authentication-parameters" },
  {   9, "terminalType-mismatch" },
  {  10, "mIN-IMSI-or-ESN-authorization-failure" },
  { 0, NULL }
};


static int
dissect_ansi_map_DenyAccess(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_DestinationDigits(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_LocationAreaID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_RandomVariableReauthentication(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_MEID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_MobileStationMIN(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_MINType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_MSCID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_mscid(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_RandomVariableSSD(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_RandomVariableUniqueChallenge(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_RoutingDigits(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_SenderIdentificationNumber(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_SharedSecretData(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_SignalingMessageEncryptionKey(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string ansi_map_SSDNotShared_vals[] = {
  {   0, "not-used" },
  {   1, "discard-SSD" },
  { 0, NULL }
};


static int
dissect_ansi_map_SSDNotShared(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const value_string ansi_map_UpdateCount_vals[] = {
  {   0, "not-used" },
  {   1, "update-COUNT" },
  { 0, NULL }
};


static int
dissect_ansi_map_UpdateCount(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t AuthenticationDirective_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_authenticationAlgorithmVersion, BER_CLASS_CON, 77, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationAlgorithmVersion },
  { &hf_ansi_map_authenticationResponseReauthentication, BER_CLASS_CON, 182, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationResponseReauthentication },
  { &hf_ansi_map_authenticationResponseUniqueChallenge, BER_CLASS_CON, 37, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationResponseUniqueChallenge },
  { &hf_ansi_map_callHistoryCount, BER_CLASS_CON, 38, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallHistoryCount },
  { &hf_ansi_map_cdmaPrivateLongCodeMask, BER_CLASS_CON, 67, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPrivateLongCodeMask },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_caveKey    , BER_CLASS_CON, 316, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CaveKey },
  { &hf_ansi_map_denyAccess , BER_CLASS_CON, 50, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DenyAccess },
  { &hf_ansi_map_destinationDigits, BER_CLASS_CON, 87, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DestinationDigits },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_randomVariableReauthentication, BER_CLASS_CON, 191, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariableReauthentication },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { &hf_ansi_map_mobileStationMIN, BER_CLASS_CON, 184, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileStationMIN },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_randomVariableSSD, BER_CLASS_CON, 42, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariableSSD },
  { &hf_ansi_map_randomVariableUniqueChallenge, BER_CLASS_CON, 43, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariableUniqueChallenge },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_sharedSecretData, BER_CLASS_CON, 46, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SharedSecretData },
  { &hf_ansi_map_signalingMessageEncryptionKey, BER_CLASS_CON, 45, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SignalingMessageEncryptionKey },
  { &hf_ansi_map_ssdnotShared, BER_CLASS_CON, 52, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SSDNotShared },
  { &hf_ansi_map_updateCount, BER_CLASS_CON, 51, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UpdateCount },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AuthenticationDirective_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              AuthenticationDirective_U_set, hf_index, ett_ansi_map_AuthenticationDirective_U);

  return offset;
}



static int
dissect_ansi_map_AuthenticationDirective(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_AuthenticationDirective_U);

  return offset;
}


static const ber_sequence_t AuthenticationDirectiveRes_U_set[] = {
  { &hf_ansi_map_callHistoryCount, BER_CLASS_CON, 38, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallHistoryCount },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AuthenticationDirectiveRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              AuthenticationDirectiveRes_U_set, hf_index, ett_ansi_map_AuthenticationDirectiveRes_U);

  return offset;
}



static int
dissect_ansi_map_AuthenticationDirectiveRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_AuthenticationDirectiveRes_U);

  return offset;
}



static int
dissect_ansi_map_InterMSCCircuitID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_intermsccircuitid(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}


static const ber_sequence_t AuthenticationDirectiveForward_U_set[] = {
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_authenticationResponseUniqueChallenge, BER_CLASS_CON, 37, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationResponseUniqueChallenge },
  { &hf_ansi_map_randomVariableUniqueChallenge, BER_CLASS_CON, 43, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariableUniqueChallenge },
  { &hf_ansi_map_updateCount, BER_CLASS_CON, 51, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UpdateCount },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AuthenticationDirectiveForward_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              AuthenticationDirectiveForward_U_set, hf_index, ett_ansi_map_AuthenticationDirectiveForward_U);

  return offset;
}



static int
dissect_ansi_map_AuthenticationDirectiveForward(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_AuthenticationDirectiveForward_U);

  return offset;
}



static int
dissect_ansi_map_CountUpdateReport(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_UniqueChallengeReport(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t AuthenticationDirectiveForwardRes_U_set[] = {
  { &hf_ansi_map_countUpdateReport, BER_CLASS_CON, 138, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CountUpdateReport },
  { &hf_ansi_map_uniqueChallengeReport, BER_CLASS_CON, 124, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UniqueChallengeReport },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AuthenticationDirectiveForwardRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              AuthenticationDirectiveForwardRes_U_set, hf_index, ett_ansi_map_AuthenticationDirectiveForwardRes_U);

  return offset;
}



static int
dissect_ansi_map_AuthenticationDirectiveForwardRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_AuthenticationDirectiveForwardRes_U);

  return offset;
}


static const value_string ansi_map_ReportType_vals[] = {
  {   0, "not-used" },
  {   1, "unspecified-security-violation" },
  {   2, "mSID-ESN-mismatch" },
  {   3, "rANDC-mismatch" },
  {   4, "reserved" },
  {   5, "sSD-update-failed" },
  {   6, "reserved" },
  {   7, "cOUNT-mismatch" },
  {   8, "reserved" },
  {   9, "unique-Challenge-failed" },
  {  10, "unsolicited-Base-Station-Challenge" },
  {  11, "sSD-Update-no-response" },
  {  12, "cOUNT-Update-no-response" },
  {  13, "unique-Challenge-no-response" },
  {  14, "aUTHR-mismatch" },
  {  15, "tERMTYP-mismatch" },
  {  16, "missing-authentication-parameters" },
  { 0, NULL }
};


static int
dissect_ansi_map_ReportType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const value_string ansi_map_SystemAccessType_vals[] = {
  {   0, "not-used" },
  {   1, "unspecified" },
  {   2, "flash-request" },
  {   3, "autonomous-registration" },
  {   4, "call-origination" },
  {   5, "page-response" },
  {   6, "no-access" },
  {   7, "power-down-registration" },
  {   8, "sms-page-response" },
  {   9, "otasp" },
  { 0, NULL }
};


static int
dissect_ansi_map_SystemAccessType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_SystemCapabilities(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_systemcapabilities(parameter_tvb,actx->pinfo,tree, actx);
	}



  return offset;
}



static int
dissect_ansi_map_CallHistoryCountExpected(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}


static const value_string ansi_map_TerminalType_vals[] = {
  {   0, "not-used" },
  {   1, "not-distinguished" },
  {   2, "iS-54-B" },
  {   3, "iS-136" },
  {   4, "j-STD-011" },
  {   5, "iS-136-A-or-TIA-EIA-136-Revision-0" },
  {   6, "tIA-EIA-136-A" },
  {   7, "iA-EIA-136-B" },
  {  32, "iS-95" },
  {  33, "iS-95B" },
  {  34, "j-STD-008" },
  {  35, "tIA-EIA-95-B" },
  {  36, "iS-2000" },
  {  64, "iS-88" },
  {  65, "iS-94" },
  {  66, "iS-91" },
  {  67, "j-STD-014" },
  {  68, "tIA-EIA-553-A" },
  {  69, "iS-91-A" },
  { 0, NULL }
};

static value_string_ext ansi_map_TerminalType_vals_ext = VALUE_STRING_EXT_INIT(ansi_map_TerminalType_vals);


static int
dissect_ansi_map_TerminalType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t AuthenticationFailureReport_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_reportType , BER_CLASS_CON, 44, BER_FLAGS_IMPLTAG, dissect_ansi_map_ReportType },
  { &hf_ansi_map_systemAccessType, BER_CLASS_CON, 34, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemAccessType },
  { &hf_ansi_map_systemCapabilities, BER_CLASS_CON, 49, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemCapabilities },
  { &hf_ansi_map_callHistoryCount, BER_CLASS_CON, 38, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallHistoryCount },
  { &hf_ansi_map_callHistoryCountExpected, BER_CLASS_CON, 79, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallHistoryCountExpected },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_reportType2, BER_CLASS_CON, 44, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReportType },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_terminalType, BER_CLASS_CON, 47, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminalType },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AuthenticationFailureReport_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              AuthenticationFailureReport_U_set, hf_index, ett_ansi_map_AuthenticationFailureReport_U);

  return offset;
}



static int
dissect_ansi_map_AuthenticationFailureReport(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_AuthenticationFailureReport_U);

  return offset;
}


static const ber_sequence_t AuthenticationFailureReportRes_U_set[] = {
  { &hf_ansi_map_authenticationAlgorithmVersion, BER_CLASS_CON, 77, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationAlgorithmVersion },
  { &hf_ansi_map_authenticationResponseUniqueChallenge, BER_CLASS_CON, 37, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationResponseUniqueChallenge },
  { &hf_ansi_map_callHistoryCount, BER_CLASS_CON, 38, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallHistoryCount },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_denyAccess , BER_CLASS_CON, 50, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DenyAccess },
  { &hf_ansi_map_destinationDigits, BER_CLASS_CON, 87, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DestinationDigits },
  { &hf_ansi_map_randomVariableSSD, BER_CLASS_CON, 42, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariableSSD },
  { &hf_ansi_map_randomVariableUniqueChallenge, BER_CLASS_CON, 43, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariableUniqueChallenge },
  { &hf_ansi_map_sharedSecretData, BER_CLASS_CON, 46, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SharedSecretData },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_ssdnotShared, BER_CLASS_CON, 52, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SSDNotShared },
  { &hf_ansi_map_terminalType, BER_CLASS_CON, 47, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminalType },
  { &hf_ansi_map_updateCount, BER_CLASS_CON, 51, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UpdateCount },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AuthenticationFailureReportRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              AuthenticationFailureReportRes_U_set, hf_index, ett_ansi_map_AuthenticationFailureReportRes_U);

  return offset;
}



static int
dissect_ansi_map_AuthenticationFailureReportRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_AuthenticationFailureReportRes_U);

  return offset;
}



static int
dissect_ansi_map_AuthenticationData(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_AuthenticationResponse(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CDMANetworkIdentification(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_ConfidentialityModes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_confidentialitymodes(parameter_tvb,actx->pinfo,tree, actx);
	}

  return offset;
}



static int
dissect_ansi_map_ControlChannelMode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_Digits(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_PC_SSN(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_pc_ssn(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_RandomVariable(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_ServiceRedirectionCause(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string ansi_map_SuspiciousAccess_vals[] = {
  {   0, "not-used" },
  {   1, "anomalous-Digits" },
  {   2, "unspecified" },
  { 0, NULL }
};


static int
dissect_ansi_map_SuspiciousAccess(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_TransactionCapability(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_transactioncapability(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}


static const ber_sequence_t AuthenticationRequest_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_systemAccessType, BER_CLASS_CON, 34, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemAccessType },
  { &hf_ansi_map_systemCapabilities, BER_CLASS_CON, 49, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemCapabilities },
  { &hf_ansi_map_authenticationData, BER_CLASS_CON, 161, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationData },
  { &hf_ansi_map_authenticationResponse, BER_CLASS_CON, 35, BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationResponse },
  { &hf_ansi_map_callHistoryCount, BER_CLASS_CON, 38, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallHistoryCount },
  { &hf_ansi_map_cdmaNetworkIdentification, BER_CLASS_CON, 232, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMANetworkIdentification },
  { &hf_ansi_map_confidentialityModes, BER_CLASS_CON, 39, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConfidentialityModes },
  { &hf_ansi_map_controlChannelMode, BER_CLASS_CON, 199, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlChannelMode },
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_randomVariable, BER_CLASS_CON, 40, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariable },
  { &hf_ansi_map_serviceRedirectionCause, BER_CLASS_CON, 237, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceRedirectionCause },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_suspiciousAccess, BER_CLASS_CON, 285, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SuspiciousAccess },
  { &hf_ansi_map_terminalType, BER_CLASS_CON, 47, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminalType },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AuthenticationRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              AuthenticationRequest_U_set, hf_index, ett_ansi_map_AuthenticationRequest_U);

  return offset;
}



static int
dissect_ansi_map_AuthenticationRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_AuthenticationRequest_U);

  return offset;
}



static int
dissect_ansi_map_AnalogRedirectInfo(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t AnalogRedirectRecord_sequence[] = {
  { &hf_ansi_map_analogRedirectInfo, BER_CLASS_CON, 224, BER_FLAGS_IMPLTAG, dissect_ansi_map_AnalogRedirectInfo },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AnalogRedirectRecord(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   AnalogRedirectRecord_sequence, hf_index, ett_ansi_map_AnalogRedirectRecord);

  return offset;
}



static int
dissect_ansi_map_CDMABandClass(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CDMAChannelNumber(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t CDMAChannelNumberList_item_sequence[] = {
  { &hf_ansi_map_cdmaChannelNumber, BER_CLASS_CON, 226, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelNumber },
  { &hf_ansi_map_cdmaChannelNumber2, BER_CLASS_CON, 226, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CDMAChannelNumberList_item(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   CDMAChannelNumberList_item_sequence, hf_index, ett_ansi_map_CDMAChannelNumberList_item);

  return offset;
}


static const ber_sequence_t CDMAChannelNumberList_sequence_of[1] = {
  { &hf_ansi_map_CDMAChannelNumberList_item, BER_CLASS_UNI, BER_UNI_TAG_SEQUENCE, BER_FLAGS_NOOWNTAG, dissect_ansi_map_CDMAChannelNumberList_item },
};

static int
dissect_ansi_map_CDMAChannelNumberList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      CDMAChannelNumberList_sequence_of, hf_index, ett_ansi_map_CDMAChannelNumberList);

  return offset;
}


static const ber_sequence_t CDMARedirectRecord_sequence[] = {
  { &hf_ansi_map_cdmaBandClass, BER_CLASS_CON, 170, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMABandClass },
  { &hf_ansi_map_cdmaChannelNumberList, BER_CLASS_CON, 227, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelNumberList },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_cdmaNetworkIdentification, BER_CLASS_CON, 232, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMANetworkIdentification },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CDMARedirectRecord(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   CDMARedirectRecord_sequence, hf_index, ett_ansi_map_CDMARedirectRecord);

  return offset;
}



static int
dissect_ansi_map_DataKey(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_RoamingIndication(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_ServiceRedirectionInfo(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_VoicePrivacyMask(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t AuthenticationRequestRes_U_set[] = {
  { &hf_ansi_map_analogRedirectRecord, BER_CLASS_CON, 225, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnalogRedirectRecord },
  { &hf_ansi_map_authenticationAlgorithmVersion, BER_CLASS_CON, 77, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationAlgorithmVersion },
  { &hf_ansi_map_authenticationResponseUniqueChallenge, BER_CLASS_CON, 37, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationResponseUniqueChallenge },
  { &hf_ansi_map_callHistoryCount, BER_CLASS_CON, 38, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallHistoryCount },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_cdmaPrivateLongCodeMask, BER_CLASS_CON, 67, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPrivateLongCodeMask },
  { &hf_ansi_map_cdmaRedirectRecord, BER_CLASS_CON, 229, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMARedirectRecord },
  { &hf_ansi_map_dataKey    , BER_CLASS_CON, 215, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataKey },
  { &hf_ansi_map_denyAccess , BER_CLASS_CON, 50, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DenyAccess },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_roamingIndication, BER_CLASS_CON, 239, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoamingIndication },
  { &hf_ansi_map_serviceRedirectionInfo, BER_CLASS_CON, 238, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceRedirectionInfo },
  { &hf_ansi_map_destinationDigits, BER_CLASS_CON, 87, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DestinationDigits },
  { &hf_ansi_map_randomVariableSSD, BER_CLASS_CON, 42, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariableSSD },
  { &hf_ansi_map_randomVariableUniqueChallenge, BER_CLASS_CON, 43, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariableUniqueChallenge },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_sharedSecretData, BER_CLASS_CON, 46, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SharedSecretData },
  { &hf_ansi_map_signalingMessageEncryptionKey, BER_CLASS_CON, 45, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SignalingMessageEncryptionKey },
  { &hf_ansi_map_ssdnotShared, BER_CLASS_CON, 52, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SSDNotShared },
  { &hf_ansi_map_updateCount, BER_CLASS_CON, 51, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UpdateCount },
  { &hf_ansi_map_voicePrivacyMask, BER_CLASS_CON, 48, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoicePrivacyMask },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AuthenticationRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              AuthenticationRequestRes_U_set, hf_index, ett_ansi_map_AuthenticationRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_AuthenticationRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_AuthenticationRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_ReauthenticationReport(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_ServiceIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		ServiceIndicator = tvb_get_uint8(parameter_tvb,0);
		if (SMS_BearerData_tvb !=NULL)
		{
			switch(ServiceIndicator){
				case 1: /* CDMA OTASP Service */
				case 3: /* CDMA OTAPA Service */
					dissector_try_uint(is683_dissector_table, ansi_map_is_invoke ? 0 : 1, SMS_BearerData_tvb, g_pinfo, g_tree);
					break;
				case 4: /* CDMA Position Determination Service */
					dissector_try_uint(is801_dissector_table, ansi_map_is_invoke ? 0 : 1, SMS_BearerData_tvb, g_pinfo, g_tree);
					break;
				default:
					break;
			}
		}
	}


  return offset;
}



static int
dissect_ansi_map_SignalingMessageEncryptionReport(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_SSDUpdateReport(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_VoicePrivacyReport(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t AuthenticationStatusReport_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_systemCapabilities, BER_CLASS_CON, 49, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemCapabilities },
  { &hf_ansi_map_countUpdateReport, BER_CLASS_CON, 138, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CountUpdateReport },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_reauthenticationReport, BER_CLASS_CON, 192, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReauthenticationReport },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_serviceIndicator, BER_CLASS_CON, 193, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceIndicator },
  { &hf_ansi_map_signalingMessageEncryptionReport, BER_CLASS_CON, 194, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SignalingMessageEncryptionReport },
  { &hf_ansi_map_ssdUpdateReport, BER_CLASS_CON, 156, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SSDUpdateReport },
  { &hf_ansi_map_uniqueChallengeReport, BER_CLASS_CON, 124, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UniqueChallengeReport },
  { &hf_ansi_map_voicePrivacyReport, BER_CLASS_CON, 196, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoicePrivacyReport },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AuthenticationStatusReport_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              AuthenticationStatusReport_U_set, hf_index, ett_ansi_map_AuthenticationStatusReport_U);

  return offset;
}



static int
dissect_ansi_map_AuthenticationStatusReport(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_AuthenticationStatusReport_U);

  return offset;
}


static const ber_sequence_t AuthenticationStatusReportRes_U_set[] = {
  { &hf_ansi_map_authenticationAlgorithmVersion, BER_CLASS_CON, 77, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationAlgorithmVersion },
  { &hf_ansi_map_authenticationResponseUniqueChallenge, BER_CLASS_CON, 37, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationResponseUniqueChallenge },
  { &hf_ansi_map_callHistoryCount, BER_CLASS_CON, 38, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallHistoryCount },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_denyAccess , BER_CLASS_CON, 50, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DenyAccess },
  { &hf_ansi_map_destinationDigits, BER_CLASS_CON, 87, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DestinationDigits },
  { &hf_ansi_map_randomVariableSSD, BER_CLASS_CON, 42, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariableSSD },
  { &hf_ansi_map_randomVariableUniqueChallenge, BER_CLASS_CON, 43, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariableUniqueChallenge },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_sharedSecretData, BER_CLASS_CON, 46, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SharedSecretData },
  { &hf_ansi_map_ssdnotShared, BER_CLASS_CON, 52, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SSDNotShared },
  { &hf_ansi_map_updateCount, BER_CLASS_CON, 51, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UpdateCount },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AuthenticationStatusReportRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              AuthenticationStatusReportRes_U_set, hf_index, ett_ansi_map_AuthenticationStatusReportRes_U);

  return offset;
}



static int
dissect_ansi_map_AuthenticationStatusReportRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_AuthenticationStatusReportRes_U);

  return offset;
}



static int
dissect_ansi_map_RandomVariableBaseStation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t BaseStationChallenge_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_randomVariableBaseStation, BER_CLASS_CON, 41, BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariableBaseStation },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_serviceIndicator, BER_CLASS_CON, 193, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceIndicator },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_BaseStationChallenge_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              BaseStationChallenge_U_set, hf_index, ett_ansi_map_BaseStationChallenge_U);

  return offset;
}



static int
dissect_ansi_map_BaseStationChallenge(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_BaseStationChallenge_U);

  return offset;
}



static int
dissect_ansi_map_AuthenticationResponseBaseStation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t BaseStationChallengeRes_U_set[] = {
  { &hf_ansi_map_authenticationResponseBaseStation, BER_CLASS_CON, 36, BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationResponseBaseStation },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_BaseStationChallengeRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              BaseStationChallengeRes_U_set, hf_index, ett_ansi_map_BaseStationChallengeRes_U);

  return offset;
}



static int
dissect_ansi_map_BaseStationChallengeRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_BaseStationChallengeRes_U);

  return offset;
}


static const ber_sequence_t Blocking_U_set[] = {
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_Blocking_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              Blocking_U_set, hf_index, ett_ansi_map_Blocking_U);

  return offset;
}



static int
dissect_ansi_map_Blocking(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_Blocking_U);

  return offset;
}


static const ber_sequence_t BulkDeregistration_U_set[] = {
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_BulkDeregistration_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              BulkDeregistration_U_set, hf_index, ett_ansi_map_BulkDeregistration_U);

  return offset;
}



static int
dissect_ansi_map_BulkDeregistration(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_BulkDeregistration_U);

  return offset;
}


static const ber_sequence_t CountRequest_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CountRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              CountRequest_U_set, hf_index, ett_ansi_map_CountRequest_U);

  return offset;
}



static int
dissect_ansi_map_CountRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_CountRequest_U);

  return offset;
}


static const ber_sequence_t CountRequestRes_U_set[] = {
  { &hf_ansi_map_callHistoryCount, BER_CLASS_CON, 38, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallHistoryCount },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CountRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              CountRequestRes_U_set, hf_index, ett_ansi_map_CountRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_CountRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_CountRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_BillingID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_billingid(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_ChannelData(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_channeldata(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_InterSwitchCount(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}



static int
dissect_ansi_map_ServingCellID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_StationClassMark(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_TargetCellID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string ansi_map_HandoffReason_vals[] = {
  {   0, "not-used" },
  {   1, "unspecified" },
  {   2, "weak-Signal" },
  {   3, "off-loading" },
  {   4, "anticipatory" },
  { 0, NULL }
};


static int
dissect_ansi_map_HandoffReason(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_HandoffState(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_handoffstate(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_TDMABurstIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_TDMACallMode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_TDMAChannelData(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t FacilitiesDirective_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_interSwitchCount, BER_CLASS_CON, 7, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterSwitchCount },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_stationClassMark, BER_CLASS_CON, 18, BER_FLAGS_IMPLTAG, dissect_ansi_map_StationClassMark },
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { &hf_ansi_map_confidentialityModes, BER_CLASS_CON, 39, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConfidentialityModes },
  { &hf_ansi_map_handoffReason, BER_CLASS_CON, 30, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_HandoffReason },
  { &hf_ansi_map_handoffState, BER_CLASS_CON, 164, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_HandoffState },
  { &hf_ansi_map_signalingMessageEncryptionKey, BER_CLASS_CON, 45, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SignalingMessageEncryptionKey },
  { &hf_ansi_map_tdmaBurstIndicator, BER_CLASS_CON, 31, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABurstIndicator },
  { &hf_ansi_map_tdmaCallMode, BER_CLASS_CON, 29, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMACallMode },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { &hf_ansi_map_voicePrivacyMask, BER_CLASS_CON, 48, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoicePrivacyMask },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_FacilitiesDirective_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              FacilitiesDirective_U_set, hf_index, ett_ansi_map_FacilitiesDirective_U);

  return offset;
}



static int
dissect_ansi_map_FacilitiesDirective(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_FacilitiesDirective_U);

  return offset;
}


static const ber_sequence_t FacilitiesDirectiveRes_U_set[] = {
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_confidentialityModes, BER_CLASS_CON, 39, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConfidentialityModes },
  { &hf_ansi_map_tdmaBurstIndicator, BER_CLASS_CON, 31, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABurstIndicator },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_FacilitiesDirectiveRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              FacilitiesDirectiveRes_U_set, hf_index, ett_ansi_map_FacilitiesDirectiveRes_U);

  return offset;
}



static int
dissect_ansi_map_FacilitiesDirectiveRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_FacilitiesDirectiveRes_U);

  return offset;
}



static int
dissect_ansi_map_BaseStationManufacturerCode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_AlertCode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_alertcode(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_CDMA2000HandoffInvokeIOSData(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
    proto_tree *subtree;

  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		subtree = proto_item_add_subtree(actx->created_item, ett_CDMA2000HandoffInvokeIOSData);
		dissect_cdma2000_a1_elements(parameter_tvb, actx->pinfo, subtree,
			0, tvb_reported_length_remaining(parameter_tvb,0));
	}

  return offset;
}



static int
dissect_ansi_map_CDMAMobileProtocolRevision(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CDMAStationClassMark2(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t CDMABandClassInformation_sequence[] = {
  { &hf_ansi_map_cdmaBandClass, BER_CLASS_CON, 170, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMABandClass },
  { &hf_ansi_map_cdmaMobileProtocolRevision, BER_CLASS_CON, 66, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAMobileProtocolRevision },
  { &hf_ansi_map_cdmaStationClassMark2, BER_CLASS_CON, 177, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark2 },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CDMABandClassInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   CDMABandClassInformation_sequence, hf_index, ett_ansi_map_CDMABandClassInformation);

  return offset;
}


static const ber_sequence_t CDMABandClassList_sequence_of[1] = {
  { &hf_ansi_map_CDMABandClassList_item, BER_CLASS_CON, 171, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMABandClassInformation },
};

static int
dissect_ansi_map_CDMABandClassList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      CDMABandClassList_sequence_of, hf_index, ett_ansi_map_CDMABandClassList);

  return offset;
}



static int
dissect_ansi_map_CDMACallMode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_cdmacallmode(parameter_tvb,actx->pinfo,tree, actx);
	}

  return offset;
}



static int
dissect_ansi_map_CDMAChannelData(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_cdmachanneldata(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_CDMAConnectionReference(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CDMAServiceOption(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_cdmaserviceoption(parameter_tvb,actx->pinfo,tree, actx);
	}



  return offset;
}



static int
dissect_ansi_map_CDMAState(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_DataPrivacyParameters(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CDMAServiceOptionConnectionIdentifier(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t CDMAConnectionReferenceInformation_sequence[] = {
  { &hf_ansi_map_cdmaConnectionReference, BER_CLASS_CON, 208, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAConnectionReference },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_cdmaState  , BER_CLASS_CON, 213, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAState },
  { &hf_ansi_map_dataPrivacyParameters, BER_CLASS_CON, 216, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataPrivacyParameters },
  { &hf_ansi_map_cdmaServiceOptionConnectionIdentifier, BER_CLASS_CON, 361, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionConnectionIdentifier },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CDMAConnectionReferenceInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   CDMAConnectionReferenceInformation_sequence, hf_index, ett_ansi_map_CDMAConnectionReferenceInformation);

  return offset;
}


static const ber_sequence_t CDMAConnectionReferenceList_item_sequence[] = {
  { &hf_ansi_map_cdmaConnectionReferenceInformation, BER_CLASS_CON, 211, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAConnectionReferenceInformation },
  { &hf_ansi_map_cdmaConnectionReferenceInformation2, BER_CLASS_CON, 211, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAConnectionReferenceInformation },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CDMAConnectionReferenceList_item(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   CDMAConnectionReferenceList_item_sequence, hf_index, ett_ansi_map_CDMAConnectionReferenceList_item);

  return offset;
}


static const ber_sequence_t CDMAConnectionReferenceList_sequence_of[1] = {
  { &hf_ansi_map_CDMAConnectionReferenceList_item, BER_CLASS_UNI, BER_UNI_TAG_SEQUENCE, BER_FLAGS_NOOWNTAG, dissect_ansi_map_CDMAConnectionReferenceList_item },
};

static int
dissect_ansi_map_CDMAConnectionReferenceList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      CDMAConnectionReferenceList_sequence_of, hf_index, ett_ansi_map_CDMAConnectionReferenceList);

  return offset;
}



static int
dissect_ansi_map_CDMAMSMeasuredChannelIdentity(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CDMAServiceConfigurationRecord(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t CDMAServiceOptionList_sequence_of[1] = {
  { &hf_ansi_map_CDMAServiceOptionList_item, BER_CLASS_CON, 175, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
};

static int
dissect_ansi_map_CDMAServiceOptionList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      CDMAServiceOptionList_sequence_of, hf_index, ett_ansi_map_CDMAServiceOptionList);

  return offset;
}



static int
dissect_ansi_map_CDMAServingOneWayDelay(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CDMAStationClassMark(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_cdmastationclassmark(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_CDMAPilotStrength(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CDMATargetOneWayDelay(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t CDMATargetMAHOInformation_sequence[] = {
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { &hf_ansi_map_cdmaPilotStrength, BER_CLASS_CON, 65, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPilotStrength },
  { &hf_ansi_map_cdmaTargetOneWayDelay, BER_CLASS_CON, 61, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetOneWayDelay },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CDMATargetMAHOInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   CDMATargetMAHOInformation_sequence, hf_index, ett_ansi_map_CDMATargetMAHOInformation);

  return offset;
}


static const ber_sequence_t CDMATargetMAHOList_sequence_of[1] = {
  { &hf_ansi_map_CDMATargetMAHOList_item, BER_CLASS_CON, 135, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMAHOInformation },
};

static int
dissect_ansi_map_CDMATargetMAHOList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      CDMATargetMAHOList_sequence_of, hf_index, ett_ansi_map_CDMATargetMAHOList);

  return offset;
}



static int
dissect_ansi_map_CDMASignalQuality(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t CDMATargetMeasurementInformation_sequence[] = {
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { &hf_ansi_map_cdmaSignalQuality, BER_CLASS_CON, 64, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMASignalQuality },
  { &hf_ansi_map_cdmaTargetOneWayDelay, BER_CLASS_CON, 61, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetOneWayDelay },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CDMATargetMeasurementInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   CDMATargetMeasurementInformation_sequence, hf_index, ett_ansi_map_CDMATargetMeasurementInformation);

  return offset;
}


static const ber_sequence_t CDMATargetMeasurementList_sequence_of[1] = {
  { &hf_ansi_map_CDMATargetMeasurementList_item, BER_CLASS_CON, 133, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMeasurementInformation },
};

static int
dissect_ansi_map_CDMATargetMeasurementList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      CDMATargetMeasurementList_sequence_of, hf_index, ett_ansi_map_CDMATargetMeasurementList);

  return offset;
}



static int
dissect_ansi_map_ISLPInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_MSLocation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_mslocation(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_NAMPSCallMode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_nampscallmode(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_NAMPSChannelData(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_nampschanneldata(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_NonPublicData(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_PDSNAddress(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_PDSNProtocolType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_QoSPriority(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_SystemOperatorCode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_TDMABandwidth(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_TDMAServiceCode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_TDMATerminalCapability(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_TDMAVoiceCoder(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_UserZoneData(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t FacilitiesDirective2_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_interSwitchCount, BER_CLASS_CON, 7, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterSwitchCount },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_baseStationManufacturerCode, BER_CLASS_CON, 197, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BaseStationManufacturerCode },
  { &hf_ansi_map_alertCode  , BER_CLASS_CON, 75, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AlertCode },
  { &hf_ansi_map_cdma2000HandoffInvokeIOSData, BER_CLASS_CON, 356, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMA2000HandoffInvokeIOSData },
  { &hf_ansi_map_cdmaBandClassList, BER_CLASS_CON, 172, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMABandClassList },
  { &hf_ansi_map_cdmaCallMode, BER_CLASS_CON, 62, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMACallMode },
  { &hf_ansi_map_cdmaChannelData, BER_CLASS_CON, 63, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelData },
  { &hf_ansi_map_cdmaConnectionReferenceList, BER_CLASS_CON, 212, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAConnectionReferenceList },
  { &hf_ansi_map_cdmaMobileProtocolRevision, BER_CLASS_CON, 66, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAMobileProtocolRevision },
  { &hf_ansi_map_cdmaMSMeasuredChannelIdentity, BER_CLASS_CON, 351, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAMSMeasuredChannelIdentity },
  { &hf_ansi_map_cdmaPrivateLongCodeMask, BER_CLASS_CON, 67, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPrivateLongCodeMask },
  { &hf_ansi_map_cdmaServiceConfigurationRecord, BER_CLASS_CON, 174, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceConfigurationRecord },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_cdmaServingOneWayDelay, BER_CLASS_CON, 60, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServingOneWayDelay },
  { &hf_ansi_map_cdmaStationClassMark, BER_CLASS_CON, 59, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark },
  { &hf_ansi_map_cdmaStationClassMark2, BER_CLASS_CON, 177, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark2 },
  { &hf_ansi_map_cdmaTargetMAHOList, BER_CLASS_CON, 136, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMAHOList },
  { &hf_ansi_map_cdmaTargetMeasurementList, BER_CLASS_CON, 134, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMeasurementList },
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_confidentialityModes, BER_CLASS_CON, 39, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConfidentialityModes },
  { &hf_ansi_map_dataKey    , BER_CLASS_CON, 215, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataKey },
  { &hf_ansi_map_dataPrivacyParameters, BER_CLASS_CON, 216, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataPrivacyParameters },
  { &hf_ansi_map_handoffReason, BER_CLASS_CON, 30, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_HandoffReason },
  { &hf_ansi_map_handoffState, BER_CLASS_CON, 164, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_HandoffState },
  { &hf_ansi_map_ilspInformation, BER_CLASS_CON, 217, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ISLPInformation },
  { &hf_ansi_map_msLocation , BER_CLASS_CON, 70, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSLocation },
  { &hf_ansi_map_nampsCallMode, BER_CLASS_CON, 165, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSCallMode },
  { &hf_ansi_map_nampsChannelData, BER_CLASS_CON, 74, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSChannelData },
  { &hf_ansi_map_randomVariable, BER_CLASS_CON, 40, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariable },
  { &hf_ansi_map_nonPublicData, BER_CLASS_CON, 200, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NonPublicData },
  { &hf_ansi_map_pdsnAddress, BER_CLASS_CON, 349, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PDSNAddress },
  { &hf_ansi_map_pdsnProtocolType, BER_CLASS_CON, 350, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PDSNProtocolType },
  { &hf_ansi_map_qosPriority, BER_CLASS_CON, 348, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_QoSPriority },
  { &hf_ansi_map_signalingMessageEncryptionKey, BER_CLASS_CON, 45, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SignalingMessageEncryptionKey },
  { &hf_ansi_map_stationClassMark, BER_CLASS_CON, 18, BER_FLAGS_IMPLTAG, dissect_ansi_map_StationClassMark },
  { &hf_ansi_map_systemOperatorCode, BER_CLASS_CON, 206, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemOperatorCode },
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { &hf_ansi_map_tdmaBandwidth, BER_CLASS_CON, 220, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABandwidth },
  { &hf_ansi_map_tdmaBurstIndicator, BER_CLASS_CON, 31, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABurstIndicator },
  { &hf_ansi_map_tdmaCallMode, BER_CLASS_CON, 29, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMACallMode },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_tdmaTerminalCapability, BER_CLASS_CON, 179, BER_FLAGS_OPTIONAL, dissect_ansi_map_TDMATerminalCapability },
  { &hf_ansi_map_tdmaVoiceCoder, BER_CLASS_CON, 180, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAVoiceCoder },
  { &hf_ansi_map_terminalType, BER_CLASS_CON, 47, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminalType },
  { &hf_ansi_map_userZoneData, BER_CLASS_CON, 209, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UserZoneData },
  { &hf_ansi_map_voicePrivacyMask, BER_CLASS_CON, 48, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoicePrivacyMask },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_FacilitiesDirective2_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              FacilitiesDirective2_U_set, hf_index, ett_ansi_map_FacilitiesDirective2_U);

  return offset;
}



static int
dissect_ansi_map_FacilitiesDirective2(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_FacilitiesDirective2_U);

  return offset;
}



static int
dissect_ansi_map_BSMCStatus(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CDMA2000HandoffResponseIOSData(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
    proto_tree *subtree;

  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		subtree = proto_item_add_subtree(actx->created_item, ett_CDMA2000HandoffResponseIOSData);
		dissect_cdma2000_a1_elements(parameter_tvb, actx->pinfo, subtree,
			0, tvb_reported_length_remaining(parameter_tvb,0));
	}

  return offset;
}



static int
dissect_ansi_map_CDMACodeChannel(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CDMAPilotPN(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CDMAPowerCombinedIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t CDMACodeChannelInformation_sequence[] = {
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { &hf_ansi_map_cdmaCodeChannel, BER_CLASS_CON, 68, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMACodeChannel },
  { &hf_ansi_map_cdmaPilotPN, BER_CLASS_CON, 173, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPilotPN },
  { &hf_ansi_map_cdmaPowerCombinedIndicator, BER_CLASS_CON, 228, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPowerCombinedIndicator },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CDMACodeChannelInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   CDMACodeChannelInformation_sequence, hf_index, ett_ansi_map_CDMACodeChannelInformation);

  return offset;
}


static const ber_sequence_t CDMACodeChannelList_sequence_of[1] = {
  { &hf_ansi_map_CDMACodeChannelList_item, BER_CLASS_CON, 131, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMACodeChannelInformation },
};

static int
dissect_ansi_map_CDMACodeChannelList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      CDMACodeChannelList_sequence_of, hf_index, ett_ansi_map_CDMACodeChannelList);

  return offset;
}



static int
dissect_ansi_map_CDMASearchParameters(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CDMASearchWindow(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_SOCStatus(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t FacilitiesDirective2Res_U_set[] = {
  { &hf_ansi_map_bsmcstatus , BER_CLASS_CON, 198, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BSMCStatus },
  { &hf_ansi_map_cdma2000HandoffResponseIOSData, BER_CLASS_CON, 357, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMA2000HandoffResponseIOSData },
  { &hf_ansi_map_cdmaChannelData, BER_CLASS_CON, 63, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelData },
  { &hf_ansi_map_cdmaCodeChannelList, BER_CLASS_CON, 132, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMACodeChannelList },
  { &hf_ansi_map_cdmaConnectionReferenceList, BER_CLASS_CON, 212, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAConnectionReferenceList },
  { &hf_ansi_map_cdmaSearchParameters, BER_CLASS_CON, 230, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMASearchParameters },
  { &hf_ansi_map_cdmaSearchWindow, BER_CLASS_CON, 69, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMASearchWindow },
  { &hf_ansi_map_cdmaServiceConfigurationRecord, BER_CLASS_CON, 174, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceConfigurationRecord },
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_confidentialityModes, BER_CLASS_CON, 39, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConfidentialityModes },
  { &hf_ansi_map_ilspInformation, BER_CLASS_CON, 217, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ISLPInformation },
  { &hf_ansi_map_nampsChannelData, BER_CLASS_CON, 74, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSChannelData },
  { &hf_ansi_map_sOCStatus  , BER_CLASS_CON, 205, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SOCStatus },
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { &hf_ansi_map_tdmaBurstIndicator, BER_CLASS_CON, 31, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABurstIndicator },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { &hf_ansi_map_tdmaVoiceCoder, BER_CLASS_CON, 180, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAVoiceCoder },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_FacilitiesDirective2Res_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              FacilitiesDirective2Res_U_set, hf_index, ett_ansi_map_FacilitiesDirective2Res_U);

  return offset;
}



static int
dissect_ansi_map_FacilitiesDirective2Res(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_FacilitiesDirective2Res_U);

  return offset;
}


static const value_string ansi_map_ReleaseReason_vals[] = {
  {   0, "unspecified" },
  {   1, "callOverClearForward" },
  {   2, "callOverClearBackward" },
  {   3, "handoffSuccessful" },
  {   4, "handoffAbort-call-over" },
  {   5, "handoffAbort-not-received" },
  {   6, "abnormalMobileTermination" },
  {   7, "abnormalSwitchTermination" },
  {   8, "specialFeatureRelease" },
  {   9, "sessionOverClearForward" },
  {  10, "sessionOverClearBackward" },
  {  11, "clearAllServicesForward" },
  {  12, "clearAllServicesBackward" },
  {  13, "anchor-MSC-was-removed-from-the-packet-data-session" },
  {  14, "keep-MS-on-traffic-channel" },
  { 0, NULL }
};


static int
dissect_ansi_map_ReleaseReason(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t FacilitiesRelease_U_set[] = {
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_releaseReason, BER_CLASS_CON, 10, BER_FLAGS_IMPLTAG, dissect_ansi_map_ReleaseReason },
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_FacilitiesRelease_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              FacilitiesRelease_U_set, hf_index, ett_ansi_map_FacilitiesRelease_U);

  return offset;
}



static int
dissect_ansi_map_FacilitiesRelease(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_FacilitiesRelease_U);

  return offset;
}


static const ber_sequence_t FacilitiesReleaseRes_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_FacilitiesReleaseRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              FacilitiesReleaseRes_U_set, hf_index, ett_ansi_map_FacilitiesReleaseRes_U);

  return offset;
}



static int
dissect_ansi_map_FacilitiesReleaseRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_FacilitiesReleaseRes_U);

  return offset;
}



static int
dissect_ansi_map_ACGEncountered(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CallingPartyName(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_callingpartyname(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_CallingPartyNumberDigits1(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_CallingPartyNumberDigits2(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_Subaddress(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_subaddress(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_CallingPartySubaddress(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_Subaddress(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_ConferenceCallingIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_MobileDirectoryNumber(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_MSCIdentificationNumber(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_OneTimeFeatureIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_onetimefeatureindicator(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}


static const value_string ansi_map_SystemMyTypeCode_vals[] = {
  {   0, "not-used" },
  {   1, "eDS" },
  {   2, "astronet" },
  {   3, "lucent-Technologies" },
  {   4, "ericsson" },
  {   5, "gTE" },
  {   6, "motorola" },
  {   7, "nEC" },
  {   8, "nORTEL" },
  {   9, "novAtel" },
  {  10, "plexsys" },
  {  11, "digital-Equipment-Corp" },
  {  12, "iNET" },
  {  13, "bellcore" },
  {  14, "alcatel-SEL" },
  {  15, "compaq" },
  {  16, "qUALCOMM" },
  {  17, "aldiscon" },
  {  18, "celcore" },
  {  19, "tELOS" },
  {  20, "aDI-Limited" },
  {  21, "coral-Systems" },
  {  22, "synacom-Technology" },
  {  23, "dSC" },
  {  24, "mCI" },
  {  25, "newNet" },
  {  26, "sema-Group-Telecoms" },
  {  27, "lG-Information-and-Communications" },
  {  28, "cBIS" },
  {  29, "siemens" },
  {  30, "samsung-Electronics" },
  {  31, "readyCom-Inc" },
  {  32, "aG-Communication-Systems" },
  {  33, "hughes-Network-Systems" },
  {  34, "phoenix-Wireless-Group" },
  { 0, NULL }
};

static value_string_ext ansi_map_SystemMyTypeCode_vals_ext = VALUE_STRING_EXT_INIT(ansi_map_SystemMyTypeCode_vals);


static int
dissect_ansi_map_SystemMyTypeCode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t FeatureRequest_U_set[] = {
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_acgencountered, BER_CLASS_CON, 340, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ACGEncountered },
  { &hf_ansi_map_callingPartyName, BER_CLASS_CON, 243, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyName },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_callingPartyNumberDigits2, BER_CLASS_CON, 81, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_conferenceCallingIndicator, BER_CLASS_CON, 137, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConferenceCallingIndicator },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_FeatureRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              FeatureRequest_U_set, hf_index, ett_ansi_map_FeatureRequest_U);

  return offset;
}



static int
dissect_ansi_map_FeatureRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_FeatureRequest_U);

  return offset;
}


static const value_string ansi_map_FeatureResult_vals[] = {
  {   0, "not-used" },
  {   1, "unsuccessful" },
  {   2, "successful" },
  { 0, NULL }
};


static int
dissect_ansi_map_FeatureResult(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const value_string ansi_map_AccessDeniedReason_vals[] = {
  {   0, "not-used" },
  {   1, "unassigned-directory-number" },
  {   2, "inactive" },
  {   3, "busy" },
  {   4, "termination-denied" },
  {   5, "no-page-response" },
  {   6, "unavailable" },
  {   7, "service-Rejected-by-MS" },
  {   8, "services-Rejected-by-the-System" },
  {   9, "service-Type-Mismatch" },
  {  10, "service-Denied" },
  {  12, "position-Determination-Not-Supported" },
  { 0, NULL }
};


static int
dissect_ansi_map_AccessDeniedReason(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_ActionCode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_AnnouncementCode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_announcementcode(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}


static const ber_sequence_t AnnouncementList_sequence[] = {
  { &hf_ansi_map_announcementCode1, BER_CLASS_CON, 76, BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementCode },
  { &hf_ansi_map_announcementCode2, BER_CLASS_CON, 76, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementCode },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AnnouncementList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   AnnouncementList_sequence, hf_index, ett_ansi_map_AnnouncementList);

  return offset;
}



static int
dissect_ansi_map_CallingPartyNumberString1(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_CallingPartyNumberString2(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_DisplayText(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_DisplayText2(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_DMH_AccountCodeDigits(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_DMH_AlternateBillingDigits(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_DMH_BillingDigits(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}


static const value_string ansi_map_DMH_RedirectionIndicator_vals[] = {
  {   0, "not-specified" },
  {   1, "cfu" },
  {   2, "cfb" },
  {   3, "cfna" },
  {   4, "cfo" },
  {   5, "cd-Unspecified" },
  {   6, "cd-PSTN" },
  {   7, "cd-Private" },
  {   8, "pstn-Tandem" },
  {   9, "private" },
  {  10, "busy" },
  {  11, "inactive" },
  {  12, "unassigned" },
  {  13, "termination-denied" },
  {  14, "cd-failure" },
  {  15, "ect" },
  {  16, "mah" },
  {  17, "fa" },
  {  18, "abandoned-call-leg" },
  {  19, "pca-call-refused" },
  {  20, "sca-call-refused" },
  {  21, "dialogue" },
  {  22, "cfd" },
  {  23, "cd-local" },
  {  24, "voice-mail-retrieval" },
  { 0, NULL }
};

static value_string_ext ansi_map_DMH_RedirectionIndicator_vals_ext = VALUE_STRING_EXT_INIT(ansi_map_DMH_RedirectionIndicator_vals);


static int
dissect_ansi_map_DMH_RedirectionIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_GroupInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_NoAnswerTime(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_PACAIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_pacaindicator(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_PilotNumber(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_PreferredLanguageIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_RedirectingNumberDigits(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_RedirectingNumberString(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_RedirectingSubaddress(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_Subaddress(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}


static const value_string ansi_map_ResumePIC_vals[] = {
  {   1, "continue-Call-Processing" },
  {   2, "collect-Information-PIC" },
  {   3, "analyze-Information-PIC" },
  {   4, "select-Route-PIC" },
  {   5, "authorize-Origination-Attempt-PIC" },
  {   6, "authorize-Call-Setup-PIC" },
  {   7, "send-Call-PIC" },
  {   8, "o-Alerting-PIC" },
  {   9, "o-Active-PIC" },
  {  10, "o-Suspended-PIC" },
  {  11, "o-Null-PIC" },
  {  32, "select-Facility-PIC" },
  {  33, "present-Call-PIC" },
  {  34, "authorize-Termination-Attempt-PIC" },
  {  35, "t-Alerting-PIC" },
  {  36, "t-Active-PIC" },
  {  37, "t-Suspended-PIC" },
  {  38, "t-Null-PIC" },
  { 0, NULL }
};


static int
dissect_ansi_map_ResumePIC(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_LegInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_TerminationTriggers(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_terminationtriggers(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}


static const ber_sequence_t IntersystemTermination_sequence[] = {
  { &hf_ansi_map_destinationDigits, BER_CLASS_CON, 87, BER_FLAGS_IMPLTAG, dissect_ansi_map_DestinationDigits },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_legInformation, BER_CLASS_CON, 144, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LegInformation },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_IntersystemTermination(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   IntersystemTermination_sequence, hf_index, ett_ansi_map_IntersystemTermination);

  return offset;
}



static int
dissect_ansi_map_TerminationTreatment(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_VoiceMailboxPIN(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_VoiceMailboxNumber(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}


static const ber_sequence_t LocalTermination_sequence[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_terminationTreatment, BER_CLASS_CON, 121, BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTreatment },
  { &hf_ansi_map_alertCode  , BER_CLASS_CON, 75, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AlertCode },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_destinationDigits, BER_CLASS_CON, 87, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DestinationDigits },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_legInformation, BER_CLASS_CON, 144, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LegInformation },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_voiceMailboxPIN, BER_CLASS_CON, 159, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoiceMailboxPIN },
  { &hf_ansi_map_voiceMailboxNumber, BER_CLASS_CON, 160, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoiceMailboxNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_LocalTermination(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   LocalTermination_sequence, hf_index, ett_ansi_map_LocalTermination);

  return offset;
}


static const ber_sequence_t PSTNTermination_sequence[] = {
  { &hf_ansi_map_destinationDigits, BER_CLASS_CON, 87, BER_FLAGS_IMPLTAG, dissect_ansi_map_DestinationDigits },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_legInformation, BER_CLASS_CON, 144, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LegInformation },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_PSTNTermination(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   PSTNTermination_sequence, hf_index, ett_ansi_map_PSTNTermination);

  return offset;
}


static const value_string ansi_map_TerminationList_item_vals[] = {
  {  89, "intersystemTermination" },
  {  91, "localTermination" },
  {  95, "pstnTermination" },
  { 0, NULL }
};

static const ber_choice_t TerminationList_item_choice[] = {
  {  89, &hf_ansi_map_intersystemTermination, BER_CLASS_CON, 89, BER_FLAGS_IMPLTAG, dissect_ansi_map_IntersystemTermination },
  {  91, &hf_ansi_map_localTermination, BER_CLASS_CON, 91, BER_FLAGS_IMPLTAG, dissect_ansi_map_LocalTermination },
  {  95, &hf_ansi_map_pstnTermination, BER_CLASS_CON, 95, BER_FLAGS_IMPLTAG, dissect_ansi_map_PSTNTermination },
  { 0, NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TerminationList_item(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 TerminationList_item_choice, hf_index, ett_ansi_map_TerminationList_item,
                                 NULL);

  return offset;
}


static const ber_sequence_t TerminationList_set_of[1] = {
  { &hf_ansi_map_TerminationList_item, BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_TerminationList_item },
};

static int
dissect_ansi_map_TerminationList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
                                 TerminationList_set_of, hf_index, ett_ansi_map_TerminationList);

  return offset;
}



static int
dissect_ansi_map_GlobalTitle(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string ansi_map_DestinationAddress_vals[] = {
  { 261, "globalTitle" },
  {  32, "pC-SSN" },
  { 0, NULL }
};

static const ber_choice_t DestinationAddress_choice[] = {
  { 261, &hf_ansi_map_globalTitle, BER_CLASS_CON, 261, BER_FLAGS_IMPLTAG, dissect_ansi_map_GlobalTitle },
  {  32, &hf_ansi_map_pC_SSN     , BER_CLASS_CON, 32, BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { 0, NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_DestinationAddress(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 DestinationAddress_choice, hf_index, ett_ansi_map_DestinationAddress,
                                 NULL);

  return offset;
}



static int
dissect_ansi_map_WIN_TriggerList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_win_trigger_list(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}


static const ber_sequence_t TriggerList_set[] = {
  { &hf_ansi_map_destinationAddress, BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_DestinationAddress },
  { &hf_ansi_map_wIN_TriggerList, BER_CLASS_CON, 283, BER_FLAGS_IMPLTAG, dissect_ansi_map_WIN_TriggerList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TriggerList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              TriggerList_set, hf_index, ett_ansi_map_TriggerList);

  return offset;
}


static const ber_sequence_t TriggerAddressList_set[] = {
  { &hf_ansi_map_triggerList, BER_CLASS_CON, 278, BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerList },
  { &hf_ansi_map_triggerListOpt, BER_CLASS_CON, 278, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TriggerAddressList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              TriggerAddressList_set, hf_index, ett_ansi_map_TriggerAddressList);

  return offset;
}


static const ber_sequence_t FeatureRequestRes_U_set[] = {
  { &hf_ansi_map_featureResult, BER_CLASS_CON, 18, BER_FLAGS_IMPLTAG, dissect_ansi_map_FeatureResult },
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_actionCode , BER_CLASS_CON, 128, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ActionCode },
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_callingPartyNumberString1, BER_CLASS_CON, 82, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString1 },
  { &hf_ansi_map_callingPartyNumberString2, BER_CLASS_CON, 83, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_conferenceCallingIndicator, BER_CLASS_CON, 137, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConferenceCallingIndicator },
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_digits_Destination, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_displayText2, BER_CLASS_CON, 299, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText2 },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_dmh_RedirectionIndicator, BER_CLASS_CON, 88, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_RedirectionIndicator },
  { &hf_ansi_map_groupInformation, BER_CLASS_CON, 163, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GroupInformation },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_noAnswerTime, BER_CLASS_CON, 96, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NoAnswerTime },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_pACAIndicator, BER_CLASS_CON, 146, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PACAIndicator },
  { &hf_ansi_map_pilotNumber, BER_CLASS_CON, 168, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotNumber },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingNumberString, BER_CLASS_CON, 101, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberString },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_resumePIC  , BER_CLASS_CON, 266, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ResumePIC },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_terminationList, BER_CLASS_CON, 120, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationList },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_FeatureRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              FeatureRequestRes_U_set, hf_index, ett_ansi_map_FeatureRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_FeatureRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_FeatureRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_EmergencyServicesRoutingDigits(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}


static const ber_sequence_t FlashRequest_U_set[] = {
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_confidentialityModes, BER_CLASS_CON, 39, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConfidentialityModes },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_emergencyServicesRoutingDigits, BER_CLASS_CON, 239, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_EmergencyServicesRoutingDigits },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_FlashRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              FlashRequest_U_set, hf_index, ett_ansi_map_FlashRequest_U);

  return offset;
}



static int
dissect_ansi_map_FlashRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_FlashRequest_U);

  return offset;
}


static const ber_sequence_t HandoffBack_U_set[] = {
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_confidentialityModes, BER_CLASS_CON, 39, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConfidentialityModes },
  { &hf_ansi_map_handoffReason, BER_CLASS_CON, 30, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_HandoffReason },
  { &hf_ansi_map_handoffState, BER_CLASS_CON, 164, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_HandoffState },
  { &hf_ansi_map_signalingMessageEncryptionKey, BER_CLASS_CON, 45, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SignalingMessageEncryptionKey },
  { &hf_ansi_map_tdmaBurstIndicator, BER_CLASS_CON, 31, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABurstIndicator },
  { &hf_ansi_map_tdmaCallMode, BER_CLASS_CON, 29, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMACallMode },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { &hf_ansi_map_voicePrivacyMask, BER_CLASS_CON, 48, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoicePrivacyMask },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_HandoffBack_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              HandoffBack_U_set, hf_index, ett_ansi_map_HandoffBack_U);

  return offset;
}



static int
dissect_ansi_map_HandoffBack(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_HandoffBack_U);

  return offset;
}


static const ber_sequence_t HandoffBackRes_U_set[] = {
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_confidentialityModes, BER_CLASS_CON, 39, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConfidentialityModes },
  { &hf_ansi_map_tdmaBurstIndicator, BER_CLASS_CON, 31, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABurstIndicator },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_HandoffBackRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              HandoffBackRes_U_set, hf_index, ett_ansi_map_HandoffBackRes_U);

  return offset;
}



static int
dissect_ansi_map_HandoffBackRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_HandoffBackRes_U);

  return offset;
}


static const ber_sequence_t HandoffBack2_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_baseStationManufacturerCode, BER_CLASS_CON, 197, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BaseStationManufacturerCode },
  { &hf_ansi_map_cdma2000HandoffInvokeIOSData, BER_CLASS_CON, 356, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMA2000HandoffInvokeIOSData },
  { &hf_ansi_map_cdmaBandClassList, BER_CLASS_CON, 172, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMABandClassList },
  { &hf_ansi_map_cdmaCallMode, BER_CLASS_CON, 62, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMACallMode },
  { &hf_ansi_map_cdmaChannelData, BER_CLASS_CON, 63, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelData },
  { &hf_ansi_map_cdmaConnectionReferenceList, BER_CLASS_CON, 212, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAConnectionReferenceList },
  { &hf_ansi_map_cdmaMSMeasuredChannelIdentity, BER_CLASS_CON, 351, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAMSMeasuredChannelIdentity },
  { &hf_ansi_map_cdmaMobileProtocolRevision, BER_CLASS_CON, 66, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAMobileProtocolRevision },
  { &hf_ansi_map_cdmaServiceConfigurationRecord, BER_CLASS_CON, 174, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceConfigurationRecord },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_cdmaPrivateLongCodeMask, BER_CLASS_CON, 67, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPrivateLongCodeMask },
  { &hf_ansi_map_cdmaServingOneWayDelay, BER_CLASS_CON, 60, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServingOneWayDelay },
  { &hf_ansi_map_cdmaStationClassMark, BER_CLASS_CON, 59, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark },
  { &hf_ansi_map_cdmaStationClassMark2, BER_CLASS_CON, 177, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark2 },
  { &hf_ansi_map_cdmaTargetMAHOList, BER_CLASS_CON, 136, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMAHOList },
  { &hf_ansi_map_cdmaTargetMeasurementList, BER_CLASS_CON, 134, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMeasurementList },
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_confidentialityModes, BER_CLASS_CON, 39, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConfidentialityModes },
  { &hf_ansi_map_dataKey    , BER_CLASS_CON, 215, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataKey },
  { &hf_ansi_map_dataPrivacyParameters, BER_CLASS_CON, 216, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataPrivacyParameters },
  { &hf_ansi_map_handoffReason, BER_CLASS_CON, 30, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_HandoffReason },
  { &hf_ansi_map_handoffState, BER_CLASS_CON, 164, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_HandoffState },
  { &hf_ansi_map_interSwitchCount, BER_CLASS_CON, 7, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_InterSwitchCount },
  { &hf_ansi_map_ilspInformation, BER_CLASS_CON, 217, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ISLPInformation },
  { &hf_ansi_map_msLocation , BER_CLASS_CON, 70, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSLocation },
  { &hf_ansi_map_nampsCallMode, BER_CLASS_CON, 165, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSCallMode },
  { &hf_ansi_map_nampsChannelData, BER_CLASS_CON, 74, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSChannelData },
  { &hf_ansi_map_pdsnAddress, BER_CLASS_CON, 349, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PDSNAddress },
  { &hf_ansi_map_pdsnProtocolType, BER_CLASS_CON, 350, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PDSNProtocolType },
  { &hf_ansi_map_qosPriority, BER_CLASS_CON, 348, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_QoSPriority },
  { &hf_ansi_map_randomVariable, BER_CLASS_CON, 40, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariable },
  { &hf_ansi_map_signalingMessageEncryptionKey, BER_CLASS_CON, 45, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SignalingMessageEncryptionKey },
  { &hf_ansi_map_stationClassMark, BER_CLASS_CON, 18, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_StationClassMark },
  { &hf_ansi_map_systemOperatorCode, BER_CLASS_CON, 206, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemOperatorCode },
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { &hf_ansi_map_tdmaBandwidth, BER_CLASS_CON, 220, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABandwidth },
  { &hf_ansi_map_tdmaBurstIndicator, BER_CLASS_CON, 31, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABurstIndicator },
  { &hf_ansi_map_tdmaCallMode, BER_CLASS_CON, 29, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMACallMode },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_tdmaTerminalCapability, BER_CLASS_CON, 179, BER_FLAGS_OPTIONAL, dissect_ansi_map_TDMATerminalCapability },
  { &hf_ansi_map_tdmaVoiceCoder, BER_CLASS_CON, 180, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAVoiceCoder },
  { &hf_ansi_map_terminalType, BER_CLASS_CON, 47, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminalType },
  { &hf_ansi_map_voicePrivacyMask, BER_CLASS_CON, 48, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoicePrivacyMask },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_HandoffBack2_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              HandoffBack2_U_set, hf_index, ett_ansi_map_HandoffBack2_U);

  return offset;
}



static int
dissect_ansi_map_HandoffBack2(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_HandoffBack2_U);

  return offset;
}


static const ber_sequence_t HandoffBack2Res_U_set[] = {
  { &hf_ansi_map_bsmcstatus , BER_CLASS_CON, 198, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BSMCStatus },
  { &hf_ansi_map_cdma2000HandoffResponseIOSData, BER_CLASS_CON, 357, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMA2000HandoffResponseIOSData },
  { &hf_ansi_map_cdmaChannelData, BER_CLASS_CON, 63, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelData },
  { &hf_ansi_map_cdmaCodeChannelList, BER_CLASS_CON, 132, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMACodeChannelList },
  { &hf_ansi_map_cdmaSearchParameters, BER_CLASS_CON, 230, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMASearchParameters },
  { &hf_ansi_map_cdmaConnectionReferenceList, BER_CLASS_CON, 212, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAConnectionReferenceList },
  { &hf_ansi_map_cdmaSearchWindow, BER_CLASS_CON, 69, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMASearchWindow },
  { &hf_ansi_map_cdmaServiceConfigurationRecord, BER_CLASS_CON, 174, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceConfigurationRecord },
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_confidentialityModes, BER_CLASS_CON, 39, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConfidentialityModes },
  { &hf_ansi_map_nampsChannelData, BER_CLASS_CON, 74, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSChannelData },
  { &hf_ansi_map_sOCStatus  , BER_CLASS_CON, 205, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SOCStatus },
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { &hf_ansi_map_tdmaBurstIndicator, BER_CLASS_CON, 31, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABurstIndicator },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { &hf_ansi_map_tdmaVoiceCoder, BER_CLASS_CON, 180, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAVoiceCoder },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_HandoffBack2Res_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              HandoffBack2Res_U_set, hf_index, ett_ansi_map_HandoffBack2Res_U);

  return offset;
}



static int
dissect_ansi_map_HandoffBack2Res(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_HandoffBack2Res_U);

  return offset;
}


static const ber_sequence_t TargetCellIDList_sequence[] = {
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { &hf_ansi_map_targetCellID1, BER_CLASS_CON, 3, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TargetCellIDList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   TargetCellIDList_sequence, hf_index, ett_ansi_map_TargetCellIDList);

  return offset;
}


static const ber_sequence_t HandoffMeasurementRequest_U_set[] = {
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_stationClassMark, BER_CLASS_CON, 18, BER_FLAGS_IMPLTAG, dissect_ansi_map_StationClassMark },
  { &hf_ansi_map_targetCellIDList, BER_CLASS_CON, 207, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellIDList },
  { &hf_ansi_map_tdmaCallMode, BER_CLASS_CON, 29, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMACallMode },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { &hf_ansi_map_tdmaTerminalCapability, BER_CLASS_CON, 179, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMATerminalCapability },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_HandoffMeasurementRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              HandoffMeasurementRequest_U_set, hf_index, ett_ansi_map_HandoffMeasurementRequest_U);

  return offset;
}



static int
dissect_ansi_map_HandoffMeasurementRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_HandoffMeasurementRequest_U);

  return offset;
}


static const value_string ansi_map_SignalQuality_vals[] = {
  {   0, "not-a-usable-signal" },
  {   1, "treat-as-Not-a-usable-signal" },
  {   2, "treat-as-Not-a-usable-signal" },
  {   3, "treat-as-Not-a-usable-signal" },
  {   4, "treat-as-Not-a-usable-signal" },
  {   5, "treat-as-Not-a-usable-signal" },
  {   6, "treat-as-Not-a-usable-signal" },
  {   7, "treat-as-Not-a-usable-signal" },
  {   8, "treat-as-Not-a-usable-signal" },
  {   9, "usable-signal-range" },
  { 245, "usable-signal-range" },
  { 246, "treat-the-same-as-interference" },
  { 247, "treat-the-same-as-interference" },
  { 248, "treat-the-same-as-interference" },
  { 249, "treat-the-same-as-interference" },
  { 250, "treat-the-same-as-interference" },
  { 251, "treat-the-same-as-interference" },
  { 252, "treat-the-same-as-interference" },
  { 253, "treat-the-same-as-interference" },
  { 254, "treat-the-same-as-interference" },
  { 255, "interference" },
  { 0, NULL }
};

static value_string_ext ansi_map_SignalQuality_vals_ext = VALUE_STRING_EXT_INIT(ansi_map_SignalQuality_vals);


static int
dissect_ansi_map_SignalQuality(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}


static const ber_sequence_t HandoffMeasurementRequestRes_U_set[] = {
  { &hf_ansi_map_signalQuality, BER_CLASS_CON, 11, BER_FLAGS_IMPLTAG, dissect_ansi_map_SignalQuality },
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_HandoffMeasurementRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              HandoffMeasurementRequestRes_U_set, hf_index, ett_ansi_map_HandoffMeasurementRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_HandoffMeasurementRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_HandoffMeasurementRequestRes_U);

  return offset;
}


static const ber_sequence_t HandoffMeasurementRequest2_U_set[] = {
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_cdmaCallMode, BER_CLASS_CON, 62, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMACallMode },
  { &hf_ansi_map_cdmaChannelData, BER_CLASS_CON, 63, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelData },
  { &hf_ansi_map_cdmaServiceConfigurationRecord, BER_CLASS_CON, 174, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceConfigurationRecord },
  { &hf_ansi_map_cdmaServingOneWayDelay, BER_CLASS_CON, 60, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServingOneWayDelay },
  { &hf_ansi_map_cdmaStationClassMark, BER_CLASS_CON, 59, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark },
  { &hf_ansi_map_cdmaStationClassMark2, BER_CLASS_CON, 177, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark2 },
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_msLocation , BER_CLASS_CON, 70, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSLocation },
  { &hf_ansi_map_nampsCallMode, BER_CLASS_CON, 165, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSCallMode },
  { &hf_ansi_map_nampsChannelData, BER_CLASS_CON, 74, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSChannelData },
  { &hf_ansi_map_stationClassMark, BER_CLASS_CON, 18, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_StationClassMark },
  { &hf_ansi_map_targetCellIDList, BER_CLASS_CON, 207, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellIDList },
  { &hf_ansi_map_tdmaBandwidth, BER_CLASS_CON, 220, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABandwidth },
  { &hf_ansi_map_tdmaCallMode, BER_CLASS_CON, 29, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMACallMode },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_tdmaTerminalCapability, BER_CLASS_CON, 179, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMATerminalCapability },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_HandoffMeasurementRequest2_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              HandoffMeasurementRequest2_U_set, hf_index, ett_ansi_map_HandoffMeasurementRequest2_U);

  return offset;
}



static int
dissect_ansi_map_HandoffMeasurementRequest2(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_HandoffMeasurementRequest2_U);

  return offset;
}


static const ber_sequence_t TargetMeasurementInformation_sequence[] = {
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { &hf_ansi_map_signalQuality, BER_CLASS_CON, 11, BER_FLAGS_IMPLTAG, dissect_ansi_map_SignalQuality },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TargetMeasurementInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   TargetMeasurementInformation_sequence, hf_index, ett_ansi_map_TargetMeasurementInformation);

  return offset;
}


static const ber_sequence_t TargetMeasurementList_sequence_of[1] = {
  { &hf_ansi_map_TargetMeasurementList_item, BER_CLASS_CON, 157, BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetMeasurementInformation },
};

static int
dissect_ansi_map_TargetMeasurementList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      TargetMeasurementList_sequence_of, hf_index, ett_ansi_map_TargetMeasurementList);

  return offset;
}


static const ber_sequence_t HandoffMeasurementRequest2Res_U_set[] = {
  { &hf_ansi_map_cdmaTargetMeasurementList, BER_CLASS_CON, 134, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMeasurementList },
  { &hf_ansi_map_targetMeasurementList, BER_CLASS_CON, 157, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetMeasurementList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_HandoffMeasurementRequest2Res_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              HandoffMeasurementRequest2Res_U_set, hf_index, ett_ansi_map_HandoffMeasurementRequest2Res_U);

  return offset;
}



static int
dissect_ansi_map_HandoffMeasurementRequest2Res(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_HandoffMeasurementRequest2Res_U);

  return offset;
}


static const ber_sequence_t HandoffToThird_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_interSwitchCount, BER_CLASS_CON, 7, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterSwitchCount },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_baseStationManufacturerCode, BER_CLASS_CON, 197, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BaseStationManufacturerCode },
  { &hf_ansi_map_stationClassMark, BER_CLASS_CON, 18, BER_FLAGS_IMPLTAG, dissect_ansi_map_StationClassMark },
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { &hf_ansi_map_cdmaBandClassList, BER_CLASS_CON, 172, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMABandClassList },
  { &hf_ansi_map_cdmaCallMode, BER_CLASS_CON, 62, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMACallMode },
  { &hf_ansi_map_cdmaChannelData, BER_CLASS_CON, 63, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelData },
  { &hf_ansi_map_cdmaMobileProtocolRevision, BER_CLASS_CON, 66, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAMobileProtocolRevision },
  { &hf_ansi_map_cdmaPrivateLongCodeMask, BER_CLASS_CON, 67, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPrivateLongCodeMask },
  { &hf_ansi_map_cdmaServiceConfigurationRecord, BER_CLASS_CON, 174, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceConfigurationRecord },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_cdmaServingOneWayDelay, BER_CLASS_CON, 60, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServingOneWayDelay },
  { &hf_ansi_map_cdmaStationClassMark, BER_CLASS_CON, 59, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark },
  { &hf_ansi_map_cdmaStationClassMark2, BER_CLASS_CON, 177, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark2 },
  { &hf_ansi_map_cdmaTargetMAHOList, BER_CLASS_CON, 136, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMAHOList },
  { &hf_ansi_map_cdmaTargetMeasurementList, BER_CLASS_CON, 134, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMeasurementList },
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_confidentialityModes, BER_CLASS_CON, 39, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConfidentialityModes },
  { &hf_ansi_map_handoffReason, BER_CLASS_CON, 30, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_HandoffReason },
  { &hf_ansi_map_handoffState, BER_CLASS_CON, 164, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_HandoffState },
  { &hf_ansi_map_msLocation , BER_CLASS_CON, 70, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSLocation },
  { &hf_ansi_map_nampsCallMode, BER_CLASS_CON, 165, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSCallMode },
  { &hf_ansi_map_nampsChannelData, BER_CLASS_CON, 74, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSChannelData },
  { &hf_ansi_map_signalingMessageEncryptionKey, BER_CLASS_CON, 45, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SignalingMessageEncryptionKey },
  { &hf_ansi_map_tdmaBurstIndicator, BER_CLASS_CON, 31, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABurstIndicator },
  { &hf_ansi_map_tdmaCallMode, BER_CLASS_CON, 29, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMACallMode },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_tdmaTerminalCapability, BER_CLASS_CON, 179, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMATerminalCapability },
  { &hf_ansi_map_tdmaVoiceCoder, BER_CLASS_CON, 180, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAVoiceCoder },
  { &hf_ansi_map_terminalType, BER_CLASS_CON, 47, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminalType },
  { &hf_ansi_map_voicePrivacyMask, BER_CLASS_CON, 48, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoicePrivacyMask },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_HandoffToThird_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              HandoffToThird_U_set, hf_index, ett_ansi_map_HandoffToThird_U);

  return offset;
}



static int
dissect_ansi_map_HandoffToThird(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_HandoffToThird_U);

  return offset;
}


static const ber_sequence_t HandoffToThirdRes_U_set[] = {
  { &hf_ansi_map_cdmaChannelData, BER_CLASS_CON, 63, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelData },
  { &hf_ansi_map_cdmaCodeChannelList, BER_CLASS_CON, 132, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMACodeChannelList },
  { &hf_ansi_map_cdmaSearchWindow, BER_CLASS_CON, 69, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMASearchWindow },
  { &hf_ansi_map_cdmaServiceConfigurationRecord, BER_CLASS_CON, 174, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceConfigurationRecord },
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_confidentialityModes, BER_CLASS_CON, 39, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConfidentialityModes },
  { &hf_ansi_map_nampsChannelData, BER_CLASS_CON, 74, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSChannelData },
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { &hf_ansi_map_tdmaBurstIndicator, BER_CLASS_CON, 31, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABurstIndicator },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { &hf_ansi_map_tdmaVoiceCoder, BER_CLASS_CON, 180, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAVoiceCoder },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_HandoffToThirdRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              HandoffToThirdRes_U_set, hf_index, ett_ansi_map_HandoffToThirdRes_U);

  return offset;
}



static int
dissect_ansi_map_HandoffToThirdRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_HandoffToThirdRes_U);

  return offset;
}


static const ber_sequence_t HandoffToThird2_U_set[] = {
  { &hf_ansi_map_bsmcstatus , BER_CLASS_CON, 198, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BSMCStatus },
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_interSwitchCount, BER_CLASS_CON, 7, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterSwitchCount },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { &hf_ansi_map_cdma2000HandoffInvokeIOSData, BER_CLASS_CON, 356, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMA2000HandoffInvokeIOSData },
  { &hf_ansi_map_cdmaCallMode, BER_CLASS_CON, 62, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMACallMode },
  { &hf_ansi_map_cdmaChannelData, BER_CLASS_CON, 63, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelData },
  { &hf_ansi_map_cdmaConnectionReferenceList, BER_CLASS_CON, 212, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAConnectionReferenceList },
  { &hf_ansi_map_cdmaMSMeasuredChannelIdentity, BER_CLASS_CON, 351, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAMSMeasuredChannelIdentity },
  { &hf_ansi_map_cdmaMobileProtocolRevision, BER_CLASS_CON, 66, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAMobileProtocolRevision },
  { &hf_ansi_map_cdmaPrivateLongCodeMask, BER_CLASS_CON, 67, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPrivateLongCodeMask },
  { &hf_ansi_map_cdmaServiceConfigurationRecord, BER_CLASS_CON, 174, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceConfigurationRecord },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_cdmaServingOneWayDelay, BER_CLASS_CON, 60, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServingOneWayDelay },
  { &hf_ansi_map_cdmaStationClassMark, BER_CLASS_CON, 59, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark },
  { &hf_ansi_map_cdmaStationClassMark2, BER_CLASS_CON, 177, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark2 },
  { &hf_ansi_map_cdmaTargetMAHOList, BER_CLASS_CON, 136, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMAHOList },
  { &hf_ansi_map_cdmaTargetMeasurementList, BER_CLASS_CON, 134, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMeasurementList },
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_confidentialityModes, BER_CLASS_CON, 39, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConfidentialityModes },
  { &hf_ansi_map_dataKey    , BER_CLASS_CON, 215, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataKey },
  { &hf_ansi_map_dataPrivacyParameters, BER_CLASS_CON, 216, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataPrivacyParameters },
  { &hf_ansi_map_handoffReason, BER_CLASS_CON, 30, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_HandoffReason },
  { &hf_ansi_map_ilspInformation, BER_CLASS_CON, 217, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ISLPInformation },
  { &hf_ansi_map_msLocation , BER_CLASS_CON, 70, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSLocation },
  { &hf_ansi_map_nampsCallMode, BER_CLASS_CON, 165, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSCallMode },
  { &hf_ansi_map_nampsChannelData, BER_CLASS_CON, 74, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSChannelData },
  { &hf_ansi_map_pdsnAddress, BER_CLASS_CON, 349, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PDSNAddress },
  { &hf_ansi_map_pdsnProtocolType, BER_CLASS_CON, 350, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PDSNProtocolType },
  { &hf_ansi_map_qosPriority, BER_CLASS_CON, 348, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_QoSPriority },
  { &hf_ansi_map_randomVariable, BER_CLASS_CON, 40, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariable },
  { &hf_ansi_map_sOCStatus  , BER_CLASS_CON, 205, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SOCStatus },
  { &hf_ansi_map_signalingMessageEncryptionKey, BER_CLASS_CON, 45, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SignalingMessageEncryptionKey },
  { &hf_ansi_map_stationClassMark, BER_CLASS_CON, 18, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_StationClassMark },
  { &hf_ansi_map_tdmaBandwidth, BER_CLASS_CON, 220, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABandwidth },
  { &hf_ansi_map_tdmaBurstIndicator, BER_CLASS_CON, 31, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABurstIndicator },
  { &hf_ansi_map_tdmaCallMode, BER_CLASS_CON, 29, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMACallMode },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_tdmaTerminalCapability, BER_CLASS_CON, 179, BER_FLAGS_OPTIONAL, dissect_ansi_map_TDMATerminalCapability },
  { &hf_ansi_map_tdmaVoiceCoder, BER_CLASS_CON, 180, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAVoiceCoder },
  { &hf_ansi_map_userZoneData, BER_CLASS_CON, 209, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UserZoneData },
  { &hf_ansi_map_voicePrivacyMask, BER_CLASS_CON, 48, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoicePrivacyMask },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_HandoffToThird2_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              HandoffToThird2_U_set, hf_index, ett_ansi_map_HandoffToThird2_U);

  return offset;
}



static int
dissect_ansi_map_HandoffToThird2(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_HandoffToThird2_U);

  return offset;
}


static const ber_sequence_t HandoffToThird2Res_U_set[] = {
  { &hf_ansi_map_cdma2000HandoffResponseIOSData, BER_CLASS_CON, 357, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMA2000HandoffResponseIOSData },
  { &hf_ansi_map_cdmaChannelData, BER_CLASS_CON, 63, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelData },
  { &hf_ansi_map_cdmaCodeChannelList, BER_CLASS_CON, 132, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMACodeChannelList },
  { &hf_ansi_map_cdmaConnectionReferenceList, BER_CLASS_CON, 212, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAConnectionReferenceList },
  { &hf_ansi_map_cdmaSearchParameters, BER_CLASS_CON, 230, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMASearchParameters },
  { &hf_ansi_map_cdmaSearchWindow, BER_CLASS_CON, 69, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMASearchWindow },
  { &hf_ansi_map_cdmaServiceConfigurationRecord, BER_CLASS_CON, 174, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceConfigurationRecord },
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_confidentialityModes, BER_CLASS_CON, 39, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConfidentialityModes },
  { &hf_ansi_map_nampsChannelData, BER_CLASS_CON, 74, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSChannelData },
  { &hf_ansi_map_targetCellID, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetCellID },
  { &hf_ansi_map_tdmaBurstIndicator, BER_CLASS_CON, 31, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABurstIndicator },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { &hf_ansi_map_tdmaVoiceCoder, BER_CLASS_CON, 180, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAVoiceCoder },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_HandoffToThird2Res_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              HandoffToThird2Res_U_set, hf_index, ett_ansi_map_HandoffToThird2Res_U);

  return offset;
}



static int
dissect_ansi_map_HandoffToThird2Res(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_HandoffToThird2Res_U);

  return offset;
}


static const ber_sequence_t InformationDirective_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_alertCode  , BER_CLASS_CON, 75, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AlertCode },
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_callingPartyNumberString1, BER_CLASS_CON, 82, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString1 },
  { &hf_ansi_map_callingPartyNumberString2, BER_CLASS_CON, 83, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_displayText2, BER_CLASS_CON, 299, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText2 },
  { &hf_ansi_map_redirectingNumberString, BER_CLASS_CON, 101, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberString },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InformationDirective_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InformationDirective_U_set, hf_index, ett_ansi_map_InformationDirective_U);

  return offset;
}



static int
dissect_ansi_map_InformationDirective(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InformationDirective_U);

  return offset;
}



static int
dissect_ansi_map_AlertResult(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t InformationDirectiveRes_U_set[] = {
  { &hf_ansi_map_alertResult, BER_CLASS_CON, 129, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AlertResult },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InformationDirectiveRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InformationDirectiveRes_U_set, hf_index, ett_ansi_map_InformationDirectiveRes_U);

  return offset;
}



static int
dissect_ansi_map_InformationDirectiveRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InformationDirectiveRes_U);

  return offset;
}



static int
dissect_ansi_map_MessageWaitingNotificationCount(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_messagewaitingnotificationcount(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_MessageWaitingNotificationType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_messagewaitingnotificationtype(parameter_tvb,actx->pinfo,tree, actx);
	}



  return offset;
}


static const ber_sequence_t InformationForward_U_set[] = {
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_alertCode  , BER_CLASS_CON, 75, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AlertCode },
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_callingPartyNumberString1, BER_CLASS_CON, 82, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString1 },
  { &hf_ansi_map_callingPartyNumberString2, BER_CLASS_CON, 83, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_displayText2, BER_CLASS_CON, 299, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText2 },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_messageWaitingNotificationCount, BER_CLASS_CON, 92, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MessageWaitingNotificationCount },
  { &hf_ansi_map_messageWaitingNotificationType, BER_CLASS_CON, 145, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MessageWaitingNotificationType },
  { &hf_ansi_map_redirectingNumberString, BER_CLASS_CON, 101, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberString },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InformationForward_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InformationForward_U_set, hf_index, ett_ansi_map_InformationForward_U);

  return offset;
}



static int
dissect_ansi_map_InformationForward(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InformationForward_U);

  return offset;
}


static const ber_sequence_t InformationForwardRes_U_set[] = {
  { &hf_ansi_map_alertResult, BER_CLASS_CON, 129, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AlertResult },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InformationForwardRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InformationForwardRes_U_set, hf_index, ett_ansi_map_InformationForwardRes_U);

  return offset;
}



static int
dissect_ansi_map_InformationForwardRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InformationForwardRes_U);

  return offset;
}


static const ber_sequence_t InterSystemAnswer_U_set[] = {
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InterSystemAnswer_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InterSystemAnswer_U_set, hf_index, ett_ansi_map_InterSystemAnswer_U);

  return offset;
}



static int
dissect_ansi_map_InterSystemAnswer(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InterSystemAnswer_U);

  return offset;
}



static int
dissect_ansi_map_CDMASlotCycleIndex(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_ExtendedMSCID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_extendedmscid(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_ExtendedSystemMyTypeCode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_extendedsystemmytypecode(parameter_tvb, actx->pinfo, tree, actx);
	}

  return offset;
}



static int
dissect_ansi_map_MSIDUsage(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_NetworkTMSI(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_PageCount(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_PageIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_PageResponseTime(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_PilotBillingID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {

	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_pilotbillingid(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_RedirectingPartyName(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_TDMADataFeaturesIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t InterSystemPage_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_alertCode  , BER_CLASS_CON, 75, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AlertCode },
  { &hf_ansi_map_callingPartyName, BER_CLASS_CON, 243, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyName },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_callingPartyNumberDigits2, BER_CLASS_CON, 81, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits2 },
  { &hf_ansi_map_callingPartyNumberString1, BER_CLASS_CON, 82, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString1 },
  { &hf_ansi_map_callingPartyNumberString2, BER_CLASS_CON, 83, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_cdmaBandClass, BER_CLASS_CON, 170, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMABandClass },
  { &hf_ansi_map_cdmaMobileProtocolRevision, BER_CLASS_CON, 66, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAMobileProtocolRevision },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_cdmaSlotCycleIndex, BER_CLASS_CON, 166, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMASlotCycleIndex },
  { &hf_ansi_map_cdmaStationClassMark, BER_CLASS_CON, 59, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark },
  { &hf_ansi_map_cdmaStationClassMark2, BER_CLASS_CON, 177, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark2 },
  { &hf_ansi_map_controlChannelMode, BER_CLASS_CON, 199, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlChannelMode },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_displayText2, BER_CLASS_CON, 299, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText2 },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_extendedMSCID, BER_CLASS_CON, 53, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ExtendedMSCID },
  { &hf_ansi_map_extendedSystemMyTypeCode, BER_CLASS_CON, 54, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ExtendedSystemMyTypeCode },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_legInformation, BER_CLASS_CON, 144, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LegInformation },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_mSIDUsage  , BER_CLASS_CON, 327, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSIDUsage },
  { &hf_ansi_map_networkTMSI, BER_CLASS_CON, 233, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NetworkTMSI },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_pageCount  , BER_CLASS_CON, 300, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PageCount },
  { &hf_ansi_map_pageIndicator, BER_CLASS_CON, 71, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PageIndicator },
  { &hf_ansi_map_pageResponseTime, BER_CLASS_CON, 301, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PageResponseTime },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_pilotBillingID, BER_CLASS_CON, 169, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotBillingID },
  { &hf_ansi_map_pilotNumber, BER_CLASS_CON, 168, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotNumber },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingNumberString, BER_CLASS_CON, 101, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberString },
  { &hf_ansi_map_redirectingPartyName, BER_CLASS_CON, 245, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingPartyName },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_tdmaDataFeaturesIndicator, BER_CLASS_CON, 221, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMADataFeaturesIndicator },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_terminalType, BER_CLASS_CON, 47, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminalType },
  { &hf_ansi_map_terminationTreatment, BER_CLASS_CON, 121, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTreatment },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InterSystemPage_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InterSystemPage_U_set, hf_index, ett_ansi_map_InterSystemPage_U);

  return offset;
}



static int
dissect_ansi_map_InterSystemPage(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InterSystemPage_U);

  return offset;
}


static const value_string ansi_map_ConditionallyDeniedReason_vals[] = {
  {   0, "not-used" },
  {   1, "waitable" },
  { 0, NULL }
};


static int
dissect_ansi_map_ConditionallyDeniedReason(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t InterSystemPageRes_U_set[] = {
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_conditionallyDeniedReason, BER_CLASS_CON, 162, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConditionallyDeniedReason },
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_extendedMSCID, BER_CLASS_CON, 53, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ExtendedMSCID },
  { &hf_ansi_map_extendedSystemMyTypeCode, BER_CLASS_CON, 54, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ExtendedSystemMyTypeCode },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InterSystemPageRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InterSystemPageRes_U_set, hf_index, ett_ansi_map_InterSystemPageRes_U);

  return offset;
}



static int
dissect_ansi_map_InterSystemPageRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InterSystemPageRes_U);

  return offset;
}



static int
dissect_ansi_map_PagingFrameClass(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_PSID_RSIDInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t PSID_RSIDList_sequence[] = {
  { &hf_ansi_map_pSID_RSIDInformation, BER_CLASS_CON, 202, BER_FLAGS_IMPLTAG, dissect_ansi_map_PSID_RSIDInformation },
  { &hf_ansi_map_pSID_RSIDInformation1, BER_CLASS_CON, 202, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PSID_RSIDInformation },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_PSID_RSIDList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   PSID_RSIDList_sequence, hf_index, ett_ansi_map_PSID_RSIDList);

  return offset;
}


static const ber_sequence_t InterSystemPage2_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_alertCode  , BER_CLASS_CON, 75, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AlertCode },
  { &hf_ansi_map_callingPartyNumberString1, BER_CLASS_CON, 82, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString1 },
  { &hf_ansi_map_callingPartyNumberString2, BER_CLASS_CON, 83, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_cdmaBandClass, BER_CLASS_CON, 170, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMABandClass },
  { &hf_ansi_map_cdmaMobileProtocolRevision, BER_CLASS_CON, 66, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAMobileProtocolRevision },
  { &hf_ansi_map_controlChannelMode, BER_CLASS_CON, 199, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlChannelMode },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_cdmaSlotCycleIndex, BER_CLASS_CON, 166, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMASlotCycleIndex },
  { &hf_ansi_map_cdmaStationClassMark, BER_CLASS_CON, 59, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark },
  { &hf_ansi_map_cdmaStationClassMark2, BER_CLASS_CON, 177, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark2 },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_displayText2, BER_CLASS_CON, 299, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText2 },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_mSIDUsage  , BER_CLASS_CON, 327, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSIDUsage },
  { &hf_ansi_map_networkTMSI, BER_CLASS_CON, 233, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NetworkTMSI },
  { &hf_ansi_map_nonPublicData, BER_CLASS_CON, 200, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NonPublicData },
  { &hf_ansi_map_pageCount  , BER_CLASS_CON, 300, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PageCount },
  { &hf_ansi_map_pageIndicator, BER_CLASS_CON, 71, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PageIndicator },
  { &hf_ansi_map_pagingFrameClass, BER_CLASS_CON, 210, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PagingFrameClass },
  { &hf_ansi_map_pageResponseTime, BER_CLASS_CON, 301, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PageResponseTime },
  { &hf_ansi_map_pSID_RSIDList, BER_CLASS_CON, 203, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PSID_RSIDList },
  { &hf_ansi_map_redirectingNumberString, BER_CLASS_CON, 101, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberString },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_tdmaDataFeaturesIndicator, BER_CLASS_CON, 221, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMADataFeaturesIndicator },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_terminalType, BER_CLASS_CON, 47, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminalType },
  { &hf_ansi_map_userZoneData, BER_CLASS_CON, 209, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UserZoneData },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InterSystemPage2_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InterSystemPage2_U_set, hf_index, ett_ansi_map_InterSystemPage2_U);

  return offset;
}



static int
dissect_ansi_map_InterSystemPage2(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InterSystemPage2_U);

  return offset;
}



static int
dissect_ansi_map_RANDC(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_TDMADataMode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t InterSystemPage2Res_U_set[] = {
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_authenticationResponseBaseStation, BER_CLASS_CON, 36, BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationResponseBaseStation },
  { &hf_ansi_map_callHistoryCount, BER_CLASS_CON, 38, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallHistoryCount },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_randc      , BER_CLASS_CON, 67, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RANDC },
  { &hf_ansi_map_randomVariableBaseStation, BER_CLASS_CON, 41, BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariableBaseStation },
  { &hf_ansi_map_systemAccessType, BER_CLASS_CON, 34, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemAccessType },
  { &hf_ansi_map_systemCapabilities, BER_CLASS_CON, 49, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemCapabilities },
  { &hf_ansi_map_tdmaDataMode, BER_CLASS_CON, 222, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMADataMode },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_terminalType, BER_CLASS_CON, 47, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminalType },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InterSystemPage2Res_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InterSystemPage2Res_U_set, hf_index, ett_ansi_map_InterSystemPage2Res_U);

  return offset;
}



static int
dissect_ansi_map_InterSystemPage2Res(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InterSystemPage2Res_U);

  return offset;
}



static int
dissect_ansi_map_ChangeServiceAttributes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t InterSystemSetup_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_alertCode  , BER_CLASS_CON, 75, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AlertCode },
  { &hf_ansi_map_callingPartyNumberString1, BER_CLASS_CON, 82, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString1 },
  { &hf_ansi_map_callingPartyNumberString2, BER_CLASS_CON, 83, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_cdmaPrivateLongCodeMask, BER_CLASS_CON, 67, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPrivateLongCodeMask },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_changeServiceAttributes, BER_CLASS_CON, 214, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ChangeServiceAttributes },
  { &hf_ansi_map_dataKey    , BER_CLASS_CON, 215, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataKey },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_displayText2, BER_CLASS_CON, 299, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText2 },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_ilspInformation, BER_CLASS_CON, 217, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ISLPInformation },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_redirectingNumberString, BER_CLASS_CON, 101, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberString },
  { &hf_ansi_map_edirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_signalingMessageEncryptionKey, BER_CLASS_CON, 45, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SignalingMessageEncryptionKey },
  { &hf_ansi_map_voicePrivacyMask, BER_CLASS_CON, 48, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoicePrivacyMask },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InterSystemSetup_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InterSystemSetup_U_set, hf_index, ett_ansi_map_InterSystemSetup_U);

  return offset;
}



static int
dissect_ansi_map_InterSystemSetup(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InterSystemSetup_U);

  return offset;
}



static int
dissect_ansi_map_SetupResult(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t InterSystemSetupRes_U_set[] = {
  { &hf_ansi_map_cdmaConnectionReferenceList, BER_CLASS_CON, 212, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAConnectionReferenceList },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_ilspInformation, BER_CLASS_CON, 217, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ISLPInformation },
  { &hf_ansi_map_setupResult, BER_CLASS_CON, 151, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SetupResult },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InterSystemSetupRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InterSystemSetupRes_U_set, hf_index, ett_ansi_map_InterSystemSetupRes_U);

  return offset;
}



static int
dissect_ansi_map_InterSystemSetupRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InterSystemSetupRes_U);

  return offset;
}



static int
dissect_ansi_map_TerminationAccessType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string ansi_map_TriggerType_vals[] = {
  {   1, "all-Calls" },
  {   2, "double-Introducing-Star" },
  {   3, "single-Introducing-Star" },
  {   4, "reserved-for-Home-System-Feature-Code" },
  {   5, "double-Introducing-Pound" },
  {   6, "single-Introducing-Pound" },
  {   7, "revertive-Call" },
  {   8, "a0-Digit" },
  {   9, "a1-Digit" },
  {  10, "a2-Digit" },
  {  11, "a3-Digit" },
  {  12, "a4-Digit" },
  {  13, "a5-Digit" },
  {  14, "a6-Digit" },
  {  15, "a7-Digit" },
  {  16, "a8-Digit" },
  {  17, "a9-Digit" },
  {  18, "a10-Digit" },
  {  19, "a11-Digit" },
  {  20, "a12-Digit" },
  {  21, "a13-Digit" },
  {  22, "a14-Digit" },
  {  23, "a15-Digit" },
  {  24, "local-Call" },
  {  25, "intra-LATA-Toll-Call" },
  {  26, "inter-LATA-Toll-Call" },
  {  27, "world-Zone-Call" },
  {  28, "international-Call" },
  {  29, "unrecognized-Number" },
  {  30, "prior-Agreement" },
  {  31, "specific-Called-Party-Digit-String" },
  {  32, "mobile-Termination" },
  {  33, "advanced-Termination" },
  {  34, "location" },
  {  35, "locally-Allowed-Specific-Digit-String" },
  {  36, "origination-Attempt-Authorized" },
  {  37, "calling-Routing-Address-Available" },
  {  38, "initial-Termination" },
  {  39, "called-Routing-Address-Available" },
  {  40, "o-Answer" },
  {  41, "o-Disconnect" },
  {  42, "o-Called-Party-Busy" },
  {  43, "o-No-Answer" },
  {  64, "terminating-Resource-Available" },
  {  65, "t-Busy" },
  {  66, "t-No-Answer" },
  {  67, "t-No-Page-Response" },
  {  68, "t-Routable" },
  {  69, "t-Answer" },
  {  70, "t-Disconnect" },
  { 220, "reserved-for-TDP-R-DP-Type-value" },
  { 221, "reserved-for-TDP-N-DP-Type-value" },
  { 222, "reserved-for-EDP-R-DP-Type-value" },
  { 223, "reserved-for-EDP-N-DP-Type-value" },
  { 0, NULL }
};

static value_string_ext ansi_map_TriggerType_vals_ext = VALUE_STRING_EXT_INIT(ansi_map_TriggerType_vals);


static int
dissect_ansi_map_TriggerType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_TriggerCapability(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_triggercapability(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_WINOperationsCapability(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_winoperationscapability(parameter_tvb,actx->pinfo,tree, actx);
	}

  return offset;
}


static const ber_sequence_t WINCapability_set[] = {
  { &hf_ansi_map_triggerCapability, BER_CLASS_CON, 277, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerCapability },
  { &hf_ansi_map_wINOperationsCapability, BER_CLASS_CON, 281, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_WINOperationsCapability },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_WINCapability(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              WINCapability_set, hf_index, ett_ansi_map_WINCapability);

  return offset;
}



static int
dissect_ansi_map_CallingPartyCategory(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t LocationRequest_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_acgencountered, BER_CLASS_CON, 340, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ACGEncountered },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_callingPartyNumberDigits2, BER_CLASS_CON, 81, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingPartyName, BER_CLASS_CON, 245, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingPartyName },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_terminationAccessType, BER_CLASS_CON, 119, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationAccessType },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_triggerType, BER_CLASS_CON, 279, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerType },
  { &hf_ansi_map_winCapability, BER_CLASS_CON, 280, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_WINCapability },
  { &hf_ansi_map_callingPartyCategory, BER_CLASS_CON, 355, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyCategory },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_LocationRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              LocationRequest_U_set, hf_index, ett_ansi_map_LocationRequest_U);

  return offset;
}



static int
dissect_ansi_map_LocationRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_LocationRequest_U);

  return offset;
}



static int
dissect_ansi_map_ControlNetworkID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_controlnetworkid(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_DMH_ServiceID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t LocationRequestRes_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_callingPartyNumberString1, BER_CLASS_CON, 82, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString1 },
  { &hf_ansi_map_callingPartyNumberString2, BER_CLASS_CON, 83, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString2 },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_controlNetworkID, BER_CLASS_CON, 307, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlNetworkID },
  { &hf_ansi_map_digits_carrier, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_digits_dest, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_displayText2, BER_CLASS_CON, 299, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText2 },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_dmh_RedirectionIndicator, BER_CLASS_CON, 88, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_RedirectionIndicator },
  { &hf_ansi_map_dmh_ServiceID, BER_CLASS_CON, 305, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ServiceID },
  { &hf_ansi_map_groupInformation, BER_CLASS_CON, 163, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GroupInformation },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_noAnswerTime, BER_CLASS_CON, 96, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NoAnswerTime },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingNumberString, BER_CLASS_CON, 101, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberString },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_terminationList, BER_CLASS_CON, 120, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationList },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_LocationRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              LocationRequestRes_U_set, hf_index, ett_ansi_map_LocationRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_LocationRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_LocationRequestRes_U);

  return offset;
}


static const value_string ansi_map_DeregistrationType_vals[] = {
  {   0, "not-used" },
  {   1, "deregister-for-an-unspecified-reason" },
  {   2, "deregister-for-an-administrative-reason" },
  {   3, "deregister-due-to-MS-power-down" },
  { 0, NULL }
};


static int
dissect_ansi_map_DeregistrationType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_ServicesResult(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_SMS_MessageWaitingIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);

  return offset;
}


static const ber_sequence_t MSInactive_U_set[] = {
  { &hf_ansi_map_lectronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_callHistoryCount, BER_CLASS_CON, 38, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallHistoryCount },
  { &hf_ansi_map_deregistrationType, BER_CLASS_CON, 73, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DeregistrationType },
  { &hf_ansi_map_destinationDigits, BER_CLASS_CON, 87, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DestinationDigits },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_servicesResult, BER_CLASS_CON, 204, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServicesResult },
  { &hf_ansi_map_sms_MessageWaitingIndicator, BER_CLASS_CON, 118, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_MessageWaitingIndicator },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_MSInactive_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              MSInactive_U_set, hf_index, ett_ansi_map_MSInactive_U);

  return offset;
}



static int
dissect_ansi_map_MSInactive(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_MSInactive_U);

  return offset;
}


static const value_string ansi_map_FeatureIndicator_vals[] = {
  {   0, "not-used" },
  {  38, "user-selective-call-forwarding" },
  { 0, NULL }
};


static int
dissect_ansi_map_FeatureIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_AuthenticationCapability(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CallingFeaturesIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_callingfeaturesindicator(parameter_tvb,actx->pinfo,tree, actx);
	}

  return offset;
}



static int
dissect_ansi_map_GeographicAuthorization(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_MEIDValidated(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);

  return offset;
}



static int
dissect_ansi_map_MobilePositionCapability(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string ansi_map_OriginationIndicator_vals[] = {
  {   0, "not-used" },
  {   1, "prior-agreement" },
  {   2, "origination-denied" },
  {   3, "local-calls-only" },
  {   4, "selected-leading-digits-of-directorynumber-or-of-international-E164-number" },
  {   5, "selected-leading-digits-of-directorynumber-or-of-international-E164-number-and-local-calls-only" },
  {   6, "national-long-distance" },
  {   7, "international-calls" },
  {   8, "single-directory-number-or-international-E164-number" },
  { 0, NULL }
};


static int
dissect_ansi_map_OriginationIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_OriginationTriggers(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_originationtriggers(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_RestrictionDigits(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_SMS_OriginationRestrictions(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_sms_originationrestrictions(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_SMS_TerminationRestrictions(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_SPINIPIN(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_SPINITriggers(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string ansi_map_TerminationRestrictionCode_vals[] = {
  {   0, "not-used" },
  {   1, "termination-denied" },
  {   2, "unrestricted" },
  {   3, "the-treatment-for-this-value-is-not-specified" },
  { 0, NULL }
};


static int
dissect_ansi_map_TerminationRestrictionCode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_UserGroup(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string ansi_map_LIRMode_vals[] = {
  {   0, "not-used" },
  {   1, "unconditionally-Restricted" },
  {   2, "pre-Authorized-LCS-Clients-Only" },
  {   3, "pre-Authorized-LCS-Clients-and-User-Authorized-LCS-Clients" },
  {   4, "unrestricted" },
  { 0, NULL }
};


static int
dissect_ansi_map_LIRMode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_CDMAMobileCapabilities(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_CDMAServingOneWayDelay2(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t CDMAPSMMList_item_set[] = {
  { &hf_ansi_map_cdmaServingOneWayDelay2, BER_CLASS_CON, 347, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServingOneWayDelay2 },
  { &hf_ansi_map_cdmaTargetMAHOList, BER_CLASS_CON, 136, BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMAHOList },
  { &hf_ansi_map_cdmaTargetMAHOList2, BER_CLASS_CON, 136, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMAHOList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CDMAPSMMList_item(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              CDMAPSMMList_item_set, hf_index, ett_ansi_map_CDMAPSMMList_item);

  return offset;
}


static const ber_sequence_t CDMAPSMMList_set_of[1] = {
  { &hf_ansi_map_CDMAPSMMList_item, BER_CLASS_UNI, BER_UNI_TAG_SET, BER_FLAGS_NOOWNTAG, dissect_ansi_map_CDMAPSMMList_item },
};

static int
dissect_ansi_map_CDMAPSMMList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
                                 CDMAPSMMList_set_of, hf_index, ett_ansi_map_CDMAPSMMList);

  return offset;
}



static int
dissect_ansi_map_MPCAddress(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}


static const ber_sequence_t OriginationRequest_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_acgencountered, BER_CLASS_CON, 340, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ACGEncountered },
  { &hf_ansi_map_callingPartyName, BER_CLASS_CON, 243, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyName },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_callingPartyNumberDigits2, BER_CLASS_CON, 81, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_featureIndicator, BER_CLASS_CON, 306, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_FeatureIndicator },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_triggerType, BER_CLASS_CON, 279, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerType },
  { &hf_ansi_map_winCapability, BER_CLASS_CON, 280, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_WINCapability },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { &hf_ansi_map_authenticationCapability, BER_CLASS_CON, 78, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationCapability },
  { &hf_ansi_map_callingFeaturesIndicator, BER_CLASS_CON, 25, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingFeaturesIndicator },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_controlNetworkID, BER_CLASS_CON, 307, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlNetworkID },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_geographicAuthorization, BER_CLASS_CON, 143, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GeographicAuthorization },
  { &hf_ansi_map_meidValidated, BER_CLASS_CON, 401, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEIDValidated },
  { &hf_ansi_map_messageWaitingNotificationCount, BER_CLASS_CON, 92, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MessageWaitingNotificationCount },
  { &hf_ansi_map_messageWaitingNotificationType, BER_CLASS_CON, 145, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MessageWaitingNotificationType },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mobilePositionCapability, BER_CLASS_CON, 335, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobilePositionCapability },
  { &hf_ansi_map_originationIndicator, BER_CLASS_CON, 23, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OriginationIndicator },
  { &hf_ansi_map_originationTriggers, BER_CLASS_CON, 98, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OriginationTriggers },
  { &hf_ansi_map_pACAIndicator, BER_CLASS_CON, 146, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PACAIndicator },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_qosPriority, BER_CLASS_CON, 348, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_QoSPriority },
  { &hf_ansi_map_restrictionDigits, BER_CLASS_CON, 227, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RestrictionDigits },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_pSID_RSIDList, BER_CLASS_CON, 203, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PSID_RSIDList },
  { &hf_ansi_map_sms_OriginationRestrictions, BER_CLASS_CON, 115, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginationRestrictions },
  { &hf_ansi_map_sms_TerminationRestrictions, BER_CLASS_CON, 117, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_TerminationRestrictions },
  { &hf_ansi_map_spinipin   , BER_CLASS_CON, 154, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SPINIPIN },
  { &hf_ansi_map_spiniTriggers, BER_CLASS_CON, 155, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SPINITriggers },
  { &hf_ansi_map_tdmaDataFeaturesIndicator, BER_CLASS_CON, 221, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMADataFeaturesIndicator },
  { &hf_ansi_map_terminationRestrictionCode, BER_CLASS_CON, 24, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationRestrictionCode },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { &hf_ansi_map_userGroup  , BER_CLASS_CON, 208, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UserGroup },
  { &hf_ansi_map_nonPublicData, BER_CLASS_CON, 200, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NonPublicData },
  { &hf_ansi_map_userZoneData, BER_CLASS_CON, 209, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UserZoneData },
  { &hf_ansi_map_callingPartyCategory, BER_CLASS_CON, 355, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyCategory },
  { &hf_ansi_map_lirMode    , BER_CLASS_CON, 369, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LIRMode },
  { &hf_ansi_map_cdmaChannelData, BER_CLASS_CON, 63, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelData },
  { &hf_ansi_map_cdmaCodeChannel, BER_CLASS_CON, 68, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMACodeChannel },
  { &hf_ansi_map_cdmaMobileCapabilities, BER_CLASS_CON, 330, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAMobileCapabilities },
  { &hf_ansi_map_cdmaPrivateLongCodeMask, BER_CLASS_CON, 67, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPrivateLongCodeMask },
  { &hf_ansi_map_cdmaServingOneWayDelay2, BER_CLASS_CON, 347, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServingOneWayDelay2 },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_cdmaTargetMAHOList, BER_CLASS_CON, 136, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMAHOList },
  { &hf_ansi_map_cdmaPSMMList, BER_CLASS_CON, 346, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPSMMList },
  { &hf_ansi_map_mpcAddress , BER_CLASS_CON, 370, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MPCAddress },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_OriginationRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              OriginationRequest_U_set, hf_index, ett_ansi_map_OriginationRequest_U);

  return offset;
}



static int
dissect_ansi_map_OriginationRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_OriginationRequest_U);

  return offset;
}



static int
dissect_ansi_map_DMH_ChargeInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t OriginationRequestRes_U_set[] = {
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_actionCode , BER_CLASS_CON, 128, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ActionCode },
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_callingPartyNumberString1, BER_CLASS_CON, 82, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString1 },
  { &hf_ansi_map_callingPartyNumberString2, BER_CLASS_CON, 83, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_displayText2, BER_CLASS_CON, 299, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText2 },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_dmh_ChargeInformation, BER_CLASS_CON, 311, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ChargeInformation },
  { &hf_ansi_map_dmh_RedirectionIndicator, BER_CLASS_CON, 88, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_RedirectionIndicator },
  { &hf_ansi_map_dmh_ServiceID, BER_CLASS_CON, 305, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ServiceID },
  { &hf_ansi_map_groupInformation, BER_CLASS_CON, 163, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GroupInformation },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_noAnswerTime, BER_CLASS_CON, 96, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NoAnswerTime },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_pilotNumber, BER_CLASS_CON, 168, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotNumber },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingNumberString, BER_CLASS_CON, 101, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberString },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_resumePIC  , BER_CLASS_CON, 266, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ResumePIC },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_terminationList, BER_CLASS_CON, 120, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationList },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_OriginationRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              OriginationRequestRes_U_set, hf_index, ett_ansi_map_OriginationRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_OriginationRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_OriginationRequestRes_U);

  return offset;
}


static const value_string ansi_map_QualificationInformationCode_vals[] = {
  {   0, "not-used" },
  {   1, "no-information" },
  {   2, "validation-only" },
  {   3, "validation-and-profile" },
  {   4, "profile-only" },
  { 0, NULL }
};


static int
dissect_ansi_map_QualificationInformationCode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const value_string ansi_map_AuthorizationDenied_vals[] = {
  {   0, "not-used" },
  {   1, "delinquent-account" },
  {   2, "invalid-serial-number" },
  {   3, "stolen-unit" },
  {   4, "duplicate-unit" },
  {   5, "unassigned-directory-number" },
  {   6, "unspecified" },
  {   7, "multiple-access" },
  {   8, "not-Authorized-for-the-MSC" },
  {   9, "missing-authentication-parameters" },
  {  10, "terminalType-mismatch" },
  {  11, "requested-Service-Code-Not-Supported" },
  { 0, NULL }
};


static int
dissect_ansi_map_AuthorizationDenied(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_AuthorizationPeriod(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_authorizationperiod(parameter_tvb,actx->pinfo,tree, actx);
	}



  return offset;
}



static int
dissect_ansi_map_DeniedAuthorizationPeriod(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_deniedauthorizationperiod(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}


static const ber_sequence_t QualificationDirective_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_qualificationInformationCode, BER_CLASS_CON, 17, BER_FLAGS_IMPLTAG, dissect_ansi_map_QualificationInformationCode },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_analogRedirectRecord, BER_CLASS_CON, 225, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnalogRedirectRecord },
  { &hf_ansi_map_authorizationDenied, BER_CLASS_CON, 13, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthorizationDenied },
  { &hf_ansi_map_authorizationPeriod, BER_CLASS_CON, 14, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthorizationPeriod },
  { &hf_ansi_map_cdmaRedirectRecord, BER_CLASS_CON, 229, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMARedirectRecord },
  { &hf_ansi_map_controlChannelMode, BER_CLASS_CON, 199, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlChannelMode },
  { &hf_ansi_map_deniedAuthorizationPeriod, BER_CLASS_CON, 167, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DeniedAuthorizationPeriod },
  { &hf_ansi_map_digits_carrier, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_digits_dest, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_authenticationCapability, BER_CLASS_CON, 78, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationCapability },
  { &hf_ansi_map_callingFeaturesIndicator, BER_CLASS_CON, 25, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingFeaturesIndicator },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_controlNetworkID, BER_CLASS_CON, 307, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlNetworkID },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_geographicAuthorization, BER_CLASS_CON, 143, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GeographicAuthorization },
  { &hf_ansi_map_meidValidated, BER_CLASS_CON, 401, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEIDValidated },
  { &hf_ansi_map_messageWaitingNotificationCount, BER_CLASS_CON, 92, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MessageWaitingNotificationCount },
  { &hf_ansi_map_messageWaitingNotificationType, BER_CLASS_CON, 145, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MessageWaitingNotificationType },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mobilePositionCapability, BER_CLASS_CON, 335, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobilePositionCapability },
  { &hf_ansi_map_originationIndicator, BER_CLASS_CON, 23, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OriginationIndicator },
  { &hf_ansi_map_originationTriggers, BER_CLASS_CON, 98, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OriginationTriggers },
  { &hf_ansi_map_pACAIndicator, BER_CLASS_CON, 146, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PACAIndicator },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_qosPriority, BER_CLASS_CON, 348, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_QoSPriority },
  { &hf_ansi_map_restrictionDigits, BER_CLASS_CON, 227, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RestrictionDigits },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_pSID_RSIDList, BER_CLASS_CON, 203, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PSID_RSIDList },
  { &hf_ansi_map_sms_OriginationRestrictions, BER_CLASS_CON, 115, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginationRestrictions },
  { &hf_ansi_map_sms_TerminationRestrictions, BER_CLASS_CON, 117, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_TerminationRestrictions },
  { &hf_ansi_map_spinipin   , BER_CLASS_CON, 154, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SPINIPIN },
  { &hf_ansi_map_spiniTriggers, BER_CLASS_CON, 155, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SPINITriggers },
  { &hf_ansi_map_tdmaDataFeaturesIndicator, BER_CLASS_CON, 221, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMADataFeaturesIndicator },
  { &hf_ansi_map_terminationRestrictionCode, BER_CLASS_CON, 24, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationRestrictionCode },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { &hf_ansi_map_userGroup  , BER_CLASS_CON, 208, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UserGroup },
  { &hf_ansi_map_nonPublicData, BER_CLASS_CON, 200, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NonPublicData },
  { &hf_ansi_map_userZoneData, BER_CLASS_CON, 209, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UserZoneData },
  { &hf_ansi_map_callingPartyCategory, BER_CLASS_CON, 355, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyCategory },
  { &hf_ansi_map_lirMode    , BER_CLASS_CON, 369, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LIRMode },
  { &hf_ansi_map_serviceRedirectionInfo, BER_CLASS_CON, 238, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceRedirectionInfo },
  { &hf_ansi_map_roamingIndication, BER_CLASS_CON, 239, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoamingIndication },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_QualificationDirective_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              QualificationDirective_U_set, hf_index, ett_ansi_map_QualificationDirective_U);

  return offset;
}



static int
dissect_ansi_map_QualificationDirective(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_QualificationDirective_U);

  return offset;
}


static const ber_sequence_t QualificationDirectiveRes_U_set[] = {
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_QualificationDirectiveRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              QualificationDirectiveRes_U_set, hf_index, ett_ansi_map_QualificationDirectiveRes_U);

  return offset;
}



static int
dissect_ansi_map_QualificationDirectiveRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_QualificationDirectiveRes_U);

  return offset;
}


static const ber_sequence_t QualificationRequest_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_qualificationInformationCode, BER_CLASS_CON, 17, BER_FLAGS_IMPLTAG, dissect_ansi_map_QualificationInformationCode },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_cdmaNetworkIdentification, BER_CLASS_CON, 232, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMANetworkIdentification },
  { &hf_ansi_map_controlChannelMode, BER_CLASS_CON, 199, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlChannelMode },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_systemAccessType, BER_CLASS_CON, 34, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemAccessType },
  { &hf_ansi_map_terminalType, BER_CLASS_CON, 47, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminalType },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_winCapability, BER_CLASS_CON, 280, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_WINCapability },
  { &hf_ansi_map_nonPublicData, BER_CLASS_CON, 200, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NonPublicData },
  { &hf_ansi_map_userZoneData, BER_CLASS_CON, 209, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UserZoneData },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_QualificationRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              QualificationRequest_U_set, hf_index, ett_ansi_map_QualificationRequest_U);

  return offset;
}



static int
dissect_ansi_map_QualificationRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_QualificationRequest_U);

  return offset;
}


static const ber_sequence_t QualificationRequestRes_U_set[] = {
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_analogRedirectRecord, BER_CLASS_CON, 225, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnalogRedirectRecord },
  { &hf_ansi_map_authorizationDenied, BER_CLASS_CON, 13, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthorizationDenied },
  { &hf_ansi_map_authorizationPeriod, BER_CLASS_CON, 14, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthorizationPeriod },
  { &hf_ansi_map_cdmaRedirectRecord, BER_CLASS_CON, 229, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMARedirectRecord },
  { &hf_ansi_map_controlChannelMode, BER_CLASS_CON, 199, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlChannelMode },
  { &hf_ansi_map_deniedAuthorizationPeriod, BER_CLASS_CON, 167, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DeniedAuthorizationPeriod },
  { &hf_ansi_map_digits_carrier, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_digits_dest, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_authenticationCapability, BER_CLASS_CON, 78, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationCapability },
  { &hf_ansi_map_callingFeaturesIndicator, BER_CLASS_CON, 25, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingFeaturesIndicator },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_controlNetworkID, BER_CLASS_CON, 307, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlNetworkID },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_geographicAuthorization, BER_CLASS_CON, 143, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GeographicAuthorization },
  { &hf_ansi_map_meidValidated, BER_CLASS_CON, 401, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEIDValidated },
  { &hf_ansi_map_messageWaitingNotificationCount, BER_CLASS_CON, 92, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MessageWaitingNotificationCount },
  { &hf_ansi_map_messageWaitingNotificationType, BER_CLASS_CON, 145, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MessageWaitingNotificationType },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mobilePositionCapability, BER_CLASS_CON, 335, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobilePositionCapability },
  { &hf_ansi_map_originationIndicator, BER_CLASS_CON, 23, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OriginationIndicator },
  { &hf_ansi_map_originationTriggers, BER_CLASS_CON, 98, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OriginationTriggers },
  { &hf_ansi_map_pACAIndicator, BER_CLASS_CON, 146, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PACAIndicator },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_restrictionDigits, BER_CLASS_CON, 227, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RestrictionDigits },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_sms_OriginationRestrictions, BER_CLASS_CON, 115, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginationRestrictions },
  { &hf_ansi_map_sms_TerminationRestrictions, BER_CLASS_CON, 117, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_TerminationRestrictions },
  { &hf_ansi_map_spinipin   , BER_CLASS_CON, 154, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SPINIPIN },
  { &hf_ansi_map_spiniTriggers, BER_CLASS_CON, 155, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SPINITriggers },
  { &hf_ansi_map_terminationRestrictionCode, BER_CLASS_CON, 24, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationRestrictionCode },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { &hf_ansi_map_callingPartyCategory, BER_CLASS_CON, 355, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyCategory },
  { &hf_ansi_map_lirMode    , BER_CLASS_CON, 369, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LIRMode },
  { &hf_ansi_map_serviceRedirectionInfo, BER_CLASS_CON, 238, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceRedirectionInfo },
  { &hf_ansi_map_roamingIndication, BER_CLASS_CON, 239, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoamingIndication },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_QualificationRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              QualificationRequestRes_U_set, hf_index, ett_ansi_map_QualificationRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_QualificationRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_QualificationRequestRes_U);

  return offset;
}


static const ber_sequence_t RandomVariableRequest_U_set[] = {
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_randc      , BER_CLASS_CON, 67, BER_FLAGS_IMPLTAG, dissect_ansi_map_RANDC },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_RandomVariableRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              RandomVariableRequest_U_set, hf_index, ett_ansi_map_RandomVariableRequest_U);

  return offset;
}



static int
dissect_ansi_map_RandomVariableRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_RandomVariableRequest_U);

  return offset;
}



static int
dissect_ansi_map_RANDValidTime(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t RandomVariableRequestRes_U_set[] = {
  { &hf_ansi_map_randomVariable, BER_CLASS_CON, 40, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariable },
  { &hf_ansi_map_randValidTime, BER_CLASS_CON, 148, BER_FLAGS_IMPLTAG, dissect_ansi_map_RANDValidTime },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_RandomVariableRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              RandomVariableRequestRes_U_set, hf_index, ett_ansi_map_RandomVariableRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_RandomVariableRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_RandomVariableRequestRes_U);

  return offset;
}


static const ber_sequence_t RedirectionDirective_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_digits_dest, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_digits_carrier, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_redirectingNumberString, BER_CLASS_CON, 101, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberString },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_RedirectionDirective_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              RedirectionDirective_U_set, hf_index, ett_ansi_map_RedirectionDirective_U);

  return offset;
}



static int
dissect_ansi_map_RedirectionDirective(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_RedirectionDirective_U);

  return offset;
}


static const value_string ansi_map_RedirectionReason_vals[] = {
  {   0, "not-used" },
  {   1, "busy" },
  {   2, "no-Answer" },
  {   3, "unconditional" },
  {   4, "no-Page-Response" },
  {   5, "unavailable" },
  {   6, "unroutable" },
  {   7, "call-accepted" },
  {   8, "call-refused" },
  {   9, "uSCFvm-Divert-to-voice-mail" },
  {  10, "uSCFms-Divert-to-an-MS-provided-DN" },
  {  11, "uSCFnr-Divert-to-a-network-registered-DN" },
  { 0, NULL }
};


static int
dissect_ansi_map_RedirectionReason(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t RedirectionRequest_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_redirectionReason, BER_CLASS_CON, 19, BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectionReason },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_legInformation, BER_CLASS_CON, 144, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LegInformation },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_RedirectionRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              RedirectionRequest_U_set, hf_index, ett_ansi_map_RedirectionRequest_U);

  return offset;
}



static int
dissect_ansi_map_RedirectionRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_RedirectionRequest_U);

  return offset;
}



static int
dissect_ansi_map_CancellationType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_ControlChannelData(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	tvbuff_t *parameter_tvb = NULL;
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		dissect_ansi_map_controlchanneldata(parameter_tvb,actx->pinfo,tree, actx);
	}


  return offset;
}



static int
dissect_ansi_map_ReceivedSignalQuality(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}



static int
dissect_ansi_map_SystemAccessData(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t RegistrationCancellation_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_cancellationType, BER_CLASS_CON, 85, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CancellationType },
  { &hf_ansi_map_controlChannelData, BER_CLASS_CON, 55, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlChannelData },
  { &hf_ansi_map_receivedSignalQuality, BER_CLASS_CON, 72, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReceivedSignalQuality },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_systemAccessData, BER_CLASS_CON, 56, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemAccessData },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_RegistrationCancellation_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              RegistrationCancellation_U_set, hf_index, ett_ansi_map_RegistrationCancellation_U);

  return offset;
}



static int
dissect_ansi_map_RegistrationCancellation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_RegistrationCancellation_U);

  return offset;
}


static const value_string ansi_map_CancellationDenied_vals[] = {
  {   0, "not-used" },
  {   1, "multipleAccess" },
  {   2, "busy" },
  { 0, NULL }
};


static int
dissect_ansi_map_CancellationDenied(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t RegistrationCancellationRes_U_set[] = {
  { &hf_ansi_map_callHistoryCount, BER_CLASS_CON, 38, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallHistoryCount },
  { &hf_ansi_map_cancellationDenied, BER_CLASS_CON, 57, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CancellationDenied },
  { &hf_ansi_map_controlChannelData, BER_CLASS_CON, 55, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlChannelData },
  { &hf_ansi_map_receivedSignalQuality, BER_CLASS_CON, 72, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReceivedSignalQuality },
  { &hf_ansi_map_sms_MessageWaitingIndicator, BER_CLASS_CON, 118, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_MessageWaitingIndicator },
  { &hf_ansi_map_systemAccessData, BER_CLASS_CON, 56, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemAccessData },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_RegistrationCancellationRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              RegistrationCancellationRes_U_set, hf_index, ett_ansi_map_RegistrationCancellationRes_U);

  return offset;
}



static int
dissect_ansi_map_RegistrationCancellationRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_RegistrationCancellationRes_U);

  return offset;
}



static int
dissect_ansi_map_AvailabilityType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string ansi_map_BorderCellAccess_vals[] = {
  {   0, "not-used" },
  {   1, "border-Cell-Access" },
  { 0, NULL }
};


static int
dissect_ansi_map_BorderCellAccess(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_MSC_Address(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_SMS_Address(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}


static const ber_sequence_t MPCAddressList_set[] = {
  { &hf_ansi_map_mpcAddress , BER_CLASS_CON, 370, BER_FLAGS_IMPLTAG, dissect_ansi_map_MPCAddress },
  { &hf_ansi_map_mpcAddress2, BER_CLASS_CON, 370, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MPCAddress },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_MPCAddressList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              MPCAddressList_set, hf_index, ett_ansi_map_MPCAddressList);

  return offset;
}


static const ber_sequence_t RegistrationNotification_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_qualificationInformationCode, BER_CLASS_CON, 17, BER_FLAGS_IMPLTAG, dissect_ansi_map_QualificationInformationCode },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_availabilityType, BER_CLASS_CON, 90, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AvailabilityType },
  { &hf_ansi_map_borderCellAccess, BER_CLASS_CON, 58, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BorderCellAccess },
  { &hf_ansi_map_cdmaNetworkIdentification, BER_CLASS_CON, 232, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMANetworkIdentification },
  { &hf_ansi_map_controlChannelData, BER_CLASS_CON, 55, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlChannelData },
  { &hf_ansi_map_controlChannelMode, BER_CLASS_CON, 199, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlChannelMode },
  { &hf_ansi_map_extendedMSCID, BER_CLASS_CON, 53, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ExtendedMSCID },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_msc_Address, BER_CLASS_CON, 284, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSC_Address },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_receivedSignalQuality, BER_CLASS_CON, 72, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReceivedSignalQuality },
  { &hf_ansi_map_reportType , BER_CLASS_CON, 44, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReportType },
  { &hf_ansi_map_serviceRedirectionCause, BER_CLASS_CON, 237, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceRedirectionCause },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_sms_Address, BER_CLASS_CON, 104, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_Address },
  { &hf_ansi_map_sms_MessageWaitingIndicator, BER_CLASS_CON, 118, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_MessageWaitingIndicator },
  { &hf_ansi_map_systemAccessData, BER_CLASS_CON, 56, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemAccessData },
  { &hf_ansi_map_systemAccessType, BER_CLASS_CON, 34, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemAccessType },
  { &hf_ansi_map_systemCapabilities, BER_CLASS_CON, 49, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemCapabilities },
  { &hf_ansi_map_terminalType, BER_CLASS_CON, 47, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminalType },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_winCapability, BER_CLASS_CON, 280, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_WINCapability },
  { &hf_ansi_map_mpcAddress , BER_CLASS_CON, 370, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MPCAddress },
  { &hf_ansi_map_mpcAddressList, BER_CLASS_CON, 381, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MPCAddressList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_RegistrationNotification_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              RegistrationNotification_U_set, hf_index, ett_ansi_map_RegistrationNotification_U);

  return offset;
}



static int
dissect_ansi_map_RegistrationNotification(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_RegistrationNotification_U);

  return offset;
}


static const ber_sequence_t RegistrationNotificationRes_U_set[] = {
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_analogRedirectRecord, BER_CLASS_CON, 225, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnalogRedirectRecord },
  { &hf_ansi_map_authorizationDenied, BER_CLASS_CON, 13, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthorizationDenied },
  { &hf_ansi_map_authorizationPeriod, BER_CLASS_CON, 14, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthorizationPeriod },
  { &hf_ansi_map_cdmaRedirectRecord, BER_CLASS_CON, 229, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMARedirectRecord },
  { &hf_ansi_map_controlChannelData, BER_CLASS_CON, 55, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlChannelData },
  { &hf_ansi_map_deniedAuthorizationPeriod, BER_CLASS_CON, 167, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DeniedAuthorizationPeriod },
  { &hf_ansi_map_digits_Carrier, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_digits_Destination, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_authenticationCapability, BER_CLASS_CON, 78, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationCapability },
  { &hf_ansi_map_callingFeaturesIndicator, BER_CLASS_CON, 25, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingFeaturesIndicator },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_controlNetworkID, BER_CLASS_CON, 307, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlNetworkID },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_geographicAuthorization, BER_CLASS_CON, 143, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GeographicAuthorization },
  { &hf_ansi_map_meidValidated, BER_CLASS_CON, 401, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEIDValidated },
  { &hf_ansi_map_messageWaitingNotificationCount, BER_CLASS_CON, 92, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MessageWaitingNotificationCount },
  { &hf_ansi_map_messageWaitingNotificationType, BER_CLASS_CON, 145, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MessageWaitingNotificationType },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mobilePositionCapability, BER_CLASS_CON, 335, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobilePositionCapability },
  { &hf_ansi_map_originationIndicator, BER_CLASS_CON, 23, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OriginationIndicator },
  { &hf_ansi_map_originationTriggers, BER_CLASS_CON, 98, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OriginationTriggers },
  { &hf_ansi_map_pACAIndicator, BER_CLASS_CON, 146, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PACAIndicator },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_qosPriority, BER_CLASS_CON, 348, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_QoSPriority },
  { &hf_ansi_map_restrictionDigits, BER_CLASS_CON, 227, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RestrictionDigits },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_pSID_RSIDList, BER_CLASS_CON, 203, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PSID_RSIDList },
  { &hf_ansi_map_sms_OriginationRestrictions, BER_CLASS_CON, 115, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginationRestrictions },
  { &hf_ansi_map_sms_TerminationRestrictions, BER_CLASS_CON, 117, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_TerminationRestrictions },
  { &hf_ansi_map_spinipin   , BER_CLASS_CON, 154, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SPINIPIN },
  { &hf_ansi_map_spiniTriggers, BER_CLASS_CON, 155, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SPINITriggers },
  { &hf_ansi_map_tdmaDataFeaturesIndicator, BER_CLASS_CON, 221, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMADataFeaturesIndicator },
  { &hf_ansi_map_terminationRestrictionCode, BER_CLASS_CON, 24, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationRestrictionCode },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { &hf_ansi_map_userGroup  , BER_CLASS_CON, 208, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UserGroup },
  { &hf_ansi_map_nonPublicData, BER_CLASS_CON, 200, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NonPublicData },
  { &hf_ansi_map_userZoneData, BER_CLASS_CON, 209, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UserZoneData },
  { &hf_ansi_map_callingPartyCategory, BER_CLASS_CON, 355, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyCategory },
  { &hf_ansi_map_lirMode    , BER_CLASS_CON, 369, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LIRMode },
  { &hf_ansi_map_receivedSignalQuality, BER_CLASS_CON, 72, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReceivedSignalQuality },
  { &hf_ansi_map_serviceRedirectionInfo, BER_CLASS_CON, 238, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceRedirectionInfo },
  { &hf_ansi_map_roamingIndication, BER_CLASS_CON, 239, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoamingIndication },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_sms_MessageWaitingIndicator, BER_CLASS_CON, 118, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_MessageWaitingIndicator },
  { &hf_ansi_map_systemAccessData, BER_CLASS_CON, 56, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemAccessData },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_RegistrationNotificationRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              RegistrationNotificationRes_U_set, hf_index, ett_ansi_map_RegistrationNotificationRes_U);

  return offset;
}



static int
dissect_ansi_map_RegistrationNotificationRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_RegistrationNotificationRes_U);

  return offset;
}



static int
dissect_ansi_map_DigitCollectionControl(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t RemoteUserInteractionDirective_U_set[] = {
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_digitCollectionControl, BER_CLASS_CON, 139, BER_FLAGS_IMPLTAG, dissect_ansi_map_DigitCollectionControl },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_RemoteUserInteractionDirective_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              RemoteUserInteractionDirective_U_set, hf_index, ett_ansi_map_RemoteUserInteractionDirective_U);

  return offset;
}



static int
dissect_ansi_map_RemoteUserInteractionDirective(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_RemoteUserInteractionDirective_U);

  return offset;
}


static const ber_sequence_t RemoteUserInteractionDirectiveRes_U_set[] = {
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_RemoteUserInteractionDirectiveRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              RemoteUserInteractionDirectiveRes_U_set, hf_index, ett_ansi_map_RemoteUserInteractionDirectiveRes_U);

  return offset;
}



static int
dissect_ansi_map_RemoteUserInteractionDirectiveRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_RemoteUserInteractionDirectiveRes_U);

  return offset;
}


static const ber_sequence_t ResetCircuit_U_set[] = {
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ResetCircuit_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ResetCircuit_U_set, hf_index, ett_ansi_map_ResetCircuit_U);

  return offset;
}



static int
dissect_ansi_map_ResetCircuit(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ResetCircuit_U);

  return offset;
}


static const value_string ansi_map_TrunkStatus_vals[] = {
  {   0, "idle" },
  {   1, "blocked" },
  { 0, NULL }
};


static int
dissect_ansi_map_TrunkStatus(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t ResetCircuitRes_U_set[] = {
  { &hf_ansi_map_trunkStatus, BER_CLASS_CON, 16, BER_FLAGS_IMPLTAG, dissect_ansi_map_TrunkStatus },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ResetCircuitRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ResetCircuitRes_U_set, hf_index, ett_ansi_map_ResetCircuitRes_U);

  return offset;
}



static int
dissect_ansi_map_ResetCircuitRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ResetCircuitRes_U);

  return offset;
}


static const ber_sequence_t RoutingRequest_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_alertCode  , BER_CLASS_CON, 75, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AlertCode },
  { &hf_ansi_map_callingPartyName, BER_CLASS_CON, 243, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyName },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_callingPartyNumberDigits2, BER_CLASS_CON, 81, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits2 },
  { &hf_ansi_map_callingPartyNumberString1, BER_CLASS_CON, 82, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString1 },
  { &hf_ansi_map_callingPartyNumberString2, BER_CLASS_CON, 83, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_controlChannelMode, BER_CLASS_CON, 199, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlChannelMode },
  { &hf_ansi_map_destinationDigits, BER_CLASS_CON, 87, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DestinationDigits },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_displayText2, BER_CLASS_CON, 299, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText2 },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_legInformation, BER_CLASS_CON, 144, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LegInformation },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_noAnswerTime, BER_CLASS_CON, 96, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NoAnswerTime },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_pilotBillingID, BER_CLASS_CON, 169, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotBillingID },
  { &hf_ansi_map_pilotNumber, BER_CLASS_CON, 168, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotNumber },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingNumberString, BER_CLASS_CON, 101, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberString },
  { &hf_ansi_map_redirectingPartyName, BER_CLASS_CON, 245, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingPartyName },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_terminationTreatment, BER_CLASS_CON, 121, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTreatment },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { &hf_ansi_map_userGroup  , BER_CLASS_CON, 208, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UserGroup },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_voiceMailboxNumber, BER_CLASS_CON, 160, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoiceMailboxNumber },
  { &hf_ansi_map_voiceMailboxPIN, BER_CLASS_CON, 159, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoiceMailboxPIN },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_RoutingRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              RoutingRequest_U_set, hf_index, ett_ansi_map_RoutingRequest_U);

  return offset;
}



static int
dissect_ansi_map_RoutingRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_RoutingRequest_U);

  return offset;
}


static const ber_sequence_t RoutingRequestRes_U_set[] = {
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_conditionallyDeniedReason, BER_CLASS_CON, 162, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConditionallyDeniedReason },
  { &hf_ansi_map_digits_Destination, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_RoutingRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              RoutingRequestRes_U_set, hf_index, ett_ansi_map_RoutingRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_RoutingRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_RoutingRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_SMS_BearerData(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
	int length;
	SMS_BearerData_tvb = NULL;

  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &SMS_BearerData_tvb);

	if (SMS_BearerData_tvb){
		/* A zero length OCTET STRING will return a zero length tvb */
		length = tvb_reported_length_remaining(SMS_BearerData_tvb,0);
		if (length <=0){
			proto_item_append_text(actx->created_item," length %u",length);
			SMS_BearerData_tvb = NULL;
			return offset;
		}
		if (ansi_map_sms_tele_id != -1)
		{
			dissector_try_uint(is637_tele_id_dissector_table, ansi_map_sms_tele_id, SMS_BearerData_tvb, g_pinfo, g_tree);
		}
		else
		{
			switch(ServiceIndicator){
				case 1: /* CDMA OTASP Service */
				case 3: /* CDMA OTAPA Service */
					dissector_try_uint(is683_dissector_table, ansi_map_is_invoke ? 0 : 1, SMS_BearerData_tvb, g_pinfo, g_tree);
					break;
				case 4: /* CDMA Position Determination Service */
					dissector_try_uint(is801_dissector_table, ansi_map_is_invoke ? 0 : 1, SMS_BearerData_tvb, g_pinfo, g_tree);
					break;
				default:
					break;
			}
		}
	}


  return offset;
}



static int
dissect_ansi_map_SMS_TeleserviceIdentifier(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {

	int length;
	tvbuff_t *parameter_tvb = NULL;
	ansi_map_sms_tele_id = -1;

  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       &parameter_tvb);

	if (parameter_tvb){
		/* A zero length OCTET STRING will return a zero length tvb */
		length = tvb_reported_length_remaining(parameter_tvb,0);
		if (length <=0){
			proto_item_append_text(actx->created_item, " length %u",length);
			return offset;
		}
		ansi_map_sms_tele_id = tvb_get_ntohs(tvb,0);
		if ((ansi_map_sms_tele_id != -1)&&(SMS_BearerData_tvb !=NULL))
		{
		    dissector_try_uint(is637_tele_id_dissector_table, ansi_map_sms_tele_id, SMS_BearerData_tvb, g_pinfo, g_tree);
		}
	}


  return offset;
}



static int
dissect_ansi_map_SMS_ChargeIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_SMS_DestinationAddress(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_SMS_OriginalDestinationAddress(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_SMS_OriginalDestinationSubaddress(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_Subaddress(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_SMS_OriginalOriginatingAddress(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_SMS_OriginalOriginatingSubaddress(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_Subaddress(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_SMS_OriginatingAddress(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}


static const ber_sequence_t SMSDeliveryBackward_U_set[] = {
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_sms_BearerData, BER_CLASS_CON, 105, BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_BearerData },
  { &hf_ansi_map_sms_TeleserviceIdentifier, BER_CLASS_CON, 116, BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_TeleserviceIdentifier },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_sms_ChargeIndicator, BER_CLASS_CON, 106, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_ChargeIndicator },
  { &hf_ansi_map_sms_DestinationAddress, BER_CLASS_CON, 107, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_DestinationAddress },
  { &hf_ansi_map_sms_OriginalDestinationAddress, BER_CLASS_CON, 110, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalDestinationAddress },
  { &hf_ansi_map_sms_OriginalDestinationSubaddress, BER_CLASS_CON, 111, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalDestinationSubaddress },
  { &hf_ansi_map_sms_OriginalOriginatingAddress, BER_CLASS_CON, 112, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalOriginatingAddress },
  { &hf_ansi_map_sms_OriginalOriginatingSubaddress, BER_CLASS_CON, 113, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalOriginatingSubaddress },
  { &hf_ansi_map_sms_OriginatingAddress, BER_CLASS_CON, 114, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginatingAddress },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SMSDeliveryBackward_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SMSDeliveryBackward_U_set, hf_index, ett_ansi_map_SMSDeliveryBackward_U);

  return offset;
}



static int
dissect_ansi_map_SMSDeliveryBackward(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SMSDeliveryBackward_U);

  return offset;
}



static int
dissect_ansi_map_SMS_CauseCode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t SMSDeliveryBackwardRes_U_set[] = {
  { &hf_ansi_map_sms_BearerData, BER_CLASS_CON, 105, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_BearerData },
  { &hf_ansi_map_sms_CauseCode, BER_CLASS_CON, 153, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_CauseCode },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SMSDeliveryBackwardRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SMSDeliveryBackwardRes_U_set, hf_index, ett_ansi_map_SMSDeliveryBackwardRes_U);

  return offset;
}



static int
dissect_ansi_map_SMSDeliveryBackwardRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SMSDeliveryBackwardRes_U);

  return offset;
}


static const ber_sequence_t SMSDeliveryForward_U_set[] = {
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_sms_BearerData, BER_CLASS_CON, 105, BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_BearerData },
  { &hf_ansi_map_sms_TeleserviceIdentifier, BER_CLASS_CON, 116, BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_TeleserviceIdentifier },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_sms_ChargeIndicator, BER_CLASS_CON, 106, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_ChargeIndicator },
  { &hf_ansi_map_sms_DestinationAddress, BER_CLASS_CON, 107, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_DestinationAddress },
  { &hf_ansi_map_sms_OriginalDestinationAddress, BER_CLASS_CON, 110, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalDestinationAddress },
  { &hf_ansi_map_sms_OriginalDestinationSubaddress, BER_CLASS_CON, 111, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalDestinationSubaddress },
  { &hf_ansi_map_sms_OriginalOriginatingAddress, BER_CLASS_CON, 112, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalOriginatingAddress },
  { &hf_ansi_map_sms_OriginalOriginatingSubaddress, BER_CLASS_CON, 113, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalOriginatingSubaddress },
  { &hf_ansi_map_sms_OriginatingAddress, BER_CLASS_CON, 114, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginatingAddress },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SMSDeliveryForward_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SMSDeliveryForward_U_set, hf_index, ett_ansi_map_SMSDeliveryForward_U);

  return offset;
}



static int
dissect_ansi_map_SMSDeliveryForward(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SMSDeliveryForward_U);

  return offset;
}


static const ber_sequence_t SMSDeliveryForwardRes_U_set[] = {
  { &hf_ansi_map_sms_BearerData, BER_CLASS_CON, 105, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_BearerData },
  { &hf_ansi_map_sms_CauseCode, BER_CLASS_CON, 153, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_CauseCode },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SMSDeliveryForwardRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SMSDeliveryForwardRes_U_set, hf_index, ett_ansi_map_SMSDeliveryForwardRes_U);

  return offset;
}



static int
dissect_ansi_map_SMSDeliveryForwardRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SMSDeliveryForwardRes_U);

  return offset;
}



static int
dissect_ansi_map_InterMessageTime(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_IMSIType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_NewlyAssignedIMSI(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_IMSIType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_NewlyAssignedMIN(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_MINType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_NewMINExtension(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_MINType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_SMS_MessageCount(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_SMS_NotificationIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_Teleservice_Priority(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_TemporaryReferenceNumber(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_MINType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}


static const ber_sequence_t SMSDeliveryPointToPoint_U_set[] = {
  { &hf_ansi_map_sms_BearerData, BER_CLASS_CON, 105, BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_BearerData },
  { &hf_ansi_map_sms_TeleserviceIdentifier, BER_CLASS_CON, 116, BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_TeleserviceIdentifier },
  { &hf_ansi_map_actionCode , BER_CLASS_CON, 128, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ActionCode },
  { &hf_ansi_map_cdmaServingOneWayDelay2, BER_CLASS_CON, 347, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServingOneWayDelay2 },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { &hf_ansi_map_interMessageTime, BER_CLASS_CON, 325, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMessageTime },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_newlyAssignedIMSI, BER_CLASS_CON, 287, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NewlyAssignedIMSI },
  { &hf_ansi_map_newlyAssignedMIN, BER_CLASS_CON, 187, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NewlyAssignedMIN },
  { &hf_ansi_map_newMINExtension, BER_CLASS_CON, 328, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NewMINExtension },
  { &hf_ansi_map_serviceIndicator, BER_CLASS_CON, 193, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceIndicator },
  { &hf_ansi_map_sms_ChargeIndicator, BER_CLASS_CON, 106, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_ChargeIndicator },
  { &hf_ansi_map_sms_DestinationAddress, BER_CLASS_CON, 107, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_DestinationAddress },
  { &hf_ansi_map_sms_MessageCount, BER_CLASS_CON, 108, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_MessageCount },
  { &hf_ansi_map_sms_NotificationIndicator, BER_CLASS_CON, 109, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_NotificationIndicator },
  { &hf_ansi_map_sms_OriginalDestinationAddress, BER_CLASS_CON, 110, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalDestinationAddress },
  { &hf_ansi_map_sms_OriginalDestinationSubaddress, BER_CLASS_CON, 111, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalDestinationSubaddress },
  { &hf_ansi_map_sms_OriginalOriginatingAddress, BER_CLASS_CON, 112, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalOriginatingAddress },
  { &hf_ansi_map_sms_OriginalOriginatingSubaddress, BER_CLASS_CON, 113, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalOriginatingSubaddress },
  { &hf_ansi_map_sms_OriginatingAddress, BER_CLASS_CON, 114, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginatingAddress },
  { &hf_ansi_map_teleservice_Priority, BER_CLASS_CON, 290, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Teleservice_Priority },
  { &hf_ansi_map_temporaryReferenceNumber, BER_CLASS_CON, 195, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TemporaryReferenceNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SMSDeliveryPointToPoint_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SMSDeliveryPointToPoint_U_set, hf_index, ett_ansi_map_SMSDeliveryPointToPoint_U);

  return offset;
}



static int
dissect_ansi_map_SMSDeliveryPointToPoint(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SMSDeliveryPointToPoint_U);

  return offset;
}



static int
dissect_ansi_map_MobileStationIMSI(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_IMSIType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}


static const value_string ansi_map_MobileStationMSID_vals[] = {
  { 184, "mobileStationMIN" },
  { 286, "mobileStationIMSI" },
  { 0, NULL }
};

static const ber_choice_t MobileStationMSID_choice[] = {
  { 184, &hf_ansi_map_mobileStationMIN, BER_CLASS_CON, 184, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileStationMIN },
  { 286, &hf_ansi_map_mobileStationIMSI, BER_CLASS_CON, 286, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileStationIMSI },
  { 0, NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_MobileStationMSID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 MobileStationMSID_choice, hf_index, ett_ansi_map_MobileStationMSID,
                                 NULL);

  return offset;
}


static const ber_sequence_t SMSDeliveryPointToPointRes_U_set[] = {
  { &hf_ansi_map_actionCode , BER_CLASS_CON, 128, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ActionCode },
  { &hf_ansi_map_authorizationDenied, BER_CLASS_CON, 13, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthorizationDenied },
  { &hf_ansi_map_denyAccess , BER_CLASS_CON, 50, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DenyAccess },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { &hf_ansi_map_mobileStationMSID, BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MobileStationMSID },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_sms_BearerData, BER_CLASS_CON, 105, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_BearerData },
  { &hf_ansi_map_sms_CauseCode, BER_CLASS_CON, 153, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_CauseCode },
  { &hf_ansi_map_systemCapabilities, BER_CLASS_CON, 49, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemCapabilities },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SMSDeliveryPointToPointRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SMSDeliveryPointToPointRes_U_set, hf_index, ett_ansi_map_SMSDeliveryPointToPointRes_U);

  return offset;
}



static int
dissect_ansi_map_SMSDeliveryPointToPointRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SMSDeliveryPointToPointRes_U);

  return offset;
}



static int
dissect_ansi_map_SMS_TransactionID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t SMSDeliveryPointToPointAck_U_set[] = {
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_sms_BearerData, BER_CLASS_CON, 105, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_BearerData },
  { &hf_ansi_map_sms_CauseCode, BER_CLASS_CON, 153, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_CauseCode },
  { &hf_ansi_map_sms_TransactionID, BER_CLASS_CON, 302, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_TransactionID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SMSDeliveryPointToPointAck_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SMSDeliveryPointToPointAck_U_set, hf_index, ett_ansi_map_SMSDeliveryPointToPointAck_U);

  return offset;
}



static int
dissect_ansi_map_SMSDeliveryPointToPointAck(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SMSDeliveryPointToPointAck_U);

  return offset;
}



static int
dissect_ansi_map_SMS_AccessDeniedReason(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t SMSNotification_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_sms_AccessDeniedReason, BER_CLASS_CON, 152, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_AccessDeniedReason },
  { &hf_ansi_map_sms_Address, BER_CLASS_CON, 104, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_Address },
  { &hf_ansi_map_sms_TeleserviceIdentifier, BER_CLASS_CON, 116, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_TeleserviceIdentifier },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SMSNotification_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SMSNotification_U_set, hf_index, ett_ansi_map_SMSNotification_U);

  return offset;
}



static int
dissect_ansi_map_SMSNotification(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SMSNotification_U);

  return offset;
}


static const ber_sequence_t SMSNotificationRes_U_set[] = {
  { &hf_ansi_map_sms_MessageCount, BER_CLASS_CON, 108, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_MessageCount },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SMSNotificationRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SMSNotificationRes_U_set, hf_index, ett_ansi_map_SMSNotificationRes_U);

  return offset;
}



static int
dissect_ansi_map_SMSNotificationRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SMSNotificationRes_U);

  return offset;
}


static const ber_sequence_t SMSRequest_U_set[] = {
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_serviceIndicator, BER_CLASS_CON, 193, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceIndicator },
  { &hf_ansi_map_sms_NotificationIndicator, BER_CLASS_CON, 109, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_NotificationIndicator },
  { &hf_ansi_map_sms_TeleserviceIdentifier, BER_CLASS_CON, 116, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_TeleserviceIdentifier },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SMSRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SMSRequest_U_set, hf_index, ett_ansi_map_SMSRequest_U);

  return offset;
}



static int
dissect_ansi_map_SMSRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SMSRequest_U);

  return offset;
}


static const ber_sequence_t SMSRequestRes_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_sms_AccessDeniedReason, BER_CLASS_CON, 152, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_AccessDeniedReason },
  { &hf_ansi_map_sms_Address, BER_CLASS_CON, 104, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_Address },
  { &hf_ansi_map_sms_CauseCode, BER_CLASS_CON, 153, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_CauseCode },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SMSRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SMSRequestRes_U_set, hf_index, ett_ansi_map_SMSRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_SMSRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SMSRequestRes_U);

  return offset;
}


static const ber_sequence_t TransferToNumberRequest_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_redirectionReason, BER_CLASS_CON, 19, BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectionReason },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_acgencountered, BER_CLASS_CON, 340, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ACGEncountered },
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_callingPartyName, BER_CLASS_CON, 243, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyName },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_callingPartyNumberDigits2, BER_CLASS_CON, 81, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_groupInformation, BER_CLASS_CON, 163, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GroupInformation },
  { &hf_ansi_map_legInformation, BER_CLASS_CON, 144, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LegInformation },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_pilotBillingID, BER_CLASS_CON, 169, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotBillingID },
  { &hf_ansi_map_pilotNumber, BER_CLASS_CON, 168, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotNumber },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_winCapability, BER_CLASS_CON, 280, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_WINCapability },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TransferToNumberRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              TransferToNumberRequest_U_set, hf_index, ett_ansi_map_TransferToNumberRequest_U);

  return offset;
}



static int
dissect_ansi_map_TransferToNumberRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_TransferToNumberRequest_U);

  return offset;
}


static const ber_sequence_t TransferToNumberRequestRes_U_set[] = {
  { &hf_ansi_map_digits_Destination, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_actionCode , BER_CLASS_CON, 128, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ActionCode },
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_callingPartyNumberString1, BER_CLASS_CON, 82, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString1 },
  { &hf_ansi_map_callingPartyNumberString2, BER_CLASS_CON, 83, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_digits_Carrier, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_displayText2, BER_CLASS_CON, 299, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText2 },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_dmh_RedirectionIndicator, BER_CLASS_CON, 88, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_RedirectionIndicator },
  { &hf_ansi_map_dmh_ServiceID, BER_CLASS_CON, 305, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ServiceID },
  { &hf_ansi_map_groupInformation, BER_CLASS_CON, 163, BER_FLAGS_OPTIONAL, dissect_ansi_map_GroupInformation },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_noAnswerTime, BER_CLASS_CON, 96, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NoAnswerTime },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingNumberString, BER_CLASS_CON, 101, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberString },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_terminationList, BER_CLASS_CON, 120, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationList },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TransferToNumberRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              TransferToNumberRequestRes_U_set, hf_index, ett_ansi_map_TransferToNumberRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_TransferToNumberRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_TransferToNumberRequestRes_U);

  return offset;
}


static const value_string ansi_map_SeizureType_vals[] = {
  {   0, "unspecified" },
  {   1, "loop-back" },
  { 0, NULL }
};


static int
dissect_ansi_map_SeizureType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t TrunkTest_U_set[] = {
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_seizureType, BER_CLASS_CON, 15, BER_FLAGS_IMPLTAG, dissect_ansi_map_SeizureType },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TrunkTest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              TrunkTest_U_set, hf_index, ett_ansi_map_TrunkTest_U);

  return offset;
}



static int
dissect_ansi_map_TrunkTest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_TrunkTest_U);

  return offset;
}


static const ber_sequence_t TrunkTestDisconnect_U_set[] = {
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TrunkTestDisconnect_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              TrunkTestDisconnect_U_set, hf_index, ett_ansi_map_TrunkTestDisconnect_U);

  return offset;
}



static int
dissect_ansi_map_TrunkTestDisconnect(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_TrunkTestDisconnect_U);

  return offset;
}


static const ber_sequence_t Unblocking_U_set[] = {
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_Unblocking_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              Unblocking_U_set, hf_index, ett_ansi_map_Unblocking_U);

  return offset;
}



static int
dissect_ansi_map_Unblocking(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_Unblocking_U);

  return offset;
}


static const ber_sequence_t UnreliableRoamerDataDirective_U_set[] = {
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_UnreliableRoamerDataDirective_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              UnreliableRoamerDataDirective_U_set, hf_index, ett_ansi_map_UnreliableRoamerDataDirective_U);

  return offset;
}



static int
dissect_ansi_map_UnreliableRoamerDataDirective(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_UnreliableRoamerDataDirective_U);

  return offset;
}


static const ber_sequence_t UnsolicitedResponse_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_digits_Destination, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_extendedMSCID, BER_CLASS_CON, 53, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ExtendedMSCID },
  { &hf_ansi_map_extendedSystemMyTypeCode, BER_CLASS_CON, 54, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ExtendedSystemMyTypeCode },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_systemAccessType, BER_CLASS_CON, 34, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemAccessType },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_UnsolicitedResponse_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              UnsolicitedResponse_U_set, hf_index, ett_ansi_map_UnsolicitedResponse_U);

  return offset;
}



static int
dissect_ansi_map_UnsolicitedResponse(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_UnsolicitedResponse_U);

  return offset;
}


static const ber_sequence_t UnsolicitedResponseRes_U_set[] = {
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_alertCode  , BER_CLASS_CON, 75, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AlertCode },
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_callingPartyName, BER_CLASS_CON, 243, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyName },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_callingPartyNumberDigits2, BER_CLASS_CON, 81, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits2 },
  { &hf_ansi_map_callingPartyNumberString1, BER_CLASS_CON, 82, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString1 },
  { &hf_ansi_map_callingPartyNumberString2, BER_CLASS_CON, 83, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_displayText2, BER_CLASS_CON, 299, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText2 },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_extendedMSCID, BER_CLASS_CON, 53, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ExtendedMSCID },
  { &hf_ansi_map_extendedSystemMyTypeCode, BER_CLASS_CON, 54, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ExtendedSystemMyTypeCode },
  { &hf_ansi_map_legInformation, BER_CLASS_CON, 144, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LegInformation },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_pilotBillingID, BER_CLASS_CON, 169, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotBillingID },
  { &hf_ansi_map_pilotNumber, BER_CLASS_CON, 168, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotNumber },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingNumberString, BER_CLASS_CON, 101, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberString },
  { &hf_ansi_map_redirectingPartyName, BER_CLASS_CON, 245, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingPartyName },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_terminationTreatment, BER_CLASS_CON, 121, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTreatment },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_UnsolicitedResponseRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              UnsolicitedResponseRes_U_set, hf_index, ett_ansi_map_UnsolicitedResponseRes_U);

  return offset;
}



static int
dissect_ansi_map_UnsolicitedResponseRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_UnsolicitedResponseRes_U);

  return offset;
}



static int
dissect_ansi_map_RequiredParametersMask(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t ParameterRequest_U_set[] = {
  { &hf_ansi_map_requiredParametersMask, BER_CLASS_CON, 236, BER_FLAGS_IMPLTAG, dissect_ansi_map_RequiredParametersMask },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_networkTMSI, BER_CLASS_CON, 233, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NetworkTMSI },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ParameterRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ParameterRequest_U_set, hf_index, ett_ansi_map_ParameterRequest_U);

  return offset;
}



static int
dissect_ansi_map_ParameterRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ParameterRequest_U);

  return offset;
}


static const value_string ansi_map_ReasonList_vals[] = {
  {   0, "unknown" },
  {   1, "unable-to-configure-ISLP" },
  {   2, "iSLP-failure" },
  {   3, "service-allowed-but-facilities-not-available" },
  {   4, "service-not-allowed" },
  {   5, "no-Response-to-TMSI-assignment" },
  {   6, "required-parameters-unavailable" },
  { 0, NULL }
};


static int
dissect_ansi_map_ReasonList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t ParameterRequestRes_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_networkTMSI, BER_CLASS_CON, 233, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NetworkTMSI },
  { &hf_ansi_map_reasonList , BER_CLASS_CON, 218, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReasonList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ParameterRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ParameterRequestRes_U_set, hf_index, ett_ansi_map_ParameterRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_ParameterRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ParameterRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_NetworkTMSIExpirationTime(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_NewNetworkTMSI(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}


static const ber_sequence_t TMSIDirective_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_networkTMSIExpirationTime, BER_CLASS_CON, 234, BER_FLAGS_IMPLTAG, dissect_ansi_map_NetworkTMSIExpirationTime },
  { &hf_ansi_map_newNetworkTMSI, BER_CLASS_CON, 235, BER_FLAGS_IMPLTAG, dissect_ansi_map_NewNetworkTMSI },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_networkTMSI, BER_CLASS_CON, 233, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NetworkTMSI },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TMSIDirective_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              TMSIDirective_U_set, hf_index, ett_ansi_map_TMSIDirective_U);

  return offset;
}



static int
dissect_ansi_map_TMSIDirective(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_TMSIDirective_U);

  return offset;
}


static const ber_sequence_t TMSIDirectiveRes_U_set[] = {
  { &hf_ansi_map_denyAccess , BER_CLASS_CON, 50, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DenyAccess },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_reasonList , BER_CLASS_CON, 218, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReasonList },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TMSIDirectiveRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              TMSIDirectiveRes_U_set, hf_index, ett_ansi_map_TMSIDirectiveRes_U);

  return offset;
}



static int
dissect_ansi_map_TMSIDirectiveRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_TMSIDirectiveRes_U);

  return offset;
}


static const ber_sequence_t NumberPortabilityRequest_U_set[] = {
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_acgencountered, BER_CLASS_CON, 340, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ACGEncountered },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_NumberPortabilityRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              NumberPortabilityRequest_U_set, hf_index, ett_ansi_map_NumberPortabilityRequest_U);

  return offset;
}



static int
dissect_ansi_map_NumberPortabilityRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_NumberPortabilityRequest_U);

  return offset;
}


static const ber_sequence_t NumberPortabilityRequestRes_U_set[] = {
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_NumberPortabilityRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              NumberPortabilityRequestRes_U_set, hf_index, ett_ansi_map_NumberPortabilityRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_NumberPortabilityRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_NumberPortabilityRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_ServiceID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_DataID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string ansi_map_Change_vals[] = {
  {   1, "setDataItemToDefaultValue" },
  {   2, "addDataItem" },
  {   3, "deleteDataItem" },
  {   4, "replaceDataItemWithAssociatedDataValue" },
  { 0, NULL }
};


static int
dissect_ansi_map_Change(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_DataValue(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t DataAccessElement_sequence[] = {
  { &hf_ansi_map_dataID     , BER_CLASS_CON, 251, BER_FLAGS_IMPLTAG, dissect_ansi_map_DataID },
  { &hf_ansi_map_change     , BER_CLASS_CON, 248, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Change },
  { &hf_ansi_map_dataValue  , BER_CLASS_CON, 256, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataValue },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_DataAccessElement(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   DataAccessElement_sequence, hf_index, ett_ansi_map_DataAccessElement);

  return offset;
}


static const ber_sequence_t DataAccessElementList_item_sequence[] = {
  { &hf_ansi_map_dataAccessElement1, BER_CLASS_CON, 249, BER_FLAGS_IMPLTAG, dissect_ansi_map_DataAccessElement },
  { &hf_ansi_map_dataAccessElement2, BER_CLASS_CON, 249, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataAccessElement },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_DataAccessElementList_item(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   DataAccessElementList_item_sequence, hf_index, ett_ansi_map_DataAccessElementList_item);

  return offset;
}


static const ber_sequence_t DataAccessElementList_sequence_of[1] = {
  { &hf_ansi_map_DataAccessElementList_item, BER_CLASS_UNI, BER_UNI_TAG_SEQUENCE, BER_FLAGS_NOOWNTAG, dissect_ansi_map_DataAccessElementList_item },
};

static int
dissect_ansi_map_DataAccessElementList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      DataAccessElementList_sequence_of, hf_index, ett_ansi_map_DataAccessElementList);

  return offset;
}



static int
dissect_ansi_map_TimeDateOffset(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_TimeOfDay(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}


static const ber_sequence_t ServiceRequest_U_set[] = {
  { &hf_ansi_map_serviceID  , BER_CLASS_CON, 246, BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceID },
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_acgencountered, BER_CLASS_CON, 340, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ACGEncountered },
  { &hf_ansi_map_availabilityType, BER_CLASS_CON, 90, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AvailabilityType },
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_callingPartyName, BER_CLASS_CON, 243, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyName },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_callingPartyNumberDigits2, BER_CLASS_CON, 81, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_conditionallyDeniedReason, BER_CLASS_CON, 162, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConditionallyDeniedReason },
  { &hf_ansi_map_dataAccessElementList, BER_CLASS_CON, 250, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataAccessElementList },
  { &hf_ansi_map_destinationDigits, BER_CLASS_CON, 87, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DestinationDigits },
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_dmh_RedirectionIndicator, BER_CLASS_CON, 88, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_RedirectionIndicator },
  { &hf_ansi_map_dmh_ServiceID, BER_CLASS_CON, 305, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ServiceID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_extendedMSCID, BER_CLASS_CON, 53, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ExtendedMSCID },
  { &hf_ansi_map_featureIndicator, BER_CLASS_CON, 306, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_FeatureIndicator },
  { &hf_ansi_map_groupInformation, BER_CLASS_CON, 163, BER_FLAGS_OPTIONAL, dissect_ansi_map_GroupInformation },
  { &hf_ansi_map_legInformation, BER_CLASS_CON, 144, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LegInformation },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_pilotBillingID, BER_CLASS_CON, 169, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotBillingID },
  { &hf_ansi_map_pilotNumber, BER_CLASS_CON, 168, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotNumber },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_redirectingPartyName, BER_CLASS_CON, 245, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingPartyName },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_redirectionReason, BER_CLASS_CON, 19, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectionReason },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_terminationAccessType, BER_CLASS_CON, 119, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationAccessType },
  { &hf_ansi_map_timeDateOffset, BER_CLASS_CON, 275, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeDateOffset },
  { &hf_ansi_map_timeOfDay  , BER_CLASS_CON, 309, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeOfDay },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_triggerType, BER_CLASS_CON, 279, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerType },
  { &hf_ansi_map_winCapability, BER_CLASS_CON, 280, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_WINCapability },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ServiceRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ServiceRequest_U_set, hf_index, ett_ansi_map_ServiceRequest_U);

  return offset;
}



static int
dissect_ansi_map_ServiceRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ServiceRequest_U);

  return offset;
}


static const ber_sequence_t ServiceRequestRes_U_set[] = {
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_actionCode , BER_CLASS_CON, 128, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ActionCode },
  { &hf_ansi_map_alertCode  , BER_CLASS_CON, 75, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AlertCode },
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_callingPartyName, BER_CLASS_CON, 243, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyName },
  { &hf_ansi_map_callingPartyNumberString1, BER_CLASS_CON, 82, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString1 },
  { &hf_ansi_map_callingPartyNumberString2, BER_CLASS_CON, 83, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_displayText2, BER_CLASS_CON, 299, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText2 },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_dmh_ChargeInformation, BER_CLASS_CON, 311, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ChargeInformation },
  { &hf_ansi_map_dmh_RedirectionIndicator, BER_CLASS_CON, 88, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_RedirectionIndicator },
  { &hf_ansi_map_dmh_ServiceID, BER_CLASS_CON, 305, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ServiceID },
  { &hf_ansi_map_groupInformation, BER_CLASS_CON, 163, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GroupInformation },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_noAnswerTime, BER_CLASS_CON, 96, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NoAnswerTime },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingNumberString, BER_CLASS_CON, 101, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberString },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_resumePIC  , BER_CLASS_CON, 266, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ResumePIC },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_terminationList, BER_CLASS_CON, 120, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationList },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ServiceRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ServiceRequestRes_U_set, hf_index, ett_ansi_map_ServiceRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_ServiceRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ServiceRequestRes_U);

  return offset;
}


static const value_string ansi_map_DMH_BillingIndicator_vals[] = {
  {   0, "unspecified" },
  { 0, NULL }
};


static int
dissect_ansi_map_DMH_BillingIndicator(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t AnalyzedInformation_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_triggerType, BER_CLASS_CON, 279, BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerType },
  { &hf_ansi_map_winCapability, BER_CLASS_CON, 280, BER_FLAGS_IMPLTAG, dissect_ansi_map_WINCapability },
  { &hf_ansi_map_acgencountered, BER_CLASS_CON, 340, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ACGEncountered },
  { &hf_ansi_map_callingPartyName, BER_CLASS_CON, 243, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyName },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_callingPartyNumberDigits2, BER_CLASS_CON, 81, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_conferenceCallingIndicator, BER_CLASS_CON, 137, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConferenceCallingIndicator },
  { &hf_ansi_map_destinationDigits, BER_CLASS_CON, 87, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DestinationDigits },
  { &hf_ansi_map_dmd_BillingIndicator, BER_CLASS_CON, 312, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingIndicator },
  { &hf_ansi_map_dmh_ChargeInformation, BER_CLASS_CON, 311, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ChargeInformation },
  { &hf_ansi_map_dmh_RedirectionIndicator, BER_CLASS_CON, 88, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_RedirectionIndicator },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_featureIndicator, BER_CLASS_CON, 306, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_FeatureIndicator },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingPartyName, BER_CLASS_CON, 245, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingPartyName },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_terminationAccessType, BER_CLASS_CON, 119, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationAccessType },
  { &hf_ansi_map_timeDateOffset, BER_CLASS_CON, 275, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeDateOffset },
  { &hf_ansi_map_timeOfDay  , BER_CLASS_CON, 309, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeOfDay },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AnalyzedInformation_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              AnalyzedInformation_U_set, hf_index, ett_ansi_map_AnalyzedInformation_U);

  return offset;
}



static int
dissect_ansi_map_AnalyzedInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_AnalyzedInformation_U);

  return offset;
}


static const ber_sequence_t AnalyzedInformationRes_U_set[] = {
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_actionCode , BER_CLASS_CON, 128, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ActionCode },
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_conferenceCallingIndicator, BER_CLASS_CON, 137, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConferenceCallingIndicator },
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_dmh_RedirectionIndicator, BER_CLASS_CON, 88, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_RedirectionIndicator },
  { &hf_ansi_map_dmh_ServiceID, BER_CLASS_CON, 305, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ServiceID },
  { &hf_ansi_map_noAnswerTime, BER_CLASS_CON, 96, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NoAnswerTime },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_resumePIC  , BER_CLASS_CON, 266, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ResumePIC },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_terminationList, BER_CLASS_CON, 120, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationList },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AnalyzedInformationRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              AnalyzedInformationRes_U_set, hf_index, ett_ansi_map_AnalyzedInformationRes_U);

  return offset;
}



static int
dissect_ansi_map_AnalyzedInformationRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_AnalyzedInformationRes_U);

  return offset;
}


static const value_string ansi_map_FailureType_vals[] = {
  {   1, "callAbandoned" },
  {   2, "resourceDisconnect" },
  {   3, "failureAtMSC" },
  {   4, "sSFTExpiration" },
  { 0, NULL }
};


static int
dissect_ansi_map_FailureType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_FailureCause(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t ConnectionFailureReport_U_set[] = {
  { &hf_ansi_map_failureType, BER_CLASS_CON, 260, BER_FLAGS_IMPLTAG, dissect_ansi_map_FailureType },
  { &hf_ansi_map_failureCause, BER_CLASS_CON, 387, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_FailureCause },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ConnectionFailureReport_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ConnectionFailureReport_U_set, hf_index, ett_ansi_map_ConnectionFailureReport_U);

  return offset;
}



static int
dissect_ansi_map_ConnectionFailureReport(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ConnectionFailureReport_U);

  return offset;
}


static const ber_sequence_t ConnectResource_U_set[] = {
  { &hf_ansi_map_destinationDigits, BER_CLASS_CON, 87, BER_FLAGS_IMPLTAG, dissect_ansi_map_DestinationDigits },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_outingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ConnectResource_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ConnectResource_U_set, hf_index, ett_ansi_map_ConnectResource_U);

  return offset;
}



static int
dissect_ansi_map_ConnectResource(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ConnectResource_U);

  return offset;
}


static const ber_sequence_t FacilitySelectedAndAvailable_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_triggerType, BER_CLASS_CON, 279, BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerType },
  { &hf_ansi_map_winCapability, BER_CLASS_CON, 280, BER_FLAGS_IMPLTAG, dissect_ansi_map_WINCapability },
  { &hf_ansi_map_acgencountered, BER_CLASS_CON, 340, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ACGEncountered },
  { &hf_ansi_map_callingPartyName, BER_CLASS_CON, 243, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyName },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_callingPartyNumberDigits2, BER_CLASS_CON, 81, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_groupInformation, BER_CLASS_CON, 163, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GroupInformation },
  { &hf_ansi_map_legInformation, BER_CLASS_CON, 144, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LegInformation },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_pilotBillingID, BER_CLASS_CON, 169, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotBillingID },
  { &hf_ansi_map_pilotNumber, BER_CLASS_CON, 168, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotNumber },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingPartyName, BER_CLASS_CON, 245, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingPartyName },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_terminationAccessType, BER_CLASS_CON, 119, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationAccessType },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_FacilitySelectedAndAvailable_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              FacilitySelectedAndAvailable_U_set, hf_index, ett_ansi_map_FacilitySelectedAndAvailable_U);

  return offset;
}



static int
dissect_ansi_map_FacilitySelectedAndAvailable(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_FacilitySelectedAndAvailable_U);

  return offset;
}


static const ber_sequence_t FacilitySelectedAndAvailableRes_U_set[] = {
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_actionCode , BER_CLASS_CON, 128, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ActionCode },
  { &hf_ansi_map_alertCode  , BER_CLASS_CON, 75, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AlertCode },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_dmh_ChargeInformation, BER_CLASS_CON, 311, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ChargeInformation },
  { &hf_ansi_map_dmh_RedirectionIndicator, BER_CLASS_CON, 88, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_RedirectionIndicator },
  { &hf_ansi_map_dmh_ServiceID, BER_CLASS_CON, 305, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ServiceID },
  { &hf_ansi_map_noAnswerTime, BER_CLASS_CON, 96, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NoAnswerTime },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_resumePIC  , BER_CLASS_CON, 266, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ResumePIC },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_FacilitySelectedAndAvailableRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              FacilitySelectedAndAvailableRes_U_set, hf_index, ett_ansi_map_FacilitySelectedAndAvailableRes_U);

  return offset;
}



static int
dissect_ansi_map_FacilitySelectedAndAvailableRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_FacilitySelectedAndAvailableRes_U);

  return offset;
}



static int
dissect_ansi_map_DatabaseKey(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t ServiceDataAccessElement_sequence[] = {
  { &hf_ansi_map_dataAccessElementList, BER_CLASS_CON, 250, BER_FLAGS_IMPLTAG, dissect_ansi_map_DataAccessElementList },
  { &hf_ansi_map_serviceID  , BER_CLASS_CON, 246, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ServiceDataAccessElement(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   ServiceDataAccessElement_sequence, hf_index, ett_ansi_map_ServiceDataAccessElement);

  return offset;
}


static const ber_sequence_t ServiceDataAccessElementList_sequence_of[1] = {
  { &hf_ansi_map_ServiceDataAccessElementList_item, BER_CLASS_CON, 270, BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceDataAccessElement },
};

static int
dissect_ansi_map_ServiceDataAccessElementList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      ServiceDataAccessElementList_sequence_of, hf_index, ett_ansi_map_ServiceDataAccessElementList);

  return offset;
}


static const value_string ansi_map_AllOrNone_vals[] = {
  {   0, "notUsed" },
  {   1, "allChangesMustSucceedOrNoneShouldBeApplied" },
  {   2, "treatEachChangeIndependently" },
  { 0, NULL }
};


static int
dissect_ansi_map_AllOrNone(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t ModificationRequest_sequence[] = {
  { &hf_ansi_map_serviceDataAccessElementList, BER_CLASS_CON, 271, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceDataAccessElementList },
  { &hf_ansi_map_allOrNone  , BER_CLASS_CON, 247, BER_FLAGS_IMPLTAG, dissect_ansi_map_AllOrNone },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ModificationRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   ModificationRequest_sequence, hf_index, ett_ansi_map_ModificationRequest);

  return offset;
}


static const ber_sequence_t ModificationRequestList_sequence_of[1] = {
  { &hf_ansi_map_ModificationRequestList_item, BER_CLASS_CON, 262, BER_FLAGS_IMPLTAG, dissect_ansi_map_ModificationRequest },
};

static int
dissect_ansi_map_ModificationRequestList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      ModificationRequestList_sequence_of, hf_index, ett_ansi_map_ModificationRequestList);

  return offset;
}


static const ber_sequence_t Modify_U_set[] = {
  { &hf_ansi_map_databaseKey, BER_CLASS_CON, 252, BER_FLAGS_IMPLTAG, dissect_ansi_map_DatabaseKey },
  { &hf_ansi_map_modificationRequestList, BER_CLASS_CON, 263, BER_FLAGS_IMPLTAG, dissect_ansi_map_ModificationRequestList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_Modify_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              Modify_U_set, hf_index, ett_ansi_map_Modify_U);

  return offset;
}



static int
dissect_ansi_map_Modify(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_Modify_U);

  return offset;
}


static const value_string ansi_map_DataResult_vals[] = {
  {   0, "not-used" },
  {   1, "successful" },
  {   2, "unsuccessful-unspecified" },
  {   3, "unsuccessful-no-default-value-available" },
  {   4, "reserved" },
  { 0, NULL }
};


static int
dissect_ansi_map_DataResult(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t DataUpdateResult_sequence[] = {
  { &hf_ansi_map_dataID     , BER_CLASS_CON, 251, BER_FLAGS_IMPLTAG, dissect_ansi_map_DataID },
  { &hf_ansi_map_dataResult , BER_CLASS_CON, 253, BER_FLAGS_IMPLTAG, dissect_ansi_map_DataResult },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_DataUpdateResult(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   DataUpdateResult_sequence, hf_index, ett_ansi_map_DataUpdateResult);

  return offset;
}


static const ber_sequence_t DataUpdateResultList_sequence_of[1] = {
  { &hf_ansi_map_DataUpdateResultList_item, BER_CLASS_UNI, BER_UNI_TAG_SEQUENCE, BER_FLAGS_NOOWNTAG, dissect_ansi_map_DataUpdateResult },
};

static int
dissect_ansi_map_DataUpdateResultList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      DataUpdateResultList_sequence_of, hf_index, ett_ansi_map_DataUpdateResultList);

  return offset;
}


static const ber_sequence_t ServiceDataResult_sequence[] = {
  { &hf_ansi_map_dataUpdateResultList, BER_CLASS_CON, 255, BER_FLAGS_IMPLTAG, dissect_ansi_map_DataUpdateResultList },
  { &hf_ansi_map_serviceID  , BER_CLASS_CON, 246, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ServiceDataResult(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   ServiceDataResult_sequence, hf_index, ett_ansi_map_ServiceDataResult);

  return offset;
}


static const ber_sequence_t ServiceDataResultList_sequence_of[1] = {
  { &hf_ansi_map_ServiceDataResultList_item, BER_CLASS_CON, 272, BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceDataResult },
};

static int
dissect_ansi_map_ServiceDataResultList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      ServiceDataResultList_sequence_of, hf_index, ett_ansi_map_ServiceDataResultList);

  return offset;
}


static const value_string ansi_map_ModificationResult_vals[] = {
  { 253, "dataResult" },
  { 273, "serviceDataResultList" },
  { 0, NULL }
};

static const ber_choice_t ModificationResult_choice[] = {
  { 253, &hf_ansi_map_dataResult , BER_CLASS_CON, 253, BER_FLAGS_IMPLTAG, dissect_ansi_map_DataResult },
  { 273, &hf_ansi_map_serviceDataResultList, BER_CLASS_CON, 273, BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceDataResultList },
  { 0, NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ModificationResult(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 ModificationResult_choice, hf_index, ett_ansi_map_ModificationResult,
                                 NULL);

  return offset;
}


static const ber_sequence_t ModificationResultList_sequence_of[1] = {
  { &hf_ansi_map_ModificationResultList_item, BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_ModificationResult },
};

static int
dissect_ansi_map_ModificationResultList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      ModificationResultList_sequence_of, hf_index, ett_ansi_map_ModificationResultList);

  return offset;
}


static const ber_sequence_t ModifyRes_U_set[] = {
  { &hf_ansi_map_modificationResultList, BER_CLASS_CON, 264, BER_FLAGS_IMPLTAG, dissect_ansi_map_ModificationResultList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ModifyRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ModifyRes_U_set, hf_index, ett_ansi_map_ModifyRes_U);

  return offset;
}



static int
dissect_ansi_map_ModifyRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ModifyRes_U);

  return offset;
}


static const ber_sequence_t Search_U_set[] = {
  { &hf_ansi_map_databaseKey, BER_CLASS_CON, 252, BER_FLAGS_IMPLTAG, dissect_ansi_map_DatabaseKey },
  { &hf_ansi_map_serviceDataAccessElementList, BER_CLASS_CON, 271, BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceDataAccessElementList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_Search_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              Search_U_set, hf_index, ett_ansi_map_Search_U);

  return offset;
}



static int
dissect_ansi_map_Search(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_Search_U);

  return offset;
}


static const ber_sequence_t SearchRes_U_set[] = {
  { &hf_ansi_map_serviceDataAccessElementList, BER_CLASS_CON, 271, BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceDataAccessElementList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SearchRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SearchRes_U_set, hf_index, ett_ansi_map_SearchRes_U);

  return offset;
}



static int
dissect_ansi_map_SearchRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SearchRes_U);

  return offset;
}



static int
dissect_ansi_map_PrivateSpecializedResource(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_SpecializedResource(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t SeizeResource_U_set[] = {
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_privateSpecializedResource, BER_CLASS_CON, 265, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PrivateSpecializedResource },
  { &hf_ansi_map_specializedResource, BER_CLASS_CON, 274, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SpecializedResource },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SeizeResource_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SeizeResource_U_set, hf_index, ett_ansi_map_SeizeResource_U);

  return offset;
}



static int
dissect_ansi_map_SeizeResource(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SeizeResource_U);

  return offset;
}


static const ber_sequence_t SeizeResourceRes_U_set[] = {
  { &hf_ansi_map_destinationDigits, BER_CLASS_CON, 87, BER_FLAGS_IMPLTAG, dissect_ansi_map_DestinationDigits },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SeizeResourceRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SeizeResourceRes_U_set, hf_index, ett_ansi_map_SeizeResourceRes_U);

  return offset;
}



static int
dissect_ansi_map_SeizeResourceRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SeizeResourceRes_U);

  return offset;
}



static int
dissect_ansi_map_ScriptName(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_ScriptArgument(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t ExecuteScript_sequence[] = {
  { &hf_ansi_map_scriptName , BER_CLASS_CON, 268, BER_FLAGS_IMPLTAG, dissect_ansi_map_ScriptName },
  { &hf_ansi_map_scriptArgument, BER_CLASS_CON, 267, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ScriptArgument },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ExecuteScript(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   ExecuteScript_sequence, hf_index, ett_ansi_map_ExecuteScript);

  return offset;
}


static const ber_sequence_t SRFDirective_U_set[] = {
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_digitCollectionControl, BER_CLASS_CON, 139, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DigitCollectionControl },
  { &hf_ansi_map_executeScript, BER_CLASS_CON, 386, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ExecuteScript },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SRFDirective_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SRFDirective_U_set, hf_index, ett_ansi_map_SRFDirective_U);

  return offset;
}



static int
dissect_ansi_map_SRFDirective(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SRFDirective_U);

  return offset;
}



static int
dissect_ansi_map_ScriptResult(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t SRFDirectiveRes_U_set[] = {
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_scriptResult, BER_CLASS_CON, 269, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ScriptResult },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_SRFDirectiveRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              SRFDirectiveRes_U_set, hf_index, ett_ansi_map_SRFDirectiveRes_U);

  return offset;
}



static int
dissect_ansi_map_SRFDirectiveRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_SRFDirectiveRes_U);

  return offset;
}


static const ber_sequence_t TBusy_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_triggerType, BER_CLASS_CON, 279, BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerType },
  { &hf_ansi_map_winCapability, BER_CLASS_CON, 280, BER_FLAGS_IMPLTAG, dissect_ansi_map_WINCapability },
  { &hf_ansi_map_acgencountered, BER_CLASS_CON, 340, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ACGEncountered },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_callingPartyNumberDigits2, BER_CLASS_CON, 81, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_groupInformation, BER_CLASS_CON, 163, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GroupInformation },
  { &hf_ansi_map_legInformation, BER_CLASS_CON, 144, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LegInformation },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_pilotBillingID, BER_CLASS_CON, 169, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotBillingID },
  { &hf_ansi_map_pilotNumber, BER_CLASS_CON, 168, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotNumber },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_redirectionReason, BER_CLASS_CON, 19, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectionReason },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_terminationAccessType, BER_CLASS_CON, 119, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationAccessType },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TBusy_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              TBusy_U_set, hf_index, ett_ansi_map_TBusy_U);

  return offset;
}



static int
dissect_ansi_map_TBusy(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_TBusy_U);

  return offset;
}


static const ber_sequence_t TBusyRes_U_set[] = {
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_actionCode , BER_CLASS_CON, 128, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ActionCode },
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_callingPartyNumberString1, BER_CLASS_CON, 82, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString1 },
  { &hf_ansi_map_callingPartyNumberString2, BER_CLASS_CON, 83, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString2 },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_dmh_RedirectionIndicator, BER_CLASS_CON, 88, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_RedirectionIndicator },
  { &hf_ansi_map_dmh_ServiceID, BER_CLASS_CON, 305, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ServiceID },
  { &hf_ansi_map_groupInformation, BER_CLASS_CON, 163, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GroupInformation },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_pilotNumber, BER_CLASS_CON, 168, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotNumber },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_resumePIC  , BER_CLASS_CON, 266, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ResumePIC },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_terminationList, BER_CLASS_CON, 120, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationList },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TBusyRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              TBusyRes_U_set, hf_index, ett_ansi_map_TBusyRes_U);

  return offset;
}



static int
dissect_ansi_map_TBusyRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_TBusyRes_U);

  return offset;
}


static const ber_sequence_t TNoAnswer_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_triggerType, BER_CLASS_CON, 279, BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerType },
  { &hf_ansi_map_winCapability, BER_CLASS_CON, 280, BER_FLAGS_IMPLTAG, dissect_ansi_map_WINCapability },
  { &hf_ansi_map_acgencountered, BER_CLASS_CON, 340, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ACGEncountered },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_callingPartyNumberDigits2, BER_CLASS_CON, 81, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_groupInformation, BER_CLASS_CON, 163, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GroupInformation },
  { &hf_ansi_map_legInformation, BER_CLASS_CON, 144, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LegInformation },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_pilotBillingID, BER_CLASS_CON, 169, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotBillingID },
  { &hf_ansi_map_pilotNumber, BER_CLASS_CON, 168, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotNumber },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingSubaddress, BER_CLASS_CON, 102, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingSubaddress },
  { &hf_ansi_map_redirectionReason, BER_CLASS_CON, 19, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectionReason },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_terminationAccessType, BER_CLASS_CON, 119, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationAccessType },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TNoAnswer_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              TNoAnswer_U_set, hf_index, ett_ansi_map_TNoAnswer_U);

  return offset;
}



static int
dissect_ansi_map_TNoAnswer(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_TNoAnswer_U);

  return offset;
}


static const ber_sequence_t TNoAnswerRes_U_set[] = {
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_actionCode , BER_CLASS_CON, 128, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ActionCode },
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_callingPartyNumberString1, BER_CLASS_CON, 82, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString1 },
  { &hf_ansi_map_callingPartyNumberString2, BER_CLASS_CON, 83, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberString2 },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_dmh_RedirectionIndicator, BER_CLASS_CON, 88, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_RedirectionIndicator },
  { &hf_ansi_map_dmh_ServiceID, BER_CLASS_CON, 305, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ServiceID },
  { &hf_ansi_map_groupInformation, BER_CLASS_CON, 163, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GroupInformation },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_pilotNumber, BER_CLASS_CON, 168, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PilotNumber },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_resumePIC  , BER_CLASS_CON, 266, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ResumePIC },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_terminationList, BER_CLASS_CON, 120, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationList },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TNoAnswerRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              TNoAnswerRes_U_set, hf_index, ett_ansi_map_TNoAnswerRes_U);

  return offset;
}



static int
dissect_ansi_map_TNoAnswerRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_TNoAnswerRes_U);

  return offset;
}


static const ber_sequence_t ChangeFacilities_U_set[] = {
  { &hf_ansi_map_cdmaPrivateLongCodeMask, BER_CLASS_CON, 67, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPrivateLongCodeMask },
  { &hf_ansi_map_cdmaServiceConfigurationRecord, BER_CLASS_CON, 174, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceConfigurationRecord },
  { &hf_ansi_map_dataKey    , BER_CLASS_CON, 215, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataKey },
  { &hf_ansi_map_dataPrivacyParameters, BER_CLASS_CON, 216, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataPrivacyParameters },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_ilspInformation, BER_CLASS_CON, 217, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ISLPInformation },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_randomVariable, BER_CLASS_CON, 40, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariable },
  { &hf_ansi_map_tdmaBandwidth, BER_CLASS_CON, 220, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABandwidth },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_voicePrivacyMask, BER_CLASS_CON, 48, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoicePrivacyMask },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ChangeFacilities_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ChangeFacilities_U_set, hf_index, ett_ansi_map_ChangeFacilities_U);

  return offset;
}



static int
dissect_ansi_map_ChangeFacilities(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ChangeFacilities_U);

  return offset;
}


static const ber_sequence_t ChangeFacilitiesRes_U_set[] = {
  { &hf_ansi_map_reasonList , BER_CLASS_CON, 218, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReasonList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ChangeFacilitiesRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ChangeFacilitiesRes_U_set, hf_index, ett_ansi_map_ChangeFacilitiesRes_U);

  return offset;
}



static int
dissect_ansi_map_ChangeFacilitiesRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ChangeFacilitiesRes_U);

  return offset;
}



static int
dissect_ansi_map_TDMAVoiceMode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t ChangeService_U_set[] = {
  { &hf_ansi_map_cdmaServiceConfigurationRecord, BER_CLASS_CON, 174, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceConfigurationRecord },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_changeServiceAttributes, BER_CLASS_CON, 214, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ChangeServiceAttributes },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_ilspInformation, BER_CLASS_CON, 217, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ISLPInformation },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_tdmaBandwidth, BER_CLASS_CON, 220, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMABandwidth },
  { &hf_ansi_map_tdmaDataMode, BER_CLASS_CON, 222, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMADataMode },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_tdmaVoiceMode, BER_CLASS_CON, 223, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAVoiceMode },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ChangeService_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ChangeService_U_set, hf_index, ett_ansi_map_ChangeService_U);

  return offset;
}



static int
dissect_ansi_map_ChangeService(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ChangeService_U);

  return offset;
}


static const ber_sequence_t ChangeServiceRes_U_set[] = {
  { &hf_ansi_map_cdmaPrivateLongCodeMask, BER_CLASS_CON, 67, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPrivateLongCodeMask },
  { &hf_ansi_map_cdmaServiceConfigurationRecord, BER_CLASS_CON, 174, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceConfigurationRecord },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_changeServiceAttributes, BER_CLASS_CON, 214, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ChangeServiceAttributes },
  { &hf_ansi_map_dataKey    , BER_CLASS_CON, 215, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataKey },
  { &hf_ansi_map_dataPrivacyParameters, BER_CLASS_CON, 216, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DataPrivacyParameters },
  { &hf_ansi_map_randomVariable, BER_CLASS_CON, 40, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariable },
  { &hf_ansi_map_reasonList , BER_CLASS_CON, 218, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReasonList },
  { &hf_ansi_map_tdmaServiceCode, BER_CLASS_CON, 178, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAServiceCode },
  { &hf_ansi_map_voicePrivacyMask, BER_CLASS_CON, 48, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoicePrivacyMask },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ChangeServiceRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ChangeServiceRes_U_set, hf_index, ett_ansi_map_ChangeServiceRes_U);

  return offset;
}



static int
dissect_ansi_map_ChangeServiceRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ChangeServiceRes_U);

  return offset;
}


static const ber_sequence_t MessageDirective_U_set[] = {
  { &hf_ansi_map_messageWaitingNotificationCount, BER_CLASS_CON, 92, BER_FLAGS_IMPLTAG, dissect_ansi_map_MessageWaitingNotificationCount },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_MessageDirective_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              MessageDirective_U_set, hf_index, ett_ansi_map_MessageDirective_U);

  return offset;
}



static int
dissect_ansi_map_MessageDirective(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_MessageDirective_U);

  return offset;
}


static const ber_sequence_t BulkDisconnection_U_set[] = {
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_timeDateOffset, BER_CLASS_CON, 275, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeDateOffset },
  { &hf_ansi_map_timeOfDay  , BER_CLASS_CON, 309, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeOfDay },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_BulkDisconnection_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              BulkDisconnection_U_set, hf_index, ett_ansi_map_BulkDisconnection_U);

  return offset;
}



static int
dissect_ansi_map_BulkDisconnection(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_BulkDisconnection_U);

  return offset;
}


static const ber_sequence_t CallControlDirective_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_actionCode , BER_CLASS_CON, 128, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ActionCode },
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_displayText, BER_CLASS_CON, 244, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DisplayText },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_dmh_ChargeInformation, BER_CLASS_CON, 311, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ChargeInformation },
  { &hf_ansi_map_dmh_RedirectionIndicator, BER_CLASS_CON, 88, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_RedirectionIndicator },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_terminationList, BER_CLASS_CON, 120, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationList },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CallControlDirective_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              CallControlDirective_U_set, hf_index, ett_ansi_map_CallControlDirective_U);

  return offset;
}



static int
dissect_ansi_map_CallControlDirective(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_CallControlDirective_U);

  return offset;
}


static const value_string ansi_map_CallStatus_vals[] = {
  {   0, "not-used" },
  {   1, "call-Setup-in-Progress" },
  {   2, "called-Party" },
  {   3, "locally-Allowed-Call-No-Action" },
  { 0, NULL }
};


static int
dissect_ansi_map_CallStatus(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t CallControlDirectiveRes_U_set[] = {
  { &hf_ansi_map_callStatus , BER_CLASS_CON, 310, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallStatus },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CallControlDirectiveRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              CallControlDirectiveRes_U_set, hf_index, ett_ansi_map_CallControlDirectiveRes_U);

  return offset;
}



static int
dissect_ansi_map_CallControlDirectiveRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_CallControlDirectiveRes_U);

  return offset;
}


static const ber_sequence_t OAnswer_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_timeDateOffset, BER_CLASS_CON, 275, BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeDateOffset },
  { &hf_ansi_map_timeOfDay  , BER_CLASS_CON, 309, BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeOfDay },
  { &hf_ansi_map_triggerType, BER_CLASS_CON, 279, BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerType },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_featureIndicator, BER_CLASS_CON, 306, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_FeatureIndicator },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_OAnswer_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              OAnswer_U_set, hf_index, ett_ansi_map_OAnswer_U);

  return offset;
}



static int
dissect_ansi_map_OAnswer(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_OAnswer_U);

  return offset;
}


static const value_string ansi_map_ReleaseCause_vals[] = {
  {   0, "unspecified" },
  {   1, "calling-Party" },
  {   2, "called-Party" },
  {   3, "commanded-Disconnect" },
  { 0, NULL }
};


static int
dissect_ansi_map_ReleaseCause(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t ODisconnect_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_releaseCause, BER_CLASS_CON, 308, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReleaseCause },
  { &hf_ansi_map_timeDateOffset, BER_CLASS_CON, 275, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeDateOffset },
  { &hf_ansi_map_timeOfDay  , BER_CLASS_CON, 309, BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeOfDay },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_winCapability, BER_CLASS_CON, 280, BER_FLAGS_IMPLTAG, dissect_ansi_map_WINCapability },
  { &hf_ansi_map_triggerType, BER_CLASS_CON, 279, BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerType },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ODisconnect_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ODisconnect_U_set, hf_index, ett_ansi_map_ODisconnect_U);

  return offset;
}



static int
dissect_ansi_map_ODisconnect(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ODisconnect_U);

  return offset;
}


static const ber_sequence_t ODisconnectRes_U_set[] = {
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_dmh_ServiceID, BER_CLASS_CON, 305, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ServiceID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ODisconnectRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ODisconnectRes_U_set, hf_index, ett_ansi_map_ODisconnectRes_U);

  return offset;
}



static int
dissect_ansi_map_ODisconnectRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ODisconnectRes_U);

  return offset;
}


static const ber_sequence_t CallRecoveryID_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_timeDateOffset, BER_CLASS_CON, 275, BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeDateOffset },
  { &hf_ansi_map_timeOfDay  , BER_CLASS_CON, 309, BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeOfDay },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CallRecoveryID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              CallRecoveryID_set, hf_index, ett_ansi_map_CallRecoveryID);

  return offset;
}


static const ber_sequence_t CallRecoveryIDList_set_of[1] = {
  { &hf_ansi_map_CallRecoveryIDList_item, BER_CLASS_CON, 303, BER_FLAGS_IMPLTAG, dissect_ansi_map_CallRecoveryID },
};

static int
dissect_ansi_map_CallRecoveryIDList(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
                                 CallRecoveryIDList_set_of, hf_index, ett_ansi_map_CallRecoveryIDList);

  return offset;
}


static const ber_sequence_t CallRecoveryReport_U_set[] = {
  { &hf_ansi_map_callRecoveryIDList, BER_CLASS_CON, 304, BER_FLAGS_IMPLTAG, dissect_ansi_map_CallRecoveryIDList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CallRecoveryReport_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              CallRecoveryReport_U_set, hf_index, ett_ansi_map_CallRecoveryReport_U);

  return offset;
}



static int
dissect_ansi_map_CallRecoveryReport(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_CallRecoveryReport_U);

  return offset;
}


static const ber_sequence_t TAnswer_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_timeDateOffset, BER_CLASS_CON, 275, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeDateOffset },
  { &hf_ansi_map_timeOfDay  , BER_CLASS_CON, 309, BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeOfDay },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_triggerType, BER_CLASS_CON, 279, BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerType },
  { &hf_ansi_map_winCapability, BER_CLASS_CON, 280, BER_FLAGS_IMPLTAG, dissect_ansi_map_WINCapability },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_featureIndicator, BER_CLASS_CON, 306, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_FeatureIndicator },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_terminationAccessType, BER_CLASS_CON, 119, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationAccessType },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TAnswer_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              TAnswer_U_set, hf_index, ett_ansi_map_TAnswer_U);

  return offset;
}



static int
dissect_ansi_map_TAnswer(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_TAnswer_U);

  return offset;
}


static const ber_sequence_t TDisconnect_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_timeDateOffset, BER_CLASS_CON, 275, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeDateOffset },
  { &hf_ansi_map_timeOfDay  , BER_CLASS_CON, 309, BER_FLAGS_IMPLTAG, dissect_ansi_map_TimeOfDay },
  { &hf_ansi_map_triggerType, BER_CLASS_CON, 279, BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerType },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_callingPartyNumberDigits2, BER_CLASS_CON, 81, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits2 },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_releaseCause, BER_CLASS_CON, 308, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReleaseCause },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TDisconnect_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              TDisconnect_U_set, hf_index, ett_ansi_map_TDisconnect_U);

  return offset;
}



static int
dissect_ansi_map_TDisconnect(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_TDisconnect_U);

  return offset;
}


static const ber_sequence_t TDisconnectRes_U_set[] = {
  { &hf_ansi_map_dmh_ServiceID, BER_CLASS_CON, 305, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ServiceID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_TDisconnectRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              TDisconnectRes_U_set, hf_index, ett_ansi_map_TDisconnectRes_U);

  return offset;
}



static int
dissect_ansi_map_TDisconnectRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_TDisconnectRes_U);

  return offset;
}


static const ber_sequence_t UnreliableCallData_U_set[] = {
  { &hf_ansi_map_controlNetworkID, BER_CLASS_CON, 307, BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlNetworkID },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_UnreliableCallData_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              UnreliableCallData_U_set, hf_index, ett_ansi_map_UnreliableCallData_U);

  return offset;
}



static int
dissect_ansi_map_UnreliableCallData(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_UnreliableCallData_U);

  return offset;
}


static const ber_sequence_t OCalledPartyBusy_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_triggerType, BER_CLASS_CON, 279, BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerType },
  { &hf_ansi_map_winCapability, BER_CLASS_CON, 280, BER_FLAGS_IMPLTAG, dissect_ansi_map_WINCapability },
  { &hf_ansi_map_callingPartyName, BER_CLASS_CON, 243, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyName },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_callingPartyNumberDigits2, BER_CLASS_CON, 81, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_destinationDigits, BER_CLASS_CON, 87, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DestinationDigits },
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_failureCause, BER_CLASS_CON, 387, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_FailureCause },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingPartyName, BER_CLASS_CON, 245, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingPartyName },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_OCalledPartyBusy_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              OCalledPartyBusy_U_set, hf_index, ett_ansi_map_OCalledPartyBusy_U);

  return offset;
}



static int
dissect_ansi_map_OCalledPartyBusy(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_OCalledPartyBusy_U);

  return offset;
}


static const ber_sequence_t OCalledPartyBusyRes_U_set[] = {
  { &hf_ansi_map_actionCode , BER_CLASS_CON, 128, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ActionCode },
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_dmh_ChargeInformation, BER_CLASS_CON, 311, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ChargeInformation },
  { &hf_ansi_map_dmh_RedirectionIndicator, BER_CLASS_CON, 88, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_RedirectionIndicator },
  { &hf_ansi_map_dmh_ServiceID, BER_CLASS_CON, 305, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ServiceID },
  { &hf_ansi_map_noAnswerTime, BER_CLASS_CON, 96, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NoAnswerTime },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_terminationList, BER_CLASS_CON, 120, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationList },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_OCalledPartyBusyRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              OCalledPartyBusyRes_U_set, hf_index, ett_ansi_map_OCalledPartyBusyRes_U);

  return offset;
}



static int
dissect_ansi_map_OCalledPartyBusyRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_OCalledPartyBusyRes_U);

  return offset;
}


static const ber_sequence_t ONoAnswer_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_triggerType, BER_CLASS_CON, 279, BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerType },
  { &hf_ansi_map_winCapability, BER_CLASS_CON, 280, BER_FLAGS_IMPLTAG, dissect_ansi_map_WINCapability },
  { &hf_ansi_map_callingPartyName, BER_CLASS_CON, 243, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyName },
  { &hf_ansi_map_callingPartyNumberDigits1, BER_CLASS_CON, 80, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits1 },
  { &hf_ansi_map_callingPartyNumberDigits2, BER_CLASS_CON, 81, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyNumberDigits2 },
  { &hf_ansi_map_callingPartySubaddress, BER_CLASS_CON, 84, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartySubaddress },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_destinationDigits, BER_CLASS_CON, 87, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DestinationDigits },
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_redirectingPartyName, BER_CLASS_CON, 245, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingPartyName },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ONoAnswer_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ONoAnswer_U_set, hf_index, ett_ansi_map_ONoAnswer_U);

  return offset;
}



static int
dissect_ansi_map_ONoAnswer(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ONoAnswer_U);

  return offset;
}


static const ber_sequence_t ONoAnswerRes_U_set[] = {
  { &hf_ansi_map_actionCode , BER_CLASS_CON, 128, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ActionCode },
  { &hf_ansi_map_announcementList, BER_CLASS_CON, 130, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnnouncementList },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_dmh_ChargeInformation, BER_CLASS_CON, 311, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ChargeInformation },
  { &hf_ansi_map_dmh_RedirectionIndicator, BER_CLASS_CON, 88, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_RedirectionIndicator },
  { &hf_ansi_map_dmh_ServiceID, BER_CLASS_CON, 305, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_ServiceID },
  { &hf_ansi_map_noAnswerTime, BER_CLASS_CON, 96, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NoAnswerTime },
  { &hf_ansi_map_oneTimeFeatureIndicator, BER_CLASS_CON, 97, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OneTimeFeatureIndicator },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_redirectingNumberDigits, BER_CLASS_CON, 100, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RedirectingNumberDigits },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_terminationList, BER_CLASS_CON, 120, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationList },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ONoAnswerRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ONoAnswerRes_U_set, hf_index, ett_ansi_map_ONoAnswerRes_U);

  return offset;
}



static int
dissect_ansi_map_ONoAnswerRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ONoAnswerRes_U);

  return offset;
}



static int
dissect_ansi_map_PositionInformationCode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t PositionRequest_U_set[] = {
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_positionInformationCode, BER_CLASS_CON, 315, BER_FLAGS_IMPLTAG, dissect_ansi_map_PositionInformationCode },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_PositionRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              PositionRequest_U_set, hf_index, ett_ansi_map_PositionRequest_U);

  return offset;
}



static int
dissect_ansi_map_PositionRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_PositionRequest_U);

  return offset;
}



static int
dissect_ansi_map_MSStatus(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t PositionRequestRes_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_extendedMSCID, BER_CLASS_CON, 53, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ExtendedMSCID },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_mSStatus   , BER_CLASS_CON, 313, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSStatus },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_pSID_RSIDInformation, BER_CLASS_CON, 202, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PSID_RSIDInformation },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_PositionRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              PositionRequestRes_U_set, hf_index, ett_ansi_map_PositionRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_PositionRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_PositionRequestRes_U);

  return offset;
}


static const ber_sequence_t PositionRequestForward_U_set[] = {
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_positionInformationCode, BER_CLASS_CON, 315, BER_FLAGS_IMPLTAG, dissect_ansi_map_PositionInformationCode },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_PositionRequestForward_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              PositionRequestForward_U_set, hf_index, ett_ansi_map_PositionRequestForward_U);

  return offset;
}



static int
dissect_ansi_map_PositionRequestForward(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_PositionRequestForward_U);

  return offset;
}


static const ber_sequence_t PositionRequestForwardRes_U_set[] = {
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_mSStatus   , BER_CLASS_CON, 313, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSStatus },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_PositionRequestForwardRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              PositionRequestForwardRes_U_set, hf_index, ett_ansi_map_PositionRequestForwardRes_U);

  return offset;
}



static int
dissect_ansi_map_PositionRequestForwardRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_PositionRequestForwardRes_U);

  return offset;
}


static const ber_sequence_t CallTerminationReport_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_networkTMSI, BER_CLASS_CON, 233, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NetworkTMSI },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CallTerminationReport_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              CallTerminationReport_U_set, hf_index, ett_ansi_map_CallTerminationReport_U);

  return offset;
}



static int
dissect_ansi_map_CallTerminationReport(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_CallTerminationReport_U);

  return offset;
}



static int
dissect_ansi_map_PositionRequestType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_LCSBillingID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_LCS_Client_ID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_DTXIndication(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_TDMA_MAHO_CELLID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_TDMA_MAHO_CHANNEL(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_TDMA_TimeAlignment(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_PQOS_HorizontalPosition(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_PQOS_HorizontalVelocity(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_PQOS_MaximumPositionAge(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_PQOS_PositionPriority(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string ansi_map_PQOS_ResponseTime_vals[] = {
  {   0, "not-used" },
  {   1, "no-Delay" },
  {   2, "low-Delay" },
  {   3, "delay-Tolerant" },
  { 0, NULL }
};


static int
dissect_ansi_map_PQOS_ResponseTime(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_PQOS_VerticalPosition(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_PQOS_VerticalVelocity(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t GeoPositionRequest_U_set[] = {
  { &hf_ansi_map_positionRequestType, BER_CLASS_CON, 337, BER_FLAGS_IMPLTAG, dissect_ansi_map_PositionRequestType },
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_lcsBillingID, BER_CLASS_CON, 367, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LCSBillingID },
  { &hf_ansi_map_lcs_Client_ID, BER_CLASS_CON, 358, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LCS_Client_ID },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_mobilePositionCapability, BER_CLASS_CON, 335, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobilePositionCapability },
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_dtxIndication, BER_CLASS_CON, 329, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DTXIndication },
  { &hf_ansi_map_receivedSignalQuality, BER_CLASS_CON, 72, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReceivedSignalQuality },
  { &hf_ansi_map_cdmaChannelData, BER_CLASS_CON, 63, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelData },
  { &hf_ansi_map_cdmaCodeChannel, BER_CLASS_CON, 68, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMACodeChannel },
  { &hf_ansi_map_cdmaMobileCapabilities, BER_CLASS_CON, 330, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAMobileCapabilities },
  { &hf_ansi_map_cdmaPrivateLongCodeMask, BER_CLASS_CON, 67, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPrivateLongCodeMask },
  { &hf_ansi_map_cdmaServingOneWayDelay2, BER_CLASS_CON, 347, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServingOneWayDelay2 },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_cdmaTargetMAHOList, BER_CLASS_CON, 136, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMAHOList },
  { &hf_ansi_map_cdmaPSMMList, BER_CLASS_CON, 346, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPSMMList },
  { &hf_ansi_map_nampsChannelData, BER_CLASS_CON, 76, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSChannelData },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { &hf_ansi_map_targetMeasurementList, BER_CLASS_CON, 157, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetMeasurementList },
  { &hf_ansi_map_tdma_MAHO_CELLID, BER_CLASS_CON, 359, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMA_MAHO_CELLID },
  { &hf_ansi_map_tdma_MAHO_CHANNEL, BER_CLASS_CON, 360, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMA_MAHO_CHANNEL },
  { &hf_ansi_map_tdma_TimeAlignment, BER_CLASS_CON, 362, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMA_TimeAlignment },
  { &hf_ansi_map_tdmaVoiceMode, BER_CLASS_CON, 223, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAVoiceMode },
  { &hf_ansi_map_voicePrivacyMask, BER_CLASS_CON, 48, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoicePrivacyMask },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_networkTMSI, BER_CLASS_CON, 233, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NetworkTMSI },
  { &hf_ansi_map_pqos_HorizontalPosition, BER_CLASS_CON, 372, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_HorizontalPosition },
  { &hf_ansi_map_pqos_HorizontalVelocity, BER_CLASS_CON, 373, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_HorizontalVelocity },
  { &hf_ansi_map_pqos_MaximumPositionAge, BER_CLASS_CON, 374, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_MaximumPositionAge },
  { &hf_ansi_map_pqos_PositionPriority, BER_CLASS_CON, 375, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_PositionPriority },
  { &hf_ansi_map_pqos_ResponseTime, BER_CLASS_CON, 376, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_ResponseTime },
  { &hf_ansi_map_pqos_VerticalPosition, BER_CLASS_CON, 377, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_VerticalPosition },
  { &hf_ansi_map_pqos_VerticalVelocity, BER_CLASS_CON, 378, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_VerticalVelocity },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_teleservice_Priority, BER_CLASS_CON, 290, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Teleservice_Priority },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_GeoPositionRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              GeoPositionRequest_U_set, hf_index, ett_ansi_map_GeoPositionRequest_U);

  return offset;
}



static int
dissect_ansi_map_GeoPositionRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_GeoPositionRequest_U);

  return offset;
}



static int
dissect_ansi_map_CDMAPSMMCount(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string ansi_map_LIRAuthorization_vals[] = {
  {   0, "not-used" },
  {   1, "user-Authorized" },
  { 0, NULL }
};


static int
dissect_ansi_map_LIRAuthorization(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_ansi_map_MPCID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ansi_map_DigitsType(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_ansi_map_TDMA_MAHORequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t InterSystemPositionRequest_U_set[] = {
  { &hf_ansi_map_positionRequestType, BER_CLASS_CON, 337, BER_FLAGS_IMPLTAG, dissect_ansi_map_PositionRequestType },
  { &hf_ansi_map_actionCode , BER_CLASS_CON, 128, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ActionCode },
  { &hf_ansi_map_cdmaPSMMCount, BER_CLASS_CON, 345, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPSMMCount },
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_emergencyServicesRoutingDigits, BER_CLASS_CON, 239, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_EmergencyServicesRoutingDigits },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_lcsBillingID, BER_CLASS_CON, 367, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LCSBillingID },
  { &hf_ansi_map_lirAuthorization, BER_CLASS_CON, 368, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LIRAuthorization },
  { &hf_ansi_map_lcs_Client_ID, BER_CLASS_CON, 358, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LCS_Client_ID },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_dtxIndication, BER_CLASS_CON, 329, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DTXIndication },
  { &hf_ansi_map_receivedSignalQuality, BER_CLASS_CON, 72, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReceivedSignalQuality },
  { &hf_ansi_map_cdmaChannelData, BER_CLASS_CON, 63, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelData },
  { &hf_ansi_map_cdmaCodeChannel, BER_CLASS_CON, 68, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMACodeChannel },
  { &hf_ansi_map_cdmaMobileCapabilities, BER_CLASS_CON, 330, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAMobileCapabilities },
  { &hf_ansi_map_cdmaPrivateLongCodeMask, BER_CLASS_CON, 67, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPrivateLongCodeMask },
  { &hf_ansi_map_cdmaServingOneWayDelay2, BER_CLASS_CON, 347, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServingOneWayDelay2 },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_cdmaTargetMAHOList, BER_CLASS_CON, 136, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMAHOList },
  { &hf_ansi_map_cdmaPSMMList, BER_CLASS_CON, 346, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPSMMList },
  { &hf_ansi_map_nampsChannelData, BER_CLASS_CON, 76, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSChannelData },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { &hf_ansi_map_targetMeasurementList, BER_CLASS_CON, 157, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetMeasurementList },
  { &hf_ansi_map_tdma_MAHO_CELLID, BER_CLASS_CON, 359, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMA_MAHO_CELLID },
  { &hf_ansi_map_tdma_MAHO_CHANNEL, BER_CLASS_CON, 360, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMA_MAHO_CHANNEL },
  { &hf_ansi_map_tdma_TimeAlignment, BER_CLASS_CON, 362, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMA_TimeAlignment },
  { &hf_ansi_map_tdmaVoiceMode, BER_CLASS_CON, 223, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAVoiceMode },
  { &hf_ansi_map_voicePrivacyMask, BER_CLASS_CON, 48, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoicePrivacyMask },
  { &hf_ansi_map_mobilePositionCapability, BER_CLASS_CON, 335, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobilePositionCapability },
  { &hf_ansi_map_mpcAddress , BER_CLASS_CON, 370, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MPCAddress },
  { &hf_ansi_map_mpcAddressList, BER_CLASS_CON, 381, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MPCAddressList },
  { &hf_ansi_map_mpcid      , BER_CLASS_CON, 371, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MPCID },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_networkTMSI, BER_CLASS_CON, 233, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NetworkTMSI },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { &hf_ansi_map_pqos_HorizontalPosition, BER_CLASS_CON, 372, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_HorizontalPosition },
  { &hf_ansi_map_pqos_HorizontalVelocity, BER_CLASS_CON, 373, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_HorizontalVelocity },
  { &hf_ansi_map_pqos_MaximumPositionAge, BER_CLASS_CON, 374, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_MaximumPositionAge },
  { &hf_ansi_map_pqos_PositionPriority, BER_CLASS_CON, 375, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_PositionPriority },
  { &hf_ansi_map_pqos_ResponseTime, BER_CLASS_CON, 376, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_ResponseTime },
  { &hf_ansi_map_pqos_VerticalPosition, BER_CLASS_CON, 377, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_VerticalPosition },
  { &hf_ansi_map_pqos_VerticalVelocity, BER_CLASS_CON, 378, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_VerticalVelocity },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { &hf_ansi_map_tdma_MAHORequest, BER_CLASS_CON, 364, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMA_MAHORequest },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InterSystemPositionRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InterSystemPositionRequest_U_set, hf_index, ett_ansi_map_InterSystemPositionRequest_U);

  return offset;
}



static int
dissect_ansi_map_InterSystemPositionRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InterSystemPositionRequest_U);

  return offset;
}



static int
dissect_ansi_map_PositionResult(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_GeneralizedTime(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);

  return offset;
}



static int
dissect_ansi_map_GeographicPosition(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_PositionSource(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_Horizontal_Velocity(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_Vertical_Velocity(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t PositionInformation_set[] = {
  { &hf_ansi_map_generalizedTime, BER_CLASS_CON, 331, BER_FLAGS_IMPLTAG, dissect_ansi_map_GeneralizedTime },
  { &hf_ansi_map_geographicPosition, BER_CLASS_CON, 333, BER_FLAGS_IMPLTAG, dissect_ansi_map_GeographicPosition },
  { &hf_ansi_map_positionSource, BER_CLASS_CON, 339, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PositionSource },
  { &hf_ansi_map_horizontal_Velocity, BER_CLASS_CON, 379, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Horizontal_Velocity },
  { &hf_ansi_map_vertical_Velocity, BER_CLASS_CON, 380, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Vertical_Velocity },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_PositionInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              PositionInformation_set, hf_index, ett_ansi_map_PositionInformation);

  return offset;
}


static const ber_sequence_t InterSystemPositionRequestRes_U_set[] = {
  { &hf_ansi_map_positionResult, BER_CLASS_CON, 338, BER_FLAGS_IMPLTAG, dissect_ansi_map_PositionResult },
  { &hf_ansi_map_lcsBillingID, BER_CLASS_CON, 367, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LCSBillingID },
  { &hf_ansi_map_mobilePositionCapability, BER_CLASS_CON, 335, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobilePositionCapability },
  { &hf_ansi_map_channelData, BER_CLASS_CON, 5, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ChannelData },
  { &hf_ansi_map_dtxIndication, BER_CLASS_CON, 329, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DTXIndication },
  { &hf_ansi_map_receivedSignalQuality, BER_CLASS_CON, 72, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReceivedSignalQuality },
  { &hf_ansi_map_cdmaChannelData, BER_CLASS_CON, 63, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAChannelData },
  { &hf_ansi_map_cdmaCodeChannel, BER_CLASS_CON, 68, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMACodeChannel },
  { &hf_ansi_map_cdmaMobileCapabilities, BER_CLASS_CON, 330, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAMobileCapabilities },
  { &hf_ansi_map_cdmaPrivateLongCodeMask, BER_CLASS_CON, 67, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPrivateLongCodeMask },
  { &hf_ansi_map_cdmaServingOneWayDelay2, BER_CLASS_CON, 347, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServingOneWayDelay2 },
  { &hf_ansi_map_cdmaServiceOption, BER_CLASS_CON, 175, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOption },
  { &hf_ansi_map_cdmaTargetMAHOList, BER_CLASS_CON, 136, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMATargetMAHOList },
  { &hf_ansi_map_cdmaPSMMList, BER_CLASS_CON, 346, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAPSMMList },
  { &hf_ansi_map_nampsChannelData, BER_CLASS_CON, 76, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NAMPSChannelData },
  { &hf_ansi_map_tdmaChannelData, BER_CLASS_CON, 28, BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAChannelData },
  { &hf_ansi_map_targetMeasurementList, BER_CLASS_CON, 157, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TargetMeasurementList },
  { &hf_ansi_map_tdma_MAHO_CELLID, BER_CLASS_CON, 359, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMA_MAHO_CELLID },
  { &hf_ansi_map_tdma_MAHO_CHANNEL, BER_CLASS_CON, 360, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMA_MAHO_CHANNEL },
  { &hf_ansi_map_tdma_TimeAlignment, BER_CLASS_CON, 362, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMA_TimeAlignment },
  { &hf_ansi_map_tdmaVoiceMode, BER_CLASS_CON, 223, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMAVoiceMode },
  { &hf_ansi_map_voicePrivacyMask, BER_CLASS_CON, 48, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoicePrivacyMask },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_positionInformation, BER_CLASS_CON, 336, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PositionInformation },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InterSystemPositionRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InterSystemPositionRequestRes_U_set, hf_index, ett_ansi_map_InterSystemPositionRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_InterSystemPositionRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InterSystemPositionRequestRes_U);

  return offset;
}


static const ber_sequence_t InterSystemPositionRequestForward_U_set[] = {
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_positionRequestType, BER_CLASS_CON, 337, BER_FLAGS_IMPLTAG, dissect_ansi_map_PositionRequestType },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_lcsBillingID, BER_CLASS_CON, 367, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LCSBillingID },
  { &hf_ansi_map_lcs_Client_ID, BER_CLASS_CON, 358, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LCS_Client_ID },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_mobilePositionCapability, BER_CLASS_CON, 335, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobilePositionCapability },
  { &hf_ansi_map_mpcid      , BER_CLASS_CON, 371, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MPCID },
  { &hf_ansi_map_pqos_HorizontalPosition, BER_CLASS_CON, 372, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_HorizontalPosition },
  { &hf_ansi_map_pqos_HorizontalVelocity, BER_CLASS_CON, 373, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_HorizontalVelocity },
  { &hf_ansi_map_pqos_MaximumPositionAge, BER_CLASS_CON, 374, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_MaximumPositionAge },
  { &hf_ansi_map_pqos_PositionPriority, BER_CLASS_CON, 375, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_PositionPriority },
  { &hf_ansi_map_pqos_ResponseTime, BER_CLASS_CON, 376, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_ResponseTime },
  { &hf_ansi_map_pqos_VerticalPosition, BER_CLASS_CON, 377, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_VerticalPosition },
  { &hf_ansi_map_pqos_VerticalVelocity, BER_CLASS_CON, 378, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PQOS_VerticalVelocity },
  { &hf_ansi_map_tdma_MAHORequest, BER_CLASS_CON, 364, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMA_MAHORequest },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InterSystemPositionRequestForward_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InterSystemPositionRequestForward_U_set, hf_index, ett_ansi_map_InterSystemPositionRequestForward_U);

  return offset;
}



static int
dissect_ansi_map_InterSystemPositionRequestForward(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InterSystemPositionRequestForward_U);

  return offset;
}


static const ber_sequence_t InterSystemPositionRequestForwardRes_U_set[] = {
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_positionResult, BER_CLASS_CON, 338, BER_FLAGS_IMPLTAG, dissect_ansi_map_PositionResult },
  { &hf_ansi_map_lcsBillingID, BER_CLASS_CON, 367, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LCSBillingID },
  { &hf_ansi_map_positionInformation, BER_CLASS_CON, 336, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PositionInformation },
  { &hf_ansi_map_servingCellID, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServingCellID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InterSystemPositionRequestForwardRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InterSystemPositionRequestForwardRes_U_set, hf_index, ett_ansi_map_InterSystemPositionRequestForwardRes_U);

  return offset;
}



static int
dissect_ansi_map_InterSystemPositionRequestForwardRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InterSystemPositionRequestForwardRes_U);

  return offset;
}



static int
dissect_ansi_map_ControlType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string ansi_map_GapDuration_vals[] = {
  {   0, "not-used" },
  { 0, NULL }
};


static int
dissect_ansi_map_GapDuration(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const value_string ansi_map_SCFOverloadGapInterval_vals[] = {
  {   0, "not-used" },
  { 0, NULL }
};


static int
dissect_ansi_map_SCFOverloadGapInterval(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const value_string ansi_map_ServiceManagementSystemGapInterval_vals[] = {
  {   0, "not-used" },
  { 0, NULL }
};


static int
dissect_ansi_map_ServiceManagementSystemGapInterval(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const value_string ansi_map_GapInterval_vals[] = {
  { 343, "sCFOverloadGapInterval" },
  { 344, "serviceManagementSystemGapInterval" },
  { 0, NULL }
};

static const ber_choice_t GapInterval_choice[] = {
  { 343, &hf_ansi_map_sCFOverloadGapInterval, BER_CLASS_CON, 343, BER_FLAGS_IMPLTAG, dissect_ansi_map_SCFOverloadGapInterval },
  { 344, &hf_ansi_map_serviceManagementSystemGapInterval, BER_CLASS_CON, 344, BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceManagementSystemGapInterval },
  { 0, NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_GapInterval(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 GapInterval_choice, hf_index, ett_ansi_map_GapInterval,
                                 NULL);

  return offset;
}


static const ber_sequence_t ACGDirective_U_set[] = {
  { &hf_ansi_map_controlType, BER_CLASS_CON, 341, BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlType },
  { &hf_ansi_map_destinationAddress, BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_DestinationAddress },
  { &hf_ansi_map_gapDuration, BER_CLASS_CON, 342, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GapDuration },
  { &hf_ansi_map_gapInterval, BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_GapInterval },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_ACGDirective_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              ACGDirective_U_set, hf_index, ett_ansi_map_ACGDirective_U);

  return offset;
}



static int
dissect_ansi_map_ACGDirective(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_ACGDirective_U);

  return offset;
}



static int
dissect_ansi_map_InvokingNEType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}



static int
dissect_ansi_map_Range(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}


static const ber_sequence_t RoamerDatabaseVerificationRequest_U_set[] = {
  { &hf_ansi_map_invokingNEType, BER_CLASS_CON, 353, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_InvokingNEType },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_range      , BER_CLASS_CON, 352, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Range },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_RoamerDatabaseVerificationRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              RoamerDatabaseVerificationRequest_U_set, hf_index, ett_ansi_map_RoamerDatabaseVerificationRequest_U);

  return offset;
}



static int
dissect_ansi_map_RoamerDatabaseVerificationRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_RoamerDatabaseVerificationRequest_U);

  return offset;
}


static const ber_sequence_t RoamerDatabaseVerificationRequestRes_U_set[] = {
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_RoamerDatabaseVerificationRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              RoamerDatabaseVerificationRequestRes_U_set, hf_index, ett_ansi_map_RoamerDatabaseVerificationRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_RoamerDatabaseVerificationRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_RoamerDatabaseVerificationRequestRes_U);

  return offset;
}


static const ber_sequence_t LCSParameterRequest_U_set[] = {
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mpcid      , BER_CLASS_CON, 371, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MPCID },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_LCSParameterRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              LCSParameterRequest_U_set, hf_index, ett_ansi_map_LCSParameterRequest_U);

  return offset;
}



static int
dissect_ansi_map_LCSParameterRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_LCSParameterRequest_U);

  return offset;
}


static const ber_sequence_t LCSParameterRequestRes_U_set[] = {
  { &hf_ansi_map_accessDeniedReason, BER_CLASS_CON, 20, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AccessDeniedReason },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_mobilePositionCapability, BER_CLASS_CON, 335, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobilePositionCapability },
  { &hf_ansi_map_mpcAddress , BER_CLASS_CON, 370, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MPCAddress },
  { &hf_ansi_map_mpcAddressList, BER_CLASS_CON, 381, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MPCAddressList },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_pc_ssn     , BER_CLASS_CON, 32, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PC_SSN },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_LCSParameterRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              LCSParameterRequestRes_U_set, hf_index, ett_ansi_map_LCSParameterRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_LCSParameterRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_LCSParameterRequestRes_U);

  return offset;
}


static const ber_sequence_t CheckMEID_U_set[] = {
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_confidentialityModes, BER_CLASS_CON, 39, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ConfidentialityModes },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_emergencyServicesRoutingDigits, BER_CLASS_CON, 239, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_EmergencyServicesRoutingDigits },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CheckMEID_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              CheckMEID_U_set, hf_index, ett_ansi_map_CheckMEID_U);

  return offset;
}



static int
dissect_ansi_map_CheckMEID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_CheckMEID_U);

  return offset;
}



static int
dissect_ansi_map_MEIDStatus(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t CheckMEIDRes_U_set[] = {
  { &hf_ansi_map_meidStatus , BER_CLASS_CON, 391, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEIDStatus },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_CheckMEIDRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              CheckMEIDRes_U_set, hf_index, ett_ansi_map_CheckMEIDRes_U);

  return offset;
}



static int
dissect_ansi_map_CheckMEIDRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_CheckMEIDRes_U);

  return offset;
}


static const ber_sequence_t AddService_U_set[] = {
  { &hf_ansi_map_cdmaConnectionReferenceList, BER_CLASS_CON, 212, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAConnectionReferenceList },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AddService_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              AddService_U_set, hf_index, ett_ansi_map_AddService_U);

  return offset;
}



static int
dissect_ansi_map_AddService(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_AddService_U);

  return offset;
}


static const ber_sequence_t AddServiceRes_U_set[] = {
  { &hf_ansi_map_cdmaConnectionReferenceList, BER_CLASS_CON, 212, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAConnectionReferenceList },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_qosPriority, BER_CLASS_CON, 348, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_QoSPriority },
  { &hf_ansi_map_reasonList , BER_CLASS_CON, 218, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReasonList },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_AddServiceRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              AddServiceRes_U_set, hf_index, ett_ansi_map_AddServiceRes_U);

  return offset;
}



static int
dissect_ansi_map_AddServiceRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_AddServiceRes_U);

  return offset;
}


static const ber_sequence_t DropService_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { &hf_ansi_map_cdmaConnectionReferenceList, BER_CLASS_CON, 212, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAConnectionReferenceList },
  { &hf_ansi_map_interMSCCircuitID, BER_CLASS_CON, 6, BER_FLAGS_IMPLTAG, dissect_ansi_map_InterMSCCircuitID },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_releaseReason, BER_CLASS_CON, 10, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ReleaseReason },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_DropService_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              DropService_U_set, hf_index, ett_ansi_map_DropService_U);

  return offset;
}



static int
dissect_ansi_map_DropService(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_DropService_U);

  return offset;
}


static const ber_sequence_t DropServiceRes_U_set[] = {
  { &hf_ansi_map_billingID  , BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BillingID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_DropServiceRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              DropServiceRes_U_set, hf_index, ett_ansi_map_DropServiceRes_U);

  return offset;
}



static int
dissect_ansi_map_DropServiceRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_DropServiceRes_U);

  return offset;
}


static const ber_sequence_t PositionEventNotification_U_set[] = {
  { &hf_ansi_map_positionResult, BER_CLASS_CON, 338, BER_FLAGS_IMPLTAG, dissect_ansi_map_PositionResult },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_lcsBillingID, BER_CLASS_CON, 367, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LCSBillingID },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_PositionEventNotification_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              PositionEventNotification_U_set, hf_index, ett_ansi_map_PositionEventNotification_U);

  return offset;
}



static int
dissect_ansi_map_PositionEventNotification(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_PositionEventNotification_U);

  return offset;
}



static int
dissect_ansi_map_AKeyProtocolVersion(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_MobileStationPartialKey(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string ansi_map_NewlyAssignedMSID_vals[] = {
  { 187, "newlyAssignedMIN" },
  { 287, "newlyAssignedIMSI" },
  { 0, NULL }
};

static const ber_choice_t NewlyAssignedMSID_choice[] = {
  { 187, &hf_ansi_map_newlyAssignedMIN, BER_CLASS_CON, 187, BER_FLAGS_IMPLTAG, dissect_ansi_map_NewlyAssignedMIN },
  { 287, &hf_ansi_map_newlyAssignedIMSI, BER_CLASS_CON, 287, BER_FLAGS_IMPLTAG, dissect_ansi_map_NewlyAssignedIMSI },
  { 0, NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_NewlyAssignedMSID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 NewlyAssignedMSID_choice, hf_index, ett_ansi_map_NewlyAssignedMSID,
                                 NULL);

  return offset;
}


static const ber_sequence_t OTASPRequest_U_set[] = {
  { &hf_ansi_map_actionCode , BER_CLASS_CON, 128, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ActionCode },
  { &hf_ansi_map_aKeyProtocolVersion, BER_CLASS_CON, 181, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AKeyProtocolVersion },
  { &hf_ansi_map_authenticationData, BER_CLASS_CON, 161, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationData },
  { &hf_ansi_map_authenticationResponse, BER_CLASS_CON, 35, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationResponse },
  { &hf_ansi_map_callHistoryCount, BER_CLASS_CON, 38, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallHistoryCount },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_mobileStationMSID, BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MobileStationMSID },
  { &hf_ansi_map_mobileStationPartialKey, BER_CLASS_CON, 185, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileStationPartialKey },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_newlyAssignedMSID, BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_NewlyAssignedMSID },
  { &hf_ansi_map_randomVariable, BER_CLASS_CON, 40, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariable },
  { &hf_ansi_map_randomVariableBaseStation, BER_CLASS_CON, 41, BER_FLAGS_IMPLTAG, dissect_ansi_map_RandomVariableBaseStation },
  { &hf_ansi_map_serviceIndicator, BER_CLASS_CON, 193, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceIndicator },
  { &hf_ansi_map_systemCapabilities, BER_CLASS_CON, 49, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemCapabilities },
  { &hf_ansi_map_terminalType, BER_CLASS_CON, 47, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminalType },
  { &hf_ansi_map_meid       , BER_CLASS_CON, 390, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_OTASPRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              OTASPRequest_U_set, hf_index, ett_ansi_map_OTASPRequest_U);

  return offset;
}



static int
dissect_ansi_map_OTASPRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_OTASPRequest_U);

  return offset;
}



static int
dissect_ansi_map_BaseStationPartialKey(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_ModulusValue(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_OTASP_ResultCode(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_ansi_map_PrimitiveValue(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t OTASPRequestRes_U_set[] = {
  { &hf_ansi_map_aKeyProtocolVersion, BER_CLASS_CON, 181, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AKeyProtocolVersion },
  { &hf_ansi_map_authenticationResponseBaseStation, BER_CLASS_CON, 36, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationResponseBaseStation },
  { &hf_ansi_map_baseStationPartialKey, BER_CLASS_CON, 183, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_BaseStationPartialKey },
  { &hf_ansi_map_denyAccess , BER_CLASS_CON, 50, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DenyAccess },
  { &hf_ansi_map_modulusValue, BER_CLASS_CON, 186, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ModulusValue },
  { &hf_ansi_map_otasp_ResultCode, BER_CLASS_CON, 189, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OTASP_ResultCode },
  { &hf_ansi_map_primitiveValue, BER_CLASS_CON, 190, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PrimitiveValue },
  { &hf_ansi_map_signalingMessageEncryptionReport, BER_CLASS_CON, 194, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SignalingMessageEncryptionReport },
  { &hf_ansi_map_ssdUpdateReport, BER_CLASS_CON, 156, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SSDUpdateReport },
  { &hf_ansi_map_uniqueChallengeReport, BER_CLASS_CON, 124, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UniqueChallengeReport },
  { &hf_ansi_map_voicePrivacyReport, BER_CLASS_CON, 196, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_VoicePrivacyReport },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_OTASPRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              OTASPRequestRes_U_set, hf_index, ett_ansi_map_OTASPRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_OTASPRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_OTASPRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_Record_Type(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t StatusRequest_U_set[] = {
  { &hf_ansi_map_msid       , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_ansi_map_MSID },
  { &hf_ansi_map_record_Type, BER_CLASS_CON, 392, BER_FLAGS_IMPLTAG, dissect_ansi_map_Record_Type },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_StatusRequest_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              StatusRequest_U_set, hf_index, ett_ansi_map_StatusRequest_U);

  return offset;
}



static int
dissect_ansi_map_StatusRequest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_StatusRequest_U);

  return offset;
}



static int
dissect_ansi_map_Information_Record(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t StatusRequestRes_U_set[] = {
  { &hf_ansi_map_information_Record, BER_CLASS_CON, 389, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Information_Record },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_StatusRequestRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              StatusRequestRes_U_set, hf_index, ett_ansi_map_StatusRequestRes_U);

  return offset;
}



static int
dissect_ansi_map_StatusRequestRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_StatusRequestRes_U);

  return offset;
}


static const ber_sequence_t InterSystemSMSDeliveryPointToPoint_U_set[] = {
  { &hf_ansi_map_sms_BearerData, BER_CLASS_CON, 105, BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_BearerData },
  { &hf_ansi_map_sms_TeleserviceIdentifier, BER_CLASS_CON, 116, BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_TeleserviceIdentifier },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_signalingMessageEncryptionKey, BER_CLASS_CON, 45, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SignalingMessageEncryptionKey },
  { &hf_ansi_map_sms_MessageCount, BER_CLASS_CON, 108, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_MessageCount },
  { &hf_ansi_map_sms_OriginalOriginatingAddress, BER_CLASS_CON, 112, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalOriginatingAddress },
  { &hf_ansi_map_sms_OriginalOriginatingSubaddress, BER_CLASS_CON, 113, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalOriginatingSubaddress },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InterSystemSMSDeliveryPointToPoint_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InterSystemSMSDeliveryPointToPoint_U_set, hf_index, ett_ansi_map_InterSystemSMSDeliveryPointToPoint_U);

  return offset;
}



static int
dissect_ansi_map_InterSystemSMSDeliveryPointToPoint(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InterSystemSMSDeliveryPointToPoint_U);

  return offset;
}


static const ber_sequence_t InterSystemSMSDeliveryPointToPointRes_U_set[] = {
  { &hf_ansi_map_sms_BearerData, BER_CLASS_CON, 105, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_BearerData },
  { &hf_ansi_map_sms_CauseCode, BER_CLASS_CON, 153, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_CauseCode },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InterSystemSMSDeliveryPointToPointRes_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InterSystemSMSDeliveryPointToPointRes_U_set, hf_index, ett_ansi_map_InterSystemSMSDeliveryPointToPointRes_U);

  return offset;
}



static int
dissect_ansi_map_InterSystemSMSDeliveryPointToPointRes(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InterSystemSMSDeliveryPointToPointRes_U);

  return offset;
}



static int
dissect_ansi_map_CDMA2000MobileSupportedCapabilities(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t InterSystemSMSPage_U_set[] = {
  { &hf_ansi_map_sms_BearerData, BER_CLASS_CON, 105, BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_BearerData },
  { &hf_ansi_map_sms_TeleserviceIdentifier, BER_CLASS_CON, 116, BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_TeleserviceIdentifier },
  { &hf_ansi_map_cdma2000MobileSupportedCapabilities, BER_CLASS_CON, 321, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMA2000MobileSupportedCapabilities },
  { &hf_ansi_map_cdmaSlotCycleIndex, BER_CLASS_CON, 166, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMASlotCycleIndex },
  { &hf_ansi_map_cdmaStationClassMark2, BER_CLASS_CON, 177, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAStationClassMark2 },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_networkTMSI, BER_CLASS_CON, 233, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NetworkTMSI },
  { &hf_ansi_map_pageIndicator, BER_CLASS_CON, 71, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PageIndicator },
  { &hf_ansi_map_pageResponseTime, BER_CLASS_CON, 301, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PageResponseTime },
  { &hf_ansi_map_sms_ChargeIndicator, BER_CLASS_CON, 106, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_ChargeIndicator },
  { &hf_ansi_map_sms_DestinationAddress, BER_CLASS_CON, 107, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_DestinationAddress },
  { &hf_ansi_map_sms_OriginalDestinationAddress, BER_CLASS_CON, 110, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalDestinationAddress },
  { &hf_ansi_map_sms_OriginalDestinationSubaddress, BER_CLASS_CON, 111, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalDestinationSubaddress },
  { &hf_ansi_map_sms_OriginalOriginatingAddress, BER_CLASS_CON, 112, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalOriginatingAddress },
  { &hf_ansi_map_sms_OriginalOriginatingSubaddress, BER_CLASS_CON, 113, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginalOriginatingSubaddress },
  { &hf_ansi_map_sms_OriginatingAddress, BER_CLASS_CON, 114, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginatingAddress },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_InterSystemSMSPage_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              InterSystemSMSPage_U_set, hf_index, ett_ansi_map_InterSystemSMSPage_U);

  return offset;
}



static int
dissect_ansi_map_InterSystemSMSPage(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_InterSystemSMSPage_U);

  return offset;
}


static const ber_sequence_t QualificationRequest2_U_set[] = {
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_qualificationInformationCode, BER_CLASS_CON, 17, BER_FLAGS_IMPLTAG, dissect_ansi_map_QualificationInformationCode },
  { &hf_ansi_map_systemAccessType, BER_CLASS_CON, 34, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemAccessType },
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_transactionCapability, BER_CLASS_CON, 123, BER_FLAGS_IMPLTAG, dissect_ansi_map_TransactionCapability },
  { &hf_ansi_map_cdmaNetworkIdentification, BER_CLASS_CON, 232, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMANetworkIdentification },
  { &hf_ansi_map_controlChannelMode, BER_CLASS_CON, 199, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlChannelMode },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_locationAreaID, BER_CLASS_CON, 33, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LocationAreaID },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mSCIdentificationNumber, BER_CLASS_CON, 94, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCIdentificationNumber },
  { &hf_ansi_map_nonPublicData, BER_CLASS_CON, 200, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NonPublicData },
  { &hf_ansi_map_serviceRedirectionCause, BER_CLASS_CON, 237, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceRedirectionCause },
  { &hf_ansi_map_senderIdentificationNumber, BER_CLASS_CON, 103, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SenderIdentificationNumber },
  { &hf_ansi_map_terminalType, BER_CLASS_CON, 47, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminalType },
  { &hf_ansi_map_userGroup  , BER_CLASS_CON, 208, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UserGroup },
  { &hf_ansi_map_userZoneData, BER_CLASS_CON, 209, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UserZoneData },
  { &hf_ansi_map_winCapability, BER_CLASS_CON, 280, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_WINCapability },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_QualificationRequest2_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              QualificationRequest2_U_set, hf_index, ett_ansi_map_QualificationRequest2_U);

  return offset;
}



static int
dissect_ansi_map_QualificationRequest2(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_QualificationRequest2_U);

  return offset;
}


static const ber_sequence_t QualificationRequest2Res_U_set[] = {
  { &hf_ansi_map_systemMyTypeCode, BER_CLASS_CON, 22, BER_FLAGS_IMPLTAG, dissect_ansi_map_SystemMyTypeCode },
  { &hf_ansi_map_analogRedirectRecord, BER_CLASS_CON, 225, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AnalogRedirectRecord },
  { &hf_ansi_map_authorizationDenied, BER_CLASS_CON, 13, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthorizationDenied },
  { &hf_ansi_map_authorizationPeriod, BER_CLASS_CON, 14, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthorizationPeriod },
  { &hf_ansi_map_cdmaRedirectRecord, BER_CLASS_CON, 229, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMARedirectRecord },
  { &hf_ansi_map_controlChannelMode, BER_CLASS_CON, 199, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlChannelMode },
  { &hf_ansi_map_deniedAuthorizationPeriod, BER_CLASS_CON, 167, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DeniedAuthorizationPeriod },
  { &hf_ansi_map_digits     , BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_Digits },
  { &hf_ansi_map_electronicSerialNumber, BER_CLASS_CON, 9, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ElectronicSerialNumber },
  { &hf_ansi_map_imsi       , BER_CLASS_CON, 242, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_gsm_map_IMSI },
  { &hf_ansi_map_mobileIdentificationNumber, BER_CLASS_CON, 8, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileIdentificationNumber },
  { &hf_ansi_map_mscid      , BER_CLASS_CON, 21, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MSCID },
  { &hf_ansi_map_authenticationCapability, BER_CLASS_CON, 78, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_AuthenticationCapability },
  { &hf_ansi_map_callingFeaturesIndicator, BER_CLASS_CON, 25, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingFeaturesIndicator },
  { &hf_ansi_map_carrierDigits, BER_CLASS_CON, 86, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CarrierDigits },
  { &hf_ansi_map_cdmaServiceOptionList, BER_CLASS_CON, 176, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CDMAServiceOptionList },
  { &hf_ansi_map_controlNetworkID, BER_CLASS_CON, 307, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ControlNetworkID },
  { &hf_ansi_map_dmh_AccountCodeDigits, BER_CLASS_CON, 140, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AccountCodeDigits },
  { &hf_ansi_map_dmh_AlternateBillingDigits, BER_CLASS_CON, 141, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_AlternateBillingDigits },
  { &hf_ansi_map_dmh_BillingDigits, BER_CLASS_CON, 142, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_DMH_BillingDigits },
  { &hf_ansi_map_geographicAuthorization, BER_CLASS_CON, 143, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_GeographicAuthorization },
  { &hf_ansi_map_meidValidated, BER_CLASS_CON, 401, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MEIDValidated },
  { &hf_ansi_map_messageWaitingNotificationCount, BER_CLASS_CON, 92, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MessageWaitingNotificationCount },
  { &hf_ansi_map_messageWaitingNotificationType, BER_CLASS_CON, 145, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MessageWaitingNotificationType },
  { &hf_ansi_map_mobileDirectoryNumber, BER_CLASS_CON, 93, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobileDirectoryNumber },
  { &hf_ansi_map_mobilePositionCapability, BER_CLASS_CON, 335, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_MobilePositionCapability },
  { &hf_ansi_map_originationIndicator, BER_CLASS_CON, 23, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OriginationIndicator },
  { &hf_ansi_map_originationTriggers, BER_CLASS_CON, 98, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_OriginationTriggers },
  { &hf_ansi_map_pACAIndicator, BER_CLASS_CON, 146, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PACAIndicator },
  { &hf_ansi_map_preferredLanguageIndicator, BER_CLASS_CON, 147, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PreferredLanguageIndicator },
  { &hf_ansi_map_qosPriority, BER_CLASS_CON, 348, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_QoSPriority },
  { &hf_ansi_map_restrictionDigits, BER_CLASS_CON, 227, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RestrictionDigits },
  { &hf_ansi_map_routingDigits, BER_CLASS_CON, 150, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoutingDigits },
  { &hf_ansi_map_pSID_RSIDList, BER_CLASS_CON, 203, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_PSID_RSIDList },
  { &hf_ansi_map_sms_OriginationRestrictions, BER_CLASS_CON, 115, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_OriginationRestrictions },
  { &hf_ansi_map_sms_TerminationRestrictions, BER_CLASS_CON, 117, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SMS_TerminationRestrictions },
  { &hf_ansi_map_spinipin   , BER_CLASS_CON, 154, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SPINIPIN },
  { &hf_ansi_map_spiniTriggers, BER_CLASS_CON, 155, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_SPINITriggers },
  { &hf_ansi_map_tdmaDataFeaturesIndicator, BER_CLASS_CON, 221, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TDMADataFeaturesIndicator },
  { &hf_ansi_map_terminationRestrictionCode, BER_CLASS_CON, 24, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationRestrictionCode },
  { &hf_ansi_map_terminationTriggers, BER_CLASS_CON, 122, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TerminationTriggers },
  { &hf_ansi_map_triggerAddressList, BER_CLASS_CON, 276, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_TriggerAddressList },
  { &hf_ansi_map_userGroup  , BER_CLASS_CON, 208, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UserGroup },
  { &hf_ansi_map_nonPublicData, BER_CLASS_CON, 200, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_NonPublicData },
  { &hf_ansi_map_userZoneData, BER_CLASS_CON, 209, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_UserZoneData },
  { &hf_ansi_map_callingPartyCategory, BER_CLASS_CON, 355, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_CallingPartyCategory },
  { &hf_ansi_map_lirMode    , BER_CLASS_CON, 369, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_LIRMode },
  { &hf_ansi_map_roamingIndication, BER_CLASS_CON, 239, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_RoamingIndication },
  { &hf_ansi_map_serviceRedirectionInfo, BER_CLASS_CON, 238, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_ansi_map_ServiceRedirectionInfo },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_ansi_map_QualificationRequest2Res_U(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_set(implicit_tag, actx, tree, tvb, offset,
                              QualificationRequest2Res_U_set, hf_index, ett_ansi_map_QualificationRequest2Res_U);

  return offset;
}



static int
dissect_ansi_map_QualificationRequest2Res(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
                                      hf_index, BER_CLASS_PRI, 18, false, dissect_ansi_map_QualificationRequest2Res_U);

  return offset;
}




/*
 * 6.5.2.dk N.S0013-0 v 1.0,X.S0004-550-E v1.0 2.301
 */
static void
dissect_ansi_map_win_trigger_list(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, asn1_ctx_t *actx _U_){

    int offset = 0;
    int end_offset = 0;
    int j = 0;
    proto_tree *subtree;
    uint8_t octet;

    end_offset = tvb_reported_length_remaining(tvb,offset);
    subtree = proto_item_add_subtree(actx->created_item, ett_win_trigger_list);

    while(offset< end_offset) {
        octet = tvb_get_uint8(tvb,offset);
        switch (octet){
        case 0xdc:
            proto_tree_add_uint_format(subtree, hf_ansi_map_win_trigger_list, tvb, offset, 1, octet, "TDP-R's armed");
            j=0;
            break;
        case 0xdd:
            proto_tree_add_uint_format(subtree, hf_ansi_map_win_trigger_list, tvb, offset, 1, octet, "TDP-N's armed");
            j=0;
            break;
        case 0xde:
            proto_tree_add_uint_format(subtree, hf_ansi_map_win_trigger_list, tvb, offset, 1, octet, "EDP-R's armed");
            j=0;
            break;
        case 0xdf:
            proto_tree_add_uint_format(subtree, hf_ansi_map_win_trigger_list, tvb, offset, 1, octet, "EDP-N's armed");
            j=0;
            break;
        default:
            proto_tree_add_uint_format(subtree, hf_ansi_map_win_trigger_list, tvb, offset, 1, octet, "[%u] (%u) %s",j,octet,val_to_str_ext(octet, &ansi_map_TriggerType_vals_ext, "Unknown TriggerType (%u)"));
            j++;
            break;
        }
        offset++;
    }
}


static int dissect_invokeData(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx) {
    static bool                   opCodeKnown = true;
    static ansi_map_tap_rec_t     tap_rec[16];
    static ansi_map_tap_rec_t     *tap_p;
    static int                    tap_current=0;

    /*
     * set tap record pointer
     */
    tap_current++;
    if (tap_current == array_length(tap_rec))
    {
        tap_current = 0;
    }
    tap_p = &tap_rec[tap_current];

    switch(OperationCode){
    case 1: /*Handoff Measurement Request*/
        offset = dissect_ansi_map_HandoffMeasurementRequest(true, tvb, offset, actx, tree, hf_ansi_map_handoffMeasurementRequest);
        break;
    case 2: /*Facilities Directive*/
        offset = dissect_ansi_map_FacilitiesDirective(true, tvb, offset, actx, tree, hf_ansi_map_facilitiesDirective);
        break;
    case 3: /*Mobile On Channel*/
        proto_tree_add_expert(tree, actx->pinfo, &ei_ansi_map_no_data, tvb, offset, -1);
        break;
    case 4: /*Handoff Back*/
        offset = dissect_ansi_map_HandoffBack(true, tvb, offset, actx, tree, hf_ansi_map_handoffBack);
        break;
    case 5: /*Facilities Release*/
        offset = dissect_ansi_map_FacilitiesRelease(true, tvb, offset, actx, tree, hf_ansi_map_facilitiesRelease);
        break;
    case 6: /*Qualification Request*/
        offset = dissect_ansi_map_QualificationRequest(true, tvb, offset, actx, tree, hf_ansi_map_qualificationRequest);
        break;
    case 7: /*Qualification Directive*/
        offset = dissect_ansi_map_QualificationDirective(true, tvb, offset, actx, tree, hf_ansi_map_qualificationDirective);
        break;
    case 8: /*Blocking*/
        offset = dissect_ansi_map_Blocking(true, tvb, offset, actx, tree, hf_ansi_map_blocking);
        break;
    case 9: /*Unblocking*/
        offset = dissect_ansi_map_Unblocking(true, tvb, offset, actx, tree, hf_ansi_map_unblocking);
        break;
    case 10: /*Reset Circuit*/
        offset = dissect_ansi_map_ResetCircuit(true, tvb, offset, actx, tree, hf_ansi_map_resetCircuit);
        break;
    case 11: /*Trunk Test*/
        offset = dissect_ansi_map_TrunkTest(true, tvb, offset, actx, tree, hf_ansi_map_trunkTest);
        break;
    case 12: /*Trunk Test Disconnect*/
        offset = dissect_ansi_map_TrunkTestDisconnect(true, tvb, offset, actx, tree, hf_ansi_map_trunkTestDisconnect);
        break;
    case  13: /*Registration Notification*/
        offset = dissect_ansi_map_RegistrationNotification(true, tvb, offset, actx, tree, hf_ansi_map_registrationNotification);
        break;
    case  14: /*Registration Cancellation*/
        offset = dissect_ansi_map_RegistrationCancellation(true, tvb, offset, actx, tree, hf_ansi_map_registrationCancellation);
        break;
    case  15: /*Location Request*/
        offset = dissect_ansi_map_LocationRequest(true, tvb, offset, actx, tree, hf_ansi_map_locationRequest);
        break;
    case  16: /*Routing Request*/
        offset = dissect_ansi_map_RoutingRequest(true, tvb, offset, actx, tree, hf_ansi_map_routingRequest);
        break;
    case  17: /*Feature Request*/
        offset = dissect_ansi_map_FeatureRequest(true, tvb, offset, actx, tree, hf_ansi_map_featureRequest);
        break;
    case  18: /*Reserved 18 (Service Profile Request, IS-41-C)*/
        proto_tree_add_expert_format(tree, actx->pinfo, &ei_ansi_map_unknown_invokeData_blob, tvb, offset, -1, "Unknown invokeData blob(18 (Service Profile Request, IS-41-C)");
        break;
    case  19: /*Reserved 19 (Service Profile Directive, IS-41-C)*/
        proto_tree_add_expert_format(tree, actx->pinfo, &ei_ansi_map_unknown_invokeData_blob, tvb, offset, -1, "Unknown invokeData blob(19 Service Profile Directive, IS-41-C)");
        break;
    case  20: /*Unreliable Roamer Data Directive*/
        offset = dissect_ansi_map_UnreliableRoamerDataDirective(true, tvb, offset, actx, tree, hf_ansi_map_unreliableRoamerDataDirective);
        break;
    case  21: /*Reserved 21 (Call Data Request, IS-41-C)*/
        proto_tree_add_expert_format(tree, actx->pinfo, &ei_ansi_map_unknown_invokeData_blob, tvb, offset, -1, "Unknown invokeData blob(Reserved 21 (Call Data Request, IS-41-C)");
        break;
    case  22: /*MS Inactive*/
        offset = dissect_ansi_map_MSInactive(true, tvb, offset, actx, tree, hf_ansi_map_mSInactive);
        break;
    case  23: /*Transfer To Number Request*/
        offset = dissect_ansi_map_TransferToNumberRequest(true, tvb, offset, actx, tree, hf_ansi_map_transferToNumberRequest);
        break;
    case  24: /*Redirection Request*/
        offset = dissect_ansi_map_RedirectionRequest(true, tvb, offset, actx, tree, hf_ansi_map_redirectionRequest);
        break;
    case  25: /*Handoff To Third*/
        offset = dissect_ansi_map_HandoffToThird(true, tvb, offset, actx, tree, hf_ansi_map_handoffToThird);
        break;
    case  26: /*Flash Request*/
        offset = dissect_ansi_map_FlashRequest(true, tvb, offset, actx, tree, hf_ansi_map_flashRequest);
        break;
    case  27: /*Authentication Directive*/
        offset = dissect_ansi_map_AuthenticationDirective(true, tvb, offset, actx, tree, hf_ansi_map_authenticationDirective);
        break;
    case  28: /*Authentication Request*/
        offset = dissect_ansi_map_AuthenticationRequest(true, tvb, offset, actx, tree, hf_ansi_map_authenticationRequest);
        break;
    case  29: /*Base Station Challenge*/
        offset = dissect_ansi_map_BaseStationChallenge(true, tvb, offset, actx, tree, hf_ansi_map_baseStationChallenge);
        break;
    case  30: /*Authentication Failure Report*/
        offset = dissect_ansi_map_AuthenticationFailureReport(true, tvb, offset, actx, tree, hf_ansi_map_authenticationFailureReport);
        break;
    case  31: /*Count Request*/
        offset = dissect_ansi_map_CountRequest(true, tvb, offset, actx, tree, hf_ansi_map_countRequest);
        break;
    case  32: /*Inter System Page*/
        offset = dissect_ansi_map_InterSystemPage(true, tvb, offset, actx, tree, hf_ansi_map_interSystemPage);
        break;
    case  33: /*Unsolicited Response*/
        offset = dissect_ansi_map_UnsolicitedResponse(true, tvb, offset, actx, tree, hf_ansi_map_unsolicitedResponse);
        break;
    case  34: /*Bulk Deregistration*/
        offset = dissect_ansi_map_BulkDeregistration(true, tvb, offset, actx, tree, hf_ansi_map_bulkDeregistration);
        break;
    case  35: /*Handoff Measurement Request 2*/
        offset = dissect_ansi_map_HandoffMeasurementRequest2(true, tvb, offset, actx, tree, hf_ansi_map_handoffMeasurementRequest2);
        break;
    case  36: /*Facilities Directive 2*/
        offset = dissect_ansi_map_FacilitiesDirective2(true, tvb, offset, actx, tree, hf_ansi_map_facilitiesDirective2);
        break;
    case  37: /*Handoff Back 2*/
        offset = dissect_ansi_map_HandoffBack2(true, tvb, offset, actx, tree, hf_ansi_map_handoffBack2);
        break;
    case  38: /*Handoff To Third 2*/
        offset = dissect_ansi_map_HandoffToThird2(true, tvb, offset, actx, tree, hf_ansi_map_handoffToThird2);
        break;
    case  39: /*Authentication Directive Forward*/
        offset = dissect_ansi_map_AuthenticationDirectiveForward(true, tvb, offset, actx, tree, hf_ansi_map_authenticationDirectiveForward);
        break;
    case  40: /*Authentication Status Report*/
        offset = dissect_ansi_map_AuthenticationStatusReport(true, tvb, offset, actx, tree, hf_ansi_map_authenticationStatusReport);
        break;
    case  41: /*Reserved 41*/
        proto_tree_add_expert_format(tree, actx->pinfo, &ei_ansi_map_unknown_invokeData_blob, tvb, offset, -1, "Reserved 41, Unknown invokeData blob");
        break;
    case  42: /*Information Directive*/
        offset = dissect_ansi_map_InformationDirective(true, tvb, offset, actx, tree, hf_ansi_map_informationDirective);
        break;
    case  43: /*Information Forward*/
        offset = dissect_ansi_map_InformationForward(true, tvb, offset, actx, tree, hf_ansi_map_informationForward);
        break;
    case  44: /*Inter System Answer*/
        offset = dissect_ansi_map_InterSystemAnswer(true, tvb, offset, actx, tree, hf_ansi_map_interSystemAnswer);
        break;
    case  45: /*Inter System Page 2*/
        offset = dissect_ansi_map_InterSystemPage2(true, tvb, offset, actx, tree, hf_ansi_map_interSystemPage2);
        break;
    case  46: /*Inter System Setup*/
        offset = dissect_ansi_map_InterSystemSetup(true, tvb, offset, actx, tree, hf_ansi_map_interSystemSetup);
        break;
    case  47: /*OriginationRequest*/
        offset = dissect_ansi_map_OriginationRequest(true, tvb, offset, actx, tree, hf_ansi_map_originationRequest);
        break;
    case  48: /*Random Variable Request*/
        offset = dissect_ansi_map_RandomVariableRequest(true, tvb, offset, actx, tree, hf_ansi_map_randomVariableRequest);
        break;
    case  49: /*Redirection Directive*/
        offset = dissect_ansi_map_RedirectionDirective(true, tvb, offset, actx, tree, hf_ansi_map_redirectionDirective);
        break;
    case  50: /*Remote User Interaction Directive*/
        offset = dissect_ansi_map_RemoteUserInteractionDirective(true, tvb, offset, actx, tree, hf_ansi_map_remoteUserInteractionDirective);
        break;
    case  51: /*SMS Delivery Backward*/
        offset = dissect_ansi_map_SMSDeliveryBackward(true, tvb, offset, actx, tree, hf_ansi_map_sMSDeliveryBackward);
        break;
    case  52: /*SMS Delivery Forward*/
        offset = dissect_ansi_map_SMSDeliveryForward(true, tvb, offset, actx, tree, hf_ansi_map_sMSDeliveryForward);
        break;
    case  53: /*SMS Delivery Point to Point*/
        offset = dissect_ansi_map_SMSDeliveryPointToPoint(true, tvb, offset, actx, tree, hf_ansi_map_sMSDeliveryPointToPoint);
        break;
    case  54: /*SMS Notification*/
        offset = dissect_ansi_map_SMSNotification(true, tvb, offset, actx, tree, hf_ansi_map_sMSNotification);
        break;
    case  55: /*SMS Request*/
        offset = dissect_ansi_map_SMSRequest(true, tvb, offset, actx, tree, hf_ansi_map_sMSRequest);
        break;
        /* End N.S0005*/
        /* N.S0010-0 v 1.0 */
        /* N.S0011-0 v 1.0 */
    case  56: /*OTASP Request 6.4.2.CC*/
        offset = dissect_ansi_map_OTASPRequest(true, tvb, offset, actx, tree, hf_ansi_map_oTASPRequest);
        break;
        /*End N.S0011-0 v 1.0 */
    case  57: /*Information Backward*/
        break;
        /*  N.S0008-0 v 1.0 */
    case  58: /*Change Facilities*/
        offset = dissect_ansi_map_ChangeFacilities(true, tvb, offset, actx, tree, hf_ansi_map_changeFacilities);
        break;
    case  59: /*Change Service*/
        offset = dissect_ansi_map_ChangeService(true, tvb, offset, actx, tree, hf_ansi_map_changeService);
        break;
        /* End N.S0008-0 v 1.0 */
    case  60: /*Parameter Request*/
        offset = dissect_ansi_map_ParameterRequest(true, tvb, offset, actx, tree, hf_ansi_map_parameterRequest);
        break;
    case  61: /*TMSI Directive*/
        offset = dissect_ansi_map_TMSIDirective(true, tvb, offset, actx, tree, hf_ansi_map_tMSIDirective);
        break;
        /*End  N.S0010-0 v 1.0 */
    case  62: /*NumberPortabilityRequest 62*/
        offset = dissect_ansi_map_NumberPortabilityRequest(true, tvb, offset, actx, tree, hf_ansi_map_numberPortabilityRequest);
        break;
    case  63: /*Service Request N.S0012-0 v 1.0*/
        offset = dissect_ansi_map_ServiceRequest(true, tvb, offset, actx, tree, hf_ansi_map_serviceRequest);
        break;
        /* N.S0013 */
    case  64: /*Analyzed Information Request*/
        offset = dissect_ansi_map_AnalyzedInformation(true, tvb, offset, actx, tree, hf_ansi_map_analyzedInformation);
        break;
    case  65: /*Connection Failure Report*/
        offset = dissect_ansi_map_ConnectionFailureReport(true, tvb, offset, actx, tree, hf_ansi_map_connectionFailureReport);
        break;
    case  66: /*Connect Resource*/
        offset = dissect_ansi_map_ConnectResource(true, tvb, offset, actx, tree, hf_ansi_map_connectResource);
        break;
    case  67: /*Disconnect Resource*/
        /* No data */
        break;
    case  68: /*Facility Selected and Available*/
        offset = dissect_ansi_map_FacilitySelectedAndAvailable(true, tvb, offset, actx, tree, hf_ansi_map_facilitySelectedAndAvailable);
        break;
    case  69: /*Instruction Request*/
        /* No data */
        break;
    case  70: /*Modify*/
        offset = dissect_ansi_map_Modify(true, tvb, offset, actx, tree, hf_ansi_map_modify);
        break;
    case  71: /*Reset Timer*/
        /*No Data*/
        break;
    case  72: /*Search*/
        offset = dissect_ansi_map_Search(true, tvb, offset, actx, tree, hf_ansi_map_search);
        break;
    case  73: /*Seize Resource*/
        offset = dissect_ansi_map_SeizeResource(true, tvb, offset, actx, tree, hf_ansi_map_seizeResource);
        break;
    case  74: /*SRF Directive*/
        offset = dissect_ansi_map_SRFDirective(true, tvb, offset, actx, tree, hf_ansi_map_sRFDirective);
        break;
    case  75: /*T Busy*/
        offset = dissect_ansi_map_TBusy(true, tvb, offset, actx, tree, hf_ansi_map_tBusy);
        break;
    case  76: /*T NoAnswer*/
        offset = dissect_ansi_map_TNoAnswer(true, tvb, offset, actx, tree, hf_ansi_map_tNoAnswer);
        break;
        /*END N.S0013 */
    case  77: /*Release*/
        break;
    case  78: /*SMS Delivery Point to Point Ack*/
        offset = dissect_ansi_map_SMSDeliveryPointToPointAck(true, tvb, offset, actx, tree, hf_ansi_map_smsDeliveryPointToPointAck);
        break;
        /* N.S0024*/
    case  79: /*Message Directive*/
        offset = dissect_ansi_map_MessageDirective(true, tvb, offset, actx, tree, hf_ansi_map_messageDirective);
        break;
        /*END N.S0024*/
        /* N.S0018 PN-4287*/
    case  80: /*Bulk Disconnection*/
        offset = dissect_ansi_map_BulkDisconnection(true, tvb, offset, actx, tree, hf_ansi_map_bulkDisconnection);
        break;
    case  81: /*Call Control Directive*/
        offset = dissect_ansi_map_CallControlDirective(true, tvb, offset, actx, tree, hf_ansi_map_callControlDirective);
        break;
    case  82: /*O Answer*/
        offset = dissect_ansi_map_OAnswer(true, tvb, offset, actx, tree, hf_ansi_map_oAnswer);
        break;
    case  83: /*O Disconnect*/
        offset = dissect_ansi_map_ODisconnect(true, tvb, offset, actx, tree, hf_ansi_map_oDisconnect);
        break;
    case  84: /*Call Recovery Report*/
        offset = dissect_ansi_map_CallRecoveryReport(true, tvb, offset, actx, tree, hf_ansi_map_callRecoveryReport);
        break;
    case  85: /*T Answer*/
        offset = dissect_ansi_map_TAnswer(true, tvb, offset, actx, tree, hf_ansi_map_tAnswer);
        break;
    case  86: /*T Disconnect*/
        offset = dissect_ansi_map_TDisconnect(true, tvb, offset, actx, tree, hf_ansi_map_tDisconnect);
        break;
    case  87: /*Unreliable Call Data*/
        offset = dissect_ansi_map_UnreliableCallData(true, tvb, offset, actx, tree, hf_ansi_map_unreliableCallData);
        break;
        /* N.S0018 PN-4287*/
        /*N.S0004 */
    case  88: /*O CalledPartyBusy*/
        offset = dissect_ansi_map_OCalledPartyBusy(true, tvb, offset, actx, tree, hf_ansi_map_oCalledPartyBusy);
        break;
    case  89: /*O NoAnswer*/
        offset = dissect_ansi_map_ONoAnswer(true, tvb, offset, actx, tree, hf_ansi_map_oNoAnswer);
        break;
    case  90: /*Position Request*/
        offset = dissect_ansi_map_PositionRequest(true, tvb, offset, actx, tree, hf_ansi_map_positionRequest);
        break;
    case  91: /*Position Request Forward*/
        offset = dissect_ansi_map_PositionRequestForward(true, tvb, offset, actx, tree, hf_ansi_map_positionRequestForward);
        break;
        /*END N.S0004 */
    case  92: /*Call Termination Report*/
        offset = dissect_ansi_map_CallTerminationReport(true, tvb, offset, actx, tree, hf_ansi_map_callTerminationReport);
        break;
    case  93: /*Geo Position Directive*/
        break;
    case  94: /*Geo Position Request*/
        offset = dissect_ansi_map_GeoPositionRequest(true, tvb, offset, actx, tree, hf_ansi_map_geoPositionRequest);
        break;
    case  95: /*Inter System Position Request*/
        offset = dissect_ansi_map_InterSystemPositionRequest(true, tvb, offset, actx, tree, hf_ansi_map_interSystemPositionRequest);
        break;
    case  96: /*Inter System Position Request Forward*/
        offset = dissect_ansi_map_InterSystemPositionRequestForward(true, tvb, offset, actx, tree, hf_ansi_map_interSystemPositionRequestForward);
        break;
        /* 3GPP2 N.S0023-0 */
    case  97: /*ACG Directive*/
        offset = dissect_ansi_map_ACGDirective(true, tvb, offset, actx, tree, hf_ansi_map_aCGDirective);
        break;
        /* END 3GPP2 N.S0023-0 */
    case  98: /*Roamer Database Verification Request*/
        offset = dissect_ansi_map_RoamerDatabaseVerificationRequest(true, tvb, offset, actx, tree, hf_ansi_map_roamerDatabaseVerificationRequest);
        break;
        /* N.S0029 X.S0001-A v1.0*/
    case  99: /*Add Service*/
        offset = dissect_ansi_map_AddService(true, tvb, offset, actx, tree, hf_ansi_map_addService);
        break;
    case  100: /*Drop Service*/
        offset = dissect_ansi_map_DropService(true, tvb, offset, actx, tree, hf_ansi_map_dropService);
        break;
        /*End N.S0029 X.S0001-A v1.0*/
        /* X.S0002-0 v1.0 */
        /* LCSParameterRequest */
    case 101:    /* InterSystemSMSPage 101 */
        offset = dissect_ansi_map_InterSystemSMSPage(true, tvb, offset, actx, tree, hf_ansi_map_interSystemSMSPage);
        break;
    case 102:
        offset = dissect_ansi_map_LCSParameterRequest(true, tvb, offset, actx, tree, hf_ansi_map_lcsParameterRequest);
        break;
        /* CheckMEID X.S0008-0 v1.0*/
    case 104:
        offset = dissect_ansi_map_CheckMEID(true, tvb, offset, actx, tree, hf_ansi_map_checkMEID);
        break;
        /* PositionEventNotification */
    case 106:
        offset = dissect_ansi_map_PositionEventNotification(true, tvb, offset, actx, tree, hf_ansi_map_positionEventNotification);
        break;
    case 107:
        /* StatusRequest X.S0008-0 v1.0*/
        offset = dissect_ansi_map_StatusRequest(true, tvb, offset, actx, tree, hf_ansi_map_statusRequest);
        break;
        /* InterSystemSMSDelivery-PointToPoint 111 X.S0004-540-E v2.0*/
    case 111:
        /* InterSystemSMSDeliveryPointToPoint X.S0004-540-E v2.0 */
        offset = dissect_ansi_map_InterSystemSMSDeliveryPointToPoint(true, tvb, offset, actx, tree, hf_ansi_map_interSystemSMSDeliveryPointToPoint);
        break;
    case 112:
        /* QualificationRequest2 112 X.S0004-540-E v2.0*/
        offset = dissect_ansi_map_QualificationRequest2(true, tvb, offset, actx, tree, hf_ansi_map_qualificationRequest2);
        break;
    default:
        proto_tree_add_expert(tree, actx->pinfo, &ei_ansi_map_unknown_invokeData_blob, tvb, offset, -1);
        opCodeKnown = false;
        break;
    }

    if (opCodeKnown)
    {
        tap_p->message_type = OperationCode;
        tap_p->size = 0;    /* should be number of octets in message */

        tap_queue_packet(ansi_map_tap, g_pinfo, tap_p);
    }

    return offset;
}

static int dissect_returnData(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx) {
    static bool                   opCodeKnown = true;
    static ansi_map_tap_rec_t     tap_rec[16];
    static ansi_map_tap_rec_t     *tap_p;
    static int                    tap_current=0;

    /*
     * set tap record pointer
     */
    tap_current++;
    if (tap_current == array_length(tap_rec))
    {
        tap_current = 0;
    }
    tap_p = &tap_rec[tap_current];

    switch(OperationCode){
    case 1: /*Handoff Measurement Request*/
        offset = dissect_ansi_map_HandoffMeasurementRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_handoffMeasurementRequestRes);
        break;
    case 2: /*Facilities Directive*/
        offset = dissect_ansi_map_FacilitiesDirectiveRes(true, tvb, offset, actx, tree, hf_ansi_map_facilitiesDirectiveRes);
        break;
    case 4: /*Handoff Back*/
        offset = dissect_ansi_map_HandoffBackRes(true, tvb, offset, actx, tree, hf_ansi_map_handoffBackRes);
        break;
    case 5: /*Facilities Release*/
        offset = dissect_ansi_map_FacilitiesReleaseRes(true, tvb, offset, actx, tree, hf_ansi_map_facilitiesReleaseRes);
        break;
    case 6: /*Qualification Request*/
        offset = dissect_ansi_map_QualificationRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_qualificationRequestRes);
        break;
    case 7: /*Qualification Directive*/
        offset = dissect_ansi_map_QualificationDirectiveRes(true, tvb, offset, actx, tree, hf_ansi_map_qualificationDirectiveRes);
        break;
    case 10: /*Reset Circuit*/
        offset = dissect_ansi_map_ResetCircuitRes(true, tvb, offset, actx, tree, hf_ansi_map_resetCircuitRes);
        break;
    case 13: /*Registration Notification*/
        offset = dissect_ansi_map_RegistrationNotificationRes(true, tvb, offset, actx, tree, hf_ansi_map_registrationNotificationRes);
        break;
    case  14: /*Registration Cancellation*/
        offset = dissect_ansi_map_RegistrationCancellationRes(true, tvb, offset, actx, tree, hf_ansi_map_registrationCancellationRes);
        break;
    case  15: /*Location Request*/
        offset = dissect_ansi_map_LocationRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_locationRequestRes);
        break;
    case  16: /*Routing Request*/
        offset = dissect_ansi_map_RoutingRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_routingRequestRes);
        break;
    case  17: /*Feature Request*/
        offset = dissect_ansi_map_FeatureRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_featureRequestRes);
        break;
    case  23: /*Transfer To Number Request*/
        offset = dissect_ansi_map_TransferToNumberRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_transferToNumberRequestRes);
        break;
    case  25: /*Handoff To Third*/
        offset = dissect_ansi_map_HandoffToThirdRes(true, tvb, offset, actx, tree, hf_ansi_map_handoffToThirdRes);
        break;
    case  26: /*Flash Request*/
        /* No data */
        proto_tree_add_expert(tree, actx->pinfo, &ei_ansi_map_no_data, tvb, offset, -1);
        break;
    case  27: /*Authentication Directive*/
        offset = dissect_ansi_map_AuthenticationDirectiveRes(true, tvb, offset, actx, tree, hf_ansi_map_authenticationDirectiveRes);
        break;
    case  28: /*Authentication Request*/
        offset = dissect_ansi_map_AuthenticationRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_authenticationRequestRes);
        break;
    case  29: /*Base Station Challenge*/
        offset = dissect_ansi_map_BaseStationChallengeRes(true, tvb, offset, actx, tree, hf_ansi_map_baseStationChallengeRes);
        break;
    case  30: /*Authentication Failure Report*/
        offset = dissect_ansi_map_AuthenticationFailureReportRes(true, tvb, offset, actx, tree, hf_ansi_map_authenticationFailureReportRes);
        break;
    case  31: /*Count Request*/
        offset = dissect_ansi_map_CountRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_countRequestRes);
        break;
    case  32: /*Inter System Page*/
        offset = dissect_ansi_map_InterSystemPageRes(true, tvb, offset, actx, tree, hf_ansi_map_interSystemPageRes);
        break;
    case  33: /*Unsolicited Response*/
        offset = dissect_ansi_map_UnsolicitedResponseRes(true, tvb, offset, actx, tree, hf_ansi_map_unsolicitedResponseRes);
        break;
    case  35: /*Handoff Measurement Request 2*/
        offset = dissect_ansi_map_HandoffMeasurementRequest2Res(true, tvb, offset, actx, tree, hf_ansi_map_handoffMeasurementRequest2Res);
        break;
    case  36: /*Facilities Directive 2*/
        offset = dissect_ansi_map_FacilitiesDirective2Res(true, tvb, offset, actx, tree, hf_ansi_map_facilitiesDirective2Res);
        break;
    case  37: /*Handoff Back 2*/
        offset = dissect_ansi_map_HandoffBack2Res(true, tvb, offset, actx, tree, hf_ansi_map_handoffBack2Res);
        break;
    case  38: /*Handoff To Third 2*/
        offset = dissect_ansi_map_HandoffToThird2Res(true, tvb, offset, actx, tree, hf_ansi_map_handoffToThird2Res);
        break;
    case  39: /*Authentication Directive Forward*/
        offset = dissect_ansi_map_AuthenticationDirectiveForwardRes(true, tvb, offset, actx, tree, hf_ansi_map_authenticationDirectiveForwardRes);
        break;
    case  40: /*Authentication Status Report*/
        offset = dissect_ansi_map_AuthenticationStatusReportRes(true, tvb, offset, actx, tree, hf_ansi_map_authenticationStatusReportRes);
        break;
        /*Reserved 41*/
    case  42: /*Information Directive*/
        offset = dissect_ansi_map_InformationDirectiveRes(true, tvb, offset, actx, tree, hf_ansi_map_informationDirectiveRes);
        break;
    case  43: /*Information Forward*/
        offset = dissect_ansi_map_InformationForwardRes(true, tvb, offset, actx, tree, hf_ansi_map_informationForwardRes);
        break;
    case  45: /*Inter System Page 2*/
        offset = dissect_ansi_map_InterSystemPage2Res(true, tvb, offset, actx, tree, hf_ansi_map_interSystemPage2Res);
        break;
    case  46: /*Inter System Setup*/
        offset = dissect_ansi_map_InterSystemSetupRes(true, tvb, offset, actx, tree, hf_ansi_map_interSystemSetupRes);
        break;
    case  47: /*OriginationRequest*/
        offset = dissect_ansi_map_OriginationRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_originationRequestRes);
        break;
    case  48: /*Random Variable Request*/
        offset = dissect_ansi_map_RandomVariableRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_randomVariableRequestRes);
        break;
    case  50: /*Remote User Interaction Directive*/
        offset = dissect_ansi_map_RemoteUserInteractionDirectiveRes(true, tvb, offset, actx, tree, hf_ansi_map_remoteUserInteractionDirectiveRes);
        break;
    case  51: /*SMS Delivery Backward*/
        offset = dissect_ansi_map_SMSDeliveryBackwardRes(true, tvb, offset, actx, tree, hf_ansi_map_sMSDeliveryBackwardRes);
        break;
    case  52: /*SMS Delivery Forward*/
        offset = dissect_ansi_map_SMSDeliveryForwardRes(true, tvb, offset, actx, tree, hf_ansi_map_sMSDeliveryForwardRes);
        break;
    case  53: /*SMS Delivery Point to Point*/
        offset = dissect_ansi_map_SMSDeliveryPointToPointRes(true, tvb, offset, actx, tree, hf_ansi_map_sMSDeliveryPointToPointRes);
        break;
    case  54: /*SMS Notification*/
        offset = dissect_ansi_map_SMSNotificationRes(true, tvb, offset, actx, tree, hf_ansi_map_sMSNotificationRes);
        break;
    case  55: /*SMS Request*/
        offset = dissect_ansi_map_SMSRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_sMSRequestRes);
        break;
        /*  N.S0008-0 v 1.0 */
    case  56: /*OTASP Request 6.4.2.CC*/
        offset = dissect_ansi_map_OTASPRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_oTASPRequestRes);
        break;
    /* 57 Information Backward*/
    case  58: /*Change Facilities*/
        offset = dissect_ansi_map_ChangeFacilitiesRes(true, tvb, offset, actx, tree, hf_ansi_map_changeFacilitiesRes);
        break;
    case  59: /*Change Service*/
        offset = dissect_ansi_map_ChangeServiceRes(true, tvb, offset, actx, tree, hf_ansi_map_changeServiceRes);
        break;
    case  60: /*Parameter Request*/
        offset = dissect_ansi_map_ParameterRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_parameterRequestRes);
        break;
    case  61: /*TMSI Directive*/
        offset = dissect_ansi_map_TMSIDirectiveRes(true, tvb, offset, actx, tree, hf_ansi_map_tMSIDirectiveRes);
        break;
    case  62: /*NumberPortabilityRequest */
        offset = dissect_ansi_map_NumberPortabilityRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_numberPortabilityRequestRes);
        break;
    case  63: /*Service Request*/
        offset = dissect_ansi_map_ServiceRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_serviceRequestRes);
        break;
        /* N.S0013 */
    case  64: /*Analyzed Information Request*/
        offset = dissect_ansi_map_AnalyzedInformationRes(true, tvb, offset, actx, tree, hf_ansi_map_analyzedInformationRes);
        break;
    /* 65 Connection Failure Report*/
    /* 66 Connect Resource*/
    /* 67 Disconnect Resource*/
    case  68: /*Facility Selected and Available*/
        offset = dissect_ansi_map_FacilitySelectedAndAvailableRes(true, tvb, offset, actx, tree, hf_ansi_map_facilitySelectedAndAvailableRes);
        break;
    /* 69 Instruction Request*/
    case  70: /*Modify*/
        offset = dissect_ansi_map_ModifyRes(true, tvb, offset, actx, tree, hf_ansi_map_modifyRes);
        break;
    case  72: /*Search*/
        offset = dissect_ansi_map_SearchRes(true, tvb, offset, actx, tree, hf_ansi_map_searchRes);
        break;
    case  73: /*Seize Resource*/
        offset = dissect_ansi_map_SeizeResourceRes(true, tvb, offset, actx, tree, hf_ansi_map_seizeResourceRes);
        break;
    case  74: /*SRF Directive*/
        offset = dissect_ansi_map_SRFDirectiveRes(true, tvb, offset, actx, tree, hf_ansi_map_sRFDirectiveRes);
        break;
    case  75: /*T Busy*/
        offset = dissect_ansi_map_TBusyRes(true, tvb, offset, actx, tree, hf_ansi_map_tBusyRes);
        break;
    case  76: /*T NoAnswer*/
        offset = dissect_ansi_map_TNoAnswerRes(true, tvb, offset, actx, tree, hf_ansi_map_tNoAnswerRes);
        break;
    case  81: /*Call Control Directive*/
        offset = dissect_ansi_map_CallControlDirectiveRes(true, tvb, offset, actx, tree, hf_ansi_map_callControlDirectiveRes);
        break;
    case  83: /*O Disconnect*/
        offset = dissect_ansi_map_ODisconnectRes(true, tvb, offset, actx, tree, hf_ansi_map_oDisconnectRes);
        break;
    case  86: /*T Disconnect*/
        offset = dissect_ansi_map_TDisconnectRes(true, tvb, offset, actx, tree, hf_ansi_map_tDisconnectRes);
        break;
    case  88: /*O CalledPartyBusy*/
        offset = dissect_ansi_map_OCalledPartyBusyRes(true, tvb, offset, actx, tree, hf_ansi_map_oCalledPartyBusyRes);
        break;
    case  89: /*O NoAnswer*/
        offset = dissect_ansi_map_ONoAnswerRes(true, tvb, offset, actx, tree, hf_ansi_map_oNoAnswerRes);
        break;
    case  90: /*Position Request*/
        offset = dissect_ansi_map_PositionRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_positionRequestRes);
        break;
    case  91: /*Position Request Forward*/
        offset = dissect_ansi_map_PositionRequestForwardRes(true, tvb, offset, actx, tree, hf_ansi_map_positionRequestForwardRes);
        break;
    case  95: /*Inter System Position Request*/
        offset = dissect_ansi_map_InterSystemPositionRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_interSystemPositionRequestRes);
        break;
    case  96: /*Inter System Position Request Forward*/
        offset = dissect_ansi_map_InterSystemPositionRequestForwardRes(true, tvb, offset, actx, tree, hf_ansi_map_interSystemPositionRequestForwardRes);
        break;
    case  98: /*Roamer Database Verification Request*/
        offset = dissect_ansi_map_RoamerDatabaseVerificationRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_roamerDatabaseVerificationRequestRes);
        break;
    case  99: /*Add Service*/
        offset = dissect_ansi_map_AddServiceRes(true, tvb, offset, actx, tree, hf_ansi_map_addServiceRes);
        break;
    case  100: /*Drop Service*/
        offset = dissect_ansi_map_DropServiceRes(true, tvb, offset, actx, tree, hf_ansi_map_dropServiceRes);
        break;
        /*End N.S0029 */
        /* X.S0002-0 v1.0 */
        /* LCSParameterRequest */
    case 102:
        offset = dissect_ansi_map_LCSParameterRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_lcsParameterRequestRes);
        break;
        /* CheckMEID X.S0008-0 v1.0*/
    case 104:
        offset = dissect_ansi_map_CheckMEIDRes(true, tvb, offset, actx, tree, hf_ansi_map_checkMEIDRes);
        break;
        /* PositionEventNotification *
           case 106:
           offset = dissect_ansi_map_PositionEventNotification(true, tvb, offset, actx, tree, hf_ansi_map_positionEventNotificationRes);
           break;
        */
    case 107:
        /* StatusRequest X.S0008-0 v1.0*/
        offset = dissect_ansi_map_StatusRequestRes(true, tvb, offset, actx, tree, hf_ansi_map_statusRequestRes);
        break;
    case 111:
        /* InterSystemSMSDeliveryPointToPointRes X.S0004-540-E v2.0 */
        offset = dissect_ansi_map_InterSystemSMSDeliveryPointToPointRes(true, tvb, offset, actx, tree, hf_ansi_map_interSystemSMSDeliveryPointToPointRes);
        break;
    case 112:
        /* QualificationRequest2Res 112 X.S0004-540-E v2.0*/
        offset = dissect_ansi_map_QualificationRequest2Res(true, tvb, offset, actx, tree, hf_ansi_map_qualificationRequest2Res);
        break;
    default:
        proto_tree_add_expert(tree, actx->pinfo, &ei_ansi_map_unknown_invokeData_blob, tvb, offset, -1);
        opCodeKnown = false;
        break;
    }

    if (opCodeKnown)
    {
        tap_p->message_type = OperationCode;
        tap_p->size = 0;    /* should be number of octets in message */

        tap_queue_packet(ansi_map_tap, g_pinfo, tap_p);
    }

    return offset;
}

static int
find_saved_invokedata(asn1_ctx_t *actx, struct ansi_tcap_private_t *p_private_tcap){
    struct ansi_map_invokedata_t *ansi_map_saved_invokedata;
    address* src = &(actx->pinfo->src);
    address* dst = &(actx->pinfo->dst);
    uint8_t *src_str;
    uint8_t *dst_str;
    char *buf;

    buf=(char *)wmem_alloc(actx->pinfo->pool, 1024);

    /* Data from the TCAP dissector */
    /* The hash string needs to contain src and dest to distinguish different flows */
    src_str = address_to_str(actx->pinfo->pool, src);
    dst_str = address_to_str(actx->pinfo->pool, dst);
    /* Reverse order to invoke */
    switch(ansi_map_response_matching_type){
        case ANSI_MAP_TID_ONLY:
            snprintf(buf,1024,"%s",p_private_tcap->TransactionID_str);
            break;
        case ANSI_MAP_TID_AND_SOURCE:
            snprintf(buf,1024,"%s%s",p_private_tcap->TransactionID_str,dst_str);
            break;
        case ANSI_MAP_TID_SOURCE_AND_DEST:
        default:
            snprintf(buf,1024,"%s%s%s",p_private_tcap->TransactionID_str,dst_str,src_str);
            break;
    }

    /*ws_warning("Find Hash string %s pkt: %u",buf,actx->pinfo->num);*/
    ansi_map_saved_invokedata = (struct ansi_map_invokedata_t *)wmem_multimap_lookup32_le(TransactionId_table, buf, actx->pinfo->num);
    if(ansi_map_saved_invokedata){
        OperationCode = ansi_map_saved_invokedata->opcode & 0xff;
        ServiceIndicator = ansi_map_saved_invokedata->ServiceIndicator;
    }else{
        OperationCode = OperationCode & 0x00ff;
    }

    return OperationCode;
}

static int
dissect_ansi_map(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
    proto_item *ansi_map_item;
    proto_tree *ansi_map_tree = NULL;
    struct ansi_tcap_private_t *p_private_tcap = (struct ansi_tcap_private_t *)data;
    asn1_ctx_t asn1_ctx;
    asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, true, pinfo);

    SMS_BearerData_tvb = NULL;
    ansi_map_sms_tele_id = -1;
    g_pinfo = pinfo;
    g_tree = tree;

    /* The TCAP dissector should have provided data but didn't so reject it. */
    if (data == NULL)
        return 0;
    /*
     * Make entry in the Protocol column on summary display
     */
    col_set_str(pinfo->cinfo, COL_PROTOCOL, "ANSI MAP");

    /*
     * create the ansi_map protocol tree
     */
    ansi_map_item = proto_tree_add_item(tree, proto_ansi_map, tvb, 0, -1, ENC_NA);
    ansi_map_tree = proto_item_add_subtree(ansi_map_item, ett_ansi_map);
    ansi_map_is_invoke = false;
    is683_ota = false;
    is801_pld = false;
    ServiceIndicator = 0;

    switch(p_private_tcap->d.pdu){
        /*
           1 : invoke,
           2 : returnResult,
           3 : returnError,
           4 : reject
        */
    case 1:
        OperationCode = p_private_tcap->d.OperationCode_private & 0x00ff;
        ansi_map_is_invoke = true;
        col_add_fstr(pinfo->cinfo, COL_INFO,"%s Invoke ", val_to_str_ext(OperationCode, &ansi_map_opr_code_strings_ext, "Unknown ANSI-MAP PDU (%u)"));
        proto_item_append_text(p_private_tcap->d.OperationCode_item," %s",val_to_str_ext(OperationCode, &ansi_map_opr_code_strings_ext, "Unknown ANSI-MAP PDU (%u)"));
        dissect_invokeData(ansi_map_tree, tvb, 0, &asn1_ctx);
        update_saved_invokedata(pinfo, p_private_tcap);
        break;
    case 2:
        OperationCode = find_saved_invokedata(&asn1_ctx, p_private_tcap);
        col_add_fstr(pinfo->cinfo, COL_INFO,"%s ReturnResult ", val_to_str_ext(OperationCode, &ansi_map_opr_code_strings_ext, "Unknown ANSI-MAP PDU (%u)"));
        proto_item_append_text(p_private_tcap->d.OperationCode_item," %s",val_to_str_ext(OperationCode, &ansi_map_opr_code_strings_ext, "Unknown ANSI-MAP PDU (%u)"));
        dissect_returnData(ansi_map_tree, tvb, 0, &asn1_ctx);
        break;
    case 3:
        col_add_fstr(pinfo->cinfo, COL_INFO,"%s ReturnError ", val_to_str_ext(OperationCode, &ansi_map_opr_code_strings_ext, "Unknown ANSI-MAP PDU (%u)"));
        break;
    case 4:
        col_add_fstr(pinfo->cinfo, COL_INFO,"%s Reject ", val_to_str_ext(OperationCode, &ansi_map_opr_code_strings_ext, "Unknown ANSI-MAP PDU (%u)"));
        break;
    default:
        /* Must be Invoke ReturnResult ReturnError or Reject */
        DISSECTOR_ASSERT_NOT_REACHED();
        break;
    }

    return tvb_captured_length(tvb);
}

static void range_delete_callback(uint32_t ssn, void *ptr _U_)
{
    if (ssn) {
        delete_ansi_tcap_subdissector(ssn, ansi_map_handle);
    }
}

static void range_add_callback(uint32_t ssn, void *ptr _U_)
{
    if (ssn) {
        add_ansi_tcap_subdissector(ssn, ansi_map_handle);
    }
}

/* TAP STAT INFO */
typedef enum
{
    OPCODE_COLUMN = 0,
    OPERATION_COLUMN,
    COUNT_COLUMN,
    TOTAL_BYTES_COLUMN,
    AVG_BYTES_COLUMN
} ansi_map_stat_columns;

static stat_tap_table_item stat_fields[] = {{TABLE_ITEM_UINT, TAP_ALIGN_RIGHT, "OpCode", "0x%02x"}, {TABLE_ITEM_STRING, TAP_ALIGN_LEFT, "Operation Name", "%-50s"},
        {TABLE_ITEM_UINT, TAP_ALIGN_RIGHT, "Count", "  %d  "}, {TABLE_ITEM_UINT, TAP_ALIGN_RIGHT, "Total Bytes", "  %d  "},
        {TABLE_ITEM_FLOAT, TAP_ALIGN_RIGHT, "Avg Bytes", "  %8.2f  "}};

static void ansi_map_stat_init(stat_tap_table_ui* new_stat)
{
    const char *table_name = "ANSI MAP Operation Statistics";
    int num_fields = array_length(stat_fields);
    stat_tap_table *table;
    int i = 0;
    stat_tap_table_item_type items[array_length(stat_fields)];

    table = stat_tap_find_table(new_stat, table_name);
    if (table) {
        if (new_stat->stat_tap_reset_table_cb) {
            new_stat->stat_tap_reset_table_cb(table);
        }
        return;
    }

    table = stat_tap_init_table(table_name, num_fields, 0, "ansi_map.op_code");
    stat_tap_add_table(new_stat, table);

    /* Add a fow for each value type */
    while (ansi_map_opr_code_strings[i].strptr)
    {
        items[OPCODE_COLUMN].type = TABLE_ITEM_UINT;
        items[OPCODE_COLUMN].value.uint_value = ansi_map_opr_code_strings[i].value;
        items[OPERATION_COLUMN].type = TABLE_ITEM_STRING;
        items[OPERATION_COLUMN].value.string_value = ansi_map_opr_code_strings[i].strptr;
        items[COUNT_COLUMN].type = TABLE_ITEM_UINT;
        items[COUNT_COLUMN].value.uint_value = 0;
        items[TOTAL_BYTES_COLUMN].type = TABLE_ITEM_UINT;
        items[TOTAL_BYTES_COLUMN].value.uint_value = 0;
        items[AVG_BYTES_COLUMN].type = TABLE_ITEM_FLOAT;
        items[AVG_BYTES_COLUMN].value.float_value = 0.0f;

        stat_tap_init_table_row(table, ansi_map_opr_code_strings[i].value, num_fields, items);
        i++;
    }
}


static tap_packet_status
ansi_map_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *data, tap_flags_t flags _U_)
{
    stat_data_t* stat_data = (stat_data_t*)tapdata;
    const ansi_map_tap_rec_t    *data_p = (const ansi_map_tap_rec_t *)data;
    stat_tap_table* table;
    stat_tap_table_item_type* item_data;
    unsigned count, total_bytes;

    /* Only tracking field values we know */
    if (try_val_to_str(data_p->message_type, ansi_map_opr_code_strings) == NULL)
        return TAP_PACKET_DONT_REDRAW;

    table = g_array_index(stat_data->stat_tap_data->tables, stat_tap_table*, 0);

    item_data = stat_tap_get_field_data(table, data_p->message_type, COUNT_COLUMN);
    item_data->value.uint_value++;
    count = item_data->value.uint_value;
    stat_tap_set_field_data(table, data_p->message_type, COUNT_COLUMN, item_data);

    item_data = stat_tap_get_field_data(table, data_p->message_type, TOTAL_BYTES_COLUMN);
    item_data->value.uint_value += data_p->size;
    total_bytes = item_data->value.uint_value;
    stat_tap_set_field_data(table, data_p->message_type, TOTAL_BYTES_COLUMN, item_data);

    item_data = stat_tap_get_field_data(table, data_p->message_type, AVG_BYTES_COLUMN);
    item_data->value.float_value = (float)total_bytes/(float)count;
    stat_tap_set_field_data(table, data_p->message_type, AVG_BYTES_COLUMN, item_data);

    return TAP_PACKET_REDRAW;
}

static void
ansi_map_stat_reset(stat_tap_table* table)
{
    unsigned element;
    stat_tap_table_item_type* item_data;

    for (element = 0; element < table->num_elements; element++)
    {
        item_data = stat_tap_get_field_data(table, element, COUNT_COLUMN);
        item_data->value.uint_value = 0;
        stat_tap_set_field_data(table, element, COUNT_COLUMN, item_data);

        item_data = stat_tap_get_field_data(table, element, TOTAL_BYTES_COLUMN);
        item_data->value.uint_value = 0;
        stat_tap_set_field_data(table, element, TOTAL_BYTES_COLUMN, item_data);

        item_data = stat_tap_get_field_data(table, element, AVG_BYTES_COLUMN);
        item_data->value.float_value = 0.0f;
        stat_tap_set_field_data(table, element, AVG_BYTES_COLUMN, item_data);
    }

}

void
proto_reg_handoff_ansi_map(void)
{
    static bool ansi_map_prefs_initialized = false;
    static range_t *ssn_range;

    if(!ansi_map_prefs_initialized)
    {
        ansi_map_prefs_initialized = true;
    }
    else
    {
        range_foreach(ssn_range, range_delete_callback, NULL);
        wmem_free(wmem_epan_scope(), ssn_range);
    }

    ssn_range = range_copy(wmem_epan_scope(), global_ssn_range);

    range_foreach(ssn_range, range_add_callback, NULL);
}

/*--- proto_register_ansi_map -------------------------------------------*/
void proto_register_ansi_map(void) {

    module_t    *ansi_map_module;

    /* List of fields */
    static hf_register_info hf[] = {

#if 0
        { &hf_ansi_map_op_code_fam,
          { "Operation Code Family", "ansi_map.op_code_fam",
            FT_UINT8, BASE_DEC, NULL, 0,
            NULL, HFILL }},
#endif
        { &hf_ansi_map_reservedBitH,
          { "Reserved", "ansi_map.reserved_bitH",
            FT_BOOLEAN, 8, NULL,0x80,
            NULL, HFILL }},
        { &hf_ansi_map_reservedBitD,
          { "Reserved", "ansi_map.reserved_bitD",
            FT_BOOLEAN, 8, NULL,0x08,
            NULL, HFILL }},
        { &hf_ansi_map_reservedBitHG,
          { "Reserved", "ansi_map.reserved_bitHG",
            FT_UINT8, BASE_DEC, NULL, 0xc0,
            NULL, HFILL }},
        { &hf_ansi_map_reservedBitHGFE,
          { "Reserved", "ansi_map.reserved_bitHGFE",
            FT_UINT8, BASE_DEC, NULL, 0xf0,
            NULL, HFILL }},
        { &hf_ansi_map_reservedBitFED,
          { "Reserved", "ansi_map.reserved_bitFED",
            FT_UINT8, BASE_DEC, NULL, 0x38,
            NULL, HFILL }},
        { &hf_ansi_map_reservedBitED,
          { "Reserved", "ansi_map.reserved_bitED",
            FT_UINT8, BASE_DEC, NULL, 0x18,
            NULL, HFILL }},
#if 0
        { &hf_ansi_map_op_code,
          { "Operation Code", "ansi_map.op_code",
            FT_UINT8, BASE_DEC|BASE_EXT_STRING, &ansi_map_opr_code_strings_ext, 0x0,
            NULL, HFILL }},
#endif
        { &hf_ansi_map_type_of_digits,
          { "Type of Digits", "ansi_map.type_of_digits",
            FT_UINT8, BASE_DEC, VALS(ansi_map_type_of_digits_vals), 0x0,
            NULL, HFILL }},
        { &hf_ansi_map_na,
          { "Nature of Number", "ansi_map.na",
            FT_BOOLEAN, 8, TFS(&ansi_map_na_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_pi,
          { "Presentation Indication", "ansi_map.type_of_pi",
            FT_BOOLEAN, 8, TFS(&ansi_map_pi_bool_val),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_navail,
          { "Number available indication", "ansi_map.navail",
            FT_BOOLEAN, 8, TFS(&ansi_map_navail_bool_val),0x04,
            NULL, HFILL }},
        { &hf_ansi_map_si,
          { "Screening indication", "ansi_map.si",
            FT_UINT8, BASE_DEC, VALS(ansi_map_si_vals), 0x30,
            NULL, HFILL }},
        { &hf_ansi_map_digits_enc,
          { "Encoding", "ansi_map.enc",
            FT_UINT8, BASE_DEC, VALS(ansi_map_digits_enc_vals), 0x0f,
            NULL, HFILL }},
        { &hf_ansi_map_np,
          { "Numbering Plan", "ansi_map.np",
            FT_UINT8, BASE_DEC, VALS(ansi_map_np_vals), 0xf0,
            NULL, HFILL }},
        { &hf_ansi_map_nr_digits,
          { "Number of Digits", "ansi_map.nr_digits",
            FT_UINT8, BASE_DEC, NULL, 0x0,
            NULL, HFILL }},
        { &hf_ansi_map_bcd_digits,
          { "BCD digits", "ansi_map.bcd_digits",
            FT_STRING, BASE_NONE, NULL, 0,
            NULL, HFILL }},
        { &hf_ansi_map_ia5_digits,
          { "IA5 digits", "ansi_map.ia5_digits",
            FT_STRING, BASE_NONE, NULL, 0,
            NULL, HFILL }},
        { &hf_ansi_map_subaddr_type,
          { "Type of Subaddress", "ansi_map.subaddr_type",
            FT_UINT8, BASE_DEC, VALS(ansi_map_sub_addr_type_vals), 0x70,
            NULL, HFILL }},
        { &hf_ansi_map_subaddr_odd_even,
          { "Odd/Even Indicator", "ansi_map.subaddr_odd_even",
            FT_BOOLEAN, 8, TFS(&ansi_map_navail_bool_val),0x08,
            NULL, HFILL }},

        { &hf_ansi_alertcode_cadence,
          { "Cadence", "ansi_map.alertcode.cadence",
            FT_UINT8, BASE_DEC, VALS(ansi_map_AlertCode_Cadence_vals), 0x3f,
            NULL, HFILL }},
        { &hf_ansi_alertcode_pitch,
          { "Pitch", "ansi_map.alertcode.pitch",
            FT_UINT8, BASE_DEC, VALS(ansi_map_AlertCode_Pitch_vals), 0xc0,
            NULL, HFILL }},
        { &hf_ansi_alertcode_alertaction,
          { "Alert Action", "ansi_map.alertcode.alertaction",
            FT_UINT8, BASE_DEC, VALS(ansi_map_AlertCode_Alert_Action_vals), 0x07,
            NULL, HFILL }},
        { &hf_ansi_map_announcementcode_tone,
          { "Tone", "ansi_map.announcementcode.tone",
            FT_UINT8, BASE_DEC, VALS(ansi_map_AnnouncementCode_tone_vals), 0x0,
            NULL, HFILL }},
        { &hf_ansi_map_announcementcode_class,
          { "Tone", "ansi_map.announcementcode.class",
            FT_UINT8, BASE_DEC, VALS(ansi_map_AnnouncementCode_class_vals), 0xf,
            NULL, HFILL }},
        { &hf_ansi_map_announcementcode_std_ann,
          { "Standard Announcement", "ansi_map.announcementcode.std_ann",
            FT_UINT8, BASE_DEC, VALS(ansi_map_AnnouncementCode_std_ann_vals), 0x0,
            NULL, HFILL }},
        { &hf_ansi_map_announcementcode_cust_ann,
          { "Custom Announcement", "ansi_map.announcementcode.cust_ann",
            FT_UINT8, BASE_DEC, NULL, 0x0,
            NULL, HFILL }},
        { &hf_ansi_map_authorizationperiod_period,
          { "Period", "ansi_map.authorizationperiod.period",
            FT_UINT8, BASE_DEC, VALS(ansi_map_authorizationperiod_period_vals), 0x0,
            NULL, HFILL }},
        { &hf_ansi_map_value,
          { "Value", "ansi_map.value",
            FT_UINT8, BASE_DEC, NULL, 0x0,
            NULL, HFILL }},
        { &hf_ansi_map_msc_type,
          { "Type", "ansi_map.extendedmscid.type",
            FT_UINT8, BASE_DEC, VALS(ansi_map_msc_type_vals), 0x0,
            NULL, HFILL }},
        { &hf_ansi_map_handoffstate_pi,
          { "Party Involved (PI)", "ansi_map.handoffstate.pi",
            FT_BOOLEAN, 8, TFS(&ansi_map_HandoffState_pi_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_tgn,
          { "Trunk Group Number (G)", "ansi_map.tgn",
            FT_UINT8, BASE_DEC, NULL,0x0,
            NULL, HFILL }},
        { &hf_ansi_map_tmn,
          { "Trunk Member Number (M)", "ansi_map.tmn",
            FT_UINT8, BASE_DEC, NULL,0x0,
            NULL, HFILL }},
        { &hf_ansi_map_messagewaitingnotificationcount_tom,
          { "Type of messages", "ansi_map.messagewaitingnotificationcount.tom",
            FT_UINT8, BASE_DEC, VALS(ansi_map_MessageWaitingNotificationCount_type_vals), 0x0,
            NULL, HFILL }},
        { &hf_ansi_map_messagewaitingnotificationcount_no_mw,
          { "Number of Messages Waiting", "ansi_map.messagewaitingnotificationcount.nomw",
            FT_UINT8, BASE_DEC, NULL,0x0,
            NULL, HFILL }},
        { &hf_ansi_map_messagewaitingnotificationtype_mwi,
          { "Message Waiting Indication (MWI)", "ansi_map.messagewaitingnotificationcount.mwi",
            FT_UINT8, BASE_DEC, VALS(ansi_map_MessageWaitingNotificationType_mwi_vals), 0x0,
            NULL, HFILL }},
        { &hf_ansi_map_messagewaitingnotificationtype_apt,
          { "Alert Pip Tone (APT)", "ansi_map.messagewaitingnotificationtype.apt",
            FT_BOOLEAN, 8, TFS(&ansi_map_HandoffState_pi_bool_val),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_messagewaitingnotificationtype_pt,
          { "Pip Tone (PT)", "ansi_map.messagewaitingnotificationtype.pt",
            FT_UINT8, BASE_DEC, VALS(ansi_map_MessageWaitingNotificationType_mwi_vals), 0xc0,
            NULL, HFILL }},

        { &hf_ansi_map_trans_cap_prof,
          { "Profile (PROF)", "ansi_map.trans_cap_prof",
            FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_prof_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_trans_cap_busy,
          { "Busy Detection (BUSY)", "ansi_map.trans_cap_busy",
            FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_busy_bool_val),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_trans_cap_ann,
          { "Announcements (ANN)", "ansi_map.trans_cap_ann",
            FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_ann_bool_val),0x04,
            NULL, HFILL }},
        { &hf_ansi_map_trans_cap_rui,
          { "Remote User Interaction (RUI)", "ansi_map.trans_cap_rui",
            FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_rui_bool_val),0x08,
            NULL, HFILL }},
        { &hf_ansi_map_trans_cap_spini,
          { "Subscriber PIN Intercept (SPINI)", "ansi_map.trans_cap_spini",
            FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_spini_bool_val),0x10,
            NULL, HFILL }},
        { &hf_ansi_map_trans_cap_uzci,
          { "UZ Capability Indicator (UZCI)", "ansi_map.trans_cap_uzci",
            FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_uzci_bool_val),0x20,
            NULL, HFILL }},
        { &hf_ansi_map_trans_cap_ndss,
          { "NDSS Capability (NDSS)", "ansi_map.trans_cap_ndss",
            FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_ndss_bool_val),0x40,
            NULL, HFILL }},
        { &hf_ansi_map_trans_cap_nami,
          { "NAME Capability Indicator (NAMI)", "ansi_map.trans_cap_nami",
            FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_nami_bool_val),0x80,
            NULL, HFILL }},
        { &hf_ansi_trans_cap_multerm,
          { "Multiple Terminations", "ansi_map.trans_cap_multerm",
            FT_UINT8, BASE_DEC, VALS(ansi_map_trans_cap_multerm_vals), 0x0f,
            NULL, HFILL }},
        { &hf_ansi_map_terminationtriggers_busy,
          { "Busy", "ansi_map.terminationtriggers.busy",
            FT_UINT8, BASE_DEC, VALS(ansi_map_terminationtriggers_busy_vals), 0x03,
            NULL, HFILL }},
        { &hf_ansi_map_terminationtriggers_rf,
          { "Routing Failure (RF)", "ansi_map.terminationtriggers.rf",
            FT_UINT8, BASE_DEC, VALS(ansi_map_terminationtriggers_rf_vals), 0x0c,
            NULL, HFILL }},
        { &hf_ansi_map_terminationtriggers_npr,
          { "No Page Response (NPR)", "ansi_map.terminationtriggers.npr",
            FT_UINT8, BASE_DEC, VALS(ansi_map_terminationtriggers_npr_vals), 0x30,
            NULL, HFILL }},
        { &hf_ansi_map_terminationtriggers_na,
          { "No Answer (NA)", "ansi_map.terminationtriggers.na",
            FT_UINT8, BASE_DEC, VALS(ansi_map_terminationtriggers_na_vals), 0xc0,
            NULL, HFILL }},
        { &hf_ansi_map_terminationtriggers_nr,
          { "None Reachable (NR)", "ansi_map.terminationtriggers.nr",
            FT_UINT8, BASE_DEC, VALS(ansi_map_terminationtriggers_nr_vals), 0x01,
            NULL, HFILL }},
        { &hf_ansi_trans_cap_tl,
          { "TerminationList (TL)", "ansi_map.trans_cap_tl",
            FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_tl_bool_val),0x10,
            NULL, HFILL }},
        { &hf_ansi_map_cdmaserviceoption,
          { "CDMAServiceOption", "ansi_map.cdmaserviceoption",
            FT_UINT16, BASE_RANGE_STRING | BASE_DEC, RVALS(cdmaserviceoption_vals), 0x0,
            NULL, HFILL }},
        { &hf_ansi_trans_cap_waddr,
          { "WIN Addressing (WADDR)", "ansi_map.trans_cap_waddr",
            FT_BOOLEAN, 8, TFS(&ansi_map_trans_cap_waddr_bool_val),0x20,
            NULL, HFILL }},

        { &hf_ansi_map_MarketID,
          { "MarketID", "ansi_map.marketid",
            FT_UINT16, BASE_DEC, NULL, 0,
            NULL, HFILL }},
        { &hf_ansi_map_swno,
          { "Switch Number (SWNO)", "ansi_map.swno",
            FT_UINT8, BASE_DEC, NULL, 0,
            NULL, HFILL }},
        { &hf_ansi_map_idno,
          { "ID Number", "ansi_map.idno",
            FT_UINT32, BASE_DEC, NULL, 0,
            NULL, HFILL }},
        { &hf_ansi_map_segcount,
          { "Segment Counter", "ansi_map.segcount",
            FT_UINT8, BASE_DEC, NULL, 0,
            NULL, HFILL }},
        { &hf_ansi_map_sms_originationrestrictions_direct,
          { "DIRECT", "ansi_map.originationrestrictions.direct",
            FT_BOOLEAN, 8, TFS(&ansi_map_SMS_OriginationRestrictions_direct_bool_val),0x04,
            NULL, HFILL }},
        { &hf_ansi_map_sms_originationrestrictions_default,
          { "DEFAULT", "ansi_map.originationrestrictions.default",
            FT_UINT8, BASE_DEC, VALS(ansi_map_SMS_OriginationRestrictions_default_vals), 0x03,
            NULL, HFILL }},
        { &hf_ansi_map_sms_originationrestrictions_fmc,
          { "Force Message Center (FMC)", "ansi_map.originationrestrictions.fmc",
            FT_BOOLEAN, 8, TFS(&ansi_map_SMS_OriginationRestrictions_fmc_bool_val),0x08,
            NULL, HFILL }},

        { &hf_ansi_map_systemcapabilities_auth,
          { "Authentication Parameters Requested (AUTH)", "ansi_map.systemcapabilities.auth",
            FT_BOOLEAN, 8, TFS(&ansi_map_systemcapabilities_auth_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_systemcapabilities_se,
          { "Signaling Message Encryption Capable (SE )", "ansi_map.systemcapabilities.se",
            FT_BOOLEAN, 8, TFS(&ansi_map_systemcapabilities_se_bool_val),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_systemcapabilities_vp,
          { "Voice Privacy Capable (VP )", "ansi_map.systemcapabilities.vp",
            FT_BOOLEAN, 8, TFS(&ansi_map_systemcapabilities_vp_bool_val),0x04,
            NULL, HFILL }},
        { &hf_ansi_map_systemcapabilities_cave,
          { "CAVE Algorithm Capable (CAVE)", "ansi_map.systemcapabilities.cave",
            FT_BOOLEAN, 8, TFS(&ansi_map_systemcapabilities_cave_bool_val),0x08,
            NULL, HFILL }},
        { &hf_ansi_map_systemcapabilities_ssd,
          { "Shared SSD (SSD)", "ansi_map.systemcapabilities.ssd",
            FT_BOOLEAN, 8, TFS(&ansi_map_systemcapabilities_ssd_bool_val),0x10,
            NULL, HFILL }},
        { &hf_ansi_map_systemcapabilities_dp,
          { "Data Privacy (DP)", "ansi_map.systemcapabilities.dp",
            FT_BOOLEAN, 8, TFS(&ansi_map_systemcapabilities_dp_bool_val),0x20,
            NULL, HFILL }},

        { &hf_ansi_map_mslocation_lat,
          { "Latitude in tenths of a second", "ansi_map.mslocation.lat",
            FT_UINT24, BASE_DEC, NULL, 0,
            NULL, HFILL }},
        { &hf_ansi_map_mslocation_long,
          { "Longitude in tenths of a second", "ansi_map.mslocation.long",
            FT_UINT24, BASE_DEC, NULL, 0,
            "Switch Number (SWNO)", HFILL }},
        { &hf_ansi_map_mslocation_res,
          { "Resolution in units of 1 foot", "ansi_map.mslocation.res",
            FT_UINT8, BASE_DEC, NULL, 0,
            NULL, HFILL }},
        { &hf_ansi_map_nampscallmode_namps,
          { "Call Mode", "ansi_map.nampscallmode.namps",
            FT_BOOLEAN, 8, TFS(&ansi_map_CallMode_namps_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_nampscallmode_amps,
          { "Call Mode", "ansi_map.nampscallmode.amps",
            FT_BOOLEAN, 8, TFS(&ansi_map_CallMode_amps_bool_val),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_nampschanneldata_navca,
          { "Narrow Analog Voice Channel Assignment (NAVCA)", "ansi_map.nampschanneldata.navca",
            FT_UINT8, BASE_DEC, VALS(ansi_map_NAMPSChannelData_navca_vals), 0x03,
            NULL, HFILL }},
        { &hf_ansi_map_nampschanneldata_CCIndicator,
          { "Color Code Indicator (CCIndicator)", "ansi_map.nampschanneldata.ccindicator",
            FT_UINT8, BASE_DEC, VALS(ansi_map_NAMPSChannelData_ccinidicator_vals), 0x1c,
            NULL, HFILL }},


        { &hf_ansi_map_callingfeaturesindicator_cfufa,
          { "Call Forwarding Unconditional FeatureActivity, CFU-FA", "ansi_map.callingfeaturesindicator.cfufa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x03,
            NULL, HFILL }},
        { &hf_ansi_map_callingfeaturesindicator_cfbfa,
          { "Call Forwarding Busy FeatureActivity, CFB-FA", "ansi_map.callingfeaturesindicator.cfbafa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x0c,
            NULL, HFILL }},
        { &hf_ansi_map_callingfeaturesindicator_cfnafa,
          { "Call Forwarding No Answer FeatureActivity, CFNA-FA", "ansi_map.callingfeaturesindicator.cfnafa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x30,
            NULL, HFILL }},
        { &hf_ansi_map_callingfeaturesindicator_cwfa,
          { "Call Waiting: FeatureActivity, CW-FA", "ansi_map.callingfeaturesindicator.cwfa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0xc0,
            NULL, HFILL }},

        { &hf_ansi_map_callingfeaturesindicator_3wcfa,
          { "Three-Way Calling FeatureActivity, 3WC-FA", "ansi_map.callingfeaturesindicator.3wcfa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x03,
            NULL, HFILL }},

        { &hf_ansi_map_callingfeaturesindicator_pcwfa,
          { "Priority Call Waiting FeatureActivity PCW-FA", "ansi_map.callingfeaturesindicator.pcwfa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x03,
            NULL, HFILL }},

        { &hf_ansi_map_callingfeaturesindicator_dpfa,
          { "Data Privacy Feature Activity DP-FA", "ansi_map.callingfeaturesindicator.dpfa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x0c,
            NULL, HFILL }},
        { &hf_ansi_map_callingfeaturesindicator_ahfa,
          { "Answer Hold: FeatureActivity AH-FA", "ansi_map.callingfeaturesindicator.ahfa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x30,
            NULL, HFILL }},
        { &hf_ansi_map_callingfeaturesindicator_uscfvmfa,
          { "USCF divert to voice mail: FeatureActivity USCFvm-FA", "ansi_map.callingfeaturesindicator.uscfvmfa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0xc0,
            NULL, HFILL }},

        { &hf_ansi_map_callingfeaturesindicator_uscfmsfa,
          { "USCF divert to mobile station provided DN:FeatureActivity.USCFms-FA", "ansi_map.callingfeaturesindicator.uscfmsfa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x03,
            NULL, HFILL }},
        { &hf_ansi_map_callingfeaturesindicator_uscfnrfa,
          { "USCF divert to network registered DN:FeatureActivity. USCFnr-FA", "ansi_map.callingfeaturesindicator.uscfnrfa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x0c,
            NULL, HFILL }},
        { &hf_ansi_map_callingfeaturesindicator_cpdsfa,
          { "CDMA-Packet Data Service: FeatureActivity. CPDS-FA", "ansi_map.callingfeaturesindicator.cpdfa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x30,
            NULL, HFILL }},
        { &hf_ansi_map_callingfeaturesindicator_ccsfa,
          { "CDMA-Concurrent Service:FeatureActivity. CCS-FA", "ansi_map.callingfeaturesindicator.ccsfa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0xc0,
            NULL, HFILL }},

        { &hf_ansi_map_callingfeaturesindicator_epefa,
          { "TDMA Enhanced Privacy and Encryption:FeatureActivity.TDMA EPE-FA", "ansi_map.callingfeaturesindicator.epefa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x03,
            NULL, HFILL }},


        { &hf_ansi_map_callingfeaturesindicator_cdfa,
          { "Call Delivery: FeatureActivity, CD-FA", "ansi_map.callingfeaturesindicator.cdfa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x0c,
            NULL, HFILL }},
        { &hf_ansi_map_callingfeaturesindicator_vpfa,
          { "Voice Privacy FeatureActivity, VP-FA", "ansi_map.callingfeaturesindicator.vpfa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x30,
            NULL, HFILL }},
        { &hf_ansi_map_callingfeaturesindicator_ctfa,
          { "Call Transfer: FeatureActivity, CT-FA", "ansi_map.callingfeaturesindicator.ctfa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0xc0,
            NULL, HFILL }},

        { &hf_ansi_map_callingfeaturesindicator_cnip1fa,
          { "One number (network-provided only) Calling Number Identification Presentation: FeatureActivity CNIP1-FA", "ansi_map.callingfeaturesindicator.cnip1fa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x03,
            NULL, HFILL }},
        { &hf_ansi_map_callingfeaturesindicator_cnip2fa,
          { "Two number (network-provided and user-provided) Calling Number Identification Presentation: FeatureActivity CNIP2-FA", "ansi_map.callingfeaturesindicator.cnip2fa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x0c,
            NULL, HFILL }},
        { &hf_ansi_map_callingfeaturesindicator_cnirfa,
          { "Calling Number Identification Restriction: FeatureActivity CNIR-FA", "ansi_map.callingfeaturesindicator.cnirfa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0x30,
            NULL, HFILL }},
        { &hf_ansi_map_callingfeaturesindicator_cniroverfa,
          { "Calling Number Identification Restriction Override FeatureActivity CNIROver-FA", "ansi_map.callingfeaturesindicator.cniroverfa",
            FT_UINT8, BASE_DEC, VALS(ansi_map_FeatureActivity_vals), 0xc0,
            NULL, HFILL }},

        { &hf_ansi_map_cdmacallmode_cdma,
          { "Call Mode", "ansi_map.cdmacallmode.cdma",
            FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cdma_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_cdmacallmode_amps,
          { "Call Mode", "ansi_map.cdmacallmode.amps",
            FT_BOOLEAN, 8, TFS(&ansi_map_CallMode_amps_bool_val),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_cdmacallmode_namps,
          { "Call Mode", "ansi_map.cdmacallmode.namps",
            FT_BOOLEAN, 8, TFS(&ansi_map_CallMode_namps_bool_val),0x04,
            NULL, HFILL }},
        { &hf_ansi_map_cdmacallmode_cls1,
          { "Call Mode", "ansi_map.cdmacallmode.cls1",
            FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls1_bool_val),0x08,
            NULL, HFILL }},
        { &hf_ansi_map_cdmacallmode_cls2,
          { "Call Mode", "ansi_map.cdmacallmode.cls2",
            FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls2_bool_val),0x10,
            NULL, HFILL }},
        { &hf_ansi_map_cdmacallmode_cls3,
          { "Call Mode", "ansi_map.cdmacallmode.cls3",
            FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls3_bool_val),0x20,
            NULL, HFILL }},
        { &hf_ansi_map_cdmacallmode_cls4,
          { "Call Mode", "ansi_map.cdmacallmode.cls4",
            FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls4_bool_val),0x40,
            NULL, HFILL }},
        { &hf_ansi_map_cdmacallmode_cls5,
          { "Call Mode", "ansi_map.cdmacallmode.cls5",
            FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls5_bool_val),0x80,
            NULL, HFILL }},
        { &hf_ansi_map_cdmacallmode_cls6,
          { "Call Mode", "ansi_map.cdmacallmode.cls6",
            FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls6_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_cdmacallmode_cls7,
          { "Call Mode", "ansi_map.cdmacallmode.cls7",
            FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls7_bool_val),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_cdmacallmode_cls8,
          { "Call Mode", "ansi_map.cdmacallmode.cls8",
            FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls8_bool_val),0x04,
            NULL, HFILL }},
        { &hf_ansi_map_cdmacallmode_cls9,
          { "Call Mode", "ansi_map.cdmacallmode.cls9",
            FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls9_bool_val),0x08,
            NULL, HFILL }},
        { &hf_ansi_map_cdmacallmode_cls10,
          { "Call Mode", "ansi_map.cdmacallmode.cls10",
            FT_BOOLEAN, 8, TFS(&ansi_map_CDMACallMode_cls10_bool_val),0x10,
            NULL, HFILL }},
        {&hf_ansi_map_cdmachanneldata_Frame_Offset,
         { "Frame Offset", "ansi_map.cdmachanneldata.frameoffset",
           FT_UINT8, BASE_DEC, NULL, 0x78,
           NULL, HFILL }},
        {&hf_ansi_map_cdmachanneldata_CDMA_ch_no,
         { "CDMA Channel Number", "ansi_map.cdmachanneldata.cdma_ch_no",
           FT_UINT16, BASE_DEC, NULL, 0x07FF,
           NULL, HFILL }},
        {&hf_ansi_map_cdmachanneldata_band_cls,
         { "Band Class", "ansi_map.cdmachanneldata.band_cls",
           FT_UINT8, BASE_DEC, VALS(ansi_map_cdmachanneldata_band_cls_vals), 0x7c,
           NULL, HFILL }},
        {&hf_ansi_map_cdmachanneldata_lc_mask_b6,
         { "Long Code Mask (byte 6) MSB", "ansi_map.cdmachanneldata.lc_mask_b6",
           FT_UINT8, BASE_HEX, NULL, 0x03,
           NULL, HFILL }},
        {&hf_ansi_map_cdmachanneldata_lc_mask_b5,
         { "Long Code Mask (byte 5)", "ansi_map.cdmachanneldata.lc_mask_b5",
           FT_UINT8, BASE_HEX, NULL, 0xff,
           NULL, HFILL }},
        {&hf_ansi_map_cdmachanneldata_lc_mask_b4,
         { "Long Code Mask (byte 4)", "ansi_map.cdmachanneldata.lc_mask_b4",
           FT_UINT8, BASE_HEX, NULL, 0xff,
           NULL, HFILL }},
        {&hf_ansi_map_cdmachanneldata_lc_mask_b3,
         { "Long Code Mask (byte 3)", "ansi_map.cdmachanneldata.lc_mask_b3",
           FT_UINT8, BASE_HEX, NULL, 0xff,
           NULL, HFILL }},
        {&hf_ansi_map_cdmachanneldata_lc_mask_b2,
         { "Long Code Mask (byte 2)", "ansi_map.cdmachanneldata.lc_mask_b2",
           FT_UINT8, BASE_HEX, NULL, 0xff,
           NULL, HFILL }},
        {&hf_ansi_map_cdmachanneldata_lc_mask_b1,
         { "Long Code Mask LSB(byte 1)", "ansi_map.cdmachanneldata.lc_mask_b1",
           FT_UINT8, BASE_HEX, NULL, 0xff,
           "Long Code Mask (byte 1)LSB", HFILL }},
        {&hf_ansi_map_cdmachanneldata_np_ext,
         { "NP EXT", "ansi_map.cdmachanneldata.np_ext",
           FT_BOOLEAN, 8, NULL,0x80,
           NULL, HFILL }},
        {&hf_ansi_map_cdmachanneldata_nominal_pwr,
         { "Nominal Power", "ansi_map.cdmachanneldata.nominal_pwr",
           FT_UINT8, BASE_DEC, NULL, 0x78,
           NULL, HFILL }},
        {&hf_ansi_map_cdmachanneldata_nr_preamble,
         { "Number Preamble", "ansi_map.cdmachanneldata.nr_preamble",
           FT_UINT8, BASE_DEC, NULL, 0x07,
           NULL, HFILL }},

        { &hf_ansi_map_cdmastationclassmark_pc,
          { "Power Class(PC)", "ansi_map.cdmastationclassmark.pc",
            FT_UINT8, BASE_DEC, VALS(ansi_map_CDMAStationClassMark_pc_vals), 0x03,
            NULL, HFILL }},

        { &hf_ansi_map_cdmastationclassmark_dtx,
          { "Analog Transmission: (DTX)", "ansi_map.cdmastationclassmark.dtx",
            FT_BOOLEAN, 8, TFS(&ansi_map_CDMAStationClassMark_dtx_bool_val),0x04,
            NULL, HFILL }},
        { &hf_ansi_map_cdmastationclassmark_smi,
          { "Slotted Mode Indicator: (SMI)", "ansi_map.cdmastationclassmark.smi",
            FT_BOOLEAN, 8, TFS(&ansi_map_CDMAStationClassMark_smi_bool_val),0x20,
            NULL, HFILL }},
        { &hf_ansi_map_cdmastationclassmark_dmi,
          { "Dual-mode Indicator(DMI)", "ansi_map.cdmastationclassmark.dmi",
            FT_BOOLEAN, 8, TFS(&ansi_map_CDMAStationClassMark_dmi_bool_val),0x40,
            NULL, HFILL }},
        { &hf_ansi_map_channeldata_vmac,
          { "Voice Mobile Attenuation Code (VMAC)", "ansi_map.channeldata.vmac",
            FT_UINT8, BASE_DEC, NULL, 0x07,
            NULL, HFILL }},
        { &hf_ansi_map_channeldata_dtx,
          { "Discontinuous Transmission Mode (DTX)", "ansi_map.channeldata.dtx",
            FT_UINT8, BASE_DEC, VALS(ansi_map_ChannelData_dtx_vals), 0x18,
            NULL, HFILL }},
        { &hf_ansi_map_channeldata_scc,
          { "SAT Color Code (SCC)", "ansi_map.channeldata.scc",
            FT_UINT8, BASE_DEC, NULL, 0xc0,
            NULL, HFILL }},
        { &hf_ansi_map_channeldata_chno,
          { "Channel Number (CHNO)", "ansi_map.channeldata.chno",
            FT_UINT16, BASE_DEC, NULL, 0x0,
            NULL, HFILL }},
        { &hf_ansi_map_ConfidentialityModes_vp,
          { "Voice Privacy (VP) Confidentiality Status", "ansi_map.confidentialitymodes.vp",
            FT_BOOLEAN, 8, TFS(&tfs_on_off),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_controlchanneldata_dcc,
          { "Digital Color Code (DCC)", "ansi_map.controlchanneldata.dcc",
            FT_UINT8, BASE_DEC, NULL, 0xc0,
            NULL, HFILL }},
        { &hf_ansi_map_controlchanneldata_cmac,
          { "Control Mobile Attenuation Code (CMAC)", "ansi_map.controlchanneldata.cmac",
            FT_UINT8, BASE_DEC, NULL, 0x07,
            NULL, HFILL }},
        { &hf_ansi_map_controlchanneldata_chno,
          { "Channel Number (CHNO)", "ansi_map.controlchanneldata.chno",
            FT_UINT16, BASE_DEC, NULL, 0x0,
            NULL, HFILL }},
        { &hf_ansi_map_controlchanneldata_sdcc1,
          { "Supplementary Digital Color Codes (SDCC1)", "ansi_map.controlchanneldata.ssdc1",
            FT_UINT8, BASE_DEC, NULL, 0x0c,
            NULL, HFILL }},
        { &hf_ansi_map_controlchanneldata_sdcc2,
          { "Supplementary Digital Color Codes (SDCC2)", "ansi_map.controlchanneldata.ssdc2",
            FT_UINT8, BASE_DEC, NULL, 0x03,
            NULL, HFILL }},
        { &hf_ansi_map_ConfidentialityModes_se,
          { "Signaling Message Encryption (SE) Confidentiality Status", "ansi_map.confidentialitymodes.se",
            FT_BOOLEAN, 8, TFS(&tfs_on_off),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_ConfidentialityModes_dp,
          { "DataPrivacy (DP) Confidentiality Status", "ansi_map.confidentialitymodes.dp",
            FT_BOOLEAN, 8, TFS(&tfs_on_off),0x04,
            NULL, HFILL }},

        { &hf_ansi_map_deniedauthorizationperiod_period,
          { "Period", "ansi_map.deniedauthorizationperiod.period",
            FT_UINT8, BASE_DEC, VALS(ansi_map_deniedauthorizationperiod_period_vals), 0x0,
            NULL, HFILL }},


        { &hf_ansi_map_originationtriggers_all,
          { "All Origination (All)", "ansi_map.originationtriggers.all",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_all_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_local,
          { "Local", "ansi_map.originationtriggers.local",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_local_bool_val),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_ilata,
          { "Intra-LATA Toll (ILATA)", "ansi_map.originationtriggers.ilata",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_ilata_bool_val),0x04,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_olata,
          { "Inter-LATA Toll (OLATA)", "ansi_map.originationtriggers.olata",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_olata_bool_val),0x08,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_int,
          { "International (Int'l )", "ansi_map.originationtriggers.int",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_int_bool_val),0x10,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_wz,
          { "World Zone (WZ)", "ansi_map.originationtriggers.wz",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_wz_bool_val),0x20,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_unrec,
          { "Unrecognized Number (Unrec)", "ansi_map.originationtriggers.unrec",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_unrec_bool_val),0x40,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_rvtc,
          { "Revertive Call (RvtC)", "ansi_map.originationtriggers.rvtc",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_rvtc_bool_val),0x80,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_star,
          { "Star", "ansi_map.originationtriggers.star",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_star_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_ds,
          { "Double Star (DS)", "ansi_map.originationtriggers.ds",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_ds_bool_val),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_pound,
          { "Pound", "ansi_map.originationtriggers.pound",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_pound_bool_val),0x04,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_dp,
          { "Double Pound (DP)", "ansi_map.originationtriggers.dp",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_dp_bool_val),0x08,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_pa,
          { "Prior Agreement (PA)", "ansi_map.originationtriggers.pa",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_pa_bool_val),0x10,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_nodig,
          { "No digits", "ansi_map.originationtriggers.nodig",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_nodig_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_onedig,
          { "1 digit", "ansi_map.originationtriggers.onedig",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_onedig_bool_val),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_twodig,
          { "2 digits", "ansi_map.originationtriggers.twodig",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_twodig_bool_val),0x04,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_threedig,
          { "3 digits", "ansi_map.originationtriggers.threedig",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_threedig_bool_val),0x08,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_fourdig,
          { "4 digits", "ansi_map.originationtriggers.fourdig",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_fourdig_bool_val),0x10,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_fivedig,
          { "5 digits", "ansi_map.originationtriggers.fivedig",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_fivedig_bool_val),0x20,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_sixdig,
          { "6 digits", "ansi_map.originationtriggers.sixdig",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_sixdig_bool_val),0x40,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_sevendig,
          { "7 digits", "ansi_map.originationtriggers.sevendig",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_sevendig_bool_val),0x80,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_eightdig,
          { "8 digits", "ansi_map.originationtriggers.eight",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_eightdig_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_ninedig,
          { "9 digits", "ansi_map.originationtriggers.nine",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_ninedig_bool_val),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_tendig,
          { "10 digits", "ansi_map.originationtriggers.ten",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_tendig_bool_val),0x04,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_elevendig,
          { "11 digits", "ansi_map.originationtriggers.eleven",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_elevendig_bool_val),0x08,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_twelvedig,
          { "12 digits", "ansi_map.originationtriggers.twelve",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_twelvedig_bool_val),0x10,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_thirteendig,
          { "13 digits", "ansi_map.originationtriggers.thirteen",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_thirteendig_bool_val),0x20,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_fourteendig,
          { "14 digits", "ansi_map.originationtriggers.fourteen",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_fourteendig_bool_val),0x40,
            NULL, HFILL }},
        { &hf_ansi_map_originationtriggers_fifteendig,
          { "15 digits", "ansi_map.originationtriggers.fifteen",
            FT_BOOLEAN, 8, TFS(&ansi_map_originationtriggers_fifteendig_bool_val),0x80,
            NULL, HFILL }},

        { &hf_ansi_map_triggercapability_init,
          { "Introducing Star/Pound (INIT)", "ansi_map.triggercapability.init",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_kdigit,
          { "K-digit (K-digit)", "ansi_map.triggercapability.kdigit",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_all,
          { "All_Calls (All)", "ansi_map.triggercapability.all",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x04,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_rvtc,
          { "Revertive_Call (RvtC)", "ansi_map.triggercapability.rvtc",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x08,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_oaa,
          { "Origination_Attempt_Authorized (OAA)", "ansi_map.triggercapability.oaa",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x10,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_oans,
          { "O_Answer (OANS)", "ansi_map.triggercapability.oans",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x20,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_odisc,
          { "O_Disconnect (ODISC)", "ansi_map.triggercapability.odisc",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x40,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_ona,
          { "O_No_Answer (ONA)", "ansi_map.triggercapability.ona",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x80,
            NULL, HFILL }},

        { &hf_ansi_map_triggercapability_ct ,
          { "Call Types (CT)", "ansi_map.triggercapability.ct",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_unrec,
          { "Unrecognized_Number (Unrec)", "ansi_map.triggercapability.unrec",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_pa,
          { "Prior_Agreement (PA)", "ansi_map.triggercapability.pa",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x04,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_at,
          { "Advanced_Termination (AT)", "ansi_map.triggercapability.at",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x08,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_cgraa,
          { "Calling_Routing_Address_Available (CgRAA)", "ansi_map.triggercapability.cgraa",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x10,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_it,
          { "Initial_Termination (IT)", "ansi_map.triggercapability.it",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x20,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_cdraa,
          { "Called_Routing_Address_Available (CdRAA)", "ansi_map.triggercapability.cdraa",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x40,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_obsy,
          { "O_Called_Party_Busy (OBSY)", "ansi_map.triggercapability.obsy",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x80,
            NULL, HFILL }},

        { &hf_ansi_map_triggercapability_tra ,
          { "Terminating_Resource_Available (TRA)", "ansi_map.triggercapability.tra",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_tbusy,
          { "T_Busy (TBusy)", "ansi_map.triggercapability.tbusy",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_tna,
          { "T_No_Answer (TNA)", "ansi_map.triggercapability.tna",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x04,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_tans,
          { "T_Answer (TANS)", "ansi_map.triggercapability.tans",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x08,
            NULL, HFILL }},
        { &hf_ansi_map_triggercapability_tdisc,
          { "T_Disconnect (TDISC)", "ansi_map.triggercapability.tdisc",
            FT_BOOLEAN, 8, TFS(&ansi_map_triggercapability_bool_val),0x10,
            NULL, HFILL }},
        { &hf_ansi_map_winoperationscapability_conn,
          { "ConnectResource (CONN)", "ansi_map.winoperationscapability.conn",
            FT_BOOLEAN, 8, TFS(&ansi_map_winoperationscapability_conn_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_winoperationscapability_ccdir,
          { "CallControlDirective(CCDIR)", "ansi_map.winoperationscapability.ccdir",
            FT_BOOLEAN, 8, TFS(&ansi_map_winoperationscapability_ccdir_bool_val),0x02,
            NULL, HFILL }},
        { &hf_ansi_map_winoperationscapability_pos,
          { "PositionRequest (POS)", "ansi_map.winoperationscapability.pos",
            FT_BOOLEAN, 8, TFS(&ansi_map_winoperationscapability_pos_bool_val),0x04,
            NULL, HFILL }},
        { &hf_ansi_map_pacaindicator_pa,
          { "Permanent Activation (PA)", "ansi_map.pacaindicator_pa",
            FT_BOOLEAN, 8, TFS(&ansi_map_pacaindicator_pa_bool_val),0x01,
            NULL, HFILL }},
        { &hf_ansi_map_PACA_Level,
          { "PACA Level", "ansi_map.PACA_Level",
            FT_UINT8, BASE_DEC, VALS(ansi_map_PACA_Level_vals), 0x1e,
            NULL, HFILL }},
        { &hf_ansi_map_point_code,
          { "Point Code", "ansi_map.point_code",
            FT_BYTES, BASE_NONE, NULL, 0x0,
            NULL, HFILL }},
        { &hf_ansi_map_SSN,
          { "SSN", "ansi_map.SSN",
            FT_UINT8, BASE_DEC, NULL, 0x0,
            NULL, HFILL }},
        { &hf_ansi_map_win_trigger_list,
          { "WIN trigger list", "ansi_map.win_trigger_list",
            FT_UINT8, BASE_DEC, NULL, 0x0,
            NULL, HFILL }},

    { &hf_ansi_map_electronicSerialNumber,
      { "electronicSerialNumber", "ansi_map.electronicSerialNumber",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_msid,
      { "msid", "ansi_map.msid",
        FT_UINT32, BASE_DEC, VALS(ansi_map_MSID_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationAlgorithmVersion,
      { "authenticationAlgorithmVersion", "ansi_map.authenticationAlgorithmVersion",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationResponseReauthentication,
      { "authenticationResponseReauthentication", "ansi_map.authenticationResponseReauthentication",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationResponseUniqueChallenge,
      { "authenticationResponseUniqueChallenge", "ansi_map.authenticationResponseUniqueChallenge",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_callHistoryCount,
      { "callHistoryCount", "ansi_map.callHistoryCount",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaPrivateLongCodeMask,
      { "cdmaPrivateLongCodeMask", "ansi_map.cdmaPrivateLongCodeMask",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_carrierDigits,
      { "carrierDigits", "ansi_map.carrierDigits",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_caveKey,
      { "caveKey", "ansi_map.caveKey",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_denyAccess,
      { "denyAccess", "ansi_map.denyAccess",
        FT_UINT32, BASE_DEC, VALS(ansi_map_DenyAccess_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_destinationDigits,
      { "destinationDigits", "ansi_map.destinationDigits",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_locationAreaID,
      { "locationAreaID", "ansi_map.locationAreaID",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_randomVariableReauthentication,
      { "randomVariableReauthentication", "ansi_map.randomVariableReauthentication",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_meid,
      { "meid", "ansi_map.meid",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_mobileStationMIN,
      { "mobileStationMIN", "ansi_map.mobileStationMIN_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_mscid,
      { "mscid", "ansi_map.mscid",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_randomVariableSSD,
      { "randomVariableSSD", "ansi_map.randomVariableSSD",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_randomVariableUniqueChallenge,
      { "randomVariableUniqueChallenge", "ansi_map.randomVariableUniqueChallenge",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_routingDigits,
      { "routingDigits", "ansi_map.routingDigits",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_senderIdentificationNumber,
      { "senderIdentificationNumber", "ansi_map.senderIdentificationNumber_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sharedSecretData,
      { "sharedSecretData", "ansi_map.sharedSecretData",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_signalingMessageEncryptionKey,
      { "signalingMessageEncryptionKey", "ansi_map.signalingMessageEncryptionKey",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_ssdnotShared,
      { "ssdnotShared", "ansi_map.ssdnotShared",
        FT_UINT32, BASE_DEC, VALS(ansi_map_SSDNotShared_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_updateCount,
      { "updateCount", "ansi_map.updateCount",
        FT_UINT32, BASE_DEC, VALS(ansi_map_UpdateCount_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_interMSCCircuitID,
      { "interMSCCircuitID", "ansi_map.interMSCCircuitID_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_mobileIdentificationNumber,
      { "mobileIdentificationNumber", "ansi_map.mobileIdentificationNumber_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_countUpdateReport,
      { "countUpdateReport", "ansi_map.countUpdateReport",
        FT_UINT8, BASE_DEC, VALS(ansi_map_CountUpdateReport_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_uniqueChallengeReport,
      { "uniqueChallengeReport", "ansi_map.uniqueChallengeReport",
        FT_UINT8, BASE_DEC, VALS(ansi_map_UniqueChallengeReport_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_reportType,
      { "reportType", "ansi_map.reportType",
        FT_UINT32, BASE_DEC, VALS(ansi_map_ReportType_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_systemAccessType,
      { "systemAccessType", "ansi_map.systemAccessType",
        FT_UINT32, BASE_DEC, VALS(ansi_map_SystemAccessType_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_systemCapabilities,
      { "systemCapabilities", "ansi_map.systemCapabilities",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_callHistoryCountExpected,
      { "callHistoryCountExpected", "ansi_map.callHistoryCountExpected",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_reportType2,
      { "reportType2", "ansi_map.reportType2",
        FT_UINT32, BASE_DEC, VALS(ansi_map_ReportType_vals), 0,
        "ReportType", HFILL }},
    { &hf_ansi_map_terminalType,
      { "terminalType", "ansi_map.terminalType",
        FT_UINT32, BASE_DEC|BASE_EXT_STRING, &ansi_map_TerminalType_vals_ext, 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationData,
      { "authenticationData", "ansi_map.authenticationData",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationResponse,
      { "authenticationResponse", "ansi_map.authenticationResponse",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaNetworkIdentification,
      { "cdmaNetworkIdentification", "ansi_map.cdmaNetworkIdentification",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_confidentialityModes,
      { "confidentialityModes", "ansi_map.confidentialityModes",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_controlChannelMode,
      { "controlChannelMode", "ansi_map.controlChannelMode",
        FT_UINT8, BASE_DEC, VALS(ansi_map_ControlChannelMode_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_digits,
      { "digits", "ansi_map.digits_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pc_ssn,
      { "pc-ssn", "ansi_map.pc_ssn",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_randomVariable,
      { "randomVariable", "ansi_map.randomVariable",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_serviceRedirectionCause,
      { "serviceRedirectionCause", "ansi_map.serviceRedirectionCause",
        FT_UINT8, BASE_DEC, VALS(ansi_map_ServiceRedirectionCause_type_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_suspiciousAccess,
      { "suspiciousAccess", "ansi_map.suspiciousAccess",
        FT_UINT32, BASE_DEC, VALS(ansi_map_SuspiciousAccess_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_transactionCapability,
      { "transactionCapability", "ansi_map.transactionCapability",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_analogRedirectRecord,
      { "analogRedirectRecord", "ansi_map.analogRedirectRecord_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaRedirectRecord,
      { "cdmaRedirectRecord", "ansi_map.cdmaRedirectRecord_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_dataKey,
      { "dataKey", "ansi_map.dataKey",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_roamingIndication,
      { "roamingIndication", "ansi_map.roamingIndication",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_serviceRedirectionInfo,
      { "serviceRedirectionInfo", "ansi_map.serviceRedirectionInfo",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_voicePrivacyMask,
      { "voicePrivacyMask", "ansi_map.voicePrivacyMask",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_reauthenticationReport,
      { "reauthenticationReport", "ansi_map.reauthenticationReport",
        FT_UINT8, BASE_DEC, VALS(ansi_map_ReauthenticationReport_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_serviceIndicator,
      { "serviceIndicator", "ansi_map.serviceIndicator",
        FT_UINT8, BASE_DEC, VALS(ansi_map_ServiceIndicator_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_signalingMessageEncryptionReport,
      { "signalingMessageEncryptionReport", "ansi_map.signalingMessageEncryptionReport",
        FT_UINT8, BASE_DEC, VALS(ansi_map_SMEReport_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_ssdUpdateReport,
      { "ssdUpdateReport", "ansi_map.ssdUpdateReport",
        FT_UINT16, BASE_DEC, VALS(ansi_map_SSDUpdateReport_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_voicePrivacyReport,
      { "voicePrivacyReport", "ansi_map.voicePrivacyReport",
        FT_UINT8, BASE_DEC, VALS(ansi_map_VoicePrivacyReport_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_randomVariableBaseStation,
      { "randomVariableBaseStation", "ansi_map.randomVariableBaseStation",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationResponseBaseStation,
      { "authenticationResponseBaseStation", "ansi_map.authenticationResponseBaseStation",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_billingID,
      { "billingID", "ansi_map.billingID",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_channelData,
      { "channelData", "ansi_map.channelData",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interSwitchCount,
      { "interSwitchCount", "ansi_map.interSwitchCount",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_servingCellID,
      { "servingCellID", "ansi_map.servingCellID",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_stationClassMark,
      { "stationClassMark", "ansi_map.stationClassMark",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_targetCellID,
      { "targetCellID", "ansi_map.targetCellID",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_handoffReason,
      { "handoffReason", "ansi_map.handoffReason",
        FT_UINT32, BASE_DEC, VALS(ansi_map_HandoffReason_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_handoffState,
      { "handoffState", "ansi_map.handoffState",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tdmaBurstIndicator,
      { "tdmaBurstIndicator", "ansi_map.tdmaBurstIndicator",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tdmaCallMode,
      { "tdmaCallMode", "ansi_map.tdmaCallMode",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tdmaChannelData,
      { "tdmaChannelData", "ansi_map.tdmaChannelData",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_baseStationManufacturerCode,
      { "baseStationManufacturerCode", "ansi_map.baseStationManufacturerCode",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_alertCode,
      { "alertCode", "ansi_map.alertCode",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdma2000HandoffInvokeIOSData,
      { "cdma2000HandoffInvokeIOSData", "ansi_map.cdma2000HandoffInvokeIOSData_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaBandClassList,
      { "cdmaBandClassList", "ansi_map.cdmaBandClassList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaCallMode,
      { "cdmaCallMode", "ansi_map.cdmaCallMode",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaChannelData,
      { "cdmaChannelData", "ansi_map.cdmaChannelData",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaConnectionReferenceList,
      { "cdmaConnectionReferenceList", "ansi_map.cdmaConnectionReferenceList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaMobileProtocolRevision,
      { "cdmaMobileProtocolRevision", "ansi_map.cdmaMobileProtocolRevision",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaMSMeasuredChannelIdentity,
      { "cdmaMSMeasuredChannelIdentity", "ansi_map.cdmaMSMeasuredChannelIdentity",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaServiceConfigurationRecord,
      { "cdmaServiceConfigurationRecord", "ansi_map.cdmaServiceConfigurationRecord",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaServiceOptionList,
      { "cdmaServiceOptionList", "ansi_map.cdmaServiceOptionList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaServingOneWayDelay,
      { "cdmaServingOneWayDelay", "ansi_map.cdmaServingOneWayDelay",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaStationClassMark,
      { "cdmaStationClassMark", "ansi_map.cdmaStationClassMark",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaStationClassMark2,
      { "cdmaStationClassMark2", "ansi_map.cdmaStationClassMark2",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaTargetMAHOList,
      { "cdmaTargetMAHOList", "ansi_map.cdmaTargetMAHOList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaTargetMeasurementList,
      { "cdmaTargetMeasurementList", "ansi_map.cdmaTargetMeasurementList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_dataPrivacyParameters,
      { "dataPrivacyParameters", "ansi_map.dataPrivacyParameters",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_ilspInformation,
      { "ilspInformation", "ansi_map.ilspInformation",
        FT_UINT8, BASE_DEC, VALS(ansi_map_islp_type_vals), 0,
        "ISLPInformation", HFILL }},
    { &hf_ansi_map_msLocation,
      { "msLocation", "ansi_map.msLocation",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_nampsCallMode,
      { "nampsCallMode", "ansi_map.nampsCallMode",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_nampsChannelData,
      { "nampsChannelData", "ansi_map.nampsChannelData",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_nonPublicData,
      { "nonPublicData", "ansi_map.nonPublicData",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pdsnAddress,
      { "pdsnAddress", "ansi_map.pdsnAddress",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pdsnProtocolType,
      { "pdsnProtocolType", "ansi_map.pdsnProtocolType",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_qosPriority,
      { "qosPriority", "ansi_map.qosPriority",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_systemOperatorCode,
      { "systemOperatorCode", "ansi_map.systemOperatorCode",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tdmaBandwidth,
      { "tdmaBandwidth", "ansi_map.tdmaBandwidth",
        FT_UINT8, BASE_DEC, VALS(ansi_map_TDMABandwidth_vals), 0x0f,
        NULL, HFILL }},
    { &hf_ansi_map_tdmaServiceCode,
      { "tdmaServiceCode", "ansi_map.tdmaServiceCode",
        FT_UINT8, BASE_DEC, VALS(ansi_map_TDMAServiceCode_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_tdmaTerminalCapability,
      { "tdmaTerminalCapability", "ansi_map.tdmaTerminalCapability",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tdmaVoiceCoder,
      { "tdmaVoiceCoder", "ansi_map.tdmaVoiceCoder",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_userZoneData,
      { "userZoneData", "ansi_map.userZoneData",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_bsmcstatus,
      { "bsmcstatus", "ansi_map.bsmcstatus",
        FT_UINT8, BASE_DEC, VALS(ansi_map_BSMCStatus_vals), 0x03,
        NULL, HFILL }},
    { &hf_ansi_map_cdma2000HandoffResponseIOSData,
      { "cdma2000HandoffResponseIOSData", "ansi_map.cdma2000HandoffResponseIOSData_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaCodeChannelList,
      { "cdmaCodeChannelList", "ansi_map.cdmaCodeChannelList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaSearchParameters,
      { "cdmaSearchParameters", "ansi_map.cdmaSearchParameters",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaSearchWindow,
      { "cdmaSearchWindow", "ansi_map.cdmaSearchWindow",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sOCStatus,
      { "sOCStatus", "ansi_map.sOCStatus",
        FT_UINT8, BASE_DEC, VALS(ansi_map_SOCStatus_vals), 0x03,
        NULL, HFILL }},
    { &hf_ansi_map_releaseReason,
      { "releaseReason", "ansi_map.releaseReason",
        FT_UINT32, BASE_DEC, VALS(ansi_map_ReleaseReason_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_acgencountered,
      { "acgencountered", "ansi_map.acgencountered",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_callingPartyName,
      { "callingPartyName", "ansi_map.callingPartyName",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_callingPartyNumberDigits1,
      { "callingPartyNumberDigits1", "ansi_map.callingPartyNumberDigits1",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_callingPartyNumberDigits2,
      { "callingPartyNumberDigits2", "ansi_map.callingPartyNumberDigits2",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_callingPartySubaddress,
      { "callingPartySubaddress", "ansi_map.callingPartySubaddress",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_conferenceCallingIndicator,
      { "conferenceCallingIndicator", "ansi_map.conferenceCallingIndicator",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_mobileDirectoryNumber,
      { "mobileDirectoryNumber", "ansi_map.mobileDirectoryNumber_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_mSCIdentificationNumber,
      { "mSCIdentificationNumber", "ansi_map.mSCIdentificationNumber_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_oneTimeFeatureIndicator,
      { "oneTimeFeatureIndicator", "ansi_map.oneTimeFeatureIndicator",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_systemMyTypeCode,
      { "systemMyTypeCode", "ansi_map.systemMyTypeCode",
        FT_UINT32, BASE_DEC|BASE_EXT_STRING, &ansi_map_SystemMyTypeCode_vals_ext, 0,
        NULL, HFILL }},
    { &hf_ansi_map_featureResult,
      { "featureResult", "ansi_map.featureResult",
        FT_UINT32, BASE_DEC, VALS(ansi_map_FeatureResult_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_accessDeniedReason,
      { "accessDeniedReason", "ansi_map.accessDeniedReason",
        FT_UINT32, BASE_DEC, VALS(ansi_map_AccessDeniedReason_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_actionCode,
      { "actionCode", "ansi_map.actionCode",
        FT_UINT8, BASE_DEC|BASE_EXT_STRING|BASE_EXT_STRING, &ansi_map_ActionCode_vals_ext, 0,
        NULL, HFILL }},
    { &hf_ansi_map_announcementList,
      { "announcementList", "ansi_map.announcementList_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_callingPartyNumberString1,
      { "callingPartyNumberString1", "ansi_map.callingPartyNumberString1_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_callingPartyNumberString2,
      { "callingPartyNumberString2", "ansi_map.callingPartyNumberString2_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_digits_Destination,
      { "digits-Destination", "ansi_map.digits_Destination_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "Digits", HFILL }},
    { &hf_ansi_map_displayText,
      { "displayText", "ansi_map.displayText",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_displayText2,
      { "displayText2", "ansi_map.displayText2",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_dmh_AccountCodeDigits,
      { "dmh-AccountCodeDigits", "ansi_map.dmh_AccountCodeDigits",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_dmh_AlternateBillingDigits,
      { "dmh-AlternateBillingDigits", "ansi_map.dmh_AlternateBillingDigits",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_dmh_BillingDigits,
      { "dmh-BillingDigits", "ansi_map.dmh_BillingDigits",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_dmh_RedirectionIndicator,
      { "dmh-RedirectionIndicator", "ansi_map.dmh_RedirectionIndicator",
        FT_UINT32, BASE_DEC|BASE_EXT_STRING, &ansi_map_DMH_RedirectionIndicator_vals_ext, 0,
        NULL, HFILL }},
    { &hf_ansi_map_groupInformation,
      { "groupInformation", "ansi_map.groupInformation",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_noAnswerTime,
      { "noAnswerTime", "ansi_map.noAnswerTime",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pACAIndicator,
      { "pACAIndicator", "ansi_map.pACAIndicator",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pilotNumber,
      { "pilotNumber", "ansi_map.pilotNumber",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_preferredLanguageIndicator,
      { "preferredLanguageIndicator", "ansi_map.preferredLanguageIndicator",
        FT_UINT8, BASE_DEC, VALS(ansi_map_PreferredLanguageIndicator_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_redirectingNumberDigits,
      { "redirectingNumberDigits", "ansi_map.redirectingNumberDigits",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_redirectingNumberString,
      { "redirectingNumberString", "ansi_map.redirectingNumberString",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_redirectingSubaddress,
      { "redirectingSubaddress", "ansi_map.redirectingSubaddress",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_resumePIC,
      { "resumePIC", "ansi_map.resumePIC",
        FT_UINT32, BASE_DEC, VALS(ansi_map_ResumePIC_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_terminationList,
      { "terminationList", "ansi_map.terminationList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_terminationTriggers,
      { "terminationTriggers", "ansi_map.terminationTriggers",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_triggerAddressList,
      { "triggerAddressList", "ansi_map.triggerAddressList_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_emergencyServicesRoutingDigits,
      { "emergencyServicesRoutingDigits", "ansi_map.emergencyServicesRoutingDigits",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_targetCellIDList,
      { "targetCellIDList", "ansi_map.targetCellIDList_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_signalQuality,
      { "signalQuality", "ansi_map.signalQuality",
        FT_UINT32, BASE_DEC|BASE_EXT_STRING, &ansi_map_SignalQuality_vals_ext, 0,
        NULL, HFILL }},
    { &hf_ansi_map_targetMeasurementList,
      { "targetMeasurementList", "ansi_map.targetMeasurementList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_alertResult,
      { "alertResult", "ansi_map.alertResult",
        FT_UINT8, BASE_DEC, VALS(ansi_map_AlertResult_result_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_messageWaitingNotificationCount,
      { "messageWaitingNotificationCount", "ansi_map.messageWaitingNotificationCount",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_messageWaitingNotificationType,
      { "messageWaitingNotificationType", "ansi_map.messageWaitingNotificationType",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaBandClass,
      { "cdmaBandClass", "ansi_map.cdmaBandClass",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaServiceOption,
      { "cdmaServiceOption", "ansi_map.cdmaServiceOption",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaSlotCycleIndex,
      { "cdmaSlotCycleIndex", "ansi_map.cdmaSlotCycleIndex",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_extendedMSCID,
      { "extendedMSCID", "ansi_map.extendedMSCID",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_extendedSystemMyTypeCode,
      { "extendedSystemMyTypeCode", "ansi_map.extendedSystemMyTypeCode",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_imsi,
      { "imsi", "ansi_map.imsi",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_legInformation,
      { "legInformation", "ansi_map.legInformation",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_mSIDUsage,
      { "mSIDUsage", "ansi_map.mSIDUsage",
        FT_UINT8, BASE_DEC, VALS(ansi_MSIDUsage_m_or_i_vals), 0x03,
        NULL, HFILL }},
    { &hf_ansi_map_networkTMSI,
      { "networkTMSI", "ansi_map.networkTMSI",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pageCount,
      { "pageCount", "ansi_map.pageCount",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pageIndicator,
      { "pageIndicator", "ansi_map.pageIndicator",
        FT_UINT8, BASE_DEC, VALS(ansi_map_PageIndicator_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_pageResponseTime,
      { "pageResponseTime", "ansi_map.pageResponseTime",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pilotBillingID,
      { "pilotBillingID", "ansi_map.pilotBillingID",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_redirectingPartyName,
      { "redirectingPartyName", "ansi_map.redirectingPartyName",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tdmaDataFeaturesIndicator,
      { "tdmaDataFeaturesIndicator", "ansi_map.tdmaDataFeaturesIndicator",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_terminationTreatment,
      { "terminationTreatment", "ansi_map.terminationTreatment",
        FT_UINT8, BASE_DEC, VALS(ansi_map_TerminationTreatment_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_conditionallyDeniedReason,
      { "conditionallyDeniedReason", "ansi_map.conditionallyDeniedReason",
        FT_UINT32, BASE_DEC, VALS(ansi_map_ConditionallyDeniedReason_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_pagingFrameClass,
      { "pagingFrameClass", "ansi_map.pagingFrameClass",
        FT_UINT8, BASE_DEC, VALS(ansi_map_PagingFrameClass_vals), 0x03,
        NULL, HFILL }},
    { &hf_ansi_map_pSID_RSIDList,
      { "pSID-RSIDList", "ansi_map.pSID_RSIDList_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_randc,
      { "randc", "ansi_map.randc",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tdmaDataMode,
      { "tdmaDataMode", "ansi_map.tdmaDataMode",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_changeServiceAttributes,
      { "changeServiceAttributes", "ansi_map.changeServiceAttributes",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_edirectingSubaddress,
      { "edirectingSubaddress", "ansi_map.edirectingSubaddress",
        FT_BYTES, BASE_NONE, NULL, 0,
        "RedirectingSubaddress", HFILL }},
    { &hf_ansi_map_setupResult,
      { "setupResult", "ansi_map.setupResult",
        FT_UINT8, BASE_DEC, VALS(ansi_map_SetupResult_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_terminationAccessType,
      { "terminationAccessType", "ansi_map.terminationAccessType",
        FT_UINT8, BASE_DEC, VALS(ansi_map_TerminationAccessType_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_triggerType,
      { "triggerType", "ansi_map.triggerType",
        FT_UINT32, BASE_DEC|BASE_EXT_STRING, &ansi_map_TriggerType_vals_ext, 0,
        NULL, HFILL }},
    { &hf_ansi_map_winCapability,
      { "winCapability", "ansi_map.winCapability_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_callingPartyCategory,
      { "callingPartyCategory", "ansi_map.callingPartyCategory",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_controlNetworkID,
      { "controlNetworkID", "ansi_map.controlNetworkID",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_digits_carrier,
      { "digits-carrier", "ansi_map.digits_carrier_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "Digits", HFILL }},
    { &hf_ansi_map_digits_dest,
      { "digits-dest", "ansi_map.digits_dest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "Digits", HFILL }},
    { &hf_ansi_map_dmh_ServiceID,
      { "dmh-ServiceID", "ansi_map.dmh_ServiceID",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_lectronicSerialNumber,
      { "lectronicSerialNumber", "ansi_map.lectronicSerialNumber",
        FT_BYTES, BASE_NONE, NULL, 0,
        "ElectronicSerialNumber", HFILL }},
    { &hf_ansi_map_deregistrationType,
      { "deregistrationType", "ansi_map.deregistrationType",
        FT_UINT32, BASE_DEC, VALS(ansi_map_DeregistrationType_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_servicesResult,
      { "servicesResult", "ansi_map.servicesResult",
        FT_UINT8, BASE_DEC, VALS(ansi_map_ServicesResult_ppr_vals), 0x03,
        NULL, HFILL }},
    { &hf_ansi_map_sms_MessageWaitingIndicator,
      { "sms-MessageWaitingIndicator", "ansi_map.sms_MessageWaitingIndicator_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_featureIndicator,
      { "featureIndicator", "ansi_map.featureIndicator",
        FT_UINT32, BASE_DEC, VALS(ansi_map_FeatureIndicator_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationCapability,
      { "authenticationCapability", "ansi_map.authenticationCapability",
        FT_UINT8, BASE_DEC, VALS(ansi_map_AuthenticationCapability_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_callingFeaturesIndicator,
      { "callingFeaturesIndicator", "ansi_map.callingFeaturesIndicator",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_geographicAuthorization,
      { "geographicAuthorization", "ansi_map.geographicAuthorization",
        FT_UINT8, BASE_DEC, VALS(ansi_map_GeographicAuthorization_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_meidValidated,
      { "meidValidated", "ansi_map.meidValidated_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_mobilePositionCapability,
      { "mobilePositionCapability", "ansi_map.mobilePositionCapability",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_originationIndicator,
      { "originationIndicator", "ansi_map.originationIndicator",
        FT_UINT32, BASE_DEC, VALS(ansi_map_OriginationIndicator_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_originationTriggers,
      { "originationTriggers", "ansi_map.originationTriggers",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_restrictionDigits,
      { "restrictionDigits", "ansi_map.restrictionDigits",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_OriginationRestrictions,
      { "sms-OriginationRestrictions", "ansi_map.sms_OriginationRestrictions",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_TerminationRestrictions,
      { "sms-TerminationRestrictions", "ansi_map.sms_TerminationRestrictions",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_spinipin,
      { "spinipin", "ansi_map.spinipin",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_spiniTriggers,
      { "spiniTriggers", "ansi_map.spiniTriggers",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_terminationRestrictionCode,
      { "terminationRestrictionCode", "ansi_map.terminationRestrictionCode",
        FT_UINT32, BASE_DEC, VALS(ansi_map_TerminationRestrictionCode_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_userGroup,
      { "userGroup", "ansi_map.userGroup",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_lirMode,
      { "lirMode", "ansi_map.lirMode",
        FT_UINT32, BASE_DEC, VALS(ansi_map_LIRMode_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaCodeChannel,
      { "cdmaCodeChannel", "ansi_map.cdmaCodeChannel",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaMobileCapabilities,
      { "cdmaMobileCapabilities", "ansi_map.cdmaMobileCapabilities",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaServingOneWayDelay2,
      { "cdmaServingOneWayDelay2", "ansi_map.cdmaServingOneWayDelay2",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaPSMMList,
      { "cdmaPSMMList", "ansi_map.cdmaPSMMList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_mpcAddress,
      { "mpcAddress", "ansi_map.mpcAddress",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_dmh_ChargeInformation,
      { "dmh-ChargeInformation", "ansi_map.dmh_ChargeInformation",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_qualificationInformationCode,
      { "qualificationInformationCode", "ansi_map.qualificationInformationCode",
        FT_UINT32, BASE_DEC, VALS(ansi_map_QualificationInformationCode_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_authorizationDenied,
      { "authorizationDenied", "ansi_map.authorizationDenied",
        FT_UINT32, BASE_DEC, VALS(ansi_map_AuthorizationDenied_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_authorizationPeriod,
      { "authorizationPeriod", "ansi_map.authorizationPeriod",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_deniedAuthorizationPeriod,
      { "deniedAuthorizationPeriod", "ansi_map.deniedAuthorizationPeriod",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_randValidTime,
      { "randValidTime", "ansi_map.randValidTime",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_redirectionReason,
      { "redirectionReason", "ansi_map.redirectionReason",
        FT_UINT32, BASE_DEC, VALS(ansi_map_RedirectionReason_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_cancellationType,
      { "cancellationType", "ansi_map.cancellationType",
        FT_UINT8, BASE_DEC, VALS(ansi_map_CancellationType_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_controlChannelData,
      { "controlChannelData", "ansi_map.controlChannelData",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_receivedSignalQuality,
      { "receivedSignalQuality", "ansi_map.receivedSignalQuality",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_systemAccessData,
      { "systemAccessData", "ansi_map.systemAccessData",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cancellationDenied,
      { "cancellationDenied", "ansi_map.cancellationDenied",
        FT_UINT32, BASE_DEC, VALS(ansi_map_CancellationDenied_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_availabilityType,
      { "availabilityType", "ansi_map.availabilityType",
        FT_UINT8, BASE_DEC, VALS(ansi_map_AvailabilityType_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_borderCellAccess,
      { "borderCellAccess", "ansi_map.borderCellAccess",
        FT_UINT32, BASE_DEC, VALS(ansi_map_BorderCellAccess_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_msc_Address,
      { "msc-Address", "ansi_map.msc_Address",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_Address,
      { "sms-Address", "ansi_map.sms_Address_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_mpcAddressList,
      { "mpcAddressList", "ansi_map.mpcAddressList_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_digits_Carrier,
      { "digits-Carrier", "ansi_map.digits_Carrier_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "Digits", HFILL }},
    { &hf_ansi_map_digitCollectionControl,
      { "digitCollectionControl", "ansi_map.digitCollectionControl",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_trunkStatus,
      { "trunkStatus", "ansi_map.trunkStatus",
        FT_UINT32, BASE_DEC, VALS(ansi_map_TrunkStatus_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_voiceMailboxNumber,
      { "voiceMailboxNumber", "ansi_map.voiceMailboxNumber",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_voiceMailboxPIN,
      { "voiceMailboxPIN", "ansi_map.voiceMailboxPIN",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_BearerData,
      { "sms-BearerData", "ansi_map.sms_BearerData",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_TeleserviceIdentifier,
      { "sms-TeleserviceIdentifier", "ansi_map.sms_TeleserviceIdentifier",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_ChargeIndicator,
      { "sms-ChargeIndicator", "ansi_map.sms_ChargeIndicator",
        FT_UINT8, BASE_DEC, VALS(ansi_map_SMS_ChargeIndicator_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_DestinationAddress,
      { "sms-DestinationAddress", "ansi_map.sms_DestinationAddress_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_OriginalDestinationAddress,
      { "sms-OriginalDestinationAddress", "ansi_map.sms_OriginalDestinationAddress_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_OriginalDestinationSubaddress,
      { "sms-OriginalDestinationSubaddress", "ansi_map.sms_OriginalDestinationSubaddress",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_OriginalOriginatingAddress,
      { "sms-OriginalOriginatingAddress", "ansi_map.sms_OriginalOriginatingAddress_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_OriginalOriginatingSubaddress,
      { "sms-OriginalOriginatingSubaddress", "ansi_map.sms_OriginalOriginatingSubaddress",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_OriginatingAddress,
      { "sms-OriginatingAddress", "ansi_map.sms_OriginatingAddress_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_CauseCode,
      { "sms-CauseCode", "ansi_map.sms_CauseCode",
        FT_UINT8, BASE_DEC|BASE_EXT_STRING|BASE_EXT_STRING, &ansi_map_SMS_CauseCode_vals_ext, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interMessageTime,
      { "interMessageTime", "ansi_map.interMessageTime",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_newlyAssignedIMSI,
      { "newlyAssignedIMSI", "ansi_map.newlyAssignedIMSI",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_newlyAssignedMIN,
      { "newlyAssignedMIN", "ansi_map.newlyAssignedMIN_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_newMINExtension,
      { "newMINExtension", "ansi_map.newMINExtension",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_MessageCount,
      { "sms-MessageCount", "ansi_map.sms_MessageCount",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_NotificationIndicator,
      { "sms-NotificationIndicator", "ansi_map.sms_NotificationIndicator",
        FT_UINT8, BASE_DEC, VALS(ansi_map_SMS_NotificationIndicator_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_teleservice_Priority,
      { "teleservice-Priority", "ansi_map.teleservice_Priority",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_temporaryReferenceNumber,
      { "temporaryReferenceNumber", "ansi_map.temporaryReferenceNumber_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_mobileStationMSID,
      { "mobileStationMSID", "ansi_map.mobileStationMSID",
        FT_UINT32, BASE_DEC, VALS(ansi_map_MobileStationMSID_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_TransactionID,
      { "sms-TransactionID", "ansi_map.sms_TransactionID",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sms_AccessDeniedReason,
      { "sms-AccessDeniedReason", "ansi_map.sms_AccessDeniedReason",
        FT_UINT8, BASE_DEC, VALS(ansi_map_SMS_AccessDeniedReason_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_seizureType,
      { "seizureType", "ansi_map.seizureType",
        FT_UINT32, BASE_DEC, VALS(ansi_map_SeizureType_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_requiredParametersMask,
      { "requiredParametersMask", "ansi_map.requiredParametersMask",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_reasonList,
      { "reasonList", "ansi_map.reasonList",
        FT_UINT32, BASE_DEC, VALS(ansi_map_ReasonList_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_networkTMSIExpirationTime,
      { "networkTMSIExpirationTime", "ansi_map.networkTMSIExpirationTime",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_newNetworkTMSI,
      { "newNetworkTMSI", "ansi_map.newNetworkTMSI",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_serviceID,
      { "serviceID", "ansi_map.serviceID",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_dataAccessElementList,
      { "dataAccessElementList", "ansi_map.dataAccessElementList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_timeDateOffset,
      { "timeDateOffset", "ansi_map.timeDateOffset",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_timeOfDay,
      { "timeOfDay", "ansi_map.timeOfDay",
        FT_INT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_dmd_BillingIndicator,
      { "dmd-BillingIndicator", "ansi_map.dmd_BillingIndicator",
        FT_UINT32, BASE_DEC, VALS(ansi_map_DMH_BillingIndicator_vals), 0,
        "DMH_BillingIndicator", HFILL }},
    { &hf_ansi_map_failureType,
      { "failureType", "ansi_map.failureType",
        FT_UINT32, BASE_DEC, VALS(ansi_map_FailureType_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_failureCause,
      { "failureCause", "ansi_map.failureCause",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_outingDigits,
      { "outingDigits", "ansi_map.outingDigits",
        FT_BYTES, BASE_NONE, NULL, 0,
        "RoutingDigits", HFILL }},
    { &hf_ansi_map_databaseKey,
      { "databaseKey", "ansi_map.databaseKey",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_modificationRequestList,
      { "modificationRequestList", "ansi_map.modificationRequestList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_modificationResultList,
      { "modificationResultList", "ansi_map.modificationResultList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_serviceDataAccessElementList,
      { "serviceDataAccessElementList", "ansi_map.serviceDataAccessElementList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_privateSpecializedResource,
      { "privateSpecializedResource", "ansi_map.privateSpecializedResource",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_specializedResource,
      { "specializedResource", "ansi_map.specializedResource",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_executeScript,
      { "executeScript", "ansi_map.executeScript_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_scriptResult,
      { "scriptResult", "ansi_map.scriptResult",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tdmaVoiceMode,
      { "tdmaVoiceMode", "ansi_map.tdmaVoiceMode",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_callStatus,
      { "callStatus", "ansi_map.callStatus",
        FT_UINT32, BASE_DEC, VALS(ansi_map_CallStatus_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_releaseCause,
      { "releaseCause", "ansi_map.releaseCause",
        FT_UINT32, BASE_DEC, VALS(ansi_map_ReleaseCause_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_callRecoveryIDList,
      { "callRecoveryIDList", "ansi_map.callRecoveryIDList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_positionInformationCode,
      { "positionInformationCode", "ansi_map.positionInformationCode",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_mSStatus,
      { "mSStatus", "ansi_map.mSStatus",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pSID_RSIDInformation,
      { "pSID-RSIDInformation", "ansi_map.pSID_RSIDInformation",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_positionRequestType,
      { "positionRequestType", "ansi_map.positionRequestType",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_lcsBillingID,
      { "lcsBillingID", "ansi_map.lcsBillingID",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_lcs_Client_ID,
      { "lcs-Client-ID", "ansi_map.lcs_Client_ID",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_dtxIndication,
      { "dtxIndication", "ansi_map.dtxIndication",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tdma_MAHO_CELLID,
      { "tdma-MAHO-CELLID", "ansi_map.tdma_MAHO_CELLID",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tdma_MAHO_CHANNEL,
      { "tdma-MAHO-CHANNEL", "ansi_map.tdma_MAHO_CHANNEL",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tdma_TimeAlignment,
      { "tdma-TimeAlignment", "ansi_map.tdma_TimeAlignment",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pqos_HorizontalPosition,
      { "pqos-HorizontalPosition", "ansi_map.pqos_HorizontalPosition",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pqos_HorizontalVelocity,
      { "pqos-HorizontalVelocity", "ansi_map.pqos_HorizontalVelocity",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pqos_MaximumPositionAge,
      { "pqos-MaximumPositionAge", "ansi_map.pqos_MaximumPositionAge",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pqos_PositionPriority,
      { "pqos-PositionPriority", "ansi_map.pqos_PositionPriority",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pqos_ResponseTime,
      { "pqos-ResponseTime", "ansi_map.pqos_ResponseTime",
        FT_UINT32, BASE_DEC, VALS(ansi_map_PQOS_ResponseTime_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_pqos_VerticalPosition,
      { "pqos-VerticalPosition", "ansi_map.pqos_VerticalPosition",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pqos_VerticalVelocity,
      { "pqos-VerticalVelocity", "ansi_map.pqos_VerticalVelocity",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaPSMMCount,
      { "cdmaPSMMCount", "ansi_map.cdmaPSMMCount",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_lirAuthorization,
      { "lirAuthorization", "ansi_map.lirAuthorization",
        FT_UINT32, BASE_DEC, VALS(ansi_map_LIRAuthorization_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_mpcid,
      { "mpcid", "ansi_map.mpcid",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tdma_MAHORequest,
      { "tdma-MAHORequest", "ansi_map.tdma_MAHORequest",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_positionResult,
      { "positionResult", "ansi_map.positionResult",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_positionInformation,
      { "positionInformation", "ansi_map.positionInformation_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_controlType,
      { "controlType", "ansi_map.controlType",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_destinationAddress,
      { "destinationAddress", "ansi_map.destinationAddress",
        FT_UINT32, BASE_DEC, VALS(ansi_map_DestinationAddress_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_gapDuration,
      { "gapDuration", "ansi_map.gapDuration",
        FT_UINT32, BASE_DEC, VALS(ansi_map_GapDuration_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_gapInterval,
      { "gapInterval", "ansi_map.gapInterval",
        FT_UINT32, BASE_DEC, VALS(ansi_map_GapInterval_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_invokingNEType,
      { "invokingNEType", "ansi_map.invokingNEType",
        FT_INT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_range,
      { "range", "ansi_map.range",
        FT_INT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_meidStatus,
      { "meidStatus", "ansi_map.meidStatus",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_aKeyProtocolVersion,
      { "aKeyProtocolVersion", "ansi_map.aKeyProtocolVersion",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_mobileStationPartialKey,
      { "mobileStationPartialKey", "ansi_map.mobileStationPartialKey",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_newlyAssignedMSID,
      { "newlyAssignedMSID", "ansi_map.newlyAssignedMSID",
        FT_UINT32, BASE_DEC, VALS(ansi_map_NewlyAssignedMSID_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_baseStationPartialKey,
      { "baseStationPartialKey", "ansi_map.baseStationPartialKey",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_modulusValue,
      { "modulusValue", "ansi_map.modulusValue",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_otasp_ResultCode,
      { "otasp-ResultCode", "ansi_map.otasp_ResultCode",
        FT_UINT8, BASE_DEC, VALS(ansi_map_OTASP_ResultCode_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_primitiveValue,
      { "primitiveValue", "ansi_map.primitiveValue",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_record_Type,
      { "record-Type", "ansi_map.record_Type",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_information_Record,
      { "information-Record", "ansi_map.information_Record",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdma2000MobileSupportedCapabilities,
      { "cdma2000MobileSupportedCapabilities", "ansi_map.cdma2000MobileSupportedCapabilities",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_announcementCode1,
      { "announcementCode1", "ansi_map.announcementCode1",
        FT_BYTES, BASE_NONE, NULL, 0,
        "AnnouncementCode", HFILL }},
    { &hf_ansi_map_announcementCode2,
      { "announcementCode2", "ansi_map.announcementCode2",
        FT_BYTES, BASE_NONE, NULL, 0,
        "AnnouncementCode", HFILL }},
    { &hf_ansi_map_cdmaPilotPN,
      { "cdmaPilotPN", "ansi_map.cdmaPilotPN",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaPowerCombinedIndicator,
      { "cdmaPowerCombinedIndicator", "ansi_map.cdmaPowerCombinedIndicator",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_CDMACodeChannelList_item,
      { "CDMACodeChannelInformation", "ansi_map.CDMACodeChannelInformation_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaPilotStrength,
      { "cdmaPilotStrength", "ansi_map.cdmaPilotStrength",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaTargetOneWayDelay,
      { "cdmaTargetOneWayDelay", "ansi_map.cdmaTargetOneWayDelay",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_CDMATargetMAHOList_item,
      { "CDMATargetMAHOInformation", "ansi_map.CDMATargetMAHOInformation_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaSignalQuality,
      { "cdmaSignalQuality", "ansi_map.cdmaSignalQuality",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_CDMATargetMeasurementList_item,
      { "CDMATargetMeasurementInformation", "ansi_map.CDMATargetMeasurementInformation_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_TargetMeasurementList_item,
      { "TargetMeasurementInformation", "ansi_map.TargetMeasurementInformation_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_TerminationList_item,
      { "TerminationList item", "ansi_map.TerminationList_item",
        FT_UINT32, BASE_DEC, VALS(ansi_map_TerminationList_item_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_intersystemTermination,
      { "intersystemTermination", "ansi_map.intersystemTermination_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_localTermination,
      { "localTermination", "ansi_map.localTermination_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pstnTermination,
      { "pstnTermination", "ansi_map.pstnTermination_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_CDMABandClassList_item,
      { "CDMABandClassInformation", "ansi_map.CDMABandClassInformation_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_CDMAServiceOptionList_item,
      { "CDMAServiceOption", "ansi_map.CDMAServiceOption",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pSID_RSIDInformation1,
      { "pSID-RSIDInformation1", "ansi_map.pSID_RSIDInformation1",
        FT_BYTES, BASE_NONE, NULL, 0,
        "PSID_RSIDInformation", HFILL }},
    { &hf_ansi_map_targetCellID1,
      { "targetCellID1", "ansi_map.targetCellID1",
        FT_BYTES, BASE_NONE, NULL, 0,
        "TargetCellID", HFILL }},
    { &hf_ansi_map_cdmaConnectionReference,
      { "cdmaConnectionReference", "ansi_map.cdmaConnectionReference",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaState,
      { "cdmaState", "ansi_map.cdmaState",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaServiceOptionConnectionIdentifier,
      { "cdmaServiceOptionConnectionIdentifier", "ansi_map.cdmaServiceOptionConnectionIdentifier",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_CDMAConnectionReferenceList_item,
      { "CDMAConnectionReferenceList item", "ansi_map.CDMAConnectionReferenceList_item_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaConnectionReferenceInformation,
      { "cdmaConnectionReferenceInformation", "ansi_map.cdmaConnectionReferenceInformation_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaConnectionReferenceInformation2,
      { "cdmaConnectionReferenceInformation2", "ansi_map.cdmaConnectionReferenceInformation2_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "CDMAConnectionReferenceInformation", HFILL }},
    { &hf_ansi_map_analogRedirectInfo,
      { "analogRedirectInfo", "ansi_map.analogRedirectInfo",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_CDMAChannelNumberList_item,
      { "CDMAChannelNumberList item", "ansi_map.CDMAChannelNumberList_item_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaChannelNumber,
      { "cdmaChannelNumber", "ansi_map.cdmaChannelNumber",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaChannelNumber2,
      { "cdmaChannelNumber2", "ansi_map.cdmaChannelNumber2",
        FT_BYTES, BASE_NONE, NULL, 0,
        "CDMAChannelNumber", HFILL }},
    { &hf_ansi_map_cdmaChannelNumberList,
      { "cdmaChannelNumberList", "ansi_map.cdmaChannelNumberList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_dataID,
      { "dataID", "ansi_map.dataID",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_change,
      { "change", "ansi_map.change",
        FT_UINT32, BASE_DEC, VALS(ansi_map_Change_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_dataValue,
      { "dataValue", "ansi_map.dataValue",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_DataAccessElementList_item,
      { "DataAccessElementList item", "ansi_map.DataAccessElementList_item_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_dataAccessElement1,
      { "dataAccessElement1", "ansi_map.dataAccessElement1_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "DataAccessElement", HFILL }},
    { &hf_ansi_map_dataAccessElement2,
      { "dataAccessElement2", "ansi_map.dataAccessElement2_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "DataAccessElement", HFILL }},
    { &hf_ansi_map_dataResult,
      { "dataResult", "ansi_map.dataResult",
        FT_UINT32, BASE_DEC, VALS(ansi_map_DataResult_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_DataUpdateResultList_item,
      { "DataUpdateResult", "ansi_map.DataUpdateResult_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_globalTitle,
      { "globalTitle", "ansi_map.globalTitle",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_pC_SSN,
      { "pC-SSN", "ansi_map.pC_SSN",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_scriptName,
      { "scriptName", "ansi_map.scriptName",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_scriptArgument,
      { "scriptArgument", "ansi_map.scriptArgument",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_allOrNone,
      { "allOrNone", "ansi_map.allOrNone",
        FT_UINT32, BASE_DEC, VALS(ansi_map_AllOrNone_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_ModificationRequestList_item,
      { "ModificationRequest", "ansi_map.ModificationRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_serviceDataResultList,
      { "serviceDataResultList", "ansi_map.serviceDataResultList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_ModificationResultList_item,
      { "ModificationResult", "ansi_map.ModificationResult",
        FT_UINT32, BASE_DEC, VALS(ansi_map_ModificationResult_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_ServiceDataAccessElementList_item,
      { "ServiceDataAccessElement", "ansi_map.ServiceDataAccessElement_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_dataUpdateResultList,
      { "dataUpdateResultList", "ansi_map.dataUpdateResultList",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_ServiceDataResultList_item,
      { "ServiceDataResult", "ansi_map.ServiceDataResult_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_triggerList,
      { "triggerList", "ansi_map.triggerList_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_triggerListOpt,
      { "triggerListOpt", "ansi_map.triggerListOpt_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "TriggerList", HFILL }},
    { &hf_ansi_map_wIN_TriggerList,
      { "wIN-TriggerList", "ansi_map.wIN_TriggerList",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_triggerCapability,
      { "triggerCapability", "ansi_map.triggerCapability",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_wINOperationsCapability,
      { "wINOperationsCapability", "ansi_map.wINOperationsCapability",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_CallRecoveryIDList_item,
      { "CallRecoveryID", "ansi_map.CallRecoveryID_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_generalizedTime,
      { "generalizedTime", "ansi_map.generalizedTime",
        FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_geographicPosition,
      { "geographicPosition", "ansi_map.geographicPosition",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_positionSource,
      { "positionSource", "ansi_map.positionSource",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_horizontal_Velocity,
      { "horizontal-Velocity", "ansi_map.horizontal_Velocity",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_vertical_Velocity,
      { "vertical-Velocity", "ansi_map.vertical_Velocity",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sCFOverloadGapInterval,
      { "sCFOverloadGapInterval", "ansi_map.sCFOverloadGapInterval",
        FT_UINT32, BASE_DEC, VALS(ansi_map_SCFOverloadGapInterval_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_serviceManagementSystemGapInterval,
      { "serviceManagementSystemGapInterval", "ansi_map.serviceManagementSystemGapInterval",
        FT_UINT32, BASE_DEC, VALS(ansi_map_ServiceManagementSystemGapInterval_vals), 0,
        NULL, HFILL }},
    { &hf_ansi_map_CDMAPSMMList_item,
      { "CDMAPSMMList item", "ansi_map.CDMAPSMMList_item_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_cdmaTargetMAHOList2,
      { "cdmaTargetMAHOList2", "ansi_map.cdmaTargetMAHOList2",
        FT_UINT32, BASE_DEC, NULL, 0,
        "CDMATargetMAHOList", HFILL }},
    { &hf_ansi_map_mpcAddress2,
      { "mpcAddress2", "ansi_map.mpcAddress2",
        FT_BYTES, BASE_NONE, NULL, 0,
        "MPCAddress", HFILL }},
    { &hf_ansi_map_mobileStationIMSI,
      { "mobileStationIMSI", "ansi_map.mobileStationIMSI",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_handoffMeasurementRequest,
      { "handoffMeasurementRequest", "ansi_map.handoffMeasurementRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_facilitiesDirective,
      { "facilitiesDirective", "ansi_map.facilitiesDirective_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_handoffBack,
      { "handoffBack", "ansi_map.handoffBack_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_facilitiesRelease,
      { "facilitiesRelease", "ansi_map.facilitiesRelease_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_qualificationRequest,
      { "qualificationRequest", "ansi_map.qualificationRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_qualificationDirective,
      { "qualificationDirective", "ansi_map.qualificationDirective_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_blocking,
      { "blocking", "ansi_map.blocking_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_unblocking,
      { "unblocking", "ansi_map.unblocking_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_resetCircuit,
      { "resetCircuit", "ansi_map.resetCircuit_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_trunkTest,
      { "trunkTest", "ansi_map.trunkTest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_trunkTestDisconnect,
      { "trunkTestDisconnect", "ansi_map.trunkTestDisconnect_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_registrationNotification,
      { "registrationNotification", "ansi_map.registrationNotification_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_registrationCancellation,
      { "registrationCancellation", "ansi_map.registrationCancellation_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_locationRequest,
      { "locationRequest", "ansi_map.locationRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_routingRequest,
      { "routingRequest", "ansi_map.routingRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_featureRequest,
      { "featureRequest", "ansi_map.featureRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_unreliableRoamerDataDirective,
      { "unreliableRoamerDataDirective", "ansi_map.unreliableRoamerDataDirective_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_mSInactive,
      { "mSInactive", "ansi_map.mSInactive_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_transferToNumberRequest,
      { "transferToNumberRequest", "ansi_map.transferToNumberRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_redirectionRequest,
      { "redirectionRequest", "ansi_map.redirectionRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_handoffToThird,
      { "handoffToThird", "ansi_map.handoffToThird_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_flashRequest,
      { "flashRequest", "ansi_map.flashRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationDirective,
      { "authenticationDirective", "ansi_map.authenticationDirective_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationRequest,
      { "authenticationRequest", "ansi_map.authenticationRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_baseStationChallenge,
      { "baseStationChallenge", "ansi_map.baseStationChallenge_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationFailureReport,
      { "authenticationFailureReport", "ansi_map.authenticationFailureReport_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_countRequest,
      { "countRequest", "ansi_map.countRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interSystemPage,
      { "interSystemPage", "ansi_map.interSystemPage_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_unsolicitedResponse,
      { "unsolicitedResponse", "ansi_map.unsolicitedResponse_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_bulkDeregistration,
      { "bulkDeregistration", "ansi_map.bulkDeregistration_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_handoffMeasurementRequest2,
      { "handoffMeasurementRequest2", "ansi_map.handoffMeasurementRequest2_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_facilitiesDirective2,
      { "facilitiesDirective2", "ansi_map.facilitiesDirective2_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_handoffBack2,
      { "handoffBack2", "ansi_map.handoffBack2_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_handoffToThird2,
      { "handoffToThird2", "ansi_map.handoffToThird2_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationDirectiveForward,
      { "authenticationDirectiveForward", "ansi_map.authenticationDirectiveForward_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationStatusReport,
      { "authenticationStatusReport", "ansi_map.authenticationStatusReport_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_informationDirective,
      { "informationDirective", "ansi_map.informationDirective_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_informationForward,
      { "informationForward", "ansi_map.informationForward_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interSystemAnswer,
      { "interSystemAnswer", "ansi_map.interSystemAnswer_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interSystemPage2,
      { "interSystemPage2", "ansi_map.interSystemPage2_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interSystemSetup,
      { "interSystemSetup", "ansi_map.interSystemSetup_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_originationRequest,
      { "originationRequest", "ansi_map.originationRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_randomVariableRequest,
      { "randomVariableRequest", "ansi_map.randomVariableRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_redirectionDirective,
      { "redirectionDirective", "ansi_map.redirectionDirective_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_remoteUserInteractionDirective,
      { "remoteUserInteractionDirective", "ansi_map.remoteUserInteractionDirective_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sMSDeliveryBackward,
      { "sMSDeliveryBackward", "ansi_map.sMSDeliveryBackward_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sMSDeliveryForward,
      { "sMSDeliveryForward", "ansi_map.sMSDeliveryForward_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sMSDeliveryPointToPoint,
      { "sMSDeliveryPointToPoint", "ansi_map.sMSDeliveryPointToPoint_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sMSNotification,
      { "sMSNotification", "ansi_map.sMSNotification_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sMSRequest,
      { "sMSRequest", "ansi_map.sMSRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_oTASPRequest,
      { "oTASPRequest", "ansi_map.oTASPRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_changeFacilities,
      { "changeFacilities", "ansi_map.changeFacilities_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_changeService,
      { "changeService", "ansi_map.changeService_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_parameterRequest,
      { "parameterRequest", "ansi_map.parameterRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tMSIDirective,
      { "tMSIDirective", "ansi_map.tMSIDirective_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_numberPortabilityRequest,
      { "numberPortabilityRequest", "ansi_map.numberPortabilityRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_serviceRequest,
      { "serviceRequest", "ansi_map.serviceRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_analyzedInformation,
      { "analyzedInformation", "ansi_map.analyzedInformation_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_connectionFailureReport,
      { "connectionFailureReport", "ansi_map.connectionFailureReport_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_connectResource,
      { "connectResource", "ansi_map.connectResource_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_facilitySelectedAndAvailable,
      { "facilitySelectedAndAvailable", "ansi_map.facilitySelectedAndAvailable_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_modify,
      { "modify", "ansi_map.modify_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_search,
      { "search", "ansi_map.search_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_seizeResource,
      { "seizeResource", "ansi_map.seizeResource_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sRFDirective,
      { "sRFDirective", "ansi_map.sRFDirective_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tBusy,
      { "tBusy", "ansi_map.tBusy_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tNoAnswer,
      { "tNoAnswer", "ansi_map.tNoAnswer_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_smsDeliveryPointToPointAck,
      { "smsDeliveryPointToPointAck", "ansi_map.smsDeliveryPointToPointAck_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_messageDirective,
      { "messageDirective", "ansi_map.messageDirective_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_bulkDisconnection,
      { "bulkDisconnection", "ansi_map.bulkDisconnection_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_callControlDirective,
      { "callControlDirective", "ansi_map.callControlDirective_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_oAnswer,
      { "oAnswer", "ansi_map.oAnswer_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_oDisconnect,
      { "oDisconnect", "ansi_map.oDisconnect_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_callRecoveryReport,
      { "callRecoveryReport", "ansi_map.callRecoveryReport_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tAnswer,
      { "tAnswer", "ansi_map.tAnswer_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tDisconnect,
      { "tDisconnect", "ansi_map.tDisconnect_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_unreliableCallData,
      { "unreliableCallData", "ansi_map.unreliableCallData_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_oCalledPartyBusy,
      { "oCalledPartyBusy", "ansi_map.oCalledPartyBusy_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_oNoAnswer,
      { "oNoAnswer", "ansi_map.oNoAnswer_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_positionRequest,
      { "positionRequest", "ansi_map.positionRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_positionRequestForward,
      { "positionRequestForward", "ansi_map.positionRequestForward_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_callTerminationReport,
      { "callTerminationReport", "ansi_map.callTerminationReport_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_geoPositionRequest,
      { "geoPositionRequest", "ansi_map.geoPositionRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interSystemPositionRequest,
      { "interSystemPositionRequest", "ansi_map.interSystemPositionRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interSystemPositionRequestForward,
      { "interSystemPositionRequestForward", "ansi_map.interSystemPositionRequestForward_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_aCGDirective,
      { "aCGDirective", "ansi_map.aCGDirective_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_roamerDatabaseVerificationRequest,
      { "roamerDatabaseVerificationRequest", "ansi_map.roamerDatabaseVerificationRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_addService,
      { "addService", "ansi_map.addService_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_dropService,
      { "dropService", "ansi_map.dropService_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_lcsParameterRequest,
      { "lcsParameterRequest", "ansi_map.lcsParameterRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_checkMEID,
      { "checkMEID", "ansi_map.checkMEID_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_positionEventNotification,
      { "positionEventNotification", "ansi_map.positionEventNotification_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_statusRequest,
      { "statusRequest", "ansi_map.statusRequest_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interSystemSMSDeliveryPointToPoint,
      { "interSystemSMSDeliveryPointToPoint", "ansi_map.interSystemSMSDeliveryPointToPoint_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_qualificationRequest2,
      { "qualificationRequest2", "ansi_map.qualificationRequest2_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_handoffMeasurementRequestRes,
      { "handoffMeasurementRequestRes", "ansi_map.handoffMeasurementRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_facilitiesDirectiveRes,
      { "facilitiesDirectiveRes", "ansi_map.facilitiesDirectiveRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_handoffBackRes,
      { "handoffBackRes", "ansi_map.handoffBackRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_facilitiesReleaseRes,
      { "facilitiesReleaseRes", "ansi_map.facilitiesReleaseRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_qualificationDirectiveRes,
      { "qualificationDirectiveRes", "ansi_map.qualificationDirectiveRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_qualificationRequestRes,
      { "qualificationRequestRes", "ansi_map.qualificationRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_resetCircuitRes,
      { "resetCircuitRes", "ansi_map.resetCircuitRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_registrationNotificationRes,
      { "registrationNotificationRes", "ansi_map.registrationNotificationRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_registrationCancellationRes,
      { "registrationCancellationRes", "ansi_map.registrationCancellationRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_locationRequestRes,
      { "locationRequestRes", "ansi_map.locationRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_routingRequestRes,
      { "routingRequestRes", "ansi_map.routingRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_featureRequestRes,
      { "featureRequestRes", "ansi_map.featureRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_transferToNumberRequestRes,
      { "transferToNumberRequestRes", "ansi_map.transferToNumberRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_handoffToThirdRes,
      { "handoffToThirdRes", "ansi_map.handoffToThirdRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationDirectiveRes,
      { "authenticationDirectiveRes", "ansi_map.authenticationDirectiveRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationRequestRes,
      { "authenticationRequestRes", "ansi_map.authenticationRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_baseStationChallengeRes,
      { "baseStationChallengeRes", "ansi_map.baseStationChallengeRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationFailureReportRes,
      { "authenticationFailureReportRes", "ansi_map.authenticationFailureReportRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_countRequestRes,
      { "countRequestRes", "ansi_map.countRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interSystemPageRes,
      { "interSystemPageRes", "ansi_map.interSystemPageRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_unsolicitedResponseRes,
      { "unsolicitedResponseRes", "ansi_map.unsolicitedResponseRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_handoffMeasurementRequest2Res,
      { "handoffMeasurementRequest2Res", "ansi_map.handoffMeasurementRequest2Res_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_facilitiesDirective2Res,
      { "facilitiesDirective2Res", "ansi_map.facilitiesDirective2Res_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_handoffBack2Res,
      { "handoffBack2Res", "ansi_map.handoffBack2Res_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_handoffToThird2Res,
      { "handoffToThird2Res", "ansi_map.handoffToThird2Res_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationDirectiveForwardRes,
      { "authenticationDirectiveForwardRes", "ansi_map.authenticationDirectiveForwardRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_authenticationStatusReportRes,
      { "authenticationStatusReportRes", "ansi_map.authenticationStatusReportRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_informationDirectiveRes,
      { "informationDirectiveRes", "ansi_map.informationDirectiveRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_informationForwardRes,
      { "informationForwardRes", "ansi_map.informationForwardRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interSystemPage2Res,
      { "interSystemPage2Res", "ansi_map.interSystemPage2Res_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interSystemSetupRes,
      { "interSystemSetupRes", "ansi_map.interSystemSetupRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_originationRequestRes,
      { "originationRequestRes", "ansi_map.originationRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_randomVariableRequestRes,
      { "randomVariableRequestRes", "ansi_map.randomVariableRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_remoteUserInteractionDirectiveRes,
      { "remoteUserInteractionDirectiveRes", "ansi_map.remoteUserInteractionDirectiveRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sMSDeliveryBackwardRes,
      { "sMSDeliveryBackwardRes", "ansi_map.sMSDeliveryBackwardRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sMSDeliveryForwardRes,
      { "sMSDeliveryForwardRes", "ansi_map.sMSDeliveryForwardRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sMSDeliveryPointToPointRes,
      { "sMSDeliveryPointToPointRes", "ansi_map.sMSDeliveryPointToPointRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sMSNotificationRes,
      { "sMSNotificationRes", "ansi_map.sMSNotificationRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sMSRequestRes,
      { "sMSRequestRes", "ansi_map.sMSRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_oTASPRequestRes,
      { "oTASPRequestRes", "ansi_map.oTASPRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_changeFacilitiesRes,
      { "changeFacilitiesRes", "ansi_map.changeFacilitiesRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_changeServiceRes,
      { "changeServiceRes", "ansi_map.changeServiceRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_parameterRequestRes,
      { "parameterRequestRes", "ansi_map.parameterRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tMSIDirectiveRes,
      { "tMSIDirectiveRes", "ansi_map.tMSIDirectiveRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_numberPortabilityRequestRes,
      { "numberPortabilityRequestRes", "ansi_map.numberPortabilityRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_serviceRequestRes,
      { "serviceRequestRes", "ansi_map.serviceRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_analyzedInformationRes,
      { "analyzedInformationRes", "ansi_map.analyzedInformationRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_facilitySelectedAndAvailableRes,
      { "facilitySelectedAndAvailableRes", "ansi_map.facilitySelectedAndAvailableRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_modifyRes,
      { "modifyRes", "ansi_map.modifyRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_searchRes,
      { "searchRes", "ansi_map.searchRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_seizeResourceRes,
      { "seizeResourceRes", "ansi_map.seizeResourceRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_sRFDirectiveRes,
      { "sRFDirectiveRes", "ansi_map.sRFDirectiveRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tBusyRes,
      { "tBusyRes", "ansi_map.tBusyRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tNoAnswerRes,
      { "tNoAnswerRes", "ansi_map.tNoAnswerRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_callControlDirectiveRes,
      { "callControlDirectiveRes", "ansi_map.callControlDirectiveRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_oDisconnectRes,
      { "oDisconnectRes", "ansi_map.oDisconnectRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_tDisconnectRes,
      { "tDisconnectRes", "ansi_map.tDisconnectRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_oCalledPartyBusyRes,
      { "oCalledPartyBusyRes", "ansi_map.oCalledPartyBusyRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_oNoAnswerRes,
      { "oNoAnswerRes", "ansi_map.oNoAnswerRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_positionRequestRes,
      { "positionRequestRes", "ansi_map.positionRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_positionRequestForwardRes,
      { "positionRequestForwardRes", "ansi_map.positionRequestForwardRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interSystemPositionRequestRes,
      { "interSystemPositionRequestRes", "ansi_map.interSystemPositionRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interSystemPositionRequestForwardRes,
      { "interSystemPositionRequestForwardRes", "ansi_map.interSystemPositionRequestForwardRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_roamerDatabaseVerificationRequestRes,
      { "roamerDatabaseVerificationRequestRes", "ansi_map.roamerDatabaseVerificationRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_addServiceRes,
      { "addServiceRes", "ansi_map.addServiceRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_dropServiceRes,
      { "dropServiceRes", "ansi_map.dropServiceRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interSystemSMSPage,
      { "interSystemSMSPage", "ansi_map.interSystemSMSPage_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_lcsParameterRequestRes,
      { "lcsParameterRequestRes", "ansi_map.lcsParameterRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_checkMEIDRes,
      { "checkMEIDRes", "ansi_map.checkMEIDRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_statusRequestRes,
      { "statusRequestRes", "ansi_map.statusRequestRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_interSystemSMSDeliveryPointToPointRes,
      { "interSystemSMSDeliveryPointToPointRes", "ansi_map.interSystemSMSDeliveryPointToPointRes_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_ansi_map_qualificationRequest2Res,
      { "qualificationRequest2Res", "ansi_map.qualificationRequest2Res_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    };

    /* List of subtrees */
    static int *ett[] = {
        &ett_ansi_map,
        &ett_mintype,
        &ett_digitstype,
        &ett_billingid,
        &ett_sms_bearer_data,
        &ett_sms_teleserviceIdentifier,
        &ett_extendedmscid,
        &ett_extendedsystemmytypecode,
        &ett_handoffstate,
        &ett_mscid,
        &ett_cdmachanneldata,
        &ett_cdmastationclassmark,
        &ett_channeldata,
        &ett_confidentialitymodes,
        &ett_controlchanneldata,
        &ett_CDMA2000HandoffInvokeIOSData,
        &ett_CDMA2000HandoffResponseIOSData,
        &ett_originationtriggers,
        &ett_pacaindicator,
        &ett_callingpartyname,
        &ett_triggercapability,
        &ett_winoperationscapability,
        &ett_win_trigger_list,
        &ett_controlnetworkid,
        &ett_transactioncapability,
        &ett_cdmaserviceoption,
        &ett_sms_originationrestrictions,
        &ett_systemcapabilities,
    &ett_ansi_map_AuthenticationDirective_U,
    &ett_ansi_map_AuthenticationDirectiveRes_U,
    &ett_ansi_map_AuthenticationDirectiveForward_U,
    &ett_ansi_map_AuthenticationDirectiveForwardRes_U,
    &ett_ansi_map_AuthenticationFailureReport_U,
    &ett_ansi_map_AuthenticationFailureReportRes_U,
    &ett_ansi_map_AuthenticationRequest_U,
    &ett_ansi_map_AuthenticationRequestRes_U,
    &ett_ansi_map_AuthenticationStatusReport_U,
    &ett_ansi_map_AuthenticationStatusReportRes_U,
    &ett_ansi_map_BaseStationChallenge_U,
    &ett_ansi_map_BaseStationChallengeRes_U,
    &ett_ansi_map_Blocking_U,
    &ett_ansi_map_BulkDeregistration_U,
    &ett_ansi_map_CountRequest_U,
    &ett_ansi_map_CountRequestRes_U,
    &ett_ansi_map_FacilitiesDirective_U,
    &ett_ansi_map_FacilitiesDirectiveRes_U,
    &ett_ansi_map_FacilitiesDirective2_U,
    &ett_ansi_map_FacilitiesDirective2Res_U,
    &ett_ansi_map_FacilitiesRelease_U,
    &ett_ansi_map_FacilitiesReleaseRes_U,
    &ett_ansi_map_FeatureRequest_U,
    &ett_ansi_map_FeatureRequestRes_U,
    &ett_ansi_map_FlashRequest_U,
    &ett_ansi_map_HandoffBack_U,
    &ett_ansi_map_HandoffBackRes_U,
    &ett_ansi_map_HandoffBack2_U,
    &ett_ansi_map_HandoffBack2Res_U,
    &ett_ansi_map_HandoffMeasurementRequest_U,
    &ett_ansi_map_HandoffMeasurementRequestRes_U,
    &ett_ansi_map_HandoffMeasurementRequest2_U,
    &ett_ansi_map_HandoffMeasurementRequest2Res_U,
    &ett_ansi_map_HandoffToThird_U,
    &ett_ansi_map_HandoffToThirdRes_U,
    &ett_ansi_map_HandoffToThird2_U,
    &ett_ansi_map_HandoffToThird2Res_U,
    &ett_ansi_map_InformationDirective_U,
    &ett_ansi_map_InformationDirectiveRes_U,
    &ett_ansi_map_InformationForward_U,
    &ett_ansi_map_InformationForwardRes_U,
    &ett_ansi_map_InterSystemAnswer_U,
    &ett_ansi_map_InterSystemPage_U,
    &ett_ansi_map_InterSystemPageRes_U,
    &ett_ansi_map_InterSystemPage2_U,
    &ett_ansi_map_InterSystemPage2Res_U,
    &ett_ansi_map_InterSystemSetup_U,
    &ett_ansi_map_InterSystemSetupRes_U,
    &ett_ansi_map_LocationRequest_U,
    &ett_ansi_map_LocationRequestRes_U,
    &ett_ansi_map_MSInactive_U,
    &ett_ansi_map_OriginationRequest_U,
    &ett_ansi_map_OriginationRequestRes_U,
    &ett_ansi_map_QualificationDirective_U,
    &ett_ansi_map_QualificationDirectiveRes_U,
    &ett_ansi_map_QualificationRequest_U,
    &ett_ansi_map_QualificationRequestRes_U,
    &ett_ansi_map_RandomVariableRequest_U,
    &ett_ansi_map_RandomVariableRequestRes_U,
    &ett_ansi_map_RedirectionDirective_U,
    &ett_ansi_map_RedirectionRequest_U,
    &ett_ansi_map_RegistrationCancellation_U,
    &ett_ansi_map_RegistrationCancellationRes_U,
    &ett_ansi_map_RegistrationNotification_U,
    &ett_ansi_map_RegistrationNotificationRes_U,
    &ett_ansi_map_RemoteUserInteractionDirective_U,
    &ett_ansi_map_RemoteUserInteractionDirectiveRes_U,
    &ett_ansi_map_ResetCircuit_U,
    &ett_ansi_map_ResetCircuitRes_U,
    &ett_ansi_map_RoutingRequest_U,
    &ett_ansi_map_RoutingRequestRes_U,
    &ett_ansi_map_SMSDeliveryBackward_U,
    &ett_ansi_map_SMSDeliveryBackwardRes_U,
    &ett_ansi_map_SMSDeliveryForward_U,
    &ett_ansi_map_SMSDeliveryForwardRes_U,
    &ett_ansi_map_SMSDeliveryPointToPoint_U,
    &ett_ansi_map_SMSDeliveryPointToPointRes_U,
    &ett_ansi_map_SMSDeliveryPointToPointAck_U,
    &ett_ansi_map_SMSNotification_U,
    &ett_ansi_map_SMSNotificationRes_U,
    &ett_ansi_map_SMSRequest_U,
    &ett_ansi_map_SMSRequestRes_U,
    &ett_ansi_map_TransferToNumberRequest_U,
    &ett_ansi_map_TransferToNumberRequestRes_U,
    &ett_ansi_map_TrunkTest_U,
    &ett_ansi_map_TrunkTestDisconnect_U,
    &ett_ansi_map_Unblocking_U,
    &ett_ansi_map_UnreliableRoamerDataDirective_U,
    &ett_ansi_map_UnsolicitedResponse_U,
    &ett_ansi_map_UnsolicitedResponseRes_U,
    &ett_ansi_map_ParameterRequest_U,
    &ett_ansi_map_ParameterRequestRes_U,
    &ett_ansi_map_TMSIDirective_U,
    &ett_ansi_map_TMSIDirectiveRes_U,
    &ett_ansi_map_NumberPortabilityRequest_U,
    &ett_ansi_map_NumberPortabilityRequestRes_U,
    &ett_ansi_map_ServiceRequest_U,
    &ett_ansi_map_ServiceRequestRes_U,
    &ett_ansi_map_AnalyzedInformation_U,
    &ett_ansi_map_AnalyzedInformationRes_U,
    &ett_ansi_map_ConnectionFailureReport_U,
    &ett_ansi_map_ConnectResource_U,
    &ett_ansi_map_FacilitySelectedAndAvailable_U,
    &ett_ansi_map_FacilitySelectedAndAvailableRes_U,
    &ett_ansi_map_Modify_U,
    &ett_ansi_map_ModifyRes_U,
    &ett_ansi_map_Search_U,
    &ett_ansi_map_SearchRes_U,
    &ett_ansi_map_SeizeResource_U,
    &ett_ansi_map_SeizeResourceRes_U,
    &ett_ansi_map_SRFDirective_U,
    &ett_ansi_map_SRFDirectiveRes_U,
    &ett_ansi_map_TBusy_U,
    &ett_ansi_map_TBusyRes_U,
    &ett_ansi_map_TNoAnswer_U,
    &ett_ansi_map_TNoAnswerRes_U,
    &ett_ansi_map_ChangeFacilities_U,
    &ett_ansi_map_ChangeFacilitiesRes_U,
    &ett_ansi_map_ChangeService_U,
    &ett_ansi_map_ChangeServiceRes_U,
    &ett_ansi_map_MessageDirective_U,
    &ett_ansi_map_BulkDisconnection_U,
    &ett_ansi_map_CallControlDirective_U,
    &ett_ansi_map_CallControlDirectiveRes_U,
    &ett_ansi_map_OAnswer_U,
    &ett_ansi_map_ODisconnect_U,
    &ett_ansi_map_ODisconnectRes_U,
    &ett_ansi_map_CallRecoveryReport_U,
    &ett_ansi_map_TAnswer_U,
    &ett_ansi_map_TDisconnect_U,
    &ett_ansi_map_TDisconnectRes_U,
    &ett_ansi_map_UnreliableCallData_U,
    &ett_ansi_map_OCalledPartyBusy_U,
    &ett_ansi_map_OCalledPartyBusyRes_U,
    &ett_ansi_map_ONoAnswer_U,
    &ett_ansi_map_ONoAnswerRes_U,
    &ett_ansi_map_PositionRequest_U,
    &ett_ansi_map_PositionRequestRes_U,
    &ett_ansi_map_PositionRequestForward_U,
    &ett_ansi_map_PositionRequestForwardRes_U,
    &ett_ansi_map_CallTerminationReport_U,
    &ett_ansi_map_GeoPositionRequest_U,
    &ett_ansi_map_InterSystemPositionRequest_U,
    &ett_ansi_map_InterSystemPositionRequestRes_U,
    &ett_ansi_map_InterSystemPositionRequestForward_U,
    &ett_ansi_map_InterSystemPositionRequestForwardRes_U,
    &ett_ansi_map_ACGDirective_U,
    &ett_ansi_map_RoamerDatabaseVerificationRequest_U,
    &ett_ansi_map_RoamerDatabaseVerificationRequestRes_U,
    &ett_ansi_map_LCSParameterRequest_U,
    &ett_ansi_map_LCSParameterRequestRes_U,
    &ett_ansi_map_CheckMEID_U,
    &ett_ansi_map_CheckMEIDRes_U,
    &ett_ansi_map_AddService_U,
    &ett_ansi_map_AddServiceRes_U,
    &ett_ansi_map_DropService_U,
    &ett_ansi_map_DropServiceRes_U,
    &ett_ansi_map_PositionEventNotification_U,
    &ett_ansi_map_OTASPRequest_U,
    &ett_ansi_map_OTASPRequestRes_U,
    &ett_ansi_map_StatusRequest_U,
    &ett_ansi_map_StatusRequestRes_U,
    &ett_ansi_map_InterSystemSMSDeliveryPointToPoint_U,
    &ett_ansi_map_InterSystemSMSDeliveryPointToPointRes_U,
    &ett_ansi_map_InterSystemSMSPage_U,
    &ett_ansi_map_QualificationRequest2_U,
    &ett_ansi_map_QualificationRequest2Res_U,
    &ett_ansi_map_AnnouncementList,
    &ett_ansi_map_CDMACodeChannelInformation,
    &ett_ansi_map_CDMACodeChannelList,
    &ett_ansi_map_CDMATargetMAHOInformation,
    &ett_ansi_map_CDMATargetMAHOList,
    &ett_ansi_map_CDMATargetMeasurementInformation,
    &ett_ansi_map_CDMATargetMeasurementList,
    &ett_ansi_map_IntersystemTermination,
    &ett_ansi_map_LocalTermination,
    &ett_ansi_map_PSTNTermination,
    &ett_ansi_map_TargetMeasurementInformation,
    &ett_ansi_map_TargetMeasurementList,
    &ett_ansi_map_TerminationList,
    &ett_ansi_map_TerminationList_item,
    &ett_ansi_map_CDMABandClassInformation,
    &ett_ansi_map_CDMABandClassList,
    &ett_ansi_map_CDMAServiceOptionList,
    &ett_ansi_map_PSID_RSIDList,
    &ett_ansi_map_TargetCellIDList,
    &ett_ansi_map_CDMAConnectionReferenceInformation,
    &ett_ansi_map_CDMAConnectionReferenceList,
    &ett_ansi_map_CDMAConnectionReferenceList_item,
    &ett_ansi_map_AnalogRedirectRecord,
    &ett_ansi_map_CDMAChannelNumberList,
    &ett_ansi_map_CDMAChannelNumberList_item,
    &ett_ansi_map_CDMARedirectRecord,
    &ett_ansi_map_MSID,
    &ett_ansi_map_DataAccessElement,
    &ett_ansi_map_DataAccessElementList,
    &ett_ansi_map_DataAccessElementList_item,
    &ett_ansi_map_DataUpdateResult,
    &ett_ansi_map_DataUpdateResultList,
    &ett_ansi_map_DestinationAddress,
    &ett_ansi_map_ExecuteScript,
    &ett_ansi_map_ModificationRequest,
    &ett_ansi_map_ModificationRequestList,
    &ett_ansi_map_ModificationResult,
    &ett_ansi_map_ModificationResultList,
    &ett_ansi_map_ServiceDataAccessElement,
    &ett_ansi_map_ServiceDataAccessElementList,
    &ett_ansi_map_ServiceDataResult,
    &ett_ansi_map_ServiceDataResultList,
    &ett_ansi_map_TriggerAddressList,
    &ett_ansi_map_TriggerList,
    &ett_ansi_map_WINCapability,
    &ett_ansi_map_CallRecoveryID,
    &ett_ansi_map_CallRecoveryIDList,
    &ett_ansi_map_PositionInformation,
    &ett_ansi_map_GapInterval,
    &ett_ansi_map_CDMAPSMMList,
    &ett_ansi_map_CDMAPSMMList_item,
    &ett_ansi_map_MPCAddressList,
    &ett_ansi_map_MobileStationMSID,
    &ett_ansi_map_NewlyAssignedMSID,
    &ett_ansi_map_InvokeData,
    &ett_ansi_map_ReturnData,
    };

    static ei_register_info ei[] = {
        { &ei_ansi_map_nr_not_used, { "ansi_map.nr_not_used", PI_PROTOCOL, PI_WARN, "This Number plan should not have been used", EXPFILL }},
        { &ei_ansi_map_unknown_invokeData_blob, { "ansi_map.unknown_invokeData_blob", PI_PROTOCOL, PI_WARN, "Unknown invokeData blob", EXPFILL }},
        { &ei_ansi_map_no_data, { "ansi_map.no_data", PI_PROTOCOL, PI_NOTE, "Carries no data", EXPFILL }},
    };

    expert_module_t* expert_ansi_map;

    static const enum_val_t ansi_map_response_matching_type_values[] = {
        {"tid",                "Transaction ID only", ANSI_MAP_TID_ONLY},
        {"tid_source",         "Transaction ID and Source", ANSI_MAP_TID_AND_SOURCE},
        {"tid_source_dest",    "Transaction ID Source and Destination", ANSI_MAP_TID_SOURCE_AND_DEST},
        {NULL, NULL, -1}
    };

    /* TAP STAT INFO */
    static stat_tap_table_ui stat_table = {
        REGISTER_TELEPHONY_GROUP_ANSI,
        "Map Operation Statistics",
        "ansi_map",
        "ansi_map",
        ansi_map_stat_init,
        ansi_map_stat_packet,
        ansi_map_stat_reset,
        NULL,
        NULL,
        array_length(stat_fields), stat_fields,
        0, NULL,
        NULL,
        0
    };

    /* Register protocol */
    proto_ansi_map = proto_register_protocol(PNAME, PSNAME, PFNAME);
    /* Register fields and subtrees */
    proto_register_field_array(proto_ansi_map, hf, array_length(hf));
    proto_register_subtree_array(ett, array_length(ett));
    expert_ansi_map = expert_register_protocol(proto_ansi_map);
    expert_register_field_array(expert_ansi_map, ei, array_length(ei));

    ansi_map_handle = register_dissector("ansi_map", dissect_ansi_map, proto_ansi_map);

    is637_tele_id_dissector_table =
        register_dissector_table("ansi_map.tele_id", "IS-637 Teleservice ID", proto_ansi_map,
                                 FT_UINT8, BASE_DEC);

    is683_dissector_table =
        register_dissector_table("ansi_map.ota", "IS-683-A (OTA)", proto_ansi_map,
                                 FT_UINT8, BASE_DEC);

    is801_dissector_table =
        register_dissector_table("ansi_map.pld", "IS-801 (PLD)", proto_ansi_map,
                                 FT_UINT8, BASE_DEC);

    ansi_map_tap = register_tap("ansi_map");


    range_convert_str(wmem_epan_scope(), &global_ssn_range, "5-14", MAX_SSN);

    ansi_map_module = prefs_register_protocol(proto_ansi_map, proto_reg_handoff_ansi_map);


    prefs_register_range_preference(ansi_map_module, "map.ssn", "ANSI MAP SSNs",
                                    "ANSI MAP SSNs to decode as ANSI MAP",
                                    &global_ssn_range, MAX_SSN);

    prefs_register_enum_preference(ansi_map_module, "transaction.matchtype",
                                  "Type of matching invoke/response",
                                  "Type of matching invoke/response, risk of mismatch if loose matching chosen",
                                  &ansi_map_response_matching_type, ansi_map_response_matching_type_values, false);

    TransactionId_table = wmem_multimap_new_autoreset(wmem_epan_scope(), wmem_file_scope(), wmem_str_hash, g_str_equal);
    register_stat_tap_table_ui(&stat_table);
}

/*
 * Editor modelines  -  https://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 4
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=4 tabstop=8 expandtab:
 * :indentSize=4:tabSize=8:noTabs=true:
 */
