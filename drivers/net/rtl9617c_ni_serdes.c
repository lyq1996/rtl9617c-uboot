// SPDX-License-Identifier: GPL-2.0+

/*
 * Copyright (C) 2022 Realtek Semiconductor Corp.
 *
 * Ethernet MAC driver for the Realtek RTL9617C
 */

#include <config.h>
#include <dm.h>
#include <env.h>
#include <init.h>
#include <stdio.h>
#include <vsprintf.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <asm/arch/registers.h>
#include <asm/arch/soc.h>
#include <phy.h>
#include <linux/delay.h>
#include <linux/ethtool.h>
#include <rtl9617c_ni.h>
#include "rtl9617c_ni_priv.h"

#include "rtl9617c_ni_regs.h"

static void __p4_sds_1g_patch(void)
{
	uint32_t value;

	/* 0xF433B204 Bit[5:0]CDR_KP=[110000] */
	value = CA_NE_SGMII_LP_REG_READ(0xF433B204);
	value = (value & ~(0x3f)) | 0x30;
	CA_NE_SGMII_LP_REG_WRITE(value, 0xF433B204);

	/* 0xF433B20C Bit[5:1]OOBS_SEN_VAL=[11100] */
	value = CA_NE_SGMII_LP_REG_READ(0xF433B20C);
	value = (value & ~(0x1f << 1)) | (0x1c << 1);
	CA_NE_SGMII_LP_REG_WRITE(value, 0xF433B20C);

	/* 0xF433B218 Bit[4:0]CMU_CP_ISEL=[11111] */
	value = CA_NE_SGMII_LP_REG_READ(0xF433B218);
	value = (value & ~(0x1f)) | 0x1f;
	CA_NE_SGMII_LP_REG_WRITE(value, 0xF433B218);

	/* 0xF433B228 Bit[14:12]CMU_SR=[111] */
	value = CA_NE_SGMII_LP_REG_READ(0xF433B228);
	value = (value & ~(0x7 << 12)) | (0x7 << 12);
	CA_NE_SGMII_LP_REG_WRITE(value, 0xF433B228);

	CA_NE_SGMII_LP_REG_WRITE(0x000034AA, 0xF433B240);
	CA_NE_SGMII_LP_REG_WRITE(0x000088AA, 0xF433B244);
	CA_NE_SGMII_LP_REG_WRITE(0x00000053, 0xF433B248);
	CA_NE_SGMII_LP_REG_WRITE(0x00008008, 0xF433B27C);

	/* 0xF433B24C  Bit[15:12]TX_TERM=[0000] */
	value = CA_NE_SGMII_LP_REG_READ(0xF433B24C);
	value = (value & ~(0xf << 12)) | (0x0 << 12);
	CA_NE_SGMII_LP_REG_WRITE(value, 0xF433B24C);

	return;
}

static void __p4_sds_2g5_patch(void)
{
	uint32_t value;

	/* 0xF433B404 Bit[5:0]CDR_KP=[010000] */
	value = CA_NE_SGMII_LP_REG_READ(0xF433B404);
	value = (value & ~(0x3f)) | 0x10;
	CA_NE_SGMII_LP_REG_WRITE(value, 0xF433B404);

	/* 0xF433B40C Bit[5:1]OOBS_SEN_VAL=[11100] */
	value = CA_NE_SGMII_LP_REG_READ(0xF433B40C);
	value = (value & ~(0x1f << 1)) | (0x1c << 1);
	CA_NE_SGMII_LP_REG_WRITE(value, 0xF433B40C);

	/* 0xF433B418 Bit[4:0]CMU_CP_ISEL=[11111] */
	value = CA_NE_SGMII_LP_REG_READ(0xF433B418);
	value = (value & ~(0x1f)) | 0x1f;
	CA_NE_SGMII_LP_REG_WRITE(value, 0xF433B418);

	/* 0xF433B428 Bit[14:12]CMU_SR=[111] */
	value = CA_NE_SGMII_LP_REG_READ(0xF433B428);
	value = (value & ~(0x7 << 12)) | (0x7 << 12);
	CA_NE_SGMII_LP_REG_WRITE(value, 0xF433B428);

	CA_NE_SGMII_LP_REG_WRITE(0x000034AA, 0xF433B440);
	CA_NE_SGMII_LP_REG_WRITE(0x000088AA, 0xF433B444);
	CA_NE_SGMII_LP_REG_WRITE(0x00000053, 0xF433B448);
	CA_NE_SGMII_LP_REG_WRITE(0x00008008, 0xF433B47C);

	/* 0xF433B44C Bit[15:12]TX_TERM=[0000] */
	value = CA_NE_SGMII_LP_REG_READ(0xF433B44C);
	value = (value & ~(0xf << 12)) | (0x0 << 12);
	CA_NE_SGMII_LP_REG_WRITE(value, 0xF433B44C);

	return;
}

