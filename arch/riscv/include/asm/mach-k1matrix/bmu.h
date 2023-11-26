#ifndef __BMU_K1MATRIX_H_INCLUDE__
#define __BMU_K1MATRIX_H_INCLUDE__

#define BMU_REG(offset)		(BMU_BASE + (offset))

#define BMU_INTR_MASK		BMU_REG(0x00)
#define BMU_INTR_STAT		BMU_REG(0x04)
#define BMU_INTR_STAT_MASK	BMU_REG(0x08)
#define BMU_CTRL_X		BMU_REG(0x0C)
#define BMU_M_INTERNAL		BMU_REG(0x10)
#define BMU_OVER_TIME_THR	BMU_REG(0x14)
#define BMU_RD_OVTIME_ADDRL	BMU_REG(0x18)
#define BMU_RD_OVTIME_ADDRH	BMU_REG(0x1C)
#define BMU_RD_OVTIME_ADDR_VLD	BMU_REG(0x20)
#define BMU_RD_OVTIME_VECTOR(n)	BMU_REG(0x24 + ((n) << 2))
#define BMU_WR_OVTIME_ADDRL	BMU_REG(0x34)
#define BMU_WR_OVTIME_ADDRH	BMU_REG(0x34)
#define BMU_WR_OVTIME_ADDR_VLD	BMU_REG(0x3C)
#define BMU_WR_OVTIME_VECTOR(n)	BMU_REG(0x40 + ((n) << 2))
#define BMU_RD_TRAN_CNT		BMU_REG(0x50)
#define BMU_RD_DATA_CNT		BMU_REG(0x54)
#define BMU_RD_DURATION_CNT	BMU_REG(0x58)
#define BMU_RD_DRT_OVTHR_CNT	BMU_REG(0x5C)
#define BMU_WR_TRAN_CNT		BMU_REG(0x60)
#define BMU_WR_DATA_CNT		BMU_REG(0x64)
#define BMU_WR_DURATION_CNT	BMU_REG(0x68)
#define BMU_WR_DRT_OVTHR_CNT	BMU_REG(0x6C)
#define BMU_FILT_RD_TRAN_CNT	BMU_REG(0x70)
#define BMU_FILT_WR_TRAN_CNT	BMU_REG(0x74)
#define BMU_RD_ERROR_RES	BMU_REG(0x78)
#define BMU_WR_ERROR_RES	BMU_REG(0x7C)
#define BMU_DATA_HIT_DATA(n)	BMU_REG(0x80 + ((n) << 2)
#define BMU_DATA_HIT_MASK	BMU_REG(0x90)
#define BMU_TGT_HIT_ADDRL	BMU_REG(0x94)
#define BMU_TGT_HIT_ADDRH	BMU_REG(0x98)
#define BMU_ADDR_HIT_ADDR_MASKL	BMU_REG(0x9C)
#define BMU_ADDR_HIT_ADDR_MASKH	BMU_REG(0xA0)
#define BMU_RD_ID_FILTER	BMU_REG(0xA4)
#define BMU_RD_ID_FILTER_MASK	BMU_REG(0xA8)
#define BMU_WR_ID_FILTER	BMU_REG(0xAC)
#define BMU_WR_ID_FILTER_MASK	BMU_REG(0xB0)
#define BMU_RD_FILT_UP_ADDRL	BMU_REG(0xB4)
#define BMU_RD_FILT_UP_ADDRH	BMU_REG(0xB8)
#define BMU_RD_FILT_LOW_ADDRL	BMU_REG(0xBC)
#define BMU_RD_FILT_LOW_ADDRH	BMU_REG(0xC0)
#define BMU_RD_FILT_TGT_ADDRL	BMU_REG(0xC4)
#define BMU_RD_FILT_TGT_ADDRH	BMU_REG(0xC8)
#define BMU_RD_FILT_ADDR_MASKL	BMU_REG(0xCC)
#define BMU_RD_FILT_ADDR_MASKH	BMU_REG(0xD0)
#define BMU_RD_FILT_TARGET_LEN	BMU_REG(0xD4)

#endif /* __BMU_K1MATRIX_H_INCLUDE__ */
