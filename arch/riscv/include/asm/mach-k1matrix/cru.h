
/*
 * ZETALOG's Personal COPYRIGHT
 *
 * Copyright (c) 2024
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
 * @(#)cru.h: k1matrix clock/reset generator definitions
 * $Id: cru.h,v 1.1 2024-06-05 17:37:00 zhenglv Exp $
 */

#ifndef __K1MATRIX_CRU_H_INCLUDE__
#define __K1MATRIX_CRU_H_INCLUDE__

#define CRU_BASE			__RMU_SYS_CRU_BASE
#define SC_PLLTS12FFC_BASE(n)		CRU_REG(0x00C * (n))

#include <driver/sc_pllts12ffclafrac2.h>

#define CRU_REG(offset)			(CRU_BASE + (offset))

#define CRU_COMPLL_CTL			CRU_REG(0x000)
#define CRU_COMPLL_CFG1			CRU_REG(0x004)
#define CRU_COMPLL_CFG2			CRU_REG(0x008)
#define CRU_MESH_PLL_CTL		CRU_REG(0x00C)
#define CRU_MESH_PLL_CFG1		CRU_REG(0x010)
#define CRU_MESH_PLL_CFG2		CRU_REG(0x014)
#define CRU_PERI_PLL_CTL		CRU_REG(0x018)
#define CRU_PERI_PLL_CFG1		CRU_REG(0x01C)
#define CRU_PERI_PLL_CFG2		CRU_REG(0x020)
#define CRU_DDR0_PLL_CTL		CRU_REG(0x024)
#define CRU_DDR0_PLL_CFG1		CRU_REG(0x028)
#define CRU_DDR0_PLL_CFG2		CRU_REG(0x02C)
#define CRU_DDR1_PLL_CTL		CRU_REG(0x030)
#define CRU_DDR1_PLL_CFG1		CRU_REG(0x034)
#define CRU_DDR1_PLL_CFG2		CRU_REG(0x038)
#define CRU_CPU0_PLL_CTL		CRU_REG(0x03C)
#define CRU_CPU0_PLL_CFG1		CRU_REG(0x040)
#define CRU_CPU0_PLL_CFG2		CRU_REG(0x044)
#define CRU_CPU1_PLL_CTL		CRU_REG(0x048)
#define CRU_CPU1_PLL_CFG1		CRU_REG(0x04C)
#define CRU_CPU1_PLL_CFG2		CRU_REG(0x050)
#define CRU_CPU_CLK_CTL			CRU_REG(0x100)
#define CRU_CPU_NIC_CLK_CTL		CRU_REG(0x104)
#define CRU_CPU_HAP_CLK_CTL		CRU_REG(0x108)
#define CRU_PCIE_TOP_CLK_CTL		CRU_REG(0x110)
#define CRU_PCIE_TOP_AUXCLK_CTL		CRU_REG(0x114)
#define CRU_PCIE_TOP_CFGCLK_CTL		CRU_REG(0x118)
#define CRU_PCIE_BOT_CLK_CTL		CRU_REG(0x120)
#define CRU_PCIE_BOT_AUXCLK_CTL		CRU_REG(0x124)
#define CRU_PCIE_BOT_CFGCLK_CTL		CRU_REG(0x128)
#define CRU_PERI_SUB_CLK_CTL		CRU_REG(0x130)
#define CRU_MESH_SUB_CLK_CTL		CRU_REG(0x140)
#define CRU_DDR_SUB_CLK_CTL		CRU_REG(0x150)
#define CRU_CLUSTER0_CLK_CTL		CRU_REG(0x200)
#define CRU_CLUSTER1_CLK_CTL		CRU_REG(0x204)
#define CRU_CLUSTER2_CLK_CTL		CRU_REG(0x208)
#define CRU_CLUSTER3_CLK_CTL		CRU_REG(0x20C)
#define CRU_CLUSTER4_CLK_CTL		CRU_REG(0x210)
#define CRU_CLUSTER5_CLK_CTL		CRU_REG(0x214)
#define CRU_CLUSTER6_CLK_CTL		CRU_REG(0x218)
#define CRU_CLUSTER7_CLK_CTL		CRU_REG(0x21C)
#define CRU_SYS_APB_CLK_CTL		CRU_REG(0x220)
#define CRU_APIC_CLK_CTL		CRU_REG(0x224)
#define CRU_IMSIC_CLK_CTL		CRU_REG(0x228)
#define CRU_CPU_CHI_CLK_CTL		CRU_REG(0x22C)
#define CRU_RMU_AXI_CLK_DIV		CRU_REG(0x300)
#define CRU_RMU_AHB_CLK_DIV		CRU_REG(0x304)
#define CRU_RMU_APB_CLK_DIV		CRU_REG(0x308)
#define CRU_RMU_LPC_CLK_DIV		CRU_REG(0x30C)
#define CRU_RMU_CLK_SEL			CRU_REG(0x310)
#define CRU_RMU_eFuse_NS_CLK_SEL	CRU_REG(0x314)
#define CRU_RMU_SRAM_CLK_EN		CRU_REG(0x320)
#define CRU_RMU_QSPI_CLK_EN		CRU_REG(0x324)
#define CRU_RMU_eFuse_NS_CLK_EN		CRU_REG(0x328)
#define CRU_RMU_STM_CLK_EN		CRU_REG(0x32C)
#define CRU_RMU_LPC_CLK_EN		CRU_REG(0x334)
#define CRU_RMU_eSPI_CLK_EN		CRU_REG(0x338)
#define CRU_RMU_PVTC_CLK_EN		CRU_REG(0x33C)
#define CRU_RMU_UART0_CLK_EN		CRU_REG(0x340)
#define CRU_RMU_UART1_CLK_EN		CRU_REG(0x344)
#define CRU_RMU_Timer_S_CLK_EN		CRU_REG(0x348)
#define CRU_RMU_Spinlock_CLK_EN		CRU_REG(0x34C)
#define CRU_RMU_Mailbox_S_CLK_EN	CRU_REG(0x350)
#define CRU_RMU_Mailbox_NS_CLK_EN	CRU_REG(0x354)
#define CRU_RMU_PIC_CLK_EN		CRU_REG(0x358)
#define CRU_RMU_HAP_CLK_EN		CRU_REG(0x35C)
#define CRU_PCIE0_BUS_CLK_CTL		CRU_REG(0x400)
#define CRU_PCIE1_BUS_CLK_CTL		CRU_REG(0x404)
#define CRU_PCIE2_BUS_CLK_CTL		CRU_REG(0x408)
#define CRU_PCIE3_BUS_CLK_CTL		CRU_REG(0x40C)
#define CRU_PCIE0_AXI_CLK_CTL		CRU_REG(0x410)
#define CRU_PCIE1_AXI_CLK_CTL		CRU_REG(0x414)
#define CRU_PCIE2_AXI_CLK_CTL		CRU_REG(0x418)
#define CRU_PCIE3_AXI_CLK_CTL		CRU_REG(0x41C)
#define CRU_MPHY0_CLK_CTL		CRU_REG(0x420)
#define CRU_MPHY1_CLK_CTL		CRU_REG(0x424)
#define CRU_MPHY2_CLK_CTL		CRU_REG(0x428)
#define CRU_TCU0_CLK_CTL		CRU_REG(0x430)
#define CRU_TCU1_CLK_CTL		CRU_REG(0x434)
#define CRU_PCIE4_BUS_CLK_CTL		CRU_REG(0x600)
#define CRU_PCIE5_BUS_CLK_CTL		CRU_REG(0x604)
#define CRU_PCIE6_BUS_CLK_CTL		CRU_REG(0x608)
#define CRU_PCIE7_BUS_CLK_CTL		CRU_REG(0x60C)
#define CRU_PCIE8_BUS_CLK_CTL		CRU_REG(0x610)
#define CRU_PCIE9_BUS_CLK_CTL		CRU_REG(0x614)
#define CRU_PCIE4_AUX_CLK_CTL		CRU_REG(0x618)
#define CRU_PCIE5_AUX_CLK_CTL		CRU_REG(0x61C)
#define CRU_PCIE6_AUX_CLK_CTL		CRU_REG(0x620)
#define CRU_PCIE7_AUX_CLK_CTL		CRU_REG(0x624)
#define CRU_PCIE8_AUX_CLK_CTL		CRU_REG(0x628)
#define CRU_PCIE9_AUX_CLK_CTL		CRU_REG(0x62C)
#define CRU_PCIE_TCU2_CLK_CTL		CRU_REG(0x630)
#define CRU_PCIE_SUBLINK_CLK_CTL	CRU_REG(0x634)
#define CRU_PCIE_SYS_CLK_CTL		CRU_REG(0x638)
#define CRU_COMBPHY3_CLK_CTL		CRU_REG(0x63C)
#define CRU_COMBPHY4_CLK_CTL		CRU_REG(0x640)
#define CRU_COMBPHY5_CLK_CTL		CRU_REG(0x644)
#define	CRU_PERI_AHB_CLK_CTL		CRU_REG(0x810)
#define	CRU_PERI_SPI0_CLK_CTL		CRU_REG(0x820)
#define	CRU_PERI_SPI1_CLK_CTL		CRU_REG(0x824)
#define	CRU_PERI_SPI2_CLK_CTL		CRU_REG(0x828)
#define	CRU_PERI_SPI3_CLK_CTL		CRU_REG(0x82C)
#define	CRU_PERI_SMBUS0_CLK_CTL		CRU_REG(0x840)
#define	CRU_PERI_SMBUS1_CLK_CTL		CRU_REG(0x844)
#define CRU_PERI_I3C0_CLK_CTL		CRU_REG(0x860)
#define CRU_PERI_I3C1_CLK_CTL		CRU_REG(0x864)
#define CRU_PERI_I2C0_CLK_CTL		CRU_REG(0x880)
#define CRU_PERI_I2C1_CLK_CTL		CRU_REG(0x884)
#define CRU_PERI_I2C2_CLK_CTL		CRU_REG(0x888)
#define CRU_PERI_I2C3_CLK_CTL		CRU_REG(0x88C)
#define CRU_PERI_I2C4_CLK_CTL		CRU_REG(0x890)
#define CRU_PERI_I2C5_CLK_CTL		CRU_REG(0x894)
#define CRU_PERI_UART0_CLK_CTL		CRU_REG(0x8A0)
#define CRU_PERI_UART1_CLK_CTL		CRU_REG(0x8A4)
#define CRU_PERI_UART2_CLK_CTL		CRU_REG(0x8A8)
#define CRU_PERI_UART3_CLK_CTL		CRU_REG(0x8AC)
#define CRU_PERI_GPIO0_CLK_CTL		CRU_REG(0x8C0)
#define CRU_PERI_GPIO1_CLK_CTL		CRU_REG(0x8C4)
#define CRU_PERI_GPIO2_CLK_CTL		CRU_REG(0x8C8)
#define CRU_PERI_GPIO3_CLK_CTL		CRU_REG(0x8CC)
#define CRU_PERI_GPIO4_CLK_CTL		CRU_REG(0x8D0)
#define CRU_PERI_WDT0_CLK_CTL		CRU_REG(0x8E0)
#define CRU_PERI_WDT1_CLK_CTL		CRU_REG(0x8E4)
#define CRU_PERI_WDT2_CLK_CTL		CRU_REG(0x8E8)
#define CRU_PERI_WDT3_CLK_CTL		CRU_REG(0x8EC)
#define CRU_PERI_WDT4_CLK_CTL		CRU_REG(0x8F0)
#define CRU_PERI_WDT5_CLK_CTL		CRU_REG(0x8F4)
#define CRU_PERI_WDT6_CLK_CTL		CRU_REG(0x8F8)
#define CRU_PERI_WDT7_CLK_CTL		CRU_REG(0x8FC)
#define CRU_PERI_TIMER0_CLK_CTL		CRU_REG(0x900)
#define CRU_PERI_TIMER1_CLK_CTL		CRU_REG(0x904)
#define CRU_PERI_TIMER2_CLK_CTL		CRU_REG(0x908)
#define CRU_PERI_TIMER3_CLK_CTL		CRU_REG(0x90C)
#define CRU_PERI_TIMER4_CLK_CTL		CRU_REG(0x910)
#define CRU_PERI_TIMER5_CLK_CTL		CRU_REG(0x914)
#define CRU_PERI_TIMER6_CLK_CTL		CRU_REG(0x918)
#define CRU_PERI_TIMER7_CLK_CTL		CRU_REG(0x91C)
#define CRU_PERI_TIMER8_CLK_CTL		CRU_REG(0x920)
#define CRU_PERI_TIMER9_CLK_CTL		CRU_REG(0x924)
#define CRU_PERI_TIMER10_CLK_CTL	CRU_REG(0x928)
#define CRU_PERI_TIMER11_CLK_CTL	CRU_REG(0x92C)
#define CRU_PERI_TIMER12_CLK_CTL	CRU_REG(0x930)
#define CRU_PERI_TIMER13_CLK_CTL	CRU_REG(0x934)
#define CRU_PERI_TIMER14_CLK_CTL	CRU_REG(0x938)
#define CRU_PERI_TIMER15_CLK_CTL	CRU_REG(0x93C)
#define CRU_PERI_TIMER16_CLK_CTL	CRU_REG(0x940)
#define CRU_PERI_TIMER17_CLK_CTL	CRU_REG(0x944)
#define CRU_PERI_TIMER18_CLK_CTL	CRU_REG(0x948)
#define CRU_PERI_TIMER19_CLK_CTL	CRU_REG(0x94C)
#define CRU_PERI_TIMER20_CLK_CTL	CRU_REG(0x950)
#define CRU_PERI_TIMER21_CLK_CTL	CRU_REG(0x954)
#define CRU_PERI_TIMER22_CLK_CTL	CRU_REG(0x958)
#define CRU_PERI_TIMER23_CLK_CTL	CRU_REG(0x95C)
#define CRU_PERI_TIMER24_CLK_CTL	CRU_REG(0x960)
#define CRU_PERI_TIMER25_CLK_CTL	CRU_REG(0x964)
#define CRU_PERI_TIMER26_CLK_CTL	CRU_REG(0x968)
#define CRU_PERI_TIMER27_CLK_CTL	CRU_REG(0x96C)
#define CRU_PERI_TIMER28_CLK_CTL	CRU_REG(0x970)
#define CRU_PERI_TIMER29_CLK_CTL	CRU_REG(0x974)
#define CRU_PERI_TIMER30_CLK_CTL	CRU_REG(0x978)
#define CRU_PERI_TIMER31_CLK_CTL	CRU_REG(0x97C)
#define CRU_PERI_DMAC_CLK_CTL		CRU_REG(0x9C0)
#define CRU_PERI_GMAC_CLK_CTL		CRU_REG(0x9E0)
#define CRU_CPU_SUB_SW_RESET		CRU_REG(0x2100)
#define CRU_PCIE_TOP_SW_RESET		CRU_REG(0x2104)
#define CRU_PCIE_BOT_SW_RESET		CRU_REG(0x2108)
#define CRU_PERI_SUB_SW_RESET		CRU_REG(0x210C)
#define CRU_MESH_SUB_SW_RESET		CRU_REG(0x2110)
#define CRU_DDR_SUB_SW_RESET		CRU_REG(0x2114)
#define CRU_CLUSTER0_SW_RESET		CRU_REG(0x2200)
#define	CRU_CLUSTER0_COREX_SW_RESET	CRU_REG(0x2204)
#define CRU_CLUSTER1_SW_RESET		CRU_REG(0x2208)
#define CRU_CLUSTER1_COREX_SW_RESET     CRU_REG(0x220C)
#define CRU_CLUSTER2_SW_RESET           CRU_REG(0x2210)
#define CRU_CLUSTER2_COREX_SW_RESET     CRU_REG(0x2214)
#define CRU_CLUSTER3_SW_RESET           CRU_REG(0x2218)
#define CRU_CLUSTER3_COREX_SW_RESET     CRU_REG(0x221C)
#define CRU_CLUSTER4_SW_RESET           CRU_REG(0x2220)
#define CRU_CLUSTER4_COREX_SW_RESET     CRU_REG(0x2224)
#define CRU_CLUSTER5_SW_RESET           CRU_REG(0x2228)
#define CRU_CLUSTER5_COREX_SW_RESET     CRU_REG(0x222C)
#define CRU_CLUSTER6_SW_RESET           CRU_REG(0x2230)
#define CRU_CLUSTER6_COREX_SW_RESET     CRU_REG(0x2234)
#define CRU_CLUSTER7_SW_RESET           CRU_REG(0x2238)
#define CRU_CLUSTER7_COREX_SW_RESET     CRU_REG(0x223C)