static int __p4_sds_mode_set(aal_sds_mode_t mode, aal_sds_speed_t speed)
{
	GLOBAL_PHY_CONTROL_t glb_phy_ctrl;
	GLOBAL_DPHY_RESET_t glb_dphy_reset;
	GLOBAL_PHY_SGMII_PCS_CONTROL_t glb_sgmii_pcs_ctrl;

	switch (mode) {
	case AAL_SDS_MODE_NONE:
		/* SDS mode */
		glb_dphy_reset.wrd = AAL_GLB_REG_READ(GLOBAL_DPHY_RESET);
		glb_dphy_reset.bf.reset_dphy_s3_sgmii = 1;
		glb_dphy_reset.bf.reset_sgmii = 1;
		AAL_GLB_REG_WRITE(glb_dphy_reset.wrd, GLOBAL_DPHY_RESET);

		glb_phy_ctrl.wrd = AAL_GLB_REG_READ(GLOBAL_PHY_CONTROL);
		glb_phy_ctrl.bf.s3_pcie_usb3_sgmii_sel = 0;
		AAL_GLB_REG_WRITE(glb_phy_ctrl.wrd, GLOBAL_PHY_CONTROL);
		break;

	case AAL_SDS_MODE_SGMII:
		switch (speed) {
		case AAL_SDS_SPEED_DEFAULT:
		case AAL_SDS_SPEED_1G:
			/* Disable SDS */
			glb_phy_ctrl.wrd = AAL_GLB_REG_READ(GLOBAL_PHY_CONTROL);
			glb_phy_ctrl.bf.s3_pcie_usb3_sgmii_sel = 0;
			AAL_GLB_REG_WRITE(glb_phy_ctrl.wrd, GLOBAL_PHY_CONTROL);

			/* Reset SDS */
			glb_dphy_reset.wrd = AAL_GLB_REG_READ(GLOBAL_DPHY_RESET);
			glb_dphy_reset.bf.reset_dphy_s3_sgmii = 1;
			glb_dphy_reset.bf.reset_sgmii = 1;
			AAL_GLB_REG_WRITE(glb_dphy_reset.wrd, GLOBAL_DPHY_RESET);
			udelay(10);
			glb_dphy_reset.wrd = AAL_GLB_REG_READ(GLOBAL_DPHY_RESET);
			glb_dphy_reset.bf.reset_dphy_s3_sgmii = 0;
			glb_dphy_reset.bf.reset_sgmii = 0;
			AAL_GLB_REG_WRITE(glb_dphy_reset.wrd, GLOBAL_DPHY_RESET);
			udelay(10);

			__p4_sds_1g_patch();

			glb_phy_ctrl.wrd = AAL_GLB_REG_READ(GLOBAL_PHY_CONTROL);
			glb_phy_ctrl.bf.s3_pcie_usb3_sgmii_sel = 1;
			AAL_GLB_REG_WRITE(glb_phy_ctrl.wrd, GLOBAL_PHY_CONTROL);

			glb_sgmii_pcs_ctrl.wrd = AAL_GLB_REG_READ(GLOBAL_PHY_SGMII_PCS_CONTROL);
			glb_sgmii_pcs_ctrl.bf.sgmii_sds_mode0 = 0x2;
			glb_sgmii_pcs_ctrl.bf.sgmii_cf_spd0x = 0x2;
			glb_sgmii_pcs_ctrl.bf.sgmii_sds0_ablty = 0x14002;
			AAL_GLB_REG_WRITE(glb_sgmii_pcs_ctrl.wrd, GLOBAL_PHY_SGMII_PCS_CONTROL);
			break;

		case AAL_SDS_SPEED_100M:
			/* Disable SDS */
			glb_phy_ctrl.wrd = AAL_GLB_REG_READ(GLOBAL_PHY_CONTROL);
			glb_phy_ctrl.bf.s3_pcie_usb3_sgmii_sel = 0;
			AAL_GLB_REG_WRITE(glb_phy_ctrl.wrd, GLOBAL_PHY_CONTROL);

			/* Reset SDS */
			glb_dphy_reset.wrd = AAL_GLB_REG_READ(GLOBAL_DPHY_RESET);
			glb_dphy_reset.bf.reset_dphy_s3_sgmii = 1;
			glb_dphy_reset.bf.reset_sgmii = 1;
			AAL_GLB_REG_WRITE(glb_dphy_reset.wrd, GLOBAL_DPHY_RESET);
			udelay(10);
			glb_dphy_reset.wrd = AAL_GLB_REG_READ(GLOBAL_DPHY_RESET);
			glb_dphy_reset.bf.reset_dphy_s3_sgmii = 0;
			glb_dphy_reset.bf.reset_sgmii = 0;
			AAL_GLB_REG_WRITE(glb_dphy_reset.wrd, GLOBAL_DPHY_RESET);
			udelay(10);

			__p4_sds_1g_patch();

			glb_phy_ctrl.wrd = AAL_GLB_REG_READ(GLOBAL_PHY_CONTROL);
			glb_phy_ctrl.bf.s3_pcie_usb3_sgmii_sel = 1;
			AAL_GLB_REG_WRITE(glb_phy_ctrl.wrd, GLOBAL_PHY_CONTROL);

			glb_sgmii_pcs_ctrl.wrd = AAL_GLB_REG_READ(GLOBAL_PHY_SGMII_PCS_CONTROL);
			glb_sgmii_pcs_ctrl.bf.sgmii_sds_mode0 = 0x2;
			glb_sgmii_pcs_ctrl.bf.sgmii_cf_spd0x = 0x1;
			glb_sgmii_pcs_ctrl.bf.sgmii_sds0_ablty = 0x14001;
			AAL_GLB_REG_WRITE(glb_sgmii_pcs_ctrl.wrd, GLOBAL_PHY_SGMII_PCS_CONTROL);
			break;

		case AAL_SDS_SPEED_10M:
			/* Disable SDS */
			glb_phy_ctrl.wrd = AAL_GLB_REG_READ(GLOBAL_PHY_CONTROL);
			glb_phy_ctrl.bf.s3_pcie_usb3_sgmii_sel = 0;
			AAL_GLB_REG_WRITE(glb_phy_ctrl.wrd, GLOBAL_PHY_CONTROL);

			/* Reset SDS */
			glb_dphy_reset.wrd = AAL_GLB_REG_READ(GLOBAL_DPHY_RESET);
			glb_dphy_reset.bf.reset_dphy_s3_sgmii = 1;
			glb_dphy_reset.bf.reset_sgmii = 1;
			AAL_GLB_REG_WRITE(glb_dphy_reset.wrd, GLOBAL_DPHY_RESET);
			udelay(10);
			glb_dphy_reset.wrd = AAL_GLB_REG_READ(GLOBAL_DPHY_RESET);
			glb_dphy_reset.bf.reset_dphy_s3_sgmii = 0;
			glb_dphy_reset.bf.reset_sgmii = 0;
			AAL_GLB_REG_WRITE(glb_dphy_reset.wrd, GLOBAL_DPHY_RESET);
			udelay(10);

			__p4_sds_1g_patch();

			glb_phy_ctrl.wrd = AAL_GLB_REG_READ(GLOBAL_PHY_CONTROL);
			glb_phy_ctrl.bf.s3_pcie_usb3_sgmii_sel = 1;
			AAL_GLB_REG_WRITE(glb_phy_ctrl.wrd, GLOBAL_PHY_CONTROL);

			glb_sgmii_pcs_ctrl.wrd = AAL_GLB_REG_READ(GLOBAL_PHY_SGMII_PCS_CONTROL);
			glb_sgmii_pcs_ctrl.bf.sgmii_sds_mode0 = 0x2;
			glb_sgmii_pcs_ctrl.bf.sgmii_cf_spd0x = 0x0;
			glb_sgmii_pcs_ctrl.bf.sgmii_sds0_ablty = 0x14000;
			AAL_GLB_REG_WRITE(glb_sgmii_pcs_ctrl.wrd, GLOBAL_PHY_SGMII_PCS_CONTROL);
			break;

		case AAL_SDS_SPEED_2G5:
			/* Disable SDS */
			glb_phy_ctrl.wrd = AAL_GLB_REG_READ(GLOBAL_PHY_CONTROL);
			glb_phy_ctrl.bf.s3_pcie_usb3_sgmii_sel = 0;
			AAL_GLB_REG_WRITE(glb_phy_ctrl.wrd, GLOBAL_PHY_CONTROL);

			/* Reset SDS */
			glb_dphy_reset.wrd = AAL_GLB_REG_READ(GLOBAL_DPHY_RESET);
			glb_dphy_reset.bf.reset_dphy_s3_sgmii = 1;
			glb_dphy_reset.bf.reset_sgmii = 1;
			AAL_GLB_REG_WRITE(glb_dphy_reset.wrd, GLOBAL_DPHY_RESET);
			udelay(10);
			glb_dphy_reset.wrd = AAL_GLB_REG_READ(GLOBAL_DPHY_RESET);
			glb_dphy_reset.bf.reset_dphy_s3_sgmii = 0;
			glb_dphy_reset.bf.reset_sgmii = 0;
			AAL_GLB_REG_WRITE(glb_dphy_reset.wrd, GLOBAL_DPHY_RESET);
			udelay(10);

			__p4_sds_2g5_patch();

			glb_phy_ctrl.wrd = AAL_GLB_REG_READ(GLOBAL_PHY_CONTROL);
			glb_phy_ctrl.bf.s3_pcie_usb3_sgmii_sel = 2;
			AAL_GLB_REG_WRITE(glb_phy_ctrl.wrd, GLOBAL_PHY_CONTROL);

			glb_sgmii_pcs_ctrl.wrd = AAL_GLB_REG_READ(GLOBAL_PHY_SGMII_PCS_CONTROL);
			glb_sgmii_pcs_ctrl.bf.sgmii_sds_mode0 = 0x12;
			glb_sgmii_pcs_ctrl.bf.sgmii_sds0_ablty = 0x01001;
			glb_sgmii_pcs_ctrl.bf.sgmii_cf_spd0x = 0x5;
			glb_sgmii_pcs_ctrl.bf.sgmii_spdup_ini = 1;
			AAL_GLB_REG_WRITE(glb_sgmii_pcs_ctrl.wrd, GLOBAL_PHY_SGMII_PCS_CONTROL);
			break;

		default:
			return CA_E_PARAM;
		}

		break;

	default:
		return CA_E_PARAM;
	}

	return CA_E_OK;
}

