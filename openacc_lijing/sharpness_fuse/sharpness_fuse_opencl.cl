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

# 23 "sharpness_fuse.cpp"

#ifdef __GPUCODE__
long reduce_s64_add_y(long priv, local long* tmpa_1, long orig)
;
#endif /* __GPUCODE__ */



# 23 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_82(cl_int width_32, cl_int height_16, cl_int quarterWidth_9, cl_char* yPlane_6, cl_char* yPlaneDown_7)
;
#endif /* __GPUCODE__ */



# 23 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_82_internal_1(cl_int width_60, cl_int height_30, cl_int quarterWidth_23, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_11, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_15)
;
#endif /* __GPUCODE__ */



# 458 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_82_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_82_parallel_region_1(int height_1, int quarterWidth_1, int width_1, __global uchar* yPlaneDown_1, __global uchar* yPlane_1);
#endif // __GPUCODE__
# 458 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_462(cl_int width_34, cl_int height_20, cl_char* yPlane_7, cl_short* pSharpness_4)
;
#endif /* __GPUCODE__ */



# 458 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_462_internal_1(cl_int width_61, cl_int height_31, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_12, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pSharpness_8)
;
#endif /* __GPUCODE__ */



# 417 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_462_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_462_parallel_region_1(int height_2, __global short* pSharpness_1, int width_2, __global uchar* yPlane_2);
#endif // __GPUCODE__
# 417 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_408(cl_int width_43, cl_int height_21, cl_char* yPlane_8, cl_short* pEdge_5, cl_short* pSharpness_2, cl_float cutoff3_1, cl_float order3_1, cl_float peak3, cl_float low3_1)
;
#endif /* __GPUCODE__ */



# 417 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_408_internal_1(cl_int width_62, cl_int height_32, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_13, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_9, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pSharpness_6, cl_float cutoff3_2, cl_float order3_2, cl_float peak3_2, cl_float low3_2)
;
#endif /* __GPUCODE__ */



# 392 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_408_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_408_parallel_region_1(float cutoff3, int height_3, float low3, float order3, __global short* pEdge_1, __global short* pSharpness_5, float peak3_1, int width_3, __global uchar* yPlane_3);
#endif // __GPUCODE__
# 392 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_389(cl_int width_45, cl_int height_22, cl_char* yPlaneCSER_16, cl_short* pError_3, cl_short* pEdge_6, cl_short* pSharpness_3, cl_double cutoff_1, cl_double peak_1, cl_double cutoff2_1, cl_double order_1, cl_double order2_1, cl_double low_1)
;
#endif /* __GPUCODE__ */



# 392 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_389_internal_1(cl_int width_63, cl_int height_33, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_35, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pError_5, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_10, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pSharpness_7, cl_double cutoff_2, cl_double peak_2, cl_double cutoff2_2, cl_double order_2, cl_double order2_2, cl_double low_2)
;
#endif /* __GPUCODE__ */



# 361 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_389_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_389_parallel_region_1(double cutoff, double cutoff2, int height_4, double low, double order, double order2, __global short* pEdge_2, __global short* pError_1, __global short* pSharpness, double peak, int width_4, __global uchar* yPlaneCSER_1);
#endif // __GPUCODE__
# 361 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_376(cl_int width_46, cl_int height_23, cl_char* yPlane_9, cl_char* yPlaneCSER_22, cl_short* pError_2)
;
#endif /* __GPUCODE__ */



# 361 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_376_internal_1(cl_int width_64, cl_int height_34, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_14, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_37, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pError_4)
;
#endif /* __GPUCODE__ */



# 342 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_376_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_376_parallel_region_1(int height_5, __global short* pError, int width_5, __global uchar* yPlaneCSER_2, __global uchar* yPlane_4);
#endif // __GPUCODE__
# 342 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_339(cl_int width_47, cl_int height_24, cl_short* pEdge_7, cl_long* sum)
;
#endif /* __GPUCODE__ */



# 342 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_339_internal_1(cl_int width_65, cl_int height_35, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_11, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_long>  sum_4)
;
#endif /* __GPUCODE__ */



# 313 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_339_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_339_parallel_region_1(__global long* gang_prv_red_sum_1, int height_6, __global short* pEdge_3, int width_6);
#endif // __GPUCODE__
# 313 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * reduce_s64_add_xy = 0;
#else
__kernel  void reduce_s64_add_xy(long neutral, __global long* scalar, int size, __global long* array);
#endif // __GPUCODE__
# 313 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_316(cl_int width_48, cl_int height_25, cl_char* yPlane_5, cl_short* pEdge_4)
;
#endif /* __GPUCODE__ */



# 313 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_316_internal_1(cl_int width_66, cl_int height_36, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_10, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_8)
;
#endif /* __GPUCODE__ */



# 279 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_316_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_316_parallel_region_1(int height_7, __global short* pEdge, int width_7, __global uchar* yPlane);
#endif // __GPUCODE__
# 279 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_279(cl_int* width_67, cl_int quarterWidth_10, cl_int quarterHeight_7, cl_char* yPlaneCSER_23, cl_char* yPlaneDown_16)
;
#endif /* __GPUCODE__ */



# 279 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_279_internal_1(cl_int* width_8, cl_int quarterWidth_17, cl_int quarterHeight_15, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_38, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_8)
;
#endif /* __GPUCODE__ */



# 267 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_279_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_279_loop1D_1(int quarterWidth_2, int quarterHeight_1, __global uchar* yPlaneCSER_3, __global uchar* yPlaneDown_2, int width_30);
#endif // __GPUCODE__
# 267 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_267(cl_int* width_9, cl_int height_8, cl_char* yPlaneCSER_4)
;
#endif /* __GPUCODE__ */



# 267 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_267_internal_1(cl_int* width_68, cl_int height_37, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_44)
;
#endif /* __GPUCODE__ */



# 244 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_267_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_267_loop1D_1(int width_42, int height_26, __global uchar* yPlaneCSER_24);
#endif // __GPUCODE__
# 244 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_244(cl_int* width_10, cl_int quarterHeight_8, cl_char* yPlaneCSER_25)
;
#endif /* __GPUCODE__ */



# 244 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_244_internal_1(cl_int* width_50, cl_int quarterHeight_16, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_39)
;
#endif /* __GPUCODE__ */



# 238 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_244_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_244_loop1D_1(int quarterHeight_2, __global uchar* yPlaneCSER_5, int width_28);
#endif // __GPUCODE__
# 238 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_232(cl_int* width_51, cl_int quarterWidth_3, cl_int quarterHeight_9, cl_char* yPlaneCSER_26, cl_char* yPlaneDown_9)
;
#endif /* __GPUCODE__ */



# 238 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_232_internal_1(cl_int* width_11, cl_int quarterWidth_21, cl_int quarterHeight_17, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_40, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_17)
;
#endif /* __GPUCODE__ */



# 223 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_232_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_232_loop1D_1(int quarterWidth_11, int quarterHeight_3, __global uchar* yPlaneCSER_6, __global uchar* yPlaneDown_3, int width_27);
#endif // __GPUCODE__
# 223 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_220(cl_int* width_12, cl_int* height_9, cl_char* yPlaneCSER_27)
;
#endif /* __GPUCODE__ */



# 223 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_220_internal_1(cl_int* width_52, cl_int* height_38, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_41)
;
#endif /* __GPUCODE__ */



# 216 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_220_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_220_loop1D_1(__global uchar* yPlaneCSER_7, int width_26, int height_14);
#endif // __GPUCODE__
# 216 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_211(cl_int* width_13, cl_char* yPlaneCSER_28)
;
#endif /* __GPUCODE__ */



# 216 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_211_internal_1(cl_int* width_53, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_42)
;
#endif /* __GPUCODE__ */



# 193 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_211_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_211_loop1D_1(__global uchar* yPlaneCSER_8, int width_25);
#endif // __GPUCODE__
# 193 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_189(cl_int* width_54, cl_int* height_28, cl_int quarterWidth_12, cl_char* yPlaneCSER_29)
;
#endif /* __GPUCODE__ */



# 193 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_189_internal_1(cl_int* width_14, cl_int* height_10, cl_int quarterWidth_18, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_43)
;
#endif /* __GPUCODE__ */



# 177 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_189_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_189_loop1D_1(int quarterWidth_4, __global uchar* yPlaneCSER_9, int width_24, int height_13);
#endif // __GPUCODE__
# 177 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_172(cl_int* width_55, cl_int quarterWidth_13, cl_char* yPlaneCSER_31)
;
#endif /* __GPUCODE__ */



# 177 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_172_internal_1(cl_int* width_15, cl_int quarterWidth_19, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_10)
;
#endif /* __GPUCODE__ */



# 163 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_172_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_172_loop1D_1(int quarterWidth_5, __global uchar* yPlaneCSER_17);
#endif // __GPUCODE__
# 163 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_159(cl_int* width_56, cl_int* height_29, cl_int quarterWidth_14, cl_int quarterHeight_13, cl_char* yPlaneCSER_36, cl_char* yPlaneDown_13)
;
#endif /* __GPUCODE__ */



# 163 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_159_internal_1(cl_int* width_16, cl_int* height_11, cl_int quarterWidth_20, cl_int quarterHeight_10, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_18, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_4)
;
#endif /* __GPUCODE__ */



# 150 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_159_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_159_loop1D_1(int width_22, int height_12, int quarterWidth_6, int quarterHeight_4, __global uchar* yPlaneCSER_11, __global uchar* yPlaneDown_10);
#endif // __GPUCODE__
# 150 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_151(cl_int* width_57, cl_int quarterWidth_22, cl_char* yPlaneCSER_32, cl_char* yPlaneDown_14)
;
#endif /* __GPUCODE__ */



# 150 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_151_internal_1(cl_int* width_17, cl_int quarterWidth_7, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_12, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_5)
;
#endif /* __GPUCODE__ */



# 138 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_151_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_151_loop1D_1(int quarterWidth_15, __global uchar* yPlaneCSER_19, __global uchar* yPlaneDown_11);
#endif // __GPUCODE__
# 138 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_138(cl_int* width_18, cl_int height, cl_char* yPlaneCSER_13)
;
#endif /* __GPUCODE__ */



# 138 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_138_internal_1(cl_int* width_58, cl_int height_27, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_33)
;
#endif /* __GPUCODE__ */



# 117 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_138_loop1D_1 = 0;
#else
__kernel  void hmpp_acc_region_main_138_loop1D_1(int width_35, int height_15, __global uchar* yPlaneCSER_20);
#endif // __GPUCODE__
# 117 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_117(cl_int width_19, cl_int quarterHeight_5, cl_char* yPlaneCSER_34)
;
#endif /* __GPUCODE__ */



