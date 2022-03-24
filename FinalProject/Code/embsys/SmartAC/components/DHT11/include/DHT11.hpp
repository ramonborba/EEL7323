/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 23/03/2022
 * File: DHT11.hpp
 */

#ifndef _DHT11_HPP_
#define _DHT11_HPP_

#include "Sensor.hpp"
#include "ClockCalendar.hpp"

#define TEMP_RANGE (50)
#define TEMP_MIN (0)
#define HUMID_RANGE (50)
#define HUMID_MIN (0)

struct dht11_data_t
{
    uint8_t     humidity_int {};        // Integral part of humidity reading
    uint8_t     humidity_frac {};       // Fractional part of humidity reading
    uint8_t     temp_int {};            // Integral part of temperature reading
    uint8_t     temp_frac {};           // Fractional part of temperature reading
    clock_t     reading_time {};        // Time of the reading
    calendar_t  reading_date {};        // Date of the reading
};


class DHT11 : public Sensor
{
    private:
        dht11_data_t data_;
        ClockCalendar timestamp_;
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
         * @brief Get the Timestamp object
         * 
         * @param rd_time Reference to hold the time
         * @param rd_date Reference to hold the date
         */
        void getTimestamp(clock_t &rd_time, calendar_t &rd_date);
};


#endif /* _DHT11_HPP_ */