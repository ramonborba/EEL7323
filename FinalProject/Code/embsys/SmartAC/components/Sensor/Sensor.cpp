/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: Sensor.cpp
 */

#include "Sensor.hpp"

int Sensor::getID(){
	return sensor_ID;
}

void Sensor::setID(int newID){
	sensor_ID = newID;
}