static void __p6_prof_load_from_file(void)
{
	CORTINA_CA_REG_WRITE(0x00004802, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000420, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000421, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000422, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000423, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000f0f0, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000424, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000f0f0, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000425, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000f0f0, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000426, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000f0f0, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000427, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000428, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000429, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000304, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000042a, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000180, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000042b, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000ffff, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000042c, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000042d, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000042e, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000f000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000042f, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00001800, 0xf550d050);
	CORTINA_CA_REG_WRITE(0x00001800, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000430, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000ffd0, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000431, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000b87e, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000432, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000e005, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000433, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000401, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000434, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00001000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000435, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00004000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000436, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000437, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000438, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000439, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000043a, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000043b, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000043c, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000043d, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000043e, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000043f, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006c0, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000ff00, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006c1, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000ff01, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006c2, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006c3, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000ff00, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006c4, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006c5, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006c6, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006c7, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006c8, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006c9, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006ca, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006cb, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006cc, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006cd, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006ce, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006cf, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006d0, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006d1, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006d2, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006d3, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006d4, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006d5, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006d6, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006d7, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006d8, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006d9, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006da, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006db, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006dc, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006dd, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006de, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00006df, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00009a45, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005c0, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00003c30, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005c1, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000f0f0, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005c2, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000f0f9, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005c3, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00001e40, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005c4, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000878c, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005c5, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00001dc8, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005c6, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00003224, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005c7, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000d125, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005c8, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00002504, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005c9, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00004000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005ca, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00002424, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005cb, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00004a12, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005cc, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00005f04, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005cd, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000056, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005ce, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00004c58, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005cf, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x000089b3, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005d0, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000f0ae, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005d1, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000f060, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005d2, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00001e22, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005d3, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000200a, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005d4, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000fb69, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005d5, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00001597, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005d6, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000f0f0, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005d7, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000f0f2, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005d8, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000f0f0, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005d9, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00005ae8, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005da, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000100, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005db, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000f0f0, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005dc, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005dd, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000a128, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005de, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00004168, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005df, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005e0, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005e1, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005e2, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005e3, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005e4, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005e5, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005e6, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005e7, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005e8, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00005840, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005e9, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000ff27, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005ea, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000d800, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005eb, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000080, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005ec, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00008000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005ed, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00004000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005ee, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000180c, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005ef, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000004, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005f0, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x000003fc, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005f1, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x000086ff, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005f2, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000020, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005f3, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000f0ff, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005f4, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000ffff, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005f5, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000ffff, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005f6, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00003e00, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005f7, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005f8, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000500, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005f9, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x000007ff, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005fa, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000fe8, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005fb, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00003fdf, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005fc, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000001e, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005fd, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00008000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005fe, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc00005ff, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000018, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000780, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x000011e0, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000781, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x000003ff, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000782, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000233, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000783, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00004000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000784, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000785, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000786, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000035, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000787, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00001800, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000788, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00004000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000789, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000078a, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000294, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000078b, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000294, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000078c, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00008007, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000078d, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000012, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000078e, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000490b, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000078f, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x000001c7, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000790, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000791, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x0000fe00, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000792, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000793, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000007, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000794, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000795, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000796, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000797, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000798, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc0000799, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000079a, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000079b, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000079c, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000079d, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000079e, 0xf550d04c);
	CORTINA_CA_REG_WRITE(0x00000000, 0xf550d050);
	CORTINA_CA_REG_WRITE(0xc000079f, 0xf550d04c);
}

