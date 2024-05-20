/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2019 Western Digital Corporation or its affiliates.
 *
 * Authors:
 *   Atish Patra <atish.patra@wdc.com>
 *   Anup Patel <anup.patel@wdc.com>
 */

#include <target/sbi.h>
#include <target/tlb.h>
#include <target/cache.h>
#include <target/paging.h>
#include <sbi/sbi_pmu.h>

static unsigned long tlb_sync_off;
static unsigned long tlb_fifo_off;
static unsigned long tlb_fifo_mem_off;

void sbi_tlb_fifo_sfence_vma(struct sbi_tlb_info *tinfo)
{
	unsigned long start = tinfo->start;
	unsigned long size  = tinfo->size;
	unsigned long i;

	sbi_pmu_ctr_incr_fw(SBI_PMU_FW_SFENCE_VMA_RCVD);

	if ((start == 0 && size == 0) || (size == SBI_TLB_FLUSH_ALL)) {
		local_flush_tlb_all();
		return;
	}

	for (i = 0; i < size; i += PAGE_SIZE)
		local_flush_tlb_page(start + i);
}

void sbi_tlb_fifo_sfence_vma_asid(struct sbi_tlb_info *tinfo)
{
	unsigned long start = tinfo->start;
	unsigned long size  = tinfo->size;
	unsigned long asid  = tinfo->asid;
	unsigned long i;

	sbi_pmu_ctr_incr_fw(SBI_PMU_FW_SFENCE_VMA_ASID_RCVD);

	if (start == 0 && size == 0) {
		local_flush_tlb_all();
		return;
	}

	/* Flush entire MM context for a given ASID */
	if (size == SBI_TLB_FLUSH_ALL) {
		local_flush_tlb_asid_all(asid);
		return;
	}

	for (i = 0; i < size; i += PAGE_SIZE)
		local_flush_tlb_asid_page(asid, start + i);
}

#ifdef CONFIG_RISCV_H
void sbi_tlb_fifo_hfence_gvma(struct sbi_tlb_info *tinfo)
{
	unsigned long start = tinfo->start;
	unsigned long size  = tinfo->size;
	unsigned long i;

	sbi_pmu_ctr_incr_fw(SBI_PMU_FW_HFENCE_GVMA_RCVD);

	if ((start == 0 && size == 0) || (size == SBI_TLB_FLUSH_ALL)) {
		__sbi_hfence_gvma_all();
		return;
	}

	for (i = 0; i < size; i += PAGE_SIZE) {
		__sbi_hfence_gvma_gpa((start + i) >> 2);
	}
}

void sbi_tlb_fifo_hfence_gvma_vmid(struct sbi_tlb_info *tinfo)
{
	unsigned long start = tinfo->start;
	unsigned long size  = tinfo->size;
	unsigned long vmid  = tinfo->vmid;
	unsigned long i;

	sbi_pmu_ctr_incr_fw(SBI_PMU_FW_HFENCE_GVMA_VMID_RCVD);

	if (start == 0 && size == 0) {
		__sbi_hfence_gvma_all();
		return;
	}

	if (size == SBI_TLB_FLUSH_ALL) {
		__sbi_hfence_gvma_vmid(vmid);
		return;
	}

	for (i = 0; i < size; i += PAGE_SIZE) {
		__sbi_hfence_gvma_vmid_gpa((start + i) >> 2, vmid);
	}
}

void sbi_tlb_fifo_hfence_vvma(struct sbi_tlb_info *tinfo)
{
	unsigned long start = tinfo->start;
	unsigned long size  = tinfo->size;
	unsigned long vmid  = tinfo->vmid;
	unsigned long i, hgatp;

	sbi_pmu_ctr_incr_fw(SBI_PMU_FW_HFENCE_VVMA_RCVD);

	hgatp = csr_swap(CSR_HGATP,
			 (vmid << ATP_VMID_SHIFT) & ATP_VMID);

	if ((start == 0 && size == 0) || (size == SBI_TLB_FLUSH_ALL)) {
		__sbi_hfence_vvma_all();
		goto done;
	}

	for (i = 0; i < size; i += PAGE_SIZE) {
		__sbi_hfence_vvma_va(start+i);
	}

done:
	csr_write(CSR_HGATP, hgatp);
}

