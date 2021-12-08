/* 
 * File:   ADC.h
 * Author: CMV_ISEN
 *
 * Created on 8 décembre 2021, 08:22
 */

#ifndef ADC_H
#define	ADC_H

void InitADC1(void);
void ADC1StartConversionSequence();
unsigned int * ADCGetResult();
unsigned char ADCIsConversionFinished();
void ADCClearConversionFinishedFlag();

#endif	/* ADC_H */

