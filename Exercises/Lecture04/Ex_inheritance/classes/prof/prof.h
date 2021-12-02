/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: prof.cpp
 * Description: Inheritance exercise - Student/Professor Registry
 */

#ifndef _PROF_H_
#define _PROF_H_

#include "../pessoa/pessoa.h"

#define N_ALUNOS 20

class Professor: public Pessoa {
        int prof_id;
        std::string password;
    public:
        Professor();
        void set_prof_id(int = -1);
        void set_password(std::string = "");
        int get_prof_id();
        std::string get_password();
};

#endif /* _PROF_H_ */