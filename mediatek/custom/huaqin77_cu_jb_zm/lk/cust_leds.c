#include <cust_leds.h>
#include <platform/mt_pwm.h>
#include <platform/mt_gpio.h>

extern void upmu_chr_chrind_on(kal_uint32 val);

int chr_det_led_control(int level){
	if(level)
		upmu_chr_chrind_on(0x01);
	else
		upmu_chr_chrind_on(0);
}

static struct cust_mt65xx_led cust_led_list[MT65XX_LED_TYPE_TOTAL] = {
	{"red",					MT65XX_LED_MODE_CUST,	(int)chr_det_led_control,	{0}},
	{"green",				MT65XX_LED_MODE_PMIC,	MT65XX_LED_PMIC_NLED_ISINK5,{0}},
	{"blue",				MT65XX_LED_MODE_PMIC,	MT65XX_LED_PMIC_NLED_ISINK4,{0}},
	{"jogball-backlight",	MT65XX_LED_MODE_NONE,	-1,							{0}},
	{"keyboard-backlight",	MT65XX_LED_MODE_NONE,	-1,							{0}},
	{"button-backlight",	MT65XX_LED_MODE_PMIC,	MT65XX_LED_PMIC_BUTTON,		{0}},
	{"lcd-backlight",		MT65XX_LED_MODE_PWM,	PWM3,						{0}},
	{"torch",				MT65XX_LED_MODE_PWM,	PWM1,						{0}},
	{"flash-light",			MT65XX_LED_MODE_GPIO,	GPIO_CAMERA_FLASH_EN_PIN,	{0}},
};

struct cust_mt65xx_led *get_cust_led_list(void)
{
	return cust_led_list;
}

