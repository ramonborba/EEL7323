/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/12/2021
 * File: Calendar.h
 */
#ifndef _CALENDAR_H_
#define _CALENDAR_H_

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

#endif /* _CALENDAR_H_ */