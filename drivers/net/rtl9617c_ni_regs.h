/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __DRIVERS_NET_RTL9617C_NI_REGS_H__
#define __DRIVERS_NET_RTL9617C_NI_REGS_H__

#include <linux/types.h>

#define L2TM_L2TM_GLB_REV_ID                     0xf4302000
#define L2TM_L2TM_GLB_REV_ID_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 minor                : 16 ; /* bits 15:0 */
    u32 major                : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_GLB_REV_ID_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_GLB_INT                        0xf4302004
#define L2TM_L2TM_GLB_INT_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bm                   :  1 ; /* bits 0:0 */
    u32 qm                   :  1 ; /* bits 1:1 */
    u32 bm1                  :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_GLB_INT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_GLB_INTE                       0xf4302008
#define L2TM_L2TM_GLB_INTE_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bmE                  :  1 ; /* bits 0:0 */
    u32 qmE                  :  1 ; /* bits 1:1 */
    u32 bm1E                 :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_GLB_INTE_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_GLB_STS                        0xf430200c
#define L2TM_L2TM_GLB_STS_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               : 14 ;
    u32 voqinfo_ram_init_done :  1 ; /* bits 14:14 */
    u32 freeq_ram_init_done  :  1 ; /* bits 15:15 */
    u32 rsrvd2               : 14 ;
    u32 idle                 :  1 ; /* bits 30:30 */
    u32 init_done            :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_GLB_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_GLB_CTRL                       0xf4302010
#define L2TM_L2TM_GLB_CTRL_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               : 31 ;
    u32 cntrcfg_clear_on_read :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_GLB_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_GLB_SPARE_CFG                  0xf4302014
#define L2TM_L2TM_GLB_SPARE_CFG_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 spare                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_GLB_SPARE_CFG_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_GLB_SPARE_STS                  0xf4302018
#define L2TM_L2TM_GLB_SPARE_STS_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 spare                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_GLB_SPARE_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_GLB_SRAM_TEST_CONTROL_0        0xf430201c
#define L2TM_L2TM_GLB_SRAM_TEST_CONTROL_0_dft    0x00000202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 test_cfg0            :  8 ; /* bits 7:0 */
    u32 test_cfg1            :  8 ; /* bits 15:8 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_GLB_SRAM_TEST_CONTROL_0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_GLB_SRAM_LS_CONTROL            0xf4302020
#define L2TM_L2TM_GLB_SRAM_LS_CONTROL_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 l2te1_sramls         :  6 ; /* bits 5:0 */
    u32 rsrvd1               :  2 ;
    u32 l2te2_sramls         :  6 ; /* bits 13:8 */
    u32 l2te3_sramls         :  8 ; /* bits 21:14 */
    u32 rsrvd2               :  1 ;
    u32 l2tm2a_sramls        :  1 ; /* bits 23:23 */
    u32 l2tm_repair1_sramls  :  1 ; /* bits 24:24 */
    u32 rsrvd3               :  7 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_GLB_SRAM_LS_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_GLB_FPGA_REV_ID                0xf4302024
#define L2TM_L2TM_GLB_FPGA_REV_ID_dft            0x00000084

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 FPGA_ver             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_GLB_FPGA_REV_ID_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_INT                         0xf4302100
#define L2TM_L2TM_BM_INT_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sb_drop              :  1 ; /* bits 0:0 */
    u32 hdr_drop             :  1 ; /* bits 1:1 */
    u32 te_drop              :  1 ; /* bits 2:2 */
    u32 wvoqid               :  1 ; /* bits 3:3 */
    u32 szerr                :  1 ; /* bits 4:4 */
    u32 seglenerr            :  1 ; /* bits 5:5 */
    u32 seq_err              :  1 ; /* bits 6:6 */
    u32 fc_mirror_drop       :  1 ; /* bits 7:7 */
    u32 dq_sb_drop           :  1 ; /* bits 8:8 */
    u32 dq_hdr_drop          :  1 ; /* bits 9:9 */
    u32 dq_wvoqid            :  1 ; /* bits 10:10 */
    u32 dq_szerr             :  1 ; /* bits 11:11 */
    u32 dq_seglenerr         :  1 ; /* bits 12:12 */
    u32 dq_seq_err           :  1 ; /* bits 13:13 */
    u32 dq_ff_undrflo        :  1 ; /* bits 14:14 */
    u32 dq_ff_ovrflo         :  1 ; /* bits 15:15 */
    u32 dq_pack_ff_undrflo   :  1 ; /* bits 16:16 */
    u32 dq_pack_ff_ovrflo    :  1 ; /* bits 17:17 */
    u32 fe_ff_undrflo        :  1 ; /* bits 18:18 */
    u32 fe_ff_ovrflo         :  1 ; /* bits 19:19 */
    u32 pack_ff_undrflo      :  1 ; /* bits 20:20 */
    u32 pack_ff_ovrflo       :  1 ; /* bits 21:21 */
    u32 wdat_ff_undrflo      :  1 ; /* bits 22:22 */
    u32 wdat_ff_ovrflo       :  1 ; /* bits 23:23 */
    u32 wcmd_ff_undrflo      :  1 ; /* bits 24:24 */
    u32 wcmd_ff_ovrflo       :  1 ; /* bits 25:25 */
    u32 rdat_ff_undrflo      :  1 ; /* bits 26:26 */
    u32 rdat_ff_ovrflo       :  1 ; /* bits 27:27 */
    u32 rcmd_ff_undrflo      :  1 ; /* bits 28:28 */
    u32 rcmd_ff_ovrflo       :  1 ; /* bits 29:29 */
    u32 rcyc_ff_undrflo      :  1 ; /* bits 30:30 */
    u32 rcyc_ff_ovrflo       :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_INT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_INTE                        0xf4302104
#define L2TM_L2TM_BM_INTE_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sb_dropE             :  1 ; /* bits 0:0 */
    u32 hdr_dropE            :  1 ; /* bits 1:1 */
    u32 te_dropE             :  1 ; /* bits 2:2 */
    u32 wvoqidE              :  1 ; /* bits 3:3 */
    u32 szerrE               :  1 ; /* bits 4:4 */
    u32 seglenerrE           :  1 ; /* bits 5:5 */
    u32 seq_errE             :  1 ; /* bits 6:6 */
    u32 fc_mirror_dropE      :  1 ; /* bits 7:7 */
    u32 dq_sb_dropE          :  1 ; /* bits 8:8 */
    u32 dq_hdr_dropE         :  1 ; /* bits 9:9 */
    u32 dq_wvoqidE           :  1 ; /* bits 10:10 */
    u32 dq_szerrE            :  1 ; /* bits 11:11 */
    u32 dq_seglenerrE        :  1 ; /* bits 12:12 */
    u32 dq_seq_errE          :  1 ; /* bits 13:13 */
    u32 dq_ff_undrfloE       :  1 ; /* bits 14:14 */
    u32 dq_ff_ovrfloE        :  1 ; /* bits 15:15 */
    u32 dq_pack_ff_undrfloE  :  1 ; /* bits 16:16 */
    u32 dq_pack_ff_ovrfloE   :  1 ; /* bits 17:17 */
    u32 fe_ff_undrfloE       :  1 ; /* bits 18:18 */
    u32 fe_ff_ovrfloE        :  1 ; /* bits 19:19 */
    u32 pack_ff_undrfloE     :  1 ; /* bits 20:20 */
    u32 pack_ff_ovrfloE      :  1 ; /* bits 21:21 */
    u32 wdat_ff_undrfloE     :  1 ; /* bits 22:22 */
    u32 wdat_ff_ovrfloE      :  1 ; /* bits 23:23 */
    u32 wcmd_ff_undrfloE     :  1 ; /* bits 24:24 */
    u32 wcmd_ff_ovrfloE      :  1 ; /* bits 25:25 */
    u32 rdat_ff_undrfloE     :  1 ; /* bits 26:26 */
    u32 rdat_ff_ovrfloE      :  1 ; /* bits 27:27 */
    u32 rcmd_ff_undrfloE     :  1 ; /* bits 28:28 */
    u32 rcmd_ff_ovrfloE      :  1 ; /* bits 29:29 */
    u32 rcyc_ff_undrfloE     :  1 ; /* bits 30:30 */
    u32 rcyc_ff_ovrfloE      :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_INTE_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_INT1                        0xf4302108
#define L2TM_L2TM_BM_INT1_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 abr_flush_cos0       :  1 ; /* bits 0:0 */
    u32 abr_flush_cos1       :  1 ; /* bits 1:1 */
    u32 abr_flush_cos2       :  1 ; /* bits 2:2 */
    u32 abr_flush_cos3       :  1 ; /* bits 3:3 */
    u32 abr_flush_cos4       :  1 ; /* bits 4:4 */
    u32 abr_flush_cos5       :  1 ; /* bits 5:5 */
    u32 abr_flush_cos6       :  1 ; /* bits 6:6 */
    u32 abr_flush_cos7       :  1 ; /* bits 7:7 */
    u32 abr_drop_cos0        :  1 ; /* bits 8:8 */
    u32 abr_drop_cos1        :  1 ; /* bits 9:9 */
    u32 abr_drop_cos2        :  1 ; /* bits 10:10 */
    u32 abr_drop_cos3        :  1 ; /* bits 11:11 */
    u32 abr_drop_cos4        :  1 ; /* bits 12:12 */
    u32 abr_drop_cos5        :  1 ; /* bits 13:13 */
    u32 abr_drop_cos6        :  1 ; /* bits 14:14 */
    u32 abr_drop_cos7        :  1 ; /* bits 15:15 */
    u32 dq_abr_drop_cos0     :  1 ; /* bits 16:16 */
    u32 dq_abr_drop_cos1     :  1 ; /* bits 17:17 */
    u32 dq_abr_drop_cos2     :  1 ; /* bits 18:18 */
    u32 dq_abr_drop_cos3     :  1 ; /* bits 19:19 */
    u32 dq_abr_drop_cos4     :  1 ; /* bits 20:20 */
    u32 dq_abr_drop_cos5     :  1 ; /* bits 21:21 */
    u32 dq_abr_drop_cos6     :  1 ; /* bits 22:22 */
    u32 dq_abr_drop_cos7     :  1 ; /* bits 23:23 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_INT1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_INT1E                       0xf430210c
#define L2TM_L2TM_BM_INT1E_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 abr_flush_cos0E      :  1 ; /* bits 0:0 */
    u32 abr_flush_cos1E      :  1 ; /* bits 1:1 */
    u32 abr_flush_cos2E      :  1 ; /* bits 2:2 */
    u32 abr_flush_cos3E      :  1 ; /* bits 3:3 */
    u32 abr_flush_cos4E      :  1 ; /* bits 4:4 */
    u32 abr_flush_cos5E      :  1 ; /* bits 5:5 */
    u32 abr_flush_cos6E      :  1 ; /* bits 6:6 */
    u32 abr_flush_cos7E      :  1 ; /* bits 7:7 */
    u32 abr_drop_cos0E       :  1 ; /* bits 8:8 */
    u32 abr_drop_cos1E       :  1 ; /* bits 9:9 */
    u32 abr_drop_cos2E       :  1 ; /* bits 10:10 */
    u32 abr_drop_cos3E       :  1 ; /* bits 11:11 */
    u32 abr_drop_cos4E       :  1 ; /* bits 12:12 */
    u32 abr_drop_cos5E       :  1 ; /* bits 13:13 */
    u32 abr_drop_cos6E       :  1 ; /* bits 14:14 */
    u32 abr_drop_cos7E       :  1 ; /* bits 15:15 */
    u32 dq_abr_drop_cos0E    :  1 ; /* bits 16:16 */
    u32 dq_abr_drop_cos1E    :  1 ; /* bits 17:17 */
    u32 dq_abr_drop_cos2E    :  1 ; /* bits 18:18 */
    u32 dq_abr_drop_cos3E    :  1 ; /* bits 19:19 */
    u32 dq_abr_drop_cos4E    :  1 ; /* bits 20:20 */
    u32 dq_abr_drop_cos5E    :  1 ; /* bits 21:21 */
    u32 dq_abr_drop_cos6E    :  1 ; /* bits 22:22 */
    u32 dq_abr_drop_cos7E    :  1 ; /* bits 23:23 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_INT1E_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_CTRL                        0xf4302110
#define L2TM_L2TM_BM_CTRL_dft                    0xc0000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_drop_cos          :  3 ; /* bits 2:0 */
    u32 rx_drop_pid          :  4 ; /* bits 6:3 */
    u32 rx_drop_en           :  2 ; /* bits 8:7 */
    u32 sb_drop_dis          :  1 ; /* bits 9:9 */
    u32 hdr_drop_code_upd_en :  1 ; /* bits 10:10 */
    u32 rsrvd1               : 13 ;
    u32 min_pktlen           :  7 ; /* bits 30:24 */
    u32 rx_en                :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_TM_TO_9THQ_QUEUE_MAP        0xf4302114
#define L2TM_L2TM_BM_TM_TO_9THQ_QUEUE_MAP_dft    0x76543210

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qsel_0               :  3 ; /* bits 2:0 */
    u32 flag_0               :  1 ; /* bits 3:3 */
    u32 qsel_1               :  3 ; /* bits 6:4 */
    u32 flag_1               :  1 ; /* bits 7:7 */
    u32 qsel_2               :  3 ; /* bits 10:8 */
    u32 flag_2               :  1 ; /* bits 11:11 */
    u32 qsel_3               :  3 ; /* bits 14:12 */
    u32 flag_3               :  1 ; /* bits 15:15 */
    u32 qsel_4               :  3 ; /* bits 18:16 */
    u32 flag_4               :  1 ; /* bits 19:19 */
    u32 qsel_5               :  3 ; /* bits 22:20 */
    u32 flag_5               :  1 ; /* bits 23:23 */
    u32 qsel_6               :  3 ; /* bits 26:24 */
    u32 flag_6               :  1 ; /* bits 27:27 */
    u32 qsel_7               :  3 ; /* bits 30:28 */
    u32 flag_7               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_TM_TO_9THQ_QUEUE_MAP_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_TM_TO_CPUQ_QUEUE_MAP        0xf4302118
#define L2TM_L2TM_BM_TM_TO_CPUQ_QUEUE_MAP_dft    0x76543210

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qsel_0               :  3 ; /* bits 2:0 */
    u32 flag_0               :  1 ; /* bits 3:3 */
    u32 qsel_1               :  3 ; /* bits 6:4 */
    u32 flag_1               :  1 ; /* bits 7:7 */
    u32 qsel_2               :  3 ; /* bits 10:8 */
    u32 flag_2               :  1 ; /* bits 11:11 */
    u32 qsel_3               :  3 ; /* bits 14:12 */
    u32 flag_3               :  1 ; /* bits 15:15 */
    u32 qsel_4               :  3 ; /* bits 18:16 */
    u32 flag_4               :  1 ; /* bits 19:19 */
    u32 qsel_5               :  3 ; /* bits 22:20 */
    u32 flag_5               :  1 ; /* bits 23:23 */
    u32 qsel_6               :  3 ; /* bits 26:24 */
    u32 flag_6               :  1 ; /* bits 27:27 */
    u32 qsel_7               :  3 ; /* bits 30:28 */
    u32 flag_7               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_TM_TO_CPUQ_QUEUE_MAP_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_TM_TO_CPU256Q_QUEUE_MAP     0xf430211c
#define L2TM_L2TM_BM_TM_TO_CPU256Q_QUEUE_MAP_dft 0x00000076

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qsel_0               :  3 ; /* bits 2:0 */
    u32 flag_0               :  1 ; /* bits 3:3 */
    u32 qsel_1               :  3 ; /* bits 6:4 */
    u32 flag_1               :  1 ; /* bits 7:7 */
    u32 rxpfc_0              :  1 ; /* bits 8:8 */
    u32 rxpfc_1              :  1 ; /* bits 9:9 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_TM_TO_CPU256Q_QUEUE_MAP_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_TM_TO_DQ_QUEUE_MAP          0xf4302120
#define L2TM_L2TM_BM_TM_TO_DQ_QUEUE_MAP_dft      0x76543210

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qsel_0               :  3 ; /* bits 2:0 */
    u32 flag_0               :  1 ; /* bits 3:3 */
    u32 qsel_1               :  3 ; /* bits 6:4 */
    u32 flag_1               :  1 ; /* bits 7:7 */
    u32 qsel_2               :  3 ; /* bits 10:8 */
    u32 flag_2               :  1 ; /* bits 11:11 */
    u32 qsel_3               :  3 ; /* bits 14:12 */
    u32 flag_3               :  1 ; /* bits 15:15 */
    u32 qsel_4               :  3 ; /* bits 18:16 */
    u32 flag_4               :  1 ; /* bits 19:19 */
    u32 qsel_5               :  3 ; /* bits 22:20 */
    u32 flag_5               :  1 ; /* bits 23:23 */
    u32 qsel_6               :  3 ; /* bits 26:24 */
    u32 flag_6               :  1 ; /* bits 27:27 */
    u32 qsel_7               :  3 ; /* bits 30:28 */
    u32 flag_7               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_TM_TO_DQ_QUEUE_MAP_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_TM_TO_LANL3FE_QUEUE_MAP     0xf4302124
#define L2TM_L2TM_BM_TM_TO_LANL3FE_QUEUE_MAP_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  3 ;
    u32 flag_0               :  1 ; /* bits 3:3 */
    u32 rsrvd2               :  3 ;
    u32 flag_1               :  1 ; /* bits 7:7 */
    u32 rsrvd3               :  3 ;
    u32 flag_2               :  1 ; /* bits 11:11 */
    u32 rsrvd4               :  3 ;
    u32 flag_3               :  1 ; /* bits 15:15 */
    u32 rsrvd5               :  3 ;
    u32 flag_4               :  1 ; /* bits 19:19 */
    u32 rsrvd6               :  3 ;
    u32 flag_5               :  1 ; /* bits 23:23 */
    u32 rsrvd7               :  3 ;
    u32 flag_6               :  1 ; /* bits 27:27 */
    u32 rsrvd8               :  3 ;
    u32 flag_7               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_TM_TO_LANL3FE_QUEUE_MAP_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_DQ_TO_TM_QUEUE_MAP          0xf4302128
#define L2TM_L2TM_BM_DQ_TO_TM_QUEUE_MAP_dft      0x76543210

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qsel_0               :  3 ; /* bits 2:0 */
    u32 flag_0               :  1 ; /* bits 3:3 */
    u32 qsel_1               :  3 ; /* bits 6:4 */
    u32 flag_1               :  1 ; /* bits 7:7 */
    u32 qsel_2               :  3 ; /* bits 10:8 */
    u32 flag_2               :  1 ; /* bits 11:11 */
    u32 qsel_3               :  3 ; /* bits 14:12 */
    u32 flag_3               :  1 ; /* bits 15:15 */
    u32 qsel_4               :  3 ; /* bits 18:16 */
    u32 flag_4               :  1 ; /* bits 19:19 */
    u32 qsel_5               :  3 ; /* bits 22:20 */
    u32 flag_5               :  1 ; /* bits 23:23 */
    u32 qsel_6               :  3 ; /* bits 26:24 */
    u32 flag_6               :  1 ; /* bits 27:27 */
    u32 qsel_7               :  3 ; /* bits 30:28 */
    u32 flag_7               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_DQ_TO_TM_QUEUE_MAP_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_DQ_TO_TM_PORT_MAP           0xf430212c
#define L2TM_L2TM_BM_DQ_TO_TM_PORT_MAP_dft       0x76543210

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tm_dpid_sel_0        :  4 ; /* bits 3:0 */
    u32 tm_dpid_sel_1        :  4 ; /* bits 7:4 */
    u32 tm_dpid_sel_2        :  4 ; /* bits 11:8 */
    u32 tm_dpid_sel_3        :  4 ; /* bits 15:12 */
    u32 tm_dpid_sel_4        :  4 ; /* bits 19:16 */
    u32 tm_dpid_sel_5        :  4 ; /* bits 23:20 */
    u32 tm_dpid_sel_6        :  4 ; /* bits 27:24 */
    u32 tm_dpid_sel_7        :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_DQ_TO_TM_PORT_MAP_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_RX_DQ_PCNT                  0xf4302130
#define L2TM_L2TM_BM_RX_DQ_PCNT_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_RX_DQ_PCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_RX_DQ_DPCNT                 0xf4302134
#define L2TM_L2TM_BM_RX_DQ_DPCNT_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_RX_DQ_DPCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_RX_DQ_ABR_DPCNT             0xf4302138
#define L2TM_L2TM_BM_RX_DQ_ABR_DPCNT_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_RX_DQ_ABR_DPCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_RX_PCNT                     0xf430213c
#define L2TM_L2TM_BM_RX_PCNT_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_RX_PCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_TX_PCNT                     0xf4302140
#define L2TM_L2TM_BM_TX_PCNT_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_TX_PCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_SB_DPCNT                    0xf4302144
#define L2TM_L2TM_BM_SB_DPCNT_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_SB_DPCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_HDR_DPCNT                   0xf4302148
#define L2TM_L2TM_BM_HDR_DPCNT_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_HDR_DPCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_TE_DPCNT                    0xf430214c
#define L2TM_L2TM_BM_TE_DPCNT_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_TE_DPCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_ERR_DPCNT                   0xf4302150
#define L2TM_L2TM_BM_ERR_DPCNT_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_ERR_DPCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_FC_MIRROR0_DPCNT            0xf4302154
#define L2TM_L2TM_BM_FC_MIRROR0_DPCNT_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_FC_MIRROR0_DPCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_FC_MIRROR1_DPCNT            0xf4302158
#define L2TM_L2TM_BM_FC_MIRROR1_DPCNT_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_FC_MIRROR1_DPCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_FC_MIRROR2_DPCNT            0xf430215c
#define L2TM_L2TM_BM_FC_MIRROR2_DPCNT_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_FC_MIRROR2_DPCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_FC_MIRROR3_DPCNT            0xf4302160
#define L2TM_L2TM_BM_FC_MIRROR3_DPCNT_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_FC_MIRROR3_DPCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_RX_DPCNT                    0xf4302164
#define L2TM_L2TM_BM_RX_DPCNT_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_RX_DPCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_RX_ABR_DPCNT                0xf4302168
#define L2TM_L2TM_BM_RX_ABR_DPCNT_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_RX_ABR_DPCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_NOBUF_DPCNT                 0xf430216c
#define L2TM_L2TM_BM_NOBUF_DPCNT_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_NOBUF_DPCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_RX_FE_HEADER_31_0           0xf4302170
#define L2TM_L2TM_BM_RX_FE_HEADER_31_0_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 header               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_RX_FE_HEADER_31_0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_RX_FE_HEADER_63_32          0xf4302174
#define L2TM_L2TM_BM_RX_FE_HEADER_63_32_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 header               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_RX_FE_HEADER_63_32_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_RX_NI_HEADER_31_0           0xf4302178
#define L2TM_L2TM_BM_RX_NI_HEADER_31_0_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 header               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_RX_NI_HEADER_31_0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_RX_NI_HEADER_63_32          0xf430217c
#define L2TM_L2TM_BM_RX_NI_HEADER_63_32_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 header               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_RX_NI_HEADER_63_32_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_TX_NI_HEADER_31_0           0xf4302180
#define L2TM_L2TM_BM_TX_NI_HEADER_31_0_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 header               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_TX_NI_HEADER_31_0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_TX_NI_HEADER_63_32          0xf4302184
#define L2TM_L2TM_BM_TX_NI_HEADER_63_32_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 header               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_TX_NI_HEADER_63_32_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_STS                         0xf4302188
#define L2TM_L2TM_BM_STS_dft                     0xff80000a

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 fe_tm_vld            :  1 ; /* bits 0:0 */
    u32 tm_fe_rdy            :  1 ; /* bits 1:1 */
    u32 ni_tm_vld            :  1 ; /* bits 2:2 */
    u32 tm_ni_rdy            :  1 ; /* bits 3:3 */
    u32 tm_ni_vld            :  1 ; /* bits 4:4 */
    u32 rsrvd1               : 18 ;
    u32 dq_ff_empty          :  1 ; /* bits 23:23 */
    u32 dq_pack_ff_empty     :  1 ; /* bits 24:24 */
    u32 fe_ff_empty          :  1 ; /* bits 25:25 */
    u32 pack_ff_empty        :  1 ; /* bits 26:26 */
    u32 wdat_ff_empty        :  1 ; /* bits 27:27 */
    u32 wcmd_ff_empty        :  1 ; /* bits 28:28 */
    u32 rdat_ff_empty        :  1 ; /* bits 29:29 */
    u32 rcmd_ff_empty        :  1 ; /* bits 30:30 */
    u32 rcyc_ff_empty        :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_PKT_MEM_ACCESS              0xf430218c
#define L2TM_L2TM_BM_PKT_MEM_ACCESS_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              : 15 ; /* bits 14:0 */
    u32 rsrvd1               : 15 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_PKT_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_PKT_MEM_DATA7               0xf4302190
#define L2TM_L2TM_BM_PKT_MEM_DATA7_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_PKT_MEM_DATA7_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_PKT_MEM_DATA6               0xf4302194
#define L2TM_L2TM_BM_PKT_MEM_DATA6_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_PKT_MEM_DATA6_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_PKT_MEM_DATA5               0xf4302198
#define L2TM_L2TM_BM_PKT_MEM_DATA5_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_PKT_MEM_DATA5_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_PKT_MEM_DATA4               0xf430219c
#define L2TM_L2TM_BM_PKT_MEM_DATA4_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_PKT_MEM_DATA4_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_PKT_MEM_DATA3               0xf43021a0
#define L2TM_L2TM_BM_PKT_MEM_DATA3_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_PKT_MEM_DATA3_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_PKT_MEM_DATA2               0xf43021a4
#define L2TM_L2TM_BM_PKT_MEM_DATA2_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_PKT_MEM_DATA2_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_PKT_MEM_DATA1               0xf43021a8
#define L2TM_L2TM_BM_PKT_MEM_DATA1_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_PKT_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_PKT_MEM_DATA0               0xf43021ac
#define L2TM_L2TM_BM_PKT_MEM_DATA0_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_PKT_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_OD_DBG0                     0xf43021b0
#define L2TM_L2TM_BM_OD_DBG0_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 od_dbg0              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_OD_DBG0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_BM_OD_DBG1                     0xf43021b4
#define L2TM_L2TM_BM_OD_DBG1_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 od_dbg1              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_BM_OD_DBG1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_INT                         0xf4302200
#define L2TM_L2TM_QM_INT_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 freeq_ecc_correctederr :  1 ; /* bits 0:0 */
    u32 freeq_ecc_err        :  1 ; /* bits 1:1 */
    u32 voqinfo_cnt_dec_with_novalid :  1 ; /* bits 2:2 */
    u32 rsrvd1               :  1 ;
    u32 nobuf_drop           :  1 ; /* bits 4:4 */
    u32 bid_out_of_range     :  1 ; /* bits 5:5 */
    u32 wr_race_err          :  1 ; /* bits 6:6 */
    u32 rsrvd2               :  9 ;
    u32 eq0_stack_err        :  1 ; /* bits 16:16 */
    u32 eq1_stack_err        :  1 ; /* bits 17:17 */
    u32 enq_ff_undrflo       :  1 ; /* bits 18:18 */
    u32 enq_ff_ovrflo        :  1 ; /* bits 19:19 */
    u32 deq_ff_undrflo       :  1 ; /* bits 20:20 */
    u32 deq_ff_ovrflo        :  1 ; /* bits 21:21 */
    u32 rsrvd3               : 10 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_INT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_INTE                        0xf4302204
#define L2TM_L2TM_QM_INTE_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 freeq_ecc_correctederrE :  1 ; /* bits 0:0 */
    u32 freeq_ecc_errE       :  1 ; /* bits 1:1 */
    u32 voqinfo_cnt_dec_with_novalidE :  1 ; /* bits 2:2 */
    u32 rsrvd1               :  1 ;
    u32 nobuf_dropE          :  1 ; /* bits 4:4 */
    u32 bid_out_of_rangeE    :  1 ; /* bits 5:5 */
    u32 wr_race_errE         :  1 ; /* bits 6:6 */
    u32 rsrvd2               :  9 ;
    u32 eq0_stack_errE       :  1 ; /* bits 16:16 */
    u32 eq1_stack_errE       :  1 ; /* bits 17:17 */
    u32 enq_ff_undrfloE      :  1 ; /* bits 18:18 */
    u32 enq_ff_ovrfloE       :  1 ; /* bits 19:19 */
    u32 deq_ff_undrfloE      :  1 ; /* bits 20:20 */
    u32 deq_ff_ovrfloE       :  1 ; /* bits 21:21 */
    u32 rsrvd3               : 10 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_INTE_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_EQ_CFG                      0xf4302208
#define L2TM_L2TM_QM_EQ_CFG_dft                  0x00040008

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 eq0_bufnum           :  5 ; /* bits 4:0 */
    u32 eq0_prvt             : 11 ; /* bits 15:5 */
    u32 eq1_bufnum           :  4 ; /* bits 19:16 */
    u32 eq1_prvt             : 10 ; /* bits 29:20 */
    u32 eq0_en               :  1 ; /* bits 30:30 */
    u32 eq1_en               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_EQ_CFG_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_EQ_CFG1                     0xf430220c
#define L2TM_L2TM_QM_EQ_CFG1_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 eq0_buffer_weight    :  1 ; /* bits 0:0 */
    u32 eq1_buffer_weight    :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_EQ_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_GLOB_BUF_CFG                0xf4302210
#define L2TM_L2TM_QM_GLOB_BUF_CFG_dft            0x90000020

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 nodrop               : 15 ; /* bits 14:0 */
    u32 drop_en              :  1 ; /* bits 15:15 */
    u32 noncong              : 15 ; /* bits 30:16 */
    u32 fe_bp_en             :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_GLOB_BUF_CFG_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_GLOB_BUF_CFG1               0xf4302214
#define L2TM_L2TM_QM_GLOB_BUF_CFG1_dft           0x00000010

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 fe_bp_th             : 15 ; /* bits 14:0 */
    u32 rsrvd1               : 17 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_GLOB_BUF_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_PORT_PRVT_PROFILE0          0xf4302218
#define L2TM_L2TM_QM_PORT_PRVT_PROFILE0_dft      0x00100000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt_even             : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 cnt_odd              : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_PORT_PRVT_PROFILE0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_PORT_PRVT_PROFILE1          0xf430221c
#define L2TM_L2TM_QM_PORT_PRVT_PROFILE1_dft      0x00400020

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt_even             : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 cnt_odd              : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_PORT_PRVT_PROFILE1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_PORT_PRVT_PROFILE2          0xf4302220
#define L2TM_L2TM_QM_PORT_PRVT_PROFILE2_dft      0x00c00080

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt_even             : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 cnt_odd              : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_PORT_PRVT_PROFILE2_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_PORT_PRVT_PROFILE3          0xf4302224
#define L2TM_L2TM_QM_PORT_PRVT_PROFILE3_dft      0x01400100

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt_even             : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 cnt_odd              : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_PORT_PRVT_PROFILE3_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_PORT_PRVT_SELECT0           0xf4302228
#define L2TM_L2TM_QM_PORT_PRVT_SELECT0_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port0                :  3 ; /* bits 2:0 */
    u32 rsrvd1               :  1 ;
    u32 port1                :  3 ; /* bits 6:4 */
    u32 rsrvd2               :  1 ;
    u32 port2                :  3 ; /* bits 10:8 */
    u32 rsrvd3               :  1 ;
    u32 port3                :  3 ; /* bits 14:12 */
    u32 rsrvd4               :  1 ;
    u32 port4                :  3 ; /* bits 18:16 */
    u32 rsrvd5               :  1 ;
    u32 port5                :  3 ; /* bits 22:20 */
    u32 rsrvd6               :  1 ;
    u32 port6                :  3 ; /* bits 26:24 */
    u32 rsrvd7               :  1 ;
    u32 port7                :  3 ; /* bits 30:28 */
    u32 rsrvd8               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_PORT_PRVT_SELECT0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_PORT_PRVT_SELECT1           0xf430222c
#define L2TM_L2TM_QM_PORT_PRVT_SELECT1_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port0                :  3 ; /* bits 2:0 */
    u32 rsrvd1               :  1 ;
    u32 port1                :  3 ; /* bits 6:4 */
    u32 rsrvd2               :  1 ;
    u32 port2                :  3 ; /* bits 10:8 */
    u32 rsrvd3               :  1 ;
    u32 port3                :  3 ; /* bits 14:12 */
    u32 rsrvd4               :  1 ;
    u32 port4                :  3 ; /* bits 18:16 */
    u32 rsrvd5               :  1 ;
    u32 port5                :  3 ; /* bits 22:20 */
    u32 rsrvd6               :  1 ;
    u32 port6                :  3 ; /* bits 26:24 */
    u32 rsrvd7               :  1 ;
    u32 port7                :  3 ; /* bits 30:28 */
    u32 rsrvd8               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_PORT_PRVT_SELECT1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_PORT_NO_PRVT_STS            0xf4302230
#define L2TM_L2TM_QM_PORT_NO_PRVT_STS_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pid                  : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_PORT_NO_PRVT_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_EQ_GLB_FREECNT              0xf4302234
#define L2TM_L2TM_QM_EQ_GLB_FREECNT_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sum_of_eqcnt         : 15 ; /* bits 14:0 */
    u32 rsrvd1               : 17 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_EQ_GLB_FREECNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_EQ_COS0_BUFCNT              0xf4302238
#define L2TM_L2TM_QM_EQ_COS0_BUFCNT_STRIDE       4
#define L2TM_L2TM_QM_EQ_COS0_BUFCNT_COUNT        8
#define L2TM_L2TM_QM_EQ_COS0_BUFCNT_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sum_of_eqcnt         : 15 ; /* bits 14:0 */
    u32 rsrvd1               : 17 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_EQ_COS0_BUFCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_PORT_PRVT_BUFCNT_MEM_ACCESS 0xf4302258
#define L2TM_L2TM_QM_PORT_PRVT_BUFCNT_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 26 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_PORT_PRVT_BUFCNT_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_PORT_PRVT_BUFCNT_MEM_DATA   0xf430225c
#define L2TM_L2TM_QM_PORT_PRVT_BUFCNT_MEM_DATA_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt0                 : 15 ; /* bits 14:0 */
    u32 rsrvd1               : 17 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_PORT_PRVT_BUFCNT_MEM_DATA_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_EQ_FREECNT                  0xf4302260
#define L2TM_L2TM_QM_EQ_FREECNT_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 eq0                  : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 eq1                  : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_EQ_FREECNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_EQ_HEAD                     0xf4302264
#define L2TM_L2TM_QM_EQ_HEAD_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 eq0                  : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 eq1                  : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_EQ_HEAD_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_EQ0_STACK_CFG               0xf4302268
#define L2TM_L2TM_QM_EQ0_STACK_CFG_dft           0x00302010

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 low_ths              :  6 ; /* bits 5:0 */
    u32 rsrvd1               :  2 ;
    u32 mid_ths              :  6 ; /* bits 13:8 */
    u32 rsrvd2               :  2 ;
    u32 high_ths             :  6 ; /* bits 21:16 */
    u32 rsrvd3               : 10 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_EQ0_STACK_CFG_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_EQ0_STACK_CTRL              0xf430226c
#define L2TM_L2TM_QM_EQ0_STACK_CTRL_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 stack_unfill         :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_EQ0_STACK_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_EQ0_STACK_STS               0xf4302270
#define L2TM_L2TM_QM_EQ0_STACK_STS_dft           0x00000007

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 stack_unfill_done    :  1 ; /* bits 0:0 */
    u32 stack_idle           :  1 ; /* bits 1:1 */
    u32 stack_empty          :  1 ; /* bits 2:2 */
    u32 stack_full           :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 12 ;
    u32 stack_cntr           :  6 ; /* bits 21:16 */
    u32 rsrvd2               : 10 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_EQ0_STACK_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_EQ1_STACK_CFG               0xf4302274
#define L2TM_L2TM_QM_EQ1_STACK_CFG_dft           0x00302010

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 low_ths              :  6 ; /* bits 5:0 */
    u32 rsrvd1               :  2 ;
    u32 mid_ths              :  6 ; /* bits 13:8 */
    u32 rsrvd2               :  2 ;
    u32 high_ths             :  6 ; /* bits 21:16 */
    u32 rsrvd3               : 10 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_EQ1_STACK_CFG_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_EQ1_STACK_CTRL              0xf4302278
#define L2TM_L2TM_QM_EQ1_STACK_CTRL_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 stack_unfill         :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_EQ1_STACK_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_EQ1_STACK_STS               0xf430227c
#define L2TM_L2TM_QM_EQ1_STACK_STS_dft           0x00000007

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 stack_unfill_done    :  1 ; /* bits 0:0 */
    u32 stack_idle           :  1 ; /* bits 1:1 */
    u32 stack_empty          :  1 ; /* bits 2:2 */
    u32 stack_full           :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 12 ;
    u32 stack_cntr           :  6 ; /* bits 21:16 */
    u32 rsrvd2               : 10 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_EQ1_STACK_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_CTRL                        0xf4302280
#define L2TM_L2TM_QM_CTRL_dft                    0x0000000a

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pcnt_dec_with_novalid_allow :  1 ; /* bits 0:0 */
    u32 ack_upd_at_same_time :  1 ; /* bits 1:1 */
    u32 l3fe_dpid_delay      :  1 ; /* bits 2:2 */
    u32 same_dpid_delay      :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 27 ;
    u32 force_init_done      :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_STS                         0xf4302284
#define L2TM_L2TM_QM_STS_dft                     0x000c0000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 plm_nempty           : 16 ; /* bits 15:0 */
    u32 rsrvd1               :  2 ;
    u32 enq_ff_empty         :  1 ; /* bits 18:18 */
    u32 deq_ff_empty         :  1 ; /* bits 19:19 */
    u32 rsrvd2               : 12 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_STS1                        0xf4302288
#define L2TM_L2TM_QM_STS1_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 init_adr             : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 init_data            :  8 ; /* bits 23:16 */
    u32 freeq_cs             :  3 ; /* bits 26:24 */
    u32 rsrvd2               :  3 ;
    u32 sm_reset             :  1 ; /* bits 30:30 */
    u32 init_done            :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_STS1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_FREEQ_MEM_ACCESS            0xf430228c
#define L2TM_L2TM_QM_FREEQ_MEM_ACCESS_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              : 15 ; /* bits 14:0 */
    u32 rsrvd1               : 15 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_FREEQ_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_FREEQ_MEM_DATA1             0xf4302290
#define L2TM_L2TM_QM_FREEQ_MEM_DATA1_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ecc                  :  2 ; /* bits 1:0 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_FREEQ_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_FREEQ_MEM_DATA0             0xf4302294
#define L2TM_L2TM_QM_FREEQ_MEM_DATA0_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 blen                 :  7 ; /* bits 6:0 */
    u32 eqid                 :  1 ; /* bits 7:7 */
    u32 eop                  :  1 ; /* bits 8:8 */
    u32 sop                  :  1 ; /* bits 9:9 */
    u32 cpu                  :  1 ; /* bits 10:10 */
    u32 prvt                 :  1 ; /* bits 11:11 */
    u32 nxt_ptr              : 15 ; /* bits 26:12 */
    u32 ecc                  :  5 ; /* bits 31:27 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_FREEQ_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_VOQINFO_MEM_ACCESS          0xf4302298
#define L2TM_L2TM_QM_VOQINFO_MEM_ACCESS_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  7 ; /* bits 6:0 */
    u32 rsrvd1               : 23 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_VOQINFO_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_VOQINFO_MEM_DATA1           0xf430229c
#define L2TM_L2TM_QM_VOQINFO_MEM_DATA1_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tail_ptr             : 10 ; /* bits 9:0 */
    u32 vallid               :  1 ; /* bits 10:10 */
    u32 rsrvd1               : 21 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_VOQINFO_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_VOQINFO_MEM_DATA0           0xf43022a0
#define L2TM_L2TM_QM_VOQINFO_MEM_DATA0_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 blen                 :  7 ; /* bits 6:0 */
    u32 eqid                 :  1 ; /* bits 7:7 */
    u32 eop                  :  1 ; /* bits 8:8 */
    u32 sop                  :  1 ; /* bits 9:9 */
    u32 cpu                  :  1 ; /* bits 10:10 */
    u32 prvt                 :  1 ; /* bits 11:11 */
    u32 head_ptr             : 15 ; /* bits 26:12 */
    u32 tail_ptr             :  5 ; /* bits 31:27 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_VOQINFO_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_VOQ_PCNT_MEM_ACCESS         0xf43022a4
#define L2TM_L2TM_QM_VOQ_PCNT_MEM_ACCESS_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  7 ; /* bits 6:0 */
    u32 rsrvd1               : 23 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_VOQ_PCNT_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_QM_VOQ_PCNT_MEM_DATA           0xf43022a8
#define L2TM_L2TM_QM_VOQ_PCNT_MEM_DATA_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt0                 : 14 ; /* bits 13:0 */
    u32 rsrvd1               : 18 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_QM_VOQ_PCNT_MEM_DATA_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_CTRL                        0xf4302300
#define L2TM_L2TM_ES_CTRL_dft                    0x24000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_port0_en          :  1 ; /* bits 0:0 */
    u32 tx_port1_en          :  1 ; /* bits 1:1 */
    u32 tx_port2_en          :  1 ; /* bits 2:2 */
    u32 tx_port3_en          :  1 ; /* bits 3:3 */
    u32 tx_port4_en          :  1 ; /* bits 4:4 */
    u32 tx_port5_en          :  1 ; /* bits 5:5 */
    u32 tx_port6_en          :  1 ; /* bits 6:6 */
    u32 tx_port7_en          :  1 ; /* bits 7:7 */
    u32 tx_port8_en          :  1 ; /* bits 8:8 */
    u32 tx_port9_en          :  1 ; /* bits 9:9 */
    u32 tx_port10_en         :  1 ; /* bits 10:10 */
    u32 tx_port11_en         :  1 ; /* bits 11:11 */
    u32 tx_port12_en         :  1 ; /* bits 12:12 */
    u32 tx_port13_en         :  1 ; /* bits 13:13 */
    u32 rsrvd1               :  1 ;
    u32 tx_port15_en         :  1 ; /* bits 15:15 */
    u32 rsrvd2               : 10 ;
    u32 ni_port_rdy_10_deglitch :  1 ; /* bits 26:26 */
    u32 rsrvd3               :  2 ;
    u32 ni_port_rdy_13_deglitch :  1 ; /* bits 29:29 */
    u32 rsrvd4               :  1 ;
    u32 tx_en                :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_SCH_CFG0                    0xf4302304
#define L2TM_L2TM_ES_SCH_CFG0_STRIDE             12
#define L2TM_L2TM_ES_SCH_CFG0_COUNT              15
#define L2TM_L2TM_ES_SCH_CFG0_dft                0x000000ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 voq_en               :  8 ; /* bits 7:0 */
    u32 flush_voqid          :  3 ; /* bits 10:8 */
    u32 rsrvd1               :  4 ;
    u32 flush_en             :  1 ; /* bits 15:15 */
    u32 speed                :  8 ; /* bits 23:16 */
    u32 rsrvd2               :  8 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_SCH_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_VOQ3_0_WEIGHT_RATIO_CFG0    0xf4302308
#define L2TM_L2TM_ES_VOQ3_0_WEIGHT_RATIO_CFG0_STRIDE 12
#define L2TM_L2TM_ES_VOQ3_0_WEIGHT_RATIO_CFG0_COUNT 15
#define L2TM_L2TM_ES_VOQ3_0_WEIGHT_RATIO_CFG0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 voq0                 :  8 ; /* bits 7:0 */
    u32 voq1                 :  8 ; /* bits 15:8 */
    u32 voq2                 :  8 ; /* bits 23:16 */
    u32 voq3                 :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_VOQ3_0_WEIGHT_RATIO_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_VOQ7_4_WEIGHT_RATIO_CFG0    0xf430230c
#define L2TM_L2TM_ES_VOQ7_4_WEIGHT_RATIO_CFG0_STRIDE 12
#define L2TM_L2TM_ES_VOQ7_4_WEIGHT_RATIO_CFG0_COUNT 15
#define L2TM_L2TM_ES_VOQ7_4_WEIGHT_RATIO_CFG0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 voq4                 :  8 ; /* bits 7:0 */
    u32 voq5                 :  8 ; /* bits 15:8 */
    u32 voq6                 :  8 ; /* bits 23:16 */
    u32 voq7                 :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_VOQ7_4_WEIGHT_RATIO_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_PORT3_0_WEIGHT_RATIO_CFG    0xf43023b8
#define L2TM_L2TM_ES_PORT3_0_WEIGHT_RATIO_CFG_dft 0x01010101

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port0                :  8 ; /* bits 7:0 */
    u32 port1                :  8 ; /* bits 15:8 */
    u32 port2                :  8 ; /* bits 23:16 */
    u32 port3                :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_PORT3_0_WEIGHT_RATIO_CFG_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_PORT7_4_WEIGHT_RATIO_CFG    0xf43023bc
#define L2TM_L2TM_ES_PORT7_4_WEIGHT_RATIO_CFG_dft 0x01010101

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port4                :  8 ; /* bits 7:0 */
    u32 port5                :  8 ; /* bits 15:8 */
    u32 port6                :  8 ; /* bits 23:16 */
    u32 port7                :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_PORT7_4_WEIGHT_RATIO_CFG_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_PORT11_8_WEIGHT_RATIO_CFG   0xf43023c0
#define L2TM_L2TM_ES_PORT11_8_WEIGHT_RATIO_CFG_dft 0x01010101

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port8                :  8 ; /* bits 7:0 */
    u32 port9                :  8 ; /* bits 15:8 */
    u32 port10               :  8 ; /* bits 23:16 */
    u32 port11               :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_PORT11_8_WEIGHT_RATIO_CFG_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_PORT15_12_WEIGHT_RATIO_CFG  0xf43023c4
#define L2TM_L2TM_ES_PORT15_12_WEIGHT_RATIO_CFG_dft 0x01000101

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port12               :  8 ; /* bits 7:0 */
    u32 port13               :  8 ; /* bits 15:8 */
    u32 rsrvd1               :  8 ;
    u32 port15               :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_PORT15_12_WEIGHT_RATIO_CFG_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_DRR_WEIGHT_BASE             0xf43023c8
#define L2TM_L2TM_ES_DRR_WEIGHT_BASE_dft         0x00000014

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 w_rate               :  5 ; /* bits 4:0 */
    u32 rsrvd1               :  3 ;
    u32 base_select          :  3 ; /* bits 10:8 */
    u32 rsrvd2               :  5 ;
    u32 dwrr_unit            :  1 ; /* bits 16:16 */
    u32 rsrvd3               : 15 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_DRR_WEIGHT_BASE_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_CFG                         0xf43023cc
#define L2TM_L2TM_ES_CFG_dft                     0x00000740

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sch_ack_len          :  8 ; /* bits 7:0 */
    u32 sch_sync_upd         :  1 ; /* bits 8:8 */
    u32 sch_rr_grant         :  1 ; /* bits 9:9 */
    u32 sch_ack_solo         :  1 ; /* bits 10:10 */
    u32 rsrvd1               : 21 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_CFG_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_STS                         0xf43023d0
#define L2TM_L2TM_ES_STS_dft                     0x00003fff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni_port_rdy          : 14 ; /* bits 13:0 */
    u32 rsrvd1               : 18 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_VOQ_STS0                    0xf43023d4
#define L2TM_L2TM_ES_VOQ_STS0_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qid                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_VOQ_STS0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_VOQ_STS1                    0xf43023d8
#define L2TM_L2TM_ES_VOQ_STS1_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qid                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_VOQ_STS1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_VOQ_STS2                    0xf43023dc
#define L2TM_L2TM_ES_VOQ_STS2_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qid                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_VOQ_STS2_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_VOQ_STS3                    0xf43023e0
#define L2TM_L2TM_ES_VOQ_STS3_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qid                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_VOQ_STS3_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_VOQ_OK_STS0                 0xf43023e4
#define L2TM_L2TM_ES_VOQ_OK_STS0_dft             0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qid                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_VOQ_OK_STS0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_VOQ_OK_STS1                 0xf43023e8
#define L2TM_L2TM_ES_VOQ_OK_STS1_dft             0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qid                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_VOQ_OK_STS1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_VOQ_OK_STS2                 0xf43023ec
#define L2TM_L2TM_ES_VOQ_OK_STS2_dft             0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qid                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_VOQ_OK_STS2_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_VOQ_OK_STS3                 0xf43023f0
#define L2TM_L2TM_ES_VOQ_OK_STS3_dft             0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qid                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_VOQ_OK_STS3_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_PORT_OK_STS                 0xf43023f4
#define L2TM_L2TM_ES_PORT_OK_STS_dft             0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pid                  : 16 ; /* bits 15:0 */
    u32 voq_grp              : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_PORT_OK_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_ABR_STS                     0xf43023f8
#define L2TM_L2TM_ES_ABR_STS_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port7_voq_abr_drop_sts :  8 ; /* bits 7:0 */
    u32 port7_abr_ovthrsh    :  1 ; /* bits 8:8 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_ABR_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TM_ES_ABR_FLUSH_PCNT              0xf43023fc
#define L2TM_L2TM_ES_ABR_FLUSH_PCNT_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TM_ES_ABR_FLUSH_PCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_GLB_REV_ID                     0xf4302400
#define L2TM_L2TE_GLB_REV_ID_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 minor                : 16 ; /* bits 15:0 */
    u32 major                : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_GLB_REV_ID_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_GLB_CTRL                       0xf4302404
#define L2TM_L2TE_GLB_CTRL_dft                   0x07000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pol_en               :  1 ; /* bits 0:0 */
    u32 shp_en               :  1 ; /* bits 1:1 */
    u32 taildrop_en          :  1 ; /* bits 2:2 */
    u32 wred_en              :  1 ; /* bits 3:3 */
    u32 mark_ecn_en          :  1 ; /* bits 4:4 */
    u32 pol_ecn_en           :  1 ; /* bits 5:5 */
    u32 wred_ecn_en          :  1 ; /* bits 6:6 */
    u32 rsrvd1               :  7 ;
    u32 port8_empty_sel      :  1 ; /* bits 14:14 */
    u32 snoop_l3_voq_taildrop_dis :  1 ; /* bits 15:15 */
    u32 glb_deepq_port_rdy_en :  8 ; /* bits 23:16 */
    u32 glb_deepq_port_rdy_id :  3 ; /* bits 26:24 */
    u32 rsrvd2               :  2 ;
    u32 puc_tqm_voqbp_7_0_dis :  1 ; /* bits 29:29 */
    u32 rsrvd3               :  1 ;
    u32 force_init_done      :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_GLB_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_GLB_INT                        0xf4302408
#define L2TM_L2TE_GLB_INT_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pol_mark             :  1 ; /* bits 0:0 */
    u32 pol_drop             :  1 ; /* bits 1:1 */
    u32 tail_drop            :  1 ; /* bits 2:2 */
    u32 wred_y_drop          :  1 ; /* bits 3:3 */
    u32 wred_g_drop          :  1 ; /* bits 4:4 */
    u32 ecn                  :  1 ; /* bits 5:5 */
    u32 rsrvd1               :  8 ;
    u32 feio                 :  1 ; /* bits 14:14 */
    u32 tmio                 :  1 ; /* bits 15:15 */
    u32 cb                   :  1 ; /* bits 16:16 */
    u32 fc                   :  1 ; /* bits 17:17 */
    u32 rsrvd2               : 14 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_GLB_INT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_GLB_INTE                       0xf430240c
#define L2TM_L2TE_GLB_INTE_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pol_markE            :  1 ; /* bits 0:0 */
    u32 pol_dropE            :  1 ; /* bits 1:1 */
    u32 tail_dropE           :  1 ; /* bits 2:2 */
    u32 wred_y_dropE         :  1 ; /* bits 3:3 */
    u32 wred_g_dropE         :  1 ; /* bits 4:4 */
    u32 ecnE                 :  1 ; /* bits 5:5 */
    u32 rsrvd1               :  8 ;
    u32 feioE                :  1 ; /* bits 14:14 */
    u32 tmioE                :  1 ; /* bits 15:15 */
    u32 cbE                  :  1 ; /* bits 16:16 */
    u32 fcE                  :  1 ; /* bits 17:17 */
    u32 rsrvd2               : 14 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_GLB_INTE_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_GLB_STS                        0xf4302410
#define L2TM_L2TE_GLB_STS_dft                    0x07000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pol_fifo_ovrn        :  1 ; /* bits 0:0 */
    u32 l2io_fifo_ovrn       :  1 ; /* bits 1:1 */
    u32 qmio_enq_ovrn        :  1 ; /* bits 2:2 */
    u32 qmio_deq_ovrn        :  1 ; /* bits 3:3 */
    u32 qmio_shp_ovrn        :  1 ; /* bits 4:4 */
    u32 te_qm_nrdy           :  1 ; /* bits 5:5 */
    u32 ptp_fifo_err         :  1 ; /* bits 6:6 */
    u32 rsrvd1               :  5 ;
    u32 pol_init_done        :  1 ; /* bits 12:12 */
    u32 shp_init_done        :  1 ; /* bits 13:13 */
    u32 cb_init_done         :  1 ; /* bits 14:14 */
    u32 wred_init_done       :  1 ; /* bits 15:15 */
    u32 feio_sm              :  4 ; /* bits 19:16 */
    u32 fe_te_req            :  1 ; /* bits 20:20 */
    u32 te_fe_ack            :  1 ; /* bits 21:21 */
    u32 rsrvd2               :  2 ;
    u32 l2io_idle            :  1 ; /* bits 24:24 */
    u32 qmio_idle            :  1 ; /* bits 25:25 */
    u32 ptp_fifo_idle        :  1 ; /* bits 26:26 */
    u32 rsrvd3               :  4 ;
    u32 init_done            :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_GLB_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_GLB_PTP_CFG                    0xf4302414
#define L2TM_L2TE_GLB_PTP_CFG_dft                0x000007ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pol_id               :  8 ; /* bits 7:0 */
    u32 pol_grp_id           :  3 ; /* bits 10:8 */
    u32 rsrvd1               :  1 ;
    u32 pol_en               :  1 ; /* bits 12:12 */
    u32 pol_grp_en           :  1 ; /* bits 13:13 */
    u32 rsrvd2               : 18 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_GLB_PTP_CFG_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_GLB_SPARE_CFG                  0xf4302418
#define L2TM_L2TE_GLB_SPARE_CFG_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 spare                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_GLB_SPARE_CFG_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_GLB_SPARE_STS                  0xf430241c
#define L2TM_L2TE_GLB_SPARE_STS_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 spare                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_GLB_SPARE_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_GLB_SRAM_TEST_CONTROL_0        0xf4302420
#define L2TM_L2TE_GLB_SRAM_TEST_CONTROL_0_dft    0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 test_cfg0            :  8 ; /* bits 7:0 */
    u32 test_cfg1            :  8 ; /* bits 15:8 */
    u32 test_cfg2            :  8 ; /* bits 23:16 */
    u32 test_cfg3            :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_GLB_SRAM_TEST_CONTROL_0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_GLB_SRAM_TEST_CONTROL_1        0xf4302424
#define L2TM_L2TE_GLB_SRAM_TEST_CONTROL_1_dft    0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 test_cfg0            :  8 ; /* bits 7:0 */
    u32 test_cfg1            :  8 ; /* bits 15:8 */
    u32 test_cfg2            :  8 ; /* bits 23:16 */
    u32 test_cfg3            :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_GLB_SRAM_TEST_CONTROL_1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_GLB_SRAM_TEST_CONTROL_2        0xf4302428
#define L2TM_L2TE_GLB_SRAM_TEST_CONTROL_2_dft    0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 test_cfg0            :  8 ; /* bits 7:0 */
    u32 test_cfg1            :  8 ; /* bits 15:8 */
    u32 test_cfg2            :  8 ; /* bits 23:16 */
    u32 test_cfg3            :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_GLB_SRAM_TEST_CONTROL_2_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_GLB_SRAM_TEST_CONTROL_3        0xf430242c
#define L2TM_L2TE_GLB_SRAM_TEST_CONTROL_3_dft    0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 test_cfg0            :  8 ; /* bits 7:0 */
    u32 test_cfg1            :  8 ; /* bits 15:8 */
    u32 test_cfg2            :  8 ; /* bits 23:16 */
    u32 test_cfg3            :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_GLB_SRAM_TEST_CONTROL_3_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_GLB_SRAM_TEST_CONTROL_4        0xf4302430
#define L2TM_L2TE_GLB_SRAM_TEST_CONTROL_4_dft    0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 test_cfg0            :  8 ; /* bits 7:0 */
    u32 test_cfg1            :  8 ; /* bits 15:8 */
    u32 test_cfg2            :  8 ; /* bits 23:16 */
    u32 test_cfg3            :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_GLB_SRAM_TEST_CONTROL_4_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PKT_TYPE_CTRL0             0xf4302500
#define L2TM_L2TE_POL_PKT_TYPE_CTRL0_STRIDE      4
#define L2TM_L2TE_POL_PKT_TYPE_CTRL0_COUNT       16
#define L2TM_L2TE_POL_PKT_TYPE_CTRL0_dft         0x00000500

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 type                 :  3 ; /* bits 2:0 */
    u32 color_blind          :  1 ; /* bits 3:3 */
    u32 pkt_mode             :  1 ; /* bits 4:4 */
    u32 egr_len_sel          :  1 ; /* bits 5:5 */
    u32 ipg                  :  5 ; /* bits 10:6 */
    u32 bypass_yellow        :  1 ; /* bits 11:11 */
    u32 bypass_red           :  1 ; /* bits 12:12 */
    u32 update_mode          :  1 ; /* bits 13:13 */
    u32 nest_level           :  2 ; /* bits 15:14 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PKT_TYPE_CTRL0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PKT_TYPE_PROFILE_MEM_ACCESS 0xf4302540
#define L2TM_L2TE_POL_PKT_TYPE_PROFILE_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 26 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PKT_TYPE_PROFILE_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PKT_TYPE_PROFILE_MEM_DATA2 0xf4302544
#define L2TM_L2TE_POL_PKT_TYPE_PROFILE_MEM_DATA2_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 peak_bs              : 12 ; /* bits 11:0 */
    u32 rsrvd1               : 20 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PKT_TYPE_PROFILE_MEM_DATA2_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PKT_TYPE_PROFILE_MEM_DATA1 0xf4302548
#define L2TM_L2TE_POL_PKT_TYPE_PROFILE_MEM_DATA1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 committed_bs         :  6 ; /* bits 5:0 */
    u32 peak_rate_k          : 10 ; /* bits 15:6 */
    u32 peak_rate_m          : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PKT_TYPE_PROFILE_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PKT_TYPE_PROFILE_MEM_DATA0 0xf430254c
#define L2TM_L2TE_POL_PKT_TYPE_PROFILE_MEM_DATA0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 committed_rate_k     : 10 ; /* bits 9:0 */
    u32 committed_rate_m     : 16 ; /* bits 25:10 */
    u32 committed_bs         :  6 ; /* bits 31:26 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PKT_TYPE_PROFILE_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PKT_TYPE_COUNTER_MEM_ACCESS 0xf4302550
#define L2TM_L2TE_POL_PKT_TYPE_COUNTER_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 26 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PKT_TYPE_COUNTER_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PKT_TYPE_COUNTER_MEM_DATA1 0xf4302554
#define L2TM_L2TE_POL_PKT_TYPE_COUNTER_MEM_DATA1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 peak_tbc             : 10 ; /* bits 9:0 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PKT_TYPE_COUNTER_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PKT_TYPE_COUNTER_MEM_DATA0 0xf4302558
#define L2TM_L2TE_POL_PKT_TYPE_COUNTER_MEM_DATA0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 committed_tbc        : 21 ; /* bits 20:0 */
    u32 peak_tbc             : 11 ; /* bits 31:21 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PKT_TYPE_COUNTER_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PORT_CTRL0                 0xf430255c
#define L2TM_L2TE_POL_PORT_CTRL0_STRIDE          4
#define L2TM_L2TE_POL_PORT_CTRL0_COUNT           16
#define L2TM_L2TE_POL_PORT_CTRL0_dft             0x00000500

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 type                 :  3 ; /* bits 2:0 */
    u32 color_blind          :  1 ; /* bits 3:3 */
    u32 pkt_mode             :  1 ; /* bits 4:4 */
    u32 egr_len_sel          :  1 ; /* bits 5:5 */
    u32 ipg                  :  5 ; /* bits 10:6 */
    u32 bypass_yellow        :  1 ; /* bits 11:11 */
    u32 bypass_red           :  1 ; /* bits 12:12 */
    u32 update_mode          :  1 ; /* bits 13:13 */
    u32 nest_level           :  2 ; /* bits 15:14 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PORT_CTRL0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PORT_PROFILE_MEM_ACCESS    0xf430259c
#define L2TM_L2TE_POL_PORT_PROFILE_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 26 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PORT_PROFILE_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PORT_PROFILE_MEM_DATA2     0xf43025a0
#define L2TM_L2TE_POL_PORT_PROFILE_MEM_DATA2_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 peak_bs              : 12 ; /* bits 11:0 */
    u32 rsrvd1               : 20 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PORT_PROFILE_MEM_DATA2_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PORT_PROFILE_MEM_DATA1     0xf43025a4
#define L2TM_L2TE_POL_PORT_PROFILE_MEM_DATA1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 committed_bs         :  6 ; /* bits 5:0 */
    u32 peak_rate_k          : 10 ; /* bits 15:6 */
    u32 peak_rate_m          : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PORT_PROFILE_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PORT_PROFILE_MEM_DATA0     0xf43025a8
#define L2TM_L2TE_POL_PORT_PROFILE_MEM_DATA0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 committed_rate_k     : 10 ; /* bits 9:0 */
    u32 committed_rate_m     : 16 ; /* bits 25:10 */
    u32 committed_bs         :  6 ; /* bits 31:26 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PORT_PROFILE_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PORT_COUNTER_MEM_ACCESS    0xf43025ac
#define L2TM_L2TE_POL_PORT_COUNTER_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 26 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PORT_COUNTER_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PORT_COUNTER_MEM_DATA1     0xf43025b0
#define L2TM_L2TE_POL_PORT_COUNTER_MEM_DATA1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 peak_tbc             : 10 ; /* bits 9:0 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PORT_COUNTER_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_PORT_COUNTER_MEM_DATA0     0xf43025b4
#define L2TM_L2TE_POL_PORT_COUNTER_MEM_DATA0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 committed_tbc        : 21 ; /* bits 20:0 */
    u32 peak_tbc             : 11 ; /* bits 31:21 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_PORT_COUNTER_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_AGRFLOW_CTRL0              0xf43025b8
#define L2TM_L2TE_POL_AGRFLOW_CTRL0_STRIDE       4
#define L2TM_L2TE_POL_AGRFLOW_CTRL0_COUNT        8
#define L2TM_L2TE_POL_AGRFLOW_CTRL0_dft          0x00000500

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 type                 :  3 ; /* bits 2:0 */
    u32 color_blind          :  1 ; /* bits 3:3 */
    u32 pkt_mode             :  1 ; /* bits 4:4 */
    u32 egr_len_sel          :  1 ; /* bits 5:5 */
    u32 ipg                  :  5 ; /* bits 10:6 */
    u32 bypass_yellow        :  1 ; /* bits 11:11 */
    u32 bypass_red           :  1 ; /* bits 12:12 */
    u32 update_mode          :  1 ; /* bits 13:13 */
    u32 nest_level           :  2 ; /* bits 15:14 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_AGRFLOW_CTRL0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_AGRFLOW_PROFILE_MEM_ACCESS 0xf43025d8
#define L2TM_L2TE_POL_AGRFLOW_PROFILE_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  3 ; /* bits 2:0 */
    u32 rsrvd1               : 27 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_AGRFLOW_PROFILE_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_AGRFLOW_PROFILE_MEM_DATA2  0xf43025dc
#define L2TM_L2TE_POL_AGRFLOW_PROFILE_MEM_DATA2_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 peak_bs              : 12 ; /* bits 11:0 */
    u32 rsrvd1               : 20 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_AGRFLOW_PROFILE_MEM_DATA2_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_AGRFLOW_PROFILE_MEM_DATA1  0xf43025e0
#define L2TM_L2TE_POL_AGRFLOW_PROFILE_MEM_DATA1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 committed_bs         :  6 ; /* bits 5:0 */
    u32 peak_rate_k          : 10 ; /* bits 15:6 */
    u32 peak_rate_m          : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_AGRFLOW_PROFILE_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_AGRFLOW_PROFILE_MEM_DATA0  0xf43025e4
#define L2TM_L2TE_POL_AGRFLOW_PROFILE_MEM_DATA0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 committed_rate_k     : 10 ; /* bits 9:0 */
    u32 committed_rate_m     : 16 ; /* bits 25:10 */
    u32 committed_bs         :  6 ; /* bits 31:26 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_AGRFLOW_PROFILE_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_AGRFLOW_COUNTER_MEM_ACCESS 0xf43025e8
#define L2TM_L2TE_POL_AGRFLOW_COUNTER_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  3 ; /* bits 2:0 */
    u32 rsrvd1               : 27 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_AGRFLOW_COUNTER_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_AGRFLOW_COUNTER_MEM_DATA1  0xf43025ec
#define L2TM_L2TE_POL_AGRFLOW_COUNTER_MEM_DATA1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 peak_tbc             : 10 ; /* bits 9:0 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_AGRFLOW_COUNTER_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_AGRFLOW_COUNTER_MEM_DATA0  0xf43025f0
#define L2TM_L2TE_POL_AGRFLOW_COUNTER_MEM_DATA0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 committed_tbc        : 21 ; /* bits 20:0 */
    u32 peak_tbc             : 11 ; /* bits 31:21 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_AGRFLOW_COUNTER_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_TB_CTRL                    0xf43025f4
#define L2TM_L2TE_POL_TB_CTRL_dft                0x2ff3e723

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 addtok_en            :  1 ; /* bits 0:0 */
    u32 subtok_en            :  1 ; /* bits 1:1 */
    u32 rsrvd1               :  2 ;
    u32 upd_cnt_lmt          :  4 ; /* bits 7:4 */
    u32 cyc_cnt_lmt          : 12 ; /* bits 19:8 */
    u32 last_upd_cyc         : 12 ; /* bits 31:20 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_TB_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_POL_TB_CTRL1                   0xf43025f8
#define L2TM_L2TE_POL_TB_CTRL1_dft               0x000001f3

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 k_cnt_lmt            : 10 ; /* bits 9:0 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_POL_TB_CTRL1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_IPG_PROFILE                0xf4302700
#define L2TM_L2TE_SHP_IPG_PROFILE_dft            0x14141414

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ipg0                 :  5 ; /* bits 4:0 */
    u32 rsrvd1               :  3 ;
    u32 ipg1                 :  5 ; /* bits 12:8 */
    u32 rsrvd2               :  3 ;
    u32 ipg2                 :  5 ; /* bits 20:16 */
    u32 rsrvd3               :  3 ;
    u32 ipg3                 :  5 ; /* bits 28:24 */
    u32 rsrvd4               :  3 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_IPG_PROFILE_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_PORT_IPG_SELECT0           0xf4302704
#define L2TM_L2TE_SHP_PORT_IPG_SELECT0_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pid0                 :  2 ; /* bits 1:0 */
    u32 pid1                 :  2 ; /* bits 3:2 */
    u32 pid2                 :  2 ; /* bits 5:4 */
    u32 pid3                 :  2 ; /* bits 7:6 */
    u32 pid4                 :  2 ; /* bits 9:8 */
    u32 pid5                 :  2 ; /* bits 11:10 */
    u32 pid6                 :  2 ; /* bits 13:12 */
    u32 pid7                 :  2 ; /* bits 15:14 */
    u32 pid8                 :  2 ; /* bits 17:16 */
    u32 pid9                 :  2 ; /* bits 19:18 */
    u32 pid10                :  2 ; /* bits 21:20 */
    u32 pid11                :  2 ; /* bits 23:22 */
    u32 pid12                :  2 ; /* bits 25:24 */
    u32 pid13                :  2 ; /* bits 27:26 */
    u32 pid14                :  2 ; /* bits 29:28 */
    u32 pid15                :  2 ; /* bits 31:30 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_PORT_IPG_SELECT0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_SRP_CONFIG0                0xf4302708
#define L2TM_L2TE_SHP_SRP_CONFIG0_STRIDE         4
#define L2TM_L2TE_SHP_SRP_CONFIG0_COUNT          2
#define L2TM_L2TE_SHP_SRP_CONFIG0_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg0_enb             :  1 ; /* bits 0:0 */
    u32 cfg0_cos             :  3 ; /* bits 3:1 */
    u32 rsrvd1               : 11 ;
    u32 cfg0_class_b         :  1 ; /* bits 15:15 */
    u32 cfg1_enb             :  1 ; /* bits 16:16 */
    u32 cfg1_cos             :  3 ; /* bits 19:17 */
    u32 rsrvd2               : 11 ;
    u32 cfg1_class_b         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_SRP_CONFIG0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_SRP_CONFIG_EN              0xf4302710
#define L2TM_L2TE_SHP_SRP_CONFIG_EN_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pid0                 :  4 ; /* bits 3:0 */
    u32 pid1                 :  4 ; /* bits 7:4 */
    u32 pid2                 :  4 ; /* bits 11:8 */
    u32 pid3                 :  4 ; /* bits 15:12 */
    u32 pid4                 :  4 ; /* bits 19:16 */
    u32 pid5                 :  4 ; /* bits 23:20 */
    u32 pid6                 :  4 ; /* bits 27:24 */
    u32 pid7                 :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_SRP_CONFIG_EN_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_CTRL                       0xf4302714
#define L2TM_L2TE_SHP_CTRL_dft                   0x0000007c

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_mode_class0_cnt  :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 pkt_mode_class1_cnt  :  7 ; /* bits 14:8 */
    u32 rsrvd2               : 17 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_PORT_TBC_MEM_ACCESS        0xf4302718
#define L2TM_L2TE_SHP_PORT_TBC_MEM_ACCESS_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 26 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_PORT_TBC_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_PORT_TBC_MEM_DATA1         0xf430271c
#define L2TM_L2TE_SHP_PORT_TBC_MEM_DATA1_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bs                   :  6 ; /* bits 5:0 */
    u32 enb                  :  2 ; /* bits 7:6 */
    u32 mode                 :  1 ; /* bits 8:8 */
    u32 tbc                  : 21 ; /* bits 29:9 */
    u32 pkt_mode_class_sel   :  1 ; /* bits 30:30 */
    u32 rsrvd1               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_PORT_TBC_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_PORT_TBC_MEM_DATA0         0xf4302720
#define L2TM_L2TE_SHP_PORT_TBC_MEM_DATA0_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rate_k               : 10 ; /* bits 9:0 */
    u32 rate_m               : 16 ; /* bits 25:10 */
    u32 bs                   :  6 ; /* bits 31:26 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_PORT_TBC_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_GROUP_TBC_MEM_ACCESS       0xf4302724
#define L2TM_L2TE_SHP_GROUP_TBC_MEM_ACCESS_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 26 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_GROUP_TBC_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_GROUP_TBC_MEM_DATA1        0xf4302728
#define L2TM_L2TE_SHP_GROUP_TBC_MEM_DATA1_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bs                   :  6 ; /* bits 5:0 */
    u32 enb                  :  2 ; /* bits 7:6 */
    u32 mode                 :  1 ; /* bits 8:8 */
    u32 tbc                  : 21 ; /* bits 29:9 */
    u32 pkt_mode_class_sel   :  1 ; /* bits 30:30 */
    u32 rsrvd1               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_GROUP_TBC_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_GROUP_TBC_MEM_DATA0        0xf430272c
#define L2TM_L2TE_SHP_GROUP_TBC_MEM_DATA0_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rate_k               : 10 ; /* bits 9:0 */
    u32 rate_m               : 16 ; /* bits 25:10 */
    u32 bs                   :  6 ; /* bits 31:26 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_GROUP_TBC_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_VOQ_TBC_MEM_ACCESS         0xf4302730
#define L2TM_L2TE_SHP_VOQ_TBC_MEM_ACCESS_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  7 ; /* bits 6:0 */
    u32 rsrvd1               : 23 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_VOQ_TBC_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_VOQ_TBC_MEM_DATA1          0xf4302734
#define L2TM_L2TE_SHP_VOQ_TBC_MEM_DATA1_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bs                   :  6 ; /* bits 5:0 */
    u32 enb                  :  2 ; /* bits 7:6 */
    u32 mode                 :  1 ; /* bits 8:8 */
    u32 tbc                  : 21 ; /* bits 29:9 */
    u32 pkt_mode_class_sel   :  1 ; /* bits 30:30 */
    u32 rsrvd1               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_VOQ_TBC_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_VOQ_TBC_MEM_DATA0          0xf4302738
#define L2TM_L2TE_SHP_VOQ_TBC_MEM_DATA0_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rate_k               : 10 ; /* bits 9:0 */
    u32 rate_m               : 16 ; /* bits 25:10 */
    u32 bs                   :  6 ; /* bits 31:26 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_VOQ_TBC_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_AGR_SHP_CFG                0xf430273c
#define L2TM_L2TE_SHP_AGR_SHP_CFG_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port_agr_bitmap      : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_AGR_SHP_CFG_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_AGR_SHP_CTRL1              0xf4302740
#define L2TM_L2TE_SHP_AGR_SHP_CTRL1_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cbs                  : 10 ; /* bits 9:0 */
    u32 enb                  :  2 ; /* bits 11:10 */
    u32 rsrvd1               : 20 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_AGR_SHP_CTRL1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_AGR_SHP_CTRL0              0xf4302744
#define L2TM_L2TE_SHP_AGR_SHP_CTRL0_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rate_k               : 10 ; /* bits 9:0 */
    u32 rate_m               : 16 ; /* bits 25:10 */
    u32 rsrvd1               :  6 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_AGR_SHP_CTRL0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_AGR_SHP_STS                0xf4302748
#define L2TM_L2TE_SHP_AGR_SHP_STS_dft            0x00100000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tbc                  : 21 ; /* bits 20:0 */
    u32 rsrvd1               : 11 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_AGR_SHP_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_TB_CTRL                    0xf430274c
#define L2TM_L2TE_SHP_TB_CTRL_dft                0x2ff3e723

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 addtok_en            :  1 ; /* bits 0:0 */
    u32 subtok_en            :  1 ; /* bits 1:1 */
    u32 rsrvd1               :  2 ;
    u32 upd_cnt_lmt          :  4 ; /* bits 7:4 */
    u32 cyc_cnt_lmt          : 12 ; /* bits 19:8 */
    u32 last_upd_cyc         : 12 ; /* bits 31:20 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_TB_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_SHP_TB_CTRL1                   0xf4302750
#define L2TM_L2TE_SHP_TB_CTRL1_dft               0x000001f3

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 k_cnt_lmt            : 10 ; /* bits 9:0 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_SHP_TB_CTRL1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_WRED_CTRL                      0xf4302800
#define L2TM_L2TE_WRED_CTRL_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  2 ;
    u32 fast_decay           :  1 ; /* bits 2:2 */
    u32 rsrvd2               :  1 ;
    u32 afgs_weight          :  4 ; /* bits 7:4 */
    u32 rsrvd3               : 24 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_WRED_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_WRED_AFGS_MEM_ACCESS           0xf4302804
#define L2TM_L2TE_WRED_AFGS_MEM_ACCESS_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 29 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_WRED_AFGS_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_WRED_AFGS_MEM_DATA             0xf4302808
#define L2TM_L2TE_WRED_AFGS_MEM_DATA_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 depth                : 15 ; /* bits 14:0 */
    u32 rsrvd1               : 17 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_WRED_AFGS_MEM_DATA_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_WRED_PROFILE_MEM_ACCESS        0xf430280c
#define L2TM_L2TE_WRED_PROFILE_MEM_ACCESS_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  5 ; /* bits 4:0 */
    u32 rsrvd1               : 25 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_WRED_PROFILE_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA7         0xf4302810
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA7_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data_rsvd            :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_WRED_PROFILE_MEM_DATA7_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA6         0xf4302814
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA6_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 unmark_idx           :  4 ; /* bits 3:0 */
    u32 mark_idx             :  4 ; /* bits 7:4 */
    u32 data_rsvd            : 24 ; /* bits 31:8 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_WRED_PROFILE_MEM_DATA6_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA5         0xf4302818
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA5_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mark_dps             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_WRED_PROFILE_MEM_DATA5_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA4         0xf430281c
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA4_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mark_dps             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_WRED_PROFILE_MEM_DATA4_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA3         0xf4302820
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA3_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mark_dps             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_WRED_PROFILE_MEM_DATA3_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA2         0xf4302824
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA2_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 unmark_dps           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_WRED_PROFILE_MEM_DATA2_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA1         0xf4302828
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA1_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 unmark_dps           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_WRED_PROFILE_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA0         0xf430282c
#define L2TM_L2TE_WRED_PROFILE_MEM_DATA0_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 unmark_dps           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_WRED_PROFILE_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_WRED_PROFILE_SELECT_MEM_ACCESS 0xf4302830
#define L2TM_L2TE_WRED_PROFILE_SELECT_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  5 ; /* bits 4:0 */
    u32 rsrvd1               : 25 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_WRED_PROFILE_SELECT_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_WRED_PROFILE_SELECT_MEM_DATA1  0xf4302834
#define L2TM_L2TE_WRED_PROFILE_SELECT_MEM_DATA1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sel6                 :  3 ; /* bits 2:0 */
    u32 sel7                 :  5 ; /* bits 7:3 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_WRED_PROFILE_SELECT_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_WRED_PROFILE_SELECT_MEM_DATA0  0xf4302838
#define L2TM_L2TE_WRED_PROFILE_SELECT_MEM_DATA0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sel0                 :  5 ; /* bits 4:0 */
    u32 sel1                 :  5 ; /* bits 9:5 */
    u32 sel2                 :  5 ; /* bits 14:10 */
    u32 sel3                 :  5 ; /* bits 19:15 */
    u32 sel4                 :  5 ; /* bits 24:20 */
    u32 sel5                 :  5 ; /* bits 29:25 */
    u32 sel6                 :  2 ; /* bits 31:30 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_WRED_PROFILE_SELECT_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_FC_GLB_INT                     0xf4302900
#define L2TM_L2TE_FC_GLB_INT_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rxflowcntl0          :  1 ; /* bits 0:0 */
    u32 rxflowcntl1          :  1 ; /* bits 1:1 */
    u32 rxflowcntl2          :  1 ; /* bits 2:2 */
    u32 rxflowcntl3          :  1 ; /* bits 3:3 */
    u32 rxflowcntl4          :  1 ; /* bits 4:4 */
    u32 rxflowcntl5          :  1 ; /* bits 5:5 */
    u32 rxflowcntl6          :  1 ; /* bits 6:6 */
    u32 rxflowcntl7          :  1 ; /* bits 7:7 */
    u32 rxflowcntl8          :  1 ; /* bits 8:8 */
    u32 rxflowcntl9          :  1 ; /* bits 9:9 */
    u32 rxflowcntl10         :  1 ; /* bits 10:10 */
    u32 rsrvd1               :  2 ;
    u32 rxflowcntl13         :  1 ; /* bits 13:13 */
    u32 rxflowcntl13_qm      :  1 ; /* bits 14:14 */
    u32 rsrvd2               :  1 ;
    u32 txflowcntl0          :  1 ; /* bits 16:16 */
    u32 txflowcntl1          :  1 ; /* bits 17:17 */
    u32 txflowcntl2          :  1 ; /* bits 18:18 */
    u32 txflowcntl3          :  1 ; /* bits 19:19 */
    u32 txflowcntl4          :  1 ; /* bits 20:20 */
    u32 txflowcntl5          :  1 ; /* bits 21:21 */
    u32 txflowcntl6          :  1 ; /* bits 22:22 */
    u32 txflowcntl7          :  1 ; /* bits 23:23 */
    u32 rsrvd3               :  1 ;
    u32 txflowcntl9          :  1 ; /* bits 25:25 */
    u32 rsrvd4               :  1 ;
    u32 txflowcntl11         :  1 ; /* bits 27:27 */
    u32 txflowcntl12         :  1 ; /* bits 28:28 */
    u32 txflowcntl13         :  1 ; /* bits 29:29 */
    u32 txflowcntl14         :  1 ; /* bits 30:30 */
    u32 txflowcntl15         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_FC_GLB_INT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_FC_GLB_INTE                    0xf4302904
#define L2TM_L2TE_FC_GLB_INTE_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rxflowcntl0E         :  1 ; /* bits 0:0 */
    u32 rxflowcntl1E         :  1 ; /* bits 1:1 */
    u32 rxflowcntl2E         :  1 ; /* bits 2:2 */
    u32 rxflowcntl3E         :  1 ; /* bits 3:3 */
    u32 rxflowcntl4E         :  1 ; /* bits 4:4 */
    u32 rxflowcntl5E         :  1 ; /* bits 5:5 */
    u32 rxflowcntl6E         :  1 ; /* bits 6:6 */
    u32 rxflowcntl7E         :  1 ; /* bits 7:7 */
    u32 rxflowcntl8E         :  1 ; /* bits 8:8 */
    u32 rxflowcntl9E         :  1 ; /* bits 9:9 */
    u32 rxflowcntl10E        :  1 ; /* bits 10:10 */
    u32 rsrvd1               :  2 ;
    u32 rxflowcntl13E        :  1 ; /* bits 13:13 */
    u32 rxflowcntl13_qmE     :  1 ; /* bits 14:14 */
    u32 rsrvd2               :  1 ;
    u32 txflowcntl0E         :  1 ; /* bits 16:16 */
    u32 txflowcntl1E         :  1 ; /* bits 17:17 */
    u32 txflowcntl2E         :  1 ; /* bits 18:18 */
    u32 txflowcntl3E         :  1 ; /* bits 19:19 */
    u32 txflowcntl4E         :  1 ; /* bits 20:20 */
    u32 txflowcntl5E         :  1 ; /* bits 21:21 */
    u32 txflowcntl6E         :  1 ; /* bits 22:22 */
    u32 txflowcntl7E         :  1 ; /* bits 23:23 */
    u32 rsrvd3               :  1 ;
    u32 txflowcntl9E         :  1 ; /* bits 25:25 */
    u32 rsrvd4               :  1 ;
    u32 txflowcntl11E        :  1 ; /* bits 27:27 */
    u32 txflowcntl12E        :  1 ; /* bits 28:28 */
    u32 txflowcntl13E        :  1 ; /* bits 29:29 */
    u32 txflowcntl14E        :  1 ; /* bits 30:30 */
    u32 txflowcntl15E        :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_FC_GLB_INTE_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_FC_GLB_CTRL                    0xf4302908
#define L2TM_L2TE_FC_GLB_CTRL_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 deepq_rxpfc_en       :  8 ; /* bits 7:0 */
    u32 cpu_rxpfc_en         :  8 ; /* bits 15:8 */
    u32 l3fewan_rxpfc_en     :  8 ; /* bits 23:16 */
    u32 l3felan_rxpfc_en     :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_FC_GLB_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_FC_GLB_CTRL_LANL3FE            0xf430290c
#define L2TM_L2TE_FC_GLB_CTRL_LANL3FE_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lanl3fe_rxpfc_en     :  7 ; /* bits 6:0 */
    u32 rsrvd1               : 25 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_FC_GLB_CTRL_LANL3FE_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_FC_GLB_STS                     0xf4302910
#define L2TM_L2TE_FC_GLB_STS_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 deepq_rxpfc          :  8 ; /* bits 7:0 */
    u32 cpu_rxpfc            :  8 ; /* bits 15:8 */
    u32 lanl3fe_rxpfc        :  7 ; /* bits 22:16 */
    u32 rsrvd1               :  9 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_FC_GLB_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_FC_GLB_TIMER                   0xf4302914
#define L2TM_L2TE_FC_GLB_TIMER_dft               0x000073ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 num_of_cycles        : 10 ; /* bits 9:0 */
    u32 rsrvd1               :  2 ;
    u32 cycle_unit           :  3 ; /* bits 14:12 */
    u32 rsrvd2               : 16 ;
    u32 enable               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_FC_GLB_TIMER_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_FC_GLB_PFC_CTRL0               0xf4302918
#define L2TM_L2TE_FC_GLB_PFC_CTRL0_STRIDE        8
#define L2TM_L2TE_FC_GLB_PFC_CTRL0_COUNT         2
#define L2TM_L2TE_FC_GLB_PFC_CTRL0_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cos_bmap             :  8 ; /* bits 7:0 */
    u32 port_bmap            :  8 ; /* bits 15:8 */
    u32 rxpfc_en             :  1 ; /* bits 16:16 */
    u32 txpfc_en             :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_FC_GLB_PFC_CTRL0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_FC_GLB_PFC_CNT0                0xf430291c
#define L2TM_L2TE_FC_GLB_PFC_CNT0_STRIDE         8
#define L2TM_L2TE_FC_GLB_PFC_CNT0_COUNT          2
#define L2TM_L2TE_FC_GLB_PFC_CNT0_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_FC_GLB_PFC_CNT0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_FC_CTRL                        0xf4302980
#define L2TM_L2TE_FC_CTRL_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_en                :  1 ; /* bits 0:0 */
    u32 tx_en                :  1 ; /* bits 1:1 */
    u32 src_rate_enforce     :  1 ; /* bits 2:2 */
    u32 rsrvd1               :  1 ;
    u32 stat_pri_sel         :  3 ; /* bits 6:4 */
    u32 rsrvd2               : 25 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_FC_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_FC_STS                         0xf4302984
#define L2TM_L2TE_FC_STS_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rxpfc                :  8 ; /* bits 7:0 */
    u32 txpfc                :  8 ; /* bits 15:8 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_FC_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_FC_STAT                        0xf4302988
#define L2TM_L2TE_FC_STAT_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 flag_num             :  3 ; /* bits 2:0 */
    u32 rsrvd1               :  1 ;
    u32 voq                  :  7 ; /* bits 10:4 */
    u32 rsrvd2               :  1 ;
    u32 qm_voq               :  9 ; /* bits 20:12 */
    u32 rsrvd3               :  9 ;
    u32 txpfc                :  1 ; /* bits 30:30 */
    u32 rxpfc                :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_FC_STAT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_INT                         0xf4302d00
#define L2TM_L2TE_CB_INT_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 voq_bufcnt_udfl      :  1 ; /* bits 0:0 */
    u32 voq_bufcnt_ovfl      :  1 ; /* bits 1:1 */
    u32 rsrvd1               :  2 ;
    u32 port_freecnt_udfl    :  1 ; /* bits 4:4 */
    u32 port_freecnt_ovfl    :  1 ; /* bits 5:5 */
    u32 rsrvd2               : 26 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_INT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_INTE                        0xf4302d04
#define L2TM_L2TE_CB_INTE_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 voq_bufcnt_udflE     :  1 ; /* bits 0:0 */
    u32 voq_bufcnt_ovflE     :  1 ; /* bits 1:1 */
    u32 rsrvd1               :  2 ;
    u32 port_freecnt_udflE   :  1 ; /* bits 4:4 */
    u32 port_freecnt_ovflE   :  1 ; /* bits 5:5 */
    u32 rsrvd2               : 26 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_INTE_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_ERR_INFO                    0xf4302d08
#define L2TM_L2TE_CB_ERR_INFO_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 voq_of_buferr        :  7 ; /* bits 6:0 */
    u32 rsrvd1               : 25 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_ERR_INFO_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_CTRL                        0xf4302d0c
#define L2TM_L2TE_CB_CTRL_dft                    0x0003ff03

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 scan_cycle_per_run   :  8 ; /* bits 7:0 */
    u32 scan_cycle_unit      : 10 ; /* bits 17:8 */
    u32 rsrvd1               : 12 ;
    u32 cnt_udfl_allow       :  1 ; /* bits 30:30 */
    u32 scan_enable          :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_TM_DQSCH_HI_BUF_USG0        0xf4302d10
#define L2TM_L2TE_CB_TM_DQSCH_HI_BUF_USG0_STRIDE 4
#define L2TM_L2TE_CB_TM_DQSCH_HI_BUF_USG0_COUNT  2
#define L2TM_L2TE_CB_TM_DQSCH_HI_BUF_USG0_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dqid                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_TM_DQSCH_HI_BUF_USG0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_TM_DQSCH_MID_BUF_USG0       0xf4302d18
#define L2TM_L2TE_CB_TM_DQSCH_MID_BUF_USG0_STRIDE 4
#define L2TM_L2TE_CB_TM_DQSCH_MID_BUF_USG0_COUNT 2
#define L2TM_L2TE_CB_TM_DQSCH_MID_BUF_USG0_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dqid                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_TM_DQSCH_MID_BUF_USG0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_TM_TAILDROP_STS0            0xf4302d20
#define L2TM_L2TE_CB_TM_TAILDROP_STS0_STRIDE     4
#define L2TM_L2TE_CB_TM_TAILDROP_STS0_COUNT      4
#define L2TM_L2TE_CB_TM_TAILDROP_STS0_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 voq                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_TM_TAILDROP_STS0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_QM_TAILDROP_STS0            0xf4302d30
#define L2TM_L2TE_CB_QM_TAILDROP_STS0_STRIDE     4
#define L2TM_L2TE_CB_QM_TAILDROP_STS0_COUNT      12
#define L2TM_L2TE_CB_QM_TAILDROP_STS0_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 voq                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_QM_TAILDROP_STS0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_GLOB_TD_STS                 0xf4302d60
#define L2TM_L2TE_CB_GLOB_TD_STS_dft             0x0020ffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 per_port_prvt_avl    : 16 ; /* bits 15:0 */
    u32 noncong_buf_avl      :  1 ; /* bits 16:16 */
    u32 common_buf_avl       :  1 ; /* bits 17:17 */
    u32 rsrvd1               :  3 ;
    u32 fc_buf_usg_l         :  1 ; /* bits 21:21 */
    u32 fc_buf_usg_m         :  1 ; /* bits 22:22 */
    u32 fc_buf_usg_h         :  1 ; /* bits 23:23 */
    u32 pfc                  :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_GLOB_TD_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_PORT_TD_STS                 0xf4302d64
#define L2TM_L2TE_CB_PORT_TD_STS_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port                 : 16 ; /* bits 15:0 */
    u32 src_port             : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_PORT_TD_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_VOQ_TD_STS0                 0xf4302d68
#define L2TM_L2TE_CB_VOQ_TD_STS0_STRIDE          4
#define L2TM_L2TE_CB_VOQ_TD_STS0_COUNT           4
#define L2TM_L2TE_CB_VOQ_TD_STS0_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 voq                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_VOQ_TD_STS0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_SRC_PRI_TD_STS              0xf4302d78
#define L2TM_L2TE_CB_SRC_PRI_TD_STS_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 src_pri              : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_SRC_PRI_TD_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_PORT_THRSH_PROFILE0         0xf4302d7c
#define L2TM_L2TE_CB_PORT_THRSH_PROFILE0_STRIDE  8
#define L2TM_L2TE_CB_PORT_THRSH_PROFILE0_COUNT   4
#define L2TM_L2TE_CB_PORT_THRSH_PROFILE0_dft     0x7fff7fff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lth                  : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 hth                  : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_PORT_THRSH_PROFILE0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_PORT_GRPTHRSH_PROFILE0      0xf4302d80
#define L2TM_L2TE_CB_PORT_GRPTHRSH_PROFILE0_STRIDE 8
#define L2TM_L2TE_CB_PORT_GRPTHRSH_PROFILE0_COUNT 4
#define L2TM_L2TE_CB_PORT_GRPTHRSH_PROFILE0_dft  0x7fff7fff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 grplth               : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 grphth               : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_PORT_GRPTHRSH_PROFILE0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_PORT_THRSH_SELECT           0xf4302d9c
#define L2TM_L2TE_CB_PORT_THRSH_SELECT_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 thsel0               :  2 ; /* bits 1:0 */
    u32 thsel1               :  2 ; /* bits 3:2 */
    u32 thsel2               :  2 ; /* bits 5:4 */
    u32 thsel3               :  2 ; /* bits 7:6 */
    u32 thsel4               :  2 ; /* bits 9:8 */
    u32 thsel5               :  2 ; /* bits 11:10 */
    u32 thsel6               :  2 ; /* bits 13:12 */
    u32 thsel7               :  2 ; /* bits 15:14 */
    u32 thsel8               :  2 ; /* bits 17:16 */
    u32 thsel9               :  2 ; /* bits 19:18 */
    u32 thsel10              :  2 ; /* bits 21:20 */
    u32 thsel11              :  2 ; /* bits 23:22 */
    u32 thsel12              :  2 ; /* bits 25:24 */
    u32 thsel13              :  2 ; /* bits 27:26 */
    u32 thsel14              :  2 ; /* bits 29:28 */
    u32 thsel15              :  2 ; /* bits 31:30 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_PORT_THRSH_SELECT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_VOQ_THRSH_PROFILE_MEM_ACCESS 0xf4302da0
#define L2TM_L2TE_CB_VOQ_THRSH_PROFILE_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  3 ; /* bits 2:0 */
    u32 rsrvd1               : 27 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_VOQ_THRSH_PROFILE_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_VOQ_THRSH_PROFILE_MEM_DATA1 0xf4302da4
#define L2TM_L2TE_CB_VOQ_THRSH_PROFILE_MEM_DATA1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 grplth               : 13 ; /* bits 12:0 */
    u32 grphth               : 15 ; /* bits 27:13 */
    u32 rsrvd1               :  4 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_VOQ_THRSH_PROFILE_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_VOQ_THRSH_PROFILE_MEM_DATA0 0xf4302da8
#define L2TM_L2TE_CB_VOQ_THRSH_PROFILE_MEM_DATA0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lth                  : 15 ; /* bits 14:0 */
    u32 hth                  : 15 ; /* bits 29:15 */
    u32 grplth               :  2 ; /* bits 31:30 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_VOQ_THRSH_PROFILE_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_VOQ_THRSH_SELECT_MEM_ACCESS 0xf4302dac
#define L2TM_L2TE_CB_VOQ_THRSH_SELECT_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  7 ; /* bits 6:0 */
    u32 rsrvd1               : 23 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_VOQ_THRSH_SELECT_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_VOQ_THRSH_SELECT_MEM_DATA   0xf4302db0
#define L2TM_L2TE_CB_VOQ_THRSH_SELECT_MEM_DATA_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sel                  :  3 ; /* bits 2:0 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_VOQ_THRSH_SELECT_MEM_DATA_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_PORT_FREECNT_MEM_ACCESS     0xf4302db4
#define L2TM_L2TE_CB_PORT_FREECNT_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 26 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_PORT_FREECNT_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_PORT_FREECNT_MEM_DATA       0xf4302db8
#define L2TM_L2TE_CB_PORT_FREECNT_MEM_DATA_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt0                 : 15 ; /* bits 14:0 */
    u32 cnt0_msb             :  1 ; /* bits 15:15 */
    u32 cnt1                 : 15 ; /* bits 30:16 */
    u32 cnt1_msb             :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_PORT_FREECNT_MEM_DATA_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_VOQ_BUFCNT_MEM_ACCESS       0xf4302dbc
#define L2TM_L2TE_CB_VOQ_BUFCNT_MEM_ACCESS_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  7 ; /* bits 6:0 */
    u32 rsrvd1               : 23 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_VOQ_BUFCNT_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_VOQ_BUFCNT_MEM_DATA         0xf4302dc0
#define L2TM_L2TE_CB_VOQ_BUFCNT_MEM_DATA_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt0                 : 15 ; /* bits 14:0 */
    u32 cnt0_rsvd            :  1 ; /* bits 15:15 */
    u32 cnt1                 : 15 ; /* bits 30:16 */
    u32 cnt1_rsvd            :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_VOQ_BUFCNT_MEM_DATA_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_VOQ_MAX_BUFCNT_MEM_ACCESS   0xf4302dc4
#define L2TM_L2TE_CB_VOQ_MAX_BUFCNT_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  7 ; /* bits 6:0 */
    u32 rsrvd1               : 23 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_VOQ_MAX_BUFCNT_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_VOQ_MAX_BUFCNT_MEM_DATA     0xf4302dc8
#define L2TM_L2TE_CB_VOQ_MAX_BUFCNT_MEM_DATA_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 15 ; /* bits 14:0 */
    u32 rsrvd1               : 17 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_VOQ_MAX_BUFCNT_MEM_DATA_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_GLB_THRSH                   0xf4302dcc
#define L2TM_L2TE_CB_GLB_THRSH_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lth                  : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 hth                  : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_GLB_THRSH_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_GLB_PRI_THRSH0              0xf4302dd0
#define L2TM_L2TE_CB_GLB_PRI_THRSH0_STRIDE       4
#define L2TM_L2TE_CB_GLB_PRI_THRSH0_COUNT        8
#define L2TM_L2TE_CB_GLB_PRI_THRSH0_dft          0x7fff7fff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lth                  : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 hth                  : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_GLB_PRI_THRSH0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_SRC_CTRL                    0xf4302df0
#define L2TM_L2TE_CB_SRC_CTRL_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 src0_pri_nspid       :  3 ; /* bits 2:0 */
    u32 src0_pri_en          :  1 ; /* bits 3:3 */
    u32 src1_pri_nspid       :  3 ; /* bits 6:4 */
    u32 src1_pri_en          :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_SRC_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_SRC_PORT_THRSH_PROFILE0     0xf4302df4
#define L2TM_L2TE_CB_SRC_PORT_THRSH_PROFILE0_STRIDE 4
#define L2TM_L2TE_CB_SRC_PORT_THRSH_PROFILE0_COUNT 4
#define L2TM_L2TE_CB_SRC_PORT_THRSH_PROFILE0_dft 0x7fff7fff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lth                  : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 hth                  : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_SRC_PORT_THRSH_PROFILE0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_SRC_PORT_THRSH_SELECT       0xf4302e04
#define L2TM_L2TE_CB_SRC_PORT_THRSH_SELECT_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 thsel0               :  2 ; /* bits 1:0 */
    u32 thsel1               :  2 ; /* bits 3:2 */
    u32 thsel2               :  2 ; /* bits 5:4 */
    u32 thsel3               :  2 ; /* bits 7:6 */
    u32 thsel4               :  2 ; /* bits 9:8 */
    u32 thsel5               :  2 ; /* bits 11:10 */
    u32 thsel6               :  2 ; /* bits 13:12 */
    u32 thsel7               :  2 ; /* bits 15:14 */
    u32 thsel8               :  2 ; /* bits 17:16 */
    u32 thsel9               :  2 ; /* bits 19:18 */
    u32 thsel10              :  2 ; /* bits 21:20 */
    u32 thsel11              :  2 ; /* bits 23:22 */
    u32 thsel12              :  2 ; /* bits 25:24 */
    u32 thsel13              :  2 ; /* bits 27:26 */
    u32 thsel14              :  2 ; /* bits 29:28 */
    u32 thsel15              :  2 ; /* bits 31:30 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_SRC_PORT_THRSH_SELECT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_SRC0_PRI_THRSH0             0xf4302e08
#define L2TM_L2TE_CB_SRC0_PRI_THRSH0_STRIDE      4
#define L2TM_L2TE_CB_SRC0_PRI_THRSH0_COUNT       8
#define L2TM_L2TE_CB_SRC0_PRI_THRSH0_dft         0x7fff7fff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lth                  : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 hth                  : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_SRC0_PRI_THRSH0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_SRC1_PRI_THRSH0             0xf4302e28
#define L2TM_L2TE_CB_SRC1_PRI_THRSH0_STRIDE      4
#define L2TM_L2TE_CB_SRC1_PRI_THRSH0_COUNT       8
#define L2TM_L2TE_CB_SRC1_PRI_THRSH0_dft         0x7fff7fff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lth                  : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 hth                  : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_SRC1_PRI_THRSH0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_SRC_PORT_BUFCNT_MEM_ACCESS  0xf4302e48
#define L2TM_L2TE_CB_SRC_PORT_BUFCNT_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 26 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_SRC_PORT_BUFCNT_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_SRC_PORT_BUFCNT_MEM_DATA    0xf4302e4c
#define L2TM_L2TE_CB_SRC_PORT_BUFCNT_MEM_DATA_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt0                 : 15 ; /* bits 14:0 */
    u32 rsrvd1               : 17 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_SRC_PORT_BUFCNT_MEM_DATA_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_SRC_PRI_BUFCNT_MEM_ACCESS   0xf4302e50
#define L2TM_L2TE_CB_SRC_PRI_BUFCNT_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 26 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_SRC_PRI_BUFCNT_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_SRC_PRI_BUFCNT_MEM_DATA     0xf4302e54
#define L2TM_L2TE_CB_SRC_PRI_BUFCNT_MEM_DATA_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt0                 : 15 ; /* bits 14:0 */
    u32 rsrvd1               : 17 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_SRC_PRI_BUFCNT_MEM_DATA_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_DQSCH_EQ_PROFILE_THRSH0     0xf4302e58
#define L2TM_L2TE_CB_DQSCH_EQ_PROFILE_THRSH0_dft 0x00007fff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 th0                  : 15 ; /* bits 14:0 */
    u32 rsrvd1               : 17 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_DQSCH_EQ_PROFILE_THRSH0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_DQSCH_PORT_THRSH_PROFILE0   0xf4302e5c
#define L2TM_L2TE_CB_DQSCH_PORT_THRSH_PROFILE0_STRIDE 4
#define L2TM_L2TE_CB_DQSCH_PORT_THRSH_PROFILE0_COUNT 4
#define L2TM_L2TE_CB_DQSCH_PORT_THRSH_PROFILE0_dft 0x7fff7fff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lth                  : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 hth                  : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_DQSCH_PORT_THRSH_PROFILE0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_DQSCH_PORT_THRSH_SELECT     0xf4302e6c
#define L2TM_L2TE_CB_DQSCH_PORT_THRSH_SELECT_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 thsel0               :  2 ; /* bits 1:0 */
    u32 thsel1               :  2 ; /* bits 3:2 */
    u32 thsel2               :  2 ; /* bits 5:4 */
    u32 thsel3               :  2 ; /* bits 7:6 */
    u32 thsel4               :  2 ; /* bits 9:8 */
    u32 thsel5               :  2 ; /* bits 11:10 */
    u32 thsel6               :  2 ; /* bits 13:12 */
    u32 thsel7               :  2 ; /* bits 15:14 */
    u32 thsel8               :  2 ; /* bits 17:16 */
    u32 thsel9               :  2 ; /* bits 19:18 */
    u32 thsel10              :  2 ; /* bits 21:20 */
    u32 thsel11              :  2 ; /* bits 23:22 */
    u32 thsel12              :  2 ; /* bits 25:24 */
    u32 thsel13              :  2 ; /* bits 27:26 */
    u32 thsel14              :  2 ; /* bits 29:28 */
    u32 thsel15              :  2 ; /* bits 31:30 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_DQSCH_PORT_THRSH_SELECT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_DQSCH_VOQ_THRSH_PROFILE_MEM_ACCESS 0xf4302e70
#define L2TM_L2TE_CB_DQSCH_VOQ_THRSH_PROFILE_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  3 ; /* bits 2:0 */
    u32 rsrvd1               : 27 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_DQSCH_VOQ_THRSH_PROFILE_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_DQSCH_VOQ_THRSH_PROFILE_MEM_DATA 0xf4302e74
#define L2TM_L2TE_CB_DQSCH_VOQ_THRSH_PROFILE_MEM_DATA_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lth                  : 15 ; /* bits 14:0 */
    u32 hth                  : 15 ; /* bits 29:15 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_DQSCH_VOQ_THRSH_PROFILE_MEM_DATA_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_DQSCH_VOQ_THRSH_SELECT_MEM_ACCESS 0xf4302e78
#define L2TM_L2TE_CB_DQSCH_VOQ_THRSH_SELECT_MEM_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  7 ; /* bits 6:0 */
    u32 rsrvd1               : 23 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_DQSCH_VOQ_THRSH_SELECT_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_DQSCH_VOQ_THRSH_SELECT_MEM_DATA 0xf4302e7c
#define L2TM_L2TE_CB_DQSCH_VOQ_THRSH_SELECT_MEM_DATA_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sel                  :  3 ; /* bits 2:0 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_DQSCH_VOQ_THRSH_SELECT_MEM_DATA_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_WIFI_CTRL                   0xf4302e80
#define L2TM_L2TE_CB_WIFI_CTRL_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wred_taildrop_dis    :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 15 ;
    u32 backpressure_en      : 12 ; /* bits 27:16 */
    u32 rsrvd2               :  2 ;
    u32 febypass_msk         :  2 ; /* bits 31:30 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_WIFI_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_WIFI_STS                    0xf4302e84
#define L2TM_L2TE_CB_WIFI_STS_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 eq_profile_ov_threshold :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  7 ;
    u32 buffer_ov_threshold  : 12 ; /* bits 19:8 */
    u32 wifi_backpressure_on : 12 ; /* bits 31:20 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_WIFI_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_WIFI_VP0_BUFCNT             0xf4302e88
#define L2TM_L2TE_CB_WIFI_VP0_BUFCNT_STRIDE      4
#define L2TM_L2TE_CB_WIFI_VP0_BUFCNT_COUNT       12
#define L2TM_L2TE_CB_WIFI_VP0_BUFCNT_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 15 ; /* bits 14:0 */
    u32 rsrvd1               : 17 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_WIFI_VP0_BUFCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_WIFI_VP0_BUF_THRSH          0xf4302eb8
#define L2TM_L2TE_CB_WIFI_VP0_BUF_THRSH_STRIDE   4
#define L2TM_L2TE_CB_WIFI_VP0_BUF_THRSH_COUNT    12
#define L2TM_L2TE_CB_WIFI_VP0_BUF_THRSH_dft      0x7fff7fff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lth                  : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 hth                  : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_WIFI_VP0_BUF_THRSH_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_WIFI_EQ_PROFILE_THRSH       0xf4302ee8
#define L2TM_L2TE_CB_WIFI_EQ_PROFILE_THRSH_dft   0x7fff7fff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lth                  : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 hth                  : 15 ; /* bits 30:16 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_WIFI_EQ_PROFILE_THRSH_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_CB_ABR_CTRL                    0xf4302eec
#define L2TM_L2TE_CB_ABR_CTRL_dft                0x7fff7fff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lth                  : 15 ; /* bits 14:0 */
    u32 rsrvd1               :  1 ;
    u32 hth                  : 15 ; /* bits 30:16 */
    u32 drop_en              :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_CB_ABR_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_CTRL                        0xf4302f00
#define L2TM_L2TE_PM_CTRL_dft                    0x000000a0

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt_saturate         :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  3 ;
    u32 mem_saturate         :  1 ; /* bits 4:4 */
    u32 mem_auto_clr_on_read :  1 ; /* bits 5:5 */
    u32 mem_init             :  1 ; /* bits 6:6 */
    u32 mem_disable          :  1 ; /* bits 7:7 */
    u32 rsrvd2               : 24 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_EVENT_CFG_0                 0xf4302f04
#define L2TM_L2TE_PM_EVENT_CFG_0_dft             0x33445550

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt0_lo              :  4 ; /* bits 3:0 */
    u32 cnt0_hi              :  4 ; /* bits 7:4 */
    u32 cnt1_lo              :  4 ; /* bits 11:8 */
    u32 cnt1_hi              :  4 ; /* bits 15:12 */
    u32 cnt2_lo              :  4 ; /* bits 19:16 */
    u32 cnt2_hi              :  4 ; /* bits 23:20 */
    u32 cnt3_lo              :  4 ; /* bits 27:24 */
    u32 cnt3_hi              :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_EVENT_CFG_0_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_STS                         0xf4302f08
#define L2TM_L2TE_PM_STS_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pcnt0_init_done      :  1 ; /* bits 0:0 */
    u32 pcnt1_init_done      :  1 ; /* bits 1:1 */
    u32 bcnt0_init_done      :  1 ; /* bits 2:2 */
    u32 bcnt1_init_done      :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_STS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_PCNT                        0xf4302f0c
#define L2TM_L2TE_PM_PCNT_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_PCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_PRE_MARK_PCNT               0xf4302f10
#define L2TM_L2TE_PM_PRE_MARK_PCNT_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_PRE_MARK_PCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_POL_DROP_PCNT               0xf4302f14
#define L2TM_L2TE_PM_POL_DROP_PCNT_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_POL_DROP_PCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_TAIL_DROP_PCNT              0xf4302f18
#define L2TM_L2TE_PM_TAIL_DROP_PCNT_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_TAIL_DROP_PCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_WRED_Y_DROP_PCNT            0xf4302f1c
#define L2TM_L2TE_PM_WRED_Y_DROP_PCNT_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_WRED_Y_DROP_PCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_WRED_G_DROP_PCNT            0xf4302f20
#define L2TM_L2TE_PM_WRED_G_DROP_PCNT_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_WRED_G_DROP_PCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_MARK_PCNT                   0xf4302f24
#define L2TM_L2TE_PM_MARK_PCNT_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_MARK_PCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_POL_MARK_PCNT               0xf4302f28
#define L2TM_L2TE_PM_POL_MARK_PCNT_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_POL_MARK_PCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_BYPASS_PCNT                 0xf4302f2c
#define L2TM_L2TE_PM_BYPASS_PCNT_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_BYPASS_PCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_BYPASS_FLOW_PCNT            0xf4302f30
#define L2TM_L2TE_PM_BYPASS_FLOW_PCNT_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_BYPASS_FLOW_PCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_CE_PCNT                     0xf4302f34
#define L2TM_L2TE_PM_CE_PCNT_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_CE_PCNT_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_CNT_MEM_ACCESS              0xf4302f38
#define L2TM_L2TE_PM_CNT_MEM_ACCESS_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 22 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_CNT_MEM_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_CNT_MEM_DATA8               0xf4302f3c
#define L2TM_L2TE_PM_CNT_MEM_DATA8_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt7                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_CNT_MEM_DATA8_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_CNT_MEM_DATA7               0xf4302f40
#define L2TM_L2TE_PM_CNT_MEM_DATA7_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt6                 : 12 ; /* bits 11:0 */
    u32 cnt7                 : 20 ; /* bits 31:12 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_CNT_MEM_DATA7_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_CNT_MEM_DATA6               0xf4302f44
#define L2TM_L2TE_PM_CNT_MEM_DATA6_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt5                 :  8 ; /* bits 7:0 */
    u32 cnt6                 : 24 ; /* bits 31:8 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_CNT_MEM_DATA6_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_CNT_MEM_DATA5               0xf4302f48
#define L2TM_L2TE_PM_CNT_MEM_DATA5_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt4                 :  4 ; /* bits 3:0 */
    u32 cnt5                 : 28 ; /* bits 31:4 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_CNT_MEM_DATA5_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_CNT_MEM_DATA4               0xf4302f4c
#define L2TM_L2TE_PM_CNT_MEM_DATA4_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt4                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_CNT_MEM_DATA4_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_CNT_MEM_DATA3               0xf4302f50
#define L2TM_L2TE_PM_CNT_MEM_DATA3_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt3                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_CNT_MEM_DATA3_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_CNT_MEM_DATA2               0xf4302f54
#define L2TM_L2TE_PM_CNT_MEM_DATA2_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt2                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_CNT_MEM_DATA2_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_CNT_MEM_DATA1               0xf4302f58
#define L2TM_L2TE_PM_CNT_MEM_DATA1_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt1                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_CNT_MEM_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define L2TM_L2TE_PM_CNT_MEM_DATA0               0xf4302f5c
#define L2TM_L2TE_PM_CNT_MEM_DATA0_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt0                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} L2TM_L2TE_PM_CNT_MEM_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXIM2_CONFIG                          0xf4306000
#define QM_AXIM2_CONFIG_dft                      0x00000200

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 axi_write_outtrans_num :  4 ; /* bits 3:0 */
    u32 axi_read_outtrans_num :  4 ; /* bits 7:4 */
    u32 axi_xbus_len         :  3 ; /* bits 10:8 */
    u32 write_cacheline_trans_en :  1 ; /* bits 11:11 */
    u32 write_cacheline_trans_size :  1 ; /* bits 12:12 */
    u32 read_cacheline_trans_en :  1 ; /* bits 13:13 */
    u32 read_cacheline_trans_size :  1 ; /* bits 14:14 */
    u32 arcache_eos_en       :  1 ; /* bits 15:15 */
    u32 awcache_eos_en       :  1 ; /* bits 16:16 */
    u32 reserved             : 15 ; /* bits 31:17 */
  } bf ;
  u32     wrd ;
} QM_AXIM2_CONFIG_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXIM2_TIMEOUT_THRESHOLD               0xf4306004
#define QM_AXIM2_TIMEOUT_THRESHOLD_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 read_channel_threshold :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  3 ;
    u32 write_channel_threshold :  1 ; /* bits 4:4 */
    u32 rsrvd2               : 27 ;
  } bf ;
  u32     wrd ;
} QM_AXIM2_TIMEOUT_THRESHOLD_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXIM2_INTERRUPT_STATUS                0xf4306008
#define QM_AXIM2_INTERRUPT_STATUS_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 read_trans_resp_timeout_int :  1 ; /* bits 0:0 */
    u32 read_trans_resp_err_int :  1 ; /* bits 1:1 */
    u32 write_trans_resp_timeout_int :  1 ; /* bits 2:2 */
    u32 write_trans_resp_err_int :  1 ; /* bits 3:3 */
    u32 read_trans_resp_ace_err_int :  1 ; /* bits 4:4 */
    u32 rsrvd1               : 27 ;
  } bf ;
  u32     wrd ;
} QM_AXIM2_INTERRUPT_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXIM2_INTERRUPT_ENABLE                0xf430600c
#define QM_AXIM2_INTERRUPT_ENABLE_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 read_trans_resp_timeout_int_en :  1 ; /* bits 0:0 */
    u32 read_trans_resp_err_int_en :  1 ; /* bits 1:1 */
    u32 write_trans_resp_timeout_int_en :  1 ; /* bits 2:2 */
    u32 write_trans_resp_err_int_en :  1 ; /* bits 3:3 */
    u32 read_trans_resp_ace_err_int_en :  1 ; /* bits 4:4 */
    u32 rsrvd1               : 27 ;
  } bf ;
  u32     wrd ;
} QM_AXIM2_INTERRUPT_ENABLE_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_REVISION                           0xf4306100
#define QM_QM_REVISION_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 minor                : 16 ; /* bits 15:0 */
    u32 major                : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} QM_QM_REVISION_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_RMU0_CTRL                          0xf4306104
#define QM_QM_RMU0_CTRL_dft                      0x80000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 voq_drop_voqid       :  9 ; /* bits 8:0 */
    u32 rsrvd1               :  1 ;
    u32 voq_drop_en          :  2 ; /* bits 11:10 */
    u32 rsrvd2               :  4 ;
    u32 no_buf_drop_prevention_ths :  2 ; /* bits 17:16 */
    u32 rsrvd3               :  1 ;
    u32 no_buf_drop_prevention_en :  1 ; /* bits 19:19 */
    u32 rx_performance_tuning_timeout_ths :  2 ; /* bits 21:20 */
    u32 rsrvd4               :  2 ;
    u32 febypass_msk         :  2 ; /* bits 25:24 */
    u32 rsrvd5               :  3 ;
    u32 rx_performance_tuning_en :  1 ; /* bits 29:29 */
    u32 stop_rx_en           :  1 ; /* bits 30:30 */
    u32 rx_en                :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_RMU0_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_ES_CTRL                            0xf4306108
#define QM_QM_ES_CTRL_dft                        0x0664ffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cpu_en               :  8 ; /* bits 7:0 */
    u32 ni_en                :  8 ; /* bits 15:8 */
    u32 inccfg_for_pkt_cntrs :  3 ; /* bits 18:16 */
    u32 rsrvd1               :  1 ;
    u32 inccfg_for_err_cntrs :  3 ; /* bits 22:20 */
    u32 rsrvd2               :  1 ;
    u32 crc_err_bypass       :  1 ; /* bits 24:24 */
    u32 crc_en               :  1 ; /* bits 25:25 */
    u32 cpuepp_wait_timer_max :  2 ; /* bits 27:26 */
    u32 bw_relocation_en     :  1 ; /* bits 28:28 */
    u32 bw_relocation_cpu_en :  1 ; /* bits 29:29 */
    u32 tx_performance_tuning_en :  1 ; /* bits 30:30 */
    u32 tx_en                :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_ES_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_ES_CTRL1                           0xf430610c
#define QM_QM_ES_CTRL1_dft                       0x0000ffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 puc_en               : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_ES_CTRL1_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EPP64_P3_0_INTERRUPT_EN            0xf4306110
#define QM_QM_EPP64_P3_0_INTERRUPT_EN_dft        0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p0_int_en            :  8 ; /* bits 7:0 */
    u32 p1_int_en            :  8 ; /* bits 15:8 */
    u32 p2_int_en            :  8 ; /* bits 23:16 */
    u32 p3_int_en            :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} QM_QM_EPP64_P3_0_INTERRUPT_EN_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EPP64_P7_4_INTERRUPT_EN            0xf4306114
#define QM_QM_EPP64_P7_4_INTERRUPT_EN_dft        0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p4_int_en            :  8 ; /* bits 7:0 */
    u32 p5_int_en            :  8 ; /* bits 15:8 */
    u32 p6_int_en            :  8 ; /* bits 23:16 */
    u32 p7_int_en            :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} QM_QM_EPP64_P7_4_INTERRUPT_EN_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ_REFILL_INTERRUPT_EN             0xf4306118
#define QM_QM_EQ_REFILL_INTERRUPT_EN_dft         0x0000ffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 eq_refill_en         : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_EQ_REFILL_INTERRUPT_EN_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_INT_SRC                            0xf430611c
#define QM_QM_INT_SRC_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 header_ecc_error_int_src :  2 ; /* bits 1:0 */
    u32 voqinfo_ecc_error_int_src :  2 ; /* bits 3:2 */
    u32 mmu_ecc_error_int_src :  2 ; /* bits 5:4 */
    u32 sop_eop_error_int_src :  1 ; /* bits 6:6 */
    u32 pkt_lenght_error_int_src :  1 ; /* bits 7:7 */
    u32 rmu0_no_buffer_drop_int_src :  1 ; /* bits 8:8 */
    u32 rmu0_check_error_int_src :  1 ; /* bits 9:9 */
    u32 rmu0_fifo_error_int_src :  1 ; /* bits 10:10 */
    u32 axiarb_fifo_error_int_src :  1 ; /* bits 11:11 */
    u32 dqm_no_buffer_drop_int_src :  1 ; /* bits 12:12 */
    u32 dqm_fe_drop_int_src  :  1 ; /* bits 13:13 */
    u32 dqm_fifo_error_int_src :  1 ; /* bits 14:14 */
    u32 eq_load_error_int_src :  1 ; /* bits 15:15 */
    u32 eqm_fifo_error_int_src :  1 ; /* bits 16:16 */
    u32 eqm_stack_error_int_src :  1 ; /* bits 17:17 */
    u32 tmu_fifo_error_int_src :  1 ; /* bits 18:18 */
    u32 tmu_header_error_int_src :  1 ; /* bits 19:19 */
    u32 cpuepp_fifo_error_int_src :  1 ; /* bits 20:20 */
    u32 eqm_buf_size_error_int_src :  1 ; /* bits 21:21 */
    u32 eqm_cfg_error_int_src :  1 ; /* bits 22:22 */
    u32 ni_bridge_fifo_error_int_src :  1 ; /* bits 23:23 */
    u32 tmu_cfg_error_int_src :  1 ; /* bits 24:24 */
    u32 mmu_lkup_bid_out_of_range_int_src :  1 ; /* bits 25:25 */
    u32 eq_overflow_int_src  :  1 ; /* bits 26:26 */
    u32 cpu_push_invalid_eq_int_src :  1 ; /* bits 27:27 */
    u32 fbm_returns_no_buffer_int_src :  1 ; /* bits 28:28 */
    u32 axim_rmu0_resp_error_int_src :  1 ; /* bits 29:29 */
    u32 axim_cpuepp_resp_error_int_src :  1 ; /* bits 30:30 */
    u32 axim_qm_int_src      :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_INT_SRC_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_INT_SRCE                           0xf4306120
#define QM_QM_INT_SRCE_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 header_ecc_error_int_srcE :  2 ; /* bits 1:0 */
    u32 voqinfo_ecc_error_int_srcE :  2 ; /* bits 3:2 */
    u32 mmu_ecc_error_int_srcE :  2 ; /* bits 5:4 */
    u32 sop_eop_error_int_srcE :  1 ; /* bits 6:6 */
    u32 pkt_lenght_error_int_srcE :  1 ; /* bits 7:7 */
    u32 rmu0_no_buffer_drop_int_srcE :  1 ; /* bits 8:8 */
    u32 rmu0_check_error_int_srcE :  1 ; /* bits 9:9 */
    u32 rmu0_fifo_error_int_srcE :  1 ; /* bits 10:10 */
    u32 axiarb_fifo_error_int_srcE :  1 ; /* bits 11:11 */
    u32 dqm_no_buffer_drop_int_srcE :  1 ; /* bits 12:12 */
    u32 dqm_fe_drop_int_srcE :  1 ; /* bits 13:13 */
    u32 dqm_fifo_error_int_srcE :  1 ; /* bits 14:14 */
    u32 eq_load_error_int_srcE :  1 ; /* bits 15:15 */
    u32 eqm_fifo_error_int_srcE :  1 ; /* bits 16:16 */
    u32 eqm_stack_error_int_srcE :  1 ; /* bits 17:17 */
    u32 tmu_fifo_error_int_srcE :  1 ; /* bits 18:18 */
    u32 tmu_header_error_int_srcE :  1 ; /* bits 19:19 */
    u32 cpuepp_fifo_error_int_srcE :  1 ; /* bits 20:20 */
    u32 eqm_buf_size_error_int_srcE :  1 ; /* bits 21:21 */
    u32 eqm_cfg_error_int_srcE :  1 ; /* bits 22:22 */
    u32 ni_bridge_fifo_error_int_srcE :  1 ; /* bits 23:23 */
    u32 tmu_cfg_error_int_srcE :  1 ; /* bits 24:24 */
    u32 mmu_lkup_bid_out_of_range_int_srcE :  1 ; /* bits 25:25 */
    u32 eq_overflow_int_srcE :  1 ; /* bits 26:26 */
    u32 cpu_push_invalid_eq_int_srcE :  1 ; /* bits 27:27 */
    u32 fbm_returns_no_buffer_int_srcE :  1 ; /* bits 28:28 */
    u32 axim_rmu0_resp_error_int_srcE :  1 ; /* bits 29:29 */
    u32 axim_cpuepp_resp_error_int_srcE :  1 ; /* bits 30:30 */
    u32 axim_qm_int_srcE     :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_INT_SRCE_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_AXI_QOS_CFG                        0xf4306124
#define QM_QM_AXI_QOS_CFG_dft                    0x0f240000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               : 16 ;
    u32 axi_id_rmu           :  4 ; /* bits 19:16 */
    u32 axi_id_cpuepp        :  4 ; /* bits 23:20 */
    u32 axi_id_tmu           :  4 ; /* bits 27:24 */
    u32 rsrvd2               :  4 ;
  } bf ;
  u32     wrd ;
} QM_QM_AXI_QOS_CFG_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ_PROFILE0                        0xf4306128
#define QM_QM_EQ_PROFILE0_STRIDE                 4
#define QM_QM_EQ_PROFILE0_COUNT                  8
#define QM_QM_EQ_PROFILE0_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 eqp0                 :  4 ; /* bits 3:0 */
    u32 eqp1                 :  4 ; /* bits 7:4 */
    u32 rsrvd1               : 23 ;
    u32 rule                 :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ_PROFILE0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEST_PORT0_EQ_CFG                  0xf4306148
#define QM_QM_DEST_PORT0_EQ_CFG_STRIDE           4
#define QM_QM_DEST_PORT0_EQ_CFG_COUNT            32
#define QM_QM_DEST_PORT0_EQ_CFG_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 profile_sel          :  3 ; /* bits 2:0 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} QM_QM_DEST_PORT0_EQ_CFG_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEST_PORT0_PKT_BUF_CFG             0xf43061c8
#define QM_QM_DEST_PORT0_PKT_BUF_CFG_STRIDE      4
#define QM_QM_DEST_PORT0_PKT_BUF_CFG_COUNT       8
#define QM_QM_DEST_PORT0_PKT_BUF_CFG_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 head_room_first      :  6 ; /* bits 5:0 */
    u32 rsrvd1               :  2 ;
    u32 tail_room_first      :  6 ; /* bits 13:8 */
    u32 rsrvd2               :  2 ;
    u32 head_room_rest       :  6 ; /* bits 21:16 */
    u32 rsrvd3               :  2 ;
    u32 tail_room_rest       :  6 ; /* bits 29:24 */
    u32 rsrvd4               :  2 ;
  } bf ;
  u32     wrd ;
} QM_QM_DEST_PORT0_PKT_BUF_CFG_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CFG0_EQ0                           0xf43061e8
#define QM_QM_CFG0_EQ0_STRIDE                    20
#define QM_QM_CFG0_EQ0_COUNT                     16
#define QM_QM_CFG0_EQ0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 eq_en                :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  6 ;
    u32 phy_addr_start       : 25 ; /* bits 31:7 */
  } bf ;
  u32     wrd ;
} QM_QM_CFG0_EQ0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CFG1_EQ0                           0xf43061ec
#define QM_QM_CFG1_EQ0_STRIDE                    20
#define QM_QM_CFG1_EQ0_COUNT                     16
#define QM_QM_CFG1_EQ0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bid_start            : 14 ; /* bits 13:0 */
    u32 rsrvd1               :  2 ;
    u32 total_buffer_num     : 14 ; /* bits 29:16 */
    u32 rsrvd2               :  2 ;
  } bf ;
  u32     wrd ;
} QM_QM_CFG1_EQ0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CFG2_EQ0                           0xf43061f0
#define QM_QM_CFG2_EQ0_STRIDE                    20
#define QM_QM_CFG2_EQ0_COUNT                     16
#define QM_QM_CFG2_EQ0_dft                       0x0000ff01

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 buffer_size          :  3 ; /* bits 2:0 */
    u32 cpu_eq               :  1 ; /* bits 3:3 */
    u32 refill_fbm_eqid      :  3 ; /* bits 6:4 */
    u32 refill_en            :  1 ; /* bits 7:7 */
    u32 refill_ths           :  8 ; /* bits 15:8 */
    u32 buffer_weight        :  3 ; /* bits 18:16 */
    u32 rsrvd1               : 13 ;
  } bf ;
  u32     wrd ;
} QM_QM_CFG2_EQ0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CFG3_EQ0                           0xf43061f4
#define QM_QM_CFG3_EQ0_STRIDE                    20
#define QM_QM_CFG3_EQ0_COUNT                     16
#define QM_QM_CFG3_EQ0_dft                       0x10000010

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qos                  :  4 ; /* bits 3:0 */
    u32 cache                :  4 ; /* bits 7:4 */
    u32 snoop                :  4 ; /* bits 11:8 */
    u32 bar                  :  2 ; /* bits 13:12 */
    u32 domain               :  2 ; /* bits 15:14 */
    u32 user                 :  6 ; /* bits 21:16 */
    u32 rsrvd1               :  2 ;
    u32 acd_cmd              :  1 ; /* bits 24:24 */
    u32 cache_line_split     :  1 ; /* bits 25:25 */
    u32 rsrvd2               :  2 ;
    u32 cache_eos            :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} QM_QM_CFG3_EQ0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CFG4_EQ0                           0xf43061f8
#define QM_QM_CFG4_EQ0_STRIDE                    20
#define QM_QM_CFG4_EQ0_COUNT                     16
#define QM_QM_CFG4_EQ0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 axi_top_bit          :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} QM_QM_CFG4_EQ0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQM_PA_REQ0                        0xf4306328
#define QM_QM_EQM_PA_REQ0_STRIDE                 4
#define QM_QM_EQM_PA_REQ0_COUNT                  16
#define QM_QM_EQM_PA_REQ0_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 inactive_bid_cntr    : 14 ; /* bits 13:0 */
    u32 rsrvd1               : 17 ;
    u32 req                  :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_EQM_PA_REQ0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CPU_PUSH_RDY0                      0xf4306368
#define QM_QM_CPU_PUSH_RDY0_STRIDE               8
#define QM_QM_CPU_PUSH_RDY0_COUNT                8
#define QM_QM_CPU_PUSH_RDY0_dft                  0x80000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               : 31 ;
    u32 rdy                  :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_CPU_PUSH_RDY0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CPU_PUSH_PADDR0                    0xf430636c
#define QM_QM_CPU_PUSH_PADDR0_STRIDE             8
#define QM_QM_CPU_PUSH_PADDR0_COUNT              8
#define QM_QM_CPU_PUSH_PADDR0_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 eqid                 :  4 ; /* bits 3:0 */
    u32 rsrvd1               :  3 ;
    u32 addr                 : 25 ; /* bits 31:7 */
  } bf ;
  u32     wrd ;
} QM_QM_CPU_PUSH_PADDR0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ_CFG_LOAD                        0xf43063a8
#define QM_QM_EQ_CFG_LOAD_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 load                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_EQ_CFG_LOAD_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ_PHY_ADDR_RETURN_CTRL            0xf43063ac
#define QM_QM_EQ_PHY_ADDR_RETURN_CTRL_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 eq_id                :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 27 ;
    u32 phy_addr_retrieval_en :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ_PHY_ADDR_RETURN_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ_RETURN_PHY_ADDR                 0xf43063b0
#define QM_QM_EQ_RETURN_PHY_ADDR_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 eq_id                :  4 ; /* bits 3:0 */
    u32 valid                :  1 ; /* bits 4:4 */
    u32 retrieval_done       :  1 ; /* bits 5:5 */
    u32 rsrvd1               :  1 ;
    u32 phy_addr             : 25 ; /* bits 31:7 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ_RETURN_PHY_ADDR_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_ACTIVE_STACK_CFG                   0xf43063b4
#define QM_QM_ACTIVE_STACK_CFG_dft               0x001a1410

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 low_ths              :  5 ; /* bits 4:0 */
    u32 rsrvd1               :  3 ;
    u32 mid_ths              :  5 ; /* bits 12:8 */
    u32 rsrvd2               :  3 ;
    u32 high_ths             :  5 ; /* bits 20:16 */
    u32 rsrvd3               : 11 ;
  } bf ;
  u32     wrd ;
} QM_QM_ACTIVE_STACK_CFG_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_INACTIVE_STACK_CFG                 0xf43063b8
#define QM_QM_INACTIVE_STACK_CFG_dft             0x001a1410

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 low_ths              :  5 ; /* bits 4:0 */
    u32 rsrvd1               :  3 ;
    u32 mid_ths              :  5 ; /* bits 12:8 */
    u32 rsrvd2               :  3 ;
    u32 high_ths             :  5 ; /* bits 20:16 */
    u32 rsrvd3               : 11 ;
  } bf ;
  u32     wrd ;
} QM_QM_INACTIVE_STACK_CFG_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ_STACK_CTRL                      0xf43063bc
#define QM_QM_EQ_STACK_CTRL_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 stack_unfill         : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_EQ_STACK_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ_STACK_UNFILL_STS                0xf43063c0
#define QM_QM_EQ_STACK_UNFILL_STS_dft            0x0000ffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 done                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_EQ_STACK_UNFILL_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_SCH_CFG0                           0xf43063c4
#define QM_QM_SCH_CFG0_STRIDE                    4
#define QM_QM_SCH_CFG0_COUNT                     32
#define QM_QM_SCH_CFG0_dft                       0x000000ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 voq_en               :  8 ; /* bits 7:0 */
    u32 flush_voqid          :  3 ; /* bits 10:8 */
    u32 rsrvd1               :  4 ;
    u32 flush_en             :  1 ; /* bits 15:15 */
    u32 rsrvd2               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_SCH_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ3_0_WEIGHT_RATIO_CFG0           0xf4306444
#define QM_QM_VOQ3_0_WEIGHT_RATIO_CFG0_STRIDE    8
#define QM_QM_VOQ3_0_WEIGHT_RATIO_CFG0_COUNT     32
#define QM_QM_VOQ3_0_WEIGHT_RATIO_CFG0_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 voq0                 :  8 ; /* bits 7:0 */
    u32 voq1                 :  8 ; /* bits 15:8 */
    u32 voq2                 :  8 ; /* bits 23:16 */
    u32 voq3                 :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ3_0_WEIGHT_RATIO_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ7_4_WEIGHT_RATIO_CFG0           0xf4306448
#define QM_QM_VOQ7_4_WEIGHT_RATIO_CFG0_STRIDE    8
#define QM_QM_VOQ7_4_WEIGHT_RATIO_CFG0_COUNT     32
#define QM_QM_VOQ7_4_WEIGHT_RATIO_CFG0_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 voq4                 :  8 ; /* bits 7:0 */
    u32 voq5                 :  8 ; /* bits 15:8 */
    u32 voq6                 :  8 ; /* bits 23:16 */
    u32 voq7                 :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ7_4_WEIGHT_RATIO_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_PORT7_0_WEIGHT_RATIO_CFG           0xf4306544
#define QM_QM_PORT7_0_WEIGHT_RATIO_CFG_dft       0x11111111

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port0                :  4 ; /* bits 3:0 */
    u32 port1                :  4 ; /* bits 7:4 */
    u32 port2                :  4 ; /* bits 11:8 */
    u32 port3                :  4 ; /* bits 15:12 */
    u32 port4                :  4 ; /* bits 19:16 */
    u32 port5                :  4 ; /* bits 23:20 */
    u32 port6                :  4 ; /* bits 27:24 */
    u32 port7                :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} QM_QM_PORT7_0_WEIGHT_RATIO_CFG_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_PORT15_8_WEIGHT_RATIO_CFG          0xf4306548
#define QM_QM_PORT15_8_WEIGHT_RATIO_CFG_dft      0x11111111

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port8                :  4 ; /* bits 3:0 */
    u32 port9                :  4 ; /* bits 7:4 */
    u32 port10               :  4 ; /* bits 11:8 */
    u32 port11               :  4 ; /* bits 15:12 */
    u32 port12               :  4 ; /* bits 19:16 */
    u32 port13               :  4 ; /* bits 23:20 */
    u32 port14               :  4 ; /* bits 27:24 */
    u32 port15               :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} QM_QM_PORT15_8_WEIGHT_RATIO_CFG_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_PORT23_16_WEIGHT_RATIO_CFG         0xf430654c
#define QM_QM_PORT23_16_WEIGHT_RATIO_CFG_dft     0x11111111

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port16               :  4 ; /* bits 3:0 */
    u32 port17               :  4 ; /* bits 7:4 */
    u32 port18               :  4 ; /* bits 11:8 */
    u32 port19               :  4 ; /* bits 15:12 */
    u32 port20               :  4 ; /* bits 19:16 */
    u32 port21               :  4 ; /* bits 23:20 */
    u32 port22               :  4 ; /* bits 27:24 */
    u32 port23               :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} QM_QM_PORT23_16_WEIGHT_RATIO_CFG_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_PORT31_24_WEIGHT_RATIO_CFG         0xf4306550
#define QM_QM_PORT31_24_WEIGHT_RATIO_CFG_dft     0x11111111

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port24               :  4 ; /* bits 3:0 */
    u32 port25               :  4 ; /* bits 7:4 */
    u32 port26               :  4 ; /* bits 11:8 */
    u32 port27               :  4 ; /* bits 15:12 */
    u32 port28               :  4 ; /* bits 19:16 */
    u32 port29               :  4 ; /* bits 23:20 */
    u32 port30               :  4 ; /* bits 27:24 */
    u32 port31               :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} QM_QM_PORT31_24_WEIGHT_RATIO_CFG_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DRR_WEIGHT_BASE                    0xf4306554
#define QM_QM_DRR_WEIGHT_BASE_dft                0x00040114

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 w_rate               :  5 ; /* bits 4:0 */
    u32 rsrvd1               :  3 ;
    u32 base_select          :  2 ; /* bits 9:8 */
    u32 rsrvd2               :  6 ;
    u32 cpu_dwrr_unit        :  1 ; /* bits 16:16 */
    u32 ni_dwrr_unit         :  1 ; /* bits 17:17 */
    u32 cpu_epp256_dwrr_unit :  1 ; /* bits 18:18 */
    u32 rsrvd3               : 13 ;
  } bf ;
  u32     wrd ;
} QM_QM_DRR_WEIGHT_BASE_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CPU_EPP0_CFG                       0xf4306558
#define QM_QM_CPU_EPP0_CFG_STRIDE                4
#define QM_QM_CPU_EPP0_CFG_COUNT                 8
#define QM_QM_CPU_EPP0_CFG_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 map_mode             :  3 ; /* bits 2:0 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} QM_QM_CPU_EPP0_CFG_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CPU_EPP_CT_CFG                     0xf4306578
#define QM_QM_CPU_EPP_CT_CFG_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 timer_base           :  2 ; /* bits 1:0 */
    u32 timer_base_256       :  2 ; /* bits 3:2 */
    u32 axi_req_accu         :  2 ; /* bits 5:4 */
    u32 rsrvd1               : 26 ;
  } bf ;
  u32     wrd ;
} QM_QM_CPU_EPP_CT_CFG_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CPU_EPP_FIFO_CFG_profile0          0xf430657c
#define QM_QM_CPU_EPP_FIFO_CFG_profile0_STRIDE   4
#define QM_QM_CPU_EPP_FIFO_CFG_profile0_COUNT    8
#define QM_QM_CPU_EPP_FIFO_CFG_profile0_dft      0xe0008001

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 high_ths             :  4 ; /* bits 3:0 */
    u32 timer_ths            :  4 ; /* bits 7:4 */
    u32 size                 : 21 ; /* bits 28:8 */
    u32 max_buf_cnt_per_pkt  :  3 ; /* bits 31:29 */
  } bf ;
  u32     wrd ;
} QM_QM_CPU_EPP_FIFO_CFG_profile0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CPU_EPP_STATUS0                    0xf430659c
#define QM_QM_CPU_EPP_STATUS0_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_CPU_EPP_STATUS0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CPU_EPP_STATUS1                    0xf43065a0
#define QM_QM_CPU_EPP_STATUS1_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_CPU_EPP_STATUS1_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CPU_EPP_FIFO0_0_CFG                0xf43065a4
#define QM_QM_CPU_EPP_FIFO0_0_CFG_STRIDE         32
#define QM_QM_CPU_EPP_FIFO0_0_CFG_COUNT          8
#define QM_QM_CPU_EPP_FIFO0_0_CFG_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 profile_sel          :  3 ; /* bits 2:0 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} QM_QM_CPU_EPP_FIFO0_0_CFG_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_AXI_ATTRIBUTE_ACCESS               0xf43066a4
#define QM_QM_AXI_ATTRIBUTE_ACCESS_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ADDR                 :  6 ; /* bits 5:0 */
    u32 rsrvd1               : 24 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_AXI_ATTRIBUTE_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_AXI_ATTRIBUTE_DATA1                0xf43066a8
#define QM_QM_AXI_ATTRIBUTE_DATA1_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 axi_top_bit          :  2 ; /* bits 1:0 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} QM_QM_AXI_ATTRIBUTE_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_AXI_ATTRIBUTE_DATA0                0xf43066ac
#define QM_QM_AXI_ATTRIBUTE_DATA0_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qos                  :  4 ; /* bits 3:0 */
    u32 cache                :  4 ; /* bits 7:4 */
    u32 snoop                :  4 ; /* bits 11:8 */
    u32 bar                  :  2 ; /* bits 13:12 */
    u32 domain               :  2 ; /* bits 15:14 */
    u32 user                 :  6 ; /* bits 21:16 */
    u32 prot                 :  3 ; /* bits 24:22 */
    u32 ace_cmd              :  1 ; /* bits 25:25 */
    u32 axi_top_bit          :  6 ; /* bits 31:26 */
  } bf ;
  u32     wrd ;
} QM_QM_AXI_ATTRIBUTE_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_BID_PADDR_LKUP_ACCESS              0xf43066b0
#define QM_QM_BID_PADDR_LKUP_ACCESS_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ADDR                 : 13 ; /* bits 12:0 */
    u32 rsrvd1               : 17 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_BID_PADDR_LKUP_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_BID_PADDR_LKUP_DATA                0xf43066b4
#define QM_QM_BID_PADDR_LKUP_DATA_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ecc                  :  6 ; /* bits 5:0 */
    u32 Reserved             :  1 ; /* bits 6:6 */
    u32 phy_addr             : 25 ; /* bits 31:7 */
  } bf ;
  u32     wrd ;
} QM_QM_BID_PADDR_LKUP_DATA_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_INFO_MEMORY_ACCESS             0xf43066b8
#define QM_QM_VOQ_INFO_MEMORY_ACCESS_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ADDR                 :  9 ; /* bits 8:0 */
    u32 rsrvd1               : 21 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_INFO_MEMORY_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_INFO_MEMORY_DATA2              0xf43066bc
#define QM_QM_VOQ_INFO_MEMORY_DATA2_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bcntr                : 11 ; /* bits 10:0 */
    u32 ecc                  :  9 ; /* bits 19:11 */
    u32 sw_id                :  6 ; /* bits 25:20 */
    u32 lspid_bp             :  3 ; /* bits 28:26 */
    u32 rsrvd1               :  3 ;
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_INFO_MEMORY_DATA2_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_INFO_MEMORY_DATA1              0xf43066c0
#define QM_QM_VOQ_INFO_MEMORY_DATA1_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 voq_header           :  1 ; /* bits 0:0 */
    u32 voq_tail             : 14 ; /* bits 14:1 */
    u32 voq_head             : 14 ; /* bits 28:15 */
    u32 bcntr                :  3 ; /* bits 31:29 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_INFO_MEMORY_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_INFO_MEMORY_DATA0              0xf43066c4
#define QM_QM_VOQ_INFO_MEMORY_DATA0_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 voq_header           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_INFO_MEMORY_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_HEADER_MEMORY_ACCESS               0xf43066c8
#define QM_QM_HEADER_MEMORY_ACCESS_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ADDR                 : 14 ; /* bits 13:0 */
    u32 rsrvd1               : 16 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_HEADER_MEMORY_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_HEADER_MEMORY_DATA1                0xf43066cc
#define QM_QM_HEADER_MEMORY_DATA1_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_type_ptp         :  1 ; /* bits 0:0 */
    u32 sw_id                :  6 ; /* bits 6:1 */
    u32 lspid_sp             :  3 ; /* bits 9:7 */
    u32 ecc                  :  7 ; /* bits 16:10 */
    u32 rsrvd1               : 15 ;
  } bf ;
  u32     wrd ;
} QM_QM_HEADER_MEMORY_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_HEADER_MEMORY_DATA0                0xf43066d0
#define QM_QM_HEADER_MEMORY_DATA0_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_length           : 14 ; /* bits 13:0 */
    u32 eop                  :  1 ; /* bits 14:14 */
    u32 sop                  :  1 ; /* bits 15:15 */
    u32 next_buffer_ptr      : 14 ; /* bits 29:16 */
    u32 l4err                :  1 ; /* bits 30:30 */
    u32 pkt_type_cpu         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_HEADER_MEMORY_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_HDM_WRITE_PROTECTION               0xf43066d4
#define QM_QM_HDM_WRITE_PROTECTION_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 passwd               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_HDM_WRITE_PROTECTION_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_MONITOR0_EQ0                       0xf43066d8
#define QM_QM_MONITOR0_EQ0_STRIDE                16
#define QM_QM_MONITOR0_EQ0_COUNT                 16
#define QM_QM_MONITOR0_EQ0_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tail                 : 14 ; /* bits 13:0 */
    u32 rsrvd1               :  2 ;
    u32 head                 : 14 ; /* bits 29:16 */
    u32 rsrvd2               :  2 ;
  } bf ;
  u32     wrd ;
} QM_QM_MONITOR0_EQ0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_MONITOR1_EQ0                       0xf43066dc
#define QM_QM_MONITOR1_EQ0_STRIDE                16
#define QM_QM_MONITOR1_EQ0_COUNT                 16
#define QM_QM_MONITOR1_EQ0_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cntr                 : 14 ; /* bits 13:0 */
    u32 rsrvd1               :  2 ;
    u32 inactive_head        : 14 ; /* bits 29:16 */
    u32 rsrvd2               :  2 ;
  } bf ;
  u32     wrd ;
} QM_QM_MONITOR1_EQ0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_MONITOR2_EQ0                       0xf43066e0
#define QM_QM_MONITOR2_EQ0_STRIDE                16
#define QM_QM_MONITOR2_EQ0_COUNT                 16
#define QM_QM_MONITOR2_EQ0_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 inactive_cntr        : 14 ; /* bits 13:0 */
    u32 rsrvd1               :  2 ;
    u32 inactive_tail        : 14 ; /* bits 29:16 */
    u32 rsrvd2               :  2 ;
  } bf ;
  u32     wrd ;
} QM_QM_MONITOR2_EQ0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_MONITOR3_EQ0                       0xf43066e4
#define QM_QM_MONITOR3_EQ0_STRIDE                16
#define QM_QM_MONITOR3_EQ0_COUNT                 16
#define QM_QM_MONITOR3_EQ0_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 inactive_stack_cntr  :  5 ; /* bits 4:0 */
    u32 rsrvd1               : 11 ;
    u32 stack_cntr           :  5 ; /* bits 20:16 */
    u32 rsrvd2               : 11 ;
  } bf ;
  u32     wrd ;
} QM_QM_MONITOR3_EQ0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_RMU0_RX_PKT_CNTR                   0xf43067d8
#define QM_QM_RMU0_RX_PKT_CNTR_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cntr                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_RMU0_RX_PKT_CNTR_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_RMU0_RX_PACKET_HEADER_INFO1        0xf43067dc
#define QM_QM_RMU0_RX_PACKET_HEADER_INFO1_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 info1                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_RMU0_RX_PACKET_HEADER_INFO1_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_RMU0_RX_PACKET_HEADER_INFO0        0xf43067e0
#define QM_QM_RMU0_RX_PACKET_HEADER_INFO0_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 info0                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_RMU0_RX_PACKET_HEADER_INFO0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_TX_PKT_CNTR                        0xf43067e4
#define QM_QM_TX_PKT_CNTR_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cntr                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_TX_PKT_CNTR_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_TX_PKT_CNTR_ALL_NI                 0xf43067e8
#define QM_QM_TX_PKT_CNTR_ALL_NI_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cntr                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_TX_PKT_CNTR_ALL_NI_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_TX_PKT_CNTR_CPU0                   0xf43067ec
#define QM_QM_TX_PKT_CNTR_CPU0_STRIDE            4
#define QM_QM_TX_PKT_CNTR_CPU0_COUNT             8
#define QM_QM_TX_PKT_CNTR_CPU0_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cntr                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_TX_PKT_CNTR_CPU0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_TX_PACKET_HEADER_INFO1             0xf430680c
#define QM_QM_TX_PACKET_HEADER_INFO1_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 info1                : 10 ; /* bits 9:0 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} QM_QM_TX_PACKET_HEADER_INFO1_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_TX_PACKET_HEADER_INFO0             0xf4306810
#define QM_QM_TX_PACKET_HEADER_INFO0_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 info0                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_TX_PACKET_HEADER_INFO0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_RMU0_NO_BUF_DROP_PKT_INFO          0xf4306814
#define QM_QM_RMU0_NO_BUF_DROP_PKT_INFO_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 eqid                 :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 12 ;
    u32 voqid                :  9 ; /* bits 24:16 */
    u32 rsrvd2               :  7 ;
  } bf ;
  u32     wrd ;
} QM_QM_RMU0_NO_BUF_DROP_PKT_INFO_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_RMU0_NO_BUF_DROP_PKT_CNTR          0xf4306818
#define QM_QM_RMU0_NO_BUF_DROP_PKT_CNTR_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cntr                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_RMU0_NO_BUF_DROP_PKT_CNTR_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_RMU0_FE_DROP_PKT_CNTR              0xf430681c
#define QM_QM_RMU0_FE_DROP_PKT_CNTR_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cntr                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_RMU0_FE_DROP_PKT_CNTR_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_RX_EOP_DROP_CNTR                   0xf4306820
#define QM_QM_RX_EOP_DROP_CNTR_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cntr                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_RX_EOP_DROP_CNTR_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_RX_LEN_CHK_ERROR_CNTR              0xf4306824
#define QM_QM_RX_LEN_CHK_ERROR_CNTR_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cntr                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_RX_LEN_CHK_ERROR_CNTR_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_RX_L2TE_TAIL_DROP_CNTR             0xf4306828
#define QM_QM_RX_L2TE_TAIL_DROP_CNTR_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cntr                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_RX_L2TE_TAIL_DROP_CNTR_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_TX_CRC_ERROR_NI_CNTR               0xf430682c
#define QM_QM_TX_CRC_ERROR_NI_CNTR_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cntr                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_TX_CRC_ERROR_NI_CNTR_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_STATUS0                        0xf4306830
#define QM_QM_VOQ_STATUS0_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_STATUS0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_STATUS1                        0xf4306834
#define QM_QM_VOQ_STATUS1_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_STATUS1_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_STATUS2                        0xf4306838
#define QM_QM_VOQ_STATUS2_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_STATUS2_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_STATUS3                        0xf430683c
#define QM_QM_VOQ_STATUS3_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_STATUS3_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_STATUS4                        0xf4306840
#define QM_QM_VOQ_STATUS4_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_STATUS4_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_STATUS5                        0xf4306844
#define QM_QM_VOQ_STATUS5_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_STATUS5_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_STATUS6                        0xf4306848
#define QM_QM_VOQ_STATUS6_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_STATUS6_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_STATUS7                        0xf430684c
#define QM_QM_VOQ_STATUS7_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_STATUS7_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_PHY_PORT_STS                       0xf4306850
#define QM_QM_PHY_PORT_STS_dft                   0xa5ffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 nirx_qm_port_rdy     :  8 ; /* bits 7:0 */
    u32 te_qm_es_ni_ok       :  8 ; /* bits 15:8 */
    u32 te_qm_es_cpu_ok      :  8 ; /* bits 23:16 */
    u32 qm_nitx_rdy          :  1 ; /* bits 24:24 */
    u32 nitx_qm_vld          :  1 ; /* bits 25:25 */
    u32 nirx_qm_rdy          :  1 ; /* bits 26:26 */
    u32 qm_nirx_vld          :  1 ; /* bits 27:27 */
    u32 axi_write_rdy        :  1 ; /* bits 28:28 */
    u32 axi_read_rdy         :  1 ; /* bits 29:29 */
    u32 qm_init_done         :  1 ; /* bits 30:30 */
    u32 qm_idle              :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_PHY_PORT_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_SUB_MODULE_STS                     0xf4306854
#define QM_QM_SUB_MODULE_STS_dft                 0x00f0bfff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qm_axi_att_idle      :  1 ; /* bits 0:0 */
    u32 qm_intf_idle         :  1 ; /* bits 1:1 */
    u32 qm_eqm_idle          :  1 ; /* bits 2:2 */
    u32 qm_rmu_idle          :  1 ; /* bits 3:3 */
    u32 qm_tmu_idle          :  1 ; /* bits 4:4 */
    u32 qm_cpuepp_idle       :  1 ; /* bits 5:5 */
    u32 qm_dqm_idle          :  1 ; /* bits 6:6 */
    u32 qm_hdm_idle          :  1 ; /* bits 7:7 */
    u32 qm_mmu_idle          :  1 ; /* bits 8:8 */
    u32 qm_ni_bridge_idle    :  1 ; /* bits 9:9 */
    u32 tmu_sch_rdy          :  1 ; /* bits 10:10 */
    u32 epp_sch_rdy          :  1 ; /* bits 11:11 */
    u32 eqm_rmu_rdy          :  1 ; /* bits 12:12 */
    u32 dqm_rmu_rdy          :  1 ; /* bits 13:13 */
    u32 sch_dqm_outstd_req   :  1 ; /* bits 14:14 */
    u32 sch_idle             :  1 ; /* bits 15:15 */
    u32 fsm_dqm_hdm          :  4 ; /* bits 19:16 */
    u32 fsm_dqm_voq_info     :  4 ; /* bits 23:20 */
    u32 qm_tmu_fsm_axi_rd    :  4 ; /* bits 27:24 */
    u32 qm_rmu_fsm_axi_wr    :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} QM_QM_SUB_MODULE_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_RMU0_FIFO_STS                      0xf4306858
#define QM_QM_RMU0_FIFO_STS_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data_fifo_depth      :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  5 ;
    u32 cmd_fifo_depth       :  4 ; /* bits 15:12 */
    u32 cmd_resp_fifo_depth  :  6 ; /* bits 21:16 */
    u32 rsrvd2               :  2 ;
    u32 axi_fifo_depth       :  3 ; /* bits 26:24 */
    u32 header_fifo_depth    :  5 ; /* bits 31:27 */
  } bf ;
  u32     wrd ;
} QM_QM_RMU0_FIFO_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CPUEPP_STS                         0xf430685c
#define QM_QM_CPUEPP_STS_dft                     0x80082020

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 epp_ptr_resp_fifo_depth :  5 ; /* bits 4:0 */
    u32 epp_ptr_resp_fifo_empty :  1 ; /* bits 5:5 */
    u32 epp_ptr_resp_fifo_full :  1 ; /* bits 6:6 */
    u32 rsrvd1               :  1 ;
    u32 eppresp_fifo_depth   :  5 ; /* bits 12:8 */
    u32 eppresp_fifo_empty   :  1 ; /* bits 13:13 */
    u32 eppresp_fifo_full    :  1 ; /* bits 14:14 */
    u32 rsrvd2               :  1 ;
    u32 eppcmd_fifo_depth    :  3 ; /* bits 18:16 */
    u32 eppcmd_fifo_empty    :  1 ; /* bits 19:19 */
    u32 eppcmd_fifo_full     :  1 ; /* bits 20:20 */
    u32 rsrvd3               :  3 ;
    u32 axi_write_state      :  3 ; /* bits 26:24 */
    u32 rsrvd4               :  2 ;
    u32 axi_write_req_wait   :  1 ; /* bits 29:29 */
    u32 axi_write_req        :  1 ; /* bits 30:30 */
    u32 epp_sch_rdy          :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_CPUEPP_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CPUEPP_SM_STS                      0xf4306860
#define QM_QM_CPUEPP_SM_STS_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 paddr_mem_ctrl_state :  3 ; /* bits 2:0 */
    u32 rsrvd1               :  5 ;
    u32 rwptr_mem_ctrl_state :  3 ; /* bits 10:8 */
    u32 rsrvd2               : 21 ;
  } bf ;
  u32     wrd ;
} QM_QM_CPUEPP_SM_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CPUEPP_AXI_CNT_STS                 0xf4306864
#define QM_QM_CPUEPP_AXI_CNT_STS_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gnt_cnt              : 16 ; /* bits 15:0 */
    u32 resp_cnt             : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} QM_QM_CPUEPP_AXI_CNT_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DQM_FIFO_STS                       0xf4306868
#define QM_QM_DQM_FIFO_STS_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dqm_rmureq_fifo_depth :  4 ; /* bits 3:0 */
    u32 dqm_nbrcy_fifo_depth :  4 ; /* bits 7:4 */
    u32 dqmreq_fifo_depth    :  5 ; /* bits 12:8 */
    u32 dqm_fercy_fifo_depth :  3 ; /* bits 15:13 */
    u32 dqmlnk_fifo_depth    :  5 ; /* bits 20:16 */
    u32 rsrvd1               :  3 ;
    u32 dqmresp_fifo_depth   :  6 ; /* bits 29:24 */
    u32 rsrvd2               :  2 ;
  } bf ;
  u32     wrd ;
} QM_QM_DQM_FIFO_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_TMU_FIFO_STS                       0xf430686c
#define QM_QM_TMU_FIFO_STS_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmu_rcy_fifo_depth   :  4 ; /* bits 3:0 */
    u32 txcmd_fifo_depth     :  5 ; /* bits 8:4 */
    u32 rsrvd1               :  7 ;
    u32 tmu_axi_beat_add     : 14 ; /* bits 29:16 */
    u32 rsrvd2               :  2 ;
  } bf ;
  u32     wrd ;
} QM_QM_TMU_FIFO_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_NI_BRIDGE_FIFO_STS                 0xf4306870
#define QM_QM_NI_BRIDGE_FIFO_STS_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 beat                 :  9 ; /* bits 8:0 */
    u32 rsrvd1               :  3 ;
    u32 ni_eop_fifo_depth    :  3 ; /* bits 14:12 */
    u32 ni_wr_pkt            :  1 ; /* bits 15:15 */
    u32 entry                :  8 ; /* bits 23:16 */
    u32 pkt                  :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} QM_QM_NI_BRIDGE_FIFO_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_SPARE_CFG                          0xf4306874
#define QM_QM_SPARE_CFG_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 spare                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_SPARE_CFG_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_SPARE_STS                          0xf4306878
#define QM_QM_SPARE_STS_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 spare                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_SPARE_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEBUG_DATA1                        0xf430687c
#define QM_QM_DEBUG_DATA1_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data1                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_DEBUG_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEBUG_DATA0                        0xf4306880
#define QM_QM_DEBUG_DATA0_dft                    0x80000008

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data0                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_DEBUG_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEBUG_STS0                         0xf4306884
#define QM_QM_DEBUG_STS0_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rmu_eqm_ack_cntr     :  8 ; /* bits 7:0 */
    u32 rmu_lkup_ack_cntr    :  8 ; /* bits 15:8 */
    u32 rmu_hdr_fifo_rd_cntr :  4 ; /* bits 19:16 */
    u32 rsrvd1               :  4 ;
    u32 rmu_axi_fifo_wr_cntr :  4 ; /* bits 27:24 */
    u32 rsrvd2               :  4 ;
  } bf ;
  u32     wrd ;
} QM_QM_DEBUG_STS0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEBUG_STS1                         0xf4306888
#define QM_QM_DEBUG_STS1_dft                     0x00112300

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 fsm_rmu_eqm_req      :  4 ; /* bits 3:0 */
    u32 fsm_axi_wr           :  4 ; /* bits 7:4 */
    u32 eqm_rmu_rdy          :  1 ; /* bits 8:8 */
    u32 dqm_rmu_rdy          :  1 ; /* bits 9:9 */
    u32 rmuhdr_fifo_dout_vld :  1 ; /* bits 10:10 */
    u32 rmuhdr_fifo_rd       :  1 ; /* bits 11:11 */
    u32 rmudata_fifo_dout_vld :  1 ; /* bits 12:12 */
    u32 rmu_fifo_data_rdy    :  1 ; /* bits 13:13 */
    u32 rx_axi_fifo_almost_full :  1 ; /* bits 14:14 */
    u32 rmu_lkup_flag        :  1 ; /* bits 15:15 */
    u32 rx_axi_fifo_empty    :  1 ; /* bits 16:16 */
    u32 lkup_axi_start       :  1 ; /* bits 17:17 */
    u32 rmu_axi_write_rdy    :  1 ; /* bits 18:18 */
    u32 rmu_lkup_pending     :  1 ; /* bits 19:19 */
    u32 qm_fe_rdy            :  1 ; /* bits 20:20 */
    u32 rmudata_fifo_almost_full :  1 ; /* bits 21:21 */
    u32 rmuhdr_fifo_almost_full :  1 ; /* bits 22:22 */
    u32 rsrvd1               :  1 ;
    u32 outstd_axi_cmd_cntr  :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} QM_QM_DEBUG_STS1_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEBUG_STS2                         0xf430688c
#define QM_QM_DEBUG_STS2_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rmu_lkup_bid         : 14 ; /* bits 13:0 */
    u32 rsrvd1               :  2 ;
    u32 ncpu_rmu_rd          : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} QM_QM_DEBUG_STS2_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEBUG_STS3                         0xf4306890
#define QM_QM_DEBUG_STS3_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rmu_lkup_cur_bid     : 14 ; /* bits 13:0 */
    u32 rsrvd1               :  2 ;
    u32 cpu_rmu_rd           : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} QM_QM_DEBUG_STS3_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEBUG_STS4                         0xf4306894
#define QM_QM_DEBUG_STS4_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rmu_lkup_paddr       : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_DEBUG_STS4_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEBUG_STS5                         0xf4306898
#define QM_QM_DEBUG_STS5_dft                     0x08000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni_bridge_eop_cntr   : 16 ; /* bits 15:0 */
    u32 eqm_stack15_cntr     :  5 ; /* bits 20:16 */
    u32 rsrvd1               :  3 ;
    u32 axiatt_tmu_lkup_ack  :  1 ; /* bits 24:24 */
    u32 tmu_axiatt_lkup_req  :  1 ; /* bits 25:25 */
    u32 tmu_axi_strt         :  1 ; /* bits 26:26 */
    u32 qm_ni_bridge_fifo_wr_rdy :  1 ; /* bits 27:27 */
    u32 sch_dqm_req          :  1 ; /* bits 28:28 */
    u32 tmu_tx_vld           :  1 ; /* bits 29:29 */
    u32 axi_att_lkup_ack_flag :  1 ; /* bits 30:30 */
    u32 tmu_eqm_done         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_DEBUG_STS5_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEBUG_STS6                         0xf430689c
#define QM_QM_DEBUG_STS6_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmu_axi_gnt_cntr     : 16 ; /* bits 15:0 */
    u32 dqm_tmu_ack_cntr     : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} QM_QM_DEBUG_STS6_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEBUG_STS7                         0xf43068a0
#define QM_QM_DEBUG_STS7_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmu_axi_eof_cntr     : 16 ; /* bits 15:0 */
    u32 ni_fifo_eop_cntr     : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} QM_QM_DEBUG_STS7_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEBUG_STS8                         0xf43068a4
#define QM_QM_DEBUG_STS8_dft                     0x000000ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmu_axi_wr_ths       : 10 ; /* bits 9:0 */
    u32 rsrvd1               : 18 ;
    u32 ni_bridge_drain_pid  :  3 ; /* bits 30:28 */
    u32 ni_bridge_drain_en   :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_QM_DEBUG_STS8_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEBUG_STS9                         0xf43068a8
#define QM_QM_DEBUG_STS9_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmu_axi_beat_add_max : 16 ; /* bits 15:0 */
    u32 tmu_axi_beat_add     : 14 ; /* bits 29:16 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} QM_QM_DEBUG_STS9_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEBUG_STS10                        0xf43068ac
#define QM_QM_DEBUG_STS10_dft                    0xdead0419

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rmu_test             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_DEBUG_STS10_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_BUFFER_CNTL                        0xf43068b0
#define QM_QM_BUFFER_CNTL_dft                    0x1034b2ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port_speed_select    :  8 ; /* bits 7:0 */
    u32 occupied_buffer_ths  :  3 ; /* bits 10:8 */
    u32 rsrvd1               :  1 ;
    u32 minimum_bytes        :  3 ; /* bits 14:12 */
    u32 low_latency_en       :  1 ; /* bits 15:15 */
    u32 eq_profile_rule0_eqp0_limit :  4 ; /* bits 19:16 */
    u32 timer_divider_constant :  6 ; /* bits 25:20 */
    u32 multi_axi_wr_id_en   :  1 ; /* bits 26:26 */
    u32 alternate_eq_en      :  1 ; /* bits 27:27 */
    u32 tmu_burst_size       :  2 ; /* bits 29:28 */
    u32 jumbo_buffer_en      :  2 ; /* bits 31:30 */
  } bf ;
  u32     wrd ;
} QM_QM_BUFFER_CNTL_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_LATENCY_TIMER_CFG                  0xf43068b4
#define QM_QM_LATENCY_TIMER_CFG_dft              0x3f3f0000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 timer_profile_sel_ni0 :  1 ; /* bits 0:0 */
    u32 timer_profile_sel_ni1 :  1 ; /* bits 1:1 */
    u32 timer_profile_sel_ni2 :  1 ; /* bits 2:2 */
    u32 timer_profile_sel_ni3 :  1 ; /* bits 3:3 */
    u32 timer_profile_sel_ni4 :  1 ; /* bits 4:4 */
    u32 timer_profile_sel_ni5 :  1 ; /* bits 5:5 */
    u32 timer_profile_sel_ni6 :  1 ; /* bits 6:6 */
    u32 timer_profile_sel_ni7 :  1 ; /* bits 7:7 */
    u32 rsrvd1               :  8 ;
    u32 ths0                 :  8 ; /* bits 23:16 */
    u32 ths1                 :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} QM_QM_LATENCY_TIMER_CFG_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_BUFFER_INT_SRC                     0xf43068b8
#define QM_QM_BUFFER_INT_SRC_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 burst_fifo_error_int_src :  1 ; /* bits 0:0 */
    u32 ni_pp_pkt_error_int_src :  1 ; /* bits 1:1 */
    u32 sta_fifo_error_int_src :  1 ; /* bits 2:2 */
    u32 qm_rmu_buf_error_int_src :  1 ; /* bits 3:3 */
    u32 qm_te_rmu_error_int_src :  1 ; /* bits 4:4 */
    u32 qm_te_tmu_error_int_src :  1 ; /* bits 5:5 */
    u32 qm_te_es_error_int_src :  1 ; /* bits 6:6 */
    u32 axi_id_cfg_error_int_src :  1 ; /* bits 7:7 */
    u32 axi_wr_reorder_resp_error_int_src :  1 ; /* bits 8:8 */
    u32 axi_wr_reorder_fifo_error_int_src :  1 ; /* bits 9:9 */
    u32 rsrvd1               : 17 ;
    u32 qm_eqm_eq_load_cfg_error_int_src :  1 ; /* bits 27:27 */
    u32 qm_eqm_no_buf_error_int_src :  1 ; /* bits 28:28 */
    u32 qm_configuration_error_int_src :  1 ; /* bits 29:29 */
    u32 qm_bb_wptr_empty_int_src :  1 ; /* bits 30:30 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} QM_QM_BUFFER_INT_SRC_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_BUFFER_INT_SRCE                    0xf43068bc
#define QM_QM_BUFFER_INT_SRCE_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 burst_fifo_error_int_srcE :  1 ; /* bits 0:0 */
    u32 ni_pp_pkt_error_int_srcE :  1 ; /* bits 1:1 */
    u32 sta_fifo_error_int_srcE :  1 ; /* bits 2:2 */
    u32 qm_rmu_buf_error_int_srcE :  1 ; /* bits 3:3 */
    u32 qm_te_rmu_error_int_srcE :  1 ; /* bits 4:4 */
    u32 qm_te_tmu_error_int_srcE :  1 ; /* bits 5:5 */
    u32 qm_te_es_error_int_srcE :  1 ; /* bits 6:6 */
    u32 axi_id_cfg_error_int_srcE :  1 ; /* bits 7:7 */
    u32 axi_wr_reorder_resp_error_int_srcE :  1 ; /* bits 8:8 */
    u32 axi_wr_reorder_fifo_error_int_srcE :  1 ; /* bits 9:9 */
    u32 rsrvd1               : 17 ;
    u32 qm_eqm_eq_load_cfg_error_int_srcE :  1 ; /* bits 27:27 */
    u32 qm_eqm_no_buf_error_int_srcE :  1 ; /* bits 28:28 */
    u32 qm_configuration_error_int_srcE :  1 ; /* bits 29:29 */
    u32 qm_bb_wptr_empty_int_srcE :  1 ; /* bits 30:30 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} QM_QM_BUFFER_INT_SRCE_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_OVER_THS_STATUS2               0xf43068c0
#define QM_QM_VOQ_OVER_THS_STATUS2_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_OVER_THS_STATUS2_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_OVER_THS_STATUS3               0xf43068c4
#define QM_QM_VOQ_OVER_THS_STATUS3_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_OVER_THS_STATUS3_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_OVER_THS_STATUS4               0xf43068c8
#define QM_QM_VOQ_OVER_THS_STATUS4_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_OVER_THS_STATUS4_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_OVER_THS_STATUS5               0xf43068cc
#define QM_QM_VOQ_OVER_THS_STATUS5_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_OVER_THS_STATUS5_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_OVER_THS_STATUS6               0xf43068d0
#define QM_QM_VOQ_OVER_THS_STATUS6_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_OVER_THS_STATUS6_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_VOQ_OVER_THS_STATUS7               0xf43068d4
#define QM_QM_VOQ_OVER_THS_STATUS7_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_VOQ_OVER_THS_STATUS7_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_BURST_BUF_DEBUG_STATUS             0xf43068d8
#define QM_QM_BURST_BUF_DEBUG_STATUS_dft         0x0000ff7f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 fifo_empty           :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 rmu_fifo_empty       :  8 ; /* bits 15:8 */
    u32 rsrvd2               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_BURST_BUF_DEBUG_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_BURST_BUF_V_FIFO_STATUS0           0xf43068dc
#define QM_QM_BURST_BUF_V_FIFO_STATUS0_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_BURST_BUF_V_FIFO_STATUS0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_BURST_BUF_V_FIFO_STATUS1           0xf43068e0
#define QM_QM_BURST_BUF_V_FIFO_STATUS1_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 status               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_BURST_BUF_V_FIFO_STATUS1_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_BURST_BUF_DEBUG_CNTR               0xf43068e4
#define QM_QM_BURST_BUF_DEBUG_CNTR_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 close_buf_cmd_cntr   : 16 ; /* bits 15:0 */
    u32 close_buf_cmd_proc_cntr : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} QM_QM_BURST_BUF_DEBUG_CNTR_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_BURST_BUF_DEBUG_SEG_ID             0xf43068e8
#define QM_QM_BURST_BUF_DEBUG_SEG_ID_dft         0x0000000a

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 seg_id               :  6 ; /* bits 5:0 */
    u32 rsrvd1               : 26 ;
  } bf ;
  u32     wrd ;
} QM_QM_BURST_BUF_DEBUG_SEG_ID_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_BURST_BUF_SEG_ID_MONITOR           0xf43068ec
#define QM_QM_BURST_BUF_SEG_ID_MONITOR_dft       0x00010000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rptr_fifo_cntr       :  3 ; /* bits 2:0 */
    u32 rsrvd1               : 13 ;
    u32 wptr_fifo_cntr       :  3 ; /* bits 18:16 */
    u32 rsrvd2               : 13 ;
  } bf ;
  u32     wrd ;
} QM_QM_BURST_BUF_SEG_ID_MONITOR_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DEBUG_CFG                          0xf43068f0
#define QM_QM_DEBUG_CFG_dft                      0x000000bb

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 te_report            :  1 ; /* bits 0:0 */
    u32 te_report_1          :  1 ; /* bits 1:1 */
    u32 eq_sel               :  1 ; /* bits 2:2 */
    u32 bug_51590_fix_en     :  1 ; /* bits 3:3 */
    u32 te_report_fifo_en    :  1 ; /* bits 4:4 */
    u32 te_report_timer_constant :  3 ; /* bits 7:5 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} QM_QM_DEBUG_CFG_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EPP                                0xf43068f4
#define QM_QM_EPP_dft                            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 map                  :  1 ; /* bits 0:0 */
    u32 aggr_mode            :  1 ; /* bits 1:1 */
    u32 cmd_mode             :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} QM_QM_EPP_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_UPPER_LDPID_MAP                    0xf43068f8
#define QM_QM_UPPER_LDPID_MAP_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pon_offset           :  3 ; /* bits 2:0 */
    u32 pon_en               :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} QM_QM_UPPER_LDPID_MAP_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_SRAM_TEST_CONTROL_l3qm_bb          0xf43068fc
#define QM_QM_SRAM_TEST_CONTROL_l3qm_bb_dft      0x00000202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 test_cfg0            :  8 ; /* bits 7:0 */
    u32 test_cfg1            :  8 ; /* bits 15:8 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_SRAM_TEST_CONTROL_l3qm_bb_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_SRAM_TEST_CONTROL_l3qm2_0          0xf4306900
#define QM_QM_SRAM_TEST_CONTROL_l3qm2_0_dft      0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 test_cfg0            :  8 ; /* bits 7:0 */
    u32 test_cfg1            :  8 ; /* bits 15:8 */
    u32 test_cfg2            :  8 ; /* bits 23:16 */
    u32 test_cfg3            :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} QM_QM_SRAM_TEST_CONTROL_l3qm2_0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_SRAM_TEST_CONTROL_l3qm2_1          0xf4306904
#define QM_QM_SRAM_TEST_CONTROL_l3qm2_1_dft      0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 test_cfg0            :  8 ; /* bits 7:0 */
    u32 test_cfg1            :  8 ; /* bits 15:8 */
    u32 test_cfg2            :  8 ; /* bits 23:16 */
    u32 test_cfg3            :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} QM_QM_SRAM_TEST_CONTROL_l3qm2_1_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_SRAM_TEST_CONTROL_l3qm2_2          0xf4306908
#define QM_QM_SRAM_TEST_CONTROL_l3qm2_2_dft      0x00000202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 test_cfg0            :  8 ; /* bits 7:0 */
    u32 test_cfg1            :  8 ; /* bits 15:8 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_SRAM_TEST_CONTROL_l3qm2_2_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_SRAM_TEST_CONTROL_l3qm_repair      0xf430690c
#define QM_QM_SRAM_TEST_CONTROL_l3qm_repair_dft  0x00000002

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 test_cfg0            :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} QM_QM_SRAM_TEST_CONTROL_l3qm_repair_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_SRAM_TEST_CONTROL_l3qm_repair2     0xf4306910
#define QM_QM_SRAM_TEST_CONTROL_l3qm_repair2_dft 0x00000002

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 test_cfg0            :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} QM_QM_SRAM_TEST_CONTROL_l3qm_repair2_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_SRAM_LS_CONTROL_0                  0xf4306914
#define QM_QM_SRAM_LS_CONTROL_0_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 l3qm2_sramls         : 10 ; /* bits 9:0 */
    u32 l3qm_bb_sramls       :  2 ; /* bits 11:10 */
    u32 l3qm_repair2_sramls  :  1 ; /* bits 12:12 */
    u32 l3qm_sramls          :  1 ; /* bits 13:13 */
    u32 rsrvd1               : 18 ;
  } bf ;
  u32     wrd ;
} QM_QM_SRAM_LS_CONTROL_0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_SRAM_LS_CONTROL_1                  0xf4306918
#define QM_QM_SRAM_LS_CONTROL_1_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 l3te1_sramls         :  9 ; /* bits 8:0 */
    u32 l3te2_sramls         :  6 ; /* bits 14:9 */
    u32 l3te3_sramls         : 10 ; /* bits 24:15 */
    u32 rsrvd1               :  7 ;
  } bf ;
  u32     wrd ;
} QM_QM_SRAM_LS_CONTROL_1_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_BACK_PRES_CTRL                     0xf430691c
#define QM_QM_BACK_PRES_CTRL_dft                 0x0000007f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qm_bp_ctrl           : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} QM_QM_BACK_PRES_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ_USG_CTRL0                       0xf4306920
#define QM_QM_EQ_USG_CTRL0_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt_en               : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_EQ_USG_CTRL0_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ_USG_CTRL1                       0xf4306924
#define QM_QM_EQ_USG_CTRL1_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt_clr              : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QM_QM_EQ_USG_CTRL1_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ0_BUF_USG_STS                    0xf4306928
#define QM_QM_EQ0_BUF_USG_STS_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ0_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ1_BUF_USG_STS                    0xf430692c
#define QM_QM_EQ1_BUF_USG_STS_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ1_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ2_BUF_USG_STS                    0xf4306930
#define QM_QM_EQ2_BUF_USG_STS_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ2_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ3_BUF_USG_STS                    0xf4306934
#define QM_QM_EQ3_BUF_USG_STS_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ3_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ4_BUF_USG_STS                    0xf4306938
#define QM_QM_EQ4_BUF_USG_STS_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ4_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ5_BUF_USG_STS                    0xf430693c
#define QM_QM_EQ5_BUF_USG_STS_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ5_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ6_BUF_USG_STS                    0xf4306940
#define QM_QM_EQ6_BUF_USG_STS_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ6_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ7_BUF_USG_STS                    0xf4306944
#define QM_QM_EQ7_BUF_USG_STS_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ7_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ8_BUF_USG_STS                    0xf4306948
#define QM_QM_EQ8_BUF_USG_STS_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ8_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ9_BUF_USG_STS                    0xf430694c
#define QM_QM_EQ9_BUF_USG_STS_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ9_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ10_BUF_USG_STS                   0xf4306950
#define QM_QM_EQ10_BUF_USG_STS_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ10_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ11_BUF_USG_STS                   0xf4306954
#define QM_QM_EQ11_BUF_USG_STS_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ11_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ12_BUF_USG_STS                   0xf4306958
#define QM_QM_EQ12_BUF_USG_STS_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ12_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ13_BUF_USG_STS                   0xf430695c
#define QM_QM_EQ13_BUF_USG_STS_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ13_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ14_BUF_USG_STS                   0xf4306960
#define QM_QM_EQ14_BUF_USG_STS_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ14_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_EQ15_BUF_USG_STS                   0xf4306964
#define QM_QM_EQ15_BUF_USG_STS_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_EQ15_BUF_USG_STS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_ES_CTRL2                           0xf4306968
#define QM_QM_ES_CTRL2_dft                       0x00040300

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qm_ni_es_pkt_ctrl    :  1 ; /* bits 0:0 */
    u32 ni_qm_hol_pkt_ctrl   :  1 ; /* bits 1:1 */
    u32 rsrvd1               :  2 ;
    u32 qm_ni_bridge_fifo_rd_thr :  7 ; /* bits 10:4 */
    u32 rsrvd2               :  1 ;
    u32 qm_ni_bridge_fifo_wr_thr :  8 ; /* bits 19:12 */
    u32 rsrvd3               : 12 ;
  } bf ;
  u32     wrd ;
} QM_QM_ES_CTRL2_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_RMU0_CTRL1                         0xf430696c
#define QM_QM_RMU0_CTRL1_dft                     0x0322d380

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rmudata_fifo_bp_ctrl :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  3 ;
    u32 qm_bb_bp_thr_on      :  7 ; /* bits 10:4 */
    u32 rsrvd2               :  1 ;
    u32 qm_bb_bp_thr_off     :  7 ; /* bits 18:12 */
    u32 rsrvd3               :  1 ;
    u32 rmudata_almost_full_thr :  7 ; /* bits 26:20 */
    u32 rsrvd4               :  5 ;
  } bf ;
  u32     wrd ;
} QM_QM_RMU0_CTRL1_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DBG_CTRL                           0xf4306970
#define QM_QM_DBG_CTRL_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qm_dbg_en            :  1 ; /* bits 0:0 */
    u32 qm_dbg_clr           :  1 ; /* bits 1:1 */
    u32 rsrvd1               :  6 ;
    u32 qm_dbg_sel           :  4 ; /* bits 11:8 */
    u32 force_qm_nitx_rdy    :  1 ; /* bits 12:12 */
    u32 rsrvd2               : 19 ;
  } bf ;
  u32     wrd ;
} QM_QM_DBG_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_DBG_STATUS                         0xf4306974
#define QM_QM_DBG_STATUS_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_DBG_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CPUEPP_POINTER_CPUEPP64_FIFO_WRPTR 0xf4307000
#define QM_QM_CPUEPP_POINTER_CPUEPP64_FIFO_WRPTR_STRIDE 4
#define QM_QM_CPUEPP_POINTER_CPUEPP64_FIFO_WRPTR_COUNT 64
#define QM_QM_CPUEPP_POINTER_CPUEPP64_FIFO_WRPTR_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wptr                 : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} QM_QM_CPUEPP_POINTER_CPUEPP64_FIFO_WRPTR_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CPUEPP_POINTER_CPUEPP64_FIFO_RDPTR 0xf4307100
#define QM_QM_CPUEPP_POINTER_CPUEPP64_FIFO_RDPTR_STRIDE 4
#define QM_QM_CPUEPP_POINTER_CPUEPP64_FIFO_RDPTR_COUNT 64
#define QM_QM_CPUEPP_POINTER_CPUEPP64_FIFO_RDPTR_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rptr                 : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} QM_QM_CPUEPP_POINTER_CPUEPP64_FIFO_RDPTR_t;
#endif /* !__ASSEMBLER__ */
#define QM_QM_CPUEPP_POINTER_CPUEPP64_FIFO_PADDR_START 0xf4307200
#define QM_QM_CPUEPP_POINTER_CPUEPP64_FIFO_PADDR_START_STRIDE 4
#define QM_QM_CPUEPP_POINTER_CPUEPP64_FIFO_PADDR_START_COUNT 64
#define QM_QM_CPUEPP_POINTER_CPUEPP64_FIFO_PADDR_START_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 phy_addr             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_QM_CPUEPP_POINTER_CPUEPP64_FIFO_PADDR_START_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_REVISION                       0xf430a000
#define NI_HV_GLB_REVISION_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 minor                : 16 ; /* bits 15:0 */
    u32 major                : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_REVISION_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_INIT_DONE                      0xf430a004
#define NI_HV_GLB_INIT_DONE_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  1 ;
    u32 ni_init_done         :  1 ; /* bits 1:1 */
    u32 rsrvd2               : 30 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_INIT_DONE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_INTF_RST_CONFIG                0xf430a008
#define NI_HV_GLB_INTF_RST_CONFIG_dft            0x0077ffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 intf_rst_p0          :  1 ; /* bits 0:0 */
    u32 intf_rst_p1          :  1 ; /* bits 1:1 */
    u32 intf_rst_p2          :  1 ; /* bits 2:2 */
    u32 intf_rst_p3          :  1 ; /* bits 3:3 */
    u32 intf_rst_p4          :  1 ; /* bits 4:4 */
    u32 intf_rst_p5          :  1 ; /* bits 5:5 */
    u32 mac_rx_rst_p0        :  1 ; /* bits 6:6 */
    u32 mac_rx_rst_p1        :  1 ; /* bits 7:7 */
    u32 mac_rx_rst_p2        :  1 ; /* bits 8:8 */
    u32 mac_rx_rst_p3        :  1 ; /* bits 9:9 */
    u32 mac_rx_rst_p4        :  1 ; /* bits 10:10 */
    u32 mac_rx_rst_p5        :  1 ; /* bits 11:11 */
    u32 mac_tx_rst_p0        :  1 ; /* bits 12:12 */
    u32 mac_tx_rst_p1        :  1 ; /* bits 13:13 */
    u32 mac_tx_rst_p2        :  1 ; /* bits 14:14 */
    u32 mac_tx_rst_p3        :  1 ; /* bits 15:15 */
    u32 mac_tx_rst_p4        :  1 ; /* bits 16:16 */
    u32 mac_tx_rst_p5        :  1 ; /* bits 17:17 */
    u32 port_rst_p5          :  1 ; /* bits 18:18 */
    u32 rsrvd1               :  1 ;
    u32 pcs_rst_p5           :  1 ; /* bits 20:20 */
    u32 mac_rst_p6           :  1 ; /* bits 21:21 */
    u32 mac_rst_p5           :  1 ; /* bits 22:22 */
    u32 rsrvd2               :  9 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_INTF_RST_CONFIG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_IPG_CMPS_CFG                   0xf430a00c
#define NI_HV_GLB_IPG_CMPS_CFG_dft               0x00005555

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p0_cmps_ipg_cfg      :  2 ; /* bits 1:0 */
    u32 p1_cmps_ipg_cfg      :  2 ; /* bits 3:2 */
    u32 p2_cmps_ipg_cfg      :  2 ; /* bits 5:4 */
    u32 p3_cmps_ipg_cfg      :  2 ; /* bits 7:6 */
    u32 p4_cmps_ipg_cfg      :  2 ; /* bits 9:8 */
    u32 p5_cmps_ipg_cfg      :  2 ; /* bits 11:10 */
    u32 p6_cmps_ipg_cfg      :  2 ; /* bits 13:12 */
    u32 p7_cmps_ipg_cfg      :  2 ; /* bits 15:14 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_IPG_CMPS_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_GPHY_STS_AUTOSYNC_CFG          0xf430a010
#define NI_HV_GLB_GPHY_STS_AUTOSYNC_CFG_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p0_en_physts_autosync :  1 ; /* bits 0:0 */
    u32 p1_en_physts_autosync :  1 ; /* bits 1:1 */
    u32 p2_en_physts_autosync :  1 ; /* bits 2:2 */
    u32 p3_en_physts_autosync :  1 ; /* bits 3:3 */
    u32 rsrvd1               :  4 ;
    u32 p0_en_fc_autosync    :  1 ; /* bits 8:8 */
    u32 p1_en_fc_autosync    :  1 ; /* bits 9:9 */
    u32 p2_en_fc_autosync    :  1 ; /* bits 10:10 */
    u32 p3_en_fc_autosync    :  1 ; /* bits 11:11 */
    u32 rsrvd2               : 20 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_GPHY_STS_AUTOSYNC_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PCS_STATUS_1                   0xf430a014
#define NI_HV_GLB_PCS_STATUS_1_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p2_pcs_ablty         : 13 ; /* bits 12:0 */
    u32 rsrvd1               :  3 ;
    u32 p3_pcs_ablty         : 13 ; /* bits 28:16 */
    u32 rsrvd2               :  3 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PCS_STATUS_1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PCS_STATUS_0                   0xf430a018
#define NI_HV_GLB_PCS_STATUS_0_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p0_pcs_ablty         : 13 ; /* bits 12:0 */
    u32 rsrvd1               :  3 ;
    u32 p1_pcs_ablty         : 13 ; /* bits 28:16 */
    u32 rsrvd2               :  3 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PCS_STATUS_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_STATIC_CFG                     0xf430a01c
#define NI_HV_GLB_STATIC_CFG_dft                 0x3ae4012f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port_to_cpu          :  4 ; /* bits 3:0 */
    u32 mgmt_pt_to_fe_also   :  1 ; /* bits 4:4 */
    u32 txcrc_chk_en         :  1 ; /* bits 5:5 */
    u32 p5_rgmii_tx_clk_phase :  2 ; /* bits 7:6 */
    u32 p5_rgmii_tx_data_order :  1 ; /* bits 8:8 */
    u32 p5_ge_sel            :  1 ; /* bits 9:9 */
    u32 rsrvd1               :  2 ;
    u32 port0_qxgmii_sel     :  1 ; /* bits 12:12 */
    u32 port1_qxgmii_sel     :  1 ; /* bits 13:13 */
    u32 port2_qxgmii_sel     :  1 ; /* bits 14:14 */
    u32 port3_qxgmii_sel     :  1 ; /* bits 15:15 */
    u32 rxmib_mode           :  1 ; /* bits 16:16 */
    u32 txmib_mode           :  1 ; /* bits 17:17 */
    u32 rt_mib_en            :  1 ; /* bits 18:18 */
    u32 rsrvd2               :  1 ;
    u32 rxaui_mode           :  2 ; /* bits 21:20 */
    u32 rxaui_sigdet         :  2 ; /* bits 23:22 */
    u32 cnt_op_mode          :  3 ; /* bits 26:24 */
    u32 saturn_p7_tx_crc32_add :  1 ; /* bits 27:27 */
    u32 venus_p6_tx_crc32_add :  1 ; /* bits 28:28 */
    u32 venus_p5_tx_crc32_add :  1 ; /* bits 29:29 */
    u32 rsrvd3               :  2 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_STATIC_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_VENUS_CORESEC10_CFG            0xf430a020
#define NI_HV_GLB_VENUS_CORESEC10_CFG_dft        0x40000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  9 ;
    u32 xgmii_rx_macsec_on   :  1 ; /* bits 9:9 */
    u32 xgmii_tx_macsec_on   :  1 ; /* bits 10:10 */
    u32 p6_txmac_in_sel      :  1 ; /* bits 11:11 */
    u32 p7_xfi_in_sel        :  1 ; /* bits 12:12 */
    u32 macsec_enc_in_sel    :  1 ; /* bits 13:13 */
    u32 macsec_dec_in_sel    :  1 ; /* bits 14:14 */
    u32 p6_nirx_in_sel       :  1 ; /* bits 15:15 */
    u32 p7_nirx_in_sel       :  1 ; /* bits 16:16 */
    u32 macsec_decrypt_en    :  1 ; /* bits 17:17 */
    u32 macsec_encrypt_en    :  1 ; /* bits 18:18 */
    u32 enc_all              :  1 ; /* bits 19:19 */
    u32 macsec_sectag_type   :  1 ; /* bits 20:20 */
    u32 rsrvd2               :  9 ;
    u32 macsec_enc_fifo_threshold :  2 ; /* bits 31:30 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_VENUS_CORESEC10_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_MAC_ADDR_CFG0                  0xf430a024
#define NI_HV_GLB_MAC_ADDR_CFG0_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mac_addr0            : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_MAC_ADDR_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_MAC_ADDR_CFG1                  0xf430a028
#define NI_HV_GLB_MAC_ADDR_CFG1_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mac_addr1            :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_MAC_ADDR_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_WOL_PASSWD_0                   0xf430a02c
#define NI_HV_GLB_WOL_PASSWD_0_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wol_passwd0          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_WOL_PASSWD_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_WOL_PASSWD_1                   0xf430a030
#define NI_HV_GLB_WOL_PASSWD_1_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wol_passwd1          :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_WOL_PASSWD_1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PKT_LEN_CFG                    0xf430a034
#define NI_HV_GLB_PKT_LEN_CFG_dft                0x004023f1

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 max_pkt_size         : 14 ; /* bits 13:0 */
    u32 rsrvd1               :  2 ;
    u32 min_pkt_size         : 10 ; /* bits 25:16 */
    u32 rsrvd2               :  6 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PKT_LEN_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PKT_STOR_LEN_CFG               0xf430a038
#define NI_HV_GLB_PKT_STOR_LEN_CFG_dft           0x00002454

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 max_stor_pkt_len     : 14 ; /* bits 13:0 */
    u32 rsrvd1               : 18 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PKT_STOR_LEN_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_P5_BYPASS_CFG                  0xf430a03c
#define NI_HV_GLB_P5_BYPASS_CFG_dft              0x00000008

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 byp_cos              :  3 ; /* bits 2:0 */
    u32 byp_dpq              :  1 ; /* bits 3:3 */
    u32 byp_dpid             :  6 ; /* bits 9:4 */
    u32 byp_mir              :  1 ; /* bits 10:10 */
    u32 byp_ndrp             :  1 ; /* bits 11:11 */
    u32 byp_en               :  1 ; /* bits 12:12 */
    u32 rsrvd1               : 19 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_P5_BYPASS_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE_BYPASS_CFG                 0xf430a040
#define NI_HV_GLB_XGE_BYPASS_CFG_dft             0x00000008

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p6_byp_cos           :  3 ; /* bits 2:0 */
    u32 p6_byp_dpq           :  1 ; /* bits 3:3 */
    u32 p6_byp_dpid          :  6 ; /* bits 9:4 */
    u32 p6_byp_mir           :  1 ; /* bits 10:10 */
    u32 p6_byp_ndrp          :  1 ; /* bits 11:11 */
    u32 p6_byp_en            :  1 ; /* bits 12:12 */
    u32 rsrvd1               : 16 ;
    u32 p6_ts_fifo_rst       :  1 ; /* bits 29:29 */
    u32 rsrvd2               :  2 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE_BYPASS_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE6_RXPAUSE_CFG               0xf430a044
#define NI_HV_GLB_XGE6_RXPAUSE_CFG_dft           0x0004b064

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 thre_lo              : 10 ; /* bits 9:0 */
    u32 thre_hi              : 10 ; /* bits 19:10 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE6_RXPAUSE_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE7_RXFIFO_THRESHOLD          0xf430a048
#define NI_HV_GLB_XGE7_RXFIFO_THRESHOLD_dft      0x00032014

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 free_buf_thre_lo     :  9 ; /* bits 8:0 */
    u32 rsrvd1               :  1 ;
    u32 free_buf_thre_hi     :  9 ; /* bits 18:10 */
    u32 rsrvd2               : 13 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE7_RXFIFO_THRESHOLD_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE6_MAC_CFG1                  0xf430a04c
#define NI_HV_GLB_XGE6_MAC_CFG1_dft              0x00000200

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mac1                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE6_MAC_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE6_MAC_CFG0                  0xf430a050
#define NI_HV_GLB_XGE6_MAC_CFG0_dft              0x00000002

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mac0                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE6_MAC_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE6_FLOW_CONTROL_CFG          0xf430a054
#define NI_HV_GLB_XGE6_FLOW_CONTROL_CFG_dft      0xc5ff011c

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qbb_tx_en            :  1 ; /* bits 0:0 */
    u32 qbb_rx_en            :  1 ; /* bits 1:1 */
    u32 pau_tx_en            :  1 ; /* bits 2:2 */
    u32 pau_rx_en            :  1 ; /* bits 3:3 */
    u32 adjust_pause_cnt     : 12 ; /* bits 15:4 */
    u32 qbb_qen              :  8 ; /* bits 23:16 */
    u32 txpfc_keep           :  1 ; /* bits 24:24 */
    u32 tx_sw_pause_en       :  1 ; /* bits 25:25 */
    u32 rx_drp_pau_en        :  1 ; /* bits 26:26 */
    u32 tx_sw_pausereq       :  1 ; /* bits 27:27 */
    u32 internal_txstop_sel  :  1 ; /* bits 28:28 */
    u32 tx_remheader_dis     :  1 ; /* bits 29:29 */
    u32 rx_pausereq_sel      :  1 ; /* bits 30:30 */
    u32 te_pausereq_sel      :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE6_FLOW_CONTROL_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE6_TX_REPEAT_CNT             0xf430a058
#define NI_HV_GLB_XGE6_TX_REPEAT_CNT_dft         0x00008000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 repeat_cnt           : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE6_TX_REPEAT_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE6_TX_QUANTA0                0xf430a05c
#define NI_HV_GLB_XGE6_TX_QUANTA0_dft            0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pause_quanta0        : 16 ; /* bits 15:0 */
    u32 pause_quanta1        : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE6_TX_QUANTA0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE6_TX_QUANTA1                0xf430a060
#define NI_HV_GLB_XGE6_TX_QUANTA1_dft            0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pause_quanta2        : 16 ; /* bits 15:0 */
    u32 pause_quanta3        : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE6_TX_QUANTA1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE6_TX_QUANTA2                0xf430a064
#define NI_HV_GLB_XGE6_TX_QUANTA2_dft            0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pause_quanta4        : 16 ; /* bits 15:0 */
    u32 pause_quanta5        : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE6_TX_QUANTA2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE6_TX_QUANTA3                0xf430a068
#define NI_HV_GLB_XGE6_TX_QUANTA3_dft            0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pause_quanta6        : 16 ; /* bits 15:0 */
    u32 pause_quanta7        : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE6_TX_QUANTA3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE6_QBB_WAIT_TIME             0xf430a06c
#define NI_HV_GLB_XGE6_QBB_WAIT_TIME_dft         0x00000005

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wait_cnt             : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE6_QBB_WAIT_TIME_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE6_RX_FLOW_CTRL_PKT_CNT      0xf430a070
#define NI_HV_GLB_XGE6_RX_FLOW_CTRL_PKT_CNT_dft  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pause_pkt_cnt        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE6_RX_FLOW_CTRL_PKT_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE6_RX_FAKE_PAUS_PKT_CNT      0xf430a074
#define NI_HV_GLB_XGE6_RX_FAKE_PAUS_PKT_CNT_dft  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 err_paus_pkt_cnt     : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE6_RX_FAKE_PAUS_PKT_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE6_TX_FLOW_CTRL_PKT_CNT      0xf430a078
#define NI_HV_GLB_XGE6_TX_FLOW_CTRL_PKT_CNT_dft  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pause_pkt_cnt        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE6_TX_FLOW_CTRL_PKT_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMUX_INTPT_CALENDAR_CFG1      0xf430a07c
#define NI_HV_GLB_RXMUX_INTPT_CALENDAR_CFG1_dft  0xe4e4e4e4

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 int_cal1             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMUX_INTPT_CALENDAR_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMUX_INTPT_CALENDAR_CFG0      0xf430a080
#define NI_HV_GLB_RXMUX_INTPT_CALENDAR_CFG0_dft  0xe4e4e4e4

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 int_cal0             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMUX_INTPT_CALENDAR_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMUX_CTRL_CFG                 0xf430a084
#define NI_HV_GLB_RXMUX_CTRL_CFG_dft             0x100a09ba

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 l3fe_pspid           :  4 ; /* bits 3:0 */
    u32 mce_pspid            :  4 ; /* bits 7:4 */
    u32 dma_pspid            :  4 ; /* bits 11:8 */
    u32 err_pkt_ok           :  1 ; /* bits 12:12 */
    u32 calendar_en          :  1 ; /* bits 13:13 */
    u32 rsrvd1               :  2 ;
    u32 next_sop_delay       : 12 ; /* bits 27:16 */
    u32 dbg_sel              :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMUX_CTRL_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMUX_LAST_HDR_A2              0xf430a088
#define NI_HV_GLB_RXMUX_LAST_HDR_A2_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdra2                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMUX_LAST_HDR_A2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMUX_LAST_HDR_A1              0xf430a08c
#define NI_HV_GLB_RXMUX_LAST_HDR_A1_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdra1                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMUX_LAST_HDR_A1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMUX_LAST_HDR_A0              0xf430a090
#define NI_HV_GLB_RXMUX_LAST_HDR_A0_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdra0                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMUX_LAST_HDR_A0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMUX_PKTCNT                   0xf430a094
#define NI_HV_GLB_RXMUX_PKTCNT_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dbg_pkt_cnt          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMUX_PKTCNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMUX_PORT0_FC_THRESHOLD_CFG   0xf430a098
#define NI_HV_GLB_RXMUX_PORT0_FC_THRESHOLD_CFG_STRIDE 4
#define NI_HV_GLB_RXMUX_PORT0_FC_THRESHOLD_CFG_COUNT 12
#define NI_HV_GLB_RXMUX_PORT0_FC_THRESHOLD_CFG_dft 0x0000a014

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 thre_lo              : 10 ; /* bits 9:0 */
    u32 thre_hi              : 10 ; /* bits 19:10 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMUX_PORT0_FC_THRESHOLD_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_P11_SEG_BUF_TOP_BOTTOM_ADDR_CFG 0xf430a0c8
#define NI_HV_GLB_RX_P11_SEG_BUF_TOP_BOTTOM_ADDR_CFG_dft 0x000fffc0

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_ptr             : 10 ; /* bits 9:0 */
    u32 top_ptr              : 10 ; /* bits 19:10 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_P11_SEG_BUF_TOP_BOTTOM_ADDR_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_P10_SEG_BUF_TOP_BOTTOM_ADDR_CFG 0xf430a0cc
#define NI_HV_GLB_RX_P10_SEG_BUF_TOP_BOTTOM_ADDR_CFG_dft 0x000eff80

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_ptr             : 10 ; /* bits 9:0 */
    u32 top_ptr              : 10 ; /* bits 19:10 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_P10_SEG_BUF_TOP_BOTTOM_ADDR_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_P9_SEG_BUF_TOP_BOTTOM_ADDR_CFG 0xf430a0d0
#define NI_HV_GLB_RX_P9_SEG_BUF_TOP_BOTTOM_ADDR_CFG_dft 0x000dff40

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_ptr             : 10 ; /* bits 9:0 */
    u32 top_ptr              : 10 ; /* bits 19:10 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_P9_SEG_BUF_TOP_BOTTOM_ADDR_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_P8_SEG_BUF_TOP_BOTTOM_ADDR_CFG 0xf430a0d4
#define NI_HV_GLB_RX_P8_SEG_BUF_TOP_BOTTOM_ADDR_CFG_dft 0x000cff00

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_ptr             : 10 ; /* bits 9:0 */
    u32 top_ptr              : 10 ; /* bits 19:10 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_P8_SEG_BUF_TOP_BOTTOM_ADDR_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_P7_SEG_BUF_TOP_BOTTOM_ADDR_CFG 0xf430a0d8
#define NI_HV_GLB_RX_P7_SEG_BUF_TOP_BOTTOM_ADDR_CFG_dft 0x000bfe00

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_ptr             : 10 ; /* bits 9:0 */
    u32 top_ptr              : 10 ; /* bits 19:10 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_P7_SEG_BUF_TOP_BOTTOM_ADDR_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_P6_SEG_BUF_TOP_BOTTOM_ADDR_CFG 0xf430a0dc
#define NI_HV_GLB_RX_P6_SEG_BUF_TOP_BOTTOM_ADDR_CFG_dft 0x0007fd80

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_ptr             : 10 ; /* bits 9:0 */
    u32 top_ptr              : 10 ; /* bits 19:10 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_P6_SEG_BUF_TOP_BOTTOM_ADDR_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_P5_SEG_BUF_TOP_BOTTOM_ADDR_CFG 0xf430a0e0
#define NI_HV_GLB_RX_P5_SEG_BUF_TOP_BOTTOM_ADDR_CFG_dft 0x0005fd40

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_ptr             : 10 ; /* bits 9:0 */
    u32 top_ptr              : 10 ; /* bits 19:10 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_P5_SEG_BUF_TOP_BOTTOM_ADDR_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_P4_SEG_BUF_TOP_BOTTOM_ADDR_CFG 0xf430a0e4
#define NI_HV_GLB_RX_P4_SEG_BUF_TOP_BOTTOM_ADDR_CFG_dft 0x0004fd00

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_ptr             : 10 ; /* bits 9:0 */
    u32 top_ptr              : 10 ; /* bits 19:10 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_P4_SEG_BUF_TOP_BOTTOM_ADDR_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_P3_SEG_BUF_TOP_BOTTOM_ADDR_CFG 0xf430a0e8
#define NI_HV_GLB_RX_P3_SEG_BUF_TOP_BOTTOM_ADDR_CFG_dft 0x0003fcc0

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_ptr             : 10 ; /* bits 9:0 */
    u32 top_ptr              : 10 ; /* bits 19:10 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_P3_SEG_BUF_TOP_BOTTOM_ADDR_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_P2_SEG_BUF_TOP_BOTTOM_ADDR_CFG 0xf430a0ec
#define NI_HV_GLB_RX_P2_SEG_BUF_TOP_BOTTOM_ADDR_CFG_dft 0x0002fc80

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_ptr             : 10 ; /* bits 9:0 */
    u32 top_ptr              : 10 ; /* bits 19:10 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_P2_SEG_BUF_TOP_BOTTOM_ADDR_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_P1_SEG_BUF_TOP_BOTTOM_ADDR_CFG 0xf430a0f0
#define NI_HV_GLB_RX_P1_SEG_BUF_TOP_BOTTOM_ADDR_CFG_dft 0x0001fc40

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_ptr             : 10 ; /* bits 9:0 */
    u32 top_ptr              : 10 ; /* bits 19:10 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_P1_SEG_BUF_TOP_BOTTOM_ADDR_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_P0_SEG_BUF_TOP_BOTTOM_ADDR_CFG 0xf430a0f4
#define NI_HV_GLB_RX_P0_SEG_BUF_TOP_BOTTOM_ADDR_CFG_dft 0x0000fc00

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_ptr             : 10 ; /* bits 9:0 */
    u32 top_ptr              : 10 ; /* bits 19:10 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_P0_SEG_BUF_TOP_BOTTOM_ADDR_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_SEG_BUFSIZE_UPDATE          0xf430a0f8
#define NI_HV_GLB_RX_SEG_BUFSIZE_UPDATE_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 load                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_SEG_BUFSIZE_UPDATE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_SEG_VLAN_TAG_INSERT_CFG     0xf430a0fc
#define NI_HV_GLB_RX_SEG_VLAN_TAG_INSERT_CFG_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p0_vlan_tag_num      :  2 ; /* bits 1:0 */
    u32 p1_vlan_tag_num      :  2 ; /* bits 3:2 */
    u32 p2_vlan_tag_num      :  2 ; /* bits 5:4 */
    u32 p3_vlan_tag_num      :  2 ; /* bits 7:6 */
    u32 p4_vlan_tag_num      :  2 ; /* bits 9:8 */
    u32 p5_vlan_tag_num      :  2 ; /* bits 11:10 */
    u32 p6_vlan_tag_num      :  2 ; /* bits 13:12 */
    u32 p7_vlan_tag_num      :  2 ; /* bits 15:14 */
    u32 p8_vlan_tag_num      :  2 ; /* bits 17:16 */
    u32 p9_vlan_tag_num      :  2 ; /* bits 19:18 */
    u32 p10_vlan_tag_num     :  2 ; /* bits 21:20 */
    u32 p11_vlan_tag_num     :  2 ; /* bits 23:22 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_SEG_VLAN_TAG_INSERT_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMUX_HDR_BUF_STATUS           0xf430a100
#define NI_HV_GLB_RXMUX_HDR_BUF_STATUS_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_buf_empty        : 12 ; /* bits 11:0 */
    u32 rsrvd1               : 20 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMUX_HDR_BUF_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMUX_DATA_BUF_STATUS          0xf430a104
#define NI_HV_GLB_RXMUX_DATA_BUF_STATUS_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 seg_buf_empty        : 12 ; /* bits 11:0 */
    u32 rsrvd1               :  4 ;
    u32 seg_buf_full         : 12 ; /* bits 27:16 */
    u32 l2fe_ni_rdy          :  1 ; /* bits 28:28 */
    u32 rsrvd2               :  3 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMUX_DATA_BUF_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMUX_DBG_CFG                  0xf430a108
#define NI_HV_GLB_RXMUX_DBG_CFG_dft              0x00000021

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt0_sel             :  4 ; /* bits 3:0 */
    u32 cnt1_sel             :  4 ; /* bits 7:4 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMUX_DBG_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMUX_OUT_CNT0                 0xf430a10c
#define NI_HV_GLB_RXMUX_OUT_CNT0_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt0                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMUX_OUT_CNT0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMUX_OUT_CNT1                 0xf430a110
#define NI_HV_GLB_RXMUX_OUT_CNT1_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt1                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMUX_OUT_CNT1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMUX_OUT_DRPCNT0              0xf430a114
#define NI_HV_GLB_RXMUX_OUT_DRPCNT0_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt0                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMUX_OUT_DRPCNT0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMUX_OUT_DRPCNT1              0xf430a118
#define NI_HV_GLB_RXMUX_OUT_DRPCNT1_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt1                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMUX_OUT_DRPCNT1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NIRX_XRAM_STS                  0xf430a11c
#define NI_HV_GLB_NIRX_XRAM_STS_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sts                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NIRX_XRAM_STS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NIRX_L3QM_STS                  0xf430a120
#define NI_HV_GLB_NIRX_L3QM_STS_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sts                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NIRX_L3QM_STS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NIRX_L3FE_STS                  0xf430a124
#define NI_HV_GLB_NIRX_L3FE_STS_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sts                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NIRX_L3FE_STS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_P0_RX_DROPCNT                  0xf430a128
#define NI_HV_GLB_P0_RX_DROPCNT_STRIDE           4
#define NI_HV_GLB_P0_RX_DROPCNT_COUNT            7
#define NI_HV_GLB_P0_RX_DROPCNT_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 CNT                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_P0_RX_DROPCNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_P0_TX_SHARE_FIFO_BASE_CFG      0xf430a144
#define NI_HV_GLB_P0_TX_SHARE_FIFO_BASE_CFG_dft  0x007f0000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_addr            : 10 ; /* bits 9:0 */
    u32 rsrvd1               :  6 ;
    u32 max                  : 10 ; /* bits 25:16 */
    u32 rsrvd2               :  6 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_P0_TX_SHARE_FIFO_BASE_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_P1_TX_SHARE_FIFO_BASE_CFG      0xf430a148
#define NI_HV_GLB_P1_TX_SHARE_FIFO_BASE_CFG_dft  0x007f0080

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_addr            : 10 ; /* bits 9:0 */
    u32 rsrvd1               :  6 ;
    u32 max                  : 10 ; /* bits 25:16 */
    u32 rsrvd2               :  6 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_P1_TX_SHARE_FIFO_BASE_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_P2_TX_SHARE_FIFO_BASE_CFG      0xf430a14c
#define NI_HV_GLB_P2_TX_SHARE_FIFO_BASE_CFG_dft  0x007f0100

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_addr            : 10 ; /* bits 9:0 */
    u32 rsrvd1               :  6 ;
    u32 max                  : 10 ; /* bits 25:16 */
    u32 rsrvd2               :  6 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_P2_TX_SHARE_FIFO_BASE_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_P3_TX_SHARE_FIFO_BASE_CFG      0xf430a150
#define NI_HV_GLB_P3_TX_SHARE_FIFO_BASE_CFG_dft  0x007f0180

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_addr            : 10 ; /* bits 9:0 */
    u32 rsrvd1               :  6 ;
    u32 max                  : 10 ; /* bits 25:16 */
    u32 rsrvd2               :  6 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_P3_TX_SHARE_FIFO_BASE_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_P4_TX_SHARE_FIFO_BASE_CFG      0xf430a154
#define NI_HV_GLB_P4_TX_SHARE_FIFO_BASE_CFG_dft  0x007f0200

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_addr            : 10 ; /* bits 9:0 */
    u32 rsrvd1               :  6 ;
    u32 max                  : 10 ; /* bits 25:16 */
    u32 rsrvd2               :  6 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_P4_TX_SHARE_FIFO_BASE_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_MCE_TX_SHARE_FIFO_BASE_CFG     0xf430a158
#define NI_HV_GLB_MCE_TX_SHARE_FIFO_BASE_CFG_dft 0x007f0280

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 base_addr            : 10 ; /* bits 9:0 */
    u32 rsrvd1               :  6 ;
    u32 max                  : 10 ; /* bits 25:16 */
    u32 rsrvd2               :  6 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_MCE_TX_SHARE_FIFO_BASE_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PG_DA_CFG0                     0xf430a15c
#define NI_HV_GLB_PG_DA_CFG0_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mac_addr0            : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PG_DA_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PG_DA_CFG1                     0xf430a160
#define NI_HV_GLB_PG_DA_CFG1_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mac_addr1            :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PG_DA_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PG_SA_CFG0                     0xf430a164
#define NI_HV_GLB_PG_SA_CFG0_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mac_addr0            : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PG_SA_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PG_SA_CFG1                     0xf430a168
#define NI_HV_GLB_PG_SA_CFG1_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mac_addr1            :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PG_SA_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PG_CFG0                        0xf430a16c
#define NI_HV_GLB_PG_CFG0_dft                    0x00648064

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pg_len               : 11 ; /* bits 10:0 */
    u32 rsrvd1               :  4 ;
    u32 pg_len_data          :  1 ; /* bits 15:15 */
    u32 pg_frm_cnt           : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PG_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PG_CFG1                        0xf430a170
#define NI_HV_GLB_PG_CFG1_dft                    0x81008100

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pg_vlan1_tpid        : 16 ; /* bits 15:0 */
    u32 pg_vlan2_tpid        : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PG_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PG_FXPT_CFG                    0xf430a174
#define NI_HV_GLB_PG_FXPT_CFG_dft                0xaaaa5555

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pg_fxpat             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PG_FXPT_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PC_DA1                         0xf430a178
#define NI_HV_GLB_PC_DA1_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pc_da4               :  8 ; /* bits 7:0 */
    u32 pc_da3               :  8 ; /* bits 15:8 */
    u32 pc_da2               :  8 ; /* bits 23:16 */
    u32 pc_da1               :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PC_DA1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PC_DA2                         0xf430a17c
#define NI_HV_GLB_PC_DA2_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pc_da5               :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PC_DA2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PC_SA1                         0xf430a180
#define NI_HV_GLB_PC_SA1_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pc_sa4               :  8 ; /* bits 7:0 */
    u32 pc_sa3               :  8 ; /* bits 15:8 */
    u32 pc_sa2               :  8 ; /* bits 23:16 */
    u32 pc_sa1               :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PC_SA1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PC_SA2                         0xf430a184
#define NI_HV_GLB_PC_SA2_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pc_sa5               :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PC_SA2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PC_CFG0                        0xf430a188
#define NI_HV_GLB_PC_CFG0_dft                    0x00000064

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pc_len               : 11 ; /* bits 10:0 */
    u32 rsrvd1               : 21 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PC_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PC_CFG1                        0xf430a18c
#define NI_HV_GLB_PC_CFG1_dft                    0x81008100

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pc_vlan1_tpid        : 16 ; /* bits 15:0 */
    u32 pc_vlan2_tpid        : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PC_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PC_FXPT                        0xf430a190
#define NI_HV_GLB_PC_FXPT_dft                    0xaaaa5555

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pc_fxpat             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PC_FXPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RM_CFG                         0xf430a194
#define NI_HV_GLB_RM_CFG_dft                     0x2100000a

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rm_en                :  1 ; /* bits 0:0 */
    u32 rm_pid               :  4 ; /* bits 4:1 */
    u32 rsrvd1               :  3 ;
    u32 rm_cntpkts           :  1 ; /* bits 8:8 */
    u32 rm_clrcnt            :  1 ; /* bits 9:9 */
    u32 rm_clrtb             :  1 ; /* bits 10:10 */
    u32 debug_mode           :  1 ; /* bits 11:11 */
    u32 rsrvd2               : 12 ;
    u32 rm_tbinc             :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RM_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RM_TBMAX                       0xf430a198
#define NI_HV_GLB_RM_TBMAX_dft                   0x00ffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rm_tbmax             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RM_TBMAX_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RM_CNTR                        0xf430a19c
#define NI_HV_GLB_RM_CNTR_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rm_cnt               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RM_CNTR_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RM_LASTCNTR                    0xf430a1a0
#define NI_HV_GLB_RM_LASTCNTR_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rm_lastcnt           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RM_LASTCNTR_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMIB_ACCESS                   0xf430a1a4
#define NI_HV_GLB_RXMIB_ACCESS_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 counter_id           :  5 ; /* bits 4:0 */
    u32 port_id              :  3 ; /* bits 7:5 */
    u32 rsrvd1               :  8 ;
    u32 debug_mode           :  1 ; /* bits 16:16 */
    u32 rsrvd2               : 11 ;
    u32 op_code              :  2 ; /* bits 29:28 */
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMIB_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMIB_DATA1                    0xf430a1a8
#define NI_HV_GLB_RXMIB_DATA1_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt_val_hi           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMIB_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXMIB_DATA0                    0xf430a1ac
#define NI_HV_GLB_RXMIB_DATA0_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt_val_lo           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXMIB_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXMIB_ACCESS                   0xf430a1b0
#define NI_HV_GLB_TXMIB_ACCESS_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 counter_id           :  5 ; /* bits 4:0 */
    u32 port_id              :  3 ; /* bits 7:5 */
    u32 rsrvd1               :  8 ;
    u32 debug_mode           :  1 ; /* bits 16:16 */
    u32 rsrvd2               : 11 ;
    u32 op_code              :  2 ; /* bits 29:28 */
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXMIB_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXMIB_DATA1                    0xf430a1b4
#define NI_HV_GLB_TXMIB_DATA1_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt_val_hi           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXMIB_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXMIB_DATA0                    0xf430a1b8
#define NI_HV_GLB_TXMIB_DATA0_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt_val_lo           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXMIB_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_INTERNAL_PORT_ID_CFG           0xf430a1bc
#define NI_HV_GLB_INTERNAL_PORT_ID_CFG_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 l3qmrx_demux_sel     :  8 ; /* bits 7:0 */
    u32 mrr_dsel             :  2 ; /* bits 9:8 */
    u32 mrr_ldpid            :  6 ; /* bits 15:10 */
    u32 mrr_cos              :  3 ; /* bits 18:16 */
    u32 mrr_fe_bypass        :  1 ; /* bits 19:19 */
    u32 l3qmrx_to_lan        :  1 ; /* bits 20:20 */
    u32 egr_mrr_sel          :  1 ; /* bits 21:21 */
    u32 wan_rxsel            :  2 ; /* bits 23:22 */
    u32 dma_to_l3fe          :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_INTERNAL_PORT_ID_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_INTERNAL_PORT_ID_CFG2          0xf430a1c0
#define NI_HV_GLB_INTERNAL_PORT_ID_CFG2_dft      0x0024009b

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mce_lspid            :  6 ; /* bits 5:0 */
    u32 mce_dpq              :  1 ; /* bits 6:6 */
    u32 mce_fe_bypass        :  1 ; /* bits 7:7 */
    u32 mrr_pol_id           :  8 ; /* bits 15:8 */
    u32 mrr_dpq              :  1 ; /* bits 16:16 */
    u32 rsrvd1               :  1 ;
    u32 rx_cpu               :  6 ; /* bits 23:18 */
    u32 rsrvd2               :  8 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_INTERNAL_PORT_ID_CFG2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_L3QMRX_DEMUX_CFG1              0xf430a1c4
#define NI_HV_GLB_L3QMRX_DEMUX_CFG1_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 l3qmrx_demux_sel_enhanced1 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_L3QMRX_DEMUX_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_L3QMRX_DEMUX_CFG0              0xf430a1c8
#define NI_HV_GLB_L3QMRX_DEMUX_CFG0_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 l3qmrx_demux_sel_enhanced0 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_L3QMRX_DEMUX_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_PORT_ID_CFG                 0xf430a1cc
#define NI_HV_GLB_RX_PORT_ID_CFG_dft             0x040c2040

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port0_id             :  6 ; /* bits 5:0 */
    u32 port1_id             :  6 ; /* bits 11:6 */
    u32 port2_id             :  6 ; /* bits 17:12 */
    u32 port3_id             :  6 ; /* bits 23:18 */
    u32 port4_id             :  6 ; /* bits 29:24 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_PORT_ID_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RX_PORT_ID_CFG2                0xf430a1d0
#define NI_HV_GLB_RX_PORT_ID_CFG2_dft            0x00007185

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port5_id             :  6 ; /* bits 5:0 */
    u32 port6_id             :  6 ; /* bits 11:6 */
    u32 port7_id             :  6 ; /* bits 17:12 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RX_PORT_ID_CFG2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NIRX_L3FE_DEMUX_CFG3           0xf430a1d4
#define NI_HV_GLB_NIRX_L3FE_DEMUX_CFG3_dft       0xaaaaaaaa

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 demux_id3            : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NIRX_L3FE_DEMUX_CFG3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NIRX_L3FE_DEMUX_CFG2           0xf430a1d8
#define NI_HV_GLB_NIRX_L3FE_DEMUX_CFG2_dft       0xaaaaaaaa

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 demux_id2            : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NIRX_L3FE_DEMUX_CFG2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NIRX_L3FE_DEMUX_CFG1           0xf430a1dc
#define NI_HV_GLB_NIRX_L3FE_DEMUX_CFG1_dft       0xaaaaaaaa

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 demux_id1            : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NIRX_L3FE_DEMUX_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NIRX_L3FE_DEMUX_CFG0           0xf430a1e0
#define NI_HV_GLB_NIRX_L3FE_DEMUX_CFG0_dft       0xaaaaaaaa

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 demux_id0            : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NIRX_L3FE_DEMUX_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NIRX_L3FE_DPQ_DEMUX_CFG3       0xf430a1e4
#define NI_HV_GLB_NIRX_L3FE_DPQ_DEMUX_CFG3_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 demux_id3            : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NIRX_L3FE_DPQ_DEMUX_CFG3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NIRX_L3FE_DPQ_DEMUX_CFG2       0xf430a1e8
#define NI_HV_GLB_NIRX_L3FE_DPQ_DEMUX_CFG2_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 demux_id2            : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NIRX_L3FE_DPQ_DEMUX_CFG2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NIRX_L3FE_DPQ_DEMUX_CFG1       0xf430a1ec
#define NI_HV_GLB_NIRX_L3FE_DPQ_DEMUX_CFG1_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 demux_id1            : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NIRX_L3FE_DPQ_DEMUX_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NIRX_L3FE_DPQ_DEMUX_CFG0       0xf430a1f0
#define NI_HV_GLB_NIRX_L3FE_DPQ_DEMUX_CFG0_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 demux_id0            : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NIRX_L3FE_DPQ_DEMUX_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NITX_MISC_CFG                  0xf430a1f4
#define NI_HV_GLB_NITX_MISC_CFG_dft              0x00084ffc

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xge6_hdrA_tx_en      :  1 ; /* bits 0:0 */
    u32 xge7_hdrA_tx_en      :  1 ; /* bits 1:1 */
    u32 xge6_tx_rd_thre_en   :  1 ; /* bits 2:2 */
    u32 xge7_tx_rd_thre_en   :  1 ; /* bits 3:3 */
    u32 xaui_tx_rd_thre_en   :  1 ; /* bits 4:4 */
    u32 l3qm_tx_rd_thre_en0  :  1 ; /* bits 5:5 */
    u32 l3qm_tx_rd_thre_en1  :  1 ; /* bits 6:6 */
    u32 l3qm_tx_rd_thre_en3  :  1 ; /* bits 7:7 */
    u32 l3fe_tx_rd_thre_en0  :  1 ; /* bits 8:8 */
    u32 l3fe_tx_rd_thre_en1  :  1 ; /* bits 9:9 */
    u32 l3fe_tx_rd_thre_en2  :  1 ; /* bits 10:10 */
    u32 l3fe_tx_rd_thre_en3  :  1 ; /* bits 11:11 */
    u32 xge6_link_fault_halt_tx_en :  1 ; /* bits 12:12 */
    u32 rsrvd1               :  1 ;
    u32 time_base_cnt        :  6 ; /* bits 19:14 */
    u32 xge6_tx_drain        :  1 ; /* bits 20:20 */
    u32 xge7_tx_drain        :  1 ; /* bits 21:21 */
    u32 xaui5_tx_drain       :  1 ; /* bits 22:22 */
    u32 rsrvd2               :  9 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NITX_MISC_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NIRX_MISC_CFG                  0xf430a1f8
#define NI_HV_GLB_NIRX_MISC_CFG_dft              0x00010080

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 l3fe_to_l2fe_deepq_csr0 :  1 ; /* bits 0:0 */
    u32 l3fe_to_l2fe_deepq_csr1 :  1 ; /* bits 1:1 */
    u32 l3fe_to_l2fe_deepq_csr2 :  1 ; /* bits 2:2 */
    u32 l3fe_to_l3qm_l4cs_err_en :  1 ; /* bits 3:3 */
    u32 l3fe_to_l2tm_l4cs_err_en :  1 ; /* bits 4:4 */
    u32 l3fe_l3qm_to_l2tm_sel :  1 ; /* bits 5:5 */
    u32 l3fe_l3qm_to_l2tm_bp_en :  1 ; /* bits 6:6 */
    u32 l3fe_l3qm_to_l2tm_arb_en :  1 ; /* bits 7:7 */
    u32 rsrvd1               :  1 ;
    u32 l2te_ni_mc_rdy_en    :  1 ; /* bits 9:9 */
    u32 l2te_ni_l3fewan_port_rdy_en :  1 ; /* bits 10:10 */
    u32 l2te_ni_l3felan_port_rdy_en :  1 ; /* bits 11:11 */
    u32 l2te_ni_txdma_l2fe_rdy_en :  1 ; /* bits 12:12 */
    u32 l2te_ni_txdma_l3fe_rdy_en :  1 ; /* bits 13:13 */
    u32 rsrvd2               :  2 ;
    u32 xge6_rx_errpkt_drp_en :  1 ; /* bits 16:16 */
    u32 rsrvd3               :  1 ;
    u32 l3fe_to_wan_l4cs_err_en :  1 ; /* bits 18:18 */
    u32 l3fe_to_l2fe_l4cs_err_en :  1 ; /* bits 19:19 */
    u32 use_p0_as_wan_port_en :  1 ; /* bits 20:20 */
    u32 p0_as_wan_encap_decap_en :  1 ; /* bits 21:21 */
    u32 rsrvd4               : 10 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NIRX_MISC_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TX_PORT_ID_CFG                 0xf430a1fc
#define NI_HV_GLB_TX_PORT_ID_CFG_dft             0x76543210

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port0_id             :  4 ; /* bits 3:0 */
    u32 port1_id             :  4 ; /* bits 7:4 */
    u32 port2_id             :  4 ; /* bits 11:8 */
    u32 port3_id             :  4 ; /* bits 15:12 */
    u32 port4_id             :  4 ; /* bits 19:16 */
    u32 port5_id             :  4 ; /* bits 23:20 */
    u32 port6_id             :  4 ; /* bits 27:24 */
    u32 port7_id             :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TX_PORT_ID_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TX_INTERNAL_PORT_ID_CFG        0xf430a200
#define NI_HV_GLB_TX_INTERNAL_PORT_ID_CFG_dft    0x00cbda98

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 l3qm_tx_dpid0        :  4 ; /* bits 3:0 */
    u32 l3qm_tx_dpid1        :  4 ; /* bits 7:4 */
    u32 l3fe_tx_dpid0        :  4 ; /* bits 11:8 */
    u32 l3fe_tx_dpid1        :  4 ; /* bits 15:12 */
    u32 mce_tx_dpid          :  4 ; /* bits 19:16 */
    u32 oam_tx_dpid          :  4 ; /* bits 23:20 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TX_INTERNAL_PORT_ID_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TX_INTERNAL_PORT_ID_CFG2       0xf430a204
#define NI_HV_GLB_TX_INTERNAL_PORT_ID_CFG2_dft   0x7000da98

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 l3qm_tx_spid0        :  4 ; /* bits 3:0 */
    u32 l3qm_tx_spid1        :  4 ; /* bits 7:4 */
    u32 l3fe_tx_spid0        :  4 ; /* bits 11:8 */
    u32 l3fe_tx_spid1        :  4 ; /* bits 15:12 */
    u32 rsrvd1               :  8 ;
    u32 l3fe_tx_spid2        :  4 ; /* bits 27:24 */
    u32 l3fe_tx_spid3        :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TX_INTERNAL_PORT_ID_CFG2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NITX_CRCE_CNT                  0xf430a208
#define NI_HV_GLB_NITX_CRCE_CNT_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 crce_cnt             : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NITX_CRCE_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NITX_P5_DRAINCNT               0xf430a20c
#define NI_HV_GLB_NITX_P5_DRAINCNT_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 drain_cnt            : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NITX_P5_DRAINCNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NITX_P6_DRAINCNT               0xf430a210
#define NI_HV_GLB_NITX_P6_DRAINCNT_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 drain_cnt            : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NITX_P6_DRAINCNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NITX_P7_DRAINCNT               0xf430a214
#define NI_HV_GLB_NITX_P7_DRAINCNT_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 drain_cnt            : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NITX_P7_DRAINCNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NITX_OAMERR_CNT                0xf430a218
#define NI_HV_GLB_NITX_OAMERR_CNT_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 oame_cnt             : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NITX_OAMERR_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_READ_THRESHOLD          0xf430a21c
#define NI_HV_GLB_TXFIFO_READ_THRESHOLD_dft      0x64503c28

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rxaui_txfifo_lo      :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 rxaui_txfifo_hi      :  7 ; /* bits 14:8 */
    u32 rsrvd2               :  1 ;
    u32 xge6_txfifo_lo       :  7 ; /* bits 22:16 */
    u32 rsrvd3               :  1 ;
    u32 xge6_txfifo_hi       :  7 ; /* bits 30:24 */
    u32 rsrvd4               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_READ_THRESHOLD_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_READ_THRESHOLD_2        0xf430a220
#define NI_HV_GLB_TXFIFO_READ_THRESHOLD_2_dft    0x71507150

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rxaui_txfifo_lo_2    :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 rxaui_txfifo_hi_2    :  7 ; /* bits 14:8 */
    u32 rsrvd2               :  1 ;
    u32 xge6_txfifo_lo_2     :  7 ; /* bits 22:16 */
    u32 rsrvd3               :  1 ;
    u32 xge6_txfifo_hi_2     :  7 ; /* bits 30:24 */
    u32 rsrvd4               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_READ_THRESHOLD_2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_READ_THRESHOLD_3        0xf430a224
#define NI_HV_GLB_TXFIFO_READ_THRESHOLD_3_dft    0x71507150

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p1_txfifo_lo         :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 p1_txfifo_hi         :  7 ; /* bits 14:8 */
    u32 rsrvd2               :  1 ;
    u32 p0_txfifo_lo         :  7 ; /* bits 22:16 */
    u32 rsrvd3               :  1 ;
    u32 p0_txfifo_hi         :  7 ; /* bits 30:24 */
    u32 rsrvd4               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_READ_THRESHOLD_3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_READ_THRESHOLD_4        0xf430a228
#define NI_HV_GLB_TXFIFO_READ_THRESHOLD_4_dft    0x71507150

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p3_txfifo_lo         :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 p3_txfifo_hi         :  7 ; /* bits 14:8 */
    u32 rsrvd2               :  1 ;
    u32 p2_txfifo_lo         :  7 ; /* bits 22:16 */
    u32 rsrvd3               :  1 ;
    u32 p2_txfifo_hi         :  7 ; /* bits 30:24 */
    u32 rsrvd4               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_READ_THRESHOLD_4_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_READ_THRESHOLD_5        0xf430a22c
#define NI_HV_GLB_TXFIFO_READ_THRESHOLD_5_dft    0x71500000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               : 16 ;
    u32 p4_txfifo_lo         :  7 ; /* bits 22:16 */
    u32 rsrvd2               :  1 ;
    u32 p4_txfifo_hi         :  7 ; /* bits 30:24 */
    u32 rsrvd3               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_READ_THRESHOLD_5_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_QM2LAN_CTRL_0           0xf430a230
#define NI_HV_GLB_TXFIFO_QM2LAN_CTRL_0_dft       0x0d090640

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 qm2lan_max_len       : 14 ; /* bits 13:0 */
    u32 rsrvd1               :  2 ;
    u32 p0_txfifo_tff_lo     :  7 ; /* bits 22:16 */
    u32 rsrvd2               :  1 ;
    u32 p0_txfifo_tff_hi     :  7 ; /* bits 30:24 */
    u32 rsrvd3               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_QM2LAN_CTRL_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_QM2LAN_CTRL_1           0xf430a234
#define NI_HV_GLB_TXFIFO_QM2LAN_CTRL_1_dft       0x0d090d09

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p1_txfifo_tff_lo     :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 p1_txfifo_tff_hi     :  7 ; /* bits 14:8 */
    u32 rsrvd2               :  1 ;
    u32 p2_txfifo_tff_lo     :  7 ; /* bits 22:16 */
    u32 rsrvd3               :  1 ;
    u32 p2_txfifo_tff_hi     :  7 ; /* bits 30:24 */
    u32 rsrvd4               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_QM2LAN_CTRL_1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_QM2LAN_CTRL_2           0xf430a238
#define NI_HV_GLB_TXFIFO_QM2LAN_CTRL_2_dft       0x0d090d09

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p3_txfifo_tff_lo     :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 p3_txfifo_tff_hi     :  7 ; /* bits 14:8 */
    u32 rsrvd2               :  1 ;
    u32 p4_txfifo_tff_lo     :  7 ; /* bits 22:16 */
    u32 rsrvd3               :  1 ;
    u32 p4_txfifo_tff_hi     :  7 ; /* bits 30:24 */
    u32 rsrvd4               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_QM2LAN_CTRL_2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_QM2LAN_CTRL_3           0xf430a23c
#define NI_HV_GLB_TXFIFO_QM2LAN_CTRL_3_dft       0x0d090d09

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p5_txfifo_tff_lo     :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 p5_txfifo_tff_hi     :  7 ; /* bits 14:8 */
    u32 rsrvd2               :  1 ;
    u32 p6_txfifo_tff_lo     :  7 ; /* bits 22:16 */
    u32 rsrvd3               :  1 ;
    u32 p6_txfifo_tff_hi     :  7 ; /* bits 30:24 */
    u32 rsrvd4               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_QM2LAN_CTRL_3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_THRESHOLD_XGE7_CFG1     0xf430a240
#define NI_HV_GLB_TXFIFO_THRESHOLD_XGE7_CFG1_dft 0x780c7864

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 from_l3fe_txfifo_lo  :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 from_l3fe_txfifo_hi  :  7 ; /* bits 14:8 */
    u32 rsrvd2               :  1 ;
    u32 from_l3qm_txfifo_lo  :  7 ; /* bits 22:16 */
    u32 rsrvd3               :  1 ;
    u32 from_l3qm_txfifo_hi  :  7 ; /* bits 30:24 */
    u32 rsrvd4               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_THRESHOLD_XGE7_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_THRESHOLD_XGE7_CFG2     0xf430a244
#define NI_HV_GLB_TXFIFO_THRESHOLD_XGE7_CFG2_dft 0x78a3e8c8

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rd_thre_txfifo_lo    :  9 ; /* bits 8:0 */
    u32 rd_thre_txfifo_hi    :  9 ; /* bits 17:9 */
    u32 from_tm_txfifo_lo    :  7 ; /* bits 24:18 */
    u32 from_tm_txfifo_hi    :  7 ; /* bits 31:25 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_THRESHOLD_XGE7_CFG2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_THRESHOLD_L3QM_CFG1     0xf430a248
#define NI_HV_GLB_TXFIFO_THRESHOLD_L3QM_CFG1_dft 0x60506050

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 from_tm9_txfifo_lo   :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 from_tm9_txfifo_hi   :  7 ; /* bits 14:8 */
    u32 rsrvd2               :  1 ;
    u32 from_tm8_txfifo_lo   :  7 ; /* bits 22:16 */
    u32 rsrvd3               :  1 ;
    u32 from_tm8_txfifo_hi   :  7 ; /* bits 30:24 */
    u32 rsrvd4               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_THRESHOLD_L3QM_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_THRESHOLD_L3QM_CFG2     0xf430a24c
#define NI_HV_GLB_TXFIFO_THRESHOLD_L3QM_CFG2_dft 0x00006050

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 from_l3fe_txfifo_lo  :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 from_l3fe_txfifo_hi  :  7 ; /* bits 14:8 */
    u32 rsrvd2               : 17 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_THRESHOLD_L3QM_CFG2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_THRESHOLD_L3FE_CFG1     0xf430a250
#define NI_HV_GLB_TXFIFO_THRESHOLD_L3FE_CFG1_dft 0xaa6c6b6a

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 from_wan_txfifo_lo   :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 from_wan_txfifo_hi   :  7 ; /* bits 14:8 */
    u32 rsrvd2               :  1 ;
    u32 from_tm_txfifo_lo    :  8 ; /* bits 23:16 */
    u32 from_tm_txfifo_hi    :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_THRESHOLD_L3FE_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_THRESHOLD_L3FE_CFG2     0xf430a254
#define NI_HV_GLB_TXFIFO_THRESHOLD_L3FE_CFG2_dft 0x0400f06e

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 from_dma_txfifo_lo   :  8 ; /* bits 7:0 */
    u32 from_dma_txfifo_hi   :  8 ; /* bits 15:8 */
    u32 tm2_shared_fifo_lo   :  6 ; /* bits 21:16 */
    u32 tm2_shared_fifo_hi   :  6 ; /* bits 27:22 */
    u32 rsrvd1               :  4 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_THRESHOLD_L3FE_CFG2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_THRESHOLD_MISC_CFG      0xf430a258
#define NI_HV_GLB_TXFIFO_THRESHOLD_MISC_CFG_dft  0x3c280000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               : 16 ;
    u32 oam_from_tm_txfifo_lo :  7 ; /* bits 22:16 */
    u32 rsrvd2               :  1 ;
    u32 oam_from_tm_txfifo_hi :  7 ; /* bits 30:24 */
    u32 rsrvd3               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_THRESHOLD_MISC_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_THRESHOLD_MISC_CFG2     0xf430a25c
#define NI_HV_GLB_TXFIFO_THRESHOLD_MISC_CFG2_dft 0x50285028

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 txfifo_l3qm_path0_lo :  8 ; /* bits 7:0 */
    u32 txfifo_l3qm_path0_hi :  8 ; /* bits 15:8 */
    u32 txfifo_l3qm_path1_lo :  8 ; /* bits 23:16 */
    u32 txfifo_l3qm_path1_hi :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_THRESHOLD_MISC_CFG2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_THRESHOLD_MISC_CFG3     0xf430a260
#define NI_HV_GLB_TXFIFO_THRESHOLD_MISC_CFG3_dft 0x00005028

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 txfifo_l3qm_path2_lo :  8 ; /* bits 7:0 */
    u32 txfifo_l3qm_path2_hi :  8 ; /* bits 15:8 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_THRESHOLD_MISC_CFG3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXFIFO_MCE_THRESHOLD_CFG       0xf430a264
#define NI_HV_GLB_TXFIFO_MCE_THRESHOLD_CFG_dft   0x00019028

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mce_from_tm_txfifo_lo : 10 ; /* bits 9:0 */
    u32 mce_from_tm_txfifo_hi : 10 ; /* bits 19:10 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXFIFO_MCE_THRESHOLD_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXFIFO_THRESHOLD_MISC_CFG      0xf430a268
#define NI_HV_GLB_RXFIFO_THRESHOLD_MISC_CFG_dft  0x780a780a

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 l3fe_rxfifo_lo       :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 l3fe_rxfifo_hi       :  7 ; /* bits 14:8 */
    u32 rsrvd2               :  1 ;
    u32 l3qm_rxfifo_lo       :  7 ; /* bits 22:16 */
    u32 rsrvd3               :  1 ;
    u32 l3qm_rxfifo_hi       :  7 ; /* bits 30:24 */
    u32 rsrvd4               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXFIFO_THRESHOLD_MISC_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_RXFIFO_XGE6_THRESHOLD_CFG      0xf430a26c
#define NI_HV_GLB_RXFIFO_XGE6_THRESHOLD_CFG_dft  0x0003c00a

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 thre_lo              :  9 ; /* bits 8:0 */
    u32 thre_hi              :  9 ; /* bits 17:9 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_RXFIFO_XGE6_THRESHOLD_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NIRX_L3QM_THRESHOLD_CFG        0xf430a270
#define NI_HV_GLB_NIRX_L3QM_THRESHOLD_CFG_dft    0x00008080

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 l2tm_fifo_thre       :  8 ; /* bits 7:0 */
    u32 wan_fifo_thre        :  8 ; /* bits 15:8 */
    u32 dis_fifo_thre        :  1 ; /* bits 16:16 */
    u32 rsrvd1               : 15 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NIRX_L3QM_THRESHOLD_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PTP_TX_CFG                     0xf430a274
#define NI_HV_GLB_PTP_TX_CFG_dft                 0x0000007f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p0_ptp_tx_en         :  1 ; /* bits 0:0 */
    u32 p1_ptp_tx_en         :  1 ; /* bits 1:1 */
    u32 p2_ptp_tx_en         :  1 ; /* bits 2:2 */
    u32 p3_ptp_tx_en         :  1 ; /* bits 3:3 */
    u32 p4_ptp_tx_en         :  1 ; /* bits 4:4 */
    u32 p5_ptp_tx_en         :  1 ; /* bits 5:5 */
    u32 p6_ptp_tx_en         :  1 ; /* bits 6:6 */
    u32 rsrvd1               :  1 ;
    u32 p0_ptp_tx_bypass     :  1 ; /* bits 8:8 */
    u32 p1_ptp_tx_bypass     :  1 ; /* bits 9:9 */
    u32 p2_ptp_tx_bypass     :  1 ; /* bits 10:10 */
    u32 p3_ptp_tx_bypass     :  1 ; /* bits 11:11 */
    u32 p4_ptp_tx_bypass     :  1 ; /* bits 12:12 */
    u32 p5_ptp_tx_bypass     :  1 ; /* bits 13:13 */
    u32 p6_ptp_tx_bypass     :  1 ; /* bits 14:14 */
    u32 rsrvd2               : 17 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PTP_TX_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_GE_PTP_ASYM_CFG_01             0xf430a278
#define NI_HV_GLB_GE_PTP_ASYM_CFG_01_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_01          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_GE_PTP_ASYM_CFG_01_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_GE_PTP_ASYM_CFG_00             0xf430a27c
#define NI_HV_GLB_GE_PTP_ASYM_CFG_00_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_00          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_GE_PTP_ASYM_CFG_00_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_GE_PTP_ASYM_CFG_11             0xf430a280
#define NI_HV_GLB_GE_PTP_ASYM_CFG_11_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_11          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_GE_PTP_ASYM_CFG_11_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_GE_PTP_ASYM_CFG_10             0xf430a284
#define NI_HV_GLB_GE_PTP_ASYM_CFG_10_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_10          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_GE_PTP_ASYM_CFG_10_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_GE_PTP_ASYM_CFG_21             0xf430a288
#define NI_HV_GLB_GE_PTP_ASYM_CFG_21_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_21          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_GE_PTP_ASYM_CFG_21_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_GE_PTP_ASYM_CFG_20             0xf430a28c
#define NI_HV_GLB_GE_PTP_ASYM_CFG_20_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_20          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_GE_PTP_ASYM_CFG_20_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_GE_PTP_ASYM_CFG_31             0xf430a290
#define NI_HV_GLB_GE_PTP_ASYM_CFG_31_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_31          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_GE_PTP_ASYM_CFG_31_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_GE_PTP_ASYM_CFG_30             0xf430a294
#define NI_HV_GLB_GE_PTP_ASYM_CFG_30_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_30          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_GE_PTP_ASYM_CFG_30_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_01           0xf430a298
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_01_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_01          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XAUI_PTP_ASYM_CFG_01_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_00           0xf430a29c
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_00_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_00          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XAUI_PTP_ASYM_CFG_00_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_11           0xf430a2a0
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_11_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_11          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XAUI_PTP_ASYM_CFG_11_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_10           0xf430a2a4
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_10_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_10          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XAUI_PTP_ASYM_CFG_10_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_21           0xf430a2a8
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_21_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_21          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XAUI_PTP_ASYM_CFG_21_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_20           0xf430a2ac
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_20_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_20          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XAUI_PTP_ASYM_CFG_20_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_31           0xf430a2b0
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_31_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_31          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XAUI_PTP_ASYM_CFG_31_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_30           0xf430a2b4
#define NI_HV_GLB_XAUI_PTP_ASYM_CFG_30_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_30          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XAUI_PTP_ASYM_CFG_30_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_01            0xf430a2b8
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_01_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_01          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE_PTP_ASYM_CFG_01_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_00            0xf430a2bc
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_00_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_00          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE_PTP_ASYM_CFG_00_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_11            0xf430a2c0
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_11_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_11          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE_PTP_ASYM_CFG_11_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_10            0xf430a2c4
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_10_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_10          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE_PTP_ASYM_CFG_10_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_21            0xf430a2c8
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_21_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_21          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE_PTP_ASYM_CFG_21_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_20            0xf430a2cc
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_20_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_20          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE_PTP_ASYM_CFG_20_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_31            0xf430a2d0
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_31_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_31          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE_PTP_ASYM_CFG_31_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_30            0xf430a2d4
#define NI_HV_GLB_XGE_PTP_ASYM_CFG_30_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asym_cfg_30          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_XGE_PTP_ASYM_CFG_30_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_P0_PTP_TX_TIMESTAMP_SEC1       0xf430a2d8
#define NI_HV_GLB_P0_PTP_TX_TIMESTAMP_SEC1_STRIDE 12
#define NI_HV_GLB_P0_PTP_TX_TIMESTAMP_SEC1_COUNT 7
#define NI_HV_GLB_P0_PTP_TX_TIMESTAMP_SEC1_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_ts_sec1           : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_P0_PTP_TX_TIMESTAMP_SEC1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_P0_PTP_TX_TIMESTAMP_SEC0       0xf430a2dc
#define NI_HV_GLB_P0_PTP_TX_TIMESTAMP_SEC0_STRIDE 12
#define NI_HV_GLB_P0_PTP_TX_TIMESTAMP_SEC0_COUNT 7
#define NI_HV_GLB_P0_PTP_TX_TIMESTAMP_SEC0_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_ts_sec0           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_P0_PTP_TX_TIMESTAMP_SEC0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_P0_PTP_TX_TIMESTAMP            0xf430a2e0
#define NI_HV_GLB_P0_PTP_TX_TIMESTAMP_STRIDE     12
#define NI_HV_GLB_P0_PTP_TX_TIMESTAMP_COUNT      7
#define NI_HV_GLB_P0_PTP_TX_TIMESTAMP_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_ts                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_P0_PTP_TX_TIMESTAMP_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NITX_STS                       0xf430a32c
#define NI_HV_GLB_NITX_STS_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sts                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NITX_STS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SPARE                          0xf430a330
#define NI_HV_GLB_SPARE_dft                      0x0000ff33

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 VALUE                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SPARE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_MISC_STS                       0xf430a334
#define NI_HV_GLB_MISC_STS_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xge6_link_fault      :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_MISC_STS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SPARESAMPLE                    0xf430a338
#define NI_HV_GLB_SPARESAMPLE_dft                0x0000ff00

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 VALUE                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SPARESAMPLE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PORT_0_INTERRUPT               0xf430a33c
#define NI_HV_GLB_PORT_0_INTERRUPT_STRIDE        8
#define NI_HV_GLB_PORT_0_INTERRUPT_COUNT         6
#define NI_HV_GLB_PORT_0_INTERRUPT_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 link_stat_chgI       :  1 ; /* bits 0:0 */
    u32 txfifo_underrunI     :  1 ; /* bits 1:1 */
    u32 txfifo_overrunI      :  1 ; /* bits 2:2 */
    u32 rxcntrl_overrunI     :  1 ; /* bits 3:3 */
    u32 rsrvd1               :  1 ;
    u32 rxmib_cntmsb_setI    :  1 ; /* bits 5:5 */
    u32 txmib_cntmsb_setI    :  1 ; /* bits 6:6 */
    u32 rsrvd2               :  2 ;
    u32 lpi_assert_stat_chgI :  1 ; /* bits 9:9 */
    u32 rx_lpi_stat_chgI     :  1 ; /* bits 10:10 */
    u32 rsrvd3               :  2 ;
    u32 ni_wol_int           :  1 ; /* bits 13:13 */
    u32 rsrvd4               : 18 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PORT_0_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PORT_0_INTERRUPTE              0xf430a340
#define NI_HV_GLB_PORT_0_INTERRUPTE_STRIDE       8
#define NI_HV_GLB_PORT_0_INTERRUPTE_COUNT        6
#define NI_HV_GLB_PORT_0_INTERRUPTE_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 link_stat_chgIE      :  1 ; /* bits 0:0 */
    u32 txfifo_underrunIE    :  1 ; /* bits 1:1 */
    u32 txfifo_overrunIE     :  1 ; /* bits 2:2 */
    u32 rxcntrl_overrunIE    :  1 ; /* bits 3:3 */
    u32 rsrvd1               :  1 ;
    u32 rxmib_cntmsb_setIE   :  1 ; /* bits 5:5 */
    u32 txmib_cntmsb_setIE   :  1 ; /* bits 6:6 */
    u32 rsrvd2               :  2 ;
    u32 lpi_assert_stat_chgIE :  1 ; /* bits 9:9 */
    u32 rx_lpi_stat_chgIE    :  1 ; /* bits 10:10 */
    u32 rsrvd3               :  2 ;
    u32 ni_wol_intE          :  1 ; /* bits 13:13 */
    u32 rsrvd4               : 18 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PORT_0_INTERRUPTE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PORT_6_INTERRUPT               0xf430a36c
#define NI_HV_GLB_PORT_6_INTERRUPT_STRIDE        8
#define NI_HV_GLB_PORT_6_INTERRUPT_COUNT         2
#define NI_HV_GLB_PORT_6_INTERRUPT_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  3 ;
    u32 rxcntrl_overrunI     :  1 ; /* bits 3:3 */
    u32 rsrvd2               :  1 ;
    u32 rxmib_cntmsb_setI    :  1 ; /* bits 5:5 */
    u32 txmib_cntmsb_setI    :  1 ; /* bits 6:6 */
    u32 rsrvd3               : 25 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PORT_6_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PORT_6_INTERRUPTE              0xf430a370
#define NI_HV_GLB_PORT_6_INTERRUPTE_STRIDE       8
#define NI_HV_GLB_PORT_6_INTERRUPTE_COUNT        2
#define NI_HV_GLB_PORT_6_INTERRUPTE_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  3 ;
    u32 rxcntrl_overrunIE    :  1 ; /* bits 3:3 */
    u32 rsrvd2               :  1 ;
    u32 rxmib_cntmsb_setIE   :  1 ; /* bits 5:5 */
    u32 txmib_cntmsb_setIE   :  1 ; /* bits 6:6 */
    u32 rsrvd3               : 25 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PORT_6_INTERRUPTE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PORT_8_INTERRUPT               0xf430a37c
#define NI_HV_GLB_PORT_8_INTERRUPT_STRIDE        8
#define NI_HV_GLB_PORT_8_INTERRUPT_COUNT         4
#define NI_HV_GLB_PORT_8_INTERRUPT_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  3 ;
    u32 rxcntrl_overrunI     :  1 ; /* bits 3:3 */
    u32 rsrvd2               :  1 ;
    u32 rxmib_cntmsb_setI    :  1 ; /* bits 5:5 */
    u32 txmib_cntmsb_setI    :  1 ; /* bits 6:6 */
    u32 rsrvd3               : 25 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PORT_8_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PORT_8_INTERRUPTE              0xf430a380
#define NI_HV_GLB_PORT_8_INTERRUPTE_STRIDE       8
#define NI_HV_GLB_PORT_8_INTERRUPTE_COUNT        4
#define NI_HV_GLB_PORT_8_INTERRUPTE_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  3 ;
    u32 rxcntrl_overrunIE    :  1 ; /* bits 3:3 */
    u32 rsrvd2               :  1 ;
    u32 rxmib_cntmsb_setIE   :  1 ; /* bits 5:5 */
    u32 txmib_cntmsb_setIE   :  1 ; /* bits 6:6 */
    u32 rsrvd3               : 25 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PORT_8_INTERRUPTE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NIFIFO_INTERRUPT               0xf430a39c
#define NI_HV_GLB_NIFIFO_INTERRUPT_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p0_nitx_fifo_under_run_setI :  1 ; /* bits 0:0 */
    u32 p0_nitx_fifo_over_run_setI :  1 ; /* bits 1:1 */
    u32 p1_nitx_fifo_under_run_setI :  1 ; /* bits 2:2 */
    u32 p1_nitx_fifo_over_run_setI :  1 ; /* bits 3:3 */
    u32 p2_nitx_fifo_under_run_setI :  1 ; /* bits 4:4 */
    u32 p2_nitx_fifo_over_run_setI :  1 ; /* bits 5:5 */
    u32 p3_nitx_fifo_under_run_setI :  1 ; /* bits 6:6 */
    u32 p3_nitx_fifo_over_run_setI :  1 ; /* bits 7:7 */
    u32 p4_nitx_fifo_under_run_setI :  1 ; /* bits 8:8 */
    u32 p4_nitx_fifo_over_run_setI :  1 ; /* bits 9:9 */
    u32 p5_nitx_fifo_under_run_setI :  1 ; /* bits 10:10 */
    u32 p5_nitx_fifo_over_run_setI :  1 ; /* bits 11:11 */
    u32 p6_nitx_fifo_under_run_setI :  1 ; /* bits 12:12 */
    u32 p6_nitx_fifo_over_run_setI :  1 ; /* bits 13:13 */
    u32 p7_nitx_fifo_under_run_setI :  1 ; /* bits 14:14 */
    u32 p7_nitx_fifo_over_run_setI :  1 ; /* bits 15:15 */
    u32 p8_nitx_fifo_under_run_setI :  1 ; /* bits 16:16 */
    u32 p8_nitx_fifo_over_run_setI :  1 ; /* bits 17:17 */
    u32 p9_nitx_fifo_under_run_setI :  1 ; /* bits 18:18 */
    u32 p9_nitx_fifo_over_run_setI :  1 ; /* bits 19:19 */
    u32 p10_nitx_fifo_under_run_setI :  1 ; /* bits 20:20 */
    u32 p10_nitx_fifo_over_run_setI :  1 ; /* bits 21:21 */
    u32 p11_nitx_fifo_under_run_setI :  1 ; /* bits 22:22 */
    u32 p11_nitx_fifo_over_run_setI :  1 ; /* bits 23:23 */
    u32 p12_nitx_fifo_under_run_setI :  1 ; /* bits 24:24 */
    u32 p12_nitx_fifo_over_run_setI :  1 ; /* bits 25:25 */
    u32 p13_nitx_fifo_under_run_setI :  1 ; /* bits 26:26 */
    u32 p13_nitx_fifo_over_run_setI :  1 ; /* bits 27:27 */
    u32 l3qm_nirx_fifo_under_run_setI :  1 ; /* bits 28:28 */
    u32 l3qm_nirx_fifo_over_run_setI :  1 ; /* bits 29:29 */
    u32 l3fe_nirx_fifo_under_run_setI :  1 ; /* bits 30:30 */
    u32 l3fe_nirx_fifo_over_run_setI :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NIFIFO_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_NIFIFO_INTERRUPTE              0xf430a3a0
#define NI_HV_GLB_NIFIFO_INTERRUPTE_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p0_nitx_fifo_under_run_setIE :  1 ; /* bits 0:0 */
    u32 p0_nitx_fifo_over_run_setIE :  1 ; /* bits 1:1 */
    u32 p1_nitx_fifo_under_run_setIE :  1 ; /* bits 2:2 */
    u32 p1_nitx_fifo_over_run_setIE :  1 ; /* bits 3:3 */
    u32 p2_nitx_fifo_under_run_setIE :  1 ; /* bits 4:4 */
    u32 p2_nitx_fifo_over_run_setIE :  1 ; /* bits 5:5 */
    u32 p3_nitx_fifo_under_run_setIE :  1 ; /* bits 6:6 */
    u32 p3_nitx_fifo_over_run_setIE :  1 ; /* bits 7:7 */
    u32 p4_nitx_fifo_under_run_setIE :  1 ; /* bits 8:8 */
    u32 p4_nitx_fifo_over_run_setIE :  1 ; /* bits 9:9 */
    u32 p5_nitx_fifo_under_run_setIE :  1 ; /* bits 10:10 */
    u32 p5_nitx_fifo_over_run_setIE :  1 ; /* bits 11:11 */
    u32 p6_nitx_fifo_under_run_setIE :  1 ; /* bits 12:12 */
    u32 p6_nitx_fifo_over_run_setIE :  1 ; /* bits 13:13 */
    u32 p7_nitx_fifo_under_run_setIE :  1 ; /* bits 14:14 */
    u32 p7_nitx_fifo_over_run_setIE :  1 ; /* bits 15:15 */
    u32 p8_nitx_fifo_under_run_setIE :  1 ; /* bits 16:16 */
    u32 p8_nitx_fifo_over_run_setIE :  1 ; /* bits 17:17 */
    u32 p9_nitx_fifo_under_run_setIE :  1 ; /* bits 18:18 */
    u32 p9_nitx_fifo_over_run_setIE :  1 ; /* bits 19:19 */
    u32 p10_nitx_fifo_under_run_setIE :  1 ; /* bits 20:20 */
    u32 p10_nitx_fifo_over_run_setIE :  1 ; /* bits 21:21 */
    u32 p11_nitx_fifo_under_run_setIE :  1 ; /* bits 22:22 */
    u32 p11_nitx_fifo_over_run_setIE :  1 ; /* bits 23:23 */
    u32 p12_nitx_fifo_under_run_setIE :  1 ; /* bits 24:24 */
    u32 p12_nitx_fifo_over_run_setIE :  1 ; /* bits 25:25 */
    u32 p13_nitx_fifo_under_run_setIE :  1 ; /* bits 26:26 */
    u32 p13_nitx_fifo_over_run_setIE :  1 ; /* bits 27:27 */
    u32 l3qm_nirx_fifo_under_run_setIE :  1 ; /* bits 28:28 */
    u32 l3qm_nirx_fifo_over_run_setIE :  1 ; /* bits 29:29 */
    u32 l3fe_nirx_fifo_under_run_setIE :  1 ; /* bits 30:30 */
    u32 l3fe_nirx_fifo_over_run_setIE :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_NIFIFO_INTERRUPTE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_MISC_INTERRUPT                 0xf430a3a4
#define NI_HV_GLB_MISC_INTERRUPT_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xge6_link_faultI     :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  1 ;
    u32 l2tm_nitx_overrunI   :  1 ; /* bits 2:2 */
    u32 rsrvd2               :  1 ;
    u32 c10_dec_asm_fifo_overflowI :  1 ; /* bits 4:4 */
    u32 c10_dec_sep_fifo_overflowI :  1 ; /* bits 5:5 */
    u32 c10_dec_hdr_fifo_overflowI :  1 ; /* bits 6:6 */
    u32 rsrvd3               : 25 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_MISC_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_MISC_INTERRUPTE                0xf430a3a8
#define NI_HV_GLB_MISC_INTERRUPTE_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xge6_link_faultIE    :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  1 ;
    u32 l2tm_nitx_overrunIE  :  1 ; /* bits 2:2 */
    u32 rsrvd2               :  1 ;
    u32 c10_dec_asm_fifo_overflowIE :  1 ; /* bits 4:4 */
    u32 c10_dec_sep_fifo_overflowIE :  1 ; /* bits 5:5 */
    u32 c10_dec_hdr_fifo_overflowIE :  1 ; /* bits 6:6 */
    u32 rsrvd3               : 25 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_MISC_INTERRUPTE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXEM_INTERRUPT                 0xf430a3ac
#define NI_HV_GLB_TXEM_INTERRUPT_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 txem_ififo_ovfI      :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  1 ;
    u32 txrm_cntovfI         :  1 ; /* bits 2:2 */
    u32 txmib_fifo_ovfI      :  1 ; /* bits 3:3 */
    u32 rxmib_fifo_ovfI      :  1 ; /* bits 4:4 */
    u32 txem_ptp_voqchg_errI :  1 ; /* bits 5:5 */
    u32 txem_ptp_cachevoq_errI :  1 ; /* bits 6:6 */
    u32 rsrvd2               :  2 ;
    u32 txem_ptp_v6csum0_errI :  1 ; /* bits 9:9 */
    u32 txrm_timerexpI       :  1 ; /* bits 10:10 */
    u32 nitx_crc_errI        :  1 ; /* bits 11:11 */
    u32 rsrvd3               : 20 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXEM_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_TXEM_INTERRUPTE                0xf430a3b0
#define NI_HV_GLB_TXEM_INTERRUPTE_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 txem_ififo_ovfIE     :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  1 ;
    u32 txrm_cntovfIE        :  1 ; /* bits 2:2 */
    u32 txmib_fifo_ovfIE     :  1 ; /* bits 3:3 */
    u32 rxmib_fifo_ovfIE     :  1 ; /* bits 4:4 */
    u32 txem_ptp_voqchg_errIE :  1 ; /* bits 5:5 */
    u32 txem_ptp_cachevoq_errIE :  1 ; /* bits 6:6 */
    u32 rsrvd2               :  2 ;
    u32 txem_ptp_v6csum0_errIE :  1 ; /* bits 9:9 */
    u32 txrm_timerexpIE      :  1 ; /* bits 10:10 */
    u32 nitx_crc_errIE       :  1 ; /* bits 11:11 */
    u32 rsrvd3               : 20 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_TXEM_INTERRUPTE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PC0_INTERRUPT                  0xf430a3b4
#define NI_HV_GLB_PC0_INTERRUPT_STRIDE           8
#define NI_HV_GLB_PC0_INTERRUPT_COUNT            6
#define NI_HV_GLB_PC0_INTERRUPT_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dchkoutofsyncI       :  1 ; /* bits 0:0 */
    u32 dstaddrmismatchI     :  1 ; /* bits 1:1 */
    u32 srcaddrmismatchI     :  1 ; /* bits 2:2 */
    u32 vlan1fieldmismatchI  :  1 ; /* bits 3:3 */
    u32 vlan2fieldmismatchI  :  1 ; /* bits 4:4 */
    u32 typefieldmismatchI   :  1 ; /* bits 5:5 */
    u32 seqnummismatchI      :  1 ; /* bits 6:6 */
    u32 datamismatchI        :  1 ; /* bits 7:7 */
    u32 framelenmismatchI    :  1 ; /* bits 8:8 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PC0_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PC0_INTERRUPTE                 0xf430a3b8
#define NI_HV_GLB_PC0_INTERRUPTE_STRIDE          8
#define NI_HV_GLB_PC0_INTERRUPTE_COUNT           6
#define NI_HV_GLB_PC0_INTERRUPTE_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dchkoutofsyncIE      :  1 ; /* bits 0:0 */
    u32 dstaddrmismatchIE    :  1 ; /* bits 1:1 */
    u32 srcaddrmismatchIE    :  1 ; /* bits 2:2 */
    u32 vlan1fieldmismatchIE :  1 ; /* bits 3:3 */
    u32 vlan2fieldmismatchIE :  1 ; /* bits 4:4 */
    u32 typefieldmismatchIE  :  1 ; /* bits 5:5 */
    u32 seqnummismatchIE     :  1 ; /* bits 6:6 */
    u32 datamismatchIE       :  1 ; /* bits 7:7 */
    u32 framelenmismatchIE   :  1 ; /* bits 8:8 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PC0_INTERRUPTE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPUXRAM_CNTR_INTERRUPT         0xf430a3e4
#define NI_HV_GLB_CPUXRAM_CNTR_INTERRUPT_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_drop_err_0_cntmsb_setI :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  9 ;
    u32 pkt_to_xram_0_cntmsb_setI :  1 ; /* bits 10:10 */
    u32 rsrvd2               :  9 ;
    u32 byt_to_xram_0_cntmsb_setI :  1 ; /* bits 20:20 */
    u32 rsrvd3               :  8 ;
    u32 dma_pkt_to_cpu_cntmsb_setI :  1 ; /* bits 29:29 */
    u32 dma_byte_to_cpu_cntmsb_setI :  1 ; /* bits 30:30 */
    u32 rsrvd4               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPUXRAM_CNTR_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPUXRAM_CNTR_INTERRUPTE        0xf430a3e8
#define NI_HV_GLB_CPUXRAM_CNTR_INTERRUPTE_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_drop_err_0_cntmsb_setIE :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  9 ;
    u32 pkt_to_xram_0_cntmsb_setIE :  1 ; /* bits 10:10 */
    u32 rsrvd2               :  9 ;
    u32 byt_to_xram_0_cntmsb_setIE :  1 ; /* bits 20:20 */
    u32 rsrvd3               :  8 ;
    u32 dma_pkt_to_cpu_cntmsb_setIE :  1 ; /* bits 29:29 */
    u32 dma_byte_to_cpu_cntmsb_setIE :  1 ; /* bits 30:30 */
    u32 rsrvd4               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPUXRAM_CNTR_INTERRUPTE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPUXRAM_ERR_INTERRUPT          0xf430a3ec
#define NI_HV_GLB_CPUXRAM_ERR_INTERRUPT_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xram_rx_0_ptrbkupI   :  1 ; /* bits 0:0 */
    u32 xram_rx_no_hdrAI     :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 20 ;
    u32 xram_rx_mgmtfifo_overrunI :  1 ; /* bits 22:22 */
    u32 dma_fifo_overrunI    :  1 ; /* bits 23:23 */
    u32 rsrvd2               :  8 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPUXRAM_ERR_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPUXRAM_ERR_INTERRUPTE         0xf430a3f0
#define NI_HV_GLB_CPUXRAM_ERR_INTERRUPTE_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xram_rx_0_ptrbkupIE  :  1 ; /* bits 0:0 */
    u32 xram_rx_no_hdrAIE    :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 20 ;
    u32 xram_rx_mgmtfifo_overrunIE :  1 ; /* bits 22:22 */
    u32 dma_fifo_overrunIE   :  1 ; /* bits 23:23 */
    u32 rsrvd2               :  8 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPUXRAM_ERR_INTERRUPTE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PTP_INTERRUPT                  0xf430a3f4
#define NI_HV_GLB_PTP_INTERRUPT_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port0_tx_timestamp_rdy_intI :  1 ; /* bits 0:0 */
    u32 port1_tx_timestamp_rdy_intI :  1 ; /* bits 1:1 */
    u32 port2_tx_timestamp_rdy_intI :  1 ; /* bits 2:2 */
    u32 port3_tx_timestamp_rdy_intI :  1 ; /* bits 3:3 */
    u32 port4_tx_timestamp_rdy_intI :  1 ; /* bits 4:4 */
    u32 port5_tx_timestamp_rdy_intI :  1 ; /* bits 5:5 */
    u32 port6_tx_timestamp_rdy_intI :  1 ; /* bits 6:6 */
    u32 rsrvd1               :  1 ;
    u32 port0_tx_ptpfifo_overflow_intI :  1 ; /* bits 8:8 */
    u32 port1_tx_ptpfifo_overflow_intI :  1 ; /* bits 9:9 */
    u32 port2_tx_ptpfifo_overflow_intI :  1 ; /* bits 10:10 */
    u32 port3_tx_ptpfifo_overflow_intI :  1 ; /* bits 11:11 */
    u32 port4_tx_ptpfifo_overflow_intI :  1 ; /* bits 12:12 */
    u32 port5_tx_ptpfifo_overflow_intI :  1 ; /* bits 13:13 */
    u32 port6_tx_ptpfifo_overflow_intI :  1 ; /* bits 14:14 */
    u32 rsrvd2               :  1 ;
    u32 port0_tx_ptpfifo_underflow_intI :  1 ; /* bits 16:16 */
    u32 port1_tx_ptpfifo_underflow_intI :  1 ; /* bits 17:17 */
    u32 port2_tx_ptpfifo_underflow_intI :  1 ; /* bits 18:18 */
    u32 port3_tx_ptpfifo_underflow_intI :  1 ; /* bits 19:19 */
    u32 port4_tx_ptpfifo_underflow_intI :  1 ; /* bits 20:20 */
    u32 port5_tx_ptpfifo_underflow_intI :  1 ; /* bits 21:21 */
    u32 port6_tx_ptpfifo_underflow_intI :  1 ; /* bits 22:22 */
    u32 rsrvd3               :  6 ;
    u32 timer_rollover_intI  :  1 ; /* bits 29:29 */
    u32 pps_event_intI       :  1 ; /* bits 30:30 */
    u32 pps_out_falledge_intI :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PTP_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PTP_INTERRUPTE                 0xf430a3f8
#define NI_HV_GLB_PTP_INTERRUPTE_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port0_tx_timestamp_rdy_intIE :  1 ; /* bits 0:0 */
    u32 port1_tx_timestamp_rdy_intIE :  1 ; /* bits 1:1 */
    u32 port2_tx_timestamp_rdy_intIE :  1 ; /* bits 2:2 */
    u32 port3_tx_timestamp_rdy_intIE :  1 ; /* bits 3:3 */
    u32 port4_tx_timestamp_rdy_intIE :  1 ; /* bits 4:4 */
    u32 port5_tx_timestamp_rdy_intIE :  1 ; /* bits 5:5 */
    u32 port6_tx_timestamp_rdy_intIE :  1 ; /* bits 6:6 */
    u32 rsrvd1               :  1 ;
    u32 port0_tx_ptpfifo_overflow_intIE :  1 ; /* bits 8:8 */
    u32 port1_tx_ptpfifo_overflow_intIE :  1 ; /* bits 9:9 */
    u32 port2_tx_ptpfifo_overflow_intIE :  1 ; /* bits 10:10 */
    u32 port3_tx_ptpfifo_overflow_intIE :  1 ; /* bits 11:11 */
    u32 port4_tx_ptpfifo_overflow_intIE :  1 ; /* bits 12:12 */
    u32 port5_tx_ptpfifo_overflow_intIE :  1 ; /* bits 13:13 */
    u32 port6_tx_ptpfifo_overflow_intIE :  1 ; /* bits 14:14 */
    u32 rsrvd2               :  1 ;
    u32 port0_tx_ptpfifo_underflow_intIE :  1 ; /* bits 16:16 */
    u32 port1_tx_ptpfifo_underflow_intIE :  1 ; /* bits 17:17 */
    u32 port2_tx_ptpfifo_underflow_intIE :  1 ; /* bits 18:18 */
    u32 port3_tx_ptpfifo_underflow_intIE :  1 ; /* bits 19:19 */
    u32 port4_tx_ptpfifo_underflow_intIE :  1 ; /* bits 20:20 */
    u32 port5_tx_ptpfifo_underflow_intIE :  1 ; /* bits 21:21 */
    u32 port6_tx_ptpfifo_underflow_intIE :  1 ; /* bits 22:22 */
    u32 rsrvd3               :  6 ;
    u32 timer_rollover_intIE :  1 ; /* bits 29:29 */
    u32 pps_event_intIE      :  1 ; /* bits 30:30 */
    u32 pps_out_falledge_intIE :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PTP_INTERRUPTE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPUXRAM_RXPKT_INTERRUPT        0xf430a3fc
#define NI_HV_GLB_CPUXRAM_RXPKT_INTERRUPT_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xram_rx_doneI        :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPUXRAM_RXPKT_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPUXRAM_RXPKT_INTERRUPTE       0xf430a400
#define NI_HV_GLB_CPUXRAM_RXPKT_INTERRUPTE_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xram_rx_doneIE       :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPUXRAM_RXPKT_INTERRUPTE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPUXRAM_TXPKT_INTERRUPT        0xf430a404
#define NI_HV_GLB_CPUXRAM_TXPKT_INTERRUPT_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xram_tx_0_doneI      :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPUXRAM_TXPKT_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPUXRAM_TXPKT_INTERRUPTE       0xf430a408
#define NI_HV_GLB_CPUXRAM_TXPKT_INTERRUPTE_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xram_tx_0_doneIE     :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPUXRAM_TXPKT_INTERRUPTE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_MC_INTERRUPT                   0xf430a40c
#define NI_HV_GLB_MC_INTERRUPT_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  1 ;
    u32 mc_ff_full_drop_intI :  1 ; /* bits 1:1 */
    u32 rsrvd2               :  1 ;
    u32 bitmap_zero_drop_intI :  1 ; /* bits 3:3 */
    u32 rsrvd3               : 28 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_MC_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_MC_INTERRUPTE                  0xf430a410
#define NI_HV_GLB_MC_INTERRUPTE_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  1 ;
    u32 mc_ff_full_drop_intIE :  1 ; /* bits 1:1 */
    u32 rsrvd2               :  1 ;
    u32 bitmap_zero_drop_intIE :  1 ; /* bits 3:3 */
    u32 rsrvd3               : 28 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_MC_INTERRUPTE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_INTERRUPT                      0xf430a414
#define NI_HV_GLB_INTERRUPT_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 int_stat_pspid_0     :  1 ; /* bits 0:0 */
    u32 int_stat_pspid_1     :  1 ; /* bits 1:1 */
    u32 int_stat_pspid_2     :  1 ; /* bits 2:2 */
    u32 int_stat_pspid_3     :  1 ; /* bits 3:3 */
    u32 int_stat_pspid_4     :  1 ; /* bits 4:4 */
    u32 int_stat_pspid_5     :  1 ; /* bits 5:5 */
    u32 int_stat_pspid_6     :  1 ; /* bits 6:6 */
    u32 int_stat_pspid_7     :  1 ; /* bits 7:7 */
    u32 int_stat_pspid_8     :  1 ; /* bits 8:8 */
    u32 int_stat_pspid_9     :  1 ; /* bits 9:9 */
    u32 int_stat_pspid_10    :  1 ; /* bits 10:10 */
    u32 int_stat_pspid_11    :  1 ; /* bits 11:11 */
    u32 macsec_de_int        :  1 ; /* bits 12:12 */
    u32 xge6_int             :  1 ; /* bits 13:13 */
    u32 xaui_int             :  1 ; /* bits 14:14 */
    u32 macsec_en_int        :  1 ; /* bits 15:15 */
    u32 int_stat_txem        :  1 ; /* bits 16:16 */
    u32 int_stat_pc0         :  1 ; /* bits 17:17 */
    u32 int_stat_pc1         :  1 ; /* bits 18:18 */
    u32 int_stat_pc2         :  1 ; /* bits 19:19 */
    u32 int_stat_pc3         :  1 ; /* bits 20:20 */
    u32 int_stat_pc4         :  1 ; /* bits 21:21 */
    u32 int_stat_pc5         :  1 ; /* bits 22:22 */
    u32 rsrvd1               :  1 ;
    u32 misc                 :  1 ; /* bits 24:24 */
    u32 cpuxram_int_stat_cntr :  1 ; /* bits 25:25 */
    u32 cpuxram_int_stat_err :  1 ; /* bits 26:26 */
    u32 int_stat_ptp         :  1 ; /* bits 27:27 */
    u32 int_stat_mceng       :  1 ; /* bits 28:28 */
    u32 cpuxram_rxpkt        :  1 ; /* bits 29:29 */
    u32 cpuxram_txpkt        :  1 ; /* bits 30:30 */
    u32 ni_fifo              :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_INTERRUPTE                     0xf430a418
#define NI_HV_GLB_INTERRUPTE_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 int_stat_pspid_0E    :  1 ; /* bits 0:0 */
    u32 int_stat_pspid_1E    :  1 ; /* bits 1:1 */
    u32 int_stat_pspid_2E    :  1 ; /* bits 2:2 */
    u32 int_stat_pspid_3E    :  1 ; /* bits 3:3 */
    u32 int_stat_pspid_4E    :  1 ; /* bits 4:4 */
    u32 int_stat_pspid_5E    :  1 ; /* bits 5:5 */
    u32 int_stat_pspid_6E    :  1 ; /* bits 6:6 */
    u32 int_stat_pspid_7E    :  1 ; /* bits 7:7 */
    u32 int_stat_pspid_8E    :  1 ; /* bits 8:8 */
    u32 int_stat_pspid_9E    :  1 ; /* bits 9:9 */
    u32 int_stat_pspid_10E   :  1 ; /* bits 10:10 */
    u32 int_stat_pspid_11E   :  1 ; /* bits 11:11 */
    u32 macsec_de_intE       :  1 ; /* bits 12:12 */
    u32 xge6_intE            :  1 ; /* bits 13:13 */
    u32 xaui_intE            :  1 ; /* bits 14:14 */
    u32 macsec_en_intE       :  1 ; /* bits 15:15 */
    u32 int_stat_txemE       :  1 ; /* bits 16:16 */
    u32 int_stat_pc0E        :  1 ; /* bits 17:17 */
    u32 int_stat_pc1E        :  1 ; /* bits 18:18 */
    u32 int_stat_pc2E        :  1 ; /* bits 19:19 */
    u32 int_stat_pc3E        :  1 ; /* bits 20:20 */
    u32 int_stat_pc4E        :  1 ; /* bits 21:21 */
    u32 int_stat_pc5E        :  1 ; /* bits 22:22 */
    u32 rsrvd1               :  1 ;
    u32 miscE                :  1 ; /* bits 24:24 */
    u32 cpuxram_int_stat_cntrE :  1 ; /* bits 25:25 */
    u32 cpuxram_int_stat_errE :  1 ; /* bits 26:26 */
    u32 int_stat_ptpE        :  1 ; /* bits 27:27 */
    u32 int_stat_mcengE      :  1 ; /* bits 28:28 */
    u32 cpuxram_rxpktE       :  1 ; /* bits 29:29 */
    u32 cpuxram_txpktE       :  1 ; /* bits 30:30 */
    u32 ni_fifoE             :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_INTERRUPTE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_ETH_TX_MISC_CFG                0xf430a41c
#define NI_HV_GLB_ETH_TX_MISC_CFG_dft            0x00002020

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rdy_low_thld_ge      :  9 ; /* bits 8:0 */
    u32 rsrvd1               :  1 ;
    u32 rdy_high_thld_ge     :  9 ; /* bits 18:10 */
    u32 rsrvd2               :  1 ;
    u32 rdy_low_thld_fe      :  5 ; /* bits 24:20 */
    u32 rsrvd3               :  2 ;
    u32 rdy_high_thld_fe     :  5 ; /* bits 31:27 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_ETH_TX_MISC_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_DEBUG_2                        0xf430a420
#define NI_HV_GLB_DEBUG_2_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dbg_ptp_hw_cnt       : 30 ; /* bits 29:0 */
    u32 rsrvd1               :  1 ;
    u32 ptp_hw_cnt_dbg       :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_DEBUG_2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_DEBUG_3                        0xf430a424
#define NI_HV_GLB_DEBUG_3_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sel                  : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_DEBUG_3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_VENUS_MISC_CFG                 0xf430a428
#define NI_HV_GLB_VENUS_MISC_CFG_dft             0x00000010

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xge7_rxfifo_almost_full_thre :  8 ; /* bits 7:0 */
    u32 rsrvd1               :  2 ;
    u32 xge7_cpu_tag_tx_en   :  1 ; /* bits 10:10 */
    u32 rsrvd2               :  1 ;
    u32 xge7_cpu_tag_cfg_sel :  1 ; /* bits 12:12 */
    u32 xge6_cpu_tag_tx_en   :  1 ; /* bits 13:13 */
    u32 xge6_cpu_tag_rx_en   :  1 ; /* bits 14:14 */
    u32 xge6_cpu_tag_cfg_sel :  1 ; /* bits 15:15 */
    u32 rsrvd3               :  4 ;
    u32 top_dbg_sel          :  2 ; /* bits 21:20 */
    u32 rsrvd4               : 10 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_VENUS_MISC_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG_CFG                    0xf430a42c
#define NI_HV_GLB_CPU_TAG_CFG_dft                0x00048899

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rtk_tag              : 16 ; /* bits 15:0 */
    u32 protocol             :  8 ; /* bits 23:16 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_PORT_ID1              0xf430a430
#define NI_HV_GLB_CPU_TAG0_PORT_ID1_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pid1                 : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_PORT_ID1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_PORT_ID0              0xf430a434
#define NI_HV_GLB_CPU_TAG0_PORT_ID0_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pid0                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_PORT_ID0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_PORT_MASK1            0xf430a438
#define NI_HV_GLB_CPU_TAG0_PORT_MASK1_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port_msk1            : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_PORT_MASK1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_PORT_MASK0            0xf430a43c
#define NI_HV_GLB_CPU_TAG0_PORT_MASK0_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port_msk0            : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_PORT_MASK0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A15               0xf430a440
#define NI_HV_GLB_CPU_TAG0_HDR_A15_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a15              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A15_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A14               0xf430a444
#define NI_HV_GLB_CPU_TAG0_HDR_A14_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a14              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A14_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A13               0xf430a448
#define NI_HV_GLB_CPU_TAG0_HDR_A13_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a13              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A13_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A12               0xf430a44c
#define NI_HV_GLB_CPU_TAG0_HDR_A12_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a12              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A12_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A11               0xf430a450
#define NI_HV_GLB_CPU_TAG0_HDR_A11_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a11              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A11_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A10               0xf430a454
#define NI_HV_GLB_CPU_TAG0_HDR_A10_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a10              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A10_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A9                0xf430a458
#define NI_HV_GLB_CPU_TAG0_HDR_A9_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a9               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A9_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A8                0xf430a45c
#define NI_HV_GLB_CPU_TAG0_HDR_A8_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a8               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A8_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A7                0xf430a460
#define NI_HV_GLB_CPU_TAG0_HDR_A7_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a7               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A7_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A6                0xf430a464
#define NI_HV_GLB_CPU_TAG0_HDR_A6_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a6               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A6_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A5                0xf430a468
#define NI_HV_GLB_CPU_TAG0_HDR_A5_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a5               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A5_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A4                0xf430a46c
#define NI_HV_GLB_CPU_TAG0_HDR_A4_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a4               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A4_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A3                0xf430a470
#define NI_HV_GLB_CPU_TAG0_HDR_A3_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a3               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A2                0xf430a474
#define NI_HV_GLB_CPU_TAG0_HDR_A2_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a2               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A1                0xf430a478
#define NI_HV_GLB_CPU_TAG0_HDR_A1_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a1               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG0_HDR_A0                0xf430a47c
#define NI_HV_GLB_CPU_TAG0_HDR_A0_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a0               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG0_HDR_A0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_PORT_ID1              0xf430a480
#define NI_HV_GLB_CPU_TAG1_PORT_ID1_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pid1                 : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_PORT_ID1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_PORT_ID0              0xf430a484
#define NI_HV_GLB_CPU_TAG1_PORT_ID0_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pid0                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_PORT_ID0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_PORT_MASK1            0xf430a488
#define NI_HV_GLB_CPU_TAG1_PORT_MASK1_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port_msk1            : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_PORT_MASK1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_PORT_MASK0            0xf430a48c
#define NI_HV_GLB_CPU_TAG1_PORT_MASK0_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 port_msk0            : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_PORT_MASK0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A15               0xf430a490
#define NI_HV_GLB_CPU_TAG1_HDR_A15_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a15              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A15_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A14               0xf430a494
#define NI_HV_GLB_CPU_TAG1_HDR_A14_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a14              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A14_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A13               0xf430a498
#define NI_HV_GLB_CPU_TAG1_HDR_A13_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a13              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A13_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A12               0xf430a49c
#define NI_HV_GLB_CPU_TAG1_HDR_A12_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a12              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A12_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A11               0xf430a4a0
#define NI_HV_GLB_CPU_TAG1_HDR_A11_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a11              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A11_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A10               0xf430a4a4
#define NI_HV_GLB_CPU_TAG1_HDR_A10_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a10              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A10_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A9                0xf430a4a8
#define NI_HV_GLB_CPU_TAG1_HDR_A9_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a9               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A9_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A8                0xf430a4ac
#define NI_HV_GLB_CPU_TAG1_HDR_A8_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a8               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A8_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A7                0xf430a4b0
#define NI_HV_GLB_CPU_TAG1_HDR_A7_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a7               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A7_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A6                0xf430a4b4
#define NI_HV_GLB_CPU_TAG1_HDR_A6_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a6               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A6_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A5                0xf430a4b8
#define NI_HV_GLB_CPU_TAG1_HDR_A5_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a5               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A5_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A4                0xf430a4bc
#define NI_HV_GLB_CPU_TAG1_HDR_A4_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a4               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A4_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A3                0xf430a4c0
#define NI_HV_GLB_CPU_TAG1_HDR_A3_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a3               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A2                0xf430a4c4
#define NI_HV_GLB_CPU_TAG1_HDR_A2_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a2               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A1                0xf430a4c8
#define NI_HV_GLB_CPU_TAG1_HDR_A1_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a1               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG1_HDR_A0                0xf430a4cc
#define NI_HV_GLB_CPU_TAG1_HDR_A0_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr_a0               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG1_HDR_A0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG_P5_DEFAULT_HEADER_CFG1 0xf430a4d0
#define NI_HV_GLB_CPU_TAG_P5_DEFAULT_HEADER_CFG1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 default_hdr_a1       : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG_P5_DEFAULT_HEADER_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG_P5_DEFAULT_HEADER_CFG0 0xf430a4d4
#define NI_HV_GLB_CPU_TAG_P5_DEFAULT_HEADER_CFG0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 default_hdr_a0       : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG_P5_DEFAULT_HEADER_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG_P6_DEFAULT_HEADER_CFG1 0xf430a4d8
#define NI_HV_GLB_CPU_TAG_P6_DEFAULT_HEADER_CFG1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 default_hdr_a1       : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG_P6_DEFAULT_HEADER_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CPU_TAG_P6_DEFAULT_HEADER_CFG0 0xf430a4dc
#define NI_HV_GLB_CPU_TAG_P6_DEFAULT_HEADER_CFG0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 default_hdr_a0       : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CPU_TAG_P6_DEFAULT_HEADER_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMTEST_CFG11                 0xf430a4e0
#define NI_HV_GLB_SRAMTEST_CFG11_dft             0x00020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni1_ctl1             : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMTEST_CFG11_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMTEST_CFG10                 0xf430a4e4
#define NI_HV_GLB_SRAMTEST_CFG10_dft             0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni1_ctl0             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMTEST_CFG10_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMTEST_CFG22                 0xf430a4e8
#define NI_HV_GLB_SRAMTEST_CFG22_dft             0x00000202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni2_ctl2             : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMTEST_CFG22_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMTEST_CFG21                 0xf430a4ec
#define NI_HV_GLB_SRAMTEST_CFG21_dft             0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni2_ctl1             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMTEST_CFG21_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMTEST_CFG20                 0xf430a4f0
#define NI_HV_GLB_SRAMTEST_CFG20_dft             0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni2_ctl0             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMTEST_CFG20_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMTEST_CFG32                 0xf430a4f4
#define NI_HV_GLB_SRAMTEST_CFG32_dft             0x00000002

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni3_ctl2             :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMTEST_CFG32_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMTEST_CFG31                 0xf430a4f8
#define NI_HV_GLB_SRAMTEST_CFG31_dft             0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni3_ctl1             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMTEST_CFG31_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMTEST_CFG30                 0xf430a4fc
#define NI_HV_GLB_SRAMTEST_CFG30_dft             0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni3_ctl0             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMTEST_CFG30_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMTEST_CFG4                  0xf430a500
#define NI_HV_GLB_SRAMTEST_CFG4_dft              0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni4_ctl              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMTEST_CFG4_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMTEST_CFG5                  0xf430a504
#define NI_HV_GLB_SRAMTEST_CFG5_dft              0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni5_ctl              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMTEST_CFG5_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMTEST_CFG61                 0xf430a508
#define NI_HV_GLB_SRAMTEST_CFG61_dft             0x00000202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni6_ctl1             : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMTEST_CFG61_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMTEST_CFG60                 0xf430a50c
#define NI_HV_GLB_SRAMTEST_CFG60_dft             0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni6_ctl0             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMTEST_CFG60_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMTEST_CFG7                  0xf430a510
#define NI_HV_GLB_SRAMTEST_CFG7_dft              0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni_xaui1_ctl         : 24 ; /* bits 23:0 */
    u32 ni_xram_ctl          :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMTEST_CFG7_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMTEST_CFG8                  0xf430a514
#define NI_HV_GLB_SRAMTEST_CFG8_dft              0x02020202

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni_xaui2_ctl         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMTEST_CFG8_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMLS_CFG0                    0xf430a518
#define NI_HV_GLB_SRAMLS_CFG0_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni1_sramls           :  7 ; /* bits 6:0 */
    u32 ni2_sramls           : 10 ; /* bits 16:7 */
    u32 ni3_sramls           :  9 ; /* bits 25:17 */
    u32 ni4_sramls           :  4 ; /* bits 29:26 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMLS_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_SRAMLS_CFG1                    0xf430a51c
#define NI_HV_GLB_SRAMLS_CFG1_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni5_sramls           :  4 ; /* bits 3:0 */
    u32 ni6_sramls           :  6 ; /* bits 9:4 */
    u32 ni_xaui1_sramls      :  3 ; /* bits 12:10 */
    u32 ni_xaui2_sramls      :  4 ; /* bits 16:13 */
    u32 ni_xram_sramls       :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_SRAMLS_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CLK_THROTTLE_CNTL              0xf430a520
#define NI_HV_GLB_CLK_THROTTLE_CNTL_dft          0x00000014

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 max_period           :  5 ; /* bits 4:0 */
    u32 lpf_mode             :  2 ; /* bits 6:5 */
    u32 rsrvd1               :  4 ;
    u32 sw_thresh            : 21 ; /* bits 31:11 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CLK_THROTTLE_CNTL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CLK_LUT_0                      0xf430a524
#define NI_HV_GLB_CLK_LUT_0_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lut_vec_0            : 30 ; /* bits 29:0 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CLK_LUT_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CLK_LUT_1                      0xf430a528
#define NI_HV_GLB_CLK_LUT_1_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lut_vec_1            : 30 ; /* bits 29:0 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CLK_LUT_1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CLK_LUT_2                      0xf430a52c
#define NI_HV_GLB_CLK_LUT_2_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lut_vec_2            : 30 ; /* bits 29:0 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CLK_LUT_2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CLK_LUT_3                      0xf430a530
#define NI_HV_GLB_CLK_LUT_3_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lut_vec_3            : 30 ; /* bits 29:0 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CLK_LUT_3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CLK_LUT_4                      0xf430a534
#define NI_HV_GLB_CLK_LUT_4_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lut_vec_4            : 30 ; /* bits 29:0 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CLK_LUT_4_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CLK_LUT_5                      0xf430a538
#define NI_HV_GLB_CLK_LUT_5_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lut_vec_5            : 30 ; /* bits 29:0 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CLK_LUT_5_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CLK_LUT_6                      0xf430a53c
#define NI_HV_GLB_CLK_LUT_6_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lut_vec_6            : 30 ; /* bits 29:0 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CLK_LUT_6_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CLK_DIV_0                      0xf430a540
#define NI_HV_GLB_CLK_DIV_0_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 div_setting_0        :  7 ; /* bits 6:0 */
    u32 div_setting_1        :  7 ; /* bits 13:7 */
    u32 div_setting_2        :  7 ; /* bits 20:14 */
    u32 div_setting_3        :  7 ; /* bits 27:21 */
    u32 rsrvd1               :  4 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CLK_DIV_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CLK_DIV_1                      0xf430a544
#define NI_HV_GLB_CLK_DIV_1_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 div_setting_4        :  7 ; /* bits 6:0 */
    u32 div_setting_5        :  7 ; /* bits 13:7 */
    u32 div_setting_6        :  7 ; /* bits 20:14 */
    u32 div_setting_7        :  7 ; /* bits 27:21 */
    u32 rsrvd1               :  4 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CLK_DIV_1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_CLK_MAX_TRAP                   0xf430a548
#define NI_HV_GLB_CLK_MAX_TRAP_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 max_trap             : 21 ; /* bits 20:0 */
    u32 rsrvd1               : 11 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_CLK_MAX_TRAP_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_C10_DEC_IN_RATE_CFG            0xf430a54c
#define NI_HV_GLB_C10_DEC_IN_RATE_CFG_dft        0xa8aa8aa8

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rate                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_C10_DEC_IN_RATE_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_VMAC_CTRL                      0xf430a550
#define NI_HV_GLB_VMAC_CTRL_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 vmac_en              :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_VMAC_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_VMAC_RX_CTRL                   0xf430a554
#define NI_HV_GLB_VMAC_RX_CTRL_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 send                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_VMAC_RX_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_VMAC_RX_IF                     0xf430a558
#define NI_HV_GLB_VMAC_RX_IF_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 valid                :  1 ; /* bits 0:0 */
    u32 drop                 :  1 ; /* bits 1:1 */
    u32 sop                  :  1 ; /* bits 2:2 */
    u32 eop                  :  1 ; /* bits 3:3 */
    u32 sob                  :  1 ; /* bits 4:4 */
    u32 eob                  :  1 ; /* bits 5:5 */
    u32 rsrvd1               :  2 ;
    u32 pspid                :  4 ; /* bits 11:8 */
    u32 bv                   :  4 ; /* bits 15:12 */
    u32 rsrvd2               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_VMAC_RX_IF_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_VMAC_RX_DATA2                  0xf430a55c
#define NI_HV_GLB_VMAC_RX_DATA2_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data2                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_VMAC_RX_DATA2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_VMAC_RX_DATA1                  0xf430a560
#define NI_HV_GLB_VMAC_RX_DATA1_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data1                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_VMAC_RX_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_VMAC_RX_DATA0                  0xf430a564
#define NI_HV_GLB_VMAC_RX_DATA0_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data0                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_VMAC_RX_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_VMAC_TX_CTRL                   0xf430a568
#define NI_HV_GLB_VMAC_TX_CTRL_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 capture              :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_VMAC_TX_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_VMAC_TX_IF                     0xf430a56c
#define NI_HV_GLB_VMAC_TX_IF_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 valid                :  1 ; /* bits 0:0 */
    u32 drop                 :  1 ; /* bits 1:1 */
    u32 sop                  :  1 ; /* bits 2:2 */
    u32 eop                  :  1 ; /* bits 3:3 */
    u32 vmactx_src           :  2 ; /* bits 5:4 */
    u32 sob                  :  1 ; /* bits 6:6 */
    u32 eob                  :  1 ; /* bits 7:7 */
    u32 dpid                 :  4 ; /* bits 11:8 */
    u32 bv                   :  4 ; /* bits 15:12 */
    u32 rsrvd1               : 15 ;
    u32 non_empty            :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_VMAC_TX_IF_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_VMAC_TX_DATA3                  0xf430a570
#define NI_HV_GLB_VMAC_TX_DATA3_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data3                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_VMAC_TX_DATA3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_VMAC_TX_DATA2                  0xf430a574
#define NI_HV_GLB_VMAC_TX_DATA2_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data2                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_VMAC_TX_DATA2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_VMAC_TX_DATA1                  0xf430a578
#define NI_HV_GLB_VMAC_TX_DATA1_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data1                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_VMAC_TX_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_VMAC_TX_DATA0                  0xf430a57c
#define NI_HV_GLB_VMAC_TX_DATA0_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data0                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_VMAC_TX_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PORT_FNL_STS_1                 0xf430a580
#define NI_HV_GLB_PORT_FNL_STS_1_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p2_int_cfg           :  4 ; /* bits 3:0 */
    u32 p2_link_status       :  1 ; /* bits 4:4 */
    u32 p2_duplex            :  1 ; /* bits 5:5 */
    u32 p2_speed             :  1 ; /* bits 6:6 */
    u32 p2_rx_flow_to_tx_en  :  1 ; /* bits 7:7 */
    u32 p2_rx_pfc_disable    :  1 ; /* bits 8:8 */
    u32 p2_rx_flow_disable   :  1 ; /* bits 9:9 */
    u32 p2_tx_pfc_disable    :  1 ; /* bits 10:10 */
    u32 p2_tx_flow_disable   :  1 ; /* bits 11:11 */
    u32 p2_giga_lite         :  1 ; /* bits 12:12 */
    u32 rsrvd1               :  3 ;
    u32 p3_int_cfg           :  4 ; /* bits 19:16 */
    u32 p3_link_status       :  1 ; /* bits 20:20 */
    u32 p3_duplex            :  1 ; /* bits 21:21 */
    u32 p3_speed             :  1 ; /* bits 22:22 */
    u32 p3_rx_flow_to_tx_en  :  1 ; /* bits 23:23 */
    u32 p3_rx_pfc_disable    :  1 ; /* bits 24:24 */
    u32 p3_rx_flow_disable   :  1 ; /* bits 25:25 */
    u32 p3_tx_pfc_disable    :  1 ; /* bits 26:26 */
    u32 p3_tx_flow_disable   :  1 ; /* bits 27:27 */
    u32 p3_giga_lite         :  1 ; /* bits 28:28 */
    u32 rsrvd2               :  3 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PORT_FNL_STS_1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_PORT_FNL_STS_0                 0xf430a584
#define NI_HV_GLB_PORT_FNL_STS_0_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p0_int_cfg           :  4 ; /* bits 3:0 */
    u32 p0_link_status       :  1 ; /* bits 4:4 */
    u32 p0_duplex            :  1 ; /* bits 5:5 */
    u32 p0_speed             :  1 ; /* bits 6:6 */
    u32 p0_rx_flow_to_tx_en  :  1 ; /* bits 7:7 */
    u32 p0_rx_pfc_disable    :  1 ; /* bits 8:8 */
    u32 p0_rx_flow_disable   :  1 ; /* bits 9:9 */
    u32 p0_tx_pfc_disable    :  1 ; /* bits 10:10 */
    u32 p0_tx_flow_disable   :  1 ; /* bits 11:11 */
    u32 p0_giga_lite         :  1 ; /* bits 12:12 */
    u32 rsrvd1               :  3 ;
    u32 p1_int_cfg           :  4 ; /* bits 19:16 */
    u32 p1_link_status       :  1 ; /* bits 20:20 */
    u32 p1_duplex            :  1 ; /* bits 21:21 */
    u32 p1_speed             :  1 ; /* bits 22:22 */
    u32 p1_rx_flow_to_tx_en  :  1 ; /* bits 23:23 */
    u32 p1_rx_pfc_disable    :  1 ; /* bits 24:24 */
    u32 p1_rx_flow_disable   :  1 ; /* bits 25:25 */
    u32 p1_tx_pfc_disable    :  1 ; /* bits 26:26 */
    u32 p1_tx_flow_disable   :  1 ; /* bits 27:27 */
    u32 p1_giga_lite         :  1 ; /* bits 28:28 */
    u32 rsrvd2               :  3 ;
  } bf ;
  u32     wrd ;
} NI_HV_GLB_PORT_FNL_STS_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_DBG_CTL                        0xf430a588
#define NI_HV_GLB_DBG_CTL_dft                    0x80000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni_dbg_sel           :  4 ; /* bits 3:0 */
    u32 ni_dbg_sel_2         :  4 ; /* bits 7:4 */
    u32 rsrvd1               : 23 ;
    u32 ni_dbg_clr           :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_DBG_CTL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_GLB_DBG_DATA                       0xf430a58c
#define NI_HV_GLB_DBG_DATA_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ni_dbg_sig           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_GLB_DBG_DATA_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_PORT_STATIC_CFG                 0xf430a5c0
#define NI_HV_PT_PORT_STATIC_CFG_dft             0x00000203

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 int_cfg              :  4 ; /* bits 3:0 */
    u32 phy_mode             :  1 ; /* bits 4:4 */
    u32 rmii_clksrc          :  1 ; /* bits 5:5 */
    u32 inv_clk_in           :  1 ; /* bits 6:6 */
    u32 inv_clk_out          :  1 ; /* bits 7:7 */
    u32 inv_rxclk_out        :  1 ; /* bits 8:8 */
    u32 tx_use_gefifo        :  1 ; /* bits 9:9 */
    u32 smii_tx_stat         :  1 ; /* bits 10:10 */
    u32 crs_polarity         :  1 ; /* bits 11:11 */
    u32 lpbk_mode            :  2 ; /* bits 13:12 */
    u32 gmii_like_half_duplex_en :  1 ; /* bits 14:14 */
    u32 sup_tx_to_rx_lpbk_data :  1 ; /* bits 15:15 */
    u32 cpu_tag_rx_en        :  1 ; /* bits 16:16 */
    u32 cpu_tag_tx_en        :  1 ; /* bits 17:17 */
    u32 cpu_tag_cfg_sel      :  1 ; /* bits 18:18 */
    u32 giga_lite            :  1 ; /* bits 19:19 */
    u32 rsrvd1               :  4 ;
    u32 mac_addr6            :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_PORT_STATIC_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_PORT_GLB_CFG                    0xf430a5c4
#define NI_HV_PT_PORT_GLB_CFG_dft                0x00000004

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 speed                :  1 ; /* bits 0:0 */
    u32 duplex               :  1 ; /* bits 1:1 */
    u32 link_status          :  1 ; /* bits 2:2 */
    u32 link_stat_mask       :  1 ; /* bits 3:3 */
    u32 rsrvd1               :  7 ;
    u32 power_dwn_rx         :  1 ; /* bits 11:11 */
    u32 power_dwn_tx         :  1 ; /* bits 12:12 */
    u32 tx_intf_lp_time      :  1 ; /* bits 13:13 */
    u32 rsrvd2               : 18 ;
  } bf ;
  u32     wrd ;
} NI_HV_PT_PORT_GLB_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_RXMAC_CFG                       0xf430a5c8
#define NI_HV_PT_RXMAC_CFG_dft                   0x00001101

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_en                :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  7 ;
    u32 rx_flow_disable      :  1 ; /* bits 8:8 */
    u32 rsrvd2               :  3 ;
    u32 rx_flow_to_tx_en     :  1 ; /* bits 12:12 */
    u32 rx_pfc_disable       :  1 ; /* bits 13:13 */
    u32 rsrvd3               : 15 ;
    u32 send_pg_data         :  1 ; /* bits 29:29 */
    u32 rsrvd4               :  2 ;
  } bf ;
  u32     wrd ;
} NI_HV_PT_RXMAC_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_RXMAC_WOL_CFG                   0xf430a5cc
#define NI_HV_PT_RXMAC_WOL_CFG_dft               0x00000f00

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wol_pkt_det_en       :  1 ; /* bits 0:0 */
    u32 wol_chk_da           :  2 ; /* bits 2:1 */
    u32 wol_ign_err          :  1 ; /* bits 3:3 */
    u32 wol_secure_on        :  1 ; /* bits 4:4 */
    u32 wol_passwd_cnt       :  1 ; /* bits 5:5 */
    u32 rsrvd1               :  2 ;
    u32 wol_mac_adr_cnt      :  6 ; /* bits 13:8 */
    u32 rsrvd2               :  2 ;
    u32 wol_passwd6          :  8 ; /* bits 23:16 */
    u32 rsrvd3               :  7 ;
    u32 wol_wake_on_any_pkt  :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_RXMAC_WOL_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_MAC_STATUS                      0xf430a5d0
#define NI_HV_PT_MAC_STATUS_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rcv_speed            :  2 ; /* bits 1:0 */
    u32 rcv_duplex           :  1 ; /* bits 2:2 */
    u32 rcv_lnk_stat         :  1 ; /* bits 3:3 */
    u32 rx_lpi_detect        :  1 ; /* bits 4:4 */
    u32 lpi_assert           :  1 ; /* bits 5:5 */
    u32 lpi_mac_dis          :  1 ; /* bits 6:6 */
    u32 rsrvd1               : 25 ;
  } bf ;
  u32     wrd ;
} NI_HV_PT_MAC_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_TXMAC_CFG                       0xf430a5d4
#define NI_HV_PT_TXMAC_CFG_dft                   0x04059901

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_en                :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  7 ;
    u32 mac_crc_calc_en      :  1 ; /* bits 8:8 */
    u32 tx_ipg_sel           :  3 ; /* bits 11:9 */
    u32 tx_flow_disable      :  1 ; /* bits 12:12 */
    u32 tx_drain             :  1 ; /* bits 13:13 */
    u32 tx_pfc_disable       :  1 ; /* bits 14:14 */
    u32 tx_pau_sel           :  2 ; /* bits 16:15 */
    u32 force_xon_stream     :  1 ; /* bits 17:17 */
    u32 tx_bkprs_en          :  1 ; /* bits 18:18 */
    u32 rsrvd2               :  7 ;
    u32 tx_auto_xon          :  1 ; /* bits 26:26 */
    u32 rsrvd3               :  1 ;
    u32 pass_thru_hdr        :  1 ; /* bits 28:28 */
    u32 rsrvd4               :  3 ;
  } bf ;
  u32     wrd ;
} NI_HV_PT_TXMAC_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG0      0xf430a5d8
#define NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG0_dft  0x00ff00ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 txpfc_time_0         : 16 ; /* bits 15:0 */
    u32 txpfc_time_1         : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG1      0xf430a5dc
#define NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG1_dft  0x00ff00ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 txpfc_time_2         : 16 ; /* bits 15:0 */
    u32 txpfc_time_3         : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG2      0xf430a5e0
#define NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG2_dft  0x00ff00ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 txpfc_time_4         : 16 ; /* bits 15:0 */
    u32 txpfc_time_5         : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG3      0xf430a5e4
#define NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG3_dft  0x00ff00ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 txpfc_time_6         : 16 ; /* bits 15:0 */
    u32 txpfc_time_7         : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_EEE_LPI_CFG0                    0xf430a5e8
#define NI_HV_PT_EEE_LPI_CFG0_dft                0x01387000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_eee_enable        :  1 ; /* bits 0:0 */
    u32 cpu_lpi_deassert     :  1 ; /* bits 1:1 */
    u32 stop_txclk_on_lpi    :  1 ; /* bits 2:2 */
    u32 lpi_data_mode        :  1 ; /* bits 3:3 */
    u32 lpi_mode_te          :  1 ; /* bits 4:4 */
    u32 rsrvd1               :  7 ;
    u32 txfifo_empty_cnt     : 20 ; /* bits 31:12 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_EEE_LPI_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_EEE_LPI_CFG1                    0xf430a5ec
#define NI_HV_PT_EEE_LPI_CFG1_dft                0x0000071b

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lpi_min_assert_cnt   : 20 ; /* bits 19:0 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_PT_EEE_LPI_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_EEE_LPI_CFG2                    0xf430a5f0
#define NI_HV_PT_EEE_LPI_CFG2_dft                0x000000a4

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lpi_min_wakeup_cnt   : 20 ; /* bits 19:0 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} NI_HV_PT_EEE_LPI_CFG2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_EEE_LPI_CFG3                    0xf430a5f4
#define NI_HV_PT_EEE_LPI_CFG3_dft                0x0f000005

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lpi_mac_dis_wait_cnt : 12 ; /* bits 11:0 */
    u32 rsrvd1               :  8 ;
    u32 stop_txclk_en_cnt    : 12 ; /* bits 31:20 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_EEE_LPI_CFG3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_RX_CNTRL_CFG                    0xf430a5f8
#define NI_HV_PT_RX_CNTRL_CFG_dft                0x08000400

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  2 ;
    u32 ff_overrun_drop_dis  :  1 ; /* bits 2:2 */
    u32 rsrvd2               :  1 ;
    u32 crc_drop_dis         :  1 ; /* bits 4:4 */
    u32 ovr_drop_dis         :  1 ; /* bits 5:5 */
    u32 runt_drop_dis        :  1 ; /* bits 6:6 */
    u32 flow_drop_dis        :  1 ; /* bits 7:7 */
    u32 ukopcode_drop_dis    :  1 ; /* bits 8:8 */
    u32 oam_drop_dis         :  1 ; /* bits 9:9 */
    u32 linkstat_drop_dis    :  1 ; /* bits 10:10 */
    u32 pfc_drop_dis         :  1 ; /* bits 11:11 */
    u32 rsrvd3               :  4 ;
    u32 rxctrl_byp_dpid      :  6 ; /* bits 21:16 */
    u32 rsrvd4               :  2 ;
    u32 rxctrl_byp_cos       :  3 ; /* bits 26:24 */
    u32 rxctrl_byp_dpq       :  1 ; /* bits 27:27 */
    u32 rxctrl_byp_en        :  1 ; /* bits 28:28 */
    u32 rsrvd5               :  1 ;
    u32 rxctrl_byp_mir       :  1 ; /* bits 30:30 */
    u32 rxctrl_byp_ndrp      :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_RX_CNTRL_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_TXFIFO_THLD_CFG                 0xf430a5fc
#define NI_HV_PT_TXFIFO_THLD_CFG_dft             0x00280064

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 high_thld            : 10 ; /* bits 9:0 */
    u32 rsrvd1               :  6 ;
    u32 low_thld             : 10 ; /* bits 25:16 */
    u32 rsrvd2               :  6 ;
  } bf ;
  u32     wrd ;
} NI_HV_PT_TXFIFO_THLD_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_PG_CFG0                         0xf430a600
#define NI_HV_PT_PG_CFG0_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pg_da6               :  8 ; /* bits 7:0 */
    u32 pg_sa6               :  8 ; /* bits 15:8 */
    u32 pg_type              : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_PG_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_PG_CFG1                         0xf430a604
#define NI_HV_PT_PG_CFG1_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pg_vlan1             : 16 ; /* bits 15:0 */
    u32 pg_vlan2             : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_PG_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_PG_CNTRL_CFG                    0xf430a608
#define NI_HV_PT_PG_CNTRL_CFG_dft                0x08018000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pg_en                :  1 ; /* bits 0:0 */
    u32 pg_fixedcount        :  1 ; /* bits 1:1 */
    u32 rsrvd1               :  2 ;
    u32 pg_fixedlen          :  1 ; /* bits 4:4 */
    u32 pg_insvlan2          :  1 ; /* bits 5:5 */
    u32 pg_insvlan1          :  1 ; /* bits 6:6 */
    u32 pg_instype           :  1 ; /* bits 7:7 */
    u32 pg_insseqnum         :  1 ; /* bits 8:8 */
    u32 pg_invpat            :  1 ; /* bits 9:9 */
    u32 pg_insfixpattern     :  1 ; /* bits 10:10 */
    u32 rsrvd2               :  4 ;
    u32 pg_linerate          :  9 ; /* bits 23:15 */
    u32 pg_ipg               :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_PG_CNTRL_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_PC_CFG1                         0xf430a60c
#define NI_HV_PT_PC_CFG1_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pc_da6               :  8 ; /* bits 7:0 */
    u32 pc_sa6               :  8 ; /* bits 15:8 */
    u32 pc_type              : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_PC_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_PC_CFG2                         0xf430a610
#define NI_HV_PT_PC_CFG2_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pc_vlan1             : 16 ; /* bits 15:0 */
    u32 pc_vlan2             : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_PC_CFG2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_PC_CNTRL                        0xf430a614
#define NI_HV_PT_PC_CNTRL_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pc_en                :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  3 ;
    u32 pc_fixedlen          :  1 ; /* bits 4:4 */
    u32 pc_expvlan2          :  1 ; /* bits 5:5 */
    u32 pc_expvlan1          :  1 ; /* bits 6:6 */
    u32 pc_exptype           :  1 ; /* bits 7:7 */
    u32 pc_expseqnum         :  1 ; /* bits 8:8 */
    u32 pc_invpat            :  1 ; /* bits 9:9 */
    u32 pc_expfixpattern     :  1 ; /* bits 10:10 */
    u32 rsrvd2               : 21 ;
  } bf ;
  u32     wrd ;
} NI_HV_PT_PC_CNTRL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_PC_STAT                         0xf430a618
#define NI_HV_PT_PC_STAT_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pc_dchkstatus        :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_PT_PC_STAT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_DEBUG_1                         0xf430a61c
#define NI_HV_PT_DEBUG_1_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hd_backoff_cnt       : 10 ; /* bits 9:0 */
    u32 hd_backoff_dbg       :  1 ; /* bits 10:10 */
    u32 rsrvd1               : 21 ;
  } bf ;
  u32     wrd ;
} NI_HV_PT_DEBUG_1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_TX_DRAINCNT                     0xf430a620
#define NI_HV_PT_TX_DRAINCNT_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 CNT                  : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_PT_TX_DRAINCNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_CPU_TAG_DEFAULT_HEADER_CFG1     0xf430a624
#define NI_HV_PT_CPU_TAG_DEFAULT_HEADER_CFG1_dft 0xffff0000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 default_hdr_a1       : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_CPU_TAG_DEFAULT_HEADER_CFG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_CPU_TAG_DEFAULT_HEADER_CFG0     0xf430a628
#define NI_HV_PT_CPU_TAG_DEFAULT_HEADER_CFG0_dft 0xffff0000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 default_hdr_a0       : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_CPU_TAG_DEFAULT_HEADER_CFG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_SPARE                           0xf430a62c
#define NI_HV_PT_SPARE_dft                       0x0000ff00

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 VALUE                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_SPARE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_PT_SPARESAMPLE                     0xf430a630
#define NI_HV_PT_SPARESAMPLE_dft                 0x0000ff00

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 VALUE                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_PT_SPARESAMPLE_t;
#endif /* !__ASSEMBLER__ */
#define APB0_NI_HV_PT_STRIDE                     144
#define APB0_NI_HV_PT_COUNT                      6



/******************************************************************
 *
 * Block declaration
 *
 ******************************************************************/

/* PT */
#ifndef __ASSEMBLER__
typedef struct {
  NI_HV_PT_PORT_STATIC_CFG_t               PORT_STATIC_CFG;               /* addr: 0x00000000 */
  u32                              rsrvd1[3];
  NI_HV_PT_PORT_GLB_CFG_t                  PORT_GLB_CFG;                  /* addr: 0x00000004 */
  u32                              rsrvd2[3];
  NI_HV_PT_RXMAC_CFG_t                     RXMAC_CFG;                     /* addr: 0x00000008 */
  u32                              rsrvd3[3];
  NI_HV_PT_RXMAC_WOL_CFG_t                 RXMAC_WOL_CFG;                 /* addr: 0x0000000c */
  u32                              rsrvd4[3];
  NI_HV_PT_MAC_STATUS_t                    MAC_STATUS;                    /* addr: 0x00000010 */
  u32                              rsrvd5[3];
  NI_HV_PT_TXMAC_CFG_t                     TXMAC_CFG;                     /* addr: 0x00000014 */
  u32                              rsrvd6[3];
  NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG0_t    ETH_TXMAC_PAUSE_TIMER_CFG0;    /* addr: 0x00000018 */
  u32                              rsrvd7[3];
  NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG1_t    ETH_TXMAC_PAUSE_TIMER_CFG1;    /* addr: 0x0000001c */
  u32                              rsrvd8[3];
  NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG2_t    ETH_TXMAC_PAUSE_TIMER_CFG2;    /* addr: 0x00000020 */
  u32                              rsrvd9[3];
  NI_HV_PT_ETH_TXMAC_PAUSE_TIMER_CFG3_t    ETH_TXMAC_PAUSE_TIMER_CFG3;    /* addr: 0x00000024 */
  u32                              rsrvd10[3];
  NI_HV_PT_EEE_LPI_CFG0_t                  EEE_LPI_CFG0;                  /* addr: 0x00000028 */
  u32                              rsrvd11[3];
  NI_HV_PT_EEE_LPI_CFG1_t                  EEE_LPI_CFG1;                  /* addr: 0x0000002c */
  u32                              rsrvd12[3];
  NI_HV_PT_EEE_LPI_CFG2_t                  EEE_LPI_CFG2;                  /* addr: 0x00000030 */
  u32                              rsrvd13[3];
  NI_HV_PT_EEE_LPI_CFG3_t                  EEE_LPI_CFG3;                  /* addr: 0x00000034 */
  u32                              rsrvd14[3];
  NI_HV_PT_RX_CNTRL_CFG_t                  RX_CNTRL_CFG;                  /* addr: 0x00000038 */
  u32                              rsrvd15[3];
  NI_HV_PT_TXFIFO_THLD_CFG_t               TXFIFO_THLD_CFG;               /* addr: 0x0000003c */
  u32                              rsrvd16[3];
  NI_HV_PT_PG_CFG0_t                       PG_CFG0;                       /* addr: 0x00000040 */
  u32                              rsrvd17[3];
  NI_HV_PT_PG_CFG1_t                       PG_CFG1;                       /* addr: 0x00000044 */
  u32                              rsrvd18[3];
  NI_HV_PT_PG_CNTRL_CFG_t                  PG_CNTRL_CFG;                  /* addr: 0x00000048 */
  u32                              rsrvd19[3];
  NI_HV_PT_PC_CFG1_t                       PC_CFG1;                       /* addr: 0x0000004c */
  u32                              rsrvd20[3];
  NI_HV_PT_PC_CFG2_t                       PC_CFG2;                       /* addr: 0x00000050 */
  u32                              rsrvd21[3];
  NI_HV_PT_PC_CNTRL_t                      PC_CNTRL;                      /* addr: 0x00000054 */
  u32                              rsrvd22[3];
  NI_HV_PT_PC_STAT_t                       PC_STAT;                       /* addr: 0x00000058 */
  u32                              rsrvd23[3];
  NI_HV_PT_DEBUG_1_t                       DEBUG_1;                       /* addr: 0x0000005c */
  u32                              rsrvd24[3];
  NI_HV_PT_TX_DRAINCNT_t                   TX_DRAINCNT;                   /* addr: 0x00000060 */
  u32                              rsrvd25[3];
  NI_HV_PT_CPU_TAG_DEFAULT_HEADER_CFG1_t   CPU_TAG_DEFAULT_HEADER_CFG1;   /* addr: 0x00000064 */
  u32                              rsrvd26[3];
  NI_HV_PT_CPU_TAG_DEFAULT_HEADER_CFG0_t   CPU_TAG_DEFAULT_HEADER_CFG0;   /* addr: 0x00000068 */
  u32                              rsrvd27[3];
  NI_HV_PT_SPARE_t                         SPARE;                         /* addr: 0x0000006c */
  u32                              rsrvd28[3];
  NI_HV_PT_SPARESAMPLE_t                   SPARESAMPLE;                   /* addr: 0x00000070 */
  u32                              rsrvd29[31];
} APB0_NI_HV_PT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_INTPT_RX_CNTRL_CFG                 0xf430a920
#define NI_HV_INTPT_RX_CNTRL_CFG_dft             0x00028000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               : 14 ;
    u32 rx_rate              :  8 ; /* bits 21:14 */
    u32 rsrvd2               : 10 ;
  } bf ;
  u32     wrd ;
} NI_HV_INTPT_RX_CNTRL_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_INTPT_RX_MISSING_SOP_EOP_CNT       0xf430a924
#define NI_HV_INTPT_RX_MISSING_SOP_EOP_CNT_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_missing_eop_pkt_cnt : 16 ; /* bits 15:0 */
    u32 rx_missing_sop_pkt_cnt : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_INTPT_RX_MISSING_SOP_EOP_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_INTPT_RX_SHORT_ERR_CNT             0xf430a928
#define NI_HV_INTPT_RX_SHORT_ERR_CNT_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_err_pkt_cnt       : 16 ; /* bits 15:0 */
    u32 rx_short_pkt_cnt     : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_INTPT_RX_SHORT_ERR_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_INTPT_RX_PKT_CNT                   0xf430a92c
#define NI_HV_INTPT_RX_PKT_CNT_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_pkt_cnt           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_INTPT_RX_PKT_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_INTPT_RX_PKT_BYTE_HI_CNT           0xf430a930
#define NI_HV_INTPT_RX_PKT_BYTE_HI_CNT_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_pkt_cnt           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_INTPT_RX_PKT_BYTE_HI_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_INTPT_RX_PKT_BYTE_LO_CNT           0xf430a934
#define NI_HV_INTPT_RX_PKT_BYTE_LO_CNT_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_pkt_cnt           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_INTPT_RX_PKT_BYTE_LO_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_INTPT_TX_MISSING_SOP_EOP_CNT       0xf430a938
#define NI_HV_INTPT_TX_MISSING_SOP_EOP_CNT_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_missing_eop_pkt_cnt : 16 ; /* bits 15:0 */
    u32 tx_missing_sop_pkt_cnt : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_INTPT_TX_MISSING_SOP_EOP_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_INTPT_TX_SHORT_ERR_CNT             0xf430a93c
#define NI_HV_INTPT_TX_SHORT_ERR_CNT_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_err_pkt_cnt       : 16 ; /* bits 15:0 */
    u32 tx_short_pkt_cnt     : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_INTPT_TX_SHORT_ERR_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_INTPT_TX_PKT_CNT                   0xf430a940
#define NI_HV_INTPT_TX_PKT_CNT_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_pkt_cnt           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_INTPT_TX_PKT_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_INTPT_TX_PKT_BYTE_HI_CNT           0xf430a944
#define NI_HV_INTPT_TX_PKT_BYTE_HI_CNT_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_pkt_cnt           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_INTPT_TX_PKT_BYTE_HI_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_INTPT_TX_PKT_BYTE_LO_CNT           0xf430a948
#define NI_HV_INTPT_TX_PKT_BYTE_LO_CNT_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_pkt_cnt           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_INTPT_TX_PKT_BYTE_LO_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XRAM_CPUXRAM_ADRCFG_RX             0xf430aa20
#define NI_HV_XRAM_CPUXRAM_ADRCFG_RX_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_base_addr         : 10 ; /* bits 9:0 */
    u32 rsrvd1               :  6 ;
    u32 rx_top_addr          : 10 ; /* bits 25:16 */
    u32 rsrvd2               :  6 ;
  } bf ;
  u32     wrd ;
} NI_HV_XRAM_CPUXRAM_ADRCFG_RX_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XRAM_CPUXRAM_ADRCFG_TX_0           0xf430aa24
#define NI_HV_XRAM_CPUXRAM_ADRCFG_TX_0_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_base_addr         : 10 ; /* bits 9:0 */
    u32 rsrvd1               :  6 ;
    u32 tx_top_addr          : 10 ; /* bits 25:16 */
    u32 rsrvd2               :  6 ;
  } bf ;
  u32     wrd ;
} NI_HV_XRAM_CPUXRAM_ADRCFG_TX_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XRAM_CPUXRAM_CFG                   0xf430aa28
#define NI_HV_XRAM_CPUXRAM_CFG_dft               0x0000c001

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_0_cpu_pkt_dis     :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  8 ;
    u32 tx_0_cpu_pkt_dis     :  1 ; /* bits 9:9 */
    u32 rsrvd2               :  1 ;
    u32 rx_x_drop_err_pkt    :  1 ; /* bits 11:11 */
    u32 xram_mgmt_dis_drop_ovsz_pkt :  1 ; /* bits 12:12 */
    u32 xram_mgmt_term_large_pkt :  1 ; /* bits 13:13 */
    u32 xram_mgmt_promisc_mode :  2 ; /* bits 15:14 */
    u32 xram_cntr_debug_mode :  1 ; /* bits 16:16 */
    u32 xram_cntr_op_code    :  2 ; /* bits 18:17 */
    u32 rsrvd3               :  2 ;
    u32 xram_rx_mgmtfifo_srst :  1 ; /* bits 21:21 */
    u32 xram_dma_fifo_srst   :  1 ; /* bits 22:22 */
    u32 rsrvd4               :  9 ;
  } bf ;
  u32     wrd ;
} NI_HV_XRAM_CPUXRAM_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XRAM_CPUXRAM_CPU_CFG_RX_0          0xf430aa2c
#define NI_HV_XRAM_CPUXRAM_CPU_CFG_RX_0_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_rd_ptr           : 10 ; /* bits 9:0 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} NI_HV_XRAM_CPUXRAM_CPU_CFG_RX_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XRAM_CPUXRAM_CPU_STA_RX_0          0xf430aa30
#define NI_HV_XRAM_CPUXRAM_CPU_STA_RX_0_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_wr_ptr           : 10 ; /* bits 9:0 */
    u32 rsrvd1               :  5 ;
    u32 int_colsc_thresh_reached :  1 ; /* bits 15:15 */
    u32 rsrvd2               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XRAM_CPUXRAM_CPU_STA_RX_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XRAM_CPUXRAM_INT_COLSC_CFG_0       0xf430aa34
#define NI_HV_XRAM_CPUXRAM_INT_COLSC_CFG_0_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 int_colsc_dly_time   : 20 ; /* bits 19:0 */
    u32 int_colsc_pkt        : 10 ; /* bits 29:20 */
    u32 int_colsc_first_en   :  1 ; /* bits 30:30 */
    u32 int_colsc_en         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XRAM_CPUXRAM_INT_COLSC_CFG_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XRAM_CPUXRAM_PKT_CNT_0             0xf430aa38
#define NI_HV_XRAM_CPUXRAM_PKT_CNT_0_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_to_xram          : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XRAM_CPUXRAM_PKT_CNT_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XRAM_CPUXRAM_BYT_CNT_0             0xf430aa3c
#define NI_HV_XRAM_CPUXRAM_BYT_CNT_0_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 byt_to_xram          : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} NI_HV_XRAM_CPUXRAM_BYT_CNT_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XRAM_CPUXRAM_PKT_ERR_DRP_0         0xf430aa40
#define NI_HV_XRAM_CPUXRAM_PKT_ERR_DRP_0_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_drop_err         : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XRAM_CPUXRAM_PKT_ERR_DRP_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XRAM_CPUXRAM_CPU_CFG_TX_0          0xf430aa44
#define NI_HV_XRAM_CPUXRAM_CPU_CFG_TX_0_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_wr_ptr           : 10 ; /* bits 9:0 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} NI_HV_XRAM_CPUXRAM_CPU_CFG_TX_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XRAM_CPUXRAM_CPU_STAT_TX_0         0xf430aa48
#define NI_HV_XRAM_CPUXRAM_CPU_STAT_TX_0_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_rd_ptr           : 10 ; /* bits 9:0 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} NI_HV_XRAM_CPUXRAM_CPU_STAT_TX_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XRAM_DMA_PKT_CNT                   0xf430aa4c
#define NI_HV_XRAM_DMA_PKT_CNT_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dma_pkt_to_cpu       : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} NI_HV_XRAM_DMA_PKT_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XRAM_DMA_BYTE_CNT                  0xf430aa50
#define NI_HV_XRAM_DMA_BYTE_CNT_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dma_byte_to_cpu      : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XRAM_DMA_BYTE_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_CTL_REG                        0xf430aa60
#define NI_HV_MCE_CTL_REG_dft                    0x0002f0ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ff_thrshd            : 10 ; /* bits 9:0 */
    u32 min_pktsize          :  6 ; /* bits 15:10 */
    u32 crc_err_drop_en      :  1 ; /* bits 16:16 */
    u32 cp_lspid_to_pol_id_en :  1 ; /* bits 17:17 */
    u32 buf_flush_en         :  1 ; /* bits 18:18 */
    u32 rsrvd1               : 13 ;
  } bf ;
  u32     wrd ;
} NI_HV_MCE_CTL_REG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_INDX_LKUP_ACCESS               0xf430aa64
#define NI_HV_MCE_INDX_LKUP_ACCESS_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 addr                 :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 22 ;
    u32 rbw                  :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_MCE_INDX_LKUP_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_INDX_LKUP_DATA1                0xf430aa68
#define NI_HV_MCE_INDX_LKUP_DATA1_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mc_vec               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_MCE_INDX_LKUP_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_INDX_LKUP_DATA0                0xf430aa6c
#define NI_HV_MCE_INDX_LKUP_DATA0_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mc_vec               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_MCE_INDX_LKUP_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_ZERO_BITMAP_DROP_CNT           0xf430aa70
#define NI_HV_MCE_ZERO_BITMAP_DROP_CNT_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_MCE_ZERO_BITMAP_DROP_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_INGRESS_CNT                    0xf430aa74
#define NI_HV_MCE_INGRESS_CNT_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_MCE_INGRESS_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_EGRESS_CNT                     0xf430aa78
#define NI_HV_MCE_EGRESS_CNT_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_MCE_EGRESS_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_LAST_IN_HDR2                   0xf430aa7c
#define NI_HV_MCE_LAST_IN_HDR2_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr2                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_MCE_LAST_IN_HDR2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_LAST_IN_HDR1                   0xf430aa80
#define NI_HV_MCE_LAST_IN_HDR1_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr1                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_MCE_LAST_IN_HDR1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_LAST_IN_HDR0                   0xf430aa84
#define NI_HV_MCE_LAST_IN_HDR0_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr0                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_MCE_LAST_IN_HDR0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_LAST_OUT_HDR2                  0xf430aa88
#define NI_HV_MCE_LAST_OUT_HDR2_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr2                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_MCE_LAST_OUT_HDR2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_LAST_OUT_HDR1                  0xf430aa8c
#define NI_HV_MCE_LAST_OUT_HDR1_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr1                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_MCE_LAST_OUT_HDR1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_LAST_OUT_HDR0                  0xf430aa90
#define NI_HV_MCE_LAST_OUT_HDR0_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 hdr0                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_MCE_LAST_OUT_HDR0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_ERROR_STS                      0xf430aa94
#define NI_HV_MCE_ERROR_STS_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 flag                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_MCE_ERROR_STS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_ERROR_STS1                     0xf430aa98
#define NI_HV_MCE_ERROR_STS1_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 flag                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_MCE_ERROR_STS1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_MCE_ERROR_STS2                     0xf430aa9c
#define NI_HV_MCE_ERROR_STS2_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 flag                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_MCE_ERROR_STS2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl0     0xf430af00
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_rx_mode         :  2 ; /* bits 1:0 */
    u32 rsrvd1               :  1 ;
    u32 xgxs_rx_random_6     :  1 ; /* bits 3:3 */
    u32 xgxs_rx_err_inj      :  4 ; /* bits 7:4 */
    u32 xgxs_fpat_sel        :  8 ; /* bits 15:8 */
    u32 rsrvd2               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl1     0xf430af04
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_fpat_0          :  9 ; /* bits 8:0 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl2     0xf430af08
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl2_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_fpat_1          :  9 ; /* bits 8:0 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl3     0xf430af0c
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl3_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_fpat_2          :  9 ; /* bits 8:0 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl4     0xf430af10
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl4_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_fpat_3          :  9 ; /* bits 8:0 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl4_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl5     0xf430af14
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl5_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_rx_phase        :  4 ; /* bits 3:0 */
    u32 rsrvd1               :  4 ;
    u32 xgxs_rx_fzero        :  4 ; /* bits 11:8 */
    u32 xgxs_rx_fone         :  4 ; /* bits 15:12 */
    u32 rsrvd2               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_RX_RxCntrl5_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RX_INTSTAT   0xf430af18
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RX_INTSTAT_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  1 ;
    u32 ErrorPktSat          :  1 ; /* bits 1:1 */
    u32 GoodPktSat           :  1 ; /* bits 2:2 */
    u32 rsrvd2               : 29 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_RX_RX_INTSTAT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RX_INTERRUPT 0xf430af1c
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RX_INTERRUPT_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ErrorPktI            :  1 ; /* bits 0:0 */
    u32 ErrorPktSatI         :  1 ; /* bits 1:1 */
    u32 GoodPktSatI          :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_RX_RX_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RX_INTENABLE 0xf430af20
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_RX_INTENABLE_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ErrorPkte            :  1 ; /* bits 0:0 */
    u32 ErrorPktSate         :  1 ; /* bits 1:1 */
    u32 GoodPktSate          :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_RX_RX_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_GoodPkt      0xf430af24
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_GoodPkt_dft  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 good_pkt_rx          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_RX_GoodPkt_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_ErrPkt       0xf430af28
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_ErrPkt_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 err_pkt_rx           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_RX_ErrPkt_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_SCRATCH      0xf430af2c
#define NI_HV_XAUI_XGXS_TOP_XGXS_RX_SCRATCH_dft  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 scratch              : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_RX_SCRATCH_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl0     0xf430af40
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_tx_mode         :  2 ; /* bits 1:0 */
    u32 rsrvd1               :  1 ;
    u32 xgxs_lf_enable       :  1 ; /* bits 3:3 */
    u32 rsrvd2               :  3 ;
    u32 xgxs_ddsa_enable     :  1 ; /* bits 7:7 */
    u32 xgxs_fpat_sel        :  8 ; /* bits 15:8 */
    u32 rsrvd3               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl1     0xf430af44
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_fpat_0          :  9 ; /* bits 8:0 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl2     0xf430af48
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl2_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_fpat_1          :  9 ; /* bits 8:0 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl3     0xf430af4c
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl3_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_fpat_2          :  9 ; /* bits 8:0 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl4     0xf430af50
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl4_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_fpat_3          :  9 ; /* bits 8:0 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl4_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl5     0xf430af54
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl5_dft 0x00000a00

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rxaui_cgalign_ena_mode :  2 ; /* bits 1:0 */
    u32 rxaui_a_column_ena_mode :  2 ; /* bits 3:2 */
    u32 rxaui_a_column_verify_mode :  1 ; /* bits 4:4 */
    u32 rxaui_lane_swap_01   :  1 ; /* bits 5:5 */
    u32 rxaui_lane_swap_23   :  1 ; /* bits 6:6 */
    u32 rsrvd1               :  1 ;
    u32 rxaui_comma_thresh   :  6 ; /* bits 13:8 */
    u32 rsrvd2               : 18 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_TxCntrl5_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TX_INTSTAT   0xf430af58
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TX_INTSTAT_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  1 ;
    u32 ErrorPktSat          :  1 ; /* bits 1:1 */
    u32 GoodPktSat           :  1 ; /* bits 2:2 */
    u32 rsrvd2               :  1 ;
    u32 InvCodeSat           :  1 ; /* bits 4:4 */
    u32 xgxs_comma_found_0   :  1 ; /* bits 5:5 */
    u32 PatErrSat            :  1 ; /* bits 6:6 */
    u32 xgxs_comma_found_1   :  1 ; /* bits 7:7 */
    u32 SyncDet0             :  1 ; /* bits 8:8 */
    u32 SyncDet1             :  1 ; /* bits 9:9 */
    u32 SyncDet2             :  1 ; /* bits 10:10 */
    u32 SyncDet3             :  1 ; /* bits 11:11 */
    u32 xgxs_align_det       :  1 ; /* bits 12:12 */
    u32 xgxs_cpat_lock       :  1 ; /* bits 13:13 */
    u32 xgxs_A_column_found_0 :  1 ; /* bits 14:14 */
    u32 xgxs_A_column_found_1 :  1 ; /* bits 15:15 */
    u32 rsrvd3               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_TX_INTSTAT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TX_INTERRUPT 0xf430af5c
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TX_INTERRUPT_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ErrorPktI            :  1 ; /* bits 0:0 */
    u32 ErrorPktSatI         :  1 ; /* bits 1:1 */
    u32 GoodPktSatI          :  1 ; /* bits 2:2 */
    u32 InvCodeI             :  1 ; /* bits 3:3 */
    u32 InvCodeSatI          :  1 ; /* bits 4:4 */
    u32 PatErrI              :  1 ; /* bits 5:5 */
    u32 PatErrSatI           :  1 ; /* bits 6:6 */
    u32 comma_foundI         :  1 ; /* bits 7:7 */
    u32 SyncDet0I            :  1 ; /* bits 8:8 */
    u32 SyncDet1I            :  1 ; /* bits 9:9 */
    u32 SyncDet2I            :  1 ; /* bits 10:10 */
    u32 SyncDet3I            :  1 ; /* bits 11:11 */
    u32 AlignDetI            :  1 ; /* bits 12:12 */
    u32 PatLockDetI          :  1 ; /* bits 13:13 */
    u32 A_column_found0I     :  1 ; /* bits 14:14 */
    u32 A_column_found1I     :  1 ; /* bits 15:15 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_TX_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TX_INTENABLE 0xf430af60
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_TX_INTENABLE_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ErrorPkte            :  1 ; /* bits 0:0 */
    u32 ErrorPktSate         :  1 ; /* bits 1:1 */
    u32 GoodPktSate          :  1 ; /* bits 2:2 */
    u32 InvCodee             :  1 ; /* bits 3:3 */
    u32 InvCodeSate          :  1 ; /* bits 4:4 */
    u32 PatErre              :  1 ; /* bits 5:5 */
    u32 PatErrSate           :  1 ; /* bits 6:6 */
    u32 CommaFounde          :  1 ; /* bits 7:7 */
    u32 SyncDet0e            :  1 ; /* bits 8:8 */
    u32 SyncDet1e            :  1 ; /* bits 9:9 */
    u32 SyncDet2e            :  1 ; /* bits 10:10 */
    u32 SyncDet3e            :  1 ; /* bits 11:11 */
    u32 AlignDete            :  1 ; /* bits 12:12 */
    u32 PatLockDete          :  1 ; /* bits 13:13 */
    u32 A_column_found0e     :  1 ; /* bits 14:14 */
    u32 A_column_found1e     :  1 ; /* bits 15:15 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_TX_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_GoodPkt      0xf430af64
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_GoodPkt_dft  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 good_pkt_tx          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_GoodPkt_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_ErrPkt       0xf430af68
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_ErrPkt_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 err_pkt_tx           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_ErrPkt_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_ICC0         0xf430af6c
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_ICC0_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_icc_0           : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_ICC0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_ICC1         0xf430af70
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_ICC1_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_icc_1           : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_ICC1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_ICC2         0xf430af74
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_ICC2_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_icc_2           : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_ICC2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_ICC3         0xf430af78
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_ICC3_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_icc_3           : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_ICC3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_PEC0         0xf430af7c
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_PEC0_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_pec_0           : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_PEC0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_PEC1         0xf430af80
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_PEC1_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_pec_1           : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_PEC1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_PEC2         0xf430af84
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_PEC2_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_pec_2           : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_PEC2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_PEC3         0xf430af88
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_PEC3_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgxs_pec_3           : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_PEC3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_SCRATCH      0xf430af8c
#define NI_HV_XAUI_XGXS_TOP_XGXS_TX_SCRATCH_dft  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 scratch              : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XGXS_TOP_XGXS_TX_SCRATCH_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_INTERRUPT  0xf430afa0
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_INTERRUPT_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rc_ffoverrun_intI    :  1 ; /* bits 0:0 */
    u32 tc_espkterr_intI     :  1 ; /* bits 1:1 */
    u32 rxestore0_intI       :  1 ; /* bits 2:2 */
    u32 rxestore1_intI       :  1 ; /* bits 3:3 */
    u32 rxestore2_intI       :  1 ; /* bits 4:4 */
    u32 rxestore3_intI       :  1 ; /* bits 5:5 */
    u32 txestore0_intI       :  1 ; /* bits 6:6 */
    u32 txestore1_intI       :  1 ; /* bits 7:7 */
    u32 txestore2_intI       :  1 ; /* bits 8:8 */
    u32 txestore3_intI       :  1 ; /* bits 9:9 */
    u32 rsrvd1               :  6 ;
    u32 rc_ptp_pkt_intI      :  1 ; /* bits 16:16 */
    u32 tc_ptp_pkt_intI      :  1 ; /* bits 17:17 */
    u32 rsrvd2               :  6 ;
    u32 tc_ffoverrun_intI    :  1 ; /* bits 24:24 */
    u32 tx_asyncff_underrun_intI :  1 ; /* bits 25:25 */
    u32 tx_asyncff_overrun_intI :  1 ; /* bits 26:26 */
    u32 rsrvd3               :  5 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_INTERRUPTE 0xf430afa4
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_INTERRUPTE_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rc_ffoverrun_intIE   :  1 ; /* bits 0:0 */
    u32 tc_espkterr_intIE    :  1 ; /* bits 1:1 */
    u32 rxestore0_intIE      :  1 ; /* bits 2:2 */
    u32 rxestore1_intIE      :  1 ; /* bits 3:3 */
    u32 rxestore2_intIE      :  1 ; /* bits 4:4 */
    u32 rxestore3_intIE      :  1 ; /* bits 5:5 */
    u32 txestore0_intIE      :  1 ; /* bits 6:6 */
    u32 txestore1_intIE      :  1 ; /* bits 7:7 */
    u32 txestore2_intIE      :  1 ; /* bits 8:8 */
    u32 txestore3_intIE      :  1 ; /* bits 9:9 */
    u32 rsrvd1               :  6 ;
    u32 rc_ptp_pkt_intIE     :  1 ; /* bits 16:16 */
    u32 tc_ptp_pkt_intIE     :  1 ; /* bits 17:17 */
    u32 rsrvd2               :  6 ;
    u32 tc_ffoverrun_intIE   :  1 ; /* bits 24:24 */
    u32 tx_asyncff_underrun_intIE :  1 ; /* bits 25:25 */
    u32 tx_asyncff_overrun_intIE :  1 ; /* bits 26:26 */
    u32 rsrvd3               :  5 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_INTERRUPTE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_CTRL_CFG        0xf430afa8
#define NI_HV_XAUI_XAUI_MAC_CTRL_CTRL_CFG_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx2tx_lpbk_en        :  1 ; /* bits 0:0 */
    u32 tx2rx_lpbk_en        :  1 ; /* bits 1:1 */
    u32 rs_locfault_en       :  1 ; /* bits 2:2 */
    u32 rs_rmtfault_en       :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_CTRL_CFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_BRIGE_CTRL      0xf430afac
#define NI_HV_XAUI_XAUI_MAC_CTRL_BRIGE_CTRL_dft  0xe4e40000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 flip_sds_xgxs_rx_en  :  1 ; /* bits 0:0 */
    u32 flip_sds_xgxs_tx_en  :  1 ; /* bits 1:1 */
    u32 pcs_line_swap_txd_en :  1 ; /* bits 2:2 */
    u32 pcs_line_swap_rxd_en :  1 ; /* bits 3:3 */
    u32 rx_invert_ctl        :  1 ; /* bits 4:4 */
    u32 tx_invert_ctl        :  1 ; /* bits 5:5 */
    u32 rx_data_resync0      :  1 ; /* bits 6:6 */
    u32 rx_data_resync1      :  1 ; /* bits 7:7 */
    u32 rx_data_resync2      :  1 ; /* bits 8:8 */
    u32 rx_data_resync3      :  1 ; /* bits 9:9 */
    u32 tx_data_resync0      :  1 ; /* bits 10:10 */
    u32 tx_data_resync1      :  1 ; /* bits 11:11 */
    u32 tx_data_resync2      :  1 ; /* bits 12:12 */
    u32 tx_data_resync3      :  1 ; /* bits 13:13 */
    u32 tx_scramble          :  1 ; /* bits 14:14 */
    u32 rx_scramble          :  1 ; /* bits 15:15 */
    u32 rxswap0              :  2 ; /* bits 17:16 */
    u32 rxswap1              :  2 ; /* bits 19:18 */
    u32 rxswap2              :  2 ; /* bits 21:20 */
    u32 rxswap3              :  2 ; /* bits 23:22 */
    u32 txswap0              :  2 ; /* bits 25:24 */
    u32 txswap1              :  2 ; /* bits 27:26 */
    u32 txswap2              :  2 ; /* bits 29:28 */
    u32 txswap3              :  2 ; /* bits 31:30 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_BRIGE_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_ADDRESS_H       0xf430afb0
#define NI_HV_XAUI_XAUI_MAC_CTRL_ADDRESS_H_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_ADDRESS_H_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_ADDRESS_L       0xf430afb4
#define NI_HV_XAUI_XAUI_MAC_CTRL_ADDRESS_L_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 address              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_ADDRESS_L_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_CTRL_MODE       0xf430afb8
#define NI_HV_XAUI_XAUI_MAC_CTRL_CTRL_MODE_dft   0x40003601

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ctrl_mode_en         :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  3 ;
    u32 flush_pkt_en         :  5 ; /* bits 8:4 */
    u32 flush_pkt_en1        :  1 ; /* bits 9:9 */
    u32 flush_pkt_sdid       :  1 ; /* bits 10:10 */
    u32 rsrvd2               :  1 ;
    u32 pkt_tocsport_en      :  1 ; /* bits 12:12 */
    u32 pkt_toupport_en      :  1 ; /* bits 13:13 */
    u32 pkt_tocsport_toup    :  1 ; /* bits 14:14 */
    u32 pkt_toupport_tocs    :  1 ; /* bits 15:15 */
    u32 flush_touplink_pkt   :  1 ; /* bits 16:16 */
    u32 rsrvd3               : 13 ;
    u32 mask_nop_en          :  1 ; /* bits 30:30 */
    u32 mask_ddbm_en         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_CTRL_MODE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_CTL     0xf430afbc
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_CTL_dft 0x0007b800

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 clr_rcffoverrun      :  1 ; /* bits 0:0 */
    u32 drop_ptp_pkt_type    : 10 ; /* bits 10:1 */
    u32 qbb_pause_drop_en    :  1 ; /* bits 11:11 */
    u32 frame_error_drop_en  :  1 ; /* bits 12:12 */
    u32 frame_fcs_error_drop_en :  1 ; /* bits 13:13 */
    u32 frame_bytecnt_drop_en :  1 ; /* bits 14:14 */
    u32 frame_pause_drop_en  :  1 ; /* bits 15:15 */
    u32 frame_runt_drop_en   :  1 ; /* bits 16:16 */
    u32 frame_oversize_drop_en :  1 ; /* bits 17:17 */
    u32 frame_ffoverflow_drop_en :  1 ; /* bits 18:18 */
    u32 frame_management_drop_en :  1 ; /* bits 19:19 */
    u32 frame_nomanagement_drop_en :  1 ; /* bits 20:20 */
    u32 rsrvd1               :  2 ;
    u32 qbb_pause_det_en     :  1 ; /* bits 23:23 */
    u32 bypass               :  1 ; /* bits 24:24 */
    u32 ptp_ing_ts_cmp       :  5 ; /* bits 29:25 */
    u32 rx_pkt_clr           :  1 ; /* bits 30:30 */
    u32 ptp_da_en            :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_CTL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_DA_HI 0xf430afc0
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_DA_HI_dft 0x00000180

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 management_da        : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_DA_HI_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_DA_LO 0xf430afc4
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_DA_LO_dft 0xc2000001

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 management_da        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_DA_LO_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE0 0xf430afc8
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE0_dft 0x00008809

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 management_type0     : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 15 ;
    u32 det_type0_en         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE1 0xf430afcc
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE1_dft 0x00008808

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 management_type1     : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 15 ;
    u32 det_type1_en         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE2 0xf430afd0
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE2_dft 0x00008863

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 management_type2     : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 15 ;
    u32 det_type2_en         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE3 0xf430afd4
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE3_dft 0x00008864

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 management_type3     : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 15 ;
    u32 det_type3_en         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE4 0xf430afd8
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE4_dft 0x0000888e

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 management_type4     : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 15 ;
    u32 det_type4_en         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE4_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE5 0xf430afdc
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE5_dft 0x00000806

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 management_type5     : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 15 ;
    u32 det_type5_en         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE5_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE6 0xf430afe0
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE6_dft 0x0000814c

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 management_type6     : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 15 ;
    u32 det_type6_en         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE6_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE7 0xf430afe4
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE7_dft 0x0000ffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 management_type7     : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 15 ;
    u32 det_type7_en         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_MANAGEMENT_TYPE7_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_FLOWON_CTL 0xf430afe8
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_FLOWON_CTL_dft 0x000001ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xon_threshold        : 10 ; /* bits 9:0 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_FLOWON_CTL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_FLOWOFF_CTL 0xf430afec
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_FLOWOFF_CTL_dft 0x000002ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xoff_threshold       : 10 ; /* bits 9:0 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_FLOWOFF_CTL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_CTL     0xf430aff0
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_CTL_dft 0x00ff0000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pau_flow_en          :  1 ; /* bits 0:0 */
    u32 tx_remheader_dis     :  1 ; /* bits 1:1 */
    u32 tx_pkt_clr           :  1 ; /* bits 2:2 */
    u32 tx_pad_en            :  1 ; /* bits 3:3 */
    u32 loopback             :  1 ; /* bits 4:4 */
    u32 ptp_eg_ts_comp       :  5 ; /* bits 9:5 */
    u32 external_pausereq_pol :  1 ; /* bits 10:10 */
    u32 rsrvd1               :  4 ;
    u32 qbb_flow_en          :  1 ; /* bits 15:15 */
    u32 qbb_qen              :  8 ; /* bits 23:16 */
    u32 rsrvd2               :  3 ;
    u32 external_txstop_sel  :  1 ; /* bits 27:27 */
    u32 internal_txstop_sel  :  1 ; /* bits 28:28 */
    u32 external_pausereq_sel :  1 ; /* bits 29:29 */
    u32 rx_pausereq_sel      :  1 ; /* bits 30:30 */
    u32 te_pfcreq_sel        :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_CTL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA  0xf430aff4
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA_dft 0x7f0dffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pause_quanta         : 16 ; /* bits 15:0 */
    u32 adjust_qbb_cnt       :  8 ; /* bits 23:16 */
    u32 adjust_1g_qbb_cnt    :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA1 0xf430aff8
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA1_dft 0x0000ffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pause_quanta         : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA2 0xf430affc
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA2_dft 0x0000ffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pause_quanta         : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA3 0xf430b000
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA3_dft 0x0000ffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pause_quanta         : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA4 0xf430b004
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA4_dft 0x0000ffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pause_quanta         : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA4_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA5 0xf430b008
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA5_dft 0x0000ffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pause_quanta         : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA5_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA6 0xf430b00c
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA6_dft 0x0000ffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pause_quanta         : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA6_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA7 0xf430b010
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA7_dft 0x0000ffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pause_quanta         : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_QUANTA7_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_FF_THRESHOLD 0xf430b014
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_FF_THRESHOLD_dft 0x803f01fa

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 txff_wrff_threshold  :  6 ; /* bits 5:0 */
    u32 txff_rdff_threshold  :  6 ; /* bits 11:6 */
    u32 txctl_wrff_threshold :  9 ; /* bits 20:12 */
    u32 rd_thre_en           :  1 ; /* bits 21:21 */
    u32 rsrvd1               :  1 ;
    u32 txctl_rdff_threshold :  9 ; /* bits 31:23 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_FF_THRESHOLD_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS0 0xf430b018
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rcdrop_cnt           : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS1 0xf430b01c
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rcff_pktnum          : 11 ; /* bits 10:0 */
    u32 rs_locfault          :  1 ; /* bits 11:11 */
    u32 rs_rmtfault          :  1 ; /* bits 12:12 */
    u32 rsrvd1               : 19 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS2 0xf430b020
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS2_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_torxmux_cnt      : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS3 0xf430b024
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS3_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_tocstxmux_cnt    : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS4 0xf430b028
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS4_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_touptxmux_cnt    : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS4_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS5 0xf430b02c
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS5_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_tocstxmux_errcnt :  5 ; /* bits 4:0 */
    u32 rsrvd1               : 27 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS5_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS6 0xf430b030
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS6_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pkt_cs_flushcnt      :  5 ; /* bits 4:0 */
    u32 rsrvd1               : 27 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_STATUS6_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_STATUS0 0xf430b034
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_STATUS0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tcdrop_cnt           : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_STATUS0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_STATUS1 0xf430b038
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_STATUS1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tcff_pktnum          :  9 ; /* bits 8:0 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_STATUS1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_STATUS3 0xf430b03c
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_STATUS3_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 length_mismatch      :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_STATUS3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_STATUS4 0xf430b040
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_STATUS4_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 es_runt_pkt          :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_STATUS4_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_FF_STATUS  0xf430b044
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_FF_STATUS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_ffempty           :  1 ; /* bits 0:0 */
    u32 tx_fffull            :  1 ; /* bits 1:1 */
    u32 rx_ffempty           :  1 ; /* bits 2:2 */
    u32 rx_fffull            :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_FF_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_BP_CTRL    0xf430b048
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_BP_CTRL_dft 0x00ffd200

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cascade_bp_en        :  1 ; /* bits 0:0 */
    u32 external_stoptx_en   :  1 ; /* bits 1:1 */
    u32 external_pausereq_en :  1 ; /* bits 2:2 */
    u32 external_pausereq_pol :  1 ; /* bits 3:3 */
    u32 cascade_ff_threshold : 10 ; /* bits 13:4 */
    u32 external_pausereq_oen_sel :  1 ; /* bits 14:14 */
    u32 external_pausereq_oen :  1 ; /* bits 15:15 */
    u32 xaui_die_tx_threshold :  9 ; /* bits 24:16 */
    u32 external_stop_lcl_en :  1 ; /* bits 25:25 */
    u32 uplink_lcl_pol       :  1 ; /* bits 26:26 */
    u32 rsrvd1               :  1 ;
    u32 dbg_sel              :  3 ; /* bits 30:28 */
    u32 die_cascade_bp_en    :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_BP_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_SLD_ERRCNT 0xf430b04c
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_SLD_ERRCNT_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sld_crc8_err_cnt     : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_SLD_ERRCNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_MIB_RAM_STATUS_REG 0xf430b050
#define NI_HV_XAUI_XAUI_MAC_CTRL_MIB_RAM_STATUS_REG_dft 0x00000001

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ram_initdone         :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_MIB_RAM_STATUS_REG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_MIB_CTL         0xf430b054
#define NI_HV_XAUI_XAUI_MAC_CTRL_MIB_CTL_dft     0x00000019

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ram_clr_en           :  1 ; /* bits 0:0 */
    u32 ram_sw_initial       :  1 ; /* bits 1:1 */
    u32 dbg_sel              :  1 ; /* bits 2:2 */
    u32 term_dbg_en          :  1 ; /* bits 3:3 */
    u32 rt_mib_en            :  1 ; /* bits 4:4 */
    u32 rsrvd1               : 27 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_MIB_CTL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_RX_MIB_ACC_ACCESS 0xf430b058
#define NI_HV_XAUI_XAUI_MAC_CTRL_RX_MIB_ACC_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 Addr                 :  5 ; /* bits 4:0 */
    u32 rsrvd1               : 25 ;
    u32 rw                   :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_RX_MIB_ACC_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_RX_MIB_ACC_DATA 0xf430b05c
#define NI_HV_XAUI_XAUI_MAC_CTRL_RX_MIB_ACC_DATA_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_RX_MIB_ACC_DATA_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_TX_MIB_ACC_ACCESS 0xf430b060
#define NI_HV_XAUI_XAUI_MAC_CTRL_TX_MIB_ACC_ACCESS_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 Addr                 :  5 ; /* bits 4:0 */
    u32 rsrvd1               : 25 ;
    u32 rw                   :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_TX_MIB_ACC_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_TX_MIB_ACC_DATA 0xf430b064
#define NI_HV_XAUI_XAUI_MAC_CTRL_TX_MIB_ACC_DATA_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_TX_MIB_ACC_DATA_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_MIB_RX_DROPCNT  0xf430b068
#define NI_HV_XAUI_XAUI_MAC_CTRL_MIB_RX_DROPCNT_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mib_drop_cnt         : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_MIB_RX_DROPCNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_MIB_TX_DROPCNT  0xf430b06c
#define NI_HV_XAUI_XAUI_MAC_CTRL_MIB_TX_DROPCNT_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mib_drop_cnt         : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_MIB_TX_DROPCNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_TX_PKT_MIB      0xf430b070
#define NI_HV_XAUI_XAUI_MAC_CTRL_TX_PKT_MIB_dft  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 count                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_TX_PKT_MIB_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_RX_PKT_MIB      0xf430b074
#define NI_HV_XAUI_XAUI_MAC_CTRL_RX_PKT_MIB_dft  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 count                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_RX_PKT_MIB_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_MIB_RX_BYTECNT_HI 0xf430b078
#define NI_HV_XAUI_XAUI_MAC_CTRL_MIB_RX_BYTECNT_HI_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mib_cnt              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_MIB_RX_BYTECNT_HI_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_MIB_TX_BYTECNT_HI 0xf430b07c
#define NI_HV_XAUI_XAUI_MAC_CTRL_MIB_TX_BYTECNT_HI_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mib_cnt              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_MIB_TX_BYTECNT_HI_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PAU     0xf430b080
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PAU_dft 0x80000005

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wait_cnt             : 16 ; /* bits 15:0 */
    u32 repeat_cnt           : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PAU_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_DIE0    0xf430b084
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_DIE0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pktcnt               : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_DIE0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_DIE1    0xf430b088
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_DIE1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pktcnt               : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_DIE1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_DIE2    0xf430b08c
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_DIE2_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pktcnt               : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_DIE2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_DIE3    0xf430b090
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_DIE3_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pktcnt               : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_DIE3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_UPLINK  0xf430b094
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_UPLINK_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pktcnt               : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_UPLINK_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_PTP_TM  0xf430b098
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_PTP_TM_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ptp_tm               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_PTP_TM_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_PTP_TM_S_LO 0xf430b09c
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_PTP_TM_S_LO_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ptp_tm               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_PTP_TM_S_LO_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_PTP_TM_S_HI 0xf430b0a0
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_PTP_TM_S_HI_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ptp_tm               : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_PTP_TM_S_HI_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_PTP_TYPE 0xf430b0a4
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_PTP_TYPE_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ptp_type             :  2 ; /* bits 1:0 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_PTP_TYPE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_PTP_SQID 0xf430b0a8
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_PTP_SQID_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sq_id                : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_PTP_SQID_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PTP_TM  0xf430b0ac
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PTP_TM_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ptp_tm               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PTP_TM_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PTP_TM_S_LO 0xf430b0b0
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PTP_TM_S_LO_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ptp_tm               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PTP_TM_S_LO_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PTP_TM_S_HI 0xf430b0b4
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PTP_TM_S_HI_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ptp_tm               : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PTP_TM_S_HI_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PTP_TYPE 0xf430b0b8
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PTP_TYPE_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ptp_type             :  2 ; /* bits 1:0 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PTP_TYPE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PTP_SQID 0xf430b0bc
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PTP_SQID_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sq_id                : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TX_PTP_SQID_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_CT_CTL     0xf430b0c0
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_CT_CTL_dft 0x81000002

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_ct_mode_en        :  1 ; /* bits 0:0 */
    u32 drop_ct_en           :  1 ; /* bits 1:1 */
    u32 tx_ct_mode_en        :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 13 ;
    u32 ct_tpid              : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_CT_CTL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_CT_LLID_CTL 0xf430b0c4
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_CT_LLID_CTL_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pon_llid             : 13 ; /* bits 12:0 */
    u32 rsrvd1               :  3 ;
    u32 xgpon_llid           : 13 ; /* bits 28:16 */
    u32 rsrvd2               :  3 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_CT_LLID_CTL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_PTP_VLAN0  0xf430b0c8
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_PTP_VLAN0_dft 0x81009100

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 vlan0                : 16 ; /* bits 15:0 */
    u32 vlan1                : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_PTP_VLAN0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_PTP_VLAN1  0xf430b0cc
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_PTP_VLAN1_dft 0x81009100

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 vlan0                : 16 ; /* bits 15:0 */
    u32 vlan1                : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_PTP_VLAN1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_DBG0            0xf430b0d0
#define NI_HV_XAUI_XAUI_MAC_CTRL_DBG0_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dbg                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_DBG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_DBG1            0xf430b0d4
#define NI_HV_XAUI_XAUI_MAC_CTRL_DBG1_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dbg                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_DBG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_DBG2            0xf430b0d8
#define NI_HV_XAUI_XAUI_MAC_CTRL_DBG2_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dbg                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_DBG2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_DBG3            0xf430b0dc
#define NI_HV_XAUI_XAUI_MAC_CTRL_DBG3_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dbg                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_DBG3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_GE_DBG_RX_CNT   0xf430b0e0
#define NI_HV_XAUI_XAUI_MAC_CTRL_GE_DBG_RX_CNT_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_GE_DBG_RX_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_GE_DBG_TX_CNT   0xf430b0e4
#define NI_HV_XAUI_XAUI_MAC_CTRL_GE_DBG_TX_CNT_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt                  : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_GE_DBG_TX_CNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_FLUSH_KNOW 0xf430b0e8
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_FLUSH_KNOW_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pktcnt               : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_FLUSH_KNOW_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_FLUSH_SDID 0xf430b0ec
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_FLUSH_SDID_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pktcnt               : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_FLUSH_SDID_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RXFPGA_DROPCNT 0xf430b0f0
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RXFPGA_DROPCNT_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 asyncff_dropcnt      : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RXFPGA_DROPCNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RXFPGA_FF_THRESHOLD 0xf430b0f4
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RXFPGA_FF_THRESHOLD_dft 0x30000090

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_wrff_threshold    :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 20 ;
    u32 rx_rdff_ipg          :  3 ; /* bits 30:28 */
    u32 rsrvd2               :  1 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RXFPGA_FF_THRESHOLD_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TXFPGA_FF_THRESHOLD 0xf430b0f8
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TXFPGA_FF_THRESHOLD_dft 0x004000f0

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_wrff_threshold    :  8 ; /* bits 7:0 */
    u32 rsrvd1               :  8 ;
    u32 tx_rdff_threshold    :  8 ; /* bits 23:16 */
    u32 rsrvd2               :  8 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_TXFPGA_FF_THRESHOLD_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_DBGCNT0 0xf430b0fc
#define NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_DBGCNT0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rc_sop_cnt           : 16 ; /* bits 15:0 */
    u32 rc_eop_cnt           : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_XAUI_RX_DBGCNT0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_SPARE           0xf430b100
#define NI_HV_XAUI_XAUI_MAC_CTRL_SPARE_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 spare                :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_SPARE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_SPARE1          0xf430b104
#define NI_HV_XAUI_XAUI_MAC_CTRL_SPARE1_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 spare                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_SPARE1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_CONTROL_0 0xf430b108
#define NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_CONTROL_0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 prbsEnabled          :  1 ; /* bits 0:0 */
    u32 loadPrbsState        :  1 ; /* bits 1:1 */
    u32 clrCnt               :  1 ; /* bits 2:2 */
    u32 rsrvd1               :  1 ;
    u32 prbs_mode            :  2 ; /* bits 5:4 */
    u32 rsrvd2               :  2 ;
    u32 insertError          :  1 ; /* bits 8:8 */
    u32 insertErrorOnce      :  1 ; /* bits 9:9 */
    u32 insertOneBitError    :  1 ; /* bits 10:10 */
    u32 insertOneBitErrorOnce :  1 ; /* bits 11:11 */
    u32 rsrvd3               : 20 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_CONTROL_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_ERRCNT_0 0xf430b10c
#define NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_ERRCNT_0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 prbsErrCnt           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_ERRCNT_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_SYNC_0 0xf430b110
#define NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_SYNC_0_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 syncState            :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_SYNC_0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_CONTROL_1 0xf430b114
#define NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_CONTROL_1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 prbsEnabled          :  1 ; /* bits 0:0 */
    u32 loadPrbsState        :  1 ; /* bits 1:1 */
    u32 clrCnt               :  1 ; /* bits 2:2 */
    u32 rsrvd1               :  1 ;
    u32 prbs_mode            :  2 ; /* bits 5:4 */
    u32 rsrvd2               :  2 ;
    u32 insertError          :  1 ; /* bits 8:8 */
    u32 insertErrorOnce      :  1 ; /* bits 9:9 */
    u32 insertOneBitError    :  1 ; /* bits 10:10 */
    u32 insertOneBitErrorOnce :  1 ; /* bits 11:11 */
    u32 rsrvd3               : 20 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_CONTROL_1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_ERRCNT_1 0xf430b118
#define NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_ERRCNT_1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 prbsErrCnt           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_ERRCNT_1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_SYNC_1 0xf430b11c
#define NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_SYNC_1_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 syncState            :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_CTRL_RXAUI_PRBS_SYNC_1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_TXMAC_TX_CONFIG      0xf430b120
#define NI_HV_XAUI_XAUI_MAC_TXMAC_TX_CONFIG_dft  0x40000070

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 insert_cshead        :  1 ; /* bits 0:0 */
    u32 reset                :  1 ; /* bits 1:1 */
    u32 flow_en              :  1 ; /* bits 2:2 */
    u32 mac_en               :  1 ; /* bits 3:3 */
    u32 crc_recaculate_en    :  1 ; /* bits 4:4 */
    u32 swap_crc8_en         :  1 ; /* bits 5:5 */
    u32 swap_datain_en       :  1 ; /* bits 6:6 */
    u32 rsrvd1               :  6 ;
    u32 dic_mode             :  2 ; /* bits 14:13 */
    u32 rsrvd2               : 15 ;
    u32 link_fault_en        :  1 ; /* bits 30:30 */
    u32 insert_nop           :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_TXMAC_TX_CONFIG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_TXMAC_ASYNC_FF_STATUS 0xf430b124
#define NI_HV_XAUI_XAUI_MAC_TXMAC_ASYNC_FF_STATUS_dft 0x00000001

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 empty                :  1 ; /* bits 0:0 */
    u32 full                 :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_TXMAC_ASYNC_FF_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_TXMAC_TX_DBG0        0xf430b128
#define NI_HV_XAUI_XAUI_MAC_TXMAC_TX_DBG0_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dbg                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_TXMAC_TX_DBG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_TXMAC_TX_DBG1        0xf430b12c
#define NI_HV_XAUI_XAUI_MAC_TXMAC_TX_DBG1_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dbg                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_TXMAC_TX_DBG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_RXMAC_RX_CONFIG      0xf430b140
#define NI_HV_XAUI_XAUI_MAC_RXMAC_RX_CONFIG_dft  0x23f10230

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  1 ;
    u32 reset                :  1 ; /* bits 1:1 */
    u32 dxaui_quanta_mode    :  1 ; /* bits 2:2 */
    u32 rsrvd2               :  1 ;
    u32 swap_crc8_en         :  1 ; /* bits 4:4 */
    u32 swap_datain_en       :  1 ; /* bits 5:5 */
    u32 rsrvd3               :  1 ;
    u32 mac_en               :  1 ; /* bits 7:7 */
    u32 rsrvd4               :  1 ;
    u32 pause_en             :  1 ; /* bits 9:9 */
    u32 rsrvd5               :  6 ;
    u32 max_size             : 14 ; /* bits 29:16 */
    u32 rsrvd6               :  2 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_RXMAC_RX_CONFIG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_RXMAC_RX_PKT_DET     0xf430b144
#define NI_HV_XAUI_XAUI_MAC_RXMAC_RX_PKT_DET_dft 0x00000066

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 check_idle           :  1 ; /* bits 0:0 */
    u32 check_start          :  1 ; /* bits 1:1 */
    u32 check_sld            :  1 ; /* bits 2:2 */
    u32 check_preamble       :  1 ; /* bits 3:3 */
    u32 check_bf_start       :  1 ; /* bits 4:4 */
    u32 check_crc8           :  1 ; /* bits 5:5 */
    u32 check_terminate      :  1 ; /* bits 6:6 */
    u32 rx_revcs             :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_RXMAC_RX_PKT_DET_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_RXMAC_RX_CASCADE_HD  0xf430b148
#define NI_HV_XAUI_XAUI_MAC_RXMAC_RX_CASCADE_HD_dft 0x10000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cascade_hd           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_RXMAC_RX_CASCADE_HD_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_RXMAC_RX_INIT_CASCADE_HD 0xf430b14c
#define NI_HV_XAUI_XAUI_MAC_RXMAC_RX_INIT_CASCADE_HD_dft 0x10000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cascade_hd           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_RXMAC_RX_INIT_CASCADE_HD_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_RXMAC_RX_ASYNC_FF_OVERFLOW 0xf430b150
#define NI_HV_XAUI_XAUI_MAC_RXMAC_RX_ASYNC_FF_OVERFLOW_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_asyncff_overflow  :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_RXMAC_RX_ASYNC_FF_OVERFLOW_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_RXMAC_RX_DBG0        0xf430b154
#define NI_HV_XAUI_XAUI_MAC_RXMAC_RX_DBG0_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dbg                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_RXMAC_RX_DBG0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_MAC_RXMAC_RX_DBG1        0xf430b158
#define NI_HV_XAUI_XAUI_MAC_RXMAC_RX_DBG1_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dbg                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_MAC_RXMAC_RX_DBG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_XGRS_TX_TXCNTRL          0xf430b160
#define NI_HV_XAUI_XAUI_XGRS_TX_TXCNTRL_dft      0x00000013

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_localOrdEn        :  1 ; /* bits 0:0 */
    u32 tx_remoteOrdEn       :  1 ; /* bits 1:1 */
    u32 tx_userOrdEn         :  1 ; /* bits 2:2 */
    u32 tx_dataTruncEn       :  1 ; /* bits 3:3 */
    u32 tx_pcs6_line_txd_en  :  1 ; /* bits 4:4 */
    u32 rsrvd1               : 10 ;
    u32 tx_logicReset        :  1 ; /* bits 15:15 */
    u32 rsrvd2               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_XGRS_TX_TXCNTRL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_XGRS_TX_TXUSERORD1       0xf430b164
#define NI_HV_XAUI_XAUI_XGRS_TX_TXUSERORD1_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_userOrdL1         :  8 ; /* bits 7:0 */
    u32 tx_userOrdL2         :  8 ; /* bits 15:8 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_XGRS_TX_TXUSERORD1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_XGRS_TX_TXUSERORD2       0xf430b168
#define NI_HV_XAUI_XAUI_XGRS_TX_TXUSERORD2_dft   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_userOrdL3         :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_XGRS_TX_TXUSERORD2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_XGRS_TX_TXINT            0xf430b16c
#define NI_HV_XAUI_XAUI_XGRS_TX_TXINT_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 truncPktI            :  1 ; /* bits 0:0 */
    u32 truncPktSatI         :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_XGRS_TX_TXINT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_XGRS_TX_TXINTENABLE      0xf430b170
#define NI_HV_XAUI_XAUI_XGRS_TX_TXINTENABLE_dft  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 truncPktE            :  1 ; /* bits 0:0 */
    u32 truncPktSatE         :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_XGRS_TX_TXINTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_XGRS_TX_TRUNCPKT         0xf430b174
#define NI_HV_XAUI_XAUI_XGRS_TX_TRUNCPKT_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 trunc_pkt_tx         : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_XGRS_TX_TRUNCPKT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_XGRS_TX_OIDLECOUNT       0xf430b178
#define NI_HV_XAUI_XAUI_XGRS_TX_OIDLECOUNT_dft   0x00000006

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 oidle_pkt_tx         :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_XGRS_TX_OIDLECOUNT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_XGRS_RX_RXCNTRL1         0xf430b180
#define NI_HV_XAUI_XAUI_XGRS_RX_RXCNTRL1_dft     0x0000028f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_dataLosEn         :  1 ; /* bits 0:0 */
    u32 rx_lockLosEn         :  1 ; /* bits 1:1 */
    u32 rx_sigLosEn          :  1 ; /* bits 2:2 */
    u32 rx_phyRLFEn          :  1 ; /* bits 3:3 */
    u32 rx_losPolarity       :  1 ; /* bits 4:4 */
    u32 rsrvd1               :  2 ;
    u32 rx_noIpg             :  1 ; /* bits 7:7 */
    u32 rx_ofsmUNHEn         :  1 ; /* bits 8:8 */
    u32 rx_pcs6_line_rxd_en  :  1 ; /* bits 9:9 */
    u32 rsrvd2               :  5 ;
    u32 rx_logicReset        :  1 ; /* bits 15:15 */
    u32 rsrvd3               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_XGRS_RX_RXCNTRL1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_XGRS_RX_RXCNTRL2         0xf430b184
#define NI_HV_XAUI_XAUI_XGRS_RX_RXCNTRL2_dft     0x0000037f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_col_thr           :  8 ; /* bits 7:0 */
    u32 rx_seq_thr           :  4 ; /* bits 11:8 */
    u32 rsrvd1               : 20 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_XGRS_RX_RXCNTRL2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_XGRS_RX_RXSTATUS         0xf430b188
#define NI_HV_XAUI_XAUI_XGRS_RX_RXSTATUS_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 localordS            :  1 ; /* bits 0:0 */
    u32 remoteordS           :  1 ; /* bits 1:1 */
    u32 unknownordS          :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_XGRS_RX_RXSTATUS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_XGRS_RX_RXINT            0xf430b18c
#define NI_HV_XAUI_XAUI_XGRS_RX_RXINT_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 localordI            :  1 ; /* bits 0:0 */
    u32 remoteordI           :  1 ; /* bits 1:1 */
    u32 unknownordI          :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_XGRS_RX_RXINT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_XGRS_RX_RXINTENABLE      0xf430b190
#define NI_HV_XAUI_XAUI_XGRS_RX_RXINTENABLE_dft  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 localordE            :  1 ; /* bits 0:0 */
    u32 remoteordE           :  1 ; /* bits 1:1 */
    u32 unknownordE          :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_XGRS_RX_RXINTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_XGRS_RX_UNKNOWNORD1      0xf430b194
#define NI_HV_XAUI_XAUI_XGRS_RX_UNKNOWNORD1_dft  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_unknownOrd_l1     :  8 ; /* bits 7:0 */
    u32 rx_unknownOrd_l2     :  8 ; /* bits 15:8 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_XGRS_RX_UNKNOWNORD1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_XGRS_RX_UNKNOWNORD2      0xf430b198
#define NI_HV_XAUI_XAUI_XGRS_RX_UNKNOWNORD2_dft  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_unknownOrd_l3     :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_XGRS_RX_UNKNOWNORD2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XAUI_XAUI_XGRS_RX_FAULT_SEL        0xf430b19c
#define NI_HV_XAUI_XAUI_XGRS_RX_FAULT_SEL_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 loc_fault_sel        :  1 ; /* bits 0:0 */
    u32 rmt_fault_sel        :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} NI_HV_XAUI_XAUI_XGRS_RX_FAULT_SEL_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_CFG_COM                    0xf430b200
#define NI_HV_XGE_MAC_CFG_COM_dft                0x0000e018

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rpr_mode             :  1 ; /* bits 0:0 */
    u32 stack_en             :  1 ; /* bits 1:1 */
    u32 clronread            :  1 ; /* bits 2:2 */
    u32 rt_mib_en            :  1 ; /* bits 3:3 */
    u32 stats_err_order      :  3 ; /* bits 6:4 */
    u32 stats_drop_en        :  1 ; /* bits 7:7 */
    u32 core_tx2rx_lb        :  1 ; /* bits 8:8 */
    u32 core_rx2tx_lb        :  1 ; /* bits 9:9 */
    u32 rsrvd1               :  3 ;
    u32 cntr_rst             :  1 ; /* bits 13:13 */
    u32 rx_rst               :  1 ; /* bits 14:14 */
    u32 tx_rst               :  1 ; /* bits 15:15 */
    u32 rsrvd2               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_CFG_COM_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_CFG_RX                     0xf430b204
#define NI_HV_XGE_MAC_CFG_RX_dft                 0x00000bc1

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 promis_mode          :  1 ; /* bits 0:0 */
    u32 drop_short           :  1 ; /* bits 1:1 */
    u32 strip                :  2 ; /* bits 3:2 */
    u32 pause_term           :  1 ; /* bits 4:4 */
    u32 pause_extract        :  1 ; /* bits 5:5 */
    u32 len_chk_en           :  1 ; /* bits 6:6 */
    u32 len_chk_en_pause     :  1 ; /* bits 7:7 */
    u32 len_chk_en_pad       :  1 ; /* bits 8:8 */
    u32 fcs_chk_en           :  1 ; /* bits 9:9 */
    u32 IFG_mode_rx          :  1 ; /* bits 10:10 */
    u32 crc_err_fatal        :  1 ; /* bits 11:11 */
    u32 maxlen_mode          :  1 ; /* bits 12:12 */
    u32 prmbl_sfd_gmii_err   :  1 ; /* bits 13:13 */
    u32 rsrvd1               : 18 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_CFG_RX_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_CFG_TX                     0xf430b208
#define NI_HV_XGE_MAC_CFG_TX_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 IFG_mode_tx          :  2 ; /* bits 1:0 */
    u32 halt                 :  1 ; /* bits 2:2 */
    u32 insSA                :  1 ; /* bits 3:3 */
    u32 pause_req_en         :  1 ; /* bits 4:4 */
    u32 pause_req_auto_xon   :  1 ; /* bits 5:5 */
    u32 lf_auto_flush_en     :  1 ; /* bits 6:6 */
    u32 vlan_pad_mode        :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_CFG_TX_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_CFG_TX_2                   0xf430b20c
#define NI_HV_XGE_MAC_CFG_TX_2_dft               0x0000060e

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 fifo1_thr_afull      :  5 ; /* bits 4:0 */
    u32 rsrvd1               :  3 ;
    u32 fifo1_read_thr       :  5 ; /* bits 12:8 */
    u32 rsrvd2               : 19 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_CFG_TX_2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_CFG_TX_IFG                 0xf430b210
#define NI_HV_XGE_MAC_CFG_TX_IFG_dft             0x0000000c

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ifg                  : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_CFG_TX_IFG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_MAC_ADDR_A                 0xf430b214
#define NI_HV_XGE_MAC_MAC_ADDR_A_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 addr                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_MAC_ADDR_A_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_MAC_ADDR_B                 0xf430b218
#define NI_HV_XGE_MAC_MAC_ADDR_B_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 addr                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_MAC_ADDR_B_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_MAC_ADDR_C                 0xf430b21c
#define NI_HV_XGE_MAC_MAC_ADDR_C_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 addr                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_MAC_ADDR_C_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_VLAN_TAG1                  0xf430b220
#define NI_HV_XGE_MAC_VLAN_TAG1_dft              0x00008100

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tag                  : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_VLAN_TAG1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_VLAN_TAG2                  0xf430b224
#define NI_HV_XGE_MAC_VLAN_TAG2_dft              0x00008100

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tag                  : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_VLAN_TAG2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_VLAN_TAG3                  0xf430b228
#define NI_HV_XGE_MAC_VLAN_TAG3_dft              0x00008100

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tag                  : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_VLAN_TAG3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_MINLEN                     0xf430b22c
#define NI_HV_XGE_MAC_MINLEN_dft                 0x00000040

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 minlen               :  7 ; /* bits 6:0 */
    u32 rsrvd1               : 25 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_MINLEN_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_MAXLEN                     0xf430b230
#define NI_HV_XGE_MAC_MAXLEN_dft                 0x000023f1

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 maxlen               : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_MAXLEN_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_PAUSE_ADDR_A               0xf430b234
#define NI_HV_XGE_MAC_PAUSE_ADDR_A_dft           0x00000180

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 addr                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_PAUSE_ADDR_A_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_PAUSE_ADDR_B               0xf430b238
#define NI_HV_XGE_MAC_PAUSE_ADDR_B_dft           0x0000c200

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 addr                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_PAUSE_ADDR_B_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_PAUSE_ADDR_C               0xf430b23c
#define NI_HV_XGE_MAC_PAUSE_ADDR_C_dft           0x00000001

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 addr                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_PAUSE_ADDR_C_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_PQUANTA                    0xf430b240
#define NI_HV_XGE_MAC_PQUANTA_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pq                   : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_PQUANTA_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_PAUSE_TX_CMD               0xf430b244
#define NI_HV_XGE_MAC_PAUSE_TX_CMD_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 X_GEN                :  1 ; /* bits 0:0 */
    u32 XON_XOFF             :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_PAUSE_TX_CMD_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_INTERRUPT                  0xf430b248
#define NI_HV_XGE_MAC_INTERRUPT_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 miscI                :  1 ; /* bits 0:0 */
    u32 stats1I              :  1 ; /* bits 1:1 */
    u32 stats2I              :  1 ; /* bits 2:2 */
    u32 stats3I              :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_INTENABLE                  0xf430b24c
#define NI_HV_XGE_MAC_INTENABLE_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 miscE                :  1 ; /* bits 0:0 */
    u32 stats1E              :  1 ; /* bits 1:1 */
    u32 stats2E              :  1 ; /* bits 2:2 */
    u32 stats3E              :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_MISC_INTERRUPT             0xf430b250
#define NI_HV_XGE_MAC_MISC_INTERRUPT_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo1_uflwI       :  1 ; /* bits 0:0 */
    u32 tx_fifo1_oflwI       :  1 ; /* bits 1:1 */
    u32 tx_pause_doneI       :  1 ; /* bits 2:2 */
    u32 rsrvd1               :  5 ;
    u32 rx_no_sfdI           :  1 ; /* bits 8:8 */
    u32 rsrvd2               : 23 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_MISC_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_MISC_INTENABLE             0xf430b254
#define NI_HV_XGE_MAC_MISC_INTENABLE_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo1_uflwE       :  1 ; /* bits 0:0 */
    u32 tx_fifo1_oflwE       :  1 ; /* bits 1:1 */
    u32 tx_pause_doneE       :  1 ; /* bits 2:2 */
    u32 rsrvd1               :  5 ;
    u32 rx_no_sfdE           :  1 ; /* bits 8:8 */
    u32 rsrvd2               : 23 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_MISC_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_STATS_INTERRUPT1           0xf430b258
#define NI_HV_XGE_MAC_STATS_INTERRUPT1_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_good_framesI      :  1 ; /* bits 0:0 */
    u32 tx_good_octetsI      :  1 ; /* bits 1:1 */
    u32 tx_pause_framesI     :  1 ; /* bits 2:2 */
    u32 rx_good_framesI      :  1 ; /* bits 3:3 */
    u32 rx_good_octetsI      :  1 ; /* bits 4:4 */
    u32 rx_pause_framesI     :  1 ; /* bits 5:5 */
    u32 rx_crcerr_framesI    :  1 ; /* bits 6:6 */
    u32 rx_alignerr_framesI  :  1 ; /* bits 7:7 */
    u32 tx_ucast_framesI     :  1 ; /* bits 8:8 */
    u32 tx_mcast_framesI     :  1 ; /* bits 9:9 */
    u32 tx_bcast_framesI     :  1 ; /* bits 10:10 */
    u32 tx_err_framesI       :  1 ; /* bits 11:11 */
    u32 rx_ucast_framesI     :  1 ; /* bits 12:12 */
    u32 rx_mcast_framesI     :  1 ; /* bits 13:13 */
    u32 rx_bcast_framesI     :  1 ; /* bits 14:14 */
    u32 rx_err_framesI       :  1 ; /* bits 15:15 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_STATS_INTERRUPT1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_STATS_INTENABLE1           0xf430b25c
#define NI_HV_XGE_MAC_STATS_INTENABLE1_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_good_framesE      :  1 ; /* bits 0:0 */
    u32 tx_good_octetsE      :  1 ; /* bits 1:1 */
    u32 tx_pause_framesE     :  1 ; /* bits 2:2 */
    u32 rx_good_framesE      :  1 ; /* bits 3:3 */
    u32 rx_good_octetsE      :  1 ; /* bits 4:4 */
    u32 rx_pause_framesE     :  1 ; /* bits 5:5 */
    u32 rx_crcerr_framesE    :  1 ; /* bits 6:6 */
    u32 rx_alignerr_framesE  :  1 ; /* bits 7:7 */
    u32 tx_ucast_framesE     :  1 ; /* bits 8:8 */
    u32 tx_mcast_framesE     :  1 ; /* bits 9:9 */
    u32 tx_bcast_framesE     :  1 ; /* bits 10:10 */
    u32 tx_err_framesE       :  1 ; /* bits 11:11 */
    u32 rx_ucast_framesE     :  1 ; /* bits 12:12 */
    u32 rx_mcast_framesE     :  1 ; /* bits 13:13 */
    u32 rx_bcast_framesE     :  1 ; /* bits 14:14 */
    u32 rx_err_framesE       :  1 ; /* bits 15:15 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_STATS_INTENABLE1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_STATS_INTERRUPT2           0xf430b260
#define NI_HV_XGE_MAC_STATS_INTERRUPT2_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_octetsI           :  1 ; /* bits 0:0 */
    u32 rx_framesI           :  1 ; /* bits 1:1 */
    u32 rx_runt_framesI      :  1 ; /* bits 2:2 */
    u32 rx_short_framesI     :  1 ; /* bits 3:3 */
    u32 rx_undersize_framesI :  1 ; /* bits 4:4 */
    u32 rx_giant_framesI     :  1 ; /* bits 5:5 */
    u32 rx_jabber_framesI    :  1 ; /* bits 6:6 */
    u32 rx_64b_framesI       :  1 ; /* bits 7:7 */
    u32 rx_65b_to_127b_framesI :  1 ; /* bits 8:8 */
    u32 rx_128b_to_255b_framesI :  1 ; /* bits 9:9 */
    u32 rx_256b_to_511b_framesI :  1 ; /* bits 10:10 */
    u32 rx_512b_to_1023b_framesI :  1 ; /* bits 11:11 */
    u32 rx_1024b_to_1518b_framesI :  1 ; /* bits 12:12 */
    u32 rx_1519b_to_maxb_framesI :  1 ; /* bits 13:13 */
    u32 tx_octetsI           :  1 ; /* bits 14:14 */
    u32 tx_framesI           :  1 ; /* bits 15:15 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_STATS_INTERRUPT2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_STATS_INTENABLE2           0xf430b264
#define NI_HV_XGE_MAC_STATS_INTENABLE2_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_octetsE           :  1 ; /* bits 0:0 */
    u32 rx_framesE           :  1 ; /* bits 1:1 */
    u32 rx_runt_framesE      :  1 ; /* bits 2:2 */
    u32 rx_short_framesE     :  1 ; /* bits 3:3 */
    u32 rx_undersize_framesE :  1 ; /* bits 4:4 */
    u32 rx_giant_framesE     :  1 ; /* bits 5:5 */
    u32 rx_jabber_framesE    :  1 ; /* bits 6:6 */
    u32 rx_64b_framesE       :  1 ; /* bits 7:7 */
    u32 rx_65b_to_127b_framesE :  1 ; /* bits 8:8 */
    u32 rx_128b_to_255b_framesE :  1 ; /* bits 9:9 */
    u32 rx_256b_to_511b_framesE :  1 ; /* bits 10:10 */
    u32 rx_512b_to_1023b_framesE :  1 ; /* bits 11:11 */
    u32 rx_1024b_to_1518b_framesE :  1 ; /* bits 12:12 */
    u32 rx_1519b_to_maxb_framesE :  1 ; /* bits 13:13 */
    u32 tx_octetsE           :  1 ; /* bits 14:14 */
    u32 tx_framesE           :  1 ; /* bits 15:15 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_STATS_INTENABLE2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_STATS_INTERRUPT3           0xf430b268
#define NI_HV_XGE_MAC_STATS_INTERRUPT3_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_64b_framesI       :  1 ; /* bits 0:0 */
    u32 tx_65b_to_127b_framesI :  1 ; /* bits 1:1 */
    u32 tx_128b_to_255b_framesI :  1 ; /* bits 2:2 */
    u32 tx_256b_to_511b_framesI :  1 ; /* bits 3:3 */
    u32 tx_512b_to_1023b_framesI :  1 ; /* bits 4:4 */
    u32 tx_1024b_to_1518b_framesI :  1 ; /* bits 5:5 */
    u32 tx_1519b_framesI     :  1 ; /* bits 6:6 */
    u32 drop_rx_crcerr_framesI :  1 ; /* bits 7:7 */
    u32 drop_rx_alignerr_framesI :  1 ; /* bits 8:8 */
    u32 rx_pfc_framesI       :  1 ; /* bits 9:9 */
    u32 tx_pfc_framesI       :  1 ; /* bits 10:10 */
    u32 rsrvd1               : 21 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_STATS_INTERRUPT3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_STATS_INTENABLE3           0xf430b26c
#define NI_HV_XGE_MAC_STATS_INTENABLE3_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_64b_framesE       :  1 ; /* bits 0:0 */
    u32 tx_65b_to_127b_framesE :  1 ; /* bits 1:1 */
    u32 tx_128b_to_255b_framesE :  1 ; /* bits 2:2 */
    u32 tx_256b_to_511b_framesE :  1 ; /* bits 3:3 */
    u32 tx_512b_to_1023b_framesE :  1 ; /* bits 4:4 */
    u32 tx_1024b_to_1518b_framesE :  1 ; /* bits 5:5 */
    u32 tx_1519b_framesE     :  1 ; /* bits 6:6 */
    u32 drop_rx_crcerr_framesE :  1 ; /* bits 7:7 */
    u32 drop_rx_alignerr_framesE :  1 ; /* bits 8:8 */
    u32 rx_pfc_framesE       :  1 ; /* bits 9:9 */
    u32 tx_pfc_framesE       :  1 ; /* bits 10:10 */
    u32 rsrvd1               : 21 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_STATS_INTENABLE3_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_STATS_ACCESS               0xf430b270
#define NI_HV_XGE_MAC_STATS_ACCESS_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt_id               :  6 ; /* bits 5:0 */
    u32 rsrvd1               : 24 ;
    u32 dbg_write            :  1 ; /* bits 30:30 */
    u32 access               :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_STATS_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_STATS_DATA1                0xf430b274
#define NI_HV_XGE_MAC_STATS_DATA1_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_STATS_DATA1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_STATS_DATA0                0xf430b278
#define NI_HV_XGE_MAC_STATS_DATA0_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_STATS_DATA0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_MAC_ADDR_RDONLY2           0xf430b27c
#define NI_HV_XGE_MAC_MAC_ADDR_RDONLY2_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 addr                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_MAC_ADDR_RDONLY2_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_MAC_ADDR_RDONLY1           0xf430b280
#define NI_HV_XGE_MAC_MAC_ADDR_RDONLY1_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 addr                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_MAC_ADDR_RDONLY1_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_MAC_ADDR_RDONLY0           0xf430b284
#define NI_HV_XGE_MAC_MAC_ADDR_RDONLY0_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 addr                 : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_MAC_ADDR_RDONLY0_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_TL_BOUNDARY                0xf430b288
#define NI_HV_XGE_MAC_TL_BOUNDARY_dft            0x00000600

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 boundary             : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_TL_BOUNDARY_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MAC_FMRO                       0xf430b28c
#define NI_HV_XGE_MAC_FMRO_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data_sel             :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 clk_sel              :  2 ; /* bits 9:8 */
    u32 rsrvd2               : 22 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MAC_FMRO_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MISC_INTERRUPT                 0xf430b2a0
#define NI_HV_XGE_MISC_INTERRUPT_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 macI                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MISC_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MISC_INTENABLE                 0xf430b2a4
#define NI_HV_XGE_MISC_INTENABLE_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 macE                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MISC_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MISC_CONFIG                    0xf430b2a8
#define NI_HV_XGE_MISC_CONFIG_dft                0x300000ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 spare                : 14 ; /* bits 13:0 */
    u32 rsrvd1               : 14 ;
    u32 inf_sel              :  2 ; /* bits 29:28 */
    u32 mode322              :  1 ; /* bits 30:30 */
    u32 gige_mode            :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MISC_CONFIG_t;
#endif /* !__ASSEMBLER__ */
#define NI_HV_XGE_MISC_FMRO                      0xf430b2ac
#define NI_HV_XGE_MISC_FMRO_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sel                  :  3 ; /* bits 2:0 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} NI_HV_XGE_MISC_FMRO_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_RD_ORIG_ID            0xf432d000
#define QM_AXI_REO_AXI_REO_RD_ORIG_ID_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 axi_id               :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_RD_ORIG_ID_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_RD_NEW_ID             0xf432d004
#define QM_AXI_REO_AXI_REO_RD_NEW_ID_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 axi_id               :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 27 ;
    u32 axi_id_valid         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_RD_NEW_ID_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_RD_TOP_ADDR0          0xf432d008
#define QM_AXI_REO_AXI_REO_RD_TOP_ADDR0_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 id_addr              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_RD_TOP_ADDR0_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_RD_TOP_ADDR_MASK0     0xf432d00c
#define QM_AXI_REO_AXI_REO_RD_TOP_ADDR_MASK0_dft 0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 id_mask              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_RD_TOP_ADDR_MASK0_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_RD_NEW_ID0            0xf432d010
#define QM_AXI_REO_AXI_REO_RD_NEW_ID0_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 axi_id               :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 27 ;
    u32 axi_id_valid         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_RD_NEW_ID0_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_RD_TOP_ADDR1          0xf432d014
#define QM_AXI_REO_AXI_REO_RD_TOP_ADDR1_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 id_addr              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_RD_TOP_ADDR1_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_RD_TOP_ADDR_MASK1     0xf432d018
#define QM_AXI_REO_AXI_REO_RD_TOP_ADDR_MASK1_dft 0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 id_mask              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_RD_TOP_ADDR_MASK1_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_RD_NEW_ID1            0xf432d01c
#define QM_AXI_REO_AXI_REO_RD_NEW_ID1_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 axi_id               :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 27 ;
    u32 axi_id_valid         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_RD_NEW_ID1_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_RD_TOP_ADDR2          0xf432d020
#define QM_AXI_REO_AXI_REO_RD_TOP_ADDR2_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 id_addr              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_RD_TOP_ADDR2_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_RD_TOP_ADDR_MASK2     0xf432d024
#define QM_AXI_REO_AXI_REO_RD_TOP_ADDR_MASK2_dft 0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 id_mask              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_RD_TOP_ADDR_MASK2_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_RD_NEW_ID2            0xf432d028
#define QM_AXI_REO_AXI_REO_RD_NEW_ID2_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 axi_id               :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 27 ;
    u32 axi_id_valid         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_RD_NEW_ID2_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_RD_STATUS             0xf432d02c
#define QM_AXI_REO_AXI_REO_RD_STATUS_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 return_full          :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 12 ;
    u32 return_status        :  4 ; /* bits 19:16 */
    u32 rsrvd2               : 12 ;
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_RD_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_RD_SRAM_TEST_CONTROL  0xf432d030
#define QM_AXI_REO_AXI_REO_RD_SRAM_TEST_CONTROL_dft 0x00000022

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rm0                  :  2 ; /* bits 1:0 */
    u32 rme0                 :  1 ; /* bits 2:2 */
    u32 test0                :  1 ; /* bits 3:3 */
    u32 rm1                  :  2 ; /* bits 5:4 */
    u32 rme1                 :  1 ; /* bits 6:6 */
    u32 test1                :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_RD_SRAM_TEST_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_RD_SRAM_LS_CONTROL    0xf432d034
#define QM_AXI_REO_AXI_REO_RD_SRAM_LS_CONTROL_dft 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sramls               :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_RD_SRAM_LS_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_WR_ORIG_ID            0xf432d400
#define QM_AXI_REO_AXI_REO_WR_ORIG_ID_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 axi_id               :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_WR_ORIG_ID_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_WR_NEW_ID             0xf432d404
#define QM_AXI_REO_AXI_REO_WR_NEW_ID_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 axi_id               :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 27 ;
    u32 axi_id_valid         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_WR_NEW_ID_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_WR_TOP_ADDR0          0xf432d408
#define QM_AXI_REO_AXI_REO_WR_TOP_ADDR0_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 id_addr              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_WR_TOP_ADDR0_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_WR_TOP_ADDR_MASK0     0xf432d40c
#define QM_AXI_REO_AXI_REO_WR_TOP_ADDR_MASK0_dft 0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 id_mask              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_WR_TOP_ADDR_MASK0_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_WR_NEW_ID0            0xf432d410
#define QM_AXI_REO_AXI_REO_WR_NEW_ID0_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 axi_id               :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 27 ;
    u32 axi_id_valid         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_WR_NEW_ID0_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_WR_TOP_ADDR1          0xf432d414
#define QM_AXI_REO_AXI_REO_WR_TOP_ADDR1_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 id_addr              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_WR_TOP_ADDR1_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_WR_TOP_ADDR_MASK1     0xf432d418
#define QM_AXI_REO_AXI_REO_WR_TOP_ADDR_MASK1_dft 0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 id_mask              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_WR_TOP_ADDR_MASK1_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_WR_NEW_ID1            0xf432d41c
#define QM_AXI_REO_AXI_REO_WR_NEW_ID1_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 axi_id               :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 27 ;
    u32 axi_id_valid         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_WR_NEW_ID1_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_WR_TOP_ADDR2          0xf432d420
#define QM_AXI_REO_AXI_REO_WR_TOP_ADDR2_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 id_addr              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_WR_TOP_ADDR2_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_WR_TOP_ADDR_MASK2     0xf432d424
#define QM_AXI_REO_AXI_REO_WR_TOP_ADDR_MASK2_dft 0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 id_mask              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_WR_TOP_ADDR_MASK2_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_WR_NEW_ID2            0xf432d428
#define QM_AXI_REO_AXI_REO_WR_NEW_ID2_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 axi_id               :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 27 ;
    u32 axi_id_valid         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_WR_NEW_ID2_t;
#endif /* !__ASSEMBLER__ */
#define QM_AXI_REO_AXI_REO_WR_STATUS             0xf432d42c
#define QM_AXI_REO_AXI_REO_WR_STATUS_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 return_full          :  4 ; /* bits 3:0 */
    u32 rsrvd1               : 12 ;
    u32 return_status        :  4 ; /* bits 19:16 */
    u32 rsrvd2               : 12 ;
  } bf ;
  u32     wrd ;
} QM_AXI_REO_AXI_REO_WR_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_CTRL0                          0xf4700000
#define WRAP_GPHY_CTRL0_dft                      0x00003110

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_peri_cmds_wr     :  4 ; /* bits 3:0 */
    u32 cfg_peri_cmds_rd     :  4 ; /* bits 7:4 */
    u32 cfg_peri_wrmsk_en    :  4 ; /* bits 11:8 */
    u32 cfg_hotcmd_en        :  3 ; /* bits 14:12 */
    u32 cfg_phy_sdet         :  2 ; /* bits 16:15 */
    u32 cfg_byps_chk_ini     :  1 ; /* bits 17:17 */
    u32 cfg_hotcmd_prd_en    :  1 ; /* bits 18:18 */
    u32 rsrvd1               : 13 ;
  } bf ;
  u32     wrd ;
} WRAP_GPHY_CTRL0_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_CTRL1                          0xf4700004
#define WRAP_GPHY_CTRL1_dft                      0x00010ff0

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_iniphy_disgiga   :  4 ; /* bits 3:0 */
    u32 cfg_iniphy_pwrup     :  4 ; /* bits 7:4 */
    u32 cfg_iniphy_eee       :  4 ; /* bits 11:8 */
    u32 rsrvd1               :  4 ;
    u32 cfg_poll_period      :  5 ; /* bits 20:16 */
    u32 rsrvd2               : 11 ;
  } bf ;
  u32     wrd ;
} WRAP_GPHY_CTRL1_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_CTRL2                          0xf4700008
#define WRAP_GPHY_CTRL2_dft                      0x0010bc06

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_getpowctrl_adr   : 16 ; /* bits 15:0 */
    u32 cfg_getpowctrl_bit   : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_CTRL2_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_CTRL3                          0xf470000c
#define WRAP_GPHY_CTRL3_dft                      0x0800a400

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_hotcmd1_adr      : 16 ; /* bits 15:0 */
    u32 cfg_hotcmd1_dat      : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_CTRL3_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_CTRL4                          0xf4700010
#define WRAP_GPHY_CTRL4_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_hotcmd2_adr      : 16 ; /* bits 15:0 */
    u32 cfg_hotcmd2_wrbus    : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_CTRL4_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_CTRL5                          0xf4700014
#define WRAP_GPHY_CTRL5_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_hotcmd2_inv      : 16 ; /* bits 15:0 */
    u32 cfg_hotcmd2_rd       :  1 ; /* bits 16:16 */
    u32 cfg_hotcmd2_wrmsk    :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} WRAP_GPHY_CTRL5_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_CTRL6                          0xf4700018
#define WRAP_GPHY_CTRL6_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_peri_inv_en0     : 16 ; /* bits 15:0 */
    u32 cfg_peri_inv_en1     : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_CTRL6_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_CTRL7                          0xf470001c
#define WRAP_GPHY_CTRL7_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_peri_inv_en2     : 16 ; /* bits 15:0 */
    u32 cfg_peri_inv_en3     : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_CTRL7_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_CTRL8                          0xf4700020
#define WRAP_GPHY_CTRL8_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_peri_wrbus0      : 16 ; /* bits 15:0 */
    u32 cfg_peri_wrbus1      : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_CTRL8_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_CTRL9                          0xf4700024
#define WRAP_GPHY_CTRL9_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_peri_wrbus2      : 16 ; /* bits 15:0 */
    u32 cfg_peri_wrbus3      : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_CTRL9_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_CTRL10                         0xf4700028
#define WRAP_GPHY_CTRL10_dft                     0xa47aa434

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_peri_adr0        : 16 ; /* bits 15:0 */
    u32 cfg_peri_adr1        : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_CTRL10_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_CTRL11                         0xf470002c
#define WRAP_GPHY_CTRL11_dft                     0x0000a730

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_peri_adr2        : 16 ; /* bits 15:0 */
    u32 cfg_peri_adr3        : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_CTRL11_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_CTRL12                         0xf4700030
#define WRAP_GPHY_CTRL12_dft                     0x1f000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_base_phyad       :  5 ; /* bits 4:0 */
    u32 cfg_brd_phyad        :  5 ; /* bits 9:5 */
    u32 rsrvd1               :  6 ;
    u32 cfg_phy_brd_mode     :  4 ; /* bits 19:16 */
    u32 cfg_msk_mdi          :  4 ; /* bits 23:20 */
    u32 cfg_ocp_timeout      :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_CTRL12_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_CTRL13                         0xf4700034
#define WRAP_GPHY_CTRL13_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mdio_ocp_sel         :  1 ; /* bits 0:0 */
    u32 sel_ext_mdio         :  1 ; /* bits 1:1 */
    u32 rsrvd1               :  6 ;
    u32 pll_ate_clk_sel      :  1 ; /* bits 8:8 */
    u32 dbgo_gphy_loc_sel    :  3 ; /* bits 11:9 */
    u32 patch_phy_done       :  1 ; /* bits 12:12 */
    u32 rsrvd2               : 19 ;
  } bf ;
  u32     wrd ;
} WRAP_GPHY_CTRL13_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_STS0                           0xf4700038
#define WRAP_GPHY_STS0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p0_pericmd0_rddata   : 16 ; /* bits 15:0 */
    u32 p0_pericmd1_rddata   : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_STS0_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_STS1                           0xf470003c
#define WRAP_GPHY_STS1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p0_pericmd2_rddata   : 16 ; /* bits 15:0 */
    u32 p0_pericmd3_rddata   : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_STS1_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_STS2                           0xf4700040
#define WRAP_GPHY_STS2_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p1_pericmd0_rddata   : 16 ; /* bits 15:0 */
    u32 p1_pericmd1_rddata   : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_STS2_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_STS3                           0xf4700044
#define WRAP_GPHY_STS3_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p1_pericmd2_rddata   : 16 ; /* bits 15:0 */
    u32 p1_pericmd3_rddata   : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_STS3_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_STS4                           0xf4700048
#define WRAP_GPHY_STS4_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p2_pericmd0_rddata   : 16 ; /* bits 15:0 */
    u32 p2_pericmd1_rddata   : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_STS4_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_STS5                           0xf470004c
#define WRAP_GPHY_STS5_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p2_pericmd2_rddata   : 16 ; /* bits 15:0 */
    u32 p2_pericmd3_rddata   : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_STS5_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_STS6                           0xf4700050
#define WRAP_GPHY_STS6_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p3_pericmd0_rddata   : 16 ; /* bits 15:0 */
    u32 p3_pericmd1_rddata   : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_STS6_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_STS7                           0xf4700054
#define WRAP_GPHY_STS7_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p3_pericmd2_rddata   : 16 ; /* bits 15:0 */
    u32 p3_pericmd3_rddata   : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_STS7_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_STS8                           0xf4700058
#define WRAP_GPHY_STS8_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 p0_phy_in_extini     :  1 ; /* bits 0:0 */
    u32 p1_phy_in_extini     :  1 ; /* bits 1:1 */
    u32 p2_phy_in_extini     :  1 ; /* bits 2:2 */
    u32 p3_phy_in_extini     :  1 ; /* bits 3:3 */
    u32 p0_phy_in_lan_on     :  1 ; /* bits 4:4 */
    u32 p1_phy_in_lan_on     :  1 ; /* bits 5:5 */
    u32 p2_phy_in_lan_on     :  1 ; /* bits 6:6 */
    u32 p3_phy_in_lan_on     :  1 ; /* bits 7:7 */
    u32 phy_ocp_timeout      :  4 ; /* bits 11:8 */
    u32 p0_phy_fatal_err     :  1 ; /* bits 12:12 */
    u32 p1_phy_fatal_err     :  1 ; /* bits 13:13 */
    u32 p2_phy_fatal_err     :  1 ; /* bits 14:14 */
    u32 p3_phy_fatal_err     :  1 ; /* bits 15:15 */
    u32 rdy4patch            :  1 ; /* bits 16:16 */
    u32 rsrvd1               : 15 ;
  } bf ;
  u32     wrd ;
} WRAP_GPHY_STS8_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_GPHY_ANA_CENREG0               0xf470005c
#define WRAP_GPHY_GPHY_ANA_CENREG0_dft           0x00010094

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_gphy_ana_cen0    : 16 ; /* bits 15:0 */
    u32 cfg_gphy_ana_cen1    : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_GPHY_ANA_CENREG0_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_GPHY_ANA_CENREG1               0xf4700060
#define WRAP_GPHY_GPHY_ANA_CENREG1_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_gphy_ana_cen2    : 16 ; /* bits 15:0 */
    u32 cfg_gphy_ana_cen3    : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_GPHY_ANA_CENREG1_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_GPHY_ANA_CENREG2               0xf4700064
#define WRAP_GPHY_GPHY_ANA_CENREG2_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_gphy_ana_cen4    : 16 ; /* bits 15:0 */
    u32 cfg_gphy_ana_cen5    : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_GPHY_ANA_CENREG2_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_GPHY_ANA_CENREG3               0xf4700068
#define WRAP_GPHY_GPHY_ANA_CENREG3_dft           0x0f0f0000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_gphy_ana_cen6    : 16 ; /* bits 15:0 */
    u32 cfg_gphy_ana_cen7    : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_GPHY_ANA_CENREG3_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_GPHY_ANA_CENREG4               0xf470006c
#define WRAP_GPHY_GPHY_ANA_CENREG4_dft           0x0f0f0f0f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_gphy_ana_cen8    : 16 ; /* bits 15:0 */
    u32 cfg_gphy_ana_cen9    : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_GPHY_ANA_CENREG4_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_GPHY_ANA_CENREG5               0xf4700070
#define WRAP_GPHY_GPHY_ANA_CENREG5_dft           0x0f0f0f0f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_gphy_ana_cen10   : 16 ; /* bits 15:0 */
    u32 cfg_gphy_ana_cen11   : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_GPHY_ANA_CENREG5_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_GPHY_ANA_PLLREG0               0xf4700074
#define WRAP_GPHY_GPHY_ANA_PLLREG0_dft           0xeb650063

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_gphy_ana_pll0    : 16 ; /* bits 15:0 */
    u32 cfg_gphy_ana_pll1    : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_GPHY_ANA_PLLREG0_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_GPHY_ANA_PLLREG1               0xf4700078
#define WRAP_GPHY_GPHY_ANA_PLLREG1_dft           0x00014003

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_gphy_ana_pll2    : 16 ; /* bits 15:0 */
    u32 cfg_gphy_ana_pll3    : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_GPHY_ANA_PLLREG1_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_GPHY_ANA_PLLREG2               0xf470007c
#define WRAP_GPHY_GPHY_ANA_PLLREG2_dft           0x20008003

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_gphy_ana_pll4    : 16 ; /* bits 15:0 */
    u32 cfg_gphy_ana_pll5    : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_GPHY_ANA_PLLREG2_t;
#endif /* !__ASSEMBLER__ */
#define WRAP_GPHY_GPHY_ANA_PLLREG3               0xf4700080
#define WRAP_GPHY_GPHY_ANA_PLLREG3_dft           0x0f007e01

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_gphy_ana_pll6    : 16 ; /* bits 15:0 */
    u32 cfg_gphy_ana_pll7    : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} WRAP_GPHY_GPHY_ANA_PLLREG3_t;
#endif /* !__ASSEMBLER__ */
#define QX_RESET                                 0xf550d000
#define QX_RESET_dft                             0x00000001

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dp_reset             :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} QX_RESET_t;
#endif /* !__ASSEMBLER__ */
#define QX_MODE                                  0xf550d004
#define QX_MODE_dft                              0x0000105f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sds_mode_s0          :  5 ; /* bits 4:0 */
    u32 usx_sub_mx_s0        :  5 ; /* bits 9:5 */
    u32 use_wtg              :  1 ; /* bits 10:10 */
    u32 use_wtg_dp           :  1 ; /* bits 11:11 */
    u32 sd_s0                :  1 ; /* bits 12:12 */
    u32 rsrvd1               : 19 ;
  } bf ;
  u32     wrd ;
} QX_MODE_t;
#endif /* !__ASSEMBLER__ */
#define QX_CH0_ABILITY                           0xf550d008
#define QX_CH0_ABILITY_dft                       0x00005cf5

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sds01_sds0_ablty     : 17 ; /* bits 16:0 */
    u32 rsrvd1               : 15 ;
  } bf ;
  u32     wrd ;
} QX_CH0_ABILITY_t;
#endif /* !__ASSEMBLER__ */
#define QX_CH1_ABILITY                           0xf550d00c
#define QX_CH1_ABILITY_dft                       0x00005cf5

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sds01_sds1_ablty     : 17 ; /* bits 16:0 */
    u32 rsrvd1               : 15 ;
  } bf ;
  u32     wrd ;
} QX_CH1_ABILITY_t;
#endif /* !__ASSEMBLER__ */
#define QX_CH2_ABILITY                           0xf550d010
#define QX_CH2_ABILITY_dft                       0x00005cf5

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sds01_sds2_ablty     : 17 ; /* bits 16:0 */
    u32 rsrvd1               : 15 ;
  } bf ;
  u32     wrd ;
} QX_CH2_ABILITY_t;
#endif /* !__ASSEMBLER__ */
#define QX_CH3_ABILITY                           0xf550d014
#define QX_CH3_ABILITY_dft                       0x00005cf5

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sds01_sds3_ablty     : 17 ; /* bits 16:0 */
    u32 rsrvd1               : 15 ;
  } bf ;
  u32     wrd ;
} QX_CH3_ABILITY_t;
#endif /* !__ASSEMBLER__ */
#define QX_MISC_CNTL_1                           0xf550d018
#define QX_MISC_CNTL_1_dft                       0x00002000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 auto_det_sg0_upd_en  :  1 ; /* bits 0:0 */
    u32 cfg_fb_on            :  1 ; /* bits 1:1 */
    u32 cfg_unidir_en_tgxr0  :  1 ; /* bits 2:2 */
    u32 eee_lpi_tx_tgxr0     :  1 ; /* bits 3:3 */
    u32 load_sys_par_s0      :  1 ; /* bits 4:4 */
    u32 load_sys_par_s1      :  1 ; /* bits 5:5 */
    u32 load_sys_par_s2      :  1 ; /* bits 6:6 */
    u32 load_sys_par_s3      :  1 ; /* bits 7:7 */
    u32 pdown_en_ini_tgr_s0  :  1 ; /* bits 8:8 */
    u32 sds01_autoneg_en_ini_s0 :  1 ; /* bits 9:9 */
    u32 sds01_autoneg_en_ini_s1 :  1 ; /* bits 10:10 */
    u32 sds01_iso_on_s0      :  1 ; /* bits 11:11 */
    u32 sds01_iso_on_s1      :  1 ; /* bits 12:12 */
    u32 sds01_lpi_gmii_sel   :  1 ; /* bits 13:13 */
    u32 sds01_pdown_en_ini_s0 :  1 ; /* bits 14:14 */
    u32 sds01_pdown_en_ini_s1 :  1 ; /* bits 15:15 */
    u32 sds01_sds_frc_ld_s0  :  1 ; /* bits 16:16 */
    u32 sds01_sds_phy_mode   :  1 ; /* bits 17:17 */
    u32 sds01_sds_rx_disable_s0 :  1 ; /* bits 18:18 */
    u32 sds01_sds_rx_disable_s1 :  1 ; /* bits 19:19 */
    u32 sds01_sds_tx_disable_s0 :  1 ; /* bits 20:20 */
    u32 sds01_sds_tx_disable_s1 :  1 ; /* bits 21:21 */
    u32 sds01_silent_en_ini_s0 :  1 ; /* bits 22:22 */
    u32 sds01_silent_en_ini_s1 :  1 ; /* bits 23:23 */
    u32 sds01_spdup_ini      :  1 ; /* bits 24:24 */
    u32 sds01_unidir_tx_able_s0 :  1 ; /* bits 25:25 */
    u32 sds23_iso_on_s0      :  1 ; /* bits 26:26 */
    u32 sds23_iso_on_s1      :  1 ; /* bits 27:27 */
    u32 sel_ori_312p5_tgr0   :  1 ; /* bits 28:28 */
    u32 tgr_ecc_en           :  1 ; /* bits 29:29 */
    u32 sds01_frc_reg4_en_s0 :  1 ; /* bits 30:30 */
    u32 sds01_frc_reg4_fib100_s0 :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QX_MISC_CNTL_1_t;
#endif /* !__ASSEMBLER__ */
#define QX_MISC_CNTL_2                           0xf550d01c
#define QX_MISC_CNTL_2_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sds01_pause_ini_s0   :  2 ; /* bits 1:0 */
    u32 sds01_pause_ini_s1   :  2 ; /* bits 3:2 */
    u32 sds01_revision_no    :  4 ; /* bits 7:4 */
    u32 sds01_mac_trx_idle   :  8 ; /* bits 15:8 */
    u32 sds01_cmd_stop_gli_clk :  8 ; /* bits 23:16 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} QX_MISC_CNTL_2_t;
#endif /* !__ASSEMBLER__ */
#define QX_MISC_CNTL_3                           0xf550d020
#define QX_MISC_CNTL_3_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sds01_phy_lpi_rx     :  8 ; /* bits 7:0 */
    u32 sds01_mac_lpi_tx     :  8 ; /* bits 15:8 */
    u32 sds01_model_no       :  6 ; /* bits 21:16 */
    u32 model_no_tgr_s0      :  6 ; /* bits 27:22 */
    u32 revision_no_tgr_s0   :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} QX_MISC_CNTL_3_t;
#endif /* !__ASSEMBLER__ */
#define QX_MISC_CNTL_4                           0xf550d024
#define QX_MISC_CNTL_4_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 realtek_oui_tgr_s0   : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} QX_MISC_CNTL_4_t;
#endif /* !__ASSEMBLER__ */
#define QX_MISC_CNTL_5                           0xf550d028
#define QX_MISC_CNTL_5_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sds01_realtek_oui    : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} QX_MISC_CNTL_5_t;
#endif /* !__ASSEMBLER__ */
#define QX_IF_INTERRUPT                          0xf550d02c
#define QX_IF_INTERRUPT_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_sym_err_tgxr0I    :  1 ; /* bits 0:0 */
    u32 sds01_sds_rx_sym_err_all_s0I :  1 ; /* bits 1:1 */
    u32 eee_lpi_rx_tgxr0I    :  1 ; /* bits 2:2 */
    u32 sds01_sds_link_ok_0I :  1 ; /* bits 3:3 */
    u32 sds01_sds_link_ok_1I :  1 ; /* bits 4:4 */
    u32 sds01_sds_link_ok_2I :  1 ; /* bits 5:5 */
    u32 sds01_sds_link_ok_3I :  1 ; /* bits 6:6 */
    u32 sds01_sds_sdet_out_s0I :  1 ; /* bits 7:7 */
    u32 rxidle_d_s0I         :  1 ; /* bits 8:8 */
    u32 link_ok_tgxr0I       :  1 ; /* bits 9:9 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} QX_IF_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define QX_IF_INTENABLE                          0xf550d030
#define QX_IF_INTENABLE_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_sym_err_tgxr0E    :  1 ; /* bits 0:0 */
    u32 sds01_sds_rx_sym_err_all_s0E :  1 ; /* bits 1:1 */
    u32 eee_lpi_rx_tgxr0E    :  1 ; /* bits 2:2 */
    u32 sds01_sds_link_ok_0E :  1 ; /* bits 3:3 */
    u32 sds01_sds_link_ok_1E :  1 ; /* bits 4:4 */
    u32 sds01_sds_link_ok_2E :  1 ; /* bits 5:5 */
    u32 sds01_sds_link_ok_3E :  1 ; /* bits 6:6 */
    u32 sds01_sds_sdet_out_s0E :  1 ; /* bits 7:7 */
    u32 rxidle_d_s0E         :  1 ; /* bits 8:8 */
    u32 link_ok_tgxr0E       :  1 ; /* bits 9:9 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} QX_IF_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define QX_IF_STATUS                             0xf550d034
#define QX_IF_STATUS_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_sym_err_tgxr0     :  1 ; /* bits 0:0 */
    u32 sds01_sds_rx_sym_err_all_s0 :  1 ; /* bits 1:1 */
    u32 eee_lpi_rx_tgxr0     :  1 ; /* bits 2:2 */
    u32 sds01_sds_link_ok_0  :  1 ; /* bits 3:3 */
    u32 sds01_sds_link_ok_1  :  1 ; /* bits 4:4 */
    u32 sds01_sds_link_ok_2  :  1 ; /* bits 5:5 */
    u32 sds01_sds_link_ok_3  :  1 ; /* bits 6:6 */
    u32 sds01_sds_sdet_out_s0 :  1 ; /* bits 7:7 */
    u32 rxidle_d_s0          :  1 ; /* bits 8:8 */
    u32 sds01_mac_lpi_rx     :  8 ; /* bits 16:9 */
    u32 sds01_phy_lpi_tx     :  8 ; /* bits 24:17 */
    u32 link_fault_tgxr0     :  3 ; /* bits 27:25 */
    u32 wtg_reg_rdy          :  1 ; /* bits 28:28 */
    u32 sds01_fib_iso_s0     :  1 ; /* bits 29:29 */
    u32 intp_tgr0            :  1 ; /* bits 30:30 */
    u32 link_ok_tgxr0        :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QX_IF_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define QX_IF_STATUS2                            0xf550d038
#define QX_IF_STATUS2_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sds01_fib100_det_s0  :  1 ; /* bits 0:0 */
    u32 sds01_fib100_sdet_s0 :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} QX_IF_STATUS2_t;
#endif /* !__ASSEMBLER__ */
#define QX_IF_ABILITY                            0xf550d03c
#define QX_IF_ABILITY_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wtg_sdsab_0_ablty    : 17 ; /* bits 16:0 */
    u32 rsrvd1               : 15 ;
  } bf ;
  u32     wrd ;
} QX_IF_ABILITY_t;
#endif /* !__ASSEMBLER__ */
#define QX_IF_ABILITY1                           0xf550d040
#define QX_IF_ABILITY1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wtg_sdsab_1_ablty    : 17 ; /* bits 16:0 */
    u32 rsrvd1               : 15 ;
  } bf ;
  u32     wrd ;
} QX_IF_ABILITY1_t;
#endif /* !__ASSEMBLER__ */
#define QX_IF_ABILITY2                           0xf550d044
#define QX_IF_ABILITY2_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wtg_sdsab_2_ablty    : 17 ; /* bits 16:0 */
    u32 rsrvd1               : 15 ;
  } bf ;
  u32     wrd ;
} QX_IF_ABILITY2_t;
#endif /* !__ASSEMBLER__ */
#define QX_IF_ABILITY3                           0xf550d048
#define QX_IF_ABILITY3_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wtg_sdsab_3_ablty    : 17 ; /* bits 16:0 */
    u32 rsrvd1               : 15 ;
  } bf ;
  u32     wrd ;
} QX_IF_ABILITY3_t;
#endif /* !__ASSEMBLER__ */
#define QX_REG_ACCESS                            0xf550d04c
#define QX_REG_ACCESS_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sds_a                : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 14 ;
    u32 sds_we               :  1 ; /* bits 30:30 */
    u32 sds_access           :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} QX_REG_ACCESS_t;
#endif /* !__ASSEMBLER__ */
#define QX_REG_DATAIN                            0xf550d050
#define QX_REG_DATAIN_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sds_d_in             : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QX_REG_DATAIN_t;
#endif /* !__ASSEMBLER__ */
#define QX_REG_DATAOUT                           0xf550d054
#define QX_REG_DATAOUT_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sds_d_out            : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} QX_REG_DATAOUT_t;
#endif /* !__ASSEMBLER__ */
#define QX_SDS_STATE                             0xf550d058
#define QX_SDS_STATE_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               : 13 ;
    u32 CKRDY                :  1 ; /* bits 13:13 */
    u32 RXIDLE               :  1 ; /* bits 14:14 */
    u32 BER_NOTIFY           :  1 ; /* bits 15:15 */
    u32 VTH_EN               :  1 ; /* bits 16:16 */
    u32 rsrvd2               : 15 ;
  } bf ;
  u32     wrd ;
} QX_SDS_STATE_t;
#endif /* !__ASSEMBLER__ */
#define QX_XG_PRMB_RCVY                          0xf550d05c
#define QX_XG_PRMB_RCVY_dft                      0x00000009

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_prmb_rcvy_en     :  1 ; /* bits 0:0 */
    u32 cfg_prmb_6byte_mode  :  1 ; /* bits 1:1 */
    u32 cfg_dbg_info_off     :  1 ; /* bits 2:2 */
    u32 cfg_burstact_6_det_en :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} QX_XG_PRMB_RCVY_t;
#endif /* !__ASSEMBLER__ */
#define QX_XG_PRMB_RCVY_DBG_0                    0xf550d060
#define QX_XG_PRMB_RCVY_DBG_0_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dbg_prmb_rcvy_0      : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QX_XG_PRMB_RCVY_DBG_0_t;
#endif /* !__ASSEMBLER__ */
#define QX_XG_PRMB_RCVY_DBG_1                    0xf550d064
#define QX_XG_PRMB_RCVY_DBG_1_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dbg_prmb_rcvy_1      : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} QX_XG_PRMB_RCVY_DBG_1_t;
#endif /* !__ASSEMBLER__ */

#endif /* __DRIVERS_NET_RTL9617C_NI_REGS_H__ */
