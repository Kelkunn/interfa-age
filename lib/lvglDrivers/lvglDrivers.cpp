#include "lvglDrivers.h"
#include "lv_conf.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"

extern uint8_t bufferEcran[64 * 32 * 2];

static void lvglTask(void *pvParameters)
{
    while (1)
    {
        uint32_t time_till_next = lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(time_till_next));
    }
}

static void my_flush_cb(lv_display_t *display, const lv_area_t *area, uint8_t *px_map)
{
    // Serial.printf("%3d %3d %3d %3d\n", area->x1, area->y1, area->x2, area->y2);
    uint32_t *buf = (uint32_t *)px_map;
    int32_t x, y;
    for (y = area->y1; y <= area->y2; y++)
    {
        for (x = area->x1; x <= area->x2; x++)
        {
            int index_x = x / 7.5;
            if (y >= 51)
            {                
                int index_y = (y - 51) / 6.9;
                if (index_x >= 0 && index_x < 64 && index_y >= 0 && index_y < 32)
                {
                    int data = bufferEcran[index_y * 64 + index_x];
                    *buf = 0xFF000000;
                    if (data & 1) *buf |= 0x00FF0000;
                    if (data & 2) *buf |= 0x0000FF00;
                    if (data & 4) *buf |= 0x000000FF;
                }
            }
            BSP_LCD_DrawPixel(x, y, *buf);
            buf++;
        }
    }

    // IMPORTANT!!!
    // Inform LVGL that you are ready with the flushing and buf is not used anymore
    lv_display_flush_ready(display);
}

static void my_read_cb(lv_indev_t *indev, lv_indev_data_t *data)
{
    TS_StateTypeDef TS_State;
    BSP_TS_GetState(&TS_State);

    if (TS_State.touchDetected != 0)
    {
        data->point.x = TS_State.touchX[0];
        data->point.y = TS_State.touchY[0];
        data->state = LV_INDEV_STATE_PRESSED;
    }
    else
    {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

void setup()
{
    Serial.begin(115200);
    Serial.println("Start");

    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);

    BSP_TS_Init(480, 272);

    lv_init();

    lv_log_register_print_cb([](lv_log_level_t level, const char *buf)
                             { Serial.printf("%s", buf); });

    lv_display_t *display = lv_display_create(480, 272);

    lv_display_set_flush_cb(display, my_flush_cb);

    static uint32_t buf[480 * 272 / 10];

    lv_display_set_buffers(display, buf, NULL, sizeof(buf), LV_DISPLAY_RENDER_MODE_PARTIAL);

    lv_indev_t *indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev, my_read_cb);

    lv_tick_set_cb(xTaskGetTickCount);

    mySetup();

    xTaskCreate(lvglTask, "lvgl", 8192, NULL, osPriorityNormal, NULL);
    xTaskCreate(myTask, "task", 8192, NULL, osPriorityNormal, NULL);
    xTaskCreate(myMatrixTask, "matrix", 8192, NULL, osPriorityHigh, NULL);

    vTaskStartScheduler();
    Serial.println("Insufficient RAM");
    while (1)
        ;
}
