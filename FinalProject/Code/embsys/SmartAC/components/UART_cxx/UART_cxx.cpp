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
                    int queue_size) : port_num_{portnum}, config_{}
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
            
            // Store default configuration in config_
            uart_get_baudrate(port_num_, (uint32_t*)&config_.baud_rate );
            uart_get_word_length(port_num_, &config_.data_bits);
            uart_get_parity(port_num_, &config_.parity);
            uart_get_stop_bits(port_num_, &config_.stop_bits);
            uart_get_hw_flow_ctrl(port_num_, &config_.flow_ctrl);
        }

    }
}

UARTPort::~UARTPort()
{
    // Delete UART driver to free allocated resources
    uart_driver_delete(port_num_);
    ESP_LOGD(LOG_TAG, "Deleted UART%d driver", port_num_);
}


void UARTPort::set_config(const uart_config_t& cfg)
{
    // Call uart parameter configuration function
    config_ = cfg;
    uart_param_config(port_num_, &config_);
    ESP_LOGD(LOG_TAG, "Configured UART%d parameters", port_num_);
}


void UARTPort::get_config(uart_config_t& cfg)
{
    cfg = config_;
    ESP_LOGD(LOG_TAG, "Retrieving UART%d parameters", port_num_);
}

} // namespace idf