# 117 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_117_internal_1(cl_int width_59, cl_int quarterHeight_14, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_14)
;
#endif /* __GPUCODE__ */



# 101 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_117_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_117_parallel_region_1(int quarterHeight_11, int width_33, __global uchar* yPlaneCSER_21);
#endif // __GPUCODE__
# 101 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_105(cl_int width, cl_int quarterWidth, cl_int quarterHeight_12, cl_char* yPlaneCSER_30, cl_char* yPlaneDown)
;
#endif /* __GPUCODE__ */



# 101 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_105_internal_1(cl_int width_49, cl_int quarterWidth_16, cl_int quarterHeight, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_12)
;
#endif /* __GPUCODE__ */



# 101 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_main_105_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_main_105_parallel_region_1(int quarterHeight_6, int quarterWidth_8, int width_31, __global uchar* yPlaneCSER_15, __global uchar* yPlaneDown_6);
#endif // __GPUCODE__
# 101 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_105_parallel_region_1(int quarterHeight_6, int quarterWidth_8, int width_31, __global uchar* yPlaneCSER_15, __global uchar* yPlaneDown_6)
{
 # 103 "sharpness_fuse.cpp"
 {
  # 108 "sharpness_fuse.cpp"
  int iter_per_gang_9;
  # 108 "sharpness_fuse.cpp"
  int first_gang_iter_9;
  # 108 "sharpness_fuse.cpp"
  int last_gang_iter_9;
  # 108 "sharpness_fuse.cpp"
  iter_per_gang_9 = ((1 + (quarterHeight_6 - 1) / 192) > 256 ? (1 + (quarterHeight_6 - 1) / 192) : 256);
  # 108 "sharpness_fuse.cpp"
  first_gang_iter_9 = get_group_id(0) * iter_per_gang_9;
  # 108 "sharpness_fuse.cpp"
  last_gang_iter_9 = ((first_gang_iter_9 + iter_per_gang_9 - 1) < (quarterHeight_6 - 1) ? (first_gang_iter_9 + iter_per_gang_9 - 1) : (quarterHeight_6 - 1));
  # 108 "sharpness_fuse.cpp"
  int h_11;
  # 108 "sharpness_fuse.cpp"
  # 109 "sharpness_fuse.cpp"
  for (h_11 = first_gang_iter_9 + get_local_id(1) ; h_11 <= last_gang_iter_9 ; h_11 = h_11 + get_local_size(1))
  {
   # 110 "sharpness_fuse.cpp"
   *(yPlaneCSER_15 + h_11 * 4 * width_31) = *(yPlaneDown_6 + h_11 * quarterWidth_8);
  }
  # 101 "sharpness_fuse.cpp"
 }
}
#endif /* __GPUCODE__ */



# 101 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_105_internal_1(cl_int width_49, cl_int quarterWidth_16, cl_int quarterHeight, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_12)
{
 # 101 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight), "quarterHeight_6");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_16), "quarterWidth_8");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_49), "width_31");
  __hmppcg_call.addLocalParameter(&yPlaneCSER, 8, "yPlaneCSER_15");
  __hmppcg_call.addLocalParameter(&yPlaneDown_12, 8, "yPlaneDown_6");
  __hmppcg_call.launch(hmpp_acc_region_main_105_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 101 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_105(cl_int width, cl_int quarterWidth, cl_int quarterHeight_12, cl_char* yPlaneCSER_30, cl_char* yPlaneDown)
{
 # 117 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_105_internal_1(width, quarterWidth, quarterHeight_12, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_30), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneDown)));
}
#endif /* __GPUCODE__ */



# 117 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_117_parallel_region_1(int quarterHeight_11, int width_33, __global uchar* yPlaneCSER_21)
{
 # 119 "sharpness_fuse.cpp"
 {
  # 120 "sharpness_fuse.cpp"
  int iter_per_gang_8;
  # 120 "sharpness_fuse.cpp"
  int first_gang_iter_8;
  # 120 "sharpness_fuse.cpp"
  int last_gang_iter_8;
  # 120 "sharpness_fuse.cpp"
  iter_per_gang_8 = ((1 + (quarterHeight_11 - 1) / 192) > 256 ? (1 + (quarterHeight_11 - 1) / 192) : 256);
  # 120 "sharpness_fuse.cpp"
  first_gang_iter_8 = get_group_id(0) * iter_per_gang_8;
  # 120 "sharpness_fuse.cpp"
  last_gang_iter_8 = ((first_gang_iter_8 + iter_per_gang_8 - 1) < (quarterHeight_11 - 1) ? (first_gang_iter_8 + iter_per_gang_8 - 1) : (quarterHeight_11 - 1));
  # 120 "sharpness_fuse.cpp"
  int h_12;
  # 120 "sharpness_fuse.cpp"
  # 121 "sharpness_fuse.cpp"
  for (h_12 = first_gang_iter_8 + get_local_id(1) ; h_12 <= last_gang_iter_8 ; h_12 = h_12 + get_local_size(1))
  {
   # 122 "sharpness_fuse.cpp"
   if (h_12 < quarterHeight_11 - 1)
   {
    # 124 "sharpness_fuse.cpp"
    *(yPlaneCSER_21 + (h_12 * 4 + 1) * width_33) = (uchar ) (((int ) (*(yPlaneCSER_21 + h_12 * 4 * width_33)) * 3 + (int ) (*(yPlaneCSER_21 + (h_12 * 4 + 4) * width_33))) / 4);
    # 125 "sharpness_fuse.cpp"
    *(yPlaneCSER_21 + (h_12 * 4 + 2) * width_33) = (uchar ) (((int ) (*(yPlaneCSER_21 + h_12 * 4 * width_33)) * 2 + (int ) (*(yPlaneCSER_21 + (h_12 * 4 + 4) * width_33)) * 2) / 4);
    # 126 "sharpness_fuse.cpp"
    *(yPlaneCSER_21 + (h_12 * 4 + 3) * width_33) = (uchar ) (((int ) (*(yPlaneCSER_21 + h_12 * 4 * width_33)) + (int ) (*(yPlaneCSER_21 + (h_12 * 4 + 4) * width_33)) * 3) / 4);
   }
   else
   {
    # 130 "sharpness_fuse.cpp"
    *(yPlaneCSER_21 + (h_12 * 4 + 1) * width_33) = *(yPlaneCSER_21 + h_12 * 4 * width_33);
   }
  }
  # 117 "sharpness_fuse.cpp"
 }
}
#endif /* __GPUCODE__ */



# 117 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_117_internal_1(cl_int width_59, cl_int quarterHeight_14, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_14)
{
 # 117 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_14), "quarterHeight_11");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_59), "width_33");
  __hmppcg_call.addLocalParameter(&yPlaneCSER_14, 8, "yPlaneCSER_21");
  __hmppcg_call.launch(hmpp_acc_region_main_117_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 117 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_117(cl_int width_19, cl_int quarterHeight_5, cl_char* yPlaneCSER_34)
{
 # 138 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_117_internal_1(width_19, quarterHeight_5, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_34)));
}
#endif /* __GPUCODE__ */



# 138 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_138_loop1D_1(int width_35, int height_15, __global uchar* yPlaneCSER_20)
{
 # 141 "sharpness_fuse.cpp"
 int h_13;
 # 143 "sharpness_fuse.cpp"
 h_13 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 143 "sharpness_fuse.cpp"
 if (h_13 > height_15 - 1)
 {
  # 143 "sharpness_fuse.cpp"
  goto __hmppcg_label_1;
 }
 # 143 "sharpness_fuse.cpp"
 *(yPlaneCSER_20 + (h_13 * width_35 + 1)) = *(yPlaneCSER_20 + h_13 * width_35);
 # 138 "sharpness_fuse.cpp"
 __hmppcg_label_1:;
}
#endif /* __GPUCODE__ */



# 138 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_138_internal_1(cl_int* width_58, cl_int height_27, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_33)
{
 # 140 "sharpness_fuse.cpp"
 cl_int width_20;
 # 140 "sharpness_fuse.cpp"
 width_20 = *width_58;
 # 140 "sharpness_fuse.cpp"
 {
  # 138 "sharpness_fuse.cpp"
  if (height_27 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((height_27 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_20), "width_35");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_27), "height_15");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_33, 8, "yPlaneCSER_20");
   __hmppcg_call.launch(hmpp_acc_region_main_138_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 138 "sharpness_fuse.cpp"
 *width_58 = width_20;
}
#endif /* __GPUCODE__ */



# 138 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_138(cl_int* width_18, cl_int height, cl_char* yPlaneCSER_13)
{
 # 150 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_138_internal_1(width_18, height, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_13)));
}
#endif /* __GPUCODE__ */



# 150 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_151_loop1D_1(int quarterWidth_15, __global uchar* yPlaneCSER_19, __global uchar* yPlaneDown_11)
{
 # 154 "sharpness_fuse.cpp"
 int w_11;
 # 156 "sharpness_fuse.cpp"
 w_11 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 156 "sharpness_fuse.cpp"
 if (w_11 > quarterWidth_15 - 1)
 {
  # 156 "sharpness_fuse.cpp"
  goto __hmppcg_label_2;
 }
 # 156 "sharpness_fuse.cpp"
 *(yPlaneCSER_19 + w_11 * 4) = *(yPlaneDown_11 + w_11);
 # 150 "sharpness_fuse.cpp"
 __hmppcg_label_2:;
}
#endif /* __GPUCODE__ */



# 150 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_151_internal_1(cl_int* width_17, cl_int quarterWidth_7, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_12, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_5)
{
 # 152 "sharpness_fuse.cpp"
 cl_int width_21;
 # 152 "sharpness_fuse.cpp"
 width_21 = *width_17;
 # 152 "sharpness_fuse.cpp"
 {
  # 150 "sharpness_fuse.cpp"
  if (quarterWidth_7 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_7 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_7), "quarterWidth_15");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_12, 8, "yPlaneCSER_19");
   __hmppcg_call.addLocalParameter(&yPlaneDown_5, 8, "yPlaneDown_11");
   __hmppcg_call.launch(hmpp_acc_region_main_151_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 150 "sharpness_fuse.cpp"
 *width_17 = width_21;
}
#endif /* __GPUCODE__ */



# 150 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_151(cl_int* width_57, cl_int quarterWidth_22, cl_char* yPlaneCSER_32, cl_char* yPlaneDown_14)
{
 # 163 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_151_internal_1(width_57, quarterWidth_22, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_32), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneDown_14)));
}
#endif /* __GPUCODE__ */



# 163 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_159_loop1D_1(int width_22, int height_12, int quarterWidth_6, int quarterHeight_4, __global uchar* yPlaneCSER_11, __global uchar* yPlaneDown_10)
{
 # 168 "sharpness_fuse.cpp"
 int w_12;
 # 170 "sharpness_fuse.cpp"
 w_12 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 170 "sharpness_fuse.cpp"
 if (w_12 > quarterWidth_6 - 1)
 {
  # 170 "sharpness_fuse.cpp"
  goto __hmppcg_label_3;
 }
 # 170 "sharpness_fuse.cpp"
 *(yPlaneCSER_11 + ((height_12 - 2) * width_22 + w_12 * 4)) = *(yPlaneDown_10 + ((quarterHeight_4 - 1) * quarterWidth_6 + w_12));
 # 163 "sharpness_fuse.cpp"
 __hmppcg_label_3:;
}
#endif /* __GPUCODE__ */



# 163 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_159_internal_1(cl_int* width_16, cl_int* height_11, cl_int quarterWidth_20, cl_int quarterHeight_10, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_18, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_4)
{
 # 165 "sharpness_fuse.cpp"
 cl_int height_17;
 # 165 "sharpness_fuse.cpp"
 height_17 = *height_11;
 # 165 "sharpness_fuse.cpp"
 cl_int width_36;
 # 165 "sharpness_fuse.cpp"
 width_36 = *width_16;
 # 165 "sharpness_fuse.cpp"
 {
  # 163 "sharpness_fuse.cpp"
  if (quarterWidth_20 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_20 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_36), "width_22");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_17), "height_12");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_20), "quarterWidth_6");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_10), "quarterHeight_4");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_18, 8, "yPlaneCSER_11");
   __hmppcg_call.addLocalParameter(&yPlaneDown_4, 8, "yPlaneDown_10");
   __hmppcg_call.launch(hmpp_acc_region_main_159_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 163 "sharpness_fuse.cpp"
 *width_16 = width_36;
 # 163 "sharpness_fuse.cpp"
 *height_11 = height_17;
}
#endif /* __GPUCODE__ */



