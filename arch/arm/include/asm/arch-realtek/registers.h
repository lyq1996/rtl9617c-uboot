/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __ARCH_ARM_INCLUDE_ASM_ARCH_RTL9617C_REGISTERS_H__
#define __ARCH_ARM_INCLUDE_ASM_ARCH_RTL9617C_REGISTERS_H__

#include <linux/types.h>

#define GLOBAL_JTAG_ID                           0xf4320000
#define GLOBAL_JTAG_ID_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 jtag_id              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_JTAG_ID_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_CONTROL13                    0xf4320004
#define GLOBAL_BIST_CONTROL13_dft                0x00040020

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_global13        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_CONTROL13_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_CONTROL12                    0xf4320008
#define GLOBAL_BIST_CONTROL12_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_global12        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_CONTROL12_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_CONTROL11                    0xf432000c
#define GLOBAL_BIST_CONTROL11_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_global11        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_CONTROL11_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_CONTROL10                    0xf4320010
#define GLOBAL_BIST_CONTROL10_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_global10        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_CONTROL10_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_CONTROL9                     0xf4320014
#define GLOBAL_BIST_CONTROL9_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_global9         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_CONTROL9_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_CONTROL8                     0xf4320018
#define GLOBAL_BIST_CONTROL8_dft                 0x000003ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_global8         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_CONTROL8_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_CONTROL7                     0xf432001c
#define GLOBAL_BIST_CONTROL7_dft                 0xc0000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_global7         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_CONTROL7_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_CONTROL6                     0xf4320020
#define GLOBAL_BIST_CONTROL6_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_global6         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_CONTROL6_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_CONTROL5                     0xf4320024
#define GLOBAL_BIST_CONTROL5_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_global5         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_CONTROL5_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_CONTROL4                     0xf4320028
#define GLOBAL_BIST_CONTROL4_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_global4         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_CONTROL4_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_CONTROL3                     0xf432002c
#define GLOBAL_BIST_CONTROL3_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_global3         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_CONTROL3_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_CONTROL2                     0xf4320030
#define GLOBAL_BIST_CONTROL2_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_global2         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_CONTROL2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_CONTROL1                     0xf4320034
#define GLOBAL_BIST_CONTROL1_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_global1         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_CONTROL1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_CONTROL0                     0xf4320038
#define GLOBAL_BIST_CONTROL0_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_global0         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_CONTROL0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_RESULTS13                    0xf432003c
#define GLOBAL_BIST_RESULTS13_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_results13       : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_RESULTS13_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_RESULTS12                    0xf4320040
#define GLOBAL_BIST_RESULTS12_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_results12       : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_RESULTS12_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_RESULTS11                    0xf4320044
#define GLOBAL_BIST_RESULTS11_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_results11       : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_RESULTS11_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_RESULTS10                    0xf4320048
#define GLOBAL_BIST_RESULTS10_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_results10       : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_RESULTS10_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_RESULTS9                     0xf432004c
#define GLOBAL_BIST_RESULTS9_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_results9        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_RESULTS9_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_RESULTS8                     0xf4320050
#define GLOBAL_BIST_RESULTS8_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_results8        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_RESULTS8_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_RESULTS7                     0xf4320054
#define GLOBAL_BIST_RESULTS7_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_results7        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_RESULTS7_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_RESULTS6                     0xf4320058
#define GLOBAL_BIST_RESULTS6_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_results6        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_RESULTS6_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_RESULTS5                     0xf432005c
#define GLOBAL_BIST_RESULTS5_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_results5        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_RESULTS5_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_RESULTS4                     0xf4320060
#define GLOBAL_BIST_RESULTS4_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_results4        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_RESULTS4_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_RESULTS3                     0xf4320064
#define GLOBAL_BIST_RESULTS3_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_results3        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_RESULTS3_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_RESULTS2                     0xf4320068
#define GLOBAL_BIST_RESULTS2_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_results2        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_RESULTS2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_RESULTS1                     0xf432006c
#define GLOBAL_BIST_RESULTS1_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_results1        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_RESULTS1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_RESULTS0                     0xf4320070
#define GLOBAL_BIST_RESULTS0_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_results0        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_RESULTS0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_EPON_CNTL                         0xf4320074
#define GLOBAL_EPON_CNTL_dft                     0x00030000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 epon_rst_n           :  1 ; /* bits 0:0 */
    u32 onumpcp_rst_n        :  1 ; /* bits 1:1 */
    u32 onugepn_rst_n        :  1 ; /* bits 2:2 */
    u32 xgepn_rst_n          :  1 ; /* bits 3:3 */
    u32 rsrvd1               :  1 ;
    u32 rx_coresec_10_rst_n  :  1 ; /* bits 5:5 */
    u32 tx_coresec_10_rst_n  :  1 ; /* bits 6:6 */
    u32 apb_coresec_10_rst_n :  1 ; /* bits 7:7 */
    u32 xge_c10_en           :  1 ; /* bits 8:8 */
    u32 act_eth_rst_n        :  1 ; /* bits 9:9 */
    u32 rsrvd2               :  6 ;
    u32 epon_onu_mode        :  2 ; /* bits 17:16 */
    u32 epon_ethernet_mode   :  1 ; /* bits 18:18 */
    u32 rsrvd3               : 13 ;
  } bf ;
  u32     wrd ;
} GLOBAL_EPON_CNTL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_EPON_STATUS                       0xf4320078
#define GLOBAL_EPON_STATUS_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 xgepon_linkok        :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} GLOBAL_EPON_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_GPON_CNTL                         0xf432007c
#define GLOBAL_GPON_CNTL_dft                     0x00000300

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ani_rst_n            :  1 ; /* bits 0:0 */
    u32 gpon_rst_n           :  1 ; /* bits 1:1 */
    u32 xgpn_rst_n           :  1 ; /* bits 2:2 */
    u32 rsrvd1               :  5 ;
    u32 us10g_mode           :  1 ; /* bits 8:8 */
    u32 nxgs_mode            :  1 ; /* bits 9:9 */
    u32 rsrvd2               : 22 ;
  } bf ;
  u32     wrd ;
} GLOBAL_GPON_CNTL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_OPT_MODULE_CNTL                   0xf4320080
#define GLOBAL_OPT_MODULE_CNTL_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 opt_tx_power_down    :  1 ; /* bits 0:0 */
    u32 en_lao_det           :  1 ; /* bits 1:1 */
    u32 hw_lao_enable        :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 27 ;
    u32 los_invert           :  1 ; /* bits 30:30 */
    u32 opt_cntl_reset       :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_OPT_MODULE_CNTL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_OPT_MODULE_LAO_CNTL               0xf4320084
#define GLOBAL_OPT_MODULE_LAO_CNTL_dft           0x00ff00ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 lao_accu_one         : 16 ; /* bits 15:0 */
    u32 lao_accu_zero        : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} GLOBAL_OPT_MODULE_LAO_CNTL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_OPT_INTERRUPT                     0xf4320088
#define GLOBAL_OPT_INTERRUPT_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_los               :  1 ; /* bits 0:0 */
    u32 tx_fault             :  1 ; /* bits 1:1 */
    u32 mod_abs              :  1 ; /* bits 2:2 */
    u32 rsrvd1               :  5 ;
    u32 lao_stuck_at_one_int :  1 ; /* bits 8:8 */
    u32 lao_stuck_at_zero_int :  1 ; /* bits 9:9 */
    u32 rsrvd2               : 22 ;
  } bf ;
  u32     wrd ;
} GLOBAL_OPT_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_OPT_INTENABLE                     0xf432008c
#define GLOBAL_OPT_INTENABLE_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_losE              :  1 ; /* bits 0:0 */
    u32 tx_faultE            :  1 ; /* bits 1:1 */
    u32 mod_absE             :  1 ; /* bits 2:2 */
    u32 rsrvd1               :  5 ;
    u32 lao_stuck_at_one_intE :  1 ; /* bits 8:8 */
    u32 lao_stuck_at_zero_intE :  1 ; /* bits 9:9 */
    u32 rsrvd2               : 22 ;
  } bf ;
  u32     wrd ;
} GLOBAL_OPT_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_OPT_MODULE_STATUS                 0xf4320090
#define GLOBAL_OPT_MODULE_STATUS_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 opt_tx_fault         :  1 ; /* bits 0:0 */
    u32 opt_tx_sd            :  1 ; /* bits 1:1 */
    u32 opt_mod_abs          :  1 ; /* bits 2:2 */
    u32 opt_rx_los           :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} GLOBAL_OPT_MODULE_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PON_CNTL                          0xf4320094
#define GLOBAL_PON_CNTL_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 epon_mode            :  1 ; /* bits 0:0 */
    u32 pon_serdes_rst_n     :  1 ; /* bits 1:1 */
    u32 psds_reg_rst_n       :  1 ; /* bits 2:2 */
    u32 ptp_rst_n            :  1 ; /* bits 3:3 */
    u32 rsrvd1               :  4 ;
    u32 puc_reset            :  1 ; /* bits 8:8 */
    u32 pdc_reset            :  1 ; /* bits 9:9 */
    u32 rsrvd2               : 22 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PON_CNTL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BLOCK_RESET                       0xf4320098
#define GLOBAL_BLOCK_RESET_dft                   0xd03021c0

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 reset_ni             :  1 ; /* bits 0:0 */
    u32 reset_l2fe           :  1 ; /* bits 1:1 */
    u32 reset_l2tm           :  1 ; /* bits 2:2 */
    u32 reset_l3fe           :  1 ; /* bits 3:3 */
    u32 reset_sdram          :  1 ; /* bits 4:4 */
    u32 reset_tqm            :  1 ; /* bits 5:5 */
    u32 reset_pcie0          :  1 ; /* bits 6:6 */
    u32 reset_pcie1          :  1 ; /* bits 7:7 */
    u32 reset_pcie2          :  1 ; /* bits 8:8 */
    u32 rsrvd1               :  1 ;
    u32 reset_gic400         :  1 ; /* bits 10:10 */
    u32 reset_l3fe_reo       :  1 ; /* bits 11:11 */
    u32 reset_qm_reo         :  1 ; /* bits 12:12 */
    u32 reset_usb            :  1 ; /* bits 13:13 */
    u32 reset_flash          :  1 ; /* bits 14:14 */
    u32 reset_per            :  1 ; /* bits 15:15 */
    u32 reset_dma            :  1 ; /* bits 16:16 */
    u32 reset_rtc            :  1 ; /* bits 17:17 */
    u32 reset_pe0            :  1 ; /* bits 18:18 */
    u32 reset_pe1            :  1 ; /* bits 19:19 */
    u32 reset_rcpu0          :  1 ; /* bits 20:20 */
    u32 reset_rcpu1          :  1 ; /* bits 21:21 */
    u32 reset_sadb           :  1 ; /* bits 22:22 */
    u32 reset_uvlo           :  1 ; /* bits 23:23 */
    u32 reset_rcrypto        :  1 ; /* bits 24:24 */
    u32 reset_ldma           :  1 ; /* bits 25:25 */
    u32 reset_gphy           :  1 ; /* bits 26:26 */
    u32 reset_dma_reo        :  1 ; /* bits 27:27 */
    u32 reset_sd             :  1 ; /* bits 28:28 */
    u32 reset_otprom         :  1 ; /* bits 29:29 */
    u32 reset_ptp_timer      :  1 ; /* bits 30:30 */
    u32 reset_qxgmii         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_BLOCK_RESET_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BLOCK_RESET_EXT                   0xf432009c
#define GLOBAL_BLOCK_RESET_EXT_dft               0x00003f00

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 reset_i2s            :  1 ; /* bits 0:0 */
    u32 reset_gdma           :  1 ; /* bits 1:1 */
    u32 reset_ssi0           :  1 ; /* bits 2:2 */
    u32 reset_uart0          :  1 ; /* bits 3:3 */
    u32 reset_uart1          :  1 ; /* bits 4:4 */
    u32 USB2_PORT_1_OTG_SW_PHY_RESET :  1 ; /* bits 5:5 */
    u32 rsrvd1               :  2 ;
    u32 en_gdma              :  1 ; /* bits 8:8 */
    u32 en_ssi0              :  1 ; /* bits 9:9 */
    u32 en_dma_uart0         :  1 ; /* bits 10:10 */
    u32 en_dma_uart1         :  1 ; /* bits 11:11 */
    u32 en_i2s               :  1 ; /* bits 12:12 */
    u32 wrap_sds_en          :  1 ; /* bits 13:13 */
    u32 en_sd                :  1 ; /* bits 14:14 */
    u32 rsrvd2               : 17 ;
  } bf ;
  u32     wrd ;
} GLOBAL_BLOCK_RESET_EXT_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_DPHY_RESET                        0xf43200a0
#define GLOBAL_DPHY_RESET_dft                    0x000001af

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 reset_dphy_s0_pcie   :  1 ; /* bits 0:0 */
    u32 reset_dphy_s1_pcie   :  1 ; /* bits 1:1 */
    u32 reset_dphy_s2_pcie   :  1 ; /* bits 2:2 */
    u32 reset_dphy_s3_pcie   :  1 ; /* bits 3:3 */
    u32 rsrvd1               :  1 ;
    u32 reset_dphy_s3_sgmii  :  1 ; /* bits 5:5 */
    u32 rsrvd2               :  1 ;
    u32 reset_sdsif          :  1 ; /* bits 7:7 */
    u32 reset_sgmii          :  1 ; /* bits 8:8 */
    u32 rsrvd3               : 23 ;
  } bf ;
  u32     wrd ;
} GLOBAL_DPHY_RESET_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_FABRIC_RESET                      0xf43200a4
#define GLOBAL_FABRIC_RESET_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 reset_axi            :  1 ; /* bits 0:0 */
    u32 reset_capsram        :  1 ; /* bits 1:1 */
    u32 reset_capsramreg     :  1 ; /* bits 2:2 */
    u32 reset_ccireg         :  1 ; /* bits 3:3 */
    u32 reset_global_hsio    :  1 ; /* bits 4:4 */
    u32 rsrvd1               :  1 ;
    u32 reset_global_ls      :  1 ; /* bits 6:6 */
    u32 reset_global_pe      :  1 ; /* bits 7:7 */
    u32 reset_lsaxi_cortexapb :  1 ; /* bits 8:8 */
    u32 rsrvd2               : 23 ;
  } bf ;
  u32     wrd ;
} GLOBAL_FABRIC_RESET_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ARM_RESET                         0xf43200a8
#define GLOBAL_ARM_RESET_dft                     0x000001c0

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 restart              :  1 ; /* bits 0:0 */
    u32 CPUPORESET           :  4 ; /* bits 4:1 */
    u32 CORERESET            :  4 ; /* bits 8:5 */
    u32 rsrvd1               :  2 ;
    u32 RESETSOCDBG          :  1 ; /* bits 11:11 */
    u32 RESETPOR             :  1 ; /* bits 12:12 */
    u32 ALLOW_DBG            :  4 ; /* bits 16:13 */
    u32 ALLOW_WARM           :  4 ; /* bits 20:17 */
    u32 rsrvd2               :  7 ;
    u32 A53WARMRSTREQ        :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} GLOBAL_ARM_RESET_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_STRAP                             0xf43200ac
#define GLOBAL_STRAP_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 debug_mode           :  1 ; /* bits 0:0 */
    u32 speed                :  3 ; /* bits 3:1 */
    u32 flash_type           :  3 ; /* bits 6:4 */
    u32 flash_size           :  2 ; /* bits 8:7 */
    u32 flash_width          :  1 ; /* bits 9:9 */
    u32 flash_pin            :  1 ; /* bits 10:10 */
    u32 uart_message         :  1 ; /* bits 11:11 */
    u32 sd                   :  1 ; /* bits 12:12 */
    u32 pmd                  :  1 ; /* bits 13:13 */
    u32 rsrvd1               : 10 ;
    u32 jtag_osc             :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} GLOBAL_STRAP_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_RESULT                       0xf43200b0
#define GLOBAL_BIST_RESULT_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 bist_complete_capsram :  1 ; /* bits 0:0 */
    u32 bist_complete_puc3   :  1 ; /* bits 1:1 */
    u32 bist_complete_puc2b  :  1 ; /* bits 2:2 */
    u32 bist_complete_puc2   :  1 ; /* bits 3:3 */
    u32 bist_complete_l3qm2  :  1 ; /* bits 4:4 */
    u32 bist_complete_l2tm1  :  1 ; /* bits 5:5 */
    u32 bist_complete_taroko_1 :  1 ; /* bits 6:6 */
    u32 bist_complete_taroko_0 :  1 ; /* bits 7:7 */
    u32 bist_complete_a55_1  :  1 ; /* bits 8:8 */
    u32 bist_complete_a55_0  :  1 ; /* bits 9:9 */
    u32 rsrvd1               : 10 ;
    u32 a55_1                : 12 ; /* bits 31:20 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_RESULT_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_DATA                         0xf43200b4
#define GLOBAL_BIST_DATA_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 capsram              : 12 ; /* bits 11:0 */
    u32 l3qm2                :  6 ; /* bits 17:12 */
    u32 l2tm1                :  6 ; /* bits 23:18 */
    u32 puc3                 :  6 ; /* bits 29:24 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_DATA_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_DATA2                        0xf43200b8
#define GLOBAL_BIST_DATA2_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 puc2                 : 20 ; /* bits 19:0 */
    u32 a55_0                : 12 ; /* bits 31:20 */
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_DATA2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BIST_DATA3                        0xf43200bc
#define GLOBAL_BIST_DATA3_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 puc2b                : 20 ; /* bits 19:0 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} GLOBAL_BIST_DATA3_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_GLOBAL_CONFIG                     0xf43200c0
#define GLOBAL_GLOBAL_CONFIG_dft                 0x07e45400

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 quad_off             :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  3 ;
    u32 wd_reset_subsys_enable :  1 ; /* bits 4:4 */
    u32 wd_reset_pcie        :  1 ; /* bits 5:5 */
    u32 wd_reset_all_blocks  :  1 ; /* bits 6:6 */
    u32 wd_reset_remap       :  1 ; /* bits 7:7 */
    u32 wd_reset_ext_reset   :  1 ; /* bits 8:8 */
    u32 ext_reset            :  1 ; /* bits 9:9 */
    u32 cfg_pcie_0_clken     :  1 ; /* bits 10:10 */
    u32 rsrvd2               :  1 ;
    u32 cfg_pcie_1_clken     :  1 ; /* bits 12:12 */
    u32 rsrvd3               :  1 ;
    u32 cfg_pcie_2_clken     :  1 ; /* bits 14:14 */
    u32 gpon_pd              :  1 ; /* bits 15:15 */
    u32 epon_pd              :  1 ; /* bits 16:16 */
    u32 ext_eth_refclk       :  1 ; /* bits 17:17 */
    u32 refclk_sel           :  2 ; /* bits 19:18 */
    u32 trng_pd              :  1 ; /* bits 20:20 */
    u32 ps_usb2_otg_en       :  1 ; /* bits 21:21 */
    u32 ps_pcie0_en          :  1 ; /* bits 22:22 */
    u32 ps_pcie1_en          :  1 ; /* bits 23:23 */
    u32 ps_pcie2_en          :  1 ; /* bits 24:24 */
    u32 ps_usb3_en           :  1 ; /* bits 25:25 */
    u32 ps_pe_en             :  1 ; /* bits 26:26 */
    u32 l3fe_pd              :  1 ; /* bits 27:27 */
    u32 offload0_pd          :  1 ; /* bits 28:28 */
    u32 offload1_pd          :  1 ; /* bits 29:29 */
    u32 crypto_pd            :  1 ; /* bits 30:30 */
    u32 core_pd              :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_GLOBAL_CONFIG_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PHY_CONTROL                       0xf43200c4
#define GLOBAL_PHY_CONTROL_dft                   0x01040113

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_xfi0_10g         :  1 ; /* bits 0:0 */
    u32 cfg_xfi1_10g         :  1 ; /* bits 1:1 */
    u32 rsrvd1               :  2 ;
    u32 USB2_LPM_PLL_ALIVE   :  1 ; /* bits 4:4 */
    u32 USB2_PORT_1_CLOSE    :  1 ; /* bits 5:5 */
    u32 rsrvd2               :  2 ;
    u32 USB2_REF_SEL         :  4 ; /* bits 11:8 */
    u32 rsrvd3               :  6 ;
    u32 sys_pcie2_and_s2_sel :  1 ; /* bits 18:18 */
    u32 sys_usb3_and_s2_sel  :  1 ; /* bits 19:19 */
    u32 s2_pcie_usb3_sel     :  1 ; /* bits 20:20 */
    u32 s2_pcie_usb3_sgmii_sel :  2 ; /* bits 22:21 */
    u32 rsrvd4               :  1 ;
    u32 s3_pcie_usb3_sel     :  1 ; /* bits 24:24 */
    u32 s3_pcie_usb3_sgmii_sel :  2 ; /* bits 26:25 */
    u32 s0_rxaui_mode        :  1 ; /* bits 27:27 */
    u32 s0_p_mdio_enable_reg :  1 ; /* bits 28:28 */
    u32 s1_p_mdio_enable_reg :  1 ; /* bits 29:29 */
    u32 s2_p_mdio_enable_reg :  1 ; /* bits 30:30 */
    u32 s3_p_mdio_enable_reg :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_PHY_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PHY_MISC_CONTROL                  0xf43200c8
#define GLOBAL_PHY_MISC_CONTROL_dft              0xc0000a00

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  8 ;
    u32 s2_USB3_BG_EN        :  1 ; /* bits 8:8 */
    u32 s2_USB3_MBIAS_EN     :  1 ; /* bits 9:9 */
    u32 s3_USB3_BG_EN        :  1 ; /* bits 10:10 */
    u32 s3_USB3_MBIAS_EN     :  1 ; /* bits 11:11 */
    u32 rsrvd2               : 18 ;
    u32 s2_USB3_OOBS_PDB     :  1 ; /* bits 30:30 */
    u32 s3_USB3_OOBS_PDB     :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_PHY_MISC_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PHY_STATUS                        0xf43200cc
