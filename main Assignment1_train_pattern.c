/*
 Name:Monica.s
 Date:25.07.24
 Description:
 Sample execution:Implement LED train pattern on leds
 */


#include <xc.h>
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled)

void init_config(void) {
    //Initializations here 
    TRISB = 0X00;;//set PORTB pins as output
    PORTB = 0X00;//Turn off all 8 led 
}
void LED_pattern1(void);
void LED_pattern2(void);

void LED_pattern1(void) {
    PORTB = 0x01; // Start with the first LED on
    while (PORTB != 0xFF) {
        PORTB = (PORTB << 1) | 1;
        for(unsigned long int i=0;i<10000;i++);
    }

    while (PORTB != 0x00) {
        PORTB >>= 1;
         for(unsigned long int i=0;i<10000;i++);
    }
}
void LED_pattern2(void) {
    PORTB = 0x80; // Start with the last LED on
    while (PORTB != 0xFF) {
        PORTB = (PORTB >> 1) | 0x80;
        for(unsigned long int i=0;i<10000;i++);
    }

    while (PORTB != 0x00) {
        PORTB <<= 1;
        for(unsigned long int i=0;i<10000;i++);
    }
}
void main()
{
    init_config();
    while (1) {
        // Application code here
        LED_pattern1();
       for(unsigned long int i=0;i<10000;i++);
        LED_pattern2();
        for(unsigned long int i=0;i<10000;i++);
    }
}