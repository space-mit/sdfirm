/*
 * ZETALOG's Personal COPYRIGHT
 *
 * Copyright (c) 2021
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
 * @(#)mobiveil_rab.h: MobiVeil RapidIO to AXI Bridge (RAB) interface
 * $Id: mobiveil_rab.h,v 1.0 2021-11-02 17:05:00 zhenglv Exp $
 */

#ifndef __MOBIVEIL_RAB_H_INCLUDE__
#define __MOBIVEIL_RAB_H_INCLUDE__

#ifdef CONFIG_RAB_PAGE_2KB
#define RAB_PAGE_SHIFT			11
#endif /* CONFIG_RAB_PAGE_2KB */
#ifdef CONFIG_RAB_PAGE_4KB
#define RAB_PAGE_SHIFT			12
#endif /* CONFIG_RAB_PAGE_4KB */
#define RAB_PAGE_SIZE			_BV(RAB_PAGE_SHIFT)
#define RAB_PAGE_MASK			(RAB_PAGE_SIZE - 1)
#define RAB_ACCESS_SIZE			_BV(RAB_PAGE_SHIFT + 1)
#define RAB_ACCESS_MASK			(RAB_ACCESS_SIZE - 1)
#define RAB_ACCESS(addr)				\
	((RIO_PTR2INT(addr) & ~RAB_ACCESS_MASK) +	\
	 (RIO_PTR2INT(addr) & RAB_PAGE_MASK) +		\
	 RAB_PAGE_SIZE)

#define RAB_REG(offset)			(RAB_BASE + (offset))

#define RAB_GLOBAL_CSR(offset)			RAB_REG(0x20000 + (offset))
#define RAB_INTERRUPT_CSR(offset)		RAB_REG(0x20040 + (offset))
#define RAB_RIO_PIO_ENGINE_CSR(n, offset)	\
	RAB_REG(0x20080 + (offset) + 0x08 * (n))
#define RAB_RIO_ADDRESS_MAPPING_CSR(offset)	\
	RAB_REG(0x20100 + (offset))
#define RAB_AXI_PIO_ENGINE_CSR(n, offset)	\
	RAB_REG(0x20180 + (offset) + 0x08 * (n))
#define RAB_AXI_SLAVE_CSR(n, offset)		\
	RAB_REG(0x201C0 + (offset) + 0x08 * (n))
#define RAB_AXI_MASTER_CSR(n, offset)		\
	RAB_REG(0x201E0 + (offset) + 0x08 * (n))
#define RAB_AXI_ADDRESS_MAPPING_CSR(n, offset)	\
	RAB_REG(0x20100 + (offset) + 0x10 * (n))
#define RAB_DOORBELL_MESSAGE_CSR(offset)	RAB_REG(0x20400 + (offset))

/* RAB Global CSR */
#define RAB_VER				RAB_GLOBAL_CSR(0x00)
#define RAB_CAPA			RAB_GLOBAL_CSR(0x04)
#define RAB_CTRL			RAB_GLOBAL_CSR(0x08)
#define RAB_STAT			RAB_GLOBAL_CSR(0x0C)
#define RAB_AXI_TIMEOUT			RAB_GLOBAL_CSR(0x10)
#define RAB_DME_TIMEOUT			RAB_GLOBAL_CSR(0x14)
#define RAB_RST_CTRL			RAB_GLOBAL_CSR(0x18)
#define RAB_COOP_LOCK			RAB_GLOBAL_CSR(0x1C)
#define RAB_STAT_ESEL			RAB_GLOBAL_CSR(0x20)
#define RAB_STAT_STAT			RAB_GLOBAL_CSR(0x24)
#define RAB_IB_PW_CSR			RAB_GLOBAL_CSR(0x28)
#define RAB_IB_PW_Data			RAB_GLOBAL_CSR(0x2C)
#define RAB_APB_CSR			RAB_GLOBAL_CSR(0x30)
#define RAB_ARB_TIMEOUT			RAB_GLOBAL_CSR(0x34)
#define RAB_DESC_RDY_TIMEOUT		RAB_GLOBAL_CSR(0x38)

