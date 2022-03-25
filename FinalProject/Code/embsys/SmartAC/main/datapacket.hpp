/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 24/03/2022
 * File: datapacket.hpp
 */

#ifndef _DATAPACKET_HPP_
#define _DATAPACKET_HPP_

#include "DHT11.hpp"
#include "ClockCalendar.hpp"

// Structure containing all the data to be stored in ine log entry
struct datapacket
{
    clock_t         log_time;
    calendar_t      log_date;
    uint8_t         sensID;
    dht11_data_t    dht11_data;
    uint8_t         button_state;
    uint8_t         tf_lite_output;
    bool            ac_state;
};


#endif /* _DATAPACKET_HPP_ */