void sbi_tlb_fifo_hfence_vvma_asid(struct sbi_tlb_info *tinfo)
{
	unsigned long start = tinfo->start;
	unsigned long size  = tinfo->size;
	unsigned long asid  = tinfo->asid;
	unsigned long vmid  = tinfo->vmid;
	unsigned long i, hgatp;

	sbi_pmu_ctr_incr_fw(SBI_PMU_FW_HFENCE_VVMA_ASID_RCVD);

	hgatp = csr_swap(CSR_HGATP,
			 (vmid << ATP_VMID_SHIFT) & ATP_VMID);

	if (start == 0 && size == 0) {
		__sbi_hfence_vvma_all();
		goto done;
	}

	if (size == SBI_TLB_FLUSH_ALL) {
		__sbi_hfence_vvma_asid(asid);
		goto done;
	}

	for (i = 0; i < size; i += PAGE_SIZE) {
		__sbi_hfence_vvma_asid_va(start + i, asid);
	}

done:
	csr_write(CSR_HGATP, hgatp);
}
#endif

static void sbi_tlb_local_flush(struct sbi_tlb_info *tinfo)
{
	if (tinfo->type == SBI_TLB_FLUSH_VMA)
		sbi_tlb_fifo_sfence_vma(tinfo);
	else if (tinfo->type == SBI_TLB_FLUSH_VMA_ASID)
		sbi_tlb_fifo_sfence_vma_asid(tinfo);
#ifdef CONFIG_RISCV_H
	else if (tinfo->type == SBI_TLB_FLUSH_VVMA)
		sbi_tlb_fifo_hfence_vvma(tinfo);
	else if (tinfo->type == SBI_TLB_FLUSH_VVMA_ASID)
		sbi_tlb_fifo_hfence_vvma_asid(tinfo);
	else if (tinfo->type == SBI_TLB_FLUSH_GVMA)
		sbi_tlb_fifo_hfence_gvma(tinfo);
	else if (tinfo->type == SBI_TLB_FLUSH_GVMA_VMID)
		sbi_tlb_fifo_hfence_gvma_vmid(tinfo);
#endif
	else if (tinfo->type == SBI_ITLB_FLUSH)
		local_flush_icache_all();
	else
		sbi_printf("Invalid tlb flush request type [%lu]\n",
			   tinfo->type);
	return;
}

static void tlb_pmu_incr_fw_ctr(struct sbi_tlb_info *data)
{
	if (unlikely(!data))
		return;

	if (data->local_fn == sbi_tlb_fifo_sfence_vma)
		sbi_pmu_ctr_incr_fw(SBI_PMU_FW_SFENCE_VMA_SENT);
	else if (data->local_fn == sbi_tlb_fifo_sfence_vma_asid)
		sbi_pmu_ctr_incr_fw(SBI_PMU_FW_SFENCE_VMA_ASID_SENT);
#ifdef CONFIG_RISCV_H
	else if (data->local_fn == sbi_tlb_fifo_hfence_gvma)
		sbi_pmu_ctr_incr_fw(SBI_PMU_FW_HFENCE_GVMA_SENT);
	else if (data->local_fn == sbi_tlb_fifo_hfence_gvma_vmid)
		sbi_pmu_ctr_incr_fw(SBI_PMU_FW_HFENCE_GVMA_VMID_SENT);
	else if (data->local_fn == sbi_tlb_fifo_hfence_vvma)
		sbi_pmu_ctr_incr_fw(SBI_PMU_FW_HFENCE_VVMA_SENT);
	else if (data->local_fn == sbi_tlb_fifo_hfence_vvma_asid)
		sbi_pmu_ctr_incr_fw(SBI_PMU_FW_HFENCE_VVMA_ASID_SENT);
#endif
}

static void sbi_tlb_entry_process(struct sbi_scratch *scratch,
				  struct sbi_tlb_info *tinfo)
{
	uint32_t i;
	uint64_t m;
	struct sbi_scratch *rscratch = NULL;
	unsigned long *rtlb_sync = NULL;

