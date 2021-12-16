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

struct PressureData
{
    Pressao pressure;
    bool valid = false;
};

class CadastroPressao {
        PressureData pressureReading[N_PRESSURE_READINGS];
        int requestID();
    public:
        void newReading();
        void delReading();
        void getReading(int reqID = -1);
        void listReadings();
};

#endif /* _CADASTROPRESSAO_H_ */