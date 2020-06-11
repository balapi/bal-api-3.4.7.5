/*
 *  <:Copyright 2016-2019 Broadcom. All rights reserved. 
 *    The term “Broadcom” refers to Broadcom Inc. and/or its subsidiaries
 *  :>
 */

/*
 * Application side connection manager.
 * This module monitors application connection with Device Managhement Daemon(s)
 */

#ifndef BCMOLT_API_CONN_MGR_
#define BCMOLT_API_CONN_MGR_

#include <bcmos_system.h>
#include <bcmolt_msg.h>
#include <bcmtr_interface.h>
#include <bcmolt_api_topology.h>

/** Connection manager flags */
typedef enum
{
    BCMOLT_API_CONN_MGR_FLAGS_NONE          = 0,
    BCMOLT_API_CONN_MGR_FLAGS_DISABLE_KA    = 0x1,   /**< Disable keep alive (for debugging) */
} bcmolt_api_conn_mgr_flags;

bcmos_errno bcmolt_api_conn_mgr_start(bcmolt_goid olt, bcmolt_loid loid,
    const bcmtr_conn_parms *tr_conn_parms, bcmolt_api_conn_mgr_flags flags);

bcmos_bool bcmolt_api_conn_mgr_is_connected(bcmolt_goid olt);

void bcmolt_api_conn_mgr_stop(bcmolt_goid olt);

void bcmolt_api_conn_mgr_stop_all(void);

#endif /* BCMOLT_API_CONN_MGR_H_ */
