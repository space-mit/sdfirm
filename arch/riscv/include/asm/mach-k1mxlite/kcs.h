#ifndef __KCS_K1MXLITE_H_INCLUDE__
#define __KCS_K1MXLITE_H_INCLUDE__

#ifdef CONFIG_KCS_MICROSEMI_CORELPC
#define ARCH_HAS_KCS				1
#include <driver/corelpc.h>

#define kcs_hw_read_cmd()			corelpc_read_kibr()
#define kcs_hw_read_dat()			corelpc_read_kibr()
#define kcs_hw_write_dat(dat)			corelpc_write_kobr(dat)
#define kcs_hw_write_state(state)		corelpc_write_state(state)
#define kcs_hw_write_obf(obf)			corelpc_write_obf(obf)
#define kcs_hw_clear_status(status)		corelpc_clear_status(status)
#define kcs_hw_poll_irqs()			corelpc_poll_irqs()
#define kcs_hw_irq_init()			corelpc_kcs_init()
#endif

#ifdef CONFIG_K1MXLITE_KCS
void k1mxlite_kcs_init(void);
#else
#define k1mxlite_kcs_init()			do {} while (0)
#endif

#endif /* __KCS_K1MXLITE_H_INCLUDE__ */
