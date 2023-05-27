
/*
LCD屏幕SPI

*/
#define LCD_HOST SPI2_HOST

/*
触摸I2C

*/
#define I2C_HOST 0

/*
LCD屏幕SPI速率

*/
#define LCD_PIXEL_CLOCK_HZ (60 * 1000 * 1000)

/*
背光控制引脚及电平

*/
#define PIN_NUM_BK_LIGHT 8
#define LCD_BK_LIGHT_ON_LEVEL 1
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL

/*
LCD屏幕引脚

*/
#define PIN_NUM_SCLK 12
#define PIN_NUM_MOSI 11
#define PIN_NUM_MISO -1
#define PIN_NUM_LCD_DC 9
#define PIN_NUM_LCD_RST 13
#define PIN_NUM_LCD_CS 10

/*
触摸引脚

*/
#define PIN_NUM_TOUCH_SDA 39
#define PIN_NUM_TOUCH_SCL 40
#define PIN_NUM_TOUCH_INT 41
#define PIN_NUM_TOUCH_RST 42

/*
LCD屏幕分辨率和BUF

*/
#define LCD_H_RES 240
#define LCD_V_RES 240
#define DISP_BUF_SIZE ((LCD_H_RES * LCD_V_RES) / 6)


#define LCD_CMD_BITS 8
#define LCD_PARAM_BITS 8

#define LVGL_TICK_PERIOD_MS 2