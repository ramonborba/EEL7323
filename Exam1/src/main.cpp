/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: main.cpp
 * Description: Inheritance exercise - Student/Professor Registry
 */
#include <iostream>
using namespace std;

void pressEnterToContinue();

int main(){

    bool sair = false;
    int op = -1;
    
    while (!sair)
    {   
        cout << endl;   
        cout << "------------------------------------------------------------" << endl;
        cout << endl;   
        cout << "Sistema de gerenciamento de dados de sendores:" << endl;
        cout << endl;
        cout << "-Indice de operacoes:" << endl;
        cout << endl;
        cout << "   Sensor de Temperatura:" << endl;
        cout << "   1 - Leitura de sensor de temperatura" << endl;
        cout << "   2 - Excluir temperatura" << endl;
        cout << "   3 - Consultar determinada temperatura" << endl;
        cout << "   4 - Listar todas as temperaturas" << endl;
        cout << endl;
        cout << "   Sensor de Pressao:" << endl;
        cout << "   5 - Leitura de sensor de pressao" << endl;
        cout << "   6 - Excluir pressao" << endl;
        cout << "   7 - Consultar determinada pressao" << endl;
        cout << "   8 - Listar todas as pressoes" << endl;
        cout << endl;
        cout << "   0 - Sair do programa" << endl;
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
            pressEnterToContinue();
            break;
        
        case 4:
            pressEnterToContinue();
            break;
        
        case 5:
            pressEnterToContinue();
            break;
        
        case 6:
            pressEnterToContinue();
            break;
        
        case 7:
            pressEnterToContinue();
            break;
        
        case 8:
            pressEnterToContinue();
            break;
        
        case 0:
            sair = true;
            break;
        
        default:
            cout << endl << "Operação invalida" << endl;
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
}