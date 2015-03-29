/***********************************************************************
Copyright (c) 2006-2012, Skype Limited. All rights reserved. 
Redistribution and use in source and binary forms, with or without 
modification, (subject to the limitations in the disclaimer below) 
are permitted provided that the following conditions are met:
- Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright 
notice, this list of conditions and the following disclaimer in the 
documentation and/or other materials provided with the distribution.
- Neither the name of Skype Limited, nor the names of specific 
contributors, may be used to endorse or promote products derived from 
this software without specific prior written permission.
NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED 
BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
CONTRIBUTORS ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND 
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF 
USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON 
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***********************************************************************/

/*                                                                      *
 * SKP_Silk_resampler_private_up2_HQ_mips.c                                *
 *                                                                      *
 * Upsample by a factor 2, high quality                                 *
 *                                                                      *
 * Copyright 2010 (c), Skype Limited                                    *
 *                                                                      */

#include "SKP_Silk_SigProc_FIX.h"
#include "SKP_Silk_resampler_private.h"

#if defined(EMBEDDED_MIPS)

/* Tables for 2x upsampler, high quality. Values above 32767 intentionally wrap to a negative value. */
//const SKP_int16 SKP_Silk_resampler_up2_hq_0[ 2 ] = {  4280, 33727 };
//const SKP_int16 SKP_Silk_resampler_up2_hq_1[ 2 ] = { 16295, 54015 };
/* Matlab code for the notch filter coefficients: */
/* B = [1, 0.12, 1];  A = [1, 0.055, 0.8]; G = 0.87; freqz(G * B, A, 2^14, 16e3); axis([0, 8000, -10, 1]);  */
/* fprintf('\t%6d, %6d, %6d, %6d\n', round(B(2)*2^16), round(-A(2)*2^16), round((1-A(3))*2^16), round(G*2^15)) */
//const SKP_int16 SKP_Silk_resampler_up2_hq_notch[ 4 ] = { 7864,  -3604,  13107,  28508 };