#define CRU_CPU_RAS_SW_RESET            CRU_REG(0x2240)
#define CRU_CPU_SW_RESET		CRU_REG(0X2250)
#define CRU_RMU_SRAM_SW_RSTN		CRU_REG(0x2320)
#define CRU_RMU_QSPI_SW_RSTN		CRU_REG(0x2324)
#define CRU_RMU_eFuse_NS_SW_RSTN	CRU_REG(0x2328)
#define CRU_RMU_LPC_SW_RSTN		CRU_REG(0x2334)
#define CRU_RMU_eSPI_SW_RSTN		CRU_REG(0x2338)
#define CRU_RMU_PVTC_SW_RSTN		CRU_REG(0x233C)
#define CRU_RMU_UART0_SW_RSTN		CRU_REG(0x2340)
#define CRU_RMU_UART1_SW_RSTN		CRU_REG(0x2344)
#define CRU_RMU_Timer_S_SW_RSTN		CRU_REG(0x2348)
#define CRU_RMU_Spinlock_SW_RSTN	CRU_REG(0x234C)
#define CRU_RMU_Mailbox_S_SW_RSTN	CRU_REG(0x2350)
#define CRU_RMU_Mailbox_NS_SW_RSTN	CRU_REG(0x2354)
#define CRU_RMU_PIC_SW_RSTN		CRU_REG(0x2358)
#define CRU_PCIE0_SW_RESET		CRU_REG(0x2400)
#define CRU_PCIE1_SW_RESET		CRU_REG(0x2404)
#define CRU_PCIE2_SW_RESET		CRU_REG(0x2408)
#define CRU_PCIE3_SW_RESET		CRU_REG(0x240C)
#define CRU_MPHY0_SW_RESET		CRU_REG(0x2420)
#define CRU_MPHY1_SW_RESET		CRU_REG(0x2424)
#define CRU_MPHY2_SW_RESET		CRU_REG(0x2428)
#define CRU_TCU0_SW_RESET		CRU_REG(0x2430)
#define CRU_TCU1_SW_RESET		CRU_REG(0x2434)
#define CRU_PCIE4_SW_RESET		CRU_REG(0x2600)
#define CRU_PCIE5_SW_RESET		CRU_REG(0x2604)
#define CRU_PCIE6_SW_RESET		CRU_REG(0x2608)
#define CRU_PCIE7_SW_RESET		CRU_REG(0x260C)
#define CRU_PCIE8_SW_RESET		CRU_REG(0x2610)
#define CRU_PCIE9_SW_RESET		CRU_REG(0x2614)
#define CRU_PCIE_TCU2_SW_RESET		CRU_REG(0x2634)
#define CRU_PCIE_SUBLINK_SW_RESET	CRU_REG(0x2638)
#define CRU_PCIE_SYS_SW_RESET		CRU_REG(0x263C)
#define CRU_COMBPHY3_APB_SW_RESET	CRU_REG(0x2640)
#define CRU_COMBPHY4_APB_SW_RESET	CRU_REG(0x2644)
#define CRU_COMBPHY5_APB_SW_RESET	CRU_REG(0x2648)
#define CRU_COMBPHY3_PHYRESETN_SW_RESET	CRU_REG(0x264C)
#define CRU_COMBPHY4_PHYRESETN_SW_RESET	CRU_REG(0x2650)
#define CRU_COMBPHY5_PHYRESETN_SW_RESET	CRU_REG(0x2654)
#define CRU_PERI_SPI0_SW_RESET		CRU_REG(0x2820)
#define CRU_PERI_SPI1_SW_RESET		CRU_REG(0x2824)
#define CRU_PERI_SPI2_SW_RESET		CRU_REG(0x2828)
#define CRU_PERI_SPI3_SW_RESET		CRU_REG(0x282C)
#define CRU_PERI_SMBUS0_SW_RESET	CRU_REG(0x2840)
#define CRU_PERI_SMBUS1_SW_RESET	CRU_REG(0x2844)
#define CRU_PERI_I3C0_SW_RESET		CRU_REG(0x2860)
#define CRU_PERI_I3C1_SW_RESET		CRU_REG(0x2864)
#define CRU_PERI_I2C0_SW_RESET		CRU_REG(0x2880)
#define CRU_PERI_I2C1_SW_RESET		CRU_REG(0x2884)
#define CRU_PERI_I2C2_SW_RESET		CRU_REG(0x2888)
#define CRU_PERI_I2C3_SW_RESET		CRU_REG(0x288C)
#define CRU_PERI_I2C4_SW_RESET		CRU_REG(0x2890)
#define CRU_PERI_I2C5_SW_RESET		CRU_REG(0x2894)
#define CRU_PERI_UART0_SW_RESET		CRU_REG(0x28A0)
#define CRU_PERI_UART1_SW_RESET		CRU_REG(0x28A4)
#define CRU_PERI_UART2_SW_RESET		CRU_REG(0x28A8)
#define CRU_PERI_UART3_SW_RESET		CRU_REG(0x28AC)
#define CRU_PERI_GPIO0_SW_RESET		CRU_REG(0x28C0)
#define CRU_PERI_GPIO1_SW_RESET		CRU_REG(0x28C4)
#define CRU_PERI_GPIO2_SW_RESET		CRU_REG(0x28C8)
#define CRU_PERI_GPIO3_SW_RESET		CRU_REG(0x28CC)
#define CRU_PERI_GPIO4_SW_RESET		CRU_REG(0x28D0)
#define CRU_PERI_WDT0_SW_RESET		CRU_REG(0x28E0)
#define CRU_PERI_WDT1_SW_RESET		CRU_REG(0x28E4)
#define CRU_PERI_WDT2_SW_RESET		CRU_REG(0x28E8)
#define CRU_PERI_WDT3_SW_RESET		CRU_REG(0x28EC)
#define CRU_PERI_WDT4_SW_RESET		CRU_REG(0x28F0)
#define CRU_PERI_WDT5_SW_RESET		CRU_REG(0x28F4)
#define CRU_PERI_WDT6_SW_RESET		CRU_REG(0x28F8)
#define CRU_PERI_WDT7_SW_RESET		CRU_REG(0x28FC)
#define CRU_PERI_GTIMER0_SW_RESET	CRU_REG(0x2900)
#define CRU_PERI_GTIMER1_SW_RESET	CRU_REG(0x2920)
#define CRU_PERI_GTIMER2_SW_RESET	CRU_REG(0x2940)
#define CRU_PERI_GTIMER3_SW_RESET	CRU_REG(0x2960)
#define CRU_PERI_DMAC_SW_RESET		CRU_REG(0x29C0)
#define CRU_PERI_GMAC_SW_RESET		CRU_REG(0x29E0)
#define CRU_PERI_TBU_SW_RESET		CRU_REG(0x29F0)
#define CRU_PERI_TBU_ADB_SW_RESET	CRU_REG(0x29F4)

