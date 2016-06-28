/*
 * Copyright (C) 2008-2013 CAPS entreprise.  All Rights Reserved.
 * 
 * The source code contained or described herein and all documents  related
 * to the source code ("Material") are owned  by  CAPS  entreprise  or  its
 * suppliers or licensors.
 * 
 * Title to the Material remains with CAPS entreprise or its suppliers  and
 * licensors.  The Material contains trade secrets and proprietary and con-
 * fidential information of CAPS entreprise or its suppliers and licensors.
 * 
 * The Material is protected by the French intellectual property code,  in-
 * tellectual property laws and international treaties.  No part of the Ma-
 * terial may be used, copied, reproduced, modified,  published,  uploaded,
 * posted, transmitted, distributed or disclosed in any  way  without  CAPS
 * entreprise's prior express written permission.
 * 
 * No license under any patent, copyright, trade secret or other  intellec-
 * tual property right is granted to or conferred upon you by disclosure or
 * delivery of the Material, either expressly, by implication,  inducement,
 * estoppel or otherwise.
 * 
 * Any license under such intellectual property rights  must  be  expressed
 * and approved by CAPS entreprise in writing.
 */
/// \internal

#ifndef HMPPRT_OPENCL_INTRINSICS_H
#define HMPPRT_OPENCL_INTRINSICS_H

#ifdef __GPUCODE__

#ifdef CL_KHR_INT64_BASE_ATOMICS_SUPPORTED
#pragma OPENCL EXTENSION cl_khr_int64_base_atomics : enable
#endif

inline unsigned int atomic_write_u32(volatile __global unsigned int * v, const unsigned int x)
{
    unsigned int old = *v;
    unsigned int assumed;
    do
    {
        assumed = old;
        old = atomic_cmpxchg(v, assumed, x);
    }
    while (assumed != old);
        
    return old;
}

#ifdef CL_KHR_INT64_BASE_ATOMICS_SUPPORTED
inline ulong atomic_write_u64(volatile __global ulong * v, const ulong x)
{
    ulong old = *v;
    ulong assumed;
    do
    {
        assumed = old;
        old = atom_cmpxchg(v, assumed, x);
    }
    while (assumed != old);

    return old;
}
#endif

inline int atomic_write_s32(volatile __global int * v, const int x)
{
    int old = *v;
    int assumed;
    do
    {
        assumed = old;
        old = atomic_cmpxchg(v, assumed, x);
    }
    while (assumed != old);

    return old;
}

#ifdef CL_KHR_INT64_BASE_ATOMICS_SUPPORTED
inline long atomic_write_s64(volatile __global long * v, const long x)
{
    long old = *v;
    long assumed;
    do
    {
        assumed = old;
        old = atom_cmpxchg(v, assumed, x);
    }
    while (assumed != old);

    return old;
}
#endif

inline float atomic_write_float(volatile __global float * v, const float x)
{
    __global int * v_as_int = (__global int *) v;
    int old = *v_as_int;
    int assumed;

    do
    {
        assumed = old;
        old = atomic_cmpxchg(v_as_int, assumed, as_int(x));
    }
    while (assumed != old);

    return as_float(old);
}

#ifdef CL_KHR_INT64_BASE_ATOMICS_SUPPORTED
inline double atomic_write_double(volatile __global double * v, const double x)
{
    __global ulong * v_as_ulong = (__global ulong *) v;
    ulong old = *v_as_ulong;
    ulong assumed;

    do
    {
        assumed = old;
        old = atom_cmpxchg(v_as_ulong, assumed, as_ulong(x));
    }
    while (assumed != old);

    return as_double(old);
}
#endif

//#################################################################################################

inline int atomic_min_s32_v(volatile __global int * x, int expr)
{
    int old = *x;
    int assumed;
    int v;

    do
    {
        assumed = old;
        v = (assumed < expr ) ? assumed : expr;
        old = atomic_cmpxchg(x, assumed, v);
    }
    while (assumed != old);

    return v;    
}

inline unsigned int atomic_min_u32_v(volatile __global unsigned int * x, unsigned int expr)
{
    unsigned int old = *x;
    unsigned int assumed;
    unsigned int v;

    do
    {
        assumed = old;
        v = (assumed < expr ) ? assumed : expr;
        old = atomic_cmpxchg(x, assumed, v);
    }
    while (assumed != old);

    return v;    
}

#ifdef CL_KHR_INT64_BASE_ATOMICS_SUPPORTED
inline ulong atomic_min_u64_v(volatile __global ulong * x, ulong expr)
{
    ulong old = *x;
    ulong assumed;
    ulong v;

    do
    {
        assumed = old;
        v = (assumed < expr ) ? assumed : expr;
        old = atom_cmpxchg(x, assumed, expr);
    }
    while (assumed != old);

    return v;
}

inline long atomic_min_s64_v(volatile __global long * x, long expr)
{
    long old = *x;
    long assumed;
    long v;

    do
    {
        assumed = old;
        v = (assumed < expr ) ? assumed : expr;
        old = atom_cmpxchg(x, assumed, v);
    }
    while (assumed != old);

    return v;
}
#endif

inline float atomic_min_float_v(volatile __global float * x, float expr)
{
    __global int * x_as_int = (__global int *) x;
    int old = *x_as_int;
    int exprr = as_int(expr);
    int assumed;
    int v;

    do
    {
        assumed = old;
        v = (assumed < exprr ) ? assumed : exprr;
        old = atomic_cmpxchg(x_as_int, assumed, v);
    }
    while (assumed != old);

    return as_float(v);    
}

#ifdef CL_KHR_INT64_BASE_ATOMICS_SUPPORTED
inline double atomic_min_double_v(volatile __global double * x, double expr)
{
    __global ulong * x_as_ulong = (__global ulong *) x;
    ulong old = *x_as_ulong;
    ulong assumed;
    ulong exprr = as_long(expr);
    ulong v;

    do
    {
        assumed = old;
        v = (assumed < exprr ) ? assumed : exprr;
        old = atom_cmpxchg(x_as_ulong, assumed, v);
    }
    while (assumed != old);

    return as_double(v);    
}
#endif

//#################################################################################################

inline int atomic_max_s32_v(volatile __global int * x, int expr)
{
    int old = *x;
    int assumed;
    int v;

    do
    {
        assumed = old;
        v = (assumed > expr ) ? assumed : expr;
        old = atomic_cmpxchg(x, assumed, v);
    }
    while (assumed != old);

    return v;    
}

inline unsigned int atomic_max_u32_v(volatile __global unsigned int * x, unsigned int expr)
{
    unsigned int old = *x;
    unsigned int assumed;
    unsigned int v;

    do
    {
        assumed = old;
        v = (assumed > expr ) ? assumed : expr;
        old = atomic_cmpxchg(x, assumed, v);
    }
    while (assumed != old);

    return v;    
}

#ifdef CL_KHR_INT64_BASE_ATOMICS_SUPPORTED
inline ulong atomic_max_u64_v(volatile __global ulong * x, ulong expr)
{
    ulong old = *x;
    ulong exprr = expr;
    ulong assumed;
    ulong v;

    do
    {
        assumed = old;
        v = (assumed > exprr ) ? assumed : exprr;
        old = atom_cmpxchg(x, assumed, v);
    }
    while (assumed != old);

    return v;
}

inline long atomic_max_s64_v(volatile __global long * x, long expr)
{
    long old = (long) *x;
    long exprr = (long) expr;
    long assumed;
    long v;

    do
    {
        assumed = old;
        v = (assumed > exprr ) ? assumed : exprr;
        old = atom_cmpxchg(x, assumed, v);
    }
    while (assumed != old);

    return v;
}
#endif

inline float atomic_max_float_v(volatile __global float * x, float expr)
{
    __global int * x_as_int = (__global int *) x;
    int old = *x_as_int;
    int exprr = as_int(expr);
    int assumed;
    int v;

    do
    {
        assumed = old;
        v = (assumed > exprr ) ? assumed : exprr;
        old = atomic_cmpxchg(x_as_int, assumed, v);
    }
    while (assumed != old);

    return as_float(v);    
}

#ifdef CL_KHR_INT64_BASE_ATOMICS_SUPPORTED
inline double atomic_max_double_v(volatile __global double * x, double expr)
{
    __global ulong * x_as_ulong = (__global ulong *) x;
    ulong old = *x_as_ulong;
    ulong assumed;
    ulong exprr = as_long(expr);
    ulong v;

    do
    {
        assumed = old;
        v = (assumed > exprr ) ? assumed : exprr;
        old = atom_cmpxchg(x_as_ulong, assumed, v);
    }
    while (assumed != old);

    return as_double(v);    
}
#endif

//#################################################################################################

