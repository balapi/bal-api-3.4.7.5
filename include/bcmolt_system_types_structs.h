/*
 *  <:Copyright 2016-2019 Broadcom. All rights reserved. 
 *    The term “Broadcom” refers to Broadcom Inc. and/or its subsidiaries
 *  :>
*/

#ifndef BCMOLT_SYSTEM_TYPES_STRUCTS_H_
#define BCMOLT_SYSTEM_TYPES_STRUCTS_H_

#include <bcmos_system.h>
#include <bcmolt_presence_mask.h>
#include "bcmolt_system_types_enums.h"
#include "bcmolt_system_types_typedefs.h"

/** \addtogroup object_model
 * @{
 */

/** IEEE Demo ONU LLID Support */
typedef struct
{
    bcmolt_presence_mask presence_mask;
    bcmolt_ieee_demo_onu_llid_rate plid; /**< PLID. */
    bcmolt_ieee_demo_onu_llid_rate mlid; /**< MLID. */
    bcmolt_ieee_demo_onu_llid_rate bcast_plid; /**< BCAST_PLID. */
    bcmolt_ieee_demo_onu_llid_rate bcast_mlid; /**< BCAST_MLID. */
    bcmolt_ieee_demo_onu_llid_rate bcast_ulid; /**< BCAST_ULID. */
} bcmolt_ieee_demo_onu_llid_support;

/* Constants associated with bcmolt_ieee_demo_onu_llid_support. */
#define BCMOLT_IEEE_DEMO_ONU_LLID_SUPPORT_PRESENCE_MASK_ALL 0x000000000000001FULL



/** @} */

#endif
