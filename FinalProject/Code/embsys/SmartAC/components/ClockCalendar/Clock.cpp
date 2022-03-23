
/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: clock.cpp
 */
#include "Clock.hpp"

//Clock class members
Clock::Clock(int h, int m, int s, bool pm){
    hr = h;
    min = m;
    sec = s;
    is_pm = pm;
}

void Clock::setClock (int h, int m, int s, bool pm){
    hr = h;
    min = m;
    sec = s;
    is_pm = pm;
}

void Clock::readClock (int& h, int& m, int& s, bool& pm){
    h = hr;
    m = min;
    s = sec;
    pm = is_pm;
}

void Clock::advance(){
    sec++;
    if (sec >= 60)
    {
        sec = 0;
        min ++;
        if (min >= 60)
        {
            min = 0;
            hr++;
            if (hr >=13)
            {
                hr = 1;
            }
            if ((hr >= 12) && (is_pm)) //passa de pm para am >> 11:59:59 > 00:00:00
            {
                hr = 0;
                is_pm = !is_pm;
            }
            else if ((hr >= 12) && (!is_pm))
            {
                is_pm = !is_pm;
            }   
        }   
    }   
}