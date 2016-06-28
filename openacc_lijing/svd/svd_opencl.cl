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

# 363 "svd.cpp"

#ifdef __GPUCODE__
double reduce_double_add_x(double priv, local double* tmpa, double orig)
;
#endif /* __GPUCODE__ */



# 363 "svd.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_svd_363(cl_double* A_H_1, cl_double* B_H_2, cl_double* S_H_3)
;
#endif /* __GPUCODE__ */



# 363 "svd.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_svd_363_internal_1(hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  A_H_7, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  B_H_1, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  S_H_5)
;
#endif /* __GPUCODE__ */



# 325 "svd.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_svd_363_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_svd_363_parallel_region_1(__global double* A_H_4, __global double* B_H, __global double* S_H_1);
#endif // __GPUCODE__
# 325 "svd.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_svd_332(cl_double* A_H_5, cl_double* S_H_2, cl_double* ci_3)
;
#endif /* __GPUCODE__ */



# 325 "svd.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_svd_332_internal_1(hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  A_H_8, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  S_H_4, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  ci_5)
;
#endif /* __GPUCODE__ */



# 60 "svd.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_svd_332_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_svd_332_parallel_region_1(__global double* A_H_2, __global double* S_H, __global double* ci_1);
#endif // __GPUCODE__
# 60 "svd.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_svd_124(cl_int* pass_3, cl_double* A_H_6, cl_double* V_H_2, cl_int* rotate_col_idx_2, cl_double* ci_4, cl_double* cj_2, cl_double* vi_2, cl_double* vj_2, cl_int start_index_2)
;
#endif /* __GPUCODE__ */



# 60 "svd.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_svd_124_internal_1(cl_int* pass, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  A_H, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  V_H_1, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int>  rotate_col_idx_1, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  ci_2, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  cj_1, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  vi_1, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  vj_1, cl_int start_index)
;
#endif /* __GPUCODE__ */



# 60 "svd.cpp"