#define GLOBAL_PHY_STATUS_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 USB2_CKUSABLE        :  2 ; /* bits 1:0 */
    u32 rsrvd1               :  1 ;
    u32 s2_CKUSABLE          :  1 ; /* bits 3:3 */
    u32 s3_CKUSABLE          :  1 ; /* bits 4:4 */
    u32 s0_CKUSABLE          :  1 ; /* bits 5:5 */
    u32 s1_CKUSABLE          :  1 ; /* bits 6:6 */
    u32 CKUSABLE_SGMII       :  1 ; /* bits 7:7 */
    u32 rsrvd2               : 24 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PHY_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PHY_SGMII_MISC_CONTROL            0xf43200d0
#define GLOBAL_PHY_SGMII_MISC_CONTROL_dft        0x00000010

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 s3_SGMII_CKBUF_EN    :  1 ; /* bits 0:0 */
    u32 s3_SGMII_CLK_MODE_SEL :  2 ; /* bits 2:1 */
    u32 s3_SGMII_BG_EN       :  1 ; /* bits 3:3 */
    u32 s3_SGMII_MBIAS_EN    :  1 ; /* bits 4:4 */
    u32 s3_SGMII_RX50_LINK   :  1 ; /* bits 5:5 */
    u32 rsrvd1               :  1 ;
    u32 s3_TX_DEEMP_SEL_SGMII :  1 ; /* bits 7:7 */
    u32 s3_EQHOLD_SGMII      :  1 ; /* bits 8:8 */
    u32 rsrvd2               : 23 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PHY_SGMII_MISC_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PHY_SGMII_PCS_CONTROL             0xf43200d4
#define GLOBAL_PHY_SGMII_PCS_CONTROL_dft         0x0000007c

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sgmii_sds_tx_disable_s0 :  1 ; /* bits 0:0 */
    u32 sgmii_sds_rx_disable_s0 :  1 ; /* bits 1:1 */
    u32 sgmii_sds_mode0      :  5 ; /* bits 6:2 */
    u32 sgmii_sds_iso_on_s0  :  1 ; /* bits 7:7 */
    u32 sgmii_sds_frc_ld_s0  :  1 ; /* bits 8:8 */
    u32 sgmii_sds0_ablty     : 17 ; /* bits 25:9 */
    u32 sgmii_cf_spd0x       :  3 ; /* bits 28:26 */
    u32 sgmii_spdup_ini      :  1 ; /* bits 29:29 */
    u32 sgmii_load_sys_par   :  1 ; /* bits 30:30 */
    u32 rsrvd1               :  1 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PHY_SGMII_PCS_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PHY_SGMII_PCS_CONTROL_2nd         0xf43200d8
#define GLOBAL_PHY_SGMII_PCS_CONTROL_2nd_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sgmii_unidir_tx_able_s0 :  1 ; /* bits 0:0 */
    u32 sgmii_pause_ini_s0   :  2 ; /* bits 2:1 */
    u32 rsrvd1               :  1 ;
    u32 sgmii_realtek_oui    : 24 ; /* bits 27:4 */
    u32 rsrvd2               :  4 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PHY_SGMII_PCS_CONTROL_2nd_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PHY_SGMII_PCS_CONTROL_3rd         0xf43200dc
#define GLOBAL_PHY_SGMII_PCS_CONTROL_3rd_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sgmii_revision_no    :  4 ; /* bits 3:0 */
    u32 sgmii_model_no       :  6 ; /* bits 9:4 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PHY_SGMII_PCS_CONTROL_3rd_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PHY_SGMII_PCS_INFO                0xf43200e0
#define GLOBAL_PHY_SGMII_PCS_INFO_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sgmii_sds_link_ok    :  1 ; /* bits 0:0 */
    u32 sgmii_sds_reg_rdy    :  1 ; /* bits 1:1 */
    u32 sgmii_sds_sdet_out_s0 :  1 ; /* bits 2:2 */
    u32 sgmii_sts_upd_rx     :  1 ; /* bits 3:3 */
    u32 sgmii_sds_rx_sym_err_all_s0 :  1 ; /* bits 4:4 */
    u32 sgmii_sds0_link_partner_ablty : 17 ; /* bits 21:5 */
    u32 rsrvd1               : 10 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PHY_SGMII_PCS_INFO_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SGMII_PCS_INTERRUPT               0xf43200e4
#define GLOBAL_SGMII_PCS_INTERRUPT_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 LINK_OKi             :  1 ; /* bits 0:0 */
    u32 UPD_RXi              :  1 ; /* bits 1:1 */
    u32 SYM_ERRi             :  1 ; /* bits 2:2 */
    u32 LPA_MDFi             :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} GLOBAL_SGMII_PCS_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SGMII_PCS_INTENABLE               0xf43200e8
#define GLOBAL_SGMII_PCS_INTENABLE_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 LINK_OKe             :  1 ; /* bits 0:0 */
    u32 UPD_RXe              :  1 ; /* bits 1:1 */
    u32 SYM_ERRe             :  1 ; /* bits 2:2 */
    u32 LPA_MDFe             :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} GLOBAL_SGMII_PCS_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_RXAUI_SERDES_CONTROL              0xf43200ec
#define GLOBAL_RXAUI_SERDES_CONTROL_dft          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 aphy_txdata_en       :  2 ; /* bits 1:0 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} GLOBAL_RXAUI_SERDES_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PIN_MUX                           0xf43200f0
#define GLOBAL_PIN_MUX_dft                       0x80000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pmux_flash           :  2 ; /* bits 1:0 */
    u32 arm_trace_enable     :  1 ; /* bits 2:2 */
    u32 iomux_uart_0_hwfc_enable :  1 ; /* bits 3:3 */
    u32 iomux_uart_2_enable  :  1 ; /* bits 4:4 */
    u32 iomux_uart_3_enable  :  1 ; /* bits 5:5 */
    u32 iomux_spi_cs_1_enable :  1 ; /* bits 6:6 */
    u32 iomux_spi_cs_2_enable :  1 ; /* bits 7:7 */
    u32 iomux_spi_cs_3_enable :  1 ; /* bits 8:8 */
    u32 iomux_spi_cs_4_enable :  1 ; /* bits 9:9 */
    u32 iomux_pwm_nf         :  1 ; /* bits 10:10 */
    u32 iomux_pwm_sf         :  1 ; /* bits 11:11 */
    u32 rsrvd1               :  2 ;
    u32 iomux_use_cspi       :  1 ; /* bits 14:14 */
    u32 rsrvd2               :  4 ;
    u32 iomux_led_enable     :  1 ; /* bits 19:19 */
    u32 rsrvd3               : 10 ;
    u32 fmro_enable          :  1 ; /* bits 30:30 */
    u32 flash_mux_sel        :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_PIN_MUX_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PIN_MUX_NEW                       0xf43200f4
#define GLOBAL_PIN_MUX_NEW_dft                   0x0091cfdc

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 iomux_uart_3_hwfc_enable :  1 ; /* bits 0:0 */
    u32 iomux_uart_2_hwfc_enable :  1 ; /* bits 1:1 */
    u32 iomux_uart_1_enable  :  1 ; /* bits 2:2 */
    u32 iomux_uart_0_enable  :  1 ; /* bits 3:3 */
    u32 iomux_ssp_enable     :  1 ; /* bits 4:4 */
    u32 iomux_spi_dma_enable :  1 ; /* bits 5:5 */
    u32 iomux_spi_enable     :  1 ; /* bits 6:6 */
    u32 iomux_ref_clk_enable :  1 ; /* bits 7:7 */
    u32 iomux_opt_enable     :  1 ; /* bits 8:8 */
    u32 iomux_onu_enable     :  1 ; /* bits 9:9 */
    u32 iomux_mmc_enable     :  1 ; /* bits 10:10 */
    u32 iomux_mdio_enable    :  1 ; /* bits 11:11 */
    u32 iomux_i2s_slv_enable :  1 ; /* bits 12:12 */
    u32 iomux_i2s_mst_enable :  1 ; /* bits 13:13 */
    u32 iomux_gmac_enable    :  1 ; /* bits 14:14 */
    u32 iomux_flash_enable   :  1 ; /* bits 15:15 */
    u32 iomux_cpu_debug_enable :  1 ; /* bits 16:16 */
    u32 iomux_biw1_enable    :  3 ; /* bits 19:17 */
    u32 iomux_biw0_enable    :  3 ; /* bits 22:20 */
    u32 iomux_jtag_enable    :  1 ; /* bits 23:23 */
    u32 iomux_sdpll_enable   :  1 ; /* bits 24:24 */
    u32 iomux_spi_dma_3wire  :  1 ; /* bits 25:25 */
    u32 rsrvd1               :  6 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PIN_MUX_NEW_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SD_IO_PULL_CONTROL                0xf43200f8
#define GLOBAL_SD_IO_PULL_CONTROL_dft            0x010015ff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_mmc_pd           : 13 ; /* bits 12:0 */
    u32 cfg_mmc_pu           : 13 ; /* bits 25:13 */
    u32 rsrvd1               :  6 ;
  } bf ;
  u32     wrd ;
} GLOBAL_SD_IO_PULL_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_IO_DRIVE_CONTROL                  0xf43200fc
#define GLOBAL_IO_DRIVE_CONTROL_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gmac_dp              :  3 ; /* bits 2:0 */
    u32 gmac_dn              :  3 ; /* bits 5:3 */
    u32 gmac_mode            :  2 ; /* bits 7:6 */
    u32 gmac_ds              :  1 ; /* bits 8:8 */
    u32 flash_ds             :  1 ; /* bits 9:9 */
    u32 nu_ds                :  1 ; /* bits 10:10 */
    u32 ssp_ds               :  1 ; /* bits 11:11 */
    u32 spi_ds               :  1 ; /* bits 12:12 */
    u32 gpio_ds              :  1 ; /* bits 13:13 */
    u32 misc_ds              :  1 ; /* bits 14:14 */
    u32 eaxi_ds              :  1 ; /* bits 15:15 */
    u32 rsrvd1               :  8 ;
    u32 sr                   :  1 ; /* bits 24:24 */
    u32 rsrvd2               :  7 ;
  } bf ;
  u32     wrd ;
} GLOBAL_IO_DRIVE_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_GPIO_MUX_0                        0xf4320100
#define GLOBAL_GPIO_MUX_0_dft                    0x0000ffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpio0en              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_GPIO_MUX_0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_GPIO_MUX_1                        0xf4320104
#define GLOBAL_GPIO_MUX_1_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpio1en              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_GPIO_MUX_1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_GPIO_MUX_2                        0xf4320108
#define GLOBAL_GPIO_MUX_2_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpio2en              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_GPIO_MUX_2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_GPIO_MUX_3                        0xf432010c
#define GLOBAL_GPIO_MUX_3_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpio3en              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_GPIO_MUX_3_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_GPIO_MUX_4                        0xf4320110
#define GLOBAL_GPIO_MUX_4_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpio4en              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_GPIO_MUX_4_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_GIGE_PHY                          0xf4320114
#define GLOBAL_GIGE_PHY_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  3 ;
    u32 gphy_SEL_PHY_REFCK_UPS_L :  1 ; /* bits 3:3 */
    u32 rsrvd2               : 28 ;
  } bf ;
  u32     wrd ;
} GLOBAL_GIGE_PHY_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ARM_STATE                         0xf4320118
#define GLOBAL_ARM_STATE_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 CLUSTERPACTIVE       : 20 ; /* bits 19:0 */
    u32 CLUSTERPACCEPT       :  1 ; /* bits 20:20 */
    u32 CLUSTERPDENY         :  1 ; /* bits 21:21 */
    u32 PMUSNAPSHOTACK       :  1 ; /* bits 22:22 */
    u32 gic_pmu_sample_ack   :  1 ; /* bits 23:23 */
    u32 rsrvd1               :  1 ;
    u32 cpu_wd_req           :  1 ; /* bits 25:25 */
    u32 cpll_lock            :  1 ; /* bits 26:26 */
    u32 epll_lock            :  1 ; /* bits 27:27 */
    u32 fpll_lock            :  1 ; /* bits 28:28 */
    u32 cpll_switch_state    :  1 ; /* bits 29:29 */
    u32 epll_switch_state    :  1 ; /* bits 30:30 */
    u32 fpll_switch_state    :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_ARM_STATE_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ARM_CPU0_STATE                    0xf432011c
#define GLOBAL_ARM_CPU0_STATE_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 COREPACTIVE0         : 18 ; /* bits 17:0 */
    u32 rsrvd1               :  2 ;
    u32 COREPACCEPT0         :  1 ; /* bits 20:20 */
    u32 COREPDENY0           :  1 ; /* bits 21:21 */
    u32 pwrctrl_out          :  1 ; /* bits 22:22 */
    u32 pwrctrl_2nd_out      :  1 ; /* bits 23:23 */
    u32 rsrvd2               :  8 ;
  } bf ;
  u32     wrd ;
} GLOBAL_ARM_CPU0_STATE_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ARM_CPU1_STATE                    0xf4320120
#define GLOBAL_ARM_CPU1_STATE_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 COREPACTIVE1         : 18 ; /* bits 17:0 */
    u32 rsrvd1               :  2 ;
    u32 COREPACCEPT1         :  1 ; /* bits 20:20 */
    u32 COREPDENY1           :  1 ; /* bits 21:21 */
    u32 pwrctrl_out          :  1 ; /* bits 22:22 */
    u32 pwrctrl_2nd_out      :  1 ; /* bits 23:23 */
    u32 rsrvd2               :  8 ;
  } bf ;
  u32     wrd ;
} GLOBAL_ARM_CPU1_STATE_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ARM_CPU2_STATE                    0xf4320124
#define GLOBAL_ARM_CPU2_STATE_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 COREPACTIVE2         : 18 ; /* bits 17:0 */
    u32 rsrvd1               :  2 ;
    u32 COREPACCEPT2         :  1 ; /* bits 20:20 */
    u32 COREPDENY2           :  1 ; /* bits 21:21 */
    u32 pwrctrl_out          :  1 ; /* bits 22:22 */
    u32 pwrctrl_2nd_out      :  1 ; /* bits 23:23 */
    u32 rsrvd2               :  8 ;
  } bf ;
  u32     wrd ;
} GLOBAL_ARM_CPU2_STATE_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ARM_CPU3_STATE                    0xf4320128
#define GLOBAL_ARM_CPU3_STATE_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 COREPACTIVE3         : 18 ; /* bits 17:0 */
    u32 rsrvd1               :  2 ;
    u32 COREPACCEPT3         :  1 ; /* bits 20:20 */
    u32 COREPDENY3           :  1 ; /* bits 21:21 */
    u32 pwrctrl_out          :  1 ; /* bits 22:22 */
    u32 pwrctrl_2nd_out      :  1 ; /* bits 23:23 */
    u32 rsrvd2               :  8 ;
  } bf ;
  u32     wrd ;
} GLOBAL_ARM_CPU3_STATE_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PE_DSS_STATE                      0xf432012c
#define GLOBAL_PE_DSS_STATE_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_dss_ready       :  4 ; /* bits 3:0 */
    u32 rsrvd1               :  4 ;
    u32 pe0_debug_mode       :  1 ; /* bits 8:8 */
    u32 pe0_sleepsys_mode    :  1 ; /* bits 9:9 */
    u32 pe1_debug_mode       :  1 ; /* bits 10:10 */
    u32 pe1_sleepsys_mode    :  1 ; /* bits 11:11 */
    u32 rsrvd2               : 20 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PE_DSS_STATE_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_DSS_COUNT2                        0xf4320130
#define GLOBAL_DSS_COUNT2_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_count_out2      : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} GLOBAL_DSS_COUNT2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_DSS_COUNT1                        0xf4320134
#define GLOBAL_DSS_COUNT1_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_count_out1      : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_DSS_COUNT1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_DSS_COUNT0                        0xf4320138
#define GLOBAL_DSS_COUNT0_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_count_out0      : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_DSS_COUNT0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ARM_CONFIG_A                      0xf432013c
#define GLOBAL_ARM_CONFIG_A_dft                  0x0000f00f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 AA64nAA32            :  4 ; /* bits 3:0 */
    u32 CFGEND               :  4 ; /* bits 7:4 */
    u32 CFGTE                :  4 ; /* bits 11:8 */
    u32 VINITHI              :  4 ; /* bits 15:12 */
    u32 CRYPTODISABLE        :  1 ; /* bits 16:16 */
    u32 PMUSNAPSHOTREQ       :  1 ; /* bits 17:17 */
    u32 gic_pmu_sample_req   :  1 ; /* bits 18:18 */
    u32 rsrvd1               : 11 ;
    u32 gict_allow_ns        :  1 ; /* bits 30:30 */
    u32 gicp_allow_ns        :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_ARM_CONFIG_A_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ARM_CONFIG_B                      0xf4320140
#define GLOBAL_ARM_CONFIG_B_dft                  0x00000048

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 CLUSTERPSTATE        :  7 ; /* bits 6:0 */
    u32 CLUSTERPREQ          :  1 ; /* bits 7:7 */
    u32 rsrvd1               :  8 ;
    u32 ca55_core_clamp_en   :  4 ; /* bits 19:16 */
    u32 ca55_core_pwrctrl_in :  4 ; /* bits 23:20 */
    u32 ca55_core_pwrctrl_2nd_in :  4 ; /* bits 27:24 */
    u32 rsrvd2               :  4 ;
  } bf ;
  u32     wrd ;
} GLOBAL_ARM_CONFIG_B_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ARM_CONFIG_C                      0xf4320144
#define GLOBAL_ARM_CONFIG_C_dft                  0x08080808

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 COREPSTATE0          :  6 ; /* bits 5:0 */
    u32 rsrvd1               :  1 ;
    u32 COREPREQ0            :  1 ; /* bits 7:7 */
    u32 COREPSTATE1          :  6 ; /* bits 13:8 */
    u32 rsrvd2               :  1 ;
    u32 COREPREQ1            :  1 ; /* bits 15:15 */
    u32 COREPSTATE2          :  6 ; /* bits 21:16 */
    u32 rsrvd3               :  1 ;
    u32 COREPREQ2            :  1 ; /* bits 23:23 */
    u32 COREPSTATE3          :  6 ; /* bits 29:24 */
    u32 rsrvd4               :  1 ;
    u32 COREPREQ3            :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_ARM_CONFIG_C_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ARM_CONFIG_D1                     0xf4320148
#define GLOBAL_ARM_CONFIG_D1_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 RVBARADDR1           :  6 ; /* bits 5:0 */
    u32 rsrvd1               : 26 ;
  } bf ;
  u32     wrd ;
} GLOBAL_ARM_CONFIG_D1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ARM_CONFIG_D0                     0xf432014c
#define GLOBAL_ARM_CONFIG_D0_dft                 0x3fffc000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 RVBARADDR0           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_ARM_CONFIG_D0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ARM_CONFIG_E                      0xf4320150
#define GLOBAL_ARM_CONFIG_E_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  6 ;
    u32 ca55_dss_rst_n       :  4 ; /* bits 9:6 */
    u32 ca55_dss_ro_sel      : 12 ; /* bits 21:10 */
    u32 ca55_dss_speed_en    :  4 ; /* bits 25:22 */
    u32 ca55_dss_wire_sel    :  4 ; /* bits 29:26 */
    u32 rsrvd2               :  2 ;
  } bf ;
  u32     wrd ;
} GLOBAL_ARM_CONFIG_E_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ARM_CONFIG_F                      0xf4320154
#define GLOBAL_ARM_CONFIG_F_dft                  0x00004000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ASTARTMP             : 20 ; /* bits 19:0 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} GLOBAL_ARM_CONFIG_F_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ARM_CONFIG_G                      0xf4320158
#define GLOBAL_ARM_CONFIG_G_dft                  0x00008000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 AENDMP               : 20 ; /* bits 19:0 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} GLOBAL_ARM_CONFIG_G_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SYSTEM_INTERRUPT                  0xf432015c
#define GLOBAL_SYSTEM_INTERRUPT_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 CPLL_LOCKi           :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  1 ;
    u32 EPLL_LOCKi           :  1 ; /* bits 2:2 */
    u32 FPLL_LOCKi           :  1 ; /* bits 3:3 */
    u32 CPU_WD_REQi          :  1 ; /* bits 4:4 */
    u32 CORE_CLKi            :  1 ; /* bits 5:5 */
    u32 rsrvd2               : 26 ;
  } bf ;
  u32     wrd ;
} GLOBAL_SYSTEM_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SYSTEM_INTENABLE                  0xf4320160
#define GLOBAL_SYSTEM_INTENABLE_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 CPLL_LOCKe           :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  1 ;
    u32 EPLL_LOCKe           :  1 ; /* bits 2:2 */
    u32 FPLL_LOCKe           :  1 ; /* bits 3:3 */
    u32 CPU_WD_REQe          :  1 ; /* bits 4:4 */
    u32 CORE_CLKe            :  1 ; /* bits 5:5 */
    u32 rsrvd2               : 26 ;
  } bf ;
  u32     wrd ;
} GLOBAL_SYSTEM_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_NETWORK_ENGINE_INTERRUPT_0        0xf4320164
#define GLOBAL_NETWORK_ENGINE_INTERRUPT_0_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 NIi                  :  1 ; /* bits 0:0 */
    u32 L2FEi                :  1 ; /* bits 1:1 */
    u32 L2TMi                :  1 ; /* bits 2:2 */
    u32 L3TEi                :  1 ; /* bits 3:3 */
    u32 TQMi                 :  1 ; /* bits 4:4 */
    u32 PONi                 :  1 ; /* bits 5:5 */
    u32 CPU_EPP_FIFO_0i      :  1 ; /* bits 6:6 */
    u32 CPU_EPP_FIFO_1i      :  1 ; /* bits 7:7 */
    u32 CPU_EPP_FIFO_2i      :  1 ; /* bits 8:8 */
    u32 CPU_EPP_FIFO_3i      :  1 ; /* bits 9:9 */
    u32 CPU_EPP_FIFO_4i      :  1 ; /* bits 10:10 */
    u32 CPU_EPP_FIFO_5i      :  1 ; /* bits 11:11 */
    u32 CPU_EPP_FIFO_6i      :  1 ; /* bits 12:12 */
    u32 CPU_EPP_FIFO_7i      :  1 ; /* bits 13:13 */
    u32 CPU_EPP_256_FIFO_LOi :  1 ; /* bits 14:14 */
    u32 CPU_EPP_256_FIFO_HIi :  1 ; /* bits 15:15 */
    u32 CPU_REFILL_REQ_0i    :  1 ; /* bits 16:16 */
    u32 CPU_REFILL_REQ_1i    :  1 ; /* bits 17:17 */
    u32 CPU_REFILL_REQ_2i    :  1 ; /* bits 18:18 */
    u32 CPU_REFILL_REQ_3i    :  1 ; /* bits 19:19 */
    u32 CPU_REFILL_REQ_4i    :  1 ; /* bits 20:20 */
    u32 CPU_REFILL_REQ_5i    :  1 ; /* bits 21:21 */
    u32 CPU_REFILL_REQ_6i    :  1 ; /* bits 22:22 */
    u32 CPU_REFILL_REQ_7i    :  1 ; /* bits 23:23 */
    u32 CPU_REFILL_REQ_8i    :  1 ; /* bits 24:24 */
    u32 CPU_REFILL_REQ_9i    :  1 ; /* bits 25:25 */
    u32 CPU_REFILL_REQ_10i   :  1 ; /* bits 26:26 */
    u32 CPU_REFILL_REQ_11i   :  1 ; /* bits 27:27 */
    u32 CPU_REFILL_REQ_12i   :  1 ; /* bits 28:28 */
    u32 CPU_REFILL_REQ_13i   :  1 ; /* bits 29:29 */
    u32 CPU_REFILL_REQ_14i   :  1 ; /* bits 30:30 */
    u32 CPU_REFILL_REQ_15i   :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_NETWORK_ENGINE_INTERRUPT_0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_NETWORK_ENGINE_INTENABLE_0        0xf4320168