# 163 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_159(cl_int* width_56, cl_int* height_29, cl_int quarterWidth_14, cl_int quarterHeight_13, cl_char* yPlaneCSER_36, cl_char* yPlaneDown_13)
{
 # 177 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_159_internal_1(width_56, height_29, quarterWidth_14, quarterHeight_13, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_36), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneDown_13)));
}
#endif /* __GPUCODE__ */



# 177 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_172_loop1D_1(int quarterWidth_5, __global uchar* yPlaneCSER_17)
{
 # 175 "sharpness_fuse.cpp"
 int w_13;
 # 177 "sharpness_fuse.cpp"
 w_13 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 177 "sharpness_fuse.cpp"
 if (w_13 > quarterWidth_5 - 1)
 {
  # 177 "sharpness_fuse.cpp"
  goto __hmppcg_label_4;
 }
 # 177 "sharpness_fuse.cpp"
 if (w_13 < quarterWidth_5 - 1)
 {
  # 179 "sharpness_fuse.cpp"
  *(yPlaneCSER_17 + (w_13 * 4 + 1)) = (uchar ) (((int ) (*(yPlaneCSER_17 + w_13 * 4)) * 3 + (int ) (*(yPlaneCSER_17 + (w_13 * 4 + 4)))) / 4);
  # 180 "sharpness_fuse.cpp"
  *(yPlaneCSER_17 + (w_13 * 4 + 2)) = (uchar ) (((int ) (*(yPlaneCSER_17 + w_13 * 4)) * 2 + (int ) (*(yPlaneCSER_17 + (w_13 * 4 + 4))) * 2) / 4);
  # 181 "sharpness_fuse.cpp"
  *(yPlaneCSER_17 + (w_13 * 4 + 3)) = (uchar ) (((int ) (*(yPlaneCSER_17 + w_13 * 4)) + (int ) (*(yPlaneCSER_17 + (w_13 * 4 + 4))) * 3) / 4);
 }
 else
 {
  # 185 "sharpness_fuse.cpp"
  *(yPlaneCSER_17 + (w_13 * 4 + 1)) = *(yPlaneCSER_17 + w_13 * 4);
 }
 # 177 "sharpness_fuse.cpp"
 __hmppcg_label_4:;
}
#endif /* __GPUCODE__ */



# 177 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_172_internal_1(cl_int* width_15, cl_int quarterWidth_19, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_10)
{
 # 179 "sharpness_fuse.cpp"
 cl_int width_23;
 # 179 "sharpness_fuse.cpp"
 width_23 = *width_15;
 # 179 "sharpness_fuse.cpp"
 {
  # 177 "sharpness_fuse.cpp"
  if (quarterWidth_19 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_19 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_19), "quarterWidth_5");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_10, 8, "yPlaneCSER_17");
   __hmppcg_call.launch(hmpp_acc_region_main_172_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 177 "sharpness_fuse.cpp"
 *width_15 = width_23;
}
#endif /* __GPUCODE__ */



# 177 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_172(cl_int* width_55, cl_int quarterWidth_13, cl_char* yPlaneCSER_31)
{
 # 193 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_172_internal_1(width_55, quarterWidth_13, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_31)));
}
#endif /* __GPUCODE__ */



# 193 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_189_loop1D_1(int quarterWidth_4, __global uchar* yPlaneCSER_9, int width_24, int height_13)
{
 # 198 "sharpness_fuse.cpp"
 int w_14;
 # 200 "sharpness_fuse.cpp"
 w_14 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 200 "sharpness_fuse.cpp"
 if (w_14 > quarterWidth_4 - 1)
 {
  # 200 "sharpness_fuse.cpp"
  goto __hmppcg_label_5;
 }
 # 200 "sharpness_fuse.cpp"
 if (w_14 < quarterWidth_4 - 1)
 {
  # 202 "sharpness_fuse.cpp"
  *(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4 + 1)) = (uchar ) (((int ) (*(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4))) * 3 + (int ) (*(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4 + 4)))) / 4);
  # 203 "sharpness_fuse.cpp"
  *(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4 + 2)) = (uchar ) (((int ) (*(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4))) * 2 + (int ) (*(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4 + 4))) * 2) / 4);
  # 204 "sharpness_fuse.cpp"
  *(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4 + 3)) = (uchar ) (((int ) (*(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4))) + (int ) (*(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4 + 4))) * 3) / 4);
 }
 else
 {
  # 208 "sharpness_fuse.cpp"
  *(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4 + 1)) = *(yPlaneCSER_9 + ((height_13 - 2) * width_24 + w_14 * 4));
 }
 # 193 "sharpness_fuse.cpp"
 __hmppcg_label_5:;
}
#endif /* __GPUCODE__ */



# 193 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_189_internal_1(cl_int* width_14, cl_int* height_10, cl_int quarterWidth_18, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_43)
{
 # 195 "sharpness_fuse.cpp"
 cl_int height_18;
 # 195 "sharpness_fuse.cpp"
 height_18 = *height_10;
 # 195 "sharpness_fuse.cpp"
 cl_int width_37;
 # 195 "sharpness_fuse.cpp"
 width_37 = *width_14;
 # 195 "sharpness_fuse.cpp"
 {
  # 193 "sharpness_fuse.cpp"
  if (quarterWidth_18 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterWidth_18 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_18), "quarterWidth_4");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_43, 8, "yPlaneCSER_9");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_37), "width_24");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_18), "height_13");
   __hmppcg_call.launch(hmpp_acc_region_main_189_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 193 "sharpness_fuse.cpp"
 *width_14 = width_37;
 # 193 "sharpness_fuse.cpp"
 *height_10 = height_18;
}
#endif /* __GPUCODE__ */



# 193 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_189(cl_int* width_54, cl_int* height_28, cl_int quarterWidth_12, cl_char* yPlaneCSER_29)
{
 # 216 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_189_internal_1(width_54, height_28, quarterWidth_12, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_29)));
}
#endif /* __GPUCODE__ */



# 216 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_211_loop1D_1(__global uchar* yPlaneCSER_8, int width_25)
{
 # 214 "sharpness_fuse.cpp"
 int w_15;
 # 216 "sharpness_fuse.cpp"
 w_15 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 216 "sharpness_fuse.cpp"
 if (w_15 > width_25 - 1)
 {
  # 216 "sharpness_fuse.cpp"
  goto __hmppcg_label_6;
 }
 # 216 "sharpness_fuse.cpp"
 *(yPlaneCSER_8 + (width_25 + w_15)) = *(yPlaneCSER_8 + w_15);
 # 216 "sharpness_fuse.cpp"
 __hmppcg_label_6:;
}
#endif /* __GPUCODE__ */



