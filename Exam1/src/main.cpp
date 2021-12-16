/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: main.cpp
 * Description: Inheritance exercise - Student/Professor Registry
 */
#include <iostream>
using namespace std;

#include "classes/CadastroTemp/CadastroTemp.h"
#include "classes/CadastroPressao/CadastroPressao.h"

void pressEnterToContinue();

int main(){
    bool validop = false, sair = false;
    int op = -1;

    CadastroTemp cadTemp;
    CadastroPressao cadPressao;

    while (!sair)
    {
        cout << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << endl;
        cout << "Sistema de gerenciamento de dados de sendores:" << endl;
        cout << endl;
        cout << "-Indice de operacoes:" << endl;
        cout << endl;
        cout << "   Sensor de Temperatura:" << endl;
        cout << "       1 - Nova leitura" << endl;
        cout << "       2 - Excluir leitura" << endl;
        cout << "       3 - Consultar leitura" << endl;
        cout << "       4 - Listar todas as leituras" << endl;
        cout << endl;
        cout << "   Sensor de Pressao:" << endl;
        cout << "       5 - Nova leitura" << endl;
        cout << "       6 - Excluir leitura" << endl;
        cout << "       7 - Consultar determinada leitura" << endl;
        cout << "       8 - Listar todas as leituras" << endl;
        cout << endl;
        cout << "   0 - Sair do programa" << endl;
        cout << endl << "Escolha a operacao: ";
        cin >> op;
        if ( cin.fail() )
        {
            cin.clear();
            cin.ignore(1000, '\n');
            op = -1;
        }
        cout << endl;
        cout << "-------------------------------------------------------------" << endl;

        switch (op)
        {
        case 1:     // New temp reading
            cadTemp.newReading();
            pressEnterToContinue();
            break;

        case 2:     // Delete temp reading
            cadTemp.delReading();
            pressEnterToContinue();
            break;

        case 3:     // Consult temp reading
            cadTemp.getReading();
            pressEnterToContinue();
            break;

        case 4:     // List temp readings
            cadTemp.listReadings();
            pressEnterToContinue();
            break;

        case 5:     // New pressure reading
            cadPressao.newReading();
            pressEnterToContinue();
            break;

        case 6:     // Delete pressure reading
            cadPressao.delReading();
            pressEnterToContinue();
            break;

        case 7:     // Consult pressure reading
            cadPressao.getReading();
            pressEnterToContinue();
            break;

        case 8:     // List pressure reading
            cadPressao.listReadings();
            pressEnterToContinue();
            break;

        case 0:
            sair = true;
            break;

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