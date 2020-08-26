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
 * @(#)scsr.h: DUOWEN SysCSR register definitions
 * $Id: scsr.h,v 1.1 2019-09-02 11:12:00 zhenglv Exp $
 */

#ifndef __SCSR_DUOWEN_H_INCLUDE__
#define __SCSR_DUOWEN_H_INCLUDE__

#define AXI_AXSIZE_BYTES		32

#include <target/amba.h>

#define SCSR_REG(offset)		(SCSR_BASE + (offset))
#define SCSR_BOOT_ADDR			SCSR_REG(0x00)
#define SCSR_CORE_ID			SCSR_REG(0x04)
#define SCSR_CLUSTER_ID			SCSR_REG(0x08)
#define SCSR_CLOCK_EN			SCSR_REG(0x0C)
#define SCSR_BOOT_MODE			SCSR_REG(0x10)

/* CORE_ID (offset 0x04) */
#define IMC_CORE_ID_OFFSET		0
#define IMC_CORE_ID_MASK		REG_4BIT_MASK
#define IMC_CORE_ID(value)		_GET_FV(IMC_CORE_ID, value)
/* CLUSTER_ID (offset 0x08) */
#define IMC_CLUSTER_ID_OFFSET		0
#define IMC_CLUSTER_ID_MASK		REG_6BIT_MASK
#define IMC_CLUSTER_ID(value)		_GET_FV(IMC_CLUSTER_ID, value)
/* CLOCK_EN (offset 0x0C) */
#define IMC_CLOCK_EN			_BV(0)
/* BOOT_MODE */
#define IMC_BOOT_MODE_OFFSET		0
#define IMC_BOOT_MODE_MASK		REG_2BIT_MASK
#define IMC_BOOT_MODE(value)		_GET_FV(IMC_BOOT_MODE, value)
#define IMC_BOOT_ROM			0x00
#define IMC_BOOT_FLASH			0x01
#define IMC_BOOT_USE_BOOT_ADDR		0x02
/* FLASH_SEL */
#define IMC_FLASH_SEL_OFFSET		4
#define IMC_FLASH_SEL_MASK		REG_1BIT_MASK
#define IMC_FLASH_SEL(value)		_GET_FV(IMC_FLASH_SEL, value)
#define IMC_FLASH_SPI			0x00
#define IMC_FLASH_SSI			0x01

#define imc_core_id()			\
	IMC_CORE_ID(__raw_readl(SCSR_CORE_ID))
#define imc_cluster_id()		\
	IMC_CLUSTER_ID(__raw_readl(SCSR_CLUSTER_ID))
#define imc_enable_clock()		\
	__raw_setl(IMC_CLOCK_EN, SCSR_CLOCK_EN)
#define imc_disable_clock()		\
	__raw_clearl(IMC_CLOCK_EN, SCSR_CLOCK_EN)
#define imc_boot_flash()			\
	IMC_FLASH_SEL(__raw_readl(SCSR_BOOT_MODE))

#endif /* __SCSR_DUOWEN_H_INCLUDE__ */
