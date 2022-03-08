/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 02/03/2022
 * File: EmbSysLinux.h
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <iostream>
#include <string.h>
#include <sys/ioctl.h>
#include "../EmbSys/EmbSys.h"

using namespace std;


class EmbSysLinux : public EmbSys {
    private:
        fstream logfile;
        const char* logfilename = "logfile.bin";
        int serial;                                                 // Handle to serial port
    protected:

    public:
        void openSerial(const char* port);                          // Open serial port

        char sendCommand(char cmd);                                 // Send command to embedded system

        void serialMonitor();                                             // Read incoming log information (run in a thread)

        void storeData(char* info);                                 // Store log information in a file as hex value
};