#include <target/ddr.h>
#include <target/clk.h>

/* 2.22 Mode Register Reads and Writes
 */
#ifdef CONFIG_DW_UMCTL2_DDR4
void dw_umctl2_mr_write(uint8_t n, uint8_t c, uint8_t ranks,
			uint16_t val, uint8_t reg)
{
	uint32_t mrctrl0, mrctrl1;

	while (dw_umctl2_read(UMCTL2_MRSTAT(n, c)) & MRSTAT_mr_wr_busy);

	mrctrl0 = MRCTRL0_mr_type(MRCTRL0_mr_Write);
	mrctrl0 |= MRCTRL0_mr_addr(reg);
	mrctrl0 |= MRCTRL0_mr_rank(ranks);
	if (reg == DDR4_RCW)
		mrctrl0 |= MRCTRL0_sw_init_int;
	mrctrl1 = MRCTRL1_mr_data(DDR4_MR162MR18(val));
	dw_umctl2_write(mrctrl0, UMCTL2_MRCTRL0(n, c));
	dw_umctl2_write(mrctrl1, UMCTL2_MRCTRL1(n, c));

	dw_umctl2_set(MRCTRL0_mr_wr, UMCTL2_MRCTRL0(n, c));
	while (dw_umctl2_read(UMCTL2_MRCTRL0(n, c)) & MRCTRL0_mr_wr);
	while (dw_umctl2_read(UMCTL2_MRSTAT(n, c)) & MRSTAT_mr_wr_busy);
}

uint16_t dw_umctl2_mr_read(uint8_t n, uint8_t c, uint8_t ranks, uint8_t reg)
{
	uint32_t mrctrl0;
	uint32_t mrr_data;

	while (dw_umctl2_read(UMCTL2_MRSTAT(n, c)) & MRSTAT_mr_wr_busy);

	mrctrl0 = MRCTRL0_mr_type(MRCTRL0_mr_Read);
	mrctrl0 |= MRCTRL0_mr_addr(reg);
	mrctrl0 |= MRCTRL0_mr_rank(ranks);
	if (reg == DDR4_RCW)
		mrctrl0 |= MRCTRL0_sw_init_int;
	dw_umctl2_write(mrctrl0, UMCTL2_MRCTRL0(n, c));

	dw_umctl2_set(MRCTRL0_mr_wr, UMCTL2_MRCTRL0(n, c));
	while (dw_umctl2_read(UMCTL2_MRCTRL0(n, c)) & MRCTRL0_mr_wr);
	while (dw_umctl2_read(UMCTL2_MRSTAT(n, c)) & MRSTAT_mr_wr_busy);

#if 1
	/* TODO: Should read hif_mrr_data signal instead */
	mrr_data = dw_umctl2_read(UMCTL2_MRCTRL1(n, c));
#else
	mrr_data = dw_umctl2_read(n, c, hif_mrr_data);
#endif
	return DDR4_MR182MR16(mrr_data);
}
#endif

#ifdef CONFIG_DW_UMCTL2_ECC
static void dw_umctl2_init_ecc(uint8_t n, uint8_t c, uint8_t f)
{
	dw_umctl2_write(0x4, UMCTL2_ECCCFG0(n));
	dw_umctl2_write(0x0, UMCTL2_ECCCFG1(n));
	dw_umctl2_write(0x300, UMCTL2_ECCCTL(n, c));
	dw_umctl2_write(0x100, UMCTL2_INIT6(n, f));
}
#else
#define dw_umctl2_init_ecc(n, c, f)		do { } while (0)
#endif

#ifdef CONFIG_DW_UMCTL2_FAST_FREQ_CHANGE
static inline void dw_umctl2_init_ffc(uint8_t n, uint8_t f, uint8_t spd)
{
	dw_umctl2_set(MSTR_frequency_mode, UMCTL2_MSTR(n));
	dw_umctl2_write(MSTR2_target_frequency(f), UMCTL2_MSTR2(n));
}
#else
static inline void dw_umctl2_init_ffc(uint8_t n, uint8_t f, uint8_t spd)
{
	dw_umctl2_clear(MSTR_frequency_mode, UMCTL2_MSTR(n));
}
#endif

#ifdef CONFIG_DW_UMCTL2_DDR4_MRAM
static inline void dw_umctl2_init_mram(uint8_t n)
{
	dw_umctl2_write(MSTR1_rank_tmgreg_sel_static, UMCTL2_MSTR1(n));
}
#else
#define dw_umctl2_init_mram(n)			do { } while (0)
#endif

