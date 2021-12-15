/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: clk_cal.h
 * Description: Inheritance exercise - Student/Professor Registry
 */
#ifndef _CLK_CAL_H
#define _CLK_CAL_H

#include "Clock.h"
#include "Calendar.h"

//ClockCalendar class
class ClockCalendar : public Clock, public Calendar {
    public:
        ClockCalendar (int mt, int d, int y, int h, int m, int s, bool pm);
        void advance ();
};

#endif /* _CLK_CAL_H */