#ifndef __GPUCODE__
static hmpprt::OpenCLGrid * hmpp_acc_region_svd_124_parallel_region_1 = 0;
#else
__kernel  void hmpp_acc_region_svd_124_parallel_region_1(__global double* A_H_3, __global double* V_H, __global double* ci, __global double* cj, __global int* pass_1, __global int* rotate_col_idx, int start_index_1, __global double* value_1, __global double* vi, __global double* vj);
#endif // __GPUCODE__
# 60 "svd.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(32, 8, 1)))  void hmpp_acc_region_svd_124_parallel_region_1(__global double* A_H_3, __global double* V_H, __global double* ci, __global double* cj, __global int* pass_1, __global int* rotate_col_idx, int start_index_1, __global double* value_1, __global double* vi, __global double* vj)
{
 
 local double tmpr_2[256];
 
 # 62 "svd.cpp"
 {
  # 127 "svd.cpp"
  int iter_per_gang_3;
  # 127 "svd.cpp"
  int first_gang_iter_3;
  # 127 "svd.cpp"
  int last_gang_iter_3;
  # 127 "svd.cpp"
  iter_per_gang_3 = ((1 + ((256 - start_index_1) / 2 - 1) / 192) > 8 ? (1 + ((256 - start_index_1) / 2 - 1) / 192) : 8);
  # 127 "svd.cpp"
  first_gang_iter_3 = get_group_id(0) * iter_per_gang_3;
  # 127 "svd.cpp"
  last_gang_iter_3 = ((first_gang_iter_3 + iter_per_gang_3 - 1) < ((256 - start_index_1) / 2 - 1) ? (first_gang_iter_3 + iter_per_gang_3 - 1) : ((256 - start_index_1) / 2 - 1));
  # 127 "svd.cpp"
  int j_2;
  # 127 "svd.cpp"
  # 128 "svd.cpp"
  for (j_2 = first_gang_iter_3 + get_local_id(1) ; j_2 <= last_gang_iter_3 ; j_2 = j_2 + get_local_size(1))
  {
   # 133 "svd.cpp"
   int col_p;
   # 133 "svd.cpp"
   col_p = *(rotate_col_idx + (j_2 * 2 + (start_index_1 + 1) - 1));
   # 134 "svd.cpp"
   int col_q;
   # 134 "svd.cpp"
   col_q = *(rotate_col_idx + (j_2 * 2 + (start_index_1 + 1)));
   # 135 "svd.cpp"
   double real1;
   # 136 "svd.cpp"
   double imag1;
   # 142 "svd.cpp"
   int k_18;
   # 142 "svd.cpp"
   # 143 "svd.cpp"
   for (k_18 = get_local_id(0) ; k_18 <= 255 ; k_18 = k_18 + get_local_size(0))
   {
    # 144 "svd.cpp"
    *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_18) = *(A_H_3 + (col_p * 256 + k_18));
    # 145 "svd.cpp"
    *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_18)) = *(A_H_3 + (65536 + col_p * 256 + k_18));
   }
   # 150 "svd.cpp"
   # 150 "svd.cpp"
   int k_19;
   # 150 "svd.cpp"
   # 151 "svd.cpp"
   for (k_19 = get_local_id(0) ; k_19 <= 255 ; k_19 = k_19 + get_local_size(0))
   {
    # 152 "svd.cpp"
    *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_19) = *(A_H_3 + (col_q * 256 + k_19));
    # 153 "svd.cpp"
    *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_19)) = *(A_H_3 + (65536 + col_q * 256 + k_19));
   }
   # 158 "svd.cpp"
   # 158 "svd.cpp"
   int k_20;
   # 158 "svd.cpp"
   # 159 "svd.cpp"
   for (k_20 = get_local_id(0) ; k_20 <= 255 ; k_20 = k_20 + get_local_size(0))
   {
    # 160 "svd.cpp"
    *(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_20) = *(V_H + (col_p * 256 + k_20));
    # 161 "svd.cpp"
    *(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_20)) = *(V_H + (65536 + col_p * 256 + k_20));
   }
   # 166 "svd.cpp"
   # 166 "svd.cpp"
   int k_21;
   # 166 "svd.cpp"
   # 167 "svd.cpp"
   for (k_21 = get_local_id(0) ; k_21 <= 255 ; k_21 = k_21 + get_local_size(0))
   {
    # 168 "svd.cpp"
    *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_21) = *(V_H + (col_q * 256 + k_21));
    # 169 "svd.cpp"
    *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_21)) = *(V_H + (65536 + col_q * 256 + k_21));
   }
   # 172 "svd.cpp"
   # 172 "svd.cpp"
   int skip_trans;
   # 172 "svd.cpp"
   skip_trans = 0;
   # 136 "svd.cpp"
   double imag1_1;
   # 135 "svd.cpp"
   imag1_1 = 0;
   # 135 "svd.cpp"
   double real1_1;
   # 176 "svd.cpp"
   real1_1 = 0;
   # 176 "svd.cpp"
   int k_22;
   # 176 "svd.cpp"
   # 177 "svd.cpp"
   for (k_22 = get_local_id(0) ; k_22 <= 255 ; k_22 = k_22 + get_local_size(0))
   {
    # 178 "svd.cpp"
    real1_1 = real1_1 + (*(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_22) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_22) + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_22)) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_22)));
    # 179 "svd.cpp"
    imag1_1 = imag1_1 + (*(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_22) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_22)) - *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (256 + k_22)) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_22));
   }
   # 181 "svd.cpp"
   # 181 "svd.cpp"
   real1 = (reduce_double_add_x(real1_1, tmpr_2, (double) 0.));
   # 181 "svd.cpp"
   imag1 = (reduce_double_add_x(imag1_1, tmpr_2, (double) 0.));
   # 181 "svd.cpp"
   *(value_1 + (j_2 * 2 + (start_index_1 + 1)) / 2) = sqrt(real1 * real1 + imag1 * imag1);
   # 183 "svd.cpp"
   if (*(value_1 + (j_2 * 2 + (start_index_1 + 1)) / 2) < (double) 1.0000000000000000818e-05)
   {
    # 184 "svd.cpp"
    skip_trans = 1;
   }
   # 186 "svd.cpp"
   if (skip_trans == 0)
   {
    # 188 "svd.cpp"
    *pass_1 = 0;
    # 192 "svd.cpp"
    double result1;
    # 193 "svd.cpp"
    double result2;
    # 194 "svd.cpp"
    double result3;
    # 195 "svd.cpp"
    double result4;
    # 196 "svd.cpp"
    double result5;
    # 197 "svd.cpp"
    double result6;
    # 198 "svd.cpp"
    double result7;
    # 199 "svd.cpp"
    double result8;
    # 192 "svd.cpp"
    double result1_1;
    # 202 "svd.cpp"
    result1_1 = 0;
    # 202 "svd.cpp"
    int k_23;
    # 202 "svd.cpp"
    # 203 "svd.cpp"
    for (k_23 = get_local_id(0) ; k_23 <= 255 ; k_23 = k_23 + get_local_size(0))
    {
     # 203 "svd.cpp"
     result1_1 = result1_1 + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_23) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_23 + 256));
    }
    # 193 "svd.cpp"
    # 193 "svd.cpp"
    result1 = (reduce_double_add_x(result1_1, tmpr_2, (double) 0.));
    # 193 "svd.cpp"
    double result2_1;
    # 208 "svd.cpp"
    result2_1 = 0;
    # 208 "svd.cpp"
    int k_24;
    # 208 "svd.cpp"
    # 209 "svd.cpp"
    for (k_24 = get_local_id(0) ; k_24 <= 255 ; k_24 = k_24 + get_local_size(0))
    {
     # 209 "svd.cpp"
     result2_1 = result2_1 + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_24 + 256)) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_24);
    }
    # 194 "svd.cpp"
    # 194 "svd.cpp"
    result2 = (reduce_double_add_x(result2_1, tmpr_2, (double) 0.));
    # 194 "svd.cpp"
    double result3_1;
    # 214 "svd.cpp"
    result3_1 = 0;
    # 214 "svd.cpp"
    int k_25;
    # 214 "svd.cpp"
    # 215 "svd.cpp"
    for (k_25 = get_local_id(0) ; k_25 <= 255 ; k_25 = k_25 + get_local_size(0))
    {
     # 215 "svd.cpp"
     result3_1 = result3_1 + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_25) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_25);
    }
    # 195 "svd.cpp"
    # 195 "svd.cpp"
    result3 = (reduce_double_add_x(result3_1, tmpr_2, (double) 0.));
    # 195 "svd.cpp"
    double result4_1;
    # 220 "svd.cpp"
    result4_1 = 0;
    # 220 "svd.cpp"
    int k_26;
    # 220 "svd.cpp"
    # 221 "svd.cpp"
    for (k_26 = get_local_id(0) ; k_26 <= 255 ; k_26 = k_26 + get_local_size(0))
    {
     # 221 "svd.cpp"
     result4_1 = result4_1 + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_26 + 256)) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_26 + 256));
    }
    # 224 "svd.cpp"
    # 224 "svd.cpp"
    result4 = (reduce_double_add_x(result4_1, tmpr_2, (double) 0.));
    # 224 "svd.cpp"
    double a;
    # 224 "svd.cpp"
    a = result1 - result2;
    # 225 "svd.cpp"
    double b;
    # 225 "svd.cpp"
    b = result3 + result4;
    # 227 "svd.cpp"
    double s_a2b2;
    # 50 "svd.cpp"
    int rvalue_1;
    # 50 "svd.cpp"
    if (b > (double) 0.)
    {
     # 53 "svd.cpp"
     rvalue_1 = 1;
     # 53 "svd.cpp"
     goto endf_2;
    }
    # 53 "svd.cpp"
    if (b == (double) 0.)
    {
     # 227 "svd.cpp"
     rvalue_1 = 0;
     # 227 "svd.cpp"
     goto endf_2;
    }
    # 227 "svd.cpp"
    rvalue_1 =  -1;
    # 227 "svd.cpp"
    endf_2:;
    # 227 "svd.cpp"
    s_a2b2 = (double ) (rvalue_1) * sqrt(a * a + b * b);
    # 228 "svd.cpp"
    double sin_alpha;
    # 228 "svd.cpp"
    sin_alpha = a / s_a2b2;
    # 229 "svd.cpp"
    double cos_alpha;
    # 229 "svd.cpp"
    cos_alpha = b / s_a2b2;
    # 230 "svd.cpp"
    double m;
    # 230 "svd.cpp"
    m =  -(b * cos_alpha + a * sin_alpha);
    # 196 "svd.cpp"
    double result5_1;
    # 235 "svd.cpp"
    result5_1 = 0;
    # 235 "svd.cpp"
    int k_27;
    # 235 "svd.cpp"
    # 236 "svd.cpp"
    for (k_27 = get_local_id(0) ; k_27 <= 255 ; k_27 = k_27 + get_local_size(0))
    {
     # 236 "svd.cpp"
     result5_1 = result5_1 + *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_27) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_27);
    }
    # 197 "svd.cpp"
    # 197 "svd.cpp"
    result5 = (reduce_double_add_x(result5_1, tmpr_2, (double) 0.));
    # 197 "svd.cpp"
    double result6_1;
    # 241 "svd.cpp"
    result6_1 = 0;
    # 241 "svd.cpp"
    int k_28;
    # 241 "svd.cpp"
    # 242 "svd.cpp"
    for (k_28 = get_local_id(0) ; k_28 <= 255 ; k_28 = k_28 + get_local_size(0))
    {
     # 242 "svd.cpp"
     result6_1 = result6_1 + *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_28 + 256)) * *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_28 + 256));
    }
    # 198 "svd.cpp"
    # 198 "svd.cpp"
    result6 = (reduce_double_add_x(result6_1, tmpr_2, (double) 0.));
    # 198 "svd.cpp"
    double result7_1;
    # 247 "svd.cpp"
    result7_1 = 0;
    # 247 "svd.cpp"
    int k_29;
    # 247 "svd.cpp"
    # 248 "svd.cpp"
    for (k_29 = get_local_id(0) ; k_29 <= 255 ; k_29 = k_29 + get_local_size(0))
    {
     # 248 "svd.cpp"
     result7_1 = result7_1 + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_29) * *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_29);
    }
    # 199 "svd.cpp"
    # 199 "svd.cpp"
    result7 = (reduce_double_add_x(result7_1, tmpr_2, (double) 0.));
    # 199 "svd.cpp"
    double result8_1;
    # 253 "svd.cpp"
    result8_1 = 0;
    # 253 "svd.cpp"
    int k_30;
    # 253 "svd.cpp"
    # 254 "svd.cpp"
    for (k_30 = get_local_id(0) ; k_30 <= 255 ; k_30 = k_30 + get_local_size(0))
    {
     # 254 "svd.cpp"
     result8_1 = result8_1 + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_30 + 256)) * *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_30 + 256));
    }
    # 257 "svd.cpp"
    # 257 "svd.cpp"
    result8 = (reduce_double_add_x(result8_1, tmpr_2, (double) 0.));
    # 257 "svd.cpp"
    double n_1;
    # 257 "svd.cpp"
    n_1 = (double) 0.5 * (result5 + result6 - result7 - result8);
    # 258 "svd.cpp"
    double w;
    # 50 "svd.cpp"
    int rvalue_2;
    # 50 "svd.cpp"
    if (n_1 > (double) 0.)
    {
     # 53 "svd.cpp"
     rvalue_2 = 1;
     # 53 "svd.cpp"
     goto endf_3;
    }
    # 53 "svd.cpp"
    if (n_1 == (double) 0.)
    {
     # 258 "svd.cpp"
     rvalue_2 = 0;
     # 258 "svd.cpp"
     goto endf_3;
    }
    # 258 "svd.cpp"
    rvalue_2 =  -1;
    # 258 "svd.cpp"
    endf_3:;
    # 258 "svd.cpp"
    w = (double ) (rvalue_2) * m / sqrt(m * m + n_1 * n_1);
    # 260 "svd.cpp"
    double sin_x;
    # 260 "svd.cpp"
    sin_x = w / sqrt((double) 2. * ((double) 1. + sqrt((double) 1. - w * w)));
    # 261 "svd.cpp"
    double cos_x;
    # 261 "svd.cpp"
    cos_x = sqrt((double) 1. - sin_x * sin_x);
    # 264 "svd.cpp"
    double real2;
    # 265 "svd.cpp"
    double imag2;
    # 266 "svd.cpp"
    double real3;
    # 267 "svd.cpp"
    double imag3;
    # 268 "svd.cpp"
    double real4;
    # 269 "svd.cpp"
    double imag4;
    # 270 "svd.cpp"
    double real5;
    # 271 "svd.cpp"
    double imag5;
    # 274 "svd.cpp"
    int k_31;
    # 274 "svd.cpp"
    # 275 "svd.cpp"
    for (k_31 = get_local_id(0) ; k_31 <= 255 ; k_31 = k_31 + get_local_size(0))
    {
     # 276 "svd.cpp"
     real2 = *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_31) * cos_x + *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_31) * cos_alpha * sin_x + *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_31 + 256)) * sin_alpha * sin_x;
     # 277 "svd.cpp"
     imag2 = *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_31 + 256)) * cos_x + *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_31 + 256)) * cos_alpha * sin_x - *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_31) * sin_alpha * sin_x;
     # 279 "svd.cpp"
     *(A_H_3 + (col_p * 256 + k_31)) = real2;
     # 280 "svd.cpp"
     *(A_H_3 + (65536 + col_p * 256 + k_31)) = imag2;
    }
    # 285 "svd.cpp"
    # 285 "svd.cpp"
    int k_32;
    # 285 "svd.cpp"
    # 286 "svd.cpp"
    for (k_32 = get_local_id(0) ; k_32 <= 255 ; k_32 = k_32 + get_local_size(0))
    {
     # 287 "svd.cpp"
     real3 = *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_32) * cos_x +  -*(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_32) * cos_alpha * sin_x + *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_32 + 256)) * sin_alpha * sin_x;
     # 288 "svd.cpp"
     imag3 = *(cj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_32 + 256)) * cos_x +  -*(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_32 + 256)) * cos_alpha * sin_x - *(ci + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_32) * sin_alpha * sin_x;
     # 290 "svd.cpp"
     *(A_H_3 + (col_q * 256 + k_32)) = real3;
     # 291 "svd.cpp"
     *(A_H_3 + (65536 + col_q * 256 + k_32)) = imag3;
    }
    # 296 "svd.cpp"
    # 296 "svd.cpp"
    int k_33;
    # 296 "svd.cpp"
    # 297 "svd.cpp"
    for (k_33 = get_local_id(0) ; k_33 <= 255 ; k_33 = k_33 + get_local_size(0))
    {
     # 298 "svd.cpp"
     real4 = *(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_33) * cos_x + *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_33) * cos_alpha * sin_x + *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_33 + 256)) * sin_alpha * sin_x;
     # 299 "svd.cpp"
     imag4 = *(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_33 + 256)) * cos_x + *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_33 + 256)) * cos_alpha * sin_x - *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_33) * sin_alpha * sin_x;
     # 301 "svd.cpp"
     *(V_H + (col_p * 256 + k_33)) = real4;
     # 302 "svd.cpp"
     *(V_H + (65536 + col_p * 256 + k_33)) = imag4;
    }
    # 307 "svd.cpp"
    # 307 "svd.cpp"
    int k_34;
    # 307 "svd.cpp"
    # 308 "svd.cpp"
    for (k_34 = get_local_id(0) ; k_34 <= 255 ; k_34 = k_34 + get_local_size(0))
    {
     # 309 "svd.cpp"
     real5 = *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_34) * cos_x +  -*(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_34) * cos_alpha * sin_x + *(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_34 + 256)) * sin_alpha * sin_x;
     # 310 "svd.cpp"
     imag5 = *(vj + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_34 + 256)) * cos_x +  -*(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + (k_34 + 256)) * cos_alpha * sin_x - *(vi + (j_2 * 2 + (start_index_1 + 1)) / 2 * 256 * 2 + k_34) * sin_alpha * sin_x;
     # 312 "svd.cpp"
     *(V_H + (col_q * 256 + k_34)) = real5;
     # 313 "svd.cpp"
     *(V_H + (65536 + col_q * 256 + k_34)) = imag5;
    }
    # 317 "svd.cpp"
   }
   # 317 "svd.cpp"
   *(rotate_col_idx + (j_2 * 2 + (start_index_1 + 1) - 1)) = col_q;
   # 318 "svd.cpp"
   *(rotate_col_idx + (j_2 * 2 + (start_index_1 + 1))) = col_p;
  }
  # 60 "svd.cpp"
 }
}
#endif /* __GPUCODE__ */



