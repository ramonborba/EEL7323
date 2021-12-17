/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/12/2021
 * File: CadastroTemp.h
 */
#ifndef _CADASTROTEMP_H_
#define _CADASTROTEMP_H_

#include "../Temperatura/Temperatura.h"

#define N_TEMP_READINGS 20

struct TempData                                             // Struct for temperature data
{
    Temperatura temp;                                       // Temperatura object
    bool valid = false;                                     // Indicates if there is valid data stored
};

class CadastroTemp {
        TempData tempReading[N_TEMP_READINGS];              // Vector containing N_TEMP_READINGS values
        int requestID();                                    // Requests ID value from user
    public:
        void newReading();                                  // Generates and stores a new reading
        void delReading();                                  // Delete a reading base on it's ID
        void getReading(int reqID = -1);                    // Consult a reading based on it's ID
        void listReadings();                                // Lists all valid readings
};

#endif /* _CADASTROTEMP_H_ */