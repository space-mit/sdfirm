#ifndef __LPC_K1MATRIX_H_INCLUDE__
#define __LPC_K1MATRIX_H_INCLUDE__

#include <target/clk.h>

#define lpc_clk                         rmu_lpc_clk
#define lpc_lclk                        rmu_lpc_lclk
#define SPACEMIT_LPC_CFG_BASE		__RMU_LPC_CFG_BASE
#define SPACEMIT_LPC_IO_BASE            __RMU_LPC_IO_BASE
#define SPACEMIT_LPC_MEM_BASE           __RMU_LPC_FLASH_BASE
#define CORELPC_BASE			__RMU_LPC_IO_BASE

#ifndef ARCH_HAVE_LPC
#define ARCH_HAVE_LPC			1
#else
#error "Multiple LPC controller defined"
#endif
#define LPC_HW_SERIRQ_NUM		17
#define LPC_HW_SERIRQ_IDLE		0
#define LPC_HW_SERIRQ_START		4

#ifdef CONFIG_K1MATRIX_LPC
#include <driver/spacemit_lpc.h>
#endif

#define lpc_hw_ctrl_init()		k1matrix_lpc_init()

void k1matrix_lpc_init(void);

#endif /* __LPC_K1MATRIX_H_INCLUDE__ */