#define GLOBAL_NETWORK_ENGINE_INTENABLE_0_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 NIe                  :  1 ; /* bits 0:0 */
    u32 L2FEe                :  1 ; /* bits 1:1 */
    u32 L2TMe                :  1 ; /* bits 2:2 */
    u32 L3TEe                :  1 ; /* bits 3:3 */
    u32 TQMe                 :  1 ; /* bits 4:4 */
    u32 PONe                 :  1 ; /* bits 5:5 */
    u32 CPU_EPP_FIFO_0e      :  1 ; /* bits 6:6 */
    u32 CPU_EPP_FIFO_1e      :  1 ; /* bits 7:7 */
    u32 CPU_EPP_FIFO_2e      :  1 ; /* bits 8:8 */
    u32 CPU_EPP_FIFO_3e      :  1 ; /* bits 9:9 */
    u32 CPU_EPP_FIFO_4e      :  1 ; /* bits 10:10 */
    u32 CPU_EPP_FIFO_5e      :  1 ; /* bits 11:11 */
    u32 CPU_EPP_FIFO_6e      :  1 ; /* bits 12:12 */
    u32 CPU_EPP_FIFO_7e      :  1 ; /* bits 13:13 */
    u32 CPU_EPP_256_FIFO_LOe :  1 ; /* bits 14:14 */
    u32 CPU_EPP_256_FIFO_HIe :  1 ; /* bits 15:15 */
    u32 CPU_REFILL_REQ_0e    :  1 ; /* bits 16:16 */
    u32 CPU_REFILL_REQ_1e    :  1 ; /* bits 17:17 */
    u32 CPU_REFILL_REQ_2e    :  1 ; /* bits 18:18 */
    u32 CPU_REFILL_REQ_3e    :  1 ; /* bits 19:19 */
    u32 CPU_REFILL_REQ_4e    :  1 ; /* bits 20:20 */
    u32 CPU_REFILL_REQ_5e    :  1 ; /* bits 21:21 */
    u32 CPU_REFILL_REQ_6e    :  1 ; /* bits 22:22 */
    u32 CPU_REFILL_REQ_7e    :  1 ; /* bits 23:23 */
    u32 CPU_REFILL_REQ_8e    :  1 ; /* bits 24:24 */
    u32 CPU_REFILL_REQ_9e    :  1 ; /* bits 25:25 */
    u32 CPU_REFILL_REQ_10e   :  1 ; /* bits 26:26 */
    u32 CPU_REFILL_REQ_11e   :  1 ; /* bits 27:27 */
    u32 CPU_REFILL_REQ_12e   :  1 ; /* bits 28:28 */
    u32 CPU_REFILL_REQ_13e   :  1 ; /* bits 29:29 */
    u32 CPU_REFILL_REQ_14e   :  1 ; /* bits 30:30 */
    u32 CPU_REFILL_REQ_15e   :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_NETWORK_ENGINE_INTENABLE_0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_NETWORK_ENGINE_INTERRUPT_1        0xf432016c
#define GLOBAL_NETWORK_ENGINE_INTERRUPT_1_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 NIi                  :  1 ; /* bits 0:0 */
    u32 L2FEi                :  1 ; /* bits 1:1 */
    u32 L2TMi                :  1 ; /* bits 2:2 */
    u32 L3TEi                :  1 ; /* bits 3:3 */
    u32 TQMi                 :  1 ; /* bits 4:4 */
    u32 PONi                 :  1 ; /* bits 5:5 */
    u32 CPU_EPP_FIFO_0i      :  1 ; /* bits 6:6 */
    u32 CPU_EPP_FIFO_1i      :  1 ; /* bits 7:7 */
    u32 CPU_EPP_FIFO_2i      :  1 ; /* bits 8:8 */
    u32 CPU_EPP_FIFO_3i      :  1 ; /* bits 9:9 */
    u32 CPU_EPP_FIFO_4i      :  1 ; /* bits 10:10 */
    u32 CPU_EPP_FIFO_5i      :  1 ; /* bits 11:11 */
    u32 CPU_EPP_FIFO_6i      :  1 ; /* bits 12:12 */
    u32 CPU_EPP_FIFO_7i      :  1 ; /* bits 13:13 */
    u32 CPU_EPP_256_FIFO_LOi :  1 ; /* bits 14:14 */
    u32 CPU_EPP_256_FIFO_HIi :  1 ; /* bits 15:15 */
    u32 CPU_REFILL_REQ_0i    :  1 ; /* bits 16:16 */
    u32 CPU_REFILL_REQ_1i    :  1 ; /* bits 17:17 */
    u32 CPU_REFILL_REQ_2i    :  1 ; /* bits 18:18 */
    u32 CPU_REFILL_REQ_3i    :  1 ; /* bits 19:19 */
    u32 CPU_REFILL_REQ_4i    :  1 ; /* bits 20:20 */
    u32 CPU_REFILL_REQ_5i    :  1 ; /* bits 21:21 */
    u32 CPU_REFILL_REQ_6i    :  1 ; /* bits 22:22 */
    u32 CPU_REFILL_REQ_7i    :  1 ; /* bits 23:23 */
    u32 CPU_REFILL_REQ_8i    :  1 ; /* bits 24:24 */
    u32 CPU_REFILL_REQ_9i    :  1 ; /* bits 25:25 */
    u32 CPU_REFILL_REQ_10i   :  1 ; /* bits 26:26 */
    u32 CPU_REFILL_REQ_11i   :  1 ; /* bits 27:27 */
    u32 CPU_REFILL_REQ_12i   :  1 ; /* bits 28:28 */
    u32 CPU_REFILL_REQ_13i   :  1 ; /* bits 29:29 */
    u32 CPU_REFILL_REQ_14i   :  1 ; /* bits 30:30 */
    u32 CPU_REFILL_REQ_15i   :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_NETWORK_ENGINE_INTERRUPT_1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_NETWORK_ENGINE_INTENABLE_1        0xf4320170
#define GLOBAL_NETWORK_ENGINE_INTENABLE_1_dft    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 NIe                  :  1 ; /* bits 0:0 */
    u32 L2FEe                :  1 ; /* bits 1:1 */
    u32 L2TMe                :  1 ; /* bits 2:2 */
    u32 L3TEe                :  1 ; /* bits 3:3 */
    u32 TQMe                 :  1 ; /* bits 4:4 */
    u32 PONe                 :  1 ; /* bits 5:5 */
    u32 CPU_EPP_FIFO_0e      :  1 ; /* bits 6:6 */
    u32 CPU_EPP_FIFO_1e      :  1 ; /* bits 7:7 */
    u32 CPU_EPP_FIFO_2e      :  1 ; /* bits 8:8 */
    u32 CPU_EPP_FIFO_3e      :  1 ; /* bits 9:9 */
    u32 CPU_EPP_FIFO_4e      :  1 ; /* bits 10:10 */
    u32 CPU_EPP_FIFO_5e      :  1 ; /* bits 11:11 */
    u32 CPU_EPP_FIFO_6e      :  1 ; /* bits 12:12 */
    u32 CPU_EPP_FIFO_7e      :  1 ; /* bits 13:13 */
    u32 CPU_EPP_256_FIFO_LOe :  1 ; /* bits 14:14 */
    u32 CPU_EPP_256_FIFO_HIe :  1 ; /* bits 15:15 */
    u32 CPU_REFILL_REQ_0e    :  1 ; /* bits 16:16 */
    u32 CPU_REFILL_REQ_1e    :  1 ; /* bits 17:17 */
    u32 CPU_REFILL_REQ_2e    :  1 ; /* bits 18:18 */
    u32 CPU_REFILL_REQ_3e    :  1 ; /* bits 19:19 */
    u32 CPU_REFILL_REQ_4e    :  1 ; /* bits 20:20 */
    u32 CPU_REFILL_REQ_5e    :  1 ; /* bits 21:21 */
    u32 CPU_REFILL_REQ_6e    :  1 ; /* bits 22:22 */
    u32 CPU_REFILL_REQ_7e    :  1 ; /* bits 23:23 */
    u32 CPU_REFILL_REQ_8e    :  1 ; /* bits 24:24 */
    u32 CPU_REFILL_REQ_9e    :  1 ; /* bits 25:25 */
    u32 CPU_REFILL_REQ_10e   :  1 ; /* bits 26:26 */
    u32 CPU_REFILL_REQ_11e   :  1 ; /* bits 27:27 */
    u32 CPU_REFILL_REQ_12e   :  1 ; /* bits 28:28 */
    u32 CPU_REFILL_REQ_13e   :  1 ; /* bits 29:29 */
    u32 CPU_REFILL_REQ_14e   :  1 ; /* bits 30:30 */
    u32 CPU_REFILL_REQ_15e   :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_NETWORK_ENGINE_INTENABLE_1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_NETWORK_ENGINE_STATUS             0xf4320174
#define GLOBAL_NETWORK_ENGINE_STATUS_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 l2fe_init_done       :  1 ; /* bits 0:0 */
    u32 l2tm_init_done       :  1 ; /* bits 1:1 */
    u32 tqm_init_done        :  1 ; /* bits 2:2 */
    u32 tqm_glb_idle         :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} GLOBAL_NETWORK_ENGINE_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_WOL_INTERRUPT                     0xf4320178
#define GLOBAL_WOL_INTERRUPT_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 PORT0_WOLi           :  1 ; /* bits 0:0 */
    u32 PORT1_WOLi           :  1 ; /* bits 1:1 */
    u32 PORT2_WOLi           :  1 ; /* bits 2:2 */
    u32 PORT3_WOLi           :  1 ; /* bits 3:3 */
    u32 PORT4_WOLi           :  1 ; /* bits 4:4 */
    u32 rsrvd1               : 27 ;
  } bf ;
  u32     wrd ;
} GLOBAL_WOL_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_WOL_INTENABLE                     0xf432017c
#define GLOBAL_WOL_INTENABLE_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 PORT0_WOLe           :  1 ; /* bits 0:0 */
    u32 PORT1_WOLe           :  1 ; /* bits 1:1 */
    u32 PORT2_WOLe           :  1 ; /* bits 2:2 */
    u32 PORT3_WOLe           :  1 ; /* bits 3:3 */
    u32 PORT4_WOLe           :  1 ; /* bits 4:4 */
    u32 rsrvd1               : 27 ;
  } bf ;
  u32     wrd ;
} GLOBAL_WOL_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PON_INTERRUPT_0                   0xf4320180
#define GLOBAL_PON_INTERRUPT_0_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 PON_MACi             :  1 ; /* bits 0:0 */
    u32 PON_CNTLi            :  1 ; /* bits 1:1 */
    u32 PTPi                 :  1 ; /* bits 2:2 */
    u32 OPTi                 :  1 ; /* bits 3:3 */
    u32 PSDS_PRBSi           :  1 ; /* bits 4:4 */
    u32 SGMII_PCSi           :  1 ; /* bits 5:5 */
    u32 QXGMIIi              :  1 ; /* bits 6:6 */
    u32 PSDSi                :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PON_INTERRUPT_0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PON_INTENABLE_0                   0xf4320184
#define GLOBAL_PON_INTENABLE_0_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 PON_MACe             :  1 ; /* bits 0:0 */
    u32 PON_CNTLe            :  1 ; /* bits 1:1 */
    u32 PTPe                 :  1 ; /* bits 2:2 */
    u32 OPTe                 :  1 ; /* bits 3:3 */
    u32 PSDS_PRBSe           :  1 ; /* bits 4:4 */
    u32 SGMII_PCSe           :  1 ; /* bits 5:5 */
    u32 QXGMIIe              :  1 ; /* bits 6:6 */
    u32 PSDSe                :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PON_INTENABLE_0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PON_INTERRUPT_1                   0xf4320188
#define GLOBAL_PON_INTERRUPT_1_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 PON_MACi             :  1 ; /* bits 0:0 */
    u32 PON_CNTLi            :  1 ; /* bits 1:1 */
    u32 PTPi                 :  1 ; /* bits 2:2 */
    u32 OPTi                 :  1 ; /* bits 3:3 */
    u32 PSDS_PRBSi           :  1 ; /* bits 4:4 */
    u32 SGMII_PCSi           :  1 ; /* bits 5:5 */
    u32 QXGMIIi              :  1 ; /* bits 6:6 */
    u32 PSDSi                :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PON_INTERRUPT_1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PON_INTENABLE_1                   0xf432018c
#define GLOBAL_PON_INTENABLE_1_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 PON_MACe             :  1 ; /* bits 0:0 */
    u32 PON_CNTLe            :  1 ; /* bits 1:1 */
    u32 PTPe                 :  1 ; /* bits 2:2 */
    u32 OPTe                 :  1 ; /* bits 3:3 */
    u32 PSDS_PRBSe           :  1 ; /* bits 4:4 */
    u32 SGMII_PCSe           :  1 ; /* bits 5:5 */
    u32 QXGMIIe              :  1 ; /* bits 6:6 */
    u32 PSDSe                :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PON_INTENABLE_1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_JTAG_TAP_CONTROL                  0xf4320190
#define GLOBAL_JTAG_TAP_CONTROL_dft              0x00000001

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 enable_arm           :  1 ; /* bits 0:0 */
    u32 enable_recirc_0      :  1 ; /* bits 1:1 */
    u32 enable_recirc_1      :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} GLOBAL_JTAG_TAP_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SOFTWARE                          0xf4320194
#define GLOBAL_SOFTWARE_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 val                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_SOFTWARE_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SOFTWARE2                         0xf4320198
#define GLOBAL_SOFTWARE2_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 val                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_SOFTWARE2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SCRATCH                           0xf432019c
#define GLOBAL_SCRATCH_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 scratch              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_SCRATCH_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_FMRO                              0xf43201a0
#define GLOBAL_FMRO_dft                          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 fmro_sel             : 16 ; /* bits 15:0 */
    u32 clk_sel              :  6 ; /* bits 21:16 */
    u32 blk_sel              :  6 ; /* bits 27:22 */
    u32 rot_sel              :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} GLOBAL_FMRO_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CRYPTO_CONFIG_0                   0xf43201a4
#define GLOBAL_CRYPTO_CONFIG_0_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 crypto0_rng_test_mode :  1 ; /* bits 0:0 */
    u32 crypto0_rng_test_tweak_mux :  2 ; /* bits 2:1 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CRYPTO_CONFIG_0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CRYPTO_CONFIG_1                   0xf43201a8
#define GLOBAL_CRYPTO_CONFIG_1_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 crypto1_rng_test_mode :  1 ; /* bits 0:0 */
    u32 crypto1_rng_test_tweak_mux :  2 ; /* bits 2:1 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CRYPTO_CONFIG_1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SPEED_OVERRIDE                    0xf43201ac
#define GLOBAL_SPEED_OVERRIDE_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 speed                :  3 ; /* bits 2:0 */
    u32 ov_enable            : 29 ; /* bits 31:3 */
  } bf ;
  u32     wrd ;
} GLOBAL_SPEED_OVERRIDE_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ARM_DEBUG                         0xf43201b0
#define GLOBAL_ARM_DEBUG_dft                     0x00bf000f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cpu_dbgen            :  1 ; /* bits 0:0 */
    u32 cpu_niden            :  1 ; /* bits 1:1 */
    u32 cpu_spiden           :  1 ; /* bits 2:2 */
    u32 cpu_spinden          :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 12 ;
    u32 auth_cssys_dbgen     :  1 ; /* bits 16:16 */
    u32 auth_cssys_niden     :  1 ; /* bits 17:17 */
    u32 cs_auth_niden        :  1 ; /* bits 18:18 */
    u32 cs_auth_spinden      :  1 ; /* bits 19:19 */
    u32 cfg_tpctl            :  1 ; /* bits 20:20 */
    u32 cfg_tpmaxdatasize    :  5 ; /* bits 25:21 */
    u32 rsrvd2               :  6 ;
  } bf ;
  u32     wrd ;
} GLOBAL_ARM_DEBUG_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_AXI_MUX_TEST                      0xf43201b4
#define GLOBAL_AXI_MUX_TEST_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 test_en              :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} GLOBAL_AXI_MUX_TEST_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_AXI_MUX_TEST_STATUS               0xf43201b8
#define GLOBAL_AXI_MUX_TEST_STATUS_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 result               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_AXI_MUX_TEST_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONTROL                       0xf43201bc
#define GLOBAL_LED_CONTROL_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 blink_rate_1         :  8 ; /* bits 7:0 */
    u32 blink_rate_2         :  8 ; /* bits 15:8 */
    u32 led_test             :  1 ; /* bits 16:16 */
    u32 led_clk_polarity     :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 12 ;
    u32 led_test_activity    :  2 ; /* bits 31:30 */
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_0                      0xf43201c0
#define GLOBAL_LED_CONFIG_0_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_1                      0xf43201c4
#define GLOBAL_LED_CONFIG_1_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_2                      0xf43201c8
#define GLOBAL_LED_CONFIG_2_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_3                      0xf43201cc
#define GLOBAL_LED_CONFIG_3_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_3_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_4                      0xf43201d0
#define GLOBAL_LED_CONFIG_4_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_4_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_5                      0xf43201d4
#define GLOBAL_LED_CONFIG_5_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_5_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_6                      0xf43201d8
#define GLOBAL_LED_CONFIG_6_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_6_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_7                      0xf43201dc
#define GLOBAL_LED_CONFIG_7_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_7_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_8                      0xf43201e0
#define GLOBAL_LED_CONFIG_8_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_8_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_9                      0xf43201e4
#define GLOBAL_LED_CONFIG_9_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_9_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_10                     0xf43201e8
#define GLOBAL_LED_CONFIG_10_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_10_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_11                     0xf43201ec
#define GLOBAL_LED_CONFIG_11_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_11_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_12                     0xf43201f0
#define GLOBAL_LED_CONFIG_12_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_12_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_13                     0xf43201f4
#define GLOBAL_LED_CONFIG_13_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_13_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_14                     0xf43201f8
#define GLOBAL_LED_CONFIG_14_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_14_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LED_CONFIG_15                     0xf43201fc
#define GLOBAL_LED_CONFIG_15_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 led_event_on         :  3 ; /* bits 2:0 */
    u32 led_event_blink      :  3 ; /* bits 5:3 */
    u32 led_event_off        :  3 ; /* bits 8:6 */
    u32 led_off_on           :  2 ; /* bits 10:9 */
    u32 led_port             :  3 ; /* bits 13:11 */
    u32 led_off_val          :  1 ; /* bits 14:14 */
    u32 led_sw_event         :  1 ; /* bits 15:15 */
    u32 led_blink_sel        :  1 ; /* bits 16:16 */
    u32 led_blink_or         :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LED_CONFIG_15_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CPLLDIV                           0xf4320200
#define GLOBAL_CPLLDIV_dft                       0x06210200

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cortex_divsel        :  6 ; /* bits 5:0 */
    u32 cpll_div_override    :  1 ; /* bits 6:6 */
    u32 f2c_divsel           :  4 ; /* bits 10:7 */
    u32 cf_sel               :  1 ; /* bits 11:11 */
    u32 trc_divsel           :  7 ; /* bits 18:12 */
    u32 cfg_pilcs_per_divsel :  6 ; /* bits 24:19 */
    u32 cfg_ext_vsfc_divsel  :  6 ; /* bits 30:25 */
    u32 cpll_mode_override   :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_CPLLDIV_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CPLLMUX                           0xf4320204
#define GLOBAL_CPLLMUX_dft                       0x00220000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               : 16 ;
    u32 cf_i0delay           :  4 ; /* bits 19:16 */
    u32 cf_i1delay           :  4 ; /* bits 23:20 */
    u32 cf_i0guard           :  4 ; /* bits 27:24 */
    u32 cf_i1guard           :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} GLOBAL_CPLLMUX_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_EPLLDIV                           0xf4320208
#define GLOBAL_EPLLDIV_dft                       0x14000c28

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dw_per_divsel        :  7 ; /* bits 6:0 */
    u32 rsrvd1               :  1 ;
    u32 core_divsel          :  7 ; /* bits 14:8 */
    u32 rsrvd2               :  1 ;
    u32 core_dynamic_en      :  1 ; /* bits 16:16 */
    u32 rsrvd3               :  7 ;
    u32 lsaxi_divsel         :  7 ; /* bits 30:24 */
    u32 rsrvd4               :  1 ;
  } bf ;
  u32     wrd ;
} GLOBAL_EPLLDIV_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_EPLLDIV2                          0xf432020c
#define GLOBAL_EPLLDIV2_dft                      0x00000a00

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  8 ;
    u32 cci_divsel           :  7 ; /* bits 14:8 */
    u32 rsrvd2               : 17 ;
  } bf ;
  u32     wrd ;
} GLOBAL_EPLLDIV2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PEDIV                             0xf4320210
#define GLOBAL_PEDIV_dft                         0x00040404

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 f_divsel             :  6 ; /* bits 5:0 */
    u32 offload_sel          :  1 ; /* bits 6:6 */
    u32 rsrvd1               :  1 ;
    u32 c2f_divsel           :  6 ; /* bits 13:8 */
    u32 rsrvd2               :  2 ;
    u32 peaxi_divsel         :  6 ; /* bits 21:16 */
    u32 peaxi_fullspeedsel   :  1 ; /* bits 22:22 */
    u32 rsrvd3               :  9 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PEDIV_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PEMUX                             0xf4320214
