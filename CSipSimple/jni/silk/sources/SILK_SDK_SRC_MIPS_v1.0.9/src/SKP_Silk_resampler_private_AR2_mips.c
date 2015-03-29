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

/*																		*
 * SKP_Silk_resampler_private_AR2_mips. c                                  *
 *																		*
 * Second order AR filter with single delay elements                	*
 *                                                                      *
 * Copyright 2010 (c), Skype Limited                                    *
 *                                                                      */

#include "SKP_Silk_SigProc_FIX.h"
#include "SKP_Silk_resampler_private.h"

#if defined(EMBEDDED_MIPS)

#define RESAMPLER_PRIVATE_AR2(S, out, in, A, len)	\
__asm__ volatile (	\
  ".set push			\n\t"	\
  ".set noreorder		\n\t"	\
  "blez	%4, 1f			\n\t"	\
  "lh	$10, 0(%3)		\n\t"	\
  "lh	$11, 2(%3)		\n\t"	\
  "lh	$12, 0(%2)		\n\t"	\
  "lw	$8, 0(%0)		\n\t"	\
  "lw	$9, 4(%0)		\n\t"	\
  "sll	$10, $10, 16	\n\t"	\
  "sll	$11, $11, 16	\n\t"	\
  "0:					\n\t"	\
  "sll	$12, $12, 8		\n\t"	\
  "add	%2, %2, 2 		\n\t"	\
  "add	$13, $12, $8	\n\t"	\
  "sll	$14, $13, 2		\n\t"	\
  "sw	$13, 0(%1)		\n\t"	\
  "mult	$14, $10		\n\t"	\
  "lh	$12, 0(%2)		\n\t"	\
  "mfhi	$8				\n\t"	\
  "add	%1, %1, 4		\n\t"	\
  "mult	$14, $11		\n\t"	\
  "addu	$8, $8, $9		\n\t"	\
  "add	%4, %4, -1		\n\t"	\
  "bgtz %4, 0b			\n\t"	\
  "mfhi	$9				\n\t"	\
  "sw	$8, 0(%0)		\n\t"	\
  "sw	$9, 4(%0)		\n\t"	\
  "1:					\n\t"	\
  ".set pop				\n\t"	\
  : "+r" (S), "+r" (out), "+r" (in), "+r" (A), "+r" (len) \
  : : "$8", "$9", "$10", "$11", "$12", "$13", "$14")



/* Second order AR filter with single delay elements */
void SKP_Silk_resampler_private_AR2(
	SKP_int32					    S[],		    /* I/O: State vector [ 2 ]			    	    */
	SKP_int32					    out_Q8[],		/* O:	Output signal				    	    */
	const SKP_int16				    in[],			/* I:	Input signal				    	    */
	const SKP_int16				    A_Q14[],		/* I:	AR coefficients, Q14 	                */
	SKP_int32				        len				/* I:	Signal length				        	*/
)
{
	RESAMPLER_PRIVATE_AR2(S, out_Q8, in, A_Q14, len);
}
#endif
