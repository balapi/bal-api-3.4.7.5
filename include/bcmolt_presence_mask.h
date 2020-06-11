/*
 *  <:Copyright 2016-2019 Broadcom. All rights reserved. 
 *    The term “Broadcom” refers to Broadcom Inc. and/or its subsidiaries
 *  :>
 */

/* bcmolt_presence_mask.h:
 * Definitions/utilities related to presence masks.
 */

#ifndef BCMOLT_PRESENCE_MASK_H_
#define BCMOLT_PRESENCE_MASK_H_

#include <bcmos_system.h>

/** Bitmask of fields that are present in a message/struct/array. */
typedef uint64_t bcmolt_presence_mask;

/** Presence mask indicating all fields present. For structures/arrays, 0 also means all fields present. */
#define BCMOLT_PRESENCE_MASK_ALL ((bcmolt_presence_mask)0xFFFFFFFFFFFFFFFF)

#endif