	sbi_tlb_local_flush(tinfo);
	for (i = 0, m = tinfo->shart_mask; m; i++, m >>= 1) {
		if (!(m & 1UL))
			continue;

		rscratch = sbi_hart_id_to_scratch(scratch, i);
		rtlb_sync = sbi_scratch_offset_ptr(rscratch, tlb_sync_off);
		while (xchg(rtlb_sync, 1)) ;
	}
}

static void sbi_tlb_fifo_process_count(struct sbi_scratch *scratch, int count)
{
	struct sbi_tlb_info tinfo;
	uint32_t deq_count = 0;
	struct sbi_fifo *tlb_fifo =
		sbi_scratch_offset_ptr(scratch, tlb_fifo_off);

	while (!sbi_fifo_dequeue(tlb_fifo, &tinfo)) {
		sbi_tlb_entry_process(scratch, &tinfo);
		deq_count++;
		if (deq_count > count)
			break;
	}
}

void sbi_tlb_fifo_process(struct sbi_scratch *scratch)
{
	struct sbi_tlb_info tinfo;
	struct sbi_fifo *tlb_fifo =
			sbi_scratch_offset_ptr(scratch, tlb_fifo_off);

	while (!sbi_fifo_dequeue(tlb_fifo, &tinfo))
		sbi_tlb_entry_process(scratch, &tinfo);
}

void sbi_tlb_fifo_sync(struct sbi_scratch *scratch)
{
	unsigned long *tlb_sync =
		sbi_scratch_offset_ptr(scratch, tlb_sync_off);

	while (!xchg(tlb_sync, 0)) {
		/*
		 * While we are waiting for remote hart to set the sync,
		 * consume fifo requests to avoid deadlock.
		 */
		sbi_tlb_fifo_process_count(scratch, 1);
	}

	return;
}

static inline int __sbi_tlb_fifo_range_check(struct sbi_tlb_info *curr,
					     struct sbi_tlb_info *next)
{
	unsigned long curr_end;
	unsigned long next_end;
	int ret = SBI_FIFO_UNCHANGED;

	if (!curr || !next)
		return ret;

	next_end = next->start + next->size;
	curr_end = curr->start + curr->size;
	if (next->start <= curr->start && next_end > curr_end) {
		curr->start = next->start;
		curr->size  = next->size;
		curr->shart_mask = curr->shart_mask | next->shart_mask;
		ret	    = SBI_FIFO_UPDATED;
	} else if (next->start >= curr->start && next_end <= curr_end) {
		curr->shart_mask = curr->shart_mask | next->shart_mask;
		ret		 = SBI_FIFO_SKIP;
	}

	return ret;
}

/**
 * Call back to decide if an inplace fifo update is required or next entry can
 * can be skipped. Here are the different cases that are being handled.
 *
 * Case1:
 *	if next flush request range lies within one of the existing entry, skip
 *	the next entry.
 * Case2:
 *	if flush request range in current fifo entry lies within next flush
 *	request, update the current entry.
 *
 * Note:
 *	We can not issue a fifo reset anymore if a complete vma flush is requested.
 *	This is because we are queueing FENCE.I requests as well now.
 *	To ease up the pressure in enqueue/fifo sync path, try to dequeue 1 element
 *	before continuing the while loop. This method is preferred over wfi/ipi because
 *	of MMIO cost involved in later method.
 */
static int sbi_tlb_fifo_update_cb(void *in, void *data)
{
	struct sbi_tlb_info *curr;
	struct sbi_tlb_info *next;
	int ret = SBI_FIFO_UNCHANGED;

	if (!in || !!data)
		return ret;

	curr = (struct sbi_tlb_info *)data;
	next = (struct sbi_tlb_info *)in;

	if (next->type == SBI_TLB_FLUSH_VMA_ASID &&
	    curr->type == SBI_TLB_FLUSH_VMA_ASID) {
		if (next->asid == curr->asid)
			ret = __sbi_tlb_fifo_range_check(curr, next);
	} else if (next->type == SBI_TLB_FLUSH_VMA &&
		   curr->type == SBI_TLB_FLUSH_VMA) {
		ret = __sbi_tlb_fifo_range_check(curr, next);
	}
	return ret;
}

