#ifndef __DBG_EVENT_H_INCLUDE__
#define __DBG_EVENT_H_INCLUDE__

/* XXX: Current DBG_SRC Start
 * current DBG_SRC_XXX should not use 0x00, since dumped 0x00 data are
 * too much to be correctly handled as simple raw data
 */
#define DBG_SRC_MAIN		1
#define DBG_SRC_IDLE		2
#define DBG_SRC_IO		3
#define DBG_SRC_USB		4
#define DBG_SRC_SCD		5
#define DBG_SRC_HID		6
#define DBG_SRC_SCS		7
#define DBG_SRC_MSD		8
#define DBG_SRC_DFU		9
#define DBG_SRC_UART		10
#define DBG_SRC_BULK		11
#define DBG_SRC_USER		12
#define DBG_SRC_MMC		13
#define DBG_SRC_ESPI		14
#define NR_DBG_SRCS		15
/* XXX: Current DBG_SRCS Limitation
 * current NR_DBG_SRCS should not exceed 0x14, or 0x15 could not be used
 * as raw data in the UI
 */

#define IO_DEBUG_BASE		(DBG_SRC_IO<<4)
#define IO_DEBUG_KEY_DOWN	IO_DEBUG_BASE+0
#define IO_DEBUG_KEY_UP		IO_DEBUG_BASE+1
#define IO_DEBUG_WAIT_KEY	IO_DEBUG_BASE+2
#define NR_IO_EVENTS		(IO_DEBUG_WAIT_KEY - IO_DEBUG_BASE + 1)

#define USB_DEBUG_BASE		(DBG_SRC_USB<<4)
#define USB_DEBUG_IRQ		USB_DEBUG_BASE+0
#define USB_DEBUG_STATE		USB_DEBUG_BASE+1
#define USB_DEBUG_STAGE		USB_DEBUG_BASE+2
#define USB_DEBUG_SETUP		USB_DEBUG_BASE+3
#define USB_DEBUG_DESC		USB_DEBUG_BASE+4
#define USB_DEBUG_ENDP		USB_DEBUG_BASE+5
#define USB_DEBUG_INTF		USB_DEBUG_BASE+6
#define USB_DEBUG_CALL		USB_DEBUG_BASE+7
#define NR_USB_EVENTS		(USB_DEBUG_CALL - IO_DEBUG_BASE + 1)

#define SCD_DEBUG_BASE		(DBG_SRC_SCD<<4)
#define SCD_DEBUG_CS_REQ	SCD_DEBUG_BASE+0
#define SCD_DEBUG_PC2RDR	SCD_DEBUG_BASE+1
#define SCD_DEBUG_RDR2PC	SCD_DEBUG_BASE+2
#define SCD_DEBUG_SLOT		SCD_DEBUG_BASE+3
#define SCD_DEBUG_INTR		SCD_DEBUG_BASE+4
#define SCD_DEBUG_STATE		SCD_DEBUG_BASE+5
#define SCD_DEBUG_DIGIT		SCD_DEBUG_BASE+6
#define SCD_DEBUG_INS		SCD_DEBUG_BASE+7
#define SCD_DEBUG_ABORT		SCD_DEBUG_BASE+8
#define NR_SCD_EVENTS		(SCD_DEBUG_ABORT - SCD_DEBUG_BASE + 1)

#define HID_DEBUG_BASE		(DBG_SRC_HID<<4)
#define HID_DEBUG_CS_REQ	HID_DEBUG_BASE+0
#define HID_DEBUG_DESC		HID_DEBUG_BASE+1
#define HID_DEBUG_REPORT	HID_DEBUG_BASE+2
#define HID_DEBUG_INTR		HID_DEBUG_BASE+3
#define NR_HID_EVENTS		(HID_DEBUG_INTR - HID_DEBUG_BASE + 1)

#define SCS_DEBUG_BASE		(DBG_SRC_SCS<<4)
#define SCS_DEBUG_SLOT		SCS_DEBUG_BASE+0
#define SCS_DEBUG_SLOT_EVENT	SCS_DEBUG_BASE+1
#define SCS_DEBUG_SLOT_STATE	SCS_DEBUG_BASE+2
#define SCS_DEBUG_XCHG_STATE	SCS_DEBUG_BASE+3
#define SCS_DEBUG_XCHG_EVENT	SCS_DEBUG_BASE+4
#define SCS_DEBUG_SEQ		SCS_DEBUG_BASE+5
#define SCS_DEBUG_ERROR		SCS_DEBUG_BASE+6
#define SCS_DEBUG_CLASS		SCS_DEBUG_BASE+7
#define SCS_DEBUG_CONV		SCS_DEBUG_BASE+8
#define SCS_DEBUG_CONF_ETU	SCS_DEBUG_BASE+9
#define SCS_DEBUG_CONF_WT	SCS_DEBUG_BASE+10
#define SCS_DEBUG_CONF_GT	SCS_DEBUG_BASE+11
#define NR_SCS_EVENTS		(SCS_DEBUG_CONF_GT - SCS_DEBUG_BASE + 1)

