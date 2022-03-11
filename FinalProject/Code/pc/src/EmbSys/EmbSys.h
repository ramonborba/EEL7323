/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 02/03/2022
 * File: EmbSys.h
 */

#ifndef EMBSYS_H
#define EMBSYS_H


#include "../Queue/Queue.h"


class EmbSys {
    protected:
        Queue log;
    public:
        virtual void openSerial(const char* port) = 0;              // Open serial port

        virtual uint8_t sendCommand(uint8_t cmd) = 0;               // Send command to embedded system

        virtual void serialMonitor() = 0;                           // Read incoming log information

        void listData();                                            // List stored data

        void displayTotalTime();                                    // Display total time AC was powerded
};

#endif  /* EMBSYS_H */