/* Interrupt CSR */
#define RAB_INTR_ENAB_GNRL		RAB_INTERRUPT_CSR(0x00)
#define RAB_INTR_ENAB_APIO		RAB_INTERRUPT_CSR(0x04)
#define RAB_INTR_ENAB_RPIO		RAB_INTERRUPT_CSR(0x08)
#define RAB_INTR_ENAB_WDMA		RAB_INTERRUPT_CSR(0x0C)
#define RAB_INTR_ENAB_RDMA		RAB_INTERRUPT_CSR(0x10)
#define RAB_INTR_ENAB_IDME		RAB_INTERRUPT_CSR(0x14)
#define RAB_INTR_ENAB_ODME		RAB_INTERRUPT_CSR(0x18)
#define RAB_INTR_ENAB_MISC		RAB_INTERRUPT_CSR(0x1C)
#define RAB_INTR_STAT_GNRL		RAB_INTERRUPT_CSR(0x20)
#define RAB_INTR_STAT_APIO		RAB_INTERRUPT_CSR(0x24)
#define RAB_INTR_STAT_RPIO		RAB_INTERRUPT_CSR(0x28)
#define RAB_INTR_STAT_WDMA		RAB_INTERRUPT_CSR(0x2C)
#define RAB_INTR_STAT_RDMA		RAB_INTERRUPT_CSR(0x30)
#define RAB_INTR_STAT_IDME		RAB_INTERRUPT_CSR(0x34)
#define RAB_INTR_STAT_ODME		RAB_INTERRUPT_CSR(0x38)
#define RAB_INTR_STAT_MISC		RAB_INTERRUPT_CSR(0x3C)

/* RIO PIO Engine CSR (N = 0~RAB_NUM_RIO_PIO [max 8]) */
#define RAB_RIO_PIO_CTRL(n)		RAB_RIO_PIO_ENGINE_CSR(n, 0x00)
#define RAB_RIO_PIO_STAT(n)		RAB_RIO_PIO_ENGINE_CSR(n, 0x04)

/* RIO Address Mapping CSR */
#define RAB_RIO_AMAP_LUT(n)		RAB_ADDRESS_MAPPING_CSR(0x04 * n)
#define RAB_RIO_AMAP_IDSL		RAB_ADDRESS_MAPPING_CSR(0x40)
#define RAB_RIO_AMAP_BYPS		RAB_ADDRESS_MAPPING_CSR(0x44)

/* AXI PIO Engine CSR (N = 0~RAB_NUM_AXI_PIO [max 8]) */
#define RAB_APIO_N_CTRL(n)		RAB_AXI_PIO_ENGINE_CSR(n, 0x00)
#define RAB_APIO_N_STAT(n)		RAB_AXI_PIO_ENGINE_CSR(n, 0x04)

/* AXI Slave CSR */
#define RAB_ASLV_STAT_CMD(n)		RAB_AXI_SLAVE_CSR(n, 0x00)
#define RAB_ASLV_STAT_ADDR(n)		RAB_AXI_SLAVE_CSR(n, 0x04)

/* AXI Master CSR */
#define RAB_AMST_STAT(n)		RAB_AXI_MASTER_CSR(n, 0x00)

/* AXI Address Mapping CSR (N = 0~RAB_NUM_A2P_AMAP_WIN [max 32] */
#define RAB_APIO_AMAP_CTRL(n)		RAB_AXI_ADDRESS_MAPPING_CSR(n, 0x00)
#define RAB_APIO_AMAP_SIZE(n)		RAB_AXI_ADDRESS_MAPPING_CSR(n, 0x04)
#define RAB_APIO_AMAP_ABAR(n)		RAB_AXI_ADDRESS_MAPPING_CSR(n, 0x08)
#define RAB_APIO_AMAP_RBAR(n)		RAB_AXI_ADDRESS_MAPPING_CSR(n, 0x0C)

/* Doorbell Message CSR */
#define RAB_OB_DB_CSR(n)		RAB_DOORBELL_MESSAGE_CSR(0x08 * (n))
#define RAB_OB_DB_INFO(n)		\
	RAB_DOORBELL_MESSAGE_CSR(0x04 + (0x08 * (n)))
#define RAB_OB_IDB_CSR			RAB_DOORBELL_MESSAGE_CSR(0x78)
#define RAB_OB_IDB_INFO			RAB_DOORBELL_MESSAGE_CSR(0x7C)
#define RAB_IB_DB_CSR			RAB_DOORBELL_MESSAGE_CSR(0x80)
#define RAB_IB_DB_INFO			RAB_DOORBELL_MESSAGE_CSR(0x84)
#define RAB_IB_DB_CHK(n)		\
	RAB_DOORBELL_MESSAGE_CSR(0x88 + (0x04 * (n)))

/* Outbound DME CSR */
#define RAB_OB_DME_CTRL(n)		RAB_OUTBOUND_DME_CSR(n, 0x00)
#define RAB_OB_DME_ADDR(n)		RAB_OUTBOUND_DME_CSR(n, 0x04)
#define RAB_OB_DME_STAT(n)		RAB_OUTBOUND_DME_CSR(n, 0x08)
#define RAB_OB_DME_TIDMSK		RAB_REG(0x205F0)

