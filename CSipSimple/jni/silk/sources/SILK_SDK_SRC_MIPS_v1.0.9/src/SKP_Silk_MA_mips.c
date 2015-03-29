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
 * SKP_Silk_MA.c                                                      *
 *                                                                      *
 * Variable order MA filter                                             *
 *                                                                      *
 * Copyright 2010 (c), Skype Limited                                    *
 *                                                                      */
#include "SKP_Silk_SigProc_FIX.h"

#if defined(EMBEDDED_MIPS)

/* -------------- Order-dependent optimizations --------------- */

/* Low complexity silk encoder calls filter with orders 8, 10, and 12.
   As these calls are high in silk encoder profile and they could
   be heavily optimized, they were. */

/* Optimized filter loop for order 8. Runs almost 2x faster than the
   unrolled C implementation below. */
SKP_INLINE void FILTER_LOOP_ORDER_8(SKP_int32 * S, const SKP_int16 * B, SKP_int16 in16)
{
	__asm__ volatile(
".set	push		\n\t"
".set	noreorder	\n\t"
/* 0..3 */
"lh	$12, 0(%1)	\n\t"
"lh	$13, 2(%1)	\n\t"
"lw	$8, 4(%0)	\n\t"
"mul	$12, $12, %2	\n\t"
"lw	$9, 8(%0)	\n\t"
"lh	$14, 4(%1)	\n\t"
"mul	$13, $13, %2	\n\t"
"lw	$10, 12(%0)	\n\t"
"lh	$15, 6(%1)	\n\t"
"addu	$8, $8, $12	\n\t"
"mul	$14, $14, %2	\n\t"
"lw	$11, 16(%0)	\n\t"
"addu	$9, $9, $13	\n\t"
"mul	$15, $15, %2	\n\t"
"sw	$8, 0(%0)	\n\t"
"sw	$9, 4(%0)	\n\t"
"addu	$10, $10, $14	\n\t"
"addu	$11, $11, $15	\n\t"
"sw	$10, 8(%0)	\n\t"
"sw	$11, 12(%0)	\n\t"
/* 4..7 */
"lh	$12, 8(%1)	\n\t"
"lh	$13, 10(%1)	\n\t"
"lw	$8, 20(%0)	\n\t"
"mul	$12, $12, %2	\n\t"
"lw	$9, 24(%0)	\n\t"
"lh	$14, 12(%1)	\n\t"
"mul	$13, $13, %2	\n\t"
"lw	$10, 28(%0)	\n\t"
"lh	$15, 14(%1)	\n\t"
"addu	$8, $8, $12	\n\t"
"mul	$14, $14, %2	\n\t"
"sw	$8, 16(%0)	\n\t"
"addu	$9, $9, $13	\n\t"
"mul	$11, $15, %2	\n\t"
"sw	$9, 20(%0)	\n\t"
"addu	$10, $10, $14	\n\t"
"sw	$10, 24(%0)	\n\t"
"sw	$11, 28(%0)	\n\t"
".set	pop		\n\t"
: : "r" (S), "r" (B), "r" (in16)
: "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}

/* Optimized filter loop for order 10. Runs about 1.6x faster than the
   unrolled C implementation below. */
SKP_INLINE void FILTER_LOOP_ORDER_10(SKP_int32 * S, const SKP_int16 * B, SKP_int16 in16)
{
	__asm__ volatile(
".set	push		\n\t"
".set	noreorder	\n\t"
/* 0..3 */
"lh	$12, 0(%1)	\n\t"
"lh	$13, 2(%1)	\n\t"
"lw	$8, 4(%0)	\n\t"
"mul	$12, $12, %2	\n\t"
"lw	$9, 8(%0)	\n\t"
"lh	$14, 4(%1)	\n\t"
"mul	$13, $13, %2	\n\t"
"lw	$10, 12(%0)	\n\t"
"lh	$15, 6(%1)	\n\t"
"addu	$8, $8, $12	\n\t"
"mul	$14, $14, %2	\n\t"
"lw	$11, 16(%0)	\n\t"
"addu	$9, $9, $13	\n\t"
"mul	$15, $15, %2	\n\t"
"sw	$8, 0(%0)	\n\t"
"sw	$9, 4(%0)	\n\t"
"addu	$10, $10, $14	\n\t"
"addu	$11, $11, $15	\n\t"
"sw	$10, 8(%0)	\n\t"
"sw	$11, 12(%0)	\n\t"
/* 4..7 */
"lh	$12, 8(%1)	\n\t"
"lh	$13, 10(%1)	\n\t"
"lw	$8, 20(%0)	\n\t"
"mul	$12, $12, %2	\n\t"
"lw	$9, 24(%0)	\n\t"
"lh	$14, 12(%1)	\n\t"
"mul	$13, $13, %2	\n\t"
"lw	$10, 28(%0)	\n\t"
"lh	$15, 14(%1)	\n\t"
"addu	$8, $8, $12	\n\t"
"mul	$14, $14, %2	\n\t"
"lw	$11, 32(%0)	\n\t"
"addu	$9, $9, $13	\n\t"
"mul	$15, $15, %2	\n\t"
"sw	$8, 16(%0)	\n\t"
/* 8..9 */
"lh	$12, 16(%1)	\n\t"
"sw	$9, 20(%0)	\n\t"
"lh	$13, 18(%1)	\n\t"
"mul	$12, $12, %2	\n\t"
"lw	$8, 36(%0)	\n\t"
"addu	$10, $10, $14	\n\t"
"addu	$11, $11, $15	\n\t"
"mul	$9, $13, %2	\n\t"
"sw	$10, 24(%0)	\n\t"
"addu	$8, $8, $12	\n\t"
"sw	$11, 28(%0)	\n\t"
"sw	$8, 32(%0)	\n\t"
"sw	$9, 36(%0)	\n\t"
".set	pop		\n\t"
: : "r" (S), "r" (B), "r" (in16)
: "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}

/* Optimized filter loop for order 12. Runs almost 2x faster than the
   unrolled C implementation below. */
SKP_INLINE void FILTER_LOOP_ORDER_12(SKP_int32 * S, const SKP_int16 * B, SKP_int16 in16)
{
	__asm__ volatile(
".set	push		\n\t"
".set	noreorder	\n\t"
/* 0..3 */
"lh	$12, 0(%1)	\n\t"
"lh	$13, 2(%1)	\n\t"
"lw	$8, 4(%0)	\n\t"
"mul	$12, $12, %2	\n\t"
"lw	$9, 8(%0)	\n\t"
"lh	$14, 4(%1)	\n\t"
"mul	$13, $13, %2	\n\t"
"lw	$10, 12(%0)	\n\t"
"lh	$15, 6(%1)	\n\t"
"addu	$8, $8, $12	\n\t"
"mul	$14, $14, %2	\n\t"
"lw	$11, 16(%0)	\n\t"
"addu	$9, $9, $13	\n\t"
"mul	$15, $15, %2	\n\t"
"sw	$8, 0(%0)	\n\t"
"sw	$9, 4(%0)	\n\t"
"addu	$10, $10, $14	\n\t"
"addu	$11, $11, $15	\n\t"
"sw	$10, 8(%0)	\n\t"
"sw	$11, 12(%0)	\n\t"
/* 4..7 */
"lh	$12, 8(%1)	\n\t"
"lh	$13, 10(%1)	\n\t"
"lw	$8, 20(%0)	\n\t"
"mul	$12, $12, %2	\n\t"
"lw	$9, 24(%0)	\n\t"
"lh	$14, 12(%1)	\n\t"
"mul	$13, $13, %2	\n\t"
"lw	$10, 28(%0)	\n\t"
"lh	$15, 14(%1)	\n\t"
"addu	$8, $8, $12	\n\t"
"mul	$14, $14, %2	\n\t"
"lw	$11, 32(%0)	\n\t"
"addu	$9, $9, $13	\n\t"
"mul	$15, $15, %2	\n\t"
"sw	$8, 16(%0)	\n\t"
"sw	$9, 20(%0)	\n\t"
"addu	$10, $10, $14	\n\t"
"addu	$11, $11, $15	\n\t"
"sw	$10, 24(%0)	\n\t"
"sw	$11, 28(%0)	\n\t"
/* 8..11 */
"lh	$12, 16(%1)	\n\t"
"lh	$13, 18(%1)	\n\t"
"lw	$8, 36(%0)	\n\t"
"mul	$12, $12, %2	\n\t"
"lw	$9, 40(%0)	\n\t"
"lh	$14, 20(%1)	\n\t"
"mul	$13, $13, %2	\n\t"
"lw	$10, 44(%0)	\n\t"
"lh	$15, 22(%1)	\n\t"
"addu	$8, $8, $12	\n\t"
"mul	$14, $14, %2	\n\t"
"sw	$8, 32(%0)	\n\t"
"addu	$9, $9, $13	\n\t"
"mul	$11, $15, %2	\n\t"
"sw	$9, 36(%0)	\n\t"
"addu	$10, $10, $14	\n\t"
"sw	$10, 40(%0)	\n\t"
"sw	$11, 44(%0)	\n\t"
".set	pop		\n\t"
: : "r" (S), "r" (B), "r" (in16)
: "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}

/* Optimized filter loop for order 16. Runs almost 2x faster than the
   unrolled C implementation below. */
SKP_INLINE void FILTER_LOOP_ORDER_16(SKP_int32 * S, const SKP_int16 * B, SKP_int16 in16)
{
	__asm__ volatile(
".set	push		\n\t"
".set	noreorder	\n\t"
/* 0..3 */
"lh	$12, 0(%1)	\n\t"
"lh	$13, 2(%1)	\n\t"
"lw	$8, 4(%0)	\n\t"
"mul	$12, $12, %2	\n\t"
"lw	$9, 8(%0)	\n\t"
"lh	$14, 4(%1)	\n\t"
"mul	$13, $13, %2	\n\t"
"lw	$10, 12(%0)	\n\t"
"lh	$15, 6(%1)	\n\t"
"addu	$8, $8, $12	\n\t"
"mul	$14, $14, %2	\n\t"
"lw	$11, 16(%0)	\n\t"
"addu	$9, $9, $13	\n\t"
"mul	$15, $15, %2	\n\t"
"sw	$8, 0(%0)	\n\t"
"sw	$9, 4(%0)	\n\t"
"addu	$10, $10, $14	\n\t"
"addu	$11, $11, $15	\n\t"
"sw	$10, 8(%0)	\n\t"
"sw	$11, 12(%0)	\n\t"
/* 4..7 */
"lh	$12, 8(%1)	\n\t"
"lh	$13, 10(%1)	\n\t"
"lw	$8, 20(%0)	\n\t"
"mul	$12, $12, %2	\n\t"
"lw	$9, 24(%0)	\n\t"
"lh	$14, 12(%1)	\n\t"
"mul	$13, $13, %2	\n\t"
"lw	$10, 28(%0)	\n\t"
"lh	$15, 14(%1)	\n\t"
"addu	$8, $8, $12	\n\t"
"mul	$14, $14, %2	\n\t"
"lw	$11, 32(%0)	\n\t"
"addu	$9, $9, $13	\n\t"
"mul	$15, $15, %2	\n\t"
"sw	$8, 16(%0)	\n\t"
"sw	$9, 20(%0)	\n\t"
"addu	$10, $10, $14	\n\t"
"addu	$11, $11, $15	\n\t"
"sw	$10, 24(%0)	\n\t"
"sw	$11, 28(%0)	\n\t"
/* 8..11 */
"lh	$12, 16(%1)	\n\t"
"lh	$13, 18(%1)	\n\t"
"lw	$8, 36(%0)	\n\t"
"mul	$12, $12, %2	\n\t"
"lw	$9, 40(%0)	\n\t"
"lh	$14, 20(%1)	\n\t"
"mul	$13, $13, %2	\n\t"
"lw	$10, 44(%0)	\n\t"
"lh	$15, 22(%1)	\n\t"
"addu	$8, $8, $12	\n\t"
"mul	$14, $14, %2	\n\t"
"lw	$11, 48(%0)	\n\t"
"addu	$9, $9, $13	\n\t"
"mul	$15, $15, %2	\n\t"
"sw	$8, 32(%0)	\n\t"
"sw	$9, 36(%0)	\n\t"
"addu	$10, $10, $14	\n\t"
"addu	$11, $11, $15	\n\t"
"sw	$10, 40(%0)	\n\t"
"sw	$11, 44(%0)	\n\t"
/* 12..15 */
"lh	$12, 24(%1)	\n\t"
"lh	$13, 26(%1)	\n\t"
"lw	$8, 52(%0)	\n\t"
"mul	$12, $12, %2	\n\t"
"lw	$9, 56(%0)	\n\t"
"lh	$14, 28(%1)	\n\t"
"mul	$13, $13, %2	\n\t"
"lw	$10, 60(%0)	\n\t"
"lh	$15, 30(%1)	\n\t"
"addu	$8, $8, $12	\n\t"
"mul	$14, $14, %2	\n\t"
"sw	$8, 48(%0)	\n\t"
"addu	$9, $9, $13	\n\t"
"mul	$11, $15, %2	\n\t"
"sw	$9, 52(%0)	\n\t"
"addu	$10, $10, $14	\n\t"
"sw	$10, 56(%0)	\n\t"
"sw	$11, 60(%0)	\n\t"
".set	pop		\n\t"
: : "r" (S), "r" (B), "r" (in16)
: "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}

/* Generic filter loop. Runs about 10..25% faster than the unrolled
   C implementation. */
SKP_INLINE void FILTER_LOOP_ORDER_ANY(SKP_int32 * S, const SKP_int16 * B,
		SKP_int16 in16, SKP_int32 order)
{
	SKP_int d;

	/* Unroll for 4 elements */
	for(d = 0; d < order - 4; d += 4) {
		S[d + 0] = SKP_SMLABB(S[d + 1], in16, B[d + 0]);
		S[d + 1] = SKP_SMLABB(S[d + 2], in16, B[d + 1]);
		S[d + 2] = SKP_SMLABB(S[d + 3], in16, B[d + 2]);
		S[d + 3] = SKP_SMLABB(S[d + 4], in16, B[d + 3]);
	}
	if(d < order - 2) {
		S[d + 0] = SKP_SMLABB(S[d + 1], in16, B[d + 0]);
		S[d + 1] = SKP_SMLABB(S[d + 2], in16, B[d + 1]);
		d += 2;
	}
	if(d == order - 2)
		S[d] = SKP_SMLABB(S[d + 1], in16, B[d]);
	S[order - 1] = SKP_SMULBB(in16, B[order - 1]);
}

/* ---------- End opts ----------- */

/* Variable order MA filter */
void SKP_Silk_MA(
    const SKP_int16      *in,            /* I:   input signal                                */
    const SKP_int16      *B,             /* I:   MA coefficients, Q13 [order+1]              */
    SKP_int32            *S,             /* I/O: state vector [order]                        */
    SKP_int16            *out,           /* O:   output signal                               */
    const SKP_int32      len,            /* I:   signal length                               */
    const SKP_int32      order           /* I:   filter order                                */
)
{
	SKP_int   k, in16;
	SKP_int32 out32;

	switch(order) {
	case 8:
		for( k = 0; k < len; k++ ) {
			in16 = in[ k ];
			out32 = SKP_SMLABB( S[ 0 ], in16, B[ 0 ] );
			out32 = SKP_RSHIFT_ROUND( out32, 13 );
			FILTER_LOOP_ORDER_8(S, B + 1, in16);
			out[ k ] = (SKP_int16) SKP_SAT16(out32);
		}
		break;
	case 10:
		for( k = 0; k < len; k++ ) {
			in16 = in[ k ];
			out32 = SKP_SMLABB( S[ 0 ], in16, B[ 0 ] );
			out32 = SKP_RSHIFT_ROUND( out32, 13 );
			FILTER_LOOP_ORDER_10(S, B + 1, in16);
			out[ k ] = (SKP_int16) SKP_SAT16(out32);
		}
		break;
	case 12:
		for( k = 0; k < len; k++ ) {
			in16 = in[ k ];
			out32 = SKP_SMLABB( S[ 0 ], in16, B[ 0 ] );
			out32 = SKP_RSHIFT_ROUND( out32, 13 );
			FILTER_LOOP_ORDER_12(S, B + 1, in16);
			out[ k ] = (SKP_int16) SKP_SAT16(out32);
		}
		break;
	case 16:
		for( k = 0; k < len; k++ ) {
			in16 = in[ k ];
			out32 = SKP_SMLABB( S[ 0 ], in16, B[ 0 ] );
			out32 = SKP_RSHIFT_ROUND( out32, 13 );
			FILTER_LOOP_ORDER_16(S, B + 1, in16);
			out[ k ] = (SKP_int16) SKP_SAT16(out32);
		}
		break;
	default:
		for( k = 0; k < len; k++ ) {
			in16 = in[ k ];
			out32 = SKP_SMLABB( S[ 0 ], in16, B[ 0 ] );
			out32 = SKP_RSHIFT_ROUND( out32, 13 );
			FILTER_LOOP_ORDER_ANY(S, B + 1, in16, order);
			out[ k ] = (SKP_int16) SKP_SAT16(out32);
		}
	}
}

/* Variable order MA prediction error filter */
void SKP_Silk_MA_Prediction(
    const SKP_int16      *in,            /* I:   Input signal                                */
    const SKP_int16      *B,             /* I:   MA prediction coefficients, Q12 [order]     */
    SKP_int32            *S,             /* I/O: State vector [order]                        */
    SKP_int16            *out,           /* O:   Output signal                               */
    const SKP_int32      len,            /* I:   Signal length                               */
    const SKP_int32      order           /* I:   Filter order                                */
)
{
	SKP_int   k, in16;
	SKP_int32 out32;

	switch(order) {
	case 8:
		for( k = 0; k < len; k++ ) {
			in16 = in[ k ];
			out32 = SKP_LSHIFT( in16, 12 ) - S[ 0 ];
			out32 = SKP_RSHIFT_ROUND( out32, 12 );
			FILTER_LOOP_ORDER_8(S, B, in16);
			out[ k ] = (SKP_int16) SKP_SAT16(out32);
		}
		break;
	case 10:
		for( k = 0; k < len; k++ ) {
			in16 = in[ k ];
			out32 = SKP_LSHIFT( in16, 12 ) - S[ 0 ];
			out32 = SKP_RSHIFT_ROUND( out32, 12 );
			FILTER_LOOP_ORDER_10(S, B, in16);
			out[ k ] = (SKP_int16) SKP_SAT16(out32);
		}
		break;
	case 12:
		for( k = 0; k < len; k++ ) {
			in16 = in[ k ];
			out32 = SKP_LSHIFT( in16, 12 ) - S[ 0 ];
			out32 = SKP_RSHIFT_ROUND( out32, 12 );
			FILTER_LOOP_ORDER_12(S, B, in16);
			out[ k ] = (SKP_int16) SKP_SAT16(out32);
		}
		break;
	case 16:
		for( k = 0; k < len; k++ ) {
			in16 = in[ k ];
			out32 = SKP_LSHIFT( in16, 12 ) - S[ 0 ];
			out32 = SKP_RSHIFT_ROUND( out32, 12 );
			FILTER_LOOP_ORDER_16(S, B, in16);
			out[ k ] = (SKP_int16) SKP_SAT16(out32);
		}
		break;
	default:
		for( k = 0; k < len; k++ ) {
			in16 = in[ k ];
			out32 = SKP_LSHIFT( in16, 12 ) - S[ 0 ];
			out32 = SKP_RSHIFT_ROUND( out32, 12 );
			FILTER_LOOP_ORDER_ANY(S, B, in16, order);
			out[ k ] = (SKP_int16) SKP_SAT16(out32);
		}
	}
}

void SKP_Silk_MA_Prediction_Q13(
    const SKP_int16      *in,            /* I:   input signal                                */
    const SKP_int16      *B,             /* I:   MA prediction coefficients, Q13 [order]     */
    SKP_int32            *S,             /* I/O: state vector [order]                        */
    SKP_int16            *out,           /* O:   output signal                               */
    SKP_int32            len,            /* I:   signal length                               */
    SKP_int32            order           /* I:   filter order                                */
)
{
	SKP_int   k, in16;
	SKP_int32 out32;

	switch(order) {
	case 8:
		for( k = 0; k < len; k++ ) {
			in16 = in[ k ];
			out32 = SKP_LSHIFT( in16, 13 ) - S[ 0 ];
			out32 = SKP_RSHIFT_ROUND( out32, 13 );
			FILTER_LOOP_ORDER_8(S, B, in16);
			out[ k ] = (SKP_int16) SKP_SAT16(out32);
		}
		break;
	case 10:
		for( k = 0; k < len; k++ ) {
			in16 = in[ k ];
			out32 = SKP_LSHIFT( in16, 13 ) - S[ 0 ];
			out32 = SKP_RSHIFT_ROUND( out32, 13 );
			FILTER_LOOP_ORDER_10(S, B, in16);
			out[ k ] = (SKP_int16) SKP_SAT16(out32);
		}
		break;
	case 12:
		for( k = 0; k < len; k++ ) {
			in16 = in[ k ];
			out32 = SKP_LSHIFT( in16, 13 ) - S[ 0 ];
			out32 = SKP_RSHIFT_ROUND( out32, 13 );
			FILTER_LOOP_ORDER_12(S, B, in16);
			out[ k ] = (SKP_int16) SKP_SAT16(out32);
		}
		break;
	case 16:
		for( k = 0; k < len; k++ ) {
			in16 = in[ k ];
			out32 = SKP_LSHIFT( in16, 13 ) - S[ 0 ];
			out32 = SKP_RSHIFT_ROUND( out32, 13 );
			FILTER_LOOP_ORDER_16(S, B, in16);
			out[ k ] = (SKP_int16) SKP_SAT16(out32);
		}
		break;
	default:
		for( k = 0; k < len; k++ ) {
			in16 = in[ k ];
			out32 = SKP_LSHIFT( in16, 13 ) - S[ 0 ];
			out32 = SKP_RSHIFT_ROUND( out32, 13 );
			FILTER_LOOP_ORDER_ANY(S, B, in16, order);
			out[ k ] = (SKP_int16) SKP_SAT16(out32);
		}
	}
}

/*
  The inner loop for SKP_Silk_LPC_analysis_filter().
  Register allocation:
  S0..S3: $8..$11
  S + m: $6
  B0..B3: $12..$15
  B + m: $7
  m: $3
*/
#define LPC_ANALYSYS(out32_Q12, S, B, Order)	\
__asm__ volatile(	\
  ".set	push		\n\t"	\
  ".set noreorder	\n\t"	\
\
  /* Set up loop */	\
  "addiu $6, %1, -8	\n\t"	/* S - 4 */	\
  "move	$7, %2		\n\t"	/* B */	\
  "lh	$8, 8($6)	\n\t"	/* S0 = S[0] */	\
  "mult	$0, $0		\n\t"	\
  "j	2f		\n\t"	\
  "addiu $3, %3, -4	\n\t"	/* m = Order - 4 */	\
  /* Loop unrolled for 4 elements */	\
  "1:			\n\t"	\
  "lh	$12, 0($7)	\n\t"	\
  "lh	$9, 2($6)	\n\t"	\
  "madd	$8, $12		\n\t"	\
  "lh	$13, 2($7)	\n\t"	\
  "lh	$10, 4($6)	\n\t"	\
  "madd	$9, $13		\n\t"	\
  "lh	$14, 4($7)	\n\t"	\
  "lh	$11, 6($6)	\n\t"	\
  "madd	$10, $14	\n\t"	\
  "lh	$15, 6($7)	\n\t"	\
  "sh	$8, 2($6)	\n\t"	/* S[m + 1] = S0 */	\
  "madd	$11, $15	\n\t"	\
  "lh	$8, 8($6)	\n\t"	/* S0 = S[m + 4] */	\
  "sh	$9, 4($6)	\n\t"	\
  "sh	$10, 6($6)	\n\t"	\
  "sh	$11, 8($6)	\n\t"	\
  "addiu $7, $7, 8	\n\t"	/* B += 4 */	\
  "addiu $3, $3, -4	\n\t"	\
  "2:			\n\t"	\
  "bgtz	$3, 1b		\n\t"	\
  "addiu $6, $6, 8	\n\t"	/* S += 4 */	\
  /* Elements Order-4, Order-3 */	\
  "bltz	$3, 3f		\n\t"	/* (Order % 4) != 0 */	\
  "nop			\n\t"	/* -1 clk */	\
  "lh	$12, 0($7)	\n\t"	\
  "lh	$9, 2($6)	\n\t"	\
  "madd	$8, $12		\n\t"	\
  "lh	$13, 2($7)	\n\t"	\
  "sh	$8, 2($6)	\n\t"	\
  "madd	$9, $13		\n\t"	\
  "lh	$8, 4($6)	\n\t"	\
  "sh	$9, 4($6)	\n\t"	\
  "addiu $7, $7, 4	\n\t"	\
  "addiu $6, $6, 4	\n\t"	\
  /* Elements Order-2, Order-1 */	\
  "3:			\n\t"	\
  "lh	$12, 0($7)	\n\t"	\
  "lh	$9, 2($6)	\n\t"	\
  "madd	$8, $12		\n\t"	\
  "lh	$13, 2($7)	\n\t"	\
  "sh	$8, 2($6)	\n\t"	\
  "madd	$9, $13		\n\t"	\
  "mflo	%0		\n\t"	\
\
  ".set	pop		\n\t"	\
  : "=r" (out32_Q12)	\
  : "r" (S), "r" (B), "r" (Order)	\
  : "$3", "$6", "$7", "$8", "$9", "$10", "$11", \
    "$12", "$13", "$14", "$15", "memory")

/*
  Variable order MA prediction error filter. Inverse filter of
  SKP_Silk_LPC_synthesis_filter.

  The inlined assembly makes it over 30% faster than the generic C.
*/
void SKP_Silk_LPC_analysis_filter(
    const SKP_int16      *in,            /* I:   Input signal                                */
    const SKP_int16      *B,             /* I:   MA prediction coefficients, Q12 [order]     */
    SKP_int16            *S,             /* I/O: State vector [order]                        */
    SKP_int16            *out,           /* O:   Output signal                               */
    const SKP_int32      len,            /* I:   Signal length                               */
    const SKP_int32      Order           /* I:   Filter order                                */
)
{
	SKP_int  k;
	SKP_int32 out32_Q12, out32;
	/* Order must be even */
	SKP_assert( 2 * Order_half == Order );

	/* S[] values are in Q0 */
	for( k = 0; k < len; k++ ) {
		LPC_ANALYSYS(out32_Q12, S, B, Order);
		/* Subtract prediction */
		out32_Q12 = SKP_SUB_SAT32( SKP_LSHIFT(
			(SKP_int32)in[ k ], 12 ), out32_Q12 );
		/* Scale to Q0 */
		out32 = SKP_RSHIFT_ROUND( out32_Q12, 12 );
		out[ k ] = (SKP_int16)SKP_SAT16( out32 );
		/* Move input line */
		S[ 0 ] = in[ k ];
	}
}

#endif /* defined(EMBEDDED_MIPS) */
