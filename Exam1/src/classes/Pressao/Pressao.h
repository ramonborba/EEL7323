/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/12/2021
 * File: Pressao.h
 */
#ifndef _PRESSAO_H_
#define _PRESSAO_H_

#define PRESSURE_RANGE 10							// Range between minimum and maximum value
#define PRESSURE_MIN 0							// Minimum presure value --> reading = (randnum{0.0 to 1.0} * PRESSURE_RANGE ) + PRESSURE_MIN

#include "../Sensor/Sensor.h"
#include "../ClockCalendar/ClockCalendar.h"

class Pressao : public Sensor {
	    ClockCalendar dataHora;
	public:										// Public methods for aggregation
		Pressao();
		void readSensor();
		float getPressure();
		void setID(int newID);
		int getID();
		void printTimestamp();
		void printData();
};

#endif /* _PRESSAO_H_ */