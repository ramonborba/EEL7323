/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/03/2022
 * File: SmartAC.h
 */
#ifndef SMART_AC_H_
#define SMART_AC_H_


#include "UART_cxx.hpp"

#define LED_PIN 2

// Host computer UART parameters
#define HOST_UART_NUM                UART_NUM_1

#define HOST_UART_BAUD               115200
#define HOST_UART_DATA_BITS          UART_DATA_8_BITS
#define HOST_UART_PARITY             UART_PARITY_DISABLE
#define HOST_UART_STOP_BITS          UART_STOP_BITS_1
#define HOST_UART_FLOW_CTRL          UART_HW_FLOWCTRL_DISABLE

//Uart event queue
QueueHandle_t uart0_queue;

// Uart port object
idf::UARTPort uart(HOST_UART_NUM, 2048, 2048, uart0_queue, 20);


#endif /* SMART_AC_H_ */