#ifdef CONFIG_K1MATRIX_64C

#define CRU_COMPLL_CTL			CRU_REG(0x000)
#define CRU_COMPLL_CFG1			CRU_REG(0x004)
#define CRU_COMPLL_CFG2			CRU_REG(0x008)
#define CRU_MESH_PLL_CTL		CRU_REG(0x00C)
#define CRU_MESH_PLL_CFG1		CRU_REG(0x010)
#define CRU_MESH_PLL_CFG2		CRU_REG(0x014)
#define CRU_PERI_PLL_CTL		CRU_REG(0x018)
#define CRU_PERI_PLL_CFG1		CRU_REG(0x01C)
#define CRU_PERI_PLL_CFG2		CRU_REG(0x020)
#define CRU_DDR0_PLL_CTL		CRU_REG(0x024)
#define CRU_DDR0_PLL_CFG1		CRU_REG(0x028)
#define CRU_DDR0_PLL_CFG2		CRU_REG(0x02C)
#define CRU_DDR1_PLL_CTL		CRU_REG(0x030)
#define CRU_DDR1_PLL_CFG1		CRU_REG(0x034)
#define CRU_DDR1_PLL_CFG2		CRU_REG(0x038)
#define CRU_CPU0_PLL_CTL		CRU_REG(0x03C)
#define CRU_CPU0_PLL_CFG1		CRU_REG(0x040)
#define CRU_CPU0_PLL_CFG2		CRU_REG(0x044)
#define CRU_CPU1_PLL_CTL		CRU_REG(0x048)
#define CRU_CPU1_PLL_CFG1		CRU_REG(0x04C)
#define CRU_CPU1_PLL_CFG2		CRU_REG(0x050)
#define CRU_CPU_CLK_CTL			CRU_REG(0x100)
#define CRU_CPU_NIC_CLK_CTL		CRU_REG(0x104)
#define CRU_CPU_HAP_CLK_CTL		CRU_REG(0x108)

