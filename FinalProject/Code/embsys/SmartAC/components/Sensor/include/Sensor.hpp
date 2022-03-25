/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: Sensor.hpp
 */

#ifndef _SENSOR_HPP_
#define _SENSOR_HPP_

class Sensor {
	    int sensor_ID;
	protected:
		int getID();
		void setID(int);
		virtual void readSensor() = 0;		// funcao virtual pura
};

#endif /* _SENSOR_HPP_ */