/**
 * Author: Ramon de Araujo Borba
 * Institution: UFSC
 * Date: 10/11/2021
 * File: teste_clock.cpp
 */
#include <iostream>
#include "clock.cpp"
using namespace std;

int main()
{
    int hour, min, sec;
    bool am_pm;
    Clock relogio (0, 0, 0, false);
    
    cout << "Teste do Clock" << endl;

    cout << "" << endl;
    cout << "Troca de minuto" << endl;
    relogio.setClock(8, 20, 58, false);
    for (int i = 0; i < 5; i++)
    {
        relogio.advance();
        relogio.readClock(hour, min, sec, am_pm);
        cout << "Relogio: " << hour << "h" << min << "m" << sec << "s : " << (am_pm ? "PM" : "AM") << endl;
    }

    cout << "" << endl;
    cout << "Troca de hora" << endl;
    relogio.setClock(8, 59, 58, false);
    for (int i = 0; i < 5; i++)
    {
        relogio.advance();
        relogio.readClock(hour, min, sec, am_pm);
        cout << "Relogio: " << hour << "h" << min << "m" << sec << "s : " << (am_pm ? "PM" : "AM") << endl;
    }

    cout << "" << endl;
    cout << "Troca AM >> PM" << endl;
    relogio.setClock(11, 59, 58, false);
    for (int i = 0; i < 5; i++)
    {
        relogio.advance();
        relogio.readClock(hour, min, sec, am_pm);
        cout << "Relogio: " << hour << "h" << min << "m" << sec << "s : " << (am_pm ? "PM" : "AM") << endl;
    }

    cout << "" << endl;
    cout << "Troca PM >> AM" << endl;
    relogio.setClock(11, 59, 58, true);
    for (int i = 0; i < 5; i++)
    {
        relogio.advance();
        relogio.readClock(hour, min, sec, am_pm);
        cout << "Relogio: " << hour << "h" << min << "m" << sec << "s : " << (am_pm ? "PM" : "AM") << endl;
    }

    cout << "" << endl;
    cout << "Teste 1h PM" << endl;
    relogio.setClock(12, 59, 58, true);
    for (int i = 0; i < 5; i++)
    {
        relogio.advance();
        relogio.readClock(hour, min, sec, am_pm);
        cout << "Relogio: " << hour << "h" << min << "m" << sec << "s : " << (am_pm ? "PM" : "AM") << endl;
    }

    return 0;
}
