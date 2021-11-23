/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: reg_aluno.h
 * Description: Inheritance exercise - Student/Professor Registry
 */
#include "../aluno/aluno.cpp"

#define N_ALUNOS 20

class reg_aluno {
        Aluno aluno[20];
        int pede_matricula();
        float pede_nota();
    public:
        void incluir_aluno();
        void mod_aluno(int);
        void exclui_aluno();
        void consulta_aluno();
        void lista_alunos();
};