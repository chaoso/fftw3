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
/* Generated on Thu May 24 08:06:09 EDT 2018 */

#include "fftw/fftw_api.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_twiddle.native -fma -rdft_simd -compact -variables 4 -pipeline-latency 8 -n 2 -name t1sv_2 -include fftw/rdft_simd/ts.h */

/*
 * This function contains 6 FP additions, 4 FP multiplications,
 * (or, 4 additions, 2 multiplications, 2 fused multiply/add),
 * 11 stack variables, 0 constants, and 8 memory accesses
 */
#include "fftw/rdft_simd/ts.h"

static void t1sv_2(FFTW_REAL_TYPE *ri, FFTW_REAL_TYPE *ii, const FFTW_REAL_TYPE *W, stride rs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  for (m = mb, W = W + (mb * 2); m < me; m = m + (2 * VL), ri = ri + ((2 * VL) * ms), ii = ii + ((2 * VL) * ms), W = W + ((2 * VL) * 2), MAKE_VOLATILE_STRIDE(4, rs)) {
	       V T1, Ta, T3, T6, T4, T8, T2, T7, T9, T5;
	       T1 = LD(&(ri[0]), ms, &(ri[0]));
	       Ta = LD(&(ii[0]), ms, &(ii[0]));
	       T3 = LD(&(ri[WS(rs, 1)]), ms, &(ri[WS(rs, 1)]));
	       T6 = LD(&(ii[WS(rs, 1)]), ms, &(ii[WS(rs, 1)]));
	       T2 = LDW(&(W[0]));
	       T4 = VMUL(T2, T3);
	       T8 = VMUL(T2, T6);
	       T5 = LDW(&(W[TWVL * 1]));
	       T7 = VFMA(T5, T6, T4);
	       T9 = VFNMS(T5, T3, T8);
	       ST(&(ri[WS(rs, 1)]), VSUB(T1, T7), ms, &(ri[WS(rs, 1)]));
	       ST(&(ii[WS(rs, 1)]), VSUB(Ta, T9), ms, &(ii[WS(rs, 1)]));
	       ST(&(ri[0]), VADD(T1, T7), ms, &(ri[0]));
	       ST(&(ii[0]), VADD(T9, Ta), ms, &(ii[0]));
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     {TW_NEXT, (2 * VL), 0}
};

static const ct_desc desc = { 2, XSIMD_STRING("t1sv_2"), twinstr, &GENUS, {4, 2, 2, 0}, 0, 0, 0 };

void XSIMD(codelet_t1sv_2) (planner *p) {
     fftw_kdft_dit_register (p, t1sv_2, &desc);
}
#else

/* Generated by: ../../../genfft/gen_twiddle.native -rdft_simd -compact -variables 4 -pipeline-latency 8 -n 2 -name t1sv_2 -include fftw/rdft_simd/ts.h */

/*
 * This function contains 6 FP additions, 4 FP multiplications,
 * (or, 4 additions, 2 multiplications, 2 fused multiply/add),
 * 9 stack variables, 0 constants, and 8 memory accesses
 */
#include "fftw/dft_simd/ts.h"

static void t1sv_2(FFTW_REAL_TYPE *ri, FFTW_REAL_TYPE *ii, const FFTW_REAL_TYPE *W, stride rs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  for (m = mb, W = W + (mb * 2); m < me; m = m + (2 * VL), ri = ri + ((2 * VL) * ms), ii = ii + ((2 * VL) * ms), W = W + ((2 * VL) * 2), MAKE_VOLATILE_STRIDE(4, rs)) {
	       V T1, T8, T6, T7;
	       T1 = LD(&(ri[0]), ms, &(ri[0]));
	       T8 = LD(&(ii[0]), ms, &(ii[0]));
	       {
		    V T3, T5, T2, T4;
		    T3 = LD(&(ri[WS(rs, 1)]), ms, &(ri[WS(rs, 1)]));
		    T5 = LD(&(ii[WS(rs, 1)]), ms, &(ii[WS(rs, 1)]));
		    T2 = LDW(&(W[0]));
		    T4 = LDW(&(W[TWVL * 1]));
		    T6 = VFMA(T2, T3, VMUL(T4, T5));
		    T7 = VFNMS(T4, T3, VMUL(T2, T5));
	       }
	       ST(&(ri[WS(rs, 1)]), VSUB(T1, T6), ms, &(ri[WS(rs, 1)]));
	       ST(&(ii[WS(rs, 1)]), VSUB(T8, T7), ms, &(ii[WS(rs, 1)]));
	       ST(&(ri[0]), VADD(T1, T6), ms, &(ri[0]));
	       ST(&(ii[0]), VADD(T7, T8), ms, &(ii[0]));
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     {TW_NEXT, (2 * VL), 0}
};

static const ct_desc desc = { 2, XSIMD_STRING("t1sv_2"), twinstr, &GENUS, {4, 2, 2, 0}, 0, 0, 0 };

void XSIMD(codelet_t1sv_2) (planner *p) {
     fftw_kdft_dit_register (p, t1sv_2, &desc);
}
#endif