#define GLOBAL_PEMUX_dft                         0x00220000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               : 16 ;
    u32 offload_i0delay      :  4 ; /* bits 19:16 */
    u32 offload_i1delay      :  4 ; /* bits 23:20 */
    u32 offload_i0guard      :  4 ; /* bits 27:24 */
    u32 offload_i1guard      :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} GLOBAL_PEMUX_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SECURITY_OVERRIDE                 0xf4320218
#define GLOBAL_SECURITY_OVERRIDE_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 secure_override_ne   :  1 ; /* bits 0:0 */
    u32 secure_override_per  :  1 ; /* bits 1:1 */
    u32 secure_override_wrap_gphy :  1 ; /* bits 2:2 */
    u32 secure_override_dma  :  1 ; /* bits 3:3 */
    u32 secure_override_ldma :  1 ; /* bits 4:4 */
    u32 secure_override_flash :  1 ; /* bits 5:5 */
    u32 secure_override_pcie0 :  1 ; /* bits 6:6 */
    u32 secure_override_pcie1 :  1 ; /* bits 7:7 */
    u32 secure_override_pcie2 :  1 ; /* bits 8:8 */
    u32 secure_override_ccireg :  1 ; /* bits 9:9 */
    u32 secure_override_capsram :  1 ; /* bits 10:10 */
    u32 secure_override_ddr  :  1 ; /* bits 11:11 */
    u32 secure_override_sadb :  1 ; /* bits 12:12 */
    u32 secure_override_usb  :  1 ; /* bits 13:13 */
    u32 secure_override_pon  :  1 ; /* bits 14:14 */
    u32 secure_override_otprom :  1 ; /* bits 15:15 */
    u32 secure_override_peatu :  1 ; /* bits 16:16 */
    u32 secure_override_hsioatu :  1 ; /* bits 17:17 */
    u32 otp_lock_prot_fields :  1 ; /* bits 18:18 */
    u32 secure_override_global :  1 ; /* bits 19:19 */
    u32 secure_override_dma_reo :  1 ; /* bits 20:20 */
    u32 secure_override_pemisc :  1 ; /* bits 21:21 */
    u32 secure_override_qxgmii :  1 ; /* bits 22:22 */
    u32 secure_override_efuse_otp :  1 ; /* bits 23:23 */
    u32 secure_override_otp_mem :  1 ; /* bits 24:24 */
    u32 rsrvd1               :  7 ;
  } bf ;
  u32     wrd ;
} GLOBAL_SECURITY_OVERRIDE_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_MASTER_OVERRIDE_SECURITY          0xf432021c
#define GLOBAL_MASTER_OVERRIDE_SECURITY_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 master_secure_override_ne :  1 ; /* bits 0:0 */
    u32 master_secure_override_dma :  1 ; /* bits 1:1 */
    u32 master_secure_override_ldma :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} GLOBAL_MASTER_OVERRIDE_SECURITY_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PE_ISO_MODE                       0xf4320220
#define GLOBAL_PE_ISO_MODE_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 pe_iso_mode          :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PE_ISO_MODE_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ROMOTP_SLV_ID                     0xf4320224
#define GLOBAL_ROMOTP_SLV_ID_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 reg_id_entry0        :  6 ; /* bits 5:0 */
    u32 reg_id_entry1        :  6 ; /* bits 11:6 */
    u32 reg_id_entry2        :  6 ; /* bits 17:12 */
    u32 reg_id_entry3        :  6 ; /* bits 23:18 */
    u32 reg_id_en0           :  1 ; /* bits 24:24 */
    u32 reg_id_en1           :  1 ; /* bits 25:25 */
    u32 reg_id_en2           :  1 ; /* bits 26:26 */
    u32 reg_id_en3           :  1 ; /* bits 27:27 */
    u32 reg_enabled          :  1 ; /* bits 28:28 */
    u32 rom_enabled          :  1 ; /* bits 29:29 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} GLOBAL_ROMOTP_SLV_ID_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_ROMOTP_SLV_ID_MASK                0xf4320228
#define GLOBAL_ROMOTP_SLV_ID_MASK_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 reg_id_entry_mask0   :  6 ; /* bits 5:0 */
    u32 reg_id_entry_mask1   :  6 ; /* bits 11:6 */
    u32 reg_id_entry_mask2   :  6 ; /* bits 17:12 */
    u32 reg_id_entry_mask3   :  6 ; /* bits 23:18 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} GLOBAL_ROMOTP_SLV_ID_MASK_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PSDS_INIT_CNTL                    0xf432022c
#define GLOBAL_PSDS_INIT_CNTL_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  4 ;
    u32 ben_oen              :  1 ; /* bits 4:4 */
    u32 POW_PCIX             :  1 ; /* bits 5:5 */
    u32 rsrvd2               : 26 ;
  } bf ;
  u32     wrd ;
} GLOBAL_PSDS_INIT_CNTL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CPLL0                             0xf4320230
#define GLOBAL_CPLL0_dft                         0x00003fed

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 SCPU_DIV_DIVN        :  8 ; /* bits 7:0 */
    u32 SCPU_POW             :  2 ; /* bits 9:8 */
    u32 SCPU_RSTB            :  2 ; /* bits 11:10 */
    u32 DIV_PREDIV_SEL       :  2 ; /* bits 13:12 */
    u32 DIV_PREDIV_BPS       :  1 ; /* bits 14:14 */
    u32 rsrvd1               : 17 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CPLL0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CPLL1                             0xf4320234
#define GLOBAL_CPLL1_dft                         0x000c025f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ICP                  :  3 ; /* bits 2:0 */
    u32 LPF_CS               :  2 ; /* bits 4:3 */
    u32 LPF_RS               :  3 ; /* bits 7:5 */
    u32 SCPU_DBUG_EN         :  1 ; /* bits 8:8 */
    u32 SEL_CCO              :  1 ; /* bits 9:9 */
    u32 WD_RST               :  2 ; /* bits 11:10 */
    u32 WD_SET               :  2 ; /* bits 13:12 */
    u32 OEB                  :  2 ; /* bits 15:14 */
    u32 TESTSEL              :  1 ; /* bits 16:16 */
    u32 LDO10V_SEL           :  2 ; /* bits 18:17 */
    u32 LDO18V_SEL           :  2 ; /* bits 20:19 */
    u32 rsrvd1               : 11 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CPLL1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_EPLL0                             0xf4320238
#define GLOBAL_EPLL0_dft                         0x00000f9d

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 SCPU_DIV_DIVN        :  8 ; /* bits 7:0 */
    u32 SCPU_POW             :  2 ; /* bits 9:8 */
    u32 SCPU_RSTB            :  2 ; /* bits 11:10 */
    u32 DIV_PREDIV_SEL       :  2 ; /* bits 13:12 */
    u32 DIV_PREDIV_BPS       :  1 ; /* bits 14:14 */
    u32 rsrvd1               : 17 ;
  } bf ;
  u32     wrd ;
} GLOBAL_EPLL0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_EPLL1                             0xf432023c
#define GLOBAL_EPLL1_dft                         0x000a025f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ICP                  :  3 ; /* bits 2:0 */
    u32 LPF_CS               :  2 ; /* bits 4:3 */
    u32 LPF_RS               :  3 ; /* bits 7:5 */
    u32 SCPU_DBUG_EN         :  1 ; /* bits 8:8 */
    u32 SEL_CCO              :  1 ; /* bits 9:9 */
    u32 WD_RST               :  2 ; /* bits 11:10 */
    u32 WD_SET               :  2 ; /* bits 13:12 */
    u32 OEB                  :  2 ; /* bits 15:14 */
    u32 TESTSEL              :  1 ; /* bits 16:16 */
    u32 LDO10V_SEL           :  2 ; /* bits 18:17 */
    u32 LDO18V_SEL           :  2 ; /* bits 20:19 */
    u32 rsrvd1               : 11 ;
  } bf ;
  u32     wrd ;
} GLOBAL_EPLL1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_FPLL0                             0xf4320240
#define GLOBAL_FPLL0_dft                         0x00001fbd

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 SCPU_DIV_DIVN        :  8 ; /* bits 7:0 */
    u32 SCPU_POW             :  2 ; /* bits 9:8 */
    u32 SCPU_RSTB            :  2 ; /* bits 11:10 */
    u32 DIV_PREDIV_SEL       :  2 ; /* bits 13:12 */
    u32 DIV_PREDIV_BPS       :  1 ; /* bits 14:14 */
    u32 rsrvd1               : 17 ;
  } bf ;
  u32     wrd ;
} GLOBAL_FPLL0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_FPLL1                             0xf4320244
#define GLOBAL_FPLL1_dft                         0x000a025f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ICP                  :  3 ; /* bits 2:0 */
    u32 LPF_CS               :  2 ; /* bits 4:3 */
    u32 LPF_RS               :  3 ; /* bits 7:5 */
    u32 SCPU_DBUG_EN         :  1 ; /* bits 8:8 */
    u32 SEL_CCO              :  1 ; /* bits 9:9 */
    u32 WD_RST               :  2 ; /* bits 11:10 */
    u32 WD_SET               :  2 ; /* bits 13:12 */
    u32 OEB                  :  2 ; /* bits 15:14 */
    u32 TESTSEL              :  1 ; /* bits 16:16 */
    u32 LDO10V_SEL           :  2 ; /* bits 18:17 */
    u32 LDO18V_SEL           :  2 ; /* bits 20:19 */
    u32 rsrvd1               : 11 ;
  } bf ;
  u32     wrd ;
} GLOBAL_FPLL1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BOOT_VEC_0                        0xf4320248
#define GLOBAL_BOOT_VEC_0_dft                    0x17ff4000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 global_boot_0        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BOOT_VEC_0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BOOT_VEC_4                        0xf432024c
#define GLOBAL_BOOT_VEC_4_dft                    0xd503201f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 global_boot_4        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BOOT_VEC_4_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BOOT_VEC_8                        0xf4320250
#define GLOBAL_BOOT_VEC_8_dft                    0xd503201f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 global_boot_8        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BOOT_VEC_8_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_BOOT_VEC_C                        0xf4320254
#define GLOBAL_BOOT_VEC_C_dft                    0xd503201f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 global_boot_c        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_BOOT_VEC_C_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PTP_CFG                           0xf4320258
#define GLOBAL_PTP_CFG_dft                       0x80000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               : 31 ;
    u32 div_8                :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_PTP_CFG_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PTP_PHASE_VAL                     0xf432025c
#define GLOBAL_PTP_PHASE_VAL_dft                 0x40000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_PTP_PHASE_VAL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PTP_PERIOD_ERR                    0xf4320260
#define GLOBAL_PTP_PERIOD_ERR_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 data                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_PTP_PERIOD_ERR_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_TMS_REG_A                         0xf4320264
#define GLOBAL_TMS_REG_A_dft                     0x086d6b85

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 reg_a                : 29 ; /* bits 28:0 */
    u32 rsrvd1               :  3 ;
  } bf ;
  u32     wrd ;
} GLOBAL_TMS_REG_A_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_TMS_REG_B                         0xf4320268
#define GLOBAL_TMS_REG_B_dft                     0x0036f2cd

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 reg_b                : 22 ; /* bits 21:0 */
    u32 rsrvd1               : 10 ;
  } bf ;
  u32     wrd ;
} GLOBAL_TMS_REG_B_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_TMS_REG_C                         0xf432026c
#define GLOBAL_TMS_REG_C_dft                     0x2101012c

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rstb                 :  1 ; /* bits 0:0 */
    u32 adccksel             :  1 ; /* bits 1:1 */
    u32 biasdem_en           :  1 ; /* bits 2:2 */
    u32 ppow                 :  1 ; /* bits 3:3 */
    u32 chopen               :  1 ; /* bits 4:4 */
    u32 en_latch             :  1 ; /* bits 5:5 */
    u32 rsrvd1               :  2 ;
    u32 hold_dly             :  2 ; /* bits 9:8 */
    u32 hold_en              :  1 ; /* bits 10:10 */
    u32 rsrvd2               :  5 ;
    u32 osr                  :  3 ; /* bits 18:16 */
    u32 rsrvd3               :  5 ;
    u32 chopfreqsel          :  4 ; /* bits 27:24 */
    u32 ctmk_inv_sel         :  1 ; /* bits 28:28 */
    u32 powct                :  1 ; /* bits 29:29 */
    u32 rsrvd4               :  2 ;
  } bf ;
  u32     wrd ;
} GLOBAL_TMS_REG_C_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_TMS_TEMP_DATA                     0xf4320270
#define GLOBAL_TMS_TEMP_DATA_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tm_out               : 19 ; /* bits 18:0 */
    u32 rsrvd1               : 13 ;
  } bf ;
  u32     wrd ;
} GLOBAL_TMS_TEMP_DATA_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_TMS_ADC_DATA                      0xf4320274
#define GLOBAL_TMS_ADC_DATA_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 adc_out              : 22 ; /* bits 21:0 */
    u32 rsrvd1               : 10 ;
  } bf ;
  u32     wrd ;
} GLOBAL_TMS_ADC_DATA_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_CONTROL_GAINN                0xf4320278
#define GLOBAL_UVLO_CONTROL_GAINN_dft            0x00842108

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_uvlo_reg_gainn  : 25 ; /* bits 24:0 */
    u32 rsrvd1               :  7 ;
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_CONTROL_GAINN_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_CONTROL_GAINP                0xf432027c
#define GLOBAL_UVLO_CONTROL_GAINP_dft            0x01084210

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_uvlo_reg_gainp  : 25 ; /* bits 24:0 */
    u32 ca55_uvlo_reg_pow    :  5 ; /* bits 29:25 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_CONTROL_GAINP_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_CONTROL                      0xf4320280
#define GLOBAL_UVLO_CONTROL_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 glb_en               :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  3 ;
    u32 div_sel              :  1 ; /* bits 4:4 */
    u32 rsrvd2               :  3 ;
    u32 trig_sel             :  3 ; /* bits 10:8 */
    u32 rsrvd3               :  1 ;
    u32 uvlo_deg_filter      :  3 ; /* bits 14:12 */
    u32 rsrvd4               :  1 ;
    u32 fss_deg_filter       :  3 ; /* bits 18:16 */
    u32 rsrvd5               :  1 ;
    u32 cpu_deg_filter       :  3 ; /* bits 22:20 */
    u32 fss_detect_out       :  5 ; /* bits 27:23 */
    u32 rsrvd6               :  4 ;
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_TRIG_CONTROL                 0xf4320284
#define GLOBAL_UVLO_TRIG_CONTROL_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 uvlo_min             :  3 ; /* bits 2:0 */
    u32 rsrvd1               :  1 ;
    u32 fss_min              :  3 ; /* bits 6:4 */
    u32 rsrvd2               :  1 ;
    u32 core_min             :  2 ; /* bits 9:8 */
    u32 rsrvd3               :  6 ;
    u32 core_idle_div_en     :  1 ; /* bits 16:16 */
    u32 fss_deg_filter_h2l   :  3 ; /* bits 19:17 */
    u32 uvlo_deg_filter_h2l  :  3 ; /* bits 22:20 */
    u32 rsrvd4               :  9 ;
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_TRIG_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_RECV_CTRL0                   0xf4320288
#define GLOBAL_UVLO_RECV_CTRL0_dft               0x00000001

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 det_recv_sel         :  2 ; /* bits 1:0 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_RECV_CTRL0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_RECV_CTRL1                   0xf432028c
#define GLOBAL_UVLO_RECV_CTRL1_dft               0x00000010

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cycle_lowf           : 16 ; /* bits 15:0 */
    u32 lowf                 : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_RECV_CTRL1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_RECV_CTRL2                   0xf4320290
#define GLOBAL_UVLO_RECV_CTRL2_dft               0x00000010

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cycle_recv1          : 16 ; /* bits 15:0 */
    u32 recv1                : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_RECV_CTRL2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_RECV_CTRL3                   0xf4320294
#define GLOBAL_UVLO_RECV_CTRL3_dft               0x00000010

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cycle_recv2          : 16 ; /* bits 15:0 */
    u32 recv2                : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_RECV_CTRL3_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_RECV_CTRL4                   0xf4320298
#define GLOBAL_UVLO_RECV_CTRL4_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 recv1_sw             : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_RECV_CTRL4_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_PROF_INTST                   0xf432029c
#define GLOBAL_UVLO_PROF_INTST_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  1 ;
    u32 prof_intst           :  1 ; /* bits 1:1 */
    u32 sw_recv_intst        :  1 ; /* bits 2:2 */
    u32 rsrvd2               : 29 ;
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_PROF_INTST_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_PROF_INTEN                   0xf43202a0
#define GLOBAL_UVLO_PROF_INTEN_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  1 ;
    u32 prof_inten           :  1 ; /* bits 1:1 */
    u32 sw_recv_inten        :  1 ; /* bits 2:2 */
    u32 rsrvd2               : 29 ;
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_PROF_INTEN_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_VSFC_STATUS                       0xf43202a4
#define GLOBAL_VSFC_STATUS_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 idle_st              :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  3 ;
    u32 fss_detect_out       :  5 ; /* bits 8:4 */
    u32 rsrvd2               :  3 ;
    u32 uvlo_detect_out      :  5 ; /* bits 16:12 */
    u32 rsrvd3               : 15 ;
  } bf ;
  u32     wrd ;
} GLOBAL_VSFC_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_PORF_ST0                     0xf43202a8
#define GLOBAL_UVLO_PORF_ST0_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 trig_cnt             : 12 ; /* bits 11:0 */
    u32 rsrvd1               : 19 ;
    u32 ovfl_trig            :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_PORF_ST0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_PORF_ST1                     0xf43202ac
#define GLOBAL_UVLO_PORF_ST1_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 max_duration         : 16 ; /* bits 15:0 */
    u32 min_duration         : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_PORF_ST1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_PORF_ST2                     0xf43202b0
#define GLOBAL_UVLO_PORF_ST2_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ovfl_duration        :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_PORF_ST2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_PORF_ST3                     0xf43202b4
#define GLOBAL_UVLO_PORF_ST3_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 all_idle_cnt         : 12 ; /* bits 11:0 */
    u32 rsrvd1               :  3 ;
    u32 ovfl_all_idle        :  1 ; /* bits 15:15 */
    u32 wakeup_cnt           : 12 ; /* bits 27:16 */
    u32 rsrvd2               :  3 ;
    u32 ovfl_wakeup          :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_PORF_ST3_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_SW_RECV                      0xf43202b8
#define GLOBAL_UVLO_SW_RECV_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sw_recv_finish       :  1 ; /* bits 0:0 */
    u32 recv_st              :  1 ; /* bits 1:1 */
    u32 sw_recv_en           :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 13 ;
    u32 recv_cycle_cnt       : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_SW_RECV_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_PROF_CTRL0                   0xf43202bc
#define GLOBAL_UVLO_PROF_CTRL0_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cycle_prof           : 20 ; /* bits 19:0 */
    u32 rsrvd1               : 10 ;
    u32 prof_fin_sel         :  1 ; /* bits 30:30 */
    u32 prof_en              :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_PROF_CTRL0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_UVLO_PROF_CTRL1                   0xf43202c0
#define GLOBAL_UVLO_PROF_CTRL1_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cnt_2nd_droop        : 12 ; /* bits 11:0 */
    u32 rsrvd1               :  3 ;
    u32 ovfl_2nd_droop       :  1 ; /* bits 15:15 */
    u32 rsrvd2               : 16 ;
  } bf ;
  u32     wrd ;
} GLOBAL_UVLO_PROF_CTRL1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_ARM_SRAM_A                   0xf43202c4
#define GLOBAL_CA55_ARM_SRAM_A_dft               0x06db06db

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_ema_tlb_tag     : 12 ; /* bits 11:0 */
    u32 rsrvd1               :  4 ;
    u32 ca55_ema_tlb_data    : 12 ; /* bits 27:16 */
    u32 rsrvd2               :  4 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_ARM_SRAM_A_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_ARM_SRAM_B                   0xf43202c8
#define GLOBAL_CA55_ARM_SRAM_B_dft               0x06db06db

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_ema_idata       : 12 ; /* bits 11:0 */
    u32 rsrvd1               :  4 ;
    u32 ca55_ema_itag        : 12 ; /* bits 27:16 */
    u32 rsrvd2               :  4 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_ARM_SRAM_B_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_ARM_SRAM_C                   0xf43202cc
#define GLOBAL_CA55_ARM_SRAM_C_dft               0x06db06db

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_ema_btac0       : 12 ; /* bits 11:0 */
    u32 rsrvd1               :  4 ;
    u32 ca55_ema_btac1       : 12 ; /* bits 27:16 */
    u32 rsrvd2               :  4 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_ARM_SRAM_C_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_ARM_SRAM_D                   0xf43202d0
#define GLOBAL_CA55_ARM_SRAM_D_dft               0x06db06db

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_ema_ddata       : 12 ; /* bits 11:0 */
    u32 rsrvd1               :  4 ;
    u32 ca55_ema_dtag        : 12 ; /* bits 27:16 */
    u32 rsrvd2               :  4 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_ARM_SRAM_D_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_ARM_SRAM_E                   0xf43202d4
#define GLOBAL_CA55_ARM_SRAM_E_dft               0x024906db

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_ema_ddirty      : 12 ; /* bits 11:0 */
    u32 rsrvd1               :  4 ;
    u32 ca55_emaa_l2_db      : 12 ; /* bits 27:16 */
    u32 rsrvd2               :  4 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_ARM_SRAM_E_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_ARM_SRAM_F                   0xf43202d8
