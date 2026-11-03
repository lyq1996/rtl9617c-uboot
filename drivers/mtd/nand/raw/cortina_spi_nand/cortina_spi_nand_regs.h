/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __DRIVERS_MTD_NAND_RAW_CORTINA_SPI_NAND_CORTINA_SPI_NAND_REGS_H__
#define __DRIVERS_MTD_NAND_RAW_CORTINA_SPI_NAND_CORTINA_SPI_NAND_REGS_H__

#include <linux/types.h>

#define FLASH_ID                                 0xf4324000
#define FLASH_ID_dft                             0x00000101

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 flashRevID           :  8 ; /* bits 7:0 */
    u32 flashDevID           : 24 ; /* bits 31:8 */
  } bf ;
  u32     wrd ;
} FLASH_ID_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_TIMEOUT                            0xf4324004
#define FLASH_TIMEOUT_dft                        0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 timeout_load         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} FLASH_TIMEOUT_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_STATUS                             0xf4324008
#define FLASH_STATUS_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sState               :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} FLASH_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_TYPE                               0xf432400c
#define FLASH_TYPE_dft                           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  9 ;
    u32 flashSize            :  2 ; /* bits 10:9 */
    u32 flashWidth           :  1 ; /* bits 11:11 */
    u32 flashType            :  3 ; /* bits 14:12 */
    u32 flashPin             :  1 ; /* bits 15:15 */
    u32 rsrvd2               : 16 ;
  } bf ;
  u32     wrd ;
} FLASH_TYPE_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_FLASH_ACCESS_START                 0xf4324010
#define FLASH_FLASH_ACCESS_START_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  1 ;
    u32 sflashRegReq         :  1 ; /* bits 1:1 */
    u32 rsrvd2               :  1 ;
    u32 sflashFifoReq        :  1 ; /* bits 3:3 */
    u32 rsrvd3               :  5 ;
    u32 sflashRegCmd         :  1 ; /* bits 9:9 */
    u32 rsrvd4               :  6 ;
    u32 sflashbusy           :  1 ; /* bits 16:16 */
    u32 rsrvd5               : 15 ;
  } bf ;
  u32     wrd ;
} FLASH_FLASH_ACCESS_START_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_FLASH_INTERRUPT                    0xf4324014
#define FLASH_FLASH_INTERRUPT_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 regIrq               :  1 ; /* bits 0:0 */
    u32 fifoIrq              :  1 ; /* bits 1:1 */
    u32 f_addr_err           :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} FLASH_FLASH_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_FLASH_MASK                         0xf4324018
#define FLASH_FLASH_MASK_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 flashRegIrqMask      :  1 ; /* bits 0:0 */
    u32 fifoIrqMask          :  1 ; /* bits 1:1 */
    u32 f_addr_IrqMask       :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} FLASH_FLASH_MASK_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_FIFO_CONTROL                       0xf432401c
