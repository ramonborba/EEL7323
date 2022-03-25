/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 22/03/2022
 * File: gpio_event_task.hpp
 */

#ifndef GPIO_EVENT_TASK_HPP_
#define GPIO_EVENT_TASK_HPP_

/**
 * @brief Task to handle the button interrupts
 * 
 * @param pvParameters Necessary for task creation, but no used in this task, set to NULL on task creation
 */
void gpio_event_task(void *pvParameters);

#endif /* GPIO_EVENT_TASK_HPP_ */