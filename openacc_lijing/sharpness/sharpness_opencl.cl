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
#define HMPPCG_SIMD_LENGTH 1

# 23 "sharpness.cpp"

#ifdef __GPUCODE__
long reduce_s64_add_y(long priv, local long* tmpa_1, long orig)
;
#endif /* __GPUCODE__ */



# 23 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_84(cl_int width_32, cl_int height_16, cl_int quarterWidth_9, cl_char* yPlane_6, cl_char* yPlaneDown_7)
;
#endif /* __GPUCODE__ */



# 23 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_84_internal_1(cl_int width_60, cl_int height_30, cl_int quarterWidth_23, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_11, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_15)
;
#endif /* __GPUCODE__ */



# 486 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_84_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_84_parallel_region_1(int height_1, int quarterWidth_1, int width_1, __global uchar* yPlaneDown_1, __global uchar* yPlane_1);
#endif // __GPUCODE__
# 486 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_490(cl_int width_34, cl_int height_20, cl_char* yPlane_7, cl_short* pSharpness_4)
;
#endif /* __GPUCODE__ */



# 486 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_490_internal_1(cl_int width_61, cl_int height_31, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_12, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pSharpness_7)
;
#endif /* __GPUCODE__ */



# 433 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_490_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_490_parallel_region_1(int height_2, __global short* pSharpness_1, int width_2, __global uchar* yPlane_2);
#endif // __GPUCODE__
# 433 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_436(cl_int width_43, cl_int height_21, cl_char* yPlane_8, cl_short* pEdge_5, cl_short* pSharpness_5, cl_float cutoff3_1, cl_float order3_1, cl_float peak3_1, cl_float low3_1)
;
#endif /* __GPUCODE__ */



# 433 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_436_internal_1(cl_int width_62, cl_int height_32, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_13, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_9, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pSharpness_8, cl_float cutoff3_2, cl_float order3_2, cl_float peak3_2, cl_float low3_2)
;
#endif /* __GPUCODE__ */



# 391 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_436_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_436_parallel_region_1(float cutoff3, int height_3, float low3, float order3, __global short* pEdge_1, __global short* pSharpness_2, float peak3, int width_3, __global uchar* yPlane_3);
#endif // __GPUCODE__
# 391 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_411(cl_int width_45, cl_int height_22, cl_char* yPlaneCSER_16, cl_short* pError_3, cl_short* pEdge_6, cl_short* pSharpness_3, cl_double cutoff_1, cl_double peak_1, cl_double cutoff2_1, cl_double order_1, cl_double order2_1, cl_double low_1)
;
#endif /* __GPUCODE__ */



# 391 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_411_internal_1(cl_int width_63, cl_int height_33, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_33, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pError_5, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_10, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pSharpness_6, cl_double cutoff_2, cl_double peak_2, cl_double cutoff2_2, cl_double order_2, cl_double order2_2, cl_double low_2)
;
#endif /* __GPUCODE__ */



# 372 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_411_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_411_parallel_region_1(double cutoff, double cutoff2, int height_4, double low, double order, double order2, __global short* pEdge_2, __global short* pError_1, __global short* pSharpness, double peak, int width_4, __global uchar* yPlaneCSER_1);
#endif // __GPUCODE__
# 372 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_375(cl_int width_46, cl_int height_23, cl_short* pEdge_7, cl_long* sum)
;
#endif /* __GPUCODE__ */



# 372 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_375_internal_1(cl_int width_64, cl_int height_34, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_11, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_long>  sum_4)
;
#endif /* __GPUCODE__ */



# 342 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_375_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_375_parallel_region_1(__global long* gang_prv_red_sum_2, int height_5, __global short* pEdge_3, int width_5);
#endif // __GPUCODE__
# 342 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * reduce_s64_add_xy = 0;
#else
__kernel  void reduce_s64_add_xy(long neutral, __global long* scalar, int size, __global long* array);
#endif // __GPUCODE__
# 342 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_346(cl_int width_47, cl_int height_24, cl_char* yPlane_9, cl_short* pEdge_4)
;
#endif /* __GPUCODE__ */



# 342 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_346_internal_1(cl_int width_65, cl_int height_35, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_14, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_8)
;
#endif /* __GPUCODE__ */



# 323 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_346_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_346_parallel_region_1(int height_6, __global short* pEdge, int width_6, __global uchar* yPlane_4);
#endif // __GPUCODE__
# 323 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_326(cl_int width_48, cl_int height_25, cl_char* yPlane_5, cl_char* yPlaneCSER_22, cl_short* pError_2)
;
#endif /* __GPUCODE__ */



# 323 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_326_internal_1(cl_int width_66, cl_int height_36, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_10, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_37, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pError_4)
;
#endif /* __GPUCODE__ */



# 289 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_326_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_326_parallel_region_1(int height_7, __global short* pError, int width_7, __global uchar* yPlane, __global uchar* yPlaneCSER_2);
#endif // __GPUCODE__
# 289 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_289(cl_int* width_8, cl_int quarterWidth_10, cl_int quarterHeight_7, cl_char* yPlaneCSER_23, cl_char* yPlaneDown_8)
;
#endif /* __GPUCODE__ */



# 289 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_289_internal_1(cl_int* width_67, cl_int quarterWidth_16, cl_int quarterHeight_16, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_38, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_16)
;
#endif /* __GPUCODE__ */



# 277 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_289_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_289_loop1D_1(int width_30, int quarterWidth_2, int quarterHeight_1, __global uchar* yPlaneCSER_3, __global uchar* yPlaneDown_2);
#endif // __GPUCODE__
# 277 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_277(cl_int* width_9, cl_int height_8, cl_char* yPlaneCSER_4)
;
#endif /* __GPUCODE__ */



# 277 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_277_internal_1(cl_int* width_68, cl_int height_37, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_42)
;
#endif /* __GPUCODE__ */



# 254 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_277_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_277_loop1D_1(int height_26, __global uchar* yPlaneCSER_24, int width_29);
#endif // __GPUCODE__
# 254 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_254(cl_int* width_10, cl_int quarterHeight_2, cl_char* yPlaneCSER_5)
;
#endif /* __GPUCODE__ */



# 254 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_254_internal_1(cl_int* width_49, cl_int quarterHeight_12, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_43)
;
#endif /* __GPUCODE__ */



# 242 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_254_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_254_loop1D_1(int quarterHeight_8, __global uchar* yPlaneCSER_25, int width_28);
#endif // __GPUCODE__
# 242 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_242(cl_int* width_11, cl_int quarterWidth_3, cl_int quarterHeight_9, cl_char* yPlaneCSER_26, cl_char* yPlaneDown_9)
;
#endif /* __GPUCODE__ */



# 242 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_242_internal_1(cl_int* width_50, cl_int quarterWidth_20, cl_int quarterHeight_17, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_39, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_17)
;
#endif /* __GPUCODE__ */



# 230 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_242_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_242_loop1D_1(int quarterWidth_11, int quarterHeight_3, __global uchar* yPlaneCSER_6, __global uchar* yPlaneDown_3, int width_27);
#endif // __GPUCODE__
# 230 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_230(cl_int* width_12, cl_int* height_9, cl_char* yPlaneCSER_40)
;
#endif /* __GPUCODE__ */



# 230 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_230_internal_1(cl_int* width_51, cl_int* height_38, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_27)
;
#endif /* __GPUCODE__ */



# 209 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_230_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_230_loop1D_1(__global uchar* yPlaneCSER_7, int width_26, int height_14);
#endif // __GPUCODE__
# 209 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_209(cl_int* width_13, cl_int* height_10, cl_int quarterWidth_12, cl_char* yPlaneCSER_28)
;
#endif /* __GPUCODE__ */



# 209 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_209_internal_1(cl_int* width_52, cl_int* height_27, cl_int quarterWidth_17, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_41)
;
#endif /* __GPUCODE__ */



# 197 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_209_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_209_loop1D_1(int quarterWidth_4, __global uchar* yPlaneCSER_8, int width_25, int height_13);
#endif // __GPUCODE__
# 197 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_197(cl_int* width_53, cl_int* height_28, cl_int quarterWidth_18, cl_int quarterHeight_13, cl_char* yPlaneCSER_9, cl_char* yPlaneDown_12)
;
#endif /* __GPUCODE__ */



# 197 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_197_internal_1(cl_int* width_14, cl_int* height_11, cl_int quarterWidth_13, cl_int quarterHeight_4, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_44, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_4)
;
#endif /* __GPUCODE__ */



# 185 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_197_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_197_loop1D_1(int quarterWidth_5, int quarterHeight_10, __global uchar* yPlaneCSER_29, __global uchar* yPlaneDown_10, int width_24, int height_17);
#endif // __GPUCODE__
# 185 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_185(cl_int* width_54, cl_char* yPlaneCSER_34)
;
#endif /* __GPUCODE__ */



# 185 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_185_internal_1(cl_int* width_15, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_17)
;
#endif /* __GPUCODE__ */



# 164 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_185_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_185_loop1D_1(int width_36, __global uchar* yPlaneCSER_10);
#endif // __GPUCODE__
# 164 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_164(cl_int* width_55, cl_int quarterWidth_19, cl_char* yPlaneCSER_35)
;
#endif /* __GPUCODE__ */



# 164 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_164_internal_1(cl_int* width_16, cl_int quarterWidth_14, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_18)
;
#endif /* __GPUCODE__ */



# 152 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_164_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_164_loop1D_1(int quarterWidth_6, __global uchar* yPlaneCSER_11);
#endif // __GPUCODE__
# 152 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_152(cl_int* width_17, cl_int quarterWidth_7, cl_char* yPlaneCSER_30, cl_char* yPlaneDown_5)
;
#endif /* __GPUCODE__ */



# 152 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_152_internal_1(cl_int* width_56, cl_int quarterWidth_21, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_12, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_13)
;
#endif /* __GPUCODE__ */



# 140 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_152_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_152_loop1D_1(int quarterWidth_15, __global uchar* yPlaneCSER_19, __global uchar* yPlaneDown_11);
#endif // __GPUCODE__
# 140 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_140(cl_int* width_57, cl_int height_29, cl_char* yPlaneCSER_31)
;
#endif /* __GPUCODE__ */



# 140 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_140_internal_1(cl_int* width_18, cl_int height_15, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_13)
;
#endif /* __GPUCODE__ */



