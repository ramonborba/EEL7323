/**
 * Author: Ramon de Araujo Borba
 * Institution: UFSC
 * Date: 10/11/2021
 * File: calendar.cpp
 */
#include "calendar.h"

//Calendar class members
Calendar::Calendar(int m, int d, int y){
    mo = m;
    day = d;
    yr = y;
}

void Calendar::setCalendar(int m, int d, int y){
    mo = m;
    day = d;
    yr = y;
}

void Calendar::readCalendar(int& m, int& d, int& y){
    m = mo;
    d = day;
    y = yr;
}

void Calendar::advance(){
    day++;
    if (day > 30)
    {
        day = 1;
        mo++;
        if (mo > 12)
        {
            mo = 1;
            yr++;
        }
    }
}