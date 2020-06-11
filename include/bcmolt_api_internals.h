/*
 *  <:Copyright 2016-2019 Broadcom. All rights reserved. 
 *    The term “Broadcom” refers to Broadcom Inc. and/or its subsidiaries
 *  :>
 */

#ifndef BCMOLT_API_INTERNALS_H_
#define BCMOLT_API_INTERNALS_H_

#include <bcm_dev_log.h>

/** Default log ID for API error reporting */
extern dev_log_id bcmolt_api_log_id;

#ifdef BCMOLT_API_INTERNAL

/* The following internal functions are available to SDK components,
   but not to SDK application
*/

/** Get indication configuration
 *
 * This function is internal
 *
 * \param[in]   olt     OLT ID
 * \param[out]  cfg     Indication configuration structure
 * \returns error code
 * The error code can indicate local or remote failure
 */
bcmos_errno bcmolt_auto_cfg_get(bcmolt_oltid olt, bcmolt_auto_cfg *cfg);

/** Set indication configuration
 *
 * This function is internal
 *
 * \param[in]   olt     OLT ID
 * \param[in]   cfg     Indication configuration structure
 * \returns error code
 * The error code can indicate local or remote failure
 */
bcmos_errno bcmolt_auto_cfg_set(bcmolt_oltid olt, bcmolt_auto_cfg *cfg);

#endif /* #ifdef BCMOLT_API_INTERNAL */

#endif /* #ifdef BCMOLT_API_INTERNALS_H */
