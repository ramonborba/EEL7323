/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: clock.h
 * Description: Inheritance exercise - Student/Professor Registry
 */
#ifndef _CLOCK_H
#define _CLOCK_H

//Clock class
class Clock {
    protected:
        int hr, min, sec;
        bool is_pm;
    public:
        Clock (int h, int m, int s, bool pm);
        void setClock (int h, int m, int s, bool pm);
        void readClock (int& h, int& m, int& s, bool& pm);
        void advance ();
};

#endif /* _CLOCK_H */