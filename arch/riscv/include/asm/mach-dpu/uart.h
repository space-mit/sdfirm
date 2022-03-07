/*
 * ZETALOG's Personal COPYRIGHT
 *
 * Copyright (c) 2020
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
 * @(#)uart.h: DPU specific UART controller interface
 * $Id: uart.h,v 1.1 2020-03-04 13:18:00 zhenglv Exp $
 */

#ifndef __UART_DPU_H_INCLUDE__
#define __UART_DPU_H_INCLUDE__

#include <target/gpio.h>
#include <target/clk.h>

#define UART_CLK_ID		srst_uart
#define __DPU_UART_BASE		UART_BASE
#ifdef CONFIG_MMU
#define DPU_UART_BASE		dpu_uart_reg_base
extern caddr_t dpu_uart_reg_base;
#else
#define DPU_UART_BASE		__DPU_UART_BASE
#endif
#define DW_UART_REG(n, offset)	(DPU_UART_BASE + (offset))
#define UART_CON_ID		0
#define UART_CON_IRQ		IRQ_UART

#ifdef CONFIG_DW_UART
#include <driver/dw_uart.h>
#ifndef ARCH_HAVE_UART
#define ARCH_HAVE_UART		1
#else
#error "Multiple UART controller defined"
#endif
#endif

#ifdef CONFIG_DPU_UART_VIP
#define UART_CON_BAUDRATE		(APB_CLK_FREQ/16)
#endif

#ifdef CONFIG_DEBUG_PRINT
void uart_hw_dbg_init(void);
void uart_hw_dbg_start(void);
void uart_hw_dbg_stop(void);
void uart_hw_dbg_write(uint8_t byte);
void uart_hw_dbg_config(uint8_t params, uint32_t baudrate);
#endif

#ifdef CONFIG_MMU
void uart_hw_mmu_init(void);
#endif

#ifdef CONFIG_DW_UART
#ifdef CONFIG_CLK
#define dpu_uart_init()							\
	do {								\
		board_init_clock();					\
		clk_enable(UART_CLK_ID);				\
		dw_uart_ctrl_init(clk_get_frequency(UART_CLK_ID));	\
	} while (0)
#define dpu_uart_putc(byte)						\
	do {								\
		while (!dw_uart_write_poll(UART_CON_ID));		\
		dw_uart_write_byte(UART_CON_ID, byte);			\
	} while (0)
#else /* CONFIG_CLK */
#define dpu_uart_init()		do { } while (0)
#define dpu_uart_putc(byte)	do { } while (0)
#endif /* CONFIG_CLK */
#endif /* CONFIG_DW_UART */

#ifdef CONFIG_CONSOLE
#define uart_hw_con_init()	dpu_uart_init()
#endif
#ifdef CONFIG_CONSOLE_OUTPUT
#define uart_hw_con_write(byte)	dw_uart_con_write(byte)
#endif
#ifdef CONFIG_CONSOLE_INPUT
#define uart_hw_con_read()	dw_uart_con_read()
#define uart_hw_con_poll()	dw_uart_con_poll()
#ifndef CONFIG_SYS_NOIRQ
#define uart_hw_irq_init()	dw_uart_irq_init()
#define uart_hw_irq_ack()	dw_uart_irq_ack()
#endif
#endif

#endif /* __UART_DPU_H_INCLUDE__ */
