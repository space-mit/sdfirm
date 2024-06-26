#include <target/kcs.h>

static uint8_t kcs_state = KCS_IDLE_STATE;
static uint8_t kcs_event = 0;

uint8_t txn_write_buf[8];
uint8_t txn_read_buf[8];
uint8_t txn_read_idx;
uint8_t txn_write_idx;

bh_t kcs_bh;

void kcs_enter_state(uint8_t state);
void kcs_handle_event(void);

void kcs_obf_set_index(uint8_t idx)
{
	txn_write_idx = idx;
	if (idx == 0)
		kcs_hw_clear_status(KCS_OBF);
}

void kcs_obf_write(void)
{
	if (txn_write_idx > 0) {
		kcs_hw_write_obf(txn_write_buf[txn_write_idx]);
		kcs_obf_set_index(txn_write_idx - 1);
	} else {
		kcs_enter_state(KCS_IDLE_STATE);
	}
}

void kcs_ibf_set_index(uint8_t idx)
{
	txn_read_idx = idx;
	if (idx == 0)
		kcs_hw_clear_status(KCS_OBF);
}

void kcs_ibf_read(void)
{
	if (txn_read_idx < 8) {
		txn_read_buf[txn_read_idx] = kcs_hw_read_dat();
		kcs_ibf_set_index(txn_read_idx+1);
	} else {
		kcs_enter_state(KCS_ERROR_STATE);
	}
}

void kcs_enter_state(uint8_t state)
{
	kcs_state = state;
	if (state == KCS_IDLE_STATE) {
		txn_read_idx = 0;
		txn_write_idx = 0;
	}
	if (state == KCS_WRITE_STATE)
		kcs_ibf_read();
	if (state == KCS_READ_STATE)
		kcs_obf_write();
	kcs_hw_write_state(kcs_state);
}

void kcs_raise_event(uint8_t event)
{
	kcs_event |= event;
	kcs_handle_event();
}

void kcs_handle_transaction(void)
{
	if (txn_read_idx > 0) {
		uint8_t len = txn_read_idx;

		while (len) {
			kcs_obf_write();
			len--;
		}
	} else
		kcs_obf_write();
}

void kcs_read_cmd(void)
{
	uint8_t cmd = kcs_hw_read_cmd();

	switch (cmd) {
		case KCS_GET_STATUS:
			kcs_enter_state(KCS_IDLE_STATE);
			break;
		case KCS_WRITE_START:
			kcs_enter_state(KCS_WRITE_STATE);
			break;
		case KCS_WRITE_END:
			kcs_ibf_read();
			kcs_enter_state(KCS_IDLE_STATE);
			kcs_handle_transaction();
			break;
		case KCS_READ:
			kcs_enter_state(KCS_READ_STATE);
			break;
	}
}

#ifdef SYS_REALTIME
static void kcs_poll_init(void)
{
	irq_register_poller(kcs_bh);
}

static void kcs_poll_irqs(void)
{
	kcs_hw_poll_irqs();
}
#define kcs_irq_init()			do { } while (0)
#else
#define kcs_poll_irqs()			do { } while (0)
#define kcs_poll_init()			do { } while (0)
#define kcs_irq_init()			kcs_hw_irq_init()
#endif

void kcs_handle_event(void)
{
	uint8_t event = kcs_event;
	uint8_t state = kcs_state;
	if (event & KCS_EVENT_IBF) {
		kcs_read_cmd();
	} else if (event & KCS_EVENT_OBF) {
		if (state & KCS_READ_STATE)
			kcs_obf_write();
	}
}

void kcs_bh_handler(uint8_t events)
{
	if (events == BH_POLLIRQ)
		kcs_poll_irqs();
	else
		kcs_handle_event();
}

void kcs_init(void)
{
	kcs_bh = bh_register_handler(kcs_bh_handler);
	kcs_irq_init();
	kcs_poll_init();
}

void kcs_handler(void) {
	// while (1) {
	// 	kcs_hw_slave();
	// }
}