/* Inbound DME CSR */
#define RAB_IB_DME_CTRL(n)		RAB_INBOUND_DME_CSR(n, 0x00)
#define RAB_IB_DME_ADDR(n)		RAB_INBOUND_DME_CSR(n, 0x04)
#define RAB_IB_DME_STAT(n)		RAB_INBOUND_DME_CSR(n, 0x08)
#define RAB_IB_DME_DESC(n)		RAB_INBOUND_DME_CSR(n, 0x0C)

/* Write DMA CSR */
#define RAB_WDMA_CTRL(n)		RAB_WRITE_DMA_CSR(n, 0x00)
#define RAB_WDMA_ADDR(n)		RAB_WRITE_DMA_CSR(n, 0x04)
#define RAB_WDMA_STAT(n)		RAB_WRITE_DMA_CSR(n, 0x08)
#define RAB_WDMA_ADDR_EXT(n)		RAB_WRITE_DMA_CSR(n, 0x0C)

/* Read DMA CSR */
#define RAB_RDMA_CTRL(n)		RAB_READ_DMA_CSR(n, 0x00)
#define RAB_RDMA_ADDR(n)		RAB_READ_DMA_CSR(n, 0x04)
#define RAB_RDMA_STAT(n)		RAB_READ_DMA_CSR(n, 0x08)
#define RAB_RDMA_ADDR_EXT(n)		RAB_READ_DMA_CSR(n, 0x0C)

/* 19.3.3 Bridge Control Register */
#define RAB_AMBA_PIO_Enable		_BV(0)
#define RAB_RIO_PIO_Enable		_BV(1)
#define RAB_Write_DMA_Enable		_BV(2)
#define RAB_Read_DMA_Enable		_BV(3)
#define RAB_AXI_Byte_Swapping_Select_OFFSET			4
#define RAB_AXI_Byte_Swapping_Select_MASK			REG_2BIT_MASK
#define RAB_AXI_Byte_Swapping_Select(value)			\
	_SET_FV(RAB_AXI_Byte_Swapping_Select, value)
#define RAB_OB_Message_Arbitration_OFFSET			6
#define RAB_OB_Message_Arbitration_MASK				REG_2BIT_MASK
#define RAB_OB_Message_Arbitration(value)			\
	_SET_FV(RAB_OB_Message_Arbitration, value)
#define RAB_Prefetch_Size_of_DMA_Descriptors_Array_OFFSET	8
#define RAB_Prefetch_Size_of_DMA_Descriptors_Array_MASK		REG_2BIT_MASK
#define RAB_Prefetch_Size_of_DMA_Descriptors_Array(value)	\
	_SET_FV(RAB_Prefetch_Size_of_DMA_Descriptors_Array, value)
#define RAB_OB_Response_Priority_Control_OFFSET			10
#define RAB_OB_Response_Priority_Control_MASK			REG_2BIT_MASK
#define RAB_OB_Response_Priority_Control(value)			\
	_SET_FV(RAB_OB_Response_Priority_Control, value)
#define RAB_Message_Descriptor_Memory_Enable			_BV(12)

/* 19.3.13 APB Control & Status Register */
#define RAB_APBKey				_BV(0)
#define RAB_KEY_DEFAULT				0x3A2B
#define RAB_APBPageSelect_OFFSET		16
#ifdef CONFIG_RAB_PAGE_2KB
#define RAB_APBPageSelect_MASK			REG_13BIT_MASK
#endif /* CONFIG_RAB_PAGE_2KB */
#ifdef CONFIG_RAB_PAGE_4KB
#define RAB_APBPageSelect_MASK			REG_12BIT_MASK
#endif /* CONFIG_RAB_PAGE_4KB */
#define RAB_APBPageSelect(value)		\
	_SET_FV(RAB_APBPageSelect, value)
#define RAB_APBGRIOLocked			_BV(29)
#define RAB_APBByteSwappingSelect_OFFSET	30
#define RAB_APBByteSwappingSelect_MASK		REG_2BIT_MASK
#define RAB_APBByteSwappingSelect(value)	\
	_SET_FV(RAB_APBByteSwappingSelect, value)

#define rab_setl(v,a)					\
	do {						\
		uint32_t __v = rab_readl(a);		\
		__v |= (v);				\
		rab_writel(__v, (a));			\
	} while (0)
#define rab_clearl(v,a)					\
	do {						\
		uint32_t __v = rab_readl(a);		\
		__v &= ~(v);				\
		rab_writel(__v, (a));			\
	} while (0)
#define rab_writel_mask(v,m,a)				\
	do {						\
		uint32_t __v = rab_readl(a);		\
		__v &= ~(m);				\
		__v |= (v);				\
		rab_writel(__v, (a));			\
	} while (0)

void rab_init_port(void);
void rab_writel(uint32_t value, caddr_t addr);
uint32_t rab_readl(caddr_t addr);

#endif /* __MOBIVEIL_RAB_H_INCLUDE__ */
