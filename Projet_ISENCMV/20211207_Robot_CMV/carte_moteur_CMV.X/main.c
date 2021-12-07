/* 
 * File:   main.c
 * Author: CMV_ISEN
 *
 * Created on 7 décembre 2021, 08:37
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "PWM.h"

int main (void)
{
    /***************************************************************************************************/
    //Initialisation de l?oscillateur
    /****************************************************************************************************/
    InitOscillator();

    /****************************************************************************************************/
    // Configuration des entrées sorties
    /****************************************************************************************************/
    InitIO();

    InitTimer23();
    
    InitTimer1();
       
    InitPWM();
    
    // PWMSetSpeed1(0);
    // PWMSetSpeed(10, MOTEUR_DROIT); 
    // PWMSetSpeed(10, MOTEUR_GAUCHE);
    
//    PWMUpdateSpeed();   
    
    /****************************************************************************************************/
    // Boucle Principale
    /****************************************************************************************************/
       
    while(1)
    { 
        
    } // fin main

}

