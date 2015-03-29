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

/*
 *	MIPS32 asm for SKP_Silk_warped_autocorrelation_FIX
 *	
 *
 *
 *
 */
#if defined(__mips__)

#if defined (_MIPSEB)
#define MSB	0
#define LSB	4
#define MSB2	8
#define LSB2	12
#elif defined (_MIPSEL)
#define MSB	4
#define LSB	0
#define MSB2	12
#define LSB2	8
#else
#error	"Can't read Endianness defines"
#endif

/* Variable mapping is in C preprocessor level, as no asm directives has been found. */
#define corr_ptr	$a0
#define	word_i		$a1
#define scale_ptr	$a1
#define input_ptr	$a2
#define	warping_Q16 	$a3



#define	tmp1_QS		$t0
#define	tmp2_QS		$t1
#define state_QS_val1	$t2
#define state_QS_val2	$t3
#define state_QS_val3	$t2
#define tmp64M2		$t2
#define tmp64L2		$t3
#define tmp64M		$t4
#define tmp64L		$t5
#define corr_QC_ptr	$t6
#define	length		$t7
#define	state_QS_ptr	$t8
#define	state0		$t9


#define	tmp0		$s0
#define tmp1		$s1
#define	tmp2		$s2
#define	tmp3		$s3


/* Hardcoded Stack */

#define FP_STACK 8
#define corr_QC_STACK 144
#define state_QS_STACK 72
#define VAL_STACK 40
#define TOTAL_STACK (VAL_STACK+state_QS_STACK+corr_QC_STACK+FP_STACK)

#define state_QS_OFFSET VAL_STACK
#define corr_QC_OFFSET (VAL_STACK+state_QS_STACK)
#define FP_OFFSET (TOTAL_STACK-4) 


.globl	SKP_Silk_warped_autocorrelation_FIX

SKP_Silk_warped_autocorrelation_FIX: /*(SKP_int32 *(a0) 	corr,
					SKP_int32 *(a1)		scale,
					SKP_int32(a2) 		input,
					SKP_int32(a3) 		warping_Q16,
					SKP_int32(sp+16)	length,
					SKP_int32(sp+20) 	order
					)*/
/*Loading input arguments*/	
	lw	length, 16($sp)
	lw	state0/*order*/, 20($sp)
/*Stacking - 4 Words*/
	addi	$sp, $sp, -TOTAL_STACK
	sw	$s0, 0($sp)
	sw	$s1, 4($sp)
	sw	$s2, 8($sp)
	sw	$s3, 12($sp)
	sw	$s8, FP_OFFSET($sp)
	move	$s8, $sp
	addi	state_QS_ptr, $sp, state_QS_OFFSET
	addi	tmp0, $sp, state_QS_OFFSET
	addi	corr_QC_ptr, $sp, corr_QC_OFFSET
	li	tmp1, 18
	sw	state_QS_ptr, 16($sp)
	sw	corr_QC_ptr, 20($sp)
	sw	state0/*order*/, 24($sp)
	sw	corr_ptr, 28($sp)
	sw	scale_ptr, 32($sp)

/*Local Array Initialization*/		
5:
	sw	$zero,  0(tmp0)
	sw	$zero,  4(tmp0)
	sw	$zero,  8(tmp0)
	addi	tmp0, tmp0, 12
	addi	tmp1, tmp1, -1
	bgtz	tmp1, 5b


	sll	warping_Q16, warping_Q16, 16
1: 
	lh	state0, 0(input_ptr)
	sll	state0, state0, 14
	move	tmp1_QS, state0
	addi	input_ptr, input_ptr, 2
	addi	length, length, -1
	lw	state_QS_ptr, 16($sp)
	lw	corr_QC_ptr, 20($sp)
	lw	word_i, 24($sp)
	lw	state_QS_val1, 0(state_QS_ptr)

0:
/*INNERLOOP 1st half*/
	lw	state_QS_val2, 4(state_QS_ptr)
	
	addi	word_i, word_i, -2
	sw	tmp1_QS, 0(state_QS_ptr)
	subu	tmp0, state_QS_val2, tmp1_QS
	mult	tmp0, warping_Q16
	mfhi	tmp3
	
	lw	tmp64M, MSB(corr_QC_ptr)
	
	mult	state0, tmp1_QS
	mfhi	tmp0
	mflo	tmp1
	lw	tmp64L, LSB(corr_QC_ptr)
	addu	tmp2_QS, tmp3, state_QS_val1
	lw	state_QS_val3, 8(state_QS_ptr)
  
	sll	tmp2, tmp0, 14			/*RSHIFT64*/
	srl	tmp1, tmp1, 18
	sra	tmp0, tmp0, 18
	or	tmp1, tmp1, tmp2

	addu	tmp0, tmp0, tmp64M		/*ADD64*/
	addu	tmp1, tmp1, tmp64L
	sltu	tmp2, tmp1, tmp64L
	addu	tmp0, tmp0, tmp2
	
	sw	tmp1, LSB(corr_QC_ptr)
	sw	tmp0, MSB(corr_QC_ptr)
