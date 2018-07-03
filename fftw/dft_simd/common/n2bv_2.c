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
/* Generated on Thu May 24 08:05:11 EDT 2018 */

#include "fftw/fftw_api.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_notw_c.native -fma -rdft_simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 2 -name n2bv_2 -with-ostride 2 -include fftw/rdft_simd/n2b.h -store-multiple 2 */

/*
 * This function contains 2 FP additions, 0 FP multiplications,
 * (or, 2 additions, 0 multiplications, 0 fused multiply/add),
 * 7 stack variables, 0 constants, and 5 memory accesses
 */
#include "fftw/rdft_simd/n2b.h"

static void n2bv_2(const FFTW_REAL_TYPE *ri, const FFTW_REAL_TYPE *ii, FFTW_REAL_TYPE *ro, FFTW_REAL_TYPE *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     {
	  INT i;
	  const FFTW_REAL_TYPE *xi;
	  FFTW_REAL_TYPE *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(4, is), MAKE_VOLATILE_STRIDE(4, os)) {
	       V T1, T2, T3, T4;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
	       T3 = VSUB(T1, T2);
	       STM2(&(xo[2]), T3, ovs, &(xo[2]));
	       T4 = VADD(T1, T2);
	       STM2(&(xo[0]), T4, ovs, &(xo[0]));
	       STN2(&(xo[0]), T4, T3, ovs);
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 2, XSIMD_STRING("n2bv_2"), {2, 0, 0, 0}, &GENUS, 0, 2, 0, 0 };

void XSIMD(codelet_n2bv_2) (planner *p) {
     fftw_kdft_register (p, n2bv_2, &desc);
}

#else

/* Generated by: ../../../genfft/gen_notw_c.native -rdft_simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 2 -name n2bv_2 -with-ostride 2 -include fftw/rdft_simd/n2b.h -store-multiple 2 */

/*
 * This function contains 2 FP additions, 0 FP multiplications,
 * (or, 2 additions, 0 multiplications, 0 fused multiply/add),
 * 7 stack variables, 0 constants, and 5 memory accesses
 */
#include "fftw/dft_simd/n2b.h"

static void n2bv_2(const FFTW_REAL_TYPE *ri, const FFTW_REAL_TYPE *ii, FFTW_REAL_TYPE *ro, FFTW_REAL_TYPE *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     {
	  INT i;
	  const FFTW_REAL_TYPE *xi;
	  FFTW_REAL_TYPE *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(4, is), MAKE_VOLATILE_STRIDE(4, os)) {
	       V T1, T2, T3, T4;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
	       T3 = VSUB(T1, T2);
	       STM2(&(xo[2]), T3, ovs, &(xo[2]));
	       T4 = VADD(T1, T2);
	       STM2(&(xo[0]), T4, ovs, &(xo[0]));
	       STN2(&(xo[0]), T4, T3, ovs);
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 2, XSIMD_STRING("n2bv_2"), {2, 0, 0, 0}, &GENUS, 0, 2, 0, 0 };

void XSIMD(codelet_n2bv_2) (planner *p) {
     fftw_kdft_register (p, n2bv_2, &desc);
}

#endif
