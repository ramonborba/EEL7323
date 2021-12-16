/*
 * file: Temperatura.h
 *
 * Descricao: Classe Temperatura utilizada para realizar a leitura do sensor de temperatura, e data data/hora da leitura realizada.
 *
 * Autor: Eduardo Augusto Bezerra
 * Data: 09/12/2021
 *
 * Ultima Alteracao: Eduardo Augusto Bezerra
 * Data da ultima alteracao: 09/12/2021
 *
 */
#ifndef _TEMPERATURA_H_
#define _TEMPERATURA_H_

#define TEMP_RANGE 200							// Range between minimum and maximum value
#define TEMP_MIN -50							// Minimum temperature value --> reading = (randnum{0.0 to 1.0} * TEMP_RANGE ) + TEMP_MIN

#include "../Sensor/Sensor.h"
#include "../ClockCalendar/ClockCalendar.h"

class Temperatura : public Sensor {
	    ClockCalendar dataHora;
	public:										// Public methods for aggregation
		Temperatura();
		void readSensor();
		float getTemp();
		void setID(int newID);
		int getID();
		void printTimestamp(); 					//Testin purposes, may decite to keep it later
};

#endif /* _TEMPERATURA_H_ */