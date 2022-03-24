
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
        int hr, min, sec;   // Time specification
        bool is_pm;         // am:pm indicator, true for pm, false for am
    public:
    	/**
    	 * @brief Construct a new Clock object with default constructor.
    	 * 
    	 */
        Clock();

        /**
         * @brief Construct a new Clock object.
         * 
         * @param h Hours.
         * @param m Minutes.
         * @param s Second.
         * @param pm am:pm indicator.
         */
        Clock (int h, int m, int s, bool pm);

        /**
         * @brief Set the Clock object to a specific time.
         * 
         * @param h Hours.
         * @param m Minutes.
         * @param s Seconds.
         * @param pm am:pm indicator.
         */
        void setClock (int h, int m, int s, bool pm);

        /**
         * @brief Reads currently stored time. Values passed by reference.
         * 
         * @param h Hours.
         * @param m Minutes.
         * @param s Seconds.
         * @param pm am:pm indicator.
         */
        void readClock (int& h, int& m, int& s, bool& pm);
        
        /**
         * @brief Advances the clock by one second.
         * 
         */
        void advance ();
};

#endif /* CLOCK_HPP_ */