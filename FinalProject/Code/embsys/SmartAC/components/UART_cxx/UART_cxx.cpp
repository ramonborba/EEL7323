/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/03/2022
 * File: UART_cxx.cpp
 * 
 * Implementations for the UART C++ API are based
 * in the GPIO C++ API provided in ESP-IDF examples.
 * 
 */


#include "driver/uart.h"
#include "UART_cxx.hpp"


namespace idf
{
UARTException::UARTException(esp_err_t error) : ESPException(error) { }


UARTPort::UARTPort(uart_port_t portnum,
                    int rx_buffer_size,
                    int tx_buffer_size,
                    QueueHandle_t uart_queue,
                    int queue_size) : port_num_{portnum}
{
    ESP_LOGD(LOG_TAG, "Constructing UART%d", port_num_);
    // Check for valid port number   
    if (!(portnum > (UART_NUM_MAX-1)))
    {
        ESP_LOGD(LOG_TAG, "Port num %d is valid", port_num_);
        // Check if driver is already installed
        if (!uart_is_driver_installed(port_num_))
        {
            // Install UART driver
            uart_driver_install(portnum, BUFFER_SIZE * 2, BUFFER_SIZE * 2, queue_size, &uart_queue, 0);
            ESP_LOGD(LOG_TAG, "Installed UART%d driver", port_num_);
        }
    }
}

UARTPort::~UARTPort()
{
    // Delete UART driver to free allocated resources
    uart_driver_delete(port_num_);
    ESP_LOGD(LOG_TAG, "Deleted UART%d driver", port_num_);
}


} // namespace idf
