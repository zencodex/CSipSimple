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

#if defined(__mips__)

#if defined (_MIPSEB)
#define retM	$v0
#define retL	$v1
#elif defined (_MIPSEL)
#define retM	$v1
#define retL	$v0
#else
#error	"Can't read Endianness defines"
#endif


#define 	inVec1	$a0
#define		inVec2	$a1
#define		len	$a2
#define 	val0	$t0
#define		val1	$t1
#define 	val2	$t2
#define		val3	$t3
#define 	val4	$t4
#define 	val5	$t5
#define 	val6	$t6

.globl SKP_Silk_inner_prod16_aligned_64
.globl SKP_Silk_inner_prod_aligned

SKP_Silk_inner_prod16_aligned_64:
/*-fno-omit-frame-pointer*/
	addi	$sp, $sp, -8
	sw	$s8, 4($sp)
	move	$s8, $sp

	sll	val4, len, 1 
        addu	inVec2, inVec2, val4 
        addu	inVec1, inVec1, val4 	 
        mult	$zero, $zero
	j	2f
 
/* Unrolled loop */		 
1:		 
        lh	val0, -2(inVec1) 
        lh	val1, -2(inVec2) 
        lh	val2, -4(inVec1) 
        lh	val3, -4(inVec2) 
        madd	val0, val1	 
        lh	val0, -6(inVec1) 
        lh	val1, -6(inVec2) 
        madd	val2, val3 
        lh	val2, -8(inVec1) 
        lh	val3, -8(inVec2) 
        madd	val0, val1	 
        lh	val0, -10(inVec1) 
        lh	val1, -10(inVec2) 
        madd	val2, val3 
        lh	val2, -12(inVec1) 
        lh	val3, -12(inVec2) 
        madd	val0, val1	 
        lh	val0, -14(inVec1) 
        lh	val1, -14(inVec2) 
        madd	val2, val3 
        lh	val2, -16(inVec1) 
        lh	val3, -16(inVec2) 
        madd	val0, val1	 
        addiu 	inVec1, inVec1, -16 
        addiu 	inVec2, inVec2, -16 
        madd	val2, val3 
2:		 
        pref 	0, -18(inVec1) 
        addiu 	len, len, -8  
        pref	0, -18(inVec2)
	bgez	len, 1b	
 
/* 4-element leftover */	 
        addiu 	len, len, 4 
        bltz	len, 3f	 

        lh	val0, -2(inVec1) 
        lh	val1, -2(inVec2) 
        lh	val2, -4(inVec1) 
        lh	val3, -4(inVec2) 
        madd	val0, val1	 
        lh	val0, -6(inVec1) 
        lh	val1, -6(inVec2) 
        madd	val2, val3 
        lh	val2, -8(inVec1) 
        lh	val3, -8(inVec2) 
        madd	val0, val1	 
        addiu 	inVec1, inVec1, -8 
        addiu 	inVec2, inVec2, -8 
        madd	val2, val3 
        addiu 	len, len, -4 
/* 2-element leftover */	 
3:		 
        addiu 	len, len, 2 
        bltz	len, 4f	 

        lh	val0, -2(inVec1) 
        lh	val1, -2(inVec2) 
        lh	val2, -4(inVec1) 
        lh	val3, -4(inVec2) 
        madd	val0, val1	 
        addiu	inVec1, inVec1, -4 
        addiu 	inVec2, inVec2, -4 
        madd	val2, val3 
        addiu 	len, len, -2 
 
/* 1-element leftover */	 
4:		 
        addiu 	len, len, 1 
        bltz	len, 5f

        lh	val0, -2(inVec1) 
        lh	val1, -2(inVec2) 
        madd	val0, val1
 
5:		 
        mflo	retL 
        mfhi	retM

	move	$sp, $s8
	lw	$s8, 4($sp)
	addi	$sp, $sp, 8
	jr	$ra


SKP_Silk_inner_prod_aligned:
/*-fno-omit-frame-pointer*/
	addi	$sp, $sp, -8
	sw	$s8, 4($sp)
	move	$s8, $sp

	sll	val4, len, 1 
        addu	inVec2, inVec2, val4 
        addu	inVec1, inVec1, val4 	 
#if (__mips_dsp_rev > 0 )
        mult	$ac0, $zero, $zero
	andi	val4, inVec1, 3
	andi	val5, inVec2, 3
	xor	val6, val4, val5
	bnez	val6, 1f
	beqz	val4, 6f
	addu	len, len, -1
	lh	val0, -2(inVec1) 
        lh	val1, -2(inVec2)
	addi	inVec1, inVec1, -2
	addi	inVec2, inVec2, -2
        madd	val0, val1
	madd	val0, val1
	
	j	6f
	/* Unrolled loop */		 
