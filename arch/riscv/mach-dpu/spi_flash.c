#include <target/clk.h>

void dpu_flash_set_frequency(uint32_t freq)
{
	__raw_writel(div32u(APB_CLK_FREQ + freq - 1, freq), SPI_DIVIDER);
}
