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
 * @(#)reg.h: K1Matrix specific register layout definitions
 * $Id: reg.h,v 1.1 2023-09-06 18:10:00 zhenglv Exp $
 */

#ifndef __REG_K1MATRIX_H_INCLUDE__
#define __REG_K1MATRIX_H_INCLUDE__

#ifndef __ASSEMBLY__
extern unsigned long k1matrix_die_base;
#endif

#define DIE0_BASE			ULL(0x00000000000)
#define DIE1_BASE			ULL(0x05000000000)
#define __DIE_BASE(die)			((uint64_t)(die) << 39)
#define DIE_BASE			k1matrix_die_base

#define __DDR_BASE			ULL(0x00000000000)
#define __DRAM_SIZE		        ULL(0x01000000000)

#define __RMU_SPI_XIP_BASE		ULL(0x00400000000)
#define __RMU_ROM_BASE			ULL(0x00408000000)
#define __RMU_RAM_BASE			ULL(0x00408100000)
#define __RMU_MAILBOX_EHSM_BASE		ULL(0x0040C000000)
#define __RMU_EFUSE_S_BASE		ULL(0x0040C010000)
#define __RMU_LS_DMA_BASE		ULL(0x0040C020000)
#define __RMU_SPI_M_0_BASE		ULL(0x0040C400000)
#define __RMU_SPI_S_0_BASE		ULL(0x0040C410000)
#define __RMU_QSPI_BASE			ULL(0x0040C420000)
#define __RMU_SMBUS0_BASE		ULL(0x0040C500000)
#define __RMU_SMBUS1_BASE		ULL(0x0040C510000)
#define __RMU_I2C0_BASE			ULL(0x0040C600000)
#define __RMU_I2C1_BASE			ULL(0x0040C610000)
#define __RMU_I2C2_BASE			ULL(0x0040C620000)
#define __RMU_I2C3_BASE			ULL(0x0040C630000)
#define __RMU_GPIOA_BASE		ULL(0x0040C700000)
#define __RMU_WDT_BASE			ULL(0x0040C710000)
#define __RMU_TIMER0_3_BASE		ULL(0x0040C720000)
#define __RMU_REG_BASE			ULL(0x0040C730000)
#define __RMU_PLIC_BASE			ULL(0x00410000000)
#define __RMU_CLINT_BASE		ULL(0x00414000000)
#define __RMU_UART0_BASE		ULL(0x00418000000)
#define __RMU_UART1_BASE		ULL(0x00418010000)
#define __RMU_TIMER_S_BASE		ULL(0x00418020000)
#define __RMU_MAILBOX_S_BASE		ULL(0x00418030000)
#define __RMU_PIC_EX_BASE		ULL(0x00418040000)
#define __RMU_PVT_CRTL_BASE		ULL(0x00418050000)
#define __RMU_STM_BASE			ULL(0x00418060000)
#define __RMU_SYS_REG_BASE		ULL(0x00418070000)
#define __RMU_SYS_CRU_BASE		ULL(0x00418080000)
#define __RMU_LPC_CFG_BASE		ULL(0x0041A000000)
#define __RMU_ESPI_CFG_BASE		ULL(0x0041A010000)
#define __RMU_SPINLOCK_BASE		ULL(0x0041A200000)
#define __RMU_MAILBOX_NS_BASE		ULL(0x0041A210000)
#define __RMU_EMUSE_NS_BASE		ULL(0x0041A220000)
#define __RMU_LPC_IO_BASE		ULL(0x0041BE00000)
#define __RMU_ESPI_IO_BASE		ULL(0x0041BE10000)
#define __RMU_LPC_FLASH_BASE		ULL(0x0041C000000)
#define __RMU_ESPI_FLASH_BASE		ULL(0x0041E000000)

#define __SPI0_BASE			ULL(0x00422000000)
#define __SPI1_BASE			ULL(0x00422010000)
#define __SPI2_BASE			ULL(0x00422020000)
#define __SPI3_BASE			ULL(0x00422030000)
#define __SMBUS1_BASE			ULL(0x00422100000)
#define __SMBUS2_BASE			ULL(0x00422110000)
#define __I2C0_BASE			ULL(0x00422200000)
#define __I2C1_BASE			ULL(0x00422210000)
#define __I2C2_BASE			ULL(0x00422220000)
#define __I2C3_BASE			ULL(0x00422230000)
#define __I2C4_BASE			ULL(0x00422240000)
#define __I2C5_BASE			ULL(0x00422250000)
#define __I2C6_BASE			ULL(0x00422260000)
#define __I2C7_BASE			ULL(0x00422270000)
#define __UART0_BASE			ULL(0x00422300000)
#define __UART1_BASE			ULL(0x00422310000)
#define __UART2_BASE			ULL(0x00422320000)
#define __UART3_BASE			ULL(0x00422330000)
#define __GPIOB_BASE			ULL(0x00422400000)
#define __GPIOC_BASE			ULL(0x00422410000)
#define __GPIOD_BASE			ULL(0x00422420000)
#define __WDT0_BASE			ULL(0x00422500000)
#define __WDT1_BASE			ULL(0x00422510000)
#define __WDT2_BASE			ULL(0x00422520000)
#define __WDT3_BASE			ULL(0x00422530000)
#define __WDT4_BASE			ULL(0x00422540000)
#define __WDT5_BASE			ULL(0x00422550000)
#define __WDT6_BASE			ULL(0x00422560000)
#define __WDT7_BASE			ULL(0x00422570000)
#define __TIMER_NS_0_7_BASE		ULL(0x00422700000)
#define __TIMER_NS_8_15_BASE		ULL(0x00422710000)
#define __TIMER_NS_16_23_BASE		ULL(0x00422720000)
#define __TIMER_NS_24_31_BASE		ULL(0x00422730000)
#define __HS_DMA_BASE			ULL(0x00424C00000)
#define __GMAC_BASE			ULL(0x00424C20000)

#define __S_ACLINT_HARTX_SSIP_BASE	ULL(0x00430400000)
#define __S_APLIC_S_DOMAIN_CFG_BASE	ULL(0x00430500000)
#define __S_MODE_MSI_BASE		ULL(0x00430600000)
#define __M_ACLINT_HARTX_MSIP_BASE	ULL(0x00432000000)
#define __M_ACLINT_HARTX_MTIP_BASE	ULL(0x00432004000)
#define __M_APLIC_M_DOMAIN_CFG_BASE	ULL(0x00432200000)
#define __M_MODE_MSI_BASE		ULL(0x00432300000)
#define __NIC400_PIC_GPV		ULL(0x00433B00000)
#define __PCIE9_M0_IOPMP_S0_NID44	ULL(0x00433C00000)
#define __PCIE9_M1_IOPMP_S0_NID108	ULL(0x00433C10000)
#define __TCU3_IOPMP_S1__NID108		ULL(0x00433C20000)
#define __PCIE6_IOPMP_S0_NID172		ULL(0x00433C30000)



#define __DDR_CHA_PHY_BASE		ULL(0x00434000000)
#define __DDR_CHA_CRTL_BASE		ULL(0x00435000000)
#define __DDR_CHA_LSC_BASE		ULL(0x00435800000)
#define __DDR_CHB_PHY_BASE		ULL(0x00436000000)
#define __DDR_CHB_CRTL_BASE		ULL(0x00437000000)
#define __DDR_CHB_LSC_BASE		ULL(0x00437800000)
#define __DDR_CHC_PHY_BASE		ULL(0x00438000000)
#define __DDR_CHC_CRTL_BASE		ULL(0x00439000000)
#define __DDR_CHC_LSC_BASE		ULL(0x00439800000)
#define __DDR_CHD_PHY_BASE		ULL(0x0043A000000)
#define __DDR_CHD_CRTL_BASE		ULL(0x0043B000000)
#define __DDR_CHD_LSC_BASE		ULL(0x0043B800000)
#define __N100_CFG_BASE			ULL(0x00440000000)
#define __N100_OCM_BASE			ULL(0x00444000000)

#define __ACPU_RAS_SPACE_BASE		ULL(0x00448000000)
#define __PCIE0_SLV_BASE		ULL(0x04000000000)
#define __PCIE1_SLV_BASE		ULL(0x04100000000)
#define __PCIE2_SLV_BASE		ULL(0x04200000000)
#define __PCIE3_SLV_BASE		ULL(0x04300000000)
#define __PCIE0_DBI_BASE		ULL(0x04700000000)
#define __PCIE0_APP_BASE		ULL(0x04700400000)
#define __PCIE_4L_RC_0_PHY_BASE		ULL(0x04700600000)
#define __PCIE1_DBI_BASE		ULL(0x04700700000)
#define __PCIE1_APP_BASE		ULL(0x04700B00000)
#define __PCIE_4L_RC_1_PHY_BASE		ULL(0x04700C00000)
#define __PCIE2_DBI_BASE		ULL(0x04700D00000)
#define __PCIE2_APP_BASE		ULL(0x04701100000)
#define __PCIE3_DBI_BASE		ULL(0x04701200000)
#define __PCIE3_APP_BASE		ULL(0x04701600000)
#define __PCIE_16L88L_DM_CCIX_0_1_PHY_BASE	ULL(0x04701700000)
#define __IOMMU_CRTL0_CFG_BASE		ULL(0x04780000000)
#define __IOMMU_CRTL1_CFG_BASE		ULL(0x04780200000)
#define __PCIE4_SLV_BASE		ULL(0x04800000000)
#define __PCIE5_SLV_BASE		ULL(0x04900000000)
#define __PCIE6_SLV_BASE		ULL(0x04A00000000)
#define __PCIE7_SLV_BASE		ULL(0x04B00000000)
#define __PCIE8_SLV_BASE		ULL(0x04C00000000)
#define __PCIE9_SLV_BASE		ULL(0x04D00000000)
#define __PCIE4_DBI_BASE		ULL(0x04F00000000)
#define __PCIE4_APP_BASE		ULL(0x04F00400000)
#define __PCIE5_DBI_BASE		ULL(0x04F00500000)
#define __PCIE5_APP_BASE		ULL(0x04F00900000)
#define __PCIE_8L44L_DM_CCIX_2_PHY	ULL(0x04F00A00000)
#define __PCIE6_DBI_BASE		ULL(0x04F00B00000)
#define __PCIE6_APP_BASE		ULL(0x04F00F00000)
#define __PCIE7_DBI_BASE		ULL(0x04F01000000)
#define __PCIE7_APP_BASE		ULL(0x04F01400000)
#define __PCIE8_DBI_BASE		ULL(0x04F01500000)
#define __PCIE8_APP_BASE		ULL(0x04F01900000)
#define __PCIE_4L211L_RC_PHY_BASE	ULL(0x04F01A00000)
#define __PCIE_9_DBI_BASE		ULL(0x04F01B00000)
#define __PCIE_9_APP_BASE		ULL(0x04F01F00000)
#define __PCIE_16L_RC_PHY_BASE		ULL(0x04F02000000)
#define __IOMMU_CRTL2_CFG_BASE		ULL(0x04F80000000)
#define __IOMMU_CRTL3_CFG_BASE		ULL(0x04F80200000)

#ifdef CONFIG_K1MATRIX_64C

#define DIE0_BASE			ULL(0x00000000000)
#define DIE1_BASE			ULL(0x05000000000)
#define __DIE_BASE(die)			((uint64_t)(die) << 39)
#define DIE_BASE			k1matrix_die_base

#define __DDR_BASE			ULL(0x00000000000)
#define __DRAM_SIZE		        ULL(0x02000000000)

#define __RMU_QSPI_XIP_BASE		ULL(0x00400000000)
#define __RMU_BROM_BASE			ULL(0x00410000000)
#define __RMU_RAM_BASE			ULL(0x00410100000)
#define __RMU_MAILBOX_EHSM_BASE		ULL(0x00420000000)
#define __RMU_EFUSE_S_BASE		ULL(0x00420010000)
#define __RMU_QSPI_0_BASE		ULL(0x00420420000)
#define __RMU_WDT_BASE			ULL(0x00420710000)
#define __RMU_TIMER0_3_BASE		ULL(0x00420720000)
#define __RMU_REG_BASE			ULL(0x00420730000)
#define __RMU_PLIC_BASE			ULL(0x00528000000)
#define __RMU_CLINT_BASE		ULL(0x00530000000)
#define __RMU_SRAM_MAILBOX_S_BASE	ULL(0x00538000000)
#define __RMU_LS_DMA_BASE		ULL(0x00538010000)
#define __RMU_MAILBOX_EHSM_ALIAS_BASE	ULL(0x00539000000)
#define __RMU_EFUSE_S_ALIAS_BASE	ULL(0x00539000000)
#define __RMU_QSPI_0_ALIAS_BASE		ULL(0x00539020000)
#define __RMU_REG_ALIAS_BASE		ULL(0x00539030000)
#define __RMU_R_SPI_M_0_BASE		ULL(0x0053A000000)
#define __RMU_R_SPI_S_0_BASE		ULL(0x0053A010000)
#define __RMU_R_SMBUS_0_BASE		ULL(0x0053A100000)
#define __RMU_R_SMBUS_1_BASE		ULL(0x0053A110000)
#define __RMU_R_SMBUS_2_BASE		ULL(0x0053A120000)
#define __RMU_R_SMBUS_3_BASE		ULL(0x0053A130000)
#define __RMU_R_SMBUS_4_BASE		ULL(0x0053A140000)
#define __RMU_R_I2C_0_BASE		ULL(0x0053A200000)
#define __RMU_R_I2C_1_BASE		ULL(0x0053A210000)
#define __RMU_R_I2C_2_BASE		ULL(0x0053A220000)
#define __RMU_R_GPIOA_BASE		ULL(0x0053A300000)
#define __RMU_R_GPIOB_BASE		ULL(0x0053A310000)
#define __RMU_R_GPIOC_BASE		ULL(0x0053A320000)
#define __RMU_UART_S_0_BASE		ULL(0x0053C000000)
#define __RMU_UART_S_1_BASE		ULL(0x0053C010000)
#define __RMU_UART_S_2_BASE		ULL(0x0053C020000)
#define __RMU_MAILBOX_S_BASE		ULL(0x0053C030000)
#define __RMU_TIMER_S_BASE		ULL(0x0053C050000)
#define __RMU_STM_BASE			ULL(0x0053C060000)
#define __RMU_SYS_REG_BASE		ULL(0x0053C070000)
#define __RMU_SYS_CRU_BASE		ULL(0x0053C080000)
#define __RMU_PVT_CRTL_0_BASE		ULL(0x0053C100000)
#define __RMU_PVT_CRTL_1_BASE		ULL(0x0053C110000)
#define __RMU_PVT_CRTL_2_BASE		ULL(0x0053C120000)
#define __RMU_ACTIVE_SHIELD_BASE	ULL(0x0053C130000)
#define __RMU_LCP_CFG_BASE		ULL(0x0053E000000)
#define __RMU_ESPI_CFG_BASE		ULL(0x0053E010000)
#define __RMU_SPINLOCK_BASE		ULL(0x0053E200000)
#define __RMU_MAILBOX_NS_BASE		ULL(0x0053E210000)
#define __RMU_EFUSE_NS_BASE		ULL(0x0053E230000)
#define __RMU_SRAM_MAILBOX_BASE		ULL(0x0053F000000)
#define __RMU_LPC_IO_BASE		ULL(0x0053FE00000)
#define __RMU_ESPI_IO_BASE		ULL(0x0053FE10000)
#define __RMU_IOPMP_DEFAULT_SLV_NID0_BASE	ULL(0x0053FFF0000)

#define __SPI0_M_0_BASE			ULL(0x00552000000)
#define __SPI1_M_1_BASE			ULL(0x00552010000)
#define __I3C_0_BASE			ULL(0x00552180000)
#define __I3C_1_BASE			ULL(0x00552190000)
#define __I3C_2_BASE			ULL(0x005521A0000)
#define __I3C_3_BASE			ULL(0x005521B0000)
#define __I2C_0_BASE			ULL(0x00552200000)
#define __I2C_1_BASE			ULL(0x00552210000)
#define __I2C_2_BASE			ULL(0x00552220000)
#define __I2C_3_BASE			ULL(0x00552230000)
#define __I2C_4_BASE			ULL(0x00552240000)
#define __I2C_5_BASE			ULL(0x00552250000)
#define __UART_0_BASE			ULL(0x00552300000)
#define __UART_1_BASE			ULL(0x00552310000)
#define __A_GPIOA_BASE			ULL(0x00552400000)
#define __A_GPIOB_BASE			ULL(0x00552410000)
#define __A_GPIOC_BASE			ULL(0x00552420000)
#define __WDT_BASE			ULL(0x00552500000)
#define __TIMER_NS_BASE			ULL(0x00552700000)
#define __HS_DMA_BASE			ULL(0x00554C00000)
#define __GMAC_BASE			ULL(0x00554C20000)
#define __SRAM_GMAC_BASE		ULL(0x00554C40000)
#define __S_ACLINT_HARTX_SSIP_BASE	ULL(0x00558400000)
#define __S_APLIC_S_DOMAIN_CFG_BASE	ULL(0x00558500000)
#define __S_MODE_MSI_BASE		ULL(0x00558600000)
#define __M_ACLINT_HARTX_MSIP_BASE	ULL(0x0055A000000)
#define __M_ACLINT_HARTX_MTIP_BASE	ULL(0x0055A004000)
#define __M_APLIC_M_DOMAIN_CFG_BASE	ULL(0x0055A200000)
#define __M_MODE_MSI_BASE		ULL(0x0055A300000)

#define __RMU_IOPMP_S0_NID4		ULL(0x0055C000000)
#define __PERI_IOPMP_S1_NID4		ULL(0x0055C010000)
#define __PCIE0_IOPMP_S0_NID68		ULL(0x0055C020000)
#define __PCIE1_IOPMP_S1_NID68		ULL(0x0055C030000)
#define __PCIE2_IOPMP_S2_NID68		ULL(0x0055C040000)
#define __PCIE3_IOPMP_S0_NID132		ULL(0x0055C050000)
#define __PCIE4_IOPMP_S1_NID132		ULL(0x0055C060000)
#define __PCIE5_IOPMP_S0_NID196		ULL(0x0055C070000)
#define __IOMMU_CTRL0_IOPMP_S1_NID196	ULL(0x0055C080000)
#define __IOMMU_CTRL1_IOPMP_S0_NID260	ULL(0x0055C090000)
#define __PCIE6_IOPMP_S1_NID260		ULL(0x0055C0A0000)
#define __PCIE7_IOPMP_S1_NID324		ULL(0x0055C0B0000)
#define __PCIE8_IOPMP_S2_NID324		ULL(0x0055C0C0000)
#define __PCIE9_IOPMP_S0_NID300		ULL(0x00560000000)
#define __PCIE10_IOPMP_S0_NID364	ULL(0x00560010000)
#define __IOMMU_CTRL2_IOPMP_S1_NID364	ULL(0x00560020000)
#define __PCIE11_IOPMP_S0_NID108	ULL(0x00568000000)
#define __PCIE12_IOPMP_S1_NID44		ULL(0x00568010000)
#define __IOMMU_CTRL3_IOPMP_S2_NID44	ULL(0x00568020000)

#define __DDR_CH_C_PHY_BASE		ULL(0x0056C000000)
#define __DDR_CH_C_CRTL_BASE		ULL(0x0056D000000)
#define __DDR_CH_C_LSC_BASE		ULL(0x0056D800000)
#define __DDR_CH_D_PHY_BASE		ULL(0x0056E000000)
#define __DDR_CH_D_CRTL_BASE		ULL(0x0056F000000)
#define __DDR_CH_D_LSC_BASE		ULL(0x0056F800000)
#define __DDR_CH_A_PHY_BASE		ULL(0x00570000000)
#define __DDR_CH_A_CRTL_BASE		ULL(0x00571000000)
#define __DDR_CH_A_LSC_BASE		ULL(0x00571800000)
#define __DDR_CH_B_PHY_BASE		ULL(0x00572000000)
#define __DDR_CH_B_CRTL_BASE		ULL(0x00573000000)
#define __DDR_CH_B_LSC_BASE		ULL(0x00573800000)
#define __DDR_CH_E_PHY_BASE		ULL(0x00574000000)
#define __DDR_CH_E_CRTL_BASE		ULL(0x00575000000)
#define __DDR_CH_E_LSC_BASE		ULL(0x00575800000)
#define __DDR_CH_F_PHY_BASE		ULL(0x00576000000)
#define __DDR_CH_F_CRTL_BASE		ULL(0x00577000000)
#define __DDR_CH_F_LSC_BASE		ULL(0x00577800000)
#define __DDR_CH_G_PHY_BASE		ULL(0x00578000000)
#define __DDR_CH_G_CRTL_BASE		ULL(0x00579000000)
#define __DDR_CH_G_LSC_BASE		ULL(0x00579800000)
#define __DDR_CH_H_PHY_BASE		ULL(0x0057A000000)
#define __DDR_CH_H_CRTL_BASE		ULL(0x0057B000000)
#define __DDR_CH_H_LSC_BASE		ULL(0x0057B800000)
#define __ACPU_RAS_SPACE_BASE		ULL(0x00580000000)

#define __N100_CFG_BASE			ULL(0x005C8000000)
#define __N100_OCM_BASE			ULL(0x005CC000000)
#define __LPC_FLASH_BASE		ULL(0x005E0000000)
#define __ESPI_FLASH_BASE		ULL(0x005E2000000)
#define __XIP_FLASH_ALIAS_BASE		ULL(0x005F0000000)

#define __PCIE0_SLV_BASE		ULL(0x04000000000)
#define __PCIE1_SLV_BASE		ULL(0x04100000000)
#define __PCIE2_SLV_BASE		ULL(0x04200000000)
#define __PCIE3_SLV_BASE		ULL(0x04300000000)
#define __PCIE4_SLV_BASE		ULL(0x04400000000)
#define __PCIE5_SLV_BASE		ULL(0x04500000000)
#define __IOPMP_DEFAULT_SLV_NID192	ULL(0x046FFFF0000)
#define __PCIE0_DBI_BASE		ULL(0x04700000000)
#define __PCIE0_APP_BASE		ULL(0x04700400000)
#define __PCIE1_DBI_BASE		ULL(0x04700800000)
#define __PCIE1_APP_BASE		ULL(0x04700C00000)
#define __PCIE2_DBI_BASE		ULL(0x04701000000)
#define __PCIE2_APP_BASE		ULL(0x04701400000)
#define __PCIE_4L_COMBPHY0_BASE		ULL(0x04701800000)
#define __PCIE3_DBI_BASE		ULL(0x04702000000)
#define __PCIE3_APP_BASE		ULL(0x04702400000)
#define __PCIE_4L_COMBPHY1_BASE		ULL(0x04703800000)
#define __PCIE4_DBI_BASE		ULL(0x04704000000)
#define __PCIE4_APP_BASE		ULL(0x04704400000)
#define __PCIE_4L_COMBPHY2_BASE		ULL(0x04705800000)
#define __PCIE5_DBI_BASE		ULL(0x04706000000)
#define __PCIE5_APP_BASE		ULL(0x04706400000)
#define __PCIE_4L_COMBPHY3_BASE		ULL(0x04707800000)
#define __IOMMU_CRTL0_CFG_BASE		ULL(0x04780000000)
#define __PCIE6_SLV_BASE		ULL(0x04800000000)
#define __PCIE7_SLV_BASE		ULL(0x04900000000)
#define __PCIE8_SLV_BASE		ULL(0x04A00000000)
#define __PCIE6_DBI_BASE		ULL(0x04F00000000)
#define __PCIE6_APP_BASE		ULL(0x04F00400000)
#define __PCIE7_DBI_BASE		ULL(0x04F00800000)
#define __PCIE7_APP_BASE		ULL(0x04F00C00000)
#define __PCIE8_DBI_BASE		ULL(0x04F01000000)
#define __PCIE8_APP_BASE		ULL(0x04F01400000)
#define __PCIE_16L_COMBPHY4_BASE	ULL(0x04F01800000)
#define __IOMMU_CRTL1_CFG_BASE		ULL(0x04F80000000)
#define __PCIE9_SLV_BASE		ULL(0x05000000000)
#define __PCIE10_SLV_BASE		ULL(0x05100000000)
#define __PCIE9_DBI_BASE		ULL(0x05700000000)
#define __PCIE9_APP_BASE		ULL(0x05700400000)
#define __PCIE10_DBI_BASE		ULL(0x05700800000)
#define __PCIE10_APP_BASE		ULL(0x05700C00000)
#define __PCIE_16L_COMBPHY5_BASE	ULL(0x05701800000)
#define __IOPMP_DEFAULT_SLV_NID296	ULL(0x0577FFF0000)
#define __IOMMU_CRTL2_CFG_BASE		ULL(0x05780000000)
#define __PCIE11_SLV_BASE		ULL(0x05800000000)
#define __PCIE12_SLV_BASE		ULL(0x05900000000)
#define __PCIE11_DBI_BASE		ULL(0x05F00000000)
#define __PCIE11_APP_BASE		ULL(0x05F00400000)
#define __PCIE12_DBI_BASE		ULL(0x05F00800000)
#define __PCIE12_APP_BASE		ULL(0x05F00C00000)
#define __PCIE_16L_COMBPHY6_BASE	ULL(0x05F01800000)
#define __IOPMP_DEFAULT_SLV_NID104	ULL(0x05F7FFF0000)
#define __IOMMU_CRTL3_CFG_BASE		ULL(0x05F80000000)
#endif

#define UART0_BASE			__RMU_UART0_BASE

#define ACLINT_BASE			__RMU_CLINT_BASE
#ifdef CONFIG_K1MATRIX_RMU
#define PLIC_REG_BASE			__RMU_PLIC_BASE
#endif
#ifdef CONFIG_K1MATRIX_APU
#define PLIC_REG_BASE			__RMU_PLIC_BASE
#endif

#define N100_CFG_BASE			__N100_CFG_BASE
#define SYS_REG_BASE			__RMU_SYS_CRU_BASE
#define SRAM0_BASE			__RMU_RAM_BASE

#define SRAM01_SIZE			SZ_512K

#include <asm/mach/cprint.h>

#ifdef CONFIG_K1MATRIX_BOOT_LLP
#define BROM_BASE		__RMU_ROM_BASE
#endif /* CONFIG_K1MATRIX_BOOT_LLP */
#ifdef CONFIG_K1MATRIX_BOOT_SYS
#define BROM_BASE		SRAM1_BASE
#endif /* CONFIG_K1MATRIX_BOOT_SYS */

#ifdef CONFIG_K1MATRIX_ROM
#define BROM_SIZE		SZ_64K
#else /* CONFIG_K1MATRIX_ROM */
#define BROM_SIZE		0
#endif /* CONFIG_K1MATRIX_ROM */

#define SRAM_BASE		(SRAM0_BASE)
#define SRAM_SIZE		(SRAM01_SIZE)

#ifdef CONFIG_K1MATRIX_DDR_SIZE_CUSTOM
#define DRAM_SIZE               CONFIG_K1MATRIX_DDR_SIZE
#else /* CONFIG_K1MATRIX_DDR_SIZE_CUSTOM */
#define DRAM_SIZE		__DRAM_SIZE
#endif /* CONFIG_K1MATRIX_DDR_SIZE_CUSTOM */

#ifdef CONFIG_K1MATRIX_ZSBL
#define ROM_BASE		BROM_BASE
#define ROM_SIZE		BROM_SIZE
#define RAM_BASE		SRAM_BASE
#define RAM_SIZE		SRAM_SIZE
#endif /* CONFIG_K1MATRIX_ZSBL */
#ifdef CONFIG_K1MATRIX_FSBL
#define ROM_BASE		SRAM_BASE
#define ROM_SIZE		SRAM_SIZE
#define RAM_BASE		SRAM_BASE
#define RAM_SIZE		SRAM_SIZE
#endif /* CONFIG_K1MATRIX_FSBL */
#ifdef CONFIG_K1MATRIX_BBL
#define ROM_BASE		__DDR_BASE
#define ROM_SIZE		DRAM_SIZE
#define RAM_BASE		__DDR_BASE
#define RAM_SIZE		DRAM_SIZE
#endif /* CONFIG_K1MATRIX_BBL */
#ifdef CONFIG_K1MATRIX_TB
#ifdef CONFIG_K1MATRIX_TB_ROM
#define ROM_BASE		BROM_BASE
#define ROM_SIZE		BROM_SIZE
#define RAM_BASE		SRAM_BASE
#define RAM_SIZE		SRAM_SIZE
#endif
#ifdef CONFIG_K1MATRIX_TB_SRAM
#define ROM_BASE		SRAM_BASE
#define ROM_SIZE		SRAM_SIZE
#define RAM_BASE		SRAM_BASE
#define RAM_SIZE		SRAM_SIZE
#endif
#ifdef CONFIG_K1MATRIX_TB_DDR
#define ROM_BASE		DDR_BASE
#define ROM_SIZE		DRAM_SIZE
#define RAM_BASE		DDR_BASE
#define RAM_SIZE		DRAM_SIZE
#endif
#endif /* CONFIG_K1MATRIX_TB */

#define ROMEND			(ROM_BASE + ROM_SIZE)
#define RAMEND			(RAM_BASE + RAM_SIZE)

#endif /* __REG_K1MATRIX_H_INCLUDE__ */
