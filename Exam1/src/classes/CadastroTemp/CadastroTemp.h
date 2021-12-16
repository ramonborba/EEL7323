/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: reg_aluno.h
 * Description: Inheritance exercise - Student/Professor Registry
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
        void get_Reading();
        void listReadings();
};

#endif /* _CADASTROTEMP_H_ */