int sbi_tlb_fifo_update(struct sbi_scratch *rscratch,
			uint32_t hartid, void *data)
{
	int ret;
	struct sbi_fifo *tlb_fifo_r;
	struct sbi_scratch *lscratch;
	struct sbi_tlb_info *tinfo = data;
	uint32_t curr_hartid = sbi_current_hartid();

	/*
	 * If address range to flush is too big then simply
	 * upgrade it to flush all because we can only flush
	 * 4KB at a time.
	 */
	if (tinfo->size >= SBI_TLB_FLUSH_MAX_SIZE) {
		tinfo->start = 0;
		tinfo->size = SBI_TLB_FLUSH_ALL;
	}

	/*
	 * If the request is to queue a tlb flush entry for itself
	 * then just do a local flush and return;
	 */
	if (hartid == curr_hartid) {
		sbi_tlb_local_flush(tinfo);
		return -1;
	}

	lscratch = sbi_hart_id_to_scratch(rscratch, curr_hartid);
	tlb_fifo_r = sbi_scratch_offset_ptr(rscratch, tlb_fifo_off);

	ret = sbi_fifo_inplace_update(tlb_fifo_r, data, sbi_tlb_fifo_update_cb);
	if (ret != SBI_FIFO_UNCHANGED) {
		return 1;
	}

	while (sbi_fifo_enqueue(tlb_fifo_r, data) < 0) {
		/**
		 * For now, Busy loop until there is space in the fifo.
		 * There may be case where target hart is also
		 * enqueue in source hart's fifo. Both hart may busy
		 * loop leading to a deadlock.
		 * TODO: Introduce a wait/wakeup event mechanism to handle
		 * this properly.
		 */
		sbi_tlb_fifo_process_count(lscratch, 1);
		sbi_printf("hart%d: hart%d tlb fifo full\n",
			   curr_hartid, hartid);
	}

	return 0;
}

int sbi_tlb_request(unsigned long hmask, unsigned long hbase,
		     struct sbi_tlb_info *tinfo)
{
#if 0
	if (!tinfo->local_fn)
		return SBI_EINVAL;
#endif
	tlb_pmu_incr_fw_ctr(tinfo);

	return sbi_ipi_send_many(hmask, hbase, SBI_IPI_EVENT_RFENCE, tinfo);
}

int sbi_tlb_fifo_init(struct sbi_scratch *scratch, bool cold_boot)
{
	void *tlb_mem;
	unsigned long *tlb_sync;
	struct sbi_fifo *tlb_q;

	if (cold_boot) {
		tlb_sync_off = sbi_scratch_alloc_offset(sizeof(*tlb_sync),
							    "IPI_TLB_SYNC");
		if (!tlb_sync_off)
			return -ENOMEM;
		
		tlb_fifo_off = sbi_scratch_alloc_offset(sizeof(*tlb_q),
							    "IPI_TLB_FIFO");
		if (!tlb_fifo_off) {
			sbi_scratch_free_offset(tlb_sync_off);
			return -ENOMEM;
		}

		tlb_fifo_mem_off = sbi_scratch_alloc_offset(
				SBI_TLB_FIFO_NUM_ENTRIES * SBI_TLB_INFO_SIZE,
				"IPI_TLB_FIFO_MEM");
		if (!tlb_fifo_mem_off) {
			sbi_scratch_free_offset(tlb_fifo_off);
			sbi_scratch_free_offset(tlb_sync_off);
			return -ENOMEM;
		}
	} else {
		if (!tlb_sync_off ||
		    !tlb_fifo_off ||
		    !tlb_fifo_mem_off)
			return -ENOMEM;
	}

	tlb_sync = sbi_scratch_offset_ptr(scratch, tlb_sync_off);
	tlb_q = sbi_scratch_offset_ptr(scratch, tlb_fifo_off);
	tlb_mem = sbi_scratch_offset_ptr(scratch, tlb_fifo_mem_off);

	*tlb_sync = 0;

	sbi_fifo_init(tlb_q, tlb_mem,
		      SBI_TLB_FIFO_NUM_ENTRIES, SBI_TLB_INFO_SIZE);
	return 0;
}
