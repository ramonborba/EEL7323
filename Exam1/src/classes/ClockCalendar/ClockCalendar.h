/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/12/2021
 * File: ClockCalendar.h
 */
#ifndef _CLK_CAL_H
#define _CLK_CAL_H

#include <ctime>
#include "Clock.h"
#include "Calendar.h"

//ClockCalendar class
class ClockCalendar : public Clock, public Calendar {
    public:
        ClockCalendar ();
        ClockCalendar (int mt, int d, int y, int h, int m, int s, bool pm);
        ClockCalendar (time_t time);
        void advance ();
        void printClkCal();
};

#endif /* _CLK_CAL_H */