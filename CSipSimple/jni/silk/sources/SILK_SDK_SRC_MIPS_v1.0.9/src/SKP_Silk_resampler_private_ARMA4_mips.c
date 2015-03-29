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

/*												*
 * SKP_Silk_resampler_private_ARMA4.c			*
 *												*
 *												*
 * Copyright 2010 (c), Skype Limited			*
 *												*/

#include "SKP_Silk_SigProc_FIX.h"
#include "SKP_Silk_resampler_private.h"

#if defined(EMBEDDED_MIPS)

#define RESAMPLER_PRIVATE_ARMA4(S, out, in, coef, len)	\
__asm__ volatile (	\
  ".set push			\n\t"	\
  ".set noreorder		\n\t"	\
  "lw	$14, 0(%0)		\n\t"	\
  "lw	$15, 4(%0)		\n\t"	\
  "lw	$16, 8(%0)		\n\t"	\
  "blez	%4, 1f			\n\t"	\
  "lw	$17, 12(%0)		\n\t"	\
\
  "0:					\n\t"	\
  "lh	$8, 0(%2)		\n\t"	\
  "lh	$9, 0(%3)		\n\t"	\
  "lh	$10, 4(%3)		\n\t"	\
  "li	$13, 0			\n\t"	\
  "sll	$8, $8, 8		\n\t"	\
  "sll	$14, $14, 2		\n\t"	\
  "sll	$16, $16, 2		\n\t"	\
  "sll	$9, $9, 16		\n\t"	\
  "sll	$10, $10, 16	\n\t"	\
  "mthi	$15				\n\t"	\
  "mtlo	$13				\n\t"	\
  "addu	$11, $8, $14	\n\t"	\
  "madd	$8, $9			\n\t"	\
  "mtlo	$13				\n\t"	\
  "addu	$12, $11, $16	\n\t"	\
  "madd	$11, $10		\n\t"	\
\
  "lh	$9, 2(%3)		\n\t"	\
  "lh	$10, 8(%3)		\n\t"	\
  "sll	$9, $9, 16		\n\t"	\
  "mfhi	$14				\n\t"	\
  "mtlo	$13				\n\t"	\
  "mthi $17				\n\t"	\
  "madd	$11, $9			\n\t"	\
  "sll	$10, $10, 16	\n\t"	\
  "mtlo	$13				\n\t"	\
  "lh	$9, 6(%3)		\n\t"	\
  "madd	$12, $10		\n\t"	\
  "mfhi	$16				\n\t"	\
\
  "lh	$10, 10(%3)		\n\t"	\
  "sra	$8, $8, 2		\n\t"	\
  "sll	$9, $9, 16		\n\t"	\
  "mtlo $13				\n\t"	\
  "mthi	$8				\n\t"	\
  "sll	$10, $10, 16	\n\t"	\
  "madd	$11, $9			\n\t"	\
  "sra	$11, $11, 2		\n\t"	\
  "mtlo $13				\n\t"	\
  "mfhi	$15				\n\t"	\
  "lh	$9, 12(%3)		\n\t"	\
  "mthi $11				\n\t"	\
  "madd	$12, $10		\n\t"	\
\
  "sll	$9, $9, 16		\n\t"	\
  "mfhi	$17				\n\t"	\
  "mult	$12, $9			\n\t"	\
  "mfhi	$10				\n\t"	\
  "li	$11, 0x7FFF		\n\t"   \
  "li	$12, 0x8000		\n\t"   \
  "addiu	$10, $10, 128	\n\t"	\
  "addi	%2, %2, 2		\n\t"   \
  "sra	$10, $10, 8		\n\t"	\
  "addi	%4, %4, -1		\n\t"   \
  "slti	$8, $10, 0x7FFF	\n\t"	\
  "slti	$9, $10, 0x8000	\n\t"	\
  "movz	$10, $11, $8	\n\t"   \
  "movn	$10, $12, $9	\n\t"   \
  "sh	$10, 0(%1)		\n\t"   \
  "bgtz	%4, 0b			\n\t"   \
  "addi	%1, %1, 2		\n\t"   \
\
  "1:					\n\t"   \
  "sw	$14, 0(%0)		\n\t"	\
  "sw	$15, 4(%0)		\n\t"	\
  "sw	$16, 8(%0)		\n\t"	\
  "sw	$17, 12(%0)		\n\t"	\
  ".set pop				\n\t"	\
  : "+r" (S), "+r" (out), "+r" (in), "+r" (coef), "+r" (len) \
  : : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$16", "$17")
/* Fourth order ARMA filter                                             */
/* Internally operates as two biquad filters in sequence.               */

/* Coeffients are stored in a packed format:                                                        */
/*    { B1_Q14[1], B2_Q14[1], -A1_Q14[1], -A1_Q14[2], -A2_Q14[1], -A2_Q14[2], gain_Q16 }            */
/* where it is assumed that B*_Q14[0], B*_Q14[2], A*_Q14[0] are all 16384                           */
void SKP_Silk_resampler_private_ARMA4(
	SKP_int32					    S[],		    /* I/O: State vector [ 4 ]			    	    */
	SKP_int16					    out[],		    /* O:	Output signal				    	    */
	const SKP_int16				    in[],			/* I:	Input signal				    	    */
	const SKP_int16				    Coef[],		    /* I:	ARMA coefficients [ 7 ]                 */
	SKP_int32				        len				/* I:	Signal length				        	*/
)
{
	RESAMPLER_PRIVATE_ARMA4(S, out, in, Coef, len);
}





















#endif

