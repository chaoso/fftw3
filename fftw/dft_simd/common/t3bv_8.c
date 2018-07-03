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
/* Generated on Thu May 24 08:06:06 EDT 2018 */

#include "fftw/fftw_api.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -rdft_simd -compact -variables 4 -pipeline-latency 8 -twiddle-log3 -precompute-twiddles -no-generate-bytw -n 8 -name t3bv_8 -include fftw/rdft_simd/t3b.h -sign 1 */

/*
 * This function contains 37 FP additions, 32 FP multiplications,
 * (or, 27 additions, 22 multiplications, 10 fused multiply/add),
 * 31 stack variables, 1 constants, and 16 memory accesses
 */
#include "fftw/rdft_simd/t3b.h"

static void t3bv_8(FFTW_REAL_TYPE *ri, FFTW_REAL_TYPE *ii, const FFTW_REAL_TYPE *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  FFTW_REAL_TYPE *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 6)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 6), MAKE_VOLATILE_STRIDE(8, rs)) {
	       V T2, T3, Ta, T4, Tb, Tc, Tp;
	       T2 = LDW(&(W[0]));
	       T3 = LDW(&(W[TWVL * 2]));
	       Ta = VZMULJ(T2, T3);
	       T4 = VZMUL(T2, T3);
	       Tb = LDW(&(W[TWVL * 4]));
	       Tc = VZMULJ(Ta, Tb);
	       Tp = VZMULJ(T2, Tb);
	       {
		    V T7, Tx, Ts, Ty, Tf, TA, Tk, TB, T1, T6, T5;
		    T1 = LD(&(x[0]), ms, &(x[0]));
		    T5 = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
		    T6 = VZMUL(T4, T5);
		    T7 = VSUB(T1, T6);
		    Tx = VADD(T1, T6);
		    {
			 V To, Tr, Tn, Tq;
			 Tn = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			 To = VZMUL(Ta, Tn);
			 Tq = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 Tr = VZMUL(Tp, Tq);
			 Ts = VSUB(To, Tr);
			 Ty = VADD(To, Tr);
		    }
		    {
			 V T9, Te, T8, Td;
			 T8 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 T9 = VZMUL(T2, T8);
			 Td = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
			 Te = VZMUL(Tc, Td);
			 Tf = VSUB(T9, Te);
			 TA = VADD(T9, Te);
		    }
		    {
			 V Th, Tj, Tg, Ti;
			 Tg = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 Th = VZMUL(Tb, Tg);
			 Ti = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 Tj = VZMUL(T3, Ti);
			 Tk = VSUB(Th, Tj);
			 TB = VADD(Th, Tj);
		    }
		    {
			 V Tz, TC, TD, TE;
			 Tz = VSUB(Tx, Ty);
			 TC = VSUB(TA, TB);
			 ST(&(x[WS(rs, 6)]), VFNMSI(TC, Tz), ms, &(x[0]));
			 ST(&(x[WS(rs, 2)]), VFMAI(TC, Tz), ms, &(x[0]));
			 TD = VADD(Tx, Ty);
			 TE = VADD(TA, TB);
			 ST(&(x[WS(rs, 4)]), VSUB(TD, TE), ms, &(x[0]));
			 ST(&(x[0]), VADD(TD, TE), ms, &(x[0]));
			 {
			      V Tm, Tv, Tu, Tw, Tl, Tt;
			      Tl = VADD(Tf, Tk);
			      Tm = VFNMS(LDK(KP707106781), Tl, T7);
			      Tv = VFMA(LDK(KP707106781), Tl, T7);
			      Tt = VSUB(Tf, Tk);
			      Tu = VFNMS(LDK(KP707106781), Tt, Ts);
			      Tw = VFMA(LDK(KP707106781), Tt, Ts);
			      ST(&(x[WS(rs, 3)]), VFNMSI(Tu, Tm), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 7)]), VFNMSI(Tw, Tv), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 5)]), VFMAI(Tu, Tm), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 1)]), VFMAI(Tw, Tv), ms, &(x[WS(rs, 1)]));
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 3),
     VTW(0, 7),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 8, XSIMD_STRING("t3bv_8"), twinstr, &GENUS, {27, 22, 10, 0}, 0, 0, 0 };

