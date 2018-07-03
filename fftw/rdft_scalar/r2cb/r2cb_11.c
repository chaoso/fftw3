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
/* Generated on Thu May 24 08:07:28 EDT 2018 */

#include "fftw/fftw_api.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_r2cb.native -fma -compact -variables 4 -pipeline-latency 4 -sign 1 -n 11 -name r2cb_11 -include fftw/rdft_scalar/r2cb.h */

/*
 * This function contains 60 FP additions, 56 FP multiplications,
 * (or, 4 additions, 0 multiplications, 56 fused multiply/add),
 * 44 stack variables, 11 constants, and 22 memory accesses
 */
#include "fftw/rdft_scalar/r2cb.h"

static void r2cb_11(FFTW_REAL_TYPE *R0, FFTW_REAL_TYPE *R1, FFTW_REAL_TYPE *Cr, FFTW_REAL_TYPE *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP1_979642883, +1.979642883761865464752184075553437574753038744);
     DK(KP918985947, +0.918985947228994779780736114132655398124909697);
     DK(KP830830026, +0.830830026003772851058548298459246407048009821);
     DK(KP1_918985947, +1.918985947228994779780736114132655398124909697);
     DK(KP876768831, +0.876768831002589333891339807079336796764054852);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     DK(KP778434453, +0.778434453334651800608337670740821884709317477);
     DK(KP634356270, +0.634356270682424498893150776899916060542806975);
     DK(KP342584725, +0.342584725681637509502641509861112333758894680);
     DK(KP715370323, +0.715370323453429719112414662767260662417897278);
     DK(KP521108558, +0.521108558113202722944698153526659300680427422);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(44, rs), MAKE_VOLATILE_STRIDE(44, csr), MAKE_VOLATILE_STRIDE(44, csi)) {
	       E T1, Td, Th, Te, Tf, Tg, Tj, TT, Ts, TB, TK, T2, T6, T3, T4;
	       E T5, Ta, To, TP, TG, Tx, T7;
	       T1 = Cr[0];
	       {
		    E Ti, TS, Tr, TA, TJ;
		    Td = Ci[WS(csi, 3)];
		    Th = Ci[WS(csi, 5)];
		    Te = Ci[WS(csi, 2)];
		    Tf = Ci[WS(csi, 4)];
		    Tg = Ci[WS(csi, 1)];
		    Ti = FMA(KP521108558, Th, Tg);
		    TS = FMS(KP521108558, Tg, Te);
		    Tr = FMA(KP521108558, Td, Th);
		    TA = FNMS(KP521108558, Te, Tf);
		    TJ = FMA(KP521108558, Tf, Td);
		    Tj = FMA(KP715370323, Ti, Tf);
		    TT = FMA(KP715370323, TS, Td);
		    Ts = FNMS(KP715370323, Tr, Te);
		    TB = FMA(KP715370323, TA, Th);
		    TK = FMA(KP715370323, TJ, Tg);
	       }
	       {
		    E T8, TN, Tm, Tv, TE;
		    T2 = Cr[WS(csr, 1)];
		    T6 = Cr[WS(csr, 5)];
		    T3 = Cr[WS(csr, 2)];
		    T4 = Cr[WS(csr, 3)];
		    T5 = Cr[WS(csr, 4)];
		    T8 = FNMS(KP342584725, T4, T3);
		    TN = FNMS(KP342584725, T6, T5);
		    Tm = FNMS(KP342584725, T5, T2);
		    Tv = FNMS(KP342584725, T2, T4);
		    TE = FNMS(KP342584725, T3, T6);
		    {
			 E T9, Tn, TO, TF, Tw;
			 T9 = FNMS(KP634356270, T8, T5);
			 Ta = FNMS(KP778434453, T9, T2);
			 Tn = FNMS(KP634356270, Tm, T3);
			 To = FNMS(KP778434453, Tn, T6);
			 TO = FNMS(KP634356270, TN, T4);
			 TP = FNMS(KP778434453, TO, T3);
			 TF = FNMS(KP634356270, TE, T2);
			 TG = FNMS(KP778434453, TF, T4);
			 Tw = FNMS(KP634356270, Tv, T6);
			 Tx = FNMS(KP778434453, Tw, T5);
			 T7 = T2 + T3 + T4 + T5 + T6;
		    }
	       }
	       R0[0] = FMA(KP2_000000000, T7, T1);
	       {
		    E Tc, Tl, Tb, Tk;
		    Tb = FNMS(KP876768831, Ta, T6);
		    Tc = FNMS(KP1_918985947, Tb, T1);
		    Tk = FMA(KP830830026, Tj, Te);
		    Tl = FMA(KP918985947, Tk, Td);
		    R1[0] = FNMS(KP1_979642883, Tl, Tc);
		    R0[WS(rs, 5)] = FMA(KP1_979642883, Tl, Tc);
	       }
	       {
		    E TR, TV, TQ, TU;
		    TQ = FNMS(KP876768831, TP, T2);
		    TR = FNMS(KP1_918985947, TQ, T1);
		    TU = FNMS(KP830830026, TT, Tf);
		    TV = FNMS(KP918985947, TU, Th);
		    R1[WS(rs, 2)] = FNMS(KP1_979642883, TV, TR);
		    R0[WS(rs, 3)] = FMA(KP1_979642883, TV, TR);
	       }
	       {
		    E TI, TM, TH, TL;
		    TH = FNMS(KP876768831, TG, T5);
		    TI = FNMS(KP1_918985947, TH, T1);
		    TL = FNMS(KP830830026, TK, Th);
		    TM = FMA(KP918985947, TL, Te);
		    R1[WS(rs, 3)] = FNMS(KP1_979642883, TM, TI);
		    R0[WS(rs, 2)] = FMA(KP1_979642883, TM, TI);
	       }
	       {
		    E Tz, TD, Ty, TC;
		    Ty = FNMS(KP876768831, Tx, T3);
		    Tz = FNMS(KP1_918985947, Ty, T1);
		    TC = FNMS(KP830830026, TB, Td);
		    TD = FNMS(KP918985947, TC, Tg);
		    R1[WS(rs, 1)] = FNMS(KP1_979642883, TD, Tz);
		    R0[WS(rs, 4)] = FMA(KP1_979642883, TD, Tz);
	       }
	       {
		    E Tq, Tu, Tp, Tt;
		    Tp = FNMS(KP876768831, To, T4);
		    Tq = FNMS(KP1_918985947, Tp, T1);
		    Tt = FMA(KP830830026, Ts, Tg);
		    Tu = FNMS(KP918985947, Tt, Tf);
		    R1[WS(rs, 4)] = FNMS(KP1_979642883, Tu, Tq);
		    R0[WS(rs, 1)] = FMA(KP1_979642883, Tu, Tq);
	       }
	  }
     }
}

