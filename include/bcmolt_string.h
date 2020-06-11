/*
 *  <:Copyright 2016-2019 Broadcom. All rights reserved. 
 *    The term “Broadcom” refers to Broadcom Inc. and/or its subsidiaries
 *  :>
 */

#ifndef _BCMOLT_STRING_H_
#define _BCMOLT_STRING_H_

#include "bcmos_system.h"

typedef struct
{
    char *str;
    uint32_t max_len;
    char *curr;
    int32_t remaining;
} bcmolt_string;

int bcmolt_string_copy(bcmolt_string *str, const char *buf, uint32_t size);

int bcmolt_string_append(bcmolt_string *str, const char *fmt, ...);

const char *bcmolt_string_get(bcmolt_string *str);

void bcmolt_string_reset(bcmolt_string *str);

void bcmolt_string_rewind(bcmolt_string *str, int len);

void bcmolt_string_init(bcmolt_string *str, char *buf, uint32_t max_len);

/** strncpy flavour that always add 0 terminator
 * \param[in]       dst             Destination string
 * \param[in]       src             Source string
 * \param[in]       dst_size        Destination buffer size
 * \return dst
 */
static inline char *bcmolt_strncpy(char *dst, const char *src, uint32_t dst_size)
{
    strncpy(dst, src, dst_size - 1);
    dst[dst_size - 1] = 0;
    return dst;
}

/** strncat flavour that limits size of destination buffer
 * \param[in]       dst             Destination string
 * \param[in]       src             Source string
 * \param[in]       dst_size        Destination buffer size
 * \return dst
 */
static inline char *bcmolt_strncat(char *dst, const char *src, uint32_t dst_size)
{
    uint32_t dst_len = strlen(dst);
    return strncat(dst, src, dst_size - dst_len - 1);
}

/** Construct a string for indentation, given a specific indentation level
 * \param[in]       dst             Destination string
 * \param[in]       dst_size        Destination buffer size
 * \param[in]       indent_level    Indentation level 
 * \return dst
 */
char *bcmolt_string_indent(char *dst, uint32_t dst_size, uint32_t indent_level);

#endif /* _BCMOLT_STRING_H_ */
