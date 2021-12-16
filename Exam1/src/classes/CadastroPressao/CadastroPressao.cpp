/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/12/2021
 * File: CadastroPressao.cpp
 */
#include <iostream>
#include <iomanip>
using namespace std;

#include "CadastroPressao.h"

void CadastroPressao::newReading(){
    int newID, slot = -1;

    // Verify available slots
    for (int i = 0; i < N_PRESSURE_READINGS; i++)
    {
        if (!(pressureReading[i].valid) && (slot == -1))
        {
            slot = i;
            break;
        }
        else if (i == (N_PRESSURE_READINGS-1))
        {
            cout << "Nao ha espaco para novas leituras" << endl;
            return;
        }
    }
    
    // Request reading ID to record
    newID = requestID();

    // Verify if ID is unique
    for (int i = 0; i < N_PRESSURE_READINGS; i++)
    {
        if (pressureReading[i].pressure.getID() == newID)
        {
            cout << "ID ja existente" << endl;
            return;
        }
    }

    // Generate new sensor reading
    if (slot != -1)
    {
        pressureReading[slot].pressure.setID(newID);
        pressureReading[slot].pressure.readSensor();
        pressureReading[slot].valid = true;
        cout << "Leitura cadastrada: " << endl;
        getReading(newID);
    } 
}

void CadastroPressao::delReading(){
    int reqID = requestID();

    // Search for ID
    for (int i = 0; i < N_PRESSURE_READINGS; i++)
    {
        if (reqID == pressureReading[i].pressure.getID())           // Reset values if if is found
        {
            pressureReading[i].valid = false;
            pressureReading[i].pressure = Pressao();
            cout << "Leitura removida" << endl;
            return;   
        }
        else if (i == (N_PRESSURE_READINGS-1))                  // Return if ID not found
        {
            cout << "ID não encontrado" << endl;
            return;
        }
    }
}

void CadastroPressao::getReading(int reqID){
    if (reqID == -1)
    {
        reqID = requestID();
    }   
    
    // Search for ID
    for (int i = 0; i < N_PRESSURE_READINGS; i++)
    {
        if (reqID == pressureReading[i].pressure.getID())               // Print data for requested ID if found
        {
            cout << endl << "Leitura " << i+1 << ":" << endl;
            pressureReading[i].pressure.printData();
            return;   
        }
        else if (i == (N_PRESSURE_READINGS-1))                      // Return if ID not found
        {
            cout << "ID nao encontrado" << endl;
            return;
        }
    }
}

void CadastroPressao::listReadings(){
    cout << endl << "Leituras de Temperatura: " << endl;
    for (int i = 0; i < N_PRESSURE_READINGS; i++)
    {
        if (pressureReading[i].valid)                               // Print valid readings
        {
            cout << endl;
            cout << "Leitura " << i+1 << ":" << endl;
            pressureReading[i].pressure.printData();
        }
    }
    
}

int CadastroPressao::requestID(){
    int newID;
    bool valid=false;
    // Request ID number
    do
    {
        cout << endl << "Digite o ID da leitura: ";
        cin >> newID; cout << endl;
        if ( cin.fail() || (newID < 1) )
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

