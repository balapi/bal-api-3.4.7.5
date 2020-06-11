/*
 *  <:Copyright 2016-2019 Broadcom. All rights reserved. 
 *    The term “Broadcom” refers to Broadcom Inc. and/or its subsidiaries
 *  :>
 */

#ifndef __BCM_DEV_LOG_H_
#define __BCM_DEV_LOG_H_

#include <bcmos_system.h>
#include <math.h>
#include "bcm_dev_log_task.h"

#ifdef ENABLE_LOG

/********************************************/
/*                                          */
/* Log macros                               */
/*                                          */
/********************************************/

#define MACRO_ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, N, ...) N
#define MACROS_ARGS_SEQUENCE 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
#define MACRO_NUM_ARGS_HELPER(...)    MACRO_ARG_N(__VA_ARGS__)
#define MACRO_NUM_ARGS(...)     MACRO_NUM_ARGS_HELPER(__VA_ARGS__, MACROS_ARGS_SEQUENCE)

/* IMPORTANT! DO NOT USE THESE MACROS, USE BCM_LOG ONLY ! */
/* These macros force number of arguments in compile time. A single macro for each number of arguments (including the format) */
#ifdef __BASENAME__
#define _BCM_LOG_ARGS1(level, id, flags, ...) \
    bcm_dev_log_log(id, level, flags, STRINGIFY_EXPAND(__BASENAME__) " " STRINGIFY_EXPAND(__LINE__) "| " __VA_ARGS__)
#else
#define _BCM_LOG_ARGS1(level, id, flags, ...) \
    bcm_dev_log_log(id, level, flags | BCM_LOG_FLAG_FILENAME_IN_FMT, __FILE__ " " STRINGIFY_EXPAND(__LINE__) "| " __VA_ARGS__)
#endif
#define _BCM_LOG_ARGS2(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS3(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS4(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS5(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS6(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS7(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS8(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS9(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS10(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS11(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS12(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS13(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS14(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS15(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS16(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS17(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS18(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS19(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS20(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS21(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS22(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS23(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS24(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS25(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS26(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS27(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS28(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS29(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS30(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS31(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS32(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS33(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS34(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS35(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS36(...) _BCM_LOG_ARGS1(__VA_ARGS__)
#define _BCM_LOG_ARGS(n) _BCM_LOG_ARGS##n
#define _BCM_LOG_EXPAND(n, ...) _BCM_LOG_ARGS(n) (__VA_ARGS__)

/*
 * IMPORTANT! you should use only this macro for logging
 *
 * 1. Support prints up to DEV_LOG_MAX_ARGS parameters each with maximum size of 32bits
 * 2. Support also prints of arguments with size 64bits but each one counted as two arguments of 32bits,
 *    so you can only print up to (DEV_LOG_MAX_ARGS/2) arguments of 64bits.
 *    Mix of 64 and 32 are allowed as long you don't exceed DEV_LOG_MAX_ARGS.
 * 3. Any possible combination of mix 32 and 64 arguments are allowed.
 */
#define BCM_LOG(level, id, ...) _BCM_LOG_EXPAND(MACRO_NUM_ARGS(__VA_ARGS__), DEV_LOG_LEVEL_##level, id, 0, __VA_ARGS__)
/* Same as BCM_LOG(), but overrides BCM_LOG() default behavior by letting the format be done in the context of the caller task. This allows using stack/heap strings
 * for fmt and args. See comment for BCM_LOG_FLAG_CALLER_FMT. */
#define BCM_LOG_CALLER_FMT(level, id, ...) _BCM_LOG_EXPAND(MACRO_NUM_ARGS(__VA_ARGS__), DEV_LOG_LEVEL_##level, id, BCM_LOG_FLAG_CALLER_FMT, __VA_ARGS__)

/* Same as BCM_LOG(), but the level is not given as a token for concatenation, but as a regular enum. */
#define BCM_LOG_LEVEL(level, id, ...) _BCM_LOG_EXPAND(MACRO_NUM_ARGS(__VA_ARGS__), level, id, 0, __VA_ARGS__)

