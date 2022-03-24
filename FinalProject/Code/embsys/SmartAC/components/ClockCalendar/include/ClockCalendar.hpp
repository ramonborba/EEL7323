
/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: ClockCalendar.hpp
 */
#ifndef CLK_CAL_HPP_
#define CLK_CAL_HPP_

#include <ctime>
#include "Clock.hpp"
#include "Calendar.hpp"

//ClockCalendar class
class ClockCalendar : public Clock, public Calendar {
    public:
        /**
         * @brief Construct a new Clock Calendar object with default constructor.
         * 
         */
        ClockCalendar ();
        
        /**
         * @brief Construct a new Clock Calendar object with specific values.
         * 
         * @param mt Month.
         * @param d Day.
         * @param y Year.
         * @param h Hour.
         * @param m Minutes.
         * @param s Seconds.
         * @param pm am:pm indicator.
         */
        ClockCalendar (int mt, int d, int y, int h, int m, int s, bool pm);
        
        /**
         * @brief Construct a new Clock Calendar object using time_t type from ctime library.
         * 
         * @param time System time to store.
         */
        ClockCalendar (time_t time);
        void advance ();
};

#endif /* CLK_CAL_HPP_ */