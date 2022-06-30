/*
 * ZETALOG's Personal COPYRIGHT
 *
 * Copyright (c) 2022
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
 * @(#)uart.h: VIRAPA specific uart controller definitions
 * $Id: uart.h,v 1.1 2022-06-27 17:41:00 zhenglv Exp $
 */

#ifndef __UART_VIRAPA_H_INCLUDE__
#define __UART_VIRAPA_H_INCLUDE__

#include <target/arch.h>
#include <target/irq.h>

#define UART_CON_ID			0
#define UART_CON_IRQ			IRQ_UART0

#ifdef CONFIG_MMU
#define VIRAPA_UART_BASE		virapa_uart_reg_base
extern caddr_t virapa_uart_reg_base;
#else
#define VIRAPA_UART_BASE		UART_BASE
#endif
#define VIRAPA_UART_REG(n, offset)	(VIRAPA_UART_BASE + (offset))
#define UART_REG(n, offset)		VIRAPA_UART_REG(n, offset)

#ifdef CONFIG_VIRAPA_UART
#include <driver/uart_pl01x.h>
#ifndef ARCH_HAVE_UART
#define ARCH_HAVE_UART		1
#else
#error "Multiple UART controller defined"
#endif

#define uart_hw_con_write(byte)	pl01x_write_byte(byte)
#define uart_hw_con_read()	pl01x_read_byte()
#define uart_hw_con_poll()	pl01x_read_poll()
#define uart_hw_con_init()	virapa_uart_con_init()
#ifdef CONFIG_MMU
#define uart_hw_mmu_init()	virapa_uart_mmu_init()
void virapa_uart_mmu_init(void);
#endif /* CONFIG_MMU */
void virapa_uart_con_init(void);
#endif /* CONFIG_VIRAPA_UART */

#endif /* __UART_VIRAPA_H_INCLUDE__ */
