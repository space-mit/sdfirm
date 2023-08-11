/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2020 Western Digital Corporation or its affiliates.
 *
 * Authors:
 *   Atish Patra <atish.patra@wdc.com>
 */

#ifndef __SBI_HSM_H__
#define __SBI_HSM_H__

#include <target/types.h>
#include <target/sbi.h>

/** Hart state values **/
#define SBI_HART_STOPPED	0
#define SBI_HART_STOPPING	1
#define SBI_HART_STARTING	2
#define SBI_HART_STARTED	3

int sbi_hsm_init(struct sbi_scratch *scratch, uint32_t hartid, bool cold_boot);
void __noreturn sbi_hsm_exit(struct sbi_scratch *scratch);

int sbi_hsm_hart_start(struct sbi_scratch *scratch, uint32_t hartid,
			   uint64_t saddr, uint64_t priv);
int sbi_hsm_hart_stop(struct sbi_scratch *scratch, bool exitnow);
int sbi_hsm_hart_get_state(struct sbi_scratch *scratch, uint32_t hartid);
int sbi_hsm_hart_state_to_status(int state);
bool sbi_hsm_hart_started(struct sbi_scratch *scratch, uint32_t hartid);
void sbi_hsm_prepare_next_jump(struct sbi_scratch *scratch, uint32_t hartid);
#endif