# 119 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_140_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_140_loop1D_1(int width_35, int height, __global uchar* yPlaneCSER_20);
#endif // __GPUCODE__
# 119 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_119(cl_int width_19, cl_int quarterHeight_14, cl_char* yPlaneCSER_21)
;
#endif /* __GPUCODE__ */



# 119 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_119_internal_1(cl_int width_58, cl_int quarterHeight_5, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_36)
;
#endif /* __GPUCODE__ */



# 103 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_119_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_119_parallel_region_1(int quarterHeight_11, int width_33, __global uchar* yPlaneCSER_14);
#endif // __GPUCODE__
# 103 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_107(cl_int width_31, cl_int quarterWidth_22, cl_int quarterHeight_15, cl_char* yPlaneCSER_15, cl_char* yPlaneDown_6)
;
#endif /* __GPUCODE__ */



# 103 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_107_internal_1(cl_int width_59, cl_int quarterWidth_8, cl_int quarterHeight_6, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_32, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_14)
;
#endif /* __GPUCODE__ */



# 103 "sharpness.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_107_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_107_parallel_region_1(int quarterHeight, int quarterWidth, int width, __global uchar* yPlaneCSER, __global uchar* yPlaneDown);
#endif // __GPUCODE__
# 103 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_107_parallel_region_1(int quarterHeight, int quarterWidth, int width, __global uchar* yPlaneCSER, __global uchar* yPlaneDown)
{
 # 105 "sharpness.cpp"
 {
  # 110 "sharpness.cpp"
  int iter_per_gang_9;
  # 110 "sharpness.cpp"
  int first_gang_iter_9;
  # 110 "sharpness.cpp"
  int last_gang_iter_9;
  # 110 "sharpness.cpp"
  iter_per_gang_9 = ((1 + (quarterHeight - 1) / 192) > 256 ? (1 + (quarterHeight - 1) / 192) : 256);
  # 110 "sharpness.cpp"
  first_gang_iter_9 = get_group_id(0) * iter_per_gang_9;
  # 110 "sharpness.cpp"
  last_gang_iter_9 = ((first_gang_iter_9 + iter_per_gang_9 - 1) < (quarterHeight - 1) ? (first_gang_iter_9 + iter_per_gang_9 - 1) : (quarterHeight - 1));
  # 110 "sharpness.cpp"
  int h_11;
  # 110 "sharpness.cpp"
  # 111 "sharpness.cpp"
  for (h_11 = first_gang_iter_9 + get_local_id(1) ; h_11 <= last_gang_iter_9 ; h_11 = h_11 + get_local_size(1))
  {
   # 112 "sharpness.cpp"
   *(yPlaneCSER + h_11 * 4 * width) = *(yPlaneDown + h_11 * quarterWidth);
  }
  # 103 "sharpness.cpp"
 }
}
#endif /* __GPUCODE__ */



# 103 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_107_internal_1(cl_int width_59, cl_int quarterWidth_8, cl_int quarterHeight_6, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_32, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_14)
{
 # 103 "sharpness.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_6), "quarterHeight");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_8), "quarterWidth");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_59), "width");
  __hmppcg_call.addLocalParameter(&yPlaneCSER_32, 8, "yPlaneCSER");
  __hmppcg_call.addLocalParameter(&yPlaneDown_14, 8, "yPlaneDown");
  __hmppcg_call.launch(hmpp_acc_region_main_107_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 103 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_107(cl_int width_31, cl_int quarterWidth_22, cl_int quarterHeight_15, cl_char* yPlaneCSER_15, cl_char* yPlaneDown_6)
{
 # 119 "sharpness.cpp"
 (hmpp_acc_region_main_107_internal_1(width_31, quarterWidth_22, quarterHeight_15, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_15), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneDown_6)));
}
#endif /* __GPUCODE__ */



# 119 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_119_parallel_region_1(int quarterHeight_11, int width_33, __global uchar* yPlaneCSER_14)
{
 # 121 "sharpness.cpp"
 {
  # 122 "sharpness.cpp"
  int iter_per_gang_8;
  # 122 "sharpness.cpp"
  int first_gang_iter_8;
  # 122 "sharpness.cpp"
  int last_gang_iter_8;
  # 122 "sharpness.cpp"
  iter_per_gang_8 = ((1 + (quarterHeight_11 - 1) / 192) > 256 ? (1 + (quarterHeight_11 - 1) / 192) : 256);
  # 122 "sharpness.cpp"
  first_gang_iter_8 = get_group_id(0) * iter_per_gang_8;
  # 122 "sharpness.cpp"
  last_gang_iter_8 = ((first_gang_iter_8 + iter_per_gang_8 - 1) < (quarterHeight_11 - 1) ? (first_gang_iter_8 + iter_per_gang_8 - 1) : (quarterHeight_11 - 1));
  # 122 "sharpness.cpp"
  int h_12;
  # 122 "sharpness.cpp"
  # 123 "sharpness.cpp"
  for (h_12 = first_gang_iter_8 + get_local_id(1) ; h_12 <= last_gang_iter_8 ; h_12 = h_12 + get_local_size(1))
  {
   # 124 "sharpness.cpp"
   if (h_12 < quarterHeight_11 - 1)
   {
    # 126 "sharpness.cpp"
    *(yPlaneCSER_14 + (h_12 * 4 + 1) * width_33) = (uchar ) (((int ) (*(yPlaneCSER_14 + h_12 * 4 * width_33)) * 3 + (int ) (*(yPlaneCSER_14 + (h_12 * 4 + 4) * width_33))) / 4);
    # 127 "sharpness.cpp"
    *(yPlaneCSER_14 + (h_12 * 4 + 2) * width_33) = (uchar ) (((int ) (*(yPlaneCSER_14 + h_12 * 4 * width_33)) * 2 + (int ) (*(yPlaneCSER_14 + (h_12 * 4 + 4) * width_33)) * 2) / 4);
    # 128 "sharpness.cpp"
    *(yPlaneCSER_14 + (h_12 * 4 + 3) * width_33) = (uchar ) (((int ) (*(yPlaneCSER_14 + h_12 * 4 * width_33)) + (int ) (*(yPlaneCSER_14 + (h_12 * 4 + 4) * width_33)) * 3) / 4);
   }
   else
   {
    # 132 "sharpness.cpp"
    *(yPlaneCSER_14 + (h_12 * 4 + 1) * width_33) = *(yPlaneCSER_14 + h_12 * 4 * width_33);
   }
  }
  # 119 "sharpness.cpp"
 }
}
#endif /* __GPUCODE__ */



# 119 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_119_internal_1(cl_int width_58, cl_int quarterHeight_5, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_36)
{
 # 119 "sharpness.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_5), "quarterHeight_11");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_58), "width_33");
  __hmppcg_call.addLocalParameter(&yPlaneCSER_36, 8, "yPlaneCSER_14");
  __hmppcg_call.launch(hmpp_acc_region_main_119_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 119 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_119(cl_int width_19, cl_int quarterHeight_14, cl_char* yPlaneCSER_21)
{
 # 140 "sharpness.cpp"
 (hmpp_acc_region_main_119_internal_1(width_19, quarterHeight_14, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_21)));
}
#endif /* __GPUCODE__ */



# 140 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_140_loop1D_1(int width_35, int height, __global uchar* yPlaneCSER_20)
{
 # 143 "sharpness.cpp"
 int h_13;
 # 145 "sharpness.cpp"
 h_13 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 145 "sharpness.cpp"
 if (h_13 > height - 1)
 {
  # 145 "sharpness.cpp"
  goto __hmppcg_label_1;
 }
 # 145 "sharpness.cpp"
 *(yPlaneCSER_20 + (h_13 * width_35 + 1)) = *(yPlaneCSER_20 + h_13 * width_35);
 # 140 "sharpness.cpp"
 __hmppcg_label_1:;
}
#endif /* __GPUCODE__ */



# 140 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_140_internal_1(cl_int* width_18, cl_int height_15, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_13)
{
 # 142 "sharpness.cpp"
 cl_int width_20;
 # 142 "sharpness.cpp"
 width_20 = *width_18;
 # 142 "sharpness.cpp"
 {
  # 140 "sharpness.cpp"
  if (height_15 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((height_15 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_20), "width_35");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_15), "height");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_13, 8, "yPlaneCSER_20");
   __hmppcg_call.launch(hmpp_acc_region_main_140_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 140 "sharpness.cpp"
 *width_18 = width_20;
}
#endif /* __GPUCODE__ */



# 140 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_140(cl_int* width_57, cl_int height_29, cl_char* yPlaneCSER_31)
{
 # 152 "sharpness.cpp"
 (hmpp_acc_region_main_140_internal_1(width_57, height_29, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_31)));
}
#endif /* __GPUCODE__ */



# 152 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_152_loop1D_1(int quarterWidth_15, __global uchar* yPlaneCSER_19, __global uchar* yPlaneDown_11)
{
 # 155 "sharpness.cpp"
 int w_11;
 # 157 "sharpness.cpp"
 w_11 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 157 "sharpness.cpp"
 if (w_11 > quarterWidth_15 - 1)
 {
  # 157 "sharpness.cpp"
  goto __hmppcg_label_2;
 }
 # 157 "sharpness.cpp"
 *(yPlaneCSER_19 + w_11 * 4) = *(yPlaneDown_11 + w_11);
 # 152 "sharpness.cpp"
 __hmppcg_label_2:;
}
#endif /* __GPUCODE__ */



# 152 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_152_internal_1(cl_int* width_56, cl_int quarterWidth_21, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_12, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_13)
{
 # 154 "sharpness.cpp"
 cl_int width_21;
 # 154 "sharpness.cpp"
 width_21 = *width_56;
 # 154 "sharpness.cpp"
 {
  # 152 "sharpness.cpp"
  if (quarterWidth_21 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_21 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_21), "quarterWidth_15");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_12, 8, "yPlaneCSER_19");
   __hmppcg_call.addLocalParameter(&yPlaneDown_13, 8, "yPlaneDown_11");
   __hmppcg_call.launch(hmpp_acc_region_main_152_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 152 "sharpness.cpp"
 *width_56 = width_21;
}
#endif /* __GPUCODE__ */



# 152 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_152(cl_int* width_17, cl_int quarterWidth_7, cl_char* yPlaneCSER_30, cl_char* yPlaneDown_5)
{
 # 164 "sharpness.cpp"
 (hmpp_acc_region_main_152_internal_1(width_17, quarterWidth_7, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_30), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneDown_5)));
}
#endif /* __GPUCODE__ */



