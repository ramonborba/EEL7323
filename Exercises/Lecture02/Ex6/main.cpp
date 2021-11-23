/*
 * Autor: Ramon de Araujo Borba
 * Instituicao: UFSC
 * Data: 10/11/2021
 * Arquivo: main.cpp
 * Descricao: Exercicio 6 da aula 2
 */
#include "reg_aluno.cpp"

void pressEnterToContinue();

int main(){
    turma turma1;
    bool sair = false;
    int op = -1;
    
    system("clear");
    while (!sair)
    {
        cout << "Sistema de registro de alunos:" << endl;
        cout << endl;
        cout << "-Indice de operacoes:" << endl;
        cout << "   1 - Cadastrar aluno" << endl;
        cout << "   2 - Consultar aluno" << endl;
        cout << "   3 - Modificar aluno" << endl;
        cout << "   4 - Excluir aluno" << endl;
        cout << "   5 - Listar todos os alunos" << endl;
        cout << "   0 - Sair do programa" << endl;
        cout << endl << "Escolha a operacao: ";
        cin >> op;

        switch (op)
        {
        case 1:
            turma1.cadastrar_estudante();
            pressEnterToContinue();
            break;
        
        case 2:
            turma1.consulta_estudante();
            pressEnterToContinue();
            break;
        
        case 3:
            turma1.mod_estudante();
            pressEnterToContinue();
            break;
        
        case 4:
            turma1.del_estudante();
            pressEnterToContinue();
            break;
        
        case 5:
            turma1.lista_estudantes();
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