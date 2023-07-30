#include <target/kbuild.h>
#include <target/task.h>
#include <target/sbi.h>

int main(void)
{
#ifdef CONFIG_TASK
	OFFSET(TASK_THREAD_RA, task_entry, thread.ra);
	OFFSET(TASK_THREAD_SP, task_entry, thread.sp);
	OFFSET(TASK_THREAD_S0, task_entry, thread.s[0]);
	OFFSET(TASK_THREAD_S1, task_entry, thread.s[1]);
	OFFSET(TASK_THREAD_S2, task_entry, thread.s[2]);
	OFFSET(TASK_THREAD_S3, task_entry, thread.s[3]);
	OFFSET(TASK_THREAD_S4, task_entry, thread.s[4]);
	OFFSET(TASK_THREAD_S5, task_entry, thread.s[5]);
	OFFSET(TASK_THREAD_S6, task_entry, thread.s[6]);
	OFFSET(TASK_THREAD_S7, task_entry, thread.s[7]);
	OFFSET(TASK_THREAD_S8, task_entry, thread.s[8]);
	OFFSET(TASK_THREAD_S9, task_entry, thread.s[9]);
	OFFSET(TASK_THREAD_S10, task_entry, thread.s[10]);
	OFFSET(TASK_THREAD_S11, task_entry, thread.s[11]);
	OFFSET(TASK_THREAD_SP, task_entry, thread.sp);
	OFFSET(TASK_THREAD_CPU, task_entry, thread.cpu);
#endif

	OFFSET(TASK_KERN_SP, task_entry, kern_sp);
	OFFSET(TASK_USER_SP, task_entry, user_sp);

	DEFINE(SCRATCH_SIZE, sizeof(struct scratch));
	OFFSET(SCRATCH_SP, scratch, sp);

	DEFINE(PT_SIZE, sizeof(struct pt_regs));
	OFFSET(PT_ZERO, pt_regs, zero);
	OFFSET(PT_EPC, pt_regs, epc);
	OFFSET(PT_RA, pt_regs, ra);
	OFFSET(PT_FP, pt_regs, s0);
	OFFSET(PT_S0, pt_regs, s0);
	OFFSET(PT_S1, pt_regs, s1);
	OFFSET(PT_S2, pt_regs, s2);
	OFFSET(PT_S3, pt_regs, s3);
	OFFSET(PT_S4, pt_regs, s4);
	OFFSET(PT_S5, pt_regs, s5);
	OFFSET(PT_S6, pt_regs, s6);
	OFFSET(PT_S7, pt_regs, s7);
	OFFSET(PT_S8, pt_regs, s8);
	OFFSET(PT_S9, pt_regs, s9);
	OFFSET(PT_S10, pt_regs, s10);
	OFFSET(PT_S11, pt_regs, s11);
	OFFSET(PT_SP, pt_regs, sp);
	OFFSET(PT_TP, pt_regs, tp);
	OFFSET(PT_A0, pt_regs, a0);
	OFFSET(PT_A1, pt_regs, a1);
	OFFSET(PT_A2, pt_regs, a2);
	OFFSET(PT_A3, pt_regs, a3);
	OFFSET(PT_A4, pt_regs, a4);
	OFFSET(PT_A5, pt_regs, a5);
	OFFSET(PT_A6, pt_regs, a6);
	OFFSET(PT_A7, pt_regs, a7);
	OFFSET(PT_T0, pt_regs, t0);
	OFFSET(PT_T1, pt_regs, t1);
	OFFSET(PT_T2, pt_regs, t2);
	OFFSET(PT_T3, pt_regs, t3);
	OFFSET(PT_T4, pt_regs, t4);
	OFFSET(PT_T5, pt_regs, t5);
	OFFSET(PT_T6, pt_regs, t6);
	OFFSET(PT_GP, pt_regs, gp);
	OFFSET(PT_ORIG_A0, pt_regs, orig_a0);
	OFFSET(PT_STATUS, pt_regs, status);
	OFFSET(PT_BADADDR, pt_regs, badaddr);
	OFFSET(PT_CAUSE, pt_regs, cause);
	/*
	 * We allocate a pt_regs on the stack when entering the kernel.  This
	 * ensures the alignment is sane.
	 */
	DEFINE(PT_SIZE_ON_STACK, ALIGN(sizeof(struct pt_regs), STACK_ALIGN));

	OFFSET(SBI_SCRATCH_FW_START, sbi_scratch, fw_start);
	OFFSET(SBI_SCRATCH_FW_SIZE, sbi_scratch, fw_size);
	OFFSET(SBI_SCRATCH_NEXT_ARG1, sbi_scratch, next_arg1);
	OFFSET(SBI_SCRATCH_NEXT_ADDR, sbi_scratch, next_addr);
	OFFSET(SBI_SCRATCH_NEXT_MODE, sbi_scratch, next_mode);
	OFFSET(SBI_SCRATCH_WARMBOOT_ADDR, sbi_scratch, warmboot_addr);
	OFFSET(SBI_SCRATCH_PLATFORM_ADDR, sbi_scratch, platform_addr);
	OFFSET(SBI_SCRATCH_HARTID_TO_SCRATCH, sbi_scratch, hartid_to_scratch);
	OFFSET(SBI_SCRATCH_TMP0, sbi_scratch, tmp0);
	OFFSET(SBI_SCRATCH_OPTIONS, sbi_scratch, options);
	OFFSET(SBI_SCRATCH_EXTRA_SPACE, sbi_scratch, extra_space);

	OFFSET(SBI_PLATFORM_OPENSBI_VERSION, sbi_platform, opensbi_version);
	OFFSET(SBI_PLATFORM_PLATFORM_VERSION, sbi_platform, platform_version);
	OFFSET(SBI_PLATFORM_NAME, sbi_platform, name);
	OFFSET(SBI_PLATFORM_FEATURES, sbi_platform, features);
	OFFSET(SBI_PLATFORM_DISABLED_HART_MASK, sbi_platform, disabled_hart_mask);
	OFFSET(SBI_PLATFORM_PLATFORM_OPS_ADDR, sbi_platform, platform_ops_addr);
	OFFSET(SBI_PLATFORM_FIRMWARE_CONTEXT, sbi_platform, firmware_context);

	OFFSET(CSR_TRAP_INFO_EPC, csr_trap_info, epc);
	OFFSET(CSR_TRAP_INFO_CAUSE, csr_trap_info, cause);
	OFFSET(CSR_TRAP_INFO_TVAL, csr_trap_info, tval);
	OFFSET(CSR_TRAP_INFO_TVAL2, csr_trap_info, tval2);
	OFFSET(CSR_TRAP_INFO_TINST, csr_trap_info, tinst);
	OFFSET(CSR_TRAP_INFO_GVA, csr_trap_info, gva);

#ifdef CONFIG_TASK
	DEFINE(TASK_THREAD_RA_RA,
		  offsetof(struct task_entry, thread.ra)
		- offsetof(struct task_entry, thread.ra)
	);
	DEFINE(TASK_THREAD_SP_RA,
		  offsetof(struct task_entry, thread.sp)
		- offsetof(struct task_entry, thread.ra)
	);
	DEFINE(TASK_THREAD_S0_RA,
		  offsetof(struct task_entry, thread.s[0])
		- offsetof(struct task_entry, thread.ra)
	);
	DEFINE(TASK_THREAD_S1_RA,
		  offsetof(struct task_entry, thread.s[1])
		- offsetof(struct task_entry, thread.ra)
	);
	DEFINE(TASK_THREAD_S2_RA,
		  offsetof(struct task_entry, thread.s[2])
		- offsetof(struct task_entry, thread.ra)
	);
	DEFINE(TASK_THREAD_S3_RA,
		  offsetof(struct task_entry, thread.s[3])
		- offsetof(struct task_entry, thread.ra)
	);
	DEFINE(TASK_THREAD_S4_RA,
		  offsetof(struct task_entry, thread.s[4])
		- offsetof(struct task_entry, thread.ra)
	);
	DEFINE(TASK_THREAD_S5_RA,
		  offsetof(struct task_entry, thread.s[5])
		- offsetof(struct task_entry, thread.ra)
	);
	DEFINE(TASK_THREAD_S6_RA,
		  offsetof(struct task_entry, thread.s[6])
		- offsetof(struct task_entry, thread.ra)
	);
	DEFINE(TASK_THREAD_S7_RA,
		  offsetof(struct task_entry, thread.s[7])
		- offsetof(struct task_entry, thread.ra)
	);
	DEFINE(TASK_THREAD_S8_RA,
		  offsetof(struct task_entry, thread.s[8])
		- offsetof(struct task_entry, thread.ra)
	);
	DEFINE(TASK_THREAD_S9_RA,
		  offsetof(struct task_entry, thread.s[9])
		- offsetof(struct task_entry, thread.ra)
	);
	DEFINE(TASK_THREAD_S10_RA,
		  offsetof(struct task_entry, thread.s[10])
		- offsetof(struct task_entry, thread.ra)
	);
	DEFINE(TASK_THREAD_S11_RA,
		  offsetof(struct task_entry, thread.s[11])
		- offsetof(struct task_entry, thread.ra)
	);
#endif
	return 0;
}