#define CRU_LTOP_CFG_CLK_CTL		CRU_REG(0x110)
#define CRU_LTOP_PCIE_CFG_CLK_CTL	CRU_REG(0x120)
#define CRU_LTOP_PCIE_AUX_CLK_CTL	CRU_REG(0x124)
#define CRU_LTOP_PCIE_TFR_CLK_CTL	CRU_REG(0x128)
#define CRU_LTOP_PHY_FW_CLK_CTL		CRU_REG(0x12C)
#define CRU_RTOP_CFG_CLK_CTL		CRU_REG(0x130)
#define CRU_RTOP_PCIE_CFG_CLK_CTL	CRU_REG(0x134)
#define CRU_RTOP_PCIE_AUX_CLK_CTL	CRU_REG(0x138)
#define CRU_RTOP_PCIE_TFR_CLK_CTL	CRU_REG(0x13C)
#define CRU_RTOP_PHY_FW_CLK_CTL		CRU_REG(0x140)
#define CRU_BOT_CFG_CLK_CTL		CRU_REG(0x144)
#define CRU_BOT_PCIE_CFG_CLK_CTL	CRU_REG(0x148)
#define CRU_BOT_PCIE_AUX_CLK_CTL	CRU_REG(0x14C)
#define CRU_BOT_PCIE_TFR_CLK_CTL	CRU_REG(0x150)
#define CRU_BOT_PHY_FW_CLK_CTL		CRU_REG(0x154)
#define CRU_TPERI_SUB_SCLK_CTL		CRU_REG(0x158)
#define CRU_TPERI_SUB_MCLK_CTL		CRU_REG(0x15C)
#define CRU_MESH_SUB_CLK_CTL		CRU_REG(0x160)
#define CRU_DDR_CFG_CLK_CTL		CRU_REG(0x170)
#define CRU_DDR_SUB_CLK_CTL		CRU_REG(0x174)
#define CRU_DDRAB_SUB_CLK_CTL		CRU_REG(0x178)
#define CRU_DDRCD_SUB_CLK_CTL		CRU_REG(0x17C)
#define CRU_DDREF_SUB_CLK_CTL		CRU_REG(0x180)
#define CRU_DDRGH_SUB_CLK_CTL		CRU_REG(0x184)
#define CRU_TRMU_IOPMP_CFG_CLK_CTL	CRU_REG(0x188)
#define CRU_HNI_PERI_CFG_CLK_CTL	CRU_REG(0x190)
#define CRU_CLUSTER0_CLK_CTL		CRU_REG(0x200)
#define CRU_CLUSTER1_CLK_CTL		CRU_REG(0x204)
#define CRU_CLUSTER2_CLK_CTL		CRU_REG(0x208)
#define CRU_CLUSTER3_CLK_CTL		CRU_REG(0x20C)
#define CRU_CLUSTER4_CLK_CTL		CRU_REG(0x210)
#define CRU_CLUSTER5_CLK_CTL		CRU_REG(0x214)
#define CRU_CLUSTER6_CLK_CTL		CRU_REG(0x218)
#define CRU_CLUSTER7_CLK_CTL		CRU_REG(0x21C)
#define CRU_CLUSTER8_CLK_CTL		CRU_REG(0x220)
#define CRU_CLUSTER9_CLK_CTL		CRU_REG(0x224)
#define CRU_CLUSTER10_CLK_CTL		CRU_REG(0x228)
#define CRU_CLUSTER11_CLK_CTL		CRU_REG(0x22C)
#define CRU_CLUSTER12_CLK_CTL		CRU_REG(0x230)
#define CRU_CLUSTER13_CLK_CTL		CRU_REG(0x234)
#define CRU_CLUSTER14_CLK_CTL		CRU_REG(0x238)
#define CRU_CLUSTER15_CLK_CTL		CRU_REG(0x23C)
#define CRU_SYS_APB_CLK_CTL		CRU_REG(0x240)
#define CRU_APIC_CLK_CTL		CRU_REG(0x244)
#define CRU_IMSIC_CLK_CTL		CRU_REG(0x248)
#define CRU_MESH_CXS40_CLK_CTL		CRU_REG(0x24C)
#define CRU_MESH_CXS360_CLK_CTL		CRU_REG(0x250)
#define CRU_RMU_AXI_CLK_DIV		CRU_REG(0x300)
#define CRU_RMU_AHB_CLK_DIV		CRU_REG(0x304)
#define CRU_RMU_APB_CLK_DIV		CRU_REG(0x308)
#define CRU_RMU_LPC_CLK_DIV		CRU_REG(0x30C)
#define CRU_RMU_CLK_SEL			CRU_REG(0x310)
#define CRU_RMU_PVTC_CLK_SEL		CRU_REG(0x314)
#define CRU_RMU_SRAM_CLK_EN		CRU_REG(0x320)
#define CRU_RMU_QSPI_CLK_EN		CRU_REG(0x324)
#define CRU_RMU_eFuse_NS_CLK_EN		CRU_REG(0x328)
#define CRU_RMU_LPC_IO_CLK_CTL		CRU_REG(0x32C)
#define CRU_RMU_LPC_LCLK_CTL		CRU_REG(0x330)
#define CRU_RMU_LPC_CLK_EN		CRU_REG(0x334)
#define CRU_RMU_eSPI_CLK_EN		CRU_REG(0x338)
#define CRU_RMU_UART0_CLK_EN		CRU_REG(0x33C)
#define CRU_RMU_UART1_CLK_EN		CRU_REG(0x340)
#define CRU_RMU_UART2_CLK_EN		CRU_REG(0x344)
#define CRU_RMU_Timer_S_CLK_EN		CRU_REG(0x348)
#define CRU_RMU_Spinlock_CLK_EN		CRU_REG(0x34C)
#define CRU_RMU_Mailbox_S_CLK_EN	CRU_REG(0x350)
#define CRU_RMU_Mailbox_NS_CLK_EN	CRU_REG(0x354)
#define CRU_RMU_SRAM_MAILBOX_S_CLK_EN	CRU_REG(0x358)
#define CRU_RMU_SRAM_MAILBOX_NS_CLK_EN	CRU_REG(0x35C)


