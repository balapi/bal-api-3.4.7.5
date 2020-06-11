/*
 *  <:Copyright 2016-2019 Broadcom. All rights reserved. 
 *    The term “Broadcom” refers to Broadcom Inc. and/or its subsidiaries
 *  :>
 */

/* system_types_common.h: commonly used platform agnostic data types */

#ifndef SYSTEM_TYPES_COMMON_H_
#define SYSTEM_TYPES_COMMON_H_

#include <bcmos_system.h>

/** Indication message type mask - high bits indicate message types that will be forwarded to the host.
 *
 * Bit positions correspond to the xxx_auto_id enum from the object model (e.g. bcmolt_gpon_ni_auto_id).
 */
typedef uint64_t ind_msg_mask;

#endif
