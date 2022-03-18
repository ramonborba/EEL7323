/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 17/03/2022
 * File: uart_event_task.hpp
 * 
 * Task to handle events from uart
 * 
 */

#include "SmartAC.h"

#define BUF_SIZE (1024)
#define RD_BUF_SIZE (BUF_SIZE)
#define PATTERN_CHR_NUM (3)

void uart_event_task(void* pvParameters);
