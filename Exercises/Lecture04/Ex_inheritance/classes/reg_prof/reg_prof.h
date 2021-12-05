/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: reg_prof.h
 * Description: Inheritance exercise - Student/Professor Registry
 */

#include "../prof/prof.h"

#define N_PROFS 20

struct User
{
    Professor active_user;
    bool logged_in = false;
};

class reg_prof {
        Professor professor[N_PROFS];
        User usr;
        int pede_id();
        std::string pede_password();
        std::string pede_nome();
        void pede_birth(int&, int&, int&);
    public:
        void incluir_professor();
        void mod_professor(int = -1);
        void exclui_professor();
        void consulta_professor();
        void lista_professores();
        void usr_login();
        void usr_logout();
        void usr_show();
        bool usr_check_login();
        bool vazio();
};