/*INNERLOOP 2nd half*/
	subu	tmp0, state_QS_val3, tmp2_QS
	mult	tmp0, warping_Q16
	mfhi	tmp3
	
	sw	tmp2_QS, 4(state_QS_ptr)
	addi	state_QS_ptr, state_QS_ptr, 8
	mult	state0, tmp2_QS
	mfhi	tmp0
	mflo	tmp1
	lw	tmp64M, MSB2(corr_QC_ptr)
	lw	tmp64L, LSB2(corr_QC_ptr)
	addu	tmp1_QS, tmp3, state_QS_val2
	
	sll	tmp2, tmp0, 14			/*RSHIFT64*/
	srl	tmp1, tmp1, 18
	sra	tmp0, tmp0, 18
	or	tmp1, tmp1, tmp2

	addu	tmp0, tmp0, tmp64M		/*ADD64*/
	addu	tmp1, tmp1, tmp64L
	sltu	tmp2, tmp1, tmp64L
	addu	tmp0, tmp0, tmp2
	sw	tmp1, LSB2(corr_QC_ptr)
	sw	tmp0, MSB2(corr_QC_ptr)
	addi	corr_QC_ptr, corr_QC_ptr, 16
	bgtz	word_i, 0b
	/*nop*/

	
	mult	state0, tmp1_QS
	mfhi	tmp0
	mflo	tmp1
	sw	tmp1_QS, 0(state_QS_ptr)
	lw	tmp64M, MSB(corr_QC_ptr)
	lw	tmp64L, LSB(corr_QC_ptr)

	sll	tmp2, tmp0, 14			/*RSHIFT64*/
	srl	tmp1, tmp1, 18
	sra	tmp0, tmp0, 18
	or	tmp1, tmp1, tmp2

	addu	tmp0, tmp0, tmp64M		/*ADD64*/
	addu	tmp1, tmp1, tmp64L
	sltu	tmp2, tmp1, tmp64L
	addu	tmp0, tmp0, tmp2
	sw	tmp0, MSB(corr_QC_ptr)
	sw	tmp1, LSB(corr_QC_ptr)
	bgtz	length, 1b
	/*nop*/
	lw	corr_QC_ptr, 20($sp)
	li	tmp3, 0
	li	tmp1_QS, -22
	li	tmp2_QS, 20
	lw	tmp64M, MSB(corr_QC_ptr)
	lw	tmp64L, LSB(corr_QC_ptr)
	
	lw	scale_ptr, 32($sp)
	clz	tmp0, tmp64M
	clz	tmp1, tmp64L
	movn	tmp1, tmp3, tmp64M
	add 	tmp0, tmp0, tmp1
	addi	tmp0, tmp0, -35
	addi	tmp1, tmp0, 22
	addi	tmp2, tmp0, -20
	slti	tmp1, tmp1, 0
	slti	tmp2, tmp2, 0
	movn	tmp0, tmp1_QS, tmp1
	movz	tmp0, tmp2_QS, tmp2
	negu	tmp2_QS, tmp0			/*-( QC + lsh )*/
	addi	tmp2, tmp2_QS, -10
	sw	tmp2, 0(scale_ptr)
	/*move	$v0, tmp0*/
	move	tmp1_QS, tmp0
	lw	word_i, 24($sp)
	lw	corr_QC_ptr, 20($sp)
	lw	corr_ptr, 28($sp)
	addi	word_i, word_i, -1
/*SHIFT FORLOOP*/
	bltz	tmp1_QS, 2f 
3:	
	lw	tmp64L, LSB(corr_QC_ptr)
	lw	tmp64L2, LSB2(corr_QC_ptr)
	addi	corr_ptr, corr_ptr, 8
	addi	corr_QC_ptr, corr_QC_ptr, 16
	addi	word_i, word_i, -2
	sllv	tmp64L, tmp64L,tmp1_QS	
	sllv	tmp64L2, tmp64L2,tmp1_QS
	sw	tmp64L, -8(corr_ptr)
	sw	tmp64L2, -4(corr_ptr)
	bgtz	word_i, 3b

	lw	tmp64L, LSB(corr_QC_ptr)
	sllv	tmp64L, tmp64L,tmp1_QS
	sw	tmp64L, 0(corr_ptr)
/*DeStacking - 2 Words*/
	move	$sp, $s8
	lw	$s8, FP_OFFSET($sp)
	lw	$s0, 0($sp)
	lw	$s1, 4($sp)
	lw	$s2, 8($sp)
	lw	$s3, 12($sp)
	addi	$sp, $sp, TOTAL_STACK
/*Retruning*/
	jr	$ra

2:
	addi	tmp1_QS, tmp1_QS, 32
4:
	lw	tmp64M, MSB(corr_QC_ptr)
	lw	tmp64L, LSB(corr_QC_ptr)
	lw	tmp64M2, MSB2(corr_QC_ptr)
	lw	tmp64L2, LSB2(corr_QC_ptr)
	addi	corr_ptr, corr_ptr, 8
	addi	corr_QC_ptr, corr_QC_ptr, 16
	addi	word_i, word_i, -2
	sllv	tmp0, tmp64M, tmp1_QS	
	sllv	tmp1, tmp64M2, tmp1_QS
	srlv	tmp64L, tmp64L, tmp2_QS	
	srlv	tmp64L2, tmp64L2, tmp2_QS
	or	tmp64L, tmp64L, tmp0
	or	tmp64L2, tmp64L2, tmp1
	sw	tmp64L, -8(corr_ptr)
	sw	tmp64L2, -4(corr_ptr)
	bgtz	word_i, 4b

	lw	tmp64M, MSB(corr_QC_ptr)
	lw	tmp64L, LSB(corr_QC_ptr)
	sllv	tmp0, tmp64M, tmp1_QS	
	srlv	tmp64L, tmp64L, tmp2_QS
	or	tmp64L, tmp64L, tmp0
	sw	tmp64L, 0(corr_ptr)
/*DeStacking - 4 Words*/
	move	$sp, $s8
	lw	$s8, FP_OFFSET($sp)
	lw	$s0, 0($sp)
	lw	$s1, 4($sp)
	lw	$s2, 8($sp)
	lw	$s3, 12($sp)
	addi	$sp, $sp, TOTAL_STACK
/*Retruning*/
	jr	$ra

#endif
