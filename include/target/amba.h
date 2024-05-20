/*
 * ZETALOG's Personal COPYRIGHT
 *
 * Copyright (c) 2019
 *    ZETALOG - "Lv ZHENG".  All rights reserved.
 *    Author: Lv "Zetalog" Zheng
 *    Internet: zhenglv@hotmail.com
 *
 * This COPYRIGHT used to protect Personal Intelligence Rights.
 * Redistribution and use in source and binary forms with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by the Lv "Zetalog" ZHENG.
 * 3. Neither the name of this software nor the names of its developers may
 *    be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * 4. Permission of redistribution and/or reuse of souce code partially only
 *    granted to the developer(s) in the companies ZETALOG worked.
 * 5. Any modification of this software should be published to ZETALOG unless
 *    the above copyright notice is no longer declaimed.
 *
 * THIS SOFTWARE IS PROVIDED BY THE ZETALOG AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE ZETALOG OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * @(#)amba.h: advanced microcontroller bus architecture (AMBA) definitions
 * $Id: amba.h,v 1.1 2019-09-30 09:11:00 zhenglv Exp $
 */

#ifndef __AMBA_H_INCLUDE__
#define __AMBA_H_INCLUDE__

#include <target/types.h>

#define AXI_AXLEN_MAX_AXI3		16
#define AXI_AXLEN_MAX_AXI4		256

#define AXI_AXSIZE_1			0
#define AXI_AXSIZE_2			1
#define AXI_AXSIZE_4			2
#define AXI_AXSIZE_8			3
#define AXI_AXSIZE_16			4
#define AXI_AXSIZE_32			5
#define AXI_AXSIZE_64			6
#define AXI_AXSIZE_128			7

#define AXI_AXBURST_FIXED		0
#define AXI_AXBURST_INCR		1 /* align cache line */
#define AXI_AXBURST_WRAP		2 /* align AxSize */

#define AXI_AXCACHE_BUFFERABLE		_BV(0)
#define AXI_AXCACHE_NON_BUFFERABLE	0
#define AXI_AXCACHE_CACHEABLE		_BV(1)
#define AXI_AXCACHE_NON_CACHEABLE	0
#define AXI_AXCACHE_READ_ALLOCATE	_BV(2)
#define AXI_AXCACHE_WRITE_ALLOCATE	_BV(3)

#define AXI_AXPROT_PRIVILEDGED		_BV(0)
#define AXI_AXPROT_NON_PRIVILEDGED	0
#define AXI_AXPROT_NON_SECURE		_BV(1)
#define AXI_AXPROT_SECURE		0
#define AXI_AXPROT_INSTRUCTION		_BV(2)
#define AXI_AXPROT_DATA			0

#define AXI_AXLOCK_NORMAL		0
#define AXI_AXLOCK_EXCLUSIVE		1

#define AXI_RESP_OKAY			0
#define AXI_RESP_EXOKAY			1
#define AXI_RESP_SLVERR			2
#define AXI_RESP_DECERR			3

#define __bus_aligned			__align(AXI_AXSIZE_BYTES)

#endif /* __AMBA_H_INCLUDE__ */
