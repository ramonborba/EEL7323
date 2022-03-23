
/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: clk_cal.h
 */
#ifndef CLK_CAL_HPP_
#define CLK_CAL_HPP_

#include "Clock.hpp"
#include "Calendar.hpp"

//ClockCalendar class
class ClockCalendar : public Clock, public Calendar {
    public:
        ClockCalendar (int mt, int d, int y, int h, int m, int s, bool pm);
        void advance ();
};

#endif /* CLK_CAL_HPP_ */