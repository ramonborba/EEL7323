/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/12/2021
 * File: CadastroPressao.h
 */
#ifndef _CADASTROPRESSAO_H_
#define _CADASTROPRESSAO_H_

#include "../Pressao/Pressao.h"

#define N_PRESSURE_READINGS 20

struct PressureData                                             // Struct for pressure data
{
    Pressao pressure;                                           // Pressao object
    bool valid = false;                                         // Indicates if there is valid data stored
};

class CadastroPressao {
        PressureData pressureReading[N_PRESSURE_READINGS];      // Vector containing N_PRESSURE_READINGS values
        int requestID();                                        // Requests ID value from user
    public:
        void newReading();                                      // Generates and stores a new reading
        void delReading();                                      // Delete a reading base on it's ID
        void getReading(int reqID = -1);                        // Consult a reading based on it's ID
        void listReadings();                                    // Lists all valid readings
};

#endif /* _CADASTROPRESSAO_H_ */