# 216 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_211_internal_1(cl_int* width_53, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_42)
{
 # 218 "sharpness_fuse.cpp"
 cl_int width_38;
 # 218 "sharpness_fuse.cpp"
 width_38 = *width_53;
 # 218 "sharpness_fuse.cpp"
 {
  # 216 "sharpness_fuse.cpp"
  if (width_38 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((width_38 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter(&yPlaneCSER_42, 8, "yPlaneCSER_8");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_38), "width_25");
   __hmppcg_call.launch(hmpp_acc_region_main_211_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 216 "sharpness_fuse.cpp"
 *width_53 = width_38;
}
#endif /* __GPUCODE__ */



# 216 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_211(cl_int* width_13, cl_char* yPlaneCSER_28)
{
 # 223 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_211_internal_1(width_13, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_28)));
}
#endif /* __GPUCODE__ */



# 223 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_220_loop1D_1(__global uchar* yPlaneCSER_7, int width_26, int height_14)
{
 # 229 "sharpness_fuse.cpp"
 int w_16;
 # 231 "sharpness_fuse.cpp"
 w_16 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 231 "sharpness_fuse.cpp"
 if (w_16 > width_26 - 1)
 {
  # 231 "sharpness_fuse.cpp"
  goto __hmppcg_label_7;
 }
 # 231 "sharpness_fuse.cpp"
 *(yPlaneCSER_7 + ((height_14 - 1) * width_26 + w_16)) = *(yPlaneCSER_7 + ((height_14 - 2) * width_26 + w_16));
 # 223 "sharpness_fuse.cpp"
 __hmppcg_label_7:;
}
#endif /* __GPUCODE__ */



# 223 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_220_internal_1(cl_int* width_52, cl_int* height_38, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_41)
{
 # 225 "sharpness_fuse.cpp"
 cl_int height_19;
 # 225 "sharpness_fuse.cpp"
 height_19 = *height_38;
 # 225 "sharpness_fuse.cpp"
 cl_int width_39;
 # 225 "sharpness_fuse.cpp"
 width_39 = *width_52;
 # 225 "sharpness_fuse.cpp"
 {
  # 223 "sharpness_fuse.cpp"
  if (width_39 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((width_39 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter(&yPlaneCSER_41, 8, "yPlaneCSER_7");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_39), "width_26");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_19), "height_14");
   __hmppcg_call.launch(hmpp_acc_region_main_220_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 223 "sharpness_fuse.cpp"
 *width_52 = width_39;
 # 223 "sharpness_fuse.cpp"
 *height_38 = height_19;
}
#endif /* __GPUCODE__ */



# 223 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_220(cl_int* width_12, cl_int* height_9, cl_char* yPlaneCSER_27)
{
 # 238 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_220_internal_1(width_12, height_9, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_27)));
}
#endif /* __GPUCODE__ */



# 238 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_232_loop1D_1(int quarterWidth_11, int quarterHeight_3, __global uchar* yPlaneCSER_6, __global uchar* yPlaneDown_3, int width_27)
{
 # 235 "sharpness_fuse.cpp"
 int h_14;
 # 237 "sharpness_fuse.cpp"
 h_14 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 237 "sharpness_fuse.cpp"
 if (h_14 > quarterHeight_3 - 1)
 {
  # 237 "sharpness_fuse.cpp"
  goto __hmppcg_label_8;
 }
 # 237 "sharpness_fuse.cpp"
 *(yPlaneCSER_6 + (h_14 * 4 * width_27 + width_27 - 2)) = *(yPlaneDown_3 + (h_14 * quarterWidth_11 + quarterWidth_11 - 1));
 # 238 "sharpness_fuse.cpp"
 __hmppcg_label_8:;
}
#endif /* __GPUCODE__ */



# 238 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_232_internal_1(cl_int* width_11, cl_int quarterWidth_21, cl_int quarterHeight_17, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_40, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_17)
{
 # 240 "sharpness_fuse.cpp"
 cl_int width_40;
 # 240 "sharpness_fuse.cpp"
 width_40 = *width_11;
 # 240 "sharpness_fuse.cpp"
 {
  # 238 "sharpness_fuse.cpp"
  if (quarterHeight_17 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterHeight_17 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_21), "quarterWidth_11");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_17), "quarterHeight_3");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_40, 8, "yPlaneCSER_6");
   __hmppcg_call.addLocalParameter(&yPlaneDown_17, 8, "yPlaneDown_3");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_40), "width_27");
   __hmppcg_call.launch(hmpp_acc_region_main_232_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 238 "sharpness_fuse.cpp"
 *width_11 = width_40;
}
#endif /* __GPUCODE__ */



# 238 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_232(cl_int* width_51, cl_int quarterWidth_3, cl_int quarterHeight_9, cl_char* yPlaneCSER_26, cl_char* yPlaneDown_9)
{
 # 244 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_232_internal_1(width_51, quarterWidth_3, quarterHeight_9, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_26), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneDown_9)));
}
#endif /* __GPUCODE__ */



# 244 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_244_loop1D_1(int quarterHeight_2, __global uchar* yPlaneCSER_5, int width_28)
{
 # 247 "sharpness_fuse.cpp"
 int h_15;
 # 249 "sharpness_fuse.cpp"
 h_15 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 249 "sharpness_fuse.cpp"
 if (h_15 > quarterHeight_2 - 1)
 {
  # 249 "sharpness_fuse.cpp"
  goto __hmppcg_label_9;
 }
 # 249 "sharpness_fuse.cpp"
 if (h_15 < quarterHeight_2 - 1)
 {
  # 251 "sharpness_fuse.cpp"
  *(yPlaneCSER_5 + ((h_15 * 4 + 1) * width_28 + width_28 - 2)) = (uchar ) (((int ) (*(yPlaneCSER_5 + (h_15 * 4 * width_28 + width_28 - 2))) * 3 + (int ) (*(yPlaneCSER_5 + ((h_15 * 4 + 4) * width_28 + width_28 - 2)))) / 4);
  # 252 "sharpness_fuse.cpp"
  *(yPlaneCSER_5 + ((h_15 * 4 + 2) * width_28 + width_28 - 2)) = (uchar ) (((int ) (*(yPlaneCSER_5 + (h_15 * 4 * width_28 + width_28 - 2))) * 2 + (int ) (*(yPlaneCSER_5 + ((h_15 * 4 + 4) * width_28 + width_28 - 2))) * 2) / 4);
  # 253 "sharpness_fuse.cpp"
  *(yPlaneCSER_5 + ((h_15 * 4 + 3) * width_28 + width_28 - 2)) = (uchar ) (((int ) (*(yPlaneCSER_5 + (h_15 * 4 * width_28 + width_28 - 2))) + (int ) (*(yPlaneCSER_5 + ((h_15 * 4 + 4) * width_28 + width_28 - 2))) * 3) / 4);
 }
 else
 {
  # 257 "sharpness_fuse.cpp"
  *(yPlaneCSER_5 + ((h_15 * 4 + 1) * width_28 + width_28 - 2)) = *(yPlaneCSER_5 + (h_15 * 4 * width_28 + width_28 - 2));
  # 258 "sharpness_fuse.cpp"
  *(yPlaneCSER_5 + ((h_15 * 4 + 2) * width_28 + width_28 - 2)) = *(yPlaneCSER_5 + (h_15 * 4 * width_28 + width_28 - 2));
  # 259 "sharpness_fuse.cpp"
  *(yPlaneCSER_5 + ((h_15 * 4 + 3) * width_28 + width_28 - 2)) = *(yPlaneCSER_5 + (h_15 * 4 * width_28 + width_28 - 2));
 }
 # 244 "sharpness_fuse.cpp"
 __hmppcg_label_9:;
}
#endif /* __GPUCODE__ */



# 244 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_244_internal_1(cl_int* width_50, cl_int quarterHeight_16, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_39)
{
 # 246 "sharpness_fuse.cpp"
 cl_int width_41;
 # 246 "sharpness_fuse.cpp"
 width_41 = *width_50;
 # 246 "sharpness_fuse.cpp"
 {
  # 244 "sharpness_fuse.cpp"
  if (quarterHeight_16 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((quarterHeight_16 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_16), "quarterHeight_2");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_39, 8, "yPlaneCSER_5");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_41), "width_28");
   __hmppcg_call.launch(hmpp_acc_region_main_244_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 244 "sharpness_fuse.cpp"
 *width_50 = width_41;
}
#endif /* __GPUCODE__ */



# 244 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_244(cl_int* width_10, cl_int quarterHeight_8, cl_char* yPlaneCSER_25)
{
 # 267 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_244_internal_1(width_10, quarterHeight_8, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_25)));
}
#endif /* __GPUCODE__ */



# 267 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_267_loop1D_1(int width_42, int height_26, __global uchar* yPlaneCSER_24)
{
 # 270 "sharpness_fuse.cpp"
 int h_16;
 # 272 "sharpness_fuse.cpp"
 h_16 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 272 "sharpness_fuse.cpp"
 if (h_16 > height_26 - 1)
 {
  # 272 "sharpness_fuse.cpp"
  goto __hmppcg_label_10;
 }
 # 272 "sharpness_fuse.cpp"
 *(yPlaneCSER_24 + (h_16 * width_42 + width_42 - 1)) = *(yPlaneCSER_24 + (h_16 * width_42 + width_42 - 2));
 # 267 "sharpness_fuse.cpp"
 __hmppcg_label_10:;
}
#endif /* __GPUCODE__ */



# 267 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_267_internal_1(cl_int* width_68, cl_int height_37, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_44)
{
 # 269 "sharpness_fuse.cpp"
 cl_int width_29;
 # 269 "sharpness_fuse.cpp"
 width_29 = *width_68;
 # 269 "sharpness_fuse.cpp"
 {
  # 267 "sharpness_fuse.cpp"
  if (height_37 - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX((height_37 - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_29), "width_42");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (height_37), "height_26");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_44, 8, "yPlaneCSER_24");
   __hmppcg_call.launch(hmpp_acc_region_main_267_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 267 "sharpness_fuse.cpp"
 *width_68 = width_29;
}
#endif /* __GPUCODE__ */



# 267 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_267(cl_int* width_9, cl_int height_8, cl_char* yPlaneCSER_4)
{
 # 279 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_267_internal_1(width_9, height_8, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_4)));
}
#endif /* __GPUCODE__ */



# 279 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(128, 1, 1)))  void hmpp_acc_region_main_279_loop1D_1(int quarterWidth_2, int quarterHeight_1, __global uchar* yPlaneCSER_3, __global uchar* yPlaneDown_2, int width_30)
{
 # 282 "sharpness_fuse.cpp"
 int h_17;
 # 285 "sharpness_fuse.cpp"
 int w_17;
 # 282 "sharpness_fuse.cpp"
 int h_22;
 # 287 "sharpness_fuse.cpp"
 h_22 = (get_global_id(1) * get_global_size(0) + get_global_id(0));
 # 287 "sharpness_fuse.cpp"
 if (h_22 > (quarterHeight_1 +  -1) * (quarterWidth_2 - 1) - 1)
 {
  # 287 "sharpness_fuse.cpp"
  goto __hmppcg_label_11;
 }
 # 287 "sharpness_fuse.cpp"
 w_17 = h_22 % (quarterWidth_2 +  -1);
 # 287 "sharpness_fuse.cpp"
 h_17 = h_22 / (quarterWidth_2 +  -1);
 # 287 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 2)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) * 7 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) / 8 / 8);
 # 288 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 3)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) * 7 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) / 8 / 8);
 # 289 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 4)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) * 7 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) / 8 / 8);
 # 290 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 2) * width_30 + w_17 * 4 + 5)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) * 7 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) / 8 / 8);
 # 292 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 2)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) * 5 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) * 3 / 8 / 8);
 # 293 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 3)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) * 5 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) * 3 / 8 / 8);
 # 294 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 4)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) * 5 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) * 3 / 8 / 8);
 # 295 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 3) * width_30 + w_17 * 4 + 5)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) * 5 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) * 3 / 8 / 8);
 # 297 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 2)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) * 3 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) * 5 / 8 / 8);
 # 298 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 3)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) * 3 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) * 5 / 8 / 8);
 # 299 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 4)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) * 3 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) * 5 / 8 / 8);
 # 300 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 4) * width_30 + w_17 * 4 + 5)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) * 3 / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) * 5 / 8 / 8);
 # 302 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 2)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1)))) / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 7 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1)))) * 7 / 8 / 8);
 # 303 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 3)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 3) / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 5 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 3) * 7 / 8 / 8);
 # 304 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 4)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 5) / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) * 3 + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 5) * 7 / 8 / 8);
 # 305 "sharpness_fuse.cpp"
 *(yPlaneCSER_3 + ((h_17 * 4 + 5) * width_30 + w_17 * 4 + 5)) = (uchar ) (((int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + (h_17 * quarterWidth_2 + w_17 + 1))) * 7) / 8 / 8 + ((int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17))) + (int ) (*(yPlaneDown_2 + ((h_17 + 1) * quarterWidth_2 + w_17 + 1))) * 7) * 7 / 8 / 8);
 # 279 "sharpness_fuse.cpp"
 __hmppcg_label_11:;
}
#endif /* __GPUCODE__ */



