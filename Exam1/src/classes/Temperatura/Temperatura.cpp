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

#include "Temperatura.h" 
#include <cstdlib>   // para usar srand() e rand()
#include <ctime>     // para usar time()

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