static void __p6_mac_10g_config(void)
{
	NI_HV_XGE_MISC_CONFIG_t xge_misc_cfg;
	NI_HV_XGE_MAC_CFG_COM_t xge_mac_cfg;
	NI_HV_XGE_MAC_CFG_TX_t xge_tx_cfg;
	NI_HV_XGE_MAC_CFG_TX_2_t xge_tx2_cfg;
	//NI_HV_XGE_MAC_CFG_RX_t xge_rx_cfg;
	//L2TM_L2TM_ES_CTRL_t tm_es_ctrl;
	//QM_QM_ES_CTRL_t qm_es_ctrl;
	NI_HV_GLB_NITX_MISC_CFG_t nitx_misc_cfg;

#if 0 ///--
	/* Stop traffic */
	tm_es_ctrl.wrd = CORTINA_CA_REG_READ(L2TM_L2TM_ES_CTRL);
	tm_es_ctrl.bf.tx_port6_en = 0;
	CORTINA_CA_REG_WRITE(tm_es_ctrl.wrd, L2TM_L2TM_ES_CTRL);
	qm_es_ctrl.wrd = CORTINA_CA_REG_READ(QM_QM_ES_CTRL);
	qm_es_ctrl.bf.ni_en &= ~(1 << 6);
	CORTINA_CA_REG_WRITE(qm_es_ctrl.wrd, QM_QM_ES_CTRL);
#endif

	/* Drain out packets */
	nitx_misc_cfg.wrd = CORTINA_CA_REG_READ(NI_HV_GLB_NITX_MISC_CFG);
	nitx_misc_cfg.bf.xge6_tx_drain = 1;
	CORTINA_CA_REG_WRITE(nitx_misc_cfg.wrd, NI_HV_GLB_NITX_MISC_CFG);

	/* interface select to init state */
	xge_misc_cfg.wrd = CORTINA_CA_REG_READ(NI_HV_XGE_MISC_CONFIG);
	xge_misc_cfg.bf.gige_mode = 0;
	xge_misc_cfg.bf.inf_sel = 0x0;
	CORTINA_CA_REG_WRITE(xge_misc_cfg.wrd, NI_HV_XGE_MISC_CONFIG);
	xge_misc_cfg.bf.gige_mode = 0;
	xge_misc_cfg.bf.inf_sel = 0x3;
	CORTINA_CA_REG_WRITE(xge_misc_cfg.wrd, NI_HV_XGE_MISC_CONFIG);

	mdelay(10);

	/* Tx IPG */
	xge_tx_cfg.wrd = CORTINA_CA_REG_READ(NI_HV_XGE_MAC_CFG_TX);
	xge_tx_cfg.bf.IFG_mode_tx = 0x1;
	CORTINA_CA_REG_WRITE(xge_tx_cfg.wrd, NI_HV_XGE_MAC_CFG_TX);
	/* Read thr */
	xge_tx2_cfg.wrd = CORTINA_CA_REG_READ(NI_HV_XGE_MAC_CFG_TX_2);
	xge_tx2_cfg.bf.fifo1_read_thr = 0xc;
	xge_tx2_cfg.bf.fifo1_thr_afull = 0xe;
	CORTINA_CA_REG_WRITE(xge_tx2_cfg.wrd, NI_HV_XGE_MAC_CFG_TX_2);
#if 0
	/* Rx */
	xge_rx_cfg.wrd = CA_NI_REG_READ(NI_HV_XGE_MAC_CFG_RX);
	xge_rx_cfg.wrd = 0xbc1;
	CA_NI_REG_WRITE(xge_rx_cfg.wrd, NI_HV_XGE_MAC_CFG_RX);
#endif
	/* Set MAC Tx/Rx resets */
	xge_mac_cfg.wrd = CORTINA_CA_REG_READ(NI_HV_XGE_MAC_CFG_COM);
	xge_mac_cfg.bf.tx_rst = 0x1;
	xge_mac_cfg.bf.rx_rst = 0x1;
	xge_mac_cfg.bf.cntr_rst = 0x0;
	xge_mac_cfg.bf.stats_err_order = 0x0;
	CORTINA_CA_REG_WRITE(xge_mac_cfg.wrd, NI_HV_XGE_MAC_CFG_COM);
	mdelay(10);
	/* Release MAC resets */
	xge_mac_cfg.wrd = CORTINA_CA_REG_READ(NI_HV_XGE_MAC_CFG_COM);
	xge_mac_cfg.bf.tx_rst = 0x0;
	xge_mac_cfg.bf.rx_rst = 0x0;
	xge_mac_cfg.bf.cntr_rst = 0x0;
	xge_mac_cfg.bf.stats_err_order = 0x0;
	CORTINA_CA_REG_WRITE(xge_mac_cfg.wrd, NI_HV_XGE_MAC_CFG_COM);

	/* interface select to 10G */
	xge_misc_cfg.wrd = CORTINA_CA_REG_READ(NI_HV_XGE_MISC_CONFIG);
	xge_misc_cfg.bf.gige_mode = 0;
	xge_misc_cfg.bf.inf_sel = 0x0;
	CORTINA_CA_REG_WRITE(xge_misc_cfg.wrd, NI_HV_XGE_MISC_CONFIG);
	xge_misc_cfg.bf.gige_mode = 0;
	xge_misc_cfg.bf.inf_sel = 0x2;
	CORTINA_CA_REG_WRITE(xge_misc_cfg.wrd, NI_HV_XGE_MISC_CONFIG);

	/* Stop drain out */
	nitx_misc_cfg.wrd = CORTINA_CA_REG_READ(NI_HV_GLB_NITX_MISC_CFG);
	nitx_misc_cfg.bf.xge6_tx_drain = 0;
	CORTINA_CA_REG_WRITE(nitx_misc_cfg.wrd, NI_HV_GLB_NITX_MISC_CFG);

#if 0 ///--
	/* Resume traffic */
	tm_es_ctrl.wrd = CORTINA_CA_REG_READ(L2TM_L2TM_ES_CTRL);
	tm_es_ctrl.bf.tx_port6_en = 1;
	CORTINA_CA_REG_WRITE(tm_es_ctrl.wrd, L2TM_L2TM_ES_CTRL);
	qm_es_ctrl.wrd = CORTINA_CA_REG_READ(QM_QM_ES_CTRL);
	qm_es_ctrl.bf.ni_en |= (1 << 6);
	CORTINA_CA_REG_WRITE(qm_es_ctrl.wrd, QM_QM_ES_CTRL);
#endif

	return;
}


