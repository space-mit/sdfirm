/*
 * ZETALOG's Personal COPYRIGHT
 *
 * Copyright (c) 2022
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
 * @(#)dw_umctl2.h: Synopsys DesignWare DDR uMCTL2 interface
 * $Id: dw_umctl2.h,v 1.0 2022-04-06 09:26:00 zhenglv Exp $
 */

#ifndef __DW_UMCTL2_H_INCLUDE__
#define __DW_UMCTL2_H_INCLUDE__

#include <target/arch.h>

#ifndef DW_UMCTL2_BASE
#define DW_UMCTL2_BASE(n)		(DW_UMCTL2##n##_BASE)
#endif
#ifndef DW_UMCTL2_REG
#define DW_UMCTL2_REG(n, offset)	(DW_UMCTL2_BASE(n) + (offset))
#endif
#ifndef NR_DW_UMCTL2S
#define NR_DW_UMCTL2S		1
#endif

/* uMCTL2 DDRC Registers UMCTL2_REGS */
/* uMCTL2 DDRC DCH1 Registers UMCTL2_REGS_DCH1 (UMCTL2_CREG)
 * if UMCTL2_DUAL_DATA_CHANNEL=1
 */
#define UMCTL2_CREG(n, c, offset)	\
	DW_UMCTL2_REG((n), (offset) + (0x1B00 * (n)))
/* uMCTL2 DDRC FREQ1 Registers UMCTL2_REGS_FREQ1 (UMCTL2_FREG)
 * if UMCTL2_FAST_FREQUENCY_CHANGE==1
 * uMCTL2 DDRC FERQ2 Registers UMCTL2_REGS_FREQ2 (UMCTL2_FREG)
 * if UMCTL2_FREQUENCY_NUM>2
 * uMCTL2 DDRC FREQ3 Registers UMCTL2_REGS_FREQ3 (UMCTL2_FREG)
 * if UMCTL2_FREQUENCY_NUM>3
 */
#define UMCTL2_FREG(n, f, offset)	\
	DW_UMCTL2_REG((n), (offset) + (0x2000 * (f)))
/* uMCTL2 DDRC Alternative Address Map Registers UMCTL2_REGS_ADDRMAP_ALT
 * (UMCTL2_AREG)
 * if UMCTL2_HET_RANK==1
 */
#define UMCTL2_AREG(n, a, offset)	\
	DW_UMCTL2_REG((n), (offset) + (0x21F8 * (a)))