#define GLOBAL_CA55_ARM_SRAM_F_dft               0x1b6d1492

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_emab_l2_db      : 12 ; /* bits 11:0 */
    u32 ca55_emaa_scu_ltdb   :  3 ; /* bits 14:12 */
    u32 ca55_emab_scu_ltdb   :  3 ; /* bits 17:15 */
    u32 ca55_ema_scu_sf      :  3 ; /* bits 20:18 */
    u32 ca55_ema_l3_tag      :  3 ; /* bits 23:21 */
    u32 ca55_ema_l3_vic      :  3 ; /* bits 26:24 */
    u32 ca55_ema_l3_data     :  3 ; /* bits 29:27 */
    u32 rsrvd1               :  2 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_ARM_SRAM_F_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_ARM_SRAM_G                   0xf43202dc
#define GLOBAL_CA55_ARM_SRAM_G_dft               0x55005555

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_emaw_tlb_tag    :  8 ; /* bits 7:0 */
    u32 ca55_emaw_tlb_data   :  8 ; /* bits 15:8 */
    u32 ca55_emaw_idata      :  8 ; /* bits 23:16 */
    u32 ca55_emaw_itag       :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_ARM_SRAM_G_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_ARM_SRAM_H                   0xf43202e0
#define GLOBAL_CA55_ARM_SRAM_H_dft               0x55005555

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_emaw_btac0      :  8 ; /* bits 7:0 */
    u32 ca55_emaw_btac1      :  8 ; /* bits 15:8 */
    u32 ca55_emaw_ddata      :  8 ; /* bits 23:16 */
    u32 ca55_emaw_dtag       :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_ARM_SRAM_H_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_ARM_SRAM_I                   0xf43202e4
#define GLOBAL_CA55_ARM_SRAM_I_dft               0x00000455

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_emaw_ddirty     :  8 ; /* bits 7:0 */
    u32 ca55_emaw_scu_sf     :  2 ; /* bits 9:8 */
    u32 ca55_emaw_l3_tag     :  2 ; /* bits 11:10 */
    u32 ca55_emaw_l3_vic     :  2 ; /* bits 13:12 */
    u32 ca55_emaw_l3_data    :  2 ; /* bits 15:14 */
    u32 ca55_emas_tlb_tag    :  4 ; /* bits 19:16 */
    u32 ca55_emas_tlb_data   :  4 ; /* bits 23:20 */
    u32 ca55_emas_idata      :  4 ; /* bits 27:24 */
    u32 ca55_emas_itag       :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_ARM_SRAM_I_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_ARM_SRAM_J                   0xf43202e8
#define GLOBAL_CA55_ARM_SRAM_J_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_emas_btac0      :  4 ; /* bits 3:0 */
    u32 ca55_emas_btac1      :  4 ; /* bits 7:4 */
    u32 ca55_emas_ddata      :  4 ; /* bits 11:8 */
    u32 ca55_emas_dtag       :  4 ; /* bits 15:12 */
    u32 ca55_emas_ddirty     :  4 ; /* bits 19:16 */
    u32 ca55_emas_scu_sf     :  1 ; /* bits 20:20 */
    u32 ca55_emas_l3_tag     :  1 ; /* bits 21:21 */
    u32 ca55_emas_l3_vic     :  1 ; /* bits 22:22 */
    u32 ca55_emas_l3_data    :  1 ; /* bits 23:23 */
    u32 ca55_emasa_l2_db     :  4 ; /* bits 27:24 */
    u32 ca55_emasa_scu_ltdb  :  1 ; /* bits 28:28 */
    u32 rsrvd1               :  3 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_ARM_SRAM_J_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_ARM_SRAM_K                   0xf43202ec
#define GLOBAL_CA55_ARM_SRAM_K_dft               0x1ff00000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ca55_stov_idata      :  4 ; /* bits 3:0 */
    u32 ca55_stov_ddata      :  4 ; /* bits 7:4 */
    u32 ca55_stov_l2_db      :  4 ; /* bits 11:8 */
    u32 ca55_stov_scu_ltdb   :  1 ; /* bits 12:12 */
    u32 ca55_stov_scu_sf     :  1 ; /* bits 13:13 */
    u32 ca55_stov_l3_vic     :  1 ; /* bits 14:14 */
    u32 ca55_stov_l3_data    :  1 ; /* bits 15:15 */
    u32 ca55_pgen            :  4 ; /* bits 19:16 */
    u32 ca55_ret1n           :  5 ; /* bits 24:20 */
    u32 ca55_ret2n           :  4 ; /* bits 28:25 */
    u32 rsrvd1               :  3 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_ARM_SRAM_K_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_TOP_DSS30_CTRL               0xf43202f0
#define GLOBAL_CA55_TOP_DSS30_CTRL_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rst_n                :  1 ; /* bits 0:0 */
    u32 ro_sel               :  3 ; /* bits 3:1 */
    u32 wire_sel             :  1 ; /* bits 4:4 */
    u32 data_in              : 20 ; /* bits 24:5 */
    u32 speed_en             :  1 ; /* bits 25:25 */
    u32 rsrvd1               :  6 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_TOP_DSS30_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_TOP_DSS30_STS                0xf43202f4
#define GLOBAL_CA55_TOP_DSS30_STS_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ready                :  1 ; /* bits 0:0 */
    u32 count_out            : 20 ; /* bits 20:1 */
    u32 wsort_go             :  1 ; /* bits 21:21 */
    u32 rsrvd1               : 10 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_TOP_DSS30_STS_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_TOP_DSS35_CTRL               0xf43202f8
#define GLOBAL_CA55_TOP_DSS35_CTRL_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rst_n                :  1 ; /* bits 0:0 */
    u32 ro_sel               :  3 ; /* bits 3:1 */
    u32 wire_sel             :  1 ; /* bits 4:4 */
    u32 data_in              : 20 ; /* bits 24:5 */
    u32 speed_en             :  1 ; /* bits 25:25 */
    u32 rsrvd1               :  6 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_TOP_DSS35_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_TOP_DSS35_STS                0xf43202fc
#define GLOBAL_CA55_TOP_DSS35_STS_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ready                :  1 ; /* bits 0:0 */
    u32 count_out            : 20 ; /* bits 20:1 */
    u32 wsort_go             :  1 ; /* bits 21:21 */
    u32 rsrvd1               : 10 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_TOP_DSS35_STS_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_TOP_DSS40_CTRL               0xf4320300
#define GLOBAL_CA55_TOP_DSS40_CTRL_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rst_n                :  1 ; /* bits 0:0 */
    u32 ro_sel               :  3 ; /* bits 3:1 */
    u32 wire_sel             :  1 ; /* bits 4:4 */
    u32 data_in              : 20 ; /* bits 24:5 */
    u32 speed_en             :  1 ; /* bits 25:25 */
    u32 rsrvd1               :  6 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_TOP_DSS40_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_TOP_DSS40_STS                0xf4320304
#define GLOBAL_CA55_TOP_DSS40_STS_dft            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ready                :  1 ; /* bits 0:0 */
    u32 count_out            : 20 ; /* bits 20:1 */
    u32 wsort_go             :  1 ; /* bits 21:21 */
    u32 rsrvd1               : 10 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_TOP_DSS40_STS_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_FSS_CTRL0                    0xf4320308
#define GLOBAL_CA55_FSS_CTRL0_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rst_n                :  4 ; /* bits 3:0 */
    u32 sensor_en            :  4 ; /* bits 7:4 */
    u32 path_sel             :  8 ; /* bits 15:8 */
    u32 fall_edge_sel        :  4 ; /* bits 19:16 */
    u32 cal_en               :  4 ; /* bits 23:20 */
    u32 cal_2nd_en           :  4 ; /* bits 27:24 */
    u32 rsrvd1               :  4 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_FSS_CTRL0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_FSS_CTRL1                    0xf432030c
#define GLOBAL_CA55_FSS_CTRL1_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 config_cdl0          : 16 ; /* bits 15:0 */
    u32 config_cdl1          : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_FSS_CTRL1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_FSS_CTRL2                    0xf4320310
#define GLOBAL_CA55_FSS_CTRL2_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 config_cdl2          : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_FSS_CTRL2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_FSS_STS0                     0xf4320314
#define GLOBAL_CA55_FSS_STS0_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cal_cdl0             : 16 ; /* bits 15:0 */
    u32 cal_cdl1             : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_FSS_STS0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_FSS_STS1                     0xf4320318
#define GLOBAL_CA55_FSS_STS1_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cal_done             :  4 ; /* bits 3:0 */
    u32 cal_min_cdl1         : 16 ; /* bits 19:4 */
    u32 detect_out           :  4 ; /* bits 23:20 */
    u32 detector_1           :  4 ; /* bits 27:24 */
    u32 detector_2           :  4 ; /* bits 31:28 */
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_FSS_STS1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_TOP_FSS_CTRL                 0xf432031c
#define GLOBAL_CA55_TOP_FSS_CTRL_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rst_n                :  1 ; /* bits 0:0 */
    u32 sensor_en            :  1 ; /* bits 1:1 */
    u32 path_sel             :  2 ; /* bits 3:2 */
    u32 fall_edge_sel        :  1 ; /* bits 4:4 */
    u32 critical_path_in     :  1 ; /* bits 5:5 */
    u32 cal_en               :  1 ; /* bits 6:6 */
    u32 cal_2nd_en           :  1 ; /* bits 7:7 */
    u32 config_cdl0          :  4 ; /* bits 11:8 */
    u32 config_cdl1          :  4 ; /* bits 15:12 */
    u32 config_cdl2          :  4 ; /* bits 19:16 */
    u32 rsrvd1               : 12 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_TOP_FSS_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CA55_TOP_FSS_STS                  0xf4320320
#define GLOBAL_CA55_TOP_FSS_STS_dft              0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 detector_1           :  1 ; /* bits 0:0 */
    u32 detector_2           :  1 ; /* bits 1:1 */
    u32 detect_out           :  1 ; /* bits 2:2 */
    u32 cal_cdl0             :  4 ; /* bits 6:3 */
    u32 cal_cdl1             :  4 ; /* bits 10:7 */
    u32 cal_min_cdl1         :  4 ; /* bits 14:11 */
    u32 cal_done             :  1 ; /* bits 15:15 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} GLOBAL_CA55_TOP_FSS_STS_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SD_RM                             0xf4320324
#define GLOBAL_SD_RM_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sd_sramtest          : 12 ; /* bits 11:0 */
    u32 sd_sramls            :  2 ; /* bits 13:12 */
    u32 epon_sramls          :  1 ; /* bits 14:14 */
    u32 gpn_sramls           :  1 ; /* bits 15:15 */
    u32 xgpn_sramls          :  1 ; /* bits 16:16 */
    u32 puc_sramls           :  1 ; /* bits 17:17 */
    u32 rsrvd1               : 14 ;
  } bf ;
  u32     wrd ;
} GLOBAL_SD_RM_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_USB2_OTG_RM                       0xf4320328
#define GLOBAL_USB2_OTG_RM_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 usb2_otg_sramtest    :  6 ; /* bits 5:0 */
    u32 usb2_otg_sramls      :  1 ; /* bits 6:6 */
    u32 rsrvd1               : 25 ;
  } bf ;
  u32     wrd ;
} GLOBAL_USB2_OTG_RM_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_USB3_RM                           0xf432032c
#define GLOBAL_USB3_RM_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 usb3_sramtest        : 21 ; /* bits 20:0 */
    u32 usb3_sramls          :  3 ; /* bits 23:21 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} GLOBAL_USB3_RM_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_DSS_0_CNTL                        0xf4320330
#define GLOBAL_DSS_0_CNTL_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dss_rst_n            :  1 ; /* bits 0:0 */
    u32 ro_sel               :  3 ; /* bits 3:1 */
    u32 wire_sel             :  1 ; /* bits 4:4 */
    u32 data_in              : 20 ; /* bits 24:5 */
    u32 speed_en             :  1 ; /* bits 25:25 */
    u32 rsrvd1               :  6 ;
  } bf ;
  u32     wrd ;
} GLOBAL_DSS_0_CNTL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_DSS_0_STATUS                      0xf4320334
#define GLOBAL_DSS_0_STATUS_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ready                :  1 ; /* bits 0:0 */
    u32 count_out            : 20 ; /* bits 20:1 */
    u32 wsort_go             :  1 ; /* bits 21:21 */
    u32 rsrvd1               : 10 ;
  } bf ;
  u32     wrd ;
} GLOBAL_DSS_0_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_DSS_1_CNTL                        0xf4320338
#define GLOBAL_DSS_1_CNTL_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dss_rst_n            :  1 ; /* bits 0:0 */
    u32 ro_sel               :  3 ; /* bits 3:1 */
    u32 wire_sel             :  1 ; /* bits 4:4 */
    u32 data_in              : 20 ; /* bits 24:5 */
    u32 speed_en             :  1 ; /* bits 25:25 */
    u32 rsrvd1               :  6 ;
  } bf ;
  u32     wrd ;
} GLOBAL_DSS_1_CNTL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_DSS_1_STATUS                      0xf432033c
#define GLOBAL_DSS_1_STATUS_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ready                :  1 ; /* bits 0:0 */
    u32 count_out            : 20 ; /* bits 20:1 */
    u32 wsort_go             :  1 ; /* bits 21:21 */
    u32 rsrvd1               : 10 ;
  } bf ;
  u32     wrd ;
} GLOBAL_DSS_1_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_DSS_2_CNTL                        0xf4320340
#define GLOBAL_DSS_2_CNTL_dft                    0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dss_rst_n            :  1 ; /* bits 0:0 */
    u32 ro_sel               :  3 ; /* bits 3:1 */
    u32 wire_sel             :  1 ; /* bits 4:4 */
    u32 data_in              : 20 ; /* bits 24:5 */
    u32 speed_en             :  1 ; /* bits 25:25 */
    u32 rsrvd1               :  6 ;
  } bf ;
  u32     wrd ;
} GLOBAL_DSS_2_CNTL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_DSS_2_STATUS                      0xf4320344
#define GLOBAL_DSS_2_STATUS_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ready                :  1 ; /* bits 0:0 */
    u32 count_out            : 20 ; /* bits 20:1 */
    u32 wsort_go             :  1 ; /* bits 21:21 */
    u32 rsrvd1               : 10 ;
  } bf ;
  u32     wrd ;
} GLOBAL_DSS_2_STATUS_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_DEVICE_ASSIGN_ID1                 0xf4320348
#define GLOBAL_DEVICE_ASSIGN_ID1_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 device_id1           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_DEVICE_ASSIGN_ID1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_DEVICE_ASSIGN_ID0                 0xf432034c
#define GLOBAL_DEVICE_ASSIGN_ID0_dft             0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 device_id0           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_DEVICE_ASSIGN_ID0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SD_PLL_0                          0xf4320350
#define GLOBAL_SD_PLL_0_dft                      0x003e0003

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sd30_sscpll_ctrl0    : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_SD_PLL_0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SD_PLL_1                          0xf4320354
#define GLOBAL_SD_PLL_1_dft                      0x1eb9706c

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sd30_sscpll_ctrl1    : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_SD_PLL_1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SD_PLL_2                          0xf4320358
#define GLOBAL_SD_PLL_2_dft                      0x00c54388

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sd30_sscpll_ctrl2    : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_SD_PLL_2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SD_PLL_3                          0xf432035c
#define GLOBAL_SD_PLL_3_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sd30_sscpll_ctrl3    : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_SD_PLL_3_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_SD_PLL_4                          0xf4320360
#define GLOBAL_SD_PLL_4_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg_sdpll_ck_test    :  1 ; /* bits 0:0 */
    u32 sdpll_enable_test    :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} GLOBAL_SD_PLL_4_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_LDO_SD3                           0xf4320364
#define GLOBAL_LDO_SD3_dft                       0x000001db

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 LDO_SD3_POW          :  2 ; /* bits 1:0 */
    u32 LDO_SD3_REG_TUNEREF  :  2 ; /* bits 3:2 */
    u32 LDO_SD3_REG_SSTIME   :  2 ; /* bits 5:4 */
    u32 LDO_SD3_REG_TUNE_VO  :  3 ; /* bits 8:6 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} GLOBAL_LDO_SD3_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_U2PHY_STS_SLB                     0xf4320368
#define GLOBAL_U2PHY_STS_SLB_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ERR_NUM_0            :  8 ; /* bits 7:0 */
    u32 ERR_NUM_1            :  8 ; /* bits 15:8 */
    u32 PACKET_NUM_0         :  8 ; /* bits 23:16 */
    u32 PACKET_NUM_1         :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} GLOBAL_U2PHY_STS_SLB_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_PHY_ISO_POWER_CTRL                0xf432036c
#define GLOBAL_PHY_ISO_POWER_CTRL_dft            0xffff0000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 s0_PCIE2_ISOLATE_0   :  1 ; /* bits 0:0 */
    u32 s0_PCIE2_ISOLATE_1   :  1 ; /* bits 1:1 */
    u32 s1_PCIE2_ISOLATE_0   :  1 ; /* bits 2:2 */
    u32 s1_PCIE2_ISOLATE_1   :  1 ; /* bits 3:3 */
    u32 s2_CPHY_ISOLATE      :  1 ; /* bits 4:4 */
    u32 s3_CPHY_ISOLATE      :  1 ; /* bits 5:5 */
    u32 rsrvd1               :  1 ;
    u32 s0_POW_PCIE2_0       :  1 ; /* bits 7:7 */
    u32 s0_POW_PCIE2_1       :  1 ; /* bits 8:8 */
    u32 s1_POW_PCIE2_0       :  1 ; /* bits 9:9 */
    u32 s1_POW_PCIE2_1       :  1 ; /* bits 10:10 */
    u32 s2_POW_USB3          :  1 ; /* bits 11:11 */
    u32 s2_POW_PCIE2         :  1 ; /* bits 12:12 */
    u32 s3_POW_USB3          :  1 ; /* bits 13:13 */
    u32 s3_POW_PCIE2         :  1 ; /* bits 14:14 */
    u32 rsrvd2               :  1 ;
    u32 s0_ISO_ANA_B         :  1 ; /* bits 16:16 */
    u32 s1_ISO_ANA_B         :  1 ; /* bits 17:17 */
    u32 s2_ISO_ANA_B         :  1 ; /* bits 18:18 */
    u32 s3_ISO_ANA_B         :  1 ; /* bits 19:19 */
    u32 s0_LANE0_CA09PC_EN   :  1 ; /* bits 20:20 */
    u32 s0_LANE0_CA33PC_EN   :  1 ; /* bits 21:21 */
    u32 s0_LANE1_CA09PC_EN   :  1 ; /* bits 22:22 */
    u32 s0_LANE1_CA33PC_EN   :  1 ; /* bits 23:23 */
    u32 s1_LANE0_CA09PC_EN   :  1 ; /* bits 24:24 */
    u32 s1_LANE0_CA33PC_EN   :  1 ; /* bits 25:25 */
    u32 s1_LANE1_CA09PC_EN   :  1 ; /* bits 26:26 */
    u32 s1_LANE1_CA33PC_EN   :  1 ; /* bits 27:27 */
    u32 s2_CA09PC_EN         :  1 ; /* bits 28:28 */
    u32 s2_CA33PC_EN         :  1 ; /* bits 29:29 */
    u32 s3_CA09PC_EN         :  1 ; /* bits 30:30 */
    u32 s3_CA33PC_EN         :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} GLOBAL_PHY_ISO_POWER_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_GPI_STATUS4                       0xf4320370