0:		 
        lw	val0, -4(inVec1) 
        lw	val1, -4(inVec2) 
        lw	val2, -8(inVec1) 
        lw	val3, -8(inVec2) 
        dpaq_s.w.ph	$ac0, val0, val1	 
        lw	val0, -12(inVec1) 
        lw	val1, -12(inVec2) 
        dpaq_s.w.ph	$ac0, val2, val3 
        lw	val2, -16(inVec1) 
        lw	val3, -16(inVec2) 
        dpaq_s.w.ph	$ac0, val0, val1	 
        lw	val0, -20(inVec1) 
        lw	val1, -20(inVec2) 
        dpaq_s.w.ph	$ac0, val2, val3 
        lw	val2, -24(inVec1) 
        lw	val3, -24(inVec2) 
        dpaq_s.w.ph	$ac0, val0, val1	 
        lw	val0, -28(inVec1) 
        lw	val1, -28(inVec2) 
        dpaq_s.w.ph	$ac0, val2, val3 
        lw	val2, -32(inVec1) 
        lw	val3, -32(inVec2)    
        dpaq_s.w.ph	$ac0, val0, val1
        addiu 	inVec1, inVec1, -32 
        addiu 	inVec2, inVec2, -32 
        dpaq_s.w.ph	$ac0, val2, val3  
6:		 
        pref 	0, -32(inVec1) 
        addiu 	len, len, -16  
        pref	0, -32(inVec2)
	bgez	len, 0b	


	/* 4-element leftover */	 
        addiu 	len, len, 8 
        bltz	len, 7f	 

/* 8-element leftover */		 
        lw	val0, -4(inVec1) 
        lw	val1, -4(inVec2) 
        lw	val2, -8(inVec1) 
        lw	val3, -8(inVec2) 
        dpaq_s.w.ph	$ac0, val0, val1	 
        lw	val0, -12(inVec1) 
        lw	val1, -12(inVec2) 
        dpaq_s.w.ph	$ac0, val2, val3  
        lw	val2, -16(inVec1) 
        lw	val3, -16(inVec2) 
        dpaq_s.w.ph	$ac0, val0, val1	 
        addiu 	inVec1, inVec1, -16 
        addiu 	inVec2, inVec2, -16 
        dpaq_s.w.ph	$ac0, val2, val3	 
        addiu 	len, len, -8  

7: 
/* 4-element leftover */	 
        addiu 	len, len, 4 
        bltz	len, 8f	 

        lw	val0, -4(inVec1) 
        lw	val1, -4(inVec2) 
        lw	val2, -8(inVec1) 
        lw	val3, -8(inVec2) 
        dpaq_s.w.ph	$ac0, val0, val1 
        addiu 	inVec1, inVec1, -8 
        addiu 	inVec2, inVec2, -8 
        dpaq_s.w.ph	$ac0, val2, val3
        addiu 	len, len, -4 
/* 2-element leftover */	 
8:		 
        addiu 	len, len, 2 
        bltz	len, 9f	 

        lw	val0, -4(inVec1) 
        lw	val1, -4(inVec2)  
        addiu	inVec1, inVec1, -4 
        addiu 	inVec2, inVec2, -4 
        dpaq_s.w.ph	$ac0, val0, val1
        addiu 	len, len, -2 
 
/* 1-element leftover */	 
9:		 
        addiu 	len, len, 1 
        bltz	len, 2f

        lh	val0, -2(inVec1) 
        lh	val1, -2(inVec2) 
        madd	val0, val1
	madd	val0, val1
 
2:		 
	shilo	$ac0, 1
        mflo	$v0, $ac0

	move	$sp, $s8
	lw	$s8, 4($sp)
	addi	$sp, $sp, 8
	jr	$ra

#endif
	mult	$zero, $zero
	j	1f

