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
    char resp;
    
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
        cout << "   13 - Usuario Ativo" << endl;
        cout << "    0 - Sair do programa" << endl;
        cout << endl << "Escolha a operacao: ";
        cin >> op; cout << endl;

        switch (op)
        {
        case 1:
            if (!reg_profs.vazio())
            {
                reg_profs.usr_login();
            }
            else
            {
                cout << "Nenhum professor cadastrado." << endl;
                cout << "Deseja cadastrar novo professor agora (s:n)?";
                cin >> resp; cout << endl << endl;
                if (resp == 's')
                {
                    reg_profs.incluir_professor();
                }
            }
            pressEnterToContinue();
            break;
        
        case 2:
            reg_profs.usr_logout();
            pressEnterToContinue();
            break;
        
        case 3:
            if (reg_profs.usr_check_login())
            {
                reg_alunos.incluir_aluno();
            }
            else
            {
                cout << "Faça login primeiro" << endl << endl;
            }
            pressEnterToContinue();
            break;
        
        case 4:
            if (reg_profs.usr_check_login())
            {
                reg_alunos.exclui_aluno();
            }
            else
            {
                cout << "Faça login primeiro" << endl << endl;
            }
            pressEnterToContinue();
            break;
        
        case 5:
            if (reg_profs.usr_check_login())
            {
                reg_alunos.mod_aluno();
            }
            else
            {
                cout << "Faça login primeiro" << endl << endl;
            }
            pressEnterToContinue();
            break;
        
        case 6:
            if (reg_profs.usr_check_login())
            {
                reg_alunos.consulta_aluno();
            }
            else
            {
                cout << "Faça login primeiro" << endl << endl;
            }
            pressEnterToContinue();
            break;
        
        case 7:
            if (reg_profs.usr_check_login())
            {
                reg_alunos.lista_alunos();
            }
            else
            {
                cout << "Faça login primeiro" << endl << endl;
            }
            pressEnterToContinue();
            break;
        
        case 8:
            if (reg_profs.usr_check_login())
            {
                reg_profs.incluir_professor();
            }
            else
            {
                cout << "Faça login primeiro" << endl << endl;
            }
            pressEnterToContinue();
            break;
        
        case 9:
            if (reg_profs.usr_check_login())
            {
                reg_profs.exclui_professor();
            }
            else
            {
                cout << "Faça login primeiro" << endl << endl;
            }
            pressEnterToContinue();
            break;
        
        case 10:
            if (reg_profs.usr_check_login())
            {
                reg_profs.mod_professor();
            }
            else
            {
                cout << "Faça login primeiro" << endl << endl;
            }
            pressEnterToContinue();
            break;
        
        case 11:
            if (reg_profs.usr_check_login())
            {
                reg_profs.consulta_professor();
            }
            else
            {
                cout << "Faça login primeiro" << endl << endl;
            }
            pressEnterToContinue();
            break;
        
        case 12:
            if (reg_profs.usr_check_login())
            {
                reg_profs.lista_professores();
            }
            else
            {
                cout << "Faça login primeiro" << endl << endl;
            }
            pressEnterToContinue();
            break;
        
        case 13:
            reg_profs.usr_show();
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