#define CRU_RMU_PIC_CLK_EN		CRU_REG(0x358)
#define CRU_RMU_HAP_CLK_EN		CRU_REG(0x35C)
#define CRU_PCIE0_BUS_CLK_CTL		CRU_REG(0x400)
#define CRU_PCIE1_BUS_CLK_CTL		CRU_REG(0x404)
#define CRU_PCIE2_BUS_CLK_CTL		CRU_REG(0x408)
#define CRU_PCIE3_BUS_CLK_CTL		CRU_REG(0x40C)
#define CRU_PCIE0_AXI_CLK_CTL		CRU_REG(0x410)
#define CRU_PCIE1_AXI_CLK_CTL		CRU_REG(0x414)
#define CRU_PCIE2_AXI_CLK_CTL		CRU_REG(0x418)
#define CRU_PCIE3_AXI_CLK_CTL		CRU_REG(0x41C)
#define CRU_MPHY0_CLK_CTL		CRU_REG(0x420)
#define CRU_MPHY1_CLK_CTL		CRU_REG(0x424)
#define CRU_MPHY2_CLK_CTL		CRU_REG(0x428)
#define CRU_TCU0_CLK_CTL		CRU_REG(0x430)
#define CRU_TCU1_CLK_CTL		CRU_REG(0x434)
#define CRU_PCIE4_BUS_CLK_CTL		CRU_REG(0x600)
#define CRU_PCIE5_BUS_CLK_CTL		CRU_REG(0x604)
#define CRU_PCIE6_BUS_CLK_CTL		CRU_REG(0x608)
#define CRU_PCIE7_BUS_CLK_CTL		CRU_REG(0x60C)
#define CRU_PCIE8_BUS_CLK_CTL		CRU_REG(0x610)
#define CRU_PCIE9_BUS_CLK_CTL		CRU_REG(0x614)
#define CRU_PCIE4_AUX_CLK_CTL		CRU_REG(0x618)
#define CRU_PCIE5_AUX_CLK_CTL		CRU_REG(0x61C)
#define CRU_PCIE6_AUX_CLK_CTL		CRU_REG(0x620)
#define CRU_PCIE7_AUX_CLK_CTL		CRU_REG(0x624)
#define CRU_PCIE8_AUX_CLK_CTL		CRU_REG(0x628)
#define CRU_PCIE9_AUX_CLK_CTL		CRU_REG(0x62C)
#define CRU_PCIE_TCU2_CLK_CTL		CRU_REG(0x630)
#define CRU_PCIE_SUBLINK_CLK_CTL	CRU_REG(0x634)
#define CRU_PCIE_SYS_CLK_CTL		CRU_REG(0x638)
#define CRU_COMBPHY3_CLK_CTL		CRU_REG(0x63C)
#define CRU_COMBPHY4_CLK_CTL		CRU_REG(0x640)
#define CRU_COMBPHY5_CLK_CTL		CRU_REG(0x644)
#define	CRU_PERI_AHB_CLK_CTL		CRU_REG(0x810)
#define	CRU_PERI_SPI0_CLK_CTL		CRU_REG(0x820)
#define	CRU_PERI_SPI1_CLK_CTL		CRU_REG(0x824)
#define	CRU_PERI_SPI2_CLK_CTL		CRU_REG(0x828)
#define	CRU_PERI_SPI3_CLK_CTL		CRU_REG(0x82C)
#define	CRU_PERI_SMBUS0_CLK_CTL		CRU_REG(0x840)
#define	CRU_PERI_SMBUS1_CLK_CTL		CRU_REG(0x844)
#define CRU_PERI_I3C0_CLK_CTL		CRU_REG(0x860)
#define CRU_PERI_I3C1_CLK_CTL		CRU_REG(0x864)
#define CRU_PERI_I2C0_CLK_CTL		CRU_REG(0x880)
#define CRU_PERI_I2C1_CLK_CTL		CRU_REG(0x884)
#define CRU_PERI_I2C2_CLK_CTL		CRU_REG(0x888)
#define CRU_PERI_I2C3_CLK_CTL		CRU_REG(0x88C)
#define CRU_PERI_I2C4_CLK_CTL		CRU_REG(0x890)
#define CRU_PERI_I2C5_CLK_CTL		CRU_REG(0x894)
#define CRU_PERI_UART0_CLK_CTL		CRU_REG(0x8A0)
#define CRU_PERI_UART1_CLK_CTL		CRU_REG(0x8A4)
#define CRU_PERI_UART2_CLK_CTL		CRU_REG(0x8A8)
#define CRU_PERI_UART3_CLK_CTL		CRU_REG(0x8AC)
#define CRU_PERI_GPIO0_CLK_CTL		CRU_REG(0x8C0)
#define CRU_PERI_GPIO1_CLK_CTL		CRU_REG(0x8C4)
#define CRU_PERI_GPIO2_CLK_CTL		CRU_REG(0x8C8)
#define CRU_PERI_GPIO3_CLK_CTL		CRU_REG(0x8CC)
#define CRU_PERI_GPIO4_CLK_CTL		CRU_REG(0x8D0)
#define CRU_PERI_WDT0_CLK_CTL		CRU_REG(0x8E0)
#define CRU_PERI_WDT1_CLK_CTL		CRU_REG(0x8E4)
#define CRU_PERI_WDT2_CLK_CTL		CRU_REG(0x8E8)
#define CRU_PERI_WDT3_CLK_CTL		CRU_REG(0x8EC)
#define CRU_PERI_WDT4_CLK_CTL		CRU_REG(0x8F0)
#define CRU_PERI_WDT5_CLK_CTL		CRU_REG(0x8F4)
#define CRU_PERI_WDT6_CLK_CTL		CRU_REG(0x8F8)
#define CRU_PERI_WDT7_CLK_CTL		CRU_REG(0x8FC)
#define CRU_PERI_TIMER0_CLK_CTL		CRU_REG(0x900)
#define CRU_PERI_TIMER1_CLK_CTL		CRU_REG(0x904)
#define CRU_PERI_TIMER2_CLK_CTL		CRU_REG(0x908)
#define CRU_PERI_TIMER3_CLK_CTL		CRU_REG(0x90C)
#define CRU_PERI_TIMER4_CLK_CTL		CRU_REG(0x910)
#define CRU_PERI_TIMER5_CLK_CTL		CRU_REG(0x914)
#define CRU_PERI_TIMER6_CLK_CTL		CRU_REG(0x918)
#define CRU_PERI_TIMER7_CLK_CTL		CRU_REG(0x91C)
#define CRU_PERI_TIMER8_CLK_CTL		CRU_REG(0x920)
#define CRU_PERI_TIMER9_CLK_CTL		CRU_REG(0x924)
#define CRU_PERI_TIMER10_CLK_CTL	CRU_REG(0x928)
#define CRU_PERI_TIMER11_CLK_CTL	CRU_REG(0x92C)
#define CRU_PERI_TIMER12_CLK_CTL	CRU_REG(0x930)
#define CRU_PERI_TIMER13_CLK_CTL	CRU_REG(0x934)
#define CRU_PERI_TIMER14_CLK_CTL	CRU_REG(0x938)
#define CRU_PERI_TIMER15_CLK_CTL	CRU_REG(0x93C)
#define CRU_PERI_TIMER16_CLK_CTL	CRU_REG(0x940)
#define CRU_PERI_TIMER17_CLK_CTL	CRU_REG(0x944)
#define CRU_PERI_TIMER18_CLK_CTL	CRU_REG(0x948)
#define CRU_PERI_TIMER19_CLK_CTL	CRU_REG(0x94C)
#define CRU_PERI_TIMER20_CLK_CTL	CRU_REG(0x950)
#define CRU_PERI_TIMER21_CLK_CTL	CRU_REG(0x954)
#define CRU_PERI_TIMER22_CLK_CTL	CRU_REG(0x958)
#define CRU_PERI_TIMER23_CLK_CTL	CRU_REG(0x95C)
#define CRU_PERI_TIMER24_CLK_CTL	CRU_REG(0x960)
#define CRU_PERI_TIMER25_CLK_CTL	CRU_REG(0x964)
#define CRU_PERI_TIMER26_CLK_CTL	CRU_REG(0x968)
#define CRU_PERI_TIMER27_CLK_CTL	CRU_REG(0x96C)
#define CRU_PERI_TIMER28_CLK_CTL	CRU_REG(0x970)
#define CRU_PERI_TIMER29_CLK_CTL	CRU_REG(0x974)
#define CRU_PERI_TIMER30_CLK_CTL	CRU_REG(0x978)
#define CRU_PERI_TIMER31_CLK_CTL	CRU_REG(0x97C)
#define CRU_PERI_DMAC_CLK_CTL		CRU_REG(0x9C0)
#define CRU_PERI_GMAC_CLK_CTL		CRU_REG(0x9E0)
#define CRU_CPU_SUB_SW_RESET		CRU_REG(0x2100)
#define CRU_PCIE_TOP_SW_RESET		CRU_REG(0x2104)
#define CRU_PCIE_BOT_SW_RESET		CRU_REG(0x2108)
#define CRU_PERI_SUB_SW_RESET		CRU_REG(0x210C)
#define CRU_MESH_SUB_SW_RESET		CRU_REG(0x2110)
#define CRU_DDR_SUB_SW_RESET		CRU_REG(0x2114)
#define CRU_CLUSTER0_SW_RESET		CRU_REG(0x2200)
#define	CRU_CLUSTER0_COREX_SW_RESET	CRU_REG(0x2204)
#define CRU_CLUSTER1_SW_RESET		CRU_REG(0x2208)
#define CRU_CLUSTER1_COREX_SW_RESET     CRU_REG(0x220C)
#define CRU_CLUSTER2_SW_RESET           CRU_REG(0x2210)
#define CRU_CLUSTER2_COREX_SW_RESET     CRU_REG(0x2214)
#define CRU_CLUSTER3_SW_RESET           CRU_REG(0x2218)
#define CRU_CLUSTER3_COREX_SW_RESET     CRU_REG(0x221C)
#define CRU_CLUSTER4_SW_RESET           CRU_REG(0x2220)
#define CRU_CLUSTER4_COREX_SW_RESET     CRU_REG(0x2224)
#define CRU_CLUSTER5_SW_RESET           CRU_REG(0x2228)
#define CRU_CLUSTER5_COREX_SW_RESET     CRU_REG(0x222C)
#define CRU_CLUSTER6_SW_RESET           CRU_REG(0x2230)
#define CRU_CLUSTER6_COREX_SW_RESET     CRU_REG(0x2234)
#define CRU_CLUSTER7_SW_RESET           CRU_REG(0x2238)
#define CRU_CLUSTER7_COREX_SW_RESET     CRU_REG(0x223C)