#define GEN_INTRINSIC_S32(opname, op)                                   \
    inline int atomic_ ## opname ## _s32_old(volatile __global int * x, int expr) \
    {                                                                   \
        int old = *x;                                                   \
        int assumed;                                                    \
        int v;                                                          \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = assumed op expr;                                        \
            old = atomic_cmpxchg(x, assumed, v);                        \
        }                                                               \
        while (assumed != old);                                         \
        return old;                                                     \
    }                                                                   \
                                                                        \
    inline int atomic_ ## opname ## _s32_v(volatile __global int * x, int expr) \
    {                                                                   \
        int old = *x;                                                   \
        int assumed;                                                    \
        int v;                                                          \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = assumed op expr;                                        \
            old = atomic_cmpxchg(x, assumed, v);                        \
        }                                                               \
        while (assumed != old);                                         \
        return v;                                                       \
    }                                                                   \
                                                                        \
    inline int atomic_ ## opname ## _s32_old_r(volatile __global int * x, int expr) \
    {                                                                   \
        int old = *x;                                                   \
        int assumed;                                                    \
        int v;                                                          \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = expr op assumed;                                        \
            old = atomic_cmpxchg(x, assumed, v);                        \
        }                                                               \
        while (assumed != old);                                         \
        return old;                                                     \
    }                                                                   \
                                                                        \
                                                                        \
    inline int atomic_ ## opname ## _s32_v_r(volatile __global int * x, int expr) \
    {                                                                   \
        int old = *x;                                                   \
        int assumed;                                                    \
        int v;                                                          \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = expr op assumed;                                        \
            old = atomic_cmpxchg(x, assumed, v);                        \
        }                                                               \
        while (assumed != old);                                         \
        return v;                                                       \
    }

GEN_INTRINSIC_S32(add, +)
GEN_INTRINSIC_S32(mul, *)
GEN_INTRINSIC_S32(sub, -)
GEN_INTRINSIC_S32(div, /)
GEN_INTRINSIC_S32(and, &)
GEN_INTRINSIC_S32(xor, ^)
GEN_INTRINSIC_S32(or, |)
GEN_INTRINSIC_S32(shl, <<)
GEN_INTRINSIC_S32(shr, >>)

#undef GEN_INTRINSIC_S32

//#################################################################################################

#ifdef CL_KHR_INT64_BASE_ATOMICS_SUPPORTED
#define GEN_INTRINSIC_S64(opname, op)                                   \
    inline long atomic_ ## opname ## _s64_old(volatile __global long * x, long expr) \
    {                                                                   \
        long old = *x;                                                  \
        long assumed;                                                   \
        long v;                                                         \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = assumed op expr;                                        \
            old = atom_cmpxchg(x, assumed, v);                          \
        }                                                               \
        while (assumed != old);                                         \
        return old;                                                     \
    }                                                                   \
                                                                        \
    inline long atomic_ ## opname ## _s64_v(volatile __global long * x, long expr) \
    {                                                                   \
        long old = *x;                                                  \
        long assumed;                                                   \
        long v;                                                         \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = assumed op (ulong) expr;                                \
            old = atom_cmpxchg(x, assumed, v);                          \
        }                                                               \
        while (assumed != old);                                         \
        return v;                                                       \
    }                                                                   \
                                                                        \
    inline long atomic_ ## opname ## _s64_old_r(volatile __global long * x, long expr) \
    {                                                                   \
        long old = *x;                                                  \
        long assumed;                                                   \
        long v;                                                         \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = expr op assumed;                                        \
            old = atom_cmpxchg(x, assumed, v);                          \
        }                                                               \
        while (assumed != old);                                         \
        return old;                                                     \
    }                                                                   \
                                                                        \
    inline long atomic_ ## opname ## _s64_v_r(volatile __global long * x, long expr) \
    {                                                                   \
        long old = *x;                                                  \
        long assumed;                                                   \
        long v;                                                         \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = expr op assumed;                                        \
            old = atom_cmpxchg(x, assumed, v);                          \
        }                                                               \
        while (assumed != old);                                         \
        return v;                                                       \
    }
     
GEN_INTRINSIC_S64(add, +)
GEN_INTRINSIC_S64(mul, *)
GEN_INTRINSIC_S64(sub, -)
GEN_INTRINSIC_S64(div, /)
GEN_INTRINSIC_S64(and, &)
GEN_INTRINSIC_S64(xor, ^)
GEN_INTRINSIC_S64(or, |)
GEN_INTRINSIC_S64(shl, <<)
GEN_INTRINSIC_S64(shr, >>)

#undef GEN_INTRINSIC_S64
#endif

//#################################################################################################

#define GEN_INTRINSIC_U32(opname, op)                                   \
    inline unsigned int atomic_ ## opname ## _u32_old(volatile __global unsigned int * x, unsigned int expr) \
    {                                                                   \
        unsigned int old = *x;                                          \
        unsigned int assumed;                                           \
        unsigned int v;                                                 \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = assumed op expr;                                        \
            old = atomic_cmpxchg(x, assumed, v);                        \
        }                                                               \
        while (assumed != old);                                         \
        return old;                                                     \
    }                                                                   \
                                                                        \
    inline unsigned int atomic_ ## opname ## _u32_v(volatile __global unsigned int * x, unsigned int expr) \
    {                                                                   \
        unsigned int old = *x;                                          \
        unsigned int assumed;                                           \
        unsigned int v;                                                 \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = assumed op expr;                                        \
            old = atomic_cmpxchg(x, assumed, v);                        \
        }                                                               \
        while (assumed != old);                                         \
        return v;                                                       \
    }                                                                   \
                                                                        \
    inline unsigned int atomic_ ## opname ## _u32_old_r(volatile __global unsigned int * x, unsigned int expr) \
    {                                                                   \
        unsigned int old = *x;                                          \
        unsigned int assumed;                                           \
        unsigned int v;                                                 \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = expr op assumed;                                        \
            old = atomic_cmpxchg(x, assumed, v);                        \
        }                                                               \
        while (assumed != old);                                         \
        return old;                                                     \
    }                                                                   \
                                                                        \
                                                                        \
    inline unsigned int atomic_ ## opname ## _u32_v_r(volatile __global unsigned int * x, unsigned int expr) \
    {                                                                   \
        unsigned int old = *x;                                          \
        unsigned int assumed;                                           \
        unsigned int v;                                                 \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = expr op assumed;                                        \
            old = atomic_cmpxchg(x, assumed, v);                        \
        }                                                               \
        while (assumed != old);                                         \
        return v;                                                       \
    }
    
GEN_INTRINSIC_U32(add, +)
GEN_INTRINSIC_U32(mul, *)
GEN_INTRINSIC_U32(sub, -)
GEN_INTRINSIC_U32(div, /)
GEN_INTRINSIC_U32(and, &)
GEN_INTRINSIC_U32(xor, ^)
GEN_INTRINSIC_U32(or, |)
GEN_INTRINSIC_U32(shl, <<)
GEN_INTRINSIC_U32(shr, >>)

#undef GEN_INTRINSIC_U32

//#################################################################################################

#ifdef CL_KHR_INT64_BASE_ATOMICS_SUPPORTED
#define GEN_INTRINSIC_U64(opname, op)                                   \
    inline ulong atomic_ ## opname ## _u64_old(volatile __global ulong * x, ulong expr) \
    {                                                                   \
        ulong old = *x;                                                 \
        ulong assumed;                                                  \
        ulong v;                                                        \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = assumed op expr;                                        \
            old = atom_cmpxchg(x, assumed, v);                          \
        }                                                               \
        while (assumed != old);                                         \
        return old;                                                     \
    }                                                                   \
                                                                        \
    inline ulong atomic_ ## opname ## _u64_v(volatile __global ulong * x, ulong expr) \
    {                                                                   \
        ulong old = *x;                                                 \
        ulong assumed;                                                  \
        ulong v;                                                        \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = assumed op expr;                                        \
            old = atom_cmpxchg(x, assumed, v);                          \
        }                                                               \
        while (assumed != old);                                         \
        return v;                                                       \
    }                                                                   \
                                                                        \
    inline ulong atomic_ ## opname ## _u64_old_r(volatile __global ulong * x, ulong expr) \
    {                                                                   \
        ulong old = *x;                                                 \
        ulong assumed;                                                  \
        ulong v;                                                        \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = expr op assumed;                                        \
            old = atom_cmpxchg(x, assumed, v);                          \
        }                                                               \
        while (assumed != old);                                         \
        return old;                                                     \
    }                                                                   \
                                                                        \
    inline ulong atomic_ ## opname ## _u64_v_r(volatile __global ulong * x, ulong expr) \
    {                                                                   \
        ulong old = *x;                                                 \
        ulong assumed;                                                  \
        ulong v;                                                        \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = expr op assumed;                                        \
            old = atom_cmpxchg(x, assumed, v);                          \
        }                                                               \
        while (assumed != old);                                         \
        return v;                                                       \
    }
     
GEN_INTRINSIC_U64(add, +)
GEN_INTRINSIC_U64(mul, *)
GEN_INTRINSIC_U64(sub, -)
GEN_INTRINSIC_U64(div, /)
GEN_INTRINSIC_U64(and, &)
GEN_INTRINSIC_U64(xor, ^)
GEN_INTRINSIC_U64(or, |)
GEN_INTRINSIC_U64(shl, <<)
GEN_INTRINSIC_U64(shr, >>)

#undef GEN_INTRINSIC_U64
#endif

//#################################################################################################

