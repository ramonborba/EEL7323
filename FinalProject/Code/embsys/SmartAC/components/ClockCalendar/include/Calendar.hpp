
/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: calendar.h
 */
#ifndef CALENDAR_HPP_
#define CALENDAR_HPP_

//Calendar class
class Calendar {
    protected:
        int mo, day, yr;
    public:
        Calendar();
        Calendar (int m, int d, int y);
        void setCalendar (int m, int d, int y);
        void readCalendar (int& m, int& d, int& y);
        void advance ();
};

#endif /* CALENDAR_HPP_ */