/*
 *  <:Copyright 2016-2019 Broadcom. All rights reserved. 
 *    The term “Broadcom” refers to Broadcom Inc. and/or its subsidiaries
 *  :>
 */

#ifndef BCMOS_PACK_H_
#define BCMOS_PACK_H_


/*
 * Packing macros
 *
 * Usage:
 * struct __PACKED_ATTR_START__ my_packed_struct
 * {
 *      ...
 * } __PACKED_ATTR_END__ ;
 *
 */

#ifdef __GNUC__

#define __PACKED_ATTR_START__
#define __PACKED_ATTR_END__ __attribute__ ((packed))

#else

#error define __PACKED_ATTR_START__,  __PACKED_ATTR_END__ for this compiler

#endif

/*
 * Macros for bit-field manipulation
 * For each field F requires 2 constants
 * - F_S - field shift
 * - F_W - field width
 */
#define BCM_FIELD_GET(_w, _f)           (((_w)>>_f ## _S) & ((1 << _f ## _W) - 1))
#define BCM_FIELD(_f, _v)               ((_v & ((1 << _f ## _W) - 1)) << _f ## _S)
#define BCM_FIELD_SET(_w, _f, _v)       (_w) |= BCM_FIELD(_f, _v)


#endif /* BCMOS_PACK_H_ */
