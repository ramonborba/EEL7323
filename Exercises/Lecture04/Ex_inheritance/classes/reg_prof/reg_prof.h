/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: reg_prof.h
 * Description: Inheritance exercise - Student/Professor Registry
 */

#include "../prof/prof.h"

#define N_PROFS 20

class reg_prof {
        Professor professor[N_PROFS];
        int pede_matricula();
        float pede_nota();
    public:
        void incluir_aluno();
        void mod_aluno(int);
        void exclui_aluno();
        void consulta_aluno();
        void lista_alunos();
};