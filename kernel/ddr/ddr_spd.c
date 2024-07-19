#include <target/ddr.h>
#include <target/cmdline.h>
#include <target/console.h>

const char rdimm_test_spd[512] = {
	0x23, 0x12, 0x0c, 0x01, 0x85, 0x21, 0x00, 0x08,
	0x00, 0x60, 0x00, 0x03, 0x01, 0x0b, 0x80, 0x00,
	0x00, 0x00, 0x06, 0x0d, 0xf8, 0xff, 0x00, 0x00,
	0x6e, 0x6e, 0x6e, 0x11, 0x00, 0x6e, 0xf0, 0x0a,
	0x20, 0x08, 0x00, 0x05, 0x00, 0xa8, 0x16, 0x28,
	0x28, 0x00, 0x78, 0x00, 0x14, 0x3c, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x24, 0x03, 0x15, 0x2c,
	0x24, 0x03, 0x15, 0x2c, 0x24, 0x03, 0x24, 0x03,
	0x15, 0x2c, 0x24, 0x03, 0x15, 0x2c, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0xce,
	0x00, 0x00, 0x00, 0x00, 0xe7, 0xbc, 0x2f, 0x48,
	0x11, 0x11, 0x23, 0x15, 0x00, 0x86, 0x32, 0xd1,
	0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xdc,
	0x23, 0x12, 0x0c, 0x01, 0x85, 0x21, 0x00, 0x08,
	0x00, 0x60, 0x00, 0x03, 0x01, 0x0b, 0x80, 0x00,
	0x00, 0x00, 0x06, 0x0d, 0xf8, 0xff, 0x00, 0x00,
	0x6e, 0x6e, 0x6e, 0x11, 0x00, 0x6e, 0xf0, 0x0a,
	0x20, 0x08, 0x00, 0x05, 0x00, 0xa8, 0x16, 0x28,
	0x28, 0x00, 0x78, 0x00, 0x14, 0x3c, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x24, 0x03, 0x15, 0x2c,
	0x24, 0x03, 0x15, 0x2c, 0x24, 0x03, 0x24, 0x03,
	0x15, 0x2c, 0x24, 0x03, 0x15, 0x2c, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0xce,
	0x00, 0x00, 0x00, 0x00, 0xe7, 0xbc, 0x2f, 0x48,
	0x11, 0x11, 0x23, 0x15, 0x00, 0x86, 0x32, 0xd1,
	0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xdc,
};

const char udimm_test_spd[512] = {
	0x23, 0x11, 0x0c, 0x02, 0x86, 0x29, 0x00, 0x08,
	0x00, 0x60, 0x00, 0x03, 0x01, 0x03, 0x00, 0x00,
	0x00, 0x00, 0x05, 0x0d, 0xf8, 0xff, 0x02, 0x00,
	0x6e, 0x6e, 0x6e, 0x11, 0x00, 0x6e, 0x30, 0x11,
	0xf0, 0x0a, 0x20, 0x08, 0x00, 0xa8, 0x14, 0x28,
	0x28, 0x00, 0x78, 0x00, 0x14, 0x3c, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x16, 0x36, 0x16, 0x36,
	0x16, 0x36, 0x16, 0x36, 0x00, 0x00, 0x16, 0x36,
	0x16, 0x36, 0x16, 0x36, 0x16, 0x36, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xe7, 0x00, 0x87, 0x17,
	0x11, 0x11, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x41,
	0x23, 0x11, 0x0c, 0x02, 0x86, 0x29, 0x00, 0x08,
	0x00, 0x60, 0x00, 0x03, 0x01, 0x03, 0x00, 0x00,
	0x00, 0x00, 0x05, 0x0d, 0xf8, 0xff, 0x02, 0x00,
	0x6e, 0x6e, 0x6e, 0x11, 0x00, 0x6e, 0x30, 0x11,
	0xf0, 0x0a, 0x20, 0x08, 0x00, 0xa8, 0x14, 0x28,
	0x28, 0x00, 0x78, 0x00, 0x14, 0x3c, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x16, 0x36, 0x16, 0x36,
	0x16, 0x36, 0x16, 0x36, 0x00, 0x00, 0x16, 0x36,
	0x16, 0x36, 0x16, 0x36, 0x16, 0x36, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xe7, 0x00, 0x87, 0x17,
	0x11, 0x11, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x41,
};