# 164 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_164_loop1D_1(int quarterWidth_6, __global uchar* yPlaneCSER_11)
{
 # 167 "sharpness.cpp"
 int w_12;
 # 169 "sharpness.cpp"
 w_12 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 169 "sharpness.cpp"
 if (w_12 > quarterWidth_6 - 1)
 {
  # 169 "sharpness.cpp"
  goto __hmppcg_label_3;
 }
 # 169 "sharpness.cpp"
 if (w_12 < quarterWidth_6 - 1)
 {
  # 171 "sharpness.cpp"
  *(yPlaneCSER_11 + (w_12 * 4 + 1)) = (uchar ) (((int ) (*(yPlaneCSER_11 + w_12 * 4)) * 3 + (int ) (*(yPlaneCSER_11 + (w_12 * 4 + 4)))) / 4);
  # 172 "sharpness.cpp"
  *(yPlaneCSER_11 + (w_12 * 4 + 2)) = (uchar ) (((int ) (*(yPlaneCSER_11 + w_12 * 4)) * 2 + (int ) (*(yPlaneCSER_11 + (w_12 * 4 + 4))) * 2) / 4);
  # 173 "sharpness.cpp"
  *(yPlaneCSER_11 + (w_12 * 4 + 3)) = (uchar ) (((int ) (*(yPlaneCSER_11 + w_12 * 4)) + (int ) (*(yPlaneCSER_11 + (w_12 * 4 + 4))) * 3) / 4);
 }
 else
 {
  # 177 "sharpness.cpp"
  *(yPlaneCSER_11 + (w_12 * 4 + 1)) = *(yPlaneCSER_11 + w_12 * 4);
 }
 # 164 "sharpness.cpp"
 __hmppcg_label_3:;
}
#endif /* __GPUCODE__ */



# 164 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_164_internal_1(cl_int* width_16, cl_int quarterWidth_14, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_18)
{
 # 166 "sharpness.cpp"
 cl_int width_22;
 # 166 "sharpness.cpp"
 width_22 = *width_16;
 # 166 "sharpness.cpp"
 {
  # 164 "sharpness.cpp"
  if (quarterWidth_14 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_14 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_14), "quarterWidth_6");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_18, 8, "yPlaneCSER_11");
   __hmppcg_call.launch(hmpp_acc_region_main_164_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 164 "sharpness.cpp"
 *width_16 = width_22;
}
#endif /* __GPUCODE__ */



# 164 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_164(cl_int* width_55, cl_int quarterWidth_19, cl_char* yPlaneCSER_35)
{
 # 185 "sharpness.cpp"
 (hmpp_acc_region_main_164_internal_1(width_55, quarterWidth_19, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_35)));
}
#endif /* __GPUCODE__ */



# 185 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_185_loop1D_1(int width_36, __global uchar* yPlaneCSER_10)
{
 # 188 "sharpness.cpp"
 int w_13;
 # 190 "sharpness.cpp"
 w_13 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 190 "sharpness.cpp"
 if (w_13 > width_36 - 1)
 {
  # 190 "sharpness.cpp"
  goto __hmppcg_label_4;
 }
 # 190 "sharpness.cpp"
 *(yPlaneCSER_10 + (width_36 + w_13)) = *(yPlaneCSER_10 + w_13);
 # 185 "sharpness.cpp"
 __hmppcg_label_4:;
}
#endif /* __GPUCODE__ */



# 185 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_185_internal_1(cl_int* width_15, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_17)
{
 # 187 "sharpness.cpp"
 cl_int width_23;
 # 187 "sharpness.cpp"
 width_23 = *width_15;
 # 187 "sharpness.cpp"
 {
  # 185 "sharpness.cpp"
  if (width_23 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((width_23 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_23), "width_36");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_17, 8, "yPlaneCSER_10");
   __hmppcg_call.launch(hmpp_acc_region_main_185_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 185 "sharpness.cpp"
 *width_15 = width_23;
}
#endif /* __GPUCODE__ */



# 185 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_185(cl_int* width_54, cl_char* yPlaneCSER_34)
{
 # 197 "sharpness.cpp"
 (hmpp_acc_region_main_185_internal_1(width_54, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_34)));
}
#endif /* __GPUCODE__ */



# 197 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_197_loop1D_1(int quarterWidth_5, int quarterHeight_10, __global uchar* yPlaneCSER_29, __global uchar* yPlaneDown_10, int width_24, int height_17)
{
 # 200 "sharpness.cpp"
 int w_14;
 # 202 "sharpness.cpp"
 w_14 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 202 "sharpness.cpp"
 if (w_14 > quarterWidth_5 - 1)
 {
  # 202 "sharpness.cpp"
  goto __hmppcg_label_5;
 }
 # 202 "sharpness.cpp"
 *(yPlaneCSER_29 + ((height_17 - 2) * width_24 + w_14 * 4)) = *(yPlaneDown_10 + ((quarterHeight_10 - 1) * quarterWidth_5 + w_14));
 # 197 "sharpness.cpp"
 __hmppcg_label_5:;
}
#endif /* __GPUCODE__ */



# 197 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_197_internal_1(cl_int* width_14, cl_int* height_11, cl_int quarterWidth_13, cl_int quarterHeight_4, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_44, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_4)
{
 # 199 "sharpness.cpp"
 cl_int height_12;
 # 199 "sharpness.cpp"
 height_12 = *height_11;
 # 199 "sharpness.cpp"
 cl_int width_37;
 # 199 "sharpness.cpp"
 width_37 = *width_14;
 # 199 "sharpness.cpp"
 {
  # 197 "sharpness.cpp"
  if (quarterWidth_13 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_13 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_13), "quarterWidth_5");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_4), "quarterHeight_10");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_44, 8, "yPlaneCSER_29");
   __hmppcg_call.addLocalParameter(&yPlaneDown_4, 8, "yPlaneDown_10");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_37), "width_24");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_12), "height_17");
   __hmppcg_call.launch(hmpp_acc_region_main_197_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 197 "sharpness.cpp"
 *width_14 = width_37;
 # 197 "sharpness.cpp"
 *height_11 = height_12;
}
#endif /* __GPUCODE__ */



# 197 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_197(cl_int* width_53, cl_int* height_28, cl_int quarterWidth_18, cl_int quarterHeight_13, cl_char* yPlaneCSER_9, cl_char* yPlaneDown_12)
{
 # 209 "sharpness.cpp"
 (hmpp_acc_region_main_197_internal_1(width_53, height_28, quarterWidth_18, quarterHeight_13, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_9), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneDown_12)));
}
#endif /* __GPUCODE__ */



# 209 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_209_loop1D_1(int quarterWidth_4, __global uchar* yPlaneCSER_8, int width_25, int height_13)
{
 # 212 "sharpness.cpp"
 int w_15;
 # 214 "sharpness.cpp"
 w_15 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 214 "sharpness.cpp"
 if (w_15 > quarterWidth_4 - 1)
 {
  # 214 "sharpness.cpp"
  goto __hmppcg_label_6;
 }
 # 214 "sharpness.cpp"
 if (w_15 < quarterWidth_4 - 1)
 {
  # 216 "sharpness.cpp"
  *(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4 + 1)) = (uchar ) (((int ) (*(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4))) * 3 + (int ) (*(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4 + 4)))) / 4);
  # 217 "sharpness.cpp"
  *(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4 + 2)) = (uchar ) (((int ) (*(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4))) * 2 + (int ) (*(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4 + 4))) * 2) / 4);
  # 218 "sharpness.cpp"
  *(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4 + 3)) = (uchar ) (((int ) (*(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4))) + (int ) (*(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4 + 4))) * 3) / 4);
 }
 else
 {
  # 222 "sharpness.cpp"
  *(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4 + 1)) = *(yPlaneCSER_8 + ((height_13 - 2) * width_25 + w_15 * 4));
 }
 # 209 "sharpness.cpp"
 __hmppcg_label_6:;
}
#endif /* __GPUCODE__ */



# 209 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_209_internal_1(cl_int* width_52, cl_int* height_27, cl_int quarterWidth_17, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_41)
{
 # 211 "sharpness.cpp"
 cl_int height_18;
 # 211 "sharpness.cpp"
 height_18 = *height_27;
 # 211 "sharpness.cpp"
 cl_int width_38;
 # 211 "sharpness.cpp"
 width_38 = *width_52;
 # 211 "sharpness.cpp"
 {
  # 209 "sharpness.cpp"
  if (quarterWidth_17 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_17 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_17), "quarterWidth_4");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_41, 8, "yPlaneCSER_8");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_38), "width_25");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_18), "height_13");
   __hmppcg_call.launch(hmpp_acc_region_main_209_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 209 "sharpness.cpp"
 *width_52 = width_38;
 # 209 "sharpness.cpp"
 *height_27 = height_18;
}
#endif /* __GPUCODE__ */



# 209 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_209(cl_int* width_13, cl_int* height_10, cl_int quarterWidth_12, cl_char* yPlaneCSER_28)
{
 # 230 "sharpness.cpp"
 (hmpp_acc_region_main_209_internal_1(width_13, height_10, quarterWidth_12, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_28)));
}
#endif /* __GPUCODE__ */



# 230 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_230_loop1D_1(__global uchar* yPlaneCSER_7, int width_26, int height_14)
{
 # 233 "sharpness.cpp"
 int w_16;
 # 235 "sharpness.cpp"
 w_16 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 235 "sharpness.cpp"
 if (w_16 > width_26 - 1)
 {
  # 235 "sharpness.cpp"
  goto __hmppcg_label_7;
 }
 # 235 "sharpness.cpp"
 *(yPlaneCSER_7 + ((height_14 - 1) * width_26 + w_16)) = *(yPlaneCSER_7 + ((height_14 - 2) * width_26 + w_16));
 # 230 "sharpness.cpp"
 __hmppcg_label_7:;
}
#endif /* __GPUCODE__ */