#ifdef CONFIG_DW_UMCTL2_HET_RANK_DDR34
static inline void dw_umctl2_init_het_rank(uint8_t n)
{
	dw_umctl2_write(MSTR1_rfc_tmgreg_sel_static |
			MSTR1_alt_addrmap_en, /* static */
			UMCTL2_MSTR1(n));
}
#else
#define dw_umctl2_init_het_rank(n)		do { } while (0)
#endif

#ifndef CONFIG_DW_UMCTL2_CID_WIDTH_0
static inline void dw_umctl2_init_3ds(uint8_t n)
{
	/* NYI */
	dw_umctl2_write(MRCTRL0_mr_cid(0), UMCTL2_MRCTRL0(n));
}
#else
#define dw_umctl2_init_3ds(n)			do { } while (0)
#endif

static void dw_umctl2_init_dev(uint8_t n, uint8_t spd, uint8_t dev,
			       uint8_t ranks)
{
	dw_umctl2_write(MSTR_protocols(MSTR_ddr4) | /* static */
			MSTR_device_config(MSTR_device_x8) | /* static */
			MSTR_active_ranks(ranks) | /* static */
			MSTR_burst_mode_static |
			MSTR_burstchop_static |
			MSTR_en_2t_timing_mode_static |
			MSTR_data_bus_width_static |
			MSTR_burst_rdwr_static |
			MSTR_active_logical_ranks_static |
			MSTR_frequency_ratio_static |
			MSTR_dll_off_mode_quasi |
			MSTR_geardown_mode_quasi |
			MSTR_frequency_mode_quasi, /* Do not configure? */
			UMCTL2_MSTR(n));
}

/*===== Low power control =====*/
#if defined(CONFIG_DW_UMCTL2_MOBILE) || defined(CONFIG_DW_UMCTL2_LPDDR2)
#define dw_umctl2_enable_dpd(n, c)		\
	dw_umctl2_set(PWRCTL_deeppowerdown_en, UMCTL2_PWRCTL(n, c))
#define dw_umctl2_disable_dpd(n, c)		\
	dw_umctl2_clear(PWRCTL_deeppowerdown_en, UMCTL2_PWRCTL(n, c))

static void dw_umctl2_init_dpd(uint8_t n, uint8_t c, uint8_t f,
			       uint32_t cycles_deep_powerdown)
{
	if (cycles_deep_powerdown) {
		dw_umctl2_set_msk(PWRTMG_t_dpd_x4096(cycles_deep_powerdown),
			          UMCTL2_PWRTMG(n, f));
		dw_umctl2_set(PWRCTL_deeppowerdown_en, UMCTL2_PWRCTL(n, c));
	}
}
#else
#define dw_umctl2_init_dpd(n, c, f, cycles)	do { } while (0)
#endif

#ifdef CONFIG_DW_UMCTL2_DDR4
#define dw_umctl2_enable_mpsm(n, c)		\
	dw_umctl2_set(PWRCTL_mpsm_en, UMCTL2_PWRCTL(n, c))
#define dw_umctl2_disable_mpsm(n, c)		\
	dw_umctl2_clear(PWRCTL_mpsm_en, UMCTL2_PWRCTL(n, c))

static inline void dw_umctl2_init_mpsm(uint8_t n, uint8_t c)
{
	dw_umctl2_set(PWRCTL_mpsm_en, UMCTL2_PWRCTL(n, c));
}
#else
static inline void dw_umctl2_init_mpsm(uint8_t n, uint8_t c)
{
	dw_umctl2_clear(PWRCTL_mpsm_en, UMCTL2_PWRCTL(n, c));
}
#endif

#define dw_umctl2_enable_sr(n, c)	\
	dw_umctl2_set(PWRCTL_selfref_en, UMCTL2_PWRCTL(n, c))
#define dw_umctl2_disable_sr(n, c)	\
	dw_umctl2_clear(PWRCTL_selfref_en, UMCTL2_PWRCTL(n, c))
#define dw_umctl2_entry_sr(n, c)	\
	dw_umctl2_set(PWRCTL_selfref_sw, UMCTL2_PWRCTL(n, c))
#define dw_umctl2_exit_sr(n, c)		\
	dw_umctl2_clear(PWRCTL_selfref_sw, UMCTL2_PWRCTL(n, c))
#define dw_umctl2_enable_pd(n, c)	\
	dw_umctl2_set(PWRCTL_powerdown_en, UMCTL2_PWRCTL(n, c))
