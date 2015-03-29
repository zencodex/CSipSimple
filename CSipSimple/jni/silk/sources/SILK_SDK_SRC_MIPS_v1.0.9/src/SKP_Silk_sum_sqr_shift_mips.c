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
 * SKP_Silk_sum_sqr_shift_mips.c                                      *
 *                                                                      *
 * compute number of bits to right shift the sum of squares of a vector *
 * of int16s to make it fit in an int32                                 *
 *                                                                      *
 * Copyright 2010 (c), Skype Limited                                    *
 *                                                                      */

#include "SKP_Silk_SigProc_FIX.h"

#if defined(EMBEDDED_MIPS)

/* Compute number of bits to right shift the sum of squares of a vector */
/* of int16s to make it fit in an int32                                 */


#if ! defined(BITEXACT)


/*
   Sum of squares of vector elements. On 4Kc, it runs about 4x faster than
   the generic implementation as tested with a 200-element and a 7-element
   input vectors.

   In general, the code should run stall-free on both 4K and 24K. The few
   remaining nop-s could be optimized out by putting lh-s there. However,
   when doing this, keep in mind of not accessing elements that are not
   present in the input vector. Gaining a few clocks in the non-looped
   codepath is not worth risking a segfault.

   On 24K, there will probably be a stall after the last mflo as the
   result of higher-order bits is immediately needed to decide for further
   operations. Reimplementing in assembly wouldn't help there.
*/
#define SUM_SQR_SHIFT_BUDY(x, len, nrg, shft)		\
__asm__ volatile(						\
  ".set push		\n\t"				\
  ".set noreorder	\n\t"				\
\
  /* main loop, unrolled for 16 elements */		\
  "pref	0, 32(%0)	\n\t"				\
  "addiu %1, %1, 16	\n\t"	/* len+=16, loop prep. */\
  "mult	$0, $0		\n\t"	/* Zero hi/lo */	\
  "j	2f		\n\t"				\
  "1:			\n\t"				\
  "pref	0, 64(%0)	\n\t"				\
  "lh	$10, 0(%0)	\n\t"				\
  "lh	$11, 2(%0)	\n\t"				\
  "madd	$10, $10	\n\t"				\
  "lh	$12, 4(%0)	\n\t"				\
  "madd	$11, $11	\n\t"				\
  "lh	$13, 6(%0)	\n\t"				\
  "madd $12, $12	\n\t"				\
  "lh	$10, 8(%0)	\n\t"				\
  "madd	$13, $13	\n\t"				\
  "lh	$11, 10(%0)	\n\t"				\
  "madd	$10, $10	\n\t"				\
  "lh	$12, 12(%0)	\n\t"				\
  "madd	$11, $11	\n\t"				\
  "lh	$13, 14(%0)	\n\t"				\
  "madd	$12, $12	\n\t"				\
  "lh	$10, 16(%0)	\n\t"				\
  "madd	$13, $13	\n\t"				\
  "lh	$11, 18(%0)	\n\t"				\
  "madd	$10, $10	\n\t"				\
  "lh	$12, 20(%0)	\n\t"				\
  "madd	$11, $11	\n\t"				\
  "lh	$13, 22(%0)	\n\t"				\
  "madd	$12, $12	\n\t"				\
  "lh	$10, 24(%0)	\n\t"				\
  "madd	$13, $13	\n\t"				\
  "lh	$11, 26(%0)	\n\t"				\
  "madd	$10, $10	\n\t"				\
  "lh	$12, 28(%0)	\n\t"				\
  "madd	$11, $11	\n\t"				\
  "lh	$13, 30(%0)	\n\t"				\
  "madd	$12, $12	\n\t"				\
  "addiu %0, %0, 32	\n\t"				\
  "madd $13, $13	\n\t"				\
  "2:			\n\t"				\
  "slti	$15, %1, 32	\n\t"				\
  "beqz	$15, 1b		\n\t"				\
  "addiu %1, %1, -16	\n\t"				\
\
  /* 8-element leftover */				\
  "slti	$15, %1, 8	\n\t"				\
  "bnez	$15, 3f		\n\t"				\
  "nop			\n\t"	/* -1 clk */		\
  "lh	$10, 0(%0)	\n\t"				\
  "lh	$11, 2(%0)	\n\t"				\
  "madd	$10, $10	\n\t"				\
  "lh	$12, 4(%0)	\n\t"				\
  "madd	$11, $11	\n\t"				\
  "lh	$13, 6(%0)	\n\t"				\
  "madd	$12, $12	\n\t"				\
  "lh	$10, 8(%0)	\n\t"				\
  "madd	$13, $13	\n\t"				\
  "lh	$11, 10(%0)	\n\t"				\
  "madd	$10, $10	\n\t"				\
  "lh	$12, 12(%0)	\n\t"				\
  "madd	$11, $11	\n\t"				\
  "lh	$13, 14(%0)	\n\t"				\
  "madd	$12, $12	\n\t"				\
  "addiu %0, %0, 16	\n\t"				\
  "addiu %1, %1, -8	\n\t"				\
  "madd	$13, $13	\n\t"				\
\
  /* 4-element leftover */				\
  "3:			\n\t"				\
  "slti	$15, %1, 4	\n\t"				\
  "bnez	$15, 4f		\n\t"				\
  "nop			\n\t"	/* -1 clk */		\
  "lh	$10, 0(%0)	\n\t"				\
  "lh	$11, 2(%0)	\n\t"				\
  "madd	$10, $10	\n\t"				\
  "lh	$12, 4(%0)	\n\t"				\
  "madd	$11, $11	\n\t"				\
  "lh	$13, 6(%0)	\n\t"				\
  "madd	$12, $12	\n\t"				\
  "addiu %0, %0, 8	\n\t"				\
  "addiu %1, %1, -4	\n\t"				\
  "madd	$13, $13	\n\t"				\
\
  /* 2-element leftover */				\
  "4:			\n\t"				\
  "slti	$15, %1, 2	\n\t"				\
  "bnez	$15, 5f		\n\t"				\
  "nop			\n\t"	/* -1 clk */		\
  "lh	$10, 0(%0)	\n\t"				\
  "lh	$11, 2(%0)	\n\t"				\
  "madd	$10, $10	\n\t"				\
  "addiu %0, %0, 4	\n\t"				\
  "addiu %1, %1, -2	\n\t"				\
  "madd	$11, $11	\n\t"				\
\
  /* 1-element leftover */				\
  "5:			\n\t"				\
  "beqz	%1, 6f		\n\t"				\
  "nop			\n\t"	/* -1 clk */		\
  "lh	$10, 0(%0)	\n\t"				\
  "madd	$10, $10	\n\t"	/* -1 clk */		\
\
  /* Return */						\
  "6:			\n\t"				\
  "mfhi	%3		\n\t"				\
  "mflo	%2		\n\t"				\
  /* up to -3 clks on 24K because of accessing target */\
\
  ".set push		\n\t"				\
  : "+r" (x), "+r" (len), "=r" (nrg), "=r" (shft)	\
  : : "$10", "$11", "$12", "$13", "$15")



