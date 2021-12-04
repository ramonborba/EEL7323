/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: main.cpp
 * Description: Inheritance exercise - Student/Professor Registry
 */
#include <iostream>
using namespace std;

#include "./classes/clk_cal/calendar.cpp"
#include "./classes/pessoa/pessoa.cpp"
#include "./classes/aluno/aluno.cpp"
#include "./classes/reg_aluno/reg_aluno.cpp"
#include "./classes/prof/prof.cpp"
#include "./classes/reg_prof/reg_prof.cpp"


void pressEnterToContinue();

int main(){
    reg_aluno reg_alunos;
    reg_prof reg_profs;

    bool sair = false;
    int op = -1;
    
    system("clear");
    while (!sair)
    {       
        cout << "Sistema de registro de alunos e professores:" << endl;
        cout << endl;
        cout << "-Indice de operacoes:" << endl;
        cout << "    1 - Login" << endl;
        cout << "    2 - Logout" << endl;
        cout << "    3 - Incluir Aluno" << endl;
        cout << "    4 - Excluir Aluno" << endl;
        cout << "    5 - Alterar Aluno" << endl;
        cout << "    6 - Consultar Aluno" << endl;
        cout << "    7 - Listar Alunos" << endl;
        cout << "    8 - Incluir Professor" << endl;
        cout << "    9 - Excluir Professor" << endl;
        cout << "   10 - Alterar Professor" << endl;
        cout << "   11 - Consultar Professor" << endl;
        cout << "   12 - Listar Professores" << endl;
        cout << "    0 - Sair do programa" << endl;
        cout << endl << "Escolha a operacao: ";
        cin >> op;

        switch (op)
        {
        case 1:
            pressEnterToContinue();
            break;
        
        case 2:
            pressEnterToContinue();
            break;
        
        case 3:
            reg_alunos.incluir_aluno();
            pressEnterToContinue();
            break;
        
        case 4:
            reg_alunos.exclui_aluno();
            pressEnterToContinue();
            break;
        
        case 5:
            reg_alunos.mod_aluno();
            pressEnterToContinue();
            break;
        
        case 6:
            reg_alunos.consulta_aluno();
            pressEnterToContinue();
            break;
        
        case 7:
            reg_alunos.lista_alunos();
            pressEnterToContinue();
            break;
        
        case 8:
            reg_profs.incluir_professor();
            pressEnterToContinue();
            break;
        
        case 9:
            reg_profs.exclui_professor();
            pressEnterToContinue();
            break;
        
        case 10:
            reg_profs.mod_professor();
            pressEnterToContinue();
            break;
        
        case 11:
            reg_profs.consulta_professor();
            pressEnterToContinue();
            break;
        
        case 12:
            reg_profs.lista_professores();
            pressEnterToContinue();
            break;
        
        case 0:
            sair = true;
            system("clear");
            break;
        
        default:
            cout << "Operação invalida" << endl;
            pressEnterToContinue();
            break;
        }

    }
    
    return 0;
}

void pressEnterToContinue(){
    cout << endl << "Pressione 'Enter' para continuar.";
    cin.ignore();
    cin.get();
    system("clear");
}