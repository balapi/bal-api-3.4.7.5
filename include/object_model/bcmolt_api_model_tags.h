/*
 *  <:Copyright 2016-2019 Broadcom. All rights reserved. 
 *    The term “Broadcom” refers to Broadcom Inc. and/or its subsidiaries
 *  :>
*/

#ifndef BCMOLT_API_MODEL_TAGS_H_
#define BCMOLT_API_MODEL_TAGS_H_

#include <bcmos_system.h>

/** All object/field tags included in the API object model. */
typedef enum
{
    BCMOLT_TAG__NONE = 0,
    BCMOLT_TAG_DEVICE = 1ULL << 0,
    BCMOLT_TAG_GPON = 1ULL << 1,
    BCMOLT_TAG_NGPON2 = 1ULL << 2,
    BCMOLT_TAG_SYSTEM = 1ULL << 3,
    BCMOLT_TAG_XGPON = 1ULL << 4,
    BCMOLT_TAG_XGS = 1ULL << 5,
} bcmolt_tag;

/* The following config modes are enabled for this build (based on tags). */
#define BCMOLT_CONFIG_MODE_DEVICE 1
#define BCMOLT_CONFIG_MODE_GPON 1
#define BCMOLT_CONFIG_MODE_NGPON2 1
#define BCMOLT_CONFIG_MODE_SYSTEM 1
#define BCMOLT_CONFIG_MODE_XGPON 1
#define BCMOLT_CONFIG_MODE_XGS 1

/** Get all tags that are currently active for a given access_control based on system state. */
bcmolt_tag bcmolt_access_control_get_active_tags(const bcmolt_access_control_key *key);

/** Get all tags that are currently active for a given bal_system based on system state. */
bcmolt_tag bcmolt_bal_system_get_active_tags(const bcmolt_bal_system_key *key);

/** Get all tags that are currently active for a given device based on system state. */
bcmolt_tag bcmolt_device_get_active_tags(const bcmolt_device_key *key);

/** Get all tags that are currently active for a given erps_interface based on system state. */
bcmolt_tag bcmolt_erps_interface_get_active_tags(const bcmolt_erps_interface_key *key);

/** Get all tags that are currently active for a given eth_oam based on system state. */
bcmolt_tag bcmolt_eth_oam_get_active_tags(const bcmolt_eth_oam_key *key);

/** Get all tags that are currently active for a given flow based on system state. */
bcmolt_tag bcmolt_flow_get_active_tags(const bcmolt_flow_key *key);

/** Get all tags that are currently active for a given gpio based on system state. */
bcmolt_tag bcmolt_gpio_get_active_tags(const bcmolt_gpio_key *key);

/** Get all tags that are currently active for a given group based on system state. */
bcmolt_tag bcmolt_group_get_active_tags(const bcmolt_group_key *key);

/** Get all tags that are currently active for a given inband_mgmt_channel based on system state. */
bcmolt_tag bcmolt_inband_mgmt_channel_get_active_tags(const bcmolt_inband_mgmt_channel_key *key);

/** Get all tags that are currently active for a given internal_nni based on system state. */
bcmolt_tag bcmolt_internal_nni_get_active_tags(const bcmolt_internal_nni_key *key);

/** Get all tags that are currently active for a given itupon_alloc based on system state. */
bcmolt_tag bcmolt_itupon_alloc_get_active_tags(const bcmolt_itupon_alloc_key *key);

/** Get all tags that are currently active for a given itupon_gem based on system state. */
bcmolt_tag bcmolt_itupon_gem_get_active_tags(const bcmolt_itupon_gem_key *key);

/** Get all tags that are currently active for a given lag_interface based on system state. */
bcmolt_tag bcmolt_lag_interface_get_active_tags(const bcmolt_lag_interface_key *key);

/** Get all tags that are currently active for a given log based on system state. */
bcmolt_tag bcmolt_log_get_active_tags(const bcmolt_log_key *key);

/** Get all tags that are currently active for a given log_file based on system state. */
bcmolt_tag bcmolt_log_file_get_active_tags(const bcmolt_log_file_key *key);

/** Get all tags that are currently active for a given ngpon2_channel based on system state. */
bcmolt_tag bcmolt_ngpon2_channel_get_active_tags(const bcmolt_ngpon2_channel_key *key);

/** Get all tags that are currently active for a given nni_interface based on system state. */
bcmolt_tag bcmolt_nni_interface_get_active_tags(const bcmolt_nni_interface_key *key);

/** Get all tags that are currently active for a given olt based on system state. */
bcmolt_tag bcmolt_olt_get_active_tags(const bcmolt_olt_key *key);

/** Get all tags that are currently active for a given onu based on system state. */
bcmolt_tag bcmolt_onu_get_active_tags(const bcmolt_onu_key *key);

/** Get all tags that are currently active for a given pbit_to_tc based on system state. */
bcmolt_tag bcmolt_pbit_to_tc_get_active_tags(const bcmolt_pbit_to_tc_key *key);

/** Get all tags that are currently active for a given policer_profile based on system state. */
bcmolt_tag bcmolt_policer_profile_get_active_tags(const bcmolt_policer_profile_key *key);

/** Get all tags that are currently active for a given pon_interface based on system state. */
bcmolt_tag bcmolt_pon_interface_get_active_tags(const bcmolt_pon_interface_key *key);

/** Get all tags that are currently active for a given protection_interface based on system state. */
bcmolt_tag bcmolt_protection_interface_get_active_tags(const bcmolt_protection_interface_key *key);

/** Get all tags that are currently active for a given software_error based on system state. */
bcmolt_tag bcmolt_software_error_get_active_tags(const bcmolt_software_error_key *key);

/** Get all tags that are currently active for a given switch_inni based on system state. */
bcmolt_tag bcmolt_switch_inni_get_active_tags(const bcmolt_switch_inni_key *key);

/** Get all tags that are currently active for a given tc_to_queue based on system state. */
bcmolt_tag bcmolt_tc_to_queue_get_active_tags(const bcmolt_tc_to_queue_key *key);

/** Get all tags that are currently active for a given tm_qmp based on system state. */
bcmolt_tag bcmolt_tm_qmp_get_active_tags(const bcmolt_tm_qmp_key *key);

/** Get all tags that are currently active for a given tm_queue based on system state. */
bcmolt_tag bcmolt_tm_queue_get_active_tags(const bcmolt_tm_queue_key *key);

/** Get all tags that are currently active for a given tm_sched based on system state. */
bcmolt_tag bcmolt_tm_sched_get_active_tags(const bcmolt_tm_sched_key *key);



#endif