# 230 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_230_internal_1(cl_int* width_51, cl_int* height_38, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_27)
{
 # 232 "sharpness.cpp"
 cl_int height_19;
 # 232 "sharpness.cpp"
 height_19 = *height_38;
 # 232 "sharpness.cpp"
 cl_int width_39;
 # 232 "sharpness.cpp"
 width_39 = *width_51;
 # 232 "sharpness.cpp"
 {
  # 230 "sharpness.cpp"
  if (width_39 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((width_39 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter(&yPlaneCSER_27, 8, "yPlaneCSER_7");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_39), "width_26");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_19), "height_14");
   __hmppcg_call.launch(hmpp_acc_region_main_230_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 230 "sharpness.cpp"
 *width_51 = width_39;
 # 230 "sharpness.cpp"
 *height_38 = height_19;
}
#endif /* __GPUCODE__ */



# 230 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_230(cl_int* width_12, cl_int* height_9, cl_char* yPlaneCSER_40)
{
 # 242 "sharpness.cpp"
 (hmpp_acc_region_main_230_internal_1(width_12, height_9, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_40)));
}
#endif /* __GPUCODE__ */



# 242 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_242_loop1D_1(int quarterWidth_11, int quarterHeight_3, __global uchar* yPlaneCSER_6, __global uchar* yPlaneDown_3, int width_27)
{
 # 245 "sharpness.cpp"
 int h_14;
 # 247 "sharpness.cpp"
 h_14 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 247 "sharpness.cpp"
 if (h_14 > quarterHeight_3 - 1)
 {
  # 247 "sharpness.cpp"
  goto __hmppcg_label_8;
 }
 # 247 "sharpness.cpp"
 *(yPlaneCSER_6 + (h_14 * 4 * width_27 + width_27 - 2)) = *(yPlaneDown_3 + (h_14 * quarterWidth_11 + quarterWidth_11 - 1));
 # 242 "sharpness.cpp"
 __hmppcg_label_8:;
}
#endif /* __GPUCODE__ */



# 242 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_242_internal_1(cl_int* width_50, cl_int quarterWidth_20, cl_int quarterHeight_17, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_39, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_17)
{
 # 244 "sharpness.cpp"
 cl_int width_40;
 # 244 "sharpness.cpp"
 width_40 = *width_50;
 # 244 "sharpness.cpp"
 {
  # 242 "sharpness.cpp"
  if (quarterHeight_17 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterHeight_17 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_20), "quarterWidth_11");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_17), "quarterHeight_3");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_39, 8, "yPlaneCSER_6");
   __hmppcg_call.addLocalParameter(&yPlaneDown_17, 8, "yPlaneDown_3");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_40), "width_27");
   __hmppcg_call.launch(hmpp_acc_region_main_242_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 242 "sharpness.cpp"
 *width_50 = width_40;
}
#endif /* __GPUCODE__ */



# 242 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_242(cl_int* width_11, cl_int quarterWidth_3, cl_int quarterHeight_9, cl_char* yPlaneCSER_26, cl_char* yPlaneDown_9)
{
 # 254 "sharpness.cpp"
 (hmpp_acc_region_main_242_internal_1(width_11, quarterWidth_3, quarterHeight_9, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_26), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneDown_9)));
}
#endif /* __GPUCODE__ */



# 254 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_254_loop1D_1(int quarterHeight_8, __global uchar* yPlaneCSER_25, int width_28)
{
 # 257 "sharpness.cpp"
 int h_15;
 # 259 "sharpness.cpp"
 h_15 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 259 "sharpness.cpp"
 if (h_15 > quarterHeight_8 - 1)
 {
  # 259 "sharpness.cpp"
  goto __hmppcg_label_9;
 }
 # 259 "sharpness.cpp"
 if (h_15 < quarterHeight_8 - 1)
 {
  # 261 "sharpness.cpp"
  *(yPlaneCSER_25 + ((h_15 * 4 + 1) * width_28 + width_28 - 2)) = (uchar ) (((int ) (*(yPlaneCSER_25 + (h_15 * 4 * width_28 + width_28 - 2))) * 3 + (int ) (*(yPlaneCSER_25 + ((h_15 * 4 + 4) * width_28 + width_28 - 2)))) / 4);
  # 262 "sharpness.cpp"
  *(yPlaneCSER_25 + ((h_15 * 4 + 2) * width_28 + width_28 - 2)) = (uchar ) (((int ) (*(yPlaneCSER_25 + (h_15 * 4 * width_28 + width_28 - 2))) * 2 + (int ) (*(yPlaneCSER_25 + ((h_15 * 4 + 4) * width_28 + width_28 - 2))) * 2) / 4);
  # 263 "sharpness.cpp"
  *(yPlaneCSER_25 + ((h_15 * 4 + 3) * width_28 + width_28 - 2)) = (uchar ) (((int ) (*(yPlaneCSER_25 + (h_15 * 4 * width_28 + width_28 - 2))) + (int ) (*(yPlaneCSER_25 + ((h_15 * 4 + 4) * width_28 + width_28 - 2))) * 3) / 4);
 }
 else
 {
  # 267 "sharpness.cpp"
  *(yPlaneCSER_25 + ((h_15 * 4 + 1) * width_28 + width_28 - 2)) = *(yPlaneCSER_25 + (h_15 * 4 * width_28 + width_28 - 2));
  # 268 "sharpness.cpp"
  *(yPlaneCSER_25 + ((h_15 * 4 + 2) * width_28 + width_28 - 2)) = *(yPlaneCSER_25 + (h_15 * 4 * width_28 + width_28 - 2));
  # 269 "sharpness.cpp"
  *(yPlaneCSER_25 + ((h_15 * 4 + 3) * width_28 + width_28 - 2)) = *(yPlaneCSER_25 + (h_15 * 4 * width_28 + width_28 - 2));
 }
 # 254 "sharpness.cpp"
 __hmppcg_label_9:;
}
#endif /* __GPUCODE__ */



# 254 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_254_internal_1(cl_int* width_49, cl_int quarterHeight_12, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_43)
{
 # 256 "sharpness.cpp"
 cl_int width_41;
 # 256 "sharpness.cpp"
 width_41 = *width_49;
 # 256 "sharpness.cpp"
 {
  # 254 "sharpness.cpp"
  if (quarterHeight_12 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterHeight_12 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_12), "quarterHeight_8");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_43, 8, "yPlaneCSER_25");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_41), "width_28");
   __hmppcg_call.launch(hmpp_acc_region_main_254_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 254 "sharpness.cpp"
 *width_49 = width_41;
}
#endif /* __GPUCODE__ */



# 254 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_254(cl_int* width_10, cl_int quarterHeight_2, cl_char* yPlaneCSER_5)
{
 # 277 "sharpness.cpp"
 (hmpp_acc_region_main_254_internal_1(width_10, quarterHeight_2, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_5)));
}
#endif /* __GPUCODE__ */



# 277 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_277_loop1D_1(int height_26, __global uchar* yPlaneCSER_24, int width_29)
{
 # 280 "sharpness.cpp"
 int h_16;
 # 282 "sharpness.cpp"
 h_16 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 282 "sharpness.cpp"
 if (h_16 > height_26 - 1)
 {
  # 282 "sharpness.cpp"
  goto __hmppcg_label_10;
 }
 # 282 "sharpness.cpp"
 *(yPlaneCSER_24 + (h_16 * width_29 + width_29 - 1)) = *(yPlaneCSER_24 + (h_16 * width_29 + width_29 - 2));
 # 277 "sharpness.cpp"
 __hmppcg_label_10:;
}
#endif /* __GPUCODE__ */



# 277 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_277_internal_1(cl_int* width_68, cl_int height_37, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_42)
{
 # 279 "sharpness.cpp"
 cl_int width_42;
 # 279 "sharpness.cpp"
 width_42 = *width_68;
 # 279 "sharpness.cpp"
 {
  # 277 "sharpness.cpp"
  if (height_37 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((height_37 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_37), "height_26");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_42, 8, "yPlaneCSER_24");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_42), "width_29");
   __hmppcg_call.launch(hmpp_acc_region_main_277_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 277 "sharpness.cpp"
 *width_68 = width_42;
}
#endif /* __GPUCODE__ */



# 277 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_277(cl_int* width_9, cl_int height_8, cl_char* yPlaneCSER_4)
{
 # 289 "sharpness.cpp"
 (hmpp_acc_region_main_277_internal_1(width_9, height_8, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_4)));
}
#endif /* __GPUCODE__ */



# 289 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_289_loop1D_1(int width_30, int quarterWidth_2, int quarterHeight_1, __global uchar* yPlaneCSER_3, __global uchar* yPlaneDown_2)
{
 # 292 "sharpness.cpp"
 int h_17;
 # 295 "sharpness.cpp"
 int w_17;
 # 292 "sharpness.cpp"
 int h_22;
 # 297 "sharpness.cpp"
 h_22 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 297 "sharpness.cpp"
 if (h_22 > (quarterHeight_1 +  -1) * (quarterWidth_2 - 1) - 1)
 {
  # 297 "sharpness.cpp"
  goto __hmppcg_label_11;
 }
 # 297 "sharpness.cpp"
 w_17 = h_22 % (quarterWidth_2 +  -1);
 # 297 "sharpness.cpp"
 h_17 = h_22 / (quarterWidth_2 +  -1);
 # 297 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 2)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) * 7 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) / 8 / 8);
 # 298 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 3)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) * 7 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) / 8 / 8);
 # 299 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 4)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) * 7 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) / 8 / 8);
 # 300 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 5)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) * 7 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) / 8 / 8);
 # 302 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 2)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) * 5 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) * 3 / 8 / 8);
 # 303 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 3)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) * 5 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) * 3 / 8 / 8);
 # 304 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 4)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) * 5 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) * 3 / 8 / 8);
 # 305 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 5)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) * 5 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) * 3 / 8 / 8);
 # 307 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 2)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) * 3 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) * 5 / 8 / 8);
 # 308 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 3)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) * 3 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) * 5 / 8 / 8);
 # 309 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 4)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) * 3 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) * 5 / 8 / 8);
 # 310 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 5)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) * 3 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) * 5 / 8 / 8);
 # 312 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 2)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) * 7 / 8 / 8);
 # 313 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 3)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) * 7 / 8 / 8);
 # 314 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 4)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) * 7 / 8 / 8);
 # 315 "sharpness.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 5)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) * 7 / 8 / 8);
 # 289 "sharpness.cpp"
 __hmppcg_label_11:;
}
#endif /* __GPUCODE__ */