# 60 "svd.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_svd_124_internal_1(cl_int* pass, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  A_H, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  V_H_1, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int>  rotate_col_idx_1, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  ci_2, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  cj_1, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  vi_1, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  vj_1, cl_int start_index)
{
 # 60 "svd.cpp"
 hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int>  pass_2;
 # 60 "svd.cpp"
 hmpprt::Context::getInstance()->allocate((void **) &pass_2, hmpprt::MS_OPENCL_GLOB, 4);
 # 60 "svd.cpp"
 *pass_2 = *pass;
 # 60 "svd.cpp"
 hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  value_2;
 # 60 "svd.cpp"
 hmpprt::Context::getInstance()->allocate((void **) &value_2, hmpprt::MS_OPENCL_GLOB, 1024u);
 # 60 "svd.cpp"
 hmpprt::DevicePtr<hmpprt::MS_OPENCL_SHARED,cl_double>  tmpr_4;
 # 60 "svd.cpp"
 hmpprt::Context::getInstance()->allocate((void **) &tmpr_4, hmpprt::MS_OPENCL_SHARED, 2048);
 # 60 "svd.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(32);
  __hmppcg_call.setBlockSizeY(8);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter(&A_H, 8, "A_H_3");
  __hmppcg_call.addLocalParameter(&V_H_1, 8, "V_H");
  __hmppcg_call.addLocalParameter(&ci_2, 8, "ci");
  __hmppcg_call.addLocalParameter(&cj_1, 8, "cj");
  __hmppcg_call.addLocalParameter(&pass_2, 8, "pass_1");
  __hmppcg_call.addLocalParameter(&rotate_col_idx_1, 8, "rotate_col_idx");
  __hmppcg_call.addLocalParameter((hmpprt::s32) (start_index), "start_index_1");
  __hmppcg_call.addSharedParameter(tmpr_4, "tmpr_2");
  __hmppcg_call.addLocalParameter(&value_2, 8, "value_1");
  __hmppcg_call.addLocalParameter(&vi_1, 8, "vi");
  __hmppcg_call.addLocalParameter(&vj_1, 8, "vj");
  __hmppcg_call.launch(hmpp_acc_region_svd_124_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
 # 60 "svd.cpp"
 *pass = *pass_2;
 # 60 "svd.cpp"
 hmpprt::Context::getInstance()->free((void **) &pass_2);
 # 60 "svd.cpp"
 hmpprt::Context::getInstance()->free((void **) &value_2);
 # 60 "svd.cpp"
 hmpprt::Context::getInstance()->free((void **) &tmpr_4);
}
#endif /* __GPUCODE__ */



# 60 "svd.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_svd_124(cl_int* pass_3, cl_double* A_H_6, cl_double* V_H_2, cl_int* rotate_col_idx_2, cl_double* ci_4, cl_double* cj_2, cl_double* vi_2, cl_double* vj_2, cl_int start_index_2)
{
 # 325 "svd.cpp"
 (hmpp_acc_region_svd_124_internal_1(pass_3, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double> (A_H_6), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double> (V_H_2), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_int> (rotate_col_idx_2), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double> (ci_4), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double> (cj_2), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double> (vi_2), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double> (vj_2), start_index_2));
}
#endif /* __GPUCODE__ */



# 325 "svd.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(32, 8, 1)))  void hmpp_acc_region_svd_332_parallel_region_1(__global double* A_H_2, __global double* S_H, __global double* ci_1)
{
 
 local double tmpr_1[256];
 
 # 327 "svd.cpp"
 {
  # 335 "svd.cpp"
  int first_gang_iter_2;
  # 335 "svd.cpp"
  int last_gang_iter_2;
  # 335 "svd.cpp"
  first_gang_iter_2 = get_group_id(0) * 8;
  # 335 "svd.cpp"
  last_gang_iter_2 = ((first_gang_iter_2 + 7) < 255 ? (first_gang_iter_2 + 7) : 255);
  # 335 "svd.cpp"
  int i_2;
  # 335 "svd.cpp"
  # 336 "svd.cpp"
  for (i_2 = first_gang_iter_2 + get_local_id(1) ; i_2 <= last_gang_iter_2 ; i_2 = i_2 + get_local_size(1))
  {
   # 337 "svd.cpp"
   double real;
   # 338 "svd.cpp"
   double imag;
   # 341 "svd.cpp"
   int k_35;
   # 341 "svd.cpp"
   # 342 "svd.cpp"
   for (k_35 = get_local_id(0) ; k_35 <= 255 ; k_35 = k_35 + get_local_size(0))
   {
    # 343 "svd.cpp"
    *(ci_1 + i_2 * 256 * 2 + k_35) = *(A_H_2 + (i_2 * 256 + k_35));
    # 344 "svd.cpp"
    *(ci_1 + i_2 * 256 * 2 + (256 + k_35)) = *(A_H_2 + (65536 + i_2 * 256 + k_35));
   }
   # 338 "svd.cpp"
   # 338 "svd.cpp"
   double imag_1;
   # 337 "svd.cpp"
   imag_1 = 0;
   # 337 "svd.cpp"
   double real_1;
   # 349 "svd.cpp"
   real_1 = 0;
   # 349 "svd.cpp"
   int l_1;
   # 349 "svd.cpp"
   # 350 "svd.cpp"
   for (l_1 = get_local_id(0) ; l_1 <= 255 ; l_1 = l_1 + get_local_size(0))
   {
    # 351 "svd.cpp"
    real_1 = real_1 + (*(ci_1 + i_2 * 256 * 2 + l_1) * *(ci_1 + i_2 * 256 * 2 + l_1) + *(ci_1 + i_2 * 256 * 2 + (256 + l_1)) * *(ci_1 + i_2 * 256 * 2 + (256 + l_1)));
    # 352 "svd.cpp"
    imag_1 = imag_1 + (*(ci_1 + i_2 * 256 * 2 + l_1) * *(ci_1 + i_2 * 256 * 2 + (256 + l_1)) - *(ci_1 + i_2 * 256 * 2 + (256 + l_1)) * *(ci_1 + i_2 * 256 * 2 + l_1));
   }
   # 355 "svd.cpp"
   # 355 "svd.cpp"
   real = (reduce_double_add_x(real_1, tmpr_1, (double) 0.));
   # 355 "svd.cpp"
   imag = (reduce_double_add_x(imag_1, tmpr_1, (double) 0.));
   # 355 "svd.cpp"
   double norm_A;
   # 355 "svd.cpp"
   norm_A = sqrt(sqrt(real * real + imag * imag));
   # 356 "svd.cpp"
   *(S_H + i_2) = norm_A;
  }
  # 325 "svd.cpp"
 }
}
#endif /* __GPUCODE__ */



# 325 "svd.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_svd_332_internal_1(hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  A_H_8, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  S_H_4, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  ci_5)
{
 # 325 "svd.cpp"
 hmpprt::DevicePtr<hmpprt::MS_OPENCL_SHARED,cl_double>  tmpr_3;
 # 325 "svd.cpp"
 hmpprt::Context::getInstance()->allocate((void **) &tmpr_3, hmpprt::MS_OPENCL_SHARED, 2048);
 # 325 "svd.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(32);
  __hmppcg_call.setBlockSizeY(8);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter(&A_H_8, 8, "A_H_2");
  __hmppcg_call.addLocalParameter(&S_H_4, 8, "S_H");
  __hmppcg_call.addLocalParameter(&ci_5, 8, "ci_1");
  __hmppcg_call.addSharedParameter(tmpr_3, "tmpr_1");
  __hmppcg_call.launch(hmpp_acc_region_svd_332_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
 # 325 "svd.cpp"
 hmpprt::Context::getInstance()->free((void **) &tmpr_3);
}
#endif /* __GPUCODE__ */



# 325 "svd.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_svd_332(cl_double* A_H_5, cl_double* S_H_2, cl_double* ci_3)
{
 # 363 "svd.cpp"
 (hmpp_acc_region_svd_332_internal_1(hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double> (A_H_5), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double> (S_H_2), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double> (ci_3)));
}
#endif /* __GPUCODE__ */



# 363 "svd.cpp"

#ifdef __GPUCODE__

__kernel __attribute__((reqd_work_group_size(1, 256, 1)))  void hmpp_acc_region_svd_363_parallel_region_1(__global double* A_H_4, __global double* B_H, __global double* S_H_1)
{
 # 365 "svd.cpp"
 {
  # 366 "svd.cpp"
  int first_gang_iter_1;
  # 366 "svd.cpp"
  int last_gang_iter_1;
  # 366 "svd.cpp"
  first_gang_iter_1 = get_group_id(0) * 342;
  # 366 "svd.cpp"
  last_gang_iter_1 = ((first_gang_iter_1 + 341) < 65535 ? (first_gang_iter_1 + 341) : 65535);
  # 366 "svd.cpp"
  int j_4;
  # 366 "svd.cpp"
  # 369 "svd.cpp"
  for (j_4 = first_gang_iter_1 + get_local_id(1) ; j_4 <= last_gang_iter_1 ; j_4 = j_4 + get_local_size(1))
  {
   # 366 "svd.cpp"
   int j_3;
   # 368 "svd.cpp"
   int i_3;
   # 370 "svd.cpp"
   i_3 = j_4 % 256;
   # 370 "svd.cpp"
   j_3 = j_4 / 256;
   # 370 "svd.cpp"
   *(B_H + (j_3 * 256 + i_3)) = *(A_H_4 + (j_3 * 256 + i_3)) / *(S_H_1 + j_3);
   # 371 "svd.cpp"
   *(B_H + (65536 + j_3 * 256 + i_3)) = *(A_H_4 + (65536 + j_3 * 256 + i_3)) / *(S_H_1 + j_3);
  }
  # 363 "svd.cpp"
 }
}
#endif /* __GPUCODE__ */



# 363 "svd.cpp"

#ifndef __GPUCODE__
void hmpp_acc_region_svd_363_internal_1(hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  A_H_7, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  B_H_1, hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double>  S_H_5)
{
 # 363 "svd.cpp"
 if (1)
 {
  hmpprt::OpenCLGridCall __hmppcg_call;
  __hmppcg_call.setSizeX(192);
  __hmppcg_call.setSizeY(1);
  __hmppcg_call.setBlockSizeX(1);
  __hmppcg_call.setBlockSizeY(256);
  __hmppcg_call.setWorkDim(2);
  __hmppcg_call.addLocalParameter(&A_H_7, 8, "A_H_4");
  __hmppcg_call.addLocalParameter(&B_H_1, 8, "B_H");
  __hmppcg_call.addLocalParameter(&S_H_5, 8, "S_H_1");
  __hmppcg_call.launch(hmpp_acc_region_svd_363_parallel_region_1, hmpprt::Context::getInstance()->getOpenCLDevice());
 }
 ;
}
#endif /* __GPUCODE__ */



# 363 "svd.cpp"

#ifndef __GPUCODE__
extern "C" CDLT_API  void hmpp_acc_region_svd_363(cl_double* A_H_1, cl_double* B_H_2, cl_double* S_H_3)
{
 # 1 "<preprocessor>"
 (hmpp_acc_region_svd_363_internal_1(hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double> (A_H_1), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double> (B_H_2), hmpprt::DevicePtr<hmpprt::MS_OPENCL_GLOB,cl_double> (S_H_3)));
}
#endif /* __GPUCODE__ */



# 1 "<preprocessor>"

#ifdef __GPUCODE__
double reduce_double_add_x(double priv, local double* tmpa, double orig)
{
 # 1 "<preprocessor>"
 tmpa[get_local_id(1) + get_local_size(1) * get_local_id(0)] = priv;
 # 1 "<preprocessor>"
 int n;
 # 1 "<preprocessor>"
 # 1 "<preprocessor>"
 for (n = (get_local_size(0) - 1 >> 1) + 1 ; n > 0 ; n = (n >> 1))
 {
  # 1 "<preprocessor>"
  int next;
  # 1 "<preprocessor>"
  next = get_local_id(0) + n;
  # 1 "<preprocessor>"
  if (get_local_id(0) < n && next < get_local_size(0))
  {
   # 1 "<preprocessor>"
   tmpa[get_local_id(1) + get_local_size(1) * get_local_id(0)] = tmpa[get_local_id(1) + get_local_size(1) * get_local_id(0)] + tmpa[get_local_id(1) + get_local_size(1) * next];
  }
 }
 # 1 "<preprocessor>"
 # 1 "<preprocessor>"
 return tmpa[get_local_id(1)] + orig;
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
      hmpp_acc_region_svd_124_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_svd_124_parallel_region_1");
      hmpp_acc_region_svd_332_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_svd_332_parallel_region_1");
      hmpp_acc_region_svd_363_parallel_region_1 = new hmpprt::OpenCLGrid(hmpprt_module, "hmpp_acc_region_svd_363_parallel_region_1");

    }
    hmpprt::Context::getInstance()->getGrouplet()->setTarget(hmpprt::OPENCL);
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_svd_124", "prototype hmpp_acc_region_svd_124(pass: ^host s32, A_H: ^openclglob double, V_H: ^openclglob double, rotate_col_idx: ^openclglob s32, ci: ^openclglob double, cj: ^openclglob double, vi: ^openclglob double, vj: ^openclglob double, start_index: s32)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_svd_332", "prototype hmpp_acc_region_svd_332(A_H: ^openclglob double, S_H: ^openclglob double, ci: ^openclglob double)");
    hmpprt::Context::getInstance()->getGrouplet()->addSignature("hmpp_acc_region_svd_363", "prototype hmpp_acc_region_svd_363(A_H: ^openclglob double, B_H: ^openclglob double, S_H: ^openclglob double)");

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
      delete hmpp_acc_region_svd_124_parallel_region_1;
      delete hmpp_acc_region_svd_332_parallel_region_1;
      delete hmpp_acc_region_svd_363_parallel_region_1;

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