#define RESAMPLER_PRIVATE_UP2_HQ(S, out, in, len)	\
__asm__ volatile (	\
  ".set push			\n\t"	\
  ".set noreorder		\n\t"	\
  "blez	%3, 1f			\n\t"	\
  "lw	$10, 0(%0)		\n\t"	\
  "lw	$11, 4(%0)		\n\t"	\
  "lw	$12, 8(%0)		\n\t"	\
  "lw	$13, 12(%0)		\n\t"	\
  "lw	$14, 16(%0)		\n\t"	\
  "lw	$15, 20(%0)		\n\t"	\
  "0:					\n\t"	\
  "lh	$16, 0(%2)		\n\t"	\
  "lui	$8, 0x10B8		\n\t"	\
  "lui	$9, 0x83BF		\n\t"	\
  "sll	$16, $16, 10	\n\t"	\
  "subu	$17, $16, $10	\n\t"	\
  "mult	$17, $8			\n\t"	\
  "mfhi	$18				\n\t"	\
  "addu	$21, $18, $10	\n\t"	\
  "addu	$10, $18, $16	\n\t"	\
  \
  "subu	$17, $21, $11	\n\t"	\
  "mult	$17, $9			\n\t"	\
  "mfhi	$18				\n\t"	\
  "addu	$18, $18, $17	\n\t"	\
  "addu	$22, $18, $11	\n\t"	\
  "addu	$11, $21, $18	\n\t"	\
  \
  "lui	$8, 0xF1EC		\n\t"	\
  "lui	$9, 0x3333		\n\t"	\
  "lui	$23, 0			\n\t"	\
  "mthi	$22				\n\t"	\
  "mtlo	$23				\n\t"	\
  "madd	$15, $9			\n\t"	\
  "mtlo	$23				\n\t"	\
  "madd	$14, $8			\n\t"	\
  "lui	$8, 0x1EB8		\n\t"	\
  "lui	$9, 0x6F5C		\n\t"	\
  "mfhi	$22				\n\t"	\
  "mtlo	$23				\n\t"	\
  "madd	$14, $8			\n\t"	\
  "mtlo	$23				\n\t"	\
  "mfhi	$21				\n\t"	\
  "subu	$15, $22, $15	\n\t"	\
  \
  "mult	$21, $9			\n\t"	\
  "mfhi	$8				\n\t"	\
  "li	$17, 0x7FFF		\n\t"   \
  "li	$18, 0x8000		\n\t"   \
  "addu	$8, $8, 256		\n\t"	\
  "sra	$8, $8, 9		\n\t"	\
  "slti	$19, $8, 0x7FFF	\n\t"	\
  "slti	$20, $8, 0x8000	\n\t"	\
  "movz	$8, $17, $19	\n\t"   \
  "movn	$8, $18, $20	\n\t"   \
  "sh	$8, 0(%1)		\n\t"	\
  \
  "lui	$8, 0x3FA7		\n\t"	\
  "lui	$9, 0xD2FF		\n\t"	\
  "subu	$17, $16, $12	\n\t"	\
  "mult	$17, $8			\n\t"	\
  "mfhi	$18				\n\t"	\
  "addu	$21, $18, $12	\n\t"	\
  "addu	$12, $18, $16	\n\t"	\
  \
  "subu	$17, $21, $13	\n\t"	\
  "mult	$17, $9			\n\t"	\
  "mfhi	$18				\n\t"	\
  "addu	$18, $18, $17	\n\t"	\
  "addu	$22, $18, $13	\n\t"	\
  "addu	$13, $21, $18	\n\t"	\
  \
  "lui	$8, 0xF1EC		\n\t"	\
  "lui	$9, 0x3333		\n\t"	\
  "lui	$23, 0			\n\t"	\
  "mthi	$22				\n\t"	\
  "mtlo	$23				\n\t"	\
  "madd	$14, $9			\n\t"	\
  "mtlo	$23				\n\t"	\
  "madd	$15, $8			\n\t"	\
  "lui	$8, 0x1EB8		\n\t"	\
  "lui	$9, 0x6F5C		\n\t"	\
  "mfhi	$22				\n\t"	\
  "mtlo	$23				\n\t"	\
  "madd	$15, $8			\n\t"	\
  "mtlo	$23				\n\t"	\
  "mfhi	$21				\n\t"	\
  "subu	$14, $22, $14	\n\t"	\
  \
  "mult	$21, $9			\n\t"	\
  "mfhi	$8				\n\t"	\
  "li	$17, 0x7FFF		\n\t"   \
  "li	$18, 0x8000		\n\t"   \
  "addu	$8, $8, 256		\n\t"	\
  "sra	$8, $8, 9		\n\t"	\
  "slti	$19, $8, 0x7FFF	\n\t"	\
  "slti	$20, $8, 0x8000	\n\t"	\
  "movz	$8, $17, $19	\n\t"   \
  "movn	$8, $18, $20	\n\t"   \
  "sh	$8, 2(%1)		\n\t"	\
  "add	%3, %3, -1		\n\t"	\
  "add	%1, %1, 4		\n\t"	\
  "add	%2, %2, 2		\n\t"	\
  "bgtz %3, 0b			\n\t"	\
  "nop					\n\t"	\
  "sw	$10, 0(%0)		\n\t"	\
  "sw	$11, 4(%0)		\n\t"	\
  "sw	$12, 8(%0)		\n\t"	\
  "sw	$13, 12(%0)		\n\t"	\
  "sw	$14, 16(%0)		\n\t"	\
  "sw	$15, 20(%0)		\n\t"	\
  "1:					\n\t"	\
  ".set pop				\n\t"	\
  : "+r" (S), "+r" (out), "+r" (in), "+r" (len) \
  : : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$16", "$17", "$18", "$19", "$20", "$21", "$22", "$23")

/* Upsample by a factor 2, high quality */
/* Uses 2nd order allpass filters for the 2x upsampling, followed by a      */
/* notch filter just above Nyquist.                                         */
void SKP_Silk_resampler_private_up2_HQ(
	SKP_int32	                    *S,			    /* I/O: Resampler state [ 6 ]					*/
    SKP_int16                       *out,           /* O:   Output signal [ 2 * len ]               */
    const SKP_int16                 *in,            /* I:   Input signal [ len ]                    */
    SKP_int32                       len             /* I:   Number of INPUT samples                 */
)
{
	RESAMPLER_PRIVATE_UP2_HQ(S, out, in, len);
}
#endif