#define PRINT_NXS(n, f, s...)						\
	printf("%-3d    : " s "\n" "         %02x (%d)\n",		\
	       n, (uint8_t)f, (unsigned int)f);
#define PRINT_NXSs(n, f, s...)						\
	printf("%-3d    : " s "\n" "         %02x (%d)\n",		\
	       n, (uint8_t)f, (signed int)f);
#define PRINT_NX1S(n0, n1, f0, f1, s...)				\
	printf("%-3d:%3d: " s "\n         %02x %02x (%d)\n",		\
	       n1, n0, (uint8_t)f1, (uint8_t)f0,			\
	       (unsigned int)MAKEWORD((f1), (f0)))
#define PRINT_NX2S(n0, n1, f0, f1, s...)				\
	printf("%-3d:%3d: " s "\n         %02x %02x (%d)\n",		\
	       n0, n1, (uint8_t)f0, (uint8_t)f1,			\
	       (unsigned int)MAKEWORD((f0), (f1)))
#define PRINT_NXXS(n0, n1, f, s) 					\
	do {								\
		int i;							\
		printf("%-3d-%3d: " s, n0, n1);				\
		for (i = n0; i <= n1; i++) {				\
			if ((i - (n0)) % 16 == 0)			\
				printf("\n         ");			\
			printf("%02x ", (f)[i - n0]);			\
		}							\
		printf("\n");						\
	} while (0)

static void ddr4_spd_dump_unbufferred(struct ddr4_spd_unbufferred_eeprom *spd)
{
	PRINT_NXS(128, spd->mod_height,
		  "Raw Card Extension, Module Nominal Height");
	PRINT_NXS(129, spd->mod_thickness,
		  "Module Maximum Thickness");
	PRINT_NXS(130, spd->ref_raw_card,
		  "Reference Raw Card Used");
	PRINT_NXS(131, spd->addr_mapping,
		  "Address Mapping from Edge Connector to DRAM");
	PRINT_NXXS(132, 253, spd->rsvd_132,
		   "Reserved");
	PRINT_NX2S(254, 255, spd->crc_lsb, spd->crc_msb,
		   "CRC for Module Specific Section");
}

static void ddr4_spd_dump_registered(struct ddr4_spd_registered_eeprom *spd)
{
	PRINT_NXS(128, spd->mod_height,
		  "Module Nominal Height");
	PRINT_NXS(129, spd->mod_thickness,
		  "Module Maximum Thickness");
	PRINT_NXS(130, spd->ref_raw_card,
		  "Reference Raw Card Used");
	PRINT_NXS(131, spd->dimm_mod_attr,
		  "DIMM Module Attributes");
	PRINT_NXS(132, spd->rdimm_thermal,
		  "Thermal Heat Spreader Solution");
	PRINT_NX2S(133, 134, spd->reg_id_lsb, spd->reg_id_msb,
		  "Register Manufacturer ID Code");
	PRINT_NXS(135, spd->reg_rev,
		  "Register Revision Number");
	PRINT_NXS(136, spd->addr_mapping,
		  "Address Mapping from Edge Connector to DRAM");
	PRINT_NXXS(137, 253, spd->rsvd_137,
		   "Reserved");
	PRINT_NX2S(254, 255, spd->crc_lsb, spd->crc_msb,
		   "CRC for Module Specific Section");
}