# 289 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_289_internal_1(cl_int* width_67, cl_int quarterWidth_16, cl_int quarterHeight_16, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_38, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_16)
{
 # 291 "sharpness.cpp"
 cl_int width_44;
 # 291 "sharpness.cpp"
 width_44 = *width_67;
 # 291 "sharpness.cpp"
 {
  # 289 "sharpness.cpp"
  if ((quarterHeight_16 +  -1) * (quarterWidth_16 - 1) - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX(((quarterHeight_16 +  -1) * (quarterWidth_16 - 1) - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_44), "width_30");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_16), "quarterWidth_2");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_16), "quarterHeight_1");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_38, 8, "yPlaneCSER_3");
   __hmppcg_call.addLocalParameter(&yPlaneDown_16, 8, "yPlaneDown_2");
   __hmppcg_call.launch(hmpp_acc_region_main_289_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 289 "sharpness.cpp"
 *width_67 = width_44;
}
#endif /* __GPUCODE__ */



# 289 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_289(cl_int* width_8, cl_int quarterWidth_10, cl_int quarterHeight_7, cl_char* yPlaneCSER_23, cl_char* yPlaneDown_8)
{
 # 323 "sharpness.cpp"
 (hmpp_acc_region_main_289_internal_1(width_8, quarterWidth_10, quarterHeight_7, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_23), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneDown_8)));
}
#endif /* __GPUCODE__ */



# 323 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_326_parallel_region_1(int height_7, __global short* pError, int width_7, __global uchar* yPlane, __global uchar* yPlaneCSER_2)
{
 # 325 "sharpness.cpp"
 {
  # 329 "sharpness.cpp"
  int iter_per_gang_7;
  # 329 "sharpness.cpp"
  int first_gang_iter_7;
  # 329 "sharpness.cpp"
  int last_gang_iter_7;
  # 329 "sharpness.cpp"
  iter_per_gang_7 = ((1 + (height_7 * width_7 - 1) / 192) > 256 ? (1 + (height_7 * width_7 - 1) / 192) : 256);
  # 329 "sharpness.cpp"
  first_gang_iter_7 = get_group_id(0) * iter_per_gang_7;
  # 329 "sharpness.cpp"
  last_gang_iter_7 = ((first_gang_iter_7 + iter_per_gang_7 - 1) < (height_7 * width_7 - 1) ? (first_gang_iter_7 + iter_per_gang_7 - 1) : (height_7 * width_7 - 1));
  # 329 "sharpness.cpp"
  int h_23;
  # 329 "sharpness.cpp"
  # 333 "sharpness.cpp"
  for (h_23 = first_gang_iter_7 + get_local_id(1) ; h_23 <= last_gang_iter_7 ; h_23 = h_23 + get_local_size(1))
  {
   # 329 "sharpness.cpp"
   int h_18;
   # 332 "sharpness.cpp"
   int w_18;
   # 334 "sharpness.cpp"
   w_18 = h_23 % width_7;
   # 334 "sharpness.cpp"
   h_18 = h_23 / width_7;
   # 334 "sharpness.cpp"
   *(pError + (h_18 * width_7 + w_18)) = (short ) ((int ) (*(yPlane + (h_18 * width_7 + w_18))) - (int ) (*(yPlaneCSER_2 + (h_18 * width_7 + w_18))));
  }
  # 323 "sharpness.cpp"
 }
}
#endif /* __GPUCODE__ */



# 323 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_326_internal_1(cl_int width_66, cl_int height_36, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_10, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_37, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pError_4)
{
 # 323 "sharpness.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_36), "height_7");
  __hmppcg_call.addLocalParameter(&pError_4, 8, "pError");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_66), "width_7");
  __hmppcg_call.addLocalParameter(&yPlane_10, 8, "yPlane");
  __hmppcg_call.addLocalParameter(&yPlaneCSER_37, 8, "yPlaneCSER_2");
  __hmppcg_call.launch(hmpp_acc_region_main_326_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 323 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_326(cl_int width_48, cl_int height_25, cl_char* yPlane_5, cl_char* yPlaneCSER_22, cl_short* pError_2)
{
 # 342 "sharpness.cpp"
 (hmpp_acc_region_main_326_internal_1(width_48, height_25, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlane_5), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_22), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pError_2)));
}
#endif /* __GPUCODE__ */



# 342 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_346_parallel_region_1(int height_6, __global short* pEdge, int width_6, __global uchar* yPlane_4)
{
 # 344 "sharpness.cpp"
 {
  # 349 "sharpness.cpp"
  int iter_per_gang_6;
  # 349 "sharpness.cpp"
  int first_gang_iter_6;
  # 349 "sharpness.cpp"
  int last_gang_iter_6;
  # 349 "sharpness.cpp"
  iter_per_gang_6 = ((1 + (height_6 * width_6 - 1) / 192) > 256 ? (1 + (height_6 * width_6 - 1) / 192) : 256);
  # 349 "sharpness.cpp"
  first_gang_iter_6 = get_group_id(0) * iter_per_gang_6;
  # 349 "sharpness.cpp"
  last_gang_iter_6 = ((first_gang_iter_6 + iter_per_gang_6 - 1) < (height_6 * width_6 - 1) ? (first_gang_iter_6 + iter_per_gang_6 - 1) : (height_6 * width_6 - 1));
  # 349 "sharpness.cpp"
  int y_2;
  # 349 "sharpness.cpp"
  # 353 "sharpness.cpp"
  for (y_2 = first_gang_iter_6 + get_local_id(1) ; y_2 <= last_gang_iter_6 ; y_2 = y_2 + get_local_size(1))
  {
   # 349 "sharpness.cpp"
   int y_1;
   # 352 "sharpness.cpp"
   int x_1;
   # 354 "sharpness.cpp"
   x_1 = y_2 % width_6;
   # 354 "sharpness.cpp"
   y_1 = y_2 / width_6;
   # 354 "sharpness.cpp"
   if (y_1 == 0 || y_1 == height_6 - 1 || x_1 == 0 || x_1 == width_6 - 1)
   {
    # 356 "sharpness.cpp"
    *(pEdge + (y_1 * width_6 + x_1)) = (short) 0;
   }
   else
   {
    # 360 "sharpness.cpp"
    int gx;
    # 360 "sharpness.cpp"
    gx = (int ) (*(yPlane_4 + ((y_1 - 1) * width_6 + x_1 + 1))) + ((int ) (*(yPlane_4 + (y_1 * width_6 + x_1 + 1))) << 1) + (int ) (*(yPlane_4 + ((y_1 + 1) * width_6 + x_1 + 1))) - ((int ) (*(yPlane_4 + ((y_1 - 1) * width_6 + x_1 - 1))) + ((int ) (*(yPlane_4 + (y_1 * width_6 + x_1 - 1))) << 1) + (int ) (*(yPlane_4 + ((y_1 + 1) * width_6 + x_1 - 1))));
    # 361 "sharpness.cpp"
    int gy;
    # 361 "sharpness.cpp"
    gy = (int ) (*(yPlane_4 + ((y_1 - 1) * width_6 + x_1 - 1))) + ((int ) (*(yPlane_4 + ((y_1 - 1) * width_6 + x_1))) << 1) + (int ) (*(yPlane_4 + ((y_1 - 1) * width_6 + x_1 + 1))) - ((int ) (*(yPlane_4 + ((y_1 + 1) * width_6 + x_1 - 1))) + ((int ) (*(yPlane_4 + ((y_1 + 1) * width_6 + x_1))) << 1) + (int ) (*(yPlane_4 + ((y_1 + 1) * width_6 + x_1 + 1))));
    # 362 "sharpness.cpp"
    int edgeV;
    # 362 "sharpness.cpp"
    edgeV = ((gx) > 0 ? (gx) : -(gx)) + ((gy) > 0 ? (gy) : -(gy));
    # 363 "sharpness.cpp"
    *(pEdge + (y_1 * width_6 + x_1)) = (short ) (edgeV);
   }
  }
  # 342 "sharpness.cpp"
 }
}
#endif /* __GPUCODE__ */



# 342 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_346_internal_1(cl_int width_65, cl_int height_35, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_14, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_8)
{
 # 342 "sharpness.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_35), "height_6");
  __hmppcg_call.addLocalParameter(&pEdge_8, 8, "pEdge");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_65), "width_6");
  __hmppcg_call.addLocalParameter(&yPlane_14, 8, "yPlane_4");
  __hmppcg_call.launch(hmpp_acc_region_main_346_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 342 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_346(cl_int width_47, cl_int height_24, cl_char* yPlane_9, cl_short* pEdge_4)
{
 # 372 "sharpness.cpp"
 (hmpp_acc_region_main_346_internal_1(width_47, height_24, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlane_9), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pEdge_4)));
}
#endif /* __GPUCODE__ */



# 372 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(256, 1, 1)))  void reduce_s64_add_xy(long neutral, __global long* scalar, int size, __global long* array)
{
 
 local long tmpa[256];
 
 # 372 "sharpness.cpp"
 long var;
 # 372 "sharpness.cpp"
 var = neutral;
 # 372 "sharpness.cpp"
 int end_5;
 # 372 "sharpness.cpp"
 int i;
 # 372 "sharpness.cpp"
 # 372 "sharpness.cpp"
 # 372 "sharpness.cpp"
 for (i = (get_local_id(1)* get_local_size(0) + get_local_id(0)), end_5 = size - 1 ; i <= end_5 ; i = i + 256)
 {
  # 372 "sharpness.cpp"
  var = var + *(array + i);
 }
 # 372 "sharpness.cpp"
 # 372 "sharpness.cpp"
 tmpa[(get_local_id(1)* get_local_size(0) + get_local_id(0))] = var;
 # 372 "sharpness.cpp"
 int n_1;
 # 372 "sharpness.cpp"
 # 372 "sharpness.cpp"
 for (n_1 = (255 >> 1) + 1 ; n_1 > 0 ; n_1 = (n_1 >> 1))
 {
  # 372 "sharpness.cpp"
  int next_1;
  # 372 "sharpness.cpp"
  next_1 = (get_local_id(1)* get_local_size(0) + get_local_id(0)) + n_1;
  # 372 "sharpness.cpp"
  barrier(CLK_LOCAL_MEM_FENCE);
  # 372 "sharpness.cpp"
  if ((get_local_id(1)* get_local_size(0) + get_local_id(0)) < n_1 && next_1 < 256)
  {
   # 372 "sharpness.cpp"
   tmpa[(get_local_id(1)* get_local_size(0) + get_local_id(0))] = tmpa[(get_local_id(1)* get_local_size(0) + get_local_id(0))] + tmpa[next_1];
  }
 }
 # 372 "sharpness.cpp"
 # 372 "sharpness.cpp"
 if ((get_local_id(1)* get_local_size(0) + get_local_id(0)) == 0)
 {
  # 372 "sharpness.cpp"
  *scalar = tmpa[0] + *scalar;
 }
}
#endif /* __GPUCODE__ */



