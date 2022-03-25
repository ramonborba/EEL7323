/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 23/03/2022
 * File: DHT11.cpp
 */

#include "DHT11.hpp"


DHT11::DHT11() : data_ {}, timestamp_ {} {}


dht11_data_t DHT11::getData() 
{
    return data_;
}

void DHT11::getTimestamp(clock_t &rd_time, calendar_t &rd_date)
{
    timestamp_.readClock(rd_time);
    timestamp_.readCalendar(rd_date);
}

void DHT11::readSensor()
{
    // Random value generation for sensor data as a place holder
    float rng_num;

	// Time and date of the reading
	timestamp_ = ClockCalendar(time(nullptr));
    getTimestamp(data_.reading_time, data_.reading_date);

	// Sensor reading simulation
	srand(static_cast <unsigned> (time(0)));
	rng_num = ((static_cast <float> (rand()) / static_cast <float> (RAND_MAX))*TEMP_RANGE)+TEMP_MIN;
    data_.humidity_int = static_cast <uint8_t> (rng_num);
	rng_num = ((static_cast <float> (rand()) / static_cast <float> (RAND_MAX))*TEMP_RANGE)+TEMP_MIN;
    data_.temp_int = static_cast <uint8_t> (rng_num);

}