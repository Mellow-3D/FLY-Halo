/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include "config.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_timer.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "driver/gpio.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

#include "tools/wifi/wifi.h"

#include "demos/lv_demos.h"

static const char *TAG = "Halo-demo-main";

extern void example_lvgl_demo_ui();

/*互斥锁*/
SemaphoreHandle_t _semaphore = NULL;

/*线程回调预声明*/
void taskLvgl(void *pvParameter);
void taskBoot(void *pvParameter);

/*初始化并打开背光*/
void init_backlight()
{
    /*初始化背光控制*/
    gpio_config_t bk_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << PIN_NUM_BK_LIGHT};
    ESP_ERROR_CHECK(gpio_config(&bk_gpio_config));

    /*打开背光*/
    gpio_set_level(PIN_NUM_BK_LIGHT, LCD_BK_LIGHT_ON_LEVEL);
}

/*入口函数*/
void app_main(void)
{
    /*创建互斥锁*/
    _semaphore = xSemaphoreCreateMutex();

    /*初始化wifi并连接wifi*/
    /*
    idf.py menuconfig => “Halo Demo Configuration”
    or
    #define WIFI_SSID "ssid"
    #define WIFI_PASS "password"
    */
    init_wifi();

    /*初始化背光控制*/
    init_backlight();

    /*初始化LVGL*/
    lv_init();

    /*LVGL显示和触摸驱动初始化注册*/
    lv_port_disp_init();
    lv_port_indev_init();

    /*创建LVGL任务线程*/
    xTaskCreatePinnedToCore(taskLvgl, "taskLvgl", 20 * 1024, NULL, configMAX_PRIORITIES - 1, NULL, 1);

    /*创建Boot线程*/
    xTaskCreate(taskBoot, "taskBoot", 20 * 1024, NULL, configMAX_PRIORITIES - 10, NULL);

    /*注意：所有在线程中的lvgl操作必须使用互斥锁*/
}

/*LVGL任务线程*/
void taskLvgl(void *pvParameter)
{
    /*LVGL任务处理*/
    while (1)
    {
        xSemaphoreTake(_semaphore, portMAX_DELAY); // 加锁
        lv_task_handler();
        xSemaphoreGive(_semaphore); // 解锁释放
        lv_tick_inc(5);
        vTaskDelay(pdMS_TO_TICKS(1));
    }

    /*销毁线程*/
    vTaskDelete(NULL);
}

/*Boot线程*/
void taskBoot(void *pvParameter)
{
    lv_obj_t *scr = lv_scr_act();

    xSemaphoreTake(_semaphore, portMAX_DELAY);
    lv_obj_clean(scr);
    lv_obj_set_style_bg_opa(scr, LV_OPA_100, 0);         // 设备背景不透明度
    lv_obj_set_style_bg_color(scr, lv_color_black(), 0); // 设备背景为黑色
    lv_obj_clear_flag(scr, LV_OBJ_FLAG_SCROLLABLE);      // scr不可滚动
    LV_IMG_DECLARE(boot_mellow);                         // 加载图片
    lv_obj_t *img = lv_gif_create(scr);                  // 创建gif控件
    lv_gif_set_src(img, &boot_mellow);                   // 显示gif
    lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);            // 居中显示
    xSemaphoreGive(_semaphore);

    vTaskDelay(pdMS_TO_TICKS(4700)); // 等待gif播放完毕

    xSemaphoreTake(_semaphore, portMAX_DELAY);
    lv_obj_del_async(img); // 删除gif控件
    lv_mem_buf_free_all(); // 释放lvgl所有缓存
    xSemaphoreGive(_semaphore);

    vTaskDelay(pdMS_TO_TICKS(200)); // 等待200ms

    /*示例程序, 任选一个*/
    xSemaphoreTake(_semaphore, portMAX_DELAY);
    // example_lvgl_demo_ui(); //仪表盘DEMO
    lv_demo_music(); // LVGL官方音乐播放器DEMO
    xSemaphoreGive(_semaphore);

    /*销毁线程*/
    vTaskDelete(NULL);
}
