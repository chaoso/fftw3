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
/* Generated on Thu May 24 08:04:51 EDT 2018 */

#include "fftw/fftw_api.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_notw_c.native -fma -rdft_simd -compact -variables 4 -pipeline-latency 8 -n 10 -name n1fv_10 -include fftw/rdft_simd/n1f.h */

/*
 * This function contains 42 FP additions, 22 FP multiplications,
 * (or, 24 additions, 4 multiplications, 18 fused multiply/add),
 * 33 stack variables, 4 constants, and 20 memory accesses
 */
#include "fftw/rdft_simd/n1f.h"

static void n1fv_10(const FFTW_REAL_TYPE *ri, const FFTW_REAL_TYPE *ii, FFTW_REAL_TYPE *ro, FFTW_REAL_TYPE *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     {
	  INT i;
	  const FFTW_REAL_TYPE *xi;
	  FFTW_REAL_TYPE *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(20, is), MAKE_VOLATILE_STRIDE(20, os)) {
	       V T3, Tr, Tm, Tn, TD, TC, Tu, Tx, Ty, Ta, Th, Ti, T1, T2;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
	       T3 = VSUB(T1, T2);
	       Tr = VADD(T1, T2);
	       {
		    V T6, Ts, Tg, Tw, T9, Tt, Td, Tv;
		    {
			 V T4, T5, Te, Tf;
			 T4 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 T5 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
			 T6 = VSUB(T4, T5);
			 Ts = VADD(T4, T5);
			 Te = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
			 Tf = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			 Tg = VSUB(Te, Tf);
			 Tw = VADD(Te, Tf);
		    }
		    {
			 V T7, T8, Tb, Tc;
			 T7 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			 T8 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
			 T9 = VSUB(T7, T8);
			 Tt = VADD(T7, T8);
			 Tb = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
			 Tc = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
			 Td = VSUB(Tb, Tc);
			 Tv = VADD(Tb, Tc);
		    }
		    Tm = VSUB(T6, T9);
		    Tn = VSUB(Td, Tg);
		    TD = VSUB(Ts, Tt);
		    TC = VSUB(Tv, Tw);
		    Tu = VADD(Ts, Tt);
		    Tx = VADD(Tv, Tw);
		    Ty = VADD(Tu, Tx);
		    Ta = VADD(T6, T9);
		    Th = VADD(Td, Tg);
		    Ti = VADD(Ta, Th);
	       }
	       ST(&(xo[WS(os, 5)]), VADD(T3, Ti), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[0]), VADD(Tr, Ty), ovs, &(xo[0]));
	       {
		    V To, Tq, Tl, Tp, Tj, Tk;
		    To = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), Tn, Tm));
		    Tq = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), Tm, Tn));
		    Tj = VFNMS(LDK(KP250000000), Ti, T3);
		    Tk = VSUB(Ta, Th);
		    Tl = VFMA(LDK(KP559016994), Tk, Tj);
		    Tp = VFNMS(LDK(KP559016994), Tk, Tj);
		    ST(&(xo[WS(os, 1)]), VFNMSI(To, Tl), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 7)]), VFMAI(Tq, Tp), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 9)]), VFMAI(To, Tl), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 3)]), VFNMSI(Tq, Tp), ovs, &(xo[WS(os, 1)]));
	       }
	       {
		    V TE, TG, TB, TF, Tz, TA;
		    TE = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), TD, TC));
		    TG = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), TC, TD));
		    Tz = VFNMS(LDK(KP250000000), Ty, Tr);
		    TA = VSUB(Tu, Tx);
		    TB = VFNMS(LDK(KP559016994), TA, Tz);
		    TF = VFMA(LDK(KP559016994), TA, Tz);
		    ST(&(xo[WS(os, 2)]), VFMAI(TE, TB), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 6)]), VFNMSI(TG, TF), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 8)]), VFNMSI(TE, TB), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 4)]), VFMAI(TG, TF), ovs, &(xo[0]));
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 10, XSIMD_STRING("n1fv_10"), {24, 4, 18, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1fv_10) (planner *p) {
     fftw_kdft_register (p, n1fv_10, &desc);
}

#else

/* Generated by: ../../../genfft/gen_notw_c.native -rdft_simd -compact -variables 4 -pipeline-latency 8 -n 10 -name n1fv_10 -include fftw/rdft_simd/n1f.h */