static void ddr4_spd_dump_load_reduced(struct ddr4_spd_load_reduced_eeprom *spd)
{
	PRINT_NXS(128, spd->mod_height,
		  "Module Nominal Height");
	PRINT_NXS(129, spd->mod_thickness,
		  "Module Maximum Thickness");
	PRINT_NXS(130, spd->ref_raw_card,
		  "Reference Raw Card Used");
	PRINT_NXS(131, spd->dimm_mod_attr,
		  "DIMM Module Attributes");
	PRINT_NXS(132, spd->lrdimm_thermal,
		  "Thermal Heat Spreader Solution");
	PRINT_NX2S(133, 134, spd->reg_id_lsb, spd->reg_id_msb,
		   "Register Manufacturer ID Code");
	PRINT_NXS(135, spd->reg_rev,
		  "Register Revision Number");
	PRINT_NXS(136, spd->addr_mapping,
		  "Address Mapping from Register to DRAM");
#if 0
	PRINT_NXS(137, spd->reg_drv,
		  "reg_drv       (Loadreduced) Reg output drive strength");
	PRINT_NXS(138, spd->reg_drv_ck,
		  "reg_drv_ck    (Loadreduced) Reg output drive strength for CK");
	PRINT_NXS(139, spd->data_buf_rev,
		  "data_buf_rev  (Loadreduced) Data Buffer Revision Numbe");
	PRINT_NXS(140, spd->vrefqe_r0,
		  "vrefqe_r0     (Loadreduced) DRAM VrefDQ for Package Rank 0");
	PRINT_NXS(141, spd->vrefqe_r1,
		  "vrefqe_r1     (Loadreduced) DRAM VrefDQ for Package Rank 1");
	PRINT_NXS(142, spd->vrefqe_r2,
		  "vrefqe_r2     (Loadreduced) DRAM VrefDQ for Package Rank 2");
	PRINT_NXS(143, spd->vrefqe_r3,
		  "vrefqe_r3     (Loadreduced) DRAM VrefDQ for Package Rank 3");
	PRINT_NXS(144, spd->data_intf,
		  "data_intf     (Loadreduced) Data Buffer VrefDQ for DRAM Interface");
	PRINT_NXS(145, spd->data_drv_1866,
		  "data_drv_1866 (Loadreduced) Data Buffer MDQ Drive Strength and RTT");
	PRINT_NXS(146, spd->data_drv_2400,
		  "data_drv_2400 (Loadreduced) Data Buffer MDQ Drive Strength and RTT");
	PRINT_NXS(147, spd->data_drv_3200,
		  "data_drv_3200 (Loadreduced) Data Buffer MDQ Drive Strength and RTT");
	PRINT_NXS(148, spd->dram_drv,
		  "dram_drv      (Loadreduced) DRAM Drive Strength");
	PRINT_NXS(149, spd->dram_odt_1866,
		  "dram_odt_1866 (Loadreduced) DRAM ODT (RTT_WR, RTT_NOM)");
	PRINT_NXS(150, spd->dram_odt_2400,
		  "dram_odt_2400 (Loadreduced) DRAM ODT (RTT_WR, RTT_NOM)");
	PRINT_NXS(151, spd->dram_odt_3200,
		  "dram_odt_3200 (Loadreduced) DRAM ODT (RTT_WR, RTT_NOM)");
	PRINT_NXS(152, spd->dram_odt_park_1866,
		  "dram_odt_park_1866 (Loadreduced) DRAM ODT (RTT_PARK)");
	PRINT_NXS(153, spd->dram_odt_park_2400,
		  "dram_odt_park_2400 (Loadreduced) DRAM ODT (RTT_PARK)");
	PRINT_NXS(154, spd->dram_odt_park_3200,
		  "dram_odt_park_3200 (Loadreduced) DRAM ODT (RTT_PARK)");
	PRINT_NNXXS(254, 255, spd->crc[0],
		    spd->crc[1],
		    "  Module CRC");
#endif
	PRINT_NXXS(155, 253, spd->rsvd_155,
		   "Reserved");
	PRINT_NX2S(254, 255, spd->crc_lsb, spd->crc_msb,
		   "CRC for Module Specific Section");
}