# 279 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_279_internal_1(cl_int* width_8, cl_int quarterWidth_17, cl_int quarterHeight_15, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_38, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_8)
{
 # 281 "sharpness_fuse.cpp"
 cl_int width_44;
 # 281 "sharpness_fuse.cpp"
 width_44 = *width_8;
 # 281 "sharpness_fuse.cpp"
 {
  # 279 "sharpness_fuse.cpp"
  if ((quarterHeight_15 +  -1) * (quarterWidth_17 - 1) - 1 >= 0)
  {
   hmpprt::OpenCLGridCall __hmppcg_call;
   __hmppcg_call.setSizeX(((quarterHeight_15 +  -1) * (quarterWidth_17 - 1) - 1) / 128 + 1);
   __hmppcg_call.setSizeY(1);
   __hmppcg_call.setBlockSizeX(32);
   __hmppcg_call.setBlockSizeY(4);
   __hmppcg_call.setWorkDim(1);
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterWidth_17), "quarterWidth_2");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (quarterHeight_15), "quarterHeight_1");
   __hmppcg_call.addLocalParameter(&yPlaneCSER_38, 8, "yPlaneCSER_3");
   __hmppcg_call.addLocalParameter(&yPlaneDown_8, 8, "yPlaneDown_2");
   __hmppcg_call.addLocalParameter((hmpprt::s32) (width_44), "width_30");
   __hmppcg_call.launch(hmpp_acc_region_main_279_loop1D_1, hmpprt::Context::getInstance()->getOpenCLDevice());
  }
  ;
 }
 # 279 "sharpness_fuse.cpp"
 *width_8 = width_44;
}
#endif /* __GPUCODE__ */



# 279 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_279(cl_int* width_67, cl_int quarterWidth_10, cl_int quarterHeight_7, cl_char* yPlaneCSER_23, cl_char* yPlaneDown_16)
{
 # 313 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_279_internal_1(width_67, quarterWidth_10, quarterHeight_7, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_23), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneDown_16)));
}
#endif /* __GPUCODE__ */



# 313 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_316_parallel_region_1(int height_7, __global short* pEdge, int width_7, __global uchar* yPlane)
{
 # 315 "sharpness_fuse.cpp"
 {
  # 319 "sharpness_fuse.cpp"
  int iter_per_gang_7;
  # 319 "sharpness_fuse.cpp"
  int first_gang_iter_7;
  # 319 "sharpness_fuse.cpp"
  int last_gang_iter_7;
  # 319 "sharpness_fuse.cpp"
  iter_per_gang_7 = ((1 + (height_7 * width_7 - 1) / 192) > 256 ? (1 + (height_7 * width_7 - 1) / 192) : 256);
  # 319 "sharpness_fuse.cpp"
  first_gang_iter_7 = get_group_id(0) * iter_per_gang_7;
  # 319 "sharpness_fuse.cpp"
  last_gang_iter_7 = ((first_gang_iter_7 + iter_per_gang_7 - 1) < (height_7 * width_7 - 1) ? (first_gang_iter_7 + iter_per_gang_7 - 1) : (height_7 * width_7 - 1));
  # 319 "sharpness_fuse.cpp"
  int y_2;
  # 319 "sharpness_fuse.cpp"
  # 323 "sharpness_fuse.cpp"
  for (y_2 = first_gang_iter_7 + get_local_id(1) ; y_2 <= last_gang_iter_7 ; y_2 = y_2 + get_local_size(1))
  {
   # 319 "sharpness_fuse.cpp"
   int y_1;
   # 322 "sharpness_fuse.cpp"
   int x_1;
   # 324 "sharpness_fuse.cpp"
   x_1 = y_2 % width_7;
   # 324 "sharpness_fuse.cpp"
   y_1 = y_2 / width_7;
   # 324 "sharpness_fuse.cpp"
   if (y_1 == 0 || y_1 == height_7 - 1 || x_1 == 0 || x_1 == width_7 - 1)
   {
    # 326 "sharpness_fuse.cpp"
    *(pEdge + (y_1 * width_7 + x_1)) = (short) 0;
   }
   else
   {
    # 330 "sharpness_fuse.cpp"
    int gx;
    # 330 "sharpness_fuse.cpp"
    gx = (int ) (*(yPlane + ((y_1 - 1) * width_7 + x_1 + 1))) + ((int ) (*(yPlane + (y_1 * width_7 + x_1 + 1))) << 1) + (int ) (*(yPlane + ((y_1 + 1) * width_7 + x_1 + 1))) - ((int ) (*(yPlane + ((y_1 - 1) * width_7 + x_1 - 1))) + ((int ) (*(yPlane + (y_1 * width_7 + x_1 - 1))) << 1) + (int ) (*(yPlane + ((y_1 + 1) * width_7 + x_1 - 1))));
    # 331 "sharpness_fuse.cpp"
    int gy;
    # 331 "sharpness_fuse.cpp"
    gy = (int ) (*(yPlane + ((y_1 - 1) * width_7 + x_1 - 1))) + ((int ) (*(yPlane + ((y_1 - 1) * width_7 + x_1))) << 1) + (int ) (*(yPlane + ((y_1 - 1) * width_7 + x_1 + 1))) - ((int ) (*(yPlane + ((y_1 + 1) * width_7 + x_1 - 1))) + ((int ) (*(yPlane + ((y_1 + 1) * width_7 + x_1))) << 1) + (int ) (*(yPlane + ((y_1 + 1) * width_7 + x_1 + 1))));
    # 332 "sharpness_fuse.cpp"
    int edgeV;
    # 332 "sharpness_fuse.cpp"
    edgeV = ((gx) > 0 ? (gx) : -(gx)) + ((gy) > 0 ? (gy) : -(gy));
    # 333 "sharpness_fuse.cpp"
    *(pEdge + (y_1 * width_7 + x_1)) = (short ) (edgeV);
   }
  }
  # 313 "sharpness_fuse.cpp"
 }
}
#endif /* __GPUCODE__ */



