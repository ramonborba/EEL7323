/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 02/03/2022
 * File: EmbSys.h
 */

#define DATA_PKG_SIZE       1                                   // Size of one log entry
#define REQUEST_LOG_CMD     0x43


class EmbSys {
    private:

    protected:
        char data[DATA_PKG_SIZE];
        char cmd = REQUEST_LOG_CMD;                                        // Command to request the embedded system to send available log information

    public:
        virtual void openSerial(int ser) = 0;                   // Open serial port

        virtual char sendCommand(char cmd) = 0;                 // Send command to embedded system

        virtual char readLog() = 0;                             // Read incoming log information

        virtual void storeData() = 0;                           // Store log information in a txt file as hex values

        char requestLog();                                      // Request available log information from embedded system
};