/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 02/03/2022
 * File: EmbSys.cpp
 */

#include <stdint.h>
#include <fstream>
#include <iostream>
#include "EmbSys.h"


void EmbSys::listData()                                                         // Placeholder listing function
{                                                                               // For now, lists packets by arriving order
    int i, j;
    std::cout << "From: ";
    std::cin >> i;
    
    std::cout << "To : ";
    std::cin >> j;
    std::cout << "Listing packets from " << i << " to " << j << std::endl;
    
    log.dateSearch(i, j);
}

void EmbSys::displayTotalTime()
{
       log.printTotalTime();
}