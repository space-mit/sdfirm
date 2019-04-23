/*
 * ZETALOG's Personal COPYRIGHT
 *
 * Copyright (c) 2019
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
 * @(#)hmss_periph.c: QDF2400 specific HMSS periph implementation
 * $Id: hmss_periph.c,v 1.279 2019-04-14 10:19:18 zhenglv Exp $
 */

#include <target/cpus.h>

const uint64_t apcs_apr_pwr_ctl[MAX_CPU_RAILS] = {
	APCS_APR_PWR_CTL(0),
	APCS_APR_PWR_CTL(1),
	APCS_APR_PWR_CTL(2),
	APCS_APR_PWR_CTL(3),
	APCS_APR_PWR_CTL(4),
	APCS_APR_PWR_CTL(5),
	APCS_APR_PWR_CTL(6),
	APCS_APR_PWR_CTL(7),
};

const uint64_t apcs_apc_l2_pwr_ctl[MAX_CPU_CLUSTERS] = {
	APCS_APC_L2_PWR_CTL(0),
	APCS_APC_L2_PWR_CTL(1),
	APCS_APC_L2_PWR_CTL(2),
	APCS_APC_L2_PWR_CTL(3),
	APCS_APC_L2_PWR_CTL(4),
	APCS_APC_L2_PWR_CTL(5),
	APCS_APC_L2_PWR_CTL(6),
	APCS_APC_L2_PWR_CTL(7),
	APCS_APC_L2_PWR_CTL(8),
	APCS_APC_L2_PWR_CTL(9),
	APCS_APC_L2_PWR_CTL(10),
	APCS_APC_L2_PWR_CTL(11),
	APCS_APC_L2_PWR_CTL(12),
	APCS_APC_L2_PWR_CTL(13),
	APCS_APC_L2_PWR_CTL(14),
	APCS_APC_L2_PWR_CTL(15),
	APCS_APC_L2_PWR_CTL(16),
	APCS_APC_L2_PWR_CTL(17),
	APCS_APC_L2_PWR_CTL(18),
	APCS_APC_L2_PWR_CTL(19),
	APCS_APC_L2_PWR_CTL(20),
	APCS_APC_L2_PWR_CTL(21),
	APCS_APC_L2_PWR_CTL(22),
	APCS_APC_L2_PWR_CTL(23),
};

const uint64_t apcs_apc_cpu_pwr_ctl[MAX_CPU_NUM] = {
	APCS_APC_CPU_PWR_CTL(0),
	APCS_APC_CPU_PWR_CTL(1),
	APCS_APC_CPU_PWR_CTL(2),
	APCS_APC_CPU_PWR_CTL(3),
	APCS_APC_CPU_PWR_CTL(4),
	APCS_APC_CPU_PWR_CTL(5),
	APCS_APC_CPU_PWR_CTL(6),
	APCS_APC_CPU_PWR_CTL(7),
	APCS_APC_CPU_PWR_CTL(8),
	APCS_APC_CPU_PWR_CTL(9),
	APCS_APC_CPU_PWR_CTL(10),
	APCS_APC_CPU_PWR_CTL(11),
	APCS_APC_CPU_PWR_CTL(12),
	APCS_APC_CPU_PWR_CTL(13),
	APCS_APC_CPU_PWR_CTL(14),
	APCS_APC_CPU_PWR_CTL(15),
	APCS_APC_CPU_PWR_CTL(16),
	APCS_APC_CPU_PWR_CTL(17),
	APCS_APC_CPU_PWR_CTL(18),
	APCS_APC_CPU_PWR_CTL(19),
	APCS_APC_CPU_PWR_CTL(20),
	APCS_APC_CPU_PWR_CTL(21),
	APCS_APC_CPU_PWR_CTL(22),
	APCS_APC_CPU_PWR_CTL(23),
	APCS_APC_CPU_PWR_CTL(24),
	APCS_APC_CPU_PWR_CTL(25),
	APCS_APC_CPU_PWR_CTL(26),
	APCS_APC_CPU_PWR_CTL(27),
	APCS_APC_CPU_PWR_CTL(28),
	APCS_APC_CPU_PWR_CTL(29),
	APCS_APC_CPU_PWR_CTL(30),
	APCS_APC_CPU_PWR_CTL(31),
	APCS_APC_CPU_PWR_CTL(32),
	APCS_APC_CPU_PWR_CTL(33),
	APCS_APC_CPU_PWR_CTL(34),
	APCS_APC_CPU_PWR_CTL(35),
	APCS_APC_CPU_PWR_CTL(36),
	APCS_APC_CPU_PWR_CTL(37),
	APCS_APC_CPU_PWR_CTL(38),
	APCS_APC_CPU_PWR_CTL(39),
	APCS_APC_CPU_PWR_CTL(40),
	APCS_APC_CPU_PWR_CTL(41),
	APCS_APC_CPU_PWR_CTL(42),
	APCS_APC_CPU_PWR_CTL(43),
	APCS_APC_CPU_PWR_CTL(44),
	APCS_APC_CPU_PWR_CTL(45),
	APCS_APC_CPU_PWR_CTL(46),
	APCS_APC_CPU_PWR_CTL(47),
};

