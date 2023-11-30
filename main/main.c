#include <stdio.h>
#include "battery.h"
#include "driver/gpio.h"

#define EN_5V GPIO_NUM_25


static const char *TAG = "MAIN";


void app_main(void)
{
    ESP_ERROR_CHECK(batteryManagmentInit());

    gpio_config_t io_conf = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << GPIO_NUM_25,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE
    };
    gpio_config(&io_conf);
    gpio_set_level(GPIO_NUM_25, 1);

}
