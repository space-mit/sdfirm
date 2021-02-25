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
 * @(#)ssi_flash.c: DUOWEN specific SSI flash implementation
 * $Id: ssi_flash.c,v 1.1 2020-12-30 17:15:00 zhenglv Exp $
 */

#include <target/spiflash.h>
#include <target/cmdline.h>
#include <target/mem.h>
#include <target/uefi.h>
#include <target/irq.h>

mtd_t board_flash = INVALID_MTD_ID;

static inline void spi_config_pad(uint16_t pin, uint8_t pad, uint8_t func)
{
	gpio_config_pad(SSI_PORT, pin, pad, 8);
	gpio_config_mux(SSI_PORT, pin, func);
}

void spi_hw_ctrl_init(void)
{
	spi_config_pad(SSI_PIN_RXD, GPIO_PAD_PULL_DOWN, TLMM_PAD_FUNCTION);
	spi_config_pad(SSI_PIN_TXD, GPIO_PAD_PULL_DOWN, TLMM_PAD_FUNCTION);
	spi_config_pad(SSI_PIN_SCK, GPIO_PAD_PULL_DOWN, TLMM_PAD_FUNCTION);
	spi_config_pad(SSI_PIN_SS, GPIO_PAD_PULL_UP, TLMM_PAD_FUNCTION);
	spi_config_pad(SSI_PIN_SS_IN, GPIO_PAD_PULL_UP, TLMM_PAD_FUNCTION);

	clk_enable(DW_SSI_CLK);
	dw_ssi_init_master(SSI_ID, SSI_FRF_SPI,
			   SSI_TMOD_EEPROM_READ, 8, 8);
	dw_ssi_init_spi(SSI_ID, SSI_SPI_FRF_STD,
			8, 24, 0);
}

void duowen_ssi_flash_init(void)
{
	board_flash = spiflash_register_bank(0);
	if (board_flash == INVALID_MTD_ID)
		bh_panic();
}

static inline void duowen_ssi_flash_select(uint32_t chips)
{
	__raw_clearl(SSI_EN, SSI_SSIENR(0));
	__raw_writel(chips, SSI_SER(0));
	__raw_setl(SSI_EN, SSI_SSIENR(0));
}

static inline void duowen_ssi_flash_writeb(uint8_t byte)
{
	while (!(__raw_readl(SSI_RISR(0)) & SSI_TXEI));
	__raw_writel(byte, SSI_DR(0, 0));
}

static inline uint8_t duowen_ssi_flash_readb(void)
{
        while (!(__raw_readl(SSI_RISR(0)) & SSI_RXFI));
        return __raw_readl(SSI_DR(0, 0));
}

static inline uint8_t duowen_ssi_flash_read(uint32_t addr)
{
	uint8_t byte;

	duowen_ssi_flash_select(_BV(0));
	duowen_ssi_flash_writeb(SF_READ_DATA);
	duowen_ssi_flash_writeb((uint8_t)(addr >> 16));
	duowen_ssi_flash_writeb((uint8_t)(addr >> 8));
	duowen_ssi_flash_writeb((uint8_t)(addr >> 0));
	byte = duowen_ssi_flash_readb();
	duowen_ssi_flash_select(0);
	return byte;
}

void __duowen_ssi_flash_boot(void *boot, uint32_t addr, uint32_t size)
{
	int i;
	uint8_t *dst = boot;
	void (*boot_entry)(void) = boot;

	for (i = 0; i < size; i++, addr++)
		dst[i] = duowen_ssi_flash_read(addr);
	boot_entry();
}

void duowen_ssi_flash_boot(void *boot, uint32_t addr, uint32_t size)
{
	duowen_boot_cb boot_func;
#ifdef CONFIG_DUOWEN_BOOT_STACK
	__align(32) uint8_t boot_from_stack[256];

	boot_func = (duowen_boot_cb)boot_from_stack;
	memcpy(boot_from_stack, __duowen_ssi_flash_boot, 256);
#else
	boot_func = __duowen_ssi_flash_boot;
#endif
	boot_func(boot, addr, size);
	unreachable();
}

static int do_flash_dump(int argc, char *argv[])
{
	uint8_t buffer[GPT_LBA_SIZE];
	uint32_t addr = 128;
	size_t size = 32;

	if (argc > 2)
		addr = strtoul(argv[2], NULL, 0);
	if (argc > 3)
		size = strtoul(argv[3], NULL, 0);
	if (size > GPT_LBA_SIZE) {
		printf("size should be less or equal than %d\n",
		       GPT_LBA_SIZE);
		return -EINVAL;
	}
	gpt_mtd_copy(board_flash, buffer, addr, size);
	hexdump(0, buffer, 1, size);
	return 0;
}

#ifdef CONFIG_DUOWEN_SSI_FLASH_IRQ
static uint32_t dw_ssi_irqs;

static void duowen_ssi_handler(irq_t irq)
{
	uint32_t irqs = dw_ssi_irqs_status(SSI_ID);

	if ((irqs & SSI_TXEI) && !(dw_ssi_irqs & SSI_TXEI)) {
		dw_ssi_disable_irqs(SSI_ID, SSI_TXEI);
		dw_ssi_irqs |= SSI_TXEI;
		dw_ssi_write_dr(SSI_ID, SF_READ_STATUS_1);
	}
	if ((irqs & SSI_RXFI) && !(dw_ssi_irqs & SSI_RXFI)) {
		dw_ssi_disable_irqs(SSI_ID, SSI_RXFI);
		dw_ssi_irqs |= SSI_RXFI;
		(void)dw_ssi_read_dr(SSI_ID);
	}
	dw_ssi_clear_irqs(SSI_ID, irqs);
	irqc_ack_irq(IRQ_SPI);
}

void duowen_ssi_irq_init(void)
{
	irqc_configure_irq(IRQ_SPI, 0, IRQ_LEVEL_TRIGGERED);
	irq_register_vector(IRQ_SPI, duowen_ssi_handler);
}

static int do_flash_irq(int argc, char *argv[])
{
	uint32_t irqs = SSI_RXFI | SSI_TXEI;
	mtd_t smtd;

	smtd = mtd_save_device(board_flash);
	mtd_open(OPEN_READ, 0, 8);
	mtd_close();
	mtd_restore_device(smtd);
	printf("IRQ test enabled.\n");

	dw_ssi_irqs = 0;

	dw_ssi_select_chip(SSI_ID, 0);
	dw_ssi_enable_irqs(SSI_ID, irqs);
	irqc_enable_irq(IRQ_SPI);
	while (dw_ssi_irqs != irqs) {
		irq_local_enable();
		irq_local_disable();
	}
	irqc_disable_irq(IRQ_SPI);
	dw_ssi_disable_irqs(SSI_ID, irqs);
	dw_ssi_deselect_chips(SSI_ID);
	printf("IRQ test passed.\n");
	return 0;
}
#else
static int do_flash_irq(int argc, char *argv[])
{
	printf("IRQ test disabled.\n");
	return -EINVAL;
}
#endif

static int do_flash(int argc, char *argv[])
{
	if (argc < 2)
		return -EINVAL;

	if (strcmp(argv[1], "dump") == 0)
		return do_flash_dump(argc, argv);
	if (strcmp(argv[1], "gpt") == 0) {
		gpt_mtd_dump(board_flash);
		return 0;
	}
	if (strcmp(argv[1], "irq") == 0)
		return do_flash_irq(argc, argv);
	return -ENODEV;
}

DEFINE_COMMAND(flash, do_flash, "SSI flash commands",
	"dump [addr] [size]\n"
	"    - dump content of SSI flash\n"
	"      addr: default to 128\n"
	"      size: default to 32\n"
	"gpt\n"
	"    - dump GPT partitions from SSI flash\n"
	"irq\n"
	"    - testing SSI IRQ\n"
);
