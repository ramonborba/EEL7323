/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/03/2022
 * File: SmartAC.cpp
 */


#include <cstdio>
#include <iostream>
#include <string>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "gpio_cxx.hpp"

#include "SmartAC.h"
#include "uart_event_task.hpp"
#include "esp_log.h"

using namespace std;
using namespace idf;



void uart_tx_task(void *pvParameters);

extern "C" void app_main(void)
{
    static const char* MAIN_TAG = "MAIN";

    // Define log levels for debbuging
    esp_log_level_set("*", ESP_LOG_WARN);
    esp_log_level_set("MAIN", ESP_LOG_DEBUG);
    esp_log_level_set("UART_CPP", ESP_LOG_DEBUG);

    // SETUP
    GPIO_Output LED(GPIONum(LED_PIN));

    uart_config_t cfg = {};
    cfg.baud_rate = HOST_UART_BAUD;
    cfg.data_bits = HOST_UART_DATA_BITS;
    cfg.parity = HOST_UART_PARITY;
    cfg.stop_bits = HOST_UART_STOP_BITS;
    cfg.flow_ctrl = HOST_UART_FLOW_CTRL;

    uart.set_config(cfg);
    uart.set_pins(18, 19, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    
    // CREATING TASKS
    xTaskCreatePinnedToCore(uart_tx_task, "tx_task", 2048, &uart, 5, NULL, tskNO_AFFINITY);
    
    // LOOP
    while (true)
    {
        uint32_t msg;
        uart.read(&msg, sizeof(msg), portMAX_DELAY);
        ESP_LOGD(MAIN_TAG, "Read: %x", msg);
        // ESP_LOGI(MAIN_TAG, "LED ON");
        LED.set_high();
        vTaskDelay(500/ portTICK_PERIOD_MS);
        // ESP_LOGI(MAIN_TAG, "LED OFF");
        LED.set_low();
        // vTaskDelay(500/ portTICK_PERIOD_MS);
    }
    
}


void uart_tx_task(void *pvParameters){
    static const char *TX_TASK_TAG = "TX_TASK";
    esp_log_level_set(TX_TASK_TAG, ESP_LOG_INFO);
    uint32_t cmd = 0xFFFF00FF;
    while (1) {
        uart.write(&cmd, sizeof(cmd));
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}