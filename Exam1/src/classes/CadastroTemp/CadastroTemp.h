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

struct TempData
{
    Temperatura temp;
    bool valid = false;
};

class CadastroTemp {
        TempData tempReading[N_TEMP_READINGS];
        int requestID();
    public:
        void newReading();
        void delReading();
        void getReading(int reqID = -1);
        void listReadings();
};

#endif /* _CADASTROTEMP_H_ */