#define UMCTL2_MSTR(n)			DW_UMCTL2_REG(n, 0x000)
#define UMCTL2_STAT(n, c)		DW_UMCTL2_CREG(n, c, 0x004)
#define UMCTL2_MSTR1(n)			DW_UMCTL2_REG(n, 0x008)
#define UMCTL2_MRCTRL0(n, c)		DW_UMCTL2_CREG(n, c, 0x010)
#define UMCTL2_MRCTRL1(n, c)		DW_UMCTL2_CREG(n, c, 0x014)
#define UMCTL2_MRSTAT(n, c)		DW_UMCTL2_CREG(n, c, 0x018)
#define UMCTL2_MRCTRL2(n, c)		DW_UMCTL2_CREG(n, c, 0x01C)
#define UMCTL2_DERATEEN(n, f)		DW_UMCTL2_FREG(n, f, 0x020)
#define UMCTL2_DERATEINT(n, f)		DW_UMCTL2_FREG(n, f, 0x024)
#define UMCTL2_MSTR2(n)			DW_UMCTL2_REG(n, 0x028)
#define UMCTL2_DERATECTL(n, c)		DW_UMCTL2_CREG(n, c, 0x02C)
#define UMCTL2_PWRCTL(n, c)		DW_UMCTL2_CREG(n, c, 0x030)
#define UMCTL2_PWRTMG(n, f)		DW_UMCTL2_FREG(n, f, 0x034)
#define UMCTL2_HWLPCTL(n, c)		DW_UMCTL2_CREG(n, c, 0x038)
#define UMCTL2_HWFFCCTL(n)		DW_UMCTL2_REG(n, 0x03C)
#define UMCTL2_HWFFCSTAT(n, c)		DW_UMCTL2_CREG(n, c, 0x040)
#define UMCTL2_HWFFCEX_RANK1(n, f)	DW_UMCTL2_FREG(n, f, 0x044)
#define UMCTL2_HWFFCEX_RANK2(n, f)	DW_UMCTL2_FREG(n, f, 0x048)
#define UMCTL2_HWFFCEX_RANK3(n, f)	DW_UMCTL2_FREG(n, f, 0x04C)
#define UMCTL2_RFSHCTL0(n, f)		DW_UMCTL2_FREG(n, f, 0x050)
#define UMCTL2_RFSHCTL1(n)		DW_UMCTL2_REG(n, 0x054)
#define UMCTL2_RFSHCTL2(n)		DW_UMCTL2_REG(n, 0x058)
#define UMCTL2_RFSHCTL4(n)		DW_UMCTL2_REG(n, 0x05C)
#define UMCTL2_RFSHCTL3(n)		DW_UMCTL2_REG(n, 0x060)
#define UMCTL2_RFSHTMG(n, f)		DW_UMCTL2_FREG(n, f, 0x064)
#define UMCTL2_RFSHTMG1(n, f)		DW_UMCTL2_FREG(n, f, 0x068)
#define UMCTL2_ECCCFG0(n)		DW_UMCTL2_REG(n, 0x070)
#define UMCTL2_ECCCFG1(n)		DW_UMCTL2_REG(n, 0x074)
#define UMCTL2_ECCSTAT(n, c)		DW_UMCTL2_CREG(n, c, 0x078)
#define UMCTL2_ECCCTL(n, c)		DW_UMCTL2_CREG(n, c, 0x07C)
#define UMCTL2_ECCERRCNT(n, c)		DW_UMCTL2_CREG(n, c, 0x080)
#define UMCTL2_ECCCADDR0(n, c)		DW_UMCTL2_CREG(n, c, 0x084)
#define UMCTL2_ECCCADDR1(n, c)		DW_UMCTL2_CREG(n, c, 0x088)
#define UMCTL2_ECCCSYN0(n, c)		DW_UMCTL2_CREG(n, c, 0x08C)
#define UMCTL2_ECCCSYN1(n, c)		DW_UMCTL2_CREG(n, c, 0x090)
#define UMCTL2_ECCCSYN2(n, c)		DW_UMCTL2_CREG(n, c, 0x094)
#define UMCTL2_ECCBITMASK0(n, c)	DW_UMCTL2_CREG(n, c, 0x098)
#define UMCTL2_ECCBITMASK1(n, c)	DW_UMCTL2_CREG(n, c, 0x09C)
#define UMCTL2_ECCBITMASK2(n, c)	DW_UMCTL2_CREG(n, c, 0x0A0)
#define UMCTL2_ECCUADDR0(n, c)		DW_UMCTL2_CREG(n, c, 0x0A4)
#define UMCTL2_ECCUADDR1(n, c)		DW_UMCTL2_CREG(n, c, 0x0A8)
#define UMCTL2_ECCUSYN0(n, c)		DW_UMCTL2_CREG(n, c, 0x0AC)
#define UMCTL2_ECCUSYN1(n, c)		DW_UMCTL2_CREG(n, c, 0x0B0)
#define UMCTL2_ECCUSYN2(n, c)		DW_UMCTL2_CREG(n, c, 0x0B4)
#define UMCTL2_ECCPOISONADDR0(n)	DW_UMCTL2_REG(n, 0x0B8)
#define UMCTL2_ECCPOISONADDR1(n)	DW_UMCTL2_REG(n, 0x0BC)
#define UMCTL2_CRCPARCTL0(n, c)		DW_UMCTL2_CREG(n, c, 0x0C0)
#define UMCTL2_CRCPARCTL1(n)		DW_UMCTL2_REG(n, 0x0C4)
#define UMCTL2_CRCPARCTL2(n, f)		DW_UMCTL2_FREG(n, f, 0x0C8)
#define UMCTL2_CRCPARSTAT(n, c)		DW_UMCTL2_CREG(n, c, 0x0CC)
#define UMCTL2_INIT0(n)			DW_UMCTL2_REG(n, 0x0D0)
#define UMCTL2_INIT1(n)			DW_UMCTL2_REG(n, 0x0D4)
#define UMCTL2_INIT2(n)			DW_UMCTL2_REG(n, 0x0D8)
#define UMCTL2_INIT3(n, f)		DW_UMCTL2_FREG(n, f, 0x0DC)
#define UMCTL2_INIT4(n, f)		DW_UMCTL2_FREG(n, f, 0x0E0)
#define UMCTL2_INIT5(n)			DW_UMCTL2_REG(n, 0x0E4)
#define UMCTL2_INIT6(n, f)		DW_UMCTL2_FREG(n, f, 0x0E8)
#define UMCTL2_INIT7(n, f)		DW_UMCTL2_FREG(n, f, 0x0EC)
#define UMCTL2_DIMMCTL(n)		DW_UMCTL2_REG(n, 0x0F0)
#define UMCTL2_RANKCTL(n, f)		DW_UMCTL2_FREG(n, f, 0x0F4)
#define UMCTL2_RANKCTL1(n, f)		DW_UMCTL2_FREG(n, f, 0x0F8)
#define UMCTL2_CHCTL(n)			DW_UMCTL2_REG(n, 0x0FC)
#define UMCTL2_DRAMTMG0(n, f)		DW_UMCTL2_FREG(n, f, 0x100)
#define UMCTL2_DRAMTMG1(n, f)		DW_UMCTL2_FREG(n, f, 0x104)
#define UMCTL2_DRAMTMG2(n, f)		DW_UMCTL2_FREG(n, f, 0x108)
#define UMCTL2_DRAMTMG3(n, f)		DW_UMCTL2_FREG(n, f, 0x10C)
#define UMCTL2_DRAMTMG4(n, f)		DW_UMCTL2_FREG(n, f, 0x110)
#define UMCTL2_DRAMTMG5(n, f)		DW_UMCTL2_FREG(n, f, 0x114)
#define UMCTL2_DRAMTMG6(n, f)		DW_UMCTL2_FREG(n, f, 0x118)
#define UMCTL2_DRAMTMG7(n, f)		DW_UMCTL2_FREG(n, f, 0x11C)
#define UMCTL2_DRAMTMG8(n, f)		DW_UMCTL2_FREG(n, f, 0x120)
#define UMCTL2_DRAMTMG9(n, f)		DW_UMCTL2_FREG(n, f, 0x124)
#define UMCTL2_DRAMTMG10(n, f)		DW_UMCTL2_FREG(n, f, 0x128)
#define UMCTL2_DRAMTMG11(n, f)		DW_UMCTL2_FREG(n, f, 0x12C)
#define UMCTL2_DRAMTMG12(n, f)		DW_UMCTL2_FREG(n, f, 0x130)
#define UMCTL2_DRAMTMG13(n, f)		DW_UMCTL2_FREG(n, f, 0x134)
#define UMCTL2_DRAMTMG14(n, f)		DW_UMCTL2_FREG(n, f, 0x138)
#define UMCTL2_DRAMTMG15(n, f)		DW_UMCTL2_FREG(n, f, 0x13C)
#define UMCTL2_DRAMTMG16(n, f)		DW_UMCTL2_FREG(n, f, 0x140)
#define UMCTL2_DRAMTMG17(n, f)		DW_UMCTL2_FREG(n, f, 0x144)
#define UMCTL2_RFSHTMG_HET(n, f)	DW_UMCTL2_FREG(n, f, 0x150)
#define UMCTL2_MRAMTMG0(n, f)		DW_UMCTL2_FREG(n, f, 0x170)
#define UMCTL2_MRAMTMG1(n, f)		DW_UMCTL2_FREG(n, f, 0x174)
#define UMCTL2_MRAMTMG4(n, f)		DW_UMCTL2_FREG(n, f, 0x178)
#define UMCTL2_MRAMTMG9(n, f)		DW_UMCTL2_FREG(n, f, 0x17C)
#define UMCTL2_ZQCTL0(n, f)		DW_UMCTL2_FREG(n, f, 0x180)
#define UMCTL2_ZQCTL1(n)		DW_UMCTL2_REG(n, 0x184)
#define UMCTL2_ZQCTL2(n, c)		DW_UMCTL2_CREG(n, c, 0x188)
#define UMCTL2_ZQSTAT(n, c)		DW_UMCTL2_CREG(n, c, 0x18C)
#define UMCTL2_DFITMG0(n, f)		DW_UMCTL2_FREG(n, f, 0x190)
#define UMCTL2_DFITMG1(n, f)		DW_UMCTL2_FREG(n, f, 0x194)
#define UMCTL2_DFILPCFG0(n)		DW_UMCTL2_REG(n, 0x198)
#define UMCTL2_DFILPCFG1(n)		DW_UMCTL2_REG(n, 0x19C)
#define UMCTL2_DFIUPD0(n)		DW_UMCTL2_REG(n, 0x1A0)
#define UMCTL2_DFIUPD1(n)		DW_UMCTL2_REG(n, 0x1A4)
#define UMCTL2_DFIUPD2(n)		DW_UMCTL2_REG(n, 0x1A8)
#define UMCTL2_DFIMISC(n)		DW_UMCTL2_REG(n, 0x1B0)
#define UMCTL2_DFITMG2(n, f)		DW_UMCTL2_FREG(n, f, 0x1B4)
#define UMCTL2_DFITMG3(n, f)		DW_UMCTL2_FREG(n, f, 0x1B8)
#define UMCTL2_DFISTAT(n, c)		DW_UMCTL2_CREG(n, c, 0x1BC)
#define UMCTL2_DBICTL(n)		DW_UMCTL2_REG(n, 0x1C0)
#define UMCTL2_DFIPHYMSTR(n)		DW_UMCTL2_REG(n, 0x1C4)
#define UMCTL2_ADDRMAP0(n, a)		DW_UMCTL2_AREG(n, a, 0x200)
#define UMCTL2_ADDRMAP1(n, a)		DW_UMCTL2_AREG(n, a, 0x204)
#define UMCTL2_ADDRMAP2(n, a)		DW_UMCTL2_AREG(n, a, 0x208)
#define UMCTL2_ADDRMAP3(n, a)		DW_UMCTL2_AREG(n, a, 0x20C)
#define UMCTL2_ADDRMAP4(n, a)		DW_UMCTL2_AREG(n, a, 0x210)
#define UMCTL2_ADDRMAP5(n, a)		DW_UMCTL2_AREG(n, a, 0x214)
#define UMCTL2_ADDRMAP6(n, a)		DW_UMCTL2_AREG(n, a, 0x218)
#define UMCTL2_ADDRMAP7(n, a)		DW_UMCTL2_AREG(n, a, 0x21C)
#define UMCTL2_ADDRMAP8(n, a)		DW_UMCTL2_AREG(n, a, 0x220)
#define UMCTL2_ADDRMAP9(n, a)		DW_UMCTL2_AREG(n, a, 0x224)
#define UMCTL2_ADDRMAP10(n, a)		DW_UMCTL2_AREG(n, a, 0x228)
#define UMCTL2_ADDRMAP11(n, a)		DW_UMCTL2_AREG(n, a, 0x22C)
#define UMCTL2_ODTCFG(n, f)		DW_UMCTL2_FREG(n, f, 0x240)
#define UMCTL2_ODTMAP(n, c)		DW_UMCTL2_CREG(n, c, 0x244)
#define UMCTL2_SCHED(n)			DW_UMCTL2_REG(n, 0x250)
#define UMCTL2_SCHED1(n)		DW_UMCTL2_REG(n, 0x254)
#define UMCTL2_SCHED2(n)		DW_UMCTL2_REG(n, 0x258)
#define UMCTL2_PERFHPR1(n)		DW_UMCTL2_REG(n, 0x25C)
#define UMCTL2_PERFLPR1(n)		DW_UMCTL2_REG(n, 0x264)
#define UMCTL2_PERFWR1(n)		DW_UMCTL2_REG(n, 0x26C)
#define UMCTL2_SCHED3(n)		DW_UMCTL2_REG(n, 0x270)
#define UMCTL2_SCHED4(n)		DW_UMCTL2_REG(n, 0x274)
#define UMCTL2_SCHED5(n)		DW_UMCTL2_REG(n, 0x278)
#define UMCTL2_DQMAP0(n)		DW_UMCTL2_REG(n, 0x280)
#define UMCTL2_DQMAP1(n)		DW_UMCTL2_REG(n, 0x284)
#define UMCTL2_DQMAP2(n)		DW_UMCTL2_REG(n, 0x288)
#define UMCTL2_DQMAP3(n)		DW_UMCTL2_REG(n, 0x28C)
#define UMCTL2_DQMAP4(n)		DW_UMCTL2_REG(n, 0x290)
#define UMCTL2_DQMAP5(n)		DW_UMCTL2_REG(n, 0x294)
#define UMCTL2_DBG0(n)			DW_UMCTL2_REG(n, 0x300)
#define UMCTL2_DBG1(n, c)		DW_UMCTL2_CREG(n, c, 0x304)
#define UMCTL2_DBGCAM(n, c)		DW_UMCTL2_CREG(n, c, 0x308)
#define UMCTL2_DBGCMD(n, c)		DW_UMCTL2_CREG(n, c, 0x30C)
#define UMCTL2_DBGSTAT(n, c)		DW_UMCTL2_CREG(n, c, 0x310)
#define UMCTL2_DBGCAM1(n, c)		DW_UMCTL2_CREG(n, c, 0x318)
#define UMCTL2_SWCTL(n)			DW_UMCTL2_REG(n, 0x320)
#define UMCTL2_SWSTAT(n)		DW_UMCTL2_REG(n, 0x324)
#define UMCTL2_SWCTLSTATIC(n)		DW_UMCTL2_REG(n, 0x328)
#define UMCTL2_OCPARCFG0(n, c)		DW_UMCTL2_CREG(n, c, 0x330)
#define UMCTL2_OCPARCFG1(n)		DW_UMCTL2_REG(n, 0x334)
#define UMCTL2_OCPARSTAT0(n)		DW_UMCTL2_REG(n, 0x338)
#define UMCTL2_OCPARSTAT1(n)		DW_UMCTL2_REG(n, 0x33C)
#define UMCTL2_OCPARSTAT2(n, c)		DW_UMCTL2_CREG(n, c, 0x340)
#define UMCTL2_OCPARSTAT3(n)		DW_UMCTL2_REG(n, 0x344)
#define UMCTL2_OCPARSTAT4(n)		DW_UMCTL2_REG(n, 0x348)
#define UMCTL2_OCPARSTAT5(n)		DW_UMCTL2_REG(n, 0x34C)
#define UMCTL2_OCPARSTAT6(n)		DW_UMCTL2_REG(n, 0x350)
#define UMCTL2_OCPARSTAT7(n)		DW_UMCTL2_REG(n, 0x354)
#define UMCTL2_OCECCCFG0(n)		DW_UMCTL2_REG(n, 0x358)
#define UMCTL2_OCECCCFG1(n)		DW_UMCTL2_REG(n, 0x35C)
#define UMCTL2_OCECCSTAT0(n)		DW_UMCTL2_REG(n, 0x360)
#define UMCTL2_OCECCSTAT1(n)		DW_UMCTL2_REG(n, 0x364)
#define UMCTL2_OCECCSTAT2(n)		DW_UMCTL2_REG(n, 0x368)
#define UMCTL2_POISONCFG(n)		DW_UMCTL2_REG(n, 0x36C)
#define UMCTL2_POISONSTAT(n)		DW_UMCTL2_REG(n, 0x370)
#define UMCTL2_ADVECCINDEX(n)		DW_UMCTL2_REG(n, 0x374)
#define UMCTL2_ADVECCSTAT(n, c)		DW_UMCTL2_CREG(n, c, 0x378)
#define UMCTL2_ECCPOISONPAT0(n)		DW_UMCTL2_REG(n, 0x37C)
#define UMCTL2_ECCPOISONPAT1(n)		DW_UMCTL2_REG(n, 0x380)
#define UMCTL2_ECCPOISONPAT2(n)		DW_UMCTL2_REG(n, 0x384)
#define UMCTL2_ECCAPSTAT(n, c)		DW_UMCTL2_CREG(n, c, 0x388)
#define UMCTL2_CAPARPOISONCTL(n, c)	DW_UMCTL2_CREG(n, c, 0x3A0)
#define UMCTL2_CAPARPOISONSTAT(n, c)	DW_UMCTL2_CREG(n, c, 0x3A4)
#define UMCTL2_DYNBSMSTAT(n, c)		DW_UMCTL2_CREG(n, c, 0x3B0)
#define UMCTL2_CRCPARCTL3(n)		DW_UMCTL2_REG(n, 0x3B8)
#define UMCTL2_REGPARCFG(n)		DW_UMCTL2_REG(n, 0x3C0)
#define UMCTL2_REGPARSTAT(n)		DW_UMCTL2_REG(n, 0x3C4)
#define UMCTL2_RCDINIT1(n, f)		DW_UMCTL2_FREG(n, f, 0x3D0)
#define UMCTL2_RCDINIT2(n, f)		DW_UMCTL2_FREG(n, f, 0x3D4)
#define UMCTL2_RCDINIT3(n, f)		DW_UMCTL2_FREG(n, f, 0x3D8)
#define UMCTL2_RCDINIT4(n, f)		DW_UMCTL2_FREG(n, f, 0x3DC)
#define UMCTL2_OCCAPCFG(n)		DW_UMCTL2_REG(n, 0x3E0)
#define UMCTL2_OCCAPSTAT(n)		DW_UMCTL2_REG(n, 0x3E4)
#define UMCTL2_OCCAPCFG1(n, c)		DW_UMCTL2_CREG(n, c, 0x3E8)
#define UMCTL2_OCCAPSTAT1(n, c)		DW_UMCTL2_CREG(n, c, 0x3EC)
#define UMCTL2_DERATESTAT(n, c)		DW_UMCTL2_CREG(n, c, 0x3F0)

