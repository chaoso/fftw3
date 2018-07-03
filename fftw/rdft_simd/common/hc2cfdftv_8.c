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
/* Generated on Thu May 24 08:08:11 EDT 2018 */

#include "fftw/fftw_api.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2cdft_c.native -fma -rdft_simd -compact -variables 4 -pipeline-latency 8 -trivial-stores -variables 32 -no-generate-bytw -n 8 -dit -name hc2cfdftv_8 -include fftw/rdft_simd/hc2cfv.h */

/*
 * This function contains 41 FP additions, 40 FP multiplications,
 * (or, 23 additions, 22 multiplications, 18 fused multiply/add),
 * 52 stack variables, 2 constants, and 16 memory accesses
 */
#include "fftw/rdft_simd/hc2cfv.h"

static void hc2cfdftv_8(FFTW_REAL_TYPE *Rp, FFTW_REAL_TYPE *Ip, FFTW_REAL_TYPE *Rm, FFTW_REAL_TYPE *Im, const FFTW_REAL_TYPE *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * ((TWVL / VL) * 14)); m < me; m = m + VL, Rp = Rp + (VL * ms), Ip = Ip + (VL * ms), Rm = Rm - (VL * ms), Im = Im - (VL * ms), W = W + (TWVL * 14), MAKE_VOLATILE_STRIDE(32, rs)) {
	       V T8, Tt, TG, TF, TD, TC, Tn, Tu, T3, Tc, Tl, Ts, T7, Ta, Th;
	       V Tq, T1, T2, Tb, Tj, Tk, Ti, Tr, T5, T6, T4, T9, Tf, Tg, Te;
	       V Tp, Td, Tm, Tw, Tx, To, Tv, TM, TN, TK, TL, TA, TB, Ty, Tz;
	       V TI, TJ, TE, TH;
	       T1 = LD(&(Rp[0]), ms, &(Rp[0]));
	       T2 = LD(&(Rm[0]), -ms, &(Rm[0]));
	       T3 = VFMACONJ(T2, T1);
	       Tb = LDW(&(W[0]));
	       Tc = VZMULIJ(Tb, VFNMSCONJ(T2, T1));
	       Tj = LD(&(Rp[WS(rs, 3)]), ms, &(Rp[WS(rs, 1)]));
	       Tk = LD(&(Rm[WS(rs, 3)]), -ms, &(Rm[WS(rs, 1)]));
	       Ti = LDW(&(W[TWVL * 12]));
	       Tl = VZMULIJ(Ti, VFNMSCONJ(Tk, Tj));
	       Tr = LDW(&(W[TWVL * 10]));
	       Ts = VZMULJ(Tr, VFMACONJ(Tk, Tj));
	       T5 = LD(&(Rp[WS(rs, 2)]), ms, &(Rp[0]));
	       T6 = LD(&(Rm[WS(rs, 2)]), -ms, &(Rm[0]));
	       T4 = LDW(&(W[TWVL * 6]));
	       T7 = VZMULJ(T4, VFMACONJ(T6, T5));
	       T9 = LDW(&(W[TWVL * 8]));
	       Ta = VZMULIJ(T9, VFNMSCONJ(T6, T5));
	       Tf = LD(&(Rp[WS(rs, 1)]), ms, &(Rp[WS(rs, 1)]));
	       Tg = LD(&(Rm[WS(rs, 1)]), -ms, &(Rm[WS(rs, 1)]));
	       Te = LDW(&(W[TWVL * 4]));
	       Th = VZMULIJ(Te, VFNMSCONJ(Tg, Tf));
	       Tp = LDW(&(W[TWVL * 2]));
	       Tq = VZMULJ(Tp, VFMACONJ(Tg, Tf));
	       T8 = VSUB(T3, T7);
	       Tt = VSUB(Tq, Ts);
	       TG = VADD(Th, Tl);
	       TF = VADD(Tc, Ta);
	       TD = VADD(Tq, Ts);
	       TC = VADD(T3, T7);
	       Td = VSUB(Ta, Tc);
	       Tm = VSUB(Th, Tl);
	       Tn = VADD(Td, Tm);
	       Tu = VSUB(Tm, Td);
	       To = VFMA(LDK(KP707106781), Tn, T8);
	       Tv = VFNMS(LDK(KP707106781), Tu, Tt);
	       Tw = VMUL(LDK(KP500000000), VFNMSI(Tv, To));
	       Tx = VCONJ(VMUL(LDK(KP500000000), VFMAI(Tv, To)));
	       ST(&(Rp[WS(rs, 1)]), Tw, ms, &(Rp[WS(rs, 1)]));
	       ST(&(Rm[0]), Tx, -ms, &(Rm[0]));
	       TK = VADD(TC, TD);
	       TL = VADD(TF, TG);
	       TM = VMUL(LDK(KP500000000), VSUB(TK, TL));
	       TN = VCONJ(VMUL(LDK(KP500000000), VADD(TL, TK)));
	       ST(&(Rp[0]), TM, ms, &(Rp[0]));
	       ST(&(Rm[WS(rs, 3)]), TN, -ms, &(Rm[WS(rs, 1)]));
	       Ty = VFNMS(LDK(KP707106781), Tn, T8);
	       Tz = VFMA(LDK(KP707106781), Tu, Tt);
	       TA = VCONJ(VMUL(LDK(KP500000000), VFNMSI(Tz, Ty)));
	       TB = VMUL(LDK(KP500000000), VFMAI(Tz, Ty));
	       ST(&(Rm[WS(rs, 2)]), TA, -ms, &(Rm[0]));
	       ST(&(Rp[WS(rs, 3)]), TB, ms, &(Rp[WS(rs, 1)]));
	       TE = VSUB(TC, TD);
	       TH = VSUB(TF, TG);
	       TI = VMUL(LDK(KP500000000), VFMAI(TH, TE));
	       TJ = VCONJ(VMUL(LDK(KP500000000), VFNMSI(TH, TE)));
	       ST(&(Rp[WS(rs, 2)]), TI, ms, &(Rp[0]));
	       ST(&(Rm[WS(rs, 1)]), TJ, -ms, &(Rm[WS(rs, 1)]));
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(1, 1),
     VTW(1, 2),
     VTW(1, 3),
     VTW(1, 4),
     VTW(1, 5),
     VTW(1, 6),
     VTW(1, 7),
     {TW_NEXT, VL, 0}
};