# 313 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_316_internal_1(cl_int width_66, cl_int height_36, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_10, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_8)
{
 # 313 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_36), "height_7");
  __hmppcg_call.addLocalParameter(&pEdge_8, 8, "pEdge");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_66), "width_7");
  __hmppcg_call.addLocalParameter(&yPlane_10, 8, "yPlane");
  __hmppcg_call.launch(hmpp_acc_region_main_316_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 313 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_316(cl_int width_48, cl_int height_25, cl_char* yPlane_5, cl_short* pEdge_4)
{
 # 342 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_316_internal_1(width_48, height_25, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlane_5), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pEdge_4)));
}
#endif /* __GPUCODE__ */



# 342 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(256, 1, 1)))  void reduce_s64_add_xy(long neutral, __global long* scalar, int size, __global long* array)
{
 
 local long tmpa[256];
 
 # 342 "sharpness_fuse.cpp"
 long var;
 # 342 "sharpness_fuse.cpp"
 var = neutral;
 # 342 "sharpness_fuse.cpp"
 int end_4;
 # 342 "sharpness_fuse.cpp"
 int i;
 # 342 "sharpness_fuse.cpp"
 # 342 "sharpness_fuse.cpp"
 # 342 "sharpness_fuse.cpp"
 for (i = (get_local_id(1)* get_local_size(0) + get_local_id(0)), end_4 = size - 1 ; i <= end_4 ; i = i + 256)
 {
  # 342 "sharpness_fuse.cpp"
  var = var + *(array + i);
 }
 # 342 "sharpness_fuse.cpp"
 # 342 "sharpness_fuse.cpp"
 tmpa[(get_local_id(1)* get_local_size(0) + get_local_id(0))] = var;
 # 342 "sharpness_fuse.cpp"
 int n_1;
 # 342 "sharpness_fuse.cpp"
 # 342 "sharpness_fuse.cpp"
 for (n_1 = (255 >> 1) + 1 ; n_1 > 0 ; n_1 = (n_1 >> 1))
 {
  # 342 "sharpness_fuse.cpp"
  int next_1;
  # 342 "sharpness_fuse.cpp"
  next_1 = (get_local_id(1)* get_local_size(0) + get_local_id(0)) + n_1;
  # 342 "sharpness_fuse.cpp"
  barrier(CLK_LOCAL_MEM_FENCE);
  # 342 "sharpness_fuse.cpp"
  if ((get_local_id(1)* get_local_size(0) + get_local_id(0)) < n_1 && next_1 < 256)
  {
   # 342 "sharpness_fuse.cpp"
   tmpa[(get_local_id(1)* get_local_size(0) + get_local_id(0))] = tmpa[(get_local_id(1)* get_local_size(0) + get_local_id(0))] + tmpa[next_1];
  }
 }
 # 342 "sharpness_fuse.cpp"
 # 342 "sharpness_fuse.cpp"
 if ((get_local_id(1)* get_local_size(0) + get_local_id(0)) == 0)
 {
  # 342 "sharpness_fuse.cpp"
  *scalar = tmpa[0] + *scalar;
 }
}
#endif /* __GPUCODE__ */



# 342 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_339_parallel_region_1(__global long* gang_prv_red_sum_1, int height_6, __global short* pEdge_3, int width_6)
{
 
 local long sum_1[1];
 
 local long tmpr_3[256];
 
 # 344 "sharpness_fuse.cpp"
 long tmp_27;
 # 344 "sharpness_fuse.cpp"
 if ((get_local_id(1)* get_local_size(0) + get_local_id(0)) == 0)
 {
  # 344 "sharpness_fuse.cpp"
  sum_1[0] = 0;
 }
 # 344 "sharpness_fuse.cpp"
 barrier(CLK_LOCAL_MEM_FENCE);
 # 344 "sharpness_fuse.cpp"
 {
  # 342 "sharpness_fuse.cpp"
  int iter_per_gang_6;
  # 342 "sharpness_fuse.cpp"
  int first_gang_iter_6;
  # 342 "sharpness_fuse.cpp"
  int last_gang_iter_6;
  # 342 "sharpness_fuse.cpp"
  iter_per_gang_6 = ((1 + (height_6 * width_6 - 1) / 192) > 256 ? (1 + (height_6 * width_6 - 1) / 192) : 256);
  # 342 "sharpness_fuse.cpp"
  first_gang_iter_6 = get_group_id(0) * iter_per_gang_6;
  # 342 "sharpness_fuse.cpp"
  last_gang_iter_6 = ((first_gang_iter_6 + iter_per_gang_6 - 1) < (height_6 * width_6 - 1) ? (first_gang_iter_6 + iter_per_gang_6 - 1) : (height_6 * width_6 - 1));
  # 342 "sharpness_fuse.cpp"
  long sum_2;
  # 348 "sharpness_fuse.cpp"
  sum_2 = 0;
  # 348 "sharpness_fuse.cpp"
  int i_4;
  # 348 "sharpness_fuse.cpp"
  # 352 "sharpness_fuse.cpp"
  for (i_4 = first_gang_iter_6 + get_local_id(1) ; i_4 <= last_gang_iter_6 ; i_4 = i_4 + get_local_size(1))
  {
   # 348 "sharpness_fuse.cpp"
   int i_2;
   # 351 "sharpness_fuse.cpp"
   int j_2;
   # 353 "sharpness_fuse.cpp"
   j_2 = i_4 % width_6;
   # 353 "sharpness_fuse.cpp"
   i_2 = i_4 / width_6;
   # 353 "sharpness_fuse.cpp"
   sum_2 = sum_2 + (long ) (*(pEdge_3 + (i_2 * width_6 + j_2)));
  }
  # 342 "sharpness_fuse.cpp"
  # 342 "sharpness_fuse.cpp"
  sum_1[0] = (reduce_s64_add_y(sum_2, tmpr_3, sum_1[0]));
 }
 # 342 "sharpness_fuse.cpp"
 tmp_27 = sum_1[0];
 # 342 "sharpness_fuse.cpp"
 if (get_local_id(1) == 0)
 {
  # 342 "sharpness_fuse.cpp"
  *(gang_prv_red_sum_1 + get_group_id(0)) = tmp_27;
 }
 # 342 "sharpness_fuse.cpp"
 barrier(CLK_LOCAL_MEM_FENCE);
}
#endif /* __GPUCODE__ */



# 342 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_339_internal_1(cl_int width_65, cl_int height_35, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_11, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_long>  sum_4)
{
 # 342 "sharpness_fuse.cpp"
 hmpprt::DevicePtr<hmpprt::MS_OPENCL_SHARED,cl_long>  sum_3;
 # 342 "sharpness_fuse.cpp"
 cl_long tmp_28;
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->allocate((void **) &sum_3, hmpprt::MS_OPENCL_SHARED, 8);
 # 342 "sharpness_fuse.cpp"
 hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_long>  gang_prv_red_sum_2;
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->allocate((void **) &gang_prv_red_sum_2, hmpprt::MS_OPENCL_GLOB, 1536);
 # 342 "sharpness_fuse.cpp"
 hmpprt::DevicePtr<hmpprt::MS_OPENCL_SHARED,cl_long>  tmpr_2;
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->allocate((void **) &tmpr_2, hmpprt::MS_OPENCL_SHARED, 2048);
 # 342 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter(&gang_prv_red_sum_2, 8, "gang_prv_red_sum_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_35), "height_6");
  __hmppcg_call.addLocalParameter(&pEdge_11, 8, "pEdge_3");
  __hmppcg_call.addSharedParameter(sum_3, "sum_1");
  __hmppcg_call.addSharedParameter(tmpr_2, "tmpr_3");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_65), "width_6");
  __hmppcg_call.launch(hmpp_acc_region_main_339_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
 # 342 "sharpness_fuse.cpp"
 hmpprt::DevicePtr<hmpprt::MS_OPENCL_SHARED,cl_long>  tmpr_1;
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->allocate((void **) &tmpr_1, hmpprt::MS_OPENCL_SHARED, 2048);
 # 342 "sharpness_fuse.cpp"
 tmp_28 = 0;
 # 342 "sharpness_fuse.cpp"
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
  __hmppcg_call.addLocalParameter(&gang_prv_red_sum_2, 8, "array");
  __hmppcg_call.launch(reduce_s64_add_xy, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->free((void **) &tmpr_2);
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->free((void **) &tmpr_1);
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->free((void **) &gang_prv_red_sum_2);
 # 342 "sharpness_fuse.cpp"
 hmpprt::Context::getInstance()->free((void **) &sum_3);
}
#endif /* __GPUCODE__ */



# 342 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_339(cl_int width_47, cl_int height_24, cl_short* pEdge_7, cl_long* sum)
{
 # 361 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_339_internal_1(width_47, height_24, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pEdge_7), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_long> (sum)));
}
#endif /* __GPUCODE__ */



# 361 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_376_parallel_region_1(int height_5, __global short* pError, int width_5, __global uchar* yPlaneCSER_2, __global uchar* yPlane_4)
{
 # 363 "sharpness_fuse.cpp"
 {
  # 379 "sharpness_fuse.cpp"
  int iter_per_gang_5;
  # 379 "sharpness_fuse.cpp"
  int first_gang_iter_5;
  # 379 "sharpness_fuse.cpp"
  int last_gang_iter_5;
  # 379 "sharpness_fuse.cpp"
  iter_per_gang_5 = ((1 + (height_5 * width_5 - 1) / 192) > 256 ? (1 + (height_5 * width_5 - 1) / 192) : 256);
  # 379 "sharpness_fuse.cpp"
  first_gang_iter_5 = get_group_id(0) * iter_per_gang_5;
  # 379 "sharpness_fuse.cpp"
  last_gang_iter_5 = ((first_gang_iter_5 + iter_per_gang_5 - 1) < (height_5 * width_5 - 1) ? (first_gang_iter_5 + iter_per_gang_5 - 1) : (height_5 * width_5 - 1));
  # 379 "sharpness_fuse.cpp"
  int h_23;
  # 379 "sharpness_fuse.cpp"
  # 383 "sharpness_fuse.cpp"
  for (h_23 = first_gang_iter_5 + get_local_id(1) ; h_23 <= last_gang_iter_5 ; h_23 = h_23 + get_local_size(1))
  {
   # 379 "sharpness_fuse.cpp"
   int h_18;
   # 382 "sharpness_fuse.cpp"
   int w_18;
   # 384 "sharpness_fuse.cpp"
   w_18 = h_23 % width_5;
   # 384 "sharpness_fuse.cpp"
   h_18 = h_23 / width_5;
   # 384 "sharpness_fuse.cpp"
   *(pError + (h_18 * width_5 + w_18)) = (short ) ((int ) (*(yPlane_4 + (h_18 * width_5 + w_18))) - (int ) (*(yPlaneCSER_2 + (h_18 * width_5 + w_18))));
  }
  # 361 "sharpness_fuse.cpp"
 }
}
#endif /* __GPUCODE__ */



# 361 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_376_internal_1(cl_int width_64, cl_int height_34, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_14, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_37, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pError_4)
{
 # 361 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_34), "height_5");
  __hmppcg_call.addLocalParameter(&pError_4, 8, "pError");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_64), "width_5");
  __hmppcg_call.addLocalParameter(&yPlaneCSER_37, 8, "yPlaneCSER_2");
  __hmppcg_call.addLocalParameter(&yPlane_14, 8, "yPlane_4");
  __hmppcg_call.launch(hmpp_acc_region_main_376_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 361 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_376(cl_int width_46, cl_int height_23, cl_char* yPlane_9, cl_char* yPlaneCSER_22, cl_short* pError_2)
{
 # 392 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_376_internal_1(width_46, height_23, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlane_9), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_22), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pError_2)));
}
#endif /* __GPUCODE__ */



# 392 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_389_parallel_region_1(double cutoff, double cutoff2, int height_4, double low, double order, double order2, __global short* pEdge_2, __global short* pError_1, __global short* pSharpness, double peak, int width_4, __global uchar* yPlaneCSER_1)
{
 # 394 "sharpness_fuse.cpp"
 {
  # 398 "sharpness_fuse.cpp"
  int iter_per_gang_4;
  # 398 "sharpness_fuse.cpp"
  int first_gang_iter_4;
  # 398 "sharpness_fuse.cpp"
  int last_gang_iter_4;
  # 398 "sharpness_fuse.cpp"
  iter_per_gang_4 = ((1 + (height_4 * width_4 - 1) / 192) > 256 ? (1 + (height_4 * width_4 - 1) / 192) : 256);
  # 398 "sharpness_fuse.cpp"
  first_gang_iter_4 = get_group_id(0) * iter_per_gang_4;
  # 398 "sharpness_fuse.cpp"
  last_gang_iter_4 = ((first_gang_iter_4 + iter_per_gang_4 - 1) < (height_4 * width_4 - 1) ? (first_gang_iter_4 + iter_per_gang_4 - 1) : (height_4 * width_4 - 1));
  # 398 "sharpness_fuse.cpp"
  int h_24;
  # 398 "sharpness_fuse.cpp"
  # 402 "sharpness_fuse.cpp"
  for (h_24 = first_gang_iter_4 + get_local_id(1) ; h_24 <= last_gang_iter_4 ; h_24 = h_24 + get_local_size(1))
  {
   # 403 "sharpness_fuse.cpp"
   short edge;
   # 398 "sharpness_fuse.cpp"
   int h_19;
   # 401 "sharpness_fuse.cpp"
   int w_19;
   # 403 "sharpness_fuse.cpp"
   w_19 = h_24 % width_4;
   # 403 "sharpness_fuse.cpp"
   h_19 = h_24 / width_4;
   # 403 "sharpness_fuse.cpp"
   edge = *(pEdge_2 + (h_19 * width_4 + w_19));
   # 404 "sharpness_fuse.cpp"
   double weight;
   # 404 "sharpness_fuse.cpp"
   weight = (double) 1. / ((double) 1. + pow((double ) (edge) / cutoff2, (double) 2. * order2));
   # 405 "sharpness_fuse.cpp"
   double strength;
   # 405 "sharpness_fuse.cpp"
   strength = (peak - low) * ((double) 1. - (double) 1. / ((double) 1. + pow((double ) (edge) / cutoff, (double) 2. * order)));
   # 406 "sharpness_fuse.cpp"
   strength = strength * weight + low;
   # 408 "sharpness_fuse.cpp"
   *(pSharpness + (h_19 * width_4 + w_19)) = (short ) (*(yPlaneCSER_1 + (h_19 * width_4 + w_19)));
   # 409 "sharpness_fuse.cpp"
   *(pSharpness + (h_19 * width_4 + w_19)) = *(pSharpness + (h_19 * width_4 + w_19)) + (double ) (*(pError_1 + (h_19 * width_4 + w_19))) * strength;
  }
  # 392 "sharpness_fuse.cpp"
 }
}
#endif /* __GPUCODE__ */



# 392 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_389_internal_1(cl_int width_63, cl_int height_33, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneCSER_35, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pError_5, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_10, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pSharpness_7, cl_double cutoff_2, cl_double peak_2, cl_double cutoff2_2, cl_double order_2, cl_double order2_2, cl_double low_2)
{
 # 392 "sharpness_fuse.cpp"
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
  __hmppcg_call.addLocalParameter(&pSharpness_7, 8, "pSharpness");
  __hmppcg_call.addLocalParameter(&peak_2, 8, "peak");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_63), "width_4");
  __hmppcg_call.addLocalParameter(&yPlaneCSER_35, 8, "yPlaneCSER_1");
  __hmppcg_call.launch(hmpp_acc_region_main_389_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 392 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_389(cl_int width_45, cl_int height_22, cl_char* yPlaneCSER_16, cl_short* pError_3, cl_short* pEdge_6, cl_short* pSharpness_3, cl_double cutoff_1, cl_double peak_1, cl_double cutoff2_1, cl_double order_1, cl_double order2_1, cl_double low_1)
{
 # 417 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_389_internal_1(width_45, height_22, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneCSER_16), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pError_3), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pEdge_6), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pSharpness_3), cutoff_1, peak_1, cutoff2_1, order_1, order2_1, low_1));
}
#endif /* __GPUCODE__ */



# 417 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_408_parallel_region_1(float cutoff3, int height_3, float low3, float order3, __global short* pEdge_1, __global short* pSharpness_5, float peak3_1, int width_3, __global uchar* yPlane_3)
{
 # 419 "sharpness_fuse.cpp"
 {
  # 423 "sharpness_fuse.cpp"
  int iter_per_gang_3;
  # 423 "sharpness_fuse.cpp"
  int first_gang_iter_3;
  # 423 "sharpness_fuse.cpp"
  int last_gang_iter_3;
  # 423 "sharpness_fuse.cpp"
  iter_per_gang_3 = ((1 + (height_3 * width_3 - 1) / 192) > 256 ? (1 + (height_3 * width_3 - 1) / 192) : 256);
  # 423 "sharpness_fuse.cpp"
  first_gang_iter_3 = get_group_id(0) * iter_per_gang_3;
  # 423 "sharpness_fuse.cpp"
  last_gang_iter_3 = ((first_gang_iter_3 + iter_per_gang_3 - 1) < (height_3 * width_3 - 1) ? (first_gang_iter_3 + iter_per_gang_3 - 1) : (height_3 * width_3 - 1));
  # 423 "sharpness_fuse.cpp"
  int h_25;
  # 423 "sharpness_fuse.cpp"
  # 427 "sharpness_fuse.cpp"
  for (h_25 = first_gang_iter_3 + get_local_id(1) ; h_25 <= last_gang_iter_3 ; h_25 = h_25 + get_local_size(1))
  {
   # 423 "sharpness_fuse.cpp"
   int h_20;
   # 426 "sharpness_fuse.cpp"
   int w_20;
   # 428 "sharpness_fuse.cpp"
   w_20 = h_25 % width_3;
   # 428 "sharpness_fuse.cpp"
   h_20 = h_25 / width_3;
   # 428 "sharpness_fuse.cpp"
   if (!(h_20 == 0 || h_20 == height_3 - 1 || w_20 == 0 || w_20 == width_3 - 1))
   {
    # 430 "sharpness_fuse.cpp"
    int enhanced;
    # 430 "sharpness_fuse.cpp"
    int maxValue;
    # 430 "sharpness_fuse.cpp"
    int minValue;
    # 431 "sharpness_fuse.cpp"
    double oscStrength;
    # 432 "sharpness_fuse.cpp"
    enhanced = (int ) (*(pSharpness_5 + (h_20 * width_3 + w_20)));
    # 434 "sharpness_fuse.cpp"
    maxValue = (int ) ( ((int ) ( ((int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) > (int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))) ? ( ((int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20)))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1))));
    # 423 "sharpness_fuse.cpp"
    maxValue = ( (maxValue > (int ) ( ((int ) ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) > (int ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))) ? maxValue : ((int ) ( ((int ) ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) > (int ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + (h_20 * width_3 + w_20)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : (*(yPlane_3 + (h_20 * width_3 + w_20)))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))));
    # 424 "sharpness_fuse.cpp"
    maxValue = ( (maxValue > (int ) ( ((int ) ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) > (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))) ? maxValue : ((int ) ( ((int ) ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) > (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) > (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20)))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))));
    # 426 "sharpness_fuse.cpp"
    minValue = (int ) ( ((int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) < (int ) ( ((int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) < (int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1))))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 - 1))) : ( ((int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) < (int ) (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 - 1) * width_3 + w_20 + 1)))));
    # 427 "sharpness_fuse.cpp"
    minValue = ( (minValue < (int ) ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) < (int ) ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (int ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (int ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))))) ? minValue : ((int ) ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) < (int ) ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (int ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1))))) ? (*(yPlane_3 + (h_20 * width_3 + w_20 - 1))) : ( ((int ) (*(yPlane_3 + (h_20 * width_3 + w_20))) < (int ) (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))) ? (*(yPlane_3 + (h_20 * width_3 + w_20))) : (*(yPlane_3 + (h_20 * width_3 + w_20 + 1)))))));
    # 428 "sharpness_fuse.cpp"
    minValue = ( (minValue < (int ) ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) < (int ) ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))))) ? minValue : ((int ) ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) < (int ) ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1))))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 - 1))) : ( ((int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) < (int ) (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))) ? (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20))) : (*(yPlane_3 + ((h_20 + 1) * width_3 + w_20 + 1)))))));
    # 432 "sharpness_fuse.cpp"
    double cutoff2Order;
    # 432 "sharpness_fuse.cpp"
    cutoff2Order = pow((double ) (cutoff3), (double ) ((float) 2. * order3));
    # 433 "sharpness_fuse.cpp"
    double edge2Order;
    # 433 "sharpness_fuse.cpp"
    edge2Order = pow((double ) (*(pEdge_1 + (h_20 * width_3 + w_20))), (double) 2. * (double ) (order3));
    # 434 "sharpness_fuse.cpp"
    oscStrength = ((double ) (peak3_1) * cutoff2Order + (double ) (low3) * edge2Order) / (cutoff2Order + edge2Order);
    # 438 "sharpness_fuse.cpp"
    if (enhanced > maxValue)
    {
     # 440 "sharpness_fuse.cpp"
     *(pSharpness_5 + (h_20 * width_3 + w_20)) = (short ) ( ((double ) (maxValue) + oscStrength * (double ) (enhanced - maxValue) < (double) 255.) ? ((double ) (maxValue) + oscStrength * (double ) (enhanced - maxValue)) : ((double) 255.));
    }
    else
    {
     # 442 "sharpness_fuse.cpp"
     if (enhanced < minValue)
     {
      # 444 "sharpness_fuse.cpp"
      *(pSharpness_5 + (h_20 * width_3 + w_20)) = (short ) ( ((double) 0. > (double ) (minValue) - oscStrength * (double ) (minValue - enhanced)) ? ((double) 0.) : ((double ) (minValue) - oscStrength * (double ) (minValue - enhanced)));
     }
     else
     {
      # 448 "sharpness_fuse.cpp"
      *(pSharpness_5 + (h_20 * width_3 + w_20)) = (short ) ( (( (enhanced > 0) ? enhanced : 0) < 255) ? ( (enhanced > 0) ? enhanced : 0) : 255);
     }
    }
   }
  }
  # 417 "sharpness_fuse.cpp"
 }
}
#endif /* __GPUCODE__ */