static const kr2c_desc desc = { 11, "r2cb_11", {4, 0, 56, 0}, &GENUS };

void fftw_codelet_r2cb_11 (planner *p) {
     fftw_kr2c_register (p, r2cb_11, &desc);
}

#else

/* Generated by: ../../../genfft/gen_r2cb.native -compact -variables 4 -pipeline-latency 4 -sign 1 -n 11 -name r2cb_11 -include fftw/rdft_scalar/r2cb.h */

/*
 * This function contains 60 FP additions, 51 FP multiplications,
 * (or, 19 additions, 10 multiplications, 41 fused multiply/add),
 * 33 stack variables, 11 constants, and 22 memory accesses
 */
#include "fftw/rdft_scalar/r2cb.h"

static void r2cb_11(FFTW_REAL_TYPE *R0, FFTW_REAL_TYPE *R1, FFTW_REAL_TYPE *Cr, FFTW_REAL_TYPE *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     DK(KP1_918985947, +1.918985947228994779780736114132655398124909697);
     DK(KP1_309721467, +1.309721467890570128113850144932587106367582399);
     DK(KP284629676, +0.284629676546570280887585337232739337582102722);
     DK(KP830830026, +0.830830026003772851058548298459246407048009821);
     DK(KP1_682507065, +1.682507065662362337723623297838735435026584997);
     DK(KP563465113, +0.563465113682859395422835830693233798071555798);
     DK(KP1_511499148, +1.511499148708516567548071687944688840359434890);
     DK(KP1_979642883, +1.979642883761865464752184075553437574753038744);
     DK(KP1_819263990, +1.819263990709036742823430766158056920120482102);
     DK(KP1_081281634, +1.081281634911195164215271908637383390863541216);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(44, rs), MAKE_VOLATILE_STRIDE(44, csr), MAKE_VOLATILE_STRIDE(44, csi)) {
	       E Td, Tl, Tf, Th, Tj, T1, T2, T6, T5, T4, T3, T7, Tk, Te, Tg;
	       E Ti;
	       {
		    E T8, Tc, T9, Ta, Tb;
		    T8 = Ci[WS(csi, 2)];
		    Tc = Ci[WS(csi, 1)];
		    T9 = Ci[WS(csi, 4)];
		    Ta = Ci[WS(csi, 5)];
		    Tb = Ci[WS(csi, 3)];
		    Td = FMA(KP1_081281634, T8, KP1_819263990 * T9) + FNMA(KP1_979642883, Ta, KP1_511499148 * Tb) - (KP563465113 * Tc);
		    Tl = FMA(KP1_979642883, T8, KP1_819263990 * Ta) + FNMA(KP563465113, T9, KP1_081281634 * Tb) - (KP1_511499148 * Tc);
		    Tf = FMA(KP563465113, T8, KP1_819263990 * Tb) + FNMA(KP1_511499148, Ta, KP1_081281634 * T9) - (KP1_979642883 * Tc);
		    Th = FMA(KP1_081281634, Tc, KP1_819263990 * T8) + FMA(KP1_979642883, Tb, KP1_511499148 * T9) + (KP563465113 * Ta);
		    Tj = FMA(KP563465113, Tb, KP1_979642883 * T9) + FNMS(KP1_511499148, T8, KP1_081281634 * Ta) - (KP1_819263990 * Tc);
	       }
	       T1 = Cr[0];
	       T2 = Cr[WS(csr, 1)];
	       T6 = Cr[WS(csr, 5)];
	       T5 = Cr[WS(csr, 4)];
	       T4 = Cr[WS(csr, 3)];
	       T3 = Cr[WS(csr, 2)];
	       T7 = FMA(KP1_682507065, T3, T1) + FNMS(KP284629676, T6, KP830830026 * T5) + FNMA(KP1_309721467, T4, KP1_918985947 * T2);
	       Tk = FMA(KP1_682507065, T4, T1) + FNMS(KP1_918985947, T5, KP830830026 * T6) + FNMA(KP284629676, T3, KP1_309721467 * T2);
	       Te = FMA(KP830830026, T4, T1) + FNMS(KP1_309721467, T6, KP1_682507065 * T5) + FNMA(KP1_918985947, T3, KP284629676 * T2);
	       Tg = FMA(KP1_682507065, T2, T1) + FNMS(KP1_918985947, T6, KP830830026 * T3) + FNMA(KP1_309721467, T5, KP284629676 * T4);
	       Ti = FMA(KP830830026, T2, T1) + FNMS(KP284629676, T5, KP1_682507065 * T6) + FNMA(KP1_918985947, T4, KP1_309721467 * T3);
	       R0[WS(rs, 3)] = T7 - Td;
	       R0[WS(rs, 4)] = Te - Tf;
	       R0[WS(rs, 2)] = Tk + Tl;
	       R1[WS(rs, 2)] = T7 + Td;
	       R1[WS(rs, 3)] = Tk - Tl;
	       R0[WS(rs, 1)] = Ti + Tj;
	       R1[WS(rs, 1)] = Te + Tf;
	       R0[WS(rs, 5)] = Tg + Th;
	       R1[0] = Tg - Th;
	       R1[WS(rs, 4)] = Ti - Tj;
	       R0[0] = FMA(KP2_000000000, T2 + T3 + T4 + T5 + T6, T1);
	  }
     }
}

static const kr2c_desc desc = { 11, "r2cb_11", {19, 10, 41, 0}, &GENUS };

void fftw_codelet_r2cb_11 (planner *p) {
     fftw_kr2c_register (p, r2cb_11, &desc);
}

#endif