#define dw_umctl2_disable_pd(n, c)	\
	dw_umctl2_clear(PWRCTL_powerdown_en, UMCTL2_PWRCTL(n, c))

/*===== Refresh control =====*/
#define dw_umctl2_set_refresh_timer_start(n, r, v)	\
	dw_umctl2_set_msk(RFSHCTL12_refresh_timern_start_value_x32(r, v),\
			RFSHCTL12_refresh_timern_start_value_x32_mask(r),\
			UMCTL2_RFSHCTL12(n, r))

static void dw_umctl2_init_pwr(uint8_t n, uint8_t c, uint8_t f,
			       uint16_t cycles_powerdown,
			       uint16_t cycles_selfref)
{
	dw_umctl2_write(PWRTMG_powerdown_to_x32(cycles_powerdown) |
			PWRTMG_selfref_to_x32(cycles_selfref),
			UMCTL2_PWRTMG(n, f));
	dw_umctl2_write((cycles_powerdown ? PWRCTL_powerdown_en : 0) |
			(cycles_selfref ? PWRCTL_selfref_en : 0),
			UMCTL2_PWRCTL(n, c));
	dw_umctl2_init_dpd(n, c, f, cycles_powerdown * 64);
	dw_umctl2_init_mpsm(n, c);
}

#ifndef CONFIG_DW_UMCTL2_CID_WIDTH_0
static void dw_umctl2_init_3ds_rfsh(uint8_t n)
{
	dw_umctl2_write(RFSHCTL4_refresh_timer_lr_offset_x32_static,
			UMCTL2_RFSHCTL4(n));
}
#else
#define dw_umctl2_init_3ds_rfsh(n)		do { } while (0)
#endif

#ifdef CONFIG_DW_UMCTL2_DDR4_MRAM
static void dw_umctl2_init_mram_rfsh(uint8_t n, uint8_t ranks)
{
	/* NYI */
}
#else
#define dw_umctl2_init_mram_rfsh(n, ranks)	do { } while (0)
#endif

#ifdef CONFIG_DW_UMCTL2_LPDDR2
static void dw_umct2l_init_lpddr2_rfsh(uint8_t n, uint8_t f)
{
	if (RFSHCTL0_per_bank_refresh_static)
		dw_umctl2_set(RFSHCTL0_per_bank_refresh,
			      UMCTL2_RFSHCTL0(n, f));
	if (RFSHTMG_t_rfc_nom_x1_sel_dynamic)
		dw_umctl2_set(RFSHTMG_t_rfc_nom_x1_sel_dynamic,
			      UMCTL2_RFSHTMG(n, f));
}
#else
#define dw_umctl2_init_lpddr2_rfsh(n, f)	do { } while (0)
#endif

#define dw_umctl2_update_rfsh(n)			\
	dw_umctl2_toggle(RFSHCTL3_refresh_update_level,	\
			 UMCTL2_RFSH3CTL(n))

static void dw_umctl2_init_rfsh(uint8_t n, uint8_t f, uint8_t ranks)
{
	uint8_t r;

	dw_umctl2_write(RFSHCTL0_refresh_burst_dynamic |
			RFSHCTL0_refresh_to_x1_x32_dynamic |
			RFSHCTL0_refresh_margin_dynamic,
			UMCTL2_RFSHCTL0(n, f));
	for (r = 0; r < ranks; r++) {
		dw_umctl2_set_refresh_timer_start(n, r,
			RFSHCTL12_refresh_timern_start_value_x32_dynamic);
	}
	dw_umctl2_init_3ds_rfsh(n);
	dw_umctl2_write(RFSHCTL3_refresh_mode_quasi,
			UMCTL2_RFSHCTL3(n));
	dw_umctl2_init_mram_rfsh(n, ranks);
	dw_umctl2_init_lpddr2_rfsh(n, f);
	printf("================================\n");
	dw_umctl2_write(0x00A200EA, UMCTL2_RFSHTMG(n, f));
	printf("================================\n");
}

