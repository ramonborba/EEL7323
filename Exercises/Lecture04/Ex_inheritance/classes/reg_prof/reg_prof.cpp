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

void reg_prof::incluir_professor(){
    int new_id, slot = -1;

    //Verifica se ha espaco para novos professores
    for (int i = 0; i < N_PROFS; i++)
    {
        if ((professor[i].get_prof_id() == -1) && (slot == -1))
        {
            slot = i;
            break;
        }
        else if (i == (N_PROFS-1))
        {
            cout << "Nao e possivel cadastrar novos professores" << endl;
            return;
        }
    }
    
    //Pede numero de id a ser cadastrado
    new_id = pede_id();
    if (new_id == -1)
    {
        return;
    }
    

    //Verifica se new_id ja existe
    for (int i = 0; i < N_PROFS; i++)
    {
        if (professor[i].get_prof_id() == new_id)
        {
            cout << "ID já esxistente" << endl;
            return;
        }
    }

    //IMPLEMENTAR SENHA
    //Cadastra ID do novo professor
    if (slot != -1)
    {
        professor[slot].set_prof_id(new_id);
        mod_professor(new_id);
        cout << "Professor cadastrado com sucesso" << endl;
    } 
}

void reg_prof::mod_professor(int req_id){
    string nome;
    int mo, day, yr;

    //IMPLEMENTAR SENHA

    if (req_id == -1)
    {
        req_id = pede_id();
        if (req_id == -1)
        {
            return;
        }
    }
    
    //Procura pelo id
    for (int i = 0; i < N_PROFS; i++)
    {
        if (req_id == professor[i].get_prof_id())
        {
            //Modifica informações
            cout << endl << "Nome do professor ( digite -1 para nao modificar)" << endl;
            nome = pede_nome();
            if (nome != "-1")
            {
                professor[i].set_nome(nome);
            } 
            cout << endl << "Data de nascimento ( digite -1 para nao modificar)" << endl;
            pede_birth(mo, day, yr);
            if ((mo != -1) && (day != -1) && (yr != -1))
            {
                professor[i].set_birth(mo, day, yr);
            } 
            return;
        }
        else if (i == (N_PROFS-1))
        {
            cout << "ID nao encontrado" << endl;
            return;
        }
        
    }
    
}

void reg_prof::exclui_professor(){
    int req_id = pede_id();

    //Procura pela matricula
    for (int i = 0; i < N_PROFS; i++)
    {
        if (req_id == professor[i].get_prof_id())
        {
            // IMPLEMENTAR SENHA
            professor[i].set_prof_id();
            // professor[i].delete_password(pswd);
            professor[i].set_nome();
            professor[i].set_birth();
            cout << "Professor removido" << endl;
            return;   
        }
        else if (i == (N_PROFS-1))
        {
            cout << "Matricula nao encontrada" << endl;
            return;
        }

    }
}

void reg_prof::consulta_professor(){
    int req_id = pede_id();
    int mo, day, yr;

    //Procura pela matricula
    for (int i = 0; i < N_PROFS; i++)
    {
        if (req_id == professor[i].get_prof_id())
        {
            professor[i].get_birth(mo, day, yr);
            cout << endl << "Consulta de professor:" << endl;
            cout    << "- ID        : " << setw(5) << setfill('0') << professor[i].get_prof_id() << endl
                    << "- Nome      : " << professor[i].get_nome() << endl
                    << "- Nascimento: " << setw(2) << day << "/" << mo << "/" << setw(4) << yr << endl;
                return;   
        }
        else if (i == (N_PROFS-1))
        {
            cout << "ID nao encontrado" << endl;
            return;
        }
        
    }
}

void reg_prof::lista_professores(){
    int mo, day, yr;

    cout << endl;
    cout << "Lista de professores:" << endl << endl;

    for (int i = 0; i < N_PROFS; i++)
    {
        professor[i].get_birth(mo, day, yr);
        cout    << "Professor " << (i+1) << ":" << endl ;
        cout    << "- ID        : " << setw(5) << setfill('0') << professor[i].get_prof_id() << endl
                << "- Nome      : " << professor[i].get_nome() << endl
                << "- Nascimento: " << setw(2) << day << "/" << mo << "/" << setw(4) << yr << endl;
    }
    
}

int reg_prof::pede_id(){
    int req_id;
    //Pede numero de id
    cout << endl << "Digite o ID: ";
    cin >> req_id;
    
    //Verifica se id é valido
    if (req_id < 0)
    {
        cout << "ID invalido" << endl;
        return -1;
    }
    else
    {
        return req_id;
    }
}


string reg_prof::pede_nome(){
    string nome;
    //Pede nome
    cout << "Digite o nome: ";
    cin >> nome;
    return nome;
}

void reg_prof::pede_birth(int& mo, int& day, int& yr){
    //Pede datas
    cout << "Digite o dia: ";
    cin >> day;
    cout << "Digite o mes: ";
    cin >> mo;
    cout << "Digite o ano: ";
    cin >> yr;
}