/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/03/2022
 * File: SmartAC.cpp
 */


#include <cstdio>
#include <iostream>
#include <string>

#include "gpio_cxx.hpp"

#include "SmartAC.h"
#include "uart_event_task.hpp"
#include "esp_log.h"

using namespace std;
using namespace idf;


void test_gpio_handler (void* args);
void uart_tx_task(void *pvParameters);
void test_gpio_task(void *pvParameters);
static QueueHandle_t gpio_queue;

extern "C" void app_main(void)
{
    static const char* MAIN_TAG = "MAIN";

    // Define log levels for debbuging
    esp_log_level_set("*", ESP_LOG_WARN);
    // esp_log_level_set("MAIN", ESP_LOG_DEBUG);
    esp_log_level_set("UART_CPP", ESP_LOG_DEBUG);
    esp_log_level_set("GPIO_CPP", ESP_LOG_DEBUG);
    esp_log_level_set("GPIO_TASK", ESP_LOG_DEBUG);

    // SETUP
    // Configure GPIO pins
    GPIO_Output LED(GPIONum(LED_PIN));
    
    GPIOInput hot_button (GPIONum(HOT_INPUT_PIN));
    hot_button.set_pull_mode(GPIOPullMode::PULLUP());
    hot_button.set_intr_type(GPIOIntrType::FALLING_EDGE());

    GPIOInput cold_button (GPIONum(COLD_INPUT_PIN));
    cold_button.set_pull_mode(GPIOPullMode::PULLUP());
    cold_button.set_intr_type(GPIOIntrType::FALLING_EDGE());


    // Configure GPIO interrupts
    GPIOIntrManager ISRMngr;
    ISRMngr.add_isr_handler(hot_button.get_num(), test_gpio_handler, (void *)hot_button.get_num().get_value());
    ISRMngr.add_isr_handler(cold_button.get_num(), test_gpio_handler, (void *)cold_button.get_num().get_value());
    gpio_queue = xQueueCreate(20, sizeof(uint32_t));
    
    // Configure UART port
    uart_config_t cfg = {};// UART config struct
    cfg.baud_rate = HOST_UART_BAUD;
    cfg.data_bits = HOST_UART_DATA_BITS;
    cfg.parity = HOST_UART_PARITY;
    cfg.stop_bits = HOST_UART_STOP_BITS;
    cfg.flow_ctrl = HOST_UART_FLOW_CTRL;

    uart.set_config(cfg);
    // uart.set_pins(18, 19, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    // CREATING TASKS
    xTaskCreatePinnedToCore(uart_event_task, "uart_event_task", 2048, NULL, 12, &uart_event_task_handle, tskNO_AFFINITY);
    xTaskCreatePinnedToCore(test_gpio_task, "tx_task", 2048, NULL, 5, NULL, tskNO_AFFINITY);
    

    // LOOP
    while (true)
    {
        // uint32_t msg;
        // uart->read(&msg, sizeof(msg), portMAX_DELAY);
        ESP_LOGI(MAIN_TAG, "LED ON");
        LED.set_high();
        vTaskDelay(500/ portTICK_PERIOD_MS);
        ESP_LOGI(MAIN_TAG, "LED OFF");
        LED.set_low();
        vTaskDelay(500/ portTICK_PERIOD_MS);
    }
    
}

void test_gpio_handler (void* args){
    uint32_t gpio = (uint32_t)args;
    static TickType_t last_time = 0;
    TickType_t now = xTaskGetTickCountFromISR();
    if ( (now - last_time) >= (500/portTICK_PERIOD_MS) )
    {
        xQueueSendToBackFromISR(gpio_queue, &gpio, NULL);
        last_time = now;
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

void test_gpio_task(void *pvParameters){
    static const char *GPIO_TASK_TAG = "GPIO_TASK";
    while (true)
    {
        uint32_t gpio_pin = 0;
        ESP_LOGD(GPIO_TASK_TAG, "Waiting for QueueReceive");
        if (xQueueReceive(gpio_queue, &gpio_pin, portMAX_DELAY))
        {
            ESP_LOGD(GPIO_TASK_TAG, "Received GPIO pin %d", gpio_pin);
        }
    }
    
}