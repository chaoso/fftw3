/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Thu May 24 08:06:13 EDT 2018 */

#include "fftw/fftw_api.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_twidsq_c.native -fma -rdft_simd -compact -variables 4 -pipeline-latency 8 -n 2 -dif -name q1fv_2 -include fftw/rdft_simd/q1f.h */

/*
 * This function contains 6 FP additions, 4 FP multiplications,
 * (or, 6 additions, 4 multiplications, 0 fused multiply/add),
 * 8 stack variables, 0 constants, and 8 memory accesses
 */
#include "fftw/rdft_simd/q1f.h"

static void q1fv_2(FFTW_REAL_TYPE *ri, FFTW_REAL_TYPE *ii, const FFTW_REAL_TYPE *W, stride rs, stride vs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  FFTW_REAL_TYPE *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 2)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 2), MAKE_VOLATILE_STRIDE(4, rs), MAKE_VOLATILE_STRIDE(4, vs)) {
	       V T1, T2, T3, T4, T5, T6;
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       T2 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
	       T3 = BYTWJ(&(W[0]), VSUB(T1, T2));
	       T4 = LD(&(x[WS(vs, 1)]), ms, &(x[WS(vs, 1)]));
	       T5 = LD(&(x[WS(vs, 1) + WS(rs, 1)]), ms, &(x[WS(vs, 1) + WS(rs, 1)]));
	       T6 = BYTWJ(&(W[0]), VSUB(T4, T5));
	       ST(&(x[WS(vs, 1)]), T3, ms, &(x[WS(vs, 1)]));
	       ST(&(x[WS(vs, 1) + WS(rs, 1)]), T6, ms, &(x[WS(vs, 1) + WS(rs, 1)]));
	       ST(&(x[0]), VADD(T1, T2), ms, &(x[0]));
	       ST(&(x[WS(rs, 1)]), VADD(T4, T5), ms, &(x[WS(rs, 1)]));
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 2, XSIMD_STRING("q1fv_2"), twinstr, &GENUS, {6, 4, 0, 0}, 0, 0, 0 };

void XSIMD(codelet_q1fv_2) (planner *p) {
     fftw_kdft_difsq_register (p, q1fv_2, &desc);
}
#else

/* Generated by: ../../../genfft/gen_twidsq_c.native -rdft_simd -compact -variables 4 -pipeline-latency 8 -n 2 -dif -name q1fv_2 -include fftw/rdft_simd/q1f.h */

/*
 * This function contains 6 FP additions, 4 FP multiplications,
 * (or, 6 additions, 4 multiplications, 0 fused multiply/add),
 * 8 stack variables, 0 constants, and 8 memory accesses
 */
#include "fftw/dft_simd/q1f.h"

static void q1fv_2(FFTW_REAL_TYPE *ri, FFTW_REAL_TYPE *ii, const FFTW_REAL_TYPE *W, stride rs, stride vs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  FFTW_REAL_TYPE *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 2)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 2), MAKE_VOLATILE_STRIDE(4, rs), MAKE_VOLATILE_STRIDE(4, vs)) {
	       V T1, T2, T3, T4, T5, T6;
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       T2 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
	       T3 = BYTWJ(&(W[0]), VSUB(T1, T2));
	       T4 = LD(&(x[WS(vs, 1)]), ms, &(x[WS(vs, 1)]));
	       T5 = LD(&(x[WS(vs, 1) + WS(rs, 1)]), ms, &(x[WS(vs, 1) + WS(rs, 1)]));
	       T6 = BYTWJ(&(W[0]), VSUB(T4, T5));
	       ST(&(x[WS(vs, 1)]), T3, ms, &(x[WS(vs, 1)]));
	       ST(&(x[WS(vs, 1) + WS(rs, 1)]), T6, ms, &(x[WS(vs, 1) + WS(rs, 1)]));
	       ST(&(x[0]), VADD(T1, T2), ms, &(x[0]));
	       ST(&(x[WS(rs, 1)]), VADD(T4, T5), ms, &(x[WS(rs, 1)]));
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 2, XSIMD_STRING("q1fv_2"), twinstr, &GENUS, {6, 4, 0, 0}, 0, 0, 0 };

void XSIMD(codelet_q1fv_2) (planner *p) {
     fftw_kdft_difsq_register (p, q1fv_2, &desc);
}
#endif