#define GLOBAL_GPI_STATUS4_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpio_i4              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_GPI_STATUS4_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_GPI_STATUS3                       0xf4320374
#define GLOBAL_GPI_STATUS3_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpio_i3              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_GPI_STATUS3_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_GPI_STATUS2                       0xf4320378
#define GLOBAL_GPI_STATUS2_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpio_i2              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_GPI_STATUS2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_GPI_STATUS1                       0xf432037c
#define GLOBAL_GPI_STATUS1_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpio_i1              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_GPI_STATUS1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_GPI_STATUS0                       0xf4320380
#define GLOBAL_GPI_STATUS0_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpio_i0              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_GPI_STATUS0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_TH_PLL                            0xf4320384
#define GLOBAL_TH_PLL_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 PLL_RDY              :  1 ; /* bits 0:0 */
    u32 AFE_SDM_DBG_OUT      :  3 ; /* bits 3:1 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} GLOBAL_TH_PLL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_TH_PLL_0                          0xf4320388
#define GLOBAL_TH_PLL_0_dft                      0xe22d7e80

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 REG0X_PLL_I2S        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_TH_PLL_0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_TH_PLL_1                          0xf432038c
#define GLOBAL_TH_PLL_1_dft                      0x17850180

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 REG1X_PLL_I2S        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_TH_PLL_1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_TH_PLL_2                          0xf4320390
#define GLOBAL_TH_PLL_2_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 REG2X_PLL_I2S        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_TH_PLL_2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_TH_PLL_3                          0xf4320394
#define GLOBAL_TH_PLL_3_dft                      0x9b030000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 REG3X_PLL_I2S        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_TH_PLL_3_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_DDR_RESET_MODE                    0xf4320398
#define GLOBAL_DDR_RESET_MODE_dft                0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ddr_warm_rst_mode    :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} GLOBAL_DDR_RESET_MODE_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_RSVD_CONTROL7                     0xf432039c
#define GLOBAL_RSVD_CONTROL7_dft                 0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsvd_global7         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_RSVD_CONTROL7_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_RSVD_CONTROL6                     0xf43203a0
#define GLOBAL_RSVD_CONTROL6_dft                 0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsvd_global6         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_RSVD_CONTROL6_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_RSVD_CONTROL5                     0xf43203a4
#define GLOBAL_RSVD_CONTROL5_dft                 0xaaaaaaaa

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsvd_global5         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_RSVD_CONTROL5_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_RSVD_CONTROL4                     0xf43203a8
#define GLOBAL_RSVD_CONTROL4_dft                 0xaaaaaaaa

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsvd_global4         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_RSVD_CONTROL4_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_RSVD_CONTROL3                     0xf43203ac
#define GLOBAL_RSVD_CONTROL3_dft                 0x55555555

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsvd_global3         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_RSVD_CONTROL3_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_RSVD_CONTROL2                     0xf43203b0
#define GLOBAL_RSVD_CONTROL2_dft                 0x55555555

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsvd_global2         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_RSVD_CONTROL2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_RSVD_CONTROL1                     0xf43203b4
#define GLOBAL_RSVD_CONTROL1_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsvd_global1         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_RSVD_CONTROL1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_RSVD_CONTROL0                     0xf43203b8
#define GLOBAL_RSVD_CONTROL0_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsvd_global0         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_RSVD_CONTROL0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_RSVD_RESULTS3                     0xf43203bc
#define GLOBAL_RSVD_RESULTS3_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsvd_results3        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_RSVD_RESULTS3_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_RSVD_RESULTS2                     0xf43203c0
#define GLOBAL_RSVD_RESULTS2_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsvd_results2        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_RSVD_RESULTS2_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_RSVD_RESULTS1                     0xf43203c4
#define GLOBAL_RSVD_RESULTS1_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsvd_results1        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_RSVD_RESULTS1_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_RSVD_RESULTS0                     0xf43203c8
#define GLOBAL_RSVD_RESULTS0_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsvd_results0        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_RSVD_RESULTS0_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CHIP_ID_CTRL                      0xf4320ff0
#define GLOBAL_CHIP_ID_CTRL_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               : 16 ;
    u32 chip_id_ctrl         : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} GLOBAL_CHIP_ID_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_CHIP_ID                           0xf4320ff4
#define GLOBAL_CHIP_ID_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 chip_id              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_CHIP_ID_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_FPGA_OPTION                       0xf4320ff8
#define GLOBAL_FPGA_OPTION_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 fpga_option          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_FPGA_OPTION_t;
#endif /* !__ASSEMBLER__ */
#define GLOBAL_FPGA_DATE                         0xf4320ffc
#define GLOBAL_FPGA_DATE_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 fpga_date            : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} GLOBAL_FPGA_DATE_t;
#endif /* !__ASSEMBLER__ */
#define PER_SOFT_RESET                           0xf4329000
#define PER_SOFT_RESET_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 soft_reset           :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SOFT_RESET_t;
#endif /* !__ASSEMBLER__ */
#define PER_PERIPHERAL_INTERRUPT_0               0xf4329004
#define PER_PERIPHERAL_INTERRUPT_0_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 soft0i               :  1 ; /* bits 0:0 */
    u32 soft1i               :  1 ; /* bits 1:1 */
    u32 tmr1i                :  1 ; /* bits 2:2 */
    u32 tmr2i                :  1 ; /* bits 3:3 */
    u32 tmr3i                :  1 ; /* bits 4:4 */
    u32 tmr4i                :  1 ; /* bits 5:5 */
    u32 wdti                 :  1 ; /* bits 6:6 */
    u32 spii                 :  1 ; /* bits 7:7 */
    u32 gpio0i               :  1 ; /* bits 8:8 */
    u32 gpio1i               :  1 ; /* bits 9:9 */
    u32 gpio2i               :  1 ; /* bits 10:10 */
    u32 gpio3i               :  1 ; /* bits 11:11 */
    u32 gpio4i               :  1 ; /* bits 12:12 */
    u32 biw0i                :  1 ; /* bits 13:13 */
    u32 mdioi                :  1 ; /* bits 14:14 */
    u32 trng0i               :  1 ; /* bits 15:15 */
    u32 trng1i               :  1 ; /* bits 16:16 */
    u32 cspii                :  1 ; /* bits 17:17 */
    u32 ldma4i               :  1 ; /* bits 18:18 */
    u32 ldma5i               :  1 ; /* bits 19:19 */
    u32 ldma6i               :  1 ; /* bits 20:20 */
    u32 ldma7i               :  1 ; /* bits 21:21 */
    u32 taroko_timer0i       :  1 ; /* bits 22:22 */
    u32 taroko_timer1i       :  1 ; /* bits 23:23 */
    u32 dying_gaspi          :  1 ; /* bits 24:24 */
    u32 ssp_i                :  1 ; /* bits 25:25 */
    u32 biw1i                :  1 ; /* bits 26:26 */
    u32 rsrvd1               :  5 ;
  } bf ;
  u32     wrd ;
} PER_PERIPHERAL_INTERRUPT_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_PERIPHERAL_INTENABLE_0               0xf4329008
#define PER_PERIPHERAL_INTENABLE_0_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 soft0e               :  1 ; /* bits 0:0 */
    u32 soft1e               :  1 ; /* bits 1:1 */
    u32 tmr1e                :  1 ; /* bits 2:2 */
    u32 tmr2e                :  1 ; /* bits 3:3 */
    u32 tmr3e                :  1 ; /* bits 4:4 */
    u32 tmr4e                :  1 ; /* bits 5:5 */
    u32 wdte                 :  1 ; /* bits 6:6 */
    u32 spie                 :  1 ; /* bits 7:7 */
    u32 gpio0e               :  1 ; /* bits 8:8 */
    u32 gpio1e               :  1 ; /* bits 9:9 */
    u32 gpio2e               :  1 ; /* bits 10:10 */
    u32 gpio3e               :  1 ; /* bits 11:11 */
    u32 gpio4e               :  1 ; /* bits 12:12 */
    u32 biw0e                :  1 ; /* bits 13:13 */
    u32 mdioe                :  1 ; /* bits 14:14 */
    u32 trng0e               :  1 ; /* bits 15:15 */
    u32 trng1e               :  1 ; /* bits 16:16 */
    u32 cspie                :  1 ; /* bits 17:17 */
    u32 ldma4e               :  1 ; /* bits 18:18 */
    u32 ldma5e               :  1 ; /* bits 19:19 */
    u32 ldma6e               :  1 ; /* bits 20:20 */
    u32 ldma7e               :  1 ; /* bits 21:21 */
    u32 taroko_timer0e       :  1 ; /* bits 22:22 */
    u32 taroko_timer1e       :  1 ; /* bits 23:23 */
    u32 dying_gaspe          :  1 ; /* bits 24:24 */
    u32 ssp_e                :  1 ; /* bits 25:25 */
    u32 biw1e                :  1 ; /* bits 26:26 */
    u32 rsrvd1               :  5 ;
  } bf ;
  u32     wrd ;
} PER_PERIPHERAL_INTENABLE_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_PERIPHERAL_INTERRUPT_1               0xf432900c
#define PER_PERIPHERAL_INTERRUPT_1_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 soft0i               :  1 ; /* bits 0:0 */
    u32 soft1i               :  1 ; /* bits 1:1 */
    u32 tmr1i                :  1 ; /* bits 2:2 */
    u32 tmr2i                :  1 ; /* bits 3:3 */
    u32 tmr3i                :  1 ; /* bits 4:4 */
    u32 tmr4i                :  1 ; /* bits 5:5 */
    u32 wdti                 :  1 ; /* bits 6:6 */
    u32 spii                 :  1 ; /* bits 7:7 */
    u32 gpio0i               :  1 ; /* bits 8:8 */
    u32 gpio1i               :  1 ; /* bits 9:9 */
    u32 gpio2i               :  1 ; /* bits 10:10 */
    u32 gpio3i               :  1 ; /* bits 11:11 */
    u32 gpio4i               :  1 ; /* bits 12:12 */
    u32 biw0i                :  1 ; /* bits 13:13 */
    u32 mdioi                :  1 ; /* bits 14:14 */
    u32 trng0i               :  1 ; /* bits 15:15 */
    u32 trng1i               :  1 ; /* bits 16:16 */
    u32 cspii                :  1 ; /* bits 17:17 */
    u32 ldma4i               :  1 ; /* bits 18:18 */
    u32 ldma5i               :  1 ; /* bits 19:19 */
    u32 ldma6i               :  1 ; /* bits 20:20 */
    u32 ldma7i               :  1 ; /* bits 21:21 */
    u32 taroko_timer0i       :  1 ; /* bits 22:22 */
    u32 taroko_timer1i       :  1 ; /* bits 23:23 */
    u32 dying_gaspi          :  1 ; /* bits 24:24 */
    u32 ssp_i                :  1 ; /* bits 25:25 */
    u32 biw1i                :  1 ; /* bits 26:26 */
    u32 rsrvd1               :  5 ;
  } bf ;
  u32     wrd ;
} PER_PERIPHERAL_INTERRUPT_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_PERIPHERAL_INTENABLE_1               0xf4329010
#define PER_PERIPHERAL_INTENABLE_1_dft           0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 soft0e               :  1 ; /* bits 0:0 */
    u32 soft1e               :  1 ; /* bits 1:1 */
    u32 tmr1e                :  1 ; /* bits 2:2 */
    u32 tmr2e                :  1 ; /* bits 3:3 */
    u32 tmr3e                :  1 ; /* bits 4:4 */
    u32 tmr4e                :  1 ; /* bits 5:5 */
    u32 wdte                 :  1 ; /* bits 6:6 */
    u32 spie                 :  1 ; /* bits 7:7 */
    u32 gpio0e               :  1 ; /* bits 8:8 */
    u32 gpio1e               :  1 ; /* bits 9:9 */
    u32 gpio2e               :  1 ; /* bits 10:10 */
    u32 gpio3e               :  1 ; /* bits 11:11 */
    u32 gpio4e               :  1 ; /* bits 12:12 */
    u32 biw0e                :  1 ; /* bits 13:13 */
    u32 mdioe                :  1 ; /* bits 14:14 */
    u32 trng0e               :  1 ; /* bits 15:15 */
    u32 trng1e               :  1 ; /* bits 16:16 */
    u32 cspie                :  1 ; /* bits 17:17 */
    u32 ldma4e               :  1 ; /* bits 18:18 */
    u32 ldma5e               :  1 ; /* bits 19:19 */
    u32 ldma6e               :  1 ; /* bits 20:20 */
    u32 ldma7e               :  1 ; /* bits 21:21 */
    u32 taroko_timer0e       :  1 ; /* bits 22:22 */
    u32 taroko_timer1e       :  1 ; /* bits 23:23 */
    u32 dying_gaspe          :  1 ; /* bits 24:24 */
    u32 ssp_e                :  1 ; /* bits 25:25 */
    u32 biw1e                :  1 ; /* bits 26:26 */
    u32 rsrvd1               :  5 ;
  } bf ;
  u32     wrd ;
} PER_PERIPHERAL_INTENABLE_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_IRQ_SOFT1                            0xf4329014
#define PER_IRQ_SOFT1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 softiSet             :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_IRQ_SOFT1_t;
#endif /* !__ASSEMBLER__ */
#define PER_IRQ_SOFT0                            0xf4329018
#define PER_IRQ_SOFT0_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 softiSet             :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_IRQ_SOFT0_t;
#endif /* !__ASSEMBLER__ */
#define PER_WDT_CTRL                             0xf432901c
#define PER_WDT_CTRL_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wdten                :  1 ; /* bits 0:0 */
    u32 rsten                :  1 ; /* bits 1:1 */
    u32 clksel               :  1 ; /* bits 2:2 */
    u32 rsrvd1               :  9 ;
    u32 wdt_delay            : 20 ; /* bits 31:12 */
  } bf ;
  u32     wrd ;
} PER_WDT_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define PER_WDT_PS                               0xf4329020
#define PER_WDT_PS_dft                           0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wdtps                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_WDT_PS_t;
#endif /* !__ASSEMBLER__ */
#define PER_WDT_DIV                              0xf4329024
#define PER_WDT_DIV_dft                          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 div_load             : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} PER_WDT_DIV_t;
#endif /* !__ASSEMBLER__ */
#define PER_WDT_LD                               0xf4329028
#define PER_WDT_LD_dft                           0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wdtld                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_WDT_LD_t;
#endif /* !__ASSEMBLER__ */
#define PER_WDT_LOADE                            0xf432902c
#define PER_WDT_LOADE_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 update_wdt           :  1 ; /* bits 0:0 */
    u32 update_pre           :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} PER_WDT_LOADE_t;
#endif /* !__ASSEMBLER__ */
#define PER_WDT_CNT                              0xf4329030
#define PER_WDT_CNT_dft                          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wdtcount             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_WDT_CNT_t;
#endif /* !__ASSEMBLER__ */
#define PER_WDT_IE_0                             0xf4329034
#define PER_WDT_IE_0_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wdte                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_WDT_IE_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_WDT_INT_0                            0xf4329038
#define PER_WDT_INT_0_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wdti                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_WDT_INT_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_WDT_STAT_0                           0xf432903c
#define PER_WDT_STAT_0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wdts                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_WDT_STAT_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_WDT_IE_1                             0xf4329040
#define PER_WDT_IE_1_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wdte                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_WDT_IE_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_WDT_INT_1                            0xf4329044
#define PER_WDT_INT_1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wdti                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_WDT_INT_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_WDT_STAT_1                           0xf4329048
#define PER_WDT_STAT_1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wdts                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_WDT_STAT_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_WDT_TST                              0xf432904c
#define PER_WDT_TST_dft                          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 testmode             :  1 ; /* bits 0:0 */
    u32 testclken            :  1 ; /* bits 1:1 */
    u32 testreset            :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} PER_WDT_TST_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_LD1                              0xf4329050
#define PER_TMR_LD1_dft                          0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 load1                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_TMR_LD1_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_CTRL1                            0xf4329054
#define PER_TMR_CTRL1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  2 ;
    u32 clksel1              :  2 ; /* bits 3:2 */
    u32 rsrvd2               :  2 ;
    u32 rlmode1              :  1 ; /* bits 6:6 */
    u32 timen1               :  1 ; /* bits 7:7 */
    u32 rsrvd3               : 24 ;
  } bf ;
  u32     wrd ;
} PER_TMR_CTRL1_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_CNT1                             0xf4329058
#define PER_TMR_CNT1_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 count1               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_TMR_CNT1_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_IE1_0                            0xf432905c
#define PER_TMR_IE1_0_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr1e                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_IE1_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_IE1_1                            0xf4329060
#define PER_TMR_IE1_1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr1e                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_IE1_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_INT1_0                           0xf4329064
#define PER_TMR_INT1_0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr1i                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_INT1_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_INT1_1                           0xf4329068
#define PER_TMR_INT1_1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr1i                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_INT1_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_STAT1                            0xf432906c
#define PER_TMR_STAT1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr1s                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_STAT1_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_LD2                              0xf4329070
#define PER_TMR_LD2_dft                          0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 load2                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_TMR_LD2_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_CTRL2                            0xf4329074
#define PER_TMR_CTRL2_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  2 ;
    u32 clksel2              :  2 ; /* bits 3:2 */
    u32 rsrvd2               :  2 ;
    u32 rlmode2              :  1 ; /* bits 6:6 */
    u32 timen2               :  1 ; /* bits 7:7 */
    u32 rsrvd3               : 24 ;
  } bf ;
  u32     wrd ;
} PER_TMR_CTRL2_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_CNT2                             0xf4329078
#define PER_TMR_CNT2_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 count2               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_TMR_CNT2_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_IE2_0                            0xf432907c
#define PER_TMR_IE2_0_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr2e                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_IE2_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_IE2_1                            0xf4329080
#define PER_TMR_IE2_1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr2e                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_IE2_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_INT2_0                           0xf4329084
#define PER_TMR_INT2_0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr2i                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_INT2_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_INT2_1                           0xf4329088
#define PER_TMR_INT2_1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr2i                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_INT2_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_STAT2                            0xf432908c
#define PER_TMR_STAT2_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr2s                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_STAT2_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_LD3                              0xf4329090
#define PER_TMR_LD3_dft                          0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 load3                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_TMR_LD3_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_CTRL3                            0xf4329094
#define PER_TMR_CTRL3_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  2 ;
    u32 clksel3              :  2 ; /* bits 3:2 */
    u32 rsrvd2               :  2 ;
    u32 rlmode3              :  1 ; /* bits 6:6 */
    u32 timen3               :  1 ; /* bits 7:7 */
    u32 rsrvd3               : 24 ;
  } bf ;
  u32     wrd ;
} PER_TMR_CTRL3_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_CNT3                             0xf4329098
#define PER_TMR_CNT3_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 count3               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_TMR_CNT3_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_IE3_0                            0xf432909c
#define PER_TMR_IE3_0_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr3e                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_IE3_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_IE3_1                            0xf43290a0
#define PER_TMR_IE3_1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr3e                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_IE3_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_INT3_0                           0xf43290a4
#define PER_TMR_INT3_0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr3i                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_INT3_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_INT3_1                           0xf43290a8
#define PER_TMR_INT3_1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr3i                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_INT3_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_STAT3                            0xf43290ac
#define PER_TMR_STAT3_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr3s                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_STAT3_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_LD4                              0xf43290b0
#define PER_TMR_LD4_dft                          0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 load4                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_TMR_LD4_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_CTRL4                            0xf43290b4
#define PER_TMR_CTRL4_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  2 ;
    u32 clksel4              :  2 ; /* bits 3:2 */
    u32 rsrvd2               :  2 ;
    u32 rlmode4              :  1 ; /* bits 6:6 */
    u32 timen4               :  1 ; /* bits 7:7 */
    u32 rsrvd3               : 24 ;
  } bf ;
  u32     wrd ;
} PER_TMR_CTRL4_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_CNT4                             0xf43290b8
#define PER_TMR_CNT4_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 count4               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_TMR_CNT4_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_IE4_0                            0xf43290bc
#define PER_TMR_IE4_0_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr4e                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_IE4_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_IE4_1                            0xf43290c0
#define PER_TMR_IE4_1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr4e                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_IE4_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_INT4_0                           0xf43290c4
#define PER_TMR_INT4_0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr4i                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_INT4_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_INT4_1                           0xf43290c8
#define PER_TMR_INT4_1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr4i                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_INT4_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_STAT4                            0xf43290cc
#define PER_TMR_STAT4_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tmr4s                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_TMR_STAT4_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_LOADE                            0xf43290d0
#define PER_TMR_LOADE_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rsrvd1               :  1 ;
    u32 update_tmr1          :  1 ; /* bits 1:1 */
    u32 update_tmr2          :  1 ; /* bits 2:2 */
    u32 update_tmr3          :  1 ; /* bits 3:3 */
    u32 update_tmr4          :  1 ; /* bits 4:4 */
    u32 rsrvd2               : 27 ;
  } bf ;
  u32     wrd ;
} PER_TMR_LOADE_t;
#endif /* !__ASSEMBLER__ */
#define PER_TMR_TST                              0xf43290d4
#define PER_TMR_TST_dft                          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 testclksel           :  1 ; /* bits 0:0 */
    u32 test1                :  1 ; /* bits 1:1 */
    u32 test2                :  1 ; /* bits 2:2 */
    u32 test3                :  1 ; /* bits 3:3 */
    u32 test4                :  1 ; /* bits 4:4 */
    u32 pps_timer1_en        :  1 ; /* bits 5:5 */
    u32 pps_timer2_en        :  1 ; /* bits 6:6 */
    u32 pps_from_timer       :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_TMR_TST_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_CLK                              0xf43290d8
#define PER_SPI_CLK_dft                          0x00000002

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 counter_load         : 16 ; /* bits 15:0 */
    u32 ssp_igap             :  8 ; /* bits 23:16 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} PER_SPI_CLK_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_CFG                              0xf43290dc
#define PER_SPI_CFG_dft                          0x3f090000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 command_cyc          :  1 ; /* bits 0:0 */
    u32 read_write           :  1 ; /* bits 1:1 */
    u32 micro_wire_cs_sel    :  5 ; /* bits 6:2 */
    u32 rsrvd1               :  1 ;
    u32 sel_ssp_cs           :  5 ; /* bits 12:8 */
    u32 rsrvd2               :  3 ;
    u32 ssp_cmd_cnt          :  7 ; /* bits 22:16 */
    u32 rsrvd3               :  1 ;
    u32 pre_ssp_dat_cnt      :  6 ; /* bits 29:24 */
    u32 sspcs_en3_gpio       :  1 ; /* bits 30:30 */
    u32 sspcs_en4_gpio       :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} PER_SPI_CFG_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_MODE                             0xf43290e0
#define PER_SPI_MODE_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cfg                  : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SPI_MODE_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_CTRL                             0xf43290e4
#define PER_SPI_CTRL_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sspdone              :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  6 ;
    u32 sspstart             :  1 ; /* bits 7:7 */
    u32 rsrvd2               : 24 ;
  } bf ;
  u32     wrd ;
} PER_SPI_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_CA0                              0xf43290e8
#define PER_SPI_CA0_dft                          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ssp_cmd_addr0        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SPI_CA0_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_CA1                              0xf43290ec
#define PER_SPI_CA1_dft                          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ssp_cmd_addr1        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SPI_CA1_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_CA2                              0xf43290f0
#define PER_SPI_CA2_dft                          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ssp_cmd_addr2        : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SPI_CA2_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_WDAT1                            0xf43290f4
#define PER_SPI_WDAT1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ssp_wdata1           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SPI_WDAT1_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_WDAT0                            0xf43290f8
#define PER_SPI_WDAT0_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ssp_wdata0           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SPI_WDAT0_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_RDAT1                            0xf43290fc
#define PER_SPI_RDAT1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ssp_rdata1           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SPI_RDAT1_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_RDAT0                            0xf4329100
#define PER_SPI_RDAT0_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ssp_rdata0           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SPI_RDAT0_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_IE_0                             0xf4329104
#define PER_SPI_IE_0_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 spie                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SPI_IE_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_INT_0                            0xf4329108
#define PER_SPI_INT_0_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sspi                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SPI_INT_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_IE_1                             0xf432910c
#define PER_SPI_IE_1_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 spie                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SPI_IE_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_INT_1                            0xf4329110
#define PER_SPI_INT_1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 sspi                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SPI_INT_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPI_STAT                             0xf4329114
#define PER_SPI_STAT_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 ssps                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SPI_STAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_CFG                             0xf4329118
#define PER_MDIO_CFG_dft                         0x10000001

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mdio_manual          :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 15 ;
    u32 mdio_pre_scale       : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} PER_MDIO_CFG_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_ADDR                            0xf432911c