void SKP_Silk_sum_sqr_shift(SKP_int32 * energy, SKP_int * shift,
				const SKP_int16 * x, SKP_int len)
{
	unsigned shft;
	unsigned nrg;

	SUM_SQR_SHIFT_BUDY(x, len, nrg, shft);

	/* At this point, nrg contains bits 0..31 and shft contains 
	   bits 32..63 of the energy. Rework the energy into a 30-bit 
	   integer and reckon the corresponding even shift */
	if(shft) {
		int shift = (35 - SKP_Silk_CLZ32(shft)) & ~1;
		nrg = (nrg >> shift) | (shft << (32 - shift));
		shft = shift;
	} else if(nrg > 0x3fffffff) {
		nrg >>= 2;
		shft = 2;
	}
	*shift  = shft;
	*energy = (SKP_int32) nrg;
}


#else /* defined(BITEXACT) */


void SKP_Silk_sum_sqr_shift(
    SKP_int32            *energy,            /* O    Energy of x, after shifting to the right            */
    SKP_int              *shift,             /* O    Number of bits right shift applied to energy        */
    const SKP_int16      *x,                 /* I    Input vector                                        */
    SKP_int              len                 /* I    Length of input vector                              */
)
{
    SKP_int   i, shft;
    SKP_int32 in32, nrg_tmp, nrg;

    if( (SKP_int32)( (SKP_int_ptr_size)x & 2 ) != 0 ) {
        /* Input is not 4-byte aligned */
        nrg = SKP_SMULBB( x[ 0 ], x[ 0 ] );
        i = 1;
    } else {
        nrg = 0;
        i   = 0;
    }
    shft = 0;
    len--;
    while( i < len ) {
        /* Load two values at once */
        in32 = *( (SKP_int32 *)&x[ i ] );
        nrg = SKP_SMLABB_ovflw( nrg, in32, in32 );
        nrg = SKP_SMLATT_ovflw( nrg, in32, in32 );
        i += 2;
        if( nrg < 0 ) {
            /* Scale down */
            nrg = (SKP_int32)SKP_RSHIFT_uint( (SKP_uint32)nrg, 2 );
            shft = 2;
            break;
        }
    }
    for( ; i < len; i += 2 ) {
        /* Load two values at once */
        in32 = *( (SKP_int32 *)&x[ i ] );
        nrg_tmp = SKP_SMULBB( in32, in32 );
        nrg_tmp = SKP_SMLATT_ovflw( nrg_tmp, in32, in32 );
        nrg = (SKP_int32)SKP_ADD_RSHIFT_uint( nrg, (SKP_uint32)nrg_tmp, shft );
        if( nrg < 0 ) {
            /* Scale down */
            nrg = (SKP_int32)SKP_RSHIFT_uint( (SKP_uint32)nrg, 2 );
            shft += 2;
        }
    }
    if( i == len ) {
        /* One sample left to process */
        nrg_tmp = SKP_SMULBB( x[ i ], x[ i ] );
        nrg = (SKP_int32)SKP_ADD_RSHIFT_uint( nrg, nrg_tmp, shft );
    }

    /* Make sure to have at least one extra leading zero (two leading zeros in total) */
    if( nrg & 0xC0000000 ) {
        nrg = SKP_RSHIFT_uint( (SKP_uint32)nrg, 2 );
        shft += 2;
    }

    /* Output arguments */
    *shift  = shft;
    *energy = nrg;
}


#endif /* defined(BITEXACT) */
#endif /* defined(EMBEDDED_MIPS) */
