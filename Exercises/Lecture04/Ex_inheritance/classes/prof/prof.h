/*
 * Autor: Ramon de Araujo Borba
 * Instituicao: UFSC
 * Data: 10/11/2021
 * Arquivo: prof.h
 * Descricao: Exercicio 6 da aula 2
 */

#define N_ALUNOS 20

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