static void ddr4_spd_dump(const uint8_t *buf)
{
	struct ddr4_spd_eeprom *spd = (struct ddr4_spd_eeprom *)buf;

	/* General Section: Bytes 0-127 */
	PRINT_NXS(0, spd->spd_size_crc,
		  "Number of Serial PD Bytes Written / SPD Device Size / "
		  "CRC Coverage");
	PRINT_NXS(1, spd->spd_rev,
		  "SPD Revision");
	PRINT_NXS(2, spd->mem_type,
		  "Key Byte / DRAM Device Type");
	PRINT_NXS(3, spd->mod_type,
		  "Key Byte / Module Type");
	PRINT_NXS(4, spd->density_banks,
		  "SDRAM Density and Banks");
	PRINT_NXS(5, spd->addressing,
		  "SDRAM Addressing");
	PRINT_NXS(6, spd->package_type,
		  "SDRAM Package Type");
	PRINT_NXS(7, spd->opt_feature,
		  "SDRAM Optional Features");
	PRINT_NXS(8, spd->thermal_refresh,
		  "SDRAM Thermal and Refresh options");
	PRINT_NXS(9, spd->other_opt_features,
		  "Other SDRAM Optional Features");
	PRINT_NXS(10, spd->rsvd_10,
		  "Reserved");
	PRINT_NXS(11, spd->mod_VDD,
		  "Module Nominal Voltage, VDD");
	PRINT_NXS(12, spd->mod_org,
		  "Module Organization");
	PRINT_NXS(13, spd->mod_bus_width,
		  "Module Memory Bus Width");
	PRINT_NXS(14, spd->mod_tsens,
		  "Module Thermal Sensor");
	PRINT_NXXS(15, 16, spd->rsvd_15,
		   "Reserved");
	PRINT_NXS(17, spd->timebases,
		  "Timebases (MTB and FTB)");
	PRINT_NXS(18, spd->tCKAVGmin,
		  "SDRAM Mimimum Cycle Time (tCKAVGmin)");
	PRINT_NXS(19, spd->tCKAVGmax,
		  "SDRAM Maximum Cycle Time (TCKAVGmax)");
	PRINT_NXS(20, spd->cas_latency_1,
		  "CAS Latencies Supported, First Byte");
	PRINT_NXS(21, spd->cas_latency_2,
		  "CAS Latencies Supported, Second Byte");
	PRINT_NXS(22, spd->cas_latency_3,
		  "CAS Latencies Supported, Third Byte");
	PRINT_NXS(23, spd->cas_latency_4,
		  "CAS Latencies Supported, Fourth Byte");
	PRINT_NXS(24, spd->tAAmin,
		  "Minimum CAS Latency Time (tAAmin)");
	PRINT_NXS(25, spd->tRCDmin,
		  "Minimum RAS to CAS Delay Time (tRCDmin)");
	PRINT_NXS(26, spd->tRPmin,
		  "Minimum Row Precharge Delay Time (tRPmin)");
	PRINT_NXS(27, spd->tRAS_tRC_msn,
		  "Upper Nibbles for tRAS and tRC");
	PRINT_NX1S(27, 28, spd->tRAS_tRC_msn, spd->tRASmin_lsb,
		   "Minimum Active to Precharge Delay Time (tRASmin)");
	PRINT_NX1S(27, 29, spd->tRAS_tRC_msn, spd->tRCmin_lsb,
		   "Minimum Active to Active/Refresh Delay Time (tRCmin)");
	PRINT_NX2S(30, 31, spd->tRFC1min_lsb, spd->tRFC1min_msb,
		   "Minimum Refresh Recovery Delay Time (tRFC1min)");
	PRINT_NX2S(32, 33, spd->tRFC2min_lsb, spd->tRFC2min_msb,
		   "Minimum Refresh Recovery Delay Time (tRFC2min)");
	PRINT_NX2S(34, 35, spd->tRFC4min_lsb, spd->tRFC4min_msb,
		   "Minimum Refresh Recovery Delay Time (tRFC4min)");
	PRINT_NX1S(36, 37, spd->tFAWmin_msn, spd->tFAWmin_lsb,
		   "Minimum Four Activate Window Time (tFAWmin)");
	PRINT_NXS(38, spd->tRRD_Smin,
		  "Minimum Activate to Activate Delay Time (tRRD_Smin), "
		  "different bank group");
	PRINT_NXS(39, spd->tRRD_Lmin,
		  "Minimum Activate to Activate Delay Time (tRRD_Lmin), "
		  "same bank group");
	PRINT_NXS(40, spd->tCCD_Lmin,
		  "Minimum CAS to CAS Delay Time (tCCD_Lmin), "
		  "same bank group");
	PRINT_NXXS(41, 59, spd->rsvd_41,
		   "Reserved");
	PRINT_NXXS(66, 77, spd->conn_sram_bitmap,
		   "Connector to SRAM Bit Mapping");
	PRINT_NXXS(78, 116, spd->rsvd_78,
		   "Reserved");
	PRINT_NXSs(117, spd->fine_tCCD_Lmin,
		   "Fine Offset for Minimum CAS to CAS Delay Time "
		   "(tCCD_Lmin), same bank group");
	PRINT_NXSs(118, spd->fine_tRRD_Lmin,
		   "Fine Offset for Minimum Activate to Activate Delay Time "
		   "(tRRD_Lmin), same bank group");
	PRINT_NXSs(119, spd->fine_tRRD_Smin,
		   "Fine Offset for Minimum Activate to Activate Delay Time "
		   "(tRRD_Smin), different bank group");
	PRINT_NXSs(120, spd->fine_tRCmin,
		   "Fine Offset for Minimum Activate to Activate/Refresh "
		   "Delay Time (tRCmin)");
	PRINT_NXSs(121, spd->fine_tRPmin,
		   "Fine Offset for Minimum Row Precharge Delay Time "
		   "(tRPmin)");
	PRINT_NXSs(122, spd->fine_tRCDmin,
		   "Fine Offset for Minimum RAS to CAS Delay Time (tRCDmin)");
	PRINT_NXSs(123, spd->fine_tAAmin,
		   "Fine Offset for Minimum CAS Latency Time (tAAmin)");
	PRINT_NXSs(124, spd->fine_tCKAVGmax,
		   "Fine Offset for SDRAM Maximum Cycle Time (tCKAVGmax)");
	PRINT_NXSs(124, spd->fine_tCKAVGmin,
		   "Fine Offset for SDRAM Minimum Cycle Time (tCKAVGmin)");
	PRINT_NX2S(126, 127, spd->crc_lsb, spd->crc_msb,
		   "CRC for Base Configuration Section");

	switch (spd->mod_type) {
	case 0x02:  /* UDIMM */
	case 0x03:  /* SO-DIMM */
		ddr4_spd_dump_unbufferred(&(spd->mod.unbufferred));
		break;
	case 0x01:  /* RDIMM */
		ddr4_spd_dump_registered(&(spd->mod.registered));
		break;
	case 0x04:  /* LRDIMM */
		ddr4_spd_dump_load_reduced(&(spd->mod.load_reduced));
	default:
		PRINT_NXXS(128, 255, spd->mod.raw,
			   "Unsupported Module-specific Section");
		break;
	}

	/* Unique Module ID: Bytes 320-383 */
	PRINT_NX2S(320, 321, spd->mod_id_lsb, spd->mod_id_msb,
		   "Module Manufacturer’s ID Code");
	PRINT_NXS(322, spd->mod_loc,
		  "Module Manufacturing Location");
	PRINT_NX2S(323, 324, spd->mod_date[0], spd->mod_date[1],
		   "Module Manufacturing Date");
	PRINT_NXXS(325, 328, spd->mod_sn,
		   "Module Serial Number");
	PRINT_NXXS(329, 348, spd->mod_part,
		   "Module Part Number");
	PRINT_NXS(349, spd->mod_rev,
		  "Module Revision Code");
	PRINT_NX2S(350, 351, spd->dram_id_lsb, spd->dram_id_msb,
		   "DRAM Manufacturer’s ID Code");
	PRINT_NXS(352, spd->dram_stepping,
		  "DRAM stepping");
	PRINT_NXXS(353, 381, spd->mod_spec_data,
		   "Module Manufacturer's Specific Data");
	PRINT_NXXS(382, 383, spd->rsvd_382,
		   "Reserved");
	PRINT_NXXS(384, 511, spd->user,
		   "End User Programmable");
}

