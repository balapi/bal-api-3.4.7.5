/*
<:copyright-BRCM:2019:DUAL/GPL:standard

   Broadcom Proprietary and Confidential.(c) 2016 Broadcom
   All Rights Reserved

Unless you and Broadcom execute a separate written software license
agreement governing use of this software, this software is licensed
to you under the terms of the GNU General Public License version 2
(the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
with the following added to such license:

   As a special exception, the copyright holders of this software give
   you permission to link this software with independent modules, and
   to copy and distribute the resulting executable under terms of your
   choice, provided that you also meet, for each linked independent
   module, the terms and conditions of the license of that module.
   An independent module is a module which is not derived from this
   software.  The special exception does not apply to any modifications
   of the software.

Not withstanding the above, under no circumstances may you combine
this software in any way with any other Broadcom software provided
under a license other than the GPL, without Broadcom's express prior
written consent.

:>
 */
#include <stdio.h>
#include <string.h>

#include <bcmolt_host_api.h>

/* Initialize API layer */
bcmos_errno bcmolt_api_init(void)
{
    printf("-- entering :stubbed %s\n", __FUNCTION__);
    return BCM_ERR_OK;
}

/* Set configuration */
bcmos_errno bcmolt_cfg_set(bcmolt_oltid olt, bcmolt_cfg *cfg)
{
    printf("-- entering :stubbed %s\n", __FUNCTION__);
    return BCM_ERR_OK;   
}

/* Get configuration */
bcmos_errno bcmolt_cfg_get(bcmolt_oltid olt, bcmolt_cfg *cfg)
{
    printf("-- entering :stubbed %s\n", __FUNCTION__);
    return BCM_ERR_OK;   
}

/* Clear configuration */
bcmos_errno bcmolt_cfg_clear(bcmolt_oltid olt, bcmolt_cfg *cfg)
{
    printf("-- entering :stubbed %s\n", __FUNCTION__);
    return BCM_ERR_OK;   
}

/* Get statistics */
bcmos_errno bcmolt_stat_get(bcmolt_oltid olt, bcmolt_stat *stat, bcmolt_stat_flags flags)
{
    printf("-- entering :stubbed %s\n", __FUNCTION__);
    return BCM_ERR_OK;   
}

/* Get statistics configuration */
bcmos_errno bcmolt_stat_cfg_get(bcmolt_oltid olt, bcmolt_stat_cfg *cfg)
{
    printf("-- entering :stubbed %s\n", __FUNCTION__);
    return BCM_ERR_OK;   
}

/* Set statistics configuration */
bcmos_errno bcmolt_stat_cfg_set(bcmolt_oltid olt, bcmolt_stat_cfg *cfg)
{
    printf("-- entering :stubbed %s\n", __FUNCTION__);
    return BCM_ERR_OK;   
}

/* Register Autonomous Indication Message Handler */
bcmos_errno bcmolt_ind_subscribe(bcmolt_oltid olt, bcmolt_rx_cfg *rx_cfg)
{
    printf("-- entering :stubbed %s\n", __FUNCTION__);
    return BCM_ERR_OK;
}

/* Un-register Autonomous Indication Message Handler registered by bcmolt_ind_subscribe() */
bcmos_errno bcmolt_ind_unsubscribe(bcmolt_oltid olt, bcmolt_rx_cfg *rx_cfg)
{
    printf("-- entering :stubbed %s\n", __FUNCTION__);
    return BCM_ERR_OK;
}

/* Submit Operation */
bcmos_errno bcmolt_oper_submit(bcmolt_oltid olt, bcmolt_oper *oper)
{
    printf("-- entering :stubbed %s\n", __FUNCTION__);
    return BCM_ERR_OK;
}

/* Get configuration of multiple objects */
bcmos_errno bcmolt_multi_cfg_get(
    bcmolt_oltid olt,
    bcmolt_multi_cfg *cfg,
    bcmolt_filter_flags filter_flags)
{
    printf("-- entering :stubbed %s\n", __FUNCTION__);
    return BCM_ERR_OK;
}

/* Get statistics of multiple objects */
bcmos_errno bcmolt_multi_stat_get(
    bcmolt_oltid olt,
    bcmolt_multi_stat *stat,
    bcmolt_stat_flags stat_flags,
    bcmolt_filter_flags filter_flags)
{
    printf("-- entering :stubbed %s\n", __FUNCTION__);
    return BCM_ERR_OK;
}

bcmos_errno bcmolt_host_init(const bcmolt_host_init_parms *init_parms)
{
    return BCM_ERR_OK;
}