#define GEN_INTRINSIC_FLOAT(opname, op)                                 \
    inline float atomic_ ## opname ## _float_old(volatile __global float * x, float expr) \
    {                                                                   \
        __global int * x_as_int = (__global int *) x;                   \
        int old = *x_as_int;                                            \
        int assumed;                                                    \
        int v;                                                          \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = as_int(as_float(assumed) op expr);                      \
            old = atomic_cmpxchg(x_as_int, assumed, v);                 \
        }                                                               \
        while (assumed != old);                                         \
        return  as_float(old);                                          \
    }                                                                   \
                                                                        \
    inline float atomic_ ## opname ## _float_v(volatile __global float * x, float expr) \
    {                                                                   \
        __global int * x_as_int = (__global int *) x;                   \
        int old = *x_as_int;                                            \
        int assumed;                                                    \
        int v;                                                          \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = as_int(as_float(assumed) op expr);                      \
            old = atomic_cmpxchg(x_as_int, assumed, v);                 \
        }                                                               \
        while (assumed != old);                                         \
        return  as_float(v);                                            \
    }                                                                   \
                                                                        \
    inline float atomic_ ## opname ## _float_old_r(volatile __global float * x, float expr) \
    {                                                                   \
        __global int * x_as_int = (__global int *) x;                   \
        int old = *x_as_int;                                            \
        int assumed;                                                    \
        int v;                                                          \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = as_int(expr op as_float(assumed));                      \
            old = atomic_cmpxchg(x_as_int, assumed, v);                 \
        }                                                               \
        while (assumed != old);                                         \
        return  as_float(old);                                          \
    }                                                                   \
                                                                        \
    inline float atomic_ ## opname ## _float_v_r(volatile __global float * x, float expr) \
    {                                                                   \
        __global int * x_as_int = (__global int *) x;                   \
        int old = *x_as_int;                                            \
        int assumed;                                                    \
        int v;                                                          \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = as_int(expr op as_float(assumed));                      \
            old = atomic_cmpxchg(x_as_int, assumed, v);                 \
        }                                                               \
        while (assumed != old);                                         \
        return  as_float(v);                                            \
    }

GEN_INTRINSIC_FLOAT(add, +)
GEN_INTRINSIC_FLOAT(mul, *)
GEN_INTRINSIC_FLOAT(sub, -)
GEN_INTRINSIC_FLOAT(div, /)

#undef GEN_INTRINSIC_FLOAT

//#################################################################################################

#ifdef CL_KHR_INT64_BASE_ATOMICS_SUPPORTED
#define GEN_INTRINSIC_DOUBLE(opname, op)                                \
    inline double atomic_ ## opname ## _double_old(volatile __global double * x, double expr) \
    {                                                                   \
        __global ulong * x_as_ulong = (__global ulong *) x;             \
        ulong old = *x_as_ulong;                                        \
        ulong assumed;                                                  \
        ulong v;                                                        \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = as_long( as_double(assumed) op expr);                   \
            old = atom_cmpxchg(x_as_ulong, assumed, v);                 \
        }                                                               \
        while (assumed != old);                                         \
        return as_double(old);                                          \
    }                                                                   \
                                                                        \
    inline double atomic_ ## opname ## _double_v(volatile __global double * x, double expr) \
    {                                                                   \
        __global ulong * x_as_ulong = (__global ulong *) x;             \
        ulong old = *x_as_ulong;                                        \
        ulong assumed;                                                  \
        ulong v;                                                        \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = as_long( as_double(assumed) op expr);                   \
            old = atom_cmpxchg(x_as_ulong, assumed, v);                 \
        }                                                               \
        while (assumed != old);                                         \
        return as_double(v);                                            \
    }                                                                   \
                                                                        \
    inline double atomic_ ## opname ## _double_old_r(volatile __global double * x, double expr) \
    {                                                                   \
        __global ulong * x_as_ulong = (__global ulong *) x;             \
        ulong old = *x_as_ulong;                                        \
        ulong assumed;                                                  \
        ulong v;                                                        \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = as_long(expr op as_double(assumed));                    \
            old = atom_cmpxchg(x_as_ulong, assumed, v);                 \
        }                                                               \
        while (assumed != old);                                         \
        return as_double(old);                                          \
    }                                                                   \
                                                                        \
    inline double atomic_ ## opname ## _double_v_r(volatile __global double * x, double expr) \
    {                                                                   \
        __global ulong * x_as_ulong = (__global ulong *) x;             \
        ulong old = *x_as_ulong;                                        \
        ulong assumed;                                                  \
        ulong v;                                                        \
                                                                        \
        do                                                              \
        {                                                               \
            assumed = old;                                              \
            v = as_long(expr op as_double(assumed));                    \
            old = atom_cmpxchg(x_as_ulong, assumed, v);                 \
        }                                                               \
        while (assumed != old);                                         \
        return as_double(v);                                            \
    } 
     
GEN_INTRINSIC_DOUBLE(add, +)
GEN_INTRINSIC_DOUBLE(mul, *)
GEN_INTRINSIC_DOUBLE(sub, -)
GEN_INTRINSIC_DOUBLE(div, /)

#undef GEN_INTRINSIC_DOUBLE
#endif

#endif // __GPUCODE__

#endif // HMPPRT_OPENCL_INTRINSICS_H


#ifndef __GPUCODE__
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <hmpprt/Grouplet.h>
#include <hmpprt/HostTypes.h>
#include <hmpprt/Context.h>
#include <hmpprt/OpenCLTypes.h>
#include <hmpprt/OpenCLGrid.h>
#include <hmpprt/OpenCLModule.h>
#include <hmpprt/DeviceManager.h>
#include <hmpperr/hmpperr.h>

#include <openacci/openacci_c.h>

#include <CL/cl.h>

#ifdef _WIN32
#  define CDLT_API __declspec(dllexport)
#else /* ! _WIN32 */
#  define CDLT_API
#endif /* _WIN32 */

#else

#if defined(CL_KHR_FP64_SUPPORTED) && (defined(CL_VERSION_1_0) || defined(CL_VERSION_1_1))
#pragma OPENCL EXTENSION cl_khr_fp64: enable
#endif

#ifdef GLOBAL_ATOMIC_EXTS_SUPPORTED
#pragma OPENCL EXTENSION cl_khr_global_int32_base_atomics: enable
#pragma OPENCL EXTENSION cl_khr_global_int32_extended_atomics: enable
#endif

#ifdef LOCAL_ATOMIC_EXTS_SUPPORTED
#pragma OPENCL EXTENSION cl_khr_local_int32_base_atomics: enable
#pragma OPENCL EXTENSION cl_khr_local_int32_extended_atomics: enable
#endif

#ifdef BYTE_ADDRESSABLE_STORE_EXTS_SUPPORTED
#pragma OPENCL EXTENSION cl_khr_byte_addressable_store: enable
#endif

#endif /* __GPUCODE__ */



#ifndef __GPUCODE__

#else


#endif
#define HMPPCG_SIMD_LENGTH 32

# 75 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_79(cl_int height_8, cl_int width_11, cl_int* pSrc_padding_3, cl_char* pBufL_cp_4)
;
#endif /* __GPUCODE__ */



# 75 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_79_internal_1(cl_int height_19, cl_int width_20, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int>  pSrc_padding_5, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  pBufL_cp_8)
;
#endif /* __GPUCODE__ */



# 12 "laplacian.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_79_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_79_parallel_region_1(int height_1, __global uchar* pBufL_cp_1, __global int* pSrc_padding_1, int width_1);
#endif // __GPUCODE__
# 12 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_55(cl_int height_9, cl_int width_12, cl_char* Source_3, cl_int* pSrc_padding_2)
;
#endif /* __GPUCODE__ */



# 12 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_55_internal_1(cl_int height_20, cl_int width_21, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  Source_5, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int>  pSrc_padding_4)
;
#endif /* __GPUCODE__ */



# 243 "laplacian.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_55_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_55_parallel_region_1(__global uchar* Source_1, int height_2, __global int* pSrc_padding, int width_2);
#endif // __GPUCODE__
# 243 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_247(cl_int height_10, cl_int width_13, cl_char* Source_2, cl_short* LaplacianLayer_1, cl_char* UpsampleDst_5)
;
#endif /* __GPUCODE__ */



# 243 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_247_internal_1(cl_int height_15, cl_int width_22, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  Source_4, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  LaplacianLayer_2, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  UpsampleDst_9)
;
#endif /* __GPUCODE__ */



# 229 "laplacian.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_247_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_247_parallel_region_1(__global short* LaplacianLayer, __global uchar* Source, __global uchar* UpsampleDst_1, int height_3, int width_3);
#endif // __GPUCODE__
# 229 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_230(cl_int width_4, cl_int halfWidth_5, cl_char* DownsampleDst_5, cl_char* UpsampleDst_6)
;
#endif /* __GPUCODE__ */



# 229 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_230_internal_1(cl_int width_27, cl_int halfWidth_9, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  DownsampleDst_9, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  UpsampleDst_10)
;
#endif /* __GPUCODE__ */



# 201 "laplacian.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_230_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_230_parallel_region_1(__global uchar* DownsampleDst_1, __global uchar* UpsampleDst_2, int halfWidth_1);
#endif // __GPUCODE__
# 201 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_202(cl_int width_14, cl_int halfWidth_10, cl_int halfHeight_8, cl_char* DownsampleDst_10, cl_char* UpsampleDst_11)
;
#endif /* __GPUCODE__ */



