/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 02/03/2022
 * File: EmbSys.cpp
 */

#include "EmbSys.h"

char EmbSys::requestLog(){
    char c = sendCommand(cmd);
    return c;
}