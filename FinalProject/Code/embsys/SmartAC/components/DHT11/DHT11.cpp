/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 23/03/2022
 * File: DHT11.cpp
 */

#include "DHT11.hpp"


DHT11::DHT11() : Sensor(), timestamp {}, data {} {}


dht11_data_t DHT11::getData() 
{
    return data;
}

ClockCalendar DHT11::getTimestamp()
{
    return timestamp;
}

void DHT11::readSensor()
{
    // Random value generation for sensor data as a place holder

    float rng_num;
    uint8_t newTemp_int {0};
    uint8_t newHumi_int {0};

	// Data/hora da leitura do sensor
	timestamp = ClockCalendar(time(nullptr));

	// Simulacao de leitura de sensor
	srand(static_cast <unsigned> (time(0)));
	rng_num = ((static_cast <float> (rand()) / static_cast <float> (RAND_MAX))*TEMP_RANGE)+TEMP_MIN;
    data.humidity_int = static_cast <uint8_t> (rng_num);
	rng_num = ((static_cast <float> (rand()) / static_cast <float> (RAND_MAX))*TEMP_RANGE)+TEMP_MIN;
    data.temp_int = static_cast <uint8_t> (rng_num);

}