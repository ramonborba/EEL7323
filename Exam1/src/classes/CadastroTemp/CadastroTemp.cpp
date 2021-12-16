/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/12/2021
 * File: CadastroTemp.cpp
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "CadastroTemp.h"

void CadastroTemp::newReading(){}

void CadastroTemp::delReading(){}

void CadastroTemp::get_Reading(){}

void CadastroTemp::listReadings(){}

int CadastroTemp::requestID(){
    int newID;
    bool valid=false;
    // Request ID number
    do
    {
        cout << endl << "Digite o ID da leitura: ";
        cin >> newID;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "ID invalido, tente novamente" << endl;
        }
        else
        {
            valid=true;
        }
    } while (!valid);

    return newID;
}

