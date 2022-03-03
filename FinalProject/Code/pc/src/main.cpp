/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 02/03/2022
 * File: main.cpp
 */
#include <iostream>
using namespace std;


void pressEnterToContinue();

int main(){
    bool validop = false;
    char op = '0';


    while (true)
    {
        cout << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << endl;
        cout << "Gerenciamento do controlador de ar-condicionado:" << endl;
        cout << endl;
        cout << "-Indice de operacoes:" << endl;
        cout << endl;
        cout << "   1 - Listar eventos" << endl;
        cout << "   2 - Tempo total de utilização" << endl;
        cout << endl;
        cout << "Escolha a operacao: ";
        cin >> op;
        cout << endl;
        cout << "-------------------------------------------------------------" << endl;

        switch (op)
        {
        case 1:
            pressEnterToContinue();
            break;

        case 2:
            pressEnterToContinue();
            break;

        // case 3:
        //     pressEnterToContinue();
        //     break;

        // case 4:
        //     pressEnterToContinue();
        //     break;

        // case 5:
        //     pressEnterToContinue();
        //     break;

        // case 6:
        //     pressEnterToContinue();
        //     break;

        // case 7:
        //     pressEnterToContinue();
        //     break;

        // case 8:
        //     pressEnterToContinue();
        //     break;

        default:
            cout << endl << "Operação invalida, tente novamente" << endl;
            pressEnterToContinue();
            break;
        }

    }

    return 0;
}

void pressEnterToContinue(){
    cout << endl << "Pressione 'Enter' para continuar";
    cin.ignore();
    cin.get();
}