/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 17/03/2022
 * File: uart_event_task.hpp
 * 
 * Task to handle events from uart
 * 
 */
#ifndef UART_EVENT_TASK_HPP_
#define UART_EVENT_TASK_HPP_

#include "SmartAC.h"

#define BUF_SIZE (1024)
#define RD_BUF_SIZE (BUF_SIZE)
#define PATTERN_CHR_NUM (3)

/**
 * @brief Task to handle UART events
 * 
 * @param pvParameters Necessary for task creation, but no used in this task, set to NULL on task creation
 */
void uart_event_task(void* pvParameters);

#endif /* UART_EVENT_TASK_HPP_ */