/* 
 * File:   main.h
 */

#ifndef MAIN_H
#define	MAIN_H
/* Board has 2 LED Arrays. We are using the 1st one @ PORTD*/
#define LED_ARRAY_1          PORTD
/* Define LED_ARRAY_1_DDR as TRISD for readability
 * TRISD is Data Direction Register for PORTD
 */
#define LED_ARRAY_1_DDR      TRISD

#endif	/* MAIN_H */