#define MSD_DEBUG_BASE		(DBG_SRC_MSD<<4)
#define MSD_DEBUG_CS_REQ	MSD_DEBUG_BASE+0
#define MSD_DEBUG_STATE		MSD_DEBUG_BASE+1
#define MSD_DEBUG_HALT		MSD_DEBUG_BASE+2
#define NR_MSD_EVENTS		(MSD_DEBUG_HALT - MSD_DEBUG_BASE + 1)

#define DFU_DEBUG_BASE		(DBG_SRC_DFU<<4)
#define DFU_DEBUG_CS_REQ	DFU_DEBUG_BASE+0
#define DFU_DEBUG_STATE		DFU_DEBUG_BASE+1
#define DFU_DEBUG_ERROR		DFU_DEBUG_BASE+2
#define NR_DFU_EVENTS		(DFU_DEBUG_ERROR - DFU_DEBUG_BASE + 1)

#define UART_DEBUG_BASE		(DBG_SRC_UART<<4)
#define UART_DEBUG_IRQ		UART_DEBUG_BASE+0
#define UART_DEBUG_PORT		UART_DEBUG_BASE+1
#define UART_DEBUG_OOB		UART_DEBUG_BASE+2
#define UART_DEBUG_UNOOB	UART_DEBUG_BASE+3
#define NR_UART_EVENTS		(UART_DEBUG_UNOOB - UART_DEBUG_BASE + 1)

#define BULK_DEBUG_BASE		(DBG_SRC_BULK<<4)
#define BULK_DEBUG_SET_FLAG	BULK_DEBUG_BASE+0
#define BULK_DEBUG_CLEAR_FLAG	BULK_DEBUG_BASE+1
#define BULK_DEBUG_FLOW		BULK_DEBUG_BASE+2
#define BULK_DEBUG_CHAN		BULK_DEBUG_BASE+3
#define NR_BULK_EVENTS		(BULK_DEBUG_CHAN - BULK_DEBUG_BASE + 1)

#define USER_DEBUG_BASE		(DBG_SRC_USER<<4)
#define PN53X_DEBUG_USB_STATE	USER_DEBUG_BASE+0
#define PN53X_DEBUG_USB_FLAGS	USER_DEBUG_BASE+1
#define PN53X_DEBUG_CMD_CODE	USER_DEBUG_BASE+2
#define PN53X_DEBUG_ERR_CODE	USER_DEBUG_BASE+3
#define EZIO_DEBUG_CMD		USER_DEBUG_BASE+4
#define EZIO_DEBUG_STATE	USER_DEBUG_BASE+5
#define NR_USER_EVENTS		(EZIO_DEBUG_STATE - USER_DEBUG_BASE + 1)

#define MMC_DEBUG_BASE		(DBG_SRC_MMC<<4)
#define MMC_DEBUG_OP		MMC_DEBUG_BASE+0
#define MMC_DEBUG_STATE		MMC_DEBUG_BASE+1
#define MMC_DEBUG_EVENT		MMC_DEBUG_BASE+2
#define MMC_DEBUG_CMD		MMC_DEBUG_BASE+3
#define MMC_DEBUG_ACMD		MMC_DEBUG_BASE+4
#define MMC_DEBUG_ERROR		MMC_DEBUG_BASE+5
#define NR_MMC_EVENTS		(MMC_DEBUG_ERROR - MMC_DEBUG_BASE + 1)

#define ESPI_DEBUG_BASE		(DBG_SRC_ESPI<<4)
#define ESPI_DEBUG_OP		ESPI_DEBUG_BASE+0
#define ESPI_DEBUG_STATE	ESPI_DEBUG_BASE+1
#define ESPI_DEBUG_EVENT	ESPI_DEBUG_BASE+2
#define ESPI_DEBUG_REG		ESPI_DEBUG_BASE+3

#define IDLE_DEBUG_BASE		(DBG_SRC_IDLE<<4)
#define IDLE_DEBUG_SID		IDLE_DEBUG_BASE
#define IDLE_DEBUG_TID		IDLE_DEBUG_BASE+1
#define NR_IDLE_EVENTS		(IDLE_DEBUG_TID - IDLE_DEBUG_BASE + 1)

#define MAIN_DEBUG_BASE		(DBG_SRC_MAIN<<4)
#define MAIN_DEBUG_INIT		MAIN_DEBUG_BASE
#define MAIN_DEBUG_PANIC	MAIN_DEBUG_BASE+1
#define NR_MAIN_EVENTS		(MAIN_DEBUG_PANIC - MAIN_DEBUG_BASE + 1)

#endif /* __DBG_EVENT_H_INCLUDE__ */