const uint64_t apcs_apc_l2_sw_spm_event[MAX_CPU_CLUSTERS] = {
	APCS_APC_L2_SW_SPM_EVENT(0),
	APCS_APC_L2_SW_SPM_EVENT(1),
	APCS_APC_L2_SW_SPM_EVENT(2),
	APCS_APC_L2_SW_SPM_EVENT(3),
	APCS_APC_L2_SW_SPM_EVENT(4),
	APCS_APC_L2_SW_SPM_EVENT(5),
	APCS_APC_L2_SW_SPM_EVENT(6),
	APCS_APC_L2_SW_SPM_EVENT(7),
	APCS_APC_L2_SW_SPM_EVENT(8),
	APCS_APC_L2_SW_SPM_EVENT(9),
	APCS_APC_L2_SW_SPM_EVENT(10),
	APCS_APC_L2_SW_SPM_EVENT(11),
	APCS_APC_L2_SW_SPM_EVENT(12),
	APCS_APC_L2_SW_SPM_EVENT(13),
	APCS_APC_L2_SW_SPM_EVENT(14),
	APCS_APC_L2_SW_SPM_EVENT(15),
	APCS_APC_L2_SW_SPM_EVENT(16),
	APCS_APC_L2_SW_SPM_EVENT(17),
	APCS_APC_L2_SW_SPM_EVENT(18),
	APCS_APC_L2_SW_SPM_EVENT(19),
	APCS_APC_L2_SW_SPM_EVENT(20),
	APCS_APC_L2_SW_SPM_EVENT(21),
	APCS_APC_L2_SW_SPM_EVENT(22),
	APCS_APC_L2_SW_SPM_EVENT(23),
};

