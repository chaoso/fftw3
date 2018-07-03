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
/* Generated on Thu May 24 08:05:56 EDT 2018 */

#include "fftw/fftw_api.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -rdft_simd -compact -variables 4 -pipeline-latency 8 -n 2 -name t1buv_2 -include fftw/rdft_simd/t1bu.h -sign 1 */

/*
 * This function contains 3 FP additions, 2 FP multiplications,
 * (or, 3 additions, 2 multiplications, 0 fused multiply/add),
 * 5 stack variables, 0 constants, and 4 memory accesses
 */
#include "fftw/rdft_simd/t1bu.h"

static void t1buv_2(FFTW_REAL_TYPE *ri, FFTW_REAL_TYPE *ii, const FFTW_REAL_TYPE *W, stride rs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  FFTW_REAL_TYPE *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 2)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 2), MAKE_VOLATILE_STRIDE(2, rs)) {
	       V T1, T3, T2;
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       T2 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
	       T3 = BYTW(&(W[0]), T2);
	       ST(&(x[WS(rs, 1)]), VSUB(T1, T3), ms, &(x[WS(rs, 1)]));
	       ST(&(x[0]), VADD(T1, T3), ms, &(x[0]));
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 2, XSIMD_STRING("t1buv_2"), twinstr, &GENUS, {3, 2, 0, 0}, 0, 0, 0 };

void XSIMD(codelet_t1buv_2) (planner *p) {
     fftw_kdft_dit_register (p, t1buv_2, &desc);
}
#else

/* Generated by: ../../../genfft/gen_twiddle_c.native -rdft_simd -compact -variables 4 -pipeline-latency 8 -n 2 -name t1buv_2 -include fftw/rdft_simd/t1bu.h -sign 1 */

/*
 * This function contains 3 FP additions, 2 FP multiplications,
 * (or, 3 additions, 2 multiplications, 0 fused multiply/add),
 * 5 stack variables, 0 constants, and 4 memory accesses
 */
#include "fftw/dft_simd/t1bu.h"

static void t1buv_2(FFTW_REAL_TYPE *ri, FFTW_REAL_TYPE *ii, const FFTW_REAL_TYPE *W, stride rs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  FFTW_REAL_TYPE *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 2)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 2), MAKE_VOLATILE_STRIDE(2, rs)) {
	       V T1, T3, T2;
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       T2 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
	       T3 = BYTW(&(W[0]), T2);
	       ST(&(x[WS(rs, 1)]), VSUB(T1, T3), ms, &(x[WS(rs, 1)]));
	       ST(&(x[0]), VADD(T1, T3), ms, &(x[0]));
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 2, XSIMD_STRING("t1buv_2"), twinstr, &GENUS, {3, 2, 0, 0}, 0, 0, 0 };

void XSIMD(codelet_t1buv_2) (planner *p) {
     fftw_kdft_dit_register (p, t1buv_2, &desc);
}
#endif
