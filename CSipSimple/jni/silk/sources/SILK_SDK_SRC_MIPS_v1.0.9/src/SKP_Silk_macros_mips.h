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

#ifndef _SKP_SILK_API_GNUC_MIPS_H_
#define _SKP_SILK_API_GNUC_MIPS_H_

/* Functions multiplying x32 do 64-bit multiplication, computing
   the result into HI. This results in over 2x shorter code when chaining the
   functions, like SMLAWB(SMULWB(a, b), c, d). Unfortunately our current
   MIPS compiler (cs09q2) is dumb enough to unnecessarily retransfer the
   intermediate result from HI and back to it. Therefore, reimplementing
   SMLAWB(SMULWB(a, b), c, d) explicitly in inline assembly can still
   beat the compiled code (about 3x shorter than the original).
   Nobody's perfect, let alone the poor compiler. */

// (a32 * (SKP_int32)((SKP_int16)(b32))) >> 16 output have to be 32bit int
SKP_INLINE SKP_int32 SKP_SMULWB(SKP_int32 a, SKP_int32 b)
{
	// Yao Yi: significant faster by just using asm();
	SKP_int32 ret;
	__asm__ volatile(
	"sll	$3, %2, 16	\n\t"
	"mult	%1, $3		\n\t"
	"mfhi	%0		\n\t"
	: "=r" (ret) 
	: "r" (a), "r" (b)
	: "$3");
	return ret;
	/*int64_t c = (int64_t) a * (int64_t) (b << 16);
        return (int32_t)(c >> 32);*/
}

// a32 + (b32 * (SKP_int32)((SKP_int16)(c32))) >> 16 output have to be 32bit int
SKP_INLINE SKP_int32 SKP_SMLAWB(SKP_int32 a, SKP_int32 b, SKP_int32 c)
{
        return a + SKP_SMULWB(b, c);
}
// (a32 * (b32 >> 16)) >> 16
SKP_INLINE SKP_int32 SKP_SMULWT(SKP_int32 a, SKP_int32 b)
{
	b = b & 0xFFFF0000;
        int64_t c = (int64_t) a * (int64_t) ( b );
        return (int32_t)(c >> 32);
}

// a32 + (b32 * (c32 >> 16)) >> 16
SKP_INLINE SKP_int32 SKP_SMLAWT(SKP_int32 a, SKP_int32 b, SKP_int32 c)
{
        return a + SKP_SMULWT(b, c);
}

// (SKP_int32)((SKP_int16)(a3))) * (SKP_int32)((SKP_int16)(b32)) output have to be 32bit int
#define SKP_SMULBB(a32, b32)						\
	((SKP_int32)((SKP_int16)(a32)) * (SKP_int32)((SKP_int16)(b32)))

// a32 + (SKP_int32)((SKP_int16)(b32)) * (SKP_int32)((SKP_int16)(c32)) output have to be 32bit int
#define SKP_SMLABB(a32, b32, c32)					\
	((a32) + ((SKP_int32)((SKP_int16)(b32))) * \
	(SKP_int32)((SKP_int16)(c32)))

// (SKP_int32)((SKP_int16)(a32)) * (b32 >> 16)
#define SKP_SMULBT(a32, b32)						\
	((SKP_int32)((SKP_int16)(a32)) * ((b32) >> 16))

// a32 + (SKP_int32)((SKP_int16)(b32)) * (c32 >> 16)
#define SKP_SMLABT(a32, b32, c32)					\
	((a32) + ((SKP_int32)((SKP_int16)(b32))) * ((c32) >> 16))

// a64 + (b32 * c32)
#define SKP_SMLAL(a64, b32, c32)					\
	(SKP_ADD64((a64), ((SKP_int64)(b32) * (c32))))

// (a32 * b32) >> 16
SKP_INLINE SKP_int32 SKP_SMULWW(SKP_int32 a, SKP_int32 b)
{
	return SKP_SMULWB(a, b) + a * (((b >> 15) + 1) >> 1);
}

// a32 + ((b32 * c32) >> 16)
SKP_INLINE SKP_int32 SKP_SMLAWW(SKP_int32 a, SKP_int32 b, SKP_int32 c)
{
	return SKP_SMLAWB(a, b, c) + b * (((c >> 15) + 1) >> 1);
}

/* add with output saturated */
#define SKP_ADD_SAT32(a32, b32) ({					\
	SKP_int32 a = (a32), b = (b32);					\
	SKP_int32 c = a + b, d = SKP_int32_MIN;				\
	((a ^ b) < 0 || (a ^ c) >= 0) ? c :				\
	((c >= 0) ? d : d - 1); })

/* subtract with output saturated */
#define SKP_SUB_SAT32(a32, b32) ({					\
	SKP_int32 a = (a32), b = (b32);					\
	SKP_int32 c = a - b, d = SKP_int32_MIN;				\
	((a ^ b) >= 0 || (a ^ c) >= 0) ? c :				\
        ((c >= 0) ? d : d - 1); })

SKP_INLINE SKP_int32 SKP_Silk_CLZ16(SKP_int16 a)
{
	SKP_int32 rc, tmp = (a << 16) | 0x8000;
	// rd and rt must be the same
	__asm__ volatile("clz    %0, %1\n\t" : "=r" (rc) : "r" (tmp));
	return rc;
}

SKP_INLINE SKP_int32 SKP_Silk_CLZ32(SKP_int32 a)
{
	SKP_int32 rc;
	// rd and rt must be the same
	__asm__ volatile("clz    %0, %1\n\t" : "=r" (rc) : "r" (a));
	return rc;
}

/*
  Compiles into just 4 instructions, no branching, when inlined.
*/
SKP_INLINE SKP_int32 SKP_Silk_CLZ64(SKP_int64 in)
{
	SKP_int32 rc;
	SKP_int32 low = (SKP_uint32) in;
	SKP_int32 high = (SKP_uint32) (in >> 32);
	rc = SKP_Silk_CLZ32(high);
	low = SKP_Silk_CLZ32(low) + 32;
	return high ? rc : low;
}

#define SKP_SMMUL(a32, b32)				(SKP_int32)SKP_RSHIFT64(SKP_SMULL((a32), (b32)), 32)

#endif //_SKP_SILK_API_GNUC_MIPS_H_