static int __p6_serdes_ind_read(int page, int regaddr,
					u16 *pData)
{
	QX_REG_ACCESS_t sds_access;
	QX_REG_DATAOUT_t sds_dataout;

	if (!pData)
		return CA_E_PARAM;

	sds_access.wrd = CORTINA_CA_REG_READ(QX_REG_ACCESS);
	sds_access.bf.sds_a = ((page << 5) | (regaddr));
	sds_access.bf.sds_we = 0;
	sds_access.bf.sds_access = 1;
	CORTINA_CA_REG_WRITE(sds_access.wrd, QX_REG_ACCESS);

	/* Wait at least 100ns */
	mdelay(1);

	sds_dataout.wrd = CORTINA_CA_REG_READ(QX_REG_DATAOUT);
	*pData = sds_dataout.bf.sds_d_out;

	return CA_E_OK;
}

static int __p6_serdes_ind_write(int page, int regaddr, u16 data)
{
	QX_REG_ACCESS_t sds_access;
	QX_REG_DATAIN_t sds_datain;

	sds_datain.wrd = CORTINA_CA_REG_READ(QX_REG_DATAIN);
	sds_datain.bf.sds_d_in = data;
	CORTINA_CA_REG_WRITE(sds_datain.wrd, QX_REG_DATAIN);

	sds_access.wrd = CORTINA_CA_REG_READ(QX_REG_ACCESS);
	sds_access.bf.sds_a = ((page << 5) | (regaddr));
	sds_access.bf.sds_we = 1;
	sds_access.bf.sds_access = 1;
	CORTINA_CA_REG_WRITE(sds_access.wrd, QX_REG_ACCESS);

	/* Wait at least 100ns */
	mdelay(1);

	return CA_E_OK;
}

static bool __p6_checkSdsClkReady(void)
{
	QX_SDS_STATE_t qx_sds_state;
	int count = 1500;

	do {
		qx_sds_state.wrd = CORTINA_CA_REG_READ(QX_SDS_STATE);

		if (qx_sds_state.bf.CKRDY)
			return 1;

		mdelay(10);
		count --;
	} while (count >= 0);

	return 0;
}

#define QXGMII_REG_READ(off)                CA_REG_READ(off)
#define QXGMII_REG_WRITE(data, off)         CA_REG_WRITE(data, off)

static s32
ca_ni_p6_qxgmii_port_macForceAbility_set(u32 port, u32 speed)
{
	//int ret = CA_E_OK;
	u32 speed01, speed23, mac_reg;
	QX_CH0_ABILITY_t qx_ability0;
	QX_CH0_ABILITY_t qx_ability1;
	QX_CH0_ABILITY_t qx_ability2;
	QX_CH0_ABILITY_t qx_ability3;
	NI_HV_PT_PORT_GLB_CFG_t port_glb_cfg;

	speed01 = speed & 0x3;
	speed23 = speed >> 2;
	mac_reg = NI_HV_PT_PORT_GLB_CFG + port * APB0_NI_HV_PT_STRIDE;

	switch (port) {
	case 0:
	case 1:
	case 2:
	case 3:
		/* Stop MAC Tx/Rx */
		port_glb_cfg.wrd = QXGMII_REG_READ(mac_reg);
		port_glb_cfg.bf.power_dwn_tx = 1;
		port_glb_cfg.bf.power_dwn_rx = 1;
		QXGMII_REG_WRITE(port_glb_cfg.wrd, mac_reg);
		mdelay(100);
		break;

	default:
		return CA_E_PORT_ID;
	}

	switch (port) {
	case 0:
		qx_ability0.wrd = QXGMII_REG_READ(QX_CH0_ABILITY);
		qx_ability0.bf.sds01_sds0_ablty &= ~((0x3 << 12) | (0x3 << 0));
		qx_ability0.bf.sds01_sds0_ablty |= speed01 | (speed23 << 12);
		QXGMII_REG_WRITE(qx_ability0.wrd, QX_CH0_ABILITY);
		break;

	case 1:
		qx_ability1.wrd = QXGMII_REG_READ(QX_CH1_ABILITY);
		qx_ability1.bf.sds01_sds0_ablty &= ~((0x3 << 12) | (0x3 << 0));
		qx_ability1.bf.sds01_sds0_ablty |= speed01 | (speed23 << 12);
		QXGMII_REG_WRITE(qx_ability1.wrd, QX_CH1_ABILITY);
		break;

	case 2:
		qx_ability2.wrd = QXGMII_REG_READ(QX_CH2_ABILITY);
		qx_ability2.bf.sds01_sds0_ablty &= ~((0x3 << 12) | (0x3 << 0));
		qx_ability2.bf.sds01_sds0_ablty |= speed01 | (speed23 << 12);
		QXGMII_REG_WRITE(qx_ability2.wrd, QX_CH2_ABILITY);
		break;

	case 3:
		qx_ability3.wrd = QXGMII_REG_READ(QX_CH3_ABILITY);
		qx_ability3.bf.sds01_sds0_ablty &= ~((0x3 << 12) | (0x3 << 0));
		qx_ability3.bf.sds01_sds0_ablty |= speed01 | (speed23 << 12);
		QXGMII_REG_WRITE(qx_ability3.wrd, QX_CH3_ABILITY);
		break;
	}

	mdelay(100);

	/* Resum MAC Tx/Rx */
	port_glb_cfg.wrd = QXGMII_REG_READ(mac_reg);
	port_glb_cfg.bf.power_dwn_tx = 0;
	port_glb_cfg.bf.power_dwn_rx = 0;
	QXGMII_REG_WRITE(port_glb_cfg.wrd, mac_reg);

	return CA_E_OK;
}

