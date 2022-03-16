/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/03/2022
 * File: UART_cxx.hpp
 * 
 * Implementations for the UART C++ API are based
 * in the GPIO C++ API provided in ESP-IDF examples.
 * 
 */

#ifndef UART_CXX_H_
#define UART_CXX_H_

#if __cpp_exceptions    // Check if C++ is enabled for the microcontroller module


#include "driver/uart.h"
#include "esp_exception.hpp"
#include "system_cxx.hpp"
#include "esp_log.h"

#define BUFFER_SIZE (1024)


namespace idf {

static const char* LOG_TAG = "UART_CPP";


/**
 * @brief Exception thrown for errors in the UART C++ API.
 */
struct UARTException : public ESPException {
    /**
     * @param error The IDF error representing the error class of the error to throw.
     */
    UARTException(esp_err_t error);
};

class UARTPort
{
private:
    uart_port_t port_num_;
    uart_config_t config_;
public:

    /**
     * @brief Construct a new UARTPort object
     * 
     * @param portnum Number of the UART port
     * @param rx_buffer_size Size of RX buffer
     * @param tx_buffer_size Size of TX buffer
     * @param uart_queue Handle to UART event queue
     * @param queue_size Size of UART event queue
     */
    UARTPort(uart_port_t portnum,
                int rx_buffer_size,
                int tx_buffer_size,
                QueueHandle_t uart_queue,
                int queue_size);
    ~UARTPort();

    void set_config(const uart_config_t& cfg);
    void get_config(uart_config_t& cfg);
};



} // namespace idf

#endif /* __cpp_exceptions */
#endif /* UART_CXX_H */