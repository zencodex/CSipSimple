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

#include "SKP_Silk_main_FIX.h"

#if defined(__mips__)


// LPC_order: 10, 16
// K: 8, 16, 32, 64, 128
// N: 1, 2
/* Compute weighted quantization errors for an LPC_order element input vector, over one codebook stage */
/* This MIPS-optimized version is about 2x faster than the original C version */
/* NB! Currently we assume that LPC_order is either 10 or 16. If it will be
   anything else in the future then the implementation has to be changed
   accordingly */
void SKP_Silk_NLSF_VQ_sum_error_FIX(
    SKP_int32                       *err_Q20,           /* O    Weighted quantization errors  [N*K]         */
    const SKP_int                   *in_Q15,            /* I    Input vectors to be quantized [N*LPC_order] */
    const SKP_int                   *w_Q6,              /* I    Weighting vectors             [N*LPC_order] */
    const SKP_int16                 *pCB_Q15,           /* I    Codebook vectors              [K*LPC_order] */
    const SKP_int                   N,                  /* I    Number of input vectors                     */
    const SKP_int                   K,                  /* I    Number of codebook vectors                  */
    const SKP_int                   LPC_order           /* I    Number of LPCs                              */
)
{
    SKP_int         i, n;
    SKP_int32       sum_error;
    const SKP_int16 *cb_vec_Q15;

    SKP_assert(LPC_order == 10 || LPC_order == 16);

    /* Loop over input vectors */
    for( n = 0; n < N; n++ ) {
        /* Loop over codebook */
        cb_vec_Q15 = pCB_Q15;
        for( i = 0; i < K; i++ ) {

__asm__ volatile (
".set	push		\n\t"
".set	noreorder	\n\t"
/* Prologue for m = 1, 0 */
"lw	$8, 4(%2)	\n\t"
"lh	$10, 2(%1)	\n\t"
"lw	$9, 0(%2)	\n\t"
"lh	$11, 0(%1)	\n\t"
"subu	$12, $8, $10	\n\t"
"lw	$14, 4(%3)	\n\t"
"subu	$13, $9, $11	\n\t"
"lw	$15, 0(%3)	\n\t"
"li	$2, 10		\n\t"
"beq	%4, $2, 1f	\n\t"	/* LPC_order == 10 */
"move	%0, $0		\n\t"
/* m = 15, 14 */
"mul	$12, $12, $12	\n\t"
"lw	$8, 60(%2)	\n\t"
"lh	$10, 30(%1)	\n\t"
"sll	$2, $14, 16	\n\t"
"mul	$13, $13, $13	\n\t"
"lw	$9, 56(%2)	\n\t"
"lh	$11, 28(%1)	\n\t"
"sll	$3, $15, 16	\n\t"
"mult	$12, $2		\n\t"
"subu	$12, $8, $10	\n\t"
"mfhi	$2		\n\t"
"lw	$14, 60(%3)	\n\t"
"mult	$13, $3		\n\t"
"subu	$13, $9, $11	\n\t"
"mfhi	$3		\n\t"
"lw	$15, 56(%3)	\n\t"
"addu	%0, %0, $2	\n\t"
"addu	%0, %0, $3	\n\t"
/* m = 13, 12 */
"mul	$12, $12, $12	\n\t"
"lw	$8, 52(%2)	\n\t"
"lh	$10, 26(%1)	\n\t"
"sll	$2, $14, 16	\n\t"
"mul	$13, $13, $13	\n\t"
"lw	$9, 48(%2)	\n\t"
"lh	$11, 24(%1)	\n\t"
"sll	$3, $15, 16	\n\t"
"mult	$12, $2		\n\t"
"subu	$12, $8, $10	\n\t"
"mfhi	$2		\n\t"
"lw	$14, 52(%3)	\n\t"
"mult	$13, $3		\n\t"
"subu	$13, $9, $11	\n\t"
"mfhi	$3		\n\t"
"lw	$15, 48(%3)	\n\t"
"addu	%0, %0, $2	\n\t"
"addu	%0, %0, $3	\n\t"
/* m = 11, 10 */
"mul	$12, $12, $12	\n\t"
"lw	$8, 44(%2)	\n\t"
"lh	$10, 22(%1)	\n\t"
"sll	$2, $14, 16	\n\t"
"mul	$13, $13, $13	\n\t"
"lw	$9, 40(%2)	\n\t"
"lh	$11, 20(%1)	\n\t"
"sll	$3, $15, 16	\n\t"
"mult	$12, $2		\n\t"
"subu	$12, $8, $10	\n\t"
"mfhi	$2		\n\t"
"lw	$14, 44(%3)	\n\t"
"mult	$13, $3		\n\t"
"subu	$13, $9, $11	\n\t"
"mfhi	$3		\n\t"
"lw	$15, 40(%3)	\n\t"
"addu	%0, %0, $2	\n\t"
"addu	%0, %0, $3	\n\t"
/* m = 9, 8 */
"1:			\n\t"
"mul	$12, $12, $12	\n\t"
"lw	$8, 36(%2)	\n\t"
"lh	$10, 18(%1)	\n\t"
"sll	$14, $14, 16	\n\t"
"mul	$13, $13, $13	\n\t"
"lw	$9, 32(%2)	\n\t"
"lh	$11, 16(%1)	\n\t"
"sll	$15, $15, 16	\n\t"
"mult	$12, $14	\n\t"
"subu	$12, $8, $10	\n\t"
"mfhi	$2		\n\t"
"lw	$14, 36(%3)	\n\t"
"mult	$13, $15	\n\t"
"subu	$13, $9, $11	\n\t"
"mfhi	$3		\n\t"
"lw	$15, 32(%3)	\n\t"
"addu	%0, %0, $2	\n\t"
"addu	%0, %0, $3	\n\t"
/* m = 7, 6 */
"mul	$12, $12, $12	\n\t"
"lw	$8, 28(%2)	\n\t"
"lh	$10, 14(%1)	\n\t"
"sll	$2, $14, 16	\n\t"
"mul	$13, $13, $13	\n\t"
"lw	$9, 24(%2)	\n\t"
"lh	$11, 12(%1)	\n\t"
"sll	$3, $15, 16	\n\t"
"mult	$12, $2		\n\t"
"subu	$12, $8, $10	\n\t"
"mfhi	$2		\n\t"
"lw	$14, 28(%3)	\n\t"
"mult	$13, $3		\n\t"
"subu	$13, $9, $11	\n\t"
"mfhi	$3		\n\t"
"lw	$15, 24(%3)	\n\t"
"addu	%0, %0, $2	\n\t"
"addu	%0, %0, $3	\n\t"
/* m = 5, 4 */
"mul	$12, $12, $12	\n\t"
"lw	$8, 20(%2)	\n\t"
"lh	$10, 10(%1)	\n\t"
"sll	$2, $14, 16	\n\t"
"mul	$13, $13, $13	\n\t"
"lw	$9, 16(%2)	\n\t"
"lh	$11, 8(%1)	\n\t"
"sll	$3, $15, 16	\n\t"
"mult	$12, $2		\n\t"
"subu	$12, $8, $10	\n\t"
"mfhi	$2		\n\t"
"lw	$14, 20(%3)	\n\t"
"mult	$13, $3		\n\t"
"subu	$13, $9, $11	\n\t"
"mfhi	$3		\n\t"
"lw	$15, 16(%3)	\n\t"
"addu	%0, %0, $2	\n\t"
"addu	%0, %0, $3	\n\t"
/* m = 3, 2 */
"mul	$12, $12, $12	\n\t"
"lw	$8, 12(%2)	\n\t"
"lh	$10, 6(%1)	\n\t"
"sll	$2, $14, 16	\n\t"
"mul	$13, $13, $13	\n\t"
"lw	$9, 8(%2)	\n\t"
"lh	$11, 4(%1)	\n\t"
"sll	$3, $15, 16	\n\t"
"mult	$12, $2		\n\t"
"subu	$12, $8, $10	\n\t"
"mfhi	$2		\n\t"
"lw	$14, 12(%3)	\n\t"
"mult	$13, $3		\n\t"
"subu	$13, $9, $11	\n\t"
"mfhi	$3		\n\t"
"lw	$15, 8(%3)	\n\t"
"addu	%0, %0, $2	\n\t"
"addu	%0, %0, $3	\n\t"
/* m = 1, 0 */
"mul	$12, $12, $12	\n\t"
"sll	$2, $14, 16	\n\t"
"mul	$13, $13, $13	\n\t"
"sll	$3, $15, 16	\n\t"
"mult	$12, $2		\n\t"
"addu	%1, %1, %4	\n\t"
"mfhi	$2		\n\t"
"mult	$13, $3		\n\t"
"addu	%1, %1, %4	\n\t"
"mfhi	$3		\n\t"
"addu	%0, %0, $2	\n\t"
"addu	%0, %0, $3	\n\t"
".set	pop		\n\t"
: "=&r" (sum_error), "+&r" (cb_vec_Q15)
: "r" (in_Q15), "r" (w_Q6), "r" (LPC_order)
: "$2", "$3", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15");

            SKP_assert( sum_error >= 0 );
            err_Q20[ i ] = sum_error;
        }
        err_Q20 += K;
        in_Q15 += LPC_order;
    }
}

#endif

