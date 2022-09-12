/*
 * Name: VETRIVEL.P
 * date: 24/08/2022
 * Description: This program will toggle the LEDs at PORTD
 * It illustrates coding practices and conventions used in this course.
 */

#include <xc.h>
#include "main.h"

#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 * configuration, like setting port directions, initializing port values
 */
static void init_config(void){
   
    LED_ARRAY_1_DDR = 0X00;    // set direction to o/p
    LED_ARRAY_1 = 0X00;        // set initial port value

}
void main(void) {
        
    init_config();
    unsigned int long delay = 10000;
    int i,j;

    while(1)
    {   
        /*non blocking delay*/
        if(delay++ == 10000)       
        {  
            delay = 0;
            /*Turn on LED'S from top to bottom */
            if( i < 8)       
            {           
                LED_ARRAY_1 = LED_ARRAY_1 | (1 << i);                                                                      
                i++;                                       
            } 
            /*Turn off LED'S from bottom to top */
            else if(i >= 8 && i < 16)        
            {                                                                                                                             
                LED_ARRAY_1 = LED_ARRAY_1 & ~(1 << (i - 8));                                                                                                                                              
                i++;                                              
            }
            /*Turn on LED'S from bottom to top */
            else if(j <= 8)       
            {             
                LED_ARRAY_1 = LED_ARRAY_1 | (1 << (8 - j));
                j++;       
            }
            /*Turn off LED'S from bottom to top */
            else if(j > 8 && j <= 17)
            {                                                        
                LED_ARRAY_1 = LED_ARRAY_1 & ~(1 << (16 - j));                           
                j++;                       
            } 
            /*output LEDS'S are continues running*/
            if ( i == 16 && j == 17)
            {
                i=0;
                j=0;
            }
           
        }          
        
    } 

}
    