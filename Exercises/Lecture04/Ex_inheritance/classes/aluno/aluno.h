/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: aluno.cpp
 * Description: Inheritance exercise - Student/Professor Registry
 */


//Class Aluno definition
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