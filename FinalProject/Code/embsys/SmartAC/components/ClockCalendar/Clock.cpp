
/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: Clock.cpp
 */
#include "Clock.hpp"

//Clock class members
Clock::Clock() : time_ {} {}

Clock::Clock(int h, int m, int s, bool pm) : time_ { h, m, s, pm } {}

Clock::Clock(clock_t new_time) : time_ { new_time } {}

void Clock::setClock (int h, int m, int s, bool pm){
    time_.hr = h;
    time_.min = m;
    time_.sec = s;
    time_.is_pm = pm;
}

void Clock::setClock(clock_t new_time)
{
    time_ = new_time;
}

void Clock::readClock (int& h, int& m, int& s, bool& pm){
    h = time_.hr;
    m = time_.min;
    s = time_.sec;
    pm = time_.is_pm;
}

void Clock::readClock(clock_t &rd_time)
{
    rd_time = time_;
}

void Clock::advance(){
    time_.sec++;
    if (time_.sec >= 60)
    {
        time_.sec = 0;
        time_.min ++;
        if (time_.min >= 60)
        {
            time_.min = 0;
            time_.hr++;
            if (time_.hr >=13)
            {
                time_.hr = 1;
            }
            if ((time_.hr >= 12) && (time_.is_pm)) //passa de pm para am >> 11:59:59 > 00:00:00
            {
                time_.hr = 0;
                time_.is_pm = !time_.is_pm;
            }
            else if ((time_.hr >= 12) && (!time_.is_pm))
            {
                time_.is_pm = !time_.is_pm;
            }   
        }   
    }   
}