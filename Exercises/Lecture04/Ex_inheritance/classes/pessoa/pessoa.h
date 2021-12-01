/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: pessoa.h
 * Description: Inheritance exercise - Student/Professor Registry
 */
#ifndef _PESSOA_H_
#define _PESSOA_H_

#include <string>

#include "../clk_cal/calendar.h"

//Class Pessoa definition
class Pessoa {
        std::string nome;
        Calendar birth;       
    public:
        Pessoa();
        void set_nome(std::string);
        void set_birth(int, int, int);
        std::string get_nome();
        void get_birth(int&, int&, int&);        
};

#endif /* _PESSOA_H_ */