static const hc2c_desc desc = { 8, XSIMD_STRING("hc2cfdftv_8"), twinstr, &GENUS, {23, 22, 18, 0} };

void XSIMD(codelet_hc2cfdftv_8) (planner *p) {
     fftw_khc2c_register (p, hc2cfdftv_8, &desc, HC2C_VIA_DFT);
}
#else

/* Generated by: ../../../genfft/gen_hc2cdft_c.native -rdft_simd -compact -variables 4 -pipeline-latency 8 -trivial-stores -variables 32 -no-generate-bytw -n 8 -dit -name hc2cfdftv_8 -include fftw/rdft_simd/hc2cfv.h */

/*
 * This function contains 41 FP additions, 23 FP multiplications,
 * (or, 41 additions, 23 multiplications, 0 fused multiply/add),
 * 57 stack variables, 3 constants, and 16 memory accesses
 */
#include "fftw/rdft_simd/hc2cfv.h"

static void hc2cfdftv_8(FFTW_REAL_TYPE *Rp, FFTW_REAL_TYPE *Ip, FFTW_REAL_TYPE *Rm, FFTW_REAL_TYPE *Im, const FFTW_REAL_TYPE *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     DVK(KP353553390, +0.353553390593273762200422181052424519642417969);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * ((TWVL / VL) * 14)); m < me; m = m + VL, Rp = Rp + (VL * ms), Ip = Ip + (VL * ms), Rm = Rm - (VL * ms), Im = Im - (VL * ms), W = W + (TWVL * 14), MAKE_VOLATILE_STRIDE(32, rs)) {
	       V Ta, TE, Tr, TF, Tl, TK, Tw, TG, T1, T6, T3, T8, T2, T7, T4;
	       V T9, T5, To, Tq, Tn, Tp, Tc, Th, Te, Tj, Td, Ti, Tf, Tk, Tb;
	       V Tg, Tt, Tv, Ts, Tu, Ty, Tz, Tm, Tx, TC, TD, TA, TB, TI, TO;
	       V TL, TP, TH, TJ, TM, TR, TN, TQ;
	       T1 = LD(&(Rp[0]), ms, &(Rp[0]));
	       T6 = LD(&(Rp[WS(rs, 2)]), ms, &(Rp[0]));
	       T2 = LD(&(Rm[0]), -ms, &(Rm[0]));
	       T3 = VCONJ(T2);
	       T7 = LD(&(Rm[WS(rs, 2)]), -ms, &(Rm[0]));
	       T8 = VCONJ(T7);
	       T4 = VADD(T1, T3);
	       T5 = LDW(&(W[TWVL * 6]));
	       T9 = VZMULJ(T5, VADD(T6, T8));
	       Ta = VADD(T4, T9);
	       TE = VMUL(LDK(KP500000000), VSUB(T4, T9));
	       Tn = LDW(&(W[0]));
	       To = VZMULIJ(Tn, VSUB(T3, T1));
	       Tp = LDW(&(W[TWVL * 8]));
	       Tq = VZMULIJ(Tp, VSUB(T8, T6));
	       Tr = VADD(To, Tq);
	       TF = VSUB(To, Tq);
	       Tc = LD(&(Rp[WS(rs, 1)]), ms, &(Rp[WS(rs, 1)]));
	       Th = LD(&(Rp[WS(rs, 3)]), ms, &(Rp[WS(rs, 1)]));
	       Td = LD(&(Rm[WS(rs, 1)]), -ms, &(Rm[WS(rs, 1)]));
	       Te = VCONJ(Td);
	       Ti = LD(&(Rm[WS(rs, 3)]), -ms, &(Rm[WS(rs, 1)]));
	       Tj = VCONJ(Ti);
	       Tb = LDW(&(W[TWVL * 2]));
	       Tf = VZMULJ(Tb, VADD(Tc, Te));
	       Tg = LDW(&(W[TWVL * 10]));
	       Tk = VZMULJ(Tg, VADD(Th, Tj));
	       Tl = VADD(Tf, Tk);
	       TK = VSUB(Tf, Tk);
	       Ts = LDW(&(W[TWVL * 4]));
	       Tt = VZMULIJ(Ts, VSUB(Te, Tc));
	       Tu = LDW(&(W[TWVL * 12]));
	       Tv = VZMULIJ(Tu, VSUB(Tj, Th));
	       Tw = VADD(Tt, Tv);
	       TG = VSUB(Tv, Tt);
	       Tm = VADD(Ta, Tl);
	       Tx = VADD(Tr, Tw);
	       Ty = VCONJ(VMUL(LDK(KP500000000), VSUB(Tm, Tx)));
	       Tz = VMUL(LDK(KP500000000), VADD(Tm, Tx));
	       ST(&(Rm[WS(rs, 3)]), Ty, -ms, &(Rm[WS(rs, 1)]));
	       ST(&(Rp[0]), Tz, ms, &(Rp[0]));
	       TA = VSUB(Ta, Tl);
	       TB = VBYI(VSUB(Tw, Tr));
	       TC = VCONJ(VMUL(LDK(KP500000000), VSUB(TA, TB)));
	       TD = VMUL(LDK(KP500000000), VADD(TA, TB));
	       ST(&(Rm[WS(rs, 1)]), TC, -ms, &(Rm[WS(rs, 1)]));
	       ST(&(Rp[WS(rs, 2)]), TD, ms, &(Rp[0]));
	       TH = VMUL(LDK(KP353553390), VADD(TF, TG));
	       TI = VADD(TE, TH);
	       TO = VSUB(TE, TH);
	       TJ = VMUL(LDK(KP707106781), VSUB(TG, TF));
	       TL = VMUL(LDK(KP500000000), VBYI(VSUB(TJ, TK)));
	       TP = VMUL(LDK(KP500000000), VBYI(VADD(TK, TJ)));
	       TM = VCONJ(VSUB(TI, TL));
	       ST(&(Rm[0]), TM, -ms, &(Rm[0]));
	       TR = VADD(TO, TP);
	       ST(&(Rp[WS(rs, 3)]), TR, ms, &(Rp[WS(rs, 1)]));
	       TN = VADD(TI, TL);
	       ST(&(Rp[WS(rs, 1)]), TN, ms, &(Rp[WS(rs, 1)]));
	       TQ = VCONJ(VSUB(TO, TP));
	       ST(&(Rm[WS(rs, 2)]), TQ, -ms, &(Rm[0]));
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(1, 1),
     VTW(1, 2),
     VTW(1, 3),
     VTW(1, 4),
     VTW(1, 5),
     VTW(1, 6),
     VTW(1, 7),
     {TW_NEXT, VL, 0}
};

static const hc2c_desc desc = { 8, XSIMD_STRING("hc2cfdftv_8"), twinstr, &GENUS, {41, 23, 0, 0} };

void XSIMD(codelet_hc2cfdftv_8) (planner *p) {
     fftw_khc2c_register (p, hc2cfdftv_8, &desc, HC2C_VIA_DFT);
}
#endif
