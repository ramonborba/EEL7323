/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 02/03/2022
 * File: EmbSys.h
 */
#include <fstream>
#include <iostream>
using namespace std;

#define REQUEST_LOG_CMD     0x43


class EmbSys {
    private:

    protected:
        char* data;                                             // Pointer to log data
        char cmd = REQUEST_LOG_CMD;                             // Command to request the embedded system to send available log information

    public:
        virtual void openSerial(const char* port) = 0;                // Open serial port

        virtual char sendCommand(char cmd) = 0;                 // Send command to embedded system

        virtual void serialMonitor() = 0;                             // Read incoming log information

        virtual void storeData(char* info) = 0;                           // Store log information in a file as hex values

        char requestLog();                                      // Request available log information from embedded system
};