/* Unrolled loop */		 
0:		 
        lh	val0, -2(inVec1) 
        lh	val1, -2(inVec2) 
        lh	val2, -4(inVec1) 
        lh	val3, -4(inVec2) 
        madd	val0, val1	 
        lh	val0, -6(inVec1) 
        lh	val1, -6(inVec2) 
        madd	val2, val3 
        lh	val2, -8(inVec1) 
        lh	val3, -8(inVec2) 
        madd	val0, val1	 
        lh	val0, -10(inVec1) 
        lh	val1, -10(inVec2) 
        madd	val2, val3 
        lh	val2, -12(inVec1) 
        lh	val3, -12(inVec2) 
        madd	val0, val1	 
        lh	val0, -14(inVec1) 
        lh	val1, -14(inVec2) 
        madd	val2, val3 
        lh	val2, -16(inVec1) 
        lh	val3, -16(inVec2) 
        madd	val0, val1
	lh	val0, -18(inVec1) 
        lh	val1, -18(inVec2) 
        madd	val2, val3 
        lh	val2, -20(inVec1) 
        lh	val3, -20(inVec2) 
        madd	val0, val1
	lh	val0, -22(inVec1) 
        lh	val1, -22(inVec2) 
        madd	val2, val3 
        lh	val2, -24(inVec1) 
        lh	val3, -24(inVec2) 
        madd	val0, val1
	lh	val0, -26(inVec1) 
        lh	val1, -26(inVec2) 
        madd	val2, val3 
        lh	val2, -28(inVec1) 
        lh	val3, -28(inVec2) 
        madd	val0, val1
	lh	val0, -30(inVec1) 
        lh	val1, -30(inVec2) 
        madd	val2, val3 
        lh	val2, -32(inVec1) 
        lh	val3, -32(inVec2) 
        madd	val0, val1
        addiu 	inVec1, inVec1, -32 
        addiu 	inVec2, inVec2, -32 
        madd	val2, val3 
1:		 
        pref 	0, -32(inVec1) 
        addiu 	len, len, -16  
        pref	0, -32(inVec2)
	bgez	len, 0b	


	/* 4-element leftover */	 
        addiu 	len, len, 8 
        bltz	len, 2f	 

/* 8-element leftover */		 
        lh	val0, -2(inVec1) 
        lh	val1, -2(inVec2) 
        lh	val2, -4(inVec1) 
        lh	val3, -4(inVec2) 
        madd	val0, val1	 
        lh	val0, -6(inVec1) 
        lh	val1, -6(inVec2) 
        madd	val2, val3 
        lh	val2, -8(inVec1) 
        lh	val3, -8(inVec2) 
        madd	val0, val1	 
        lh	val0, -10(inVec1) 
        lh	val1, -10(inVec2) 
        madd	val2, val3 
        lh	val2, -12(inVec1) 
        lh	val3, -12(inVec2) 
        madd	val0, val1	 
        lh	val0, -14(inVec1) 
        lh	val1, -14(inVec2) 
        madd	val2, val3 
        lh	val2, -16(inVec1) 
        lh	val3, -16(inVec2) 
        madd	val0, val1	 
        addiu 	inVec1, inVec1, -16 
        addiu 	inVec2, inVec2, -16 
        madd	val2, val3 		 
        addiu 	len, len, -8  

2: 
/* 4-element leftover */	 
        addiu 	len, len, 4 
        bltz	len, 3f	 

        lh	val0, -2(inVec1) 
        lh	val1, -2(inVec2) 
        lh	val2, -4(inVec1) 
        lh	val3, -4(inVec2) 
        madd	val0, val1	 
        lh	val0, -6(inVec1) 
        lh	val1, -6(inVec2) 
        madd	val2, val3 
        lh	val2, -8(inVec1) 
        lh	val3, -8(inVec2) 
        madd	val0, val1	 
        addiu 	inVec1, inVec1, -8 
        addiu 	inVec2, inVec2, -8 
        madd	val2, val3 
        addiu 	len, len, -4 
/* 2-element leftover */	 
3:		 
        addiu 	len, len, 2 
        bltz	len, 4f	 

        lh	val0, -2(inVec1) 
        lh	val1, -2(inVec2) 
        lh	val2, -4(inVec1) 
        lh	val3, -4(inVec2) 
        madd	val0, val1	 
        addiu	inVec1, inVec1, -4 
        addiu 	inVec2, inVec2, -4 
        madd	val2, val3 
        addiu 	len, len, -2 
 
/* 1-element leftover */	 
4:		 
        addiu 	len, len, 1 
        bltz	len, 5f

        lh	val0, -2(inVec1) 
        lh	val1, -2(inVec2) 
        madd	val0, val1
 
5:		 
        mflo	$v0

	move	$sp, $s8
	lw	$s8, 4($sp)
	addi	$sp, $sp, 8
	jr	$ra

#endif