static void ca_ni_p6_qxgmii_init(void)
{

	GLOBAL_BLOCK_RESET_t glb_blk_reset;
	QX_RESET_t qx_reset;
	QX_MODE_t qx_mode;
	QX_CH0_ABILITY_t qx_ch0_ability;
	QX_CH1_ABILITY_t qx_ch1_ability;
	QX_CH2_ABILITY_t qx_ch2_ability;
	QX_CH3_ABILITY_t qx_ch3_ability;
	NI_HV_GLB_STATIC_CFG_t ni_hv_glb_static_cfg;
	QX_MISC_CNTL_1_t qx_misc_cntl_1;
	//QX_SDS_STATE_t qx_sds_state;
	u16 data;

	// PHY reset GPIO: 9615C GPIO4[0]:
	// CORTINA_CA_REG_WRITE(0x1, GLOBAL_GPIO_MUX_4);
	// CORTINA_CA_REG_WRITE(0xfffffffe, PER_GPIO4_CFG);
	// CORTINA_CA_REG_WRITE(0x1, PER_GPIO4_OUT);
	//printk("%s\n", __func__);
	/*
	QXGMII init patch:
	mw 0xf4320098 0x503021c0
	mw 0xf550d004 0x0000104d
	mw 0xf550d008 0x00005cf5
	mw 0xf550d00c 0x00005cf5
	mw 0xf550d010 0x00005cf5
	mw 0xf550d014 0x00005cf5
	mw 0xf430a01c 0x3ae4f12f
	mw 0xf550d018 0x00002002

	>>>>>>
	mw 0xf550d000 0x00000000
	mw 0xf550d004 0x0000144d
	mw 0xf430b2a8 0x000000ff
	mw 0xf430b2a8 0x200000ff
	mw 0xf430b200 0x00000018
	mw 0xf430b208 0x00000001
	mw 0xf430b20c 0x00000c0e
	mw 0xf430b204 0x00000bc1
	<<<<<<
	*/

	/* Global reset */
	glb_blk_reset.wrd = CORTINA_CA_REG_READ(GLOBAL_BLOCK_RESET);
	glb_blk_reset.bf.reset_qxgmii = 1;
	CORTINA_CA_REG_WRITE(glb_blk_reset.wrd, GLOBAL_BLOCK_RESET);
	mdelay(50);
	/* Release reset */
	glb_blk_reset.wrd = CORTINA_CA_REG_READ(GLOBAL_BLOCK_RESET);
	glb_blk_reset.bf.reset_qxgmii = 0;
	CORTINA_CA_REG_WRITE(glb_blk_reset.wrd, GLOBAL_BLOCK_RESET);

	/* Digital SDS related configuration */
	/* Datapath reset */
	qx_reset.wrd = CORTINA_CA_REG_READ(QX_RESET);
	qx_reset.bf.dp_reset = 1;
	CORTINA_CA_REG_WRITE(qx_reset.wrd, QX_RESET);
	/* SDS mode off */
	qx_mode.wrd = CORTINA_CA_REG_READ(QX_MODE);
	qx_mode.bf.sds_mode_s0 = 0x1f;
	CORTINA_CA_REG_WRITE(qx_mode.wrd, QX_MODE);
	mdelay(50);

	/* SDS mode */
	qx_mode.wrd = CORTINA_CA_REG_READ(QX_MODE);
	qx_mode.bf.sds_mode_s0 = 0xd;
	qx_mode.bf.usx_sub_mx_s0 = 0x2;
	CORTINA_CA_REG_WRITE(qx_mode.wrd, QX_MODE);
	/* SDS ability */
	qx_ch0_ability.wrd = CORTINA_CA_REG_READ(QX_CH0_ABILITY);
	qx_ch0_ability.bf.sds01_sds0_ablty = 0x5cf5;
	CORTINA_CA_REG_WRITE(qx_ch0_ability.wrd, QX_CH0_ABILITY);
	qx_ch1_ability.wrd = CORTINA_CA_REG_READ(QX_CH1_ABILITY);
	qx_ch1_ability.bf.sds01_sds1_ablty = 0x5cf5;
	CORTINA_CA_REG_WRITE(qx_ch0_ability.wrd, QX_CH1_ABILITY);
	qx_ch2_ability.wrd = CORTINA_CA_REG_READ(QX_CH2_ABILITY);
	qx_ch2_ability.bf.sds01_sds2_ablty = 0x5cf5;
	CORTINA_CA_REG_WRITE(qx_ch0_ability.wrd, QX_CH2_ABILITY);
	qx_ch3_ability.wrd = CORTINA_CA_REG_READ(QX_CH3_ABILITY);
	qx_ch3_ability.bf.sds01_sds3_ablty = 0x5cf5;
	CORTINA_CA_REG_WRITE(qx_ch0_ability.wrd, QX_CH3_ABILITY);

	/* Select MAC source */
	ni_hv_glb_static_cfg.wrd = CORTINA_CA_REG_READ(NI_HV_GLB_STATIC_CFG);
	ni_hv_glb_static_cfg.bf.port0_qxgmii_sel = 1;
	ni_hv_glb_static_cfg.bf.port1_qxgmii_sel = 1;
	ni_hv_glb_static_cfg.bf.port2_qxgmii_sel = 1;
	ni_hv_glb_static_cfg.bf.port3_qxgmii_sel = 1;
	CORTINA_CA_REG_WRITE(ni_hv_glb_static_cfg.wrd, NI_HV_GLB_STATIC_CFG);
	//printf("%s(%d): CFG=%x\n",__func__,__LINE__,CORTINA_CA_REG_READ(NI_HV_GLB_STATIC_CFG));

	qx_misc_cntl_1.wrd = CORTINA_CA_REG_READ(QX_MISC_CNTL_1);
	qx_misc_cntl_1.bf.cfg_fb_on = 1;
	CORTINA_CA_REG_WRITE(qx_misc_cntl_1.wrd, QX_MISC_CNTL_1);

	/* Anlog SDS configurations */
	if (__p6_serdes_ind_read(0x20, 5, &data) != CA_E_OK) {
		printf("ca-sds: __p6_serdes_ind_read FAIL\r\n");
		return;
	}

	data = 0x9f;

	if (__p6_serdes_ind_write(0x20, 5, data) != CA_E_OK) {
		printf("ca-sds: __p6_serdes_ind_write FAIL\r\n");
		return;
	}

	/* Load serdes patch from file if any */
	/* TBD: chip revsion */
	__p6_prof_load_from_file();

	/* Release datapath reset */
	qx_reset.wrd = CORTINA_CA_REG_READ(QX_RESET);
	qx_reset.bf.dp_reset = 0;
	CORTINA_CA_REG_WRITE(qx_reset.wrd, QX_RESET);

	/* SDS mode */
	qx_mode.wrd = CORTINA_CA_REG_READ(QX_MODE);
	qx_mode.bf.use_wtg = 0x1;
	CORTINA_CA_REG_WRITE(qx_mode.wrd, QX_MODE);

	if (!__p6_checkSdsClkReady())
		printf("ca-sds: p6 no clk ready\r\n");
	else
		mdelay(400);

	/* MODIFY_ME - Remove P6 MAC configure */
	/* NI related configuration */
	__p6_mac_10g_config();

}

