// SPDX-License-Identifier: GPL-2.0+

#include <linux/types.h>
#include <fdtdec.h>
#include <errno.h>
#include <dm.h>
#include <i2c.h>
#include <panel.h>
#include <linux/delay.h>

#define REG_TP		0x94
#define REG_LCD		0x95
#define REG_PWM		0x96
#define REG_SIZE	0x97
#define REG_ID		0x98
#define REG_VERSION	0x99

#define VCC_ENABLE_HI	0x03
#define VCC_ENABLE_LO	0x00

#define AVDD_ENABLE	0x01
#define RESET_ENABLE	0x02
#define BL_ENABLE	0x04
#define IOVCC_ENABLE	0x10

#define DEFAULT_BRIGHTNESS	0xFF

static int ws_touch_i2c_write(struct udevice *dev, uint8_t val, uint8_t reg)
{
	int ret;

	ret = dm_i2c_write(dev, reg, &val, 1);
	if (ret)
		printf("%s: failed reg: 0x%02x ret: %d\n", __func__, reg, ret);

	return ret;
}

static int ws_touch_i2c_read(struct udevice *dev, uint8_t *buf, uint8_t reg)
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

	mdelay(5);

	msgs[0].addr  = chip->chip_addr;
	msgs[0].flags = I2C_M_RD;
	msgs[0].len   = 1;
	msgs[0].buf   = data_buf;

	ret = dm_i2c_xfer(dev, msgs, ARRAY_SIZE(msgs));
	*buf = data_buf[0];
	return ret;
}

static int ws_touch_set_backlight(struct udevice *dev, int percent)
{
	u8 brightness = (percent * 0xFF) / 100;

	return ws_touch_i2c_write(dev, brightness, REG_PWM);
}

static int ws_touch_enable_backlight(struct udevice *dev)
{
	int ret;

	ret = ws_touch_i2c_write(dev, IOVCC_ENABLE | AVDD_ENABLE
				 | RESET_ENABLE | BL_ENABLE, REG_LCD);
	if (ret) {
		printf("%s: REG_LCD write failed\n", __func__);
		return ret;
	}

	ret = ws_touch_i2c_write(dev, DEFAULT_BRIGHTNESS, REG_PWM);
	if (ret) {
		printf("%s: REG_PWM write failed\n", __func__);
		return ret;
	}

	return 0;
}

static int ws_touch_get_display_timing(struct udevice *dev,
				       struct display_timing *timing)
{
	return 0;
}

static const struct panel_ops ws_touch_panel_ops = {
	.enable_backlight	= ws_touch_enable_backlight,
	.set_backlight		= ws_touch_set_backlight,
	.get_display_timing	= ws_touch_get_display_timing,
};

static int ws_touch_probe(struct udevice *dev)
{
	u8 data;
	int ret;

	ret = ws_touch_i2c_read(dev, &data, REG_ID);
	if (ret)
		return ret;
	ret = ws_touch_i2c_read(dev, &data, REG_SIZE);
	if (ret)
		return ret;
	ret = ws_touch_i2c_read(dev, &data, REG_VERSION);
	if (ret)
		return ret;

	ret = ws_touch_i2c_write(dev, VCC_ENABLE_HI, REG_TP);
	if (ret) {
		printf("%s: REG_TP write failed\n", __func__);
		return ret;
	}

	ret = ws_touch_i2c_write(dev, VCC_ENABLE_LO, REG_LCD);
	if (ret) {
		printf("%s: REG_LCD write failed\n", __func__);
		return ret;
	}

	ret = ws_touch_i2c_write(dev, IOVCC_ENABLE, REG_LCD);
	if (ret) {
		printf("%s: IOVCC enable failed\n", __func__);
		return ret;
	}

	ret = ws_touch_i2c_write(dev, IOVCC_ENABLE | AVDD_ENABLE, REG_LCD);
	if (ret) {
		printf("%s: AVDD enable failed\n", __func__);
		return ret;
	}

	ret = ws_touch_i2c_write(dev, IOVCC_ENABLE | AVDD_ENABLE | RESET_ENABLE, REG_LCD);
	if (ret) {
		printf("%s: RESET deassert failed\n", __func__);
		return ret;
	}

	return ws_touch_enable_backlight(dev);
}

static const struct udevice_id ws_touch_ids[] = {
	{ .compatible = "waveshare,10.1-dsi-touch-a" },
	{ }
};

U_BOOT_DRIVER(ws_touch_panel) = {
	.name		= "ws_touch_panel",
	.id		= UCLASS_PANEL_BACKLIGHT,
	.of_match	= ws_touch_ids,
	.ops		= &ws_touch_panel_ops,
	.probe		= ws_touch_probe,
};
