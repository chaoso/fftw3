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
/* Generated on Thu May 24 08:07:44 EDT 2018 */

#include "fftw/fftw_api.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_r2cb.native -fma -compact -variables 4 -pipeline-latency 4 -sign 1 -n 16 -name r2cbIII_16 -dft-III -include fftw/rdft_scalar/r2cbIII.h */

/*
 * This function contains 66 FP additions, 36 FP multiplications,
 * (or, 46 additions, 16 multiplications, 20 fused multiply/add),
 * 40 stack variables, 9 constants, and 32 memory accesses
 */
#include "fftw/rdft_scalar/r2cbIII.h"

static void r2cbIII_16(FFTW_REAL_TYPE *R0, FFTW_REAL_TYPE *R1, FFTW_REAL_TYPE *Cr, FFTW_REAL_TYPE *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP198912367, +0.198912367379658006911597622644676228597850501);
     DK(KP1_961570560, +1.961570560806460898252364472268478073947867462);
     DK(KP668178637, +0.668178637919298919997757686523080761552472251);
     DK(KP1_662939224, +1.662939224605090474157576755235811513477121624);
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     DK(KP1_414213562, +1.414213562373095048801688724209698078569671875);
     DK(KP414213562, +0.414213562373095048801688724209698078569671875);
     DK(KP1_847759065, +1.847759065022573512256366378793576573644833252);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(64, rs), MAKE_VOLATILE_STRIDE(64, csr), MAKE_VOLATILE_STRIDE(64, csi)) {
	       E T7, TW, T13, Tj, TA, TK, TP, TH, Te, TX, T12, To, Tt, TC, TS;
	       E TB, TT, TY;
	       {
		    E T3, Tf, Tz, TU, T6, Tw, Ti, TV;
		    {
			 E T1, T2, Tx, Ty;
			 T1 = Cr[0];
			 T2 = Cr[WS(csr, 7)];
			 T3 = T1 + T2;
			 Tf = T1 - T2;
			 Tx = Ci[0];
			 Ty = Ci[WS(csi, 7)];
			 Tz = Tx + Ty;
			 TU = Ty - Tx;
		    }
		    {
			 E T4, T5, Tg, Th;
			 T4 = Cr[WS(csr, 4)];
			 T5 = Cr[WS(csr, 3)];
			 T6 = T4 + T5;
			 Tw = T4 - T5;
			 Tg = Ci[WS(csi, 4)];
			 Th = Ci[WS(csi, 3)];
			 Ti = Tg + Th;
			 TV = Th - Tg;
		    }
		    T7 = T3 + T6;
		    TW = TU - TV;
		    T13 = TV + TU;
		    Tj = Tf - Ti;
		    TA = Tw + Tz;
		    TK = Tw - Tz;
		    TP = T3 - T6;
		    TH = Tf + Ti;
	       }
	       {
		    E Ta, Tk, Tn, TR, Td, Tp, Ts, TQ;
		    {
			 E T8, T9, Tl, Tm;
			 T8 = Cr[WS(csr, 2)];
			 T9 = Cr[WS(csr, 5)];
			 Ta = T8 + T9;
			 Tk = T8 - T9;
			 Tl = Ci[WS(csi, 2)];
			 Tm = Ci[WS(csi, 5)];
			 Tn = Tl + Tm;
			 TR = Tl - Tm;
		    }
		    {
			 E Tb, Tc, Tq, Tr;
			 Tb = Cr[WS(csr, 1)];
			 Tc = Cr[WS(csr, 6)];
			 Td = Tb + Tc;
			 Tp = Tb - Tc;
			 Tq = Ci[WS(csi, 1)];
			 Tr = Ci[WS(csi, 6)];
			 Ts = Tq + Tr;
			 TQ = Tr - Tq;
		    }
		    Te = Ta + Td;
		    TX = Ta - Td;
		    T12 = TR + TQ;
		    To = Tk - Tn;
		    Tt = Tp - Ts;
		    TC = Tk + Tn;
		    TS = TQ - TR;
		    TB = Tp + Ts;
	       }
	       R0[0] = KP2_000000000 * (T7 + Te);
	       R0[WS(rs, 4)] = KP2_000000000 * (T13 - T12);
	       TT = TP + TS;
	       TY = TW - TX;
	       R0[WS(rs, 1)] = KP1_847759065 * (FMA(KP414213562, TY, TT));
	       R0[WS(rs, 5)] = KP1_847759065 * (FNMS(KP414213562, TT, TY));
	       {
		    E T11, T14, TZ, T10;
		    T11 = T7 - Te;
		    T14 = T12 + T13;
		    R0[WS(rs, 2)] = KP1_414213562 * (T11 + T14);
		    R0[WS(rs, 6)] = KP1_414213562 * (T14 - T11);
		    TZ = TX + TW;
		    T10 = TP - TS;
		    R0[WS(rs, 3)] = KP1_847759065 * (FMA(KP414213562, T10, TZ));
		    R0[WS(rs, 7)] = -(KP1_847759065 * (FNMS(KP414213562, TZ, T10)));
	       }
	       {
		    E TJ, TO, TM, TN, TI, TL;
		    TI = TC + TB;
		    TJ = FNMS(KP707106781, TI, TH);
		    TO = FMA(KP707106781, TI, TH);
		    TL = To - Tt;
		    TM = FNMS(KP707106781, TL, TK);
		    TN = FMA(KP707106781, TL, TK);
		    R1[WS(rs, 1)] = KP1_662939224 * (FMA(KP668178637, TM, TJ));
		    R1[WS(rs, 7)] = -(KP1_961570560 * (FNMS(KP198912367, TN, TO)));
		    R1[WS(rs, 5)] = KP1_662939224 * (FNMS(KP668178637, TJ, TM));
		    R1[WS(rs, 3)] = KP1_961570560 * (FMA(KP198912367, TO, TN));
	       }
	       {
		    E Tv, TG, TE, TF, Tu, TD;
		    Tu = To + Tt;
		    Tv = FMA(KP707106781, Tu, Tj);
		    TG = FNMS(KP707106781, Tu, Tj);
		    TD = TB - TC;
		    TE = FNMS(KP707106781, TD, TA);
		    TF = FMA(KP707106781, TD, TA);
		    R1[0] = KP1_961570560 * (FNMS(KP198912367, TE, Tv));
		    R1[WS(rs, 6)] = -(KP1_662939224 * (FMA(KP668178637, TF, TG)));
		    R1[WS(rs, 4)] = -(KP1_961570560 * (FMA(KP198912367, Tv, TE)));
		    R1[WS(rs, 2)] = -(KP1_662939224 * (FNMS(KP668178637, TG, TF)));
	       }
	  }
     }
}