# 372 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_375_parallel_region_1(__global long* gang_prv_red_sum_2, int height_5, __global short* pEdge_3, int width_5)
{
 
 local long sum_3[1];
 
 local long tmpr_2[256];
 
 # 374 "sharpness.cpp"
 long tmp_27;
 # 374 "sharpness.cpp"
 if ((get_local_id(1)* get_local_size(0) + get_local_id(0)) == 0)
 {
  # 374 "sharpness.cpp"
  sum_3[0] = 0;
 }
 # 374 "sharpness.cpp"
 barrier(CLK_LOCAL_MEM_FENCE);
 # 374 "sharpness.cpp"
 {
  # 372 "sharpness.cpp"
  int iter_per_gang_5;
  # 372 "sharpness.cpp"
  int first_gang_iter_5;
  # 372 "sharpness.cpp"
  int last_gang_iter_5;
  # 372 "sharpness.cpp"
  iter_per_gang_5 = ((1 + (height_5 * width_5 - 1) / 192) > 256 ? (1 + (height_5 * width_5 - 1) / 192) : 256);
  # 372 "sharpness.cpp"
  first_gang_iter_5 = get_group_id(0) * iter_per_gang_5;
  # 372 "sharpness.cpp"
  last_gang_iter_5 = ((first_gang_iter_5 + iter_per_gang_5 - 1) < (height_5 * width_5 - 1) ? (first_gang_iter_5 + iter_per_gang_5 - 1) : (height_5 * width_5 - 1));
  # 372 "sharpness.cpp"
  long sum_2;
  # 378 "sharpness.cpp"
  sum_2 = 0;
  # 378 "sharpness.cpp"
  int i_4;
  # 378 "sharpness.cpp"
  # 382 "sharpness.cpp"
  for (i_4 = first_gang_iter_5 + get_local_id(1) ; i_4 <= last_gang_iter_5 ; i_4 = i_4 + get_local_size(1))
  {
   # 378 "sharpness.cpp"
   int i_2;
   # 381 "sharpness.cpp"
   int j_2;
   # 383 "sharpness.cpp"
   j_2 = i_4 % width_5;
   # 383 "sharpness.cpp"
   i_2 = i_4 / width_5;
   # 383 "sharpness.cpp"
   sum_2 = sum_2 + (long ) (*(pEdge_3 + (i_2 * width_5 + j_2)));
  }
  # 372 "sharpness.cpp"
  # 372 "sharpness.cpp"
  sum_3[0] = (reduce_s64_add_y(sum_2, tmpr_2, sum_3[0]));
 }
 # 372 "sharpness.cpp"
 tmp_27 = sum_3[0];
 # 372 "sharpness.cpp"
 if (get_local_id(1) == 0)
 {
  # 372 "sharpness.cpp"
  *(gang_prv_red_sum_2 + get_group_id(0)) = tmp_27;
 }
 # 372 "sharpness.cpp"
 barrier(CLK_LOCAL_MEM_FENCE);
}
#endif /* __GPUCODE__ */



# 372 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_375_internal_1(cl_int width_64, cl_int height_34, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_11, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_long>  sum_4)
{
 # 372 "sharpness.cpp"
 hmpprt::DevicePtr<hmpprt::MS_OPENCL_SHARED,cl_long>  sum_1;
 # 372 "sharpness.cpp"
 cl_long tmp_28;
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->allocate((void **) &sum_1, hmpprt::MS_OPENCL_SHARED, 8);
 # 372 "sharpness.cpp"
 hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_long>  gang_prv_red_sum_1;
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->allocate((void **) &gang_prv_red_sum_1, hmpprt::MS_OPENCL_GLOB, 1536);
 # 372 "sharpness.cpp"
 hmpprt::DevicePtr<hmpprt::MS_OPENCL_SHARED,cl_long>  tmpr_3;
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->allocate((void **) &tmpr_3, hmpprt::MS_OPENCL_SHARED, 2048);
 # 372 "sharpness.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter(&gang_prv_red_sum_1, 8, "gang_prv_red_sum_2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_34), "height_5");
  __hmppcg_call.addLocalParameter(&pEdge_11, 8, "pEdge_3");
  __hmppcg_call.addSharedParameter(sum_1, "sum_3");
  __hmppcg_call.addSharedParameter(tmpr_3, "tmpr_2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_64), "width_5");
  __hmppcg_call.launch(hmpp_acc_region_main_375_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
 # 372 "sharpness.cpp"
 hmpprt::DevicePtr<hmpprt::MS_OPENCL_SHARED,cl_long>  tmpr_1;
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->allocate((void **) &tmpr_1, hmpprt::MS_OPENCL_SHARED, 2048);
 # 372 "sharpness.cpp"
 tmp_28 = 0;
 # 372 "sharpness.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(1);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(256);
  __hmppcg_call.setBlockSizeY(1);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter(&tmp_28, 8, "neutral");
  __hmppcg_call.addLocalParameter(&sum_4, 8, "scalar");
  __hmppcg_call.addSharedParameter(tmpr_1, "tmpa");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (192), "size");
  __hmppcg_call.addLocalParameter(&gang_prv_red_sum_1, 8, "array");
  __hmppcg_call.launch(reduce_s64_add_xy, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->free((void **) &gang_prv_red_sum_1);
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->free((void **) &sum_1);
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->free((void **) &tmpr_1);
 # 372 "sharpness.cpp"
 hmpprt::Context::getInstance()->free((void **) &tmpr_3);
}
#endif /* __GPUCODE__ */



# 372 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_375(cl_int width_46, cl_int height_23, cl_short* pEdge_7, cl_long* sum)
{
 # 391 "sharpness.cpp"
 (hmpp_acc_region_main_375_internal_1(width_46, height_23, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pEdge_7), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_long> (sum)));
}
#endif /* __GPUCODE__ */



# 391 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_411_parallel_region_1(double cutoff, double cutoff2, int height_4, double low, double order, double order2, __global short* pEdge_2, __global short* pError_1, __global short* pSharpness, double peak, int width_4, __global uchar* yPlaneCSER_1)
{
 # 393 "sharpness.cpp"
 {
  # 414 "sharpness.cpp"
  int iter_per_gang_4;
  # 414 "sharpness.cpp"
  int first_gang_iter_4;
  # 414 "sharpness.cpp"
  int last_gang_iter_4;
  # 414 "sharpness.cpp"
  iter_per_gang_4 = ((1 + (height_4 * width_4 - 1) / 192) > 256 ? (1 + (height_4 * width_4 - 1) / 192) : 256);
  # 414 "sharpness.cpp"
  first_gang_iter_4 = get_group_id(0) * iter_per_gang_4;
  # 414 "sharpness.cpp"
  last_gang_iter_4 = ((first_gang_iter_4 + iter_per_gang_4 - 1) < (height_4 * width_4 - 1) ? (first_gang_iter_4 + iter_per_gang_4 - 1) : (height_4 * width_4 - 1));
  # 414 "sharpness.cpp"
  int h_24;
  # 414 "sharpness.cpp"
  # 418 "sharpness.cpp"
  for (h_24 = first_gang_iter_4 + get_local_id(1) ; h_24 <= last_gang_iter_4 ; h_24 = h_24 + get_local_size(1))
  {
   # 419 "sharpness.cpp"
   short edge;
   # 414 "sharpness.cpp"
   int h_19;
   # 417 "sharpness.cpp"
   int w_19;
   # 419 "sharpness.cpp"
   w_19 = h_24 % width_4;
   # 419 "sharpness.cpp"
   h_19 = h_24 / width_4;
   # 419 "sharpness.cpp"
   edge = *(pEdge_2 + (h_19 * width_4 + w_19));
   # 420 "sharpness.cpp"
   double weight;
   # 420 "sharpness.cpp"
   weight = (double) 1. / ((double) 1. + pow((double ) (edge) / cutoff2, (double) 2. * order2));
   # 421 "sharpness.cpp"
   double strength;
   # 421 "sharpness.cpp"
   strength = (peak - low) * ((double) 1. - (double) 1. / ((double) 1. + pow((double ) (edge) / cutoff, (double) 2. * order)));
   # 422 "sharpness.cpp"
   strength = strength * weight + low;
   # 424 "sharpness.cpp"
   *(pSharpness + (h_19 * width_4 + w_19)) = (short ) (*(yPlaneCSER_1 + (h_19 * width_4 + w_19)));
   # 425 "sharpness.cpp"
   *(pSharpness + (h_19 * width_4 + w_19)) = *(pSharpness + (h_19 * width_4 + w_19)) + (double ) (*(pError_1 + (h_19 * width_4 + w_19))) * strength;
  }
  # 391 "sharpness.cpp"
 }
}
#endif /* __GPUCODE__ */



# 391 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_411_internal_1(cl_int width_63, cl_int height_33, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_33, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pError_5, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_10, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pSharpness_6, cl_double cutoff_2, cl_double peak_2, cl_double cutoff2_2, cl_double order_2, cl_double order2_2, cl_double low_2)
{
 # 391 "sharpness.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter(&cutoff_2, 8, "cutoff");
  __hmppcg_call.addLocalParameter(&cutoff2_2, 8, "cutoff2");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_33), "height_4");
  __hmppcg_call.addLocalParameter(&low_2, 8, "low");
  __hmppcg_call.addLocalParameter(&order_2, 8, "order");
  __hmppcg_call.addLocalParameter(&order2_2, 8, "order2");
  __hmppcg_call.addLocalParameter(&pEdge_10, 8, "pEdge_2");
  __hmppcg_call.addLocalParameter(&pError_5, 8, "pError_1");
  __hmppcg_call.addLocalParameter(&pSharpness_6, 8, "pSharpness");
  __hmppcg_call.addLocalParameter(&peak_2, 8, "peak");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_63), "width_4");
  __hmppcg_call.addLocalParameter(&yPlaneCSER_33, 8, "yPlaneCSER_1");
  __hmppcg_call.launch(hmpp_acc_region_main_411_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 391 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_411(cl_int width_45, cl_int height_22, cl_char* yPlaneCSER_16, cl_short* pError_3, cl_short* pEdge_6, cl_short* pSharpness_3, cl_double cutoff_1, cl_double peak_1, cl_double cutoff2_1, cl_double order_1, cl_double order2_1, cl_double low_1)
{
 # 433 "sharpness.cpp"
 (hmpp_acc_region_main_411_internal_1(width_45, height_22, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_16), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pError_3), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pEdge_6), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pSharpness_3), cutoff_1, peak_1, cutoff2_1, order_1, order2_1, low_1));
}
#endif /* __GPUCODE__ */



