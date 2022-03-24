
/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: Clock.cpp
 */
#include "Clock.hpp"

//Clock class members
Clock::Clock() : time {} {}

Clock::Clock(int h, int m, int s, bool pm) : time { h, m, s, pm } {}

void Clock::setClock (int h, int m, int s, bool pm){
    time.hr = h;
    time.min = m;
    time.sec = s;
    time.is_pm = pm;
}

void Clock::readClock (int& h, int& m, int& s, bool& pm){
    h = time.hr;
    m = time.min;
    s = time.sec;
    pm = time.is_pm;
}

void Clock::advance(){
    time.sec++;
    if (time.sec >= 60)
    {
        time.sec = 0;
        time.min ++;
        if (time.min >= 60)
        {
            time.min = 0;
            time.hr++;
            if (time.hr >=13)
            {
                time.hr = 1;
            }
            if ((time.hr >= 12) && (time.is_pm)) //passa de pm para am >> 11:59:59 > 00:00:00
            {
                time.hr = 0;
                time.is_pm = !time.is_pm;
            }
            else if ((time.hr >= 12) && (!time.is_pm))
            {
                time.is_pm = !time.is_pm;
            }   
        }   
    }   
}