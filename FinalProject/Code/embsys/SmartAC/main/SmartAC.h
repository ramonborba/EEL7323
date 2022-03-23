/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/03/2022
 * File: SmartAC.h
 */
#ifndef SMART_AC_H_
#define SMART_AC_H_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "UART_cxx.hpp"

#define LED_PIN 2
#define HOT_INPUT_PIN 18
#define COLD_INPUT_PIN 19

// Host computer UART parameters
#define HOST_UART_NUM                UART_NUM_2

#define HOST_UART_BAUD               115200
#define HOST_UART_DATA_BITS          UART_DATA_8_BITS
#define HOST_UART_PARITY             UART_PARITY_DISABLE
#define HOST_UART_STOP_BITS          UART_STOP_BITS_1
#define HOST_UART_FLOW_CTRL          UART_HW_FLOWCTRL_DISABLE

//Queue handles
extern QueueHandle_t uart_event_queue;
extern QueueHandle_t gpio_interrupt_queue;


// Uart port pointer
idf::UARTPort uart (HOST_UART_NUM, 2048, 2048, &uart_event_queue, 20);

// Task handles
extern TaskHandle_t uart_event_task_handle;
extern TaskHandle_t gpio_event_task_handle;

#endif /* SMART_AC_H_ */