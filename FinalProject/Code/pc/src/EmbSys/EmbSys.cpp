/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 02/03/2022
 * File: EmbSys.cpp
 */

#include "EmbSys.h"

uint8_t EmbSys::requestLog(){
    uint8_t c = sendCommand(cmd);
    return c;
}