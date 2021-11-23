/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: reg_prof.cpp
 * Description: Inheritance exercise - Student/Professor Registry
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "reg_prof.h"


//Membros da classe aluno
aluno::aluno(){
    matricula = -1;
    nota1 = -1;
    nota2 = -1;
}

void aluno::set_nota(int sel, float nota = 0){
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


void aluno::set_matricula(int mat){
    matricula = mat;
}

float aluno::get_nota(int sel){
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


int aluno::get_matricula(){
    return matricula;
}

void aluno::calc_media(){
    if ((nota1 != -1) && (nota2 != -1))
    {
        media = (nota1+nota2)/2;
    }
    else
    {
        media = -1;
    }    
}

float aluno::get_media(){
    calc_media();
    return media;
}


/*******************************************************************************/
//Membros da classe turma

void turma::cadastrar_estudante(){
    int mat, slot = -1;

    //Verifica se ha espaco para novos alunos
    for (int i = 0; i < N_PROFS; i++)
    {
        if ((estudante[i].get_matricula() == -1) && (slot == -1))
        {
            slot = i;
            break;
        }
        else if (i == (N_PROFS-1))
        {
            cout << "Nao e possivel cadastrar novos alunos" << endl;
            return;
        }
    }
    
    //Pede numero de matricula a ser cadastrado
    mat = pede_matricula();
    if (mat == -1)
    {
        return;
    }
    

    //Verifica se matricula ja existe
    for (int i = 0; i < N_PROFS; i++)
    {
        if (estudante[i].get_matricula() == mat)
        {
            cout << "Matricula já esxistente" << endl;
            return;
        }
        else if ((estudante[i].get_matricula() == -1) && (slot == -1))
        {
            slot = i;
        }
    }

    //Cadastra matricula do novo aluno
    if (slot != -1)
    {
        estudante[slot].set_matricula(mat);
        mod_estudante(mat);
        cout << "Aluno cadastrado com sucesso" << endl;
    } 
}

void turma::mod_estudante(int mat = -1){
    float nota;
    if (mat == -1)
    {
        mat = pede_matricula();
        if (mat == -1)
        {
            return;
        }
    }
    
    //Procura pela matricula
    for (int i = 0; i < N_PROFS; i++)
    {
        if (mat == estudante[i].get_matricula())
        {
            //Modifica informações
            cout << endl << "Nota 1 ( digite -1 para nao modificar)" << endl;
            nota = pede_nota();
            if (nota != -1)
            {
                estudante[i].set_nota(1, nota);
            } 
            cout << endl << "Nota 2 ( digite -1 para nao modificar)" << endl;
            nota = pede_nota();
            if (nota != -1)
            {
                estudante[i].set_nota(2, nota);
            }
            return;
        }
        else if (i == (N_PROFS-1))
        {
            cout << "Matricula nao encontrada" << endl;
            return;
        }
        
    }
    
}

void turma::del_estudante(){
    int mat = pede_matricula();

    //Procura pela matricula
    for (int i = 0; i < N_PROFS; i++)
    {
        if (mat == estudante[i].get_matricula())
        {
            estudante[i].set_matricula(-1);
            estudante[i].set_nota(0);
            estudante[i].calc_media();
            cout << "Aluno removido" << endl;
            return;   
        }
        else if (i == (N_PROFS-1))
        {
            cout << "Matricula nao encontrada" << endl;
            return;
        }

    }
}

void turma::consulta_estudante(){
    int mat = pede_matricula();

    //Procura pela matricula
    for (int i = 0; i < N_PROFS; i++)
    {
        if (mat == estudante[i].get_matricula())
        {
            cout << endl << "Consulta de aluno:" << endl;
            cout    << "-Matricula: " << setw(5) << setfill('0') << estudante[i].get_matricula() << endl
                    << "-Nota 1: " << estudante[i].get_nota(1) << endl
                    << "-Nota 2: " << estudante[i].get_nota(2) << endl
                    << "-Media : " << estudante[i].get_media() << endl << endl;
                return;   
        }
        else if (i == (N_PROFS-1))
        {
            cout << "Matricula nao encontrada" << endl;
            return;
        }
        
    }
}

void turma::lista_estudantes(){
    
    cout << endl;
    cout << "Lista de alunos:" << endl << endl;

    for (int i = 0; i < N_PROFS; i++)
    {
        cout    << "Aluno " << (i+1) << ":" << endl 
                << "-Matricula: " << setw(5) << setfill('0') << estudante[i].get_matricula() << endl
                << "-Nota 1: " << estudante[i].get_nota(1) << endl
                << "-Nota 2: " << estudante[i].get_nota(2) << endl
                << "-Media : " << estudante[i].get_media() << endl << endl;
    }
    
}

int turma::pede_matricula(){
    int mat;
    //Pede numero de matricula
    cout << endl << "Digite o numero de matrícula: ";
    cin >> mat;
    
    //Verifica se matrícula é valida
    if (mat < 0)
    {
        cout << "Matricula invalida" << endl;
        return -1;
    }
    else
    {
        return mat;
    }
}

float turma::pede_nota(){
    float nota;
    //Pede valor da nota
    cout << "Digite o valor da nota: ";
    cin >> nota;
    return nota;
}