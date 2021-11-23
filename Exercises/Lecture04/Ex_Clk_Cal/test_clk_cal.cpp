/**
 * Author: Ramon de Araujo Borba
 * Institution: UFSC
 * Date: 10/11/2021
 * File: teste_clk_cal.cpp
 */
#include <iostream>
#include "clk_cal.cpp"
using namespace std;

int main()
{
    int hour, min, sec, month, day, year;
    bool am_pm;
    ClockCalendar watch (1, 1, 2021, 0, 0, 0, false);

    cout << "Teste do ClockCalendar" << endl;
    cout << "" << endl;
    cout << "Troca de minuto" << endl;
    watch.setClock(8, 20, 58, false);
    for (int i = 0; i < 5; i++)
    {
        watch.advance();
        watch.readClock(hour, min, sec, am_pm);
        cout << "Hora: " << hour << "h" << min << "m" << sec << "s : " << (am_pm ? "PM" : "AM") << endl;
    }

    cout << "" << endl;
    cout << "Troca de hora" << endl;
    watch.setClock(8, 59, 58, false);
    for (int i = 0; i < 5; i++)
    {
        watch.advance();
        watch.readClock(hour, min, sec, am_pm);
        cout << "Hora: " << hour << "h" << min << "m" << sec << "s : " << (am_pm ? "PM" : "AM") << endl;
    }

    cout << "" << endl;
    cout << "Troca AM >> PM" << endl;
    watch.setClock(11, 59, 58, false);
    for (int i = 0; i < 5; i++)
    {
        watch.advance();
        watch.readClock(hour, min, sec, am_pm);
        cout << "Hora: " << hour << "h" << min << "m" << sec << "s : " << (am_pm ? "PM" : "AM") << endl;
    }

    cout << "" << endl;
    cout << "Troca PM >> AM" << endl;
    watch.setClock(11, 59, 58, true);
    for (int i = 0; i < 5; i++)
    {
        watch.advance();
        watch.readClock(hour, min, sec, am_pm);
        cout << "Hora: " << hour << "h" << min << "m" << sec << "s : " << (am_pm ? "PM" : "AM") << endl;
    }

    cout << "" << endl;
    cout << "Teste 1h PM" << endl;
    watch.setClock(12, 59, 58, true);
    for (int i = 0; i < 5; i++)
    {
        watch.advance();
        watch.readClock(hour, min, sec, am_pm);
        cout << "Hora: " << hour << "h" << min << "m" << sec << "s : " << (am_pm ? "PM" : "AM") << endl;
    }
    
    cout << "" << endl;
    cout << "Troca de dia" << endl;
    watch.setClock(11, 59, 58, true);
    watch.setCalendar(3, 28, 1997);
    for (int i = 0; i < 5; i++)
    {
        watch.advance();
        watch.readCalendar(month, day, year);
        watch.readClock(hour, min, sec, am_pm);        
        cout << "Data: " << month << "/" << day << "/" << year << endl;
        cout << "Hora: " << hour << "h" << min << "m" << sec << "s : " << (am_pm ? "PM" : "AM") << endl;
    }

    cout << "" << endl;
    cout << "Troca de mes" << endl;
    watch.setClock(11, 59, 58, true);
    watch.setCalendar(3, 30, 1997);
    for (int i = 0; i < 5; i++)
    {
        watch.advance();
        watch.readCalendar(month, day, year);
        watch.readClock(hour, min, sec, am_pm);        
        cout << "Data: " << month << "/" << day << "/" << year << endl;
        cout << "Hora: " << hour << "h" << min << "m" << sec << "s : " << (am_pm ? "PM" : "AM") << endl;
    }

    cout << "" << endl;
    cout << "Troca de ano" << endl;
    watch.setClock(11, 59, 58, true);
    watch.setCalendar(12, 30, 1997);
    for (int i = 0; i < 5; i++)
    {
        watch.advance();
        watch.readCalendar(month, day, year);
        watch.readClock(hour, min, sec, am_pm);        
        cout << "Data: " << month << "/" << day << "/" << year << endl;
        cout << "Hora: " << hour << "h" << min << "m" << sec << "s : " << (am_pm ? "PM" : "AM") << endl;
    }
    return 0;
}
