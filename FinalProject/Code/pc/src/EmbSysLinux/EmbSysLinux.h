/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 02/03/2022
 * File: EmbSysLinux.h
 */

#ifndef EMBSYSLINUX_H
#define EMBSYSLINUX_H

#include "../EmbSys/EmbSys.h"


class EmbSysLinux : public EmbSys {
    private:

        int serial;                                                 // Handle to serial port
    protected:

    public:
        void openSerial(const char* port);                          // Open serial port

        uint8_t sendCommand(uint8_t cmd);                           // Send command to embedded system

        void serialMonitor();                                       // Read incoming log information (run in a thread)

};
#endif  /* EMBSYSLINUX_H */