# 417 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_408_internal_1(cl_int width_62, cl_int height_32, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_13, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pEdge_9, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pSharpness_6, cl_float cutoff3_2, cl_float order3_2, cl_float peak3_2, cl_float low3_2)
{
 # 417 "sharpness_fuse.cpp"
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
  __hmppcg_call.addLocalParameter(&pSharpness_6, 8, "pSharpness_5");
  __hmppcg_call.addLocalParameter((float) (peak3_2), "peak3_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_62), "width_3");
  __hmppcg_call.addLocalParameter(&yPlane_13, 8, "yPlane_3");
  __hmppcg_call.launch(hmpp_acc_region_main_408_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 417 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_408(cl_int width_43, cl_int height_21, cl_char* yPlane_8, cl_short* pEdge_5, cl_short* pSharpness_2, cl_float cutoff3_1, cl_float order3_1, cl_float peak3, cl_float low3_1)
{
 # 458 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_408_internal_1(width_43, height_21, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlane_8), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pEdge_5), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pSharpness_2), cutoff3_1, order3_1, peak3, low3_1));
}
#endif /* __GPUCODE__ */



# 458 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_462_parallel_region_1(int height_2, __global short* pSharpness_1, int width_2, __global uchar* yPlane_2)
{
 # 460 "sharpness_fuse.cpp"
 {
  # 465 "sharpness_fuse.cpp"
  int iter_per_gang_2;
  # 465 "sharpness_fuse.cpp"
  int first_gang_iter_2;
  # 465 "sharpness_fuse.cpp"
  int last_gang_iter_2;
  # 465 "sharpness_fuse.cpp"
  iter_per_gang_2 = ((1 + (height_2 * width_2 - 1) / 192) > 256 ? (1 + (height_2 * width_2 - 1) / 192) : 256);
  # 465 "sharpness_fuse.cpp"
  first_gang_iter_2 = get_group_id(0) * iter_per_gang_2;
  # 465 "sharpness_fuse.cpp"
  last_gang_iter_2 = ((first_gang_iter_2 + iter_per_gang_2 - 1) < (height_2 * width_2 - 1) ? (first_gang_iter_2 + iter_per_gang_2 - 1) : (height_2 * width_2 - 1));
  # 465 "sharpness_fuse.cpp"
  int h_26;
  # 465 "sharpness_fuse.cpp"
  # 469 "sharpness_fuse.cpp"
  for (h_26 = first_gang_iter_2 + get_local_id(1) ; h_26 <= last_gang_iter_2 ; h_26 = h_26 + get_local_size(1))
  {
   # 465 "sharpness_fuse.cpp"
   int h_21;
   # 468 "sharpness_fuse.cpp"
   int w_21;
   # 470 "sharpness_fuse.cpp"
   w_21 = h_26 % width_2;
   # 470 "sharpness_fuse.cpp"
   h_21 = h_26 / width_2;
   # 470 "sharpness_fuse.cpp"
   *(yPlane_2 + (h_21 * width_2 + w_21)) = (uchar ) ( ((int ) (*(pSharpness_1 + (h_21 * width_2 + w_21))) > 255) ? 255 : ( ((int ) (*(pSharpness_1 + (h_21 * width_2 + w_21))) < 0) ? 0 : ((int ) (*(pSharpness_1 + (h_21 * width_2 + w_21))))));
  }
  # 458 "sharpness_fuse.cpp"
 }
}
#endif /* __GPUCODE__ */



# 458 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_462_internal_1(cl_int width_61, cl_int height_31, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_12, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short>  pSharpness_8)
{
 # 458 "sharpness_fuse.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter((hmpprt::s32) (height_31), "height_2");
  __hmppcg_call.addLocalParameter(&pSharpness_8, 8, "pSharpness_1");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (width_61), "width_2");
  __hmppcg_call.addLocalParameter(&yPlane_12, 8, "yPlane_2");
  __hmppcg_call.launch(hmpp_acc_region_main_462_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 458 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_462(cl_int width_34, cl_int height_20, cl_char* yPlane_7, cl_short* pSharpness_4)
{
 # 23 "sharpness_fuse.cpp"
 (hmpp_acc_region_main_462_internal_1(width_34, height_20, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlane_7), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_short> (pSharpness_4)));
}
#endif /* __GPUCODE__ */



# 23 "sharpness_fuse.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_main_82_parallel_region_1(int height_1, int quarterWidth_1, int width_1, __global uchar* yPlaneDown_1, __global uchar* yPlane_1)
{
 # 25 "sharpness_fuse.cpp"
 {
  # 85 "sharpness_fuse.cpp"
  int iter_per_gang_1;
  # 85 "sharpness_fuse.cpp"
  int first_gang_iter_1;
  # 85 "sharpness_fuse.cpp"
  int last_gang_iter_1;
  # 85 "sharpness_fuse.cpp"
  iter_per_gang_1 = ((1 + ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1) / 192) > 256 ? (1 + ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1) / 192) : 256);
  # 85 "sharpness_fuse.cpp"
  first_gang_iter_1 = get_group_id(0) * iter_per_gang_1;
  # 85 "sharpness_fuse.cpp"
  last_gang_iter_1 = ((first_gang_iter_1 + iter_per_gang_1 - 1) < ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1) ? (first_gang_iter_1 + iter_per_gang_1 - 1) : ((height_1 + 3) / 4 * ((width_1 + 3) / 4) - 1));
  # 85 "sharpness_fuse.cpp"
  int i_5;
  # 85 "sharpness_fuse.cpp"
  # 89 "sharpness_fuse.cpp"
  for (i_5 = first_gang_iter_1 + get_local_id(1) ; i_5 <= last_gang_iter_1 ; i_5 = i_5 + get_local_size(1))
  {
   # 85 "sharpness_fuse.cpp"
   uchar tbt_1;
   # 85 "sharpness_fuse.cpp"
   int tbt_2;
   # 85 "sharpness_fuse.cpp"
   int tbt_3;
   # 85 "sharpness_fuse.cpp"
   int i_3;
   # 88 "sharpness_fuse.cpp"
   int j_3;
   # 90 "sharpness_fuse.cpp"
   j_3 = i_5 % ((width_1 + 3) / 4);
   # 90 "sharpness_fuse.cpp"
   i_3 = i_5 / ((width_1 + 3) / 4);
   # 90 "sharpness_fuse.cpp"
   tbt_1 = *(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4 + 3));
   # 90 "sharpness_fuse.cpp"
   tbt_2 = (int ) (*(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4 + 2)));
   # 90 "sharpness_fuse.cpp"
   tbt_3 = (int ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4))) + (int ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4 + 1))) + (int ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4 + 2))) + (int ) (*(yPlane_1 + (i_3 * 4 * width_1 + j_3 * 4 + 3))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 1) * width_1 + j_3 * 4 + 1)));
   # 90 "sharpness_fuse.cpp"
   *(yPlaneDown_1 + (i_3 * 4 / 4 * quarterWidth_1 + j_3 * 4 / 4)) = (uchar ) (tbt_3 + tbt_2 + (int ) (tbt_1) + (int ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4 + 1))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4 + 2))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 2) * width_1 + j_3 * 4 + 3))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4 + 1))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4 + 2))) + (int ) (*(yPlane_1 + ((i_3 * 4 + 3) * width_1 + j_3 * 4 + 3))) + 8 >> 4);
  }
  # 23 "sharpness_fuse.cpp"
 }
}
#endif /* __GPUCODE__ */



