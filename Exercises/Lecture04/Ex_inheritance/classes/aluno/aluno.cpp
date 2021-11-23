/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: aluno.cpp
 * Description: Inheritance exercise - Student/Professor Registry
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "aluno.h"


//Members of class Aluno
Aluno::Aluno(){
    matricula = -1;
    nota1 = -1;
    nota2 = -1;
}

void Aluno::set_nota(int sel, float nota = 0){
    if ((nota >= 0) && (nota <=10))
    {
        switch (sel)
        {
        case 1:
            nota1 = nota;
            return;
            break;
        
        case 2:
            nota2 = nota;
            return;
            break;

        case 0:
            nota1 = -1;
            nota2 = -1;
            return;
            break;

        default:
            break;
        }
    }
    else
    {
        cout << "Nota invalida, valor deve estar entre 0.0 e 10.0" << endl;
    }
}


void Aluno::set_matricula(int mat){
    matricula = mat;
}

float Aluno::get_nota(int sel){
        switch (sel)
        {
        case 1:
            return nota1;
            break;

        case 2:
            return nota2;
            break;

        default:
            return -1;
            break;
        }    
}


int Aluno::get_matricula(){
    return matricula;
}

void Aluno::calc_media(){
    if ((nota1 != -1) && (nota2 != -1))
    {
        media = (nota1+nota2)/2;
    }
    else
    {
        media = -1;
    }    
}

float Aluno::get_media(){
    calc_media();
    return media;
}