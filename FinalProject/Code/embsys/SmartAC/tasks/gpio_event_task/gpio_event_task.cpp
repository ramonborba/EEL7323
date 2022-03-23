/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 22/03/2022
 * File: gpio_event_task.cpp
 */

#include <stdio.h>

#include "gpio_event_task.hpp"
#include "SmartAC.h"
#include "esp_log.h"


void gpio_event_task(void *pvParameters)
{
    static const char *GPIO_TASK_TAG = "GPIO_TASK";
    while (true)
    {
        uint32_t gpio_pin = 0;
        ESP_LOGD(GPIO_TASK_TAG, "Waiting for QueueReceive");
        if (xQueueReceive(gpio_interrupt_queue, &gpio_pin, portMAX_DELAY))
        {
            ESP_LOGD(GPIO_TASK_TAG, "Received %s", ( (HOT_INPUT_PIN == gpio_pin) ? "HOT button press" : "COLD button press" ) );
        }
    }

}