# 201 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_202_internal_1(cl_int width_23, cl_int halfWidth_6, cl_int halfHeight_4, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  DownsampleDst_6, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  UpsampleDst_7)
;
#endif /* __GPUCODE__ */



# 175 "laplacian.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_202_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_202_parallel_region_1(__global uchar* DownsampleDst_2, __global uchar* UpsampleDst_3, int halfHeight_1, int halfWidth_2, int width_5);
#endif // __GPUCODE__
# 175 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_188(cl_int height_11, cl_int width_15, cl_int halfWidth_7, cl_int halfHeight_2, cl_char* DownsampleDst_11, cl_char* UpsampleDst_4)
;
#endif /* __GPUCODE__ */



# 175 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_188_internal_1(cl_int height_16, cl_int width_24, cl_int halfWidth_11, cl_int halfHeight_6, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  DownsampleDst_7, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  UpsampleDst_8)
;
#endif /* __GPUCODE__ */



# 154 "laplacian.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_188_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_188_parallel_region_1(__global uchar* DownsampleDst_3, __global uchar* UpsampleDst, int halfHeight_5, int halfWidth_3, int height_4, int width_6);
#endif // __GPUCODE__
# 154 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_159(cl_int width_16, cl_int halfWidth_4, cl_int halfHeight_3, cl_char* FilterDst_3, cl_char* DownsampleDst_4)
;
#endif /* __GPUCODE__ */



# 154 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_159_internal_1(cl_int width_25, cl_int halfWidth_8, cl_int halfHeight_7, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  FilterDst_5, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  DownsampleDst_8)
;
#endif /* __GPUCODE__ */



# 132 "laplacian.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_159_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_159_parallel_region_1(__global uchar* DownsampleDst, __global uchar* FilterDst_1, int halfHeight, int halfWidth, int width_7);
#endif // __GPUCODE__
# 132 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_136(cl_int height_5, cl_int width_8, cl_char* FilterDst_2, cl_int* pSrc_padding2_6)
;
#endif /* __GPUCODE__ */



# 132 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_136_internal_1(cl_int height_18, cl_int width_28, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  FilterDst_4, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int>  pSrc_padding2_1)
;
#endif /* __GPUCODE__ */



# 114 "laplacian.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_136_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_136_parallel_region_1(__global uchar* FilterDst, int height_12, __global int* pSrc_padding2_4, int width_17);
#endif // __GPUCODE__
# 114 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_114(cl_int height_17, cl_int width_18, cl_int* pSrc_padding2_7, cl_char* pBufL_cp_2)
;
#endif /* __GPUCODE__ */



# 114 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_114_internal_1(cl_int height_13, cl_int width_26, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int>  pSrc_padding2_2, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  pBufL_cp_6)
;
#endif /* __GPUCODE__ */



# 97 "laplacian.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_114_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_114_parallel_region_1(int height_6, __global uchar* pBufL_cp_5, __global int* pSrc_padding2_5, int width_9);
#endif // __GPUCODE__
# 97 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_100(cl_int height_14, cl_int width_10, cl_int* pSrc_padding2_3, cl_char* pBufL_cp_7)
;
#endif /* __GPUCODE__ */



# 97 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_100_internal_1(cl_int height, cl_int width_19, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int>  pSrc_padding2_8, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  pBufL_cp_3)
;
#endif /* __GPUCODE__ */



# 97 "laplacian.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_100_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_100_parallel_region_1(int height_7, __global uchar* pBufL_cp, __global int* pSrc_padding2, int width);
#endif // __GPUCODE__
# 97 "laplacian.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_100_parallel_region_1(int height_7, __global uchar* pBufL_cp, __global int* pSrc_padding2, int width)
{
 # 99 "laplacian.cpp"
 {
  # 103 "laplacian.cpp"
  int iter_per_gang_10;
  # 103 "laplacian.cpp"
  int first_gang_iter_10;
  # 103 "laplacian.cpp"
  int last_gang_iter_10;
  # 103 "laplacian.cpp"
  iter_per_gang_10 = ((1 + (height_7 * width - 1) / 192) > 256 ? (1 + (height_7 * width - 1) / 192) : 256);
  # 103 "laplacian.cpp"
  first_gang_iter_10 = get_group_id(0) * iter_per_gang_10;
  # 103 "laplacian.cpp"
  last_gang_iter_10 = ((first_gang_iter_10 + iter_per_gang_10 - 1) < (height_7 * width - 1) ? (first_gang_iter_10 + iter_per_gang_10 - 1) : (height_7 * width - 1));
  # 103 "laplacian.cpp"
  int h_9;
  # 103 "laplacian.cpp"
  # 107 "laplacian.cpp"
  for (h_9 = first_gang_iter_10 + get_local_id(1) ; h_9 <= last_gang_iter_10 ; h_9 = h_9 + get_local_size(1))
  {
   # 103 "laplacian.cpp"
   int h_4;
   # 106 "laplacian.cpp"
   int w_5;
   # 107 "laplacian.cpp"
   w_5 = h_9 % width;
   # 107 "laplacian.cpp"
   h_4 = h_9 / width;
   # 107 "laplacian.cpp"
   *(pSrc_padding2 + ((h_4 + 2) * (width + 4) + w_5 + 2)) = (int ) (*(pBufL_cp + (h_4 * width + w_5)));
  }
  # 97 "laplacian.cpp"
 }
}
#endif /* __GPUCODE__ */



