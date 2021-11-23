/**
 * Author: Ramon de Araujo Borba
 * Institution: UFSC
 * Date: 10/11/2021
 * File: teste_calendar.cpp
 */
#include <iostream>
#include "calendar.cpp"
using namespace std;

int main()
{
    int month, day, year;
    Calendar calendario (1, 1, 2021);


    cout << "Teste do Calendar" << endl;
    cout << "" << endl;
    cout << "Troca de mes" << endl;
    calendario.setCalendar(3, 28, 1997);
    for (int i = 0; i < 5; i++)
    {
        calendario.advance();
        calendario.readCalendar(month, day, year);
        cout << "Calendario: " << month << "/" << day << "/" << year << endl;
    }

    cout << "" << endl;
    cout << "Troca de ano" << endl;
calendario.setCalendar(12, 28, 1997);
    for (int i = 0; i < 5; i++)
    {
        calendario.advance();
        calendario.readCalendar(month, day, year);
        cout << "Calendario: " << month << "/" << day << "/" << year << endl;
    }
    return 0;
}