#define CA_NI_REG_READ CORTINA_CA_REG_READ
#define CA_NI_REG_WRITE CORTINA_CA_REG_WRITE
static int __p5_sds_mode_set(aal_sds_mode_t mode, aal_sds_speed_t speed)
{
	NI_HV_PT_PORT_STATIC_CFG_t port_static_cfg;
	NI_HV_GLB_STATIC_CFG_t glb_static_cfg;
	GLOBAL_GPIO_MUX_3_t gpio_mux_3;
	GLOBAL_IO_DRIVE_CONTROL_t io_drv_ctrl;

	switch (mode) {
	case AAL_SDS_MODE_RGMII:
		switch (speed) {
		case AAL_SDS_SPEED_DEFAULT:
		case AAL_SDS_SPEED_1G:
			port_static_cfg.wrd = CA_NI_REG_READ(NI_HV_PT_PORT_STATIC_CFG +
							     APB0_NI_HV_PT_STRIDE * 5);
			port_static_cfg.bf.int_cfg = 0x2 ;
			CA_NI_REG_WRITE(port_static_cfg.wrd,
					NI_HV_PT_PORT_STATIC_CFG + APB0_NI_HV_PT_STRIDE * 5);

			glb_static_cfg.wrd = CA_NI_REG_READ(NI_HV_GLB_STATIC_CFG);
			glb_static_cfg.bf.txmib_mode = 1;
			glb_static_cfg.bf.rxmib_mode = 1;
			glb_static_cfg.bf.p5_ge_sel = 1;
			CA_NI_REG_WRITE(glb_static_cfg.wrd, NI_HV_GLB_STATIC_CFG);

			gpio_mux_3.wrd = AAL_GLB_REG_READ(GLOBAL_GPIO_MUX_3);
			gpio_mux_3.bf.gpio3en |= ((1 << 7) | (1 << 3));
			AAL_GLB_REG_WRITE(gpio_mux_3.wrd, GLOBAL_GPIO_MUX_3);

			io_drv_ctrl.wrd = AAL_GLB_REG_READ(GLOBAL_IO_DRIVE_CONTROL);
			io_drv_ctrl.bf.gmac_mode = 0x3;
			AAL_GLB_REG_WRITE(io_drv_ctrl.wrd, GLOBAL_IO_DRIVE_CONTROL);
			break;

		case AAL_SDS_SPEED_100M:
			port_static_cfg.wrd = CA_NI_REG_READ(NI_HV_PT_PORT_STATIC_CFG +
							     APB0_NI_HV_PT_STRIDE * 5);
			port_static_cfg.bf.int_cfg = 0x3 ;
			CA_NI_REG_WRITE(port_static_cfg.wrd,
					NI_HV_PT_PORT_STATIC_CFG + APB0_NI_HV_PT_STRIDE * 5);

			glb_static_cfg.wrd = CA_NI_REG_READ(NI_HV_GLB_STATIC_CFG);
			glb_static_cfg.bf.txmib_mode = 1;
			glb_static_cfg.bf.rxmib_mode = 1;
			glb_static_cfg.bf.p5_ge_sel = 1;
			CA_NI_REG_WRITE(glb_static_cfg.wrd, NI_HV_GLB_STATIC_CFG);

			gpio_mux_3.wrd = AAL_GLB_REG_READ(GLOBAL_GPIO_MUX_3);
			gpio_mux_3.bf.gpio3en |= ((1 << 7) | (1 << 3));
			AAL_GLB_REG_WRITE(gpio_mux_3.wrd, GLOBAL_GPIO_MUX_3);

			io_drv_ctrl.wrd = AAL_GLB_REG_READ(GLOBAL_IO_DRIVE_CONTROL);
			io_drv_ctrl.bf.gmac_mode = 0x3;
			AAL_GLB_REG_WRITE(io_drv_ctrl.wrd, GLOBAL_IO_DRIVE_CONTROL);
			break;

		default:
			return CA_E_PARAM;
		}

		break;

	default:
		return CA_E_PARAM;
	}

	return CA_E_OK;
}

