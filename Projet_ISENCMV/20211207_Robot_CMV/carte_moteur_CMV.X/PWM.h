/* 
 * File:   PWM.h
 * Author: CMV_ISEN
 *
 * Created on 7 décembre 2021, 08:37
 */

#ifndef PWM_H
#define	PWM_H
#define MOTEUR_GAUCHE 0
#define MOTEUR_DROIT 1


void InitPWM();
//void PWMSetSpeed1(float);
void PWMSetSpeedConsigne(float, char);

void PWMUpdateSpeed();

#endif	/* PWM_H */