# 97 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_100_internal_1(cl_int height, cl_int width_19, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int>  pSrc_padding2_8, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  pBufL_cp_3)
{
 # 97 "laplacian.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height), "height_7");
  __hmppcg_call.addLocalParameter(&pBufL_cp_3, 8, "pBufL_cp");
  __hmppcg_call.addLocalParameter(&pSrc_padding2_8, 8, "pSrc_padding2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_19), "width");
  __hmppcg_call.launch(hmpp_acc_region_main_100_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 97 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_100(cl_int height_14, cl_int width_10, cl_int* pSrc_padding2_3, cl_char* pBufL_cp_7)
{
 # 114 "laplacian.cpp"
 (hmpp_acc_region_main_100_internal_1(height_14, width_10, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int> (pSrc_padding2_3), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (pBufL_cp_7)));
}
#endif /* __GPUCODE__ */



# 114 "laplacian.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_114_parallel_region_1(int height_6, __global uchar* pBufL_cp_5, __global int* pSrc_padding2_5, int width_9)
{
 # 116 "laplacian.cpp"
 {
  # 117 "laplacian.cpp"
  int iter_per_gang_9;
  # 117 "laplacian.cpp"
  int first_gang_iter_9;
  # 117 "laplacian.cpp"
  int last_gang_iter_9;
  # 117 "laplacian.cpp"
  iter_per_gang_9 = ((1 + (width_9 - 1) / 192) > 256 ? (1 + (width_9 - 1) / 192) : 256);
  # 117 "laplacian.cpp"
  first_gang_iter_9 = get_group_id(0) * iter_per_gang_9;
  # 117 "laplacian.cpp"
  last_gang_iter_9 = ((first_gang_iter_9 + iter_per_gang_9 - 1) < (width_9 - 1) ? (first_gang_iter_9 + iter_per_gang_9 - 1) : (width_9 - 1));
  # 117 "laplacian.cpp"
  int w_6;
  # 117 "laplacian.cpp"
  # 118 "laplacian.cpp"
  for (w_6 = first_gang_iter_9 + get_local_id(1) ; w_6 <= last_gang_iter_9 ; w_6 = w_6 + get_local_size(1))
  {
   # 119 "laplacian.cpp"
   *(pSrc_padding2_5 + (width_9 + 4 + (w_6 + 2))) = 2 * (int ) (*(pBufL_cp_5 + (width_9 + (w_6 + 2) - 2))) - (int ) (*(pBufL_cp_5 + (3 * width_9 + (w_6 + 2) - 2)));
   # 120 "laplacian.cpp"
   *(pSrc_padding2_5 + (w_6 + 2)) = 4 * (int ) (*(pBufL_cp_5 + (3 * width_9 + (w_6 + 2) - 2))) - 4 * (int ) (*(pBufL_cp_5 + (width_9 + (w_6 + 2) - 2))) + 2 * (int ) (*(pBufL_cp_5 + w_6)) - (int ) (*(pBufL_cp_5 + (2 * width_9 + (w_6 + 2) - 2)));
   # 123 "laplacian.cpp"
   *(pSrc_padding2_5 + ((height_6 + 2) * (width_9 + 4) + (w_6 + 2))) = 2 * (int ) (*(pBufL_cp_5 + ((height_6 - 2) * width_9 + (w_6 + 2) - 2))) - (int ) (*(pBufL_cp_5 + ((height_6 - 4) * width_9 + (w_6 + 2) - 2)));
   # 124 "laplacian.cpp"
   *(pSrc_padding2_5 + ((height_6 + 3) * (width_9 + 4) + (w_6 + 2))) = 4 * (int ) (*(pBufL_cp_5 + ((height_6 - 4) * width_9 + (w_6 + 2) - 2))) - 4 * (int ) (*(pBufL_cp_5 + ((height_6 - 2) * width_9 + (w_6 + 2) - 2))) + 2 * (int ) (*(pBufL_cp_5 + ((height_6 - 1) * width_9 + (w_6 + 2) - 2))) - (int ) (*(pBufL_cp_5 + ((height_6 - 3) * width_9 + (w_6 + 2) - 2)));
  }
  # 114 "laplacian.cpp"
 }
}
#endif /* __GPUCODE__ */



# 114 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_114_internal_1(cl_int height_13, cl_int width_26, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int>  pSrc_padding2_2, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  pBufL_cp_6)
{
 # 114 "laplacian.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_13), "height_6");
  __hmppcg_call.addLocalParameter(&pBufL_cp_6, 8, "pBufL_cp_5");
  __hmppcg_call.addLocalParameter(&pSrc_padding2_2, 8, "pSrc_padding2_5");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_26), "width_9");
  __hmppcg_call.launch(hmpp_acc_region_main_114_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 114 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_114(cl_int height_17, cl_int width_18, cl_int* pSrc_padding2_7, cl_char* pBufL_cp_2)
{
 # 132 "laplacian.cpp"
 (hmpp_acc_region_main_114_internal_1(height_17, width_18, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int> (pSrc_padding2_7), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (pBufL_cp_2)));
}
#endif /* __GPUCODE__ */



# 132 "laplacian.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_136_parallel_region_1(__global uchar* FilterDst, int height_12, __global int* pSrc_padding2_4, int width_17)
{
 # 134 "laplacian.cpp"
 {
  # 139 "laplacian.cpp"
  int iter_per_gang_8;
  # 139 "laplacian.cpp"
  int first_gang_iter_8;
  # 139 "laplacian.cpp"
  int last_gang_iter_8;
  # 139 "laplacian.cpp"
  iter_per_gang_8 = ((1 + (width_17 * height_12 - 1) / 192) > 256 ? (1 + (width_17 * height_12 - 1) / 192) : 256);
  # 139 "laplacian.cpp"
  first_gang_iter_8 = get_group_id(0) * iter_per_gang_8;
  # 139 "laplacian.cpp"
  last_gang_iter_8 = ((first_gang_iter_8 + iter_per_gang_8 - 1) < (width_17 * height_12 - 1) ? (first_gang_iter_8 + iter_per_gang_8 - 1) : (width_17 * height_12 - 1));
  # 139 "laplacian.cpp"
  int w_10;
  # 139 "laplacian.cpp"
  # 142 "laplacian.cpp"
  for (w_10 = first_gang_iter_8 + get_local_id(1) ; w_10 <= last_gang_iter_8 ; w_10 = w_10 + get_local_size(1))
  {
   # 139 "laplacian.cpp"
   int w_7;
   # 141 "laplacian.cpp"
   int h_5;
   # 143 "laplacian.cpp"
   h_5 = w_10 % height_12;
   # 143 "laplacian.cpp"
   w_7 = w_10 / height_12;
   # 143 "laplacian.cpp"
   *(FilterDst + (h_5 * width_17 + w_7)) = (uchar ) (*(pSrc_padding2_4 + (h_5 * (width_17 + 4) + (w_7 + 2))) + (*(pSrc_padding2_4 + ((h_5 + 1) * (width_17 + 4) + (w_7 + 2))) << 2) + 6 * *(pSrc_padding2_4 + ((h_5 + 2) * (width_17 + 4) + (w_7 + 2))) + (*(pSrc_padding2_4 + ((h_5 + 3) * (width_17 + 4) + (w_7 + 2))) << 2) + *(pSrc_padding2_4 + ((h_5 + 4) * (width_17 + 4) + (w_7 + 2))) + 8 >> 4);
  }
  # 132 "laplacian.cpp"
 }
}
#endif /* __GPUCODE__ */



# 132 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_136_internal_1(cl_int height_18, cl_int width_28, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  FilterDst_4, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int>  pSrc_padding2_1)
{
 # 132 "laplacian.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter(&FilterDst_4, 8, "FilterDst");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_18), "height_12");
  __hmppcg_call.addLocalParameter(&pSrc_padding2_1, 8, "pSrc_padding2_4");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_28), "width_17");
  __hmppcg_call.launch(hmpp_acc_region_main_136_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 132 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_136(cl_int height_5, cl_int width_8, cl_char* FilterDst_2, cl_int* pSrc_padding2_6)
{
 # 154 "laplacian.cpp"
 (hmpp_acc_region_main_136_internal_1(height_5, width_8, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (FilterDst_2), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int> (pSrc_padding2_6)));
}
#endif /* __GPUCODE__ */



# 154 "laplacian.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_159_parallel_region_1(__global uchar* DownsampleDst, __global uchar* FilterDst_1, int halfHeight, int halfWidth, int width_7)
{
 # 156 "laplacian.cpp"
 {
  # 162 "laplacian.cpp"
  int iter_per_gang_7;
  # 162 "laplacian.cpp"
  int first_gang_iter_7;
  # 162 "laplacian.cpp"
  int last_gang_iter_7;
  # 162 "laplacian.cpp"
  iter_per_gang_7 = ((1 + (halfHeight * halfWidth - 1) / 192) > 256 ? (1 + (halfHeight * halfWidth - 1) / 192) : 256);
  # 162 "laplacian.cpp"
  first_gang_iter_7 = get_group_id(0) * iter_per_gang_7;
  # 162 "laplacian.cpp"
  last_gang_iter_7 = ((first_gang_iter_7 + iter_per_gang_7 - 1) < (halfHeight * halfWidth - 1) ? (first_gang_iter_7 + iter_per_gang_7 - 1) : (halfHeight * halfWidth - 1));
  # 162 "laplacian.cpp"
  int y_7;
  # 162 "laplacian.cpp"
  # 166 "laplacian.cpp"
  for (y_7 = first_gang_iter_7 + get_local_id(1) ; y_7 <= last_gang_iter_7 ; y_7 = y_7 + get_local_size(1))
  {
   # 162 "laplacian.cpp"
   int y_3;
   # 165 "laplacian.cpp"
   int x_5;
   # 167 "laplacian.cpp"
   x_5 = y_7 % halfWidth;
   # 167 "laplacian.cpp"
   y_3 = y_7 / halfWidth;
   # 167 "laplacian.cpp"
   *(DownsampleDst + (y_3 * halfWidth + x_5)) = *(FilterDst_1 + ((y_3 << 1) * width_7 + (x_5 << 1)));
  }
  # 154 "laplacian.cpp"
 }
}
#endif /* __GPUCODE__ */



# 154 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_159_internal_1(cl_int width_25, cl_int halfWidth_8, cl_int halfHeight_7, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  FilterDst_5, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  DownsampleDst_8)
{
 # 154 "laplacian.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter(&DownsampleDst_8, 8, "DownsampleDst");
  __hmppcg_call.addLocalParameter(&FilterDst_5, 8, "FilterDst_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfHeight_7), "halfHeight");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfWidth_8), "halfWidth");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_25), "width_7");
  __hmppcg_call.launch(hmpp_acc_region_main_159_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 154 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_159(cl_int width_16, cl_int halfWidth_4, cl_int halfHeight_3, cl_char* FilterDst_3, cl_char* DownsampleDst_4)
{
 # 175 "laplacian.cpp"
 (hmpp_acc_region_main_159_internal_1(width_16, halfWidth_4, halfHeight_3, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (FilterDst_3), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (DownsampleDst_4)));
}
#endif /* __GPUCODE__ */



# 175 "laplacian.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_188_parallel_region_1(__global uchar* DownsampleDst_3, __global uchar* UpsampleDst, int halfHeight_5, int halfWidth_3, int height_4, int width_6)
{
 # 177 "laplacian.cpp"
 {
  # 191 "laplacian.cpp"
  int iter_per_gang_6;
  # 191 "laplacian.cpp"
  int first_gang_iter_6;
  # 191 "laplacian.cpp"
  int last_gang_iter_6;
  # 191 "laplacian.cpp"
  iter_per_gang_6 = ((1 + (halfWidth_3 - 2) / 192) > 256 ? (1 + (halfWidth_3 - 2) / 192) : 256);
  # 191 "laplacian.cpp"
  first_gang_iter_6 = get_group_id(0) * iter_per_gang_6;
  # 191 "laplacian.cpp"
  last_gang_iter_6 = ((first_gang_iter_6 + iter_per_gang_6 - 1) < (halfWidth_3 - 2) ? (first_gang_iter_6 + iter_per_gang_6 - 1) : (halfWidth_3 - 2));
  # 191 "laplacian.cpp"
  int x_6;
  # 191 "laplacian.cpp"
  # 192 "laplacian.cpp"
  for (x_6 = first_gang_iter_6 + get_local_id(1) ; x_6 <= last_gang_iter_6 ; x_6 = x_6 + get_local_size(1))
  {
   # 193 "laplacian.cpp"
   *(UpsampleDst + ((height_4 - 1) * width_6 + 2 * (x_6 + 1) - 1)) = (uchar ) ((int ) (*(DownsampleDst_3 + ((halfHeight_5 - 1) * halfWidth_3 + (x_6 + 1) - 1))) + (int ) (*(DownsampleDst_3 + ((halfHeight_5 - 1) * halfWidth_3 + (x_6 + 1)))) + 1 >> 1);
   # 194 "laplacian.cpp"
   *(UpsampleDst + ((height_4 - 1) * width_6 + 2 * (x_6 + 1))) = *(DownsampleDst_3 + ((halfHeight_5 - 1) * halfWidth_3 + (x_6 + 1)));
  }
  # 175 "laplacian.cpp"
 }
}
#endif /* __GPUCODE__ */



# 175 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_188_internal_1(cl_int height_16, cl_int width_24, cl_int halfWidth_11, cl_int halfHeight_6, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  DownsampleDst_7, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  UpsampleDst_8)
{
 # 175 "laplacian.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter(&DownsampleDst_7, 8, "DownsampleDst_3");
  __hmppcg_call.addLocalParameter(&UpsampleDst_8, 8, "UpsampleDst");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfHeight_6), "halfHeight_5");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfWidth_11), "halfWidth_3");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_16), "height_4");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_24), "width_6");
  __hmppcg_call.launch(hmpp_acc_region_main_188_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 175 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_188(cl_int height_11, cl_int width_15, cl_int halfWidth_7, cl_int halfHeight_2, cl_char* DownsampleDst_11, cl_char* UpsampleDst_4)
{
 # 201 "laplacian.cpp"
 (hmpp_acc_region_main_188_internal_1(height_11, width_15, halfWidth_7, halfHeight_2, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (DownsampleDst_11), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (UpsampleDst_4)));
}
#endif /* __GPUCODE__ */



# 201 "laplacian.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_202_parallel_region_1(__global uchar* DownsampleDst_2, __global uchar* UpsampleDst_3, int halfHeight_1, int halfWidth_2, int width_5)
{
 # 203 "laplacian.cpp"
 {
  # 205 "laplacian.cpp"
  int iter_per_gang_5;
  # 205 "laplacian.cpp"
  int first_gang_iter_5;
  # 205 "laplacian.cpp"
  int last_gang_iter_5;
  # 205 "laplacian.cpp"
  iter_per_gang_5 = 1 +  -(1 - (halfHeight_1 - 1)) / 192;
  # 205 "laplacian.cpp"
  first_gang_iter_5 = get_group_id(0) * iter_per_gang_5;
  # 205 "laplacian.cpp"
  last_gang_iter_5 = ((first_gang_iter_5 + iter_per_gang_5 - 1) < ( -(1 - (halfHeight_1 - 1))) ? (first_gang_iter_5 + iter_per_gang_5 - 1) : ( -(1 - (halfHeight_1 - 1))));
  # 205 "laplacian.cpp"
  int y_4;
  # 205 "laplacian.cpp"
  # 206 "laplacian.cpp"
  for (y_4 = first_gang_iter_5 ; y_4 <= last_gang_iter_5 ; y_4 = y_4 + 1)
  {
   # 209 "laplacian.cpp"
   uchar tmp_18;
   # 209 "laplacian.cpp"
   uchar tmp_19;
   # 209 "laplacian.cpp"
   uchar tmp_20;
   # 209 "laplacian.cpp"
   uchar tmp_21;
   # 209 "laplacian.cpp"
   int end_6;
   # 209 "laplacian.cpp"
   int x_7;
   # 209 "laplacian.cpp"
   # 210 "laplacian.cpp"
   # 210 "laplacian.cpp"
   for (x_7 = get_local_id(1), end_6 = halfWidth_2 - 2 ; x_7 <= end_6 ; x_7 = x_7 + get_local_size(1))
   {
    # 211 "laplacian.cpp"
    *(UpsampleDst_3 + ((2 * (halfHeight_1 - 1 - y_4) - 1) * width_5 + 2 * (x_7 + 1) - 1)) = (uchar ) ((int ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + (x_7 + 1) - 1))) + (int ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + (x_7 + 1)))) + (int ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4 - 1) * halfWidth_2 + (x_7 + 1) - 1))) + (int ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4 - 1) * halfWidth_2 + (x_7 + 1)))) + 2 >> 2);
    # 212 "laplacian.cpp"
    *(UpsampleDst_3 + ((2 * (halfHeight_1 - 1 - y_4) - 1) * width_5 + 2 * (x_7 + 1))) = (uchar ) ((int ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + (x_7 + 1)))) + (int ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4 - 1) * halfWidth_2 + (x_7 + 1)))) + 1 >> 1);
    # 214 "laplacian.cpp"
    *(UpsampleDst_3 + (2 * (halfHeight_1 - 1 - y_4) * width_5 + 2 * (x_7 + 1) - 1)) = (uchar ) ((int ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + (x_7 + 1) - 1))) + (int ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + (x_7 + 1)))) + 1 >> 1);
    # 215 "laplacian.cpp"
    *(UpsampleDst_3 + (2 * (halfHeight_1 - 1 - y_4) * width_5 + 2 * (x_7 + 1))) = *(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + (x_7 + 1)));
   }
   # 201 "laplacian.cpp"
   # 201 "laplacian.cpp"
   tmp_18 = (uchar ) ((int ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + halfWidth_2 - 1))) + (int ) (*(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4 - 1) * halfWidth_2 + halfWidth_2 - 1))) + 1 >> 1);
   # 201 "laplacian.cpp"
   if (get_local_id(1) == 0)
   {
    # 201 "laplacian.cpp"
    *(UpsampleDst_3 + ((2 * (halfHeight_1 - 1 - y_4) - 1) * width_5 + width_5 - 1)) = tmp_18;
   }
   # 201 "laplacian.cpp"
   barrier(CLK_LOCAL_MEM_FENCE);
   # 201 "laplacian.cpp"
   tmp_19 = *(DownsampleDst_2 + ((halfHeight_1 - 1 - y_4) * halfWidth_2 + halfWidth_2 - 1));
   # 201 "laplacian.cpp"
   if (get_local_id(1) == 0)
   {
    # 201 "laplacian.cpp"
    *(UpsampleDst_3 + (2 * (halfHeight_1 - 1 - y_4) * width_5 + width_5 - 1)) = tmp_19;
   }
   # 201 "laplacian.cpp"
   barrier(CLK_LOCAL_MEM_FENCE);
   # 201 "laplacian.cpp"
   tmp_20 = (uchar ) ((int ) (*(DownsampleDst_2 + (halfHeight_1 - 1 - y_4) * halfWidth_2)) + (int ) (*(DownsampleDst_2 + (halfHeight_1 - 1 - y_4 - 1) * halfWidth_2)) + 1 >> 1);
   # 201 "laplacian.cpp"
   if (get_local_id(1) == 0)
   {
    # 201 "laplacian.cpp"
    *(UpsampleDst_3 + (2 * (halfHeight_1 - 1 - y_4) - 1) * width_5) = tmp_20;
   }
   # 201 "laplacian.cpp"
   barrier(CLK_LOCAL_MEM_FENCE);
   # 201 "laplacian.cpp"
   tmp_21 = *(DownsampleDst_2 + (halfHeight_1 - 1 - y_4) * halfWidth_2);
   # 201 "laplacian.cpp"
   if (get_local_id(1) == 0)
   {
    # 201 "laplacian.cpp"
    *(UpsampleDst_3 + 2 * (halfHeight_1 - 1 - y_4) * width_5) = tmp_21;
   }
   # 201 "laplacian.cpp"
   barrier(CLK_LOCAL_MEM_FENCE);
  }
  # 201 "laplacian.cpp"
 }
}
#endif /* __GPUCODE__ */



