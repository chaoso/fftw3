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
/* Generated on Thu May 24 08:04:12 EDT 2018 */

#include "fftw/fftw_api.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_twiddle.native -fma -compact -variables 4 -pipeline-latency 4 -n 4 -name t1_4 -include fftw/rdft_scalar/t.h */

/*
 * This function contains 22 FP additions, 12 FP multiplications,
 * (or, 16 additions, 6 multiplications, 6 fused multiply/add),
 * 15 stack variables, 0 constants, and 16 memory accesses
 */
#include "fftw/rdft_scalar/t.h"

static void t1_4(FFTW_REAL_TYPE *ri, FFTW_REAL_TYPE *ii, const FFTW_REAL_TYPE *W, stride rs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  for (m = mb, W = W + (mb * 6); m < me; m = m + 1, ri = ri + ms, ii = ii + ms, W = W + 6, MAKE_VOLATILE_STRIDE(8, rs)) {
	       E T1, Tv, T7, Tu, Te, To, Tk, Tq;
	       T1 = ri[0];
	       Tv = ii[0];
	       {
		    E T3, T6, T4, Tt, T2, T5;
		    T3 = ri[WS(rs, 2)];
		    T6 = ii[WS(rs, 2)];
		    T2 = W[2];
		    T4 = T2 * T3;
		    Tt = T2 * T6;
		    T5 = W[3];
		    T7 = FMA(T5, T6, T4);
		    Tu = FNMS(T5, T3, Tt);
	       }
	       {
		    E Ta, Td, Tb, Tn, T9, Tc;
		    Ta = ri[WS(rs, 1)];
		    Td = ii[WS(rs, 1)];
		    T9 = W[0];
		    Tb = T9 * Ta;
		    Tn = T9 * Td;
		    Tc = W[1];
		    Te = FMA(Tc, Td, Tb);
		    To = FNMS(Tc, Ta, Tn);
	       }
	       {
		    E Tg, Tj, Th, Tp, Tf, Ti;
		    Tg = ri[WS(rs, 3)];
		    Tj = ii[WS(rs, 3)];
		    Tf = W[4];
		    Th = Tf * Tg;
		    Tp = Tf * Tj;
		    Ti = W[5];
		    Tk = FMA(Ti, Tj, Th);
		    Tq = FNMS(Ti, Tg, Tp);
	       }
	       {
		    E T8, Tl, Ts, Tw;
		    T8 = T1 + T7;
		    Tl = Te + Tk;
		    ri[WS(rs, 2)] = T8 - Tl;
		    ri[0] = T8 + Tl;
		    Ts = To + Tq;
		    Tw = Tu + Tv;
		    ii[0] = Ts + Tw;
		    ii[WS(rs, 2)] = Tw - Ts;
	       }
	       {
		    E Tm, Tr, Tx, Ty;
		    Tm = T1 - T7;
		    Tr = To - Tq;
		    ri[WS(rs, 3)] = Tm - Tr;
		    ri[WS(rs, 1)] = Tm + Tr;
		    Tx = Tv - Tu;
		    Ty = Te - Tk;
		    ii[WS(rs, 1)] = Tx - Ty;
		    ii[WS(rs, 3)] = Ty + Tx;
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 0, 4},
     {TW_NEXT, 1, 0}
};

static const ct_desc desc = { 4, "t1_4", twinstr, &GENUS, {16, 6, 6, 0}, 0, 0, 0 };

void fftw_codelet_t1_4 (planner *p) {
     fftw_kdft_dit_register (p, t1_4, &desc);
}
#else

/* Generated by: ../../../genfft/gen_twiddle.native -compact -variables 4 -pipeline-latency 4 -n 4 -name t1_4 -include fftw/rdft_scalar/t.h */

/*
 * This function contains 22 FP additions, 12 FP multiplications,
 * (or, 16 additions, 6 multiplications, 6 fused multiply/add),
 * 13 stack variables, 0 constants, and 16 memory accesses
 */
#include "fftw/dft_scalar/t.h"

static void t1_4(FFTW_REAL_TYPE *ri, FFTW_REAL_TYPE *ii, const FFTW_REAL_TYPE *W, stride rs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  for (m = mb, W = W + (mb * 6); m < me; m = m + 1, ri = ri + ms, ii = ii + ms, W = W + 6, MAKE_VOLATILE_STRIDE(8, rs)) {
	       E T1, Tp, T6, To, Tc, Tk, Th, Tl;
	       T1 = ri[0];
	       Tp = ii[0];
	       {
		    E T3, T5, T2, T4;
		    T3 = ri[WS(rs, 2)];
		    T5 = ii[WS(rs, 2)];
		    T2 = W[2];
		    T4 = W[3];
		    T6 = FMA(T2, T3, T4 * T5);
		    To = FNMS(T4, T3, T2 * T5);
	       }
	       {
		    E T9, Tb, T8, Ta;
		    T9 = ri[WS(rs, 1)];
		    Tb = ii[WS(rs, 1)];
		    T8 = W[0];
		    Ta = W[1];
		    Tc = FMA(T8, T9, Ta * Tb);
		    Tk = FNMS(Ta, T9, T8 * Tb);
	       }
	       {
		    E Te, Tg, Td, Tf;
		    Te = ri[WS(rs, 3)];
		    Tg = ii[WS(rs, 3)];
		    Td = W[4];
		    Tf = W[5];
		    Th = FMA(Td, Te, Tf * Tg);
		    Tl = FNMS(Tf, Te, Td * Tg);
	       }
	       {
		    E T7, Ti, Tn, Tq;
		    T7 = T1 + T6;
		    Ti = Tc + Th;
		    ri[WS(rs, 2)] = T7 - Ti;
		    ri[0] = T7 + Ti;
		    Tn = Tk + Tl;
		    Tq = To + Tp;
		    ii[0] = Tn + Tq;
		    ii[WS(rs, 2)] = Tq - Tn;
	       }
	       {
		    E Tj, Tm, Tr, Ts;
		    Tj = T1 - T6;
		    Tm = Tk - Tl;
		    ri[WS(rs, 3)] = Tj - Tm;
		    ri[WS(rs, 1)] = Tj + Tm;
		    Tr = Tp - To;
		    Ts = Tc - Th;
		    ii[WS(rs, 1)] = Tr - Ts;
		    ii[WS(rs, 3)] = Ts + Tr;
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 0, 4},
     {TW_NEXT, 1, 0}
};

static const ct_desc desc = { 4, "t1_4", twinstr, &GENUS, {16, 6, 6, 0}, 0, 0, 0 };

void fftw_codelet_t1_4 (planner *p) {
     fftw_kdft_dit_register (p, t1_4, &desc);
}
#endif
