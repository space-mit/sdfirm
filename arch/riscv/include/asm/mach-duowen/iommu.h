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
 * @(#)iommu.h: DUOWEN input-output (IO) MMU interface
 * $Id: iommu.h,v 1.1 2020-10-17 07:40:00 zhenglv Exp $
 */

#ifndef __IOMMU_DUOWEN_H_INCLUDE__
#define __IOMMU_DUOWEN_H_INCLUDE__

#include <target/arch.h>

#ifdef CONFIG_DUOWEN_SBI_DUAL
#define DUOWEN_SMMU_SOC(smmu)	(((smmu) & 0x02) >> 1)
#define DUOWEN_SMMU_DEV(smmu)	((smmu) & 0x01)
#define SMMU_BASE(smmu)		\
	(__DMA_SMMU_BASE + (DUOWEN_SMMU_SOC(smmu) ? SOC1_BASE : SOC0_BASE) + (DUOWEN_SMMU_DEV(smmu) << 22))
#define SMMU_HW_MAX_CTRLS	4
#else
#define SMMU_BASE(smmu)		(DMA_SMMU_BASE + ((smmu) << 22))
#define SMMU_HW_MAX_CTRLS	2
#endif
#define SMMU_HW_TRANS		SMMU_FEAT_TRANS_S1
#define SMMU_HW_PTFS		(SMMU_FEAT_PTFS_RISCV_SV39 | \
				 SMMU_FEAT_PTFS_RISCV_SV48 | \
				 SMMU_FEAT_PTFS_ARCH64_4K | \
				 SMMU_FEAT_PTFS_ARCH64_64K)
#define SMMU_HW_NUMSIDB		15
#define SMMU_HW_NUMSMRG		32
#define SMMU_HW_PAGESIZE	0x1000
#define SMMU_HW_NUMPAGENDXB	3
#define SMMU_HW_NUMCB		16
#define SMMU_HW_NUMS2CB		0
#define SMMU_HW_IAS		48
#define SMMU_HW_OAS		48
#define SMMU_HW_UBS		48

/* iommu_dev_t */
#define IOMMU_DMAC		0
#define IOMMU_PCIE		1
#ifdef CONFIG_DUOWEN_SBI_DUAL
#define IOMMU_DMAC1		2
#define IOMMU_PCIE1		3
#endif

#include <driver/smarco_rvsmmu.h>

#if defined(CONFIG_DUOWEN_SMMU_SV)
#ifndef ARCH_HAVE_IOMMU
#define ARCH_HAVE_IOMMU		1

#define SMMU_HW_NUMSMES(n)	smmu_num_sms[n]

/* smmu_sme_t */
#define SMMU_SME_DMA_TBU0	SMMU_SME(IOMMU_DMAC, 0)
#define SMMU_SME_DMA_TBU1	SMMU_SME(IOMMU_DMAC, 1)
#define SMMU_SME_DMA_TBU2	SMMU_SME(IOMMU_DMAC, 2)
#define SMMU_SME_DMA_TBU3	SMMU_SME(IOMMU_DMAC, 3)
#define SMMU_SME_DMA_TBU4	SMMU_SME(IOMMU_DMAC, 4)
#define SMMU_SME_DMA_TBU5	SMMU_SME(IOMMU_DMAC, 5)
#define SMMU_SME_DMA_TBU6	SMMU_SME(IOMMU_DMAC, 6)
#define SMMU_SME_DMA_TBU7	SMMU_SME(IOMMU_DMAC, 7)
#define NR_DMA_IOMMUS		8
#define SMMU_SME_PCIE_TBU0	SMMU_SME(IOMMU_PCIE, 0)
#define SMMU_SME_PCIE_TBU1	SMMU_SME(IOMMU_PCIE, 1)
#define SMMU_SME_PCIE_TBU2	SMMU_SME(IOMMU_PCIE, 2)
#define SMMU_SME_PCIE_TBU3	SMMU_SME(IOMMU_PCIE, 3)
#define NR_PCIE_IOMMUS		4

#define NR_IOMMUS		(NR_DMA_IOMMUS + NR_PCIE_IOMMUS)
#else
#error "Multiple IOMMU controller defined"
#endif
#endif

#ifdef ARCH_HAVE_IOMMU
#define iommu_hw_ctrl_init()				smmu_device_init()
#define iommu_hw_domain_select()			smmu_domain_select()
#define iommu_hw_alloc_master(iommu)			smmu_alloc_sme(iommu)

#define iommu_hw_tlb_flush_all()			\
	smmu_tlb_inv_context_s1()
#define iommu_hw_tlb_flush_walk(iova, size, granule)	\
	smmu_tlb_inv_walk_s1(iova, size, granule)
#define iommu_hw_tlb_flush_leaf(iova, size, granule)	\
	smmu_tlb_inv_leaf_s1(iova, size, granule)
#define iommu_hw_tlb_add_page(iova, granule)	\
	smmu_tlb_add_page_s1(iova, granule)

#define iommu_hw_map(iova, pgsize, paddr, prot)		0
#define iommu_hw_unmap(iova, pgsize, gather)		0
#define iommu_hw_iotlb_sync(gather)			do { } while (0)

#define iommu_hw_alloc_table(cfg)			0
#define iommu_hw_free_table()				do { } while (0)

#define smmu_hw_ctrl_reset(reg)				(reg)

extern smmu_gr_t smmu_num_sms[];
#endif /* ARCH_HAVE_IOMMU */

#ifdef CONFIG_DUOWEN_SMMU
void duowen_smmu_pma_init(void);
#else
#define duowen_smmu_pma_init()				do { } while (0)
#endif

#endif /* __IOMMU_DUOWEN_H_INCLUDE__ */
