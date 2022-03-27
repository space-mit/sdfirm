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
 * @(#)clk_socv2_zebu.c: DUOWEN SoCv2 ZEBU frequency plan implementation
 * $Id: clk_socv2_zebu.c,v 1.1 2020-10-27 10:26:00 zhenglv Exp $
 */

#include <target/clk.h>

uint32_t input_clks[NR_INPUT_CLKS] = {
	[XO_CLK] = XO_CLK_FREQ,
	[SOC_PLL] = SOC_PLL_FREQ,
	[DDR_BUS_PLL] = DDR_BUS_PLL_FREQ,
	[DDR_PLL] = DDR_PLL_FREQ,
	[COHFAB_PLL] = CFAB_PLL_FREQ,
	[CL0_PLL] = CL_PLL_FREQ,
	[CL1_PLL] = CL_PLL_FREQ,
	[CL2_PLL] = CL_PLL_FREQ,
	[CL3_PLL] = CL_PLL_FREQ,
	[ETH_PLL] = ETH_PLL_FREQ,
	[SYSFAB_PLL] = SFAB_PLL_FREQ,
	[SGMII_PLL] = SGMII_PLL_FREQ,
	[SOC_CLK_DIV2_SEL] = SOC_PLL_FREQ/2,
	[SYSFAB_CLK_SEL] = SFAB_PLL_FREQ,
	[DDR_BUS_CLK_SEL] = DDR_BUS_PLL_FREQ,
	[DDR_CLK_SEL] = DDR_PLL_FREQ,
	[SOC_CLK_SEL] = SOC_PLL_FREQ,
	[COHFAB_CLK_SEL] = CFAB_PLL_FREQ,
	[CL0_CLK_SEL] = CL_PLL_FREQ,
	[CL1_CLK_SEL] = CL_PLL_FREQ,
	[CL2_CLK_SEL] = CL_PLL_FREQ,
	[CL3_CLK_SEL] = CL_PLL_FREQ,
};

#ifdef CONFIG_CLK_MNEMONICS
const char *input_clk_names[NR_INPUT_CLKS] = {
	[XO_CLK] = "xo_clk",
	[SOC_PLL] = "soc_pll",
	[DDR_BUS_PLL] = "ddr_bus_pll",
	[DDR_PLL] = "ddr_pll",
	[COHFAB_PLL] = "cohfab_pll",
	[CL0_PLL] = "cl0_pll",
	[CL1_PLL] = "cl1_pll",
	[CL2_PLL] = "cl2_pll",
	[CL3_PLL] = "cl3_pll",
	[ETH_PLL] = "eth_pll",
	[SYSFAB_PLL] = "sysfab_pll",
	[SGMII_PLL] = "sgmii_pll",
	[SOC_CLK_DIV2_SEL] = "soc_clk_div2_sel",
	[SYSFAB_CLK_SEL] = "sysfab_clk_sel",
	[DDR_BUS_CLK_SEL] = "ddr_bus_clk_sel",
	[DDR_CLK_SEL] = "ddr_clk_sel",
	[SOC_CLK_SEL] = "soc_clk_sel",
	[COHFAB_CLK_SEL] = "cohfab_clk_sel",
	[CL0_CLK_SEL] = "cl0_clk_sel",
	[CL1_CLK_SEL] = "cl1_clk_sel",
	[CL2_CLK_SEL] = "cl2_clk_sel",
	[CL3_CLK_SEL] = "cl3_clk_sel",
};

static const char *get_input_clk_name(clk_clk_t clk)
{
	if (clk >= NR_INPUT_CLKS)
		return NULL;
	return input_clk_names[clk];
}
#else
#define get_input_clk_name	NULL
#endif

static clk_freq_t get_input_clk_freq(clk_clk_t clk)
{
	if (clk >= NR_INPUT_CLKS)
		return INVALID_FREQ;
	return input_clks[clk];
}

struct clk_driver clk_input = {
	.max_clocks = NR_INPUT_CLKS,
	.enable = NULL,
	.disable = NULL,
	.get_freq = get_input_clk_freq,
	.set_freq = NULL,
	.select = NULL,
	.get_name = get_input_clk_name,
};

#ifdef CONFIG_DUOWEN_SBI_DUAL
struct clk_driver clk_input2 = {
	.max_clocks = NR_INPUT_CLKS,
	.enable = NULL,
	.disable = NULL,
	.get_freq = get_input_clk_freq,
	.set_freq = NULL,
	.select = NULL,
	.get_name = get_input_clk_name,
};
#endif /* CONFIG_DUOWEN_SBI_DUAL */

#ifdef CONFIG_CONSOLE_COMMAND
void clk_pll_dump(void)
{
	int i;

	for (i = 0; i < NR_SELECT_CLKS; i++) {
		if (sel_clk_names[i]) {
			printf("clk  %3d %20s %20s\n",
			       i, sel_clk_names[i],
			       clk_get_mnemonic(select_clks[i].clk_sels[0]));
			if (select_clks[i].clk_sels[1] != invalid_clk)
				printf("%4s %3s %20s %20s\n", "", "", "",
				       clk_get_mnemonic(
					       select_clks[i].clk_sels[1]));
		}
	}
}
#endif

void clk_pll_init(void)
{
	clk_register_driver(CLK_INPUT, &clk_input);
#ifdef CONFIG_DUOWEN_SBI_DUAL
	clk_register_driver(CLK_INPUT2, &clk_input2);
#endif /* CONFIG_DUOWEN_SBI_DUAL */
}