# 433 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_436_parallel_region_1(float cutoff3, int height_3, float low3, float order3, __global short* pEdge_1, __global short* pSharpness_2, float peak3, int width_3, __global uchar* yPlane_3)
{
 # 435 "sharpness.cpp"
 {
  # 439 "sharpness.cpp"
  int iter_per_gang_3;
  # 439 "sharpness.cpp"
  int first_gang_iter_3;
  # 439 "sharpness.cpp"
  int last_gang_iter_3;
  # 439 "sharpness.cpp"
  iter_per_gang_3 = ((1 + (height_3 * width_3 - 1) / 192) > 256 ? (1 + (height_3 * width_3 - 1) / 192) : 256);
  # 439 "sharpness.cpp"
  first_gang_iter_3 = get_group_id(0) * iter_per_gang_3;
  # 439 "sharpness.cpp"
  last_gang_iter_3 = ((first_gang_iter_3 + iter_per_gang_3 - 1) < (height_3 * width_3 - 1) ? (first_gang_iter_3 + iter_per_gang_3 - 1) : (height_3 * width_3 - 1));
  # 439 "sharpness.cpp"
  int h_25;
  # 439 "sharpness.cpp"
  # 443 "sharpness.cpp"
  for (h_25 = first_gang_iter_3 + get_local_id(1) ; h_25 <= last_gang_iter_3 ; h_25 = h_25 + get_local_size(1))
  {
   # 439 "sharpness.cpp"
   int h_20;
   # 442 "sharpness.cpp"
   int w_20;
   # 444 "sharpness.cpp"
   w_20 = h_25 % width_3;
   # 444 "sharpness.cpp"
   h_20 = h_25 / width_3;
   # 444 "sharpness.cpp"
   if (!(h_20 == 0 || h_20 == height_3 - 1 || w_20 == 0 || w_20 == width_3 - 1))
   {
    # 446 "sharpness.cpp"
    int enhanced;
    # 446 "sharpness.cpp"
    int maxValue;
    # 446 "sharpness.cpp"
    int minValue;
    # 447 "sharpness.cpp"
    double oscStrength;
    # 448 "sharpness.cpp"
    enhanced = (int ) (*(pSharpness_2 + (h_20 * width_3 + w_20)));
    # 450 "sharpness.cpp"
    maxValue = (int ) ( ((int ) ( ((int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) > (int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))) ? ( ((int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1))));
    # 451 "sharpness.cpp"
    maxValue = ( (maxValue > (int ) ( ((int ) ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) > (int ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))) ? maxValue : ((int ) ( ((int ) ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) > (int ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))));
    # 452 "sharpness.cpp"
    maxValue = ( (maxValue > (int ) ( ((int ) ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) > (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))) ? maxValue : ((int ) ( ((int ) ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) > (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))));
    # 454 "sharpness.cpp"
    minValue = (int ) ( ((int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) < (int ) ( ((int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) < (int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1))))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) : ( ((int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) < (int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))));
    # 455 "sharpness.cpp"
    minValue = ( (minValue < (int ) ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) < (int ) ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (int ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (int ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))))) ? minValue : ((int ) ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) < (int ) ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (int ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (int ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))))));
    # 456 "sharpness.cpp"
    minValue = ( (minValue < (int ) ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) < (int ) ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))))) ? minValue : ((int ) ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) < (int ) ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))))));
    # 460 "sharpness.cpp"
    double cutoff2Order;
    # 460 "sharpness.cpp"
    cutoff2Order = pow((double ) (cutoff3), (double ) ((float) 2. * order3));
    # 461 "sharpness.cpp"
    double edge2Order;
    # 461 "sharpness.cpp"
    edge2Order = pow((double ) (*(pEdge_1 + (h_20 * width_3 + w_20))), (double) 2. * (double ) (order3));
    # 462 "sharpness.cpp"
    oscStrength = ((double ) (peak3) * cutoff2Order + (double ) (low3) * edge2Order) / (cutoff2Order + edge2Order);
    # 466 "sharpness.cpp"
    if (enhanced > maxValue)
    {
     # 468 "sharpness.cpp"
     *(pSharpness_2 + (h_20 * width_3 + w_20)) = (short ) ( ((double ) (maxValue) + oscStrength * (double ) (enhanced - maxValue) < (double) 255.) ? ((double ) (maxValue) + oscStrength * (double ) (enhanced - maxValue)) : ((double) 255.));
    }
    else
    {
     # 470 "sharpness.cpp"
     if (enhanced < minValue)
     {
      # 472 "sharpness.cpp"
      *(pSharpness_2 + (h_20 * width_3 + w_20)) = (short ) ( ((double) 0. > (double ) (minValue) - oscStrength * (double ) (minValue - enhanced)) ? ((double) 0.) : ((double ) (minValue) - oscStrength * (double ) (minValue - enhanced)));
     }
     else
     {
      # 476 "sharpness.cpp"
      *(pSharpness_2 + (h_20 * width_3 + w_20)) = (short ) ( (( (enhanced > 0) ? enhanced : 0) < 255) ? ( (enhanced > 0) ? enhanced : 0) : 255);
     }
    }
   }
  }
  # 433 "sharpness.cpp"
 }
}
#endif /* __GPUCODE__ */



# 433 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_436_internal_1(cl_int width_62, cl_int height_32, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_13, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_9, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pSharpness_8, cl_float cutoff3_2, cl_float order3_2, cl_float peak3_2, cl_float low3_2)
{
 # 433 "sharpness.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter((float) (cutoff3_2), "cutoff3");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_32), "height_3");
  __hmppcg_call.addLocalParameter((float) (low3_2), "low3");
  __hmppcg_call.addLocalParameter((float) (order3_2), "order3");
  __hmppcg_call.addLocalParameter(&pEdge_9, 8, "pEdge_1");
  __hmppcg_call.addLocalParameter(&pSharpness_8, 8, "pSharpness_2");
  __hmppcg_call.addLocalParameter((float) (peak3_2), "peak3");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_62), "width_3");
  __hmppcg_call.addLocalParameter(&yPlane_13, 8, "yPlane_3");
  __hmppcg_call.launch(hmpp_acc_region_main_436_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 433 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_436(cl_int width_43, cl_int height_21, cl_char* yPlane_8, cl_short* pEdge_5, cl_short* pSharpness_5, cl_float cutoff3_1, cl_float order3_1, cl_float peak3_1, cl_float low3_1)
{
 # 486 "sharpness.cpp"
 (hmpp_acc_region_main_436_internal_1(width_43, height_21, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlane_8), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pEdge_5), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pSharpness_5), cutoff3_1, order3_1, peak3_1, low3_1));
}
#endif /* __GPUCODE__ */



# 486 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_490_parallel_region_1(int height_2, __global short* pSharpness_1, int width_2, __global uchar* yPlane_2)
{
 # 488 "sharpness.cpp"
 {
  # 493 "sharpness.cpp"
  int iter_per_gang_2;
  # 493 "sharpness.cpp"
  int first_gang_iter_2;
  # 493 "sharpness.cpp"
  int last_gang_iter_2;
  # 493 "sharpness.cpp"
  iter_per_gang_2 = ((1 + (height_2 * width_2 - 1) / 192) > 256 ? (1 + (height_2 * width_2 - 1) / 192) : 256);
  # 493 "sharpness.cpp"
  first_gang_iter_2 = get_group_id(0) * iter_per_gang_2;
  # 493 "sharpness.cpp"
  last_gang_iter_2 = ((first_gang_iter_2 + iter_per_gang_2 - 1) < (height_2 * width_2 - 1) ? (first_gang_iter_2 + iter_per_gang_2 - 1) : (height_2 * width_2 - 1));
  # 493 "sharpness.cpp"
  int h_26;
  # 493 "sharpness.cpp"
  # 497 "sharpness.cpp"
  for (h_26 = first_gang_iter_2 + get_local_id(1) ; h_26 <= last_gang_iter_2 ; h_26 = h_26 + get_local_size(1))
  {
   # 493 "sharpness.cpp"
   int h_21;
   # 496 "sharpness.cpp"
   int w_21;
   # 498 "sharpness.cpp"
   w_21 = h_26 % width_2;
   # 498 "sharpness.cpp"
   h_21 = h_26 / width_2;
   # 498 "sharpness.cpp"
   *(yPlane_2 + (h_21 * width_2 + w_21)) = (uchar ) ( ((int ) (*(pSharpness_1 + (h_21 * width_2 + w_21))) > 255) ? 255 : ( ((int ) (*(pSharpness_1 + (h_21 * width_2 + w_21))) < 0) ? 0 : ((int ) (*(pSharpness_1 + (h_21 * width_2 + w_21))))));
  }
  # 486 "sharpness.cpp"
 }
}
#endif /* __GPUCODE__ */



