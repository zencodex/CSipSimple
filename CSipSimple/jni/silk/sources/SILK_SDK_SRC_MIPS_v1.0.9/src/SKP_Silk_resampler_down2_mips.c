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
 * SKP_Silk_resampler_down2_mips.c                                         *
 *                                                                      *
 * Downsample by a factor 2, mediocre quality                           *
 *                                                                      *
 * Copyright 2010 (c), Skype Limited                                    *
 *                                                                      */

#include "SKP_Silk_SigProc_FIX.h"
#include "SKP_Silk_resampler_rom.h"


#if defined(EMBEDDED_MIPS)

#define RESAMPLER_DOWN2(S, out, in, len)	\
__asm__ volatile (	\
  ".set push			\n\t"	\
  ".set noreorder		\n\t"	\
  "blez	%3, 1f			\n\t"	\
  "lw	$8, 0(%0)		\n\t"	\
  "lw	$9, 4(%0)		\n\t"	\
  "lui	$10, 0x2690		\n\t"	\
  "lui	$11, 0x9B81		\n\t"	\
  "0:					\n\t"	\
  "lh	$12, 0(%2)		\n\t"	\
  "lh	$13, 2(%2)		\n\t"	\
  "add	%3, %3, -2		\n\t"	\
  "add	%2, %2, 4		\n\t"	\
  "sll	$12, $12, 10	\n\t"	\
  "sll	$13, $13, 10	\n\t"	\
  "subu	$14, $12, $8	\n\t"	\
  "subu	$15, $13, $9	\n\t"	\
  "mult	$14, $11		\n\t"	\
  "mfhi	$16				\n\t"	\
  "mult	$15, $10		\n\t"	\
  "mfhi	$17				\n\t"	\
  "addu	$16, $16, $14 	\n\t"	\
  "addu	$14, $16, $8 	\n\t"	\
  "addu	$15, $17, $9 	\n\t"	\
  "addu	$8, $16, $12	\n\t"	\
  "addu	$9, $17, $13	\n\t"	\
  "addu	$14, $14, $15	\n\t"	\
  "addu $14, $14, 1024	\n\t"	\
  "li	$16, 0x7FFF 	\n\t"	\
  "li	$17, 0x8000		\n\t"	\
  "sra	$14, $14, 11	\n\t"	\
  "slti	$12, $14, 0x7FFF	\n\t"	\
  "slti	$13, $14, 0x8000	\n\t"	\
  "movz	$14, $16, $12	\n\t"   \
  "movn	$14, $17, $13	\n\t"   \
  "add	%1, %1, 2 	\n\t"	\
  "bgtz	%3, 0b			\n\t"   \
  "sh	$14, -2(%1)	\n\t"	\
  "sw	$8, 0(%0)		\n\t"	\
  "sw	$9, 4(%0)		\n\t"	\
  "1:					\n\t"	\
  ".set pop				\n\t"	\
  : "+r" (S), "+r" (out), "+r" (in), "+r" (len) \
  : : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$16", "$17")

/* Downsample by a factor 2, mediocre quality */
void SKP_Silk_resampler_down2(
    SKP_int32                           *S,         /* I/O: State vector [ 2 ]                  */
    SKP_int16                           *out,       /* O:   Output signal [ len ]               */
    const SKP_int16                     *in,        /* I:   Input signal [ floor(len/2) ]       */
    SKP_int32                           inLen       /* I:   Number of input samples             */
)
{
	RESAMPLER_DOWN2(S, out, in, inLen);
}
#endif