# 23 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_main_82_internal_1(cl_int width_60, cl_int height_30, cl_int quarterWidth_23, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlane_11, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char>  yPlaneDown_15)
{
 # 23 "sharpness_fuse.cpp"
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
  __hmppcg_call.launch(hmpp_acc_region_main_82_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 23 "sharpness_fuse.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_main_82(cl_int width_32, cl_int height_16, cl_int quarterWidth_9, cl_char* yPlane_6, cl_char* yPlaneDown_7)
{
 # 1 "<preprocessor>"
 (hmpp_acc_region_main_82_internal_1(width_32, height_16, quarterWidth_9, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlane_6), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_char> (yPlaneDown_7)));
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
      hmpp_acc_region_main_105_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_105_parallel_region_1");
      hmpp_acc_region_main_117_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_117_parallel_region_1");
      hmpp_acc_region_main_138_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_138_loop1D_1");
      hmpp_acc_region_main_151_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_151_loop1D_1");
      hmpp_acc_region_main_159_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_159_loop1D_1");
      hmpp_acc_region_main_172_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_172_loop1D_1");
      hmpp_acc_region_main_189_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_189_loop1D_1");
      hmpp_acc_region_main_211_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_211_loop1D_1");
      hmpp_acc_region_main_220_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_220_loop1D_1");
      hmpp_acc_region_main_232_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_232_loop1D_1");
      hmpp_acc_region_main_244_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_244_loop1D_1");
      hmpp_acc_region_main_267_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_267_loop1D_1");
      hmpp_acc_region_main_279_loop1D_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_279_loop1D_1");
      hmpp_acc_region_main_316_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_316_parallel_region_1");
      reduce_s64_add_xy = new hmpprt::OpenCLGrid(hmpprt_module, "reduce_s64_add_xy");
      hmpp_acc_region_main_339_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_339_parallel_region_1");
      hmpp_acc_region_main_376_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_376_parallel_region_1");
      hmpp_acc_region_main_389_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_389_parallel_region_1");
      hmpp_acc_region_main_408_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_408_parallel_region_1");
      hmpp_acc_region_main_462_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_462_parallel_region_1");
      hmpp_acc_region_main_82_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_main_82_parallel_region_1");

    }
    hmpprt::Context::getInstance()->getGrouplet()->setTarget(hmpprt::OPENCL);
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_105", "prototype hmpp_acc_region_main_105(width: s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^openclglob u8, yPlaneDown: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_117", "prototype hmpp_acc_region_main_117(width: s32, quarterHeight: s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_138", "prototype hmpp_acc_region_main_138(width: ^host s32, height: s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_151", "prototype hmpp_acc_region_main_151(width: ^host s32, quarterWidth: s32, yPlaneCSER: ^openclglob u8, yPlaneDown: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_159", "prototype hmpp_acc_region_main_159(width: ^host s32, height: ^host s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^openclglob u8, yPlaneDown: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_172", "prototype hmpp_acc_region_main_172(width: ^host s32, quarterWidth: s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_189", "prototype hmpp_acc_region_main_189(width: ^host s32, height: ^host s32, quarterWidth: s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_211", "prototype hmpp_acc_region_main_211(width: ^host s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_220", "prototype hmpp_acc_region_main_220(width: ^host s32, height: ^host s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_232", "prototype hmpp_acc_region_main_232(width: ^host s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^openclglob u8, yPlaneDown: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_244", "prototype hmpp_acc_region_main_244(width: ^host s32, quarterHeight: s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_267", "prototype hmpp_acc_region_main_267(width: ^host s32, height: s32, yPlaneCSER: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_279", "prototype hmpp_acc_region_main_279(width: ^host s32, quarterWidth: s32, quarterHeight: s32, yPlaneCSER: ^openclglob u8, yPlaneDown: ^openclglob u8)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_316", "prototype hmpp_acc_region_main_316(width: s32, height: s32, yPlane: ^openclglob u8, pEdge: ^openclglob s16)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_339", "prototype hmpp_acc_region_main_339(width: s32, height: s32, pEdge: ^openclglob s16, sum: ^openclglob s64)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_376", "prototype hmpp_acc_region_main_376(width: s32, height: s32, yPlane: ^openclglob u8, yPlaneCSER: ^openclglob u8, pError: ^openclglob s16)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_389", "prototype hmpp_acc_region_main_389(width: s32, height: s32, yPlaneCSER: ^openclglob u8, pError: ^openclglob s16, pEdge: ^openclglob s16, pSharpness: ^openclglob s16, cutoff: double, peak: double, cutoff2: double, order: double, order2: double, low: double)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_408", "prototype hmpp_acc_region_main_408(width: s32, height: s32, yPlane: ^openclglob u8, pEdge: ^openclglob s16, pSharpness: ^openclglob s16, cutoff3: float, order3: float, peak3: float, low3: float)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_462", "prototype hmpp_acc_region_main_462(width: s32, height: s32, yPlane: ^openclglob u8, pSharpness: ^openclglob s16)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_main_82", "prototype hmpp_acc_region_main_82(width: s32, height: s32, quarterWidth: s32, yPlane: ^openclglob u8, yPlaneDown: ^openclglob u8)");

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
      delete hmpp_acc_region_main_105_parallel_region_1;
      delete hmpp_acc_region_main_117_parallel_region_1;
      delete hmpp_acc_region_main_138_loop1D_1;
      delete hmpp_acc_region_main_151_loop1D_1;
      delete hmpp_acc_region_main_159_loop1D_1;
      delete hmpp_acc_region_main_172_loop1D_1;
      delete hmpp_acc_region_main_189_loop1D_1;
      delete hmpp_acc_region_main_211_loop1D_1;
      delete hmpp_acc_region_main_220_loop1D_1;
      delete hmpp_acc_region_main_232_loop1D_1;
      delete hmpp_acc_region_main_244_loop1D_1;
      delete hmpp_acc_region_main_267_loop1D_1;
      delete hmpp_acc_region_main_279_loop1D_1;
      delete hmpp_acc_region_main_316_parallel_region_1;
      delete reduce_s64_add_xy;
      delete hmpp_acc_region_main_339_parallel_region_1;
      delete hmpp_acc_region_main_376_parallel_region_1;
      delete hmpp_acc_region_main_389_parallel_region_1;
      delete hmpp_acc_region_main_408_parallel_region_1;
      delete hmpp_acc_region_main_462_parallel_region_1;
      delete hmpp_acc_region_main_82_parallel_region_1;

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
