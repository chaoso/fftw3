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
/* Generated on Thu May 24 08:06:29 EDT 2018 */

#include "fftw/fftw_api.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2hc.native -fma -compact -variables 4 -pipeline-latency 4 -n 8 -dit -name hf_8 -include fftw/rdft_scalar/hf.h */

/*
 * This function contains 66 FP additions, 36 FP multiplications,
 * (or, 44 additions, 14 multiplications, 22 fused multiply/add),
 * 34 stack variables, 1 constants, and 32 memory accesses
 */
#include "fftw/rdft_scalar/hf.h"

static void hf_8(FFTW_REAL_TYPE *cr, FFTW_REAL_TYPE *ci, const FFTW_REAL_TYPE *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 14); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 14, MAKE_VOLATILE_STRIDE(16, rs)) {
	       E T1, T1m, T7, T1l, Tk, TS, Te, TQ, TF, T14, TL, T16, T12, T17, Ts;
	       E TX, Ty, TZ, TV, T10;
	       T1 = cr[0];
	       T1m = ci[0];
	       {
		    E T3, T6, T4, T1k, T2, T5;
		    T3 = cr[WS(rs, 4)];
		    T6 = ci[WS(rs, 4)];
		    T2 = W[6];
		    T4 = T2 * T3;
		    T1k = T2 * T6;
		    T5 = W[7];
		    T7 = FMA(T5, T6, T4);
		    T1l = FNMS(T5, T3, T1k);
	       }
	       {
		    E Tg, Tj, Th, TR, Tf, Ti;
		    Tg = cr[WS(rs, 6)];
		    Tj = ci[WS(rs, 6)];
		    Tf = W[10];
		    Th = Tf * Tg;
		    TR = Tf * Tj;
		    Ti = W[11];
		    Tk = FMA(Ti, Tj, Th);
		    TS = FNMS(Ti, Tg, TR);
	       }
	       {
		    E Ta, Td, Tb, TP, T9, Tc;
		    Ta = cr[WS(rs, 2)];
		    Td = ci[WS(rs, 2)];
		    T9 = W[2];
		    Tb = T9 * Ta;
		    TP = T9 * Td;
		    Tc = W[3];
		    Te = FMA(Tc, Td, Tb);
		    TQ = FNMS(Tc, Ta, TP);
	       }
	       {
		    E TB, TE, TC, T13, TH, TK, TI, T15, TA, TG, TD, TJ;
		    TB = cr[WS(rs, 7)];
		    TE = ci[WS(rs, 7)];
		    TA = W[12];
		    TC = TA * TB;
		    T13 = TA * TE;
		    TH = cr[WS(rs, 3)];
		    TK = ci[WS(rs, 3)];
		    TG = W[4];
		    TI = TG * TH;
		    T15 = TG * TK;
		    TD = W[13];
		    TF = FMA(TD, TE, TC);
		    T14 = FNMS(TD, TB, T13);
		    TJ = W[5];
		    TL = FMA(TJ, TK, TI);
		    T16 = FNMS(TJ, TH, T15);
		    T12 = TF - TL;
		    T17 = T14 - T16;
	       }
	       {
		    E To, Tr, Tp, TW, Tu, Tx, Tv, TY, Tn, Tt, Tq, Tw;
		    To = cr[WS(rs, 1)];
		    Tr = ci[WS(rs, 1)];
		    Tn = W[0];
		    Tp = Tn * To;
		    TW = Tn * Tr;
		    Tu = cr[WS(rs, 5)];
		    Tx = ci[WS(rs, 5)];
		    Tt = W[8];
		    Tv = Tt * Tu;
		    TY = Tt * Tx;
		    Tq = W[1];
		    Ts = FMA(Tq, Tr, Tp);
		    TX = FNMS(Tq, To, TW);
		    Tw = W[9];
		    Ty = FMA(Tw, Tx, Tv);
		    TZ = FNMS(Tw, Tu, TY);
		    TV = Ts - Ty;
		    T10 = TX - TZ;
	       }
	       {
		    E TU, T1a, T1t, T1v, T19, T1u, T1d, T1w;
		    {
			 E TO, TT, T1r, T1s;
			 TO = T1 - T7;
			 TT = TQ - TS;
			 TU = TO + TT;
			 T1a = TO - TT;
			 T1r = Te - Tk;
			 T1s = T1m - T1l;
			 T1t = T1r + T1s;
			 T1v = T1s - T1r;
		    }
		    {
			 E T11, T18, T1b, T1c;
			 T11 = TV + T10;
			 T18 = T12 - T17;
			 T19 = T11 + T18;
			 T1u = T18 - T11;
			 T1b = TV - T10;
			 T1c = T12 + T17;
			 T1d = T1b + T1c;
			 T1w = T1c - T1b;
		    }
		    ci[WS(rs, 2)] = FNMS(KP707106781, T19, TU);
		    cr[WS(rs, 5)] = FMS(KP707106781, T1w, T1v);
		    ci[WS(rs, 6)] = FMA(KP707106781, T1w, T1v);
		    cr[WS(rs, 1)] = FMA(KP707106781, T19, TU);
		    cr[WS(rs, 3)] = FNMS(KP707106781, T1d, T1a);
		    cr[WS(rs, 7)] = FMS(KP707106781, T1u, T1t);
		    ci[WS(rs, 4)] = FMA(KP707106781, T1u, T1t);
		    ci[0] = FMA(KP707106781, T1d, T1a);
	       }
	       {
		    E Tm, T1e, T1o, T1q, TN, T1p, T1h, T1i;
		    {
			 E T8, Tl, T1j, T1n;
			 T8 = T1 + T7;
			 Tl = Te + Tk;
			 Tm = T8 + Tl;
			 T1e = T8 - Tl;
			 T1j = TQ + TS;
			 T1n = T1l + T1m;
			 T1o = T1j + T1n;
			 T1q = T1n - T1j;
		    }
		    {
			 E Tz, TM, T1f, T1g;
			 Tz = Ts + Ty;
			 TM = TF + TL;
			 TN = Tz + TM;
			 T1p = TM - Tz;
			 T1f = T14 + T16;
			 T1g = TX + TZ;
			 T1h = T1f - T1g;
			 T1i = T1g + T1f;
		    }
		    ci[WS(rs, 3)] = Tm - TN;
		    cr[WS(rs, 6)] = T1p - T1q;
		    ci[WS(rs, 5)] = T1p + T1q;
		    cr[0] = Tm + TN;
		    cr[WS(rs, 2)] = T1e - T1h;
		    cr[WS(rs, 4)] = T1i - T1o;
		    ci[WS(rs, 7)] = T1i + T1o;
		    ci[WS(rs, 1)] = T1e + T1h;
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 1, 8},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 8, "hf_8", twinstr, &GENUS, {44, 14, 22, 0} };