bool ddr_spd_read(uint8_t *buf)
{
	i2c_master_select(ddr_slot_ctrl.smbus);
	i2c_set_frequency(DDR_SPD_FREQ);

	spd_hw_read_bytes(ddr_slot_ctrl.spd_addr, 0,
			  ddr_slot_ctrl.spd_buf, DDR_SPD_SIZE);
	hexdump(0, ddr_slot_ctrl.spd_buf, 1, DDR_SPD_SIZE);
	return true;
}

static void ddr_spd_dump(const uint8_t *buf)
{
	ddr4_spd_dump(buf);
}

static int do_spd_dump(int argc, char *argv[])
{
	ddr_sid_t slot, sslot;
	uint8_t smbus;

	if (argc < 3)
		return -EINVAL;
	slot = (ddr_cid_t)strtoul(argv[2], 0, 0);
	if (argv > 3)
		smbus = strtoul(argv[3], 0, 0);
	ddr_slot_ctrl.smbus = smbus;
	ddr_spd_read(ddr_slot_ctrl.spd_buf);
	sslot = ddr_slot_save(slot);
	ddr_spd_dump(ddr_slot_ctrl.spd_buf);
	ddr_slot_restore(sslot);
	return 0;
}

static int do_spd(int argc, char *argv[])
{
	if (argc < 2)
		return -EINVAL;

	if (strcmp(argv[1], "dump") == 0)
		return do_spd_dump(argc, argv);
	return 0;
}

DEFINE_COMMAND(spd, do_spd, "DDR SPD commands",
	"dump slot\n"
	"    - dump SPD of DDR slot\n"
);
