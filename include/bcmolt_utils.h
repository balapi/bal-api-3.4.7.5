/*
<:copyright-BRCM:2016:DUAL/GPL:standard

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

#ifndef _BCMOLT_UTILS_H_
#define _BCMOLT_UTILS_H_

#include "bcmos_system.h"
#include "bcmolt_calc_crc32_table.h"

#define BCMOS_MACADDR_FMT_STR "%02X:%02X:%02X:%02X:%02X:%02X"
#define BCMOS_MACADDR_PARAMS(mac) (mac)->u8[0],(mac)->u8[1],(mac)->u8[2],(mac)->u8[3],(mac)->u8[4],(mac)->u8[5]

#define MAC_STR_LEN 18

#define BYTES_IN_MEGABYTE(bytes) ((bytes) / (1024 * 1024))

static inline char *bcmos_mac_2_str(const bcmos_mac_address *mac, char *buf)
{
    snprintf(buf, MAC_STR_LEN, BCMOS_MACADDR_FMT_STR, BCMOS_MACADDR_PARAMS(mac));
    return buf;
}

/** Swap a byte string of any length.
 *
 * \param[in]   ptr     pointer to a memory space.
 * \param[in]   len     length
 * \note
 *      {0, 1, 2, 3} becomes {3, 2, 1, 0}
 */
static inline void bcmos_swap_bytes_in_place(uint8_t *ptr, uint32_t len)
{
    uint32_t  ii;
    uint8_t tmp;

    for (ii = 0; ii < (len / 2); ii++)
    {
        tmp = ptr[len - ii - 1];
        ptr[len - ii - 1] = ptr[ii];
        ptr[ii] = tmp;
    }
}

/** Swap a byte string of any length.
 *
 * \param[out]      dst     pointer to a memory space for the swapped bytes.
 * \param[in]       src     pointer to a memory space for bytes to be swapped.
 * \param[in]       len     length in bytes
 * \note
 *      {0, 1, 2, 3} becomes {3, 2, 1, 0}
 */
static inline void bcmos_swap_bytes(uint8_t *dst, const uint8_t *src, const uint32_t len)
{
    uint32_t  ii;

    for (ii = 0; ii < len; ii++)
    {
        dst[ii] = src[len - ii - 1];
    }
}

/** Copy bits from a given range of the source to a different range of the
 *  destination
 *
 * \param[in]   dst         destination value to be merged to
 * \param[in]   dst_hi      high bit position
 * \param[in]   dst_lo      low bit position
 * \param[in]   src         source value to copy the bits from
 * \param[in]   src_hi      high bit position
 * \param[in]   src_lo      low bit position
 *
 * \return      destination value
 */
static inline uint32_t bcmos_bits_copy_u32(uint32_t dst, uint8_t dst_hi, uint8_t dst_lo,
    uint32_t src, uint8_t src_hi, uint8_t src_lo)
{
    dst &= (~(((1 << ((dst_hi - dst_lo) + 1)) - 1) << dst_lo));
    src &= (((1 << ((src_hi - src_lo) + 1)) - 1) << src_lo);
    dst |= ((dst_lo >= src_lo)? (src << (dst_lo - src_lo)): (src >> (src_lo - dst_lo)));
    return dst;
}

/* network to host on unaligned array of uint32_t elements. Treat pointer p as a pointer to an array of uint32_t elements. Get element i.  */
#define N2H32(p, i) ((((const uint8_t *)(p))[(i) * 4]<<24) | (((const uint8_t *)(p))[(i) * 4+1]<<16) | (((const uint8_t *)(p))[(i) * 4+2]<<8) | (((const uint8_t *)(p))[(i) * 4+3]))
/* network to host on unaligned array of uint16_t elements. Treat pointer p as a pointer to an array of uint16_t elements. Get element i. */
#define N2H16(p, i) ((((const uint8_t *)(p))[(i) * 2]<<8) | (((const uint8_t *)(p))[(i) * 2+1]))
/* network to host on unaligned array of uint8_t elements. Treat pointer p as a pointer to an array of uint8_t elements. Get element i. */
#define N2H8(p, i) (((const uint8_t *)(p))[(i)])

/* For internal use by the following H2N* macros */
#define H2N8(p, v)   *((uint8_t *)p) = (uint8_t)(v)
/* host to network conversion of a uint16_t with support for non 16 bit aligned destination address. p is a (uint8_t *) destination pointer. v is a uint16_t value. v can be written to p even if p is unaligned to 16 bits. */
#define H2N16(p, v)  (H2N8((p), (v) >> 8), H2N8(((uint8_t *)(p) + 1), (v)))
/* host to network conversion of a uint32_t with support for non 32 bit aligned destination address. p is a (uint8_t *) destination pointer. v is a uint32_t value. v can be written to p even if p is unaligned to 32 bits. */
#define H2N32(p, v)  (H2N16((p), (v) >> 16), H2N16(((uint8_t *)(p) + 2), (v)))

#define NUM_ELEM(array)     (sizeof(array) / sizeof((array)[0]))

void bcmos_hexdump(bcmos_msg_print_cb print_cb, void *context, const void *buffer, uint32_t offset, uint32_t count, const char *indent);
void bcmos_hexdump_one_line(const char *funcname,
    uint32_t lineno,
    bcmos_msg_print_cb print_cb,
    void *context,
    char *out_buf,
    uint32_t max_buf_size,
    const void *buffer, /* start of memory region to dump */
    uint32_t start_offset, /* start offset into the region */
    uint32_t byte_count, /* number of bytes in region to dump */
    const char *prefix, /* optional prefix string */
    const char *suffix); /* optional suffix string */

static inline uint32_t bcmolt_calc_crc32(uint32_t crc, const void *buf, size_t size)
{
    const uint32_t *p = (const uint32_t *)buf;
    const uint8_t *p1;

    crc = crc ^ ~0U;

    for ( ; size >= sizeof(uint32_t); size -= sizeof(uint32_t), ++p)
    {
        uint32_t w = *p;
        /* Convert to BE so that bytes are processed in the same order they appear in memory */
        w = BCMOS_ENDIAN_CPU_TO_BIG_U32(w);
        crc = bcmolt_calc_crc32_table[(crc ^ w>>24) & 0xFF] ^ (crc >> 8);
        crc = bcmolt_calc_crc32_table[(crc ^ w>>16) & 0xFF] ^ (crc >> 8);
        crc = bcmolt_calc_crc32_table[(crc ^ w>>8)  & 0xFF] ^ (crc >> 8);
        crc = bcmolt_calc_crc32_table[(crc ^ w)     & 0xFF] ^ (crc >> 8);
    }

    p1 = (const uint8_t *)p;
    while (size--)
        crc = bcmolt_calc_crc32_table[(crc ^ *p1++) & 0xFF] ^ (crc >> 8);

    return crc ^ ~0U;
}

#define BCMOLT_TIME_STR_MAX_LEN 80

/* Read data of given width from given buffer */
bcmos_errno bcmolt_read_snum(uint8_t byte_width, const void *data, int64_t *n);

#endif /* BCMOLT_UTILS_H */
