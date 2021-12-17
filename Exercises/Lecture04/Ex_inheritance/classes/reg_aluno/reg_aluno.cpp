/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: reg_aluno.cpp
 * Description: Inheritance exercise - Student/Professor Registry
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "reg_aluno.h"

//Members of reg_aluno class

void reg_aluno::incluir_aluno(){
    int mat, slot = -1;

    //Verifica se ha espaco para novos alunos
    for (int i = 0; i < N_ALUNOS; i++)
    {
        if ((aluno[i].get_matricula() == -1) && (slot == -1))
        {
            slot = i;
            break;
        }
        else if (i == (N_ALUNOS-1))
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
    for (int i = 0; i < N_ALUNOS; i++)
    {
        if (aluno[i].get_matricula() == mat)
        {
            cout << "Matricula já esxistente" << endl;
            return;
        }
    }

    //Cadastra matricula do novo aluno
    if (slot != -1)
    {
        aluno[slot].set_matricula(mat);
        mod_aluno(mat);
        cout << "Aluno cadastrado com sucesso" << endl;
    } 
}

void reg_aluno::mod_aluno(int mat){
    float nota;
    string nome;
    int mo, day, yr;

    if (mat == -1)
    {
        mat = pede_matricula();
        if (mat == -1)
        {
            return;
        }
    }
    
    //Procura pela matricula
    for (int i = 0; i < N_ALUNOS; i++)
    {
        if (mat == aluno[i].get_matricula())
        {
            //Modifica informações
            cout << endl << "Nome do aluno ( digite -1 para nao modificar)" << endl;
            nome = pede_nome();
            if (nome != "-1")
            {
                aluno[i].set_nome(nome);
            } 
            cout << endl << "Data de nascimento ( digite -1 para nao modificar)" << endl;
            pede_birth(mo, day, yr);
            if ((mo != -1) && (day != -1) && (yr != -1))
            {
                aluno[i].set_birth(mo, day, yr);
            } 
            cout << endl << "Nota 1 ( digite -1 para nao modificar)" << endl;
            nota = pede_nota();
            if (nota != -1)
            {
                aluno[i].set_nota(1, nota);
            } 
            cout << endl << "Nota 2 ( digite -1 para nao modificar)" << endl;
            nota = pede_nota();
            if (nota != -1)
            {
                aluno[i].set_nota(2, nota);
            }
            return;
        }
        else if (i == (N_ALUNOS-1))
        {
            cout << "Matricula nao encontrada" << endl;
            return;
        }
        
    }
    
}

void reg_aluno::exclui_aluno(){
    int mat = pede_matricula();

    //Procura pela matricula
    for (int i = 0; i < N_ALUNOS; i++)
    {
        if (mat == aluno[i].get_matricula())
        {
            aluno[i].set_matricula(-1);
            aluno[i].set_nota(0, 0);
            aluno[i].calc_media();
            aluno[i].set_nome("");
            aluno[i].set_birth(0, 0, 0);
            cout << "Aluno removido" << endl;
            return;   
        }
        else if (i == (N_ALUNOS-1))
        {
            cout << "Matricula nao encontrada" << endl;
            return;
        }

    }
}

void reg_aluno::consulta_aluno(){
    int mat = pede_matricula();
    int mo, day, yr;

    //Procura pela matricula
    for (int i = 0; i < N_ALUNOS; i++)
    {
        if (mat == aluno[i].get_matricula())
        {
            aluno[i].get_birth(mo, day, yr);
            cout << endl << "Consulta de aluno:" << endl;
            cout    << "- Matricula : " << setw(5) << setfill('0') << aluno[i].get_matricula() << endl
                    << "- Nome      : " << aluno[i].get_nome() << endl
                    << "- Nascimento: " << setw(2) << day << "/" << mo << "/" << setw(4) << yr << endl
                    << "- Nota 1    : " << aluno[i].get_nota(1) << endl
                    << "- Nota 2    : " << aluno[i].get_nota(2) << endl
                    << "- Media     : " << aluno[i].get_media() << endl << endl;
                return;   
        }
        else if (i == (N_ALUNOS-1))
        {
            cout << "Matricula nao encontrada" << endl;
            return;
        }
        
    }
}

void reg_aluno::lista_alunos(){
    int mo, day, yr;

    cout << endl;
    cout << "Lista de alunos:" << endl << endl;

    for (int i = 0; i < N_ALUNOS; i++)
    {
        if (aluno[i].get_matricula() != -1)
        {
            aluno[i].get_birth(mo, day, yr);
            cout    << "Aluno " << (i+1) << ":" << endl ;
            cout    << "- Matricula : " << setw(5) << setfill('0') << aluno[i].get_matricula() << endl
                    << "- Nome      : " << aluno[i].get_nome() << endl
                    << "- Nascimento: " << setw(2) << day << "/" << mo << "/" << setw(4) << yr << endl
                    << "- Nota 1    : " << aluno[i].get_nota(1) << endl
                    << "- Nota 2    : " << aluno[i].get_nota(2) << endl
                    << "- Media     : " << aluno[i].get_media() << endl << endl;
        }        
    }
    
}

int reg_aluno::pede_matricula(){
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

float reg_aluno::pede_nota(){
    float nota;
    //Pede valor da nota
    bool valid;
    while (!valid)
    {
        cout << "Digite o valor da nota: ";
        cin >> nota;
        if ( cin.fail() )
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida, tente novamente" << endl << endl;
        }
        else
        {
            valid=true;
        }
    }
    return nota;
}

string reg_aluno::pede_nome(){
    string nome;
    //Pede nome
    cout << "Digite o nome: ";
    cin >> nome;
    return nome;
}

void reg_aluno::pede_birth(int& mo, int& day, int& yr){
    //Pede datas
    bool valid;
    while (!valid)
    {
        cout << "Digite o dia: ";
        cin >> day;
        if ( cin.fail() )
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida, tente novamente" << endl;
        }
        else
        {
            valid=true;
        }
    }
    valid=false;
    while (!valid)
    {
        cout << "Digite o mes: ";
        cin >> mo;
        if ( cin.fail() )
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida, tente novamente" << endl;
        }
        else
        {
            valid=true;
        }
    }
    valid=false;
    while (!valid)
    {
        cout << "Digite o ano: ";
        cin >> yr;
        if ( cin.fail() )
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida, tente novamente" << endl;
        }
        else
        {
            valid=true;
        }
    }
}