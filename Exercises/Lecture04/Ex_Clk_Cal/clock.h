/**
 * Author: Ramon de Araujo Borba
 * Institution: UFSC
 * Date: 10/11/2021
 * File: clock.h
 */


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