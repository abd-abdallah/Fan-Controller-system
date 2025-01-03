 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for ADC driver
 *
 * Author: Abdelrahman Abdallah
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "../GPIO/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

typedef enum
{
	AREF_internal_Vref,AVCC_external_5V,Internal_2560mV

}ADC_ReferenceVolatge;

typedef enum
{
    pre2,pre4,pre8,pre16,pre32,pre64,pre128
}ADC_Prescaler;


typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
