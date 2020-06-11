/*
 *  <:Copyright 2016-2019 Broadcom. All rights reserved.
 *    The term “Broadcom” refers to Broadcom Inc. and/or its subsidiaries
 *  :>
 */

/** Management group - key, config, operation, etc */

#ifndef BCMOLT_MGT_GROUP_H_
#define BCMOLT_MGT_GROUP_H_

typedef enum bcmolt_mgt_group
{
    BCMOLT_MGT_GROUP__BEGIN,
    BCMOLT_MGT_GROUP_KEY = BCMOLT_MGT_GROUP__BEGIN, /**< key that uniquely identifies object instance */
    BCMOLT_MGT_GROUP_CFG,                           /**< Configuration */
    BCMOLT_MGT_GROUP_STAT,                          /**< Statistics */
    BCMOLT_MGT_GROUP_STAT_CFG,                      /**< Statistics threshold configuration */
    BCMOLT_MGT_GROUP_AUTO,                          /**< Autonomous indications */
    BCMOLT_MGT_GROUP_AUTO_CFG,                      /**< Autonomous indication configuration */
    BCMOLT_MGT_GROUP_OPER,                          /**< Operations */
    BCMOLT_MGT_GROUP__NUM_OF
} bcmolt_mgt_group;

/* Message group name */
const char *bcmolt_mgt_group_to_str(bcmolt_mgt_group group);

#endif
