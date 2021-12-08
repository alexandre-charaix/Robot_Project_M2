/*
 * File:   IO.h
 * Author: CMV_ISEN
 *
 * Created on 7 d�cembre 2021, 08:37
 */

#ifndef IO_H
#define IO_H

//Affectation des pins des LEDS
#define LED_ORANGE _LATC10 
#define LED_BLEUE _LATG7
#define LED_BLANCHE _LATG6

//D�finitions des pins pour les hacheurs moteurs
// Gauche
#define MOTEUR1_IN1 _LATB14
#define MOTEUR1_IN2 _LATB15

// Droit
#define MOTEUR6_IN1 _LATC6
#define MOTEUR6_IN2 _LATC7

//Configuration sp�cifique du moteur gauche
#define MOTEUR_GAUCHE_H_IO_OUTPUT MOTEUR1_IN1
#define MOTEUR_GAUCHE_L_IO_OUTPUT MOTEUR1_IN2
#define MOTEUR_GAUCHE_L_PWM_ENABLE IOCON1bits.PENL
#define MOTEUR_GAUCHE_H_PWM_ENABLE IOCON1bits.PENH
#define MOTEUR_GAUCHE_DUTY_CYCLE PDC1

#define MOTEUR_DROIT_H_IO_OUTPUT MOTEUR6_IN1
#define MOTEUR_DROIT_L_IO_OUTPUT MOTEUR6_IN2
#define MOTEUR_DROIT_L_PWM_ENABLE IOCON6bits.PENL
#define MOTEUR_DROIT_H_PWM_ENABLE IOCON6bits.PENH
#define MOTEUR_DROIT_DUTY_CYCLE PDC6

// Prototypes fonctions
void InitIO();

#endif /* IO_H */