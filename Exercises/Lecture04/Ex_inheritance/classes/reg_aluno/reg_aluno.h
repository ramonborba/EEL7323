/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: reg_aluno.h
 * Description: Inheritance exercise - Student/Professor Registry
 */

#ifndef _REG_ALUNO_H_
#define _REG_ALUNO_H_

#include "../aluno/aluno.h"

#define N_ALUNOS 20

class reg_aluno {
        Aluno aluno[N_ALUNOS];
        int pede_matricula();
        float pede_nota();
        std::string pede_nome();
        void pede_birth(int&, int&, int&);
    public:
        void incluir_aluno();
        void mod_aluno(int = -1);
        void exclui_aluno();
        void consulta_aluno();
        void lista_alunos();
};

#endif /* _REG_ALUNO_H_ */