void fftw_codelet_hf_8 (planner *p) {
     fftw_khc2hc_register (p, hf_8, &desc);
}
#else

/* Generated by: ../../../genfft/gen_hc2hc.native -compact -variables 4 -pipeline-latency 4 -n 8 -dit -name hf_8 -include fftw/rdft_scalar/hf.h */

/*
 * This function contains 66 FP additions, 32 FP multiplications,
 * (or, 52 additions, 18 multiplications, 14 fused multiply/add),
 * 28 stack variables, 1 constants, and 32 memory accesses
 */
#include "fftw/rdft_scalar/hf.h"

static void hf_8(FFTW_REAL_TYPE *cr, FFTW_REAL_TYPE *ci, const FFTW_REAL_TYPE *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 14); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 14, MAKE_VOLATILE_STRIDE(16, rs)) {
	       E T7, T1f, TH, T19, TF, T12, TR, TU, Ti, T1e, TK, T16, Tu, T13, TM;
	       E TP;
	       {
		    E T1, T18, T6, T17;
		    T1 = cr[0];
		    T18 = ci[0];
		    {
			 E T3, T5, T2, T4;
			 T3 = cr[WS(rs, 4)];
			 T5 = ci[WS(rs, 4)];
			 T2 = W[6];
			 T4 = W[7];
			 T6 = FMA(T2, T3, T4 * T5);
			 T17 = FNMS(T4, T3, T2 * T5);
		    }
		    T7 = T1 + T6;
		    T1f = T18 - T17;
		    TH = T1 - T6;
		    T19 = T17 + T18;
	       }
	       {
		    E Tz, TS, TE, TT;
		    {
			 E Tw, Ty, Tv, Tx;
			 Tw = cr[WS(rs, 7)];
			 Ty = ci[WS(rs, 7)];
			 Tv = W[12];
			 Tx = W[13];
			 Tz = FMA(Tv, Tw, Tx * Ty);
			 TS = FNMS(Tx, Tw, Tv * Ty);
		    }
		    {
			 E TB, TD, TA, TC;
			 TB = cr[WS(rs, 3)];
			 TD = ci[WS(rs, 3)];
			 TA = W[4];
			 TC = W[5];
			 TE = FMA(TA, TB, TC * TD);
			 TT = FNMS(TC, TB, TA * TD);
		    }
		    TF = Tz + TE;
		    T12 = TS + TT;
		    TR = Tz - TE;
		    TU = TS - TT;
	       }
	       {
		    E Tc, TI, Th, TJ;
		    {
			 E T9, Tb, T8, Ta;
			 T9 = cr[WS(rs, 2)];
			 Tb = ci[WS(rs, 2)];
			 T8 = W[2];
			 Ta = W[3];
			 Tc = FMA(T8, T9, Ta * Tb);
			 TI = FNMS(Ta, T9, T8 * Tb);
		    }
		    {
			 E Te, Tg, Td, Tf;
			 Te = cr[WS(rs, 6)];
			 Tg = ci[WS(rs, 6)];
			 Td = W[10];
			 Tf = W[11];
			 Th = FMA(Td, Te, Tf * Tg);
			 TJ = FNMS(Tf, Te, Td * Tg);
		    }
		    Ti = Tc + Th;
		    T1e = Tc - Th;
		    TK = TI - TJ;
		    T16 = TI + TJ;
	       }
	       {
		    E To, TN, Tt, TO;
		    {
			 E Tl, Tn, Tk, Tm;
			 Tl = cr[WS(rs, 1)];
			 Tn = ci[WS(rs, 1)];
			 Tk = W[0];
			 Tm = W[1];
			 To = FMA(Tk, Tl, Tm * Tn);
			 TN = FNMS(Tm, Tl, Tk * Tn);
		    }
		    {
			 E Tq, Ts, Tp, Tr;
			 Tq = cr[WS(rs, 5)];
			 Ts = ci[WS(rs, 5)];
			 Tp = W[8];
			 Tr = W[9];
			 Tt = FMA(Tp, Tq, Tr * Ts);
			 TO = FNMS(Tr, Tq, Tp * Ts);
		    }
		    Tu = To + Tt;
		    T13 = TN + TO;
		    TM = To - Tt;
		    TP = TN - TO;
	       }
	       {
		    E Tj, TG, T1b, T1c;
		    Tj = T7 + Ti;
		    TG = Tu + TF;
		    ci[WS(rs, 3)] = Tj - TG;
		    cr[0] = Tj + TG;
		    T1b = TF - Tu;
		    T1c = T19 - T16;
		    cr[WS(rs, 6)] = T1b - T1c;
		    ci[WS(rs, 5)] = T1b + T1c;
		    {
			 E TX, T1i, T10, T1h, TY, TZ;
			 TX = TH - TK;
			 T1i = T1f - T1e;
			 TY = TM - TP;
			 TZ = TR + TU;
			 T10 = KP707106781 * (TY + TZ);
			 T1h = KP707106781 * (TZ - TY);
			 cr[WS(rs, 3)] = TX - T10;
			 ci[WS(rs, 6)] = T1h + T1i;
			 ci[0] = TX + T10;
			 cr[WS(rs, 5)] = T1h - T1i;
		    }
	       }
	       {
		    E T15, T1a, T11, T14;
		    T15 = T13 + T12;
		    T1a = T16 + T19;
		    cr[WS(rs, 4)] = T15 - T1a;
		    ci[WS(rs, 7)] = T15 + T1a;
		    T11 = T7 - Ti;
		    T14 = T12 - T13;
		    cr[WS(rs, 2)] = T11 - T14;
		    ci[WS(rs, 1)] = T11 + T14;
		    {
			 E TL, T1g, TW, T1d, TQ, TV;
			 TL = TH + TK;
			 T1g = T1e + T1f;
			 TQ = TM + TP;
			 TV = TR - TU;
			 TW = KP707106781 * (TQ + TV);
			 T1d = KP707106781 * (TV - TQ);
			 ci[WS(rs, 2)] = TL - TW;
			 ci[WS(rs, 4)] = T1d + T1g;
			 cr[WS(rs, 1)] = TL + TW;
			 cr[WS(rs, 7)] = T1d - T1g;
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 1, 8},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 8, "hf_8", twinstr, &GENUS, {52, 18, 14, 0} };

void fftw_codelet_hf_8 (planner *p) {
     fftw_khc2hc_register (p, hf_8, &desc);
}
#endif
