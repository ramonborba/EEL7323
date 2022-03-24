
/*
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: Calendar.cpp
 */
#include "Calendar.hpp"

//Calendar class members
Calendar::Calendar() : date {} {}

Calendar::Calendar(int m, int d, int y) : date { m, d, y } {}

void Calendar::setCalendar(int m, int d, int y){
    date.mo = m;
    date.day = d;
    date.yr = y;
}

void Calendar::readCalendar(int& m, int& d, int& y){
    m = date.mo;
    d = date.day;
    y = date.yr;
}

void Calendar::advance(){
    date.day++;
    if (date.day > 30)
    {
        date.day = 1;
        date.mo++;
        if (date.mo > 12)
        {
            date.mo = 1;
            date.yr++;
        }
    }
}