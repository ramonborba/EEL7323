/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 23/03/2022
 * File: DHT11.hpp
 */

#ifndef _DHT11_HPP_
#define _DHT11_HPP_

#include <stdint.h>
#include "Sensor.hpp"
#include "ClockCalendar.hpp"

#define TEMP_RANGE (50)
#define TEMP_MIN (0)
#define HUMID_RANGE (50)
#define HUMID_MIN (0)



struct dht11_data_t
{
    uint8_t humidity_int;
    uint8_t humidity_frac;
    uint8_t temp_int;
    uint8_t temp_frac;
};


class DHT11 : public Sensor
{
    private:
        dht11_data_t data;
        ClockCalendar timestamp;
    public:
        /**
         * @brief Construct a new DHT11 object
         *
         */
        DHT11();

        /**
         * @brief Read data from the DHT11 Sensor
         *
         */
        void readSensor();

        /**
         * @brief Get the data information
         *
         * @return dht11_data_t DHT11 data struct
         */
        dht11_data_t getData();

        /**
         * @brief Get the timestamp object
         *
         * @return ClockCalendar object containing the last reading's timestamp
         */
        ClockCalendar getTimestamp();
};


#endif /* _DHT11_HPP_ */