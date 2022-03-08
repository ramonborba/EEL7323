/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 02/03/2022
 * File: EmbSysLinux.cpp
 */

#include "EmbSysLinux.h"


void EmbSysLinux::openSerial(const char* port){

   struct termios options;


   serial = open(port, O_RDWR|O_NOCTTY|O_NDELAY);
   if (serial == -1)      // ERROR!!
      cout << "Error opening " << serial << endl;
   else
      fcntl(serial, F_SETFL, 0);
   cout << "Serial port in use: " << port << endl << endl;

   // Program serial port to 115200, 8, 1, no parity
   //

   // Get the current options for the port
   tcgetattr(serial, &options);

   // Set the baud rate to 115200
   cfsetispeed(&options, B115200);
   cfsetospeed(&options, B115200);

   // Enable the receiver and set local mode
   options.c_cflag |= (CLOCAL | CREAD);

   // Setting parity checking (no parity) 8N1
   options.c_cflag &= ~PARENB;        /* no parity */
   options.c_cflag &= ~CSTOPB;        /* 1 stop bit */
   options.c_cflag &= ~CSIZE;         /* Mask the character size bits */
   options.c_cflag |= CS8;            /* Select 8 data bits */

   // Setting raw input
   options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

   // Setting raw output
   options.c_oflag &= ~OPOST;

   // Set the new options for the port
   tcsetattr(serial, TCSANOW, &options);

}


char EmbSysLinux::sendCommand(char cmd){

    int npkg;

    if (serial == -1)
        cout << "Erro: the serial port is closed. Please, "
        << "use the openSerial() method to open it. " << endl;
    else{
        int n = write(serial, &cmd, 1);  // send 2 bytes command & motors
        if (n < 0)
            cout << "Error! write() command failed." << endl;
        else {
            fcntl(serial, F_SETFL, FNDELAY);
            int i = read(serial, &npkg, 1); // read 1 Byte interface status
            fcntl(serial, F_SETFL, 0); 
        }
    }
    return npkg;
}

void EmbSysLinux::serialMonitor(){
    int i, nbytes;
    if (serial == -1)
        cout << "Erro: the serial port is closed. Please, "
        << "use the openSerial() method to open it. " << endl;
    else
    {
        while(true)
        {
            ioctl(serial, FIONREAD, &nbytes);               // Detect bytes in IO buffer
            data = new char[nbytes];
            i = read(serial, data, sizeof(data));         // Read available data
            // Store data
            delete[] data;
        }
    }
}
