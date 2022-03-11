/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 02/03/2022
 * File: main.cpp
 */
#include <iostream>
#include <thread>
#include "../src/EmbSysLinux/EmbSysLinux.h"

using namespace std;

void serialMonitoring();
void pressEnterToContinue();

EmbSysLinux* esp32;                             // Embedded System interface

int main(){
    esp32 = new EmbSysLinux();

    thread monitor (serialMonitoring);
    usleep(500000); // Wait for readser thread to print serial connection report
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
        cout << "-------------------------------------------------------------" << endl << endl;

        switch (op)
        {
        case '1':
            esp32->listData();
            pressEnterToContinue();
            break;

        case '2':
            esp32->displayTotalTime();
            pressEnterToContinue();
            break;


        default:
            cout << endl << "Operação invalida, tente novamente" << endl;
            pressEnterToContinue();
            break;
        }

    }
    delete esp32;
    return 0;
}


void serialMonitoring()
{
    const char* port = "/dev/ttyUSB0";  // Port to use
    
    esp32->openSerial(port);
    esp32->serialMonitor();
    delete esp32;
}

void pressEnterToContinue(){
    cout << endl << "Pressione 'Enter' para continuar";
    cin.ignore();
    cin.get();
}