/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2019 Western Digital Corporation or its affiliates.
 *
 * Authors:
 *   Anup Patel <anup.patel@wdc.com>
 */

#include <target/sbi.h>

typedef int (*illegal_insn_func)(ulong insn, struct pt_regs *regs,
				 struct sbi_scratch *scratch);

static int truly_illegal_insn(ulong insn, struct pt_regs *regs,
			      struct sbi_scratch *scratch)
{
	regs->tval = insn;
	regs->tval2 = 0;
	regs->tinst = 0;
	regs->gva   = 0;

	return sbi_trap_redirect(regs, scratch, regs->epc, EXC_INSN_ILLEGAL, insn);
}

static int system_opcode_insn(ulong insn, struct pt_regs *regs,
			      struct sbi_scratch *scratch)
{
	int do_write, rs1_num = (insn >> 15) & 0x1f;
	ulong rs1_val = GET_RS1(insn, regs);
	int csr_num   = (uint32_t)insn >> 20;
	ulong csr_val, new_csr_val;

	/* TODO: Ensure that we got CSR read/write instruction */

	if (sbi_emulate_csr_read(csr_num, regs, scratch, &csr_val))
		return truly_illegal_insn(insn, regs, scratch);

	do_write = rs1_num;
	switch (GET_RM(insn)) {
	case 1:
		new_csr_val = rs1_val;
		do_write    = 1;
		break;
	case 2:
		new_csr_val = csr_val | rs1_val;
		break;
	case 3:
		new_csr_val = csr_val & ~rs1_val;
		break;
	case 5:
		new_csr_val = rs1_num;
		do_write    = 1;
		break;
	case 6:
		new_csr_val = csr_val | rs1_num;
		break;
	case 7:
		new_csr_val = csr_val & ~rs1_num;
		break;
	default:
		return truly_illegal_insn(insn, regs, scratch);
	};

	if (do_write && sbi_emulate_csr_write(csr_num, regs, scratch, new_csr_val))
		return truly_illegal_insn(insn, regs, scratch);

	SET_RD(insn, regs, csr_val);

	regs->epc += 4;

	return 0;
}

static illegal_insn_func illegal_insn_table[32] = {
	truly_illegal_insn, /* 0 */
	truly_illegal_insn, /* 1 */
	truly_illegal_insn, /* 2 */
	truly_illegal_insn, /* 3 */
	truly_illegal_insn, /* 4 */
	truly_illegal_insn, /* 5 */
	truly_illegal_insn, /* 6 */
	truly_illegal_insn, /* 7 */
	truly_illegal_insn, /* 8 */
	truly_illegal_insn, /* 9 */
	truly_illegal_insn, /* 10 */
	truly_illegal_insn, /* 11 */
	truly_illegal_insn, /* 12 */
	truly_illegal_insn, /* 13 */
	truly_illegal_insn, /* 14 */
	truly_illegal_insn, /* 15 */
	truly_illegal_insn, /* 16 */
	truly_illegal_insn, /* 17 */
	truly_illegal_insn, /* 18 */
	truly_illegal_insn, /* 19 */
	truly_illegal_insn, /* 20 */
	truly_illegal_insn, /* 21 */
	truly_illegal_insn, /* 22 */
	truly_illegal_insn, /* 23 */
	truly_illegal_insn, /* 24 */
	truly_illegal_insn, /* 25 */
	truly_illegal_insn, /* 26 */
	truly_illegal_insn, /* 27 */
	system_opcode_insn, /* 28 */
	truly_illegal_insn, /* 29 */
	truly_illegal_insn, /* 30 */
	truly_illegal_insn  /* 31 */
};

int sbi_illegal_insn_handler(uint32_t hartid, ulong mcause,
			     struct pt_regs *regs,
			     struct sbi_scratch *scratch)
{
	ulong insn = csr_read(mbadaddr);

	if (unlikely((insn & 3) != 3)) {
		if (insn == 0)
			insn = get_insn(regs->epc, NULL);
		if ((insn & 3) != 3)
			return truly_illegal_insn(insn, regs, scratch);
	}
	return illegal_insn_table[(insn & 0x7c) >> 2](insn, regs, scratch);
}