#define BCM_LOG_FLAG_NONE 0
#define BCM_LOG_FLAG_NO_HEADER (1 << 0) /* Avoid inserting header to each message. */
#define BCM_LOG_FLAG_CALLER_FMT (1 << 1) /* The log message will be formatted in the context of the caller task, not the logger task (override default behavior).
                                          * This has a penalty - bcm_dev_log_log() becomes slower. */
#define BCM_LOG_FLAG_FILENAME_IN_FMT (1 << 2) /* Indicates that __FILE__ is inserted at the beginning of the message format. */
#define BCM_LOG_FLAG_DONT_SKIP_PRINT (1 << 3) /* The message should always be printed even if the msg pool is nearly full. */

/********************************************/
/*                                          */
/* Callbacks functions                      */
/*                                          */
/********************************************/

/********************************************/
/*                                          */
/* Functions prototypes                     */
/*                                          */
/********************************************/

const char *dev_log_basename(const char *str);

/****************************************************************************************/
/*                                                                                      */
/* Name: bcm_dev_log_log                                                                */
/* Abstract: Log function                                                               */
/*           It is better using the macros and not the function directly.               */
/*                                                                                      */
/* Arguments:                                                                           */
/*   - id            - The Log ID this message is connected to.                         */
/*                        (The ID we got form bcm_dev_log_id_register)                  */
/*   - log_level     - The Log level of this message                                    */
/*   - flags         - Can be one of BCM_LOG_FLAG_XXX above.                            */
/*   - fmt              - The print format                                              */
/*     Note:              The default behavior is to format the string in the logger    */
/*                        task context, not the caller task context, to reduce the      */
/*                        penalty of calling bcm_dev_log_log(). This means 'fmt' can    */
/*                        point only to strings in data segment, but not to head/stack. */
/*                        You can override this behavior with BCM_LOG_FLAG_CALLER_FMT.  */
/*                                                                                      */
/*   - param1           - Format parameter No. 1. Like 'fmt', can reside only in data   */
/*                        segment, unless choosing BCM_LOG_FLAG_CALLER_FMT              */
/*   - ...                                                                              */
/*   - paramN           - Format parameter No. N                                        */
/*                                                                                      */
/* IMPORTANT!                                                                           */
/* 1. bcm_dev_log_log() must have even number of arguments before the '...'.            */
/*    This comes from the 64bits limitation that must be align to 8bytes in some        */
/*    platforms who doesn't support unaligned access,                                   */
/*    on xponsw (x86) it doesn't matter but on device (arm) you must have that.         */
/*                                                                                      */
/****************************************************************************************/
void bcm_dev_log_log(dev_log_id id,
    bcm_dev_log_level log_level,
    uint32_t flags,
    const char *fmt,
    ...) __attribute__((format(__printf__, 4, 5))); /* compiler attribute to check as printf style for arguments 4 (fmt) and 5 (all other) */

void bcm_dev_log_vlog(dev_log_id id,
    bcm_dev_log_level log_level,
    uint32_t flags,
    const char *fmt,
    va_list args);