/*
 * This function contains 42 FP additions, 12 FP multiplications,
 * (or, 36 additions, 6 multiplications, 6 fused multiply/add),
 * 33 stack variables, 4 constants, and 20 memory accesses
 */
#include "fftw/dft_simd/n1f.h"

static void n1fv_10(const FFTW_REAL_TYPE *ri, const FFTW_REAL_TYPE *ii, FFTW_REAL_TYPE *ro, FFTW_REAL_TYPE *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     {
	  INT i;
	  const FFTW_REAL_TYPE *xi;
	  FFTW_REAL_TYPE *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(20, is), MAKE_VOLATILE_STRIDE(20, os)) {
	       V Ti, Ty, Tm, Tn, Tw, Tt, Tz, TA, TB, T7, Te, Tj, Tg, Th;
	       Tg = LD(&(xi[0]), ivs, &(xi[0]));
	       Th = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
	       Ti = VSUB(Tg, Th);
	       Ty = VADD(Tg, Th);
	       {
		    V T3, Tu, Td, Ts, T6, Tv, Ta, Tr;
		    {
			 V T1, T2, Tb, Tc;
			 T1 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 T2 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
			 T3 = VSUB(T1, T2);
			 Tu = VADD(T1, T2);
			 Tb = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
			 Tc = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			 Td = VSUB(Tb, Tc);
			 Ts = VADD(Tb, Tc);
		    }
		    {
			 V T4, T5, T8, T9;
			 T4 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			 T5 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
			 T6 = VSUB(T4, T5);
			 Tv = VADD(T4, T5);
			 T8 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
			 T9 = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
			 Ta = VSUB(T8, T9);
			 Tr = VADD(T8, T9);
		    }
		    Tm = VSUB(T3, T6);
		    Tn = VSUB(Ta, Td);
		    Tw = VSUB(Tu, Tv);
		    Tt = VSUB(Tr, Ts);
		    Tz = VADD(Tu, Tv);
		    TA = VADD(Tr, Ts);
		    TB = VADD(Tz, TA);
		    T7 = VADD(T3, T6);
		    Te = VADD(Ta, Td);
		    Tj = VADD(T7, Te);
	       }
	       ST(&(xo[WS(os, 5)]), VADD(Ti, Tj), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[0]), VADD(Ty, TB), ovs, &(xo[0]));
	       {
		    V To, Tq, Tl, Tp, Tf, Tk;
		    To = VBYI(VFMA(LDK(KP951056516), Tm, VMUL(LDK(KP587785252), Tn)));
		    Tq = VBYI(VFNMS(LDK(KP587785252), Tm, VMUL(LDK(KP951056516), Tn)));
		    Tf = VMUL(LDK(KP559016994), VSUB(T7, Te));
		    Tk = VFNMS(LDK(KP250000000), Tj, Ti);
		    Tl = VADD(Tf, Tk);
		    Tp = VSUB(Tk, Tf);
		    ST(&(xo[WS(os, 1)]), VSUB(Tl, To), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 7)]), VADD(Tq, Tp), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 9)]), VADD(To, Tl), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 3)]), VSUB(Tp, Tq), ovs, &(xo[WS(os, 1)]));
	       }
	       {
		    V Tx, TF, TE, TG, TC, TD;
		    Tx = VBYI(VFNMS(LDK(KP587785252), Tw, VMUL(LDK(KP951056516), Tt)));
		    TF = VBYI(VFMA(LDK(KP951056516), Tw, VMUL(LDK(KP587785252), Tt)));
		    TC = VFNMS(LDK(KP250000000), TB, Ty);
		    TD = VMUL(LDK(KP559016994), VSUB(Tz, TA));
		    TE = VSUB(TC, TD);
		    TG = VADD(TD, TC);
		    ST(&(xo[WS(os, 2)]), VADD(Tx, TE), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 6)]), VSUB(TG, TF), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 8)]), VSUB(TE, Tx), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 4)]), VADD(TF, TG), ovs, &(xo[0]));
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 10, XSIMD_STRING("n1fv_10"), {36, 6, 6, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1fv_10) (planner *p) {
     fftw_kdft_register (p, n1fv_10, &desc);
}

#endif