# 486 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_490_internal_1(cl_int width_61, cl_int height_31, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_12, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pSharpness_7)
{
 # 486 "sharpness.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_31), "height_2");
  __hmppcg_call.addLocalParameter(&pSharpness_7, 8, "pSharpness_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_61), "width_2");
  __hmppcg_call.addLocalParameter(&yPlane_12, 8, "yPlane_2");
  __hmppcg_call.launch(hmpp_acc_region_main_490_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 486 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_490(cl_int width_34, cl_int height_20, cl_char* yPlane_7, cl_short* pSharpness_4)
{
 # 23 "sharpness.cpp"
 (hmpp_acc_region_main_490_internal_1(width_34, height_20, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlane_7), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pSharpness_4)));
}
#endif /* __GPUCODE__ */



# 23 "sharpness.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_84_parallel_region_1(int height_1, int quarterWidth_1, int width_1, __global uchar* yPlaneDown_1, __global uchar* yPlane_1)
{
 # 25 "sharpness.cpp"
 {
  # 87 "sharpness.cpp"
  int iter_per_gang_1;
  # 87 "sharpness.cpp"
  int first_gang_iter_1;
  # 87 "sharpness.cpp"
  int last_gang_iter_1;
  # 87 "sharpness.cpp"
  iter_per_gang_1 = ((1 + ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1) / 192) > 256 ? (1 + ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1) / 192) : 256);
  # 87 "sharpness.cpp"
  first_gang_iter_1 = get_group_id(0) * iter_per_gang_1;
  # 87 "sharpness.cpp"
  last_gang_iter_1 = ((first_gang_iter_1 + iter_per_gang_1 - 1) < ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1) ? (first_gang_iter_1 + iter_per_gang_1 - 1) : ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1));
  # 87 "sharpness.cpp"
  int i_5;
  # 87 "sharpness.cpp"
  # 91 "sharpness.cpp"
  for (i_5 = first_gang_iter_1 + get_local_id(1) ; i_5 <= last_gang_iter_1 ; i_5 = i_5 + get_local_size(1))
  {
   # 87 "sharpness.cpp"
   uchar tbt_1;
   # 87 "sharpness.cpp"
   int tbt_2;
   # 87 "sharpness.cpp"
   int tbt_3;
   # 87 "sharpness.cpp"
   int i_3;
   # 90 "sharpness.cpp"
   int j_3;
   # 92 "sharpness.cpp"
   j_3 = i_5 % ((width_1 + 3) / 4);
   # 92 "sharpness.cpp"
   i_3 = i_5 / ((width_1 + 3) / 4);
   # 92 "sharpness.cpp"
   tbt_1 = *(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4 + 3));
   # 92 "sharpness.cpp"
   tbt_2 = (int ) (*(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4 + 2)));
   # 92 "sharpness.cpp"
   tbt_3 = (int ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4))) + (int ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4 + 1))) + (int ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4 + 2))) + (int ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4 + 3))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4 + 1)));
   # 92 "sharpness.cpp"
   *(yPlaneDown_1 + (i_3 * 4 / 4 * quarterWidth_1 + j_3 * 4 / 4)) = (uchar ) (tbt_3 + tbt_2 + (int ) (tbt_1) + (int ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4 + 1))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4 + 2))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4 + 3))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4 + 1))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4 + 2))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4 + 3))) + 8 >> 4);
  }
  # 23 "sharpness.cpp"
 }
}
#endif /* __GPUCODE__ */



# 23 "sharpness.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_84_internal_1(cl_int width_60, cl_int height_30, cl_int quarterWidth_23, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_11, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_15)
{
 # 23 "sharpness.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_30), "height_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_23), "quarterWidth_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_60), "width_1");
  __hmppcg_call.addLocalParameter(&yPlaneDown_15, 8, "yPlaneDown_1");
  __hmppcg_call.addLocalParameter(&yPlane_11, 8, "yPlane_1");
  __hmppcg_call.launch(hmpp_acc_region_main_84_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 23 "sharpness.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_84(cl_int width_32, cl_int height_16, cl_int quarterWidth_9, cl_char* yPlane_6, cl_char* yPlaneDown_7)
{
 # 1 "<preprocessor>"
 (hmpp_acc_region_main_84_internal_1(width_32, height_16, quarterWidth_9, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlane_6), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneDown_7)));
}
#endif /* __GPUCODE__ */



# 1 "<preprocessor>"

#ifdef __GPUCODE__
long reduce_s64_add_y(long priv, local long* tmpa_1, long orig)
{
 # 1 "<preprocessor>"
 barrier(CLK_LOCAL_MEM_FENCE);
 # 1 "<preprocessor>"
 tmpa_1[get_local_id(1) + get_local_size(1) * get_local_id(0)] = priv;
 # 1 "<preprocessor>"
 int n;
 # 1 "<preprocessor>"
 # 1 "<preprocessor>"
 for (n = (get_local_size(1) - 1 >> 1) + 1 ; n > 0 ; n = (n >> 1))
 {
  # 1 "<preprocessor>"
  int next;
  # 1 "<preprocessor>"
  next = get_local_id(1) + n;
  # 1 "<preprocessor>"
  barrier(CLK_LOCAL_MEM_FENCE);
  # 1 "<preprocessor>"
  if (get_local_id(1) < n && next < get_local_size(1))
  {
   # 1 "<preprocessor>"
   tmpa_1[get_local_id(1) + get_local_size(1) * get_local_id(0)] = tmpa_1[get_local_id(1) + get_local_size(1) * get_local_id(0)] + tmpa_1[next + get_local_size(1) * get_local_id(0)];
  }
 }
 # 1 "<preprocessor>"
 # 1 "<preprocessor>"
 barrier(CLK_LOCAL_MEM_FENCE);
 # 1 "<preprocessor>"
 return tmpa_1[get_local_size(1) * get_local_id(0)] + orig;
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
      hmpp_acc_region_main_107_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_107_parallel_region_1");
      hmpp_acc_region_main_119_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_119_parallel_region_1");
      hmpp_acc_region_main_140_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_140_loop1D_1");
      hmpp_acc_region_main_152_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_152_loop1D_1");
      hmpp_acc_region_main_164_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_164_loop1D_1");
      hmpp_acc_region_main_185_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_185_loop1D_1");
      hmpp_acc_region_main_197_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_197_loop1D_1");
      hmpp_acc_region_main_209_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_209_loop1D_1");
      hmpp_acc_region_main_230_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_230_loop1D_1");
      hmpp_acc_region_main_242_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_242_loop1D_1");
      hmpp_acc_region_main_254_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_254_loop1D_1");
      hmpp_acc_region_main_277_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_277_loop1D_1");
      hmpp_acc_region_main_289_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_289_loop1D_1");
      hmpp_acc_region_main_326_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_326_parallel_region_1");
      hmpp_acc_region_main_346_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_346_parallel_region_1");
      reduce_s64_add_xy = new hmpprt::OpenCLGrid(hmpprt_module, "reduce_s64_add_xy");
      hmpp_acc_region_main_375_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_375_parallel_region_1");
      hmpp_acc_region_main_411_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_411_parallel_region_1");
      hmpp_acc_region_main_436_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_436_parallel_region_1");
      hmpp_acc_region_main_490_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_490_parallel_region_1");
      hmpp_acc_region_main_84_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_84_parallel_region_1");

    }
    hmpprt::Context::getInstance()->getGrouplet()->setTarget(hmpprt::OPENCL);
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_107", "prototype hmpp_acc_region_main_107(width: s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^openclglob u8, yPlaneDown: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_119", "prototype hmpp_acc_region_main_119(width: s32, quarterHeight: s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_140", "prototype hmpp_acc_region_main_140(width: ^host s32, height: s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_152", "prototype hmpp_acc_region_main_152(width: ^host s32, quarterWidth: s32, yPlaneCSER: ^openclglob u8, yPlaneDown: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_164", "prototype hmpp_acc_region_main_164(width: ^host s32, quarterWidth: s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_185", "prototype hmpp_acc_region_main_185(width: ^host s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_197", "prototype hmpp_acc_region_main_197(width: ^host s32, height: ^host s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^openclglob u8, yPlaneDown: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_209", "prototype hmpp_acc_region_main_209(width: ^host s32, height: ^host s32, quarterWidth: s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_230", "prototype hmpp_acc_region_main_230(width: ^host s32, height: ^host s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_242", "prototype hmpp_acc_region_main_242(width: ^host s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^openclglob u8, yPlaneDown: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_254", "prototype hmpp_acc_region_main_254(width: ^host s32, quarterHeight: s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_277", "prototype hmpp_acc_region_main_277(width: ^host s32, height: s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_289", "prototype hmpp_acc_region_main_289(width: ^host s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^openclglob u8, yPlaneDown: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_326", "prototype hmpp_acc_region_main_326(width: s32, height: s32, yPlane: ^openclglob u8, yPlaneCSER: ^openclglob u8, pError: ^openclglob s16)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_346", "prototype hmpp_acc_region_main_346(width: s32, height: s32, yPlane: ^openclglob u8, pEdge: ^openclglob s16)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_375", "prototype hmpp_acc_region_main_375(width: s32, height: s32, pEdge: ^openclglob s16, sum: ^openclglob s64)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_411", "prototype hmpp_acc_region_main_411(width: s32, height: s32, yPlaneCSER: ^openclglob u8, pError: ^openclglob s16, pEdge: ^openclglob s16, pSharpness: ^openclglob s16, cutoff: double, peak: double, cutoff2: double, order: double, order2: double, low: double)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_436", "prototype hmpp_acc_region_main_436(width: s32, height: s32, yPlane: ^openclglob u8, pEdge: ^openclglob s16, pSharpness: ^openclglob s16, cutoff3: float, order3: float, peak3: float, low3: float)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_490", "prototype hmpp_acc_region_main_490(width: s32, height: s32, yPlane: ^openclglob u8, pSharpness: ^openclglob s16)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_84", "prototype hmpp_acc_region_main_84(width: s32, height: s32, quarterWidth: s32, yPlane: ^openclglob u8, yPlaneDown: ^openclglob u8)");

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
      delete hmpp_acc_region_main_107_parallel_region_1;
      delete hmpp_acc_region_main_119_parallel_region_1;
      delete hmpp_acc_region_main_140_loop1D_1;
      delete hmpp_acc_region_main_152_loop1D_1;
      delete hmpp_acc_region_main_164_loop1D_1;
      delete hmpp_acc_region_main_185_loop1D_1;
      delete hmpp_acc_region_main_197_loop1D_1;
      delete hmpp_acc_region_main_209_loop1D_1;
      delete hmpp_acc_region_main_230_loop1D_1;
      delete hmpp_acc_region_main_242_loop1D_1;
      delete hmpp_acc_region_main_254_loop1D_1;
      delete hmpp_acc_region_main_277_loop1D_1;
      delete hmpp_acc_region_main_289_loop1D_1;
      delete hmpp_acc_region_main_326_parallel_region_1;
      delete hmpp_acc_region_main_346_parallel_region_1;
      delete reduce_s64_add_xy;
      delete hmpp_acc_region_main_375_parallel_region_1;
      delete hmpp_acc_region_main_411_parallel_region_1;
      delete hmpp_acc_region_main_436_parallel_region_1;
      delete hmpp_acc_region_main_490_parallel_region_1;
      delete hmpp_acc_region_main_84_parallel_region_1;

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
