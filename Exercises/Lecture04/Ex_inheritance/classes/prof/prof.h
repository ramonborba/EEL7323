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
        bool pswd_is_set;
        std::string password;
        void set_password(std::string = "");
    public:
        Professor();
        void set_prof_id(int = -1);
        int get_prof_id();
        std::string get_password();
        void mod_password();
        int delete_password();
        bool check_password(std::string);
};

#endif /* _PROF_H_ */