/* Two cores per APC, two APC's per SPM. */
const uint64_t apcs_apc_cpu_sw_spm_event[MAX_CPU_NUM] = {
	APCS_APC_CPU_SW_SPM_EVENT(0),
	APCS_APC_CPU_SW_SPM_EVENT(1),
	APCS_APC_CPU_SW_SPM_EVENT(2),
	APCS_APC_CPU_SW_SPM_EVENT(3),
	APCS_APC_CPU_SW_SPM_EVENT(4),
	APCS_APC_CPU_SW_SPM_EVENT(5),
	APCS_APC_CPU_SW_SPM_EVENT(6),
	APCS_APC_CPU_SW_SPM_EVENT(7),
	APCS_APC_CPU_SW_SPM_EVENT(8),
	APCS_APC_CPU_SW_SPM_EVENT(9),
	APCS_APC_CPU_SW_SPM_EVENT(10),
	APCS_APC_CPU_SW_SPM_EVENT(11),
	APCS_APC_CPU_SW_SPM_EVENT(12),
	APCS_APC_CPU_SW_SPM_EVENT(13),
	APCS_APC_CPU_SW_SPM_EVENT(14),
	APCS_APC_CPU_SW_SPM_EVENT(15),
	APCS_APC_CPU_SW_SPM_EVENT(16),
	APCS_APC_CPU_SW_SPM_EVENT(17),
	APCS_APC_CPU_SW_SPM_EVENT(18),
	APCS_APC_CPU_SW_SPM_EVENT(19),
	APCS_APC_CPU_SW_SPM_EVENT(20),
	APCS_APC_CPU_SW_SPM_EVENT(21),
	APCS_APC_CPU_SW_SPM_EVENT(22),
	APCS_APC_CPU_SW_SPM_EVENT(23),
	APCS_APC_CPU_SW_SPM_EVENT(24),
	APCS_APC_CPU_SW_SPM_EVENT(25),
	APCS_APC_CPU_SW_SPM_EVENT(26),
	APCS_APC_CPU_SW_SPM_EVENT(27),
	APCS_APC_CPU_SW_SPM_EVENT(28),
	APCS_APC_CPU_SW_SPM_EVENT(29),
	APCS_APC_CPU_SW_SPM_EVENT(30),
	APCS_APC_CPU_SW_SPM_EVENT(31),
	APCS_APC_CPU_SW_SPM_EVENT(32),
	APCS_APC_CPU_SW_SPM_EVENT(33),
	APCS_APC_CPU_SW_SPM_EVENT(34),
	APCS_APC_CPU_SW_SPM_EVENT(35),
	APCS_APC_CPU_SW_SPM_EVENT(36),
	APCS_APC_CPU_SW_SPM_EVENT(37),
	APCS_APC_CPU_SW_SPM_EVENT(38),
	APCS_APC_CPU_SW_SPM_EVENT(39),
	APCS_APC_CPU_SW_SPM_EVENT(40),
	APCS_APC_CPU_SW_SPM_EVENT(41),
	APCS_APC_CPU_SW_SPM_EVENT(42),
	APCS_APC_CPU_SW_SPM_EVENT(43),
	APCS_APC_CPU_SW_SPM_EVENT(44),
	APCS_APC_CPU_SW_SPM_EVENT(45),
	APCS_APC_CPU_SW_SPM_EVENT(46),
	APCS_APC_CPU_SW_SPM_EVENT(47),
};

const uint64_t saw4_vctl[MAX_CPU_RAILS] = {
	SAW4_VCTL(0),
	SAW4_VCTL(1),
	SAW4_VCTL(2),
	SAW4_VCTL(3),
	SAW4_VCTL(4),
	SAW4_VCTL(5),
	SAW4_VCTL(6),
	SAW4_VCTL(7),
};

const uint64_t saw4_avs_sts[MAX_CPU_RAILS] = {
	SAW4_AVS_STS(0),
	SAW4_AVS_STS(1),
	SAW4_AVS_STS(2),
	SAW4_AVS_STS(3),
	SAW4_AVS_STS(4),
	SAW4_AVS_STS(5),
	SAW4_AVS_STS(6),
	SAW4_AVS_STS(7),
};

/* apcs_apr_war is a structure that maps what apr war control is
 * assigned to each core. This allows easy reference when enabling a
 * particular core.
 */
const uint64_t apcs_apr_war[MAX_CPU_RAILS] = {
	APCS_APR_WAR(0),
	APCS_APR_WAR(1),
	APCS_APR_WAR(2),
	APCS_APR_WAR(3),
	APCS_APR_WAR(4),
	APCS_APR_WAR(5),
	APCS_APR_WAR(6),
	APCS_APR_WAR(7),
};

/* Below is the array of L3 power control registers. */
const uint64_t apcs_pm_cbf_l3u_pwr_ctl[L3_CACHE_BLOCKS] = {
        APCS_PM_CBF_L3U_PWR_CTL(0),
        APCS_PM_CBF_L3U_PWR_CTL(1),
        APCS_PM_CBF_L3U_PWR_CTL(2),
        APCS_PM_CBF_L3U_PWR_CTL(3),
        APCS_PM_CBF_L3U_PWR_CTL(4),
        APCS_PM_CBF_L3U_PWR_CTL(5),
        APCS_PM_CBF_L3U_PWR_CTL(6),
        APCS_PM_CBF_L3U_PWR_CTL(7),
        APCS_PM_CBF_L3U_PWR_CTL(8),
        APCS_PM_CBF_L3U_PWR_CTL(9),
        APCS_PM_CBF_L3U_PWR_CTL(10),
        APCS_PM_CBF_L3U_PWR_CTL(11),
};