static int is_qxgmii;
static int __p6_sds_mode_set(aal_sds_mode_t mode, aal_sds_speed_t speed)
{
	switch (mode) {
	case AAL_SDS_MODE_QXGMII:
		is_qxgmii = 1;
		ca_ni_p6_qxgmii_init();
		break;

	default:
		return CA_E_PARAM;
	}

	return CA_E_OK;
}

static int rtl9617c_aal_sds_mode_set(unsigned int port, aal_sds_mode_t mode,
				   aal_sds_speed_t speed)
{
	printf("%s(%d): port=%d mode=%d speed=%d\n", __func__, __LINE__, port, mode,
	       speed);

	switch (port) {
	case NI_PORT_4:
		return __p4_sds_mode_set(mode, speed);

	case NI_PORT_5:
		return __p5_sds_mode_set(mode, speed);

	case NI_PORT_6:
		return __p6_sds_mode_set(mode, speed);

	default:
		return -1;
	}
}

int aal_mode_sync(unsigned int port, aal_sds_mode_t mode,
		  struct phy_device *phy)
{
	NI_HV_PT_PORT_STATIC_CFG_t	port_static_cfg;
	NI_HV_PT_PORT_GLB_CFG_t	port_glb_cfg;
	int rc;

	aal_sds_speed_t speed = AAL_SDS_SPEED_DEFAULT;
	//printf("%s(%d): port=%d mode=%d\n", __func__, __LINE__, port, mode);

	if (phy)
		speed = _to_aal_speed(phy->speed);

	//printf("%s(%d): speed=%d\n", __func__, __LINE__, speed);

	if (speed < 0)
		return -1;

	if (port <= NI_PORT_5) {
		int type = GE_MAC_INTF_GMII;

		if ((phy->speed < SPEED_1000) && (!is_qxgmii))
			type = GE_MAC_INTF_MII;

		if ((port == NI_PORT_5) && (mode == AAL_SDS_MODE_RGMII))
			type = (phy->speed == SPEED_1000) ? \
			       GE_MAC_INTF_RGMII_1000 : \
			       GE_MAC_INTF_RGMII_100;

		port_static_cfg.wrd = CORTINA_CA_REG_READ((NI_HV_PT_PORT_STATIC_CFG +
							   APB0_NI_HV_PT_STRIDE * port));
		port_static_cfg.bf.int_cfg = type;
		CORTINA_CA_REG_WRITE(port_static_cfg.wrd,
				     (NI_HV_PT_PORT_STATIC_CFG + APB0_NI_HV_PT_STRIDE * port));

		port_glb_cfg.wrd = CORTINA_CA_REG_READ((NI_HV_PT_PORT_GLB_CFG +
							APB0_NI_HV_PT_STRIDE * port));
		port_glb_cfg.bf.speed = (phy->speed == SPEED_10) ? 1 : 0;
		port_glb_cfg.bf.duplex = (phy->duplex == DUPLEX_HALF) ? 1 : 0;
		CORTINA_CA_REG_WRITE(port_glb_cfg.wrd,
				     (NI_HV_PT_PORT_GLB_CFG + APB0_NI_HV_PT_STRIDE * port));

		if (is_qxgmii && (port <= NI_PORT_3))
			ca_ni_p6_qxgmii_port_macForceAbility_set(port,
								 _to_qx_ability_speed(phy->speed));
	}

	if (port >= NI_PORT_5) {
		rc = rtl9617c_aal_sds_mode_set(port, mode, speed);

		if (rc)
			printf("sds_mode_set(%d,%d,%d)=%d\n", port, mode, speed, rc);
	}


	return 0;
}

void aal_set_active_port(unsigned int port)
{
	NI_HV_GLB_INTF_RST_CONFIG_t  intf_rst_config;
	NI_HV_GLB_STATIC_CFG_t static_cfg;

	intf_rst_config.wrd = CORTINA_CA_REG_READ(NI_HV_GLB_INTF_RST_CONFIG);

	switch (port) {
	case NI_PORT_0:
		intf_rst_config.bf.intf_rst_p0 = 0;
		intf_rst_config.bf.mac_rx_rst_p0 = 0;
		intf_rst_config.bf.mac_tx_rst_p0 = 0;
		break;

	case NI_PORT_1:
		intf_rst_config.bf.intf_rst_p1 = 0;
		intf_rst_config.bf.mac_rx_rst_p1 = 0;
		intf_rst_config.bf.mac_tx_rst_p1 = 0;
		break;

	case NI_PORT_2:
		intf_rst_config.bf.intf_rst_p2 = 0;
		intf_rst_config.bf.mac_rx_rst_p2 = 0;
		intf_rst_config.bf.mac_tx_rst_p2 = 0;
		break;

	case NI_PORT_3:
		intf_rst_config.bf.intf_rst_p3 = 0;
		intf_rst_config.bf.mac_tx_rst_p3 = 0;
		intf_rst_config.bf.mac_rx_rst_p3 = 0;
		break;

	case NI_PORT_4:
		intf_rst_config.bf.intf_rst_p4 = 0;
		intf_rst_config.bf.mac_tx_rst_p4 = 0;
		intf_rst_config.bf.mac_rx_rst_p4 = 0;
		break;

	case NI_PORT_5:
		intf_rst_config.bf.intf_rst_p5 = 0;
		intf_rst_config.bf.mac_tx_rst_p5 = 0;
		intf_rst_config.bf.mac_rx_rst_p5 = 0;
		intf_rst_config.bf.mac_rst_p5 = 0;
		break;

	default:
		return;
	}

	CORTINA_CA_REG_WRITE(intf_rst_config.wrd, NI_HV_GLB_INTF_RST_CONFIG);

	/* Only one GMAC can connect to CPU */
	static_cfg.wrd = CORTINA_CA_REG_READ(NI_HV_GLB_STATIC_CFG);
	static_cfg.bf.port_to_cpu = port;
	static_cfg.bf.txmib_mode = 1;
	static_cfg.bf.rxmib_mode = 1;

	if (port == NI_PORT_5)
		static_cfg.bf.p5_ge_sel = 1;

	CORTINA_CA_REG_WRITE(static_cfg.wrd, NI_HV_GLB_STATIC_CFG);
}