/* uMCTL2 Multi-Port Registers UMCTL2_MP */
/* Port based register */
#define DW_UMCTL2_PREG(n, p, offset)		\
	DW_UMCTL2_REG((n), (offset) + 0xB0 * (p))
/* Port/Channel based register */
#define DW_UMCTL2_PCREG(n, p, c, offset)	\
	DW_UMCTL2_REG((n), (offset) + 0xB0 * (p) + 0x08 * (c))
/* SAR based register */
#define DW_UMCTL2_SREG(n, s, offset)		\
	DW_UMCTL2_REG((n), (offset) + 0x08 * (s))
#define UMCTL2_PSTAT(n)			DW_UMCTL2_REG(n, 0x3FC)
#define UMCTL2_PCCFG(n)			DW_UMCTL2_REG(n, 0x400)
#define UMCTL2_PCFGR(n, p)		DW_UMCTL2_PREG(n, p, 0x404)
#define UMCTL2_PCFGW(n, p)		DW_UMCTL2_PREG(n, p, 0x408)
#define UMCTL2_PCFGC(n, p)		DW_UMCTL2_PREG(n, p, 0x40C)
#define UMCTL2_PCFGIDMASKCH(n, p, c)	DW_UMCTL2_PCREG(n, p, c, 0x410)
#define UMCTL2_PCFGIDVALUECH(n, p, c)	DW_UMCTL2_PCREG(n, p, c, 0x414)
#define UMCTL2_PCTRL(n, p)		DW_UMCTL2_PREG(n, p, 0x490)
#define UMCTL2_PCFGQOS0(n, p)		DW_UMCTL2_PREG(n, p, 0x494)
#define UMCTL2_PCFGQOS1(n, p)		DW_UMCTL2_PREG(n, p, 0x498)
#define UMCTL2_PCFGWQOS0(n, p)		DW_UMCTL2_PREG(n, p, 0x49C)
#define UMCTL2_PCFGWQOS1(n, p)		DW_UMCTL2_PREG(n, p, 0x4A0)
#define UMCTL2_SARBASE(n, s)		DW_UMCTL2_SREG(n, s, 0xF04)
#define UMCTL2_SARSIZE(n, s)		DW_UMCTL2_SREG(n, s, 0xF08)
#define UMCTL2_SBRCTL(n)		DW_UMCTL2_REG(n, 0xF24)
#define UMCTL2_SBRSTAT(n)		DW_UMCTL2_REG(n, 0xF28)
#define UMCTL2_SBRWDATA0(n)		DW_UMCTL2_REG(n, 0xF2C)
#define UMCTL2_SBRWDATA1(n)		DW_UMCTL2_REG(n, 0xF30)
#define UMCTL2_PDCH(n)			DW_UMCTL2_REG(n, 0xF34)
#define UMCTL2_SBRSTART0(n)		DW_UMCTL2_REG(n, 0xF38)
#define UMCTL2_SBRSTART1(n)		DW_UMCTL2_REG(n, 0xF3C)
#define UMCTL2_SBRRANGE0(n)		DW_UMCTL2_REG(n, 0xF40)
#define UMCTL2_SBRRANGE1(n)		DW_UMCTL2_REG(n, 0xF44)
#define UMCTL2_SBRSTART0DCH1(n)		DW_UMCTL2_REG(n, 0xF48)
#define UMCTL2_SBRSTART1DCH1(n)		DW_UMCTL2_REG(n, 0xF4C)
#define UMCTL2_SBRRANGE0DCH1(n)		DW_UMCTL2_REG(n, 0xF50)
#define UMCTL2_SBRRANGE1DCH1(n)		DW_UMCTL2_REG(n, 0xF54)
#define UMCTL2_VER_NUMBER(n)		DW_UMCTL2_REG(n, 0xFF0)
#define UMCTL2_VER_TYPE(n)		DW_UMCTL2_REG(n, 0xFF4)

/* ssi_memory_map/ssi_address_block registers */

void dw_umctl2_init(void);
void dw_umctl2_start(void);

#endif /* __DW_UMCTL2_H_INCLUDE__ */
