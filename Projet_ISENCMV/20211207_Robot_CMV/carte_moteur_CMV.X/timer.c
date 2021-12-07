/* 
 * File:   timer.c
 * Author: CMV_ISEN
 *
 * Created on 7 décembre 2021, 08:37
 */

#include <xc.h>
#include "timer.h"
#include "IO.h"

//Initialisation d?un timer 32 bits
void InitTimer23(void) 
{
    T3CONbits.TON = 0; // Stop any 16-bit Timer3 operation
    T2CONbits.TON = 0; // Stop any 16/32-bit Timer3 operation
    T2CONbits.T32 = 1; // Enable 32-bit Timer mode
    T2CONbits.TCS = 0; // Select internal instruction cycle clock
    T2CONbits.TCKPS = 0b11; // Select 1:1 Prescaler // Origin : 0b00
    TMR3 = 0x00; // Clear 32-bit Timer (msw)
    TMR2 = 0x00; // Clear 32-bit Timer (lsw)
    PR3 = 0x0004; // Load 32-bit period value (msw) // Origin : PR3 = 0x0262
    PR2 = 0xC4B4; // Load 32-bit period value (lsw) // Origin : PR2 = 0x5A00
    IPC2bits.T3IP = 0x01; // Set Timer3 Interrupt Priority Level
    IFS0bits.T3IF = 0; // Clear Timer3 Interrupt Flag
    IEC0bits.T3IE = 1; // Enable Timer3 interrupt
    T2CONbits.TON = 1; // Start 32-bit Timer
    /* Example code for Timer3 ISR */
}

//Interruption du timer 32 bits sur 2-3
void __attribute__((interrupt, no_auto_psv)) _T3Interrupt(void) 
{
    IFS0bits.T3IF = 0; // Clear Timer3 Interrupt Flag
    LED_ORANGE = !LED_ORANGE;
}

//Initialisation d?un timer 16 bits
void InitTimer1(void)
{
    //Timer1 pour horodater les mesures (1ms)
    T1CONbits.TON = 0; // Disable Timer
    T1CONbits.TCKPS = 0b11; //Prescaler // Origin : ob01
    //11 = 1:256 prescale value
    //10 = 1:64 prescale value
    //01 = 1:8 prescale value
    //00 = 1:1 prescale value
    T1CONbits.TCS = 0; //clock source = internal clock
    PR1 = 0x061A; // Origin : 0b01 - 0x1388 
                  // 6kHz   : 0b01 - 0x0341
                  // 50Hz   : 0b11 - 0x061A

    IFS0bits.T1IF = 0; // Clear Timer Interrupt Flag
    IEC0bits.T1IE = 1; // Enable Timer interrupt
    T1CONbits.TON = 1; // Enable Timer
}

//Interruption du timer 1
void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{
    IFS0bits.T1IF = 0;
    LED_BLANCHE = !LED_BLANCHE;
}