void XSIMD(codelet_t3bv_8) (planner *p) {
     fftw_kdft_dit_register (p, t3bv_8, &desc);
}
#else

/* Generated by: ../../../genfft/gen_twiddle_c.native -rdft_simd -compact -variables 4 -pipeline-latency 8 -twiddle-log3 -precompute-twiddles -no-generate-bytw -n 8 -name t3bv_8 -include fftw/rdft_simd/t3b.h -sign 1 */

/*
 * This function contains 37 FP additions, 24 FP multiplications,
 * (or, 37 additions, 24 multiplications, 0 fused multiply/add),
 * 31 stack variables, 1 constants, and 16 memory accesses
 */
#include "fftw/dft_simd/t3b.h"

static void t3bv_8(FFTW_REAL_TYPE *ri, FFTW_REAL_TYPE *ii, const FFTW_REAL_TYPE *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  FFTW_REAL_TYPE *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 6)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 6), MAKE_VOLATILE_STRIDE(8, rs)) {
	       V T1, T4, T5, Tp, T6, T7, Tj;
	       T1 = LDW(&(W[0]));
	       T4 = LDW(&(W[TWVL * 2]));
	       T5 = VZMULJ(T1, T4);
	       Tp = VZMUL(T1, T4);
	       T6 = LDW(&(W[TWVL * 4]));
	       T7 = VZMULJ(T5, T6);
	       Tj = VZMULJ(T1, T6);
	       {
		    V Ts, Tx, Tm, Ty, Ta, TA, Tf, TB, To, Tr, Tq;
		    To = LD(&(x[0]), ms, &(x[0]));
		    Tq = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
		    Tr = VZMUL(Tp, Tq);
		    Ts = VSUB(To, Tr);
		    Tx = VADD(To, Tr);
		    {
			 V Ti, Tl, Th, Tk;
			 Th = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			 Ti = VZMUL(T5, Th);
			 Tk = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 Tl = VZMUL(Tj, Tk);
			 Tm = VSUB(Ti, Tl);
			 Ty = VADD(Ti, Tl);
		    }
		    {
			 V T3, T9, T2, T8;
			 T2 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 T3 = VZMUL(T1, T2);
			 T8 = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
			 T9 = VZMUL(T7, T8);
			 Ta = VSUB(T3, T9);
			 TA = VADD(T3, T9);
		    }
		    {
			 V Tc, Te, Tb, Td;
			 Tb = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 Tc = VZMUL(T6, Tb);
			 Td = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 Te = VZMUL(T4, Td);
			 Tf = VSUB(Tc, Te);
			 TB = VADD(Tc, Te);
		    }
		    {
			 V Tz, TC, TD, TE;
			 Tz = VSUB(Tx, Ty);
			 TC = VBYI(VSUB(TA, TB));
			 ST(&(x[WS(rs, 6)]), VSUB(Tz, TC), ms, &(x[0]));
			 ST(&(x[WS(rs, 2)]), VADD(Tz, TC), ms, &(x[0]));
			 TD = VADD(Tx, Ty);
			 TE = VADD(TA, TB);
			 ST(&(x[WS(rs, 4)]), VSUB(TD, TE), ms, &(x[0]));
			 ST(&(x[0]), VADD(TD, TE), ms, &(x[0]));
			 {
			      V Tn, Tv, Tu, Tw, Tg, Tt;
			      Tg = VMUL(LDK(KP707106781), VSUB(Ta, Tf));
			      Tn = VBYI(VSUB(Tg, Tm));
			      Tv = VBYI(VADD(Tm, Tg));
			      Tt = VMUL(LDK(KP707106781), VADD(Ta, Tf));
			      Tu = VSUB(Ts, Tt);
			      Tw = VADD(Ts, Tt);
			      ST(&(x[WS(rs, 3)]), VADD(Tn, Tu), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 7)]), VSUB(Tw, Tv), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 5)]), VSUB(Tu, Tn), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 1)]), VADD(Tv, Tw), ms, &(x[WS(rs, 1)]));
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 3),
     VTW(0, 7),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 8, XSIMD_STRING("t3bv_8"), twinstr, &GENUS, {37, 24, 0, 0}, 0, 0, 0 };

void XSIMD(codelet_t3bv_8) (planner *p) {
     fftw_kdft_dit_register (p, t3bv_8, &desc);
}
#endif
