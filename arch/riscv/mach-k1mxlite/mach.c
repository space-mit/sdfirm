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
 * @(#)mach.c: K1MXLite specific board initialization
 * $Id: mach.c,v 1.1 2023-10-15 14:36:00 zhenglv Exp $
 */

#include <target/arch.h>
#include <target/bench.h>
#include <target/smp.h>
#include <target/paging.h>
#include <target/barrier.h>
#include <target/percpu.h>
#include <target/cmdline.h>
#include <target/sbi.h>
#include <target/noc.h>
#include <target/pci.h>
#include <driver/spacemit_stm.h>

unsigned long k1mxlite_die_base = DIE0_BASE;
unsigned long k1mxlite_die_hart = DIE0_HART;

#ifdef CONFIG_K1MXLITE_D2D
void k1mxlite_die_init(void)
{
	/* NOTE: Boot Core Specific Code in SBI Dual
	 *
	 * Even if a boot core is booting from socket 1, we still need the
	 * SBI to prompt from socket 0. Thus the following logic is not
	 * boot core bug free. It assumes that the code is always executed
	 * by a socket 0 boot core in the SBI dual-socket evironment.
	 */
	if (sysreg_die_id() == 1) {
		k1mxlite_die_base = DIE1_BASE;
		k1mxlite_die_hart = DIE1_HART;
	}
}
#else
#define k1mxlite_die_init()		do { } while (0)
#endif

#ifdef CONFIG_K1MXLITE_BOOT_DDR

static void d2d_wait_boot(void)
{
	if (sysreg_die_id() == 0)
		__raw_writel(D2D_DIE1_BOOT, D2D_REG(2));
	else {
		while (!(__raw_readl(D2D_REG(2)) & D2D_DIE1_BOOT));
	}
}

void board_boot_ddr(void)
{
	void (*boot_entry)(void);

	d2d_wait_boot();

	boot_entry = (void *)__DDR_BASE;
	printf("B(D)\n");
	smp_boot_secondary_cpus((caddr_t)boot_entry);
	local_flush_icache_all();
	boot_entry();
}
#else
#define board_boot_ddr()	do { } while (0)
#endif

#ifdef CONFIG_K1MXLITE_BOOT
void board_boot(void)
{
	board_boot_ddr();
}
#else
#define board_boot()		do { } while (0)
#endif

void board_early_init(void)
{
	DEVICE_ARCH(DEVICE_ARCH_RISCV);
	k1mxlite_die_init();

#ifdef CONFIG_SPACEMIT_STM
	stm_hw_ctrl_init();
#endif
}

void board_late_init(void)
{
	k1mxlite_n100_init();
	pcie_ccix_linkup();
	k1mxlite_n100_d2d_init();

#ifdef CONFIG_SPACEMIT_STM
	stm_sync_2dies();
#endif

	board_boot();
}

#ifdef CONFIG_SMP
void board_smp_init(void)
{
}
#endif /* CONFIG_SMP */

#ifdef CONFIG_FINISH
#ifdef CONFIG_SBI
void board_finish(int code)
{
	sbi_finish(code);
}
#else /* CONFIG_SBI */
void board_finish(int code)
{
	if (code)
		k1mxlite_finish(1);
	else
		k1mxlite_finish(0);
}
#endif /* CONFIG_SBI */
#endif /* CONFIG_FINISH */

void board_shutdown(void)
{
	board_finish(0);
}

static int do_k1mxlite_shutdown(int argc, char *argv[])
{
	board_shutdown();
	return 0;
}

static int do_k1mxlite_reboot(int argc, char *argv[])
{
	board_reboot();
	return 0;
}

static int do_k1mxlite_info(int argc, char *argv[])
{
	printf("BOOT_SEL: %d\n", (int)sysreg_boot_sel());
	printf("DIE_ID:   %d\n", (int)sysreg_die_id());
	printf("CPU:      0x%04x\n", acpu_get_cpu_map());
	printf("CLUSTER:  0x%02x\n", acpu_get_cluster_map());
	return 0;
}

static int do_k1mxlite(int argc, char *argv[])
{
	if (argc < 2)
		return -EINVAL;

	if (strcmp(argv[1], "shutdown") == 0)
		return do_k1mxlite_shutdown(argc, argv);
	if (strcmp(argv[1], "reboot") == 0)
		return do_k1mxlite_reboot(argc, argv);
	if (strcmp(argv[1], "info") == 0)
		return do_k1mxlite_info(argc, argv);
	return -EINVAL;
}

DEFINE_COMMAND(k1mxlite, do_k1mxlite, "K1MXLite SoC global commands",
	"k1mxlite shutdown\n"
	"    -shutdown board\n"
	"k1mxlite reboot\n"
	"    -reboot board\n"
	"k1mxlite info\n"
	"    -simulation/boot mode information\n"
);
