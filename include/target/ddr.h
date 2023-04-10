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
 * @(#)ddr.h: double data rate framework interface
 * $Id: ddr.h,v 1.0 2020-03-26 08:48:00 zhenglv Exp $
 */

#ifndef __DDR_H_INCLUDE__
#define __DDR_H_INCLUDE__

#include <target/generic.h>

#define DDR_MAX_CHANNELS	CONFIG_DDR_MAX_CHANNELS
#define DDR_MAX_MODULES		CONFIG_DDR_MAX_MODULLES

/* Speed grade */
#define DDR_MIN_SPD		0
#define DDR1_MIN_SPD		DDR_MIN_SPD
#define DDR_200			(DDR1_MIN_SPD + 0)
#define DDR_266			(DDR1_MIN_SPD + 1)
#define DDR_333			(DDR1_MIN_SPD + 2)
#define DDR_400			(DDR1_MIN_SPD + 3)
#define DDR1_MAX_SPD		DDR_400
#define DDR1_MAX_SPDS		(DDR1_MAX_SPD - DDR1_MIN_SPD + 1)
#define DDR2_MIN_SPD		DDR1_MAX_SPD
#define DDR2_400		(DDR2_MIN_SPD + 0)
#define DDR2_533		(DDR2_MIN_SPD + 1)
#define DDR2_667		(DDR2_MIN_SPD + 2)
#define DDR2_800		(DDR2_MIN_SPD + 3)
#define DDR2_MAX_SPD		DDR2_800
#define DDR2_MAX_SPDS		(DDR2_MAX_SPD - DDR2_MIN_SPD + 1)
#define DDR3_MIN_SPD		DDR2_MAX_SPD
#define DDR3_800		(DDR3_MIN_SPD + 0)
#define DDR3_1066		(DDR3_MIN_SPD + 1)
#define DDR3_1333		(DDR3_MIN_SPD + 2)
#define DDR3_1600		(DDR3_MIN_SPD + 3)
#define DDR3_MAX_SPD		DDR3_1600
#define DDR3_MAX_SPDS		(DDR3_MAX_SPD - DDR3_MIN_SPD + 1)
#define DDR4_MIN_SPD		DDR3_MAX_SPD
#define DDR4_1600		(DDR4_MIN_SPD + 0)
#define DDR4_1866		(DDR4_MIN_SPD + 1)
#define DDR4_2133		(DDR4_MIN_SPD + 2)
#define DDR4_2400		(DDR4_MIN_SPD + 3)
#define DDR4_2666		(DDR4_MIN_SPD + 4)
#define DDR4_2933		(DDR4_MIN_SPD + 5)
#define DDR4_3200		(DDR4_MIN_SPD + 6)
#define DDR4_MAX_SPD		DDR4_3200
#define DDR4_MAX_SPDS		(DDR4_MAX_SPD - DDR4_MIN_SPD + 1)
#define DDR_MAX_SPDS		(DDR4_MAX_SPD + 1)
#define __DDR_SPD2tCK(spd, n)	((n) * 1000 * 1000 / ddr_spd2speed(spd)) /* In ps */

#include <target/ddr1.h>
#include <target/ddr4.h>
#include <target/ddr_spd.h>
#include <driver/ddr.h>

#define NR_DDR_CHANNELS		DDR_HW_MAX_CHANNELS
#define NR_DDR_MODULES		DDR_HW_MAX_MODULES
#if (NR_DDR_CHANNELS < DDR_MAX_CHANNNELS)
#error "Too small CONFIG_DDR_MAX_CHANNELS is specified!"
#endif
#if (NR_DDR_MODULES < DDR_MAX_MODULES)
#error "Too small CONFIG_DDR_MAX_MODULES is specified!"
#endif

#define ddr_enable_speed(speed)		ddr_hw_enable_speed(speed)
#define ddr_wait_dfi(cycles)		ddr_hw_wait_dfi(cycles)
#define ddr_mr_write(n, c, ranks, v, r)	ddr_hw_mr_write(n, c, ranks, v, r)

#ifdef CONFIG_DDR
void ddr_config_speed(uint8_t spd);
uint16_t ddr_spd2speed(uint8_t spd);
void ddr_init(void);

extern uint8_t ddr_spd;
extern uint8_t ddr_dev;
#else
#define ddr_spd2speed(spd)		0
#define ddr_init()			do { } while (0)
#endif

#endif /* __DDR_H_INCLUDE__ */
