/*
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: calendar.cpp
 * Description: Inheritance exercise - Student/Professor Registry
 */
#include "Calendar.h"

//Calendar class members
Calendar::Calendar(){
    mo = 0;
    day = 0;
    yr = 0;
}

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