/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 *  Copyright (C) 2022 CAS SmartCore Co., Ltd.
 *    Author: 2022 Lv Zheng <zhenglv@smart-core.cn>
 */

#ifndef __DT_BINDINGS_DPU_DDR_H
#define __DT_BINDINGS_DPU_DDR_H

#define DPU_DDRLO(w)			((w) & 0xFFFFFFFF)
#define DPU_DDRHI(w)			(((w) & 0xFFFFFFFF00000000) >>32)

#ifdef CONFIG_DPU_GEN2
#define DDR0_DATA_BASE		0x400000000
#define DDR1_DATA_BASE		0x800000000
#else /* CONFIG_DPU_GEN2 */
#define DDR0_DATA_BASE		0x400000000
#define DDR1_DATA_BASE		0x800000000
#endif /* CONFIG_DPU_GEN2 */

/* DDR address space:
 * Default interleaved mode:
 * DDR1 base, DDR1 address space size
 * Non-interleaved mode:
 */
#define DDR0_DATA_SIZE		0x400000000
#define DDR1_DATA_SIZE		0x400000000

#ifdef CONFIG_DPU_DDR_INTLV
#define DDR_DATA_BASE		DDR1_DATA_BASE
#define DDR_DATA_SIZE		(DDR0_DATA_SIZE + DDR1_DATA_SIZE)
#else /* CONFIG_DPU_DDR_INTLV */
#ifdef CONFIG_DPU_DDR_BANK0
#define DDR_DATA_BASE		DDR0_DATA_BASE
#ifdef CONFIG_DPU_DDR_BANK1
#define DDR_DATA_SIZE		(DDR0_DATA_SIZE + DDR1_DATA_SIZE)
#else /* CONFIG_DPU_DDR_BANK1 */
#ifdef CONFIG_DPU_SIM_DDR_SIZE32
#define DDR_DATA_SIZE		(DDR0_DATA_SIZE + DDR1_DATA_SIZE)
#else /* CONFIG_DPU_DDR_SIZE32 */
#define DDR_DATA_SIZE		DDR0_DATA_SIZE
#endif /* CONFIG_DPU_DDR_SIZE32 */
#endif /* CONFIG_DPU_DDR_BANK1 */
#else /* CONFIG_DPU_DDR_BANK0 */
#ifdef CONFIG_DPU_SIM_DDR_BASE16
#define DDR_DATA_BASE		DDR0_DATA_BASE
#else /* CONFIG_DPU_SIM_DDR_BASE16 */
#define DDR_DATA_BASE		DDR1_DATA_BASE
#endif /* CONFIG_DPU_SIM_DDR_BASE16 */
#ifdef CONFIG_DPU_SIM_DDR_SIZE32
#define DDR_DATA_SIZE		(DDR0_DATA_SIZE + DDR1_DATA_SIZE)
#else /* CONFIG_DPU_SIM_DDR_SIZE32 */
#define DDR_DATA_SIZE		DDR1_DATA_SIZE
#endif /* CONFIG_DPU_SIM_DDR_SIZE32 */
#endif /* CONFIG_DPU_DDR_BANK0 */
#endif /* CONFIG_DPU_DDR_INTLV */

#ifdef CONFIG_DPU_SIM_DDR_BOOT
#undef DDR_DATA_BASE
#undef DDR_DATA_SIZE
#define DDR_DATA_BASE		DDR1_DATA_BASE
#define DDR_DATA_SIZE		(512 * 1024 * 1024)
#endif /* CONFIG_DPU_SIM_DDR_BOOT */

#endif /* __DT_BINDINGS_DPU_DDR_H */