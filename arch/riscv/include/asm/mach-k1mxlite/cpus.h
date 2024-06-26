/*
 * ZETALOG's Personal COPYRIGHT
 *
 * Copyright (c) 2023
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
 * @(#)cpus.h: K1MXLite specific CPU definitions
 * $Id: cpus.h,v 1.1 2023-09-06 18:11:00 zhenglv Exp $
 */

#ifndef __CPUS_K1MXLITE_H_INCLUDE__
#define __CPUS_K1MXLITE_H_INCLUDE__

#define DIE0_HART		0
#define DIE1_HART		32

#ifdef CONFIG_K1MXLITE_PARTIAL_GOOD
#define BOOT_HART		CONFIG_K1MXLITE_BOOT_HART_ID
#define BOOT_MASK		CONFIG_K1MXLITE_PARTIAL_GOOD_MASK
#if !((1 << BOOT_HART) & BOOT_MASK)
#error "Bad ACPU partial good configuration!"
#endif
#else /* CONFIG_K1MXLITE_PARTIAL_GOOD */
#define BOOT_HART		DIE0_HART
#define BOOT_MASK		CPU_ALL
#endif /* CONFIG_K1MXLITE_PARTIAL_GOOD */

#ifdef CONFIG_SMP_BOOT
#define MAX_CPU_NUM		CONFIG_K1MXLITE_SMP_CPUS
#else
#define MAX_CPU_NUM		1
#endif

#define CPUS_PER_CLUSTER	4
#define MAX_CPU_CLUSTERS	(MAX_CPU_NUM / CPUS_PER_CLUSTER)

#ifndef __ASSEMBLY__
extern unsigned long k1mxlite_hart_base;
#endif
#define HART_BASE		k1mxlite_hart_base

#ifndef CONFIG_SBI
/* Local programs uses special hart mask */
/* #define HART_ALL		((CPU_TO_MASK(MAX_CPU_NUM)-1) << HART_BASE) */
#endif /* CONFIG_SBI */

#endif /* __CPUS_K1MXLITE_H_INCLUDE__ */
