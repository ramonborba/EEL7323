/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/12/2021
 * File: Pressao.cpp
 */

#include <cstdlib>   // para usar srand() e rand()
#include <ctime>     // para usar time()
#include <iostream>
#include "Pressao.h"

Pressao::Pressao(){
	setValor(-1);
	setID(-1);
}

void Pressao::readSensor(){
	float newTemp;

	// Data/hora da leitura do sensor
	dataHora = ClockCalendar(time(nullptr));

	// Simulacao de leitura de sensor
	srand(static_cast <unsigned> (time(0)));
	newTemp = ((static_cast <float> (rand()) / static_cast <float> (RAND_MAX))*PRESSURE_RANGE)+PRESSURE_MIN;
	setValor(newTemp);
}

void Pressao::printTimestamp(){
	dataHora.printClkCal();
}

float Pressao::getPressure(){
	return getValor();
}
int Pressao::getID(){
	return Sensor::getID();
}

void Pressao::setID(int newID){
	Sensor::setID(newID);
}

void Pressao::printData(){
	std::cout	<< "  -ID			: " << getID() << std::endl
         		<< "  -Valor		: " << getValor() << std::endl
        		<< "  -Data - Hora		: "; dataHora.printClkCal() ;
		 std::cout << std::endl;
}