#define PER_MDIO_ADDR_dft                        0x00080000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mdio_addr            :  5 ; /* bits 4:0 */
    u32 rsrvd1               :  3 ;
    u32 mdio_offset          :  5 ; /* bits 12:8 */
    u32 rsrvd2               :  2 ;
    u32 mdio_rd_wr           :  1 ; /* bits 15:15 */
    u32 mdio_st              :  1 ; /* bits 16:16 */
    u32 rsrvd3               :  1 ;
    u32 mdio_op              :  2 ; /* bits 19:18 */
    u32 rsrvd4               : 12 ;
  } bf ;
  u32     wrd ;
} PER_MDIO_ADDR_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_WRDATA                          0xf4329120
#define PER_MDIO_WRDATA_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mdio_wrdata          : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} PER_MDIO_WRDATA_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_RDDATA                          0xf4329124
#define PER_MDIO_RDDATA_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mdio_rddata          : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 16 ;
  } bf ;
  u32     wrd ;
} PER_MDIO_RDDATA_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_CTRL                            0xf4329128
#define PER_MDIO_CTRL_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mdiodone             :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  6 ;
    u32 mdiostart            :  1 ; /* bits 7:7 */
    u32 rsrvd2               : 24 ;
  } bf ;
  u32     wrd ;
} PER_MDIO_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_AUTO_CFG                        0xf432912c
#define PER_MDIO_AUTO_CFG_dft                    0x00001f00

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 auto_mdio_phy_start_idx :  6 ; /* bits 5:0 */
    u32 rsrvd1               :  2 ;
    u32 auto_mdio_phy_end_idx :  6 ; /* bits 13:8 */
    u32 rsrvd2               :  1 ;
    u32 auto_mdio_gpio       :  1 ; /* bits 15:15 */
    u32 auto_mdio_reg_to_read :  5 ; /* bits 20:16 */
    u32 rsrvd3               : 11 ;
  } bf ;
  u32     wrd ;
} PER_MDIO_AUTO_CFG_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_AUTO_INTV                       0xf4329130
#define PER_MDIO_AUTO_INTV_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 poll_wait_cycles     : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_MDIO_AUTO_INTV_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_AUTO_RM                         0xf4329134
#define PER_MDIO_AUTO_RM_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 auto_mdio_bit_invert : 16 ; /* bits 15:0 */
    u32 auto_mdio_bit_mask   : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} PER_MDIO_AUTO_RM_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_AUTO_AADDR                      0xf4329138
#define PER_MDIO_AUTO_AADDR_dft                  0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 auto_mdio_phy_alert_addr :  5 ; /* bits 4:0 */
    u32 auto_mdio_phy_alert_range :  1 ; /* bits 5:5 */
    u32 rsrvd1               : 10 ;
    u32 auto_mdio_rddata     : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} PER_MDIO_AUTO_AADDR_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_ENTAB0                          0xf432913c
#define PER_MDIO_ENTAB0_dft                      0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 slot_enable0         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_MDIO_ENTAB0_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_ENTAB1                          0xf4329140
#define PER_MDIO_ENTAB1_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 slot_enable1         : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_MDIO_ENTAB1_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_ITAB0                           0xf4329144
#define PER_MDIO_ITAB0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 i                    : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_MDIO_ITAB0_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_ITAB1                           0xf4329148
#define PER_MDIO_ITAB1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 i                    : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_MDIO_ITAB1_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_IE_0                            0xf432914c
#define PER_MDIO_IE_0_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mdioe                :  1 ; /* bits 0:0 */
    u32 autopolle            :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} PER_MDIO_IE_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_INT_0                           0xf4329150
#define PER_MDIO_INT_0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mdioi                :  1 ; /* bits 0:0 */
    u32 autopolli            :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} PER_MDIO_INT_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_IE_1                            0xf4329154
#define PER_MDIO_IE_1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mdioe                :  1 ; /* bits 0:0 */
    u32 autopolle            :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} PER_MDIO_IE_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_INT_1                           0xf4329158
#define PER_MDIO_INT_1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mdioi                :  1 ; /* bits 0:0 */
    u32 autopolli            :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} PER_MDIO_INT_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_MDIO_STAT                            0xf432915c
#define PER_MDIO_STAT_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 mdios                :  1 ; /* bits 0:0 */
    u32 autopolls            :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} PER_MDIO_STAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW0_CFG                             0xf4329160
#define PER_BIW0_CFG_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 core_en              :  1 ; /* bits 0:0 */
    u32 biw_soft_reset       :  1 ; /* bits 1:1 */
    u32 busywait_en          :  1 ; /* bits 2:2 */
    u32 stretch_en           :  1 ; /* bits 3:3 */
    u32 arb_en               :  1 ; /* bits 4:4 */
    u32 clksync_en           :  1 ; /* bits 5:5 */
    u32 rsrvd1               :  2 ;
    u32 spike_cnt            :  4 ; /* bits 11:8 */
    u32 rsrvd2               :  4 ;
    u32 prer                 : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} PER_BIW0_CFG_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW0_CTRL                            0xf4329164
#define PER_BIW0_CTRL_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 biwdone              :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  2 ;
    u32 ack_in               :  1 ; /* bits 3:3 */
    u32 write                :  1 ; /* bits 4:4 */
    u32 read                 :  1 ; /* bits 5:5 */
    u32 stop                 :  1 ; /* bits 6:6 */
    u32 start                :  1 ; /* bits 7:7 */
    u32 rsrvd2               : 24 ;
  } bf ;
  u32     wrd ;
} PER_BIW0_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW0_TXR                             0xf4329168
#define PER_BIW0_TXR_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 txr                  :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_BIW0_TXR_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW0_RXR                             0xf432916c
#define PER_BIW0_RXR_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rxr                  :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_BIW0_RXR_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW0_ACK                             0xf4329170
#define PER_BIW0_ACK_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 al                   :  1 ; /* bits 0:0 */
    u32 biw_busy             :  1 ; /* bits 1:1 */
    u32 ack_out              :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} PER_BIW0_ACK_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW0_IE_0                            0xf4329174
#define PER_BIW0_IE_0_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 biwe                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_BIW0_IE_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW0_INT_0                           0xf4329178
#define PER_BIW0_INT_0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 biwi                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_BIW0_INT_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW0_IE_1                            0xf432917c
#define PER_BIW0_IE_1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 biwe                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_BIW0_IE_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW0_INT_1                           0xf4329180
#define PER_BIW0_INT_1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 biwi                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_BIW0_INT_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW0_STAT                            0xf4329184
#define PER_BIW0_STAT_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 biws                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_BIW0_STAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW1_CFG                             0xf4329188
#define PER_BIW1_CFG_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 core_en              :  1 ; /* bits 0:0 */
    u32 biw_soft_reset       :  1 ; /* bits 1:1 */
    u32 busywait_en          :  1 ; /* bits 2:2 */
    u32 stretch_en           :  1 ; /* bits 3:3 */
    u32 arb_en               :  1 ; /* bits 4:4 */
    u32 clksync_en           :  1 ; /* bits 5:5 */
    u32 rsrvd1               :  2 ;
    u32 spike_cnt            :  4 ; /* bits 11:8 */
    u32 rsrvd2               :  4 ;
    u32 prer                 : 16 ; /* bits 31:16 */
  } bf ;
  u32     wrd ;
} PER_BIW1_CFG_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW1_CTRL                            0xf432918c
#define PER_BIW1_CTRL_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 biwdone              :  1 ; /* bits 0:0 */
    u32 rsrvd1               :  2 ;
    u32 ack_in               :  1 ; /* bits 3:3 */
    u32 write                :  1 ; /* bits 4:4 */
    u32 read                 :  1 ; /* bits 5:5 */
    u32 stop                 :  1 ; /* bits 6:6 */
    u32 start                :  1 ; /* bits 7:7 */
    u32 rsrvd2               : 24 ;
  } bf ;
  u32     wrd ;
} PER_BIW1_CTRL_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW1_TXR                             0xf4329190
#define PER_BIW1_TXR_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 txr                  :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_BIW1_TXR_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW1_RXR                             0xf4329194
#define PER_BIW1_RXR_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rxr                  :  8 ; /* bits 7:0 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_BIW1_RXR_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW1_ACK                             0xf4329198
#define PER_BIW1_ACK_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 al                   :  1 ; /* bits 0:0 */
    u32 biw_busy             :  1 ; /* bits 1:1 */
    u32 ack_out              :  1 ; /* bits 2:2 */
    u32 rsrvd1               : 29 ;
  } bf ;
  u32     wrd ;
} PER_BIW1_ACK_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW1_IE_0                            0xf432919c
#define PER_BIW1_IE_0_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 biwe                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_BIW1_IE_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW1_INT_0                           0xf43291a0
#define PER_BIW1_INT_0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 biwi                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_BIW1_INT_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW1_IE_1                            0xf43291a4
#define PER_BIW1_IE_1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 biwe                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_BIW1_IE_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW1_INT_1                           0xf43291a8
#define PER_BIW1_INT_1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 biwi                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_BIW1_INT_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_BIW1_STAT                            0xf43291ac
#define PER_BIW1_STAT_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 biws                 :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_BIW1_STAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART0_CFG                            0xf43291b0
#define PER_UART0_CFG_dft                        0x00000003

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 char_cnt             :  2 ; /* bits 1:0 */
    u32 uart_stop_2bit       :  1 ; /* bits 2:2 */
    u32 even_parity_sel      :  1 ; /* bits 3:3 */
    u32 uart_parity_en       :  1 ; /* bits 4:4 */
    u32 tx_sm_enable         :  1 ; /* bits 5:5 */
    u32 rx_sm_enable         :  1 ; /* bits 6:6 */
    u32 uart_en              :  1 ; /* bits 7:7 */
    u32 baud_count           : 24 ; /* bits 31:8 */
  } bf ;
  u32     wrd ;
} PER_UART0_CFG_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART0_FC                             0xf43291b4
#define PER_UART0_FC_dft                         0x00000588

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_wm                :  6 ; /* bits 5:0 */
    u32 inv_cts              :  1 ; /* bits 6:6 */
    u32 no_cts               :  1 ; /* bits 7:7 */
    u32 cts_reg              :  1 ; /* bits 8:8 */
    u32 inv_rts              :  1 ; /* bits 9:9 */
    u32 no_rts               :  1 ; /* bits 10:10 */
    u32 rsrvd1               : 21 ;
  } bf ;
  u32     wrd ;
} PER_UART0_FC_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART0_RX_SAMPLE                      0xf43291b8
#define PER_UART0_RX_SAMPLE_dft                  0x0000000f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_center            : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} PER_UART0_RX_SAMPLE_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART0_TUN                            0xf43291bc
#define PER_UART0_TUN_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_fine_tune_ctl     :  8 ; /* bits 7:0 */
    u32 rx_tune_add          :  1 ; /* bits 8:8 */
    u32 rsrvd1               :  7 ;
    u32 tx_fine_tune_ctl     :  8 ; /* bits 23:16 */
    u32 tx_tune_add          :  1 ; /* bits 24:24 */
    u32 rsrvd2               :  7 ;
  } bf ;
  u32     wrd ;
} PER_UART0_TUN_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART0_TXDAT                          0xf43291c0
#define PER_UART0_TXDAT_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_data              :  8 ; /* bits 7:0 */
    u32 send_break           :  1 ; /* bits 8:8 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} PER_UART0_TXDAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART0_RXDAT                          0xf43291c4
#define PER_UART0_RXDAT_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_data_lat          :  8 ; /* bits 7:0 */
    u32 rx_data_vld          :  1 ; /* bits 8:8 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} PER_UART0_RXDAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART0_INFO                           0xf43291c8
#define PER_UART0_INFO_dft                       0x0000000a

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_fifo_full         :  1 ; /* bits 0:0 */
    u32 rx_fifo_empty        :  1 ; /* bits 1:1 */
    u32 tx_fifo_full         :  1 ; /* bits 2:2 */
    u32 tx_fifo_empty        :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} PER_UART0_INFO_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART0_IE_0                           0xf43291cc
#define PER_UART0_IE_0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    u32 rx_stop_erre         :  1 ; /* bits 1:1 */
    u32 rx_parity_erre       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    u32 rx_breake            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART0_IE_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART0_IE_1                           0xf43291d0
#define PER_UART0_IE_1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    u32 rx_stop_erre         :  1 ; /* bits 1:1 */
    u32 rx_parity_erre       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    u32 rx_breake            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART0_IE_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART0_INT_0                          0xf43291d4
#define PER_UART0_INT_0_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    u32 rx_stop_erri         :  1 ; /* bits 1:1 */
    u32 rx_parity_erri       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    u32 rx_breaki            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART0_INT_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART0_INT_1                          0xf43291d8
#define PER_UART0_INT_1_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    u32 rx_stop_erri         :  1 ; /* bits 1:1 */
    u32 rx_parity_erri       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    u32 rx_breaki            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART0_INT_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART0_STAT                           0xf43291dc
#define PER_UART0_STAT_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overruns     :  1 ; /* bits 0:0 */
    u32 rx_stop_errs         :  1 ; /* bits 1:1 */
    u32 rx_parity_errs       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overruns     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underruns    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptys       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptys    :  1 ; /* bits 6:6 */
    u32 rx_breaks            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART0_STAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART1_CFG                            0xf43291e0
#define PER_UART1_CFG_dft                        0x00000003

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 char_cnt             :  2 ; /* bits 1:0 */
    u32 uart_stop_2bit       :  1 ; /* bits 2:2 */
    u32 even_parity_sel      :  1 ; /* bits 3:3 */
    u32 uart_parity_en       :  1 ; /* bits 4:4 */
    u32 tx_sm_enable         :  1 ; /* bits 5:5 */
    u32 rx_sm_enable         :  1 ; /* bits 6:6 */
    u32 uart_en              :  1 ; /* bits 7:7 */
    u32 baud_count           : 24 ; /* bits 31:8 */
  } bf ;
  u32     wrd ;
} PER_UART1_CFG_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART1_FC                             0xf43291e4
#define PER_UART1_FC_dft                         0x00000588

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_wm                :  6 ; /* bits 5:0 */
    u32 inv_cts              :  1 ; /* bits 6:6 */
    u32 no_cts               :  1 ; /* bits 7:7 */
    u32 cts_reg              :  1 ; /* bits 8:8 */
    u32 inv_rts              :  1 ; /* bits 9:9 */
    u32 no_rts               :  1 ; /* bits 10:10 */
    u32 rsrvd1               : 21 ;
  } bf ;
  u32     wrd ;
} PER_UART1_FC_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART1_RX_SAMPLE                      0xf43291e8
#define PER_UART1_RX_SAMPLE_dft                  0x0000000f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_center            : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} PER_UART1_RX_SAMPLE_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART1_TUN                            0xf43291ec
#define PER_UART1_TUN_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_fine_tune_ctl     :  8 ; /* bits 7:0 */
    u32 rx_tune_add          :  1 ; /* bits 8:8 */
    u32 rsrvd1               :  7 ;
    u32 tx_fine_tune_ctl     :  8 ; /* bits 23:16 */
    u32 tx_tune_add          :  1 ; /* bits 24:24 */
    u32 rsrvd2               :  7 ;
  } bf ;
  u32     wrd ;
} PER_UART1_TUN_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART1_TXDAT                          0xf43291f0
#define PER_UART1_TXDAT_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_data              :  8 ; /* bits 7:0 */
    u32 send_break           :  1 ; /* bits 8:8 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} PER_UART1_TXDAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART1_RXDAT                          0xf43291f4
#define PER_UART1_RXDAT_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_data_lat          :  8 ; /* bits 7:0 */
    u32 rx_data_vld          :  1 ; /* bits 8:8 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} PER_UART1_RXDAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART1_INFO                           0xf43291f8
#define PER_UART1_INFO_dft                       0x0000000a

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_fifo_full         :  1 ; /* bits 0:0 */
    u32 rx_fifo_empty        :  1 ; /* bits 1:1 */
    u32 tx_fifo_full         :  1 ; /* bits 2:2 */
    u32 tx_fifo_empty        :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} PER_UART1_INFO_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART1_IE_0                           0xf43291fc
#define PER_UART1_IE_0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    u32 rx_stop_erre         :  1 ; /* bits 1:1 */
    u32 rx_parity_erre       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    u32 rx_breake            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART1_IE_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART1_IE_1                           0xf4329200
#define PER_UART1_IE_1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    u32 rx_stop_erre         :  1 ; /* bits 1:1 */
    u32 rx_parity_erre       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    u32 rx_breake            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART1_IE_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART1_INT_0                          0xf4329204
#define PER_UART1_INT_0_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    u32 rx_stop_erri         :  1 ; /* bits 1:1 */
    u32 rx_parity_erri       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    u32 rx_breaki            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART1_INT_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART1_INT_1                          0xf4329208
#define PER_UART1_INT_1_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    u32 rx_stop_erri         :  1 ; /* bits 1:1 */
    u32 rx_parity_erri       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    u32 rx_breaki            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART1_INT_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART1_STAT                           0xf432920c
#define PER_UART1_STAT_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overruns     :  1 ; /* bits 0:0 */
    u32 rx_stop_errs         :  1 ; /* bits 1:1 */
    u32 rx_parity_errs       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overruns     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underruns    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptys       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptys    :  1 ; /* bits 6:6 */
    u32 rx_breaks            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART1_STAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART2_CFG                            0xf4329210
#define PER_UART2_CFG_dft                        0x00000003

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 char_cnt             :  2 ; /* bits 1:0 */
    u32 uart_stop_2bit       :  1 ; /* bits 2:2 */
    u32 even_parity_sel      :  1 ; /* bits 3:3 */
    u32 uart_parity_en       :  1 ; /* bits 4:4 */
    u32 tx_sm_enable         :  1 ; /* bits 5:5 */
    u32 rx_sm_enable         :  1 ; /* bits 6:6 */
    u32 uart_en              :  1 ; /* bits 7:7 */
    u32 baud_count           : 24 ; /* bits 31:8 */
  } bf ;
  u32     wrd ;
} PER_UART2_CFG_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART2_FC                             0xf4329214
#define PER_UART2_FC_dft                         0x00000588

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_wm                :  6 ; /* bits 5:0 */
    u32 inv_cts              :  1 ; /* bits 6:6 */
    u32 no_cts               :  1 ; /* bits 7:7 */
    u32 cts_reg              :  1 ; /* bits 8:8 */
    u32 inv_rts              :  1 ; /* bits 9:9 */
    u32 no_rts               :  1 ; /* bits 10:10 */
    u32 rsrvd1               : 21 ;
  } bf ;
  u32     wrd ;
} PER_UART2_FC_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART2_RX_SAMPLE                      0xf4329218
#define PER_UART2_RX_SAMPLE_dft                  0x0000000f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_center            : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} PER_UART2_RX_SAMPLE_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART2_TUN                            0xf432921c
#define PER_UART2_TUN_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_fine_tune_ctl     :  8 ; /* bits 7:0 */
    u32 rx_tune_add          :  1 ; /* bits 8:8 */
    u32 rsrvd1               :  7 ;
    u32 tx_fine_tune_ctl     :  8 ; /* bits 23:16 */
    u32 tx_tune_add          :  1 ; /* bits 24:24 */
    u32 rsrvd2               :  7 ;
  } bf ;
  u32     wrd ;
} PER_UART2_TUN_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART2_TXDAT                          0xf4329220
#define PER_UART2_TXDAT_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_data              :  8 ; /* bits 7:0 */
    u32 send_break           :  1 ; /* bits 8:8 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} PER_UART2_TXDAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART2_RXDAT                          0xf4329224
#define PER_UART2_RXDAT_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_data_lat          :  8 ; /* bits 7:0 */
    u32 rx_data_vld          :  1 ; /* bits 8:8 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} PER_UART2_RXDAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART2_INFO                           0xf4329228
#define PER_UART2_INFO_dft                       0x0000000a

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_fifo_full         :  1 ; /* bits 0:0 */
    u32 rx_fifo_empty        :  1 ; /* bits 1:1 */
    u32 tx_fifo_full         :  1 ; /* bits 2:2 */
    u32 tx_fifo_empty        :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} PER_UART2_INFO_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART2_IE_0                           0xf432922c
#define PER_UART2_IE_0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    u32 rx_stop_erre         :  1 ; /* bits 1:1 */
    u32 rx_parity_erre       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    u32 rx_breake            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART2_IE_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART2_IE_1                           0xf4329230
#define PER_UART2_IE_1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    u32 rx_stop_erre         :  1 ; /* bits 1:1 */
    u32 rx_parity_erre       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    u32 rx_breake            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART2_IE_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART2_INT_0                          0xf4329234
#define PER_UART2_INT_0_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    u32 rx_stop_erri         :  1 ; /* bits 1:1 */
    u32 rx_parity_erri       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    u32 rx_breaki            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART2_INT_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART2_INT_1                          0xf4329238
#define PER_UART2_INT_1_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    u32 rx_stop_erri         :  1 ; /* bits 1:1 */
    u32 rx_parity_erri       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    u32 rx_breaki            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART2_INT_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART2_STAT                           0xf432923c
#define PER_UART2_STAT_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overruns     :  1 ; /* bits 0:0 */
    u32 rx_stop_errs         :  1 ; /* bits 1:1 */
    u32 rx_parity_errs       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overruns     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underruns    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptys       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptys    :  1 ; /* bits 6:6 */
    u32 rx_breaks            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART2_STAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART3_CFG                            0xf4329240
