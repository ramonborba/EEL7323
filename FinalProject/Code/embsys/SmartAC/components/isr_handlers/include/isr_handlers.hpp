/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 22/03/2022
 * File: isr_handlers.hpp
 */
#ifndef ISR_HANDLERS_HPP_
#define ISR_HANDLERS_HPP_

#define DBOUNCE_TIME        (500) // Debouncing time in ms.
#define DBOUNCE_THRESHOLD   (DBOUNCE_TIME / portTICK_PERIOD_MS) // Debouncing threshold in system ticks

/**
 * @brief ISR to handle button presses with software debouncing.
 * 
 * @param pvParameters Number of the pin this handler is attached to.
 */
void gpio_button_handler (void* pvParameters);

#endif /* ISR_HANDLERS_HPP_ */