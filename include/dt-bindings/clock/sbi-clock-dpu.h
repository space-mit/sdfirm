/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 *  Copyright (C) 2022 CAS SmartCore Co., Ltd.
 *    Author: 2022 Lv Zheng <zhenglv@smart-core.cn>
 */

#ifndef __DT_BINDINGS_CLOCK_SBI_DPU_H
#define __DT_BINDINGS_CLOCK_SBI_DPU_H

#include <dt-bindings/clock/sbi-clock.h>

#define XIN_FREQ		25000000	/* 25MHz */
#define PCIE_PHY_CLK_FREQ	25000000	/* 25MHz */
#ifdef CONFIG_DPU_RES
#ifdef CONFIG_DPU_RES_SLOW
#define PLL0_P_FREQ		1000000000	/* 1GHz */
#else /* CONFIG_DPU_RES_SLOW */
#define PLL0_P_FREQ		1500000000	/* 1.5GHz */
#endif /* CONFIG_DPU_RES_SLOW */
#else /* CONFIG_DPU_RES */
#define PLL0_P_FREQ		800000000	/* 800MHz */
#endif /* CONFIG_DPU_RES */
#define PLL1_P_FREQ		1200000000	/* 1.2GHz */
#define PLL2_P_FREQ		800000000	/* 800MHz */
#define PLL2_R_FREQ		50000000	/* 50MHz */
#define PLL3_P_FREQ		800000000	/* 800MHz */
#define PLL3_R_FREQ		100000000	/* 100MHz */
#define PLL4_P_FREQ		1000000000	/* 1GHz */
#ifdef CONFIG_DPU_GEN2
#define PLL4_R_FREQ		25000000	/* 25MHZ */
#define PLL5_P_FREQ		1100000000	/* 1.1GHZ */
#else /* CONFIG_DPU_GEN2 */
#define PLL4_R_FREQ		500000000	/* 500MHZ */
#define PLL5_P_FREQ		100000000	/* 100MHZ */
#endif /* CONFIG_DPU_GEN2 */
#define PLL5_R_FREQ		6000000		/* 6MHz */
#ifdef CONFIG_DPU_RES
#ifdef CONFIG_DPU_BOOT_ROM
#define APC_CLK_FREQ		XIN_FREQ
#define IMC_CLK_FREQ		XIN_FREQ
#define APB_CLK_FREQ		XIN_FREQ
#else /* CONFIG_DPU_BOOT_ROM */
#define APC_CLK_FREQ		PLL0_P_FREQ
#define IMC_CLK_FREQ		(PLL0_P_FREQ / 2)
#define APB_CLK_FREQ		PLL3_R_FREQ
#endif /* CONFIG_DPU_BOOT_ROM */
#ifdef CONFIG_DPU_APC
#define CPU_CLK_FREQ		APC_CLK_FREQ
#else /* CONFIG_DPU_APC */
#define CPU_CLK_FREQ		IMC_CLK_FREQ
#endif /* CONFIG_DPU_APC */
#else /* CONFIG_DPU_RES */
#define IMC_CLK_FREQ		PLL0_P_FREQ
#define CPU_CLK_FREQ		IMC_CLK_FREQ
#define APB_CLK_FREQ		PLL3_R_FREQ
#endif /* CONFIG_DPU_RES */
#define PE_CLK_FREQ		PLL1_P_FREQ
#define AXI_CLK_FREQ		PLL3_P_FREQ
#define VPU_BCLK_FREQ		PLL4_P_FREQ
#ifdef CONFIG_DPU_GEN2
#define VPU_CCLK_FREQ		PLL5_P_FREQ
#else /* CONFIG_DPU_GEN2 */
#define VPU_CCLK_FREQ		PLL4_R_FREQ
#endif /* CONFIG_DPU_GEN2 */
#define PCIE_REF_CLK_FREQ	PLL5_P_FREQ

#ifdef CONFIG_DPU_UART_VIP
#define UART_CURRENT_SPEED	(APB_CLK_FREQ/16)
#else /* CONFIG_DPU_UART_VIP */
#ifdef CONFIG_CONSOLE_4000000
#define UART_CURRENT_SPEED	4000000
#endif
#ifdef CONFIG_CONSOLE_3500000
#define UART_CURRENT_SPEED	3500000
#endif
#ifdef CONFIG_CONSOLE_3000000
#define UART_CURRENT_SPEED	3000000
#endif
#ifdef CONFIG_CONSOLE_2500000
#define UART_CURRENT_SPEED	2500000
#endif
#ifdef CONFIG_CONSOLE_2000000
#define UART_CURRENT_SPEED	2000000
#endif
#ifdef CONFIG_CONSOLE_1500000
#define UART_CURRENT_SPEED	1500000
#endif
#ifdef CONFIG_CONSOLE_1000000
#define UART_CURRENT_SPEED	1000000
#endif
#ifdef CONFIG_CONSOLE_500000
#define UART_CURRENT_SPEED	500000
#endif
#ifdef CONFIG_CONSOLE_1152000
#define UART_CURRENT_SPEED	1152000
#endif
#ifdef CONFIG_CONSOLE_921600
#define UART_CURRENT_SPEED	921600
#endif
#ifdef CONFIG_CONSOLE_576000
#define UART_CURRENT_SPEED	576000
#endif
#ifdef CONFIG_CONSOLE_460800
#define UART_CURRENT_SPEED	460800
#endif
#ifdef CONFIG_CONSOLE_230400
#define UART_CURRENT_SPEED	230400
#endif
#ifdef CONFIG_CONSOLE_115200
#define UART_CURRENT_SPEED	115200
#endif
#ifdef CONFIG_CONSOLE_76800
#define UART_CURRENT_SPEED	76800
#endif
#ifdef CONFIG_CONSOLE_57600
#define UART_CURRENT_SPEED	57600
#endif
#ifdef CONFIG_CONSOLE_38400
#define UART_CURRENT_SPEED	38400
#endif
#ifdef CONFIG_CONSOLE_19200
#define UART_CURRENT_SPEED	19200
#endif
#ifdef CONFIG_CONSOLE_9600
#define UART_CURRENT_SPEED	9600
#endif
#ifdef CONFIG_CONSOLE_4800
#define UART_CURRENT_SPEED	4800
#endif
#ifdef CONFIG_CONSOLE_2400
#define UART_CURRENT_SPEED	2400
#endif
#endif /* CONFIG_DPU_UART_VIP */

#endif /* __DT_BINDINGS_CLOCK_SBI_DPU_H */