static const kr2c_desc desc = { 16, "r2cbIII_16", {46, 16, 20, 0}, &GENUS };

void fftw_codelet_r2cbIII_16 (planner *p) {
     fftw_kr2c_register (p, r2cbIII_16, &desc);
}

#else

/* Generated by: ../../../genfft/gen_r2cb.native -compact -variables 4 -pipeline-latency 4 -sign 1 -n 16 -name r2cbIII_16 -dft-III -include fftw/rdft_scalar/r2cbIII.h */

/*
 * This function contains 66 FP additions, 32 FP multiplications,
 * (or, 54 additions, 20 multiplications, 12 fused multiply/add),
 * 40 stack variables, 9 constants, and 32 memory accesses
 */
#include "fftw/rdft_scalar/r2cbIII.h"

static void r2cbIII_16(FFTW_REAL_TYPE *R0, FFTW_REAL_TYPE *R1, FFTW_REAL_TYPE *Cr, FFTW_REAL_TYPE *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP1_961570560, +1.961570560806460898252364472268478073947867462);
     DK(KP390180644, +0.390180644032256535696569736954044481855383236);
     DK(KP1_111140466, +1.111140466039204449485661627897065748749874382);
     DK(KP1_662939224, +1.662939224605090474157576755235811513477121624);
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     DK(KP1_414213562, +1.414213562373095048801688724209698078569671875);
     DK(KP765366864, +0.765366864730179543456919968060797733522689125);
     DK(KP1_847759065, +1.847759065022573512256366378793576573644833252);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(64, rs), MAKE_VOLATILE_STRIDE(64, csr), MAKE_VOLATILE_STRIDE(64, csi)) {
	       E T7, TW, T13, Tj, TD, TK, TP, TH, Te, TX, T12, To, Tt, Tx, TS;
	       E Tw, TT, TY;
	       {
		    E T3, Tf, TC, TV, T6, Tz, Ti, TU;
		    {
			 E T1, T2, TA, TB;
			 T1 = Cr[0];
			 T2 = Cr[WS(csr, 7)];
			 T3 = T1 + T2;
			 Tf = T1 - T2;
			 TA = Ci[0];
			 TB = Ci[WS(csi, 7)];
			 TC = TA + TB;
			 TV = TB - TA;
		    }
		    {
			 E T4, T5, Tg, Th;
			 T4 = Cr[WS(csr, 4)];
			 T5 = Cr[WS(csr, 3)];
			 T6 = T4 + T5;
			 Tz = T4 - T5;
			 Tg = Ci[WS(csi, 4)];
			 Th = Ci[WS(csi, 3)];
			 Ti = Tg + Th;
			 TU = Tg - Th;
		    }
		    T7 = T3 + T6;
		    TW = TU + TV;
		    T13 = TV - TU;
		    Tj = Tf - Ti;
		    TD = Tz + TC;
		    TK = Tz - TC;
		    TP = T3 - T6;
		    TH = Tf + Ti;
	       }
	       {
		    E Ta, Tk, Tn, TR, Td, Tp, Ts, TQ;
		    {
			 E T8, T9, Tl, Tm;
			 T8 = Cr[WS(csr, 2)];
			 T9 = Cr[WS(csr, 5)];
			 Ta = T8 + T9;
			 Tk = T8 - T9;
			 Tl = Ci[WS(csi, 2)];
			 Tm = Ci[WS(csi, 5)];
			 Tn = Tl + Tm;
			 TR = Tl - Tm;
		    }
		    {
			 E Tb, Tc, Tq, Tr;
			 Tb = Cr[WS(csr, 1)];
			 Tc = Cr[WS(csr, 6)];
			 Td = Tb + Tc;
			 Tp = Tb - Tc;
			 Tq = Ci[WS(csi, 1)];
			 Tr = Ci[WS(csi, 6)];
			 Ts = Tq + Tr;
			 TQ = Tr - Tq;
		    }
		    Te = Ta + Td;
		    TX = Ta - Td;
		    T12 = TR + TQ;
		    To = Tk - Tn;
		    Tt = Tp - Ts;
		    Tx = Tp + Ts;
		    TS = TQ - TR;
		    Tw = Tk + Tn;
	       }
	       R0[0] = KP2_000000000 * (T7 + Te);
	       R0[WS(rs, 4)] = KP2_000000000 * (T13 - T12);
	       TT = TP + TS;
	       TY = TW - TX;
	       R0[WS(rs, 1)] = FMA(KP1_847759065, TT, KP765366864 * TY);
	       R0[WS(rs, 5)] = FNMS(KP765366864, TT, KP1_847759065 * TY);
	       {
		    E T11, T14, TZ, T10;
		    T11 = T7 - Te;
		    T14 = T12 + T13;
		    R0[WS(rs, 2)] = KP1_414213562 * (T11 + T14);
		    R0[WS(rs, 6)] = KP1_414213562 * (T14 - T11);
		    TZ = TP - TS;
		    T10 = TX + TW;
		    R0[WS(rs, 3)] = FMA(KP765366864, TZ, KP1_847759065 * T10);
		    R0[WS(rs, 7)] = FNMS(KP1_847759065, TZ, KP765366864 * T10);
	       }
	       {
		    E TJ, TN, TM, TO, TI, TL;
		    TI = KP707106781 * (Tw + Tx);
		    TJ = TH - TI;
		    TN = TH + TI;
		    TL = KP707106781 * (To - Tt);
		    TM = TK - TL;
		    TO = TL + TK;
		    R1[WS(rs, 1)] = FMA(KP1_662939224, TJ, KP1_111140466 * TM);
		    R1[WS(rs, 7)] = FNMS(KP1_961570560, TN, KP390180644 * TO);
		    R1[WS(rs, 5)] = FNMS(KP1_111140466, TJ, KP1_662939224 * TM);
		    R1[WS(rs, 3)] = FMA(KP390180644, TN, KP1_961570560 * TO);
	       }
	       {
		    E Tv, TF, TE, TG, Tu, Ty;
		    Tu = KP707106781 * (To + Tt);
		    Tv = Tj + Tu;
		    TF = Tj - Tu;
		    Ty = KP707106781 * (Tw - Tx);
		    TE = Ty + TD;
		    TG = Ty - TD;
		    R1[0] = FNMS(KP390180644, TE, KP1_961570560 * Tv);
		    R1[WS(rs, 6)] = FNMS(KP1_662939224, TF, KP1_111140466 * TG);
		    R1[WS(rs, 4)] = -(FMA(KP390180644, Tv, KP1_961570560 * TE));
		    R1[WS(rs, 2)] = FMA(KP1_111140466, TF, KP1_662939224 * TG);
	       }
	  }
     }
}

static const kr2c_desc desc = { 16, "r2cbIII_16", {54, 20, 12, 0}, &GENUS };

void fftw_codelet_r2cbIII_16 (planner *p) {
     fftw_kr2c_register (p, r2cbIII_16, &desc);
}

#endif
