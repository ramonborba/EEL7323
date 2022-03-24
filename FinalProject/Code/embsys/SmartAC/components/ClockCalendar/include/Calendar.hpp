
/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: Calendar.hpp
 */
#ifndef CALENDAR_HPP_
#define CALENDAR_HPP_

//Calendar class
class Calendar {
    protected:
        int mo, day, yr;
    public:
        /**
         * @brief Construct a new Calendar object with default constructor.
         * 
         */
        Calendar();

        /**
         * @brief Construct a new Calendar object.
         * 
         * @param m Month.
         * @param d Day.
         * @param y Year.
         */
        Calendar (int m, int d, int y);

        /**
         * @brief Set the Calendar object.
         * 
         * @param m Month.
         * @param d Day.
         * @param y Year.
         */
        void setCalendar (int m, int d, int y);

        /**
         * @brief Reads currently stored date. Values passed by reference.
         * 
         * @param m Month.
         * @param d Day.
         * @param y Year.
         */
        void readCalendar (int& m, int& d, int& y);

        /**
         * @brief Advance the calendar by one day.
         * 
         */
        void advance ();
};

#endif /* CALENDAR_HPP_ */