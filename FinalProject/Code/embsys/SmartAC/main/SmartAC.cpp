#include <cstdio>
#include <iostream>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"

#define LOG_TAG "MAIN"

extern "C" void app_main(void)
{
    // SETUP
    gpio_reset_pin(gpio_num_t(2));
    gpio_set_direction(gpio_num_t(2), GPIO_MODE_OUTPUT);
    
    // LOOP
    while (1)
    {
        std::cout << "C++ is Awesome!" << std::endl;
        ESP_LOGI(LOG_TAG, "LED ON");
        gpio_set_level(gpio_num_t(2), 1);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
        ESP_LOGI(LOG_TAG, "LED OFF");
        gpio_set_level(gpio_num_t(2), 0);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
    
}