typedef enum
{
    DEV_LOG_RATE_LIMIT_ID_NONE,
    DEV_LOG_RATE_LIMIT_ID_BWS_DBA_BD_ADD_ALLOC_FAILED,
    DEV_LOG_RATE_LIMIT_ID_BWS_DBA_BD_ADD_GUARANTEED_ALLOC_FAILED,
    DEV_LOG_RATE_LIMIT_ID_BWS_CBR_RT_ADD_ALLOC_FAILED,
    DEV_LOG_RATE_LIMIT_ID_BWS_CBR_RT_ADD_ACCESS_FAILED,
    DEV_LOG_RATE_LIMIT_ID_BWS_QW_CBR_RT_ADD_ACCESS_FAILED,
    DEV_LOG_RATE_LIMIT_ID_BWS_CBR_NRT_ADD_ALLOC_FAILED,
    DEV_LOG_RATE_LIMIT_ID_BWS_CBR_COMPENSATION_ADD_ACCESS_FAILED,
    DEV_LOG_RATE_LIMIT_ID_BWS_CBR_NO_COMPENSATION_ADD_ACCESS_FAILED,
    DEV_LOG_RATE_LIMIT_ID_BWS_CBR_COPY_COMPENSATION_ADD_ACCESS_FAILED,
    DEV_LOG_RATE_LIMIT_ID_BWS_CBR_RT_SAVE_ACCESS_FOR_COMPENSATION_FAILED,
    DEV_LOG_RATE_LIMIT_ID_BWS_CBR_NRT_SAVE_ACCESS_FOR_COMPENSATION_FAILED,
    DEV_LOG_RATE_LIMIT_ID_BWS_CBR_FLUSH_FAILED,
    DEV_LOG_RATE_LIMIT_ID_BWS_DBA_BA_INCORRECT_SHARING,
    DEV_LOG_RATE_LIMIT_ID_BWS_DBA_BA_INSUFFICIENT_REMAINING_BW,
    DEV_LOG_RATE_LIMIT_ID__NUM_OF,
} dev_log_rate_limit_id;

void bcm_dev_log_log_ratelimit(dev_log_id id,
    bcm_dev_log_level log_level,
    uint32_t flags,
    uint32_t rate_us,
    dev_log_rate_limit_id rate_limit_id,
    const char *fmt,
    ...) __attribute__((format(__printf__, 6, 7))); /* compiler attribute to check as printf style for arguments 6 (fmt) and 7 (all other) */

/********************************************************************************************/
/*                                                                                          */
/* Name: bcm_dev_log_os_trace_init                                                          */
/*                                                                                          */
/* Abstract: Direct bcmos_trace() output to log                                             */
/* Arguments: NONE                                                                          */
/*                                                                                          */
/* Return Value:                                                                            */
/*   bcmos_errno - Success code (BCM_ERR_OK) or Error code (see bcmos_errno.h)              */
/*                                                                                          */
/********************************************************************************************/
bcmos_errno bcm_dev_log_os_trace_init(void);

#define DEV_LOG_CHRDEV_MAX_KERNEL_IDS   32

/* ID descriptor */
typedef struct dev_log_id_info
{
    uint32_t index;
    char name[MAX_DEV_LOG_ID_NAME + 1];
    bcm_dev_log_level default_level;
    bcm_dev_log_id_type default_type;
} dev_log_id_info;

/* ioctl parameters */
typedef union dev_log_io_param
{
    struct
    {
        int num_ids;
        dev_log_id_info ids[DEV_LOG_CHRDEV_MAX_KERNEL_IDS];
    } db_read;

    struct
    {
        uint32_t index;
        bcm_dev_log_level level_print;
        bcm_dev_log_level level_save;
    } level_set;

    struct
    {
        uint32_t index;
        bcm_dev_log_id_type type;
    } type_set;

    struct
    {
        uint32_t offset;
        char msg[MAX_DEV_LOG_STRING_SIZE + 1];
    } msg_read;

} dev_log_io_param;

#else /* #ifndef ENABLE_LOG */

#define BCM_LOG(level, id, ...) \
    do \
    { \
    } \
    while (0)
#define BCM_LOG_CALLER_FMT(level, id, ...) \
    do \
    { \
    } \
    while (0)

#endif /* ENABLE_LOG */

typedef struct
{
    ulong_t int_val;
    ulong_t fraction;
} double2two_int_t;

/* convert double type to integer part and fractional part for printing */
/* Input - double value,
 *         digits - number of digits after the decimal point
 * Output:  double2two_int_t */
static inline void dev_log_double2two_int_conv(double double_val, uint8_t digits, double2two_int_t *result)
{
    result->int_val = double_val;
    result->fraction = (double_val - (double)result->int_val)*pow(10, digits);
}

#endif /* __BCM_DEV_LOG_H_ */
