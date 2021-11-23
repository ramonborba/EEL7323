/**
 * Author: Ramon de Araujo Borba
 * Institution: UFSC
 * Date: 10/11/2021
 * File: calendar.h
 */


//Calendar class
class Calendar {
    protected:
        int mo, day, yr;
    public:
        Calendar (int m, int d, int y);
        void setCalendar (int m, int d, int y);
        void readCalendar (int& m, int& d, int& y);
        void advance ();
};