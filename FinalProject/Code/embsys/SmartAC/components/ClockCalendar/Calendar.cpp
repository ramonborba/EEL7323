
/*
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: Calendar.cpp
 */
#include "Calendar.hpp"

//Calendar class members
Calendar::Calendar() : date_ {} {}

Calendar::Calendar(int m, int d, int y) : date_ { m, d, y } {}

Calendar::Calendar(calendar_t new_date) : date_ { new_date } {}

void Calendar::setCalendar(int m, int d, int y){
    date_.mo = m;
    date_.day = d;
    date_.yr = y;
}

void Calendar::setCalendar(calendar_t new_date)
{
    date_ = new_date;
}

void Calendar::readCalendar(int& m, int& d, int& y){
    m = date_.mo;
    d = date_.day;
    y = date_.yr;
}

void Calendar::readCalendar(calendar_t &rd_date)
{
    rd_date = date_;
}

void Calendar::advance(){
    date_.day++;
    if (date_.day > 30)
    {
        date_.day = 1;
        date_.mo++;
        if (date_.mo > 12)
        {
            date_.mo = 1;
            date_.yr++;
        }
    }
}