static void dw_umctl2_init_static_regs(uint8_t n, uint8_t c,
				       uint8_t f, uint8_t spd)
{
	if (spd == DDR4_1600) {
		/* jedec_ddr4_rdimm_2G_x8_1600J_1_250_2R_ecc */
		dw_umctl2_write(DBG1_dis_dq, UMCTL2_DBG1(n, c));

		dw_umctl2_init_dev(n, spd, MSTR_device_x8, 2);
		dw_umctl2_init_mram(n);
		dw_umctl2_init_het_rank(n);
		dw_umctl2_init_ffc(n, f, spd);
		dw_umctl2_init_3ds(n);

		/* By default, enables powerdown and self refresh */
		dw_umctl2_init_pwr(n, c, f, 128, 2048);
		/* Configure self refresh for training */
		dw_umctl2_disable_sr(n, c);
#ifdef CONFIG_DW_UMCTL2_TRAINING
		dw_umctl2_entry_sr(n, c);
#else
		dw_umctl2_exit_sr(n, c);
#endif
		dw_umctl2_init_rfsh(n, f, 4);
		dw_umctl2_set_refresh_timer_start(n, 0, 0x900);
		dw_umctl2_set_refresh_timer_start(n, 1, 0x9A0);
		dw_umctl2_set_refresh_timer_start(n, 2, 0xCE0);
		dw_umctl2_set_refresh_timer_start(n, 3, 0xD20);

		dw_umctl2_write(0x00000000, UMCTL2_RFSHCTL3(n));
		dw_umctl2_write(0x00A200EA, UMCTL2_RFSHTMG(n, f));

#ifdef CONFIG_UMCTL2_ECC
		dw_umctl2_write(0x00000004, UMCTL2_ECCCFG0(n));
#else
		dw_umctl2_write(0x00000000, UMCTL2_ECCCFG0(n));
#endif
		dw_umctl2_write(0x00000000, UMCTL2_ECCCFG1(n));
		dw_umctl2_write(0x00000300, UMCTL2_ECCCTL(n, c));
#ifdef CONFIG_UMCTL2_TRAINING
		dw_umctl2_write(0xC0030128, UMCTL2_INIT0(n));
#else
		dw_umctl2_write(0x00030128, UMCTL2_INIT0(n));
#endif
		dw_umctl2_write(0x00010002, UMCTL2_INIT1(n));
		dw_umctl2_write(0x0A150001, UMCTL2_INIT3(n, f));
		dw_umctl2_write(0x00000000, UMCTL2_INIT4(n, f));
		dw_umctl2_write(0x00110000, UMCTL2_INIT5(n));
	}
	if (spd == DDR4_3200) {
		/* jedec_ddr4_rdimm_8G_x8_3200W_0_625_2R_ecc */
		dw_umctl2_write(DBG1_dis_dq, UMCTL2_DBG1(n, c));

		dw_umctl2_init_dev(n, spd, MSTR_device_x8, 2);
		dw_umctl2_init_mram(n);
		dw_umctl2_init_het_rank(n);
		dw_umctl2_init_ffc(n, f, spd);
		dw_umctl2_init_3ds(n);

		/* By default, enables powerdown and self refresh */
		dw_umctl2_init_pwr(n, c, f, 128, 2048);
		/* Configure self refresh for training */
		dw_umctl2_disable_sr(n, c);
#ifdef CONFIG_DW_UMCTL2_TRAINING
		dw_umctl2_entry_sr(n, c);
#else
		dw_umctl2_exit_sr(n, c);
#endif
		dw_umctl2_init_rfsh(n, f, 4);
		dw_umctl2_set_refresh_timer_start(n, 0, 0xAE0);
		dw_umctl2_set_refresh_timer_start(n, 1, 0xBA0);
		dw_umctl2_set_refresh_timer_start(n, 2, 0xF80);
		dw_umctl2_set_refresh_timer_start(n, 3, 0xFC0);
		printf("================================\n");
		/* Testing: configure MR7 (RCD) to 20 cycles */
		dw_umctl2_mr_write(n, c, DW_UMCTL2_NUM_RANKS_MASK(2),
				   20, DDR4_RCW);
		printf("================================\n");
	}
}

void dw_umctl2_start(void)
{
#ifndef CONFIG_DW_UMCTL2_DEBUG_REGS
	ddr_wait_dfi(8);
	clk_enable(ddr_arst);
	ddr_wait_dfi(8);
	clk_enable(ddr_rst);
#endif

	/* TODO: configure dw_umctl2 after setting ddr_clk/ddr_rst */
}

void dw_umctl2_init(void)
{
#ifndef CONFIG_DW_UMCTL2_DEBUG_REGS
	ddr_wait_dfi(8);
	clk_enable(ddr_por);
	ddr_wait_dfi(8);
	clk_enable(ddr_prst);
#endif

	dw_umctl2_init_static_regs(0, 0, 0, DDR4_3200);
}
