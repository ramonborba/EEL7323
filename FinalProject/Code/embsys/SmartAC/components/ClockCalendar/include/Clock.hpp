
/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: Clock.hpp
 */
#ifndef CLOCK_HPP_
#define CLOCK_HPP_

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

#endif /* CLOCK_HPP_ */