#define CRU_CPU_RAS_SW_RESET            CRU_REG(0x2240)
#define CRU_CPU_SW_RESET		CRU_REG(0X2250)
#define CRU_RMU_SRAM_SW_RSTN		CRU_REG(0x2320)
#define CRU_RMU_QSPI_SW_RSTN		CRU_REG(0x2324)
#define CRU_RMU_eFuse_NS_SW_RSTN	CRU_REG(0x2328)
#define CRU_RMU_LPC_SW_RSTN		CRU_REG(0x2334)
#define CRU_RMU_eSPI_SW_RSTN		CRU_REG(0x2338)
#define CRU_RMU_PVTC_SW_RSTN		CRU_REG(0x233C)
#define CRU_RMU_UART0_SW_RSTN		CRU_REG(0x2340)
#define CRU_RMU_UART1_SW_RSTN		CRU_REG(0x2344)
#define CRU_RMU_Timer_S_SW_RSTN		CRU_REG(0x2348)
#define CRU_RMU_Spinlock_SW_RSTN	CRU_REG(0x234C)
#define CRU_RMU_Mailbox_S_SW_RSTN	CRU_REG(0x2350)
#define CRU_RMU_Mailbox_NS_SW_RSTN	CRU_REG(0x2354)
#define CRU_RMU_PIC_SW_RSTN		CRU_REG(0x2358)
#define CRU_PCIE0_SW_RESET		CRU_REG(0x2400)
#define CRU_PCIE1_SW_RESET		CRU_REG(0x2404)
#define CRU_PCIE2_SW_RESET		CRU_REG(0x2408)
#define CRU_PCIE3_SW_RESET		CRU_REG(0x240C)
#define CRU_MPHY0_SW_RESET		CRU_REG(0x2420)
#define CRU_MPHY1_SW_RESET		CRU_REG(0x2424)
#define CRU_MPHY2_SW_RESET		CRU_REG(0x2428)
#define CRU_TCU0_SW_RESET		CRU_REG(0x2430)
#define CRU_TCU1_SW_RESET		CRU_REG(0x2434)
#define CRU_PCIE4_SW_RESET		CRU_REG(0x2600)
#define CRU_PCIE5_SW_RESET		CRU_REG(0x2604)
#define CRU_PCIE6_SW_RESET		CRU_REG(0x2608)
#define CRU_PCIE7_SW_RESET		CRU_REG(0x260C)
#define CRU_PCIE8_SW_RESET		CRU_REG(0x2610)
#define CRU_PCIE9_SW_RESET		CRU_REG(0x2614)
#define CRU_PCIE_TCU2_SW_RESET		CRU_REG(0x2634)
#define CRU_PCIE_SUBLINK_SW_RESET	CRU_REG(0x2638)
#define CRU_PCIE_SYS_SW_RESET		CRU_REG(0x263C)
#define CRU_COMBPHY3_APB_SW_RESET	CRU_REG(0x2640)
#define CRU_COMBPHY4_APB_SW_RESET	CRU_REG(0x2644)
#define CRU_COMBPHY5_APB_SW_RESET	CRU_REG(0x2648)
#define CRU_COMBPHY3_PHYRESETN_SW_RESET	CRU_REG(0x264C)
#define CRU_COMBPHY4_PHYRESETN_SW_RESET	CRU_REG(0x2650)
#define CRU_COMBPHY5_PHYRESETN_SW_RESET	CRU_REG(0x2654)
#define CRU_PERI_SPI0_SW_RESET		CRU_REG(0x2820)
#define CRU_PERI_SPI1_SW_RESET		CRU_REG(0x2824)
#define CRU_PERI_SPI2_SW_RESET		CRU_REG(0x2828)
#define CRU_PERI_SPI3_SW_RESET		CRU_REG(0x282C)
#define CRU_PERI_SMBUS0_SW_RESET	CRU_REG(0x2840)
#define CRU_PERI_SMBUS1_SW_RESET	CRU_REG(0x2844)
#define CRU_PERI_I3C0_SW_RESET		CRU_REG(0x2860)
#define CRU_PERI_I3C1_SW_RESET		CRU_REG(0x2864)
#define CRU_PERI_I2C0_SW_RESET		CRU_REG(0x2880)
#define CRU_PERI_I2C1_SW_RESET		CRU_REG(0x2884)
#define CRU_PERI_I2C2_SW_RESET		CRU_REG(0x2888)
#define CRU_PERI_I2C3_SW_RESET		CRU_REG(0x288C)
#define CRU_PERI_I2C4_SW_RESET		CRU_REG(0x2890)
#define CRU_PERI_I2C5_SW_RESET		CRU_REG(0x2894)
#define CRU_PERI_UART0_SW_RESET		CRU_REG(0x28A0)
#define CRU_PERI_UART1_SW_RESET		CRU_REG(0x28A4)
#define CRU_PERI_UART2_SW_RESET		CRU_REG(0x28A8)
#define CRU_PERI_UART3_SW_RESET		CRU_REG(0x28AC)
#define CRU_PERI_GPIO0_SW_RESET		CRU_REG(0x28C0)
#define CRU_PERI_GPIO1_SW_RESET		CRU_REG(0x28C4)
#define CRU_PERI_GPIO2_SW_RESET		CRU_REG(0x28C8)
#define CRU_PERI_GPIO3_SW_RESET		CRU_REG(0x28CC)
#define CRU_PERI_GPIO4_SW_RESET		CRU_REG(0x28D0)
#define CRU_PERI_WDT0_SW_RESET		CRU_REG(0x28E0)
#define CRU_PERI_WDT1_SW_RESET		CRU_REG(0x28E4)
#define CRU_PERI_WDT2_SW_RESET		CRU_REG(0x28E8)
#define CRU_PERI_WDT3_SW_RESET		CRU_REG(0x28EC)
#define CRU_PERI_WDT4_SW_RESET		CRU_REG(0x28F0)
#define CRU_PERI_WDT5_SW_RESET		CRU_REG(0x28F4)
#define CRU_PERI_WDT6_SW_RESET		CRU_REG(0x28F8)
#define CRU_PERI_WDT7_SW_RESET		CRU_REG(0x28FC)
#define CRU_PERI_GTIMER0_SW_RESET	CRU_REG(0x2900)
#define CRU_PERI_GTIMER1_SW_RESET	CRU_REG(0x2920)
#define CRU_PERI_GTIMER2_SW_RESET	CRU_REG(0x2940)
#define CRU_PERI_GTIMER3_SW_RESET	CRU_REG(0x2960)
#define CRU_PERI_DMAC_SW_RESET		CRU_REG(0x29C0)
#define CRU_PERI_GMAC_SW_RESET		CRU_REG(0x29E0)
#define CRU_PERI_TBU_SW_RESET		CRU_REG(0x29F0)
#define CRU_PERI_TBU_ADB_SW_RESET	CRU_REG(0x29F4)
#endif

