/******************************************************************************
 *
 *  <:Copyright 2016-2019 Broadcom. All rights reserved. 
 *    The term “Broadcom” refers to Broadcom Inc. and/or its subsidiaries
 *  :>
 *
 *****************************************************************************/

/**
 * @file bcmos_system.h
 * @brief The file provides a FAKE stub for bcmos_system.h
 *
 */
#ifndef BCMOS_SYSTEM_H_
#define BCMOS_SYSTEM_H_

#include <pthread.h>
#include <semaphore.h>
#include <inttypes.h>
#include <bcmos_common.h>

#ifdef __cplusplus
typedef bool bcmos_bool;
#define BCMOS_FALSE false
#define BCMOS_TRUE true
#else
typedef _Bool bcmos_bool;
#define BCMOS_FALSE 0
#define BCMOS_TRUE 1
#endif

#include "bcmos_queue.h"

typedef uint16_t bcmos_msg_instance;

#include "bcmos_types.h"
#include "bcmos_endian.h"

#endif /* BCMOS_SYSTEM_H_ */