# 201 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_202_internal_1(cl_int width_23, cl_int halfWidth_6, cl_int halfHeight_4, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  DownsampleDst_6, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  UpsampleDst_7)
{
 # 201 "laplacian.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter(&DownsampleDst_6, 8, "DownsampleDst_2");
  __hmppcg_call.addLocalParameter(&UpsampleDst_7, 8, "UpsampleDst_3");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfHeight_4), "halfHeight_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfWidth_6), "halfWidth_2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_23), "width_5");
  __hmppcg_call.launch(hmpp_acc_region_main_202_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 201 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_202(cl_int width_14, cl_int halfWidth_10, cl_int halfHeight_8, cl_char* DownsampleDst_10, cl_char* UpsampleDst_11)
{
 # 229 "laplacian.cpp"
 (hmpp_acc_region_main_202_internal_1(width_14, halfWidth_10, halfHeight_8, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (DownsampleDst_10), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (UpsampleDst_11)));
}
#endif /* __GPUCODE__ */



# 229 "laplacian.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_230_parallel_region_1(__global uchar* DownsampleDst_1, __global uchar* UpsampleDst_2, int halfWidth_1)
{
 # 231 "laplacian.cpp"
 {
  # 233 "laplacian.cpp"
  int iter_per_gang_4;
  # 233 "laplacian.cpp"
  int first_gang_iter_4;
  # 233 "laplacian.cpp"
  int last_gang_iter_4;
  # 233 "laplacian.cpp"
  iter_per_gang_4 = ((1 +  -(1 - (halfWidth_1 - 1)) / 192) > 256 ? (1 +  -(1 - (halfWidth_1 - 1)) / 192) : 256);
  # 233 "laplacian.cpp"
  first_gang_iter_4 = get_group_id(0) * iter_per_gang_4;
  # 233 "laplacian.cpp"
  last_gang_iter_4 = ((first_gang_iter_4 + iter_per_gang_4 - 1) < ( -(1 - (halfWidth_1 - 1))) ? (first_gang_iter_4 + iter_per_gang_4 - 1) : ( -(1 - (halfWidth_1 - 1))));
  # 233 "laplacian.cpp"
  int x_8;
  # 233 "laplacian.cpp"
  # 234 "laplacian.cpp"
  for (x_8 = first_gang_iter_4 + get_local_id(1) ; x_8 <= last_gang_iter_4 ; x_8 = x_8 + get_local_size(1))
  {
   # 235 "laplacian.cpp"
   *(UpsampleDst_2 + 2 * (halfWidth_1 - 1 - x_8)) = *(DownsampleDst_1 + (halfWidth_1 - 1 - x_8));
   # 236 "laplacian.cpp"
   *(UpsampleDst_2 + (2 * (halfWidth_1 - 1 - x_8) - 1)) = (uchar ) (((int ) (*(DownsampleDst_1 + (halfWidth_1 - 1 - x_8 - 1))) + (int ) (*(DownsampleDst_1 + (halfWidth_1 - 1 - x_8))) + 1) / 2);
  }
  # 229 "laplacian.cpp"
 }
}
#endif /* __GPUCODE__ */



# 229 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_230_internal_1(cl_int width_27, cl_int halfWidth_9, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  DownsampleDst_9, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  UpsampleDst_10)
{
 # 229 "laplacian.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter(&DownsampleDst_9, 8, "DownsampleDst_1");
  __hmppcg_call.addLocalParameter(&UpsampleDst_10, 8, "UpsampleDst_2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (halfWidth_9), "halfWidth_1");
  __hmppcg_call.launch(hmpp_acc_region_main_230_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 229 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_230(cl_int width_4, cl_int halfWidth_5, cl_char* DownsampleDst_5, cl_char* UpsampleDst_6)
{
 # 243 "laplacian.cpp"
 (hmpp_acc_region_main_230_internal_1(width_4, halfWidth_5, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (DownsampleDst_5), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (UpsampleDst_6)));
}
#endif /* __GPUCODE__ */



# 243 "laplacian.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_247_parallel_region_1(__global short* LaplacianLayer, __global uchar* Source, __global uchar* UpsampleDst_1, int height_3, int width_3)
{
 # 245 "laplacian.cpp"
 {
  # 250 "laplacian.cpp"
  int iter_per_gang_3;
  # 250 "laplacian.cpp"
  int first_gang_iter_3;
  # 250 "laplacian.cpp"
  int last_gang_iter_3;
  # 250 "laplacian.cpp"
  iter_per_gang_3 = ((1 + (height_3 * width_3 - 1) / 192) > 256 ? (1 + (height_3 * width_3 - 1) / 192) : 256);
  # 250 "laplacian.cpp"
  first_gang_iter_3 = get_group_id(0) * iter_per_gang_3;
  # 250 "laplacian.cpp"
  last_gang_iter_3 = ((first_gang_iter_3 + iter_per_gang_3 - 1) < (height_3 * width_3 - 1) ? (first_gang_iter_3 + iter_per_gang_3 - 1) : (height_3 * width_3 - 1));
  # 250 "laplacian.cpp"
  int y_6;
  # 250 "laplacian.cpp"
  # 254 "laplacian.cpp"
  for (y_6 = first_gang_iter_3 + get_local_id(1) ; y_6 <= last_gang_iter_3 ; y_6 = y_6 + get_local_size(1))
  {
   # 250 "laplacian.cpp"
   int y_5;
   # 253 "laplacian.cpp"
   int x_9;
   # 255 "laplacian.cpp"
   x_9 = y_6 % width_3;
   # 255 "laplacian.cpp"
   y_5 = y_6 / width_3;
   # 255 "laplacian.cpp"
   *(LaplacianLayer + (y_5 * width_3 + x_9)) = (short ) ((int ) ((short ) (*(Source + (y_5 * width_3 + x_9)))) - (int ) ((short ) (*(UpsampleDst_1 + (y_5 * width_3 + x_9)))));
  }
  # 243 "laplacian.cpp"
 }
}
#endif /* __GPUCODE__ */



# 243 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_247_internal_1(cl_int height_15, cl_int width_22, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  Source_4, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  LaplacianLayer_2, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  UpsampleDst_9)
{
 # 243 "laplacian.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter(&LaplacianLayer_2, 8, "LaplacianLayer");
  __hmppcg_call.addLocalParameter(&Source_4, 8, "Source");
  __hmppcg_call.addLocalParameter(&UpsampleDst_9, 8, "UpsampleDst_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_15), "height_3");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_22), "width_3");
  __hmppcg_call.launch(hmpp_acc_region_main_247_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 243 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_247(cl_int height_10, cl_int width_13, cl_char* Source_2, cl_short* LaplacianLayer_1, cl_char* UpsampleDst_5)
{
 # 12 "laplacian.cpp"
 (hmpp_acc_region_main_247_internal_1(height_10, width_13, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (Source_2), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (LaplacianLayer_1), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (UpsampleDst_5)));
}
#endif /* __GPUCODE__ */



# 12 "laplacian.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_55_parallel_region_1(__global uchar* Source_1, int height_2, __global int* pSrc_padding, int width_2)
{
 # 14 "laplacian.cpp"
 {
  # 58 "laplacian.cpp"
  int iter_per_gang_2;
  # 58 "laplacian.cpp"
  int first_gang_iter_2;
  # 58 "laplacian.cpp"
  int last_gang_iter_2;
  # 58 "laplacian.cpp"
  iter_per_gang_2 = 1 + (height_2 - 1) / 192;
  # 58 "laplacian.cpp"
  first_gang_iter_2 = get_group_id(0) * iter_per_gang_2;
  # 58 "laplacian.cpp"
  last_gang_iter_2 = ((first_gang_iter_2 + iter_per_gang_2 - 1) < (height_2 - 1) ? (first_gang_iter_2 + iter_per_gang_2 - 1) : (height_2 - 1));
  # 58 "laplacian.cpp"
  int h_6;
  # 58 "laplacian.cpp"
  # 59 "laplacian.cpp"
  for (h_6 = first_gang_iter_2 ; h_6 <= last_gang_iter_2 ; h_6 = h_6 + 1)
  {
   # 67 "laplacian.cpp"
   int tmp_22;
   # 67 "laplacian.cpp"
   int tmp_23;
   # 67 "laplacian.cpp"
   int tmp_24;
   # 67 "laplacian.cpp"
   int tmp_25;
   # 67 "laplacian.cpp"
   tmp_22 = 2 * (int ) (*(Source_1 + (h_6 * width_2 + 1))) - (int ) (*(Source_1 + (h_6 * width_2 + 3)));
   # 67 "laplacian.cpp"
   if (get_local_id(1) == 0)
   {
    # 67 "laplacian.cpp"
    *(pSrc_padding + ((h_6 + 2) * (width_2 + 4) + 1)) = tmp_22;
   }
   # 67 "laplacian.cpp"
   barrier(CLK_LOCAL_MEM_FENCE);
   # 67 "laplacian.cpp"
   tmp_23 = 4 * (int ) (*(Source_1 + (h_6 * width_2 + 3))) - 4 * (int ) (*(Source_1 + (h_6 * width_2 + 1))) + 2 * (int ) (*(Source_1 + h_6 * width_2)) - (int ) (*(Source_1 + (h_6 * width_2 + 2)));
   # 67 "laplacian.cpp"
   if (get_local_id(1) == 0)
   {
    # 67 "laplacian.cpp"
    *(pSrc_padding + (h_6 + 2) * (width_2 + 4)) = tmp_23;
   }
   # 67 "laplacian.cpp"
   barrier(CLK_LOCAL_MEM_FENCE);
   # 67 "laplacian.cpp"
   tmp_24 = 2 * (int ) (*(Source_1 + (h_6 * width_2 + width_2 - 2))) - (int ) (*(Source_1 + (h_6 * width_2 + width_2 - 4)));
   # 67 "laplacian.cpp"
   if (get_local_id(1) == 0)
   {
    # 67 "laplacian.cpp"
    *(pSrc_padding + ((h_6 + 2) * (width_2 + 4) + width_2 + 2)) = tmp_24;
   }
   # 67 "laplacian.cpp"
   barrier(CLK_LOCAL_MEM_FENCE);
   # 67 "laplacian.cpp"
   tmp_25 = 4 * (int ) (*(Source_1 + (h_6 * width_2 + width_2 - 4))) - 4 * (int ) (*(Source_1 + (h_6 * width_2 + width_2 - 2))) + 2 * (int ) (*(Source_1 + (h_6 * width_2 + width_2 - 1))) - (int ) (*(Source_1 + (h_6 * width_2 + width_2 - 3)));
   # 67 "laplacian.cpp"
   if (get_local_id(1) == 0)
   {
    # 67 "laplacian.cpp"
    *(pSrc_padding + ((h_6 + 2) * (width_2 + 4) + width_2 + 3)) = tmp_25;
   }
   # 67 "laplacian.cpp"
   barrier(CLK_LOCAL_MEM_FENCE);
   # 67 "laplacian.cpp"
   int end_10;
   # 67 "laplacian.cpp"
   int w_8;
   # 67 "laplacian.cpp"
   # 68 "laplacian.cpp"
   # 68 "laplacian.cpp"
   for (w_8 = get_local_id(1), end_10 = width_2 - 1 ; w_8 <= end_10 ; w_8 = w_8 + get_local_size(1))
   {
    # 68 "laplacian.cpp"
    *(pSrc_padding + ((h_6 + 2) * (width_2 + 4) + w_8 + 2)) = (int ) (*(Source_1 + (h_6 * width_2 + w_8)));
   }
   # 12 "laplacian.cpp"
  }
  # 12 "laplacian.cpp"
 }
}
#endif /* __GPUCODE__ */



# 12 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_55_internal_1(cl_int height_20, cl_int width_21, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  Source_5, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int>  pSrc_padding_4)
{
 # 12 "laplacian.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter(&Source_5, 8, "Source_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_20), "height_2");
  __hmppcg_call.addLocalParameter(&pSrc_padding_4, 8, "pSrc_padding");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_21), "width_2");
  __hmppcg_call.launch(hmpp_acc_region_main_55_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 12 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_55(cl_int height_9, cl_int width_12, cl_char* Source_3, cl_int* pSrc_padding_2)
{
 # 75 "laplacian.cpp"
 (hmpp_acc_region_main_55_internal_1(height_9, width_12, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (Source_3), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int> (pSrc_padding_2)));
}
#endif /* __GPUCODE__ */



# 75 "laplacian.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_79_parallel_region_1(int height_1, __global uchar* pBufL_cp_1, __global int* pSrc_padding_1, int width_1)
{
 # 77 "laplacian.cpp"
 {
  # 82 "laplacian.cpp"
  int iter_per_gang_1;
  # 82 "laplacian.cpp"
  int first_gang_iter_1;
  # 82 "laplacian.cpp"
  int last_gang_iter_1;
  # 82 "laplacian.cpp"
  iter_per_gang_1 = ((1 + (height_1 * width_1 - 1) / 192) > 256 ? (1 + (height_1 * width_1 - 1) / 192) : 256);
  # 82 "laplacian.cpp"
  first_gang_iter_1 = get_group_id(0) * iter_per_gang_1;
  # 82 "laplacian.cpp"
  last_gang_iter_1 = ((first_gang_iter_1 + iter_per_gang_1 - 1) < (height_1 * width_1 - 1) ? (first_gang_iter_1 + iter_per_gang_1 - 1) : (height_1 * width_1 - 1));
  # 82 "laplacian.cpp"
  int h_8;
  # 82 "laplacian.cpp"
  # 85 "laplacian.cpp"
  for (h_8 = first_gang_iter_1 + get_local_id(1) ; h_8 <= last_gang_iter_1 ; h_8 = h_8 + get_local_size(1))
  {
   # 82 "laplacian.cpp"
   int h_7;
   # 84 "laplacian.cpp"
   int w_9;
   # 86 "laplacian.cpp"
   w_9 = h_8 % width_1;
   # 86 "laplacian.cpp"
   h_7 = h_8 / width_1;
   # 86 "laplacian.cpp"
   *(pBufL_cp_1 + (h_7 * width_1 + w_9)) = (uchar ) (*(pSrc_padding_1 + ((h_7 + 2) * (width_1 + 4) + w_9)) + (*(pSrc_padding_1 + ((h_7 + 2) * (width_1 + 4) + w_9 + 1)) << 2) + 6 * *(pSrc_padding_1 + ((h_7 + 2) * (width_1 + 4) + (w_9 + 2))) + (*(pSrc_padding_1 + ((h_7 + 2) * (width_1 + 4) + (w_9 + 3))) << 2) + *(pSrc_padding_1 + ((h_7 + 2) * (width_1 + 4) + (w_9 + 4))) + 8 >> 4);
  }
  # 75 "laplacian.cpp"
 }
}
#endif /* __GPUCODE__ */



# 75 "laplacian.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_79_internal_1(cl_int height_19, cl_int width_20, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int>  pSrc_padding_5, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  pBufL_cp_8)
{
 # 75 "laplacian.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_19), "height_1");
  __hmppcg_call.addLocalParameter(&pBufL_cp_8, 8, "pBufL_cp_1");
  __hmppcg_call.addLocalParameter(&pSrc_padding_5, 8, "pSrc_padding_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_20), "width_1");
  __hmppcg_call.launch(hmpp_acc_region_main_79_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 75 "laplacian.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_79(cl_int height_8, cl_int width_11, cl_int* pSrc_padding_3, cl_char* pBufL_cp_4)
{
 # 1 "<preprocessor>"
 (hmpp_acc_region_main_79_internal_1(height_8, width_11, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int> (pSrc_padding_3), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (pBufL_cp_4)));
}
#endif /* __GPUCODE__ */




#ifndef __GPUCODE__
extern "C" const char * hmpprt_opencl_get_gpu_code();

static hmpprt::OpenCLModule * hmpprt_module = 0;
static int hmpprt_uses = 0;

extern "C" CDLT_API void * hmpprt_init()
{
  try
  {
    if (hmpprt_uses++ == 0)
    {
      hmpprt_module = new hmpprt::OpenCLModule(hmpprt_opencl_get_gpu_code());
      hmpp_acc_region_main_100_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_100_parallel_region_1");
      hmpp_acc_region_main_114_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_114_parallel_region_1");
      hmpp_acc_region_main_136_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_136_parallel_region_1");
      hmpp_acc_region_main_159_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_159_parallel_region_1");
      hmpp_acc_region_main_188_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_188_parallel_region_1");
      hmpp_acc_region_main_202_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_202_parallel_region_1");
      hmpp_acc_region_main_230_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_230_parallel_region_1");
      hmpp_acc_region_main_247_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_247_parallel_region_1");
      hmpp_acc_region_main_55_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_55_parallel_region_1");
      hmpp_acc_region_main_79_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_79_parallel_region_1");

    }
    hmpprt::Context::getInstance()->getGrouplet()->setTarget(hmpprt::OPENCL);
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_100", "prototype hmpp_acc_region_main_100(height: s32, width: s32, pSrc_padding2: ^openclglob s32, pBufL_cp: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_114", "prototype hmpp_acc_region_main_114(height: s32, width: s32, pSrc_padding2: ^openclglob s32, pBufL_cp: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_136", "prototype hmpp_acc_region_main_136(height: s32, width: s32, FilterDst: ^openclglob u8, pSrc_padding2: ^openclglob s32)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_159", "prototype hmpp_acc_region_main_159(width: s32, halfWidth: s32, halfHeight: s32, FilterDst: ^openclglob u8, DownsampleDst: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_188", "prototype hmpp_acc_region_main_188(height: s32, width: s32, halfWidth: s32, halfHeight: s32, DownsampleDst: ^openclglob u8, UpsampleDst: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_202", "prototype hmpp_acc_region_main_202(width: s32, halfWidth: s32, halfHeight: s32, DownsampleDst: ^openclglob u8, UpsampleDst: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_230", "prototype hmpp_acc_region_main_230(width: s32, halfWidth: s32, DownsampleDst: ^openclglob u8, UpsampleDst: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_247", "prototype hmpp_acc_region_main_247(height: s32, width: s32, Source: ^openclglob u8, LaplacianLayer: ^openclglob s16, UpsampleDst: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_55", "prototype hmpp_acc_region_main_55(height: s32, width: s32, Source: ^openclglob u8, pSrc_padding: ^openclglob s32)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_79", "prototype hmpp_acc_region_main_79(height: s32, width: s32, pSrc_padding: ^openclglob s32, pBufL_cp: ^openclglob u8)");

  }
  catch (hmpperr::Error & e)
  {
    return e.clone();
  }
  catch(...)
  {
    fprintf(stderr,"Unexpected error in hmpprt_init()\n");
    abort();
  }
  return 0;
}
#endif /* __GPUCODE__ */

#ifndef __GPUCODE__
extern "C" CDLT_API void * hmpprt_fini()
{
  try
  {
    if (--hmpprt_uses == 0)
    {
      delete hmpp_acc_region_main_100_parallel_region_1;
      delete hmpp_acc_region_main_114_parallel_region_1;
      delete hmpp_acc_region_main_136_parallel_region_1;
      delete hmpp_acc_region_main_159_parallel_region_1;
      delete hmpp_acc_region_main_188_parallel_region_1;
      delete hmpp_acc_region_main_202_parallel_region_1;
      delete hmpp_acc_region_main_230_parallel_region_1;
      delete hmpp_acc_region_main_247_parallel_region_1;
      delete hmpp_acc_region_main_55_parallel_region_1;
      delete hmpp_acc_region_main_79_parallel_region_1;

      delete hmpprt_module;
      hmpprt_module = 0;
    }
  }
  catch (hmpperr::Error & e)
  {
    return e.clone();
  }
  catch(...)
  {
    fprintf(stderr,"Unexpected error in hmpprt_fini()\n");
    abort();
  }
  return 0;
}
#endif /* __GPUCODE__ */

// footer