/* XXX_CLK_CTL */
#define CRU_CLKENABLE(n)		_BV(n)
#define CRU_CLKDIV0_OFFSET		4
#define CRU_CLKDIV0_MASK		REG_12BIT_MASK
#define CRU_CLKDIV0(value)		_SET_FV(CRU_CLKDIV0, value)
#define CRU_CLKDIV1_OFFSET		16
#define CRU_CLKDIV1_MASK		REG_8BIT_MASK
#define CRU_CLKDIV1(value)		_SET_FV(CRU_CLKDIV1, value)
#define CRU_CLKSEL_OFFSET		24
#define CRU_CLKSEL_MASK			REG_8BIT_MASK
#define CRU_CLKSEL(value)		_SET_FV(CRU_CLKSEL, value)

/* XXX_SW_RESET */
#define CRU_RSTN(n)			_BV(n)

/* CRU driver flags */
#define CRU_4PHASE	_BV(0)
#define CRU_FRAC	_BV(1)
#define CRU_JITTER	_BV(2)
#define CRU_FOUT0	_BV(3)
#define CRU_FOUT1	_BV(4)
#define CRU_CLKEN	_BV(5)
#define CRU_SRC_CLKSEL	_BV(6)
#define CRU_CLKEN_2BIT	_BV(7)
#define CRU_ENABLED	_BV(8)
#define CRU_RESET	_BV(9)
#define CRU_RESET_2BIT	_BV(10)
#define CRU_RESET_3BIT	_BV(11)
#define CRU_RESET_4BIT	_BV(12)

typedef uint16_t cru_flags_t;

#ifdef CONFIG_K1MATRIX_CRU_TRACE
void cru_trace(bool enabling, const char *name);
#else
#define cru_trace(enabling, name)	do { } while (0)
#endif

#endif /* __K1MATRIX_CRU_H_INCLUDE__ */