#define FLASH_FIFO_CONTROL_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 fifoCmd              :  2 ; /* bits 1:0 */
    u32 rsrvd1               :  2 ;
    u32 fifoDbgSel           :  4 ; /* bits 7:4 */
    u32 fifoClear            :  1 ; /* bits 8:8 */
    u32 rsrvd2               : 15 ;
    u32 fifoRDTH             :  2 ; /* bits 25:24 */
    u32 fifoWRTH             :  2 ; /* bits 27:26 */
    u32 rsrvd3               :  4 ;
  } bf ;
  u32     wrd ;
} FLASH_FIFO_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_FIFO_STATUS                        0xf4324020
#define FLASH_FIFO_STATUS_dft                    0x00000004

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 f_state              :  2 ; /* bits 1:0 */
    u32 f_empty              :  1 ; /* bits 2:2 */
    u32 f_full               :  1 ; /* bits 3:3 */
    u32 f_ptr_rd             :  5 ; /* bits 8:4 */
    u32 f_ptr_wr             :  5 ; /* bits 13:9 */
    u32 rsrvd1               :  2 ;
    u32 f_addr_count         :  8 ; /* bits 23:16 */
    u32 rsrvd2               :  8 ;
  } bf ;
  u32     wrd ;
} FLASH_FIFO_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_FIFO_ADDRESS                       0xf4324024
#define FLASH_FIFO_ADDRESS_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 f_AXADDR             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} FLASH_FIFO_ADDRESS_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_FIFO_MATCH_ADDRESS                 0xf4324028
#define FLASH_FIFO_MATCH_ADDRESS_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 f_AXADDR_compare     : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} FLASH_FIFO_MATCH_ADDRESS_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_FIFO_DATA                          0xf432402c
#define FLASH_FIFO_DATA_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 f_ebuf_mem1          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} FLASH_FIFO_DATA_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_SF_ACCESS                          0xf4324030
#define FLASH_SF_ACCESS_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sflashOpCode         :  8 ; /* bits 7:0 */
    u32 sflashAcCode         :  4 ; /* bits 11:8 */
    u32 sflashForceTerm      :  1 ; /* bits 12:12 */
    u32 sflashForceBurst     :  1 ; /* bits 13:13 */
    u32 rsrvd1               :  1 ;
    u32 sflashCnMode         :  1 ; /* bits 15:15 */
    u32 sflashCeAlt          :  1 ; /* bits 16:16 */
    u32 sflashHSRd           :  1 ; /* bits 17:17 */
    u32 rsrvd2               :  6 ;
    u32 sflashMData          :  1 ; /* bits 24:24 */
    u32 sflashMAddr          :  1 ; /* bits 25:25 */
    u32 sflashMCmd           :  1 ; /* bits 26:26 */
    u32 rsrvd3               :  1 ;
    u32 sflashDDR            :  2 ; /* bits 29:28 */
    u32 sflashMIO            :  2 ; /* bits 31:30 */
  } bf ;
  u32     wrd ;
} FLASH_SF_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_SF_EXT_ACCESS                      0xf4324034
#define FLASH_SF_EXT_ACCESS_dft                  0x3fffff00

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sflashOpCode         :  8 ; /* bits 7:0 */
    u32 sflashDataCount      : 13 ; /* bits 20:8 */
    u32 sflashAddrCount      :  3 ; /* bits 23:21 */
    u32 sflashDummyCount     :  6 ; /* bits 29:24 */
    u32 rsrvd1               :  1 ;
    u32 sflashDirRdCmdEn     :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} FLASH_SF_EXT_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_SF_ADDRESS                         0xf4324038
#define FLASH_SF_ADDRESS_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sflashRegAddr        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} FLASH_SF_ADDRESS_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_SF_DATA                            0xf432403c
#define FLASH_SF_DATA_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sflashRegWData       : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} FLASH_SF_DATA_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_SF_TIMING                          0xf4324040
#define FLASH_SF_TIMING_dft                      0x10373737

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sflashIdleTime       :  8 ; /* bits 7:0 */
    u32 sflashHoldTime       :  8 ; /* bits 15:8 */
    u32 sflashSetupTime      :  8 ; /* bits 23:16 */
    u32 sflashClkWidth       :  4 ; /* bits 27:24 */
    u32 sflashPipe_lat       :  2 ; /* bits 29:28 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} FLASH_SF_TIMING_t;
#endif /* !__ASSEMBLER__ */
#define FLASH_SF_PREDICTOR                       0xf4324044
#define FLASH_SF_PREDICTOR_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 predictor            :  8 ; /* bits 7:0 */
    u32 flashbpwstrob        :  1 ; /* bits 8:8 */
    u32 rsrvd1               : 22 ;
    u32 en_predictor         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} FLASH_SF_PREDICTOR_t;
#endif /* !__ASSEMBLER__ */

#endif /* __DRIVERS_MTD_NAND_RAW_CORTINA_SPI_NAND_CORTINA_SPI_NAND_REGS_H__ */
