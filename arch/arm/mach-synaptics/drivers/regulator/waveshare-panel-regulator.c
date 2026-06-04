// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2020
 */
/*
 * Copyright (C) 2016~2025 Synaptics Incorporated. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 or
 * later as published by the Free Software Foundation.
 *
 * INFORMATION CONTAINED IN THIS DOCUMENT IS PROVIDED "AS-IS," AND
 * SYNAPTICS EXPRESSLY DISCLAIMS ALL EXPRESS AND IMPLIED WARRANTIES,
 * INCLUDING ANY IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE, AND ANY WARRANTIES OF NON-INFRINGEMENT OF ANY
 * INTELLECTUAL PROPERTY RIGHTS. IN NO EVENT SHALL SYNAPTICS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, PUNITIVE, OR
 * CONSEQUENTIAL DAMAGES ARISING OUT OF OR IN CONNECTION WITH THE USE
 * OF THE INFORMATION CONTAINED IN THIS DOCUMENT, HOWEVER CAUSED AND
 * BASED ON ANY THEORY OF LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, AND EVEN IF SYNAPTICS WAS
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. IF A TRIBUNAL OF
 * COMPETENT JURISDICTION DOES NOT PERMIT THE DISCLAIMER OF DIRECT
 * DAMAGES OR ANY OTHER DAMAGES, SYNAPTICS' TOTAL CUMULATIVE LIABILITY
 * TO ANY PARTY SHALL NOT EXCEED ONE HUNDRED U.S. DOLLARS.
 */

#include <fdtdec.h>
#include <errno.h>
#include <dm.h>
#include <i2c.h>
#include <power/regulator.h>
#include <linux/delay.h>

#define REG_TP          0x94
#define REG_LCD         0x95
#define REG_PWM         0x96
#define REG_SIZE        0x97
#define REG_ID          0x98
#define REG_VERSION     0x99

#define VCC_ENABLE_HI   0x03
#define VCC_ENABLE_LO   0x00

#define AVDD_ENABLE     0x01
#define RESET_ENABLE    0x02
#define BL_ENABLE       0x04
#define IOVCC_ENABLE    0x10

#define DEFAULT_BRIGHTNESS      0xFF

static int attiny_regulator_of_to_plat(struct udevice *dev)
{
	return 0;
}

static int waveshare_i2c_write(struct udevice *dev, uint8_t val, uint8_t reg)
{
	int ret;

	ret = dm_i2c_write(dev, reg, &val, 1);
	if (ret)
		printf("%s: failed reg: 0x%02x\n", __func__, reg);

	return ret;
}

static int waveshare_i2c_read(struct udevice *dev, uint8_t *buf, uint8_t reg)
{
	struct dm_i2c_chip *chip = dev_get_parent_plat(dev);
	u8 addr_buf[1] = { reg };
	u8 data_buf[1] = { 0 };
	struct i2c_msg msgs[1];
	int ret;

	msgs[0].addr  = chip->chip_addr;
	msgs[0].flags = 0;
	msgs[0].len   = ARRAY_SIZE(addr_buf);
	msgs[0].buf   = addr_buf;

	ret = dm_i2c_xfer(dev, msgs, ARRAY_SIZE(msgs));
	if (ret)
		return ret;

	msgs[0].addr  = chip->chip_addr;
	msgs[0].flags = I2C_M_RD;
	msgs[0].len   = 1;
	msgs[0].buf   = data_buf;

	ret = dm_i2c_xfer(dev, msgs, ARRAY_SIZE(msgs));
	*buf = data_buf[0];
	return ret;
}

static int waveshare_regulator_set_enable(struct udevice *dev, bool enable)
{
	int ret;

	ret = waveshare_i2c_write(dev, VCC_ENABLE_HI, REG_TP);
	if (ret)
		return ret;

	ret = waveshare_i2c_write(dev, VCC_ENABLE_LO, REG_LCD);
	if (ret)
		return ret;

	ret = waveshare_i2c_write(dev, IOVCC_ENABLE, REG_LCD);
	if (ret)
		return ret;

	ret = waveshare_i2c_write(dev, IOVCC_ENABLE | AVDD_ENABLE, REG_LCD);
	if (ret)
		return ret;

	ret = waveshare_i2c_write(dev,
				  IOVCC_ENABLE | AVDD_ENABLE | RESET_ENABLE,
				  REG_LCD);
	if (ret)
		return ret;

	ret = waveshare_i2c_write(dev,
				  IOVCC_ENABLE | AVDD_ENABLE | RESET_ENABLE | BL_ENABLE,
				  REG_LCD);
	if (ret)
		return ret;

	waveshare_i2c_write(dev, DEFAULT_BRIGHTNESS, REG_PWM);

	return 0;
}

static int waveshare_regulator_probe(struct udevice *dev)
{
	u8 data;
	int ret;

	ret = waveshare_i2c_read(dev, &data, REG_ID);
	if (ret)
		return ret;
	ret = waveshare_i2c_read(dev, &data, REG_SIZE);
	if (ret)
		return ret;
	ret = waveshare_i2c_read(dev, &data, REG_VERSION);
	if (ret)
		return ret;

	return 0;
}

static const struct dm_regulator_ops waveshare_regulator_ops = {
	.set_enable = waveshare_regulator_set_enable,
};

static const struct udevice_id waveshare_regulator_ids[] = {
	{ .compatible = "waveshare,touchscreen-panel-regulator" },
	{ }
};

U_BOOT_DRIVER(waveshare_regulator) = {
	.name           = "waveshare_regulator",
	.id             = UCLASS_REGULATOR,
	.of_match       = waveshare_regulator_ids,
	.ops            = &waveshare_regulator_ops,
	.of_to_plat     = &attiny_regulator_of_to_plat,
	.probe          = waveshare_regulator_probe,
};
