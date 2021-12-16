/*
 * file: Temperatura.cpp
 *
 * Descricao: Implementacao da Classe Temperatura utilizada para realizar a leitura do sensor de temperatura, e data data/hora da leitura realizada.
 *
 * Autor: Eduardo Augusto Bezerra
 * Data: 09/12/2021
 *
 * Ultima Alteracao: Eduardo Augusto Bezerra
 * Data da ultima alteracao: 09/12/2021
 *
 */

#include <cstdlib>   // para usar srand() e rand()
#include <ctime>     // para usar time()
#include <iostream>
#include "Temperatura.h"

Temperatura::Temperatura(){
	setValor(-1);
	setID(-1);
}

void Temperatura::readSensor(){
	float newTemp;

	// Data/hora da leitura do sensor
	dataHora = ClockCalendar(time(nullptr));

	// Simulacao de leitura de sensor
	srand(static_cast <unsigned> (time(0)));
	newTemp = ((static_cast <float> (rand()) / static_cast <float> (RAND_MAX))*TEMP_RANGE)+TEMP_MIN;
	setValor(newTemp);
}

void Temperatura::printTimestamp(){
	dataHora.printClkCal();
}

float Temperatura::getTemp(){
	return getValor();
}
int Temperatura::getID(){
	return Sensor::getID();
}

void Temperatura::setID(int newID){
	Sensor::setID(newID);
}

void Temperatura::printData(){
	std::cout	<< "  -ID			: " << getID() << std::endl
         		<< "  -Valor		: " << getValor() << " °C" << std::endl
        		<< "  -Data - Hora		: "; dataHora.printClkCal() ;
		 std::cout << std::endl;
}
