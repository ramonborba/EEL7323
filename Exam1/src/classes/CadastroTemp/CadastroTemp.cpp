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

void CadastroTemp::newReading(){
    int newID, slot = -1;

    // Verify available slots
    for (int i = 0; i < N_TEMP_READINGS; i++)
    {
        if (!(tempReading[i].valid) && (slot == -1))
        {
            slot = i;
            break;
        }
        else if (i == (N_TEMP_READINGS-1))
        {
            cout << "Nao ha espaco para novas leituras" << endl;
            return;
        }
    }
    
    // Request reading ID to record
    newID = requestID();

    // Verify if ID is unique
    for (int i = 0; i < N_TEMP_READINGS; i++)
    {
        if (tempReading[i].temp.getID() == newID)
        {
            cout << "ID ja existente" << endl;
            return;
        }
    }

    // Generate new sensor reading
    if (slot != -1)
    {
        tempReading[slot].temp.setID(newID);
        tempReading[slot].temp.readSensor();
        tempReading[slot].valid = true;
        cout << "Leitura cadastrada: " << endl;
        // Show new reading -- use getReading()
    } 
}

void CadastroTemp::delReading(){
    int reqID = requestID();

    // Search for ID
    for (int i = 0; i < N_TEMP_READINGS; i++)
    {
        if (reqID == tempReading[i].temp.getID())
        {
            tempReading[i].valid = false;
            tempReading[i].temp = Temperatura();
            cout << "Leitura removida" << endl;
            return;   
        }
        else if (i == (N_TEMP_READINGS-1))
        {
            cout << "ID não encontrado" << endl;
            return;
        }
    }
}

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

