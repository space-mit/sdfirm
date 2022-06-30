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
 * @(#)sbi.c: VIRAPA system binary interface (sbi) driver
 * $Id: sbi.c,v 1.1 2022-06-30 14:47:00 zhenglv Exp $
 */

#include <target/sbi.h>
#include <target/fdt.h>
#include <target/uart.h>
#include <target/irq.h>
#include <target/delay.h>
#include <target/bench.h>

static void virapa_modify_dt(void *fdt)
{
}

#ifdef CONFIG_VIRAPA_BOOT_RAM
static void virapa_pma_init(void)
{
	int n = 0;

	/* PMA configured for virapa_beta test bench */
	n += pma_set(n, PMA_AT_NORMAL | PMA_S_INNER, RAM_BASE,
		     __ilog2_u64(__roundup64(max(SZ_2M, RAM_SIZE))));
	n += pma_set(n, PMA_AT_DEVICE,               DEV_BASE,
		     ilog2_const(max(SZ_2M, DEV_SIZE)));
	n += pma_set(n, PMA_AT_DEVICE,               ROM_BASE,
		     __ilog2_u64(__roundup64(ROM_SIZE)));
}
#else
#define virapa_pma_init()		do { } while (0)
#endif

static int virapa_early_init(bool cold_boot)
{
	virapa_cpu_init();

	if (!cold_boot)
		return 0;
	virapa_pma_init();

	return 0;
}

static int virapa_final_init(bool cold_boot)
{
	void *fdt;

	if (!cold_boot)
		return 0;

	fdt = sbi_scratch_thishart_arg1_ptr();
	virapa_modify_dt(fdt);
	return 0;
}

static uint32_t virapa_pmp_region_count(uint32_t hartid)
{
	return 1;
}

static int virapa_pmp_region_info(uint32_t hartid, uint32_t index,
				  ulong *prot, ulong *addr, ulong *log2size)
{
	int ret = 0;

	switch (index) {
	case 0:
		*prot	  = PMP_R | PMP_W | PMP_X;
		*addr	  = 0;
		*log2size = __riscv_xlen;
		break;
	default:
		ret = -1;
		break;
	};
	return ret;
}

#ifdef CONFIG_VIRAPA_UART
#define __UART_REG(offset)		(UART_BASE + (offset))
#define __UARTDR			__UART_REG(0x000)
#define __UARTFR			__UART_REG(0x018)
#define __pl01x_read_data()		__raw_readb(__UARTDR)
#define __pl01x_write_data(v)		__raw_writeb(v, __UARTDR)
#define __pl01x_write_full()		(__raw_readw(__UARTFR) & UART_TXFF)
#define __pl01x_read_empty()		(__raw_readw(__UARTFR) & UART_RXFE)

static void virapa_console_putc(char ch)
{
	while (__pl01x_write_full());
	__pl01x_write_data(ch);
}

static int virapa_console_getc(void)
{
	if (__pl01x_read_empty())
		return -1;
	return __pl01x_read_data();
}
#else
static void virapa_console_putc(char ch)
{
}

static int virapa_console_getc(void)
{
	return 0;
}
#endif

static int virapa_irqchip_init(bool cold_boot)
{
	return 0;
}

void virapa_ipi_send(uint32_t target_cpu)
{
	clint_set_ipi(target_cpu);
}

void virapa_ipi_clear(uint32_t target_cpu)
{
	clint_clear_ipi(target_cpu);
}

static int virapa_ipi_init(bool cold_boot)
{
	cpu_t cpu = sbi_processor_id();

	if (!cold_boot)
		virapa_ipi_clear(cpu);
	return 0;
}

uint64_t virapa_timer_value(void)
{
	return clint_read_mtime();
}

void virapa_timer_event_stop(void)
{
	__unused cpu_t cpu = sbi_processor_id();

	clint_unset_mtimecmp(cpu);
}

void virapa_timer_event_start(uint64_t next_event)
{
	__unused cpu_t cpu = sbi_processor_id();

	clint_set_mtimecmp(cpu, next_event);
}

static int virapa_timer_init(bool cold_boot)
{
	if (!cold_boot)
		virapa_timer_event_stop();
	return 0;
}

static int virapa_system_down(uint32_t type)
{
	printf("Shutting down simulation...\n");
	board_shutdown();
	return 0;
}

const struct sbi_platform_operations platform_ops = {
	.pmp_region_count	= virapa_pmp_region_count,
	.pmp_region_info	= virapa_pmp_region_info,
	.early_init		= virapa_early_init,
	.final_init		= virapa_final_init,
	.console_putc		= virapa_console_putc,
	.console_getc		= virapa_console_getc,
	.irqchip_init		= virapa_irqchip_init,
	.ipi_send		= virapa_ipi_send,
	.ipi_clear		= virapa_ipi_clear,
	.ipi_init		= virapa_ipi_init,
	.timer_value		= virapa_timer_value,
	.timer_event_stop	= virapa_timer_event_stop,
	.timer_event_start	= virapa_timer_event_start,
	.timer_init		= virapa_timer_init,
	.system_reboot		= virapa_system_down,
	.system_shutdown	= virapa_system_down
};

const struct sbi_platform platform = {
	.opensbi_version	= OPENSBI_VERSION,
	.platform_version	= SBI_PLATFORM_VERSION(0x0, 0x01),
	.name			= "Smart Core Vaisra Bench Beta",
	.features		= SBI_PLATFORM_DEFAULT_FEATURES,
	.disabled_hart_mask	= ~HART_ALL,
	.platform_ops_addr	= (unsigned long)&platform_ops
};
