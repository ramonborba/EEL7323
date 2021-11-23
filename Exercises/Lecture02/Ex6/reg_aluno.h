/*
 * Autor: Ramon de Araujo Borba
 * Instituicao: UFSC
 * Data: 10/11/2021
 * Arquivo: reg_aluno.h
 * Descricao: Exercicio 6 da aula 2
 */

#define N_ALUNOS 20

class aluno {
        int matricula;
        float nota1;
        float nota2;
        float media;
    public:
        aluno();
        void set_nota(int, float);
        void set_matricula(int);
        float get_nota(int);
        int get_matricula();
        void calc_media();
        float get_media();
};

class turma {
        aluno estudante[20];
        int pede_matricula();
        float pede_nota();
    public:
        void cadastrar_estudante();
        void mod_estudante(int);
        void del_estudante();
        void consulta_estudante();
        void lista_estudantes();
};