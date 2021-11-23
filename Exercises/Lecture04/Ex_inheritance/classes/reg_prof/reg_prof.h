/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: reg_prof.h
 * Description: Inheritance exercise - Student/Professor Registry
 */

#define N_PROFS 20

class Aluno {
        int matricula;
        float nota1;
        float nota2;
        float media;
    public:
        Aluno();
        void set_nota(int, float);
        void set_matricula(int);
        float get_nota(int);
        int get_matricula();
        void calc_media();
        float get_media();
};

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