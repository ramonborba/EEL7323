/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 17/03/2022
 * File: uart_event_task.cpp
 * 
 * Task to handle events from uart
 * Based on and ESP-IDF example
 * 
 */

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "UART_cxx.hpp"
#include "uart_event_task.hpp"
#include "esp_log.h"

void uart_event_task(void* pvParameters)
{
    static const char* EVT_TASK_TAG = "EVENT_TASK";
    uart_event_t event;
    uint32_t cmd = 0;
    for(;;) {
        //Waiting for UART event.
        if(xQueueReceive(uart0_queue, (void * )&event, portMAX_DELAY)) {
            cmd = 0;
            ESP_LOGD(EVT_TASK_TAG, "uart[%d] event:", HOST_UART_NUM);
            if (event.type==UART_DATA)
            {
                uart.read(&cmd, event.size, 10/portTICK_PERIOD_MS);
                // TODO
                // Check command and trigger log sendind
            }
            else
            {
                ESP_LOGD(EVT_TASK_TAG, "uart event type: %d", event.type);
            }
            
        }
    }
    vTaskDelete(NULL);
}
