/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 08/03/2022
 * File: datapkt.h
 */

// Data packet definition 
struct datapkt_t                // Most likely going to become a class
{
    int val;                    // place holder for embedded system log information (TBD)
    int pktn;
    char msg[20];
};
