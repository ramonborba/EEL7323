/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 22/03/2022
 * File: isr_handlers.cpp
 */


#include <stdio.h>
#include "SmartAC.h"
#include "isr_handlers.hpp"

void gpio_button_handler (void* pvParameters){
    uint32_t gpio = (uint32_t)pvParameters;
    static TickType_t last_time = 0;
    TickType_t now = xTaskGetTickCountFromISR();
    if ( (now - last_time) >= (DBOUNCE_THRESHOLD) )
    {
        xQueueSendToBackFromISR(gpio_interrupt_queue, &gpio, NULL);
        last_time = now;
    }
}
