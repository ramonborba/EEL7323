/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 02/03/2022
 * File: EmbSys.h
 */

#include <stdint.h>
#include <fstream>
#include <iostream>
#include "../Queue/Queue.h"

#define REQUEST_LOG_CMD     0x43


class EmbSys {
    protected:
        Queue log;
        uint8_t cmd = REQUEST_LOG_CMD;                             // Command to request the embedded system to send available log information

    public:
        virtual void openSerial(const char* port) = 0;                // Open serial port

        virtual uint8_t sendCommand(uint8_t cmd) = 0;                 // Send command to embedded system

        virtual void serialMonitor() = 0;                             // Read incoming log information

        uint8_t requestLog();                                      // Request available log information from embedded system
};