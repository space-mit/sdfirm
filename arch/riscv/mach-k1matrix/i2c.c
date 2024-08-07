#include <target/i2c.h>
#include <target/gpio.h>

bool k1matrix_i2c_initialized = false;

#if 0
static inline void k1matrix_i2c_gpio(uint16_t pin, uint8_t pad, uint8_t mux)
{
	gpio_config_mux(GPIO0B, pin, mux);
	gpio_config_pad(GPIO0B, pin, pad, 8);
}
#endif

void i2c_hw_ctrl_init(void)
{
	if (!k1matrix_i2c_initialized) {
#if 0
		k1matrix_i2c_gpio(pad_gpio_8, GPIO_PAD_PULL_DOWN,
				TLMM_PAD_FUNCTION);
		k1matrix_i2c_gpio(pad_gpio_9, GPIO_PAD_PULL_DOWN,
				TLMM_PAD_FUNCTION);
		clk_enable(i2c0_clk + i2c_mid);
#endif
		k1matrix_i2c_initialized = true;
	}
	dw_i2c_master_init();
}

