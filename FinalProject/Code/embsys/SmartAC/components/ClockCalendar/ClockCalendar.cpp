
/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: clk_cal.cpp
 */
#include "ClockCalendar.hpp"

//ClockCalendar class members
ClockCalendar::ClockCalendar(int mt, int d, int y, int h, int m, int s, bool pm) : Clock(h, m, s, pm), Calendar(mt, d, y){}

void ClockCalendar::advance (){
    bool was_pm = is_pm;
    Clock::advance();
    if ((was_pm) && (!is_pm))
    {
        Calendar::advance();
    }
    
}