#define PER_UART3_CFG_dft                        0x00000003

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 char_cnt             :  2 ; /* bits 1:0 */
    u32 uart_stop_2bit       :  1 ; /* bits 2:2 */
    u32 even_parity_sel      :  1 ; /* bits 3:3 */
    u32 uart_parity_en       :  1 ; /* bits 4:4 */
    u32 tx_sm_enable         :  1 ; /* bits 5:5 */
    u32 rx_sm_enable         :  1 ; /* bits 6:6 */
    u32 uart_en              :  1 ; /* bits 7:7 */
    u32 baud_count           : 24 ; /* bits 31:8 */
  } bf ;
  u32     wrd ;
} PER_UART3_CFG_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART3_FC                             0xf4329244
#define PER_UART3_FC_dft                         0x00000588

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_wm                :  6 ; /* bits 5:0 */
    u32 inv_cts              :  1 ; /* bits 6:6 */
    u32 no_cts               :  1 ; /* bits 7:7 */
    u32 cts_reg              :  1 ; /* bits 8:8 */
    u32 inv_rts              :  1 ; /* bits 9:9 */
    u32 no_rts               :  1 ; /* bits 10:10 */
    u32 rsrvd1               : 21 ;
  } bf ;
  u32     wrd ;
} PER_UART3_FC_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART3_RX_SAMPLE                      0xf4329248
#define PER_UART3_RX_SAMPLE_dft                  0x0000000f

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_center            : 24 ; /* bits 23:0 */
    u32 rsrvd1               :  8 ;
  } bf ;
  u32     wrd ;
} PER_UART3_RX_SAMPLE_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART3_TUN                            0xf432924c
#define PER_UART3_TUN_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_fine_tune_ctl     :  8 ; /* bits 7:0 */
    u32 rx_tune_add          :  1 ; /* bits 8:8 */
    u32 rsrvd1               :  7 ;
    u32 tx_fine_tune_ctl     :  8 ; /* bits 23:16 */
    u32 tx_tune_add          :  1 ; /* bits 24:24 */
    u32 rsrvd2               :  7 ;
  } bf ;
  u32     wrd ;
} PER_UART3_TUN_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART3_TXDAT                          0xf4329250
#define PER_UART3_TXDAT_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_data              :  8 ; /* bits 7:0 */
    u32 send_break           :  1 ; /* bits 8:8 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} PER_UART3_TXDAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART3_RXDAT                          0xf4329254
#define PER_UART3_RXDAT_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_data_lat          :  8 ; /* bits 7:0 */
    u32 rx_data_vld          :  1 ; /* bits 8:8 */
    u32 rsrvd1               : 23 ;
  } bf ;
  u32     wrd ;
} PER_UART3_RXDAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART3_INFO                           0xf4329258
#define PER_UART3_INFO_dft                       0x0000000a

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rx_fifo_full         :  1 ; /* bits 0:0 */
    u32 rx_fifo_empty        :  1 ; /* bits 1:1 */
    u32 tx_fifo_full         :  1 ; /* bits 2:2 */
    u32 tx_fifo_empty        :  1 ; /* bits 3:3 */
    u32 rsrvd1               : 28 ;
  } bf ;
  u32     wrd ;
} PER_UART3_INFO_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART3_IE_0                           0xf432925c
#define PER_UART3_IE_0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    u32 rx_stop_erre         :  1 ; /* bits 1:1 */
    u32 rx_parity_erre       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    u32 rx_breake            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART3_IE_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART3_IE_1                           0xf4329260
#define PER_UART3_IE_1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overrune     :  1 ; /* bits 0:0 */
    u32 rx_stop_erre         :  1 ; /* bits 1:1 */
    u32 rx_parity_erre       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overrune     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underrune    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptye       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptye    :  1 ; /* bits 6:6 */
    u32 rx_breake            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART3_IE_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART3_INT_0                          0xf4329264
#define PER_UART3_INT_0_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    u32 rx_stop_erri         :  1 ; /* bits 1:1 */
    u32 rx_parity_erri       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    u32 rx_breaki            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART3_INT_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART3_INT_1                          0xf4329268
#define PER_UART3_INT_1_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overruni     :  1 ; /* bits 0:0 */
    u32 rx_stop_erri         :  1 ; /* bits 1:1 */
    u32 rx_parity_erri       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overruni     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underruni    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptyi       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptyi    :  1 ; /* bits 6:6 */
    u32 rx_breaki            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART3_INT_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_UART3_STAT                           0xf432926c
#define PER_UART3_STAT_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tx_fifo_overruns     :  1 ; /* bits 0:0 */
    u32 rx_stop_errs         :  1 ; /* bits 1:1 */
    u32 rx_parity_errs       :  1 ; /* bits 2:2 */
    u32 rx_fifo_overruns     :  1 ; /* bits 3:3 */
    u32 rx_fifo_underruns    :  1 ; /* bits 4:4 */
    u32 tx_fifo_emptys       :  1 ; /* bits 5:5 */
    u32 rx_fifo_nonemptys    :  1 ; /* bits 6:6 */
    u32 rx_breaks            :  1 ; /* bits 7:7 */
    u32 rsrvd1               : 24 ;
  } bf ;
  u32     wrd ;
} PER_UART3_STAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_TOD_CFG                              0xf4329270
#define PER_TOD_CFG_dft                          0x00000026

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tod_counter          :  6 ; /* bits 5:0 */
    u32 rsrvd1               :  1 ;
    u32 tod_en               :  1 ; /* bits 7:7 */
    u32 tod_uart             :  2 ; /* bits 9:8 */
    u32 rsrvd2               : 22 ;
  } bf ;
  u32     wrd ;
} PER_TOD_CFG_t;
#endif /* !__ASSEMBLER__ */
#define PER_TOD_MEM                              0xf4329280
#define PER_TOD_MEM_STRIDE                       4
#define PER_TOD_MEM_COUNT                        16
#define PER_TOD_MEM_dft                          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 tod_bst_mem          : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_TOD_MEM_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO0_CFG                            0xf43292c0
#define PER_GPIO0_CFG_dft                        0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 iopmod               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO0_CFG_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO0_OUT                            0xf43292c4
#define PER_GPIO0_OUT_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dataout              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO0_OUT_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO0_IN                             0xf43292c8
#define PER_GPIO0_IN_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 iopdata              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO0_IN_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO0_LVL                            0xf43292cc
#define PER_GPIO0_LVL_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 level                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO0_LVL_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO0_EDGE                           0xf43292d0
#define PER_GPIO0_EDGE_dft                       0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 i_edge               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO0_EDGE_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO0_BOTHEDGE                       0xf43292d4
#define PER_GPIO0_BOTHEDGE_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 i_bothedge           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO0_BOTHEDGE_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO0_IE                             0xf43292d8
#define PER_GPIO0_IE_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpioe                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO0_IE_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO0_INT                            0xf43292dc
#define PER_GPIO0_INT_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpioi                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO0_INT_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO0_STAT                           0xf43292e0
#define PER_GPIO0_STAT_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpios                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO0_STAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO1_CFG                            0xf43292e4
#define PER_GPIO1_CFG_dft                        0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 iopmod               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO1_CFG_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO1_OUT                            0xf43292e8
#define PER_GPIO1_OUT_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dataout              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO1_OUT_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO1_IN                             0xf43292ec
#define PER_GPIO1_IN_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 iopdata              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO1_IN_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO1_LVL                            0xf43292f0
#define PER_GPIO1_LVL_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 level                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO1_LVL_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO1_EDGE                           0xf43292f4
#define PER_GPIO1_EDGE_dft                       0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 i_edge               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO1_EDGE_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO1_BOTHEDGE                       0xf43292f8
#define PER_GPIO1_BOTHEDGE_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 i_bothedge           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO1_BOTHEDGE_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO1_IE                             0xf43292fc
#define PER_GPIO1_IE_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpioe                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO1_IE_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO1_INT                            0xf4329300
#define PER_GPIO1_INT_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpioi                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO1_INT_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO1_STAT                           0xf4329304
#define PER_GPIO1_STAT_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpios                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO1_STAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO2_CFG                            0xf4329308
#define PER_GPIO2_CFG_dft                        0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 iopmod               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO2_CFG_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO2_OUT                            0xf432930c
#define PER_GPIO2_OUT_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dataout              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO2_OUT_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO2_IN                             0xf4329310
#define PER_GPIO2_IN_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 iopdata              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO2_IN_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO2_LVL                            0xf4329314
#define PER_GPIO2_LVL_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 level                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO2_LVL_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO2_EDGE                           0xf4329318
#define PER_GPIO2_EDGE_dft                       0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 i_edge               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO2_EDGE_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO2_BOTHEDGE                       0xf432931c
#define PER_GPIO2_BOTHEDGE_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 i_bothedge           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO2_BOTHEDGE_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO2_IE                             0xf4329320
#define PER_GPIO2_IE_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpioe                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO2_IE_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO2_INT                            0xf4329324
#define PER_GPIO2_INT_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpioi                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO2_INT_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO2_STAT                           0xf4329328
#define PER_GPIO2_STAT_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpios                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO2_STAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO3_CFG                            0xf432932c
#define PER_GPIO3_CFG_dft                        0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 iopmod               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO3_CFG_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO3_OUT                            0xf4329330
#define PER_GPIO3_OUT_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dataout              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO3_OUT_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO3_IN                             0xf4329334
#define PER_GPIO3_IN_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 iopdata              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO3_IN_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO3_LVL                            0xf4329338
#define PER_GPIO3_LVL_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 level                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO3_LVL_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO3_EDGE                           0xf432933c
#define PER_GPIO3_EDGE_dft                       0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 i_edge               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO3_EDGE_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO3_BOTHEDGE                       0xf4329340
#define PER_GPIO3_BOTHEDGE_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 i_bothedge           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO3_BOTHEDGE_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO3_IE                             0xf4329344
#define PER_GPIO3_IE_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpioe                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO3_IE_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO3_INT                            0xf4329348
#define PER_GPIO3_INT_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpioi                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO3_INT_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO3_STAT                           0xf432934c
#define PER_GPIO3_STAT_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpios                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO3_STAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO4_CFG                            0xf4329350
#define PER_GPIO4_CFG_dft                        0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 iopmod               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO4_CFG_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO4_OUT                            0xf4329354
#define PER_GPIO4_OUT_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dataout              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO4_OUT_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO4_IN                             0xf4329358
#define PER_GPIO4_IN_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 iopdata              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO4_IN_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO4_LVL                            0xf432935c
#define PER_GPIO4_LVL_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 level                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO4_LVL_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO4_EDGE                           0xf4329360
#define PER_GPIO4_EDGE_dft                       0xffffffff

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 i_edge               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO4_EDGE_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO4_BOTHEDGE                       0xf4329364
#define PER_GPIO4_BOTHEDGE_dft                   0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 i_bothedge           : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO4_BOTHEDGE_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO4_IE                             0xf4329368
#define PER_GPIO4_IE_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpioe                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO4_IE_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO4_INT                            0xf432936c
#define PER_GPIO4_INT_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpioi                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO4_INT_t;
#endif /* !__ASSEMBLER__ */
#define PER_GPIO4_STAT                           0xf4329370
#define PER_GPIO4_STAT_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gpios                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_GPIO4_STAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER1                           0xf4329374
#define PER_SYS_TIMER1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gtimer1              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER1_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER0                           0xf4329378
#define PER_SYS_TIMER0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 gtimer0              : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER0_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_COMPARATOR_CPU_01          0xf432937c
#define PER_SYS_TIMER_COMPARATOR_CPU_01_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 comp1                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_COMPARATOR_CPU_01_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_COMPARATOR_CPU_00          0xf4329380
#define PER_SYS_TIMER_COMPARATOR_CPU_00_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 comp0                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_COMPARATOR_CPU_00_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_AUTOINC_CPU_01             0xf4329384
#define PER_SYS_TIMER_AUTOINC_CPU_01_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 autoinc1             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_AUTOINC_CPU_01_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_AUTOINC_CPU_00             0xf4329388
#define PER_SYS_TIMER_AUTOINC_CPU_00_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 autoinc0             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_AUTOINC_CPU_00_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_CPU_0_INTENABLE            0xf432938c
#define PER_SYS_TIMER_CPU_0_INTENABLE_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 systimere            :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_CPU_0_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_CPU_0_INTERRUPT            0xf4329390
#define PER_SYS_TIMER_CPU_0_INTERRUPT_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 systimeri            :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_CPU_0_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_COMPARATOR_CPU_11          0xf4329394
#define PER_SYS_TIMER_COMPARATOR_CPU_11_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 comp1                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_COMPARATOR_CPU_11_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_COMPARATOR_CPU_10          0xf4329398
#define PER_SYS_TIMER_COMPARATOR_CPU_10_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 comp0                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_COMPARATOR_CPU_10_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_AUTOINC_CPU_11             0xf432939c
#define PER_SYS_TIMER_AUTOINC_CPU_11_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 autoinc1             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_AUTOINC_CPU_11_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_AUTOINC_CPU_10             0xf43293a0
#define PER_SYS_TIMER_AUTOINC_CPU_10_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 autoinc0             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_AUTOINC_CPU_10_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_CPU_1_INTENABLE            0xf43293a4
#define PER_SYS_TIMER_CPU_1_INTENABLE_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 systimere            :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_CPU_1_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_CPU_1_INTERRUPT            0xf43293a8
#define PER_SYS_TIMER_CPU_1_INTERRUPT_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 systimeri            :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_CPU_1_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_COMPARATOR_CPU_21          0xf43293ac
#define PER_SYS_TIMER_COMPARATOR_CPU_21_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 comp1                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_COMPARATOR_CPU_21_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_COMPARATOR_CPU_20          0xf43293b0
#define PER_SYS_TIMER_COMPARATOR_CPU_20_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 comp0                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_COMPARATOR_CPU_20_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_AUTOINC_CPU_21             0xf43293b4
#define PER_SYS_TIMER_AUTOINC_CPU_21_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 autoinc1             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_AUTOINC_CPU_21_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_AUTOINC_CPU_20             0xf43293b8
#define PER_SYS_TIMER_AUTOINC_CPU_20_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 autoinc0             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_AUTOINC_CPU_20_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_CPU_2_INTENABLE            0xf43293bc
#define PER_SYS_TIMER_CPU_2_INTENABLE_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 systimere            :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_CPU_2_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_CPU_2_INTERRUPT            0xf43293c0
#define PER_SYS_TIMER_CPU_2_INTERRUPT_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 systimeri            :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_CPU_2_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_COMPARATOR_CPU_31          0xf43293c4
#define PER_SYS_TIMER_COMPARATOR_CPU_31_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 comp1                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_COMPARATOR_CPU_31_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_COMPARATOR_CPU_30          0xf43293c8
#define PER_SYS_TIMER_COMPARATOR_CPU_30_dft      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 comp0                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_COMPARATOR_CPU_30_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_AUTOINC_CPU_31             0xf43293cc
#define PER_SYS_TIMER_AUTOINC_CPU_31_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 autoinc1             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_AUTOINC_CPU_31_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_AUTOINC_CPU_30             0xf43293d0
#define PER_SYS_TIMER_AUTOINC_CPU_30_dft         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 autoinc0             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_AUTOINC_CPU_30_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_CPU_3_INTENABLE            0xf43293d4
#define PER_SYS_TIMER_CPU_3_INTENABLE_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 systimere            :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_CPU_3_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_CPU_3_INTERRUPT            0xf43293d8
#define PER_SYS_TIMER_CPU_3_INTERRUPT_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 systimeri            :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_CPU_3_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_COMPARATOR_SECURE1         0xf43293dc
#define PER_SYS_TIMER_COMPARATOR_SECURE1_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 comp1                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_COMPARATOR_SECURE1_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_COMPARATOR_SECURE0         0xf43293e0
#define PER_SYS_TIMER_COMPARATOR_SECURE0_dft     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 comp0                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_COMPARATOR_SECURE0_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_AUTOINC_SECURE1            0xf43293e4
#define PER_SYS_TIMER_AUTOINC_SECURE1_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 autoinc1             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_AUTOINC_SECURE1_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_AUTOINC_SECURE0            0xf43293e8
#define PER_SYS_TIMER_AUTOINC_SECURE0_dft        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 autoinc0             : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_AUTOINC_SECURE0_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_SECURE_INTENABLE           0xf43293ec
#define PER_SYS_TIMER_SECURE_INTENABLE_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 systimere            :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_SECURE_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define PER_SYS_TIMER_SECURE_INTERRUPT           0xf43293f0
#define PER_SYS_TIMER_SECURE_INTERRUPT_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 systimeri            :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_SYS_TIMER_SECURE_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define PER_PWM_TIMER_PERIOD_0                   0xf43293f4
#define PER_PWM_TIMER_PERIOD_0_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 period               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_PWM_TIMER_PERIOD_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_PWM_TIMER_COMP_0                     0xf43293f8
#define PER_PWM_TIMER_COMP_0_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 comp                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_PWM_TIMER_COMP_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_PWM_TIMER_PERIOD_1                   0xf43293fc
#define PER_PWM_TIMER_PERIOD_1_dft               0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 period               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_PWM_TIMER_PERIOD_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_PWM_TIMER_COMP_1                     0xf4329400
#define PER_PWM_TIMER_COMP_1_dft                 0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 comp                 : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_PWM_TIMER_COMP_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_CSPI_CLK                             0xf4329404
#define PER_CSPI_CLK_dft                         0x00000002

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 divisor              : 16 ; /* bits 15:0 */
    u32 rsrvd1               : 14 ;
    u32 cpha                 :  1 ; /* bits 30:30 */
    u32 cpol                 :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} PER_CSPI_CLK_t;
#endif /* !__ASSEMBLER__ */
#define PER_CSPI_FMT                             0xf4329408
#define PER_CSPI_FMT_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 highbit              :  6 ; /* bits 5:0 */
    u32 rsrvd1               :  2 ;
    u32 frontporch           :  8 ; /* bits 15:8 */
    u32 backporch            :  8 ; /* bits 23:16 */
    u32 gap                  :  8 ; /* bits 31:24 */
  } bf ;
  u32     wrd ;
} PER_CSPI_FMT_t;
#endif /* !__ASSEMBLER__ */
#define PER_CSPI_CS                              0xf432940c
#define PER_CSPI_CS_dft                          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 enable               :  5 ; /* bits 4:0 */
    u32 rsrvd1               :  3 ;
    u32 active_hi            :  5 ; /* bits 12:8 */
    u32 rsrvd2               : 18 ;
    u32 force                :  1 ; /* bits 31:31 */
  } bf ;
  u32     wrd ;
} PER_CSPI_CS_t;
#endif /* !__ASSEMBLER__ */
#define PER_CSPI_WDATA1                          0xf4329410
#define PER_CSPI_WDATA1_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wdata1               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_CSPI_WDATA1_t;
#endif /* !__ASSEMBLER__ */
#define PER_CSPI_WDATA0                          0xf4329414
#define PER_CSPI_WDATA0_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 wdata0               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_CSPI_WDATA0_t;
#endif /* !__ASSEMBLER__ */
#define PER_CSPI_RDATA1                          0xf4329418
#define PER_CSPI_RDATA1_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rdata1               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_CSPI_RDATA1_t;
#endif /* !__ASSEMBLER__ */
#define PER_CSPI_RDATA0                          0xf432941c
#define PER_CSPI_RDATA0_dft                      0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 rdata0               : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_CSPI_RDATA0_t;
#endif /* !__ASSEMBLER__ */
#define PER_CSPI_CONTROL                         0xf4329420
#define PER_CSPI_CONTROL_dft                     0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 start                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_CSPI_CONTROL_t;
#endif /* !__ASSEMBLER__ */
#define PER_CSPI_IE_0                            0xf4329424
#define PER_CSPI_IE_0_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cspie                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_CSPI_IE_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_CSPI_INT_0                           0xf4329428
#define PER_CSPI_INT_0_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cspii                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_CSPI_INT_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_CSPI_IE_1                            0xf432942c
#define PER_CSPI_IE_1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cspie                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_CSPI_IE_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_CSPI_INT_1                           0xf4329430
#define PER_CSPI_INT_1_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cspii                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_CSPI_INT_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_CSPI_STAT                            0xf4329434
#define PER_CSPI_STAT_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 cspis                :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_CSPI_STAT_t;
#endif /* !__ASSEMBLER__ */
#define PER_SECURE_WDT_TIMER_INTENABLE           0xf4329438
#define PER_SECURE_WDT_TIMER_INTENABLE_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 secure_wdte          :  1 ; /* bits 0:0 */
    u32 secure_timere        :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} PER_SECURE_WDT_TIMER_INTENABLE_t;
#endif /* !__ASSEMBLER__ */
#define PER_SECURE_WDT_TIMER_INTERRUPT           0xf432943c
#define PER_SECURE_WDT_TIMER_INTERRUPT_dft       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 secure_wdti          :  1 ; /* bits 0:0 */
    u32 secure_timeri        :  1 ; /* bits 1:1 */
    u32 rsrvd1               : 30 ;
  } bf ;
  u32     wrd ;
} PER_SECURE_WDT_TIMER_INTERRUPT_t;
#endif /* !__ASSEMBLER__ */
#define PER_DYING_GASP                           0xf4329440
#define PER_DYING_GASP_dft                       0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dg_ifsel             :  3 ; /* bits 2:0 */
    u32 dg_bitsel            :  5 ; /* bits 7:3 */
    u32 dg_enable            :  1 ; /* bits 8:8 */
    u32 dg_pol               :  1 ; /* bits 9:9 */
    u32 rsrvd1               : 22 ;
  } bf ;
  u32     wrd ;
} PER_DYING_GASP_t;
#endif /* !__ASSEMBLER__ */
#define PER_DG_IE_0                              0xf4329444
#define PER_DG_IE_0_dft                          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dge                  :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_DG_IE_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_DG_INT_0                             0xf4329448
#define PER_DG_INT_0_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dgi                  :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_DG_INT_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_DG_STAT_0                            0xf432944c
#define PER_DG_STAT_0_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dgs                  :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_DG_STAT_0_t;
#endif /* !__ASSEMBLER__ */
#define PER_DG_IE_1                              0xf4329450
#define PER_DG_IE_1_dft                          0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dge                  :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_DG_IE_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_DG_INT_1                             0xf4329454
#define PER_DG_INT_1_dft                         0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dgi                  :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_DG_INT_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_DG_STAT_1                            0xf4329458
#define PER_DG_STAT_1_dft                        0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 dgs                  :  1 ; /* bits 0:0 */
    u32 rsrvd1               : 31 ;
  } bf ;
  u32     wrd ;
} PER_DG_STAT_1_t;
#endif /* !__ASSEMBLER__ */
#define PER_SPARE                                0xf432945c
#define PER_SPARE_dft                            0x00000000

#ifndef __ASSEMBLER__
typedef volatile union {
  struct {
    u32 spare                : 32 ; /* bits 31:0 */
  } bf ;
  u32     wrd ;
} PER_SPARE_t;
#endif /* !__ASSEMBLER__ */

#endif /* __ARCH_ARM_INCLUDE_ASM_ARCH_RTL9617C_REGISTERS_H__ */
